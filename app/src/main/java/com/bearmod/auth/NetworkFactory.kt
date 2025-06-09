package com.bearmod.auth

import android.util.Log
import com.google.gson.Gson
import com.google.gson.GsonBuilder
import okhttp3.CertificatePinner
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory
import java.util.concurrent.TimeUnit

/**
 * Network factory for creating KeyAuth API service with proper configuration
 */
object NetworkFactory {
    
    private const val TAG = "NetworkFactory"
    
    /**
     * Create KeyAuth API service with proper configuration
     */
    fun createKeyAuthService(): KeyAuthApiService {
        val okHttpClient = createOkHttpClient()
        val gson = createGson()
        
        val retrofit = Retrofit.Builder()
            .baseUrl(KeyAuthConfig.API_BASE_URL)
            .client(okHttpClient)
            .addConverterFactory(GsonConverterFactory.create(gson))
            .build()
        
        return retrofit.create(KeyAuthApiService::class.java)
    }
    
    /**
     * Create configured OkHttp client
     */
    private fun createOkHttpClient(): OkHttpClient {
        val builder = OkHttpClient.Builder()
            .connectTimeout(KeyAuthConfig.CONNECT_TIMEOUT_SECONDS, TimeUnit.SECONDS)
            .readTimeout(KeyAuthConfig.READ_TIMEOUT_SECONDS, TimeUnit.SECONDS)
            .writeTimeout(KeyAuthConfig.WRITE_TIMEOUT_SECONDS, TimeUnit.SECONDS)
            .retryOnConnectionFailure(true)
        
        // Add logging interceptor for debugging
        if (KeyAuthConfig.ENABLE_REQUEST_LOGGING) {
            val loggingInterceptor = HttpLoggingInterceptor { message ->
                Log.d(TAG, message)
            }.apply {
                level = HttpLoggingInterceptor.Level.BODY
            }
            builder.addInterceptor(loggingInterceptor)
        }
        
        // Add certificate pinning for security
        if (KeyAuthConfig.ENABLE_CERTIFICATE_PINNING) {
            val certificatePinner = CertificatePinner.Builder()
                .add("keyauth.win", "sha256/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA=") // TODO: Add actual certificate pin
                .build()
            builder.certificatePinner(certificatePinner)
        }
        
        // Add custom headers
        builder.addInterceptor { chain ->
            val request = chain.request().newBuilder()
                .addHeader("User-Agent", "BearMod/${KeyAuthConfig.APP_VERSION}")
                .addHeader("Accept", "application/json")
                .addHeader("Content-Type", "application/x-www-form-urlencoded")
                .build()
            chain.proceed(request)
        }
        
        return builder.build()
    }
    
    /**
     * Create configured Gson instance
     */
    private fun createGson(): Gson {
        return GsonBuilder()
            .setLenient()
            .serializeNulls()
            .create()
    }
    
    /**
     * Create a simple HTTP client for basic requests (without certificate pinning)
     */
    fun createSimpleHttpClient(): OkHttpClient {
        return OkHttpClient.Builder()
            .connectTimeout(KeyAuthConfig.CONNECT_TIMEOUT_SECONDS, TimeUnit.SECONDS)
            .readTimeout(KeyAuthConfig.READ_TIMEOUT_SECONDS, TimeUnit.SECONDS)
            .writeTimeout(KeyAuthConfig.WRITE_TIMEOUT_SECONDS, TimeUnit.SECONDS)
            .retryOnConnectionFailure(true)
            .addInterceptor { chain ->
                val request = chain.request().newBuilder()
                    .addHeader("User-Agent", "BearMod/${KeyAuthConfig.APP_VERSION}")
                    .build()
                chain.proceed(request)
            }
            .build()
    }
    
    /**
     * Test network connectivity to KeyAuth API
     */
    suspend fun testConnectivity(): NetworkResult<String> {
        return try {
            val client = createSimpleHttpClient()
            val request = okhttp3.Request.Builder()
                .url(KeyAuthConfig.API_BASE_URL)
                .head()
                .build()
            
            val response = client.newCall(request).execute()
            
            if (response.isSuccessful) {
                NetworkResult.Success("Connection successful")
            } else {
                NetworkResult.Error("HTTP ${response.code}: ${response.message}")
            }
        } catch (e: Exception) {
            Log.e(TAG, "Network connectivity test failed", e)
            NetworkResult.Error("Network error: ${e.message}", e)
        }
    }
    
    /**
     * Validate KeyAuth API endpoint
     */
    suspend fun validateApiEndpoint(): NetworkResult<Boolean> {
        return try {
            val service = createKeyAuthService()
            
            // Try to make a simple init call to validate the endpoint
            val response = service.init(
                version = KeyAuthConfig.APP_VERSION,
                name = KeyAuthConfig.APP_NAME,
                ownerId = KeyAuthConfig.OWNER_ID,
                hash = KeyAuthConfig.CUSTOM_HASH
            )
            
            if (response.isSuccessful) {
                NetworkResult.Success(true)
            } else {
                NetworkResult.Error("API endpoint validation failed: HTTP ${response.code()}")
            }
        } catch (e: Exception) {
            Log.e(TAG, "API endpoint validation failed", e)
            NetworkResult.Error("API validation error: ${e.message}", e)
        }
    }
    
    /**
     * Get network diagnostic information
     */
    fun getNetworkDiagnostics(): Map<String, String> {
        return mapOf(
            "baseUrl" to KeyAuthConfig.API_BASE_URL,
            "connectTimeout" to "${KeyAuthConfig.CONNECT_TIMEOUT_SECONDS}s",
            "readTimeout" to "${KeyAuthConfig.READ_TIMEOUT_SECONDS}s",
            "writeTimeout" to "${KeyAuthConfig.WRITE_TIMEOUT_SECONDS}s",
            "certificatePinning" to KeyAuthConfig.ENABLE_CERTIFICATE_PINNING.toString(),
            "requestLogging" to KeyAuthConfig.ENABLE_REQUEST_LOGGING.toString(),
            "userAgent" to "BearMod/${KeyAuthConfig.APP_VERSION}"
        )
    }
}
