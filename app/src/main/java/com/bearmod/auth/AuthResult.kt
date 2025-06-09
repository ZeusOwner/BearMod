package com.bearmod.auth

import com.google.gson.annotations.SerializedName

/**
 * Authentication result data class for BearMod KeyAuth integration
 * Contains success status, subscription tier, and error messages
 */
data class AuthResult(
    /**
     * Whether the authentication was successful
     */
    val success: Boolean,
    
    /**
     * Subscription tier (e.g., "basic", "pro", "premium")
     * Null if authentication failed
     */
    val tier: String? = null,
    
    /**
     * Error or success message
     */
    val message: String? = null,
    
    /**
     * Session ID for authenticated users
     */
    val sessionId: String? = null,
    
    /**
     * User information if authentication successful
     */
    val userInfo: UserInfo? = null,
    
    /**
     * Hardware ID used for authentication
     */
    val hwid: String? = null,
    
    /**
     * License key that was validated
     */
    val licenseKey: String? = null
) {
    /**
     * Check if the result represents a successful authentication
     */
    fun isAuthenticated(): Boolean = success && !sessionId.isNullOrEmpty()
    
    /**
     * Get the subscription tier or default to "basic"
     */
    fun getSubscriptionTier(): String = tier ?: "basic"
    
    /**
     * Check if user has premium features
     */
    fun hasPremiumFeatures(): Boolean = tier in listOf("pro", "premium")
    
    /**
     * Get display message for UI
     */
    fun getDisplayMessage(): String = message ?: if (success) "Authentication successful" else "Authentication failed"
}

/**
 * User information returned after successful authentication
 */
data class UserInfo(
    @SerializedName("username")
    val username: String? = null,
    
    @SerializedName("ip")
    val ip: String? = null,
    
    @SerializedName("hwid")
    val hwid: String? = null,
    
    @SerializedName("createdate")
    val createDate: String? = null,
    
    @SerializedName("lastlogin")
    val lastLogin: String? = null,
    
    @SerializedName("subscriptions")
    val subscriptions: List<Subscription>? = null
) {
    /**
     * Get the primary subscription tier
     */
    fun getPrimarySubscriptionTier(): String {
        return subscriptions?.firstOrNull()?.name ?: "basic"
    }
    
    /**
     * Check if user has active subscription
     */
    fun hasActiveSubscription(): Boolean {
        return subscriptions?.any { it.isActive() } ?: false
    }
    
    /**
     * Get subscription expiry time
     */
    fun getSubscriptionExpiry(): Long {
        return subscriptions?.firstOrNull()?.getExpiryTime() ?: 0L
    }
}

/**
 * Subscription information
 */
data class Subscription(
    @SerializedName("subscription")
    val name: String,
    
    @SerializedName("expiry")
    val expiry: String,
    
    @SerializedName("timeleft")
    val timeLeft: Long? = null
) {
    /**
     * Check if subscription is still active
     */
    fun isActive(): Boolean {
        return timeLeft?.let { it > 0 } ?: false
    }
    
    /**
     * Get expiry time as timestamp
     */
    fun getExpiryTime(): Long {
        return try {
            // Parse expiry string to timestamp
            // KeyAuth typically returns Unix timestamp as string
            expiry.toLongOrNull() ?: 0L
        } catch (e: Exception) {
            0L
        }
    }
    
    /**
     * Get time left in human readable format
     */
    fun getTimeLeftFormatted(): String {
        val timeLeftMs = timeLeft ?: 0L
        if (timeLeftMs <= 0) return "Expired"
        
        val days = timeLeftMs / (24 * 60 * 60 * 1000)
        val hours = (timeLeftMs % (24 * 60 * 60 * 1000)) / (60 * 60 * 1000)
        
        return when {
            days > 0 -> "${days}d ${hours}h"
            hours > 0 -> "${hours}h"
            else -> "< 1h"
        }
    }
}
