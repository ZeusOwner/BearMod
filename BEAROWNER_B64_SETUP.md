# BearOwner.b64.txt Integration Guide

## 📁 Your Base64 Secret File

You have a base64 encoded secret file at: `C:\Users\BearOwner\BearOwner.b64.txt`

This file contains your KeyAuth application secret in base64 encoded format, which provides enhanced security for your authentication system.

## 🔧 Integration Steps

### 1. Extract the Base64 Secret

Open your `BearOwner.b64.txt` file and copy the base64 encoded string.

### 2. Update KeyAuthConfig.java

Replace the empty secret in your configuration:

```java
// In app/src/main/java/com/bearmod/auth/KeyAuthConfig.java
public static final String SECRET_KEY_BASE64 = "YOUR_BASE64_STRING_FROM_FILE"; // Add your secret here
```

### 3. Fill in C++ Template

Based on the [KeyAuth C++ Example](https://github.com/KeyAuth/KeyAuth-CPP-Example.git), update these values:

```cpp
// In your C++ code (if you implement native version)
std::string name = skCrypt("com.bearmod").decrypt();  // Your app name
std::string ownerid = skCrypt("yLoA9zcOEF").decrypt(); // Your owner ID
std::string secret = skCrypt("YOUR_SECRET_HERE").decrypt(); // Your app secret (decoded from base64)
std::string version = skCrypt("1.2").decrypt(); // Your version
std::string url = skCrypt("https://enc.mod-key.click/1.2/").decrypt(); // Your custom domain
```

## 🔐 Enhanced Security Features

### HMAC Signature Verification

Your implementation now includes HMAC signature verification matching the C++ example:

```java
// Generate HMAC signature for requests
String payload = licenseKey + ":" + hwid;
String signature = generateHmac(payload, KeyAuthConfig.SECRET_KEY_BASE64);
```

### Auto-Login Functionality

Matches the C++ example's auto-login pattern:

```java
// Auto-login with license key (like C++ example)
EnhancedWebhookVerifier.autoLogin(licenseKey, hwid, new VerificationCallback() {
    @Override
    public void onSuccess(String response) {
        Log.d(TAG, "Successfully Automatically Logged In");
    }
    
    @Override
    public void onFailure(String error) {
        Log.e(TAG, "Auto-login failed: " + error);
    }
});
```

### Webhook Calls with Signature

Secure webhook calls with HMAC signatures:

```java
// Call webhook with signature (matching C++ pattern)
EnhancedWebhookVerifier.callWebhook(webhookID, userKey, hwid, callback);
```

## 🎯 Usage Examples

### Basic License Verification

```java
// Enhanced license verification with signature
EnhancedWebhookVerifier.verifyLicenseEnhanced(licenseKey, hwid, new VerificationCallback() {
    @Override
    public void onSuccess(String response) {
        // License verified successfully
        showUserData();
    }
    
    @Override
    public void onFailure(String error) {
        // License verification failed
        showError(error);
    }
});
```

### Webhook Integration

```java
// Configure webhook (like C++ example webhook calls)
String webhookID = "Sh1j25S5iX"; // Your webhook ID from dashboard
EnhancedWebhookVerifier.callWebhook(webhookID, userKey, hwid, new VerificationCallback() {
    @Override
    public void onSuccess(String response) {
        Log.d(TAG, "Webhook response: " + response);
    }
    
    @Override
    public void onFailure(String error) {
        Log.e(TAG, "Webhook failed: " + error);
    }
});
```

## 🔄 Migration from Current Implementation

### Update Launcher.java

Replace the current verification with enhanced version:

```java
// Replace in Launcher.java loginAsync method
EnhancedWebhookVerifier.autoLogin(userKey, hwid, new EnhancedWebhookVerifier.VerificationCallback() {
    @Override
    public void onSuccess(String response) {
        // Save credentials and proceed
        SharedPreferences prefs = context.getSharedPreferences(context.getPackageName(), Context.MODE_PRIVATE);
        prefs.edit().putString("USER_KEY", userKey).apply();
        callback.onSuccess();
    }
    
    @Override
    public void onFailure(String error) {
        // Fallback to old method if needed
        fallbackToOldAuth(context, userKey, callback);
    }
});
```

## 🛡️ Security Benefits

1. **HMAC Signatures**: All requests signed with your secret key
2. **Base64 Encoding**: Secret stored in encoded format
3. **Custom Domain**: Using your encrypted domain `https://enc.mod-key.click/1.2/`
4. **Enhanced Verification**: Multi-layer security checks
5. **C++ Pattern Matching**: Compatible with official KeyAuth examples

## ⚠️ Important Notes

- **Keep your `BearOwner.b64.txt` file secure** - it contains your application secret
- **Don't commit the decoded secret** to version control
- **Use obfuscation** in production builds
- **The base64 secret should match** what you have in your KeyAuth dashboard

## 🔧 Next Steps

1. **Add your base64 secret** to `KeyAuthConfig.java`
2. **Test the enhanced verification** with a valid license key
3. **Configure webhooks** in your KeyAuth dashboard
4. **Remove old CURL code** following the cleanup guide
5. **Implement additional C++ features** if needed (optional)

Your implementation now matches the official [KeyAuth C++ Example](https://github.com/KeyAuth/KeyAuth-CPP-Example.git) pattern while providing enhanced Android-specific security features! 