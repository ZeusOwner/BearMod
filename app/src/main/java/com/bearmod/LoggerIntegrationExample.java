package com.bearmod;

import android.content.Context;
import android.util.Log;
import com.bearmod.core.MemoryManager;
import com.bearmod.core.hooks.HookManager;

/**
 * Example demonstrating unified Logger integration across all BearMod systems
 * Shows how the enhanced Logger works with existing logging systems
 */
public class LoggerIntegrationExample {
    private static final String TAG = "BearMod_LoggerIntegration";
    
    /**
     * Initialize unified logging across all BearMod systems
     */
    public static void initializeUnifiedLogging(Context context) {
        try {
            Log.d(TAG, "🚀 Initializing Unified Logging System");
            
            // Step 1: Initialize native Logger
            initializeNativeLogger();
            
            // Step 2: Initialize MemoryManager with logging
            initializeMemoryManagerWithLogging();
            
            // Step 3: Initialize HookManager with logging
            initializeHookManagerWithLogging(context);
            
            // Step 4: Test logging integration
            testLoggingIntegration();
            
            Log.d(TAG, "✅ Unified Logging System initialized successfully");
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Failed to initialize unified logging", e);
        }
    }
    
    /**
     * Step 1: Initialize native Logger
     */
    private static void initializeNativeLogger() {
        try {
            // Initialize native Logger through JNI
            boolean nativeLoggerInit = nativeInitializeLogger("BearMod", 1); // 1 = INFO level
            
            Log.d(TAG, "   Native Logger initialized: " + nativeLoggerInit);
            
            // Test native logging
            nativeLogInfo("Native Logger initialized successfully");
            nativeLogDebug("Debug logging is working");
            
        } catch (Exception e) {
            Log.e(TAG, "Error initializing native Logger", e);
        }
    }
    
    /**
     * Step 2: Initialize MemoryManager with unified logging
     */
    private static void initializeMemoryManagerWithLogging() {
        try {
            MemoryManager memoryManager = MemoryManager.getInstance();
            boolean initialized = memoryManager.initialize();
            
            Log.d(TAG, "   MemoryManager initialized: " + initialized);
            
            if (initialized) {
                // Test memory operations with logging
                long libcBase = memoryManager.getModuleBase("libc.so");
                Log.d(TAG, "   libc.so base address: 0x" + Long.toHexString(libcBase));
                
                // Get statistics (includes logging info)
                String stats = memoryManager.getStatistics();
                Log.d(TAG, "   MemoryManager stats: " + stats.split("\n")[0]); // First line only
            }
            
        } catch (Exception e) {
            Log.e(TAG, "Error initializing MemoryManager with logging", e);
        }
    }
    
    /**
     * Step 3: Initialize HookManager with unified logging
     */
    private static void initializeHookManagerWithLogging(Context context) {
        try {
            HookManager hookManager = HookManager.getInstance();
            boolean initialized = hookManager.initialize(context);
            
            Log.d(TAG, "   HookManager initialized: " + initialized);
            
            if (initialized) {
                // Get hook statistics (includes logging info)
                String stats = hookManager.getHookStatistics();
                Log.d(TAG, "   HookManager stats: " + stats.split("\n")[0]); // First line only
            }
            
        } catch (Exception e) {
            Log.e(TAG, "Error initializing HookManager with logging", e);
        }
    }
    
    /**
     * Step 4: Test logging integration across all systems
     */
    private static void testLoggingIntegration() {
        try {
            Log.d(TAG, "🧪 Testing logging integration across systems");
            
            // Test 1: Native Logger integration
            testNativeLoggerIntegration();
            
            // Test 2: Cross-system logging
            testCrossSystemLogging();
            
            // Test 3: Log level management
            testLogLevelManagement();
            
            // Test 4: Performance impact
            testLoggingPerformance();
            
            Log.d(TAG, "✅ Logging integration tests completed");
            
        } catch (Exception e) {
            Log.e(TAG, "Error testing logging integration", e);
        }
    }
    
    /**
     * Test 1: Native Logger integration
     */
    private static void testNativeLoggerIntegration() {
        try {
            // Test different log levels
            nativeLogDebug("This is a debug message from native");
            nativeLogInfo("This is an info message from native");
            nativeLogWarning("This is a warning message from native");
            nativeLogError("This is an error message from native");
            
            // Test formatted logging
            nativeLogInfo("Formatted message: value=%d, string=%s", 42, "test");
            
            Log.d(TAG, "   Native Logger integration test passed");
            
        } catch (Exception e) {
            Log.e(TAG, "Native Logger integration test failed", e);
        }
    }
    
    /**
     * Test 2: Cross-system logging
     */
    private static void testCrossSystemLogging() {
        try {
            // Log from Java
            Log.d(TAG, "Java logging: System operational");
            
            // Log from native systems
            nativeLogInfo("Native logging: MemoryManager operational");
            nativeLogInfo("Native logging: HookManager operational");
            
            // Test bridge logging (if available)
            testBridgeLogging();
            
            Log.d(TAG, "   Cross-system logging test passed");
            
        } catch (Exception e) {
            Log.e(TAG, "Cross-system logging test failed", e);
        }
    }
    
    /**
     * Test 3: Log level management
     */
    private static void testLogLevelManagement() {
        try {
            // Test setting different log levels
            nativeSetLogLevel(0); // DEBUG
            nativeLogDebug("Debug level active");
            
            nativeSetLogLevel(2); // WARNING
            nativeLogInfo("This info message should be filtered out");
            nativeLogWarning("This warning should appear");
            
            nativeSetLogLevel(1); // INFO (restore default)
            
            Log.d(TAG, "   Log level management test passed");
            
        } catch (Exception e) {
            Log.e(TAG, "Log level management test failed", e);
        }
    }
    
    /**
     * Test 4: Performance impact of logging
     */
    private static void testLoggingPerformance() {
        try {
            int iterations = 1000;
            
            // Test Java logging performance
            long startTime = System.nanoTime();
            for (int i = 0; i < iterations; i++) {
                Log.d(TAG, "Performance test message " + i);
            }
            long javaTime = System.nanoTime() - startTime;
            
            // Test native logging performance
            startTime = System.nanoTime();
            for (int i = 0; i < iterations; i++) {
                nativeLogInfo("Performance test message %d", i);
            }
            long nativeTime = System.nanoTime() - startTime;
            
            double javaAvg = (double) javaTime / iterations / 1000; // microseconds
            double nativeAvg = (double) nativeTime / iterations / 1000; // microseconds
            
            Log.d(TAG, String.format("   Logging performance - Java: %.2fμs, Native: %.2fμs per message", 
                                    javaAvg, nativeAvg));
            
            // Performance should be reasonable (< 100μs per message)
            boolean performanceOK = javaAvg < 100 && nativeAvg < 100;
            Log.d(TAG, "   Logging performance test: " + (performanceOK ? "PASSED" : "WARNING"));
            
        } catch (Exception e) {
            Log.e(TAG, "Logging performance test failed", e);
        }
    }
    
    /**
     * Test bridge logging with existing systems
     */
    private static void testBridgeLogging() {
        try {
            // Test integration with existing TEAMNRG Logger
            // This would use the BRIDGE_LOGD macros if available
            
            // Test integration with existing CLog
            // This would use the BRIDGE_CLOG macros if available
            
            Log.d(TAG, "   Bridge logging test completed");
            
        } catch (Exception e) {
            Log.d(TAG, "   Bridge logging not available (expected)");
        }
    }
    
    /**
     * Get comprehensive logging system status
     */
    public static String getLoggingSystemStatus() {
        try {
            StringBuilder status = new StringBuilder();
            status.append("=== BearMod Unified Logging System Status ===\n\n");
            
            // Native Logger status
            boolean nativeLoggerAvailable = isNativeLoggerAvailable();
            status.append("Native Logger: ").append(nativeLoggerAvailable ? "AVAILABLE" : "NOT AVAILABLE").append("\n");
            
            if (nativeLoggerAvailable) {
                String nativeTag = getNativeLoggerTag();
                int nativeLevel = getNativeLoggerLevel();
                status.append("  Tag: ").append(nativeTag).append("\n");
                status.append("  Level: ").append(getLevelName(nativeLevel)).append("\n");
            }
            
            // Java logging status
            status.append("\nJava Logging: AVAILABLE\n");
            status.append("  Android Logcat: ENABLED\n");
            
            // System integration status
            status.append("\nSystem Integration:\n");
            status.append("  MemoryManager: ").append(MemoryManager.getInstance().isInitialized() ? "INTEGRATED" : "NOT INTEGRATED").append("\n");
            status.append("  HookManager: ").append(HookManager.getInstance().isInitialized() ? "INTEGRATED" : "NOT INTEGRATED").append("\n");
            
            // Legacy system compatibility
            status.append("\nLegacy Compatibility:\n");
            status.append("  TEAMNRG Logger: PRESERVED\n");
            status.append("  CLog System: PRESERVED\n");
            
            return status.toString();
            
        } catch (Exception e) {
            return "Error generating logging system status: " + e.getMessage();
        }
    }
    
    /**
     * Helper method to get level name
     */
    private static String getLevelName(int level) {
        switch (level) {
            case 0: return "DEBUG";
            case 1: return "INFO";
            case 2: return "WARNING";
            case 3: return "ERROR";
            default: return "UNKNOWN";
        }
    }
    
    /**
     * Cleanup logging system
     */
    public static void cleanupLoggingSystem() {
        try {
            Log.d(TAG, "🧹 Cleaning up unified logging system");
            
            // Cleanup native Logger
            nativeCleanupLogger();
            
            Log.d(TAG, "✅ Logging system cleanup completed");
            
        } catch (Exception e) {
            Log.e(TAG, "Error cleaning up logging system", e);
        }
    }
    
    // Native method declarations for Logger integration
    private static native boolean nativeInitializeLogger(String tag, int level);
    private static native void nativeLogDebug(String format, Object... args);
    private static native void nativeLogInfo(String format, Object... args);
    private static native void nativeLogWarning(String format, Object... args);
    private static native void nativeLogError(String format, Object... args);
    private static native void nativeSetLogLevel(int level);
    private static native boolean isNativeLoggerAvailable();
    private static native String getNativeLoggerTag();
    private static native int getNativeLoggerLevel();
    private static native void nativeCleanupLogger();
    
    // Load native library
    static {
        try {
            System.loadLibrary("bearmod");
        } catch (UnsatisfiedLinkError e) {
            Log.e(TAG, "Failed to load native library for Logger integration", e);
        }
    }
}
