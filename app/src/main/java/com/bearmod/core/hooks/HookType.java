package com.bearmod.core.hooks;

/**
 * Enumeration of different hook types supported by the BearMod hook system
 * Each type represents a different category of function hooking for specific purposes
 */
public enum HookType {
    /**
     * Standard function hook - basic function interception
     */
    STANDARD(0, "Standard Hook", "Basic function interception"),
    
    /**
     * Signature bypass hook - bypasses signature verification functions
     */
    SIGNATURE_BYPASS(1, "Signature Bypass", "Bypasses signature verification and integrity checks"),
    
    /**
     * Anti-debug bypass hook - bypasses anti-debugging mechanisms
     */
    ANTI_DEBUG_BYPASS(2, "Anti-Debug Bypass", "Bypasses anti-debugging and detection mechanisms"),
    
    /**
     * Memory protection hook - hooks memory-related functions
     */
    MEMORY_PROTECTION(3, "Memory Protection", "Hooks memory allocation and protection functions"),
    
    /**
     * Anti-cheat bypass hook - bypasses anti-cheat detection systems
     */
    ANTI_CHEAT_BYPASS(4, "Anti-Cheat Bypass", "Bypasses anti-cheat and game protection systems"),
    
    /**
     * Network hook - intercepts network-related functions
     */
    NETWORK_HOOK(5, "Network Hook", "Intercepts network communication functions"),
    
    /**
     * File system hook - hooks file system operations
     */
    FILESYSTEM_HOOK(6, "Filesystem Hook", "Hooks file system access and operations"),
    
    /**
     * Encryption bypass hook - bypasses encryption and security functions
     */
    ENCRYPTION_BYPASS(7, "Encryption Bypass", "Bypasses encryption and cryptographic functions"),
    
    /**
     * API hook - hooks Android API functions
     */
    API_HOOK(8, "API Hook", "Hooks Android system API functions"),
    
    /**
     * Custom hook - user-defined hook type
     */
    CUSTOM(9, "Custom Hook", "User-defined custom hook implementation");
    
    private final int value;
    private final String displayName;
    private final String description;
    
    /**
     * Constructor for HookType enum
     * 
     * @param value Numeric value for native code compatibility
     * @param displayName Human-readable name for the hook type
     * @param description Detailed description of the hook type's purpose
     */
    HookType(int value, String displayName, String description) {
        this.value = value;
        this.displayName = displayName;
        this.description = description;
    }
    
    /**
     * Get the numeric value of the hook type
     * Used for compatibility with native code
     * 
     * @return Numeric value
     */
    public int getValue() {
        return value;
    }
    
    /**
     * Get the display name of the hook type
     * 
     * @return Human-readable name
     */
    public String getDisplayName() {
        return displayName;
    }
    
    /**
     * Get the description of the hook type
     * 
     * @return Detailed description
     */
    public String getDescription() {
        return description;
    }
    
    /**
     * Get HookType from numeric value
     * 
     * @param value Numeric value
     * @return Corresponding HookType, or STANDARD if not found
     */
    public static HookType fromValue(int value) {
        for (HookType type : values()) {
            if (type.value == value) {
                return type;
            }
        }
        return STANDARD; // Default fallback
    }
    
    /**
     * Check if this hook type is security-related
     * 
     * @return true if this is a security-related hook type
     */
    public boolean isSecurityHook() {
        return this == SIGNATURE_BYPASS || 
               this == ANTI_DEBUG_BYPASS || 
               this == ANTI_CHEAT_BYPASS || 
               this == ENCRYPTION_BYPASS;
    }
    
    /**
     * Check if this hook type is system-related
     * 
     * @return true if this is a system-related hook type
     */
    public boolean isSystemHook() {
        return this == MEMORY_PROTECTION || 
               this == FILESYSTEM_HOOK || 
               this == API_HOOK || 
               this == NETWORK_HOOK;
    }
    
    /**
     * Get the priority level of this hook type
     * Higher priority hooks are processed first
     * 
     * @return Priority level (0-10, higher is more important)
     */
    public int getPriority() {
        switch (this) {
            case SIGNATURE_BYPASS:
                return 10; // Highest priority
            case ANTI_CHEAT_BYPASS:
                return 9;
            case ANTI_DEBUG_BYPASS:
                return 8;
            case ENCRYPTION_BYPASS:
                return 7;
            case MEMORY_PROTECTION:
                return 6;
            case API_HOOK:
                return 5;
            case NETWORK_HOOK:
                return 4;
            case FILESYSTEM_HOOK:
                return 3;
            case CUSTOM:
                return 2;
            case STANDARD:
            default:
                return 1; // Lowest priority
        }
    }
    
    @Override
    public String toString() {
        return displayName + " (" + value + ")";
    }
}
