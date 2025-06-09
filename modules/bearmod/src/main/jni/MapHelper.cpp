#include <jni.h>
#include <android/log.h>

#define LOG_TAG "BearMod-MapHelper"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

class MapHelper {
public:
    static MapHelper& getInstance() {
        static MapHelper instance;
        return instance;
    }
    
    void initialize() {
        LOGI("MapHelper initialized");
    }
    
    void cleanup() {
        LOGI("MapHelper cleanup");
    }
    
private:
    MapHelper() = default;
    ~MapHelper() = default;
};

extern "C" {
    JNIEXPORT void JNICALL
    Java_com_bearmod_loader_MapHelper_initialize(JNIEnv *env, jclass clazz) {
        MapHelper::getInstance().initialize();
    }
    
    JNIEXPORT void JNICALL
    Java_com_bearmod_loader_MapHelper_cleanup(JNIEnv *env, jclass clazz) {
        MapHelper::getInstance().cleanup();
    }
}
