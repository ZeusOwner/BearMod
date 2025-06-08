#ifndef ESP_SKIN_H
#define ESP_SKIN_H

#include <map>
#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <algorithm>
#include <thread>
#include <mutex>

// Forward declarations to avoid circular dependencies
struct MemoryProtectionState;
extern MemoryProtectionState memoryProtection;

// ===== MEMORY PROTECTION SYSTEM =====
struct MemoryProtectionState {
    bool isProtected = false;
    std::vector<uint8_t> scrambleKey;
    int protectionLevel = 0;
    std::chrono::steady_clock::time_point lastScrambleTime;
};

// Global memory protection instance
MemoryProtectionState memoryProtection;

// Memory protection functions
static void InitializeMemoryProtection() {
    if (!memoryProtection.isProtected) {
        memoryProtection.scrambleKey.resize(32);
        std::random_device rd;
        std::generate(memoryProtection.scrambleKey.begin(), memoryProtection.scrambleKey.end(), std::ref(rd));
        memoryProtection.isProtected = true;
        memoryProtection.protectionLevel = 2;
        memoryProtection.lastScrambleTime = std::chrono::steady_clock::now();
    }
}

static void ScrambleMemory(const uint8_t* key, size_t keySize) {
    if (!memoryProtection.isProtected) {
        InitializeMemoryProtection();
    }

    // Create scramble buffer
    std::vector<uint8_t> buffer(1024);
    std::random_device rd;
    std::generate(buffer.begin(), buffer.end(), std::ref(rd));

    // Apply XOR scrambling with key
    for (size_t i = 0; i < buffer.size(); i++) {
        buffer[i] ^= key[i % keySize];
    }

    // Update last scramble time
    memoryProtection.lastScrambleTime = std::chrono::steady_clock::now();

    // Clear sensitive data
    std::fill(buffer.begin(), buffer.end(), 0);
}

// ===== X-SUIT ANTI-DETECTION SYSTEM =====
struct XSuitAntiDetection {
    static std::map<int, uint64_t> lastApplicationTimes;
    static std::map<int, int> applicationCounts;
    static std::vector<uint8_t> memoryBuffer;
    static std::random_device rd;
    static std::mt19937 gen;
    static const uint64_t MIN_COOLDOWN_MS = 30000; // 30 seconds minimum
    static const uint64_t MAX_COOLDOWN_MS = 120000; // 2 minutes maximum
    static const int MAX_APPLICATIONS_PER_HOUR = 5;

    // Enhanced X-Suit ID scrambling with time-based variation
    static int scrambleXSuitId(int originalId) {
        if (!memoryProtection.isProtected) {
            InitializeMemoryProtection();
        }

        // Apply multi-layer scrambling
        uint64_t timeKey = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count();

        // Layer 1: XOR with time-based key
        uint32_t scrambled = static_cast<uint32_t>(originalId);
        scrambled ^= static_cast<uint32_t>(timeKey & 0xFFFFFFFF);

        // Layer 2: Bit rotation based on memory protection key
        if (memoryProtection.scrambleKey.size() >= 4) {
            uint8_t rotationBits = memoryProtection.scrambleKey[0] & 0x1F;
            scrambled = (scrambled << rotationBits) | (scrambled >> (32 - rotationBits));
        }

        // Layer 3: Salt with memory protection key
        for (size_t i = 0; i < memoryProtection.scrambleKey.size() && i < 4; i++) {
            scrambled ^= (memoryProtection.scrambleKey[i] << (i * 8));
        }

        return static_cast<int>(scrambled);
    }

    // Check if it's safe to apply X-Suit
    static bool isSafeToApply(int xSuitId) {
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count();

        // Check cooldown
        auto it = lastApplicationTimes.find(xSuitId);
        if (it != lastApplicationTimes.end()) {
            uint64_t elapsed = now - it->second;
            if (elapsed < MIN_COOLDOWN_MS) {
                return false; // Still in cooldown
            }
        }

        // Check application count
        auto countIt = applicationCounts.find(xSuitId);
        if (countIt != applicationCounts.end()) {
            if (countIt->second >= MAX_APPLICATIONS_PER_HOUR) {
                return false; // Too many applications
            }
        }

        return true;
    }

    // Record application
    static void recordApplication(int xSuitId) {
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count();
        
        lastApplicationTimes[xSuitId] = now;
        applicationCounts[xSuitId]++;
    }

    // Reset counts periodically
    static void resetCounts() {
        applicationCounts.clear();
    }

    // Apply X-Suit with maximum anti-detection
    // Temporarily disabled - requires SDK types
    // static bool applyXSuitSafely(ASTExtraPlayerCharacter* playerChar, int xSuitId);
};

// Static member definitions for XSuitAntiDetection
std::map<int, uint64_t> XSuitAntiDetection::lastApplicationTimes;
std::map<int, int> XSuitAntiDetection::applicationCounts;
std::vector<uint8_t> XSuitAntiDetection::memoryBuffer;
std::random_device XSuitAntiDetection::rd;
std::mt19937 XSuitAntiDetection::gen(XSuitAntiDetection::rd());

// ===== ENHANCED BEARMOD SKIN PATCH SYSTEM =====
struct snew_Skin {
    int id;
    const char* name;
    bool isActive;
    uintptr_t patchOffset;
};

// BearMod custom skins
static snew_Skin bearSkins[] = {
    {100001, "BearMod Glacier M416", false, 0},
    {100002, "BearMod Dragon AKM", false, 0},
    {100003, "BearMod Phoenix AWM", false, 0},
    {100004, "BearMod Thunder SCAR", false, 0},
    {100005, "BearMod Lightning Vector", false, 0}
};

// ===== KILL FEED SKIN MANAGEMENT =====
struct KillFeedSkinManager {
    static std::map<int, std::string> xSuitKillMessages;

    static void initializeKillMessages() {
        xSuitKillMessages[1405909] = "Blood Raven X-Suit";
        xSuitKillMessages[1405628] = "Golden Pharaoh X-Suit";
        xSuitKillMessages[1406152] = "Avalanche X-Suit";
        xSuitKillMessages[1406475] = "Irresidence X-Suit";
        xSuitKillMessages[1405983] = "Poseidon X-Suit";
        xSuitKillMessages[1406638] = "Arcane Jester X-Suit";
        xSuitKillMessages[1406311] = "Silvanus X-Suit";
        xSuitKillMessages[1406971] = "Marmoris X-Suit";
        xSuitKillMessages[1407103] = "Fiore X-Suit";
        xSuitKillMessages[1407259] = "Ignis X-Suit";
        xSuitKillMessages[1406872] = "Stygian Liege X-Suit";
        xSuitKillMessages[1407275] = "Temperance's Virtue X-Suit";
        xSuitKillMessages[1407276] = "The Lover's Grace X-Suit";
    }

    static std::string getKillMessage(int xSuitId) {
        auto it = xSuitKillMessages.find(xSuitId);
        return (it != xSuitKillMessages.end()) ? it->second : "Enhanced X-Suit";
    }
};

std::map<int, std::string> KillFeedSkinManager::xSuitKillMessages;

// ===== DEADBOX SKIN MANAGEMENT =====
struct DeadboxSkinManager {
    static std::map<int, int> weaponToMaxSkin;

    static void initializeDeadboxSkins() {
        weaponToMaxSkin[101004] = 1101004006; // M416 Glacier
        weaponToMaxSkin[101001] = 1101001006; // AKM Glacier
        weaponToMaxSkin[103003] = 1103003006; // AWM Glacier
        weaponToMaxSkin[101003] = 1101003006; // SCAR Glacier
        weaponToMaxSkin[102003] = 1102003006; // Vector Glacier
    }

    static int getMaxSkinForWeapon(int weaponId) {
        auto it = weaponToMaxSkin.find(weaponId);
        return (it != weaponToMaxSkin.end()) ? it->second : weaponId;
    }
};

std::map<int, int> DeadboxSkinManager::weaponToMaxSkin;

// ===== ENHANCED BAG DISPLAY SYSTEM =====
struct BagDisplaySystem {
    struct BagItemState {
        int itemId;
        int skinId;
        std::string displayName;
        bool isVisible;
        std::chrono::steady_clock::time_point lastUpdate;
        std::vector<int> compatibleSkins;
        std::map<std::string, int> attachments;
        bool isEquipped;
        int quantity;
        std::string itemType;
        std::vector<std::string> tags;
    };

    static std::map<int, BagItemState> bagItems;
    static std::mutex bagMutex;
    static bool isInitialized;
    static std::chrono::steady_clock::time_point lastFullUpdate;
    static std::map<int, std::chrono::steady_clock::time_point> lastItemUpdates;
    static std::vector<std::function<void(int, const BagItemState&)>> updateCallbacks;

    // Method declarations
    static void Initialize();
    static void InitializeWeaponItems();
    static void InitializeEquipmentItems();
    static void InitializeConsumableItems();
    static void InitializeThrowableItems();
    static void InitializeVehicleItems();
    static void UpdateBagItemSkin(int itemId, int skinId);
    static void UpdateBagDisplay();
    static void RegisterUpdateCallback(std::function<void(int, const BagItemState&)> callback);
    static void UnregisterUpdateCallback(size_t index);
    static std::string GetBagItemDisplayName(int itemId);
    static bool IsBagItemVisible(int itemId);
    static std::vector<int> GetCompatibleSkins(int itemId);
    static std::string GetItemType(int itemId);
    static std::vector<std::string> GetItemTags(int itemId);
    static void SetItemQuantity(int itemId, int quantity);
    static int GetItemQuantity(int itemId);
    static void SetItemEquipped(int itemId, bool equipped);
    static bool IsItemEquipped(int itemId);
};

// Static member declarations - commented out to avoid linking issues
// These would be defined in a separate .cpp file
/*
std::map<int, BagDisplaySystem::BagItemState> BagDisplaySystem::bagItems;
std::mutex BagDisplaySystem::bagMutex;
bool BagDisplaySystem::isInitialized = false;
std::chrono::steady_clock::time_point BagDisplaySystem::lastFullUpdate;
std::map<int, std::chrono::steady_clock::time_point> BagDisplaySystem::lastItemUpdates;
std::vector<std::function<void(int, const BagDisplaySystem::BagItemState&)>> BagDisplaySystem::updateCallbacks;
*/

// Function declarations - commented out for clean build
/*
uintptr_t findPattern(const char* libName, const char* pattern);
void mprotectPatchRegion(uintptr_t address);
void applySkinPatch(int skinIndex);
bool applyEnhancedSkinPatch(int weaponId, int skinId);
bool applyEnhancedSkinWithScrambler(int weaponId, int skinId);
void InitializeAllSystems();

// Bag display wrapper functions
void InitializeBagDisplay();
void UpdateBagDisplayWithSkins();
std::string GetBagItemDisplayName(int itemId);
bool IsBagItemVisible(int itemId);
std::vector<int> GetBagItemCompatibleSkins(int itemId);
std::string GetItemType(int itemId);
std::vector<std::string> GetItemTags(int itemId);
void SetItemQuantity(int itemId, int quantity);
int GetItemQuantity(int itemId);
void SetItemEquipped(int itemId, bool equipped);
bool IsItemEquipped(int itemId);
size_t RegisterBagUpdateCallback(std::function<void(int, const BagDisplaySystem::BagItemState&)> callback);
void UnregisterBagUpdateCallback(size_t index);
*/

#endif // ESP_SKIN_H
