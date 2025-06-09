package com.bearmod.auth

import android.content.Context
import android.os.Build
import android.provider.Settings
import android.util.Log
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import java.security.MessageDigest

/**
 * Core KeyAuth implementation for BearMod
 * Handles license validation, session management, and HWID generation
 */
class KeyAuth(private val context: Context) {
    
    companion object {
        private const val TAG = "KeyAuth"
        
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
    
    @Volatile
    private var isInitialized = false
    
    @Volatile
    private var sessionId: String? = null
    
    private val initializationLock = Any()
    
    /**
     * Initialize KeyAuth application
     * Must be called before any other operations
     */
    suspend fun initialize(): NetworkResult<KeyAuthResponse> = withContext(Dispatchers.IO) {
        try {
            // Validate configuration first
            if (!KeyAuthConfig.isConfigurationValid()) {
                val errors = KeyAuthConfig.getConfigurationErrors()
                Log.e(TAG, "KeyAuth configuration invalid: ${errors.joinToString(", ")}")
                return@withContext NetworkResult.Error("Configuration invalid: ${errors.joinToString(", ")}")
            }
            
            synchronized(initializationLock) {
                if (isInitialized) {
                    Log.d(TAG, "KeyAuth already initialized")
                    return@withContext NetworkResult.Success(
                        KeyAuthResponse(
                            success = true,
                            message = "Already initialized",
                            sessionId = sessionId
                        )
                    )
                }
                
                // Clear any existing session state for clean initialization
                sessionId = null
            }
            
            Log.d(TAG, "Initializing KeyAuth with config: ${KeyAuthConfig.getDiagnosticInfo()}")
            
            val response = apiService.init(
                version = KeyAuthConfig.APP_VERSION,
                name = KeyAuthConfig.APP_NAME,
                ownerId = KeyAuthConfig.OWNER_ID,
                hash = KeyAuthConfig.CUSTOM_HASH
            )
            
            if (response.isSuccessful) {
                val body = response.body()
                if (body?.success == true) {
                    synchronized(initializationLock) {
                        sessionId = body.sessionId
                        isInitialized = true
                    }
                    
                    Log.d(TAG, "KeyAuth initialization successful")
                    NetworkResult.Success(body)
                } else {
                    val errorMessage = body?.message ?: "Initialization failed"
                    Log.e(TAG, "KeyAuth initialization failed: $errorMessage")
                    NetworkResult.Error(errorMessage)
                }
            } else {
                val errorMessage = "HTTP ${response.code()}: ${response.message()}"
                Log.e(TAG, "KeyAuth initialization HTTP error: $errorMessage")
                NetworkResult.Error(errorMessage)
            }
        } catch (e: Exception) {
            Log.e(TAG, "KeyAuth initialization exception", e)
            NetworkResult.Error("Initialization error: ${e.message}", e)
        }
    }
    
    /**
     * Validate license key
     * Returns AuthResult with success status and subscription tier
     */
    suspend fun validateLicense(licenseKey: String): AuthResult = withContext(Dispatchers.IO) {
        try {
            Log.d(TAG, "Validating license key: ${licenseKey.take(8)}...")
            
            // Ensure initialization
            if (!isInitialized) {
                val initResult = initialize()
                if (initResult !is NetworkResult.Success) {
                    return@withContext AuthResult(
                        success = false,
                        message = "Initialization failed: ${initResult.getErrorMessage()}"
                    )
                }
            }
            
            val hwid = generateHWID()
            val currentSessionId = sessionId ?: run {
                Log.e(TAG, "No session ID available after initialization")
                return@withContext AuthResult(
                    success = false,
                    message = "No session ID available"
                )
            }
            
            Log.d(TAG, "Authenticating with HWID: ${hwid.take(8)}...")
            
            val response = apiService.license(
                licenseKey = licenseKey,
                hwid = hwid,
                sessionId = currentSessionId,
                name = KeyAuthConfig.APP_NAME,
                ownerId = KeyAuthConfig.OWNER_ID
            )
            
            if (response.isSuccessful) {
                val body = response.body()
                if (body?.success == true) {
                    // Update session ID if provided
                    body.sessionId?.let {
                        synchronized(initializationLock) {
                            sessionId = it
                        }
                    }
                    
                    // Store authentication data
                    handleSuccessfulAuthentication(licenseKey, hwid, body)
                    
                    Log.d(TAG, "License validation successful")
                    body.toAuthResult(licenseKey, hwid)
                } else {
                    val errorMessage = body?.message ?: "License validation failed"
                    Log.e(TAG, "License validation failed: $errorMessage")
                    
                    AuthResult(
                        success = false,
                        message = errorMessage,
                        hwid = hwid,
                        licenseKey = licenseKey
                    )
                }
            } else {
                val errorMessage = "HTTP ${response.code()}: ${response.message()}"
                Log.e(TAG, "License validation HTTP error: $errorMessage")
                
                AuthResult(
                    success = false,
                    message = errorMessage,
                    hwid = hwid,
                    licenseKey = licenseKey
                )
            }
        } catch (e: Exception) {
            Log.e(TAG, "License validation exception", e)
            AuthResult(
                success = false,
                message = "Validation error: ${e.message}"
            )
        }
    }
    
    /**
     * Check if current session is valid
     */
    suspend fun checkSession(): NetworkResult<KeyAuthResponse> = withContext(Dispatchers.IO) {
        try {
            val currentSessionId = sessionId ?: run {
                Log.e(TAG, "No active session ID")
                return@withContext NetworkResult.Error("No active session")
            }
            
            Log.d(TAG, "Checking session validity: ${currentSessionId.take(8)}...")
            
            val response = apiService.checkSession(
                sessionId = currentSessionId,
                name = KeyAuthConfig.APP_NAME,
                ownerId = KeyAuthConfig.OWNER_ID
            )
            
            if (response.isSuccessful) {
                val body = response.body()
                if (body?.success == true) {
                    Log.d(TAG, "Session validation successful")
                    NetworkResult.Success(body)
                } else {
                    val errorMessage = body?.message ?: "Session invalid"
                    Log.e(TAG, "Session validation failed: $errorMessage")
                    
                    // Clear invalid session
                    if (errorMessage.contains("session not found", ignoreCase = true)) {
                        clearSession()
                    }
                    
                    NetworkResult.Error(errorMessage)
                }
            } else {
                val errorMessage = "HTTP ${response.code()}: ${response.message()}"
                Log.e(TAG, "Session check HTTP error: $errorMessage")
                NetworkResult.Error(errorMessage)
            }
        } catch (e: Exception) {
            Log.e(TAG, "Session check exception", e)
            NetworkResult.Error("Session check error: ${e.message}", e)
        }
    }
    
    /**
     * Generate Hardware ID for device identification
     */
    private fun generateHWID(): String {
        // Try to get existing HWID first
        val existingHWID = securePreferences.getStoredHWID()
        if (!existingHWID.isNullOrEmpty()) {
            return existingHWID
        }
        
        // Generate new HWID
        val hwid = generatePersistentHWID()
        securePreferences.storeHWID(hwid)
        return hwid
    }
    
    /**
     * Generate persistent HWID using device characteristics
     */
    private fun generatePersistentHWID(): String {
        return try {
            val androidId = Settings.Secure.getString(context.contentResolver, Settings.Secure.ANDROID_ID) ?: "unknown"
            
            // Hardware identifiers
            val manufacturer = Build.MANUFACTURER ?: "unknown"
            val model = Build.MODEL ?: "unknown"
            val device = Build.DEVICE ?: "unknown"
            val board = Build.BOARD ?: "unknown"
            val brand = Build.BRAND ?: "unknown"
            val hardware = Build.HARDWARE ?: "unknown"
            
            // CPU architecture
            val cpuAbi = Build.SUPPORTED_ABIS?.firstOrNull() ?: "unknown"
            
            // Screen characteristics
            val displayMetrics = context.resources.displayMetrics
            val screenDensity = displayMetrics.densityDpi.toString()
            val screenWidth = displayMetrics.widthPixels.toString()
            val screenHeight = displayMetrics.heightPixels.toString()
            
            // Combine all identifiers
            val deviceFingerprint = listOf(
                manufacturer, model, device, board, brand, hardware,
                cpuAbi, screenDensity, screenWidth, screenHeight, androidId
            ).joinToString("-")
            
            // Generate SHA-256 hash
            val digest = MessageDigest.getInstance("SHA-256")
            val hash = digest.digest(deviceFingerprint.toByteArray())
            hash.joinToString("") { "%02x".format(it) }
            
        } catch (e: Exception) {
            Log.e(TAG, "Failed to generate HWID", e)
            // Fallback
            "${Build.MANUFACTURER}-${Build.MODEL}-${Build.DEVICE}".hashCode().toString()
        }
    }
    
    /**
     * Handle successful authentication
     */
    private fun handleSuccessfulAuthentication(licenseKey: String, hwid: String, response: KeyAuthResponse) {
        try {
            // Store session token
            val sessionToken = response.sessionId ?: ""
            val expiryTime = System.currentTimeMillis() + (KeyAuthConfig.SESSION_TIMEOUT_HOURS * 60 * 60 * 1000)
            securePreferences.storeSessionToken(sessionToken, expiryTime)
            
            // Register device
            securePreferences.setDeviceRegistered(hwid, licenseKey)
            
            // Store user info
            response.userInfo?.let { userInfo ->
                securePreferences.storeUserInfo(userInfo)
            }
            
            Log.d(TAG, "Authentication data stored successfully")
        } catch (e: Exception) {
            Log.e(TAG, "Failed to store authentication data", e)
        }
    }
    
    /**
     * Clear session data
     */
    fun clearSession() {
        synchronized(initializationLock) {
            sessionId = null
            isInitialized = false
        }
        securePreferences.clearSessionToken()
    }
    
    /**
     * Logout and clear all data
     */
    fun logout() {
        clearSession()
        securePreferences.clearAuthenticationData()
        Log.d(TAG, "Logout completed")
    }
    
    /**
     * Get current session ID
     */
    fun getSessionId(): String? = sessionId
    
    /**
     * Check if initialized
     */
    fun isInitialized(): Boolean = isInitialized
    
    /**
     * Get diagnostic information
     */
    fun getDiagnosticInfo(): Map<String, String> {
        return mapOf(
            "isInitialized" to isInitialized.toString(),
            "hasSessionId" to (sessionId != null).toString(),
            "sessionIdLength" to (sessionId?.length?.toString() ?: "0"),
            "configValid" to KeyAuthConfig.isConfigurationValid().toString()
        ) + KeyAuthConfig.getDiagnosticInfo() + securePreferences.getDiagnosticInfo()
    }
}
