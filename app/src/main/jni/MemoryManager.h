#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <android/log.h>
#include <dirent.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>

// Fallback implementations for process_vm_* functions
extern "C" {
    // Fallback implementation for process_vm_readv
    inline ssize_t process_vm_readv(pid_t pid, const struct iovec *local_iov, unsigned long liovcnt,
                                   const struct iovec *remote_iov, unsigned long riovcnt, unsigned long flags) {
        // Simple fallback - just copy if it's the same process
        if (pid == getpid() && liovcnt == 1 && riovcnt == 1) {
            size_t copy_size = std::min(local_iov[0].iov_len, remote_iov[0].iov_len);
            memcpy(local_iov[0].iov_base, remote_iov[0].iov_base, copy_size);
            return copy_size;
        }
        return -1;
    }

    // Fallback implementation for process_vm_writev
    inline ssize_t process_vm_writev(pid_t pid, const struct iovec *local_iov, unsigned long liovcnt,
                                    const struct iovec *remote_iov, unsigned long riovcnt, unsigned long flags) {
        // Simple fallback - just copy if it's the same process
        if (pid == getpid() && liovcnt == 1 && riovcnt == 1) {
            size_t copy_size = std::min(local_iov[0].iov_len, remote_iov[0].iov_len);
            memcpy(remote_iov[0].iov_base, local_iov[0].iov_base, copy_size);
            return copy_size;
        }
        return -1;
    }
}

#define LOG_TAG "MemoryHelper"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

class MemoryHelper {
private:
    pid_t targetPid;
    bool initialized;

    // Get base address of a module
    uintptr_t GetModuleBase(const std::string& moduleName) {
        char line[512];
        uintptr_t baseAddr = 0;

        char path[256];
        sprintf(path, "/proc/%d/maps", targetPid);

        FILE* fp = fopen(path, "r");
        if (fp) {
            while (fgets(line, sizeof(line), fp)) {
                if (strstr(line, moduleName.c_str())) {
                    baseAddr = strtoull(line, nullptr, 16);
                    break;
                }
            }
            fclose(fp);
        }

        return baseAddr;
    }

public:
    MemoryHelper() : targetPid(0), initialized(false) {}

    // Initialize with target process ID
    bool Initialize(pid_t pid) {
        targetPid = pid;
        initialized = true;
        return true;
    }

    // Initialize with target process name
    bool Initialize(const std::string& processName) {
        char path[256];
        char line[512];

        DIR* dir = opendir("/proc");
        if (!dir) {
            LOGE("Failed to open /proc directory");
            return false;
        }

        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            // Check if entry is a directory and name is a number (PID)
            if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
                pid_t pid = atoi(entry->d_name);

                // Check process name
                sprintf(path, "/proc/%d/cmdline", pid);
                FILE* cmdline = fopen(path, "r");
                if (cmdline) {
                    if (fgets(line, sizeof(line), cmdline)) {
                        if (strstr(line, processName.c_str())) {
                            targetPid = pid;
                            initialized = true;
                            fclose(cmdline);
                            closedir(dir);
                            LOGI("Found process %s with PID %d", processName.c_str(), pid);
                            return true;
                        }
                    }
                    fclose(cmdline);
                }
            }
        }

        closedir(dir);
        LOGE("Process %s not found", processName.c_str());
        return false;
    }

    // Read memory
    template<typename T>
    T Read(uintptr_t address) {
        T value = {};

        if (!initialized) {
            LOGE("MemoryHelper not initialized");
            return value;
        }

        struct iovec local[1];
        struct iovec remote[1];

        local[0].iov_base = &value;
        local[0].iov_len = sizeof(T);
        remote[0].iov_base = (void*)address;
        remote[0].iov_len = sizeof(T);

        ssize_t nread = process_vm_readv(targetPid, local, 1, remote, 1, 0);
        if (nread != sizeof(T)) {
            LOGE("Failed to read memory at 0x%lx", address);
        }

        return value;
    }

    // Write memory
    template<typename T>
    bool Write(uintptr_t address, const T& value) {
        if (!initialized) {
            LOGE("MemoryHelper not initialized");
            return false;
        }

        struct iovec local[1];
        struct iovec remote[1];

        local[0].iov_base = (void*)&value;
        local[0].iov_len = sizeof(T);
        remote[0].iov_base = (void*)address;
        remote[0].iov_len = sizeof(T);

        ssize_t nwritten = process_vm_writev(targetPid, local, 1, remote, 1, 0);
        if (nwritten != sizeof(T)) {
            LOGE("Failed to write memory at 0x%lx", address);
            return false;
        }

        return true;
    }

    // Read string (null-terminated)
    std::string ReadString(uintptr_t address, size_t maxLength = 256) {
        if (!initialized) {
            LOGE("MemoryHelper not initialized");
            return "";
        }

        std::vector<char> buffer(maxLength, 0);

        struct iovec local[1];
        struct iovec remote[1];

        local[0].iov_base = buffer.data();
        local[0].iov_len = maxLength;
        remote[0].iov_base = (void*)address;
        remote[0].iov_len = maxLength;

        ssize_t nread = process_vm_readv(targetPid, local, 1, remote, 1, 0);
        if (nread <= 0) {
            LOGE("Failed to read string at 0x%lx", address);
            return "";
        }

        // Ensure null-termination
        buffer[maxLength - 1] = '\0';

        return std::string(buffer.data());
    }

    // Get base address of the main module
    uintptr_t GetBaseAddress(const std::string& moduleName = "libUE4.so") {
        if (!initialized) {
            LOGE("MemoryHelper not initialized");
            return 0;
        }

        return GetModuleBase(moduleName);
    }

    // Check if initialized
    bool IsInitialized() const {
        return initialized;
    }

    // Get target process ID
    pid_t GetTargetPid() const {
        return targetPid;
    }

    // Backward compatibility methods for existing code
    static bool initialize() {
        static MemoryHelper instance;
        return instance.Initialize(getpid());
    }

    static bool readMemory(uintptr_t address, void* buffer, size_t size) {
        static MemoryHelper instance;
        if (!instance.IsInitialized()) {
            instance.Initialize(getpid());
        }

        struct iovec local[1];
        struct iovec remote[1];

        local[0].iov_base = buffer;
        local[0].iov_len = size;
        remote[0].iov_base = (void*)address;
        remote[0].iov_len = size;

        ssize_t nread = process_vm_readv(instance.GetTargetPid(), local, 1, remote, 1, 0);
        return nread == (ssize_t)size;
    }

    static bool writeMemory(uintptr_t address, const void* buffer, size_t size) {
        static MemoryHelper instance;
        if (!instance.IsInitialized()) {
            instance.Initialize(getpid());
        }

        struct iovec local[1];
        struct iovec remote[1];

        local[0].iov_base = (void*)buffer;
        local[0].iov_len = size;
        remote[0].iov_base = (void*)address;
        remote[0].iov_len = size;

        ssize_t nwritten = process_vm_writev(instance.GetTargetPid(), local, 1, remote, 1, 0);
        return nwritten == (ssize_t)size;
    }

    static uintptr_t findPattern(const std::string& pattern, uintptr_t start, uintptr_t end) {
        // Simple pattern finding - not implemented for now
        return 0;
    }

    static uintptr_t getModuleBase(const std::string& moduleName) {
        static MemoryHelper instance;
        if (!instance.IsInitialized()) {
            instance.Initialize(getpid());
        }
        return instance.GetBaseAddress(moduleName);
    }

    static size_t getModuleSize(const std::string& moduleName) {
        // Module size calculation - not implemented for now
        return 0;
    }
};

// Backward compatibility aliases for existing code
using MemoryManager = MemoryHelper;
