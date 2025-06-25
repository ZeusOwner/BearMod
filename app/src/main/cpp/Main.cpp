#include <jni.h>
#include <string>
#include <vector>
#include <set>
#include <pthread.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <map>

#include "Helper/Includes.h"
#include "Helper/json.hpp"
#include "Helper/obfuscate.h"

//MOD-SYSTEM INCLUDES
#include "NRG.h"
#include "AntiCheat.h"
#include "JOIN_SKIN.h"
#include "Outfit_Skin.h"
#include "ESP_SKIN.h"
#include "WEAPON_MODS.h"
#include "Skin_System.h"

// Global variable declarations
using json = nlohmann::json;

// Helper functions
// getCategoryName is already defined in Skin_System.h - commented out to avoid redefinition
// std::string getCategoryName(int categoryId) {
//     switch(categoryId) {
//         case 1: return "Assault Rifles";
//         case 2: return "SMGs";
//         case 3: return "Sniper Rifles";
//         case 4: return "Shotguns";
//         case 5: return "LMGs";
//         case 6: return "Pistols";
//         case 7: return "Melee";
//         default: return "Unknown";
//     }
// }

// getWeaponNameFromID is already defined in JOIN_SKIN.h - commented out to avoid redefinition
// std::string getWeaponNameFromID(const std::string& weaponId) {
//     // Basic weapon ID to name mapping
//     int id = std::stoi(weaponId);
//     switch(id) {
//         case 101001: return "AKM";
//         case 101004: return "M416";
//         case 101003: return "SCAR-L";
//         case 101008: return "M762";
//         case 101002: return "M16A4";
//         case 101005: return "GROZA";
//         case 101006: return "AUG";
//         case 101102: return "ACE32";
//         case 102001: return "UZI";
//         case 102002: return "UMP45";
//         case 102003: return "VECTOR";
//         case 102004: return "THOMPSON";
//         case 103001: return "KAR98K";
//         case 103002: return "M24";
//         case 103003: return "AWM";
//         case 103012: return "AMR";
//         case 103007: return "MK14";
//         case 105001: return "M249";
//         case 105002: return "DP28";
//         case 105010: return "MG3";
//         default: return "Unknown";
//     }
// }

// ===================================================================================================
// CONFIGURATION AND OLD JNI FUNCTIONS
// ===================================================================================================

jboolean IsHideEsp(JNIEnv * env, jobject thiz) {
    if (Config.find("RECORDER_HIDE") != Config.end() && Config["RECORDER_HIDE"] == 1) {
        return JNI_TRUE;
    }
    return JNI_FALSE;
}

// ===================================================================================================
// RECORDER FAKE UTILS JNI BRIDGE FUNCTIONS
// ===================================================================================================
// These functions allow C++ to control RecorderFakeMode automatically

// void native_enableRecorderFakeMode(JNIEnv *env, jobject thiz) {
//     // Call Java method to enable RecorderFakeMode
//     jclass floatingClass = env->FindClass("com/bearmod/Floating");
//     if (floatingClass) {
//         jmethodID enableMethod = env->GetStaticMethodID(floatingClass, "hideesp", "()V");
//         if (enableMethod) {
//             env->CallStaticVoidMethod(floatingClass, enableMethod);
//         }
//         env->DeleteLocalRef(floatingClass);
//     }
// }

// void native_disableRecorderFakeMode(JNIEnv *env, jobject thiz) {
//     // Call Java method to disable RecorderFakeMode
//     jclass floatingClass = env->FindClass("com/bearmod/Floating");
//     if (floatingClass) {
//         jmethodID disableMethod = env->GetStaticMethodID(floatingClass, "stopHideesp", "()V");
//         if (disableMethod) {
//             env->CallStaticVoidMethod(floatingClass, disableMethod);
//         }
//         env->DeleteLocalRef(floatingClass);
//     }
// }

// void native_toggleRecorderFakeMode(JNIEnv *env, jobject thiz) {
//     // Toggle RecorderFakeMode based on current ESP state and configuration
//     if (Config.find("RECORDER_HIDE") != Config.end() && Config["RECORDER_HIDE"] == 1) {
//         // Check if ESP is currently active - if so, enable fake mode
//         if (Config.find("ESP_LINE") != Config.end() && Config["ESP_LINE"] == 1) {
//             native_enableRecorderFakeMode(env, thiz);
//         } else if (Config.find("ESP_BONE") != Config.end() && Config["ESP_BONE"] == 1) {
//             native_enableRecorderFakeMode(env, thiz);
//         } else if (Config.find("ESP_INFO") != Config.end() && Config["ESP_INFO"] == 1) {
//             native_enableRecorderFakeMode(env, thiz);
//         } else {
//             native_disableRecorderFakeMode(env, thiz);
//         }
//     }
// }

// void native_autoToggleRecorderFakeMode(JNIEnv *env, jobject thiz) {
//     // Automatically toggle based on overall ESP activity
//     if (Config.find("RECORDER_HIDE") != Config.end() && Config["RECORDER_HIDE"] == 1) {
//         // Check if any ESP features are enabled
//         bool anyEspActive = false;
//         
//         std::vector<std::string> espKeys = {
//             "ESP_LINE", "ESP_BONE", "ESP_INFO", "ESP_WEAPON",
//             "ESP_WARNING", "ESP_ALERT", "ESP_RADAR", "NRG_AIMBOT"
//         };
//         
//         for (const std::string& key : espKeys) {
//             if (Config.find(key) != Config.end() && Config[key] == 1) {
//                 anyEspActive = true;
//                 break;
//             }
//         }
//         
//         if (anyEspActive) {
//             native_enableRecorderFakeMode(env, thiz);
//         } else {
//             native_disableRecorderFakeMode(env, thiz);
//         }
//     }
// }

void native_onSendConfig(JNIEnv *env, jobject thiz, jstring s, jstring v) {
    const char *config = env->GetStringUTFChars(s, nullptr);
    const char *value = env->GetStringUTFChars(v, nullptr);

    if (!strcmp(config, "CMD_PARSE_ITEMS")) {
        itemData = json::parse(value);
    } else if (!strcmp(config, "ESP::ITEMS")) {
        u_long itemId = strtoul(value, nullptr, 0);
        itemConfig[itemId] = !itemConfig[itemId];
    } else {
        Config[config] = (u_long) strtoul(value, nullptr, 0);
    }
    env->ReleaseStringUTFChars(s, config);
    env->ReleaseStringUTFChars(v, value);
}

void native_saveConfiguration(JNIEnv *env, jobject thiz) {
    jclass floatingClass = env->FindClass("com/bearmod/Floating");
    if (floatingClass) {
        jmethodID saveConfigMethod = env->GetStaticMethodID(floatingClass, "SaveConfig", "()V");
        if (saveConfigMethod) {
            env->CallStaticVoidMethod(floatingClass, saveConfigMethod);
        }
        env->DeleteLocalRef(floatingClass);
    }
}

extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Floating_onlinename(JNIEnv *env, jobject thiz) { return env->NewStringUTF(OBFUSCATE("BEAR-MOD")); }
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Floating_channellink(JNIEnv *env, jobject thiz) { return env->NewStringUTF(OBFUSCATE("https://t.me/bear_mod")); }
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Floating_feedbacklink(JNIEnv *env, jobject thiz) { return env->NewStringUTF(OBFUSCATE("https://t.me/bearfeedbackbot")); }
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Floating_ChannelName(JNIEnv *env, jobject thiz) { return env->NewStringUTF(OBFUSCATE("JOIN OFFICIAL CHANNEL")); }
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Floating_FeedBackName(JNIEnv *env, jobject thiz) { return env->NewStringUTF(OBFUSCATE("FeedBack")); }
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Floating_cfg(JNIEnv *env, jobject thiz ) { return env->NewStringUTF(OBFUSCATE("NRG_SaveFile.cfg"));}

// ===================================================================================================
// LAUNCHER NATIVE STRING FUNCTIONS
// ===================================================================================================
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Launcher_LoginNameNrg(JNIEnv *env, jclass clazz) { return env->NewStringUTF(OBFUSCATE("ACTIVE KEY USER")); }
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Launcher_Pleaselog(JNIEnv *env, jclass clazz) { return env->NewStringUTF(OBFUSCATE("Please log in")); }
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Launcher_KeyAdd(JNIEnv *env, jclass clazz) { return env->NewStringUTF(OBFUSCATE("Enter your key")); }
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Launcher_Login(JNIEnv *env, jclass clazz) { return env->NewStringUTF(OBFUSCATE("Login")); }
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Launcher_Cancel(JNIEnv *env, jclass clazz) { return env->NewStringUTF(OBFUSCATE("Cancel")); }
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Launcher_Error(JNIEnv *env, jclass clazz) { return env->NewStringUTF(OBFUSCATE("Error")); }
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Launcher_Pleasecheck(JNIEnv *env, jclass clazz) { return env->NewStringUTF(OBFUSCATE("Please check your key")); }
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Launcher_Ok(JNIEnv *env, jclass clazz) { return env->NewStringUTF(OBFUSCATE("OK")); }
extern "C" JNIEXPORT jstring JNICALL Java_com_bearmod_Launcher_Loging(JNIEnv *env, jclass clazz) { return env->NewStringUTF(OBFUSCATE("Logging in...")); }

// ===================================================================================================
// NEW DATA-DRIVEN SKIN API
// ===================================================================================================

// Central map to store the user's selected skin index for each item.
static std::map<std::string, int> selectedSkins;

// ===================================================================================================
// CLEANED UP: REMOVED ORPHANED SKINMANAGER FUNCTIONS
// ===================================================================================================
// Removed 120+ lines of dead SkinManager native methods that had no Java connections

// ===================================================================================================
// THREADING, INITIALIZATION, AND JNI REGISTRATION
// ===================================================================================================
void native_Init_Floating(JNIEnv *env, jobject thiz); // Forward declaration
void native_Init_Main(JNIEnv *env, jobject thiz, jobject context) { }
// CURL authentication removed - using KeyAuth API only in Java

// Forward declaration for DrawOn from NRG.h
extern "C" JNIEXPORT void JNICALL Java_com_bearmod_Floating_DrawOn(JNIEnv *env, jclass type, jobject espView, jobject canvas);

int Register1(JNIEnv *env) {
    JNINativeMethod methods[] = {
        {"onSendConfig", "(Ljava/lang/String;Ljava/lang/String;)V", (void *) native_onSendConfig},
        {"Init", "()V", (void *) native_Init_Floating},
        {"saveConfiguration", "()V", (void *) native_saveConfiguration},
        {"DrawOn", "(Lcom/bearmod/ESPView;Landroid/graphics/Canvas;)V", (void *) Java_com_bearmod_Floating_DrawOn}
    };
    jclass clazz = env->FindClass("com/bearmod/Floating");
    if (!clazz) return -1;
    if (env->RegisterNatives(clazz, methods, 4) != 0) return -1;
    env->DeleteLocalRef(clazz);
    return 0;
}

int Register2(JNIEnv *env) {
    JNINativeMethod methods[] = {
        {"Init",  "(Landroid/content/Context;)V", (void *) native_Init_Main}
        // REMOVED: Check method - using KeyAuth API only
    };
    jclass clazz = env->FindClass("com/bearmod/Launcher");
    if (!clazz) return -1;
    if (env->RegisterNatives(clazz, methods, 1) != 0) return -1;
    env->DeleteLocalRef(clazz);
    return 0;
}

int Register3(JNIEnv *env) {
    JNINativeMethod methods[] = {
        {"IsHideEsp","()Z", (void *) IsHideEsp},
        // {"nativeEnableRecorderFakeMode","()V", (void *) native_enableRecorderFakeMode},
        // {"nativeDisableRecorderFakeMode","()V", (void *) native_disableRecorderFakeMode},
        // {"nativeToggleRecorderFakeMode","()V", (void *) native_toggleRecorderFakeMode},
        // {"nativeAutoToggleRecorderFakeMode","()V", (void *) native_autoToggleRecorderFakeMode}
    };
    jclass clazz = env->FindClass("com/bearmod/Floating");
    if (!clazz) return -1;
    if (env->RegisterNatives(clazz, methods, 1) != 0) return -1;
    env->DeleteLocalRef(clazz);
    return 0;
}

__attribute((constructor)) void on_load() {
    // Initialization code - removed anti-cheat thread to resolve linker issues
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    Register1(env);
    Register2(env);
    Register3(env);
    // Use the actual function from NRG.h instead of duplicating it
    return JNI_VERSION_1_6;
}

void native_Init_Floating(JNIEnv *env, jobject thiz) {
    // Use the actual Init_Thread from NRG.h instead of creating a duplicate
    // Initialize skin system
    initializeSkinSystem();
    
    // Start the game hooking thread
    pthread_t t;
    pthread_create(&t, 0, Init_Thread, 0);
}

// Removed remaining orphaned SkinManager functions

// ===================================================================================================
// ENHANCED SKIN NAME DISPLAY FUNCTIONS FOR UI
// ===================================================================================================
// These functions provide skin names for the floating menu UI to display alongside numbers
// ===================================================================================================

extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_getSkinName(JNIEnv *env, jclass clazz, jstring category, jint skinIndex) {
    const char *cat = env->GetStringUTFChars(category, 0);
    std::string categoryStr(cat);
    env->ReleaseStringUTFChars(category, cat);
    
    std::string skinName = "Unknown";
    
    // Handle X-Suit category
    if (categoryStr == "SKIN_XSUIT") {
        if (xSuitSkins.count(skinIndex)) {
            skinName = xSuitSkins.at(skinIndex).name;
        }
    }
    // Handle Outfit Set category
    else if (categoryStr == "SKIN_SET") {
        if (outfitSkins.count(skinIndex)) {
            skinName = outfitSkins.at(skinIndex).name;
        }
    }
    // Handle Backpack category
    else if (categoryStr == "SKIN_BACKPACK") {
        if (helmetSkins.count(skinIndex)) {
            skinName = "Backpack Lv.3";
        }
    }
    // Handle Helmet category
    else if (categoryStr == "SKIN_HELMET") {
        if (helmetSkins.count(skinIndex)) {
            skinName = "Helmet Lv.3";
        }
    }
    // Handle weapon categories using ESP_SKIN.h functions
    else if (categoryStr == "SKIN_M416") {
        skinName = getSkinDisplayName("M416", skinIndex);
    }
    else if (categoryStr == "SKIN_AKM") {
        skinName = getSkinDisplayName("AKM", skinIndex);
    }
    else if (categoryStr == "SKIN_SCARL") {
        skinName = getSkinDisplayName("SCAR-L", skinIndex);
    }
    else if (categoryStr == "SKIN_M762") {
        skinName = getSkinDisplayName("M762", skinIndex);
    }
    else if (categoryStr == "SKIN_M16A4") {
        skinName = getSkinDisplayName("M16A4", skinIndex);
    }
    else if (categoryStr == "SKIN_GROZAR") {
        skinName = getSkinDisplayName("GROZA", skinIndex);
    }
    else if (categoryStr == "SKIN_AUG") {
        skinName = getSkinDisplayName("AUG", skinIndex);
    }
    else if (categoryStr == "SKIN_ACE32") {
        skinName = getSkinDisplayName("ACE32", skinIndex);
    }
    else if (categoryStr == "SKIN_M249") {
        skinName = getSkinDisplayName("M249", skinIndex);
    }
    else if (categoryStr == "SKIN_DP28") {
        skinName = getSkinDisplayName("DP28", skinIndex);
    }
    else if (categoryStr == "SKIN_MG3") {
        skinName = getSkinDisplayName("MG3", skinIndex);
    }
    else if (categoryStr == "SKIN_P90") {
        skinName = getSkinDisplayName("P90", skinIndex);
    }
    else if (categoryStr == "SKIN_UZI") {
        skinName = getSkinDisplayName("UZI", skinIndex);
    }
    else if (categoryStr == "SKIN_UMP45") {
        skinName = getSkinDisplayName("UMP45", skinIndex);
    }
    else if (categoryStr == "SKIN_VECTOR") {
        skinName = getSkinDisplayName("Vector", skinIndex);
    }
    else if (categoryStr == "SKIN_THOMPSON") {
        skinName = getSkinDisplayName("Thompson", skinIndex);
    }
    else if (categoryStr == "SKIN_M24") {
        skinName = getSkinDisplayName("M24", skinIndex);
    }
    else if (categoryStr == "SKIN_KAR98K") {
        skinName = getSkinDisplayName("KAR98K", skinIndex);
    }
    else if (categoryStr == "SKIN_AWM") {
        skinName = getSkinDisplayName("AWM", skinIndex);
    }
    else if (categoryStr == "SKIN_AMR") {
        skinName = getSkinDisplayName("AMR", skinIndex);
    }
    else if (categoryStr == "SKIN_MK14") {
        skinName = getSkinDisplayName("MK14", skinIndex);
    }
    else if (categoryStr == "SKIN_DACIA") {
        skinName = "Dacia Vehicle Skin";
    }
    else if (categoryStr == "SKIN_COUPERP") {
        skinName = "Coupe Vehicle Skin";
    }
    else if (categoryStr == "SKIN_UAZ") {
        skinName = "UAZ Vehicle Skin";
    }
    else if (categoryStr == "SKIN_MOTO") {
        skinName = "Motorcycle Skin";
    }
    
    return env->NewStringUTF(skinName.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_bearmod_Floating_getSkinNameShort(JNIEnv *env, jclass clazz, jstring category, jint skinIndex) {
    const char *cat = env->GetStringUTFChars(category, 0);
    std::string categoryStr(cat);
    env->ReleaseStringUTFChars(category, cat);
    
    std::string skinName = "Default";
    
    // Handle X-Suit category
    if (categoryStr == "SKIN_XSUIT") {
        if (xSuitSkins.count(skinIndex)) {
            skinName = xSuitSkins.at(skinIndex).name;
            // Remove "X-Suit" suffix for shorter display
            size_t pos = skinName.find(" X-Suit");
            if (pos != std::string::npos) {
                skinName = skinName.substr(0, pos);
            }
        }
    }
    // Handle Outfit Set category
    else if (categoryStr == "SKIN_SET") {
        if (outfitSkins.count(skinIndex)) {
            skinName = outfitSkins.at(skinIndex).name;
            // Remove "Set" suffix for shorter display
            size_t pos = skinName.find(" Set");
            if (pos != std::string::npos) {
                skinName = skinName.substr(0, pos);
            }
        }
    }
    // Handle weapon categories using getSkinName from ESP_SKIN.h
    else if (categoryStr == "SKIN_M416") {
        skinName = getSkinName("M416", skinIndex);
    }
    else if (categoryStr == "SKIN_AKM") {
        skinName = getSkinName("AKM", skinIndex);
    }
    else if (categoryStr == "SKIN_SCARL") {
        skinName = getSkinName("SCAR-L", skinIndex);
    }
    else if (categoryStr == "SKIN_M762") {
        skinName = getSkinName("M762", skinIndex);
    }
    else if (categoryStr == "SKIN_M16A4") {
        skinName = getSkinName("M16A4", skinIndex);
    }
    else if (categoryStr == "SKIN_GROZAR") {
        skinName = getSkinName("GROZA", skinIndex);
    }
    else if (categoryStr == "SKIN_AUG") {
        skinName = getSkinName("AUG", skinIndex);
    }
    else if (categoryStr == "SKIN_ACE32") {
        skinName = getSkinName("ACE32", skinIndex);
    }
    else if (categoryStr == "SKIN_M249") {
        skinName = getSkinName("M249", skinIndex);
    }
    else if (categoryStr == "SKIN_DP28") {
        skinName = getSkinName("DP28", skinIndex);
    }
    else if (categoryStr == "SKIN_MG3") {
        skinName = getSkinName("MG3", skinIndex);
    }
    else if (categoryStr == "SKIN_P90") {
        skinName = getSkinName("P90", skinIndex);
    }
    else if (categoryStr == "SKIN_UZI") {
        skinName = getSkinName("UZI", skinIndex);
    }
    else if (categoryStr == "SKIN_UMP45") {
        skinName = getSkinName("UMP45", skinIndex);
    }
    else if (categoryStr == "SKIN_VECTOR") {
        skinName = getSkinName("Vector", skinIndex);
    }
    else if (categoryStr == "SKIN_THOMPSON") {
        skinName = getSkinName("Thompson", skinIndex);
    }
    else if (categoryStr == "SKIN_M24") {
        skinName = getSkinName("M24", skinIndex);
    }
    else if (categoryStr == "SKIN_KAR98K") {
        skinName = getSkinName("KAR98K", skinIndex);
    }
    else if (categoryStr == "SKIN_AWM") {
        skinName = getSkinName("AWM", skinIndex);
    }
    else if (categoryStr == "SKIN_AMR") {
        skinName = getSkinName("AMR", skinIndex);
    }
    else if (categoryStr == "SKIN_MK14") {
        skinName = getSkinName("MK14", skinIndex);
    }
    else if (categoryStr == "SKIN_BACKPACK") {
        skinName = "Backpack Lv.3";
    }
    else if (categoryStr == "SKIN_HELMET") {
        skinName = "Helmet Lv.3";
    }
    else if (categoryStr == "SKIN_DACIA") {
        skinName = "Dacia";
    }
    else if (categoryStr == "SKIN_COUPERP") {
        skinName = "Coupe";
    }
    else if (categoryStr == "SKIN_UAZ") {
        skinName = "UAZ";
    }
    else if (categoryStr == "SKIN_MOTO") {
        skinName = "Motorcycle";
    }
    
    return env->NewStringUTF(skinName.c_str());
}

// ===================================================================================================
// CRITICAL FIX: BRIDGE BETWEEN UI SELECTIONS AND SKIN SYSTEM
// ===================================================================================================
// This function bridges the gap between selectedSkins (UI) and Config (skin system)
// ===================================================================================================

extern std::map<std::string, long> Config; // Reference to the actual Config map (CORRECT TYPE)

void syncSelectedSkinsToConfig() {
    // Bridge the critical gap: selectedSkins → Config
    for (const auto& pair : selectedSkins) {
        const std::string& key = pair.first;
        int value = pair.second;
        
        // Update the Config map that updateSkin() actually reads from (FIXED: using long)
        Config[key] = static_cast<long>(value);
    }
}

// Enhanced native functions that now actually apply skins
extern "C" JNIEXPORT void JNICALL
Java_com_bearmod_Floating_applySkinConfiguration(JNIEnv *env, jclass clazz) {
    // CRITICAL: Sync UI selections to the actual skin system
    syncSelectedSkinsToConfig();
    
    // Now call the existing updateSkin() function which will work properly
    updateSkin();
}