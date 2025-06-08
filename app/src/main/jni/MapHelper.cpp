#include "MapHelper.h"
#include <algorithm>

// Static instance
MapHelper* MapHelper::instance = nullptr;

MapHelper::MapHelper() : screenWidth(0), screenHeight(0) {
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "MapHelper created");
}

MapHelper::~MapHelper() {
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "MapHelper destroyed");
}

void MapHelper::Initialize(int width, int height) {
    screenWidth = width;
    screenHeight = height;
    
    // Initialize default item configuration
    itemConfig[101001] = true;  // AKM
    itemConfig[101004] = true;  // M416
    itemConfig[103003] = true;  // AWM
    itemConfig[102001] = true;  // UZI
    itemConfig[105001] = true;  // M249
    
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "MapHelper initialized with screen size: %dx%d", width, height);
}

void MapHelper::UpdateLocalPlayerPosition(float x, float y, float z) {
    localPlayerPosition = Vector3(x, y, z);
    CalculateDistances();
}

void MapHelper::AddItem(int id, const std::string& name, ItemType type, float x, float y, float z) {
    Item item(id, name, type, Vector3(x, y, z));
    items.push_back(item);
}

void MapHelper::AddPlayer(int id, const std::string& name, float x, float y, float z, float health, bool isBot, bool isTeammate) {
    Player player(id, name, Vector3(x, y, z), health, isBot, isTeammate);
    players.push_back(player);
}

void MapHelper::Clear() {
    items.clear();
    players.clear();
}

std::vector<Item> MapHelper::GetItemsInRange(float maxDistance) {
    std::vector<Item> result;
    
    for (const auto& item : items) {
        if (item.distance <= maxDistance && IsItemEnabled(item.id)) {
            result.push_back(item);
        }
    }
    
    // Sort by distance
    std::sort(result.begin(), result.end(), [](const Item& a, const Item& b) {
        return a.distance < b.distance;
    });
    
    return result;
}

std::vector<Player> MapHelper::GetPlayersInRange(float maxDistance) {
    std::vector<Player> result;
    
    for (const auto& player : players) {
        if (player.distance <= maxDistance) {
            result.push_back(player);
        }
    }
    
    // Sort by distance
    std::sort(result.begin(), result.end(), [](const Player& a, const Player& b) {
        return a.distance < b.distance;
    });
    
    return result;
}

Vector2 MapHelper::WorldToScreen(const Vector3& worldPos) {
    // Simple world to screen conversion
    // This would need to be implemented based on the game's camera matrix
    float screenX = (worldPos.x - localPlayerPosition.x) * 10.0f + screenWidth / 2.0f;
    float screenY = (worldPos.z - localPlayerPosition.z) * 10.0f + screenHeight / 2.0f;
    
    return Vector2(screenX, screenY);
}

void MapHelper::SetItemConfig(int itemId, bool enabled) {
    itemConfig[itemId] = enabled;
}

bool MapHelper::IsItemEnabled(int itemId) {
    auto it = itemConfig.find(itemId);
    return it != itemConfig.end() ? it->second : false;
}

void MapHelper::CalculateDistances() {
    // Calculate distances for items
    for (auto& item : items) {
        item.distance = item.position.Distance(localPlayerPosition);
    }
    
    // Calculate distances for players
    for (auto& player : players) {
        player.distance = player.position.Distance(localPlayerPosition);
    }
}

void MapHelper::RegisterNatives(JNIEnv* env) {
    jclass clazz = env->FindClass("com/bearmod/loader/MapHelper");
    if (!clazz) {
        __android_log_print(ANDROID_LOG_ERROR, "MapHelper", "Failed to find MapHelper class");
        return;
    }
    
    JNINativeMethod methods[] = {
        {"nativeInitialize", "(II)V", (void*)JNI_Initialize},
        {"nativeUpdateLocalPlayerPosition", "(FFF)V", (void*)JNI_UpdateLocalPlayerPosition},
        {"nativeAddItem", "(ILjava/lang/String;IFFF)V", (void*)JNI_AddItem},
        {"nativeAddPlayer", "(ILjava/lang/String;FFFZZ)V", (void*)JNI_AddPlayer},
        {"nativeClear", "()V", (void*)JNI_Clear},
        {"nativeGetItemsInRange", "(F)[Ljava/lang/Object;", (void*)JNI_GetItemsInRange},
        {"nativeGetPlayersInRange", "(F)[Ljava/lang/Object;", (void*)JNI_GetPlayersInRange},
        {"nativeSetItemConfig", "(IZ)V", (void*)JNI_SetItemConfig},
        {"nativeIsItemEnabled", "(I)Z", (void*)JNI_IsItemEnabled}
    };
    
    env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0]));
    __android_log_print(ANDROID_LOG_INFO, "MapHelper", "Native methods registered");
}

// JNI Implementation methods
void MapHelper::JNI_Initialize(JNIEnv* env, jclass clazz, jint width, jint height) {
    if (!instance) {
        instance = new MapHelper();
    }
    instance->Initialize(width, height);
}

void MapHelper::JNI_UpdateLocalPlayerPosition(JNIEnv* env, jclass clazz, jfloat x, jfloat y, jfloat z) {
    if (instance) {
        instance->UpdateLocalPlayerPosition(x, y, z);
    }
}

void MapHelper::JNI_AddItem(JNIEnv* env, jclass clazz, jint id, jstring name, jint type, jfloat x, jfloat y, jfloat z) {
    if (instance) {
        const char* nameStr = env->GetStringUTFChars(name, nullptr);
        instance->AddItem(id, std::string(nameStr), static_cast<ItemType>(type), x, y, z);
        env->ReleaseStringUTFChars(name, nameStr);
    }
}

void MapHelper::JNI_AddPlayer(JNIEnv* env, jclass clazz, jint id, jstring name, jfloat x, jfloat y, jfloat z, jfloat health, jboolean isBot, jboolean isTeammate) {
    if (instance) {
        const char* nameStr = env->GetStringUTFChars(name, nullptr);
        instance->AddPlayer(id, std::string(nameStr), x, y, z, health, isBot, isTeammate);
        env->ReleaseStringUTFChars(name, nameStr);
    }
}

void MapHelper::JNI_Clear(JNIEnv* env, jclass clazz) {
    if (instance) {
        instance->Clear();
    }
}

jobjectArray MapHelper::JNI_GetItemsInRange(JNIEnv* env, jclass clazz, jfloat maxDistance) {
    if (!instance) return nullptr;
    
    auto items = instance->GetItemsInRange(maxDistance);
    // Implementation would create Java object array
    // For now, return null
    return nullptr;
}

jobjectArray MapHelper::JNI_GetPlayersInRange(JNIEnv* env, jclass clazz, jfloat maxDistance) {
    if (!instance) return nullptr;
    
    auto players = instance->GetPlayersInRange(maxDistance);
    // Implementation would create Java object array
    // For now, return null
    return nullptr;
}

void MapHelper::JNI_SetItemConfig(JNIEnv* env, jclass clazz, jint itemId, jboolean enabled) {
    if (instance) {
        instance->SetItemConfig(itemId, enabled);
    }
}

jboolean MapHelper::JNI_IsItemEnabled(JNIEnv* env, jclass clazz, jint itemId) {
    if (instance) {
        return instance->IsItemEnabled(itemId);
    }
    return false;
}
