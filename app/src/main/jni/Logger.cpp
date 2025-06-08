#include "Logger.h"
#include <android/log.h>
#include <cstdarg>
#include <cstdio>
#include <mutex>
#include <chrono>
#include <iomanip>
#include <sstream>

// Integration with existing loggers
#include "Helper/Log.h"
#include "TEAMNRG/Logger.h"

// Static member initialization
std::string Logger::tag = "BearMod";
Logger::Level Logger::level = Logger::Level::INFO;
bool Logger::initialized = false;

// Internal state
static std::mutex logMutex;
static CLog* fileLogger = nullptr;
static bool useFileLogging = false;
static bool useAndroidLogging = true;
static bool useTimestamps = true;

// Helper function to get current timestamp
static std::string getCurrentTimestamp() {
    if (!useTimestamps) return "";
    
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;
    
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%H:%M:%S");
    ss << '.' << std::setfill('0') << std::setw(3) << ms.count();
    return ss.str();
}

// Helper function to convert level to string
static const char* levelToString(Logger::Level level) {
    switch (level) {
        case Logger::Level::DEBUG:   return "DEBUG";
        case Logger::Level::INFO:    return "INFO";
        case Logger::Level::WARNING: return "WARN";
        case Logger::Level::ERROR:   return "ERROR";
        default:                     return "UNKNOWN";
    }
}

// Helper function to convert level to Android log priority
static int levelToAndroidPriority(Logger::Level level) {
    switch (level) {
        case Logger::Level::DEBUG:   return ANDROID_LOG_DEBUG;
        case Logger::Level::INFO:    return ANDROID_LOG_INFO;
        case Logger::Level::WARNING: return ANDROID_LOG_WARN;
        case Logger::Level::ERROR:   return ANDROID_LOG_ERROR;
        default:                     return ANDROID_LOG_INFO;
    }
}

void Logger::initialize(const std::string& tag, Level level) {
    std::lock_guard<std::mutex> lock(logMutex);
    
    if (initialized) {
        return;
    }
    
    Logger::tag = tag;
    Logger::level = level;
    
    try {
        // Try to initialize file logging (optional)
        try {
            fileLogger = new CLog();
            std::string logPath = "/data/data/com.bearmod/files/" + tag + ".log";
            fileLogger->Open(logPath.c_str());
            useFileLogging = true;
        } catch (...) {
            // File logging not available, continue with Android logging only
            useFileLogging = false;
            if (fileLogger) {
                delete fileLogger;
                fileLogger = nullptr;
            }
        }
        
        initialized = true;
        
        // Log initialization message
        info("Logger initialized - Tag: %s, Level: %s, File: %s, Android: %s",
             tag.c_str(), levelToString(level), 
             useFileLogging ? "YES" : "NO",
             useAndroidLogging ? "YES" : "NO");
             
    } catch (const std::exception& e) {
        // Fallback to Android logging only
        useFileLogging = false;
        useAndroidLogging = true;
        initialized = true;
        
        __android_log_print(ANDROID_LOG_ERROR, tag.c_str(), 
                           "Logger initialization failed: %s", e.what());
    }
}

void Logger::setLevel(Level level) {
    std::lock_guard<std::mutex> lock(logMutex);
    Logger::level = level;
    
    if (initialized) {
        info("Log level changed to: %s", levelToString(level));
    }
}

void Logger::debug(const char* format, ...) {
    if (!initialized || level > Level::DEBUG) {
        return;
    }
    
    std::lock_guard<std::mutex> lock(logMutex);
    
    try {
        // Format the message
        va_list args;
        va_start(args, format);
        
        char buffer[2048];
        vsnprintf(buffer, sizeof(buffer), format, args);
        
        va_end(args);
        
        // Create formatted message with timestamp
        std::string timestamp = getCurrentTimestamp();
        std::string fullMessage;
        
        if (!timestamp.empty()) {
            fullMessage = "[" + timestamp + "] [DEBUG] " + std::string(buffer);
        } else {
            fullMessage = "[DEBUG] " + std::string(buffer);
        }
        
        // Log to Android logcat
        if (useAndroidLogging) {
            __android_log_print(ANDROID_LOG_DEBUG, tag.c_str(), "%s", buffer);
        }
        
        // Log to file
        if (useFileLogging && fileLogger) {
            fileLogger->Write("%s", fullMessage.c_str());
        }
        
    } catch (const std::exception& e) {
        // Fallback to basic Android logging
        __android_log_print(ANDROID_LOG_ERROR, tag.c_str(), 
                           "Logger::debug error: %s", e.what());
    }
}

void Logger::info(const char* format, ...) {
    if (!initialized || level > Level::INFO) {
        return;
    }
    
    std::lock_guard<std::mutex> lock(logMutex);
    
    try {
        // Format the message
        va_list args;
        va_start(args, format);
        
        char buffer[2048];
        vsnprintf(buffer, sizeof(buffer), format, args);
        
        va_end(args);
        
        // Create formatted message with timestamp
        std::string timestamp = getCurrentTimestamp();
        std::string fullMessage;
        
        if (!timestamp.empty()) {
            fullMessage = "[" + timestamp + "] [INFO] " + std::string(buffer);
        } else {
            fullMessage = "[INFO] " + std::string(buffer);
        }
        
        // Log to Android logcat
        if (useAndroidLogging) {
            __android_log_print(ANDROID_LOG_INFO, tag.c_str(), "%s", buffer);
        }
        
        // Log to file
        if (useFileLogging && fileLogger) {
            fileLogger->Write("%s", fullMessage.c_str());
        }
        
    } catch (const std::exception& e) {
        // Fallback to basic Android logging
        __android_log_print(ANDROID_LOG_ERROR, tag.c_str(), 
                           "Logger::info error: %s", e.what());
    }
}

void Logger::warning(const char* format, ...) {
    if (!initialized || level > Level::WARNING) {
        return;
    }
    
    std::lock_guard<std::mutex> lock(logMutex);
    
    try {
        // Format the message
        va_list args;
        va_start(args, format);
        
        char buffer[2048];
        vsnprintf(buffer, sizeof(buffer), format, args);
        
        va_end(args);
        
        // Create formatted message with timestamp
        std::string timestamp = getCurrentTimestamp();
        std::string fullMessage;
        
        if (!timestamp.empty()) {
            fullMessage = "[" + timestamp + "] [WARN] " + std::string(buffer);
        } else {
            fullMessage = "[WARN] " + std::string(buffer);
        }
        
        // Log to Android logcat
        if (useAndroidLogging) {
            __android_log_print(ANDROID_LOG_WARN, tag.c_str(), "%s", buffer);
        }
        
        // Log to file
        if (useFileLogging && fileLogger) {
            fileLogger->Write("%s", fullMessage.c_str());
        }
        
    } catch (const std::exception& e) {
        // Fallback to basic Android logging
        __android_log_print(ANDROID_LOG_ERROR, tag.c_str(), 
                           "Logger::warning error: %s", e.what());
    }
}

void Logger::error(const char* format, ...) {
    if (!initialized || level > Level::ERROR) {
        return;
    }
    
    std::lock_guard<std::mutex> lock(logMutex);
    
    try {
        // Format the message
        va_list args;
        va_start(args, format);
        
        char buffer[2048];
        vsnprintf(buffer, sizeof(buffer), format, args);
        
        va_end(args);
        
        // Create formatted message with timestamp
        std::string timestamp = getCurrentTimestamp();
        std::string fullMessage;
        
        if (!timestamp.empty()) {
            fullMessage = "[" + timestamp + "] [ERROR] " + std::string(buffer);
        } else {
            fullMessage = "[ERROR] " + std::string(buffer);
        }
        
        // Log to Android logcat
        if (useAndroidLogging) {
            __android_log_print(ANDROID_LOG_ERROR, tag.c_str(), "%s", buffer);
        }
        
        // Log to file
        if (useFileLogging && fileLogger) {
            fileLogger->Write("%s", fullMessage.c_str());
        }
        
    } catch (const std::exception& e) {
        // Fallback to basic Android logging
        __android_log_print(ANDROID_LOG_ERROR, tag.c_str(), 
                           "Logger::error error: %s", e.what());
    }
}

// Additional utility methods for enhanced functionality

void Logger::setFileLogging(bool enabled) {
    std::lock_guard<std::mutex> lock(logMutex);
    useFileLogging = enabled && (fileLogger != nullptr);
}

void Logger::setAndroidLogging(bool enabled) {
    std::lock_guard<std::mutex> lock(logMutex);
    useAndroidLogging = enabled;
}

void Logger::setTimestamps(bool enabled) {
    std::lock_guard<std::mutex> lock(logMutex);
    useTimestamps = enabled;
}

bool Logger::isInitialized() {
    return initialized;
}

std::string Logger::getTag() {
    return tag;
}

Logger::Level Logger::getLevel() {
    return level;
}

void Logger::cleanup() {
    std::lock_guard<std::mutex> lock(logMutex);
    
    if (fileLogger) {
        try {
            fileLogger->Close();
            delete fileLogger;
            fileLogger = nullptr;
        } catch (...) {
            // Ignore cleanup errors
        }
    }
    
    useFileLogging = false;
    initialized = false;
}
