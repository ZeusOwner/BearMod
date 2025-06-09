#include <jni.h>
#include <android/log.h>
#include <string>

#define LOG_TAG "BearMod-Logger"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }
    
    void initialize() {
        LOGI("Logger initialized");
    }
    
    void log(const std::string& message) {
        LOGI("%s", message.c_str());
    }
    
    void debug(const std::string& message) {
        LOGD("%s", message.c_str());
    }
    
    void error(const std::string& message) {
        LOGE("%s", message.c_str());
    }
    
private:
    Logger() = default;
    ~Logger() = default;
};

extern "C" {
    JNIEXPORT void JNICALL
    Java_com_bearmod_loader_Logger_initialize(JNIEnv *env, jclass clazz) {
        Logger::getInstance().initialize();
    }
    
    JNIEXPORT void JNICALL
    Java_com_bearmod_loader_Logger_log(JNIEnv *env, jclass clazz, jstring message) {
        const char* msg = env->GetStringUTFChars(message, nullptr);
        Logger::getInstance().log(std::string(msg));
        env->ReleaseStringUTFChars(message, msg);
    }
}
