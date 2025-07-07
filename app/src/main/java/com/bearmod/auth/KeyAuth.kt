package com.bearmod.auth

import android.content.Context
import android.os.Build
import android.provider.Settings
import android.util.Log
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.delay
import kotlinx.coroutines.launch
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.SupervisorJob
import java.security.MessageDigest
import java.util.concurrent.ConcurrentHashMap
import java.util.concurrent.atomic.AtomicBoolean
import java.util.concurrent.atomic.AtomicLong
import javax.crypto.Mac
import javax.crypto.spec.SecretKeySpec

/**
 * Enhanced KeyAuth implementation for BearMod with advanced token flow management
 * Supports KeyAuth API 1.3 with improved security and session management
 */
class KeyAuth(private val context: Context) {
    
    companion object {
        private const val TAG = "KeyAuth"
        private const val TOKEN_REFRESH_INTERVAL = 30 * 60 * 1000L // 30 minutes
        private const val SESSION_HEARTBEAT_INTERVAL = 5 * 60 * 1000L // 5 minutes
        private const val MAX_RETRY_ATTEMPTS = 3
        private const val RETRY_DELAY_BASE = 1000L // Base delay for exponential backoff
        
        @Volatile
        private var instance: KeyAuth? = null
        
        /**
         * Get singleton instance
         */
        fun getInstance(context: Context): KeyAuth {
            return instance ?: synchronized(this) {
                instance ?: KeyAuth(context.applicationContext).also { instance = it }
            }
        }
    }
    
    private val apiService: KeyAuthApiService by lazy {
        NetworkFactory.createKeyAuthService()
    }
    
    private val securePreferences: SecurePreferences by lazy {
        SecurePreferences(context)
    }
    
    // Enhanced state management
    private val _authState = MutableStateFlow<AuthState>(AuthState.Unauthenticated)
    val authState: StateFlow<AuthState> = _authState.asStateFlow()
    
    private val _tokenState = MutableStateFlow<TokenState>(TokenState.Invalid)
    val tokenState: StateFlow<TokenState> = _tokenState.asStateFlow()
    
    // Advanced session management
    private val sessionScope = CoroutineScope(SupervisorJob() + Dispatchers.IO)
    private val isInitialized = AtomicBoolean(false)
    private val isTokenRefreshing = AtomicBoolean(false)
    private val lastTokenRefresh = AtomicLong(0)
    private val lastHeartbeat = AtomicLong(0)
    
    @Volatile
    private var currentSessionId: String? = null
    
    @Volatile
    private var currentAccessToken: String? = null
    
    @Volatile
    private var currentRefreshToken: String? = null
    
    // Token management cache
    private val tokenCache = ConcurrentHashMap<String, TokenInfo>()
    private val initializationLock = Any()
    
    // Enhanced security features
    private val integrityValidator = IntegrityValidator()
    private val sessionValidator = SessionValidator()
    
    /**
     * Authentication state enum
     */
    sealed class AuthState {
        object Unauthenticated : AuthState()
        object Authenticating : AuthState()
        data class Authenticated(val userInfo: UserInfo, val tier: String) : AuthState()
        data class AuthError(val message: String, val retryable: Boolean = true) : AuthState()
    }
    
    /**
     * Token state enum
     */
    sealed class TokenState {
        object Invalid : TokenState()
        object Refreshing : TokenState()
        data class Valid(val accessToken: String, val expiresAt: Long) : TokenState()
        data class Error(val message: String) : TokenState()
    }
    
    /**
     * Token information holder
     */
    data class TokenInfo(
        val accessToken: String,
        val refreshToken: String?,
        val expiresAt: Long,
        val issuedAt: Long = System.currentTimeMillis(),
        val scope: String? = null
    )
    
    /**
     * Enhanced initialization with token management
     */
    suspend fun initialize(): NetworkResult<KeyAuthResponse> = withContext(Dispatchers.IO) {
        try {
            Log.d(TAG, "Initializing Enhanced KeyAuth with token management")
            
            // Validate configuration first
            if (!KeyAuthConfig.isConfigurationValid()) {
                val errors = KeyAuthConfig.getConfigurationErrors()
                Log.e(TAG, "KeyAuth configuration invalid: ${errors.joinToString(", ")}")
                _authState.value = AuthState.AuthError("Configuration invalid: ${errors.joinToString(", ")}", false)
                return@withContext NetworkResult.Error("Configuration invalid: ${errors.joinToString(", ")}")
            }
            
            synchronized(initializationLock) {
                if (isInitialized.get()) {
                    Log.d(TAG, "KeyAuth already initialized")
                    return@withContext NetworkResult.Success(
                        KeyAuthResponse(
                            success = true,
                            message = "Already initialized",
                            sessionId = currentSessionId
                        )
                    )
                }
                
                // Clear any existing session state
                clearSessionState()
            }
            
            // Enhanced initialization with integrity checking
            val response = initializeWithIntegrityCheck()
            
            if (response is NetworkResult.Success) {
                val body = response.data
                synchronized(initializationLock) {
                    currentSessionId = body.sessionId
                    isInitialized.set(true)
                    _authState.value = AuthState.Unauthenticated
                }
                
                // Start background session management
                startSessionManagement()
                
                Log.d(TAG, "Enhanced KeyAuth initialization successful")
            } else {
                _authState.value = AuthState.AuthError(response.getErrorMessage() ?: "Initialization failed")
            }
            
            response
        } catch (e: Exception) {
            Log.e(TAG, "Enhanced KeyAuth initialization exception", e)
            _authState.value = AuthState.AuthError("Initialization error: ${e.message}")
            NetworkResult.Error("Initialization error: ${e.message}", e)
        }
    }
    
    /**
     * Initialize with integrity checking
     */
    private suspend fun initializeWithIntegrityCheck(): NetworkResult<KeyAuthResponse> {
        val integrityHash = integrityValidator.generateIntegrityHash()
        
        val response = apiService.init(
            version = KeyAuthConfig.APP_VERSION,
            name = KeyAuthConfig.APP_NAME,
            ownerId = KeyAuthConfig.OWNER_ID,
            hash = integrityHash
        )
        
        if (response.isSuccessful) {
            val body = response.body()
            if (body?.success == true) {
                // Validate response integrity
                if (integrityValidator.validateResponse(body)) {
                    return NetworkResult.Success(body)
                } else {
                    return NetworkResult.Error("Response integrity validation failed")
                }
            } else {
                val errorMessage = body?.message ?: "Initialization failed"
                return NetworkResult.Error(errorMessage)
            }
        } else {
            val errorMessage = "HTTP ${response.code()}: ${response.message()}"
            return NetworkResult.Error(errorMessage)
        }
    }
    
    /**
     * Enhanced license validation with token flow
     */
    suspend fun validateLicense(licenseKey: String): AuthResult = withContext(Dispatchers.IO) {
        try {
            Log.d(TAG, "Enhanced license validation with token flow")
            _authState.value = AuthState.Authenticating
            
            // Ensure initialization
            if (!isInitialized.get()) {
                val initResult = initialize()
                if (initResult !is NetworkResult.Success) {
                    val errorMessage = "Initialization failed: ${initResult.getErrorMessage()}"
                    _authState.value = AuthState.AuthError(errorMessage)
                    return@withContext AuthResult(success = false, message = errorMessage)
                }
            }
            
            // Generate enhanced HWID with security features
            val hwid = generateEnhancedHWID()
            val sessionId = currentSessionId ?: run {
                val errorMessage = "No session ID available after initialization"
                _authState.value = AuthState.AuthError(errorMessage)
                return@withContext AuthResult(success = false, message = errorMessage)
            }
            
            // Perform license validation with retry logic
            val validationResult = performLicenseValidationWithRetry(licenseKey, hwid, sessionId)
            
            if (validationResult.success) {
                // Store token information
                validationResult.sessionId?.let { newSessionId ->
                    currentSessionId = newSessionId
                }
                
                // Generate and store access token
                val accessToken = generateAccessToken(licenseKey, hwid)
                currentAccessToken = accessToken
                
                // Store authentication data securely
                handleSuccessfulAuthentication(licenseKey, hwid, validationResult)
                
                // Update state
                val userInfo = validationResult.userInfo
                val tier = userInfo?.getPrimarySubscriptionTier() ?: "basic"
                _authState.value = AuthState.Authenticated(userInfo ?: UserInfo(), tier)
                _tokenState.value = TokenState.Valid(accessToken, System.currentTimeMillis() + TOKEN_REFRESH_INTERVAL)
                
                // Start token refresh cycle
                startTokenRefreshCycle()
                
                Log.d(TAG, "Enhanced license validation successful with token management")
            } else {
                _authState.value = AuthState.AuthError(validationResult.message)
            }
            
            validationResult
        } catch (e: Exception) {
            Log.e(TAG, "Enhanced license validation exception", e)
            val errorMessage = "Validation error: ${e.message}"
            _authState.value = AuthState.AuthError(errorMessage)
            AuthResult(success = false, message = errorMessage)
        }
    }
    
    /**
     * Perform license validation with retry logic
     */
    private suspend fun performLicenseValidationWithRetry(
        licenseKey: String, 
        hwid: String, 
        sessionId: String,
        attempt: Int = 1
    ): AuthResult {
        try {
            val response = apiService.license(
                licenseKey = licenseKey,
                hwid = hwid,
                sessionId = sessionId,
                name = KeyAuthConfig.APP_NAME,
                ownerId = KeyAuthConfig.OWNER_ID
            )
            
            if (response.isSuccessful) {
                val body = response.body()
                if (body?.success == true) {
                    return body.toAuthResult(licenseKey, hwid)
                } else {
                    val errorMessage = body?.message ?: "License validation failed"
                    
                    // Retry on certain errors
                    if (attempt < MAX_RETRY_ATTEMPTS && isRetryableError(errorMessage)) {
                        delay(RETRY_DELAY_BASE * attempt)
                        return performLicenseValidationWithRetry(licenseKey, hwid, sessionId, attempt + 1)
                    }
                    
                    return AuthResult(success = false, message = errorMessage, hwid = hwid, licenseKey = licenseKey)
                }
            } else {
                val errorMessage = "HTTP ${response.code()}: ${response.message()}"
                
                // Retry on server errors
                if (attempt < MAX_RETRY_ATTEMPTS && response.code() >= 500) {
                    delay(RETRY_DELAY_BASE * attempt)
                    return performLicenseValidationWithRetry(licenseKey, hwid, sessionId, attempt + 1)
                }
                
                return AuthResult(success = false, message = errorMessage, hwid = hwid, licenseKey = licenseKey)
            }
        } catch (e: Exception) {
            if (attempt < MAX_RETRY_ATTEMPTS) {
                delay(RETRY_DELAY_BASE * attempt)
                return performLicenseValidationWithRetry(licenseKey, hwid, sessionId, attempt + 1)
            }
            
            return AuthResult(success = false, message = "Validation error: ${e.message}")
        }
    }
    
    /**
     * Check if error is retryable
     */
    private fun isRetryableError(errorMessage: String): Boolean {
        val retryableErrors = listOf(
            "network error",
            "timeout",
            "connection failed",
            "server error",
            "temporary unavailable"
        )
        
        return retryableErrors.any { errorMessage.contains(it, ignoreCase = true) }
    }
    
    /**
     * Generate enhanced HWID with additional security
     */
    private fun generateEnhancedHWID(): String {
        // Try to get existing HWID first
        val existingHWID = securePreferences.getStoredHWID()
        if (!existingHWID.isNullOrEmpty()) {
            return existingHWID
        }
        
        // Generate new enhanced HWID
        val hwid = generatePersistentEnhancedHWID()
        securePreferences.storeHWID(hwid)
        return hwid
    }
    
    /**
     * Generate persistent enhanced HWID with multiple device characteristics
     */
    private fun generatePersistentEnhancedHWID(): String {
        return try {
            val androidId = Settings.Secure.getString(context.contentResolver, Settings.Secure.ANDROID_ID) ?: "unknown"
            
            // Enhanced hardware identifiers
            val manufacturer = Build.MANUFACTURER ?: "unknown"
            val model = Build.MODEL ?: "unknown"
            val device = Build.DEVICE ?: "unknown"
            val board = Build.BOARD ?: "unknown"
            val brand = Build.BRAND ?: "unknown"
            val hardware = Build.HARDWARE ?: "unknown"
            val product = Build.PRODUCT ?: "unknown"
            val bootloader = Build.BOOTLOADER ?: "unknown"
            
            // CPU and architecture details
            val cpuAbi = Build.SUPPORTED_ABIS?.joinToString(",") ?: "unknown"
            val cpuAbi2 = Build.SUPPORTED_32_BIT_ABIS?.joinToString(",") ?: "unknown"
            val cpuAbi64 = Build.SUPPORTED_64_BIT_ABIS?.joinToString(",") ?: "unknown"
            
            // Display characteristics
            val displayMetrics = context.resources.displayMetrics
            val screenDensity = displayMetrics.densityDpi.toString()
            val screenWidth = displayMetrics.widthPixels.toString()
            val screenHeight = displayMetrics.heightPixels.toString()
            val scaledDensity = displayMetrics.scaledDensity.toString()
            
            // Additional system properties
            val buildFingerprint = Build.FINGERPRINT ?: "unknown"
            val buildTime = Build.TIME.toString()
            val sdkInt = Build.VERSION.SDK_INT.toString()
            
            // Combine all identifiers for enhanced uniqueness
            val deviceFingerprint = listOf(
                manufacturer, model, device, board, brand, hardware, product, bootloader,
                cpuAbi, cpuAbi2, cpuAbi64, screenDensity, screenWidth, screenHeight, scaledDensity,
                buildFingerprint, buildTime, sdkInt, androidId
            ).joinToString("-")
            
            // Generate SHA-256 hash with salt
            val salt = "BearMod_HWID_v2.0"
            val combined = deviceFingerprint + salt
            val digest = MessageDigest.getInstance("SHA-256")
            val hash = digest.digest(combined.toByteArray())
            hash.joinToString("") { "%02x".format(it) }
            
        } catch (e: Exception) {
            Log.e(TAG, "Failed to generate enhanced HWID", e)
            // Enhanced fallback
            val fallbackData = "${Build.MANUFACTURER}-${Build.MODEL}-${Build.DEVICE}-${System.currentTimeMillis()}"
            val digest = MessageDigest.getInstance("SHA-256")
            digest.digest(fallbackData.toByteArray()).joinToString("") { "%02x".format(it) }
        }
    }
    
    /**
     * Generate access token for session management
     */
    private fun generateAccessToken(licenseKey: String, hwid: String): String {
        val timestamp = System.currentTimeMillis()
        val data = "${licenseKey}_${hwid}_${timestamp}"
        
        return try {
            val mac = Mac.getInstance("HmacSHA256")
            val secret = (KeyAuthConfig.APP_NAME + KeyAuthConfig.OWNER_ID).toByteArray()
            val keySpec = SecretKeySpec(secret, "HmacSHA256")
            mac.init(keySpec)
            val hash = mac.doFinal(data.toByteArray())
            hash.joinToString("") { "%02x".format(it) }
        } catch (e: Exception) {
            Log.e(TAG, "Failed to generate access token", e)
            data.hashCode().toString()
        }
    }
    
    /**
     * Start session management background tasks
     */
    private fun startSessionManagement() {
        sessionScope.launch {
            while (isInitialized.get()) {
                try {
                    // Session heartbeat
                    if (System.currentTimeMillis() - lastHeartbeat.get() > SESSION_HEARTBEAT_INTERVAL) {
                        performSessionHeartbeat()
                    }
                    
                    // Token refresh check
                    if (shouldRefreshToken()) {
                        refreshTokenIfNeeded()
                    }
                    
                    delay(30000) // Check every 30 seconds
                } catch (e: Exception) {
                    Log.e(TAG, "Error in session management", e)
                }
            }
        }
    }
    
    /**
     * Perform session heartbeat
     */
    private suspend fun performSessionHeartbeat() {
        try {
            val sessionId = currentSessionId ?: return
            
            val result = checkSession()
            if (result is NetworkResult.Success) {
                lastHeartbeat.set(System.currentTimeMillis())
                Log.v(TAG, "Session heartbeat successful")
            } else {
                Log.w(TAG, "Session heartbeat failed: ${result.getErrorMessage()}")
                if (result.getErrorMessage()?.contains("session not found", ignoreCase = true) == true) {
                    handleSessionExpired()
                }
            }
        } catch (e: Exception) {
            Log.e(TAG, "Error performing session heartbeat", e)
        }
    }
    
    /**
     * Check if token should be refreshed
     */
    private fun shouldRefreshToken(): Boolean {
        val tokenState = _tokenState.value
        if (tokenState is TokenState.Valid) {
            val timeUntilExpiry = tokenState.expiresAt - System.currentTimeMillis()
            return timeUntilExpiry <= (TOKEN_REFRESH_INTERVAL / 2) // Refresh when half the time is left
        }
        return false
    }
    
    /**
     * Refresh token if needed
     */
    private suspend fun refreshTokenIfNeeded() {
        if (!isTokenRefreshing.compareAndSet(false, true)) {
            return // Already refreshing
        }
        
        try {
            _tokenState.value = TokenState.Refreshing
            
            // Simulate token refresh (implement actual refresh logic based on your API)
            val currentSession = currentSessionId
            val currentLicense = securePreferences.getStoredLicense()
            val currentHwid = securePreferences.getStoredHWID()
            
            if (currentSession != null && currentLicense != null && currentHwid != null) {
                // Generate new access token
                val newAccessToken = generateAccessToken(currentLicense, currentHwid)
                currentAccessToken = newAccessToken
                
                val newExpiryTime = System.currentTimeMillis() + TOKEN_REFRESH_INTERVAL
                _tokenState.value = TokenState.Valid(newAccessToken, newExpiryTime)
                lastTokenRefresh.set(System.currentTimeMillis())
                
                Log.d(TAG, "Token refreshed successfully")
            } else {
                _tokenState.value = TokenState.Error("Missing session data for token refresh")
                Log.e(TAG, "Failed to refresh token: missing session data")
            }
        } catch (e: Exception) {
            _tokenState.value = TokenState.Error("Token refresh failed: ${e.message}")
            Log.e(TAG, "Error refreshing token", e)
        } finally {
            isTokenRefreshing.set(false)
        }
    }
    
    /**
     * Start token refresh cycle
     */
    private fun startTokenRefreshCycle() {
        sessionScope.launch {
            while (_authState.value is AuthState.Authenticated) {
                try {
                    delay(TOKEN_REFRESH_INTERVAL / 2) // Check for refresh at half interval
                    if (shouldRefreshToken()) {
                        refreshTokenIfNeeded()
                    }
                } catch (e: Exception) {
                    Log.e(TAG, "Error in token refresh cycle", e)
                }
            }
        }
    }
    
    /**
     * Handle session expiration
     */
    private fun handleSessionExpired() {
        clearSessionState()
        _authState.value = AuthState.AuthError("Session expired", true)
        _tokenState.value = TokenState.Invalid
    }
    
    /**
     * Clear session state
     */
    private fun clearSessionState() {
        currentSessionId = null
        currentAccessToken = null
        currentRefreshToken = null
        tokenCache.clear()
    }
    
    /**
     * Enhanced session checking with validation
     */
    suspend fun checkSession(): NetworkResult<KeyAuthResponse> = withContext(Dispatchers.IO) {
        try {
            val sessionId = currentSessionId ?: run {
                Log.e(TAG, "No active session ID")
                return@withContext NetworkResult.Error("No active session")
            }
            
            // Validate session before making request
            if (!sessionValidator.isSessionValid(sessionId)) {
                Log.e(TAG, "Session validation failed")
                return@withContext NetworkResult.Error("Invalid session format")
            }
            
            val response = apiService.checkSession(
                sessionId = sessionId,
                name = KeyAuthConfig.APP_NAME,
                ownerId = KeyAuthConfig.OWNER_ID
            )
            
            if (response.isSuccessful) {
                val body = response.body()
                if (body?.success == true) {
                    // Validate response integrity
                    if (integrityValidator.validateResponse(body)) {
                        Log.v(TAG, "Session validation successful")
                        return@withContext NetworkResult.Success(body)
                    } else {
                        Log.e(TAG, "Session response integrity validation failed")
                        return@withContext NetworkResult.Error("Response integrity validation failed")
                    }
                } else {
                    val errorMessage = body?.message ?: "Session invalid"
                    Log.e(TAG, "Session validation failed: $errorMessage")
                    
                    // Clear invalid session
                    if (errorMessage.contains("session not found", ignoreCase = true)) {
                        clearSession()
                    }
                    
                    return@withContext NetworkResult.Error(errorMessage)
                }
            } else {
                val errorMessage = "HTTP ${response.code()}: ${response.message()}"
                Log.e(TAG, "Session check HTTP error: $errorMessage")
                return@withContext NetworkResult.Error(errorMessage)
            }
        } catch (e: Exception) {
            Log.e(TAG, "Session check exception", e)
            return@withContext NetworkResult.Error("Session check error: ${e.message}", e)
        }
    }
    
    /**
     * Handle successful authentication with enhanced security
     */
    private fun handleSuccessfulAuthentication(licenseKey: String, hwid: String, response: AuthResult) {
        try {
            // Store session token with enhanced security
            val sessionToken = currentSessionId ?: ""
            val expiryTime = System.currentTimeMillis() + (KeyAuthConfig.SESSION_TIMEOUT_HOURS * 60 * 60 * 1000)
            securePreferences.storeSessionToken(sessionToken, expiryTime)
            
            // Store license key securely
            securePreferences.storeLicense(licenseKey)
            
            // Register device with enhanced HWID
            securePreferences.setDeviceRegistered(hwid, licenseKey)
            
            // Store user info
            response.userInfo?.let { userInfo ->
                securePreferences.storeUserInfo(userInfo)
            }
            
            // Cache token information
            val tokenInfo = TokenInfo(
                accessToken = currentAccessToken ?: "",
                refreshToken = currentRefreshToken,
                expiresAt = System.currentTimeMillis() + TOKEN_REFRESH_INTERVAL,
                scope = response.tier
            )
            tokenCache[licenseKey] = tokenInfo
            
            Log.d(TAG, "Enhanced authentication data stored successfully")
        } catch (e: Exception) {
            Log.e(TAG, "Failed to store enhanced authentication data", e)
        }
    }
    
    /**
     * Clear session data with enhanced cleanup
     */
    fun clearSession() {
        synchronized(initializationLock) {
            currentSessionId = null
            currentAccessToken = null
            currentRefreshToken = null
            isInitialized.set(false)
        }
        securePreferences.clearSessionToken()
        tokenCache.clear()
        _authState.value = AuthState.Unauthenticated
        _tokenState.value = TokenState.Invalid
    }
    
    /**
     * Enhanced logout with comprehensive cleanup
     */
    fun logout() {
        clearSession()
        securePreferences.clearAuthenticationData()
        
        // Cancel all background tasks
        if (!sessionScope.coroutineContext[SupervisorJob]!!.isCancelled) {
            sessionScope.coroutineContext[SupervisorJob]!!.cancel()
        }
        
        Log.d(TAG, "Enhanced logout completed")
    }
    
    /**
     * Get current session ID
     */
    fun getSessionId(): String? = currentSessionId
    
    /**
     * Get current access token
     */
    fun getAccessToken(): String? = currentAccessToken
    
    /**
     * Check if initialized
     */
    fun isInitialized(): Boolean = isInitialized.get()
    
    /**
     * Get current authentication state
     */
    fun getCurrentAuthState(): AuthState = _authState.value
    
    /**
     * Get current token state
     */
    fun getCurrentTokenState(): TokenState = _tokenState.value
    
    /**
     * Get enhanced diagnostic information
     */
    fun getDiagnosticInfo(): Map<String, String> {
        return mapOf(
            "isInitialized" to isInitialized.get().toString(),
            "hasSessionId" to (currentSessionId != null).toString(),
            "sessionIdLength" to (currentSessionId?.length?.toString() ?: "0"),
            "hasAccessToken" to (currentAccessToken != null).toString(),
            "authState" to _authState.value::class.java.simpleName,
            "tokenState" to _tokenState.value::class.java.simpleName,
            "tokenCacheSize" to tokenCache.size.toString(),
            "lastTokenRefresh" to lastTokenRefresh.get().toString(),
            "lastHeartbeat" to lastHeartbeat.get().toString(),
            "configValid" to KeyAuthConfig.isConfigurationValid().toString()
        ) + KeyAuthConfig.getDiagnosticInfo() + securePreferences.getDiagnosticInfo()
    }
    
    /**
     * Integrity validator for API responses and requests
     */
    private inner class IntegrityValidator {
        
        /**
         * Generate integrity hash for requests
         */
        fun generateIntegrityHash(): String {
            return try {
                val data = "${KeyAuthConfig.APP_NAME}${KeyAuthConfig.APP_VERSION}${KeyAuthConfig.OWNER_ID}"
                val digest = MessageDigest.getInstance("SHA-256")
                val hash = digest.digest(data.toByteArray())
                hash.joinToString("") { "%02x".format(it) }
            } catch (e: Exception) {
                Log.e(TAG, "Failed to generate integrity hash", e)
                KeyAuthConfig.CUSTOM_HASH ?: ""
            }
        }
        
        /**
         * Validate response integrity
         */
        fun validateResponse(response: KeyAuthResponse): Boolean {
            return try {
                // Basic validation - check if response contains expected fields
                response.message.isNotEmpty() && 
                (response.success || response.message.isNotEmpty())
            } catch (e: Exception) {
                Log.e(TAG, "Failed to validate response integrity", e)
                false
            }
        }
    }
    
    /**
     * Session validator for session management
     */
    private inner class SessionValidator {
        
        /**
         * Validate session ID format and integrity
         */
        fun isSessionValid(sessionId: String): Boolean {
            return try {
                // Basic session validation
                sessionId.isNotEmpty() && 
                sessionId.length >= 16 && 
                sessionId.matches(Regex("[a-zA-Z0-9]+"))
            } catch (e: Exception) {
                Log.e(TAG, "Failed to validate session", e)
                false
            }
        }
        
        /**
         * Validate session expiry
         */
        fun isSessionExpired(sessionId: String): Boolean {
            return try {
                val tokenInfo = tokenCache.values.firstOrNull()
                tokenInfo?.let { 
                    System.currentTimeMillis() > it.expiresAt 
                } ?: false
            } catch (e: Exception) {
                Log.e(TAG, "Failed to check session expiry", e)
                true // Assume expired on error
            }
        }
    }
}

/**
 * Extension function to add license storage to SecurePreferences
 */
private fun SecurePreferences.storeLicense(licenseKey: String) {
    // This should be implemented in SecurePreferences class
    // For now, we'll use a simple approach
    try {
        // Store license key securely (implement encryption in actual SecurePreferences)
        android.preference.PreferenceManager.getDefaultSharedPreferences(context)
            .edit()
            .putString("stored_license_key", licenseKey)
            .apply()
    } catch (e: Exception) {
        android.util.Log.e("SecurePreferences", "Failed to store license", e)
    }
}

/**
 * Extension function to get stored license from SecurePreferences
 */
private fun SecurePreferences.getStoredLicense(): String? {
    return try {
        android.preference.PreferenceManager.getDefaultSharedPreferences(context)
            .getString("stored_license_key", null)
    } catch (e: Exception) {
        android.util.Log.e("SecurePreferences", "Failed to get stored license", e)
        null
    }
}
