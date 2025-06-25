#pragma once

#include "SDK.hpp"
#include <map>
#include <string>
#include <vector>
#include "JOIN_SKIN.h" // Include for weaponSkins and getWeaponNameFromID

// We need to access the map from Main.cpp
extern std::map<std::string, int> selectedSkins;

using namespace SDK;

// ===================================================================================================
// ESP-RELATED SKIN SYSTEM
// ===================================================================================================
// This file centralizes the logic for skins that are applied based on game events,
// such as kill messages and death crate appearances.
// ===================================================================================================

struct EventSkinInfo {
    int id;
    std::string name;
};

// --- DATA MAPS ---
static std::map<int, EventSkinInfo> killMessageSkins = {
    {0, {0, "Default"}},
    {1, {101, "Godzilla Kill Message"}},
    {2, {102, "Pharaoh Kill Message"}},
    {3, {103, "Onimusha Kill Message"}},
    {4, {104, "Blood Raven Kill Message"}},
    {5, {105, "The Fool Kill Message"}},
    {6, {106, "Glacier Kill Message"}},
    {7, {107, "Wanderer Kill Message"}},
    {8, {108, "TechnoCore Kill Message"}},
    {9, {109, "Call of the Wild Kill Message"}},
    {10, {110, "Hellfire Kill Message"}},
    {11, {111, "Wandering Tyrant Kill Message"}},
    {12, {112, "Jack-o'-lantern Kill Message"}},
    {13, {113, "Metro Royale Kill Message"}},
    {14, {114, "Global Kill Message"}},
    {15, {115, "Special Event Kill Message"}}
};

static std::map<int, EventSkinInfo> lootBoxSkins = {
    {0, {0, "Default"}},
    {1, {550001, "Pharaoh's Treasure"}},
    {2, {550002, "Mummy Crate"}},
    {3, {550003, "Gilded Crate"}},
    {4, {550004, "Blood Raven Crate"}},
    {5, {550005, "The Fool's Crate"}},
    {6, {550006, "Glacier Crate"}},
    {7, {550007, "Wanderer Crate"}},
    {8, {550008, "TechnoCore Crate"}},
    {9, {550009, "Call of the Wild Crate"}},
    {10, {550010, "Hellfire Crate"}},
    {11, {550011, "Wandering Tyrant Crate"}},
    {12, {550012, "Jack-o'-lantern Crate"}},
    {13, {550013, "Metro Royale Crate"}},
    {14, {550014, "Global Crate"}},
    {15, {550015, "Special Event Crate"}},
    {16, {550016, "Golden Pharaoh Crate"}},
    {17, {550017, "Avalanche Crate"}},
    {18, {550018, "Irresidence Crate"}},
    {19, {550019, "Poseidon Crate"}},
    {20, {550020, "Arcane Jester Crate"}}
};

/// @brief Updates the kill message icon based on the user's selection from the UI.
/// @param FatalDamageParameter A pointer to the damage event parameters.
void updateKillMessageSkin(FFatalDamageParameter* FatalDamageParameter) {
    if (!FatalDamageParameter) return;

    if (selectedSkins.count("Kill Message Effect")) {
        int skinIndex = selectedSkins.at("Kill Message Effect");
        if (killMessageSkins.count(skinIndex)) {
            // This ID overrides the weapon's own kill message effect.
            FatalDamageParameter->CauserWeaponAvatarID = killMessageSkins.at(skinIndex).id;
        }
    }
}

/// @brief Updates the death crate (loot box) skin based on the user's selection from the UI.
/// @param DeadBoxPointer A pointer to the DeadBoxAvatarComponent.
void updateLootBoxSkin(UDeadBoxAvatarComponent* DeadBoxPointer) {
    if (!DeadBoxPointer) return;
    
    if (selectedSkins.count("Death Crate Skin")) {
        int skinIndex = selectedSkins.at("Death Crate Skin");
        if (lootBoxSkins.count(skinIndex)) {
            DeadBoxPointer->ChangeItemAvatar(lootBoxSkins.at(skinIndex).id, true);
        }
    }
}

// ===========================================================================================================
// PROCESS EVENT HOOK FUNCTIONS
// ===========================================================================================================
// These functions are specifically designed to work with the ProcessEvent hook
// and handle the complete weapon skin application for kill messages and loot boxes
// ===========================================================================================================

/// @brief Updates kill message skins based on the current weapon and user selection
/// @param localPlayer The local player character
/// @param Params The fatal damage parameters from the ProcessEvent hook
void updateKillMessageSkins(ASTExtraPlayerCharacter* localPlayer, 
                           ASTExtraPlayerController_BroadcastFatalDamageToClientWithStruct_Params* Params) {
    if (!localPlayer || !Params) return;
    
    auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
    if (!WeaponManagerComponent) return;
    
    auto CurrentWeapon = (ASTExtraShootWeapon*)WeaponManagerComponent->CurrentWeaponReplicated;
    if (!CurrentWeapon) return;
    
    int weaponId = CurrentWeapon->GetWeaponID();
    std::string weaponName = getWeaponNameFromID(std::to_string(weaponId));
    
    // First, check if user has selected a specific kill message effect
    if (selectedSkins.count("Kill Message Effect")) {
        int skinIndex = selectedSkins.at("Kill Message Effect");
        if (killMessageSkins.count(skinIndex)) {
            Params->FatalDamageParameter.CauserWeaponAvatarID = killMessageSkins.at(skinIndex).id;
            return;
        }
    }
    
    // If no specific kill message is selected, apply weapon-specific kill message
    if (selectedSkins.count(weaponName)) {
        int skinIndex = selectedSkins.at(weaponName);
        
        // Check if this weapon has kill message skins
        if (weaponSkins.count(weaponName) && weaponSkins.at(weaponName).count(skinIndex)) {
            int skinId = weaponSkins.at(weaponName).at(skinIndex).id;
            Params->FatalDamageParameter.CauserWeaponAvatarID = skinId;
        }
    }
}

/// @brief Updates loot box skins based on the current weapon and user selection
/// @param localPlayer The local player character
/// @param DeadBoxPointer The dead box avatar component
void updateLootBoxSkins(ASTExtraPlayerCharacter* localPlayer, UDeadBoxAvatarComponent* DeadBoxPointer) {
    if (!localPlayer || !DeadBoxPointer) return;
    
    auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
    if (!WeaponManagerComponent) return;
    
    auto CurrentWeapon = (ASTExtraShootWeapon*)WeaponManagerComponent->CurrentWeaponReplicated;
    if (!CurrentWeapon) return;
    
    int weaponId = CurrentWeapon->GetWeaponID();
    std::string weaponName = getWeaponNameFromID(std::to_string(weaponId));
    
    // First, check if user has selected a specific loot box skin
    if (selectedSkins.count("Death Crate Skin")) {
        int skinIndex = selectedSkins.at("Death Crate Skin");
        if (lootBoxSkins.count(skinIndex)) {
            DeadBoxPointer->ChangeItemAvatar(lootBoxSkins.at(skinIndex).id, true);
            return;
        }
    }
    
    // If no specific loot box skin is selected, apply weapon-specific loot box skin
    if (selectedSkins.count(weaponName)) {
        int skinIndex = selectedSkins.at(weaponName);
        
        // Check if this weapon has loot box skins
        if (weaponSkins.count(weaponName) && weaponSkins.at(weaponName).count(skinIndex)) {
            int skinId = weaponSkins.at(weaponName).at(skinIndex).id;
            DeadBoxPointer->ChangeItemAvatar(skinId, true);
        }
    }
}

// ===========================================================================================================
// MODERN UI SKIN NAME DISPLAY SYSTEM
// ===========================================================================================================
// This system provides skin names for display in the Java UI
// Replaces the old tedious if-else statements with a clean data-driven approach
// ===========================================================================================================

// Skin display information structure
struct SkinDisplayInfo {
    std::string displayName;    // Name shown in UI (e.g., "Glacier M416 (Lv. 7)")
    std::string skinName;       // Base skin name (e.g., "Glacier")
    std::string weaponName;     // Weapon name (e.g., "M416")
    int level;                  // Skin level (e.g., 7)
    std::string rarity;         // Rarity (e.g., "Legendary", "Epic")
    int color;                  // Color code for UI
};

// Modern data-driven skin display mapping
static std::map<std::string, std::map<int, SkinDisplayInfo>> skinDisplayMap = {
    // M416 Skins
    {"M416", {
        {0, {"Default M416", "Default", "M416", 1, "Common", 0x808080}},
        {1, {"Glacier M416 (Lv. 7)", "Glacier", "M416", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool M416 (Lv. 7)", "The Fool", "M416", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer M416 (Lv. 7)", "Wanderer", "M416", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar M416 (Lv. 7)", "Lizard Roar", "M416", 7, "Legendary", 0xFF8000}},
        {5, {"TechnoCore M416 (Lv. 7)", "TechnoCore", "M416", 7, "Legendary", 0xFF8000}},
        {6, {"Call of the Wild M416 (Lv. 7)", "Call of the Wild", "M416", 7, "Legendary", 0xFF8000}},
        {7, {"Hellfire M416 (Lv. 7)", "Hellfire", "M416", 7, "Legendary", 0xFF8000}},
        {8, {"Wandering Tyrant M416 (Lv. 7)", "Wandering Tyrant", "M416", 7, "Legendary", 0xFF8000}},
        {9, {"Jack-o'-lantern M416 (Lv. 7)", "Jack-o'-lantern", "M416", 7, "Legendary", 0xFF8000}},
        {10, {"Metro Royale M416 (Lv. 7)", "Metro Royale", "M416", 7, "Legendary", 0xFF8000}},
        {11, {"Global M416 (Lv. 7)", "Global", "M416", 7, "Legendary", 0xFF8000}}
    }},
    
    // AKM Skins
    {"AKM", {
        {0, {"Default AKM", "Default", "AKM", 1, "Common", 0x808080}},
        {1, {"Glacier AKM (Lv. 7)", "Glacier", "AKM", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool AKM (Lv. 7)", "The Fool", "AKM", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer AKM (Lv. 7)", "Wanderer", "AKM", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar AKM (Lv. 7)", "Lizard Roar", "AKM", 7, "Legendary", 0xFF8000}},
        {5, {"TechnoCore AKM (Lv. 7)", "TechnoCore", "AKM", 7, "Legendary", 0xFF8000}},
        {6, {"Call of the Wild AKM (Lv. 7)", "Call of the Wild", "AKM", 7, "Legendary", 0xFF8000}},
        {7, {"Hellfire AKM (Lv. 7)", "Hellfire", "AKM", 7, "Legendary", 0xFF8000}},
        {8, {"Wandering Tyrant AKM (Lv. 7)", "Wandering Tyrant", "AKM", 7, "Legendary", 0xFF8000}},
        {9, {"Jack-o'-lantern AKM (Lv. 7)", "Jack-o'-lantern", "AKM", 7, "Legendary", 0xFF8000}},
        {10, {"Metro Royale AKM (Lv. 7)", "Metro Royale", "AKM", 7, "Legendary", 0xFF8000}}
    }},
    
    // SCAR-L Skins
    {"SCAR-L", {
        {0, {"Default SCAR-L", "Default", "SCAR-L", 1, "Common", 0x808080}},
        {1, {"Glacier SCAR-L (Lv. 7)", "Glacier", "SCAR-L", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool SCAR-L (Lv. 7)", "The Fool", "SCAR-L", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer SCAR-L (Lv. 7)", "Wanderer", "SCAR-L", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar SCAR-L (Lv. 7)", "Lizard Roar", "SCAR-L", 7, "Legendary", 0xFF8000}},
        {5, {"TechnoCore SCAR-L (Lv. 7)", "TechnoCore", "SCAR-L", 7, "Legendary", 0xFF8000}},
        {6, {"Call of the Wild SCAR-L (Lv. 7)", "Call of the Wild", "SCAR-L", 7, "Legendary", 0xFF8000}},
        {7, {"Hellfire SCAR-L (Lv. 7)", "Hellfire", "SCAR-L", 7, "Legendary", 0xFF8000}}
    }},
    
    // M762 Skins
    {"M762", {
        {0, {"Default M762", "Default", "M762", 1, "Common", 0x808080}},
        {1, {"Glacier M762 (Lv. 7)", "Glacier", "M762", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool M762 (Lv. 7)", "The Fool", "M762", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer M762 (Lv. 7)", "Wanderer", "M762", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar M762 (Lv. 7)", "Lizard Roar", "M762", 7, "Legendary", 0xFF8000}},
        {5, {"TechnoCore M762 (Lv. 7)", "TechnoCore", "M762", 7, "Legendary", 0xFF8000}},
        {6, {"Call of the Wild M762 (Lv. 7)", "Call of the Wild", "M762", 7, "Legendary", 0xFF8000}},
        {7, {"Hellfire M762 (Lv. 7)", "Hellfire", "M762", 7, "Legendary", 0xFF8000}},
        {8, {"Wandering Tyrant M762 (Lv. 7)", "Wandering Tyrant", "M762", 7, "Legendary", 0xFF8000}},
        {9, {"Jack-o'-lantern M762 (Lv. 7)", "Jack-o'-lantern", "M762", 7, "Legendary", 0xFF8000}}
    }},
    
    // M16A4 Skins
    {"M16A4", {
        {0, {"Default M16A4", "Default", "M16A4", 1, "Common", 0x808080}},
        {1, {"Glacier M16A4 (Lv. 7)", "Glacier", "M16A4", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool M16A4 (Lv. 7)", "The Fool", "M16A4", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer M16A4 (Lv. 7)", "Wanderer", "M16A4", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar M16A4 (Lv. 7)", "Lizard Roar", "M16A4", 7, "Legendary", 0xFF8000}},
        {5, {"TechnoCore M16A4 (Lv. 7)", "TechnoCore", "M16A4", 7, "Legendary", 0xFF8000}}
    }},
    
    // GROZA Skins
    {"GROZA", {
        {0, {"Default GROZA", "Default", "GROZA", 1, "Common", 0x808080}},
        {1, {"Glacier GROZA (Lv. 7)", "Glacier", "GROZA", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool GROZA (Lv. 7)", "The Fool", "GROZA", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer GROZA (Lv. 7)", "Wanderer", "GROZA", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar GROZA (Lv. 7)", "Lizard Roar", "GROZA", 7, "Legendary", 0xFF8000}},
        {5, {"TechnoCore GROZA (Lv. 7)", "TechnoCore", "GROZA", 7, "Legendary", 0xFF8000}},
        {6, {"Call of the Wild GROZA (Lv. 7)", "Call of the Wild", "GROZA", 7, "Legendary", 0xFF8000}},
        {7, {"Hellfire GROZA (Lv. 7)", "Hellfire", "GROZA", 7, "Legendary", 0xFF8000}}
    }},
    
    // AUG Skins
    {"AUG", {
        {0, {"Default AUG", "Default", "AUG", 1, "Common", 0x808080}},
        {1, {"Glacier AUG (Lv. 7)", "Glacier", "AUG", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool AUG (Lv. 7)", "The Fool", "AUG", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer AUG (Lv. 7)", "Wanderer", "AUG", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar AUG (Lv. 7)", "Lizard Roar", "AUG", 7, "Legendary", 0xFF8000}},
        {5, {"TechnoCore AUG (Lv. 7)", "TechnoCore", "AUG", 7, "Legendary", 0xFF8000}}
    }},
    
    // ACE32 Skins
    {"ACE32", {
        {0, {"Default ACE32", "Default", "ACE32", 1, "Common", 0x808080}},
        {1, {"Glacier ACE32 (Lv. 7)", "Glacier", "ACE32", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool ACE32 (Lv. 7)", "The Fool", "ACE32", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer ACE32 (Lv. 7)", "Wanderer", "ACE32", 7, "Legendary", 0xFF8000}}
    }},
    
    // M249 Skins
    {"M249", {
        {0, {"Default M249", "Default", "M249", 1, "Common", 0x808080}},
        {1, {"Glacier M249 (Lv. 7)", "Glacier", "M249", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool M249 (Lv. 7)", "The Fool", "M249", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer M249 (Lv. 7)", "Wanderer", "M249", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar M249 (Lv. 7)", "Lizard Roar", "M249", 7, "Legendary", 0xFF8000}}
    }},
    
    // DP28 Skins
    {"DP28", {
        {0, {"Default DP28", "Default", "DP28", 1, "Common", 0x808080}},
        {1, {"Glacier DP28 (Lv. 7)", "Glacier", "DP28", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool DP28 (Lv. 7)", "The Fool", "DP28", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer DP28 (Lv. 7)", "Wanderer", "DP28", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar DP28 (Lv. 7)", "Lizard Roar", "DP28", 7, "Legendary", 0xFF8000}}
    }},
    
    // MG3 Skins
    {"MG3", {
        {0, {"Default MG3", "Default", "MG3", 1, "Common", 0x808080}},
        {1, {"Glacier MG3 (Lv. 7)", "Glacier", "MG3", 7, "Legendary", 0xFF8000}}
    }},
    
    // UZI Skins
    {"UZI", {
        {0, {"Default UZI", "Default", "UZI", 1, "Common", 0x808080}},
        {1, {"Glacier UZI (Lv. 7)", "Glacier", "UZI", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool UZI (Lv. 7)", "The Fool", "UZI", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer UZI (Lv. 7)", "Wanderer", "UZI", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar UZI (Lv. 7)", "Lizard Roar", "UZI", 7, "Legendary", 0xFF8000}},
        {5, {"TechnoCore UZI (Lv. 7)", "TechnoCore", "UZI", 7, "Legendary", 0xFF8000}},
        {6, {"Call of the Wild UZI (Lv. 7)", "Call of the Wild", "UZI", 7, "Legendary", 0xFF8000}}
    }},
    
    // UMP45 Skins
    {"UMP45", {
        {0, {"Default UMP45", "Default", "UMP45", 1, "Common", 0x808080}},
        {1, {"Glacier UMP45 (Lv. 7)", "Glacier", "UMP45", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool UMP45 (Lv. 7)", "The Fool", "UMP45", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer UMP45 (Lv. 7)", "Wanderer", "UMP45", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar UMP45 (Lv. 7)", "Lizard Roar", "UMP45", 7, "Legendary", 0xFF8000}},
        {5, {"TechnoCore UMP45 (Lv. 7)", "TechnoCore", "UMP45", 7, "Legendary", 0xFF8000}},
        {6, {"Call of the Wild UMP45 (Lv. 7)", "Call of the Wild", "UMP45", 7, "Legendary", 0xFF8000}},
        {7, {"Hellfire UMP45 (Lv. 7)", "Hellfire", "UMP45", 7, "Legendary", 0xFF8000}},
        {8, {"Wandering Tyrant UMP45 (Lv. 7)", "Wandering Tyrant", "UMP45", 7, "Legendary", 0xFF8000}}
    }},
    
    // VECTOR Skins
    {"VECTOR", {
        {0, {"Default VECTOR", "Default", "VECTOR", 1, "Common", 0x808080}},
        {1, {"Glacier VECTOR (Lv. 7)", "Glacier", "VECTOR", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool VECTOR (Lv. 7)", "The Fool", "VECTOR", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer VECTOR (Lv. 7)", "Wanderer", "VECTOR", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar VECTOR (Lv. 7)", "Lizard Roar", "VECTOR", 7, "Legendary", 0xFF8000}}
    }},
    
    // THOMPSON Skins
    {"THOMPSON", {
        {0, {"Default THOMPSON", "Default", "THOMPSON", 1, "Common", 0x808080}},
        {1, {"Glacier THOMPSON (Lv. 7)", "Glacier", "THOMPSON", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool THOMPSON (Lv. 7)", "The Fool", "THOMPSON", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer THOMPSON (Lv. 7)", "Wanderer", "THOMPSON", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar THOMPSON (Lv. 7)", "Lizard Roar", "THOMPSON", 7, "Legendary", 0xFF8000}}
    }},
    
    // M24 Skins
    {"M24", {
        {0, {"Default M24", "Default", "M24", 1, "Common", 0x808080}},
        {1, {"Glacier M24 (Lv. 7)", "Glacier", "M24", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool M24 (Lv. 7)", "The Fool", "M24", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer M24 (Lv. 7)", "Wanderer", "M24", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar M24 (Lv. 7)", "Lizard Roar", "M24", 7, "Legendary", 0xFF8000}},
        {5, {"TechnoCore M24 (Lv. 7)", "TechnoCore", "M24", 7, "Legendary", 0xFF8000}}
    }},
    
    // KAR98K Skins
    {"KAR98K", {
        {0, {"Default KAR98K", "Default", "KAR98K", 1, "Common", 0x808080}},
        {1, {"Glacier KAR98K (Lv. 7)", "Glacier", "KAR98K", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool KAR98K (Lv. 7)", "The Fool", "KAR98K", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer KAR98K (Lv. 7)", "Wanderer", "KAR98K", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar KAR98K (Lv. 7)", "Lizard Roar", "KAR98K", 7, "Legendary", 0xFF8000}},
        {5, {"TechnoCore KAR98K (Lv. 7)", "TechnoCore", "KAR98K", 7, "Legendary", 0xFF8000}},
        {6, {"Call of the Wild KAR98K (Lv. 7)", "Call of the Wild", "KAR98K", 7, "Legendary", 0xFF8000}}
    }},
    
    // AWM Skins
    {"AWM", {
        {0, {"Default AWM", "Default", "AWM", 1, "Common", 0x808080}},
        {1, {"Glacier AWM (Lv. 7)", "Glacier", "AWM", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool AWM (Lv. 7)", "The Fool", "AWM", 7, "Legendary", 0xFF8000}},
        {3, {"Wanderer AWM (Lv. 7)", "Wanderer", "AWM", 7, "Legendary", 0xFF8000}},
        {4, {"Lizard Roar AWM (Lv. 7)", "Lizard Roar", "AWM", 7, "Legendary", 0xFF8000}},
        {5, {"TechnoCore AWM (Lv. 7)", "TechnoCore", "AWM", 7, "Legendary", 0xFF8000}},
        {6, {"Call of the Wild AWM (Lv. 7)", "Call of the Wild", "AWM", 7, "Legendary", 0xFF8000}},
        {7, {"Hellfire AWM (Lv. 7)", "Hellfire", "AWM", 7, "Legendary", 0xFF8000}}
    }},
    
    // AMR Skins
    {"AMR", {
        {0, {"Default AMR", "Default", "AMR", 1, "Common", 0x808080}},
        {1, {"Glacier AMR (Lv. 7)", "Glacier", "AMR", 7, "Legendary", 0xFF8000}}
    }},
    
    // MK14 Skins
    {"MK14", {
        {0, {"Default MK14", "Default", "MK14", 1, "Common", 0x808080}},
        {1, {"Glacier MK14 (Lv. 7)", "Glacier", "MK14", 7, "Legendary", 0xFF8000}},
        {2, {"The Fool MK14 (Lv. 7)", "The Fool", "MK14", 7, "Legendary", 0xFF8000}}
    }}
};

// ===========================================================================================================
// MODERN UI FUNCTIONS
// ===========================================================================================================

/// @brief Get skin display name for UI
/// @param weaponName The weapon name (e.g., "M416")
/// @param skinIndex The skin index (0, 1, 2, etc.)
/// @return The display name (e.g., "Glacier M416 (Lv. 7)")
std::string getSkinDisplayName(const std::string& weaponName, int skinIndex) {
    if (skinDisplayMap.count(weaponName) && skinDisplayMap.at(weaponName).count(skinIndex)) {
        return skinDisplayMap.at(weaponName).at(skinIndex).displayName;
    }
    return "Default " + weaponName;
}

/// @brief Get skin name only (without weapon name)
/// @param weaponName The weapon name (e.g., "M416")
/// @param skinIndex The skin index (0, 1, 2, etc.)
/// @return The skin name (e.g., "Glacier")
std::string getSkinName(const std::string& weaponName, int skinIndex) {
    if (skinDisplayMap.count(weaponName) && skinDisplayMap.at(weaponName).count(skinIndex)) {
        return skinDisplayMap.at(weaponName).at(skinIndex).skinName;
    }
    return "Default";
}

/// @brief Get skin level
/// @param weaponName The weapon name (e.g., "M416")
/// @param skinIndex The skin index (0, 1, 2, etc.)
/// @return The skin level (e.g., 7)
int getSkinLevel(const std::string& weaponName, int skinIndex) {
    if (skinDisplayMap.count(weaponName) && skinDisplayMap.at(weaponName).count(skinIndex)) {
        return skinDisplayMap.at(weaponName).at(skinIndex).level;
    }
    return 1;
}

/// @brief Get skin rarity
/// @param weaponName The weapon name (e.g., "M416")
/// @param skinIndex The skin index (0, 1, 2, etc.)
/// @return The skin rarity (e.g., "Legendary")
std::string getSkinRarity(const std::string& weaponName, int skinIndex) {
    if (skinDisplayMap.count(weaponName) && skinDisplayMap.at(weaponName).count(skinIndex)) {
        return skinDisplayMap.at(weaponName).at(skinIndex).rarity;
    }
    return "Common";
}

/// @brief Get skin color for UI
/// @param weaponName The weapon name (e.g., "M416")
/// @param skinIndex The skin index (0, 1, 2, etc.)
/// @return The color code for UI
int getSkinColor(const std::string& weaponName, int skinIndex) {
    if (skinDisplayMap.count(weaponName) && skinDisplayMap.at(weaponName).count(skinIndex)) {
        return skinDisplayMap.at(weaponName).at(skinIndex).color;
    }
    return 0x808080; // Default gray
}

/// @brief Get all available skin names for a weapon
/// @param weaponName The weapon name (e.g., "M416")
/// @return Vector of skin display names
std::vector<std::string> getAvailableSkinNames(const std::string& weaponName) {
    std::vector<std::string> names;
    if (skinDisplayMap.count(weaponName)) {
        for (const auto& pair : skinDisplayMap.at(weaponName)) {
            names.push_back(pair.second.displayName);
        }
    }
    return names;
}

/// @brief Get current active skin display name based on Config
/// @param weaponName The weapon name (e.g., "M416")
/// @return The current active skin display name
std::string getCurrentActiveSkinName(const std::string& weaponName) {
    std::string configKey = "SKIN_" + weaponName;
    int skinIndex = Config[configKey];
    return getSkinDisplayName(weaponName, skinIndex);
}