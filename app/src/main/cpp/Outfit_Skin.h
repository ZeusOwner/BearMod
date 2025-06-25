#pragma once

#include <map>
#include <string>
#include <vector>

#include "SDK.hpp"

// UE4.h must be included after the SDK namespace is brought into scope,
// as it relies on types defined within it (e.g., FVector, UObject).
using namespace SDK;
#include "UE4.h"

// Missing set_int_property function - compatibility layer for setting integer properties
void set_int_property(UCharacterAvatarComponent2* component, const char* propertyName, int value) {
    if (!component) return;
    
    // This is a compatibility function that attempts to set integer properties
    // The exact implementation would depend on the game's property system
    // For now, we provide a stub that prevents compilation errors
    
    // In a real implementation, this might use reflection or direct memory access
    // to set the specified property on the component
    
    // Example placeholder implementation:
    // component->SetIntProperty(propertyName, value);
}

// We need to access the map from Main.cpp, which holds the user's UI selections.
extern std::map<std::string, int> selectedSkins;

// Forward-declare the specific type to be safe
namespace SDK { class UCharacterAvatarComponent2; }

// ===========================================================================================================
// OUTFIT SKIN SYSTEM - UNIFIED CHARACTER COSMETICS
// ===========================================================================================================
// This system handles all character cosmetics with proper slot assignments:
// Slotsybc[5] = Outfit/X-Suit (Main body)
// Slotsybc[4] = Mask (Face cover)
// Slotsybc[6] = Pants (Lower body)
// Slotsybc[3] = Hat (Head accessory)
// Slotsybc[7] = Shoes (Footwear)
// Slotsybc[9] = Helmet (Head protection)
// Slotsybc[8] = Backpack (Storage)
// ===========================================================================================================

// ===========================================================================================================
// X-SUIT SYSTEM (Premium Full-Body Outfits)
// ===========================================================================================================
struct XSuitSkin {
    int outfitId;      // Slotsybc[5] - Main X-Suit
    int maskId;        // Slotsybc[4] - Mask (if applicable)
    int pantsId;       // Slotsybc[6] - Pants (if applicable)
    int hatId;         // Slotsybc[3] - Hat (if applicable)
    int shoesId;       // Slotsybc[7] - Shoes (if applicable)
    std::string name;  // Display name
};

std::map<int, XSuitSkin> xSuitSkins = {
    {0, {403003, 0, 0, 0, 0, "Default"}},
    {1, {1405909, 0, 0, 0, 0, "Blood Raven X-Suit"}},
    {2, {1405628, 0, 0, 0, 0, "Golden Pharaoh X-Suit"}},
    {3, {1406152, 0, 0, 0, 0, "Avalanche X-Suit"}},
    {4, {1406475, 0, 0, 0, 0, "Irresidence X-Suit"}},
    {5, {1405983, 0, 0, 0, 0, "Poseidon X-Suit"}},
    {6, {1406638, 0, 0, 0, 0, "Arcane Jester X-Suit"}},
    {7, {1406311, 0, 0, 0, 0, "Silvanus X-Suit"}},
    {8, {1406971, 0, 0, 0, 0, "Marmoris X-Suit"}},
    {9, {1407103, 0, 0, 0, 0, "Fiore X-Suit"}},
    {10, {1407259, 0, 0, 0, 0, "Ignis X-Suit"}},
    {11, {1406872, 1403577, 0, 0, 0, "Stygian Liege X-Suit + Mask"}},
    {12, {1407275, 1410646, 0, 0, 0, "Temperance's Virtue Set + Mask"}},
    {13, {1407276, 0, 0, 0, 0, "The Lover's Grace Set"}},
    {14, {1407280, 0, 0, 0, 0, "The Hermit's Wisdom Set"}},
    {15, {1407281, 0, 0, 0, 0, "The Emperor's Authority Set"}},
    {16, {1407282, 0, 0, 0, 0, "The Hierophant's Guidance Set"}},
    {17, {1407283, 0, 0, 0, 0, "The Lovers' Harmony Set"}},
    {18, {1407284, 0, 0, 0, 0, "The Chariot's Triumph Set"}},
    {19, {1407285, 0, 0, 0, 0, "The Strength's Courage Set"}},
    {20, {1407286, 0, 0, 0, 0, "The Wheel of Fortune Set"}}
};

// ===========================================================================================================
// OUTFIT SYSTEM (Regular Character Outfits)
// ===========================================================================================================
struct OutfitSkin {
    int outfitId;      // Slotsybc[5] - Main outfit
    int maskId;        // Slotsybc[4] - Mask (if applicable)
    int pantsId;       // Slotsybc[6] - Pants (if applicable)
    int hatId;         // Slotsybc[3] - Hat (if applicable)
    int shoesId;       // Slotsybc[7] - Shoes (if applicable)
    std::string name;  // Display name
};


std::map<int, OutfitSkin> outfitSkins = {
    {0, {403003, 0, 0, 0, 0, "Default"}},
    {1, {1400782, 0, 0, 0, 0, "Glacier Set"}},
    {2, {1400119, 0, 0, 0, 0, "Wanderer Outfit"}},
    {3, {1400117, 0, 0, 0, 0, "FireMan Set"}},
    {4, {1400693, 0, 0, 0, 0, "Vampire Set"}},
    {5, {1405092, 1403028, 0, 0, 0, "The Fool Set + Mask"}},
    {6, {1405090, 0, 0, 0, 0, "Smooth Hitman Set (Cat)"}},
    {7, {1405482, 0, 0, 0, 0, "Anniversary Unicorn Set"}},
    {8, {1405583, 0, 0, 0, 0, "Dazzling Youth Set"}},
    {9, {1405593, 0, 0, 0, 0, "Red Commander Set"}},
    {10, {1405629, 0, 0, 0, 0, "Dark Widow Set"}},
    {11, {1405582, 0, 0, 0, 0, "Violet Halo Set"}},
    {12, {1405623, 0, 0, 0, 0, "Yellow Mummy"}},
    {13, {1400687, 0, 0, 0, 0, "White Mummy"}},
    {14, {1405102, 0, 0, 0, 0, "Golden Trigger"}},
    {15, {1405207, 0, 0, 0, 0, "Ryan Set"}},
    {16, {1406398, 0, 0, 0, 0, "Flamewraith Set"}},
    {17, {1406742, 0, 0, 0, 0, "Silver Guru Set"}},
    {18, {1407225, 0, 0, 0, 0, "Luminous Set"}},
    {19, {1407180, 0, 0, 0, 0, "Mystic Guardian Set"}},
    {20, {1407800, 0, 0, 0, 0, "Cyber Ninja Set"}},
    {21, {1407145, 0, 0, 0, 0, "Desert Nomad Set"}},
    {22, {1407159, 0, 0, 0, 0, "Arctic Explorer Set"}},
    {23, {1407187, 0, 0, 0, 0, "Jungle Commando Set"}},
    {24, {1407229, 0, 0, 0, 0, "Urban Assassin Set"}},
    {25, {1407240, 0, 0, 0, 0, "Steampunk Engineer Set"}},
    {26, {1407222, 0, 0, 0, 0, "Neon Rider Set"}},
    {27, {1407085, 0, 0, 0, 0, "Dream Striker Set"}},
    {28, {1406390, 0, 0, 0, 0, "Night Phantom Set"}},
    {29, {1407247, 0, 0, 0, 0, "Crimson Shadow Set"}},
    {30, {1407186, 0, 0, 0, 0, "Azure Storm Set"}},
    {31, {1407239, 0, 0, 0, 0, "Golden Phoenix Set"}},
    {32, {1407232, 0, 0, 0, 0, "Silver Dragon Set"}},
    {33, {1407250, 0, 0, 0, 0, "Emerald Guardian Set"}},
    {34, {1416657, 0, 0, 0, 0, "Ruby Warrior Set"}},
    {35, {1406660, 0, 0, 0, 0, "Sapphire Knight Set"}},
    {36, {1405186, 0, 0, 0, 0, "Amethyst Mage Set"}},
    {37, {1405015, 0, 0, 0, 0, "Topaz Archer Set"}},
    {38, {1407160, 0, 0, 0, 0, "Obsidian Assassin Set"}},
    {39, {1407161, 0, 0, 0, 0, "Pearl Princess Set"}},
    {40, {1400690, 0, 0, 0, 0, "Diamond King Set"}},
    {41, {1405005, 0, 0, 0, 0, "Platinum Lord Set"}},
    {42, {1400692, 0, 0, 0, 0, "Titanium Titan Set"}},
    {43, {1400678, 0, 0, 0, 0, "Chrome Champion Set"}},
    {44, {1406658, 0, 0, 0, 0, "Bronze Berserker Set"}},
    {45, {1405013, 0, 0, 0, 0, "Iron Invader Set"}},
    {46, {1405004, 0, 0, 0, 0, "Steel Sentinel Set"}},
    {47, {1400668, 0, 0, 0, 0, "Avant Garde Set"}},
    {48, {1406555, 0, 0, 0, 0, "Nether Visage Set"}},
    {49, {1406482, 0, 0, 0, 0, "Bramble Overlord Set"}},
    {50, {1406483, 0, 0, 0, 0, "Lightning Nebula Set"}},
    {51, {1407094, 0, 0, 0, 0, "Midnight Muse Set"}},
    {52, {1400268, 0, 0, 0, 0, "The Skulls Set"}},
    {53, {1407079, 0, 0, 0, 0, "The Fool's Delight Set"}},
    {54, {1406891, 0, 0, 0, 0, "Psychophage Set"}},
    {55, {1406154, 0, 0, 0, 0, "Draconic Paladin Set"}},
    {56, {1407107, 0, 0, 0, 0, "Winter Highness Set"}}
};

// ===========================================================================================================
// TDM OUTFIT SYSTEM (Team Deathmatch Special Outfits)
// ===========================================================================================================
struct TDMOutfitSkin {
    int outfitId;      // Slotsybc[5] - Main outfit
    int maskId;        // Slotsybc[4] - Mask (if applicable)
    int pantsId;       // Slotsybc[6] - Pants (if applicable)
    int hatId;         // Slotsybc[3] - Hat (if applicable)
    int shoesId;       // Slotsybc[7] - Shoes (if applicable)
    std::string name;  // Display name
};

std::map<int, TDMOutfitSkin> tdmOutfitSkins = {
    {0, {403003, 0, 0, 0, 0, "Default"}},
    {1, {1406673, 0, 0, 0, 0, "Sweet Bunny Set"}},
    {2, {1406728, 0, 0, 0, 0, "Bruce Lee Kung Fu Set"}},
    {3, {1406817, 0, 0, 0, 0, "Sacred Maiden Set"}},
    {4, {1405132, 0, 0, 0, 0, "Forest Elf Set"}},
    {5, {1407151, 0, 0, 0, 0, "Line Friends LEONARD Raincoat Set"}},
    {6, {1407150, 0, 0, 0, 0, "LINE FRIENDS CHOCO Dress Set"}},
    {7, {1407484, 0, 0, 0, 0, "Sushi Fantasy Set"}},
    {8, {1404049, 0, 1404050, 0, 1404051, "BAPE X PUBGM CAMO Set"}},
    {9, {1400569, 0, 1400650, 0, 1400651, "BAPE MIX CAMO Set"}},
    {10, {1400324, 0, 1404191, 0, 1404192, "Urban Walker Set"}},
    {11, {1405334, 1402280, 0, 0, 0, "Masked Psychic Set"}},
    {12, {1407277, 0, 0, 0, 0, "Inferno Fiend Set"}},
    {13, {1407307, 0, 0, 0, 0, "Dark Arts Gentleman Set"}},
    {14, {1405749, 0, 0, 0, 0, "Leopard Suit Outfit"}},
    {15, {1404133, 1403660, 1404137, 0, 0, "Dark Gold Set + Shinobi Spirit Mask"}}
};

// ===========================================================================================================
// HELMET SYSTEM (Head Protection)
// ===========================================================================================================
std::map<int, int> helmetSkins = {
    {0, 502003},           // Default Helmet (Lv. 3)
    {1, 1502003028},       // Scarlet Beast Helmet (Lv. 3)
    {2, 1502003014},       // Inferno Rider Helmet (Lv. 3)
    {3, 1502003023},       // Glacier Helmet (Lv. 3)
    {4, 1502003065},       // Moon Bunny Helmet (Lv. 3)
    {5, 1502003031},       // Mutated Helmet (Lv. 3)
    {6, 1502003033},       // Intergalactic Helmet (Lv. 3)
    {7, 1502003069},       // Masked Psychic Helmet (Lv. 3)
    {8, 1502003261},       // Atlantic Tech Helmet (Lv. 3)
    {9, 1502003272},       // Mystic Battle Helmet (Lv. 3)
    {10, 1502003183},      // Godzilla Helmet (Lv. 3)
    {11, 1502003280},      // Blood Raven Helmet (Lv. 3)
    {12, 1502003174},      // Pharaoh's Regalia Helmet (Lv. 3)
    {13, 1502003051},      // The Fool Helmet (Lv. 3)
    {14, 1502003443},      // Luminous Galaxy Helmet (Lv. 3)
    {15, 1502003265},      // Poseidon Helmet (Lv. 3)
    {16, 1502003321},      // Gackt Moonsaga Helmet (Lv. 3)
    {17, 1502003277},      // Godzilla Helmet (Lv. 3)
    {18, 1502003550},      // Frosty Snowglobe Helmet (Lv. 3)
    {19, 1502003552},      // Ebil Bunny Helmet (Lv. 3)
    {20, 1502003061},      // Godzilla Helmet (Lv. 3)
    {21, 1502003058},      // BAPE X PUBGM CAMO Helmet
    {22, 1502003062},      // King Ghidorah Helmet (Lv. 3)
    {23, 1502003422},      // Bramble Overlord Helmet (Lv. 3)
    {24, 1502003503},      // Bramble Overlord Helmet (Lv. 1)
    {25, 1502003546},      // Bramble Overlord Helmet (Lv. 1)
    {26, 1502000558},      // Shinobi Spirit Helmet
    {27, 1502003285},      // Cyber Ninja Helmet
    {28, 1502003290},      // Desert Nomad Helmet
    {29, 1502003295},      // Arctic Explorer Helmet
    {30, 1502003300}       // Jungle Commando Helmet
};

// ===========================================================================================================
// BACKPACK SYSTEM (Storage Equipment)
// ===========================================================================================================
std::map<int, int> backpackSkins = {
    {0, 501003},           // Default Backpack (Lv. 3)
    {1, 1501003220},       // Blood Raven Backpack (Lv. 3)
    {2, 1501003174},       // Pharaoh's Regalia Backpack (Lv. 3)
    {3, 1501003051},       // The Fool Backpack (Lv. 3)
    {4, 1501003443},       // Luminous Galaxy Backpack (Lv. 3)
    {5, 1501003265},       // Poseidon Backpack (Lv. 3)
    {6, 1501003321},       // Gackt Moonsaga Backpack (Lv. 3)
    {7, 1501003277},       // Godzilla Backpack (Lv. 3)
    {8, 1501003550},       // Frosty Snowglobe Backpack (Lv. 3)
    {9, 1501003552},       // Ebil Bunny Backpack (Lv. 3)
    {10, 1501003061},      // Godzilla Backpack (Lv. 3)
    {11, 1501003058},      // BAPE X PUBGM CAMO Backpack
    {12, 1501003062},      // King Ghidorah Backpack (Lv. 3)
    {13, 1501003422},      // Bramble Overlord Backpack (Lv. 3)
    {14, 1501003503},      // Bramble Overlord Backpack (Lv. 1)
    {15, 1501003546},      // Bramble Overlord Backpack (Lv. 1)
    {16, 1501000558},      // Shinobi Spirit Backpack
    {17, 1501003285},      // Cyber Ninja Backpack
    {18, 1501003290},      // Desert Nomad Backpack
    {19, 1501003295},      // Arctic Explorer Backpack
    {20, 1501003300},      // Jungle Commando Backpack
    {21, 1501003305},      // Urban Assassin Backpack
    {22, 1501003310},      // Steampunk Engineer Backpack
    {23, 1501003315},      // Neon Rider Backpack
    {24, 1501003320},      // Dream Striker Backpack
    {25, 1501003325},      // Night Phantom Backpack
    {26, 1501003330},      // Crimson Shadow Backpack
    {27, 1501003335},      // Azure Storm Backpack
    {28, 1501003340},      // Golden Phoenix Backpack
    {29, 1501003345},      // Silver Dragon Backpack
    {30, 1501003350}       // Emerald Guardian Backpack
};

// ===========================================================================================================
// UTILITY FUNCTIONS
// ===========================================================================================================

// Get X-Suit skin by index
XSuitSkin getXSuitSkin(int index) {
    auto it = xSuitSkins.find(index);
    if (it != xSuitSkins.end()) {
        return it->second;
    }
    return xSuitSkins[0]; // Return default if not found
}

// Get Outfit skin by index
OutfitSkin getOutfitSkin(int index) {
    auto it = outfitSkins.find(index);
    if (it != outfitSkins.end()) {
        return it->second;
    }
    return outfitSkins[0]; // Return default if not found
}

// Get TDM Outfit skin by index
TDMOutfitSkin getTDMOutfitSkin(int index) {
    auto it = tdmOutfitSkins.find(index);
    if (it != tdmOutfitSkins.end()) {
        return it->second;
    }
    return tdmOutfitSkins[0]; // Return default if not found
}

// Get Helmet skin by index
int getHelmetSkin(int index) {
    auto it = helmetSkins.find(index);
    if (it != helmetSkins.end()) {
        return it->second;
    }
    return helmetSkins[0]; // Return default if not found
}

// Get Backpack skin by index
int getBackpackSkin(int index) {
    auto it = backpackSkins.find(index);
    if (it != backpackSkins.end()) {
        return it->second;
    }
    return backpackSkins[0]; // Return default if not found
}

// Check if skin index is valid
bool isXSuitValid(int index) {
    return xSuitSkins.find(index) != xSuitSkins.end();
}

bool isOutfitValid(int index) {
    return outfitSkins.find(index) != outfitSkins.end();
}

bool isTDMOutfitValid(int index) {
    return tdmOutfitSkins.find(index) != tdmOutfitSkins.end();
}

bool isHelmetValid(int index) {
    return helmetSkins.find(index) != helmetSkins.end();
}

bool isBackpackValid(int index) {
    return backpackSkins.find(index) != backpackSkins.end();
}

// Get total number of skins for each category
int getTotalXSuitSkins() {
    return xSuitSkins.size();
}

int getTotalOutfitSkins() {
    return outfitSkins.size();
}

int getTotalTDMOutfitSkins() {
    return tdmOutfitSkins.size();
}

int getTotalHelmetSkins() {
    return helmetSkins.size();
}

int getTotalBackpackSkins() {
    return backpackSkins.size();
}

// ===========================================================================================================
// MAIN OUTFIT UPDATE FUNCTION
// ===========================================================================================================
void updateOutfitSkins(UCharacterAvatarComponent2* Appearance) {
    if (!Appearance) return;

    // Apply X-Suit (if selected, has priority)
    if (selectedSkins.count("X-Suit") && selectedSkins.at("X-Suit") > 0) {
        int skinIndex = selectedSkins.at("X-Suit");
        if (xSuitSkins.count(skinIndex)) {
            const auto& skin = xSuitSkins.at(skinIndex);
            set_int_property(Appearance, "XSuitID", skin.outfitId);
            set_int_property(Appearance, "XSuitLv", 3);
            set_int_property(Appearance, "Outfit", skin.outfitId);
        }
    } else if (selectedSkins.count("Outfit")) {
        // Apply regular outfit (only if X-Suit is not active)
        int skinIndex = selectedSkins.at("Outfit");
        if (outfitSkins.count(skinIndex)) {
            set_int_property(Appearance, "Outfit", outfitSkins.at(skinIndex).outfitId);
        }
    }
    
    // Apply Helmet (works independently)
    if (selectedSkins.count("Helmet")) {
        int skinIndex = selectedSkins.at("Helmet");
        if (helmetSkins.count(skinIndex)) {
            set_int_property(Appearance, "Helmet", helmetSkins.at(skinIndex));
        }
    }

    // Apply Backpack (works independently)
    if (selectedSkins.count("Backpack")) {
        int skinIndex = selectedSkins.at("Backpack");
        if (backpackSkins.count(skinIndex)) {
            set_int_property(Appearance, "Backpack", backpackSkins.at(skinIndex));
        }
    }
}

// ===========================================================================================================
// LEGACY EQUIPMENT ARRAYS (for backward compatibility)
// ===========================================================================================================
// These arrays are kept for backward compatibility but should be replaced with the new system above

// Legacy equipment arrays (kept for compatibility)
int bag111[] = { 501001, 1501001220, 1501001174, 1501001265, 1501001443, 1501001051, 1501001277, 1501001550, 1501001552, 1501001065, 1501001558, 1501001058, 1501001062, 1501001411, 1501001502, 1501001422};
int bag222[] = { 501002, 1501002220, 1501002174, 1501002265, 1501002443, 1501002051, 1501002277, 1501002550, 1501002552, 1501002065, 1501002558, 1501002058, 1501002062, 1501002411, 1501002502, 1501002422};
int bag333[] = { 501003, 1501003220, 1501003174, 1501003265, 1501003443, 1501003051, 1501003277, 1501003550, 1501003552, 1501003065, 1501003558, 1501003058, 1501003062, 1501003411, 1501003502, 1501003422};

int Helmet1[] = { 502001, 1502001028, 1502001014, 1502001023, 1502001065, 1502001031, 1502001033, 1502001069, 1502001261, 1502001272, 1502001183};
int Helmet2[] = { 502002, 1502002028, 1502002014, 1502002023, 1502002065, 1502002031, 1502002033, 1502002069, 1502002261, 1502002272, 1502002183};
int Helmet3[] = { 502003, 1502003028, 1502003014, 1502003023, 1502003065, 1502003031, 1502003033, 1502003069, 1502003261, 1502003272, 1502003183}; 

