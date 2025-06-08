LOCAL_PATH := $(call my-dir)

# Clear variables
include $(CLEAR_VARS)

# Module name
LOCAL_MODULE := bearmod

# Source files
LOCAL_SRC_FILES := \
    BearModJNI.cpp \
    MemoryManager.cpp \
    HookManager.cpp \
    MapHelper.cpp \
    Logger.cpp \
    SecurityManager.cpp \
    LicenseValidator.cpp \
    FeatureManager.cpp

# Include directories
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH) \
    $(LOCAL_PATH)/include \
    $(LOCAL_PATH)/security \
    $(LOCAL_PATH)/memory \
    $(LOCAL_PATH)/hooks

# Compiler flags
LOCAL_CPPFLAGS := \
    -std=c++17 \
    -fexceptions \
    -frtti \
    -O2 \
    -fvisibility=hidden \
    -ffunction-sections \
    -fdata-sections \
    -DANDROID \
    -DBEARMOD_VERSION=\"3.8.0\"

# Linker flags
LOCAL_LDFLAGS := \
    -Wl,--gc-sections \
    -Wl,--strip-all

# Libraries
LOCAL_LDLIBS := \
    -llog \
    -landroid \
    -ldl

# Build shared library
include $(BUILD_SHARED_LIBRARY)
