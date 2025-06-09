LOCAL_PATH := $(call my-dir)

# ==================== Prebuilt Libraries ====================
# libcurl
include $(CLEAR_VARS)
LOCAL_MODULE := libcurl-prebuilt
LOCAL_SRC_FILES := curl/curl-android-arm64-v8a/lib/libcurl.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/curl/curl-android-arm64-v8a/include
include $(PREBUILT_STATIC_LIBRARY)

# libssl
include $(CLEAR_VARS)
LOCAL_MODULE := libssl-prebuilt
LOCAL_SRC_FILES := curl/openssl-android-arm64-v8a/lib/libssl.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/curl/openssl-android-arm64-v8a/include
include $(PREBUILT_STATIC_LIBRARY)

# libcrypto
include $(CLEAR_VARS)
LOCAL_MODULE := libcrypto-prebuilt
LOCAL_SRC_FILES := curl/openssl-android-arm64-v8a/lib/libcrypto.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/curl/openssl-android-arm64-v8a/include
include $(PREBUILT_STATIC_LIBRARY)

# ==================== Main Library ====================
include $(CLEAR_VARS)

# Module name (must match Java System.loadLibrary())
LOCAL_MODULE := bearmod

# Compiler flags (enhanced with MemoryManager, HookManager, and Modular Skin System support)
LOCAL_CFLAGS := \
    -Wno-error=format-security \
    -fvisibility=hidden \
    -ffunction-sections \
    -fdata-sections \
    -w \
    -fpermissive \
    -DUSE_MEMORY_MANAGER \
    -DUSE_HOOK_MANAGER \
    -DUSE_SIGNATURE_BYPASS \
    -DUSE_SUBSTRATE_HOOK \
    -DMEMORY_PROTECTION_SUPPORT \
    -DOPTIMIZED_MEMORY_SCAN \
    -DUSE_MODULAR_SKIN_SYSTEM \
    -DESP_SKIN_SUPPORT \
    -DXSUIT_ANTI_DETECTION

LOCAL_CPPFLAGS := \
    -std=c++17 \
    -Wno-error=c++11-narrowing \
    -fms-extensions \
    -frtti \
    -fexceptions

# Linker flags
LOCAL_LDFLAGS := -Wl,--gc-sections,--strip-all
LOCAL_LDLIBS := -llog -landroid -lz -lc

# Source files (enhanced with MemoryManager, HookManager, Logger, MapHelper, and Modular Skin System)
LOCAL_SRC_FILES := \
    Main.cpp \
    Tools.cpp \
    md5.cpp \
    ms5.h \
    Logger.cpp \
    CLog.cpp \
    MemoryManager.cpp \
    HookManager.cpp \
    NativeBridge.cpp \
    MapHelper.cpp \
    KittyMemory/KittyMemory.cpp \
    KittyMemory/MemoryPatch.cpp \
    KittyMemory/MemoryBackup.cpp \
    KittyMemory/KittyUtils.cpp \
    base64/base64.cpp \
    Substrate/hde64.c \
    Substrate/SubstrateDebug.cpp \
    Substrate/SubstrateHook.cpp \
    Substrate/SubstratePosixMemory.cpp \
    Substrate/And64InlineHook.cpp \
    SDK/PUBGM_Basic.cpp \
    SDK/PUBGM_Basic_functions.cpp \
    SDK/PUBGM_CoreUObject_functions.cpp \
    SDK/PUBGM_Engine_functions.cpp \
    SDK/PUBGM_ShadowTrackerExtra_functions.cpp \
    SDK/PUBGM_Client_functions.cpp

# Include paths
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH) \
    $(LOCAL_PATH)/KittyMemory \
    $(LOCAL_PATH)/Substrate \
    $(LOCAL_PATH)/SDK

# Static libraries
LOCAL_STATIC_LIBRARIES := \
    libcurl-prebuilt \
    libssl-prebuilt \
    libcrypto-prebuilt

# Build as shared library
include $(BUILD_SHARED_LIBRARY)

# ==================== Enhanced Configuration ====================
# Memory Manager and HookManager specific optimizations

# Architecture specific optimizations
ifeq ($(TARGET_ARCH_ABI),arm64-v8a)
    LOCAL_CFLAGS += -DARCH_ARM64 -mcpu=cortex-a57
endif

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
    LOCAL_CFLAGS += -DARCH_ARM32 -mcpu=cortex-a15 -mfpu=neon
    LOCAL_ARM_MODE := arm
endif

# Android API level specific features (Windows-compatible)
# Check if PLATFORM_SDK_VERSION is 29 or higher
ifneq ($(filter 29 30 31 32 33 34,$(PLATFORM_SDK_VERSION)),)
    LOCAL_CFLAGS += -DANDROID_API_29_PLUS -DUSE_PROCESS_VM
endif

# Security hardening (compatible with your existing flags)
LOCAL_CFLAGS += \
    -fstack-protector-strong \
    -D_FORTIFY_SOURCE=2

# Memory management optimizations
LOCAL_CFLAGS += \
    -DFAST_PATTERN_MATCHING \
    -DCACHED_MODULE_INFO \
    -DUSE_PROC_MEM \
    -DUSE_DIRECT_ACCESS

# Hook management optimizations
LOCAL_CFLAGS += \
    -DHOOK_SIGNATURE_BYPASS \
    -DANTI_DETECTION \
    -DMEMORY_SCRAMBLING

# Debug configuration (set DEBUG=1 to enable)
ifdef DEBUG
    LOCAL_CFLAGS += -DDEBUG -DVERBOSE_LOGGING -DMEMORY_DEBUG
else
    LOCAL_CFLAGS += -DNDEBUG -DRELEASE_BUILD
endif

# Configuration summary
$(info BearMod Enhanced Configuration:)
$(info - Architecture: $(TARGET_ARCH_ABI))
$(info - Android API: $(PLATFORM_SDK_VERSION))
$(info - MemoryManager: Enabled)
$(info - HookManager: Enabled)
$(info - SignatureBypass: Enabled)
