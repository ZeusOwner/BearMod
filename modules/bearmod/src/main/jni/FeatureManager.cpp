#include <jni.h>
#include <android/log.h>

#define LOG_TAG "BearMod-FeatureManager"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

class FeatureManager {
public:
    static FeatureManager& getInstance() {
        static FeatureManager instance;
        return instance;
    }
    
    void initialize() {
        LOGI("FeatureManager initialized");
    }
    
    void enableFeature(const char* featureName) {
        LOGI("Enabling feature: %s", featureName);
    }
    
    void disableFeature(const char* featureName) {
        LOGI("Disabling feature: %s", featureName);
    }
    
    void cleanup() {
        LOGI("FeatureManager cleanup");
    }
    
private:
    FeatureManager() = default;
    ~FeatureManager() = default;
};

extern "C" {
    JNIEXPORT void JNICALL
    Java_com_bearmod_loader_FeatureManager_initialize(JNIEnv *env, jclass clazz) {
        FeatureManager::getInstance().initialize();
    }
    
    JNIEXPORT void JNICALL
    Java_com_bearmod_loader_FeatureManager_enableFeature(JNIEnv *env, jclass clazz, jstring featureName) {
        const char* name = env->GetStringUTFChars(featureName, nullptr);
        FeatureManager::getInstance().enableFeature(name);
        env->ReleaseStringUTFChars(featureName, name);
    }
}
