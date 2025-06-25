package com.bearmod.auth;

import android.content.Context;
import android.os.Build;
import android.provider.Settings;
import android.util.Log;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.concurrent.CompletableFuture;

import okhttp3.FormBody;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

/**
 * Simple License Verifier for BearMod
 * Lightweight Java-only implementation without complex APIs or webhooks
 * Focuses on core license verification without interfering with target apps
 */
public class SimpleLicenseVerifier {
    private static final String TAG = "SimpleLicenseVerifier";
    
    // Simple configuration - only what's needed for KeyAuth API v1.3
    private static final String OWNER_ID = "yLoA9zcOEF";
    private static final String APP_NAME = "com.bearmod";
    private static final String VERSION = "1.3"; // Application version
    private static final String API_URL = "https://keyauth.win/api/1.3/";
    
    public interface LicenseCallback {
        void onSuccess(String message);
        void onFailure(String error);
    }
    
    /**
     * Simple license verification - initializes KeyAuth then checks license
     * 
     * @param context Application context
     * @param licenseKey License key to verify
     * @param callback Result callback
     */
    public static void verifyLicense(Context context, String licenseKey, LicenseCallback callback) {
        Log.d(TAG, "Starting KeyAuth initialization and license verification...");
        
        // Run in background thread to avoid blocking UI
        CompletableFuture.runAsync(() -> {
            try {
                // Create simple HTTP client
                OkHttpClient client = new OkHttpClient.Builder()
                        .connectTimeout(10, java.util.concurrent.TimeUnit.SECONDS)
                        .readTimeout(10, java.util.concurrent.TimeUnit.SECONDS)
                        .build();
                
                // Step 1: Initialize KeyAuth application (required before other functions)
                if (!initializeKeyAuth(client)) {
                    callback.onFailure("KeyAuth initialization failed");
                    return;
                }
                
                // Step 2: Generate simple HWID
                String hwid = generateSimpleHWID(context);
                
                // Step 3: Verify license
                verifyLicenseWithKeyAuth(client, licenseKey, hwid, callback);
                
            } catch (Exception e) {
                Log.e(TAG, "License verification error", e);
                callback.onFailure("Verification error: " + e.getMessage());
            }
        });
    }
    
    // Session ID storage
    private static String sessionId = null;
    
    /**
     * Initialize KeyAuth application and extract session ID
     */
    private static boolean initializeKeyAuth(OkHttpClient client) {
        try {
            Log.d(TAG, "Initializing KeyAuth application...");
            
            FormBody formBody = new FormBody.Builder()
                    .add("type", "init")
                    .add("name", APP_NAME)
                    .add("ownerid", OWNER_ID)
                    .add("ver", VERSION)
                    .build();
            
            Request request = new Request.Builder()
                    .url(API_URL)
                    .post(formBody)
                    .addHeader("User-Agent", "BearMod/1.0")
                    .build();
            
            try (Response response = client.newCall(request).execute()) {
                if (response.isSuccessful() && response.body() != null) {
                    String responseBody = response.body().string();
                    Log.d(TAG, "KeyAuth init response: " + responseBody);
                    
                    boolean success = responseBody.contains("\"success\":true") || 
                                     responseBody.contains("\"success\": true");
                    
                    if (success) {
                        // Extract session ID from response
                        sessionId = extractSessionId(responseBody);
                        if (sessionId != null) {
                            Log.d(TAG, "KeyAuth initialization successful, session ID: " + sessionId.substring(0, Math.min(8, sessionId.length())) + "...");
                            return true;
                        } else {
                            Log.e(TAG, "KeyAuth initialization failed: No session ID in response");
                            return false;
                        }
                    } else {
                        String errorMsg = extractErrorMessage(responseBody);
                        Log.e(TAG, "KeyAuth initialization failed: " + errorMsg);
                        return false;
                    }
                } else {
                    Log.e(TAG, "KeyAuth init failed: HTTP " + response.code());
                    return false;
                }
            }
            
        } catch (Exception e) {
            Log.e(TAG, "KeyAuth initialization exception", e);
            return false;
        }
    }
    
    /**
     * Verify license with KeyAuth (after initialization, using session ID)
     */
    private static void verifyLicenseWithKeyAuth(OkHttpClient client, String licenseKey, String hwid, LicenseCallback callback) {
        try {
            Log.d(TAG, "Verifying license with KeyAuth...");
            
            if (sessionId == null) {
                callback.onFailure("No session ID available - initialization may have failed");
                return;
            }
            
            FormBody formBody = new FormBody.Builder()
                    .add("type", "license")
                    .add("key", licenseKey)
                    .add("hwid", hwid)
                    .add("sessionid", sessionId)  // Required for API v1.3
                    .add("name", APP_NAME)
                    .add("ownerid", OWNER_ID)
                    .add("ver", VERSION)
                    .build();
            
            Request request = new Request.Builder()
                    .url(API_URL)
                    .post(formBody)
                    .addHeader("User-Agent", "BearMod/1.0")
                    .build();
            
            try (Response response = client.newCall(request).execute()) {
                if (response.isSuccessful() && response.body() != null) {
                    String responseBody = response.body().string();
                    Log.d(TAG, "License verification response: " + responseBody);
                    
                    boolean isValid = responseBody.contains("\"success\":true") || 
                                     responseBody.contains("\"success\": true");
                    
                    if (isValid) {
                        callback.onSuccess("License verified successfully");
                    } else {
                        String errorMsg = extractErrorMessage(responseBody);
                        callback.onFailure("License verification failed: " + errorMsg);
                    }
                } else {
                    callback.onFailure("Network error: " + response.code());
                }
            }
            
        } catch (Exception e) {
            Log.e(TAG, "License verification exception", e);
            callback.onFailure("License verification error: " + e.getMessage());
        }
    }
    
    /**
     * Generate simple hardware ID for license verification
     * Uses basic device identifiers without complex fingerprinting
     */
    private static String generateSimpleHWID(Context context) {
        try {
            StringBuilder hwid = new StringBuilder();
            
            // Device identifiers
            hwid.append(Build.MODEL).append("-");
            hwid.append(Build.MANUFACTURER).append("-");
            hwid.append(Build.DEVICE).append("-");
            
            // Android ID (simple unique identifier)
            String androidId = Settings.Secure.getString(
                context.getContentResolver(), 
                Settings.Secure.ANDROID_ID
            );
            if (androidId != null) {
                hwid.append(androidId);
            }
            
            // Generate MD5 hash for consistent length
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] hashBytes = md.digest(hwid.toString().getBytes());
            
            StringBuilder result = new StringBuilder();
            for (byte b : hashBytes) {
                result.append(String.format("%02x", b));
            }
            
            return result.toString();
            
        } catch (NoSuchAlgorithmException e) {
            Log.e(TAG, "MD5 not available", e);
            // Fallback to simple string hash
            return String.valueOf(Math.abs(Build.MODEL.hashCode()));
        }
    }
    
    /**
     * Extract session ID from KeyAuth init response
     */
    private static String extractSessionId(String responseBody) {
        try {
            // Extract session ID from JSON response
            if (responseBody.contains("\"sessionid\":")) {
                int start = responseBody.indexOf("\"sessionid\":\"") + 13;
                int end = responseBody.indexOf("\"", start);
                if (start > 12 && end > start) {
                    return responseBody.substring(start, end);
                }
            }
            return null;
        } catch (Exception e) {
            Log.e(TAG, "Failed to extract session ID", e);
            return null;
        }
    }
    
    /**
     * Extract error message from KeyAuth response
     */
    private static String extractErrorMessage(String responseBody) {
        try {
            // Simple error message extraction
            if (responseBody.contains("\"message\":")) {
                int start = responseBody.indexOf("\"message\":\"") + 11;
                int end = responseBody.indexOf("\"", start);
                if (start > 10 && end > start) {
                    return responseBody.substring(start, end);
                }
            }
            return "Unknown error";
        } catch (Exception e) {
            return "Unknown error";
        }
    }
    
    /**
     * Quick synchronous license check (for cases where you need immediate result)
     * Note: This blocks the calling thread, use sparingly and not on UI thread
     */
    public static boolean quickLicenseCheck(Context context, String licenseKey) {
        try {
            OkHttpClient client = new OkHttpClient.Builder()
                    .connectTimeout(5, java.util.concurrent.TimeUnit.SECONDS)
                    .readTimeout(5, java.util.concurrent.TimeUnit.SECONDS)
                    .build();
            
            // Step 1: Initialize KeyAuth (required)
            if (!initializeKeyAuth(client)) {
                Log.e(TAG, "Quick license check failed: KeyAuth initialization failed");
                return false;
            }
            
            // Step 2: Verify license
            String hwid = generateSimpleHWID(context);
            
            if (sessionId == null) {
                Log.e(TAG, "Quick license check failed: No session ID available");
                return false;
            }
            
            FormBody formBody = new FormBody.Builder()
                    .add("type", "license")
                    .add("key", licenseKey)
                    .add("hwid", hwid)
                    .add("sessionid", sessionId)  // Required for API v1.3
                    .add("name", APP_NAME)
                    .add("ownerid", OWNER_ID)
                    .add("ver", VERSION)
                    .build();
            
            Request request = new Request.Builder()
                    .url(API_URL)
                    .post(formBody)
                    .build();
            
            try (Response response = client.newCall(request).execute()) {
                if (response.isSuccessful() && response.body() != null) {
                    String responseBody = response.body().string();
                    return responseBody.contains("\"success\":true") || 
                           responseBody.contains("\"success\": true");
                }
            }
        } catch (Exception e) {
            Log.e(TAG, "Quick license check failed", e);
        }
        return false;
    }
    
    /**
     * Get the generated HWID for this device (for debugging/logging)
     */
    public static String getDeviceHWID(Context context) {
        return generateSimpleHWID(context);
    }
} 