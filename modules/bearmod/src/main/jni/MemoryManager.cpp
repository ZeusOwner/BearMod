#include <jni.h>
#include <android/log.h>

#define LOG_TAG "BearMod-MemoryManager"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

class MemoryManager {
public:
    static MemoryManager& getInstance() {
        static MemoryManager instance;
        return instance;
    }
    
    void initialize() {
        LOGI("MemoryManager initialized");
    }
    
    void cleanup() {
        LOGI("MemoryManager cleanup");
    }
    
private:
    MemoryManager() = default;
    ~MemoryManager() = default;
};

extern "C" {
    JNIEXPORT void JNICALL
    Java_com_bearmod_loader_MemoryManager_initialize(JNIEnv *env, jclass clazz) {
        MemoryManager::getInstance().initialize();
    }
    
    JNIEXPORT void JNICALL
    Java_com_bearmod_loader_MemoryManager_cleanup(JNIEnv *env, jclass clazz) {
        MemoryManager::getInstance().cleanup();
    }
}
