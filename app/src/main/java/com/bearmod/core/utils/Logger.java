package com.bearmod.core.utils;

import android.content.Context;
import android.util.Log;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.util.concurrent.atomic.AtomicBoolean;

/**
 * Enhanced Java Logger class for BearMod
 * 
 * This logger provides Java-side file logging that integrates with
 * the unified native logging system. It complements rather than
 * replaces the native Logger.h/cpp system.
 * 
 * Features:
 * - File logging to external storage
 * - Integration with native Logger
 * - Thread-safe operations
 * - Automatic file management
 * - Exception logging with stack traces
 */
public class Logger {
    private static final String DEFAULT_TAG = "BearMod_Java";
    private static String tag = DEFAULT_TAG;
    private static final AtomicBoolean initialized = new AtomicBoolean(false);
    private static volatile boolean fileLoggingEnabled = false;
    private static volatile boolean nativeIntegrationEnabled = false;
    private static File logFile = null;
    private static PrintWriter logWriter = null;
    private static Context applicationContext = null;
    
    // Integration with native Logger
    private static boolean nativeLoggerAvailable = false;
    
    /**
     * Initialize the Java logger with enhanced integration
     * 
     * @param context Application context
     * @param enableNativeIntegration Whether to integrate with native Logger
     */
    public static void initialize(Context context, boolean enableNativeIntegration) {
        if (initialized.compareAndSet(false, true)) {
            try {
                applicationContext = context.getApplicationContext();
                tag = DEFAULT_TAG;
                nativeIntegrationEnabled = enableNativeIntegration;
                
                // Test native Logger availability
                if (enableNativeIntegration) {
                    try {
                        nativeLoggerAvailable = isNativeLoggerAvailable();
                        if (nativeLoggerAvailable) {
                            log(Log.INFO, "Native Logger integration enabled");
                        }
                    } catch (Exception e) {
                        nativeLoggerAvailable = false;
                        Log.w(tag, "Native Logger not available, using Java-only logging");
                    }
                }
                
                // Initialize file logging
                initializeFileLogging();
                
                log(Log.INFO, "Java Logger initialized - File: " + fileLoggingEnabled + 
                             ", Native: " + nativeLoggerAvailable);
                
            } catch (Exception e) {
                Log.e(tag, "Failed to initialize Java Logger", e);
                initialized.set(false);
            }
        }
    }
    
    /**
     * Initialize with default settings (file logging enabled, native integration enabled)
     */
    public static void initialize(Context context) {
        initialize(context, true);
    }
    
    /**
     * Initialize file logging
     */
    private static void initializeFileLogging() {
        try {
            // Try external files directory first
            File logDir = applicationContext.getExternalFilesDir("logs");
            
            // Fallback to internal files directory
            if (logDir == null) {
                logDir = new File(applicationContext.getFilesDir(), "logs");
            }
            
            if (logDir != null) {
                if (!logDir.exists()) {
                    boolean created = logDir.mkdirs();
                    if (!created) {
                        Log.w(tag, "Failed to create log directory");
                        return;
                    }
                }
                
                SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd_HH-mm-ss", Locale.US);
                String timestamp = sdf.format(new Date());
                
                logFile = new File(logDir, "bearmod_java_" + timestamp + ".log");
                logWriter = new PrintWriter(new FileOutputStream(logFile, true));
                
                fileLoggingEnabled = true;
                
                Log.i(tag, "File logging initialized: " + logFile.getAbsolutePath());
            }
        } catch (IOException e) {
            Log.e(tag, "Failed to initialize file logging", e);
            fileLoggingEnabled = false;
        }
    }
    
    /**
     * Set the tag for log messages
     * 
     * @param newTag New tag
     */
    public static void setTag(String newTag) {
        tag = newTag != null ? newTag : DEFAULT_TAG;
    }
    
    /**
     * Log a debug message
     * 
     * @param message Message to log
     */
    public static void d(String message) {
        log(Log.DEBUG, message);
    }
    
    /**
     * Log a debug message with format
     * 
     * @param format Format string
     * @param args Format arguments
     */
    public static void d(String format, Object... args) {
        log(Log.DEBUG, String.format(Locale.US, format, args));
    }
    
    /**
     * Log an info message
     * 
     * @param message Message to log
     */
    public static void i(String message) {
        log(Log.INFO, message);
    }
    
    /**
     * Log an info message with format
     * 
     * @param format Format string
     * @param args Format arguments
     */
    public static void i(String format, Object... args) {
        log(Log.INFO, String.format(Locale.US, format, args));
    }
    
    /**
     * Log a warning message
     * 
     * @param message Message to log
     */
    public static void w(String message) {
        log(Log.WARN, message);
    }
    
    /**
     * Log a warning message with format
     * 
     * @param format Format string
     * @param args Format arguments
     */
    public static void w(String format, Object... args) {
        log(Log.WARN, String.format(Locale.US, format, args));
    }
    
    /**
     * Log an error message
     * 
     * @param message Message to log
     */
    public static void e(String message) {
        log(Log.ERROR, message);
    }
    
    /**
     * Log an error message with format
     * 
     * @param format Format string
     * @param args Format arguments
     */
    public static void e(String format, Object... args) {
        log(Log.ERROR, String.format(Locale.US, format, args));
    }
    
    /**
     * Log an error message with an exception
     * 
     * @param message Message to log
     * @param throwable Exception to log
     */
    public static void e(String message, Throwable throwable) {
        // Log to Android logcat
        Log.e(tag, message, throwable);
        
        // Log to native Logger if available
        if (nativeLoggerAvailable && nativeIntegrationEnabled) {
            try {
                nativeLogError(message + " - " + throwable.getMessage());
            } catch (Exception e) {
                // Ignore native logging errors
            }
        }
        
        // Log to file
        if (fileLoggingEnabled && logWriter != null) {
            synchronized (Logger.class) {
                try {
                    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS", Locale.US);
                    String timestamp = sdf.format(new Date());
                    
                    logWriter.println(timestamp + " E/" + tag + ": " + message);
                    throwable.printStackTrace(logWriter);
                    logWriter.flush();
                } catch (Exception e) {
                    // Ignore file logging errors
                }
            }
        }
    }
    
    /**
     * Log a message with a specific level
     * 
     * @param level Log level
     * @param message Message to log
     */
    private static void log(int level, String message) {
        if (!initialized.get()) {
            // Fallback to basic Android logging if not initialized
            Log.println(level, tag, message);
            return;
        }
        
        // Log to Android logcat
        switch (level) {
            case Log.DEBUG:
                Log.d(tag, message);
                break;
            case Log.INFO:
                Log.i(tag, message);
                break;
            case Log.WARN:
                Log.w(tag, message);
                break;
            case Log.ERROR:
                Log.e(tag, message);
                break;
        }
        
        // Log to native Logger if available
        if (nativeLoggerAvailable && nativeIntegrationEnabled) {
            try {
                switch (level) {
                    case Log.DEBUG:
                        nativeLogDebug(message);
                        break;
                    case Log.INFO:
                        nativeLogInfo(message);
                        break;
                    case Log.WARN:
                        nativeLogWarning(message);
                        break;
                    case Log.ERROR:
                        nativeLogError(message);
                        break;
                }
            } catch (Exception e) {
                // Ignore native logging errors
            }
        }
        
        // Log to file
        if (fileLoggingEnabled && logWriter != null) {
            synchronized (Logger.class) {
                try {
                    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS", Locale.US);
                    String timestamp = sdf.format(new Date());
                    
                    String levelChar;
                    switch (level) {
                        case Log.DEBUG:
                            levelChar = "D";
                            break;
                        case Log.INFO:
                            levelChar = "I";
                            break;
                        case Log.WARN:
                            levelChar = "W";
                            break;
                        case Log.ERROR:
                            levelChar = "E";
                            break;
                        default:
                            levelChar = "?";
                            break;
                    }
                    
                    logWriter.println(timestamp + " " + levelChar + "/" + tag + ": " + message);
                    logWriter.flush();
                } catch (Exception e) {
                    // Ignore file logging errors
                }
            }
        }
    }
    
    /**
     * Enable or disable file logging
     */
    public static void setFileLoggingEnabled(boolean enabled) {
        fileLoggingEnabled = enabled && (logWriter != null);
    }
    
    /**
     * Enable or disable native integration
     */
    public static void setNativeIntegrationEnabled(boolean enabled) {
        nativeIntegrationEnabled = enabled && nativeLoggerAvailable;
    }
    
    /**
     * Check if logger is initialized
     */
    public static boolean isInitialized() {
        return initialized.get();
    }
    
    /**
     * Check if file logging is enabled
     */
    public static boolean isFileLoggingEnabled() {
        return fileLoggingEnabled;
    }
    
    /**
     * Check if native integration is available
     */
    public static boolean isNativeIntegrationAvailable() {
        return nativeLoggerAvailable;
    }
    
    /**
     * Get current log file path
     */
    public static String getLogFilePath() {
        return logFile != null ? logFile.getAbsolutePath() : null;
    }
    
    /**
     * Get logger status
     */
    public static String getStatus() {
        StringBuilder status = new StringBuilder();
        status.append("Java Logger Status:\n");
        status.append("  Initialized: ").append(initialized.get()).append("\n");
        status.append("  Tag: ").append(tag).append("\n");
        status.append("  File Logging: ").append(fileLoggingEnabled).append("\n");
        status.append("  Native Integration: ").append(nativeLoggerAvailable).append("\n");
        if (logFile != null) {
            status.append("  Log File: ").append(logFile.getAbsolutePath()).append("\n");
        }
        return status.toString();
    }
    
    /**
     * Close the logger and cleanup resources
     */
    public static void close() {
        if (fileLoggingEnabled && logWriter != null) {
            synchronized (Logger.class) {
                try {
                    log(Log.INFO, "Java Logger closing");
                    logWriter.close();
                    logWriter = null;
                    fileLoggingEnabled = false;
                } catch (Exception e) {
                    // Ignore cleanup errors
                }
            }
        }
        initialized.set(false);
    }
    
    // Native method declarations for integration
    private static native boolean isNativeLoggerAvailable();
    private static native void nativeLogDebug(String message);
    private static native void nativeLogInfo(String message);
    private static native void nativeLogWarning(String message);
    private static native void nativeLogError(String message);
    
    // Load native library
    static {
        try {
            System.loadLibrary("bearmod");
        } catch (UnsatisfiedLinkError e) {
            // Native library not available, continue with Java-only logging
        }
    }
}
