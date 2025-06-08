package com.bearmod.core;

import android.util.Log;
import java.util.concurrent.ConcurrentHashMap;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;

/**
 * Java interface for the native MemoryManager
 * Provides memory operations with enhanced security and integration
 */
public class MemoryManager {
    private static final String TAG = "BearMod_MemoryManager";
    
    private static volatile MemoryManager instance;
    private static final Object lock = new Object();
    private volatile boolean initialized = false;
    
    // Cache for module information
    private final Map<String, ModuleInfo> moduleCache = new ConcurrentHashMap<>();
    private final Map<String, Long> patternCache = new ConcurrentHashMap<>();
    
    // Load native library
    static {
        try {
            System.loadLibrary("bearmod");
            Log.d(TAG, "Native library loaded successfully");
        } catch (UnsatisfiedLinkError e) {
            Log.e(TAG, "Failed to load native library", e);
        }
    }
    
    private MemoryManager() {}
    
    /**
     * Get singleton instance
     */
    public static MemoryManager getInstance() {
        if (instance == null) {
            synchronized (lock) {
                if (instance == null) {
                    instance = new MemoryManager();
                }
            }
        }
        return instance;
    }
    
    /**
     * Initialize the memory manager
     */
    public boolean initialize() {
        if (initialized) {
            Log.d(TAG, "MemoryManager already initialized");
            return true;
        }
        
        try {
            boolean nativeInit = nativeInitialize();
            if (nativeInit) {
                initialized = true;
                Log.d(TAG, "MemoryManager initialized successfully");
                
                // Load initial module cache
                refreshModuleCache();
                
                return true;
            } else {
                Log.e(TAG, "Native MemoryManager initialization failed");
                return false;
            }
        } catch (Exception e) {
            Log.e(TAG, "Error initializing MemoryManager", e);
            return false;
        }
    }
    
    /**
     * Read memory from address
     */
    public byte[] readMemory(long address, int size) {
        if (!initialized) {
            Log.e(TAG, "MemoryManager not initialized");
            return null;
        }
        
        if (address == 0 || size <= 0) {
            Log.e(TAG, "Invalid parameters for readMemory");
            return null;
        }
        
        try {
            return nativeReadMemory(address, size);
        } catch (Exception e) {
            Log.e(TAG, "Error reading memory at 0x" + Long.toHexString(address), e);
            return null;
        }
    }
    
    /**
     * Write memory to address
     */
    public boolean writeMemory(long address, byte[] data) {
        if (!initialized) {
            Log.e(TAG, "MemoryManager not initialized");
            return false;
        }
        
        if (address == 0 || data == null || data.length == 0) {
            Log.e(TAG, "Invalid parameters for writeMemory");
            return false;
        }
        
        try {
            return nativeWriteMemory(address, data);
        } catch (Exception e) {
            Log.e(TAG, "Error writing memory at 0x" + Long.toHexString(address), e);
            return false;
        }
    }
    
    /**
     * Find pattern in memory range
     */
    public long findPattern(String pattern, long startAddress, long endAddress) {
        if (!initialized) {
            Log.e(TAG, "MemoryManager not initialized");
            return 0;
        }
        
        if (pattern == null || pattern.isEmpty() || startAddress >= endAddress) {
            Log.e(TAG, "Invalid parameters for findPattern");
            return 0;
        }
        
        try {
            // Check pattern cache first
            String cacheKey = pattern + "_" + startAddress + "_" + endAddress;
            Long cachedResult = patternCache.get(cacheKey);
            if (cachedResult != null) {
                Log.d(TAG, "Pattern found in cache: " + pattern);
                return cachedResult;
            }
            
            long result = nativeFindPattern(pattern, startAddress, endAddress);
            
            // Cache the result if found
            if (result != 0) {
                patternCache.put(cacheKey, result);
                Log.d(TAG, "Pattern found and cached: " + pattern + " at 0x" + Long.toHexString(result));
            }
            
            return result;
            
        } catch (Exception e) {
            Log.e(TAG, "Error finding pattern: " + pattern, e);
            return 0;
        }
    }
    
    /**
     * Find pattern in specific module
     */
    public long findPatternInModule(String pattern, String moduleName) {
        if (!initialized) {
            Log.e(TAG, "MemoryManager not initialized");
            return 0;
        }
        
        if (pattern == null || pattern.isEmpty() || moduleName == null || moduleName.isEmpty()) {
            Log.e(TAG, "Invalid parameters for findPatternInModule");
            return 0;
        }
        
        try {
            // Check module cache
            ModuleInfo moduleInfo = getModuleInfo(moduleName);
            if (moduleInfo == null) {
                Log.w(TAG, "Module not found: " + moduleName);
                return 0;
            }
            
            // Use cached module information for faster search
            return findPattern(pattern, moduleInfo.baseAddress, moduleInfo.baseAddress + moduleInfo.size);
            
        } catch (Exception e) {
            Log.e(TAG, "Error finding pattern in module: " + moduleName, e);
            return 0;
        }
    }
    
    /**
     * Get module base address
     */
    public long getModuleBase(String moduleName) {
        if (!initialized) {
            Log.e(TAG, "MemoryManager not initialized");
            return 0;
        }
        
        try {
            ModuleInfo moduleInfo = getModuleInfo(moduleName);
            return moduleInfo != null ? moduleInfo.baseAddress : 0;
        } catch (Exception e) {
            Log.e(TAG, "Error getting module base: " + moduleName, e);
            return 0;
        }
    }
    
    /**
     * Get module size
     */
    public long getModuleSize(String moduleName) {
        if (!initialized) {
            Log.e(TAG, "MemoryManager not initialized");
            return 0;
        }
        
        try {
            ModuleInfo moduleInfo = getModuleInfo(moduleName);
            return moduleInfo != null ? moduleInfo.size : 0;
        } catch (Exception e) {
            Log.e(TAG, "Error getting module size: " + moduleName, e);
            return 0;
        }
    }
    
    /**
     * Get module information with caching
     */
    public ModuleInfo getModuleInfo(String moduleName) {
        if (moduleName == null || moduleName.isEmpty()) {
            return null;
        }
        
        // Check cache first
        ModuleInfo cached = moduleCache.get(moduleName);
        if (cached != null) {
            return cached;
        }
        
        try {
            // Get from native
            long baseAddress = nativeGetModuleBase(moduleName);
            long size = nativeGetModuleSize(moduleName);
            
            if (baseAddress != 0 && size != 0) {
                ModuleInfo moduleInfo = new ModuleInfo(moduleName, baseAddress, size);
                moduleCache.put(moduleName, moduleInfo);
                return moduleInfo;
            }
            
            return null;
            
        } catch (Exception e) {
            Log.e(TAG, "Error getting module info: " + moduleName, e);
            return null;
        }
    }
    
    /**
     * Refresh module cache
     */
    public void refreshModuleCache() {
        try {
            moduleCache.clear();
            Log.d(TAG, "Module cache refreshed");
        } catch (Exception e) {
            Log.e(TAG, "Error refreshing module cache", e);
        }
    }
    
    /**
     * Clear pattern cache
     */
    public void clearPatternCache() {
        try {
            patternCache.clear();
            Log.d(TAG, "Pattern cache cleared");
        } catch (Exception e) {
            Log.e(TAG, "Error clearing pattern cache", e);
        }
    }
    
    /**
     * Get all loaded modules
     */
    public List<ModuleInfo> getAllModules() {
        try {
            // This would need to be implemented in native code
            // For now, return cached modules
            return new ArrayList<>(moduleCache.values());
        } catch (Exception e) {
            Log.e(TAG, "Error getting all modules", e);
            return new ArrayList<>();
        }
    }
    
    /**
     * Get memory manager statistics
     */
    public String getStatistics() {
        try {
            StringBuilder stats = new StringBuilder();
            stats.append("MemoryManager Statistics:\n");
            stats.append("Initialized: ").append(initialized).append("\n");
            stats.append("Cached Modules: ").append(moduleCache.size()).append("\n");
            stats.append("Cached Patterns: ").append(patternCache.size()).append("\n");
            
            if (!moduleCache.isEmpty()) {
                stats.append("\nLoaded Modules:\n");
                for (ModuleInfo module : moduleCache.values()) {
                    stats.append("  ").append(module.name)
                         .append(" (0x").append(Long.toHexString(module.baseAddress))
                         .append(", size: 0x").append(Long.toHexString(module.size))
                         .append(")\n");
                }
            }
            
            return stats.toString();
        } catch (Exception e) {
            Log.e(TAG, "Error generating statistics", e);
            return "Error generating statistics: " + e.getMessage();
        }
    }
    
    /**
     * Check if MemoryManager is initialized
     */
    public boolean isInitialized() {
        return initialized;
    }
    
    // Native method declarations
    private native boolean nativeInitialize();
    private native byte[] nativeReadMemory(long address, int size);
    private native boolean nativeWriteMemory(long address, byte[] data);
    private native long nativeFindPattern(String pattern, long startAddress, long endAddress);
    private native long nativeGetModuleBase(String moduleName);
    private native long nativeGetModuleSize(String moduleName);
    
    /**
     * Module information container
     */
    public static class ModuleInfo {
        public final String name;
        public final long baseAddress;
        public final long size;
        
        public ModuleInfo(String name, long baseAddress, long size) {
            this.name = name;
            this.baseAddress = baseAddress;
            this.size = size;
        }
        
        @Override
        public String toString() {
            return String.format("ModuleInfo{name='%s', base=0x%x, size=0x%x}", 
                               name, baseAddress, size);
        }
    }
}
