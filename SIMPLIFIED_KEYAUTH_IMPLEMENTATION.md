# Simplified KeyAuth Implementation for BearMod

## Overview

The BearMod project has been updated to use a simplified, lightweight KeyAuth license verification system. This removes complex webhook integrations and API functions that could interfere with target game applications.

## What Was Changed

### Removed Complex Features
- ❌ Webhook verification system (`WebhookVerifier.java`, `WebhookTestActivity.java`)
- ❌ Enhanced HMAC verification (`EnhancedWebhookVerifier.java`)
- ❌ Multi-layer authentication (`FinalKeyAuthVerifier.java`)
- ❌ Complex KeyAuth managers (`KeyAuthManager.java`, `HybridKeyAuthManager.java`)
- ❌ Native authentication integration
- ❌ File hash integrity checking for authentication
- ❌ Custom domain APIs with certificate pinning

### New Simple Implementation
- ✅ **`SimpleLicenseVerifier.java`** - Lightweight license verification
- ✅ Direct KeyAuth API calls using standard endpoints
- ✅ Basic HWID generation without complex fingerprinting
- ✅ Minimal dependencies (just OkHttp for HTTP requests)
- ✅ Fallback to original CURL system if needed

## Benefits of Simplified Approach

1. **Reduced Interference**: Minimal code means less chance of conflicting with target game applications
2. **Better Performance**: No heavy API operations or complex verification chains
3. **Easier Maintenance**: Simple, single-file implementation that's easy to understand and modify
4. **Faster Startup**: No webhook calls or multi-step verification processes
5. **Less Attack Surface**: Fewer API endpoints and features to secure

## How It Works

### Simple License Check Flow
1. User enters license key in `LauncherLoginActivity`
2. `SimpleLicenseVerifier.verifyLicense()` is called
3. Basic HWID is generated using device identifiers
4. Single HTTP POST to KeyAuth API (`https://keyauth.win/api/1.2/`)
5. Response checked for `"success":true`
6. License key stored locally if valid
7. Fallback to original CURL system if needed

### Key Configuration
```java
// SimpleLicenseVerifier.java
private static final String OWNER_ID = "yLoA9zcOEF";
private static final String APP_NAME = "com.bearmod";
private static final String API_URL = "https://keyauth.win/api/1.2/";
```

## Usage Examples

### Async License Verification (Recommended)
```java
SimpleLicenseVerifier.verifyLicense(context, licenseKey, new SimpleLicenseVerifier.LicenseCallback() {
    @Override
    public void onSuccess(String message) {
        // License valid - proceed with app
        Log.d(TAG, "License verified: " + message);
    }
    
    @Override
    public void onFailure(String error) {
        // License invalid - show error
        Log.e(TAG, "License failed: " + error);
    }
});
```

### Quick Synchronous Check (Use sparingly)
```java
boolean isValid = SimpleLicenseVerifier.quickLicenseCheck(context, licenseKey);
if (isValid) {
    // Proceed
} else {
    // Handle invalid license
}
```

### Get Device HWID for Debugging
```java
String hwid = SimpleLicenseVerifier.getDeviceHWID(context);
Log.d(TAG, "Device HWID: " + hwid);
```

## File Structure Changes

### Files Removed/Disabled
- `app/src/main/java/com/bearmod/auth/WebhookVerifier.java`
- `app/src/main/java/com/bearmod/auth/EnhancedWebhookVerifier.java`
- `app/src/main/java/com/bearmod/auth/FinalKeyAuthVerifier.java`
- `app/src/main/java/com/bearmod/auth/KeyAuthManager.java`
- `app/src/main/java/com/bearmod/webhook/WebhookTestActivity.java`
- `app/src/main/res/layout/activity_webhook_test.xml`

### Files Modified
- `app/src/main/java/com/bearmod/Launcher.java` - Updated to use `SimpleLicenseVerifier`
- `app/src/main/java/com/bearmod/MainActivity.java` - Removed webhook test functionality
- `app/src/main/AndroidManifest.xml` - Disabled webhook test activity

### Files Added
- `app/src/main/java/com/bearmod/auth/SimpleLicenseVerifier.java` - New lightweight verifier

## Dependencies

The simplified implementation only requires these minimal dependencies:

```gradle
implementation 'com.squareup.okhttp3:okhttp:4.12.0'
```

All Retrofit, Gson, and security library dependencies can be removed if not used elsewhere.

## Testing

To test the implementation:

1. Build and install the app
2. Enter a valid KeyAuth license key
3. Check logs for verification success/failure
4. Long-press the settings button to see device HWID for debugging

## Fallback System

The implementation maintains compatibility with the original CURL-based system:

1. If `SimpleLicenseVerifier` fails, it automatically falls back to `Launcher.safeCheck()`
2. This ensures existing licenses continue to work
3. Native library functions are called safely with UnsatisfiedLinkError handling

## Migration Notes

- All webhook URLs and secret keys can be removed from configuration
- Custom domain settings are no longer needed
- HMAC utilities are preserved but not required for basic operation
- Existing license keys should continue to work with the simplified system

This simplified approach focuses on the core requirement: verifying licenses quickly and reliably without interfering with the target game application. 