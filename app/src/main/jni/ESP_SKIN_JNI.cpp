#include "ESP_SKIN.h"
#include "JOIN_SKIN.h"
#include "Logger.h"
#include <jni.h>
#include <android/log.h>

// Logging macros
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "ESP_SKIN_JNI", __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "ESP_SKIN_JNI", __VA_ARGS__)

// ===== KOTLIN MEMORY SCRAMBLER JNI INTEGRATION =====

extern "C" JNIEXPORT jint JNICALL
Java_com_bearmod_MemoryScrambler_scrambleSkinIDNative(JNIEnv *env, jclass clazz, jint skinId) {
    try {
        // Apply C++ level scrambling for additional security
        uint32_t scrambled = static_cast<uint32_t>(skinId);

        // Layer 1: XOR with time-based key
        uint64_t timeKey = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count();
        scrambled ^= static_cast<uint32_t>(timeKey & 0xFFFFFFFF);

        // Layer 2: Bit rotation
        uint8_t rotationBits = (timeKey >> 32) & 0x1F; // 0-31 bits
        scrambled = (scrambled << rotationBits) | (scrambled >> (32 - rotationBits));

        // Layer 3: Memory protection scrambling
        if (memoryProtection.isProtected) {
            for (size_t i = 0; i < memoryProtection.scrambleKey.size() && i < 4; i++) {
                scrambled ^= (memoryProtection.scrambleKey[i] << (i * 8));
            }
        }

        // Ensure result stays within valid bounds
        if (scrambled < 100000 || scrambled > 2000000) {
            scrambled = 100000 + (scrambled % 1900000);
        }

        return static_cast<jint>(scrambled);

    } catch (...) {
        LOGE("[-] Error in native skin ID scrambling");
        return skinId; // Return original on error
    }
}

extern "C" JNIEXPORT jint JNICALL
Java_com_bearmod_MemoryScrambler_unscrambleSkinIDNative(JNIEnv *env, jclass clazz, jint scrambledId) {
    try {
        // Reverse the C++ scrambling process
        uint32_t unscrambled = static_cast<uint32_t>(scrambledId);

        // Get the same time-based key (this is a simplified approach)
        uint64_t timeKey = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count();

        // Reverse Layer 3: Memory protection scrambling
        if (memoryProtection.isProtected) {
            for (size_t i = 0; i < memoryProtection.scrambleKey.size() && i < 4; i++) {
                unscrambled ^= (memoryProtection.scrambleKey[i] << (i * 8));
            }
        }

        // Reverse Layer 2: Bit rotation
        uint8_t rotationBits = (timeKey >> 32) & 0x1F;
        unscrambled = (unscrambled >> rotationBits) | (unscrambled << (32 - rotationBits));

        // Reverse Layer 1: XOR with time-based key
        unscrambled ^= static_cast<uint32_t>(timeKey & 0xFFFFFFFF);

        return static_cast<jint>(unscrambled);

    } catch (...) {
        LOGE("[-] Error in native skin ID unscrambling");
        return scrambledId; // Return scrambled on error
    }
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_bearmod_MemoryScrambler_isValidSkinIDNative(JNIEnv *env, jclass clazz, jint skinId) {
    // Validate skin ID ranges
    if (skinId < 100000 || skinId > 2000000) {
        return JNI_FALSE;
    }

    // Check specific weapon type ranges
    if ((skinId >= 1101000000 && skinId <= 1101999999) || // Assault rifles
        (skinId >= 1102000000 && skinId <= 1102999999) || // SMGs
        (skinId >= 1103000000 && skinId <= 1103999999) || // Snipers
        (skinId >= 1105000000 && skinId <= 1105999999) || // LMGs
        (skinId >= 1301000000 && skinId <= 1401999999) || // Vehicles
        (skinId >= 1501000000 && skinId <= 1502999999)) { // Equipment
        return JNI_TRUE;
    }

    return JNI_FALSE;
}

extern "C" JNIEXPORT jlong JNICALL
Java_com_bearmod_MemoryScrambler_generateScrambleKeyNative(JNIEnv *env, jclass clazz) {
    try {
        // Generate secure scramble key using multiple entropy sources
        uint64_t key = 0;

        // Time component
        auto now = std::chrono::steady_clock::now();
        uint64_t timeComponent = std::chrono::duration_cast<std::chrono::nanoseconds>(
            now.time_since_epoch()).count();

        // Memory address component (ASLR entropy)
        uintptr_t addressComponent = reinterpret_cast<uintptr_t>(&key);

        // Random component from memory protection
        uint64_t randomComponent = 0;
        if (memoryProtection.isProtected && memoryProtection.scrambleKey.size() >= 8) {
            for (int i = 0; i < 8; i++) {
                randomComponent |= (static_cast<uint64_t>(memoryProtection.scrambleKey[i]) << (i * 8));
            }
        }

        // Combine all components
        key = timeComponent ^ addressComponent ^ randomComponent;

        return static_cast<jlong>(key);

    } catch (...) {
        LOGE("[-] Error generating native scramble key");
        return static_cast<jlong>(std::chrono::steady_clock::now().time_since_epoch().count());
    }
}

// ===== X-SUIT SPECIFIC JNI METHODS =====

extern "C" JNIEXPORT jint JNICALL
Java_com_bearmod_MemoryScrambler_scrambleXSuitIDNative(JNIEnv *env, jclass clazz, jint xSuitId) {
    try {
        return XSuitAntiDetection::scrambleXSuitId(xSuitId);
    } catch (...) {
        LOGE("[-] Error in native X-Suit scrambling");
        return xSuitId;
    }
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_bearmod_MemoryScrambler_isXSuitSafeToApplyNative(JNIEnv *env, jclass clazz, jint xSuitId) {
    try {
        return XSuitAntiDetection::isSafeToApply(xSuitId) ? JNI_TRUE : JNI_FALSE;
    } catch (...) {
        LOGE("[-] Error checking X-Suit safety");
        return JNI_FALSE;
    }
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_bearmod_SkinManager_applyXSuitWithProtectionNative(JNIEnv *env, jclass clazz, jint xSuitId) {
    try {
        // Apply X-Suit with maximum native protection
        if (!XSuitAntiDetection::isSafeToApply(xSuitId)) {
            return JNI_FALSE;
        }

        // Enhanced memory protection
        if (!memoryProtection.isProtected) {
            InitializeMemoryProtection();
        }
        ScrambleMemory(memoryProtection.scrambleKey.data(), memoryProtection.scrambleKey.size());

        // Apply through enhanced skin patch system
        bool success = applyEnhancedSkinWithScrambler(0, xSuitId); // 0 for X-Suit category

        if (success) {
            XSuitAntiDetection::recordApplication(xSuitId);
            LOGI("[+] X-Suit applied with native protection: %d", xSuitId);
        }

        return success ? JNI_TRUE : JNI_FALSE;

    } catch (...) {
        LOGE("[-] Error applying X-Suit with native protection");
        return JNI_FALSE;
    }
}
