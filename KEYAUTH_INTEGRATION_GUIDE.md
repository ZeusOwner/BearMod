# KeyAuth Integration Guide for BearMod

This guide explains how to integrate KeyAuth license validation into the BearMod Android application.

## Overview

The KeyAuth integration provides:
- License token validation functionality
- Subscription tier management (basic, pro, premium)
- Session management with secure storage
- Hardware ID (HWID) based authentication
- Network error handling and retry logic

## Configuration

### 1. Update KeyAuth Configuration

Edit `app/src/main/java/com/bearmod/auth/KeyAuthConfig.kt`:

```kotlin
object KeyAuthConfig {
    // Replace with your actual KeyAuth application details
    const val OWNER_ID = "your_actual_owner_id"
    const val CUSTOM_HASH = "your_actual_custom_hash"
    
    // Optional: Update app name if different
    const val APP_NAME = "com.bearmod"
}
```

**Required Values:**
- `OWNER_ID`: Get from KeyAuth dashboard → Account Settings
- `CUSTOM_HASH`: Get from KeyAuth dashboard → Application Settings

### 2. Certificate Pinning (Optional)

For enhanced security, update the certificate pin in `NetworkFactory.kt`:

```kotlin
val certificatePinner = CertificatePinner.Builder()
    .add("keyauth.win", "sha256/YOUR_ACTUAL_CERTIFICATE_PIN")
    .build()
```

## Integration Methods

### Method 1: Using BearModAuthIntegration (Recommended)

This is the easiest way to integrate with existing BearMod components:

```kotlin
// In your Activity or Application class
val authIntegration = BearModAuthIntegration.getInstance(this)

// Set callback for authentication events
authIntegration.setAuthCallback(object : BearModAuthIntegration.AuthCallback {
    override fun onAuthenticationSuccess(result: AuthResult) {
        // Handle successful authentication
        val tier = result.tier // "basic", "pro", or "premium"
        val username = result.userInfo?.username
        
        // Proceed with app functionality
        startMainFeatures(result)
    }
    
    override fun onAuthenticationFailure(error: String) {
        // Handle authentication failure
        showErrorDialog(error)
    }
    
    override fun onAuthenticationProgress(message: String) {
        // Show progress to user
        updateProgressText(message)
    }
})

// Authenticate user
authIntegration.authenticateUser(licenseKey)
```

### Method 2: Direct LicenseManager Usage

For more control over the authentication process:

```kotlin
// Initialize LicenseManager
LicenseManager.initialize(applicationContext)

// Validate license
lifecycleScope.launch {
    val result = LicenseManager.validate(licenseKey)
    
    if (result.success) {
        // Authentication successful
        val tier = result.tier
        val features = LicenseManager.getAvailableFeatures(tier)
        
        // Check specific feature access
        if (LicenseManager.isFeatureAvailable("esp_advanced", tier)) {
            // Enable advanced ESP
        }
    } else {
        // Authentication failed
        showError(result.message)
    }
}
```

### Method 3: Integration with Existing Launcher

Update your existing `Launcher.java` Login method:

```kotlin
// In Launcher.java Login method
private static void Login(final Context context, final String userKey) {
    BearModAuthIntegration authIntegration = BearModAuthIntegration.getInstance(context);
    
    authIntegration.integrateWithLauncher(userKey,
        // Success callback
        result -> {
            // Handle successful authentication
            String tier = result.getTier();
            // Continue with existing logic
        },
        // Failure callback
        error -> {
            // Handle authentication failure
            Toast.makeText(context, "Authentication failed: " + error, Toast.LENGTH_LONG).show();
        }
    );
}
```

## Feature Access Control

### Check Feature Availability

```kotlin
val authIntegration = BearModAuthIntegration.getInstance(this)

// Check if user has access to specific features
if (authIntegration.hasFeatureAccess("esp_advanced")) {
    // Enable advanced ESP
}

if (authIntegration.hasFeatureAccess("aimbot_premium")) {
    // Enable premium aimbot
}

// Get all available features
val features = authIntegration.getAvailableFeatures()
```

### Subscription Tiers and Features

**Basic Tier:**
- esp_basic
- aimbot_basic
- wallhack_basic

**Pro Tier:**
- All Basic features
- esp_advanced
- aimbot_advanced
- wallhack_advanced
- speed_hack
- no_recoil

**Premium Tier:**
- All Pro features
- esp_premium
- aimbot_premium
- wallhack_premium
- fly_hack
- god_mode
- unlimited_ammo
- custom_skins

## Session Management

The integration automatically handles session persistence:

```kotlin
// Attempt to restore previous session
authIntegration.attemptSessionRestore()

// Check if user is authenticated
if (authIntegration.isAuthenticated()) {
    // User has valid session
    val tier = authIntegration.getCurrentTier()
}

// Logout user
authIntegration.logout()
```

## Error Handling

### Network Connectivity

```kotlin
// Test connectivity before authentication
authIntegration.testConnectivity()
```

### Configuration Validation

```kotlin
val (isValid, errors) = LicenseManager.validateConfiguration()
if (!isValid) {
    Log.e("Config", "Configuration errors: ${errors.joinToString(", ")}")
}
```

### Diagnostic Information

```kotlin
val diagnostics = authIntegration.getDiagnosticInfo()
Log.d("Auth", "Diagnostics: $diagnostics")
```

## Integration with BearLoaderActivity

Update your `BearLoaderActivity.kt`:

```kotlin
private suspend fun authenticateAndLoadModules(licenseKey: String) {
    try {
        showProgress("Validating license...")
        
        val authIntegration = BearModAuthIntegration.getInstance(this)
        val result = authIntegration.validateLicenseForBearLoader(licenseKey)
        
        when {
            result.success -> {
                handleSuccessfulAuthentication(result, targetPackage)
            }
            else -> {
                showError("Authentication failed: ${result.message}")
            }
        }
    } catch (e: Exception) {
        showError("Authentication error: ${e.message}")
    }
}
```

## Security Considerations

1. **Configuration**: Ensure `OWNER_ID` and `CUSTOM_HASH` are properly set
2. **Certificate Pinning**: Enable for production builds
3. **Request Logging**: Disable in production (`ENABLE_REQUEST_LOGGING = false`)
4. **Session Storage**: Uses Android's EncryptedSharedPreferences for secure storage

## Troubleshooting

### Common Issues

1. **"Configuration invalid"**: Check `OWNER_ID` and `CUSTOM_HASH` values
2. **"Network error"**: Check internet connectivity and API endpoint
3. **"Session not found"**: Session expired, user needs to re-authenticate
4. **"HWID mismatch"**: Device hardware changed, may need to reset HWID in KeyAuth dashboard

### Debug Information

Enable debug logging by setting:
```kotlin
const val ENABLE_REQUEST_LOGGING = true
```

Get diagnostic information:
```kotlin
val diagnostics = authIntegration.getDiagnosticInfo()
```

## Testing

### Test License Keys

Use your KeyAuth dashboard to generate test license keys for different subscription tiers.

### Connectivity Testing

```kotlin
authIntegration.testConnectivity()
```

### Session Testing

```kotlin
// Test session restore
authIntegration.attemptSessionRestore()

// Test session validation
val sessionResult = LicenseManager.checkSession()
```

## Migration from Existing Authentication

If you have existing authentication logic:

1. Keep existing UI components
2. Replace validation logic with KeyAuth integration
3. Update feature access checks to use subscription tiers
4. Test thoroughly with different license types

## Support

For issues with KeyAuth integration:
1. Check configuration values
2. Review diagnostic information
3. Test network connectivity
4. Check KeyAuth dashboard for license status
