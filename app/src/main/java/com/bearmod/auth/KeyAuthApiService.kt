package com.bearmod.auth

import com.google.gson.annotations.SerializedName
import retrofit2.Response
import retrofit2.http.Field
import retrofit2.http.FormUrlEncoded
import retrofit2.http.POST

/**
 * KeyAuth API service interface for BearMod v1.3 API
 * Note: API v1.3 does NOT require application secret
 */
interface KeyAuthApiService {
    
    /**
     * Initialize the application
     * Added hash parameter for KeyAuth integrity checking
     */
    @FormUrlEncoded
    @POST(".")
    suspend fun init(
        @Field("type") type: String = "init",
        @Field("ver") version: String,
        @Field("name") name: String,
        @Field("ownerid") ownerId: String,
        @Field("hash") hash: String? = null
    ): Response<KeyAuthResponse>
    
    /**
     * Authenticate with license key
     */
    @FormUrlEncoded
    @POST(".")
    suspend fun license(
        @Field("type") type: String = "license",
        @Field("key") licenseKey: String,
        @Field("hwid") hwid: String,
        @Field("sessionid") sessionId: String,
        @Field("name") name: String,
        @Field("ownerid") ownerId: String
    ): Response<KeyAuthResponse>
    
    /**
     * Check session validity
     */
    @FormUrlEncoded
    @POST(".")
    suspend fun checkSession(
        @Field("type") type: String = "check",
        @Field("sessionid") sessionId: String,
        @Field("name") name: String,
        @Field("ownerid") ownerId: String
    ): Response<KeyAuthResponse>
    
    /**
     * Get application statistics
     */
    @FormUrlEncoded
    @POST(".")
    suspend fun fetchStats(
        @Field("type") type: String = "fetchstats",
        @Field("sessionid") sessionId: String,
        @Field("name") name: String,
        @Field("ownerid") ownerId: String
    ): Response<AppInfo>
    
    /**
     * Log user activity
     */
    @FormUrlEncoded
    @POST(".")
    suspend fun log(
        @Field("type") type: String = "log",
        @Field("pcuser") pcUser: String,
        @Field("message") message: String,
        @Field("sessionid") sessionId: String,
        @Field("name") name: String,
        @Field("ownerid") ownerId: String
    ): Response<KeyAuthResponse>
}

/**
 * Base response model for KeyAuth API
 */
data class KeyAuthResponse(
    @SerializedName("success")
    val success: Boolean,
    
    @SerializedName("message")
    val message: String,
    
    @SerializedName("sessionid")
    val sessionId: String? = null,
    
    @SerializedName("info")
    val userInfo: UserInfo? = null
) {
    /**
     * Convert to BearMod AuthResult
     */
    fun toAuthResult(licenseKey: String? = null, hwid: String? = null): AuthResult {
        val tier = userInfo?.getPrimarySubscriptionTier() ?: "basic"
        
        return AuthResult(
            success = success,
            tier = tier,
            message = message,
            sessionId = sessionId,
            userInfo = userInfo,
            hwid = hwid,
            licenseKey = licenseKey
        )
    }
}

/**
 * Application information response
 */
data class AppInfo(
    @SerializedName("numUsers")
    val numUsers: String? = null,
    
    @SerializedName("numOnlineUsers") 
    val numOnlineUsers: String? = null,
    
    @SerializedName("numKeys")
    val numKeys: String? = null,
    
    @SerializedName("version")
    val version: String? = null,
    
    @SerializedName("customerPanelLink")
    val customerPanelLink: String? = null
)

/**
 * Network result wrapper for API responses
 */
sealed class NetworkResult<T> {
    data class Success<T>(val data: T) : NetworkResult<T>()
    data class Error<T>(val message: String, val exception: Throwable? = null) : NetworkResult<T>()
    data class Loading<T>(val message: String = "Loading...") : NetworkResult<T>()
    
    /**
     * Check if result is successful
     */
    fun isSuccess(): Boolean = this is Success
    
    /**
     * Check if result is error
     */
    fun isError(): Boolean = this is Error
    
    /**
     * Check if result is loading
     */
    fun isLoading(): Boolean = this is Loading
    
    /**
     * Get data if successful, null otherwise
     */
    fun getDataOrNull(): T? = if (this is Success) data else null
    
    /**
     * Get error message if error, null otherwise
     */
    fun getErrorMessage(): String? = if (this is Error) message else null
    
    /**
     * Map the result to another type
     */
    inline fun <R> map(transform: (T) -> R): NetworkResult<R> {
        return when (this) {
            is Success -> Success(transform(data))
            is Error -> Error(message, exception)
            is Loading -> Loading(message)
        }
    }
    
    /**
     * Execute action if successful
     */
    inline fun onSuccess(action: (T) -> Unit): NetworkResult<T> {
        if (this is Success) action(data)
        return this
    }
    
    /**
     * Execute action if error
     */
    inline fun onError(action: (String, Throwable?) -> Unit): NetworkResult<T> {
        if (this is Error) action(message, exception)
        return this
    }
    
    /**
     * Execute action if loading
     */
    inline fun onLoading(action: (String) -> Unit): NetworkResult<T> {
        if (this is Loading) action(message)
        return this
    }
}
