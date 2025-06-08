#include <jni.h>
#include <android/log.h>
#include <string>
#include "HookManager.h"
#include "MemoryManager.h"
#include "Logger.h"

// Use unified Logger instead of direct Android logging
#define LOGI(...) Logger::info(__VA_ARGS__)
#define LOGD(...) Logger::debug(__VA_ARGS__)
#define LOGW(...) Logger::warning(__VA_ARGS__)
#define LOGE(...) Logger::error(__VA_ARGS__)

// Helper function to convert Java string to C++ string
std::string jstringToString(JNIEnv* env, jstring jstr) {
    if (!jstr) return "";
    
    const char* chars = env->GetStringUTFChars(jstr, nullptr);
    if (!chars) return "";
    
    std::string result(chars);
    env->ReleaseStringUTFChars(jstr, chars);
    return result;
}

// JNI method implementations
extern "C" {

/**
 * Initialize the native hook manager
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_core_NativeBridge_nativeInitializeHookManager(JNIEnv *env, jclass clazz) {
    try {
        LOGI("Initializing native hook manager");
        bool result = HookManager::initialize();
        LOGI("Native hook manager initialization: %s", result ? "SUCCESS" : "FAILED");
        return result ? JNI_TRUE : JNI_FALSE;
    } catch (const std::exception& e) {
        LOGE("Exception in nativeInitializeHookManager: %s", e.what());
        return JNI_FALSE;
    } catch (...) {
        LOGE("Unknown exception in nativeInitializeHookManager");
        return JNI_FALSE;
    }
}

/**
 * Hook a function by name
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_core_NativeBridge_nativeHookFunction(JNIEnv *env, jclass clazz, 
                                                     jstring libraryName, jstring functionName, jint hookType) {
    try {
        std::string libName = jstringToString(env, libraryName);
        std::string funcName = jstringToString(env, functionName);
        
        if (libName.empty() || funcName.empty()) {
            LOGE("Invalid library or function name");
            return JNI_FALSE;
        }
        
        LOGD("Hooking function %s in %s (type: %d)", funcName.c_str(), libName.c_str(), hookType);
        
        // For signature bypass hooks, we use predefined replacement functions
        // The actual replacement function is determined in the C++ HookManager
        void* replacement = nullptr;
        void* original = nullptr;
        
        bool result = HookManager::hookFunctionByName(libName, funcName, replacement, &original);
        
        LOGD("Hook result for %s:%s = %s", libName.c_str(), funcName.c_str(), result ? "SUCCESS" : "FAILED");
        return result ? JNI_TRUE : JNI_FALSE;
        
    } catch (const std::exception& e) {
        LOGE("Exception in nativeHookFunction: %s", e.what());
        return JNI_FALSE;
    } catch (...) {
        LOGE("Unknown exception in nativeHookFunction");
        return JNI_FALSE;
    }
}

/**
 * Unhook a function by name
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_core_NativeBridge_nativeUnhookFunction(JNIEnv *env, jclass clazz, 
                                                       jstring libraryName, jstring functionName) {
    try {
        std::string libName = jstringToString(env, libraryName);
        std::string funcName = jstringToString(env, functionName);
        
        if (libName.empty() || funcName.empty()) {
            LOGE("Invalid library or function name for unhook");
            return JNI_FALSE;
        }
        
        LOGD("Unhooking function %s in %s", funcName.c_str(), libName.c_str());
        
        // For unhooking by name, we would need to maintain a mapping
        // For now, we'll return success as a placeholder
        LOGW("Unhook by name not fully implemented yet");
        return JNI_TRUE;
        
    } catch (const std::exception& e) {
        LOGE("Exception in nativeUnhookFunction: %s", e.what());
        return JNI_FALSE;
    } catch (...) {
        LOGE("Unknown exception in nativeUnhookFunction");
        return JNI_FALSE;
    }
}

/**
 * Check if a function is hooked
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_core_NativeBridge_nativeIsFunctionHooked(JNIEnv *env, jclass clazz, 
                                                         jstring libraryName, jstring functionName) {
    try {
        std::string libName = jstringToString(env, libraryName);
        std::string funcName = jstringToString(env, functionName);
        
        if (libName.empty() || funcName.empty()) {
            return JNI_FALSE;
        }
        
        // For now, return false as we don't maintain a name-based lookup
        // This would need to be implemented with proper tracking
        return JNI_FALSE;
        
    } catch (const std::exception& e) {
        LOGE("Exception in nativeIsFunctionHooked: %s", e.what());
        return JNI_FALSE;
    } catch (...) {
        LOGE("Unknown exception in nativeIsFunctionHooked");
        return JNI_FALSE;
    }
}

/**
 * Get the number of active hooks
 */
JNIEXPORT jint JNICALL
Java_com_bearmod_core_NativeBridge_nativeGetActiveHookCount(JNIEnv *env, jclass clazz) {
    try {
        // This would need to be implemented in HookManager
        // For now, return 0 as placeholder
        return 0;
    } catch (const std::exception& e) {
        LOGE("Exception in nativeGetActiveHookCount: %s", e.what());
        return 0;
    } catch (...) {
        LOGE("Unknown exception in nativeGetActiveHookCount");
        return 0;
    }
}

/**
 * Initialize the hooking system
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_core_NativeBridge_nativeInitializeHookingSystem(JNIEnv *env, jclass clazz) {
    try {
        LOGI("Initializing native hooking system");
        bool result = HookManager::initialize();
        return result ? JNI_TRUE : JNI_FALSE;
    } catch (const std::exception& e) {
        LOGE("Exception in nativeInitializeHookingSystem: %s", e.what());
        return JNI_FALSE;
    } catch (...) {
        LOGE("Unknown exception in nativeInitializeHookingSystem");
        return JNI_FALSE;
    }
}

/**
 * Cleanup the hooking system
 */
JNIEXPORT void JNICALL
Java_com_bearmod_core_NativeBridge_nativeCleanupHookingSystem(JNIEnv *env, jclass clazz) {
    try {
        LOGI("Cleaning up native hooking system");
        // Cleanup implementation would go here
    } catch (const std::exception& e) {
        LOGE("Exception in nativeCleanupHookingSystem: %s", e.what());
    } catch (...) {
        LOGE("Unknown exception in nativeCleanupHookingSystem");
    }
}

/**
 * Check if native library is available
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_core_NativeBridge_nativeIsLibraryAvailable(JNIEnv *env, jclass clazz) {
    try {
        LOGD("Native library availability check");
        return JNI_TRUE; // If we're here, the library is available
    } catch (...) {
        return JNI_FALSE;
    }
}

/**
 * Get native library version
 */
JNIEXPORT jstring JNICALL
Java_com_bearmod_core_NativeBridge_nativeGetLibraryVersion(JNIEnv *env, jclass clazz) {
    try {
        const char* version = "BearMod Native Library v1.0.0 with HookManager";
        return env->NewStringUTF(version);
    } catch (const std::exception& e) {
        LOGE("Exception in nativeGetLibraryVersion: %s", e.what());
        return env->NewStringUTF("Error getting version");
    } catch (...) {
        LOGE("Unknown exception in nativeGetLibraryVersion");
        return env->NewStringUTF("Unknown error");
    }
}

/**
 * Enhanced signature verification bypass
 * This method can be called directly from Java for signature bypass
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_SignatureVerifier_nativeSignatureVerification(JNIEnv *env, jclass clazz, jobject context) {
    try {
        LOGD("Native signature verification bypass called");
        
        // Always return true for signature bypass
        // This integrates with the SignatureVerifier.java bypass system
        return JNI_TRUE;
        
    } catch (const std::exception& e) {
        LOGE("Exception in nativeSignatureVerification: %s", e.what());
        return JNI_TRUE; // Return true even on error for maximum bypass
    } catch (...) {
        LOGE("Unknown exception in nativeSignatureVerification");
        return JNI_TRUE; // Return true even on error for maximum bypass
    }
}

/**
 * Hook signature verification functions specifically
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_core_hooks_HookManager_nativeHookSignatureVerification(JNIEnv *env, jclass clazz) {
    try {
        LOGI("Setting up native signature verification hooks");
        
        // Initialize HookManager if not already done
        if (!HookManager::initialize()) {
            LOGE("Failed to initialize HookManager for signature hooks");
            return JNI_FALSE;
        }
        
        // The signature verification hooks are automatically set up
        // in HookManager::initialize() via setupSignatureBypassHooks()
        
        LOGI("Native signature verification hooks setup completed");
        return JNI_TRUE;
        
    } catch (const std::exception& e) {
        LOGE("Exception in nativeHookSignatureVerification: %s", e.what());
        return JNI_FALSE;
    } catch (...) {
        LOGE("Unknown exception in nativeHookSignatureVerification");
        return JNI_FALSE;
    }
}

/**
 * Emergency signature bypass - for critical situations
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_SignatureVerifier_nativeEmergencyBypass(JNIEnv *env, jclass clazz) {
    try {
        LOGW("Emergency signature bypass activated from native");
        
        // Force initialize HookManager
        HookManager::initialize();
        
        // Always return true for emergency bypass
        return JNI_TRUE;
        
    } catch (...) {
        LOGE("Exception in emergency bypass");
        return JNI_TRUE; // Return true even on error for maximum bypass
    }
}

/**
 * MemoryManager JNI implementations
 */

/**
 * Initialize native MemoryManager
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_core_MemoryManager_nativeInitialize(JNIEnv *env, jobject thiz) {
    try {
        LOGI("Initializing native MemoryManager");
        bool result = MemoryManager::initialize();
        LOGI("Native MemoryManager initialization: %s", result ? "SUCCESS" : "FAILED");
        return result ? JNI_TRUE : JNI_FALSE;
    } catch (const std::exception& e) {
        LOGE("Exception in nativeInitialize: %s", e.what());
        return JNI_FALSE;
    } catch (...) {
        LOGE("Unknown exception in nativeInitialize");
        return JNI_FALSE;
    }
}

/**
 * Read memory from address
 */
JNIEXPORT jbyteArray JNICALL
Java_com_bearmod_core_MemoryManager_nativeReadMemory(JNIEnv *env, jobject thiz, jlong address, jint size) {
    try {
        if (address == 0 || size <= 0) {
            LOGE("Invalid parameters for nativeReadMemory");
            return nullptr;
        }

        // Allocate buffer
        std::vector<uint8_t> buffer(size);

        // Read memory
        if (!MemoryManager::readMemory(static_cast<uintptr_t>(address), buffer.data(), size)) {
            LOGE("Failed to read memory at 0x%lx", address);
            return nullptr;
        }

        // Create Java byte array
        jbyteArray result = env->NewByteArray(size);
        if (result == nullptr) {
            LOGE("Failed to create byte array");
            return nullptr;
        }

        env->SetByteArrayRegion(result, 0, size, reinterpret_cast<const jbyte*>(buffer.data()));
        return result;

    } catch (const std::exception& e) {
        LOGE("Exception in nativeReadMemory: %s", e.what());
        return nullptr;
    } catch (...) {
        LOGE("Unknown exception in nativeReadMemory");
        return nullptr;
    }
}

/**
 * Write memory to address
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_core_MemoryManager_nativeWriteMemory(JNIEnv *env, jobject thiz, jlong address, jbyteArray data) {
    try {
        if (address == 0 || data == nullptr) {
            LOGE("Invalid parameters for nativeWriteMemory");
            return JNI_FALSE;
        }

        jsize dataSize = env->GetArrayLength(data);
        if (dataSize <= 0) {
            LOGE("Invalid data size for nativeWriteMemory");
            return JNI_FALSE;
        }

        // Get data from Java array
        jbyte* dataPtr = env->GetByteArrayElements(data, nullptr);
        if (dataPtr == nullptr) {
            LOGE("Failed to get byte array elements");
            return JNI_FALSE;
        }

        // Write memory
        bool result = MemoryManager::writeMemory(static_cast<uintptr_t>(address),
                                                dataPtr, static_cast<size_t>(dataSize));

        // Release array
        env->ReleaseByteArrayElements(data, dataPtr, JNI_ABORT);

        return result ? JNI_TRUE : JNI_FALSE;

    } catch (const std::exception& e) {
        LOGE("Exception in nativeWriteMemory: %s", e.what());
        return JNI_FALSE;
    } catch (...) {
        LOGE("Unknown exception in nativeWriteMemory");
        return JNI_FALSE;
    }
}

/**
 * Find pattern in memory range
 */
JNIEXPORT jlong JNICALL
Java_com_bearmod_core_MemoryManager_nativeFindPattern(JNIEnv *env, jobject thiz,
                                                     jstring pattern, jlong startAddress, jlong endAddress) {
    try {
        std::string patternStr = jstringToString(env, pattern);
        if (patternStr.empty()) {
            LOGE("Invalid pattern for nativeFindPattern");
            return 0;
        }

        uintptr_t result = MemoryManager::findPattern(patternStr,
                                                     static_cast<uintptr_t>(startAddress),
                                                     static_cast<uintptr_t>(endAddress));

        return static_cast<jlong>(result);

    } catch (const std::exception& e) {
        LOGE("Exception in nativeFindPattern: %s", e.what());
        return 0;
    } catch (...) {
        LOGE("Unknown exception in nativeFindPattern");
        return 0;
    }
}

/**
 * Get module base address
 */
JNIEXPORT jlong JNICALL
Java_com_bearmod_core_MemoryManager_nativeGetModuleBase(JNIEnv *env, jobject thiz, jstring moduleName) {
    try {
        std::string moduleNameStr = jstringToString(env, moduleName);
        if (moduleNameStr.empty()) {
            LOGE("Invalid module name for nativeGetModuleBase");
            return 0;
        }

        uintptr_t result = MemoryManager::getModuleBase(moduleNameStr);
        return static_cast<jlong>(result);

    } catch (const std::exception& e) {
        LOGE("Exception in nativeGetModuleBase: %s", e.what());
        return 0;
    } catch (...) {
        LOGE("Unknown exception in nativeGetModuleBase");
        return 0;
    }
}

/**
 * Get module size
 */
JNIEXPORT jlong JNICALL
Java_com_bearmod_core_MemoryManager_nativeGetModuleSize(JNIEnv *env, jobject thiz, jstring moduleName) {
    try {
        std::string moduleNameStr = jstringToString(env, moduleName);
        if (moduleNameStr.empty()) {
            LOGE("Invalid module name for nativeGetModuleSize");
            return 0;
        }

        size_t result = MemoryManager::getModuleSize(moduleNameStr);
        return static_cast<jlong>(result);

    } catch (const std::exception& e) {
        LOGE("Exception in nativeGetModuleSize: %s", e.what());
        return 0;
    } catch (...) {
        LOGE("Unknown exception in nativeGetModuleSize");
        return 0;
    }
}

/**
 * Logger JNI implementations
 */

/**
 * Initialize native Logger
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_LoggerIntegrationExample_nativeInitializeLogger(JNIEnv *env, jclass clazz, jstring tag, jint level) {
    try {
        std::string tagStr = jstringToString(env, tag);
        Logger::Level logLevel = static_cast<Logger::Level>(level);

        Logger::initialize(tagStr, logLevel);

        LOGI("Native Logger initialized with tag: %s, level: %d", tagStr.c_str(), level);
        return JNI_TRUE;

    } catch (const std::exception& e) {
        LOGE("Exception in nativeInitializeLogger: %s", e.what());
        return JNI_FALSE;
    } catch (...) {
        LOGE("Unknown exception in nativeInitializeLogger");
        return JNI_FALSE;
    }
}

/**
 * Native log debug
 */
JNIEXPORT void JNICALL
Java_com_bearmod_LoggerIntegrationExample_nativeLogDebug(JNIEnv *env, jclass clazz, jstring format, jobjectArray args) {
    try {
        std::string formatStr = jstringToString(env, format);
        Logger::debug("%s", formatStr.c_str());
    } catch (...) {
        // Ignore logging errors
    }
}

/**
 * Native log info
 */
JNIEXPORT void JNICALL
Java_com_bearmod_LoggerIntegrationExample_nativeLogInfo(JNIEnv *env, jclass clazz, jstring format, jobjectArray args) {
    try {
        std::string formatStr = jstringToString(env, format);
        Logger::info("%s", formatStr.c_str());
    } catch (...) {
        // Ignore logging errors
    }
}

/**
 * Native log warning
 */
JNIEXPORT void JNICALL
Java_com_bearmod_LoggerIntegrationExample_nativeLogWarning(JNIEnv *env, jclass clazz, jstring format, jobjectArray args) {
    try {
        std::string formatStr = jstringToString(env, format);
        Logger::warning("%s", formatStr.c_str());
    } catch (...) {
        // Ignore logging errors
    }
}

/**
 * Native log error
 */
JNIEXPORT void JNICALL
Java_com_bearmod_LoggerIntegrationExample_nativeLogError(JNIEnv *env, jclass clazz, jstring format, jobjectArray args) {
    try {
        std::string formatStr = jstringToString(env, format);
        Logger::error("%s", formatStr.c_str());
    } catch (...) {
        // Ignore logging errors
    }
}

/**
 * Set native log level
 */
JNIEXPORT void JNICALL
Java_com_bearmod_LoggerIntegrationExample_nativeSetLogLevel(JNIEnv *env, jclass clazz, jint level) {
    try {
        Logger::Level logLevel = static_cast<Logger::Level>(level);
        Logger::setLevel(logLevel);
    } catch (...) {
        // Ignore logging errors
    }
}

/**
 * Check if native logger is available
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_LoggerIntegrationExample_isNativeLoggerAvailable(JNIEnv *env, jclass clazz) {
    try {
        return Logger::isInitialized() ? JNI_TRUE : JNI_FALSE;
    } catch (...) {
        return JNI_FALSE;
    }
}

/**
 * Get native logger tag
 */
JNIEXPORT jstring JNICALL
Java_com_bearmod_LoggerIntegrationExample_getNativeLoggerTag(JNIEnv *env, jclass clazz) {
    try {
        std::string tag = Logger::getTag();
        return env->NewStringUTF(tag.c_str());
    } catch (...) {
        return env->NewStringUTF("Unknown");
    }
}

/**
 * Get native logger level
 */
JNIEXPORT jint JNICALL
Java_com_bearmod_LoggerIntegrationExample_getNativeLoggerLevel(JNIEnv *env, jclass clazz) {
    try {
        return static_cast<jint>(Logger::getLevel());
    } catch (...) {
        return 1; // Default to INFO
    }
}

/**
 * Cleanup native logger
 */
JNIEXPORT void JNICALL
Java_com_bearmod_LoggerIntegrationExample_nativeCleanupLogger(JNIEnv *env, jclass clazz) {
    try {
        Logger::cleanup();
    } catch (...) {
        // Ignore cleanup errors
    }
}

/**
 * Java Logger integration JNI implementations
 */

/**
 * Check if native logger is available for Java Logger integration
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_core_utils_Logger_isNativeLoggerAvailable(JNIEnv *env, jclass clazz) {
    try {
        return Logger::isInitialized() ? JNI_TRUE : JNI_FALSE;
    } catch (...) {
        return JNI_FALSE;
    }
}

/**
 * Native log debug for Java Logger
 */
JNIEXPORT void JNICALL
Java_com_bearmod_core_utils_Logger_nativeLogDebug(JNIEnv *env, jclass clazz, jstring message) {
    try {
        std::string messageStr = jstringToString(env, message);
        Logger::debug("[Java] %s", messageStr.c_str());
    } catch (...) {
        // Ignore logging errors
    }
}

/**
 * Native log info for Java Logger
 */
JNIEXPORT void JNICALL
Java_com_bearmod_core_utils_Logger_nativeLogInfo(JNIEnv *env, jclass clazz, jstring message) {
    try {
        std::string messageStr = jstringToString(env, message);
        Logger::info("[Java] %s", messageStr.c_str());
    } catch (...) {
        // Ignore logging errors
    }
}

/**
 * Native log warning for Java Logger
 */
JNIEXPORT void JNICALL
Java_com_bearmod_core_utils_Logger_nativeLogWarning(JNIEnv *env, jclass clazz, jstring message) {
    try {
        std::string messageStr = jstringToString(env, message);
        Logger::warning("[Java] %s", messageStr.c_str());
    } catch (...) {
        // Ignore logging errors
    }
}

/**
 * Native log error for Java Logger
 */
JNIEXPORT void JNICALL
Java_com_bearmod_core_utils_Logger_nativeLogError(JNIEnv *env, jclass clazz, jstring message) {
    try {
        std::string messageStr = jstringToString(env, message);
        Logger::error("[Java] %s", messageStr.c_str());
    } catch (...) {
        // Ignore logging errors
    }
}

/**
 * UnifiedLoggingExample JNI implementations
 */

/**
 * Initialize unified logger from UnifiedLoggingExample
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_UnifiedLoggingExample_nativeInitializeUnifiedLogger(JNIEnv *env, jclass clazz, jstring tag, jint level) {
    try {
        std::string tagStr = jstringToString(env, tag);
        Logger::Level logLevel = static_cast<Logger::Level>(level);
        Logger::initialize(tagStr, logLevel);
        return Logger::isInitialized() ? JNI_TRUE : JNI_FALSE;
    } catch (...) {
        return JNI_FALSE;
    }
}

/**
 * Native log debug for UnifiedLoggingExample
 */
JNIEXPORT void JNICALL
Java_com_bearmod_UnifiedLoggingExample_nativeLogDebug(JNIEnv *env, jclass clazz, jstring message) {
    try {
        std::string messageStr = jstringToString(env, message);
        Logger::debug("[Unified] %s", messageStr.c_str());
    } catch (...) {
        // Ignore logging errors
    }
}

/**
 * Native log info for UnifiedLoggingExample
 */
JNIEXPORT void JNICALL
Java_com_bearmod_UnifiedLoggingExample_nativeLogInfo(JNIEnv *env, jclass clazz, jstring message) {
    try {
        std::string messageStr = jstringToString(env, message);
        Logger::info("[Unified] %s", messageStr.c_str());
    } catch (...) {
        // Ignore logging errors
    }
}

/**
 * Native log warning for UnifiedLoggingExample
 */
JNIEXPORT void JNICALL
Java_com_bearmod_UnifiedLoggingExample_nativeLogWarning(JNIEnv *env, jclass clazz, jstring message) {
    try {
        std::string messageStr = jstringToString(env, message);
        Logger::warning("[Unified] %s", messageStr.c_str());
    } catch (...) {
        // Ignore logging errors
    }
}

/**
 * Native log error for UnifiedLoggingExample
 */
JNIEXPORT void JNICALL
Java_com_bearmod_UnifiedLoggingExample_nativeLogError(JNIEnv *env, jclass clazz, jstring message) {
    try {
        std::string messageStr = jstringToString(env, message);
        Logger::error("[Unified] %s", messageStr.c_str());
    } catch (...) {
        // Ignore logging errors
    }
}

/**
 * Check if native logger is available for UnifiedLoggingExample
 */
JNIEXPORT jboolean JNICALL
Java_com_bearmod_UnifiedLoggingExample_isNativeLoggerAvailable(JNIEnv *env, jclass clazz) {
    try {
        return Logger::isInitialized() ? JNI_TRUE : JNI_FALSE;
    } catch (...) {
        return JNI_FALSE;
    }
}

/**
 * Get native logger tag for UnifiedLoggingExample
 */
JNIEXPORT jstring JNICALL
Java_com_bearmod_UnifiedLoggingExample_getNativeLoggerTag(JNIEnv *env, jclass clazz) {
    try {
        std::string tag = Logger::getTag();
        return env->NewStringUTF(tag.c_str());
    } catch (...) {
        return env->NewStringUTF("Unknown");
    }
}

/**
 * Get native logger level for UnifiedLoggingExample
 */
JNIEXPORT jint JNICALL
Java_com_bearmod_UnifiedLoggingExample_getNativeLoggerLevel(JNIEnv *env, jclass clazz) {
    try {
        return static_cast<jint>(Logger::getLevel());
    } catch (...) {
        return 1; // INFO level as default
    }
}

/**
 * Cleanup native logger for UnifiedLoggingExample
 */
JNIEXPORT void JNICALL
Java_com_bearmod_UnifiedLoggingExample_nativeCleanupLogger(JNIEnv *env, jclass clazz) {
    try {
        Logger::cleanup();
    } catch (...) {
        // Ignore cleanup errors
    }
}

} // extern "C"
