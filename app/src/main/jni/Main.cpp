#include <jni.h>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include "NRG.h"

bool TestGGG = false;
bool IsHideEsp(JNIEnv * env, jclass clazz)
{
    if (TestGGG == true){
        return true;
    }
    return false;
}

void native_onSendConfig(JNIEnv *env, jobject thiz, jstring s, jstring v) {
    const char *config = env->GetStringUTFChars(s, 0);
    const char *value = env->GetStringUTFChars(v, 0);

    if (!strcmp(config, "CMD_PARSE_ITEMS")) {
        itemData = json::parse(value);
    } else if (!strcmp(config, "ESP::ITEMS")) {
        u_long itemId = strtoul(value, 0, 0);
        itemConfig[itemId] = !itemConfig[itemId];
    } else {
        Config[config] = (u_long) strtoul(value, 0, 0);
    }
}

#include "MOD/LOGO.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_onlinename(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF(OBFUSCATE("BEAR-MOD"));
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_channellink(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("https://t.me/bear_mod"));
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_feedbacklink(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("https://t.me/bearfeedbackbot"));
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_ChannelName(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("JOIN OFFICIAL CHANNEL"));
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_FeedBackName(JNIEnv *env, jobject activityObject) {
    return env->NewStringUTF(OBFUSCATE("FeedBack"));
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_cfg(JNIEnv *env, jobject activityObject ) {
    jstring str = env->NewStringUTF(OBFUSCATE("NRG_SaveFile.cfg"));
    return str;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_LoginNameNrg(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF(OBFUSCATE("ACTIVE KEY USER"));
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_Pleaselog(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF(OBFUSCATE("    "));
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_KeyAdd(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF(OBFUSCATE(" ****** "));
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_Login(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF(OBFUSCATE("                Login                "));
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_Cancel(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF(OBFUSCATE("               Cancel                "));
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_Error(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF(OBFUSCATE("Error"));
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_Pleasecheck(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF(OBFUSCATE("Please check your key "));
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_Ok(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF(OBFUSCATE(" Ok "));
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_bearmod_Launcher_Loging(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF(OBFUSCATE(" PLEASE WAIT LOADING... "));
}

jclass (*orig_FindClass)(JNIEnv *env, const char *name);
int Register1(JNIEnv *env) {
    JNINativeMethod methods[] = {{"onSendConfig", "(Ljava/lang/String;Ljava/lang/String;)V", (void *) native_onSendConfig}/*,
         {"onCanvasDraw", "(Landroid/graphics/Canvas;IIF)V",         (void *) native_onCanvasDraw}*/};
    jclass clazz = env->FindClass("com/bearmod/Floating");
    if (!clazz)
        return -1;

    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
        return -1;

    return 0;
}



int Register2(JNIEnv *env) {
    JNINativeMethod methods[] = {{"Init",  "(Landroid/content/Context;)V", (void *) native_Init},
                                 {"Check", "(Landroid/content/Context;Ljava/lang/String;)Ljava/lang/String;", (void *) native_Check}};

    jclass clazz = env->FindClass("com/bearmod/Launcher");
    if (!clazz)
        return -1;

    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
        return -1;

    return 0;
}



int Register3(JNIEnv *env) {
    JNINativeMethod methods[] = {{"IsHideEsp","()Z", (void *) IsHideEsp}};
    jclass clazz = env->FindClass("com/bearmod/Floating");
    if (!clazz)
        return -1;
    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
        return -1;
    return 0;
}


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <cstring>
uintptr_t GetLibraryBaseAddress(const std::string& lib_name) {
    std::ifstream maps_file("/proc/self/maps");
    std::string line;
    uintptr_t base_address = 0;
    while (std::getline(maps_file, line)) {
        if (line.find(lib_name) != std::string::npos) {
            std::istringstream iss(line);
            std::string address_range;
            if (iss >> address_range) {
                std::string base_str = address_range.substr(0, address_range.find('-'));
                std::stringstream ss;
                ss << std::hex << base_str;
                ss >> base_address;
                if (ss.fail()) return 0;
                break;
            }
        }
    }
    return base_address;
}
uintptr_t xelahot_pointer(const std::vector<std::string>& lib_info, const std::vector<uintptr_t>& offsets, bool some_flag) {
    std::string lib_name = lib_info[0];
    uintptr_t base_address = GetLibraryBaseAddress(lib_name);
    if (base_address == 0) return 0;
    for (const auto& offset : offsets) {
        base_address += offset;
    }
    return base_address;
}
void setMemoryValue(uintptr_t address, int value) {
    int mem_fd = open("/proc/self/mem", O_RDWR);
    if (mem_fd == -1) return;
    pwrite(mem_fd, &value, sizeof(value), address);
    close(mem_fd);
}
void setValues(uintptr_t address, int flags, int value, bool freeze) {
    setMemoryValue(address, value);
}



#define targetLibName OBFUSCATE("libanogs.so")
void *IsAntiCheat(void *) {
    do {
        sleep(5);
    } while (!isLibraryLoaded(targetLibName));


    return nullptr;
}


__attribute((constructor)) void _bypass() {
    pthread_t t;
    pthread_create(&t, nullptr, IsAntiCheat, 0);
//pthread_create(&t, 0, IsAntiCheat2, 0);
}


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);

    if (Register1(env) != 0)
        return -1;

    if (Register2(env) != 0)
        return -1;

    if (Register3(env) != 0)
        return -1;


    pthread_t t;
    pthread_create(&t, nullptr, Init_Thread, 0);
    pthread_create(&t, nullptr, maps_thread, 0);
    return JNI_VERSION_1_6;
}


