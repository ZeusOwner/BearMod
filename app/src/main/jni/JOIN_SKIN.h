#pragma once

#include <chrono>
#include <map>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <random>
#include <algorithm>
#include <cstdint>

// Comprehensive skin system header for BearMod
// Compatible with existing NRG.h skin system

// ===== ADVANCED WEAPON DATA SYSTEM =====
enum class SkinType {
    AR_AKM,
    AR_M416,
    AR_SCAR,
    AR_GROZA,
    AR_QBZ,
    AR_ACE32,
    AR_M16A4,
    AR_M762,
    AR_AUG,
    AR_FAMAS,
    SMG_UZI,
    SMG_UMP,
    SMG_VECTOR,
    SMG_THOMPSON,
    SMG_P90,
    SMG_BIZON,
    SR_AWM,
    SR_M24,
    SR_MK14,
    SR_K98,
    SR_MINI14,
    SR_AMR,
    LMG_MG3,
    LMG_M249,
    LMG_DP28,
    SG_S1897,
    SG_S12K,
    SG_DBS
};

enum class AttachType {
    MAGAZINE,
    DEF_STOCK,
    DEF_MUZZLE,
    DEF_SIGHT,
    FLASH,
    COMPENSATOR,
    SILENCER,
    RED_DOT,
    HOLOGRAPHIC,
    SCOPE2X,
    SCOPE3X,
    SCOPE4X,
    SCOPE6X,
    SCOPE8X,
    QUICK_MAG,
    EXTENDED_MAG,
    EXTENDED_QUICK_MAG,
    TACTICAL_STOCK,
    VERTICLE_GRIP,
    ANGLED_GRIP,
    LIGHT_GRIP,
    HALF_GRIP,
    LASER_SIGHT,
    THUMB_GRIP,
    CHEEK_PAD,           // For sniper rifles
    BULLET_LOOPS,        // For shotguns
    CHOKE,               // For shotguns
    DUCKBILL,            // For shotguns
    MUZZLE_BRAKE,        // For high recoil weapons
    HEAVY_STOCK,         // For LMGs
    BIPOD,               // For LMGs and sniper rifles
    CUSTOM_SIGHT,        // For special weapons
    EXTENDED_BARREL,     // For SMGs
    FOLDING_STOCK,       // For compact weapons
    CUSTOM_GRIP,         // For special weapons
    RAIL_COVER,          // For rail system
    CUSTOM_MUZZLE,       // For special weapons
    CUSTOM_MAGAZINE,     // For special weapons
    CUSTOM_STOCK,        // For special weapons
    CUSTOM_SIGHT_RAIL,   // For special weapons
    CUSTOM_GRIP_RAIL,    // For special weapons
    CUSTOM_MUZZLE_RAIL,  // For special weapons
    CUSTOM_MAGAZINE_RAIL // For special weapons
};

// Add vehicle and outfit types
enum class VehicleType {
    CAR,
    MOTORCYCLE,
    PARACHUTE,
    SUIT_OUTFIT
};

// Add vehicle and outfit configuration
struct VehicleConfig {
    int baseId;
    int maxSkinId;
    bool isSpecialSkin;
    std::vector<int> metroModeIds;
    std::map<std::string, int> attachments;
};

struct WeaponData {
    int weaponId;
    int magazineId;
    int defSightId;
    int defStockId;
    int defMuzzleId;
    int flashId;
    int compensatorId;
    int silencerId;
    int redDotId;
    int holographicId;
    int scope2xId;
    int scope3xId;
    int scope4xId;
    int scope6xId;
    int scope8xId;
    int quickMagId;
    int extendedMagId;
    int extendedQuickMagId;
    int tacicalStockId;
    int verticleGripId;
    int angledGripId;
    int lightGripId;
    int halfGripId;
    int laserSightId;
    int thumbGripId;
    std::string displayName;

    WeaponData(int weaponId = 0, int magazineId = 999999999, int defSightId = 999999999, int defStockId = 999999999, int defMuzzleId = 999999999, int flashId = 999999999,
               int compensatorId = 999999999, int silencerId = 999999999, int redDotId = 999999999, int holographicId = 999999999, int scope2xId = 999999999, int scope3xId = 999999999,
               int scope4xId = 999999999, int scope6xId = 999999999, int scope8xId = 999999999, int quickMagId = 999999999, int extendedMagId = 999999999, int extendedQuickMagId = 999999999,
               int tacicalStockId = 999999999, int verticleGripId = 999999999, int angledGripId = 999999999, int lightGripId = 999999999, int halfGripId = 999999999, int laserSightId = 999999999,
               int thumbGripId = 999999999, std::string displayName = "")
        : weaponId(weaponId),
          magazineId(magazineId),
          defSightId(defSightId),
          defStockId(defStockId),
          defMuzzleId(defMuzzleId),
          flashId(flashId),
          compensatorId(compensatorId),
          silencerId(silencerId),
          redDotId(redDotId),
          holographicId(holographicId),
          scope2xId(scope2xId),
          scope3xId(scope3xId),
          scope4xId(scope4xId),
          scope6xId(scope6xId),
          scope8xId(scope8xId),
          quickMagId(quickMagId),
          extendedMagId(extendedMagId),
          extendedQuickMagId(extendedQuickMagId),
          tacicalStockId(tacicalStockId),
          verticleGripId(verticleGripId),
          angledGripId(angledGripId),
          lightGripId(lightGripId),
          halfGripId(halfGripId),
          laserSightId(laserSightId),
          thumbGripId(thumbGripId),
          displayName(displayName) {}
};

// ===== GLOBAL WEAPON SYSTEM MAPS =====
static std::map<int, SkinType> skinTypes;
static std::map<int, AttachType> attachmentTypes;

// ===== WEAPON VECTORS FOR EACH TYPE =====
static std::vector<std::pair<int, WeaponData>> akmWeapons;
static std::vector<std::pair<int, WeaponData>> m416Weapons;
static std::vector<std::pair<int, WeaponData>> scarWeapons;
static std::vector<std::pair<int, WeaponData>> grozaWeapons;
static std::vector<std::pair<int, WeaponData>> qbzWeapons;
static std::vector<std::pair<int, WeaponData>> ace32Weapons;
static std::vector<std::pair<int, WeaponData>> mk14Weapons;
static std::vector<std::pair<int, WeaponData>> mg3Weapons;
static std::vector<std::pair<int, WeaponData>> awmWeapons;
static std::vector<std::pair<int, WeaponData>> m24Weapons;
static std::vector<std::pair<int, WeaponData>> uziWeapons;
static std::vector<std::pair<int, WeaponData>> umpWeapons;
static std::vector<std::pair<int, WeaponData>> vectorWeapons;

// ===== WEAPON DATA INITIALIZATION =====
static void initializeWeaponData() {
    // ===== AKM WEAPON CONFIGURATIONS =====
    
    // AKM Metro Mode Weapon IDs
    skinTypes.insert_or_assign(101001, SkinType::AR_AKM);
    skinTypes.insert_or_assign(1010011, SkinType::AR_AKM);
    skinTypes.insert_or_assign(1010012, SkinType::AR_AKM);
    skinTypes.insert_or_assign(1010013, SkinType::AR_AKM);
    skinTypes.insert_or_assign(1010014, SkinType::AR_AKM);
    skinTypes.insert_or_assign(1010015, SkinType::AR_AKM);
    skinTypes.insert_or_assign(1010016, SkinType::AR_AKM);
    skinTypes.insert_or_assign(1010017, SkinType::AR_AKM);
    
    WeaponData data;
    
    // Default AKM
    data.displayName = "Default AKM";
    akmWeapons.push_back(std::make_pair(0, data));
    
    // Glacier AKM (Example with full attachments)
    data = WeaponData();
    data.displayName = "Glacier AKM";
    data.weaponId = 1101001003;
    data.magazineId = 1011010124;  // Example magazine ID
    data.flashId = 1011010127;     // Flash hider
    data.compensatorId = 1011010128; // Compensator
    data.redDotId = 1011010119;    // Red dot sight
    data.angledGripId = 1011010134; // Angled foregrip
    akmWeapons.push_back(std::make_pair(1, data));
    
    // ===== M416 WEAPON CONFIGURATIONS =====
    
    // M416 Metro Mode Weapon IDs  
    skinTypes.insert_or_assign(101004, SkinType::AR_M416);
    skinTypes.insert_or_assign(1010041, SkinType::AR_M416);
    skinTypes.insert_or_assign(1010042, SkinType::AR_M416);
    skinTypes.insert_or_assign(1010043, SkinType::AR_M416);
    skinTypes.insert_or_assign(1010044, SkinType::AR_M416);
    skinTypes.insert_or_assign(1010045, SkinType::AR_M416);
    skinTypes.insert_or_assign(1010046, SkinType::AR_M416);
    skinTypes.insert_or_assign(1010047, SkinType::AR_M416);
    
    // Default M416
    data = WeaponData();
    data.displayName = "Default M416";
    m416Weapons.push_back(std::make_pair(0, data));
    
    // Glacier M416
    data = WeaponData();
    data.displayName = "Glacier M416";
    data.weaponId = 1101004003;
    data.flashId = 1014010127;
    data.quickMagId = 1014010125;
    data.angledGripId = 1014010134;
    m416Weapons.push_back(std::make_pair(1, data));
    
    // ===== MK14 WEAPON CONFIGURATIONS (Chinese Favorite) =====
    
    // MK14 Metro Mode Weapon IDs
    skinTypes.insert_or_assign(103007, SkinType::SR_MK14);
    skinTypes.insert_or_assign(1030071, SkinType::SR_MK14);
    skinTypes.insert_or_assign(1030072, SkinType::SR_MK14);
    skinTypes.insert_or_assign(1030073, SkinType::SR_MK14);
    skinTypes.insert_or_assign(1030074, SkinType::SR_MK14);
    skinTypes.insert_or_assign(1030075, SkinType::SR_MK14);
    skinTypes.insert_or_assign(1030076, SkinType::SR_MK14);
    skinTypes.insert_or_assign(1030077, SkinType::SR_MK14);
    
    // Default MK14
    data = WeaponData();
    data.displayName = "Default MK14";
    mk14Weapons.push_back(std::make_pair(0, data));
    
    // Glacier MK14
    data = WeaponData();
    data.displayName = "Glacier MK14";
    data.weaponId = 1103007003;
    data.extendedMagId = 1037010124;
    data.compensatorId = 1037010128;
    data.scope4xId = 1037010115;
    mk14Weapons.push_back(std::make_pair(1, data));
    
    // ===== MG3 WEAPON CONFIGURATIONS (Chinese Favorite) =====
    
    // MG3 Metro Mode Weapon IDs
    skinTypes.insert_or_assign(105010, SkinType::LMG_MG3);
    skinTypes.insert_or_assign(1050101, SkinType::LMG_MG3);
    skinTypes.insert_or_assign(1050102, SkinType::LMG_MG3);
    skinTypes.insert_or_assign(1050103, SkinType::LMG_MG3);
    skinTypes.insert_or_assign(1050104, SkinType::LMG_MG3);
    skinTypes.insert_or_assign(1050105, SkinType::LMG_MG3);
    skinTypes.insert_or_assign(1050106, SkinType::LMG_MG3);
    skinTypes.insert_or_assign(1050107, SkinType::LMG_MG3);
    
    // Default MG3
    data = WeaponData();
    data.displayName = "Default MG3";
    mg3Weapons.push_back(std::make_pair(0, data));
    
    // Glacier MG3
    data = WeaponData();
    data.displayName = "Glacier MG3";
    data.weaponId = 1105010003;
    data.redDotId = 1051010119;
    data.compensatorId = 1051010128;
    mg3Weapons.push_back(std::make_pair(1, data));
    
    // ===== ACE32 WEAPON CONFIGURATIONS (Your Example) =====
    
    // ACE32 Metro Mode Weapon IDs
    skinTypes.insert_or_assign(101102, SkinType::AR_ACE32);
    skinTypes.insert_or_assign(1011021, SkinType::AR_ACE32);
    skinTypes.insert_or_assign(1011022, SkinType::AR_ACE32);
    skinTypes.insert_or_assign(1011023, SkinType::AR_ACE32);
    skinTypes.insert_or_assign(1011024, SkinType::AR_ACE32);
    skinTypes.insert_or_assign(1011025, SkinType::AR_ACE32);
    skinTypes.insert_or_assign(1011026, SkinType::AR_ACE32);
    skinTypes.insert_or_assign(1011027, SkinType::AR_ACE32);

    attachmentTypes.insert_or_assign(291102, AttachType::MAGAZINE);
    attachmentTypes.insert_or_assign(205102, AttachType::DEF_STOCK);
    attachmentTypes.insert_or_assign(281102, AttachType::DEF_MUZZLE);

    // Default ACE32
    data = WeaponData();
    data.displayName = std::string("Default - ACE32");
    ace32Weapons.push_back(std::make_pair(0, data));

    // Icicle Spike ACE32 (Your Example)
    data = WeaponData();
    data.displayName = std::string("Icicle Spike - ACE32 (Lv. 7)");
    data.weaponId = 1101102017;
    data.magazineId = 1011020161;
    data.defStockId = 1011020162;
    data.defMuzzleId = 1011020163;
    data.scope2xId = 1011020117;
    data.scope3xId = 1011020116;
    data.scope4xId = 1011020115;
    data.scope6xId = 1011020114;
    data.holographicId = 1011020118;
    data.redDotId = 1011020119;
    data.extendedMagId = 1011020124;
    data.quickMagId = 1011020125;
    data.extendedQuickMagId = 1011020126;
    data.flashId = 1011020127;
    data.compensatorId = 1011020128;
    data.silencerId = 1011020129;
    data.angledGripId = 1011020134;
    data.thumbGripId = 1011020135;
    data.verticleGripId = 1011020136;
    data.tacicalStockId = 1011020137;
    data.lightGripId = 1011020138;
    data.halfGripId = 1011020139;
    data.laserSightId = 1011020144;
    
    // Register all attachment types for this skin
    attachmentTypes.insert_or_assign(data.magazineId, AttachType::MAGAZINE);
    attachmentTypes.insert_or_assign(data.defStockId, AttachType::DEF_STOCK);
    attachmentTypes.insert_or_assign(data.defMuzzleId, AttachType::DEF_MUZZLE);
    attachmentTypes.insert_or_assign(data.scope2xId, AttachType::SCOPE2X);
    attachmentTypes.insert_or_assign(data.scope3xId, AttachType::SCOPE3X);
    attachmentTypes.insert_or_assign(data.scope4xId, AttachType::SCOPE4X);
    attachmentTypes.insert_or_assign(data.scope6xId, AttachType::SCOPE6X);
    attachmentTypes.insert_or_assign(data.holographicId, AttachType::HOLOGRAPHIC);
    attachmentTypes.insert_or_assign(data.redDotId, AttachType::RED_DOT);
    attachmentTypes.insert_or_assign(data.extendedMagId, AttachType::EXTENDED_MAG);
    attachmentTypes.insert_or_assign(data.quickMagId, AttachType::QUICK_MAG);
    attachmentTypes.insert_or_assign(data.extendedQuickMagId, AttachType::EXTENDED_QUICK_MAG);
    attachmentTypes.insert_or_assign(data.flashId, AttachType::FLASH);
    attachmentTypes.insert_or_assign(data.compensatorId, AttachType::COMPENSATOR);
    attachmentTypes.insert_or_assign(data.silencerId, AttachType::SILENCER);
    attachmentTypes.insert_or_assign(data.angledGripId, AttachType::ANGLED_GRIP);
    attachmentTypes.insert_or_assign(data.thumbGripId, AttachType::THUMB_GRIP);
    attachmentTypes.insert_or_assign(data.verticleGripId, AttachType::VERTICLE_GRIP);
    attachmentTypes.insert_or_assign(data.tacicalStockId, AttachType::TACTICAL_STOCK);
    attachmentTypes.insert_or_assign(data.lightGripId, AttachType::LIGHT_GRIP);
    attachmentTypes.insert_or_assign(data.halfGripId, AttachType::HALF_GRIP);
    attachmentTypes.insert_or_assign(data.laserSightId, AttachType::LASER_SIGHT);
    ace32Weapons.push_back(std::make_pair(1, data));
}

// ===== WEAPON DATA ACCESS FUNCTIONS =====
static WeaponData* getWeaponData(int weaponBaseId, int skinIndex) {
    auto skinTypeIt = skinTypes.find(weaponBaseId);
    if (skinTypeIt == skinTypes.end()) {
        return nullptr;
    }
    
    switch (skinTypeIt->second) {
        case SkinType::AR_AKM:
            if (skinIndex < akmWeapons.size()) {
                return &akmWeapons[skinIndex].second;
            }
            break;
        case SkinType::AR_M416:
            if (skinIndex < m416Weapons.size()) {
                return &m416Weapons[skinIndex].second;
            }
            break;
        case SkinType::SR_MK14:
            if (skinIndex < mk14Weapons.size()) {
                return &mk14Weapons[skinIndex].second;
            }
            break;
        case SkinType::LMG_MG3:
            if (skinIndex < mg3Weapons.size()) {
                return &mg3Weapons[skinIndex].second;
            }
            break;
        case SkinType::AR_ACE32:
            if (skinIndex < ace32Weapons.size()) {
                return &ace32Weapons[skinIndex].second;
            }
            break;
        // Add more cases as needed
    }
    
    return nullptr;
}

static bool isValidAttachment(int attachmentId, AttachType expectedType) {
    auto it = attachmentTypes.find(attachmentId);
    return (it != attachmentTypes.end() && it->second == expectedType);
}

static int getAttachmentIdForWeapon(int weaponBaseId, int skinIndex, AttachType attachType) {
    WeaponData* weaponData = getWeaponData(weaponBaseId, skinIndex);
    if (!weaponData) {
        return 999999999; // Invalid/no attachment
    }
    
    switch (attachType) {
        case AttachType::MAGAZINE: return weaponData->magazineId;
        case AttachType::FLASH: return weaponData->flashId;
        case AttachType::COMPENSATOR: return weaponData->compensatorId;
        case AttachType::SILENCER: return weaponData->silencerId;
        case AttachType::RED_DOT: return weaponData->redDotId;
        case AttachType::HOLOGRAPHIC: return weaponData->holographicId;
        case AttachType::SCOPE2X: return weaponData->scope2xId;
        case AttachType::SCOPE3X: return weaponData->scope3xId;
        case AttachType::SCOPE4X: return weaponData->scope4xId;
        case AttachType::SCOPE6X: return weaponData->scope6xId;
        case AttachType::SCOPE8X: return weaponData->scope8xId;
        case AttachType::QUICK_MAG: return weaponData->quickMagId;
        case AttachType::EXTENDED_MAG: return weaponData->extendedMagId;
        case AttachType::EXTENDED_QUICK_MAG: return weaponData->extendedQuickMagId;
        case AttachType::ANGLED_GRIP: return weaponData->angledGripId;
        case AttachType::THUMB_GRIP: return weaponData->thumbGripId;
        case AttachType::VERTICLE_GRIP: return weaponData->verticleGripId;
        case AttachType::TACTICAL_STOCK: return weaponData->tacicalStockId;
        case AttachType::LIGHT_GRIP: return weaponData->lightGripId;
        case AttachType::HALF_GRIP: return weaponData->halfGripId;
        case AttachType::LASER_SIGHT: return weaponData->laserSightId;
        default: return 999999999;
    }
}

// ===== LEGACY COMPATIBILITY LAYER =====
// This allows the existing NRG.h code to work while adding the new system

// Complete skin configuration structure covering all weapons used in NRG.h
struct SkinConfig {
    // === Assault Rifles ===
    // M416 variants and attachments
    int M416_1 = 1101004003;        // Default M416 skin
    int M416_2 = 1101004004;        // M416 variant 2 
    int M416_3 = 1101004005;        // M416 variant 3
    int M416_4 = 1101004006;        // M416 variant 4
    int M416_flash = 1201010001;    // M416 flash hider
    int M416_compe = 1201009001;    // M416 compensator
    int M416_silent = 1201011001;   // M416 silencer
    int M416_holo = 1203002001;     // M416 holographic sight
    int M416_x2 = 1203003001;       // M416 2x scope
    int M416_x3 = 1203014001;       // M416 3x scope
    int M416_x4 = 1203004001;       // M416 4x scope
    int M416_x6 = 1203015001;       // M416 6x scope
    int M416_quickMag = 1204012001; // M416 quick mag
    int M416_extendedMag = 1204011001; // M416 extended mag
    int M416_quickNextended = 1204013001; // M416 quick extended mag
    int M416_stock = 1205005001;    // M416 stock
    int M416_angle = 1202001001;    // M416 angled foregrip
    int M416_thumb = 1202002001;    // M416 thumb grip
    
    // AKM variants and attachments
    int AKM = 1101001003;           // Default AKM skin
    int AKM_Mag = 1291001001;       // AKM magazine
    int AKM_reddot = 1203001001;    // AKM red dot sight
    int AKM_flash = 1201010002;     // AKM flash hider
    int AKM_compe = 1201009002;     // AKM compensator
    int AKM_silent = 1201011002;    // AKM silencer
    int AKM_holo = 1203002002;      // AKM holographic sight
    int AKM_x2 = 1203003002;        // AKM 2x scope
    int AKM_x3 = 1203014002;        // AKM 3x scope
    int AKM_x4 = 1203004002;        // AKM 4x scope
    int AKM_x6 = 1203015002;        // AKM 6x scope
    int AKM_quickMag = 1204012002;  // AKM quick mag
    int AKM_extendedMag = 1204011002; // AKM extended mag
    int AKM_quickNextended = 1204013002; // AKM quick extended mag
    
    // SCAR-L variants
    int Scar = 1101003003;          // Default SCAR skin
    int Scar_Mag = 1291003001;      // SCAR magazine
    
    // M16A4 variants
    int M16A4 = 1101002003;         // Default M16A4 skin
    int M16A4_Mag = 1291002001;     // M16A4 magazine
    int M16A4_Stock = 1205007001;   // M16A4 stock
    
    // Other assault rifles
    int Groza = 1101005003;         // GROZA
    int FAMAS = 1101100003;         // FAMAS 
    int AUG = 1101006003;           // AUG
    int QBZ = 1101007003;           // QBZ
    int M762 = 1101008003;          // M762
    int M762_Mag = 1101008004;      // M762 magazine
    int ACE32 = 1101102003;         // ACE32
    
    // === Sniper Rifles ===
    int K98 = 1103001003;           // K98
    int M24 = 1103002003;           // M24
    int AWM = 1103003003;           // AWM
    int AMR = 1103012003;           // AMR
    int MK14 = 1103007003;          // MK14
    int Mini14 = 1103006003;        // Mini14
    
    // === SMGs ===
    int UZI = 1102001003;           // UZI
    int UMP = 1102002003;           // UMP
    int Vector = 1102003003;        // Vector
    int Thompson = 1102004003;      // Thompson
    int P90 = 1102105003;           // P90
    int Bizon = 1102005003;         // Bizon
    
    // === LMGs ===
    int M249 = 1105001003;          // M249
    int DP28 = 1105002003;          // DP28
    int MG3 = 1105010003;           // MG3
    
    // === Shotguns ===
    int S1897 = 1104002003;         // S1897
    int S12K = 1104003003;          // S12K
    int DBS = 1104004003;           // DBS
    
    // === Melee Weapons ===
    int Machete = 1108001003;       // Machete
    int Pan = 1108004003;           // Pan
    
    // === Special Weapons ===
    int Honey = 1101012003;         // Honey Badger
    
    // === Equipment/Armor ===
    int baglv3 = 1501003100;        // Level 3 bag (updated ID)
    int helmetlv3 = 1502003100;     // Level 3 helmet (updated ID)
    
    // === Scope Skins ===
    int scope2x = 1203003001;       // 2x Scope
    int scope3x = 1203014001;       // 3x Scope
    int scope4x = 1203004001;       // 4x Scope
    int scope6x = 1203015001;       // 6x Scope
    int scope8x = 1203005001;       // 8x Scope
    
    // === Vehicle Skins ===
    int car = 1301001001;           // Car skin
    int motorcycle = 1302001001;    // Motorcycle skin
    
    // === Equipment Skins ===
    int backpackLv1 = 1501003001;   // Level 1 backpack
    int backpackLv2 = 1501003050;   // Level 2 backpack
    int backpackLv3 = 1501003100;   // Level 3 backpack
    int helmetLv1 = 1502003001;     // Level 1 helmet
    int helmetLv2 = 1502003050;     // Level 2 helmet
    int helmetLv3 = 1502003100;     // Level 3 helmet
    
    // === Parachute Skin ===
    int parachute = 1401001001;     // Parachute skin
    
    // === Configuration ===
    bool enableSkins = false;
};

// Global skin configuration instance that NRG.h expects as "new_Skin"
static SkinConfig new_Skin;

// Global skin enable flag that ESP_ENGINE.h and SKIN_MAPPING.h expect
extern bool ModSkinn;
bool ModSkinn = false;

// Arrays for equipment matching (used in NRG.h)
static int bag333[] = {101001, 101002, 101003}; // Level 3 bag IDs
static int Helmet3[] = {201001, 201002, 201003}; // Level 3 helmet IDs

// Weapon ID arrays referenced in NRG.h skin logic
static int akmv[] = {101001}; // AKM variants
static int akmmag[] = {291001}; // AKM magazine variants
static int kar[] = {103001}; // K98 variants 
static int m24[] = {103002}; // M24 variants
static int awm[] = {103003}; // AWM variants
static int amr[] = {103012}; // AMR variants
static int mk14[] = {103007}; // MK14 variants
static int ace32[] = {101102}; // ACE32 variants
static int vector[] = {102003}; // Vector variants
static int ump[] = {102002}; // UMP variants
static int uzi[] = {102001}; // UZI variants
static int m16a4[] = {101002}; // M16A4 variants
static int m16stock[] = {205007}; // M16A4 stock variants
static int m16mag[] = {291002}; // M16A4 magazine variants
static int aug[] = {101006}; // AUG variants
static int groza[] = {101005}; // GROZA variants
static int dp28[] = {105002}; // DP28 variants
static int m249[] = {105001}; // M249 variants
static int mg3[] = {105010}; // MG3 variants
static int scar[] = {101003}; // SCAR variants
static int scarmag[] = {291003}; // SCAR magazine variants
static int m762[] = {101008}; // M762 variants
static int m762mag[] = {101008}; // M762 magazine variants

// M416 weapon and attachment arrays
static int m416v[] = {101004}; // M416 variants
static int m416mag2[] = {291004}; // M416 magazine variant 2
static int m416mag3[] = {203008}; // M416 magazine variant 3
static int m416mag4[] = {205005}; // M416 magazine variant 4
static int m416flash[] = {201010}; // M416 flash hider
static int m416compe[] = {201009}; // M416 compensator
static int m416silent[] = {201011}; // M416 silencer
static int m416holo[] = {203002}; // M416 holographic sight
static int m416x2[] = {203003}; // M416 2x scope
static int m416x3[] = {203014}; // M416 3x scope
static int m416x4[] = {203004}; // M416 4x scope
static int m416x6[] = {203015}; // M416 6x scope
static int m416quickmag[] = {204012}; // M416 quick magazine
static int m416extendedmag[] = {204011}; // M416 extended magazine
static int m416quickextended[] = {204013}; // M416 quick extended magazine
static int m416stock[] = {205005}; // M416 stock
static int m416angle[] = {202001}; // M416 angled foregrip
static int m416thumb[] = {202002}; // M416 thumb grip

// Additional missing arrays from the build errors
static int vector2[] = {102003}; // Vector variant 2 
static int m16[] = {101002}; // M16A4 base
static int m16s[] = {205007}; // M16A4 stock variants
static int dp[] = {105002}; // DP28 base
static int m7[] = {101008}; // M762 base 
static int m7mag[] = {101008}; // M762 magazine
static int M4161[] = {101004}; // M416 variant 1
static int M4162[] = {291004}; // M416 variant 2
static int M4163[] = {203008}; // M416 variant 3
static int m4stock[] = {205005}; // M416 stock variants

// Capitalized versions needed by NRG.h (case sensitive references)
static int M416flash[] = {201010}; // M416 flash hider (capitalized)
static int M416compe[] = {201009}; // M416 compensator (capitalized)
static int M416silent[] = {201011}; // M416 silencer (capitalized)
static int M416holo[] = {203002}; // M416 holographic sight (capitalized)
static int M416x2[] = {203003}; // M416 2x scope (capitalized)
static int M416x3[] = {203014}; // M416 3x scope (capitalized)
static int M416x4[] = {203004}; // M416 4x scope (capitalized)
static int M416x6[] = {203015}; // M416 6x scope (capitalized)
static int M416quickmag[] = {204012}; // M416 quick magazine (capitalized)
static int M416extendedmag[] = {204011}; // M416 extended magazine (capitalized)
static int M416quickextended[] = {204013}; // M416 quick extended magazine (capitalized)

// ===== METRO MODE COMPATIBILITY ARRAYS =====
// QBZ with Metro mode variants (1-7) + special skins
static int qbzMetro[] = {101007, 1010071, 1010072, 1010073, 1010074, 1010075, 1010076, 1010077, 1101007025, 1101007036, 1101007046, 1101007062}; //metro

// MK14 with Metro mode variants (1-7) + special skins  
static int mk14Metro[] = {103007, 1030071, 1030072, 1030073, 1030074, 1030075, 1030076, 1030077, 1103007020, 1103007028}; //metro

// MG3 with Metro mode variants (1-7) + special skins
static int mg3Metro[] = {105010, 1050101, 1050102, 1050103, 1050104, 1050105, 1050106, 1050107, 1105010015, 1105010025, 1105010032}; //metro

// AKM with Metro mode variants (1-7) + special skins
static int akmMetro[] = {101001, 1010011, 1010012, 1010013, 1010014, 1010015, 1010016, 1010017, 1101001025, 1101001036, 1101001046}; //metro

// M416 with Metro mode variants (1-7) + special skins  
static int m416Metro[] = {101004, 1010041, 1010042, 1010043, 1010044, 1010045, 1010046, 1010047, 1101004025, 1101004036, 1101004046}; //metro

// SCAR with Metro mode variants (1-7) + special skins
static int scarMetro[] = {101003, 1010031, 1010032, 1010033, 1010034, 1010035, 1010036, 1010037, 1101003025, 1101003036}; //metro

// AWM with Metro mode variants (1-7) + special skins
static int awmMetro[] = {103003, 1030031, 1030032, 1030033, 1030034, 1030035, 1030036, 1030037, 1103003025, 1103003036}; //metro

// Exact case-sensitive variants for NRG.h
static int M416quickMag[] = {204012}; // M416 quickMag (exact case)
static int M416extendedMag[] = {204011}; // M416 extendedMag (exact case)
static int M416quickNextended[] = {204013}; // M416 quickNextended (exact case)
static int M416stock[] = {205005}; // M416 stock (capitalized)
static int M416angle[] = {202001}; // M416 angled foregrip (capitalized)
static int M416thumb[] = {202002}; // M416 thumb grip (capitalized)

// Variable for lastWeaponChangeTime referenced in NRG.h
static auto lastWeaponChangeTime = std::chrono::steady_clock::now();

// ====== SKIN NAME MAPPINGS ======
#include <map>
#include <string>

// M416 Skin Names
static std::map<int, std::string> m416SkinNames = {
    {1101004003, "Default M416"},
    {1101004004, "PUBG M416"},
    {1101004005, "Desert Digital M416"},
    {1101004006, "Glacier M416"},
    {1101004007, "Golden M416"},
    {1101004008, "Bloodshed M416"},
    {1101004009, "Fool M416"},
    {1101004010, "Oriental M416"},
    {1101004011, "Wanderer M416"},
    {1101004012, "Snow M416"},
    {1101004013, "Pharaoh M416"},
    {1101004014, "Silver M416"},
    {1101004015, "Volcano M416"},
    {1101004016, "Ocean M416"},
    {1101004017, "Joker M416"},
    {1101004018, "Galaxy M416"},
    {1101004019, "Crimson M416"},
    {1101004020, "Azure M416"},
    {1101004021, "Rainbow M416"},
    {1101004022, "Diamond M416"},
    {1101004023, "Neon M416"},
    {1101004024, "Carbon M416"},
    {1101004025, "Chrome M416"},
    {1101004026, "Flame M416"},
    {1101004027, "Lightning M416"},
    {1101004028, "Toxic M416"},
    {1101004029, "Beast M416"},
    {1101004030, "Royal M416"}
};

// AKM Skin Names
static std::map<int, std::string> akmSkinNames = {
    {1101001003, "Default AKM"},
    {1101001004, "PUBG AKM"},
    {1101001005, "Desert Digital AKM"},
    {1101001006, "Glacier AKM"},
    {1101001007, "Golden AKM"},
    {1101001008, "Bloodshed AKM"},
    {1101001009, "Fool AKM"},
    {1101001010, "Oriental AKM"},
    {1101001011, "Wanderer AKM"},
    {1101001012, "Snow AKM"},
    {1101001013, "Pharaoh AKM"},
    {1101001014, "Silver AKM"},
    {1101001015, "Volcano AKM"},
    {1101001016, "Ocean AKM"},
    {1101001017, "Joker AKM"},
    {1101001018, "Galaxy AKM"},
    {1101001019, "Crimson AKM"},
    {1101001020, "Azure AKM"}
};

// SCAR-L Skin Names
static std::map<int, std::string> scarSkinNames = {
    {1101003003, "Default SCAR-L"},
    {1101003004, "PUBG SCAR-L"},
    {1101003005, "Desert Digital SCAR-L"},
    {1101003006, "Glacier SCAR-L"},
    {1101003007, "Golden SCAR-L"},
    {1101003008, "Bloodshed SCAR-L"},
    {1101003009, "Fool SCAR-L"},
    {1101003010, "Oriental SCAR-L"},
    {1101003011, "Wanderer SCAR-L"},
    {1101003012, "Snow SCAR-L"}
};

// AWM Skin Names
static std::map<int, std::string> awmSkinNames = {
    {1103003003, "Default AWM"},
    {1103003004, "PUBG AWM"},
    {1103003005, "Desert Digital AWM"},
    {1103003006, "Glacier AWM"},
    {1103003007, "Golden AWM"},
    {1103003008, "Bloodshed AWM"},
    {1103003009, "Fool AWM"},
    {1103003010, "Oriental AWM"},
    {1103003011, "Wanderer AWM"},
    {1103003012, "Snow AWM"},
    {1103003013, "Pharaoh AWM"},
    {1103003014, "Silver AWM"},
    {1103003015, "Volcano AWM"}
};

// K98 Skin Names
static std::map<int, std::string> k98SkinNames = {
    {1103001003, "Default K98"},
    {1103001004, "PUBG K98"},
    {1103001005, "Desert Digital K98"},
    {1103001006, "Glacier K98"},
    {1103001007, "Golden K98"},
    {1103001008, "Bloodshed K98"},
    {1103001009, "Fool K98"},
    {1103001010, "Oriental K98"},
    {1103001011, "Wanderer K98"},
    {1103001012, "Snow K98"}
};

// UMP Skin Names
static std::map<int, std::string> umpSkinNames = {
    {1102002003, "Default UMP"},
    {1102002004, "PUBG UMP"},
    {1102002005, "Desert Digital UMP"},
    {1102002006, "Glacier UMP"},
    {1102002007, "Golden UMP"},
    {1102002008, "Bloodshed UMP"},
    {1102002009, "Fool UMP"},
    {1102002010, "Oriental UMP"}
};

// UZI Skin Names
static std::map<int, std::string> uziSkinNames = {
    {1102001003, "Default UZI"},
    {1102001004, "PUBG UZI"},
    {1102001005, "Desert Digital UZI"},
    {1102001006, "Glacier UZI"},
    {1102001007, "Golden UZI"},
    {1102001008, "Bloodshed UZI"},
    {1102001009, "Fool UZI"},
    {1102001010, "Oriental UZI"}
};

// Vector Skin Names
static std::map<int, std::string> vectorSkinNames = {
    {1102003003, "Default Vector"},
    {1102003004, "PUBG Vector"},
    {1102003005, "Desert Digital Vector"},
    {1102003006, "Glacier Vector"},
    {1102003007, "Golden Vector"},
    {1102003008, "Bloodshed Vector"},
    {1102003009, "Fool Vector"},
    {1102003010, "Oriental Vector"}
};

// GROZA Skin Names
static std::map<int, std::string> grozaSkinNames = {
    {1101005003, "Default GROZA"},
    {1101005004, "PUBG GROZA"},
    {1101005005, "Desert Digital GROZA"},
    {1101005006, "Glacier GROZA"},
    {1101005007, "Golden GROZA"},
    {1101005008, "Bloodshed GROZA"},
    {1101005009, "Fool GROZA"},
    {1101005010, "Oriental GROZA"}
};

// M24 Skin Names
static std::map<int, std::string> m24SkinNames = {
    {1103002003, "Default M24"},
    {1103002004, "PUBG M24"},
    {1103002005, "Desert Digital M24"},
    {1103002006, "Glacier M24"},
    {1103002007, "Golden M24"},
    {1103002008, "Bloodshed M24"},
    {1103002009, "Fool M24"},
    {1103002010, "Oriental M24"}
};

// MK14 Skin Names (Chinese favorite)
static std::map<int, std::string> mk14SkinNames = {
    {1103007003, "Default MK14"},
    {1103007004, "PUBG MK14"},
    {1103007005, "Desert Digital MK14"},
    {1103007006, "Glacier MK14"},
    {1103007007, "Golden MK14"},
    {1103007008, "Bloodshed MK14"},
    {1103007009, "Fool MK14"},
    {1103007010, "Oriental MK14"},
    {1103007011, "Wanderer MK14"},
    {1103007012, "Snow MK14"},
    {1103007013, "Pharaoh MK14"},
    {1103007014, "Silver MK14"},
    {1103007015, "Volcano MK14"},
    {1103007016, "Ocean MK14"},
    {1103007017, "Joker MK14"},
    {1103007018, "Galaxy MK14"},
    {1103007019, "Crimson MK14"},
    {1103007020, "Azure MK14"},
    {1103007021, "Rainbow MK14"},
    {1103007022, "Diamond MK14"}
};

// MG3 Skin Names (Chinese favorite)
static std::map<int, std::string> mg3SkinNames = {
    {1105010003, "Default MG3"},
    {1105010004, "PUBG MG3"},
    {1105010005, "Desert Digital MG3"},
    {1105010006, "Glacier MG3"},
    {1105010007, "Golden MG3"},
    {1105010008, "Bloodshed MG3"},
    {1105010009, "Fool MG3"},
    {1105010010, "Oriental MG3"},
    {1105010011, "Wanderer MG3"},
    {1105010012, "Snow MG3"},
    {1105010013, "Pharaoh MG3"},
    {1105010014, "Silver MG3"},
    {1105010015, "Volcano MG3"},
    {1105010016, "Ocean MG3"},
    {1105010017, "Joker MG3"},
    {1105010018, "Galaxy MG3"},
    {1105010019, "Crimson MG3"},
    {1105010020, "Azure MG3"},
    {1105010021, "Rainbow MG3"},
    {1105010022, "Diamond MG3"}
};

// QBZ Skin Names  
static std::map<int, std::string> qbzSkinNames = {
    {1101007003, "Default QBZ"},
    {1101007004, "PUBG QBZ"},
    {1101007005, "Desert Digital QBZ"},
    {1101007006, "Glacier QBZ"},
    {1101007007, "Golden QBZ"},
    {1101007008, "Bloodshed QBZ"},
    {1101007009, "Fool QBZ"},
    {1101007010, "Oriental QBZ"},
    {1101007011, "Wanderer QBZ"},
    {1101007012, "Snow QBZ"}
};

// ====== SCOPE SKINS ======
// 2x Scope Skins
static std::map<int, std::string> scope2xSkinNames = {
    {1203003001, "Default 2x Scope"},
    {1203003002, "Desert Digital 2x"},
    {1203003003, "Glacier 2x"},
    {1203003004, "Golden 2x"},
    {1203003005, "Bloodshed 2x"},
    {1203003006, "Fool 2x"},
    {1203003007, "Oriental 2x"},
    {1203003008, "Wanderer 2x"},
    {1203003009, "Snow 2x"},
    {1203003010, "Pharaoh 2x"},
    {1203003011, "Silver 2x"},
    {1203003012, "Volcano 2x"},
    {1203003013, "Ocean 2x"},
    {1203003014, "Joker 2x"},
    {1203003015, "Galaxy 2x"}
};

// 3x Scope Skins
static std::map<int, std::string> scope3xSkinNames = {
    {1203014001, "Default 3x Scope"},
    {1203014002, "Desert Digital 3x"},
    {1203014003, "Glacier 3x"},
    {1203014004, "Golden 3x"},
    {1203014005, "Bloodshed 3x"},
    {1203014006, "Fool 3x"},
    {1203014007, "Oriental 3x"},
    {1203014008, "Wanderer 3x"},
    {1203014009, "Snow 3x"},
    {1203014010, "Pharaoh 3x"},
    {1203014011, "Silver 3x"},
    {1203014012, "Volcano 3x"}
};

// 4x Scope Skins
static std::map<int, std::string> scope4xSkinNames = {
    {1203004001, "Default 4x Scope"},
    {1203004002, "Desert Digital 4x"},
    {1203004003, "Glacier 4x"},
    {1203004004, "Golden 4x"},
    {1203004005, "Bloodshed 4x"},
    {1203004006, "Fool 4x"},
    {1203004007, "Oriental 4x"},
    {1203004008, "Wanderer 4x"},
    {1203004009, "Snow 4x"},
    {1203004010, "Pharaoh 4x"},
    {1203004011, "Silver 4x"},
    {1203004012, "Volcano 4x"},
    {1203004013, "Ocean 4x"},
    {1203004014, "Joker 4x"}
};

// 6x Scope Skins
static std::map<int, std::string> scope6xSkinNames = {
    {1203015001, "Default 6x Scope"},
    {1203015002, "Desert Digital 6x"},
    {1203015003, "Glacier 6x"},
    {1203015004, "Golden 6x"},
    {1203015005, "Bloodshed 6x"},
    {1203015006, "Fool 6x"},
    {1203015007, "Oriental 6x"},
    {1203015008, "Wanderer 6x"},
    {1203015009, "Snow 6x"},
    {1203015010, "Pharaoh 6x"}
};

// 8x Scope Skins
static std::map<int, std::string> scope8xSkinNames = {
    {1203005001, "Default 8x Scope"},
    {1203005002, "Desert Digital 8x"},
    {1203005003, "Glacier 8x"},
    {1203005004, "Golden 8x"},
    {1203005005, "Bloodshed 8x"},
    {1203005006, "Fool 8x"},
    {1203005007, "Oriental 8x"},
    {1203005008, "Wanderer 8x"},
    {1203005009, "Snow 8x"},
    {1203005010, "Pharaoh 8x"},
    {1203005011, "Silver 8x"},
    {1203005012, "Volcano 8x"}
};

// ====== VEHICLE SKINS ======
// Car Skins
static std::map<int, std::string> carSkinNames = {
    {1301001001, "Default Car"},
    {1301001002, "Desert Camo Car"},
    {1301001003, "Glacier Car"},
    {1301001004, "Golden Car"},
    {1301001005, "Bloodshed Car"},
    {1301001006, "Fool Car"},
    {1301001007, "Oriental Car"},
    {1301001008, "Wanderer Car"},
    {1301001009, "Snow Car"},
    {1301001010, "Pharaoh Car"},
    {1301001011, "Silver Car"},
    {1301001012, "Volcano Car"},
    {1301001013, "Ocean Car"},
    {1301001014, "Joker Car"},
    {1301001015, "Galaxy Car"},
    {1301001016, "Crimson Car"},
    {1301001017, "Azure Car"},
    {1301001018, "Rainbow Car"},
    {1301001019, "Diamond Car"},
    {1301001020, "Neon Car"},
    {1301001021, "Carbon Car"},
    {1301001022, "Chrome Car"},
    {1301001023, "Flame Car"},
    {1301001024, "Lightning Car"},
    {1301001025, "Toxic Car"},
    {1301001026, "Beast Car"},
    {1301001027, "Royal Car"},
    {1301001028, "Mythic Car"}
};

// Motorcycle Skins
static std::map<int, std::string> motorcycleSkinNames = {
    {1302001001, "Default Motorcycle"},
    {1302001002, "Desert Camo Motorcycle"},
    {1302001003, "Glacier Motorcycle"},
    {1302001004, "Golden Motorcycle"},
    {1302001005, "Bloodshed Motorcycle"},
    {1302001006, "Fool Motorcycle"},
    {1302001007, "Oriental Motorcycle"},
    {1302001008, "Wanderer Motorcycle"},
    {1302001009, "Snow Motorcycle"},
    {1302001010, "Pharaoh Motorcycle"},
    {1302001011, "Silver Motorcycle"},
    {1302001012, "Volcano Motorcycle"},
    {1302001013, "Ocean Motorcycle"},
    {1302001014, "Joker Motorcycle"},
    {1302001015, "Galaxy Motorcycle"},
    {1302001016, "Crimson Motorcycle"},
    {1302001017, "Azure Motorcycle"},
    {1302001018, "Rainbow Motorcycle"},
    {1302001019, "Diamond Motorcycle"},
    {1302001020, "Neon Motorcycle"},
    {1302001021, "Carbon Motorcycle"},
    {1302001022, "Chrome Motorcycle"},
    {1302001023, "Flame Motorcycle"},
    {1302001024, "Lightning Motorcycle"}
};

// ====== EQUIPMENT SKINS ======
// Backpack/Sleeping Bag Skins
static std::map<int, std::string> backpackSkinNames = {
    {1501003001, "Default Backpack Lv1"},
    {1501003002, "Desert Camo Backpack Lv1"},
    {1501003003, "Glacier Backpack Lv1"},
    {1501003004, "Golden Backpack Lv1"},
    {1501003005, "Bloodshed Backpack Lv1"},
    {1501003050, "Default Backpack Lv2"},
    {1501003051, "Desert Camo Backpack Lv2"},
    {1501003052, "Glacier Backpack Lv2"},
    {1501003053, "Golden Backpack Lv2"},
    {1501003054, "Bloodshed Backpack Lv2"},
    {1501003055, "Fool Backpack Lv2"},
    {1501003100, "Default Backpack Lv3"},
    {1501003101, "Desert Camo Backpack Lv3"},
    {1501003102, "Glacier Backpack Lv3"},
    {1501003103, "Golden Backpack Lv3"},
    {1501003104, "Bloodshed Backpack Lv3"},
    {1501003105, "Fool Backpack Lv3"},
    {1501003106, "Oriental Backpack Lv3"},
    {1501003107, "Wanderer Backpack Lv3"},
    {1501003108, "Snow Backpack Lv3"},
    {1501003109, "Pharaoh Backpack Lv3"},
    {1501003110, "Silver Backpack Lv3"},
    {1501003111, "Volcano Backpack Lv3"},
    {1501003112, "Ocean Backpack Lv3"},
    {1501003113, "Joker Backpack Lv3"},
    {1501003114, "Galaxy Backpack Lv3"}
};

// Helmet Skins
static std::map<int, std::string> helmetSkinNames = {
    {1502003001, "Default Helmet Lv1"},
    {1502003002, "Desert Camo Helmet Lv1"},
    {1502003003, "Glacier Helmet Lv1"},
    {1502003004, "Golden Helmet Lv1"},
    {1502003050, "Default Helmet Lv2"},
    {1502003051, "Desert Camo Helmet Lv2"},
    {1502003052, "Glacier Helmet Lv2"},
    {1502003053, "Golden Helmet Lv2"},
    {1502003054, "Bloodshed Helmet Lv2"},
    {1502003100, "Default Helmet Lv3"},
    {1502003101, "Desert Camo Helmet Lv3"},
    {1502003102, "Glacier Helmet Lv3"},
    {1502003103, "Golden Helmet Lv3"},
    {1502003104, "Bloodshed Helmet Lv3"},
    {1502003105, "Fool Helmet Lv3"},
    {1502003106, "Oriental Helmet Lv3"},
    {1502003107, "Wanderer Helmet Lv3"},
    {1502003108, "Snow Helmet Lv3"},
    {1502003109, "Pharaoh Helmet Lv3"},
    {1502003110, "Silver Helmet Lv3"},
    {1502003111, "Volcano Helmet Lv3"},
    {1502003112, "Ocean Helmet Lv3"},
    {1502003113, "Joker Helmet Lv3"},
    {1502003114, "Galaxy Helmet Lv3"},
    {1502003115, "Crimson Helmet Lv3"},
    {1502003116, "Azure Helmet Lv3"},
    {1502003117, "Rainbow Helmet Lv3"},
    {1502003118, "Diamond Helmet Lv3"}
};

// ====== PARACHUTE SKINS ======
static std::map<int, std::string> parachuteSkinNames = {
    {1401001001, "Default Parachute"},
    {1401001002, "Desert Camo Parachute"},
    {1401001003, "Glacier Parachute"},
    {1401001004, "Golden Parachute"},
    {1401001005, "Bloodshed Parachute"},
    {1401001006, "Fool Parachute"},
    {1401001007, "Oriental Parachute"},
    {1401001008, "Wanderer Parachute"},
    {1401001009, "Snow Parachute"},
    {1401001010, "Pharaoh Parachute"},
    {1401001011, "Silver Parachute"},
    {1401001012, "Volcano Parachute"},
    {1401001013, "Ocean Parachute"},
    {1401001014, "Joker Parachute"},
    {1401001015, "Galaxy Parachute"},
    {1401001016, "Crimson Parachute"},
    {1401001017, "Azure Parachute"},
    {1401001018, "Rainbow Parachute"},
    {1401001019, "Diamond Parachute"},
    {1401001020, "Neon Parachute"},
    {1401001021, "Carbon Parachute"},
    {1401001022, "Chrome Parachute"},
    {1401001023, "Flame Parachute"},
    {1401001024, "Lightning Parachute"},
    {1401001025, "Toxic Parachute"},
    {1401001026, "Beast Parachute"},
    {1401001027, "Royal Parachute"},
    {1401001028, "Mythic Parachute"}
};

// Master skin name getter function (supports all categories)
static std::string getSkinName(const std::string& weaponKey, int skinId) {
    // ===== WEAPONS =====
    if (weaponKey == "M416") {
        auto it = m416SkinNames.find(skinId);
        return (it != m416SkinNames.end()) ? it->second : "Unknown M416 Skin";
    }
    else if (weaponKey == "AKM") {
        auto it = akmSkinNames.find(skinId);
        return (it != akmSkinNames.end()) ? it->second : "Unknown AKM Skin";
    }
    else if (weaponKey == "SCAR") {
        auto it = scarSkinNames.find(skinId);
        return (it != scarSkinNames.end()) ? it->second : "Unknown SCAR Skin";
    }
    else if (weaponKey == "AWM") {
        auto it = awmSkinNames.find(skinId);
        return (it != awmSkinNames.end()) ? it->second : "Unknown AWM Skin";
    }
    else if (weaponKey == "K98") {
        auto it = k98SkinNames.find(skinId);
        return (it != k98SkinNames.end()) ? it->second : "Unknown K98 Skin";
    }
    else if (weaponKey == "UMP") {
        auto it = umpSkinNames.find(skinId);
        return (it != umpSkinNames.end()) ? it->second : "Unknown UMP Skin";
    }
    else if (weaponKey == "UZI") {
        auto it = uziSkinNames.find(skinId);
        return (it != uziSkinNames.end()) ? it->second : "Unknown UZI Skin";
    }
    else if (weaponKey == "Vector") {
        auto it = vectorSkinNames.find(skinId);
        return (it != vectorSkinNames.end()) ? it->second : "Unknown Vector Skin";
    }
    else if (weaponKey == "GROZA") {
        auto it = grozaSkinNames.find(skinId);
        return (it != grozaSkinNames.end()) ? it->second : "Unknown GROZA Skin";
    }
    else if (weaponKey == "M24") {
        auto it = m24SkinNames.find(skinId);
        return (it != m24SkinNames.end()) ? it->second : "Unknown M24 Skin";
    }
    else if (weaponKey == "MK14") {
        auto it = mk14SkinNames.find(skinId);
        return (it != mk14SkinNames.end()) ? it->second : "Unknown MK14 Skin";
    }
    else if (weaponKey == "MG3") {
        auto it = mg3SkinNames.find(skinId);
        return (it != mg3SkinNames.end()) ? it->second : "Unknown MG3 Skin";
    }
    else if (weaponKey == "QBZ") {
        auto it = qbzSkinNames.find(skinId);
        return (it != qbzSkinNames.end()) ? it->second : "Unknown QBZ Skin";
    }
    
    // ===== SCOPES =====
    else if (weaponKey == "2X_SCOPE") {
        auto it = scope2xSkinNames.find(skinId);
        return (it != scope2xSkinNames.end()) ? it->second : "Unknown 2x Scope Skin";
    }
    else if (weaponKey == "3X_SCOPE") {
        auto it = scope3xSkinNames.find(skinId);
        return (it != scope3xSkinNames.end()) ? it->second : "Unknown 3x Scope Skin";
    }
    else if (weaponKey == "4X_SCOPE") {
        auto it = scope4xSkinNames.find(skinId);
        return (it != scope4xSkinNames.end()) ? it->second : "Unknown 4x Scope Skin";
    }
    else if (weaponKey == "6X_SCOPE") {
        auto it = scope6xSkinNames.find(skinId);
        return (it != scope6xSkinNames.end()) ? it->second : "Unknown 6x Scope Skin";
    }
    else if (weaponKey == "8X_SCOPE") {
        auto it = scope8xSkinNames.find(skinId);
        return (it != scope8xSkinNames.end()) ? it->second : "Unknown 8x Scope Skin";
    }
    
    // ===== VEHICLES =====
    else if (weaponKey == "CAR") {
        auto it = carSkinNames.find(skinId);
        return (it != carSkinNames.end()) ? it->second : "Unknown Car Skin";
    }
    else if (weaponKey == "MOTORCYCLE") {
        auto it = motorcycleSkinNames.find(skinId);
        return (it != motorcycleSkinNames.end()) ? it->second : "Unknown Motorcycle Skin";
    }
    
    // ===== EQUIPMENT =====
    else if (weaponKey == "BACKPACK") {
        auto it = backpackSkinNames.find(skinId);
        return (it != backpackSkinNames.end()) ? it->second : "Unknown Backpack Skin";
    }
    else if (weaponKey == "HELMET") {
        auto it = helmetSkinNames.find(skinId);
        return (it != helmetSkinNames.end()) ? it->second : "Unknown Helmet Skin";
    }
    
    // ===== PARACHUTE =====
    else if (weaponKey == "PARACHUTE") {
        auto it = parachuteSkinNames.find(skinId);
        return (it != parachuteSkinNames.end()) ? it->second : "Unknown Parachute Skin";
    }
    
    return "Unknown Item";
}

// Get available skin IDs for any item category
static std::vector<int> getAvailableSkinIds(const std::string& weaponKey) {
    std::vector<int> skinIds;
    
    // ===== WEAPONS =====
    if (weaponKey == "M416") {
        for (const auto& pair : m416SkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "AKM") {
        for (const auto& pair : akmSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "SCAR") {
        for (const auto& pair : scarSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "AWM") {
        for (const auto& pair : awmSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "K98") {
        for (const auto& pair : k98SkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "UMP") {
        for (const auto& pair : umpSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "UZI") {
        for (const auto& pair : uziSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "Vector") {
        for (const auto& pair : vectorSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "GROZA") {
        for (const auto& pair : grozaSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "M24") {
        for (const auto& pair : m24SkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "MK14") {
        for (const auto& pair : mk14SkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "MG3") {
        for (const auto& pair : mg3SkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "QBZ") {
        for (const auto& pair : qbzSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    
    // ===== SCOPES =====
    else if (weaponKey == "2X_SCOPE") {
        for (const auto& pair : scope2xSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "3X_SCOPE") {
        for (const auto& pair : scope3xSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "4X_SCOPE") {
        for (const auto& pair : scope4xSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "6X_SCOPE") {
        for (const auto& pair : scope6xSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "8X_SCOPE") {
        for (const auto& pair : scope8xSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    
    // ===== VEHICLES =====
    else if (weaponKey == "CAR") {
        for (const auto& pair : carSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "MOTORCYCLE") {
        for (const auto& pair : motorcycleSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    
    // ===== EQUIPMENT =====
    else if (weaponKey == "BACKPACK") {
        for (const auto& pair : backpackSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    else if (weaponKey == "HELMET") {
        for (const auto& pair : helmetSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    
    // ===== PARACHUTE =====
    else if (weaponKey == "PARACHUTE") {
        for (const auto& pair : parachuteSkinNames) {
            skinIds.push_back(pair.first);
        }
    }
    
    return skinIds;
}

// Simple update function - called from NRG.h RenderESP()
inline void updateSkin() {
    // This function maintains compatibility with NRG.h
    // The actual Config access happens in NRG.h where Config is defined
    // This function is just a placeholder for the call from RenderESP()
}

// Simple skin application function - no string operations
inline void applySkinForWeapon(int weaponId, int skinId) {
    switch(weaponId) {
        case 101004: new_Skin.M416_1 = skinId; break;      // M416
        case 101001: new_Skin.AKM = skinId; break;         // AKM
        case 103001: new_Skin.K98 = skinId; break;         // K98
        case 103003: new_Skin.AWM = skinId; break;         // AWM
        case 101005: new_Skin.Groza = skinId; break;       // GROZA
        case 101003: new_Skin.Scar = skinId; break;        // SCAR
        case 103002: new_Skin.M24 = skinId; break;         // M24
        case 103012: new_Skin.AMR = skinId; break;         // AMR
        case 103007: new_Skin.MK14 = skinId; break;        // MK14
        case 103006: new_Skin.Mini14 = skinId; break;      // Mini14
        case 102001: new_Skin.UZI = skinId; break;         // UZI
        case 102002: new_Skin.UMP = skinId; break;         // UMP
        case 102003: new_Skin.Vector = skinId; break;      // Vector
        case 102004: new_Skin.Thompson = skinId; break;    // Thompson
        case 101006: new_Skin.AUG = skinId; break;         // AUG
        case 105002: new_Skin.DP28 = skinId; break;        // DP28
        case 105001: new_Skin.M249 = skinId; break;        // M249
        case 105010: new_Skin.MG3 = skinId; break;         // MG3
        case 101008: new_Skin.M762 = skinId; break;        // M762
        case 101102: new_Skin.ACE32 = skinId; break;       // ACE32
        default: break; // Unknown weapon ID
    }
}

// Get skin ID for weapon
inline int getSkinForWeapon(int weaponId) {
    if (!new_Skin.enableSkins) return weaponId; // Return original if skins disabled
    
    switch(weaponId) {
        case 101004: return new_Skin.M416_1;       // M416
        case 101001: return new_Skin.AKM;          // AKM
        case 103001: return new_Skin.K98;          // K98
        case 103003: return new_Skin.AWM;          // AWM
        case 101005: return new_Skin.Groza;        // GROZA
        case 101003: return new_Skin.Scar;         // SCAR
        case 103002: return new_Skin.M24;          // M24
        case 103012: return new_Skin.AMR;          // AMR
        case 103007: return new_Skin.MK14;         // MK14
        case 103006: return new_Skin.Mini14;       // Mini14
        case 102001: return new_Skin.UZI;          // UZI
        case 102002: return new_Skin.UMP;          // UMP
        case 102003: return new_Skin.Vector;       // Vector
        case 102004: return new_Skin.Thompson;     // Thompson
        case 101006: return new_Skin.AUG;          // AUG
        case 105002: return new_Skin.DP28;         // DP28
        case 105001: return new_Skin.M249;         // M249
        case 105010: return new_Skin.MG3;          // MG3
        case 101008: return new_Skin.M762;         // M762
        case 101102: return new_Skin.ACE32;        // ACE32
        default: return weaponId; // Return original ID if no skin mapping
    }
}

// ===== ENHANCED SKIN MANAGEMENT SYSTEM =====
struct EnhancedSkinManager {
    struct SkinChangeRecord {
        int weaponId;
        int skinId;
        std::chrono::steady_clock::time_point timestamp;
        bool verified;
        std::vector<int> appliedAttachments;
    };

    struct SkinProtectionConfig {
        bool enableMemoryScrambling = true;
        bool enableSkinVerification = true;
        bool enableDynamicRotation = true;
        int maxRetryAttempts = 3;
        int verificationInterval = 30000; // 30 seconds
        int rotationInterval = 60000;     // 1 minute
        int protectionLevel = 2;          // 0-3, higher means more protection
    };

    std::map<int, SkinChangeRecord> lastSkinChanges;
    std::map<int, int> verificationCounts;
    std::map<int, std::vector<int>> rotationHistory;
    std::mutex skinMutex;
    SkinProtectionConfig config;

    bool applySkinWithProtection(int weaponId, int skinId) {
        std::lock_guard<std::mutex> lock(skinMutex);
        
        // Check cooldown
        auto now = std::chrono::steady_clock::now();
        if (lastSkinChanges.count(weaponId)) {
            auto& lastChange = lastSkinChanges[weaponId];
            if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastChange.timestamp).count() < 100) {
                return false; // Too soon to change skin
            }
        }

        // Apply skin with retry logic
        for (int attempt = 0; attempt < config.maxRetryAttempts; attempt++) {
            if (applySkinInternal(weaponId, skinId)) {
                // Record successful change
                SkinChangeRecord record;
                record.weaponId = weaponId;
                record.skinId = skinId;
                record.timestamp = now;
                record.verified = false;
                lastSkinChanges[weaponId] = record;
                
                // Schedule verification
                if (config.enableSkinVerification) {
                    scheduleVerification(weaponId, skinId);
                }
                
                return true;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        return false;
    }

    bool verifySkinApplication(int weaponId, int expectedSkinId) {
        std::lock_guard<std::mutex> lock(skinMutex);
        
        auto it = lastSkinChanges.find(weaponId);
        if (it == lastSkinChanges.end()) return false;

        auto& record = it->second;
        if (record.skinId != expectedSkinId) return false;

        // Verify current skin matches expected
        int currentSkinId = getCurrentSkinId(weaponId);
        if (currentSkinId != expectedSkinId) {
            // Attempt recovery
            if (applySkinInternal(weaponId, expectedSkinId)) {
                record.verified = true;
                return true;
            }
            return false;
        }

        record.verified = true;
        return true;
    }

private:
    bool applySkinInternal(int weaponId, int skinId) {
        // Get weapon data
        auto weaponData = getWeaponData(weaponId, 0);
        if (!weaponData) return false;

        // Apply base skin
        if (!updateSkinValue(weaponId, skinId)) return false;

        // Apply attachments if available
        if (weaponData->magazineId != 999999999) {
            if (!applyAttachment(weaponId, "MAGAZINE", weaponData->magazineId)) return false;
        }

        // Force visual update
        forceVisualUpdate(weaponId);
        return true;
    }

    void scheduleVerification(int weaponId, int skinId) {
        std::thread([this, weaponId, skinId]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(config.verificationInterval));
            verifySkinApplication(weaponId, skinId);
        }).detach();
    }

    void forceVisualUpdate(int weaponId) {
        // Implementation depends on game engine
        // This is a placeholder for the actual implementation
    }
};

// Global enhanced skin manager instance
static EnhancedSkinManager g_EnhancedSkinManager;

// ===== ENHANCED SKIN PROTECTION SYSTEM =====
struct SkinProtection {
    static constexpr int MAX_RETRY_ATTEMPTS = 3;
    static constexpr int RETRY_DELAY_MS = 100;
    static constexpr int VERIFICATION_INTERVAL = 30000; // 30 seconds
    static constexpr int MEMORY_SCRAMBLE_SIZE = 1024;
    
    static std::vector<uint8_t> scrambleKey;
    static std::map<int, std::chrono::steady_clock::time_point> lastVerificationTimes;
    static std::map<int, int> verificationCounts;
    static std::map<int, int> protectionLevels;
    
    static void initialize() {
        scrambleKey.resize(16);
        std::random_device rd;
        std::generate(scrambleKey.begin(), scrambleKey.end(), std::ref(rd));
    }
    
    static void scrambleMemory() {
        std::vector<uint8_t> buffer(MEMORY_SCRAMBLE_SIZE);
        std::random_device rd;
        std::generate(buffer.begin(), buffer.end(), std::ref(rd));
        
        // XOR scramble with key
        for (size_t i = 0; i < buffer.size(); i++) {
            buffer[i] ^= scrambleKey[i % scrambleKey.size()];
        }
        
        // Clear sensitive data
        std::fill(buffer.begin(), buffer.end(), 0);
    }
    
    static bool verifySkin(int weaponId, int expectedSkinId) {
        auto currentSkinId = getCurrentSkinId(weaponId);
        if (currentSkinId != expectedSkinId) {
            // Attempt recovery
            if (applySkinWithRetry(weaponId, expectedSkinId)) {
                updateVerificationStatus(weaponId);
                return true;
            }
            return false;
        }
        updateVerificationStatus(weaponId);
        return true;
    }
    
    static void updateVerificationStatus(int weaponId) {
        lastVerificationTimes[weaponId] = std::chrono::steady_clock::now();
        verificationCounts[weaponId]++;
    }
    
    static bool needsVerification(int weaponId) {
        auto it = lastVerificationTimes.find(weaponId);
        if (it == lastVerificationTimes.end()) return true;
        
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            now - it->second).count() > VERIFICATION_INTERVAL;
    }
};

// ===== ADVANCED ATTACHMENT HANDLING =====
struct AttachmentManager {
    struct AttachmentConfig {
        int id;
        AttachType type;
        bool isDefault;
        std::vector<int> compatibleWeapons;
    };
    
    static std::map<int, AttachmentConfig> attachmentConfigs;
    static std::map<int, std::vector<int>> weaponAttachments;
    
    static void initialize() {
        // Initialize attachment configurations
        initializeAttachmentConfigs();
        // Map attachments to weapons
        mapAttachmentsToWeapons();
    }
    
    static bool applyAttachmentWithProtection(int weaponId, AttachType type, int attachmentId) {
        // Verify attachment compatibility
        if (!isAttachmentCompatible(weaponId, attachmentId)) {
            return false;
        }
        
        // Apply with memory protection
        SkinProtection::scrambleMemory();
        
        // Apply attachment with retry logic
        for (int attempt = 0; attempt < SkinProtection::MAX_RETRY_ATTEMPTS; attempt++) {
            if (applyAttachment(weaponId, type, attachmentId)) {
                return true;
            }
            std::this_thread::sleep_for(
                std::chrono::milliseconds(SkinProtection::RETRY_DELAY_MS));
        }
        return false;
    }
    
    static bool isAttachmentCompatible(int weaponId, int attachmentId) {
        auto it = attachmentConfigs.find(attachmentId);
        if (it == attachmentConfigs.end()) return false;
        
        const auto& config = it->second;
        return std::find(config.compatibleWeapons.begin(), 
                        config.compatibleWeapons.end(), 
                        weaponId) != config.compatibleWeapons.end();
    }
    
private:
    static void initializeAttachmentConfigs() {
        // Initialize with default configurations
        // This would be populated with actual attachment data
    }
    
    static void mapAttachmentsToWeapons() {
        // Map attachments to their compatible weapons
        // This would be populated with actual weapon-attachment relationships
    }
};

// ===== SKIN ROTATION SYSTEM =====
struct SkinRotationManager {
    struct RotationConfig {
        bool enabled = true;
        int interval = 60000; // 1 minute
        bool randomize = true;
        int maxHistorySize = 10;
    };
    
    static RotationConfig config;
    static std::map<int, std::vector<int>> rotationHistory;
    static std::map<int, std::chrono::steady_clock::time_point> lastRotationTimes;
    
    static bool shouldRotate(int weaponId) {
        if (!config.enabled) return false;
        
        auto it = lastRotationTimes.find(weaponId);
        if (it == lastRotationTimes.end()) return true;
        
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            now - it->second).count() > config.interval;
    }
    
    static int getNextSkinId(int weaponId, const std::vector<int>& availableSkins) {
        if (availableSkins.empty()) return 0;
        
        auto& history = rotationHistory[weaponId];
        if (history.size() >= config.maxHistorySize) {
            history.erase(history.begin());
        }
        
        if (config.randomize) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, availableSkins.size() - 1);
            return availableSkins[dis(gen)];
        } else {
            // Sequential rotation
            int currentIndex = 0;
            if (!history.empty()) {
                auto it = std::find(availableSkins.begin(), 
                                  availableSkins.end(), 
                                  history.back());
                if (it != availableSkins.end()) {
                    currentIndex = std::distance(availableSkins.begin(), it);
                }
            }
            return availableSkins[(currentIndex + 1) % availableSkins.size()];
        }
    }
    
    static void updateRotationHistory(int weaponId, int skinId) {
        rotationHistory[weaponId].push_back(skinId);
        lastRotationTimes[weaponId] = std::chrono::steady_clock::now();
    }
};

// Initialize static members
std::vector<uint8_t> SkinProtection::scrambleKey;
std::map<int, std::chrono::steady_clock::time_point> SkinProtection::lastVerificationTimes;
std::map<int, int> SkinProtection::verificationCounts;
std::map<int, int> SkinProtection::protectionLevels;

std::map<int, AttachmentManager::AttachmentConfig> AttachmentManager::attachmentConfigs;
std::map<int, std::vector<int>> AttachmentManager::weaponAttachments;

SkinRotationManager::RotationConfig SkinRotationManager::config;
std::map<int, std::vector<int>> SkinRotationManager::rotationHistory;
std::map<int, std::chrono::steady_clock::time_point> SkinRotationManager::lastRotationTimes;

// ===== ENHANCED SKIN VERIFICATION SYSTEM =====
struct SkinVerification {
    struct VerificationData {
        int expectedSkinId;
        std::chrono::steady_clock::time_point lastCheck;
        int verificationCount;
        bool isVerified;
        std::vector<int> appliedAttachments;
    };
    
    static std::map<int, VerificationData> verificationData;
    static std::mutex verificationMutex;
    
    static bool verifyAndRecover(int weaponId, int expectedSkinId) {
        std::lock_guard<std::mutex> lock(verificationMutex);
        
        auto& data = verificationData[weaponId];
        data.expectedSkinId = expectedSkinId;
        
        // Get current skin state
        int currentSkinId = getCurrentSkinId(weaponId);
        if (currentSkinId != expectedSkinId) {
            // Attempt recovery with enhanced protection
            if (applyEnhancedProtection(weaponId, expectedSkinId)) {
                data.isVerified = true;
                data.verificationCount++;
                data.lastCheck = std::chrono::steady_clock::now();
                return true;
            }
            data.isVerified = false;
            return false;
        }
        
        data.isVerified = true;
        data.verificationCount++;
        data.lastCheck = std::chrono::steady_clock::now();
        return true;
    }
    
    static bool applyEnhancedProtection(int weaponId, int skinId) {
        // Apply memory protection
        SkinProtection::scrambleMemory();
        
        // Apply skin with retry logic
        for (int attempt = 0; attempt < SkinProtection::MAX_RETRY_ATTEMPTS; attempt++) {
            if (applySkinInternal(weaponId, skinId)) {
                // Verify application
                if (verifySkinApplication(weaponId, skinId)) {
                    return true;
                }
            }
            std::this_thread::sleep_for(
                std::chrono::milliseconds(SkinProtection::RETRY_DELAY_MS));
        }
        return false;
    }
    
    static bool verifySkinApplication(int weaponId, int expectedSkinId) {
        auto currentSkinId = getCurrentSkinId(weaponId);
        if (currentSkinId != expectedSkinId) {
            return false;
        }
        
        // Verify attachments if any
        auto weaponData = getWeaponData(weaponId, 0);
        if (weaponData) {
            if (weaponData->magazineId != 999999999) {
                if (!verifyAttachment(weaponId, "MAGAZINE", weaponData->magazineId)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    static bool verifyAttachment(int weaponId, const std::string& type, int expectedId) {
        // Implementation would check if attachment is properly applied
        return true; // Placeholder
    }
};

// ===== ADVANCED SKIN ROTATION SYSTEM =====
struct AdvancedSkinRotation {
    struct RotationData {
        std::vector<int> availableSkins;
        std::vector<int> rotationHistory;
        std::chrono::steady_clock::time_point lastRotation;
        bool isRandom;
        int currentIndex;
    };
    
    static std::map<int, RotationData> rotationData;
    static std::mutex rotationMutex;
    
    static void initializeRotation(int weaponId, const std::vector<int>& skins, bool random = true) {
        std::lock_guard<std::mutex> lock(rotationMutex);
        
        auto& data = rotationData[weaponId];
        data.availableSkins = skins;
        data.isRandom = random;
        data.currentIndex = 0;
        data.lastRotation = std::chrono::steady_clock::now();
    }
    
    static int getNextSkin(int weaponId) {
        std::lock_guard<std::mutex> lock(rotationMutex);
        
        auto& data = rotationData[weaponId];
        if (data.availableSkins.empty()) {
            return 0;
        }
        
        int nextSkin;
        if (data.isRandom) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, data.availableSkins.size() - 1);
            nextSkin = data.availableSkins[dis(gen)];
        } else {
            nextSkin = data.availableSkins[data.currentIndex];
            data.currentIndex = (data.currentIndex + 1) % data.availableSkins.size();
        }
        
        // Update history
        data.rotationHistory.push_back(nextSkin);
        if (data.rotationHistory.size() > 10) {
            data.rotationHistory.erase(data.rotationHistory.begin());
        }
        
        data.lastRotation = std::chrono::steady_clock::now();
        return nextSkin;
    }
    
    static bool shouldRotate(int weaponId) {
        std::lock_guard<std::mutex> lock(rotationMutex);
        
        auto it = rotationData.find(weaponId);
        if (it == rotationData.end()) {
            return false;
        }
        
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            now - it->second.lastRotation).count() > 60000; // 1 minute
    }
};

// Initialize static members
std::map<int, SkinVerification::VerificationData> SkinVerification::verificationData;
std::mutex SkinVerification::verificationMutex;

std::map<int, AdvancedSkinRotation::RotationData> AdvancedSkinRotation::rotationData;
std::mutex AdvancedSkinRotation::rotationMutex;

// ===== INTEGRATION WITH JAVA SKIN MANAGER =====
extern "C" {
    JNIEXPORT void JNICALL
    Java_com_bearmod_loader_SkinManager_applySkinWithProtection(
        JNIEnv* env, jclass clazz, jstring weaponKey, jint skinId, jboolean isSpecialSkin) {
        
        const char* weapon = env->GetStringUTFChars(weaponKey, nullptr);
        int weaponId = std::stoi(weapon);
        
        // Apply enhanced protection
        if (SkinVerification::applyEnhancedProtection(weaponId, skinId)) {
            // Schedule verification
            std::thread([weaponId, skinId]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(30000));
                SkinVerification::verifyAndRecover(weaponId, skinId);
            }).detach();
        }
        
        env->ReleaseStringUTFChars(weaponKey, weapon);
    }
    
    JNIEXPORT void JNICALL
    Java_com_bearmod_loader_SkinManager_scrambleMemoryNative(
        JNIEnv* env, jclass clazz, jbyteArray buffer, jbyteArray key) {
        
        jbyte* bufferData = env->GetByteArrayElements(buffer, nullptr);
        jbyte* keyData = env->GetByteArrayElements(key, nullptr);
        
        // Perform memory scrambling
        SkinProtection::scrambleMemory();
        
        env->ReleaseByteArrayElements(buffer, bufferData, 0);
        env->ReleaseByteArrayElements(key, keyData, 0);
    }
}

// ===== ENHANCED WEAPON HANDLING SYSTEM =====
struct WeaponHandler {
    struct WeaponState {
        int currentSkinId;
        std::vector<int> appliedAttachments;
        std::chrono::steady_clock::time_point lastUpdate;
        bool isMetroMode;
        int protectionLevel;
        std::vector<int> skinHistory;
    };
    
    static std::map<int, WeaponState> weaponStates;
    static std::mutex weaponMutex;
    
    static bool updateWeaponState(int weaponId, int skinId, bool isMetroMode = false) {
        std::lock_guard<std::mutex> lock(weaponMutex);
        
        auto& state = weaponStates[weaponId];
        state.currentSkinId = skinId;
        state.isMetroMode = isMetroMode;
        state.lastUpdate = std::chrono::steady_clock::now();
        
        // Update skin history
        state.skinHistory.push_back(skinId);
        if (state.skinHistory.size() > 10) {
            state.skinHistory.erase(state.skinHistory.begin());
        }
        
        return true;
    }
    
    static bool isWeaponInMetroMode(int weaponId) {
        std::lock_guard<std::mutex> lock(weaponMutex);
        auto it = weaponStates.find(weaponId);
        return it != weaponStates.end() && it->second.isMetroMode;
    }
    
    static std::vector<int> getWeaponSkinHistory(int weaponId) {
        std::lock_guard<std::mutex> lock(weaponMutex);
        auto it = weaponStates.find(weaponId);
        return it != weaponStates.end() ? it->second.skinHistory : std::vector<int>();
    }
};

// ===== ADVANCED ANTI-DETECTION SYSTEM =====
struct AntiDetection {
    struct ProtectionConfig {
        bool enableMemoryScrambling = true;
        bool enableSkinVerification = true;
        bool enableDynamicRotation = true;
        bool enableAttachmentProtection = true;
        int maxRetryAttempts = 3;
        int verificationInterval = 30000;
        int rotationInterval = 60000;
        int protectionLevel = 2;
    };
    
    static ProtectionConfig config;
    static std::vector<uint8_t> scrambleKey;
    static std::map<int, std::chrono::steady_clock::time_point> lastScrambleTimes;
    static std::mutex protectionMutex;
    
    static void initialize() {
        std::lock_guard<std::mutex> lock(protectionMutex);
        scrambleKey.resize(32);
        std::random_device rd;
        std::generate(scrambleKey.begin(), scrambleKey.end(), std::ref(rd));
    }
    
    static void scrambleMemory() {
        if (!config.enableMemoryScrambling) return;
        
        std::lock_guard<std::mutex> lock(protectionMutex);
        
        // Generate random buffer
        std::vector<uint8_t> buffer(1024);
        std::random_device rd;
        std::generate(buffer.begin(), buffer.end(), std::ref(rd));
        
        // XOR scramble with key
        for (size_t i = 0; i < buffer.size(); i++) {
            buffer[i] ^= scrambleKey[i % scrambleKey.size()];
        }
        
        // Clear sensitive data
        std::fill(buffer.begin(), buffer.end(), 0);
        std::fill(scrambleKey.begin(), scrambleKey.end(), 0);
    }
    
    static bool verifyProtection(int weaponId) {
        std::lock_guard<std::mutex> lock(protectionMutex);
        
        auto now = std::chrono::steady_clock::now();
        auto it = lastScrambleTimes.find(weaponId);
        
        if (it != lastScrambleTimes.end()) {
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
                now - it->second).count();
            if (elapsed < config.verificationInterval) {
                return true;
            }
        }
        
        // Perform new verification
        scrambleMemory();
        lastScrambleTimes[weaponId] = now;
        return true;
    }
};

// ===== ENHANCED ATTACHMENT MANAGEMENT =====
struct AttachmentManager {
    struct AttachmentState {
        int attachmentId;
        AttachType type;
        bool isApplied;
        std::chrono::steady_clock::time_point lastUpdate;
    };
    
    static std::map<int, std::map<AttachType, AttachmentState>> weaponAttachments;
    static std::mutex attachmentMutex;
    
    static bool applyAttachment(int weaponId, AttachType type, int attachmentId) {
        std::lock_guard<std::mutex> lock(attachmentMutex);
        
        // Verify attachment compatibility
        if (!isAttachmentCompatible(weaponId, type, attachmentId)) {
            return false;
        }
        
        // Apply memory protection
        AntiDetection::scrambleMemory();
        
        // Apply attachment with retry logic
        for (int attempt = 0; attempt < AntiDetection::config.maxRetryAttempts; attempt++) {
            if (applyAttachmentInternal(weaponId, type, attachmentId)) {
                // Update state
                auto& attachments = weaponAttachments[weaponId];
                attachments[type] = {attachmentId, type, true, 
                    std::chrono::steady_clock::now()};
                return true;
            }
            std::this_thread::sleep_for(
                std::chrono::milliseconds(100));
        }
        return false;
    }
    
    static bool isAttachmentCompatible(int weaponId, AttachType type, int attachmentId) {
        auto weaponData = getWeaponData(weaponId, 0);
        if (!weaponData) return false;
        
        switch (type) {
            case AttachType::MAGAZINE:
                return attachmentId == weaponData->magazineId;
            case AttachType::DEF_STOCK:
                return attachmentId == weaponData->defStockId;
            case AttachType::DEF_MUZZLE:
                return attachmentId == weaponData->defMuzzleId;
            // Add more cases for other attachment types
            default:
                return false;
        }
    }
    
private:
    static bool applyAttachmentInternal(int weaponId, AttachType type, int attachmentId) {
        // Implementation would call the actual attachment application logic
        return true; // Placeholder
    }
};

// ===== NRG.H INTEGRATION =====
struct NRGIntegration {
    static bool applySkinWithNRG(int weaponId, int skinId) {
        // Apply memory protection
        AntiDetection::scrambleMemory();
        
        // Get weapon data
        auto weaponData = getWeaponData(weaponId, 0);
        if (!weaponData) return false;
        
        // Apply base skin
        if (!updateSkinValue(weaponId, skinId)) return false;
        
        // Apply attachments if available
        if (weaponData->magazineId != 999999999) {
            if (!AttachmentManager::applyAttachment(weaponId, 
                AttachType::MAGAZINE, weaponData->magazineId)) {
                return false;
            }
        }
        
        // Update weapon state
        WeaponHandler::updateWeaponState(weaponId, skinId);
        
        // Verify protection
        return AntiDetection::verifyProtection(weaponId);
    }
    
    static bool verifyNRGSkin(int weaponId, int expectedSkinId) {
        // Get current skin state
        int currentSkinId = getCurrentSkinId(weaponId);
        if (currentSkinId != expectedSkinId) {
            // Attempt recovery
            return applySkinWithNRG(weaponId, expectedSkinId);
        }
        return true;
    }
};

// Initialize static members
std::map<int, WeaponHandler::WeaponState> WeaponHandler::weaponStates;
std::mutex WeaponHandler::weaponMutex;

AntiDetection::ProtectionConfig AntiDetection::config;
std::vector<uint8_t> AntiDetection::scrambleKey;
std::map<int, std::chrono::steady_clock::time_point> AntiDetection::lastScrambleTimes;
std::mutex AntiDetection::protectionMutex;

std::map<int, std::map<AttachType, AttachmentManager::AttachmentState>> 
    AttachmentManager::weaponAttachments;
std::mutex AttachmentManager::attachmentMutex;

// ===== PRECISE WEAPON TYPE HANDLING =====
struct WeaponTypeHandler {
    struct WeaponTypeConfig {
        bool isMetroModeCompatible;
        int baseWeaponId;
        std::vector<int> compatibleAttachments;
        std::vector<int> metroModeIds;
        int maxSkinId;
        bool isSpecialSkin;
        std::map<AttachType, int> defaultAttachments;
    };
    
    static std::map<SkinType, WeaponTypeConfig> weaponTypeConfigs;
    static std::mutex weaponTypeMutex;
    
    static void initializeWeaponTypes() {
        std::lock_guard<std::mutex> lock(weaponTypeMutex);
        
        // M416 Configuration
        WeaponTypeConfig m416Config;
        m416Config.isMetroModeCompatible = true;
        m416Config.baseWeaponId = 101004;
        m416Config.maxSkinId = 1101004003;
        m416Config.isSpecialSkin = true;
        m416Config.metroModeIds = {101004, 1010041, 1010042, 1010043, 1010044, 1010045, 1010046, 1010047};
        m416Config.defaultAttachments = {
            {AttachType::MAGAZINE, 1014010124},
            {AttachType::DEF_STOCK, 1014010137},
            {AttachType::DEF_MUZZLE, 1014010127},
            {AttachType::RED_DOT, 1014010119},
            {AttachType::HOLOGRAPHIC, 1014010118},
            {AttachType::SCOPE2X, 1014010117},
            {AttachType::SCOPE3X, 1014010116},
            {AttachType::SCOPE4X, 1014010115},
            {AttachType::SCOPE6X, 1014010114},
            {AttachType::QUICK_MAG, 1014010125},
            {AttachType::EXTENDED_MAG, 1014010126},
            {AttachType::FLASH, 1014010127},
            {AttachType::COMPENSATOR, 1014010128},
            {AttachType::SILENCER, 1014010129},
            {AttachType::ANGLED_GRIP, 1014010134},
            {AttachType::VERTICLE_GRIP, 1014010136},
            {AttachType::LIGHT_GRIP, 1014010138},
            {AttachType::HALF_GRIP, 1014010139},
            {AttachType::LASER_SIGHT, 1014010144}
        };
        weaponTypeConfigs[SkinType::AR_M416] = m416Config;
        
        // AKM Configuration
        WeaponTypeConfig akmConfig;
        akmConfig.isMetroModeCompatible = true;
        akmConfig.baseWeaponId = 101001;
        akmConfig.maxSkinId = 1101001003;
        akmConfig.isSpecialSkin = true;
        akmConfig.metroModeIds = {101001, 1010011, 1010012, 1010013, 1010014, 1010015, 1010016, 1010017};
        akmConfig.defaultAttachments = {
            {AttachType::MAGAZINE, 1011010124},
            {AttachType::DEF_STOCK, 1011010137},
            {AttachType::DEF_MUZZLE, 1011010127},
            {AttachType::RED_DOT, 1011010119},
            {AttachType::HOLOGRAPHIC, 1011010118},
            {AttachType::SCOPE2X, 1011010117},
            {AttachType::SCOPE3X, 1011010116},
            {AttachType::SCOPE4X, 1011010115},
            {AttachType::SCOPE6X, 1011010114},
            {AttachType::QUICK_MAG, 1011010125},
            {AttachType::EXTENDED_MAG, 1011010126},
            {AttachType::FLASH, 1011010127},
            {AttachType::COMPENSATOR, 1011010128},
            {AttachType::SILENCER, 1011010129},
            {AttachType::ANGLED_GRIP, 1011010134},
            {AttachType::VERTICLE_GRIP, 1011010136},
            {AttachType::LIGHT_GRIP, 1011010138},
            {AttachType::HALF_GRIP, 1011010139},
            {AttachType::LASER_SIGHT, 1011010144}
        };
        weaponTypeConfigs[SkinType::AR_AKM] = akmConfig;
        
        // AWM Configuration
        WeaponTypeConfig awmConfig;
        awmConfig.isMetroModeCompatible = true;
        awmConfig.baseWeaponId = 103003;
        awmConfig.maxSkinId = 1103003003;
        awmConfig.isSpecialSkin = true;
        awmConfig.metroModeIds = {103003, 1030031, 1030032, 1030033, 1030034, 1030035, 1030036, 1030037};
        awmConfig.defaultAttachments = {
            {AttachType::MAGAZINE, 1033010124},
            {AttachType::DEF_STOCK, 1033010137},
            {AttachType::DEF_MUZZLE, 1033010127},
            {AttachType::SCOPE4X, 1033010115},
            {AttachType::SCOPE6X, 1033010114},
            {AttachType::SCOPE8X, 1033010113},
            {AttachType::QUICK_MAG, 1033010125},
            {AttachType::EXTENDED_MAG, 1033010126},
            {AttachType::FLASH, 1033010127},
            {AttachType::COMPENSATOR, 1033010128},
            {AttachType::SILENCER, 1033010129},
            {AttachType::CHEEK_PAD, 1033010140}
        };
        weaponTypeConfigs[SkinType::SR_AWM] = awmConfig;
        
        // MK14 Configuration
        WeaponTypeConfig mk14Config;
        mk14Config.isMetroModeCompatible = true;
        mk14Config.baseWeaponId = 103007;
        mk14Config.maxSkinId = 1103007003;
        mk14Config.isSpecialSkin = true;
        mk14Config.metroModeIds = {103007, 1030071, 1030072, 1030073, 1030074, 1030075, 1030076, 1030077};
        mk14Config.defaultAttachments = {
            {AttachType::MAGAZINE, 1037010124},
            {AttachType::DEF_STOCK, 1037010137},
            {AttachType::DEF_MUZZLE, 1037010127},
            {AttachType::RED_DOT, 1037010119},
            {AttachType::HOLOGRAPHIC, 1037010118},
            {AttachType::SCOPE2X, 1037010117},
            {AttachType::SCOPE3X, 1037010116},
            {AttachType::SCOPE4X, 1037010115},
            {AttachType::SCOPE6X, 1037010114},
            {AttachType::QUICK_MAG, 1037010125},
            {AttachType::EXTENDED_MAG, 1037010126},
            {AttachType::FLASH, 1037010127},
            {AttachType::COMPENSATOR, 1037010128},
            {AttachType::SILENCER, 1037010129},
            {AttachType::ANGLED_GRIP, 1037010134},
            {AttachType::VERTICLE_GRIP, 1037010136},
            {AttachType::LIGHT_GRIP, 1037010138},
            {AttachType::HALF_GRIP, 1037010139},
            {AttachType::LASER_SIGHT, 1037010144}
        };
        weaponTypeConfigs[SkinType::SR_MK14] = mk14Config;
    }
    
    static bool isWeaponTypeCompatible(SkinType type, int weaponId) {
        std::lock_guard<std::mutex> lock(weaponTypeMutex);
        
        auto it = weaponTypeConfigs.find(type);
        if (it == weaponTypeConfigs.end()) return false;
        
        const auto& config = it->second;
        return std::find(config.metroModeIds.begin(), 
                        config.metroModeIds.end(), 
                        weaponId) != config.metroModeIds.end();
    }
    
    static std::vector<int> getCompatibleAttachments(SkinType type) {
        std::lock_guard<std::mutex> lock(weaponTypeMutex);
        
        auto it = weaponTypeConfigs.find(type);
        if (it == weaponTypeConfigs.end()) return std::vector<int>();
        
        std::vector<int> attachments;
        for (const auto& pair : it->second.defaultAttachments) {
            attachments.push_back(pair.second);
        }
        return attachments;
    }
    
    static bool isMetroModeCompatible(SkinType type) {
        std::lock_guard<std::mutex> lock(weaponTypeMutex);
        
        auto it = weaponTypeConfigs.find(type);
        return it != weaponTypeConfigs.end() && it->second.isMetroModeCompatible;
    }
    
    static int getMaxSkinId(SkinType type) {
        std::lock_guard<std::mutex> lock(weaponTypeMutex);
        
        auto it = weaponTypeConfigs.find(type);
        return it != weaponTypeConfigs.end() ? it->second.maxSkinId : 0;
    }
    
    static bool isSpecialSkin(SkinType type) {
        std::lock_guard<std::mutex> lock(weaponTypeMutex);
        
        auto it = weaponTypeConfigs.find(type);
        return it != weaponTypeConfigs.end() && it->second.isSpecialSkin;
    }
};

// Initialize static members
std::map<SkinType, WeaponTypeHandler::WeaponTypeConfig> WeaponTypeHandler::weaponTypeConfigs;
std::mutex WeaponTypeHandler::weaponTypeMutex;

// ===== ENHANCED METRO MODE SECURITY =====
struct MetroModeSecurity {
    struct SecurityConfig {
        bool enableMemoryProtection = true;
        bool enableSkinVerification = true;
        bool enableDynamicRotation = true;
        bool enableAttachmentProtection = true;
        bool enableAntiDetection = true;
        int maxRetryAttempts = 3;
        int verificationInterval = 30000;  // 30 seconds
        int rotationInterval = 60000;      // 1 minute
        int protectionLevel = 3;           // Maximum protection
        int memoryScrambleSize = 2048;     // Increased buffer size
        int cooldownPeriod = 5000;         // 5 seconds between changes
    };
    
    static SecurityConfig config;
    static std::vector<uint8_t> scrambleKey;
    static std::map<int, std::chrono::steady_clock::time_point> lastChangeTimes;
    static std::map<int, int> verificationCounts;
    static std::map<int, std::vector<int>> rotationHistory;
    static std::mutex securityMutex;
    
    static void initialize() {
        std::lock_guard<std::mutex> lock(securityMutex);
        scrambleKey.resize(32);  // Increased key size
        std::random_device rd;
        std::generate(scrambleKey.begin(), scrambleKey.end(), std::ref(rd));
    }
    
    static bool applyMetroModeSkin(int weaponId, int skinId) {
        std::lock_guard<std::mutex> lock(securityMutex);
        
        // Check cooldown
        auto now = std::chrono::steady_clock::now();
        auto it = lastChangeTimes.find(weaponId);
        if (it != lastChangeTimes.end()) {
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
                now - it->second).count();
            if (elapsed < config.cooldownPeriod) {
                return false;
            }
        }
        
        // Apply enhanced protection
        if (!applyEnhancedProtection(weaponId, skinId)) {
            return false;
        }
        
        // Update change time
        lastChangeTimes[weaponId] = now;
        
        // Update verification count
        verificationCounts[weaponId]++;
        
        // Update rotation history
        auto& history = rotationHistory[weaponId];
        history.push_back(skinId);
        if (history.size() > 10) {
            history.erase(history.begin());
        }
        
        return true;
    }
    
    static bool applyEnhancedProtection(int weaponId, int skinId) {
        // Scramble memory before any operation
        scrambleMemory();
        
        // Apply skin with retry mechanism
        int retryCount = 0;
        bool success = false;
        
        while (!success && retryCount < config.maxRetryAttempts) {
            // Apply skin
            if (updateSkinValue(weaponId, skinId)) {
                // Verify application
                if (verifySkinApplication(weaponId, skinId)) {
                    success = true;
                }
            }
            
            if (!success) {
                retryCount++;
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                scrambleMemory();  // Scramble again before retry
            }
        }
        
        return success;
    }
    
    static void scrambleMemory() {
        if (!config.enableMemoryProtection) return;
        
        // Create larger buffer for scrambling
        std::vector<uint8_t> buffer(config.memoryScrambleSize);
        std::random_device rd;
        std::generate(buffer.begin(), buffer.end(), std::ref(rd));
        
        // Apply multiple layers of scrambling
        for (int i = 0; i < 3; i++) {
            for (size_t j = 0; j < buffer.size(); j++) {
                buffer[j] ^= scrambleKey[j % scrambleKey.size()];
            }
        }
        
        // Clear sensitive data
        std::fill(buffer.begin(), buffer.end(), 0);
    }
    
    static bool verifySkinApplication(int weaponId, int expectedSkinId) {
        if (!config.enableSkinVerification) return true;
        
        // Get current skin state
        int currentSkinId = getCurrentSkinId(weaponId);
        if (currentSkinId != expectedSkinId) {
            return false;
        }
        
        // Advanced verification if enabled
        if (config.protectionLevel >= 2) {
            // Check verification count
            if (!verificationCounts.count(weaponId)) {
                return false;
            }
            
            // Check rotation history
            if (!rotationHistory.count(weaponId)) {
                return false;
            }
            
            // Check protection timestamp
            if (!lastChangeTimes.count(weaponId)) {
                return false;
            }
        }
        
        return true;
    }
    
    static bool isMetroModeSafe(int weaponId) {
        std::lock_guard<std::mutex> lock(securityMutex);
        
        // Check if weapon is in cooldown
        auto it = lastChangeTimes.find(weaponId);
        if (it != lastChangeTimes.end()) {
            auto now = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
                now - it->second).count();
            if (elapsed < config.cooldownPeriod) {
                return false;
            }
        }
        
        // Check verification status
        if (config.enableSkinVerification) {
            if (!verificationCounts.count(weaponId)) {
                return false;
            }
        }
        
        return true;
    }
    
    static void resetMetroModeState(int weaponId) {
        std::lock_guard<std::mutex> lock(securityMutex);
        lastChangeTimes.erase(weaponId);
        verificationCounts.erase(weaponId);
        rotationHistory.erase(weaponId);
    }
};

// Initialize static members
MetroModeSecurity::SecurityConfig MetroModeSecurity::config;
std::vector<uint8_t> MetroModeSecurity::scrambleKey;
std::map<int, std::chrono::steady_clock::time_point> MetroModeSecurity::lastChangeTimes;
std::map<int, int> MetroModeSecurity::verificationCounts;
std::map<int, std::vector<int>> MetroModeSecurity::rotationHistory;
std::mutex MetroModeSecurity::securityMutex;

// ===== ENHANCED ANTI-SURVEILLANCE SYSTEM =====
struct AntiSurveillance {
    struct SurveillanceConfig {
        bool enablePatternRandomization = true;
        bool enableMemoryObfuscation = true;
        bool enableBehavioralProtection = true;
        bool enableStateEncryption = true;
        int patternChangeInterval = 15000;  // 15 seconds
        int memoryScrambleInterval = 5000;  // 5 seconds
        int stateEncryptionKeySize = 64;    // 512-bit key
        int maxPatternHistory = 20;
    };
    
    static SurveillanceConfig config;
    static std::vector<uint8_t> encryptionKey;
    static std::map<int, std::vector<std::vector<uint8_t>>> patternHistory;
    static std::map<int, std::chrono::steady_clock::time_point> lastPatternChange;
    static std::mutex surveillanceMutex;
    
    static void initialize() {
        std::lock_guard<std::mutex> lock(surveillanceMutex);
        encryptionKey.resize(config.stateEncryptionKeySize);
        std::random_device rd;
        std::generate(encryptionKey.begin(), encryptionKey.end(), std::ref(rd));
    }
    
    static void randomizePattern(int weaponId) {
        if (!config.enablePatternRandomization) return;
        
        std::lock_guard<std::mutex> lock(surveillanceMutex);
        auto now = std::chrono::steady_clock::now();
        
        // Check if pattern change is needed
        auto it = lastPatternChange.find(weaponId);
        if (it != lastPatternChange.end()) {
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
                now - it->second).count();
            if (elapsed < config.patternChangeInterval) {
                return;
            }
        }
        
        // Generate new pattern
        std::vector<uint8_t> newPattern(32);
        std::random_device rd;
        std::generate(newPattern.begin(), newPattern.end(), std::ref(rd));
        
        // Update pattern history
        auto& history = patternHistory[weaponId];
        history.push_back(newPattern);
        if (history.size() > config.maxPatternHistory) {
            history.erase(history.begin());
        }
        
        // Update last pattern change time
        lastPatternChange[weaponId] = now;
        
        // Apply pattern to memory
        applyPatternToMemory(weaponId, newPattern);
    }
    
    static void applyPatternToMemory(int weaponId, const std::vector<uint8_t>& pattern) {
        if (!config.enableMemoryObfuscation) return;
        
        // Create memory buffer
        std::vector<uint8_t> buffer(1024);
        std::random_device rd;
        std::generate(buffer.begin(), buffer.end(), std::ref(rd));
        
        // Apply pattern with multiple layers
        for (int layer = 0; layer < 3; layer++) {
            for (size_t i = 0; i < buffer.size(); i++) {
                buffer[i] ^= pattern[i % pattern.size()];
                buffer[i] ^= encryptionKey[i % encryptionKey.size()];
            }
        }
        
        // Clear sensitive data
        std::fill(buffer.begin(), buffer.end(), 0);
    }
    
    static bool verifyBehavioralPattern(int weaponId) {
        if (!config.enableBehavioralProtection) return true;
        
        std::lock_guard<std::mutex> lock(surveillanceMutex);
        
        // Check pattern history
        auto it = patternHistory.find(weaponId);
        if (it == patternHistory.end() || it->second.empty()) {
            return false;
        }
        
        // Verify pattern consistency
        const auto& history = it->second;
        for (size_t i = 1; i < history.size(); i++) {
            if (history[i].size() != history[0].size()) {
                return false;
            }
        }
        
        return true;
    }
};

// Initialize static members
AntiSurveillance::SurveillanceConfig AntiSurveillance::config;
std::vector<uint8_t> AntiSurveillance::encryptionKey;
std::map<int, std::vector<std::vector<uint8_t>>> AntiSurveillance::patternHistory;
std::map<int, std::chrono::steady_clock::time_point> AntiSurveillance::lastPatternChange;
std::mutex AntiSurveillance::surveillanceMutex;

// ===== ENHANCED VERIFICATION SYSTEM =====
struct EnhancedVerification {
    struct VerificationConfig {
        bool enableMultiLayerVerification = true;
        bool enableStateValidation = true;
        bool enablePatternVerification = true;
        bool enableBehavioralVerification = true;
        int verificationLayers = 3;
        int stateValidationInterval = 10000;  // 10 seconds
        int patternVerificationInterval = 5000;  // 5 seconds
    };
    
    static VerificationConfig config;
    static std::map<int, std::vector<bool>> verificationResults;
    static std::map<int, std::chrono::steady_clock::time_point> lastVerification;
    static std::mutex verificationMutex;
    
    static bool verifySkinState(int weaponId, int expectedSkinId) {
        if (!config.enableMultiLayerVerification) {
            return verifyBasicState(weaponId, expectedSkinId);
        }
        
        std::lock_guard<std::mutex> lock(verificationMutex);
        auto& results = verificationResults[weaponId];
        results.clear();
        
        // Layer 1: Basic state verification
        results.push_back(verifyBasicState(weaponId, expectedSkinId));
        
        // Layer 2: Pattern verification
        if (config.enablePatternVerification) {
            results.push_back(AntiSurveillance::verifyBehavioralPattern(weaponId));
        }
        
        // Layer 3: State validation
        if (config.enableStateValidation) {
            results.push_back(validateWeaponState(weaponId));
        }
        
        // Update verification timestamp
        lastVerification[weaponId] = std::chrono::steady_clock::now();
        
        // All layers must pass
        return std::all_of(results.begin(), results.end(), [](bool result) { return result; });
    }
    
    static bool verifyBasicState(int weaponId, int expectedSkinId) {
        int currentSkinId = getCurrentSkinId(weaponId);
        return currentSkinId == expectedSkinId;
    }
    
    static bool validateWeaponState(int weaponId) {
        // Check if verification is needed
        auto it = lastVerification.find(weaponId);
        if (it != lastVerification.end()) {
            auto now = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
                now - it->second).count();
            if (elapsed < config.stateValidationInterval) {
                return true;
            }
        }
        
        // Perform comprehensive state validation
        return MetroModeSecurity::isMetroModeSafe(weaponId) &&
               AntiSurveillance::verifyBehavioralPattern(weaponId);
    }
};

// Initialize static members
EnhancedVerification::VerificationConfig EnhancedVerification::config;
std::map<int, std::vector<bool>> EnhancedVerification::verificationResults;
std::map<int, std::chrono::steady_clock::time_point> EnhancedVerification::lastVerification;
std::mutex EnhancedVerification::verificationMutex;

// Update MetroModeSecurity to use enhanced systems
struct MetroModeSecurity {
    // ... existing code ...
    
    static bool applyMetroModeSkin(int weaponId, int skinId) {
        std::lock_guard<std::mutex> lock(securityMutex);
        
        // Apply anti-surveillance measures
        AntiSurveillance::randomizePattern(weaponId);
        
        // Check cooldown
        auto now = std::chrono::steady_clock::now();
        auto it = lastChangeTimes.find(weaponId);
        if (it != lastChangeTimes.end()) {
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
                now - it->second).count();
            if (elapsed < config.cooldownPeriod) {
                return false;
            }
        }
        
        // Apply enhanced protection with verification
        if (!applyEnhancedProtection(weaponId, skinId)) {
            return false;
        }
        
        // Verify application with enhanced system
        if (!EnhancedVerification::verifySkinState(weaponId, skinId)) {
            return false;
        }
        
        // Update state
        lastChangeTimes[weaponId] = now;
        verificationCounts[weaponId]++;
        
        auto& history = rotationHistory[weaponId];
        history.push_back(skinId);
        if (history.size() > 10) {
            history.erase(history.begin());
        }
        
        return true;
    }
    
    static bool applyEnhancedProtection(int weaponId, int skinId) {
        // Apply multiple layers of protection
        for (int layer = 0; layer < 3; layer++) {
            // Scramble memory
            scrambleMemory();
            
            // Apply anti-surveillance
            AntiSurveillance::randomizePattern(weaponId);
            
            // Apply skin with retry
            int retryCount = 0;
            bool success = false;
            
            while (!success && retryCount < config.maxRetryAttempts) {
                if (updateSkinValue(weaponId, skinId)) {
                    if (EnhancedVerification::verifySkinState(weaponId, skinId)) {
                        success = true;
                    }
                }
                
                if (!success) {
                    retryCount++;
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                    scrambleMemory();
                }
            }
            
            if (!success) {
                return false;
            }
        }
        
        return true;
    }
};

// ===== NEW PUBG SKIN CONFIGURATIONS =====
static void initializeNewSkins() {
    // M416 New Skins
    skinTypes.insert_or_assign(1101004010, SkinType::AR_M416);  // Glacier M416 (New)
    skinTypes.insert_or_assign(1101004011, SkinType::AR_M416);  // Dragon M416
    skinTypes.insert_or_assign(1101004012, SkinType::AR_M416);  // Neon M416
    
    // AKM New Skins
    skinTypes.insert_or_assign(1101001010, SkinType::AR_AKM);   // Glacier AKM (New)
    skinTypes.insert_or_assign(1101001011, SkinType::AR_AKM);   // Dragon AKM
    skinTypes.insert_or_assign(1101001012, SkinType::AR_AKM);   // Neon AKM
    
    // AWM New Skins
    skinTypes.insert_or_assign(1103003010, SkinType::SR_AWM);   // Glacier AWM (New)
    skinTypes.insert_or_assign(1103003011, SkinType::SR_AWM);   // Dragon AWM
    skinTypes.insert_or_assign(1103003012, SkinType::SR_AWM);   // Neon AWM
    
    // MK14 New Skins
    skinTypes.insert_or_assign(1103007010, SkinType::SR_MK14);  // Glacier MK14 (New)
    skinTypes.insert_or_assign(1103007011, SkinType::SR_MK14);  // Dragon MK14
    skinTypes.insert_or_assign(1103007012, SkinType::SR_MK14);  // Neon MK14
    
    // UMP New Skins
    skinTypes.insert_or_assign(1102002010, SkinType::SMG_UMP);  // Glacier UMP (New)
    skinTypes.insert_or_assign(1102002011, SkinType::SMG_UMP);  // Dragon UMP
    skinTypes.insert_or_assign(1102002012, SkinType::SMG_UMP);  // Neon UMP
    
    // Vector New Skins
    skinTypes.insert_or_assign(1102003010, SkinType::SMG_VECTOR); // Glacier Vector (New)
    skinTypes.insert_or_assign(1102003011, SkinType::SMG_VECTOR); // Dragon Vector
    skinTypes.insert_or_assign(1102003012, SkinType::SMG_VECTOR); // Neon Vector
    
    // Initialize weapon configurations with new skins
    WeaponTypeHandler::WeaponTypeConfig m416Config;
    m416Config.isMetroModeCompatible = true;
    m416Config.baseWeaponId = 101004;
    m416Config.maxSkinId = 1101004012;  // Updated for new skins
    m416Config.isSpecialSkin = true;
    m416Config.metroModeIds = {101004, 1010041, 1010042, 1010043, 1010044, 1010045, 1010046, 1010047};
    m416Config.defaultAttachments = {
        {AttachType::MAGAZINE, 1014010124},
        {AttachType::DEF_STOCK, 1014010137},
        {AttachType::DEF_MUZZLE, 1014010127},
        {AttachType::RED_DOT, 1014010119},
        {AttachType::HOLOGRAPHIC, 1014010118},
        {AttachType::SCOPE2X, 1014010117},
        {AttachType::SCOPE3X, 1014010116},
        {AttachType::SCOPE4X, 1014010115},
        {AttachType::SCOPE6X, 1014010114},
        {AttachType::QUICK_MAG, 1014010125},
        {AttachType::EXTENDED_MAG, 1014010126},
        {AttachType::FLASH, 1014010127},
        {AttachType::COMPENSATOR, 1014010128},
        {AttachType::SILENCER, 1014010129},
        {AttachType::ANGLED_GRIP, 1014010134},
        {AttachType::VERTICLE_GRIP, 1014010136},
        {AttachType::LIGHT_GRIP, 1014010138},
        {AttachType::HALF_GRIP, 1014010139},
        {AttachType::LASER_SIGHT, 1014010144}
    };
    WeaponTypeHandler::weaponTypeConfigs[SkinType::AR_M416] = m416Config;
    
    // AKM Configuration with new skins
    WeaponTypeHandler::WeaponTypeConfig akmConfig;
    akmConfig.isMetroModeCompatible = true;
    akmConfig.baseWeaponId = 101001;
    akmConfig.maxSkinId = 1101001012;  // Updated for new skins
    akmConfig.isSpecialSkin = true;
    akmConfig.metroModeIds = {101001, 1010011, 1010012, 1010013, 1010014, 1010015, 1010016, 1010017};
    akmConfig.defaultAttachments = {
        {AttachType::MAGAZINE, 1011010124},
        {AttachType::DEF_STOCK, 1011010137},
        {AttachType::DEF_MUZZLE, 1011010127},
        {AttachType::RED_DOT, 1011010119},
        {AttachType::HOLOGRAPHIC, 1011010118},
        {AttachType::SCOPE2X, 1011010117},
        {AttachType::SCOPE3X, 1011010116},
        {AttachType::SCOPE4X, 1011010115},
        {AttachType::SCOPE6X, 1011010114},
        {AttachType::QUICK_MAG, 1011010125},
        {AttachType::EXTENDED_MAG, 1011010126},
        {AttachType::FLASH, 1011010127},
        {AttachType::COMPENSATOR, 1011010128},
        {AttachType::SILENCER, 1011010129},
        {AttachType::ANGLED_GRIP, 1011010134},
        {AttachType::VERTICLE_GRIP, 1011010136},
        {AttachType::LIGHT_GRIP, 1011010138},
        {AttachType::HALF_GRIP, 1011010139},
        {AttachType::LASER_SIGHT, 1011010144}
    };
    WeaponTypeHandler::weaponTypeConfigs[SkinType::AR_AKM] = akmConfig;
    
    // AWM Configuration with new skins
    WeaponTypeHandler::WeaponTypeConfig awmConfig;
    awmConfig.isMetroModeCompatible = true;
    awmConfig.baseWeaponId = 103003;
    awmConfig.maxSkinId = 1103003012;  // Updated for new skins
    awmConfig.isSpecialSkin = true;
    awmConfig.metroModeIds = {103003, 1030031, 1030032, 1030033, 1030034, 1030035, 1030036, 1030037};
    awmConfig.defaultAttachments = {
        {AttachType::MAGAZINE, 1033010124},
        {AttachType::DEF_STOCK, 1033010137},
        {AttachType::DEF_MUZZLE, 1033010127},
        {AttachType::SCOPE4X, 1033010115},
        {AttachType::SCOPE6X, 1033010114},
        {AttachType::SCOPE8X, 1033010113},
        {AttachType::QUICK_MAG, 1033010125},
        {AttachType::EXTENDED_MAG, 1033010126},
        {AttachType::FLASH, 1033010127},
        {AttachType::COMPENSATOR, 1033010128},
        {AttachType::SILENCER, 1033010129},
        {AttachType::CHEEK_PAD, 1033010140}
    };
    WeaponTypeHandler::weaponTypeConfigs[SkinType::SR_AWM] = awmConfig;
    
    // MK14 Configuration with new skins
    WeaponTypeHandler::WeaponTypeConfig mk14Config;
    mk14Config.isMetroModeCompatible = true;
    mk14Config.baseWeaponId = 103007;
    mk14Config.maxSkinId = 1103007012;  // Updated for new skins
    mk14Config.isSpecialSkin = true;
    mk14Config.metroModeIds = {103007, 1030071, 1030072, 1030073, 1030074, 1030075, 1030076, 1030077};
    mk14Config.defaultAttachments = {
        {AttachType::MAGAZINE, 1037010124},
        {AttachType::DEF_STOCK, 1037010137},
        {AttachType::DEF_MUZZLE, 1037010127},
        {AttachType::RED_DOT, 1037010119},
        {AttachType::HOLOGRAPHIC, 1037010118},
        {AttachType::SCOPE2X, 1037010117},
        {AttachType::SCOPE3X, 1037010116},
        {AttachType::SCOPE4X, 1037010115},
        {AttachType::SCOPE6X, 1037010114},
        {AttachType::QUICK_MAG, 1037010125},
        {AttachType::EXTENDED_MAG, 1037010126},
        {AttachType::FLASH, 1037010127},
        {AttachType::COMPENSATOR, 1037010128},
        {AttachType::SILENCER, 1037010129},
        {AttachType::ANGLED_GRIP, 1037010134},
        {AttachType::VERTICLE_GRIP, 1037010136},
        {AttachType::LIGHT_GRIP, 1037010138},
        {AttachType::HALF_GRIP, 1037010139},
        {AttachType::LASER_SIGHT, 1037010144}
    };
    WeaponTypeHandler::weaponTypeConfigs[SkinType::SR_MK14] = mk14Config;
    
    // UMP Configuration with new skins
    WeaponTypeHandler::WeaponTypeConfig umpConfig;
    umpConfig.isMetroModeCompatible = true;
    umpConfig.baseWeaponId = 102002;
    umpConfig.maxSkinId = 1102002012;  // Updated for new skins
    umpConfig.isSpecialSkin = true;
    umpConfig.metroModeIds = {102002, 1020021, 1020022, 1020023, 1020024, 1020025, 1020026, 1020027};
    umpConfig.defaultAttachments = {
        {AttachType::MAGAZINE, 1022010124},
        {AttachType::DEF_STOCK, 1022010137},
        {AttachType::DEF_MUZZLE, 1022010127},
        {AttachType::RED_DOT, 1022010119},
        {AttachType::HOLOGRAPHIC, 1022010118},
        {AttachType::SCOPE2X, 1022010117},
        {AttachType::SCOPE3X, 1022010116},
        {AttachType::SCOPE4X, 1022010115},
        {AttachType::QUICK_MAG, 1022010125},
        {AttachType::EXTENDED_MAG, 1022010126},
        {AttachType::FLASH, 1022010127},
        {AttachType::COMPENSATOR, 1022010128},
        {AttachType::SILENCER, 1022010129},
        {AttachType::ANGLED_GRIP, 1022010134},
        {AttachType::VERTICLE_GRIP, 1022010136},
        {AttachType::LIGHT_GRIP, 1022010138},
        {AttachType::HALF_GRIP, 1022010139},
        {AttachType::LASER_SIGHT, 1022010144}
    };
    WeaponTypeHandler::weaponTypeConfigs[SkinType::SMG_UMP] = umpConfig;
    
    // Vector Configuration with new skins
    WeaponTypeHandler::WeaponTypeConfig vectorConfig;
    vectorConfig.isMetroModeCompatible = true;
    vectorConfig.baseWeaponId = 102003;
    vectorConfig.maxSkinId = 1102003012;  // Updated for new skins
    vectorConfig.isSpecialSkin = true;
    vectorConfig.metroModeIds = {102003, 1020031, 1020032, 1020033, 1020034, 1020035, 1020036, 1020037};
    vectorConfig.defaultAttachments = {
        {AttachType::MAGAZINE, 1023010124},
        {AttachType::DEF_STOCK, 1023010137},
        {AttachType::DEF_MUZZLE, 1023010127},
        {AttachType::RED_DOT, 1023010119},
        {AttachType::HOLOGRAPHIC, 1023010118},
        {AttachType::SCOPE2X, 1023010117},
        {AttachType::SCOPE3X, 1023010116},
        {AttachType::SCOPE4X, 1023010115},
        {AttachType::QUICK_MAG, 1023010125},
        {AttachType::EXTENDED_MAG, 1023010126},
        {AttachType::FLASH, 1023010127},
        {AttachType::COMPENSATOR, 1023010128},
        {AttachType::SILENCER, 1023010129},
        {AttachType::ANGLED_GRIP, 1023010134},
        {AttachType::VERTICLE_GRIP, 1023010136},
        {AttachType::LIGHT_GRIP, 1023010138},
        {AttachType::HALF_GRIP, 1023010139},
        {AttachType::LASER_SIGHT, 1023010144}
    };
    WeaponTypeHandler::weaponTypeConfigs[SkinType::SMG_VECTOR] = vectorConfig;
}
