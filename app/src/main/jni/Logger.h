#pragma once

#include <string>

/**
 * @brief Enhanced Logger class for unified debug output
 * 
 * This class provides a unified interface for logging messages at different levels
 * (debug, info, warning, error) with integration to existing BearMod logging systems.
 * 
 * Features:
 * - Multiple output targets (Android logcat, file logging)
 * - Thread-safe operations
 * - Timestamp support
 * - Integration with existing CLog and TEAMNRG Logger
 * - Configurable log levels
 * - Memory and performance optimized
 */
class Logger {
public:
    /**
     * @brief Log levels
     */
    enum class Level {
        DEBUG = 0,    ///< Debug messages (most verbose)
        INFO = 1,     ///< Informational messages
        WARNING = 2,  ///< Warning messages
        ERROR = 3     ///< Error messages (least verbose)
    };

    /**
     * @brief Initialize the logger
     * 
     * @param tag Tag to use for log messages (default: "BearMod")
     * @param level Minimum log level to display (default: INFO)
     * 
     * @note This integrates with existing Helper/Log.h and TEAMNRG/Logger.h systems
     */
    static void initialize(const std::string& tag = "BearMod", Level level = Level::INFO);

    /**
     * @brief Set the minimum log level
     * 
     * @param level Minimum log level to display
     */
    static void setLevel(Level level);

    /**
     * @brief Log a debug message
     * 
     * @param format Format string (printf-style)
     * @param ... Format arguments
     * 
     * @note Only logged if current level <= DEBUG
     */
    static void debug(const char* format, ...);

    /**
     * @brief Log an info message
     * 
     * @param format Format string (printf-style)
     * @param ... Format arguments
     * 
     * @note Only logged if current level <= INFO
     */
    static void info(const char* format, ...);

    /**
     * @brief Log a warning message
     * 
     * @param format Format string (printf-style)
     * @param ... Format arguments
     * 
     * @note Only logged if current level <= WARNING
     */
    static void warning(const char* format, ...);

    /**
     * @brief Log an error message
     * 
     * @param format Format string (printf-style)
     * @param ... Format arguments
     * 
     * @note Always logged (ERROR is highest priority)
     */
    static void error(const char* format, ...);

    // Enhanced functionality beyond your original design

    /**
     * @brief Enable or disable file logging
     * 
     * @param enabled True to enable file logging, false to disable
     * 
     * @note Integrates with existing CLog system
     */
    static void setFileLogging(bool enabled);

    /**
     * @brief Enable or disable Android logcat logging
     * 
     * @param enabled True to enable Android logging, false to disable
     * 
     * @note Integrates with existing TEAMNRG Logger system
     */
    static void setAndroidLogging(bool enabled);

    /**
     * @brief Enable or disable timestamps in log messages
     * 
     * @param enabled True to enable timestamps, false to disable
     */
    static void setTimestamps(bool enabled);

    /**
     * @brief Check if logger is initialized
     * 
     * @return True if initialized, false otherwise
     */
    static bool isInitialized();

    /**
     * @brief Get current log tag
     * 
     * @return Current log tag string
     */
    static std::string getTag();

    /**
     * @brief Get current log level
     * 
     * @return Current minimum log level
     */
    static Level getLevel();

    /**
     * @brief Cleanup logger resources
     * 
     * @note Call this before application exit
     */
    static void cleanup();

private:
    static std::string tag;      ///< Current log tag
    static Level level;          ///< Current minimum log level
    static bool initialized;     ///< Initialization status
};

// Convenience macros for easier usage (optional)
// These integrate with your existing TEAMNRG Logger macros

#ifndef DISABLE_LOGGER_MACROS

/**
 * @brief Convenience macros for Logger usage
 * 
 * These macros provide a simpler interface and can coexist with
 * your existing LOGD, LOGI, LOGW, LOGE macros from TEAMNRG/Logger.h
 */

#define LOG_DEBUG(...)   Logger::debug(__VA_ARGS__)
#define LOG_INFO(...)    Logger::info(__VA_ARGS__)
#define LOG_WARNING(...) Logger::warning(__VA_ARGS__)
#define LOG_ERROR(...)   Logger::error(__VA_ARGS__)

// Alternative names to avoid conflicts
#define LOGGER_D(...)    Logger::debug(__VA_ARGS__)
#define LOGGER_I(...)    Logger::info(__VA_ARGS__)
#define LOGGER_W(...)    Logger::warning(__VA_ARGS__)
#define LOGGER_E(...)    Logger::error(__VA_ARGS__)

// Conditional logging macros
#define LOG_DEBUG_IF(condition, ...) \
    do { if (condition) Logger::debug(__VA_ARGS__); } while(0)

#define LOG_INFO_IF(condition, ...) \
    do { if (condition) Logger::info(__VA_ARGS__); } while(0)

#define LOG_WARNING_IF(condition, ...) \
    do { if (condition) Logger::warning(__VA_ARGS__); } while(0)

#define LOG_ERROR_IF(condition, ...) \
    do { if (condition) Logger::error(__VA_ARGS__); } while(0)

#endif // DISABLE_LOGGER_MACROS

// Integration helpers for existing systems

/**
 * @brief Helper macros to bridge with existing logging systems
 * 
 * These allow gradual migration from existing loggers to the unified Logger
 */

// Bridge to TEAMNRG Logger (preserves existing functionality)
#define BRIDGE_LOGD(...) do { LOGD(__VA_ARGS__); Logger::debug(__VA_ARGS__); } while(0)
#define BRIDGE_LOGI(...) do { LOGI(__VA_ARGS__); Logger::info(__VA_ARGS__); } while(0)
#define BRIDGE_LOGW(...) do { LOGW(__VA_ARGS__); Logger::warning(__VA_ARGS__); } while(0)
#define BRIDGE_LOGE(...) do { LOGE(__VA_ARGS__); Logger::error(__VA_ARGS__); } while(0)

// Bridge to CLog (preserves existing functionality)
#define BRIDGE_CLOG(clog_instance, ...) \
    do { \
        clog_instance.Write(__VA_ARGS__); \
        Logger::info(__VA_ARGS__); \
    } while(0)

/**
 * @brief Usage Examples:
 * 
 * // Basic usage
 * Logger::initialize("BearMod", Logger::Level::DEBUG);
 * Logger::info("Application started");
 * Logger::debug("Debug info: %d", value);
 * Logger::warning("Warning: %s", message);
 * Logger::error("Error occurred: %s", error);
 * 
 * // Using macros
 * LOG_INFO("This is an info message");
 * LOG_DEBUG("Debug value: %d", debugValue);
 * 
 * // Conditional logging
 * LOG_DEBUG_IF(debugEnabled, "Debug mode active");
 * 
 * // Integration with existing systems
 * BRIDGE_LOGD("This logs to both TEAMNRG and unified Logger");
 * 
 * // Configuration
 * Logger::setLevel(Logger::Level::WARNING); // Only warnings and errors
 * Logger::setFileLogging(false);            // Disable file logging
 * Logger::setTimestamps(true);              // Enable timestamps
 * 
 * // Cleanup
 * Logger::cleanup();
 */
