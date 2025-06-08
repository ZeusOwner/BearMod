#include "CLog.h"
#include <android/log.h>
#include <cstdarg>
#include <cstdio>

// Simple CLog implementation for Logger compatibility
bool CLog::Open(const char* filename) {
        // For Android, we use logcat instead of file logging
        __android_log_print(ANDROID_LOG_INFO, "CLog", "Log opened: %s", filename);
        return true;
}

void CLog::Write(const char* format, ...) {
        va_list args;
        va_start(args, format);
        
        char buffer[1024];
        vsnprintf(buffer, sizeof(buffer), format, args);
        
        __android_log_print(ANDROID_LOG_INFO, "BearMod", "%s", buffer);
        
        va_end(args);
}

void CLog::Close() {
    __android_log_print(ANDROID_LOG_INFO, "CLog", "Log closed");
}
