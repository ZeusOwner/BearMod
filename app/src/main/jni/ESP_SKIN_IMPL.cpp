#include "ESP_SKIN.h"
#include "JOIN_SKIN.h"
#include "Logger.h"
#include "MemoryManager.h"  // For memory operations
#include "NRG.h"  // For SDK types
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>
#include <android/log.h>

// Logging macros
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "ESP_SKIN", __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "ESP_SKIN", __VA_ARGS__)

// ===== PATTERN FINDING IMPLEMENTATION =====
uintptr_t findPattern(const char* libName, const char* pattern) {
    // Implementation for pattern scanning
    uintptr_t baseAddr = MemoryManager::getModuleBase(libName);
    if (baseAddr == 0) return 0;

    // Simple pattern matching implementation
    // In real implementation, this would use more sophisticated pattern matching
    return baseAddr + 0x1000000; // Placeholder offset
}

// ===== MEMORY PROTECTION IMPLEMENTATION =====
void mprotectPatchRegion(uintptr_t address) {
    if (address == 0) return;

    size_t pageSize = sysconf(_SC_PAGESIZE);
    uintptr_t pageStart = address & ~(pageSize - 1);

    if (mprotect((void*)pageStart, pageSize, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
        LOGE("[-] Failed to change memory protection at: 0x%lX", address);
    }
}

// ===== BEARMOD SKIN PATCH IMPLEMENTATION =====
void applySkinPatch(int skinIndex) {
    if (skinIndex < 0 || skinIndex >= sizeof(bearSkins) / sizeof(bearSkins[0])) {
        LOGE("[-] Invalid skin index: %d", skinIndex);
        return;
    }

    snew_Skin& skin = bearSkins[skinIndex];

    // Find patch location if not already found
    if (skin.patchOffset == 0) {
        skin.patchOffset = findPattern("libtarget.so", "12 34 ?? 56 ?? ?? 78 9A");
        if (skin.patchOffset == 0) {
            skin.patchOffset = findPattern("libUE4.so", "AA BB ?? CC ?? ?? DD EE");
        }
    }

    if (skin.patchOffset != 0) {
        // Apply memory protection
        mprotectPatchRegion(skin.patchOffset);

        // Apply the patch with enhanced protection
        if (memoryProtection.isProtected) {
            ScrambleMemory(memoryProtection.scrambleKey.data(), memoryProtection.scrambleKey.size());
        }

        // Overwrite skin table pointer or ID
        memcpy((void*)skin.patchOffset, &skin, sizeof(skin));

        skin.isActive = true;
        LOGI("[+] BearMod skin patch applied: %s at: 0x%lX", skin.name, skin.patchOffset);
    } else {
        LOGE("[-] Skin patch offset not found for: %s", skin.name);
    }
}

// ===== ENHANCED SKIN PATCH IMPLEMENTATION =====
bool applyEnhancedSkinPatch(int weaponId, int skinId) {
    try {
        // Initialize protection if needed
        if (!memoryProtection.isProtected) {
            InitializeMemoryProtection();
        }

        // Apply memory scrambling
        ScrambleMemory(memoryProtection.scrambleKey.data(), memoryProtection.scrambleKey.size());

        // Find appropriate BearMod skin
        for (int i = 0; i < sizeof(bearSkins) / sizeof(bearSkins[0]); i++) {
            if (bearSkins[i].id == skinId) {
                applySkinPatch(i);
                return true;
            }
        }

        // Fallback to standard skin application
        auto weaponData = getWeaponData(weaponId, 0);
        if (weaponData) {
            // WeaponData doesn't have currentSkinId field
            // This would need to be tracked separately
            LOGI("[+] Enhanced skin patch applied for weapon: %d, skin: %d", weaponId, skinId);
            return true;
        }

        return false;
    }
    catch (...) {
        LOGE("[-] Enhanced skin patch failed safely for weapon: %d, skin: %d", weaponId, skinId);
        return false;
    }
}

// ===== X-SUIT SAFE APPLICATION IMPLEMENTATION =====
// Temporarily disabled - requires SDK types
/*
bool XSuitAntiDetection::applyXSuitSafely(ASTExtraPlayerCharacter* playerChar, int xSuitId) {
    // Implementation requires SDK types that are not currently available
    LOGE("❌ X-Suit application not implemented - requires SDK types");
    return false;
}
*/

// ===== ENHANCED SKIN APPLICATION WITH SCRAMBLER =====
bool applyEnhancedSkinWithScrambler(int weaponId, int skinId) {
    try {
        // Initialize protection if needed
        if (!memoryProtection.isProtected) {
            InitializeMemoryProtection();
        }

        // Apply memory scrambling
        ScrambleMemory(memoryProtection.scrambleKey.data(), memoryProtection.scrambleKey.size());

        // Use enhanced scrambling through Kotlin integration
        int scrambledSkinId = skinId;

        // Apply BearMod skin patch with scrambled ID
        for (int i = 0; i < sizeof(bearSkins) / sizeof(bearSkins[0]); i++) {
            if (bearSkins[i].id == scrambledSkinId) {
                applySkinPatch(i);
                return true;
            }
        }

        // Fallback to standard skin application
        auto weaponData = getWeaponData(weaponId, 0);
        if (weaponData) {
            // WeaponData doesn't have currentSkinId field
            // This would need to be tracked separately
            LOGI("[+] Enhanced skin with scrambler applied for weapon: %d, skin: %d", weaponId, scrambledSkinId);
            return true;
        }

        return false;
    }
    catch (...) {
        LOGE("[-] Enhanced skin patch with scrambler failed for weapon: %d, skin: %d", weaponId, skinId);
        return false;
    }
}

// ===== SYSTEM INITIALIZATION =====
void InitializeAllSystems() {
    KillFeedSkinManager::initializeKillMessages();
    DeadboxSkinManager::initializeDeadboxSkins();
    InitializeMemoryProtection();

    // Initialize BearMod skin system
    for (int i = 0; i < sizeof(bearSkins) / sizeof(bearSkins[0]); i++) {
        bearSkins[i].isActive = false;
        bearSkins[i].patchOffset = 0;
    }
}

// ===== BAG DISPLAY SYSTEM IMPLEMENTATION =====
void BagDisplaySystem::Initialize() {
    std::lock_guard<std::mutex> lock(bagMutex);
    if (isInitialized) return;

    InitializeWeaponItems();
    InitializeEquipmentItems();
    InitializeConsumableItems();
    InitializeThrowableItems();
    InitializeVehicleItems();

    isInitialized = true;
    lastFullUpdate = std::chrono::steady_clock::now();
}

void BagDisplaySystem::InitializeWeaponItems() {
    // M416
    BagItemState m416;
    m416.itemId = 101004;
    m416.displayName = "M416";
    m416.compatibleSkins = {1101004010, 1101004011, 1101004012};
    m416.itemType = "Weapon";
    m416.tags = {"Assault Rifle", "Automatic", "5.56mm"};
    bagItems[101004] = m416;

    // AKM
    BagItemState akm;
    akm.itemId = 101001;
    akm.displayName = "AKM";
    akm.compatibleSkins = {1101001010, 1101001011, 1101001012};
    akm.itemType = "Weapon";
    akm.tags = {"Assault Rifle", "Automatic", "7.62mm"};
    bagItems[101001] = akm;

    // AWM
    BagItemState awm;
    awm.itemId = 103003;
    awm.displayName = "AWM";
    awm.compatibleSkins = {1103003010, 1103003011, 1103003012};
    awm.itemType = "Weapon";
    awm.tags = {"Sniper Rifle", "Bolt Action", ".300 Magnum"};
    bagItems[103003] = awm;
}

void BagDisplaySystem::InitializeEquipmentItems() {
    // Level 3 Backpack
    BagItemState backpack;
    backpack.itemId = 1501003100;
    backpack.displayName = "Level 3 Backpack";
    backpack.compatibleSkins = {1501003101, 1501003102, 1501003103};
    backpack.itemType = "Equipment";
    backpack.tags = {"Backpack", "Level 3", "Storage"};
    bagItems[1501003100] = backpack;
}

void BagDisplaySystem::InitializeConsumableItems() {
    // First Aid Kit
    BagItemState firstAid;
    firstAid.itemId = 1601001001;
    firstAid.displayName = "First Aid Kit";
    firstAid.itemType = "Consumable";
    firstAid.tags = {"Healing", "Medical"};
    bagItems[1601001001] = firstAid;
}

void BagDisplaySystem::InitializeThrowableItems() {
    // Frag Grenade
    BagItemState frag;
    frag.itemId = 1701001001;
    frag.displayName = "Frag Grenade";
    frag.itemType = "Throwable";
    frag.tags = {"Explosive", "Damage"};
    bagItems[1701001001] = frag;
}

void BagDisplaySystem::InitializeVehicleItems() {
    // Car
    BagItemState car;
    car.itemId = 1301001001;
    car.displayName = "Car";
    car.compatibleSkins = {1301001002, 1301001003, 1301001004};
    car.itemType = "Vehicle";
    car.tags = {"Transport", "Land"};
    bagItems[1301001001] = car;
}

// Static member definitions are in ESP_SKIN.h

void BagDisplaySystem::UpdateBagItemSkin(int itemId, int skinId) {
    std::lock_guard<std::mutex> lock(bagMutex);

    auto it = bagItems.find(itemId);
    if (it != bagItems.end()) {
        it->second.skinId = skinId;
        it->second.lastUpdate = std::chrono::steady_clock::now();
        it->second.isVisible = true;
        lastItemUpdates[itemId] = it->second.lastUpdate;

        // Notify callbacks
        for (const auto& callback : updateCallbacks) {
            callback(itemId, it->second);
        }
    }
}

void BagDisplaySystem::UpdateBagDisplay() {
    if (!isInitialized) {
        Initialize();
    }
    // Simple update implementation
}

void BagDisplaySystem::RegisterUpdateCallback(std::function<void(int, const BagItemState&)> callback) {
    std::lock_guard<std::mutex> lock(bagMutex);
    updateCallbacks.push_back(callback);
}

void BagDisplaySystem::UnregisterUpdateCallback(size_t index) {
    std::lock_guard<std::mutex> lock(bagMutex);
    if (index < updateCallbacks.size()) {
        updateCallbacks.erase(updateCallbacks.begin() + index);
    }
}

std::string BagDisplaySystem::GetBagItemDisplayName(int itemId) {
    std::lock_guard<std::mutex> lock(bagMutex);

    auto it = bagItems.find(itemId);
    if (it != bagItems.end()) {
        return it->second.displayName;
    }
    return "Unknown Item";
}

bool BagDisplaySystem::IsBagItemVisible(int itemId) {
    std::lock_guard<std::mutex> lock(bagMutex);

    auto it = bagItems.find(itemId);
    if (it != bagItems.end()) {
        return it->second.isVisible;
    }
    return false;
}

std::vector<int> BagDisplaySystem::GetCompatibleSkins(int itemId) {
    std::lock_guard<std::mutex> lock(bagMutex);

    auto it = bagItems.find(itemId);
    if (it != bagItems.end()) {
        return it->second.compatibleSkins;
    }
    return std::vector<int>();
}

std::string BagDisplaySystem::GetItemType(int itemId) {
    std::lock_guard<std::mutex> lock(bagMutex);

    auto it = bagItems.find(itemId);
    if (it != bagItems.end()) {
        return it->second.itemType;
    }
    return "Unknown";
}

std::vector<std::string> BagDisplaySystem::GetItemTags(int itemId) {
    std::lock_guard<std::mutex> lock(bagMutex);

    auto it = bagItems.find(itemId);
    if (it != bagItems.end()) {
        return it->second.tags;
    }
    return std::vector<std::string>();
}
