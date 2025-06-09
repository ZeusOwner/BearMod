package com.bearmod.auth

/**
 * KeyAuth configuration constants for BearMod
 * 
 * IMPORTANT: Replace these values with your actual KeyAuth application details
 * Get these from your KeyAuth dashboard at https://keyauth.cc/app/
 */
object KeyAuthConfig {
    
    /**
     * Your application name from KeyAuth dashboard
     * Found on the main application page
     */
    const val APP_NAME = "com.bearmod"

    /**
     * Your owner ID from KeyAuth account settings
     * Click your profile picture -> Account Settings
     * 
     * TODO: Replace with your actual KeyAuth owner ID
     */
    const val OWNER_ID = "YOUR_OWNER_ID_HERE"

    /**
     * Your application version
     * Should match the version in your KeyAuth dashboard
     */
    const val APP_VERSION = "3.8.0"

    /**
     * Custom KeyAuth hash for integrity checking
     * This hash is used for additional security validation
     * 
     * TODO: Replace with your actual KeyAuth application hash
     */
    const val CUSTOM_HASH = "YOUR_CUSTOM_HASH_HERE"
    
    /**
     * KeyAuth API base URL
     * For API v1.3, use: https://keyauth.win/api/1.3/
     * You can also use your custom domain if configured
     */
    const val API_BASE_URL = "https://keyauth.win/api/1.3/"
    
    /**
     * Application display name for UI
     */
    const val APP_DISPLAY_NAME = "BearMod"
    
    /**
     * Application version for display
     */
    const val APP_DISPLAY_VERSION = "3.8.0"
    
    /**
     * Network configuration
     */
    const val CONNECT_TIMEOUT_SECONDS = 30L
    const val READ_TIMEOUT_SECONDS = 30L
    const val WRITE_TIMEOUT_SECONDS = 30L
    
    /**
     * Session configuration
     */
    const val SESSION_TIMEOUT_HOURS = 24L
    const val MAX_RETRY_ATTEMPTS = 3
    const val RETRY_DELAY_MS = 1000L
    
    /**
     * Security configuration
     */
    const val ENABLE_CERTIFICATE_PINNING = true
    const val ENABLE_REQUEST_LOGGING = false // Set to true for debugging
    
    /**
     * Subscription tiers mapping
     * Maps KeyAuth subscription names to BearMod tiers
     */
    val SUBSCRIPTION_TIER_MAPPING = mapOf(
        "default" to "basic",
        "basic" to "basic",
        "pro" to "pro",
        "premium" to "premium",
        "vip" to "premium"
    )
    
    /**
     * Feature permissions by tier
     */
    val TIER_PERMISSIONS = mapOf(
        "basic" to setOf(
            "esp_basic",
            "aimbot_basic",
            "wallhack_basic"
        ),
        "pro" to setOf(
            "esp_basic",
            "esp_advanced",
            "aimbot_basic",
            "aimbot_advanced",
            "wallhack_basic",
            "wallhack_advanced",
            "speed_hack",
            "no_recoil"
        ),
        "premium" to setOf(
            "esp_basic",
            "esp_advanced",
            "esp_premium",
            "aimbot_basic",
            "aimbot_advanced",
            "aimbot_premium",
            "wallhack_basic",
            "wallhack_advanced",
            "wallhack_premium",
            "speed_hack",
            "no_recoil",
            "fly_hack",
            "god_mode",
            "unlimited_ammo",
            "custom_skins"
        )
    )
    
    /**
     * Get permissions for a subscription tier
     */
    fun getPermissionsForTier(tier: String): Set<String> {
        return TIER_PERMISSIONS[tier] ?: TIER_PERMISSIONS["basic"] ?: emptySet()
    }
    
    /**
     * Map KeyAuth subscription to BearMod tier
     */
    fun mapSubscriptionToTier(subscription: String): String {
        return SUBSCRIPTION_TIER_MAPPING[subscription.lowercase()] ?: "basic"
    }
    
    /**
     * Check if a feature is available for a tier
     */
    fun isFeatureAvailable(feature: String, tier: String): Boolean {
        return getPermissionsForTier(tier).contains(feature)
    }
    
    /**
     * Validate configuration
     * Returns true if all required fields are properly configured
     */
    fun isConfigurationValid(): Boolean {
        return APP_NAME.isNotBlank() &&
               OWNER_ID.isNotBlank() &&
               OWNER_ID != "YOUR_OWNER_ID_HERE" &&
               APP_VERSION.isNotBlank() &&
               CUSTOM_HASH.isNotBlank() &&
               CUSTOM_HASH != "YOUR_CUSTOM_HASH_HERE" &&
               API_BASE_URL.isNotBlank()
    }
    
    /**
     * Get configuration validation errors
     */
    fun getConfigurationErrors(): List<String> {
        val errors = mutableListOf<String>()
        
        if (APP_NAME.isBlank()) {
            errors.add("APP_NAME is not configured")
        }
        
        if (OWNER_ID.isBlank() || OWNER_ID == "YOUR_OWNER_ID_HERE") {
            errors.add("OWNER_ID is not configured - please set your KeyAuth owner ID")
        }
        
        if (APP_VERSION.isBlank()) {
            errors.add("APP_VERSION is not configured")
        }
        
        if (CUSTOM_HASH.isBlank() || CUSTOM_HASH == "YOUR_CUSTOM_HASH_HERE") {
            errors.add("CUSTOM_HASH is not configured - please set your KeyAuth application hash")
        }
        
        if (API_BASE_URL.isBlank()) {
            errors.add("API_BASE_URL is not configured")
        }
        
        return errors
    }
    
    /**
     * Get diagnostic information for troubleshooting
     */
    fun getDiagnosticInfo(): Map<String, String> {
        return mapOf(
            "appName" to APP_NAME,
            "ownerId" to if (OWNER_ID == "YOUR_OWNER_ID_HERE") "NOT_CONFIGURED" else OWNER_ID.take(8) + "...",
            "appVersion" to APP_VERSION,
            "customHash" to if (CUSTOM_HASH == "YOUR_CUSTOM_HASH_HERE") "NOT_CONFIGURED" else CUSTOM_HASH.take(8) + "...",
            "apiBaseUrl" to API_BASE_URL,
            "isValid" to isConfigurationValid().toString()
        )
    }
}
