#pragma once

#define JOIN_SKIN_H

#include <map>
#include <string>
#include <vector>
#include "Helper/struct.h"
#include "Helper/obfuscate.h"
#include <sys/types.h>
#include <set>

// Forward declarations
extern std::map<std::string, long> Config;

//std::chrono::steady_clock::time_point lastWeaponChangeTimei;
//std::chrono::steady_clock::time_point lastWeaponChangeTime;


// ===================================================================================================
// MODERNIZED WEAPON SKIN DATABASE
// ===================================================================================================
// This file is the central database for all weapon skins, including their names, IDs,
// categories, and attachments. It replaces the old new_Skin struct and updateSkin function.
// ===================================================================================================
struct snew_Skin {
  int XSuits = 403003;
  int XSuits1 = 40604002;
  int Balo1 = 501001;
  int Balo2 = 501002;
  int Balo3 = 501003;
  int Balo4 = 501004;
  int Balo5 = 501005;
  int Balo6 = 501006;
  int Helmet1 = 502001;
  int Helmet2 = 502002;
  int Helmet3 = 502003;
  int Helmet4 = 502004;
  int Helmet5 = 502005;

  int Helmet6 = 502114;
  int Helmet7 = 502115;
  int Helmet8 = 502116;
  int Parachute = 703001;

 // Assault Rifles
    int AKM = 101001;
    int AKM_Mag = 291001;
    int M16A4 = 101002;
    int M16A4_Stock = 205007;
    int M16A4_Mag = 291002;
    int Scar = 101003;
    int Scar_Mag = 291003;
    int M416_1 = 101004;
    int M416_2 = 291004;
    int M416_3 = 203008;
    int M416_4 = 205005;
    int M416_flash = 201010;
    int M416_compe = 201009;
    int M416_silent = 201011;
    int M416_reddot = 203001;
    int M416_holo = 203001;
    int M416_x2 = 203003;
    int M416_x3 = 203014;
    int M416_x4 = 203004;
    int M416_x6 = 203015;
    int M416_quickMag = 204012;
    int M416_extendedMag = 204011;
    int M416_quickNextended = 204013;
    int M416_stock = 205002;
    int M416_verical = 203015;
    int M416_angle = 202001;
    int M416_lightgrip = 202004;
    int M416_pink = 202005;
    int M416_lazer = 202007;
    int M416_thumb = 202006;
    int Groza = 101005;
    int QBZ = 101007;
    int AUG = 101006;
    int M762 = 101008;
    int M762_Mag = 291008;
    int ACE32 = 101102;
    int Honey = 101012;

    // SMGs
    int UZI = 102001;
    int UMP = 102002;
    int Vector = 102003;
    int Thompson = 102004;
    int Bizon = 102005;

    // Sniper Rifles
    int K98 = 103001;
    int M24 = 103002;
    int AWM = 103003;
    int AMR = 103012;
    int VSS = 103005;
    int SKS = 103004;
    int Mini14 = 103006;
    int MK14 = 103007;
    int SLR = 103009;

    // Shotguns
    int S1897 = 104002;

    // LMGs
    int DP28 = 105002;
    int M249 = 105001;
    int MG3 = 105010;
    int M249s = 205009;

    // Other Weapons
    int Skorpion = 106008;
    int Pan = 108004;

    // Vehicles
    int Moto = 1901001;
    int CoupeRP = 1961001;
    int Dacia = 1903001;
    int UAZ = 1908001;
    int Bigfoot = 1953001;
    int Mirado = 1914004;
    int OMirado = 1915001;
    int Buggy = 1907001;
    int MiniBus = 1904001;
    int Boat = 1911001;

    // Equipment Levels
    int baglv1 = 501001;
    int baglv2 = 501002;
    int baglv3 = 501003;
    int helmetlv1 = 502001;
    int helmetlv2 = 502002;
    int helmetlv3 = 502003;
};

// Global skin instance
inline snew_Skin new_Skin;

// ===========================================================================================================
// SKIN UPDATE FUNCTION
// ===========================================================================================================

void updateSkin() {
    // AKM Skins
    if (Config["SKIN_AKM"] == 0) {
        new_Skin.AKM = 101001; // Default AKM
        new_Skin.AKM_Mag = 205005;
    }
    if (Config["SKIN_AKM"] == 1) {
        new_Skin.AKM = 1101001089; // Glacier - AKM (Lv. 7)
        new_Skin.AKM_Mag = 1010010891;
    }
    if (Config["SKIN_AKM"] == 2) {
        new_Skin.AKM = 1101001103; // Desert Fossil - AKM (Lv. 7)
        new_Skin.AKM_Mag = 1010011031;
    }
    if (Config["SKIN_AKM"] == 3) {
        new_Skin.AKM = 1101001116; // Jack-o'-lantern - AKM (Lv. 7)
        new_Skin.AKM_Mag = 1010011161;
    }
    if (Config["SKIN_AKM"] == 4) {
        new_Skin.AKM = 1101001128; // Ghillie Dragon - AKM (Lv. 7)
        new_Skin.AKM_Mag = 1010011281;
    }
    if (Config["SKIN_AKM"] == 5) {
        new_Skin.AKM = 1101001143; // Gold Pirate - AKM (Lv. 7)
        new_Skin.AKM_Mag = 1010011431;
    }
    if (Config["SKIN_AKM"] == 6) {
        new_Skin.AKM = 1101001154; // Codebreaker - AKM (Lv. 7)
        new_Skin.AKM_Mag = 1010011541;
    }
    if (Config["SKIN_AKM"] == 7) {
        new_Skin.AKM = 1101001174; // Wandering Tyrant - AKM (Lv. 8)
        new_Skin.AKM_Mag = 1010011741;
    }
    if (Config["SKIN_AKM"] == 8) {
        new_Skin.AKM = 1101001213; // Starsea Admiral - AKM (Lv. 8)
        new_Skin.AKM_Mag = 1010012131;
    }
    if (Config["SKIN_AKM"] == 9) {
        new_Skin.AKM = 1101001231; // Bunny Munchkin - AKM (Lv. 7)
        new_Skin.AKM_Mag = 1010012311;
    }
    if (Config["SKIN_AKM"] == 10) {
        new_Skin.AKM = 1101001242; // Decisive Day - AKM (Lv. 8)
        new_Skin.AKM_Mag = 1010012421;
    }

    // Kar98K Skins
    if (Config["SKIN_KAR98K"] == 0)
        new_Skin.K98 = 103001; // Default
    if (Config["SKIN_KAR98K"] == 1)
        new_Skin.K98 = 1103001060; // Terror Fang - Kar98K (Lv. 7)
    if (Config["SKIN_KAR98K"] == 2)
        new_Skin.K98 = 1103001079; // Kukulkan Fury - Kar98K (Lv. 7)
    if (Config["SKIN_KAR98K"] == 3)
        new_Skin.K98 = 1103001101; // Moonlit Grace - Kar98K (Lv. 7)
    if (Config["SKIN_KAR98K"] == 4)
        new_Skin.K98 = 1103001146; // Titanium Shark - Kar98K (Lv. 7)
    if (Config["SKIN_KAR98K"] == 5)
        new_Skin.K98 = 1103001160; // Nebula Hunter - Kar98K (Lv. 5)
    if (Config["SKIN_KAR98K"] == 6)
        new_Skin.K98 = 1103001179; // Violet Volt - Kar98K (Lv. 7)

    // AWM Skins
    if (Config["SKIN_AWM"] == 0)
        new_Skin.AWM = 103003; // Default
    if (Config["SKIN_AWM"] == 1)
        new_Skin.AWM = 1103003022; // Mauve Avenger - AWM (Lv. 7)
    if (Config["SKIN_AWM"] == 2)
        new_Skin.AWM = 1103003030; // Field Commander - AWM (Lv. 7)
    if (Config["SKIN_AWM"] == 3)
        new_Skin.AWM = 1103003042; // Godzilla - AWM (Lv. 7)
    if (Config["SKIN_AWM"] == 4)
        new_Skin.AWM = 1103003051; // Rainbow Drake - AWM (Lv. 7)
    if (Config["SKIN_AWM"] == 5)
        new_Skin.AWM = 1103003062; // Flamewave - AWM (Lv. 7)
    if (Config["SKIN_AWM"] == 6)
        new_Skin.AWM = 1103003087; // Serpengleam - AWM (Lv. 7)
    if (Config["SKIN_AWM"] == 7)
        new_Skin.AWM = 1103003055; // Bramble Overlord - AWM

    // M24 Skins
    if (Config["SKIN_M24"] == 0)
        new_Skin.M24 = 103002; // Default
    if (Config["SKIN_M24"] == 1)
        new_Skin.M24 = 1103002018;
    if (Config["SKIN_M24"] == 2)
        new_Skin.M24 = 1103002030;
    if (Config["SKIN_M24"] == 3)
        new_Skin.M24 = 1103002049;
    if (Config["SKIN_M24"] == 4)
        new_Skin.M24 = 1103002059;
    if (Config["SKIN_M24"] == 5)
        new_Skin.M24 = 1103002087;

    // ACE32 Skins
    if (Config["SKIN_ACE32"] == 0)
        new_Skin.ACE32 = 101102; // Default
    if (Config["SKIN_ACE32"] == 1)
        new_Skin.ACE32 = 1101102007;
    if (Config["SKIN_ACE32"] == 2)
        new_Skin.ACE32 = 1101102017;

    // Vector Skins
    if (Config["SKIN_VECTOR"] == 0)
        new_Skin.Vector = 102003; // Default
    if (Config["SKIN_VECTOR"] == 1)
        new_Skin.Vector = 1102003020;
    if (Config["SKIN_VECTOR"] == 2)
        new_Skin.Vector = 1102003031;
    if (Config["SKIN_VECTOR"] == 3)
        new_Skin.Vector = 1102003065;
    if (Config["SKIN_VECTOR"] == 4)
        new_Skin.Vector = 1102003080;

    // UMP45 Skins
    if (Config["SKIN_UMP45"] == 0)
        new_Skin.UMP = 102002; // Default
    if (Config["SKIN_UMP45"] == 1)
        new_Skin.UMP = 1102002043;
    if (Config["SKIN_UMP45"] == 2)
        new_Skin.UMP = 1102002061;
    if (Config["SKIN_UMP45"] == 3)
        new_Skin.UMP = 1102002090;
    if (Config["SKIN_UMP45"] == 4)
        new_Skin.UMP = 1102002117;
    if (Config["SKIN_UMP45"] == 5)
        new_Skin.UMP = 1102002124;
    if (Config["SKIN_UMP45"] == 6)
        new_Skin.UMP = 1102002129;
    if (Config["SKIN_UMP45"] == 7)
        new_Skin.UMP = 1102002136;

    // UZI Skins
    if (Config["SKIN_UZI"] == 0)
        new_Skin.UZI = 102001; // Default
    if (Config["SKIN_UZI"] == 1)
        new_Skin.UZI = 1102001024;
    if (Config["SKIN_UZI"] == 2)
        new_Skin.UZI = 1102001036;
    if (Config["SKIN_UZI"] == 3)
        new_Skin.UZI = 1102001058;
    if (Config["SKIN_UZI"] == 4)
        new_Skin.UZI = 1102001069;
    if (Config["SKIN_UZI"] == 5)
        new_Skin.UZI = 1102001089;
    if (Config["SKIN_UZI"] == 6)
        new_Skin.UZI = 1102001102;

    // Thompson Skins
    if (Config["SKIN_THOMPSON"] == 0)
        new_Skin.Thompson = 102004; // Default
    if (Config["SKIN_THOMPSON"] == 1)
        new_Skin.Thompson = 1102004018; // Candy Cane - Thompson SMG (Lv. 5)
    if (Config["SKIN_THOMPSON"] == 2)
        new_Skin.Thompson = 1102004034; // Steampunk - Thompson SMG (Lv. 5)

    // M16A4 Skins
    if (Config["SKIN_M16A4"] == 0) {
        new_Skin.M16A4 = 101002; // Default
        new_Skin.M16A4_Stock = 205007;
        new_Skin.M16A4_Mag = 291002;
    }
    if (Config["SKIN_M16A4"] == 1) {
        new_Skin.M16A4 = 1101002029;
        new_Skin.M16A4_Stock = 1010020292;
        new_Skin.M16A4_Mag = 1010020291;
    }
    if (Config["SKIN_M16A4"] == 2) {
        new_Skin.M16A4 = 1101002056;
        new_Skin.M16A4_Stock = 1010020562;
        new_Skin.M16A4_Mag = 1010020561;
    }
    if (Config["SKIN_M16A4"] == 3) {
        new_Skin.M16A4 = 1101002068;
        new_Skin.M16A4_Stock = 1010020682;
        new_Skin.M16A4_Mag = 1010020681;
    }
    if (Config["SKIN_M16A4"] == 4) {
        new_Skin.M16A4 = 1101002081;
        new_Skin.M16A4_Stock = 1010020812;
        new_Skin.M16A4_Mag = 1010020811;
    }
    if (Config["SKIN_M16A4"] == 5) {
        new_Skin.M16A4 = 1101002103;
        new_Skin.M16A4_Stock = 1010021032;
        new_Skin.M16A4_Mag = 1010021031;
    }

    // AUG Skins
    if (Config["SKIN_AUG"] == 0)
        new_Skin.AUG = 101006; // Default
    if (Config["SKIN_AUG"] == 1)
        new_Skin.AUG = 1101006033;
    if (Config["SKIN_AUG"] == 2)
        new_Skin.AUG = 1101006044;
    if (Config["SKIN_AUG"] == 3)
        new_Skin.AUG = 1101006062;

    // Groza Skins
    if (Config["SKIN_GROZAR"] == 0)
        new_Skin.Groza = 101005; // Default
    if (Config["SKIN_GROZAR"] == 1)
        new_Skin.Groza = 1101005019;
    if (Config["SKIN_GROZAR"] == 2)
        new_Skin.Groza = 1101005025;
    if (Config["SKIN_GROZAR"] == 3)
        new_Skin.Groza = 1101005038;
    if (Config["SKIN_GROZAR"] == 4)
        new_Skin.Groza = 1101005043;
    if (Config["SKIN_GROZAR"] == 5)
        new_Skin.Groza = 1101005052;
    if (Config["SKIN_GROZAR"] == 6)
        new_Skin.Groza = 1101005082;

    // DP28 Skins
    if (Config["SKIN_DP28"] == 0)
        new_Skin.DP28 = 105002; // Default
    if (Config["SKIN_DP28"] == 1)
        new_Skin.DP28 = 1105002018;
    if (Config["SKIN_DP28"] == 2)
        new_Skin.DP28 = 1105002035;
    if (Config["SKIN_DP28"] == 3)
        new_Skin.DP28 = 1105002058;
    if (Config["SKIN_DP28"] == 4)
        new_Skin.DP28 = 1105002063;

    // M249 Skins
    if (Config["SKIN_M249"] == 0) {
        new_Skin.M249 = 105001; // Default
        new_Skin.M249s = 205009;
    }
    if (Config["SKIN_M249"] == 1) {
        new_Skin.M249 = 1105001020;
        new_Skin.M249s = 1050010351;
    }
    if (Config["SKIN_M249"] == 2) {
        new_Skin.M249 = 1105001034;
        new_Skin.M249s = 1050010412;
    }
    if (Config["SKIN_M249"] == 3) {
        new_Skin.M249 = 1105001048;
        new_Skin.M249s = 1050010482;
    }
    if (Config["SKIN_M249"] == 4) {
        new_Skin.M249 = 1105001054;
        new_Skin.M249s = 1050010542;
    }

    // SCAR-L Skins
    if (Config["SKIN_SCARL"] == 0) {
        new_Skin.Scar = 101003; // Default
        new_Skin.Scar_Mag = 291003;
    }
    if (Config["SKIN_SCARL"] == 1) {
        new_Skin.Scar = 1101003057;
        new_Skin.Scar_Mag = 1010030571;
    }
    if (Config["SKIN_SCARL"] == 2) {
        new_Skin.Scar = 1101003072;
        new_Skin.Scar_Mag = 1010030721;
    }
    if (Config["SKIN_SCARL"] == 3) {
        new_Skin.Scar = 1101003085;
        new_Skin.Scar_Mag = 1010030851;
    }
    if (Config["SKIN_SCARL"] == 4) {
        new_Skin.Scar = 1101003098;
        new_Skin.Scar_Mag = 1010030981;
    }
    if (Config["SKIN_SCARL"] == 5) {
        new_Skin.Scar = 1101003112;
        new_Skin.Scar_Mag = 1010031121;
    }
    if (Config["SKIN_SCARL"] == 6) {
        new_Skin.Scar = 1101003125;
        new_Skin.Scar_Mag = 1010031251;
    }
    if (Config["SKIN_SCARL"] == 7) {
        new_Skin.Scar = 1101003138;
        new_Skin.Scar_Mag = 1010031381;
    }

    // M762 Skins
    if (Config["SKIN_M762"] == 0) {
        new_Skin.M762 = 101008; // Default
        new_Skin.M762_Mag = 291008;
    }
    if (Config["SKIN_M762"] == 1) {
        new_Skin.M762 = 1101008015;
        new_Skin.M762_Mag = 1010080151;
    }
    if (Config["SKIN_M762"] == 2) {
        new_Skin.M762 = 1101008028;
        new_Skin.M762_Mag = 1010080281;
    }
    if (Config["SKIN_M762"] == 3) {
        new_Skin.M762 = 1101008041;
        new_Skin.M762_Mag = 1010080411;
    }
    if (Config["SKIN_M762"] == 4) {
        new_Skin.M762 = 1101008054;
        new_Skin.M762_Mag = 1010080541;
    }
    if (Config["SKIN_M762"] == 5) {
        new_Skin.M762 = 1101008067;
        new_Skin.M762_Mag = 1010080671;
    }
    if (Config["SKIN_M762"] == 6) {
        new_Skin.M762 = 1101008080;
        new_Skin.M762_Mag = 1010080801;
    }
    if (Config["SKIN_M762"] == 7) {
        new_Skin.M762 = 1101008093;
        new_Skin.M762_Mag = 1010080931;
    }
    if (Config["SKIN_M762"] == 8) {
        new_Skin.M762 = 1101008106;
        new_Skin.M762_Mag = 1010081061;
    }
    if (Config["SKIN_M762"] == 9) {
        new_Skin.M762 = 1101008119;
        new_Skin.M762_Mag = 1010081191;
    }

    // Additional weapon skins can be added here...
    // This structure makes it easy to add new weapons and skins
}

// ===========================================================================================================
// SKIN UTILITY FUNCTIONS
// ===========================================================================================================

// Get weapon skin ID by weapon name and skin index
int getWeaponSkinID(const std::string& weaponName, int skinIndex) {
    if (weaponName == "AKM") {
        switch(skinIndex) {
            case 0: return 101001;
            case 1: return 1101001089;
            case 2: return 1101001103;
            case 3: return 1101001116;
            case 4: return 1101001128;
            case 5: return 1101001143;
            case 6: return 1101001154;
            case 7: return 1101001174;
            case 8: return 1101001213;
            case 9: return 1101001231;
            case 10: return 1101001242;
            default: return 101001;
        }
    }
    // Add more weapons as needed
    return 0;
}



// Check if skin is available for weapon
bool isSkinAvailable(const std::string& weaponName, int skinIndex) {
    return getWeaponSkinID(weaponName, skinIndex) != 0;
}

// Get total number of skins for a weapon
int getTotalSkinsForWeapon(const std::string& weaponName) {
    if (weaponName == "AKM") return 11;
    if (weaponName == "KAR98K") return 7;
    if (weaponName == "AWM") return 8;
    if (weaponName == "M24") return 6;
    if (weaponName == "ACE32") return 3;
    if (weaponName == "VECTOR") return 5;
    if (weaponName == "UMP45") return 8;
    if (weaponName == "UZI") return 7;
    if (weaponName == "THOMPSON") return 3;
    if (weaponName == "M16A4") return 6;
    if (weaponName == "AUG") return 4;
    if (weaponName == "GROZAR") return 7;
    if (weaponName == "SCARL") return 8;
    if (weaponName == "M762") return 10;
    if (weaponName == "M249") return 5;
    if (weaponName == "DP28") return 5;
    return 1; // Default skin only
}

// ===========================================================================================================
// COMPLETE WEAPON ATTACHMENT SYSTEM
// ===========================================================================================================
// This system automatically changes weapon attachments based on the selected gun skin
// Each weapon skin has its own set of compatible attachments (magazines, sights, stocks, etc.)
// ===========================================================================================================

// Attachment type enumeration
enum class AttachType {
    MAGAZINE,
    DEF_STOCK,
    DEF_MUZZLE,
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
    THUMB_GRIP
};

// Weapon data structure containing all attachment IDs
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
    int tacticalStockId;
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
               int tacticalStockId = 999999999, int verticleGripId = 999999999, int angledGripId = 999999999, int lightGripId = 999999999, int halfGripId = 999999999, int laserSightId = 999999999,
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
          tacticalStockId(tacticalStockId),
          verticleGripId(verticleGripId),
          angledGripId(angledGripId),
          lightGripId(lightGripId),
          halfGripId(halfGripId),
          laserSightId(laserSightId),
          thumbGripId(thumbGripId),
          displayName(displayName) {}
};

// Global maps for weapon and attachment type tracking
static std::map<int, std::string> skinTypes;
static std::map<int, AttachType> attachmentTypes;

// Weapon data vectors for each weapon type
static std::vector<std::pair<int, WeaponData>> m416Weapons;
static std::vector<std::pair<int, WeaponData>> akmWeapons;
static std::vector<std::pair<int, WeaponData>> scarWeapons;
static std::vector<std::pair<int, WeaponData>> m762Weapons;
static std::vector<std::pair<int, WeaponData>> m16Weapons;
static std::vector<std::pair<int, WeaponData>> grozaWeapons;
static std::vector<std::pair<int, WeaponData>> augWeapons;
static std::vector<std::pair<int, WeaponData>> ace32Weapons;
static std::vector<std::pair<int, WeaponData>> m249Weapons;
static std::vector<std::pair<int, WeaponData>> dp28Weapons;
static std::vector<std::pair<int, WeaponData>> mg3Weapons;
static std::vector<std::pair<int, WeaponData>> uziWeapons;
static std::vector<std::pair<int, WeaponData>> umpWeapons;
static std::vector<std::pair<int, WeaponData>> vectorWeapons;
static std::vector<std::pair<int, WeaponData>> thompsonWeapons;
static std::vector<std::pair<int, WeaponData>> m24Weapons;
static std::vector<std::pair<int, WeaponData>> kar98Weapons;
static std::vector<std::pair<int, WeaponData>> awmWeapons;
static std::vector<std::pair<int, WeaponData>> amrWeapons;
static std::vector<std::pair<int, WeaponData>> mk14Weapons;

// ===========================================================================================================
// WEAPON DATA INITIALIZATION
// ===========================================================================================================

void initializeWeaponData() {
    // ===========================================================================================================
    // M416 WEAPON DATA
    // ===========================================================================================================
    
    // Default M416
    WeaponData data;
    data.displayName = std::string(OBFUSCATE("Default - M416"));
    m416Weapons.push_back(std::make_pair(0, data));

    // Glacier M416 (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - M416 (Lv. 7)"));
    data.weaponId = 1101004046;
    data.magazineId = 1010040461;
    data.defStockId = 1010040463;
    data.defMuzzleId = 1010040462;
    data.scope2xId = 1010040466;
    data.scope3xId = 1010040467;
    data.scope4xId = 1010040468;
    data.scope6xId = 1010040481;
    data.holographicId = 1010040469;
    data.redDotId = 1010040470;
    data.extendedMagId = 1010040473;
    data.quickMagId = 1010040472;
    data.extendedQuickMagId = 1010040473;
    data.flashId = 1010040474;
    data.compensatorId = 1010040475;
    data.silencerId = 1010040476;
    data.angledGripId = 1010040477;
    data.thumbGripId = 1010040478;
    data.verticleGripId = 1010040477;
    data.tacticalStockId = 1010040480;
    data.lightGripId = 1010040477;
    data.halfGripId = 1010040477;
    data.laserSightId = 1010040477;
    
    // Register attachment types
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
    attachmentTypes.insert_or_assign(data.tacticalStockId, AttachType::TACTICAL_STOCK);
    attachmentTypes.insert_or_assign(data.lightGripId, AttachType::LIGHT_GRIP);
    attachmentTypes.insert_or_assign(data.halfGripId, AttachType::HALF_GRIP);
    attachmentTypes.insert_or_assign(data.laserSightId, AttachType::LASER_SIGHT);
    m416Weapons.push_back(std::make_pair(1, data));

    // The Fool M416 (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("The Fool - M416 (Lv. 7)"));
    data.weaponId = 1101004062;
    data.magazineId = 1010040611;
    data.defStockId = 1010040613;
    data.defMuzzleId = 1010040612;
    data.scope2xId = 1010040612;
    data.scope3xId = 1010040612;
    data.scope4xId = 1010040612;
    data.scope6xId = 1010040612;
    data.holographicId = 1010040612;
    data.redDotId = 1010040612;
    data.extendedMagId = 1010040612;
    data.quickMagId = 1010040612;
    data.extendedQuickMagId = 1010040612;
    data.flashId = 1010040612;
    data.compensatorId = 1010040612;
    data.silencerId = 1010040612;
    data.angledGripId = 1010040612;
    data.thumbGripId = 1010040612;
    data.verticleGripId = 1010040612;
    data.tacticalStockId = 1010040612;
    data.lightGripId = 1010040612;
    data.halfGripId = 1010040612;
    data.laserSightId = 1010040612;
    m416Weapons.push_back(std::make_pair(2, data));

    // ===========================================================================================================
    // AKM WEAPON DATA
    // ===========================================================================================================
    
    // Default AKM
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - AKM"));
    akmWeapons.push_back(std::make_pair(0, data));

    // Glacier AKM (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - AKM (Lv. 7)"));
    data.weaponId = 1101001089;
    data.magazineId = 1010010891;
    data.defStockId = 1010010892;
    data.defMuzzleId = 1010010893;
    data.scope2xId = 1010010894;
    data.scope3xId = 1010010895;
    data.scope4xId = 1010010896;
    data.scope6xId = 1010010897;
    data.holographicId = 1010010898;
    data.redDotId = 1010010899;
    data.extendedMagId = 1010010900;
    data.quickMagId = 1010010901;
    data.extendedQuickMagId = 1010010902;
    data.flashId = 1010010903;
    data.compensatorId = 1010010904;
    data.silencerId = 1010010905;
    data.angledGripId = 1010010906;
    data.thumbGripId = 1010010907;
    data.verticleGripId = 1010010908;
    data.tacticalStockId = 1010010909;
    data.lightGripId = 1010010910;
    data.halfGripId = 1010010911;
    data.laserSightId = 1010010912;
    akmWeapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // ACE32 WEAPON DATA
    // ===========================================================================================================
    
    // Default ACE32
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - ACE32"));
    ace32Weapons.push_back(std::make_pair(0, data));

    // Icicle Spike ACE32 (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Icicle Spike - ACE32 (Lv. 7)"));
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
    data.tacticalStockId = 1011020137;
    data.lightGripId = 1011020138;
    data.halfGripId = 1011020139;
    data.laserSightId = 1011020144;
    
    // Register attachment types for ACE32
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
    attachmentTypes.insert_or_assign(data.tacticalStockId, AttachType::TACTICAL_STOCK);
    attachmentTypes.insert_or_assign(data.lightGripId, AttachType::LIGHT_GRIP);
    attachmentTypes.insert_or_assign(data.halfGripId, AttachType::HALF_GRIP);
    attachmentTypes.insert_or_assign(data.laserSightId, AttachType::LASER_SIGHT);
    ace32Weapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // SCAR-L WEAPON DATA
    // ===========================================================================================================
    
    // Default SCAR-L
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - SCAR-L"));
    scarWeapons.push_back(std::make_pair(0, data));

    // Glacier SCAR-L (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - SCAR-L (Lv. 7)"));
    data.weaponId = 1101003057;
    data.magazineId = 1010030571;
    data.defStockId = 1010030572;
    data.defMuzzleId = 1010030573;
    data.scope2xId = 1010030574;
    data.scope3xId = 1010030575;
    data.scope4xId = 1010030576;
    data.scope6xId = 1010030577;
    data.holographicId = 1010030578;
    data.redDotId = 1010030579;
    data.extendedMagId = 1010030580;
    data.quickMagId = 1010030581;
    data.extendedQuickMagId = 1010030582;
    data.flashId = 1010030583;
    data.compensatorId = 1010030584;
    data.silencerId = 1010030585;
    data.angledGripId = 1010030586;
    data.thumbGripId = 1010030587;
    data.verticleGripId = 1010030588;
    data.tacticalStockId = 1010030589;
    data.lightGripId = 1010030590;
    data.halfGripId = 1010030591;
    data.laserSightId = 1010030592;
    scarWeapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // M762 WEAPON DATA
    // ===========================================================================================================
    
    // Default M762
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - M762"));
    m762Weapons.push_back(std::make_pair(0, data));

    // Glacier M762 (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - M762 (Lv. 7)"));
    data.weaponId = 1101008026;
    data.magazineId = 1010080261;
    data.defStockId = 1010080262;
    data.defMuzzleId = 1010080263;
    data.scope2xId = 1010080264;
    data.scope3xId = 1010080265;
    data.scope4xId = 1010080266;
    data.scope6xId = 1010080267;
    data.holographicId = 1010080268;
    data.redDotId = 1010080269;
    data.extendedMagId = 1010080270;
    data.quickMagId = 1010080271;
    data.extendedQuickMagId = 1010080272;
    data.flashId = 1010080273;
    data.compensatorId = 1010080274;
    data.silencerId = 1010080275;
    data.angledGripId = 1010080276;
    data.thumbGripId = 1010080277;
    data.verticleGripId = 1010080278;
    data.tacticalStockId = 1010080279;
    data.lightGripId = 1010080280;
    data.halfGripId = 1010080281;
    data.laserSightId = 1010080282;
    m762Weapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // M16A4 WEAPON DATA
    // ===========================================================================================================
    
    // Default M16A4
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - M16A4"));
    m16Weapons.push_back(std::make_pair(0, data));

    // Glacier M16A4 (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - M16A4 (Lv. 7)"));
    data.weaponId = 1101002029;
    data.magazineId = 1010020291;
    data.defStockId = 1010020292;
    data.defMuzzleId = 1010020293;
    data.scope2xId = 1010020294;
    data.scope3xId = 1010020295;
    data.scope4xId = 1010020296;
    data.scope6xId = 1010020297;
    data.holographicId = 1010020298;
    data.redDotId = 1010020299;
    data.extendedMagId = 1010020300;
    data.quickMagId = 1010020301;
    data.extendedQuickMagId = 1010020302;
    data.flashId = 1010020303;
    data.compensatorId = 1010020304;
    data.silencerId = 1010020305;
    data.angledGripId = 1010020306;
    data.thumbGripId = 1010020307;
    data.verticleGripId = 1010020308;
    data.tacticalStockId = 1010020309;
    data.lightGripId = 1010020310;
    data.halfGripId = 1010020311;
    data.laserSightId = 1010020312;
    m16Weapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // GROZA WEAPON DATA
    // ===========================================================================================================
    
    // Default GROZA
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - GROZA"));
    grozaWeapons.push_back(std::make_pair(0, data));

    // Glacier GROZA (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - GROZA (Lv. 7)"));
    data.weaponId = 1101005019;
    data.magazineId = 1010050191;
    data.defStockId = 1010050192;
    data.defMuzzleId = 1010050193;
    data.scope2xId = 1010050194;
    data.scope3xId = 1010050195;
    data.scope4xId = 1010050196;
    data.scope6xId = 1010050197;
    data.holographicId = 1010050198;
    data.redDotId = 1010050199;
    data.extendedMagId = 1010050200;
    data.quickMagId = 1010050201;
    data.extendedQuickMagId = 1010050202;
    data.flashId = 1010050203;
    data.compensatorId = 1010050204;
    data.silencerId = 1010050205;
    data.angledGripId = 1010050206;
    data.thumbGripId = 1010050207;
    data.verticleGripId = 1010050208;
    data.tacticalStockId = 1010050209;
    data.lightGripId = 1010050210;
    data.halfGripId = 1010050211;
    data.laserSightId = 1010050212;
    grozaWeapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // AUG WEAPON DATA
    // ===========================================================================================================
    
    // Default AUG
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - AUG"));
    augWeapons.push_back(std::make_pair(0, data));

    // Glacier AUG (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - AUG (Lv. 7)"));
    data.weaponId = 1101006033;
    data.magazineId = 1010060331;
    data.defStockId = 1010060332;
    data.defMuzzleId = 1010060333;
    data.scope2xId = 1010060334;
    data.scope3xId = 1010060335;
    data.scope4xId = 1010060336;
    data.scope6xId = 1010060337;
    data.holographicId = 1010060338;
    data.redDotId = 1010060339;
    data.extendedMagId = 1010060340;
    data.quickMagId = 1010060341;
    data.extendedQuickMagId = 1010060342;
    data.flashId = 1010060343;
    data.compensatorId = 1010060344;
    data.silencerId = 1010060345;
    data.angledGripId = 1010060346;
    data.thumbGripId = 1010060347;
    data.verticleGripId = 1010060348;
    data.tacticalStockId = 1010060349;
    data.lightGripId = 1010060350;
    data.halfGripId = 1010060351;
    data.laserSightId = 1010060352;
    augWeapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // M249 WEAPON DATA
    // ===========================================================================================================
    
    // Default M249
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - M249"));
    m249Weapons.push_back(std::make_pair(0, data));

    // Glacier M249 (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - M249 (Lv. 7)"));
    data.weaponId = 1105001020;
    data.magazineId = 1050010201;
    data.defStockId = 1050010202;
    data.defMuzzleId = 1050010203;
    data.scope2xId = 1050010204;
    data.scope3xId = 1050010205;
    data.scope4xId = 1050010206;
    data.scope6xId = 1050010207;
    data.holographicId = 1050010208;
    data.redDotId = 1050010209;
    data.extendedMagId = 1050010210;
    data.quickMagId = 1050010211;
    data.extendedQuickMagId = 1050010212;
    data.flashId = 1050010213;
    data.compensatorId = 1050010214;
    data.silencerId = 1050010215;
    data.angledGripId = 1050010216;
    data.thumbGripId = 1050010217;
    data.verticleGripId = 1050010218;
    data.tacticalStockId = 1050010219;
    data.lightGripId = 1050010220;
    data.halfGripId = 1050010221;
    data.laserSightId = 1050010222;
    m249Weapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // DP28 WEAPON DATA
    // ===========================================================================================================
    
    // Default DP28
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - DP28"));
    dp28Weapons.push_back(std::make_pair(0, data));

    // Glacier DP28 (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - DP28 (Lv. 7)"));
    data.weaponId = 1105002018;
    data.magazineId = 1050020181;
    data.defStockId = 1050020182;
    data.defMuzzleId = 1050020183;
    data.scope2xId = 1050020184;
    data.scope3xId = 1050020185;
    data.scope4xId = 1050020186;
    data.scope6xId = 1050020187;
    data.holographicId = 1050020188;
    data.redDotId = 1050020189;
    data.extendedMagId = 1050020190;
    data.quickMagId = 1050020191;
    data.extendedQuickMagId = 1050020192;
    data.flashId = 1050020193;
    data.compensatorId = 1050020194;
    data.silencerId = 1050020195;
    data.angledGripId = 1050020196;
    data.thumbGripId = 1050020197;
    data.verticleGripId = 1050020198;
    data.tacticalStockId = 1050020199;
    data.lightGripId = 1050020200;
    data.halfGripId = 1050020201;
    data.laserSightId = 1050020202;
    dp28Weapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // MG3 WEAPON DATA
    // ===========================================================================================================
    
    // Default MG3
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - MG3"));
    mg3Weapons.push_back(std::make_pair(0, data));

    // Glacier MG3 (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - MG3 (Lv. 7)"));
    data.weaponId = 1105010008;
    data.magazineId = 1050100081;
    data.defStockId = 1050100082;
    data.defMuzzleId = 1050100083;
    data.scope2xId = 1050100084;
    data.scope3xId = 1050100085;
    data.scope4xId = 1050100086;
    data.scope6xId = 1050100087;
    data.holographicId = 1050100088;
    data.redDotId = 1050100089;
    data.extendedMagId = 1050100090;
    data.quickMagId = 1050100091;
    data.extendedQuickMagId = 1050100092;
    data.flashId = 1050100093;
    data.compensatorId = 1050100094;
    data.silencerId = 1050100095;
    data.angledGripId = 1050100096;
    data.thumbGripId = 1050100097;
    data.verticleGripId = 1050100098;
    data.tacticalStockId = 1050100099;
    data.lightGripId = 1050100100;
    data.halfGripId = 1050100101;
    data.laserSightId = 1050100102;
    mg3Weapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // UZI WEAPON DATA
    // ===========================================================================================================
    
    // Default UZI
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - UZI"));
    uziWeapons.push_back(std::make_pair(0, data));

    // Glacier UZI (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - UZI (Lv. 7)"));
    data.weaponId = 1102001024;
    data.magazineId = 1020010241;
    data.defStockId = 1020010242;
    data.defMuzzleId = 1020010243;
    data.scope2xId = 1020010244;
    data.scope3xId = 1020010245;
    data.scope4xId = 1020010246;
    data.scope6xId = 1020010247;
    data.holographicId = 1020010248;
    data.redDotId = 1020010249;
    data.extendedMagId = 1020010250;
    data.quickMagId = 1020010251;
    data.extendedQuickMagId = 1020010252;
    data.flashId = 1020010253;
    data.compensatorId = 1020010254;
    data.silencerId = 1020010255;
    data.angledGripId = 1020010256;
    data.thumbGripId = 1020010257;
    data.verticleGripId = 1020010258;
    data.tacticalStockId = 1020010259;
    data.lightGripId = 1020010260;
    data.halfGripId = 1020010261;
    data.laserSightId = 1020010262;
    uziWeapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // UMP45 WEAPON DATA
    // ===========================================================================================================
    
    // Default UMP45
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - UMP45"));
    umpWeapons.push_back(std::make_pair(0, data));

    // Glacier UMP45 (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - UMP45 (Lv. 7)"));
    data.weaponId = 1102002043;
    data.magazineId = 1020020431;
    data.defStockId = 1020020432;
    data.defMuzzleId = 1020020433;
    data.scope2xId = 1020020434;
    data.scope3xId = 1020020435;
    data.scope4xId = 1020020436;
    data.scope6xId = 1020020437;
    data.holographicId = 1020020438;
    data.redDotId = 1020020439;
    data.extendedMagId = 1020020440;
    data.quickMagId = 1020020441;
    data.extendedQuickMagId = 1020020442;
    data.flashId = 1020020443;
    data.compensatorId = 1020020444;
    data.silencerId = 1020020445;
    data.angledGripId = 1020020446;
    data.thumbGripId = 1020020447;
    data.verticleGripId = 1020020448;
    data.tacticalStockId = 1020020449;
    data.lightGripId = 1020020450;
    data.halfGripId = 1020020451;
    data.laserSightId = 1020020452;
    umpWeapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // VECTOR WEAPON DATA
    // ===========================================================================================================
    
    // Default VECTOR
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - VECTOR"));
    vectorWeapons.push_back(std::make_pair(0, data));

    // Glacier VECTOR (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - VECTOR (Lv. 7)"));
    data.weaponId = 1102003020;
    data.magazineId = 1020030201;
    data.defStockId = 1020030202;
    data.defMuzzleId = 1020030203;
    data.scope2xId = 1020030204;
    data.scope3xId = 1020030205;
    data.scope4xId = 1020030206;
    data.scope6xId = 1020030207;
    data.holographicId = 1020030208;
    data.redDotId = 1020030209;
    data.extendedMagId = 1020030210;
    data.quickMagId = 1020030211;
    data.extendedQuickMagId = 1020030212;
    data.flashId = 1020030213;
    data.compensatorId = 1020030214;
    data.silencerId = 1020030215;
    data.angledGripId = 1020030216;
    data.thumbGripId = 1020030217;
    data.verticleGripId = 1020030218;
    data.tacticalStockId = 1020030219;
    data.lightGripId = 1020030220;
    data.halfGripId = 1020030221;
    data.laserSightId = 1020030222;
    vectorWeapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // THOMPSON WEAPON DATA
    // ===========================================================================================================
    
    // Default THOMPSON
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - THOMPSON"));
    thompsonWeapons.push_back(std::make_pair(0, data));

    // Glacier THOMPSON (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - THOMPSON (Lv. 7)"));
    data.weaponId = 1102004018;
    data.magazineId = 1020040181;
    data.defStockId = 1020040182;
    data.defMuzzleId = 1020040183;
    data.scope2xId = 1020040184;
    data.scope3xId = 1020040185;
    data.scope4xId = 1020040186;
    data.scope6xId = 1020040187;
    data.holographicId = 1020040188;
    data.redDotId = 1020040189;
    data.extendedMagId = 1020040190;
    data.quickMagId = 1020040191;
    data.extendedQuickMagId = 1020040192;
    data.flashId = 1020040193;
    data.compensatorId = 1020040194;
    data.silencerId = 1020040195;
    data.angledGripId = 1020040196;
    data.thumbGripId = 1020040197;
    data.verticleGripId = 1020040198;
    data.tacticalStockId = 1020040199;
    data.lightGripId = 1020040200;
    data.halfGripId = 1020040201;
    data.laserSightId = 1020040202;
    thompsonWeapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // M24 WEAPON DATA
    // ===========================================================================================================
    
    // Default M24
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - M24"));
    m24Weapons.push_back(std::make_pair(0, data));

    // Glacier M24 (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - M24 (Lv. 7)"));
    data.weaponId = 1103002018;
    data.magazineId = 1030020181;
    data.defStockId = 1030020182;
    data.defMuzzleId = 1030020183;
    data.scope2xId = 1030020184;
    data.scope3xId = 1030020185;
    data.scope4xId = 1030020186;
    data.scope6xId = 1030020187;
    data.scope8xId = 1030020188;
    data.holographicId = 1030020189;
    data.redDotId = 1030020190;
    data.extendedMagId = 1030020191;
    data.quickMagId = 1030020192;
    data.extendedQuickMagId = 1030020193;
    data.flashId = 1030020194;
    data.compensatorId = 1030020195;
    data.silencerId = 1030020196;
    data.angledGripId = 1030020197;
    data.thumbGripId = 1030020198;
    data.verticleGripId = 1030020199;
    data.tacticalStockId = 1030020200;
    data.lightGripId = 1030020201;
    data.halfGripId = 1030020202;
    data.laserSightId = 1030020203;
    m24Weapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // KAR98K WEAPON DATA
    // ===========================================================================================================
    
    // Default KAR98K
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - KAR98K"));
    kar98Weapons.push_back(std::make_pair(0, data));

    // Glacier KAR98K (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - KAR98K (Lv. 7)"));
    data.weaponId = 1103001060;
    data.magazineId = 1030010601;
    data.defStockId = 1030010602;
    data.defMuzzleId = 1030010603;
    data.scope2xId = 1030010604;
    data.scope3xId = 1030010605;
    data.scope4xId = 1030010606;
    data.scope6xId = 1030010607;
    data.scope8xId = 1030010608;
    data.holographicId = 1030010609;
    data.redDotId = 1030010610;
    data.extendedMagId = 1030010611;
    data.quickMagId = 1030010612;
    data.extendedQuickMagId = 1030010613;
    data.flashId = 1030010614;
    data.compensatorId = 1030010615;
    data.silencerId = 1030010616;
    data.angledGripId = 1030010617;
    data.thumbGripId = 1030010618;
    data.verticleGripId = 1030010619;
    data.tacticalStockId = 1030010620;
    data.lightGripId = 1030010621;
    data.halfGripId = 1030010622;
    data.laserSightId = 1030010623;
    kar98Weapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // AWM WEAPON DATA
    // ===========================================================================================================
    
    // Default AWM
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - AWM"));
    awmWeapons.push_back(std::make_pair(0, data));

    // Glacier AWM (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - AWM (Lv. 7)"));
    data.weaponId = 1103003022;
    data.magazineId = 1030030221;
    data.defStockId = 1030030222;
    data.defMuzzleId = 1030030223;
    data.scope2xId = 1030030224;
    data.scope3xId = 1030030225;
    data.scope4xId = 1030030226;
    data.scope6xId = 1030030227;
    data.scope8xId = 1030030228;
    data.holographicId = 1030030229;
    data.redDotId = 1030030230;
    data.extendedMagId = 1030030231;
    data.quickMagId = 1030030232;
    data.extendedQuickMagId = 1030030233;
    data.flashId = 1030030234;
    data.compensatorId = 1030030235;
    data.silencerId = 1030030236;
    data.angledGripId = 1030030237;
    data.thumbGripId = 1030030238;
    data.verticleGripId = 1030030239;
    data.tacticalStockId = 1030030240;
    data.lightGripId = 1030030241;
    data.halfGripId = 1030030242;
    data.laserSightId = 1030030243;
    awmWeapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // AMR WEAPON DATA
    // ===========================================================================================================
    
    // Default AMR
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - AMR"));
    amrWeapons.push_back(std::make_pair(0, data));

    // Glacier AMR (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - AMR (Lv. 7)"));
    data.weaponId = 1103012010;
    data.magazineId = 1030120101;
    data.defStockId = 1030120102;
    data.defMuzzleId = 1030120103;
    data.scope2xId = 1030120104;
    data.scope3xId = 1030120105;
    data.scope4xId = 1030120106;
    data.scope6xId = 1030120107;
    data.scope8xId = 1030120108;
    data.holographicId = 1030120109;
    data.redDotId = 1030120110;
    data.extendedMagId = 1030120111;
    data.quickMagId = 1030120112;
    data.extendedQuickMagId = 1030120113;
    data.flashId = 1030120114;
    data.compensatorId = 1030120115;
    data.silencerId = 1030120116;
    data.angledGripId = 1030120117;
    data.thumbGripId = 1030120118;
    data.verticleGripId = 1030120119;
    data.tacticalStockId = 1030120120;
    data.lightGripId = 1030120121;
    data.halfGripId = 1030120122;
    data.laserSightId = 1030120123;
    amrWeapons.push_back(std::make_pair(1, data));

    // ===========================================================================================================
    // MK14 WEAPON DATA
    // ===========================================================================================================
    
    // Default MK14
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Default - MK14"));
    mk14Weapons.push_back(std::make_pair(0, data));

    // Glacier MK14 (Lv. 7)
    data = WeaponData();
    data.displayName = std::string(OBFUSCATE("Glacier - MK14 (Lv. 7)"));
    data.weaponId = 1103007020;
    data.magazineId = 1030070201;
    data.defStockId = 1030070202;
    data.defMuzzleId = 1030070203;
    data.scope2xId = 1030070204;
    data.scope3xId = 1030070205;
    data.scope4xId = 1030070206;
    data.scope6xId = 1030070207;
    data.scope8xId = 1030070208;
    data.holographicId = 1030070209;
    data.redDotId = 1030070210;
    data.extendedMagId = 1030070211;
    data.quickMagId = 1030070212;
    data.extendedQuickMagId = 1030070213;
    data.flashId = 1030070214;
    data.compensatorId = 1030070215;
    data.silencerId = 1030070216;
    data.angledGripId = 1030070217;
    data.thumbGripId = 1030070218;
    data.verticleGripId = 1030070219;
    data.tacticalStockId = 1030070220;
    data.lightGripId = 1030070221;
    data.halfGripId = 1030070222;
    data.laserSightId = 1030070223;
    mk14Weapons.push_back(std::make_pair(1, data));
}

// ===========================================================================================================
// WEAPON DATA ACCESS FUNCTIONS
// ===========================================================================================================

// Get weapon data by weapon name and skin index
WeaponData getWeaponData(const std::string& weaponName, int skinIndex) {
    if (weaponName == "M416") {
        for (const auto& pair : m416Weapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "AKM") {
        for (const auto& pair : akmWeapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "SCAR-L") {
        for (const auto& pair : scarWeapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "M762") {
        for (const auto& pair : m762Weapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "M16A4") {
        for (const auto& pair : m16Weapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "GROZA") {
        for (const auto& pair : grozaWeapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "AUG") {
        for (const auto& pair : augWeapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "ACE32") {
        for (const auto& pair : ace32Weapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "M249") {
        for (const auto& pair : m249Weapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "DP28") {
        for (const auto& pair : dp28Weapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "MG3") {
        for (const auto& pair : mg3Weapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "UZI") {
        for (const auto& pair : uziWeapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "UMP45") {
        for (const auto& pair : umpWeapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "VECTOR") {
        for (const auto& pair : vectorWeapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "THOMPSON") {
        for (const auto& pair : thompsonWeapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "M24") {
        for (const auto& pair : m24Weapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "KAR98K") {
        for (const auto& pair : kar98Weapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "AWM") {
        for (const auto& pair : awmWeapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "AMR") {
        for (const auto& pair : amrWeapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }
        }
    } else if (weaponName == "MK14") {
        for (const auto& pair : mk14Weapons) {
            if (pair.first == skinIndex) {
                return pair.second;
            }   
        }
    }
    
    // Return default weapon data if not found
    return WeaponData();
}

// Get attachment ID by weapon name, skin index, and attachment type
int getAttachmentID(const std::string& weaponName, int skinIndex, AttachType attachType) {
    WeaponData data = getWeaponData(weaponName, skinIndex);
    
    switch (attachType) {
        case AttachType::MAGAZINE:
            return data.magazineId;
        case AttachType::DEF_STOCK:
            return data.defStockId;
        case AttachType::DEF_MUZZLE:
            return data.defMuzzleId;
        case AttachType::FLASH:
            return data.flashId;
        case AttachType::COMPENSATOR:
            return data.compensatorId;
        case AttachType::SILENCER:
            return data.silencerId;
        case AttachType::RED_DOT:
            return data.redDotId;
        case AttachType::HOLOGRAPHIC:
            return data.holographicId;
        case AttachType::SCOPE2X:
            return data.scope2xId;
        case AttachType::SCOPE3X:
            return data.scope3xId;
        case AttachType::SCOPE4X:
            return data.scope4xId;
        case AttachType::SCOPE6X:
            return data.scope6xId;
        case AttachType::SCOPE8X:
            return data.scope8xId;
        case AttachType::QUICK_MAG:
            return data.quickMagId;
        case AttachType::EXTENDED_MAG:
            return data.extendedMagId;
        case AttachType::EXTENDED_QUICK_MAG:
            return data.extendedQuickMagId;
        case AttachType::TACTICAL_STOCK:
            return data.tacticalStockId;
        case AttachType::VERTICLE_GRIP:
            return data.verticleGripId;
        case AttachType::ANGLED_GRIP:
            return data.angledGripId;
        case AttachType::LIGHT_GRIP:
            return data.lightGripId;
        case AttachType::HALF_GRIP:
            return data.halfGripId;
        case AttachType::LASER_SIGHT:
            return data.laserSightId;
        case AttachType::THUMB_GRIP:
            return data.thumbGripId;
        default:
            return 999999999; // Default invalid ID
    }
}

// Get total number of skins for a weapon
int getTotalSkinsForWeaponData(const std::string& weaponName) {
    if (weaponName == "M416") return m416Weapons.size();
    if (weaponName == "AKM") return akmWeapons.size();
    if (weaponName == "SCAR-L") return scarWeapons.size();
    if (weaponName == "M762") return m762Weapons.size();
    if (weaponName == "M16A4") return m16Weapons.size();
    if (weaponName == "GROZA") return grozaWeapons.size();
    if (weaponName == "AUG") return augWeapons.size();
    if (weaponName == "ACE32") return ace32Weapons.size();
    if (weaponName == "M249") return m249Weapons.size();
    if (weaponName == "DP28") return dp28Weapons.size();
    if (weaponName == "MG3") return mg3Weapons.size();
    if (weaponName == "UZI") return uziWeapons.size();
    if (weaponName == "UMP45") return umpWeapons.size();
    if (weaponName == "VECTOR") return vectorWeapons.size();
    if (weaponName == "THOMPSON") return thompsonWeapons.size();
    if (weaponName == "M24") return m24Weapons.size();
    if (weaponName == "KAR98K") return kar98Weapons.size();
    if (weaponName == "AWM") return awmWeapons.size();
    if (weaponName == "AMR") return amrWeapons.size();
    if (weaponName == "MK14") return mk14Weapons.size();
    return 1; // Default skin only
}

// ===================================================================================================
struct SkinInfo {
    int id;
    std::string name;
};

// Main map for all weapon skins
// Structure: Weapon Name -> { Skin Index -> {Skin ID, Skin Name} }
static std::map<std::string, std::map<int, SkinInfo>> weaponSkins = {
    {"M416", {
        {0, {101004, "Default"}},
        {1, {10100401, "Desert Camo"}},
        {2, {10100402, "Digital Camo"}},
        {3, {10100403, "The Fool"}},
        {4, {10100404, "Glacier"}},
        {5, {10100405, "Lizard"}},
        {6, {10100406, "Wanderer"}},
        {7, {10100407, "TechnoCore"}},
        {8, {10100408, "Call of the Wild"}},
        {9, {1101004046, "Metro 1"}},
        {10, {1101004062, "Metro 2"}},
        {11, {1101004078, "Metro 3"}},
        {12, {1101004086, "Metro 4"}},
        {13, {1101004098, "Metro 5"}},
        {14, {1101004138, "Metro 6"}},
        {15, {1101004163, "Metro 7"}},
        {16, {1101004201, "Metro 8"}},
        {17, {1101004209, "Metro 9"}},
        {18, {1101004218, "Metro 10"}},
        {19, {1101004226, "Metro 11"}}
    }},
    {"AKM", {
        {0, {101001, "Default"}},
        {1, {1010011, "Metro 1"}},
        {2, {1010012, "Metro 2"}},
        {3, {1010013, "Metro 3"}},
        {4, {1010014, "Metro 4"}},
        {5, {1010015, "Metro 5"}},
        {6, {1010016, "Metro 6"}},
        {7, {1010017, "Metro 7"}},
        {8, {101001008, "Hellfire"}},
        {9, {101001009, "Wandering Tyrant"}},
        {10, {101001010, "Jack-o'-lantern"}},
        {11, {1101001089, "Global 1"}},
        {12, {1101001103, "Global 2"}},
        {13, {1101001116, "Global 3"}},
        {14, {1101001128, "Global 4"}},
        {15, {1101001143, "Global 5"}},
        {16, {1101001154, "Global 6"}},
        {17, {1101001174, "Global 7"}},
        {18, {1101001213, "Global 8"}},
        {19, {1101001231, "Global 9"}},
        {20, {1101001242, "Global 10"}},
        {21, {1101001249, "Global 11"}},
        {22, {1101001256, "Global 12"}},
        {23, {1101001063, "Global 13"}}
    }},
    {"SCAR-L", {
        {0, {101003, "Default"}},
        {1, {1010031, "Metro 1"}},
        {2, {1010032, "Metro 2"}},
        {3, {1010033, "Metro 3"}},
        {4, {1010034, "Metro 4"}},
        {5, {1010035, "Metro 5"}},
        {6, {1010036, "Metro 6"}},
        {7, {1010037, "Metro 7"}},
        {8, {1101003057, "Global 1"}},
        {9, {1101003070, "Global 2"}},
        {10, {1101003080, "Global 3"}},
        {11, {1101003119, "Global 4"}},
        {12, {1101003146, "Global 5"}},
        {13, {1101003167, "Global 6"}},
        {14, {1101003181, "Global 7"}},
        {15, {1101003195, "Global 8"}}
    }},
    {"M762", {
        {0, {101008, "Default"}},
        {1, {1010081, "Metro 1"}},
        {2, {1010082, "Metro 2"}},
        {3, {1010083, "Metro 3"}},
        {4, {1010084, "Metro 4"}},
        {5, {1010085, "Metro 5"}},
        {6, {1010086, "Metro 6"}},
        {7, {1010087, "Metro 7"}},
        {8, {1101008026, "Global 1"}},
        {9, {1101008051, "Global 2"}},
        {10, {1101008061, "Global 3"}},
        {11, {1101008081, "Global 4"}},
        {12, {1101008104, "Global 5"}},
        {13, {1101008116, "Global 6"}},
        {14, {1101008126, "Global 7"}},
        {15, {1101008070, "Global 8"}}
    }},
    {"AWM", {
        {0, {103003, "Default"}},
        {1, {1030031, "Metro 1"}},
        {2, {1030032, "Metro 2"}},
        {3, {1030033, "Metro 3"}},
        {4, {1030034, "Metro 4"}},
        {5, {1030035, "Metro 5"}},
        {6, {1030036, "Metro 6"}},
        {7, {1030037, "Metro 7"}},
        {8, {1103003022, "Global 1"}},
        {9, {1103003030, "Global 2"}},
        {10, {1103003042, "Global 3"}},
        {11, {1103003051, "Global 4"}},
        {12, {1103003062, "Global 5"}}
    }},
    {"AMR", {
        {0, {103012, "Default"}},
        {1, {1030121, "Metro 1"}},
        {2, {1030122, "Metro 2"}},
        {3, {1030123, "Metro 3"}},
        {4, {1030124, "Metro 4"}},
        {5, {1030125, "Metro 5"}},
        {6, {1030126, "Metro 6"}},
        {7, {1030127, "Metro 7"}},
        {8, {1103012010, "Global 1"}},
        {9, {1103012019, "Global 2"}}
    }},
    {"MK14", {
        {0, {103007, "Default"}},
        {1, {1030071, "Metro 1"}},
        {2, {1030072, "Metro 2"}},
        {3, {1030073, "Metro 3"}},
        {4, {1030074, "Metro 4"}},
        {5, {1030075, "Metro 5"}},
        {6, {1030076, "Metro 6"}},
        {7, {1030077, "Metro 7"}},
        {8, {1103007020, "Global 1"}},
        {9, {1103007028, "Global 2"}}
    }},
    {"MG3", {
        {0, {105010, "Default"}},
        {1, {1050101, "Metro 1"}},
        {2, {1050102, "Metro 2"}},
        {3, {1050103, "Metro 3"}},
        {4, {1050104, "Metro 4"}},
        {5, {1050105, "Metro 5"}},
        {6, {1050106, "Metro 6"}},
        {7, {1050107, "Metro 7"}},
        {8, {1105010008, "Global 1"}},
        {9, {1105010019, "Global 2"}}
    }},
    {"Kar98k", {
        {0, {103001, "Default"}},
        {1, {1030011, "Metro 1"}},
        {2, {1030012, "Metro 2"}},
        {3, {1030013, "Metro 3"}},
        {4, {1030014, "Metro 4"}},
        {5, {1030015, "Metro 5"}},
        {6, {1030016, "Metro 6"}},
        {7, {1030017, "Metro 7"}},
        {8, {1103001060, "Global 1"}},
        {9, {1103001079, "Global 2"}},
        {10, {1103001101, "Global 3"}},
        {11, {1103001145, "Global 4"}},
        {12, {1103001160, "Global 5"}},
        {13, {1103001179, "Global 6"}}
    }},
    {"M24", {
        {0, {103002, "Default"}},
        {1, {1030021, "Metro 1"}},
        {2, {1030022, "Metro 2"}},
        {3, {1030023, "Metro 3"}},
        {4, {1030024, "Metro 4"}},
        {5, {1030025, "Metro 5"}},
        {6, {1030026, "Metro 6"}},
        {7, {1030027, "Metro 7"}},
        {8, {1103002018, "Global 1"}},
        {9, {1103002030, "Global 2"}},
        {10, {1103002048, "Global 3"}},
        {11, {1103002056, "Global 4"}},
        {12, {1103002087, "Global 5"}}
    }},
    {"Mini14", {
        {0, {103006, "Default"}},
        {1, {1103006030, "Global 1"}},
        {2, {1103006046, "Global 2"}},
        {3, {1103006058, "Global 3"}}
    }},
    {"DP-28", {
        {0, {105002, "Default"}},
        {1, {1105002018, "Global 1"}},
        {2, {1105002035, "Global 2"}},
        {3, {1105002058, "Global 3"}},
        {4, {1105002063, "Global 4"}}
    }},
    {"M249", {
        {0, {105001, "Default"}},
        {1, {1105001020, "Global 1"}},
        {2, {1105001034, "Global 2"}},
        {3, {1105001048, "Global 3"}},
        {4, {1105001054, "Global 4"}}
    }},
    {"Groza", {
        {0, {101005, "Default"}},
        {1, {1010051, "Metro 1"}},
        {2, {1010052, "Metro 2"}},
        {3, {1010053, "Metro 3"}},
        {4, {1010054, "Metro 4"}},
        {5, {1010055, "Metro 5"}},
        {6, {1010056, "Metro 6"}},
        {7, {1010057, "Metro 7"}},
        {8, {1101005019, "Global 1"}},
        {9, {1101005025, "Global 2"}},
        {10, {1101005038, "Global 3"}},
        {11, {1101005043, "Global 4"}},
        {12, {1101005052, "Global 5"}},
        {13, {1101005082, "Global 6"}}
    }},
    {"AUG", {
        {0, {101006, "Default"}},
        {1, {1010061, "Metro 1"}},
        {2, {1010062, "Metro 2"}},
        {3, {1010063, "Metro 3"}},
        {4, {1010064, "Metro 4"}},
        {5, {1010065, "Metro 5"}},
        {6, {1010066, "Metro 6"}},
        {7, {1010067, "Metro 7"}},
        {8, {1101006033, "Global 1"}},
        {9, {1101006044, "Global 2"}},
        {10, {1101006062, "Global 3"}}
    }},
    {"M16A4", {
        {0, {101002, "Default"}},
        {1, {1010021, "Metro 1"}},
        {2, {1010022, "Metro 2"}},
        {3, {1010023, "Metro 3"}},
        {4, {1010024, "Metro 4"}},
        {5, {1010025, "Metro 5"}},
        {6, {1010026, "Metro 6"}},
        {7, {1010027, "Metro 7"}},
        {8, {1101002029, "Global 1"}},
        {9, {1101002056, "Global 2"}},
        {10, {1101002068, "Global 3"}},
        {11, {1101002081, "Global 4"}},
        {12, {1101002103, "Global 5"}}
    }},
    {"UZI", {
        {0, {102001, "Default"}},
        {1, {1020011, "Metro 1"}},
        {2, {1020012, "Metro 2"}},
        {3, {1020013, "Metro 3"}},
        {4, {1020014, "Metro 4"}},
        {5, {1020015, "Metro 5"}},
        {6, {1020016, "Metro 6"}},
        {7, {1020017, "Metro 7"}},
        {8, {1102001024, "Global 1"}},
        {9, {1102001036, "Global 2"}},
        {10, {1102001058, "Global 3"}},
        {11, {1102001069, "Global 4"}},
        {12, {1102001089, "Global 5"}},
        {13, {1102001102, "Global 6"}}
    }},
    {"UMP45", {
        {0, {102002, "Default"}},
        {1, {1020021, "Metro 1"}},
        {2, {1020022, "Metro 2"}},
        {3, {1020023, "Metro 3"}},
        {4, {1020024, "Metro 4"}},
        {5, {1020025, "Metro 5"}},
        {6, {1020026, "Metro 6"}},
        {7, {1020027, "Metro 7"}},
        {8, {1102002043, "Global 1"}},
        {9, {1102002061, "Global 2"}},
        {10, {1102002090, "Global 3"}},
        {11, {1102002117, "Global 4"}},
        {12, {1102002124, "Global 5"}},
        {13, {1102002129, "Global 6"}},
        {14, {1102002136, "Global 7"}}
    }},
    {"Thompson", {
        {0, {102004, "Default"}},
        {1, {1102004018, "Global 1"}},
        {2, {1102004034, "Global 2"}}
    }},
    {"Vector", {
        {0, {102003, "Default"}},
        {1, {1020031, "Metro 1"}},
        {2, {1020032, "Metro 2"}},
        {3, {1020033, "Metro 3"}},
        {4, {1020034, "Metro 4"}},
        {5, {1020035, "Metro 5"}},
        {6, {1020036, "Metro 6"}},
        {7, {1020037, "Metro 7"}},
        {8, {1102003020, "Global 1"}},
        {9, {1102003031, "Global 2"}},
        {10, {1102003065, "Global 3"}},
        {11, {1102003080, "Global 4"}}
    }},
    {"PP-19 Bizon", {
        {0, {102005, "Default"}},
        {1, {1102005007, "Global 1"}},
        {2, {1102005020, "Global 2"}},
        {3, {1102005041, "Global 3"}}
    }},
    {"ACE32", {
        {0, {101102, "Default"}},
        {1, {1011021, "Metro 1"}},
        {2, {1011022, "Metro 2"}},
        {3, {1011023, "Metro 3"}},
        {4, {1011024, "Metro 4"}},
        {5, {1011025, "Metro 5"}},
        {6, {1011026, "Metro 6"}},
        {7, {1011027, "Metro 7"}},
        {8, {1101102007, "Global 1"}},
        {9, {1101102017, "Global 2"}},
        {10, {1101102025, "Global 3"}}
    }},
    {"Pan", {
        {0, {108004, "Default"}},
        {1, {1108004125, "Global 1"}},
        {2, {1108004145, "Global 2"}},
        {3, {1108004160, "Global 3"}},
        {4, {1108004283, "Global 4"}},
        {5, {1108004337, "Global 5"}},
        {6, {1108004356, "Global 6"}},
        {7, {1108004365, "Global 7"}},
        {8, {1108004054, "Global 8"}},
        {9, {1108004008, "Global 9"}}
    }}
};

// --- CATEGORY HELPERS ---
enum class WeaponCat { AR, DMR, SR, SMG, LMG, SG, PISTOL, MELEE, OTHER };
static std::map<std::string, WeaponCat> weaponCategoryMap = {
    {"M416", WeaponCat::AR}, {"AKM", WeaponCat::AR}, {"M762", WeaponCat::AR}, {"SCAR-L", WeaponCat::AR}, 
    {"Groza", WeaponCat::AR}, {"AUG", WeaponCat::AR}, {"M16A4", WeaponCat::AR}, {"ACE32", WeaponCat::AR},
    {"AWM", WeaponCat::SR}, {"AMR", WeaponCat::SR}, {"Kar98k", WeaponCat::SR}, {"M24", WeaponCat::SR},
    {"MK14", WeaponCat::DMR}, {"Mini14", WeaponCat::DMR},
    {"UZI", WeaponCat::SMG}, {"UMP45", WeaponCat::SMG}, {"Thompson", WeaponCat::SMG}, {"Vector", WeaponCat::SMG}, {"PP-19 Bizon", WeaponCat::SMG},
    {"MG3", WeaponCat::LMG}, {"DP-28", WeaponCat::LMG}, {"M249", WeaponCat::LMG},
    {"Pan", WeaponCat::MELEE}
};

static std::string getCategoryName(WeaponCat cat) {
    switch (cat) {
        case WeaponCat::AR: return "Assault Rifles";
        case WeaponCat::DMR: return "DMRs";
        case WeaponCat::SR: return "Sniper Rifles";
        case WeaponCat::SMG: return "SMGs";
        case WeaponCat::LMG: return "LMGs";
        case WeaponCat::SG: return "Shotguns";
        case WeaponCat::PISTOL: return "Pistols";
        case WeaponCat::MELEE: return "Melee";
        default: return "Other";
    }
}

static std::string getWeaponCategory(const std::string& weaponName) {
    auto it = weaponCategoryMap.find(weaponName);
    return (it != weaponCategoryMap.end()) ? getCategoryName(it->second) : "Other";
}

// --- JNI HELPER FUNCTIONS ---
static std::string getWeaponNameFromID(const std::string& weaponId) {
    if (weaponId.length() < 6) return "";
    std::string baseId = weaponId.substr(0, 6);
    for (auto const& [name, map] : weaponSkins) {
        if (!map.empty() && std::to_string(map.at(0).id).rfind(baseId, 0) == 0) {
            return name;
        }
    }
    return "";
} 