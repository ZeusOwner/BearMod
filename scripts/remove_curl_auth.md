# CURL Authentication Removal Guide

## Files to Modify/Remove

### 1. Native C++ Files (CURL Dependencies)
- `app/src/main/cpp/NRG.h` - Remove `native_Check` function (lines 3144-3218)
- `app/src/main/cpp/Main.cpp` - Remove CURL-related exports 
- Remove CURL libraries from `app/src/main/cpp/curl/` directory
- Update `app/src/main/cpp/Android.mk` to remove CURL dependencies

### 2. Java Files to Update
- `app/src/main/java/com/bearmod/Launcher.java` - Already updated to use KeyAuth
- Remove old authentication dialog code (if any exists)

### 3. Steps to Remove CURL Authentication

#### Step 1: Update Native Exports
In `app/src/main/cpp/Main.cpp`, replace the old authentication exports:

```cpp
// OLD (remove these):
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Launcher_Check(JNIEnv *env, jclass clazz, jobject mContext, jstring mUserKey) {
    // Old CURL implementation
}

// NEW (add these):
// KeyAuth implementation will go here
```

#### Step 2: Remove CURL Dependencies
In `app/src/main/cpp/Android.mk`:

```makefile
# REMOVE these lines:
LOCAL_STATIC_LIBRARIES += curl ssl crypto
LOCAL_C_INCLUDES += $(LOCAL_PATH)/curl/curl-android-$(TARGET_ARCH_ABI)/include
LOCAL_LDLIBS += -L$(LOCAL_PATH)/curl/curl-android-$(TARGET_ARCH_ABI)/lib -lcurl

# KEEP the rest
```

#### Step 3: Update NRG.h
Remove the `native_Check` function from `app/src/main/cpp/NRG.h` (lines 3144-3218)

#### Step 4: Clean Build
```bash
./gradlew clean
rm -rf app/build
rm -rf app/src/main/cpp/curl/  # Remove CURL directory
./gradlew build
```

### 4. Verification Steps

1. **Build Success**: Ensure app builds without CURL dependencies
2. **Authentication Test**: Test login with KeyAuth API
3. **Fallback Test**: Verify graceful fallback if KeyAuth fails
4. **Native Integration**: Test native KeyAuth functions if implemented

### 5. Migration Benefits

- **Modern API**: KeyAuth v1.3 instead of custom CURL implementation
- **Better Security**: HTTPS with certificate pinning
- **Easier Maintenance**: Standard HTTP libraries
- **Enhanced Features**: Session management, better error handling
- **Reduced Binary Size**: Remove CURL libraries (saves ~2MB)

### 6. Configuration Required

Update your KeyAuth configuration in `KeyAuthConfig.java`:

```java
public static final String APP_NAME = "your-keyauth-app-name";
public static final String OWNER_ID = "your-keyauth-owner-id";  
public static final String APP_VERSION = "1.3";
```

### 7. Testing Checklist

- [ ] App builds successfully without CURL
- [ ] Login works with valid KeyAuth license
- [ ] Error handling works with invalid license  
- [ ] Session persistence works across app restarts
- [ ] Fallback authentication works if needed
- [ ] Native security features work (if implemented)
- [ ] File hash verification works with FileHashCalculator
- [ ] APK integrity checks pass

## Implementation Status

✅ **Completed:**
- Java KeyAuth implementation with OkHttp
- Hybrid security manager
- Integration with FileHashCalculator
- Launcher.java updates
- Dependencies added to build.gradle

🔄 **In Progress:**
- Native C++ KeyAuth implementation (optional)
- CURL code removal

⚠️ **Manual Steps Required:**
1. Update KeyAuth configuration with your app credentials
2. Remove CURL native code
3. Test authentication flow
4. Update build configuration if needed 