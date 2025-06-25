#pragma once

#include <map>
#include <string>
#include <vector>

// ===================================================================================================
// SKIN SYSTEM COMPATIBILITY LAYER
// ===================================================================================================
// This file provides compatibility functions for the skin system without
// conflicting with existing global variables in other header files
// ===================================================================================================

// Use extern declarations to reference existing variables from other files
extern std::map<std::string, int> selectedSkins;

// Helper functions for compatibility
std::string getCategoryName(int categoryId) {
    switch(categoryId) {
        case 1: return "Assault Rifles";
        case 2: return "SMGs";
        case 3: return "Sniper Rifles";
        case 4: return "Shotguns";
        case 5: return "LMGs";
        case 6: return "Pistols";
        case 7: return "Melee";
        default: return "Unknown";
    }
}

// getWeaponNameFromID is already defined in JOIN_SKIN.h, so we don't redefine it here

// Initialize the skin system - simplified version
void initializeSkinSystem() {
    // Basic initialization - just create an empty map for selected skins
    // The actual skin data is handled by the existing header files
}

// Dummy property setting function for compatibility
void set_int_property(void* obj, const char* property, int value) {
    // This is a placeholder function - actual implementation would
    // interface with the game's property system
} 