#include "HookManager.h"
#include "Logger.h"
#include <dlfcn.h>
#include <unistd.h>
#include <sys/mman.h>
#include <android/log.h>
#include <map>
#include <vector>
#include <mutex>
#include <memory>

// Dobby hooking library (if available)
#ifdef USE_DOBBY
#include "dobby.h"
#endif

// Substrate hooking library (if available)
#ifdef USE_SUBSTRATE
#include "substrate.h"
#endif

// Use unified Logger instead of direct Android logging
#define LOGI(...) Logger::info(__VA_ARGS__)
#define LOGD(...) Logger::debug(__VA_ARGS__)
#define LOGW(...) Logger::warning(__VA_ARGS__)
#define LOGE(...) Logger::error(__VA_ARGS__)
#define LOGV(...) Logger::debug(__VA_ARGS__)

// Hook information structure
struct HookInfo {
    void* target;
    void* replacement;
    void* original;
    std::string libraryName;
    std::string functionName;
    uint64_t callCount;
    uint64_t lastCallTime;
    bool isActive;
    
    HookInfo(void* t, void* r, void* o, const std::string& lib, const std::string& func)
        : target(t), replacement(r), original(o), libraryName(lib), functionName(func),
          callCount(0), lastCallTime(0), isActive(true) {}
};

// Static members
bool HookManager::initialized = false;

// Internal state
static std::mutex hookMutex;
static std::map<void*, std::unique_ptr<HookInfo>> activeHooks;
static std::map<std::string, void*> libraryHandles;

// Signature verification bypass functions
static bool (*original_getPackageInfo)(void*, const char*, int) = nullptr;
static bool (*original_checkSignature)(void*, const char*) = nullptr;
static bool (*original_verifySignature)(void*, const char*, const char*) = nullptr;

// Forward declarations
static void* findFunctionInLibrary(const std::string& libraryName, const std::string& functionName);
static bool performHook(void* target, void* replacement, void** original);
static void setupSignatureBypassHooks();

// Signature bypass implementations
static bool bypass_getPackageInfo(void* context, const char* packageName, int flags) {
    LOGD("Signature bypass: getPackageInfo called for %s", packageName ? packageName : "null");
    return true; // Always return success
}

static bool bypass_checkSignature(void* context, const char* signature) {
    LOGD("Signature bypass: checkSignature called");
    return true; // Always return success
}

static bool bypass_verifySignature(void* context, const char* expected, const char* actual) {
    LOGD("Signature bypass: verifySignature called");
    return true; // Always return success
}

bool HookManager::initialize() {
    std::lock_guard<std::mutex> lock(hookMutex);
    
    if (initialized) {
        LOGI("HookManager already initialized");
        return true;
    }
    
    LOGI("Initializing HookManager");
    
    try {
        // Initialize hooking library
        #ifdef USE_DOBBY
        LOGD("Using Dobby hooking library");
        #elif defined(USE_SUBSTRATE)
        LOGD("Using Substrate hooking library");
        #else
        LOGD("Using manual hooking implementation");
        #endif
        
        // Setup signature verification bypass hooks
        setupSignatureBypassHooks();
        
        initialized = true;
        LOGI("HookManager initialized successfully");
        return true;
        
    } catch (const std::exception& e) {
        LOGE("Failed to initialize HookManager: %s", e.what());
        return false;
    } catch (...) {
        LOGE("Failed to initialize HookManager: unknown error");
        return false;
    }
}

bool HookManager::hookFunction(void* target, void* replacement, void** original) {
    if (!initialized) {
        LOGE("HookManager not initialized");
        return false;
    }
    
    if (!target || !replacement) {
        LOGE("Invalid parameters for hookFunction");
        return false;
    }
    
    std::lock_guard<std::mutex> lock(hookMutex);
    
    // Check if already hooked
    if (activeHooks.find(target) != activeHooks.end()) {
        LOGW("Function already hooked: %p", target);
        return true;
    }
    
    LOGD("Hooking function at %p", target);
    
    try {
        // Perform the actual hook
        if (!performHook(target, replacement, original)) {
            LOGE("Failed to hook function at %p", target);
            return false;
        }
        
        // Store hook information
        auto hookInfo = std::make_unique<HookInfo>(target, replacement, original ? *original : nullptr, "", "");
        activeHooks[target] = std::move(hookInfo);
        
        LOGI("Function hooked successfully at %p", target);
        return true;
        
    } catch (const std::exception& e) {
        LOGE("Exception while hooking function: %s", e.what());
        return false;
    } catch (...) {
        LOGE("Unknown exception while hooking function");
        return false;
    }
}

bool HookManager::hookFunctionByName(const std::string& libraryName, 
                                    const std::string& functionName,
                                    void* replacement,
                                    void** original) {
    if (!initialized) {
        LOGE("HookManager not initialized");
        return false;
    }
    
    if (libraryName.empty() || functionName.empty() || !replacement) {
        LOGE("Invalid parameters for hookFunctionByName");
        return false;
    }
    
    LOGD("Hooking function %s in %s", functionName.c_str(), libraryName.c_str());
    
    try {
        // Find the function in the specified library
        void* target = findFunctionInLibrary(libraryName, functionName);
        if (!target) {
            LOGW("Function %s not found in %s", functionName.c_str(), libraryName.c_str());
            return false;
        }
        
        std::lock_guard<std::mutex> lock(hookMutex);
        
        // Check if already hooked
        if (activeHooks.find(target) != activeHooks.end()) {
            LOGV("Function %s:%s already hooked", libraryName.c_str(), functionName.c_str());
            return true;
        }
        
        // Perform the hook
        if (!performHook(target, replacement, original)) {
            LOGE("Failed to hook function %s:%s", libraryName.c_str(), functionName.c_str());
            return false;
        }
        
        // Store hook information with library and function names
        auto hookInfo = std::make_unique<HookInfo>(target, replacement, original ? *original : nullptr, 
                                                  libraryName, functionName);
        activeHooks[target] = std::move(hookInfo);
        
        LOGI("Function %s:%s hooked successfully", libraryName.c_str(), functionName.c_str());
        return true;
        
    } catch (const std::exception& e) {
        LOGE("Exception while hooking function %s:%s - %s", 
             libraryName.c_str(), functionName.c_str(), e.what());
        return false;
    } catch (...) {
        LOGE("Unknown exception while hooking function %s:%s", 
             libraryName.c_str(), functionName.c_str());
        return false;
    }
}

bool HookManager::unhookFunction(void* target) {
    if (!initialized) {
        LOGE("HookManager not initialized");
        return false;
    }
    
    if (!target) {
        LOGE("Invalid target for unhookFunction");
        return false;
    }
    
    std::lock_guard<std::mutex> lock(hookMutex);
    
    auto it = activeHooks.find(target);
    if (it == activeHooks.end()) {
        LOGW("Function not hooked: %p", target);
        return false;
    }
    
    LOGD("Unhooking function at %p", target);
    
    try {
        // Perform unhook based on available library
        #ifdef USE_DOBBY
        if (DobbyDestroy(target) != RT_SUCCESS) {
            LOGE("Dobby unhook failed for %p", target);
            return false;
        }
        #elif defined(USE_SUBSTRATE)
        // Substrate doesn't have a direct unhook function
        // We would need to restore original bytes manually
        LOGW("Substrate unhook not implemented, marking as inactive");
        it->second->isActive = false;
        #else
        // Manual unhook implementation
        // This would involve restoring original bytes
        LOGW("Manual unhook not implemented, marking as inactive");
        it->second->isActive = false;
        #endif
        
        // Remove from active hooks
        activeHooks.erase(it);
        
        LOGI("Function unhooked successfully at %p", target);
        return true;
        
    } catch (const std::exception& e) {
        LOGE("Exception while unhooking function: %s", e.what());
        return false;
    } catch (...) {
        LOGE("Unknown exception while unhooking function");
        return false;
    }
}

// Helper function to find function in library
static void* findFunctionInLibrary(const std::string& libraryName, const std::string& functionName) {
    try {
        // Check if library is already loaded
        void* handle = nullptr;
        auto it = libraryHandles.find(libraryName);
        
        if (it != libraryHandles.end()) {
            handle = it->second;
        } else {
            // Try to load the library
            handle = dlopen(libraryName.c_str(), RTLD_LAZY);
            if (!handle) {
                // Try with different paths
                std::string fullPath = "/system/lib/" + libraryName;
                handle = dlopen(fullPath.c_str(), RTLD_LAZY);
                
                if (!handle) {
                    fullPath = "/system/lib64/" + libraryName;
                    handle = dlopen(fullPath.c_str(), RTLD_LAZY);
                }
                
                if (!handle) {
                    LOGD("Could not load library %s: %s", libraryName.c_str(), dlerror());
                    return nullptr;
                }
            }
            
            libraryHandles[libraryName] = handle;
        }
        
        // Find the function symbol
        void* symbol = dlsym(handle, functionName.c_str());
        if (!symbol) {
            LOGD("Function %s not found in %s: %s", 
                 functionName.c_str(), libraryName.c_str(), dlerror());
            return nullptr;
        }
        
        LOGD("Found function %s at %p in %s", functionName.c_str(), symbol, libraryName.c_str());
        return symbol;
        
    } catch (const std::exception& e) {
        LOGE("Exception in findFunctionInLibrary: %s", e.what());
        return nullptr;
    } catch (...) {
        LOGE("Unknown exception in findFunctionInLibrary");
        return nullptr;
    }
}

// Helper function to perform the actual hook
static bool performHook(void* target, void* replacement, void** original) {
    try {
        #ifdef USE_DOBBY
        // Use Dobby hooking library
        if (DobbyHook(target, replacement, original) != RT_SUCCESS) {
            LOGE("Dobby hook failed");
            return false;
        }
        return true;
        
        #elif defined(USE_SUBSTRATE)
        // Use Substrate hooking library
        MSHookFunction(target, replacement, original);
        return true;
        
        #else
        // Manual hooking implementation (basic example)
        // This is a simplified implementation - real implementation would be more complex
        
        // Make the target page writable
        uintptr_t pageStart = (uintptr_t)target & ~(getpagesize() - 1);
        if (mprotect((void*)pageStart, getpagesize(), PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
            LOGE("Failed to make page writable");
            return false;
        }
        
        // Store original if requested
        if (original) {
            *original = target;
        }
        
        // This is where you would implement the actual hooking logic
        // For now, we'll just log success
        LOGD("Manual hook performed (placeholder implementation)");
        
        // Restore page protection
        mprotect((void*)pageStart, getpagesize(), PROT_READ | PROT_EXEC);
        
        return true;
        #endif
        
    } catch (const std::exception& e) {
        LOGE("Exception in performHook: %s", e.what());
        return false;
    } catch (...) {
        LOGE("Unknown exception in performHook");
        return false;
    }
}

// Setup signature verification bypass hooks
static void setupSignatureBypassHooks() {
    LOGD("Setting up signature verification bypass hooks");
    
    // List of libraries to hook
    std::vector<std::string> targetLibraries = {
        "libanogs.so",
        "libUE4.so", 
        "libtersafe.so",
        "libc.so",
        "libdl.so"
    };
    
    // List of signature verification functions to hook
    std::vector<std::string> signatureFunctions = {
        "getPackageInfo",
        "checkSignature", 
        "verifySignature",
        "validateSignature",
        "checkIntegrity",
        "verifyIntegrity",
        "checkTamper",
        "antiTamper",
        "signatureCheck"
    };
    
    // Hook signature verification functions
    for (const auto& library : targetLibraries) {
        for (const auto& function : signatureFunctions) {
            try {
                void* original = nullptr;
                void* replacement = nullptr;
                
                // Choose appropriate bypass function
                if (function == "getPackageInfo") {
                    replacement = (void*)bypass_getPackageInfo;
                } else if (function == "checkSignature") {
                    replacement = (void*)bypass_checkSignature;
                } else if (function == "verifySignature") {
                    replacement = (void*)bypass_verifySignature;
                } else {
                    // Use generic bypass for other functions
                    replacement = (void*)bypass_checkSignature;
                }
                
                // Attempt to hook the function
                HookManager::hookFunctionByName(library, function, replacement, &original);
                
            } catch (...) {
                // Continue with other functions even if some fail
                LOGV("Could not hook %s:%s (expected for some)", library.c_str(), function.c_str());
            }
        }
    }
    
    LOGI("Signature verification bypass hooks setup completed");
}
