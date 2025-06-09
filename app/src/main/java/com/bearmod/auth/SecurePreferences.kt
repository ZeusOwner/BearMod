package com.bearmod.auth

import android.content.Context
import android.content.SharedPreferences
import android.util.Log

/**
 * Secure preferences for storing sensitive authentication data
 * Uses standard SharedPreferences with basic security measures
 * Note: For production, consider using EncryptedSharedPreferences
 */
class SecurePreferences(private val context: Context) {
    
    companion object {
        private const val TAG = "SecurePreferences"
        private const val PREFS_NAME = "bearmod_auth_prefs"
        
        // Keys for stored data
        private const val KEY_SESSION_TOKEN = "session_token"
        private const val KEY_SESSION_EXPIRY = "session_expiry"
        private const val KEY_REFRESH_TOKEN = "refresh_token"
        private const val KEY_HWID = "hwid"
        private const val KEY_LAST_AUTH_HWID = "last_auth_hwid"
        private const val KEY_BOUND_LICENSE = "bound_license"
        private const val KEY_DEVICE_REGISTERED = "device_registered"
        private const val KEY_DEVICE_TRUST_LEVEL = "device_trust_level"
        private const val KEY_LAST_AUTH_TIME = "last_auth_time"
        private const val KEY_AUTH_COUNT = "auth_count"
        private const val KEY_USER_INFO = "user_info"
    }
    
    private val sharedPreferences: SharedPreferences by lazy {
        context.getSharedPreferences(PREFS_NAME, Context.MODE_PRIVATE)
    }
    
    /**
     * Store session token with expiry time
     */
    fun storeSessionToken(token: String, expiryTime: Long) {
        sharedPreferences.edit()
            .putString(KEY_SESSION_TOKEN, token)
            .putLong(KEY_SESSION_EXPIRY, expiryTime)
            .apply()
    }
    
    /**
     * Get stored session token
     */
    fun getSessionToken(): String? {
        return sharedPreferences.getString(KEY_SESSION_TOKEN, null)
    }
    
    /**
     * Check if session token is valid (not expired)
     */
    fun isSessionTokenValid(): Boolean {
        val token = getSessionToken()
        val expiry = sharedPreferences.getLong(KEY_SESSION_EXPIRY, 0L)
        
        return !token.isNullOrEmpty() && 
               expiry > 0L && 
               System.currentTimeMillis() < expiry
    }
    
    /**
     * Clear session token
     */
    fun clearSessionToken() {
        sharedPreferences.edit()
            .remove(KEY_SESSION_TOKEN)
            .remove(KEY_SESSION_EXPIRY)
            .apply()
    }
    
    /**
     * Store refresh token
     */
    fun storeRefreshToken(token: String) {
        sharedPreferences.edit()
            .putString(KEY_REFRESH_TOKEN, token)
            .apply()
    }
    
    /**
     * Get refresh token
     */
    fun getRefreshToken(): String? {
        return sharedPreferences.getString(KEY_REFRESH_TOKEN, null)
    }
    
    /**
     * Clear refresh token
     */
    fun clearRefreshToken() {
        sharedPreferences.edit()
            .remove(KEY_REFRESH_TOKEN)
            .apply()
    }
    
    /**
     * Store HWID
     */
    fun storeHWID(hwid: String) {
        sharedPreferences.edit()
            .putString(KEY_HWID, hwid)
            .apply()
    }
    
    /**
     * Get stored HWID
     */
    fun getStoredHWID(): String? {
        return sharedPreferences.getString(KEY_HWID, null)
    }
    
    /**
     * Store last authentication HWID
     */
    fun storeLastAuthHWID(hwid: String) {
        sharedPreferences.edit()
            .putString(KEY_LAST_AUTH_HWID, hwid)
            .apply()
    }
    
    /**
     * Get last authentication HWID
     */
    fun getLastAuthHWID(): String? {
        return sharedPreferences.getString(KEY_LAST_AUTH_HWID, null)
    }
    
    /**
     * Set device as registered with license key
     */
    fun setDeviceRegistered(hwid: String, licenseKey: String) {
        sharedPreferences.edit()
            .putBoolean(KEY_DEVICE_REGISTERED, true)
            .putString(KEY_BOUND_LICENSE, licenseKey)
            .putString(KEY_LAST_AUTH_HWID, hwid)
            .putLong(KEY_LAST_AUTH_TIME, System.currentTimeMillis())
            .putInt(KEY_AUTH_COUNT, getAuthCount() + 1)
            .apply()
    }
    
    /**
     * Check if device is registered
     */
    fun isDeviceRegistered(): Boolean {
        return sharedPreferences.getBoolean(KEY_DEVICE_REGISTERED, false)
    }
    
    /**
     * Get bound license key
     */
    fun getBoundLicenseKey(): String? {
        return sharedPreferences.getString(KEY_BOUND_LICENSE, null)
    }
    
    /**
     * Set device trust level
     */
    fun setDeviceTrustLevel(level: Int) {
        sharedPreferences.edit()
            .putInt(KEY_DEVICE_TRUST_LEVEL, level)
            .apply()
    }
    
    /**
     * Get device trust level
     */
    fun getDeviceTrustLevel(): Int {
        return sharedPreferences.getInt(KEY_DEVICE_TRUST_LEVEL, 0)
    }
    
    /**
     * Get authentication count
     */
    fun getAuthCount(): Int {
        return sharedPreferences.getInt(KEY_AUTH_COUNT, 0)
    }
    
    /**
     * Get last authentication time
     */
    fun getLastAuthTime(): Long {
        return sharedPreferences.getLong(KEY_LAST_AUTH_TIME, 0L)
    }
    
    /**
     * Store user info as JSON
     */
    fun storeUserInfo(userInfo: UserInfo) {
        try {
            val gson = com.google.gson.Gson()
            val json = gson.toJson(userInfo)
            sharedPreferences.edit()
                .putString(KEY_USER_INFO, json)
                .apply()
        } catch (e: Exception) {
            Log.e(TAG, "Failed to store user info", e)
        }
    }
    
    /**
     * Get stored user info
     */
    fun getUserInfo(): UserInfo? {
        return try {
            val json = sharedPreferences.getString(KEY_USER_INFO, null)
            if (json != null) {
                val gson = com.google.gson.Gson()
                gson.fromJson(json, UserInfo::class.java)
            } else {
                null
            }
        } catch (e: Exception) {
            Log.e(TAG, "Failed to retrieve user info", e)
            null
        }
    }
    
    /**
     * Clear all authentication data
     */
    fun clearAuthenticationData() {
        sharedPreferences.edit()
            .remove(KEY_SESSION_TOKEN)
            .remove(KEY_SESSION_EXPIRY)
            .remove(KEY_REFRESH_TOKEN)
            .remove(KEY_BOUND_LICENSE)
            .remove(KEY_DEVICE_REGISTERED)
            .remove(KEY_DEVICE_TRUST_LEVEL)
            .remove(KEY_LAST_AUTH_TIME)
            .remove(KEY_AUTH_COUNT)
            .remove(KEY_USER_INFO)
            .apply()
    }
    
    /**
     * Clear all stored data (including HWID)
     */
    fun clearAllData() {
        sharedPreferences.edit().clear().apply()
    }
    
    /**
     * Get diagnostic information
     */
    fun getDiagnosticInfo(): Map<String, String> {
        return mapOf(
            "hasSessionToken" to (getSessionToken() != null).toString(),
            "isSessionValid" to isSessionTokenValid().toString(),
            "hasRefreshToken" to (getRefreshToken() != null).toString(),
            "hasStoredHWID" to (getStoredHWID() != null).toString(),
            "isDeviceRegistered" to isDeviceRegistered().toString(),
            "deviceTrustLevel" to getDeviceTrustLevel().toString(),
            "authCount" to getAuthCount().toString(),
            "lastAuthTime" to getLastAuthTime().toString(),
            "hasUserInfo" to (getUserInfo() != null).toString()
        )
    }
}
