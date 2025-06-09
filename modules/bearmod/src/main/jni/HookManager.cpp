#include <jni.h>
#include <android/log.h>

#define LOG_TAG "BearMod-HookManager"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

class HookManager {
public:
    static HookManager& getInstance() {
        static HookManager instance;
        return instance;
    }
    
    void initialize() {
        LOGI("HookManager initialized");
    }
    
    void cleanup() {
        LOGI("HookManager cleanup");
    }
    
private:
    HookManager() = default;
    ~HookManager() = default;
};

extern "C" {
    JNIEXPORT void JNICALL
    Java_com_bearmod_loader_HookManager_initialize(JNIEnv *env, jclass clazz) {
        HookManager::getInstance().initialize();
    }
    
    JNIEXPORT void JNICALL
    Java_com_bearmod_loader_HookManager_cleanup(JNIEnv *env, jclass clazz) {
        HookManager::getInstance().cleanup();
    }
}
