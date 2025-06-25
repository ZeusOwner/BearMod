# Authentication System Comparison: CURL vs SimpleLicenseVerifier

## Overview

BearMod now uses a **dual authentication system** with automatic fallback between the new KeyAuth API and the original CURL-based authentication. Here's how they work together and determine compatibility.

## Authentication Flow Sequence

### Primary Flow: SimpleLicenseVerifier (New)
```
1. User enters license key
2. SimpleLicenseVerifier.verifyLicense() called
3. If SUCCESS → Save key & proceed
4. If FAILURE → Automatic fallback to CURL system
```

### Fallback Flow: Native CURL System (Original)
```
1. SimpleLicenseVerifier fails
2. fallbackToOldAuth() called
3. Launcher.safeCheck() → native_Check() in C++
4. If SUCCESS → Save key & proceed
5. If FAILURE → Show error to user
```

## System 1: SimpleLicenseVerifier (New KeyAuth)

### API Endpoint & Method
```java
// Configuration
private static final String OWNER_ID = "yLoA9zcOEF";
private static final String APP_NAME = "com.bearmod";  
private static final String API_URL = "https://keyauth.win/api/1.2/";

// Request Format
FormBody formBody = new FormBody.Builder()
    .add("type", "license")
    .add("key", licenseKey)
    .add("hwid", hwid)
    .add("name", APP_NAME)
    .add("ownerid", OWNER_ID)
    .build();
```

### HWID Generation (Java)
```java
private static String generateSimpleHWID(Context context) {
    StringBuilder hwid = new StringBuilder();
    
    // Device identifiers
    hwid.append(Build.MODEL).append("-");
    hwid.append(Build.MANUFACTURER).append("-");
    hwid.append(Build.DEVICE).append("-");
    
    // Android ID
    String androidId = Settings.Secure.getString(
        context.getContentResolver(), 
        Settings.Secure.ANDROID_ID
    );
    if (androidId != null) {
        hwid.append(androidId);
    }
    
    // MD5 hash for consistent format
    MessageDigest md = MessageDigest.getInstance("MD5");
    byte[] hashBytes = md.digest(hwid.toString().getBytes());
    
    StringBuilder result = new StringBuilder();
    for (byte b : hashBytes) {
        result.append(String.format("%02x", b));
    }
    return result.toString();
}
```

### Response Handling
```java
// Simple success check
boolean isValid = responseBody.contains("\"success\":true") || 
                  responseBody.contains("\"success\": true");
```

## System 2: Native CURL Authentication (Original)

### API Endpoint & Method
```cpp
// From native_Check() in NRG.h
curl_easy_setopt(curl, CURLOPT_URL, "https://free-panel.gleeze.com/connect");

// POST data format
sprintf(data, "game=PUBG&user_key=%s&serial=%s", userKey, UUID.c_str());
```

### HWID Generation (C++)
```cpp
jstring native_Check(JNIEnv *env, jclass clazz, jobject mContext, jstring mUserKey) {
    auto userKey = env->GetStringUTFChars(mUserKey, 0);
    
    // Complex HWID composition
    std::string hwid = userKey;
    hwid += GetAndroidID(env, mContext);      // Android ID
    hwid += GetDeviceModel(env);              // Build.MODEL
    hwid += GetDeviceBrand(env);              // Build.BRAND
    
    // Generate UUID from HWID
    std::string UUID = GetDeviceUniqueIdentifier(env, hwid.c_str());
}
```

### Response Validation (C++)
```cpp
// JSON parsing with complex validation
json result = json::parse(chunk.memory);
if (result["status"] == true) {
    auto token = result["data"]["token"].get<std::string>();
    auto rng = result["data"]["rng"].get<time_t>();
    
    // Time-based validation
    if (rng + 30 > time(nullptr)) {
        // Generate auth signature
        std::string auth = enc("PUBG") + "-" + userKey + "-" + UUID + "-" + 
                          enc("Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E");
        std::string outputAuth = Tools::CalcMD5(auth);
        
        // Validate token matches calculated hash
        bValid = token == outputAuth;
    }
}

return bValid ? env->NewStringUTF("OK") : env->NewStringUTF(errMsg.c_str());
```

## Compatibility Determination Logic

### In Launcher.loginAsync()

```java
public static void loginAsync(Context context, String userKey, LoginCallback callback) {
    Log.d(TAG, "Starting simple license verification...");
    
    // TRY NEW SYSTEM FIRST
    SimpleLicenseVerifier.verifyLicense(context, userKey, new SimpleLicenseVerifier.LicenseCallback() {
        @Override
        public void onSuccess(String message) {
            // ✅ NEW SYSTEM WORKED - Save key and proceed
            SharedPreferences prefs = context.getSharedPreferences(context.getPackageName(), Context.MODE_PRIVATE);
            prefs.edit().putString("USER_KEY", userKey).apply();
            callback.onSuccess();
        }
        
        @Override
        public void onFailure(String error) {
            // ❌ NEW SYSTEM FAILED - Try old CURL system
            Log.e(TAG, "License verification failed: " + error);
            fallbackToOldAuth(context, userKey, callback);
        }
    });
}
```

### Fallback Logic

```java
private static void fallbackToOldAuth(Context context, String userKey, LoginCallback callback) {
    Log.d(TAG, "Falling back to CURL authentication...");
    
    new Thread(() -> {
        // Call native CURL system
        String result = safeCheck(context, userKey);
        
        if ("OK".equals(result)) {
            // ✅ OLD SYSTEM WORKED - Save key and proceed
            SharedPreferences prefs = context.getSharedPreferences(context.getPackageName(), Context.MODE_PRIVATE);
            prefs.edit().putString("USER_KEY", userKey).apply();
            new android.os.Handler(android.os.Looper.getMainLooper()).post(callback::onSuccess);
        } else {
            // ❌ BOTH SYSTEMS FAILED - Show error
            new android.os.Handler(android.os.Looper.getMainLooper()).post(() -> callback.onError(result));
        }
    }).start();
}
```

### Native Library Safety

```java
public static String safeCheck(Context mContext, String userKey) {
    if (nativeLibraryLoaded) {
        try {
            return Check(mContext, userKey);  // Call native_Check()
        } catch (UnsatisfiedLinkError e) {
            Log.w("Launcher", "Native Check not available, using fallback");
        }
    }
    // Demo mode fallback if native library missing
    Log.i("Launcher", "Demo mode: accepting any key");
    return "OK";
}
```

## Key Differences Between Systems

| Aspect | SimpleLicenseVerifier (New) | Native CURL (Original) |
|--------|----------------------------|------------------------|
| **API Endpoint** | `https://keyauth.win/api/1.2/` | `https://free-panel.gleeze.com/connect` |
| **Request Format** | KeyAuth standard format | Custom `game=PUBG&user_key=X&serial=Y` |
| **HWID Algorithm** | Simple: `MODEL-MANUFACTURER-DEVICE-ANDROID_ID` → MD5 | Complex: `userKey+AndroidID+Model+Brand` → UUID |
| **Response Validation** | Simple: Check for `"success":true` | Complex: Token validation with time checks |
| **Implementation** | Pure Java with OkHttp | Native C++ with libcurl |
| **Dependencies** | OkHttp only | libcurl, JSON parsing, MD5 utilities |
| **Fallback** | Falls back to CURL if fails | No fallback (final authority) |
| **Error Handling** | Simple string extraction | Full JSON error parsing |

## Compatibility Matrix

| Scenario | New System | Old System | Final Result |
|----------|------------|------------|--------------|
| **Valid KeyAuth License** | ✅ SUCCESS | ❌ Not called | ✅ **User logged in** |
| **Invalid KeyAuth License** | ❌ FAILURE | ✅ SUCCESS | ✅ **User logged in** |
| **Network Error (New)** | ❌ FAILURE | ✅ SUCCESS | ✅ **User logged in** |
| **Both Systems Fail** | ❌ FAILURE | ❌ FAILURE | ❌ **Login rejected** |
| **Native Library Missing** | ❌ FAILURE | ✅ Demo Mode | ✅ **User logged in** |

## Why This Approach Works

### 1. **License Compatibility**
- **KeyAuth licenses**: Work with new system
- **Legacy licenses**: Work with old CURL system  
- **Custom licenses**: Can work with either depending on backend

### 2. **Graceful Degradation**
- If KeyAuth service is down → CURL system still works
- If native library missing → Demo mode allows testing
- If both fail → Clear error message to user

### 3. **No License Invalidation**
- Existing users continue to work regardless of which system validates them
- New licenses can use modern KeyAuth API
- Legacy infrastructure remains as reliable fallback

### 4. **Performance Priority**
- Fast KeyAuth API tried first (typically faster)
- CURL system only used when needed (reduces load)
- Both run in background threads (no UI blocking)

## Testing Different License Types

You can test compatibility by:

```java
// Check which system validates your license
SimpleLicenseVerifier.verifyLicense(context, "your-license-key", new SimpleLicenseVerifier.LicenseCallback() {
    @Override
    public void onSuccess(String message) {
        Log.d("TEST", "✅ Validated by NEW KeyAuth system");
    }
    
    @Override  
    public void onFailure(String error) {
        Log.d("TEST", "❌ NEW system failed: " + error);
        Log.d("TEST", "🔄 Will try OLD CURL system next...");
    }
});
```

This dual system ensures **maximum compatibility** while allowing migration to the more modern, lightweight KeyAuth API without breaking existing user licenses. 