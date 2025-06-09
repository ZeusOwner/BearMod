package com.bearmod.auth

import android.content.Context
import android.util.Log
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext

/**
 * Enhanced License Manager for BearMod with KeyAuth integration
 * Singleton object that provides license validation functionality
 */
object LicenseManager {
    
    private const val TAG = "LicenseManager"
    
    @Volatile
    private var keyAuth: KeyAuth? = null
    
    @Volatile
    private var isInitialized = false
    
    private val initializationLock = Any()
    
    /**
     * Initialize the License Manager with application context
     */
    fun initialize(context: Context) {
        synchronized(initializationLock) {
            if (!isInitialized) {
                keyAuth = KeyAuth.getInstance(context.applicationContext)
                isInitialized = true
                Log.d(TAG, "LicenseManager initialized")
            }
        }
    }
    
    /**
     * Validate license key using KeyAuth
     * Returns AuthResult containing success status and subscription tier
     */
    suspend fun validate(licenseKey: String): AuthResult = withContext(Dispatchers.IO) {
        try {
            if (!isInitialized) {
                Log.e(TAG, "LicenseManager not initialized")
                return@withContext AuthResult(
                    success = false,
                    message = "License manager not initialized"
                )
            }
            
            val keyAuthInstance = keyAuth ?: run {
                Log.e(TAG, "KeyAuth instance not available")
                return@withContext AuthResult(
                    success = false,
                    message = "KeyAuth not available"
                )
            }
            
            Log.d(TAG, "Validating license key: ${licenseKey.take(8)}...")
            
            // Validate configuration before proceeding
            if (!KeyAuthConfig.isConfigurationValid()) {
                val errors = KeyAuthConfig.getConfigurationErrors()
                Log.e(TAG, "KeyAuth configuration invalid: ${errors.joinToString(", ")}")
                return@withContext AuthResult(
                    success = false,
                    message = "Configuration error: Please contact support"
                )
            }
            
            // Perform license validation
            val result = keyAuthInstance.validateLicense(licenseKey)
            
            if (result.success) {
                Log.i(TAG, "License validation successful - Tier: ${result.tier}")
            } else {
                Log.w(TAG, "License validation failed: ${result.message}")
            }
            
            return@withContext result
            
        } catch (e: Exception) {
            Log.e(TAG, "License validation error", e)
            return@withContext AuthResult(
                success = false,
                message = "Validation error: ${e.message}"
            )
        }
    }
    
    /**
     * Check if current session is valid
     */
    suspend fun checkSession(): AuthResult = withContext(Dispatchers.IO) {
        try {
            val keyAuthInstance = keyAuth ?: run {
                return@withContext AuthResult(
                    success = false,
                    message = "KeyAuth not available"
                )
            }
            
            val sessionResult = keyAuthInstance.checkSession()
            
            return@withContext when (sessionResult) {
                is NetworkResult.Success -> {
                    sessionResult.data.toAuthResult()
                }
                is NetworkResult.Error -> {
                    AuthResult(
                        success = false,
                        message = sessionResult.message
                    )
                }
                else -> {
                    AuthResult(
                        success = false,
                        message = "Unknown session check error"
                    )
                }
            }
        } catch (e: Exception) {
            Log.e(TAG, "Session check error", e)
            return@withContext AuthResult(
                success = false,
                message = "Session check error: ${e.message}"
            )
        }
    }
    
    /**
     * Get available features for a subscription tier
     */
    fun getAvailableFeatures(tier: String): Set<String> {
        return KeyAuthConfig.getPermissionsForTier(tier)
    }
    
    /**
     * Check if a feature is available for a subscription tier
     */
    fun isFeatureAvailable(feature: String, tier: String): Boolean {
        return KeyAuthConfig.isFeatureAvailable(feature, tier)
    }
    
    /**
     * Get subscription tier display name
     */
    fun getTierDisplayName(tier: String): String {
        return when (tier.lowercase()) {
            "basic" -> "Basic"
            "pro" -> "Pro"
            "premium" -> "Premium"
            else -> "Unknown"
        }
    }
    
    /**
     * Get tier description
     */
    fun getTierDescription(tier: String): String {
        return when (tier.lowercase()) {
            "basic" -> "Basic features including ESP and basic aimbot"
            "pro" -> "Advanced features with enhanced ESP and aimbot"
            "premium" -> "All features including premium hacks and custom skins"
            else -> "Unknown subscription tier"
        }
    }
    
    /**
     * Get current session ID
     */
    fun getSessionId(): String? {
        return keyAuth?.getSessionId()
    }
    
    /**
     * Check if KeyAuth is initialized
     */
    fun isKeyAuthInitialized(): Boolean {
        return keyAuth?.isInitialized() ?: false
    }
    
    /**
     * Logout and clear session
     */
    fun logout() {
        keyAuth?.logout()
        Log.d(TAG, "User logged out")
    }
    
    /**
     * Clear session data
     */
    fun clearSession() {
        keyAuth?.clearSession()
        Log.d(TAG, "Session cleared")
    }
    
    /**
     * Get diagnostic information for troubleshooting
     */
    fun getDiagnosticInfo(): Map<String, String> {
        val baseInfo = mapOf(
            "isInitialized" to isInitialized.toString(),
            "hasKeyAuth" to (keyAuth != null).toString()
        )
        
        return if (keyAuth != null) {
            baseInfo + keyAuth!!.getDiagnosticInfo()
        } else {
            baseInfo
        }
    }
    
    /**
     * Test network connectivity to KeyAuth API
     */
    suspend fun testConnectivity(): NetworkResult<String> = withContext(Dispatchers.IO) {
        return@withContext try {
            NetworkFactory.testConnectivity()
        } catch (e: Exception) {
            Log.e(TAG, "Connectivity test failed", e)
            NetworkResult.Error("Connectivity test failed: ${e.message}", e)
        }
    }
    
    /**
     * Validate KeyAuth configuration
     */
    fun validateConfiguration(): Pair<Boolean, List<String>> {
        val isValid = KeyAuthConfig.isConfigurationValid()
        val errors = if (!isValid) KeyAuthConfig.getConfigurationErrors() else emptyList()
        return Pair(isValid, errors)
    }
    
    /**
     * Attempt to restore session from stored data
     */
    suspend fun attemptSessionRestore(): AuthResult = withContext(Dispatchers.IO) {
        try {
            if (!isInitialized) {
                return@withContext AuthResult(
                    success = false,
                    message = "License manager not initialized"
                )
            }
            
            // Check if we have stored session data
            val keyAuthInstance = keyAuth ?: return@withContext AuthResult(
                success = false,
                message = "KeyAuth not available"
            )
            
            // Try to restore session
            val sessionResult = keyAuthInstance.checkSession()
            
            return@withContext when (sessionResult) {
                is NetworkResult.Success -> {
                    Log.d(TAG, "Session restored successfully")
                    sessionResult.data.toAuthResult()
                }
                is NetworkResult.Error -> {
                    Log.d(TAG, "Session restore failed: ${sessionResult.message}")
                    AuthResult(
                        success = false,
                        message = "No valid session found"
                    )
                }
                else -> {
                    AuthResult(
                        success = false,
                        message = "Session restore failed"
                    )
                }
            }
        } catch (e: Exception) {
            Log.e(TAG, "Session restore error", e)
            return@withContext AuthResult(
                success = false,
                message = "Session restore error: ${e.message}"
            )
        }
    }
}
