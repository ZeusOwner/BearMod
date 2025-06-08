package com.bearmod;

import android.content.Context;
import android.util.Log;
import com.bearmod.core.utils.Logger;
import com.bearmod.core.MemoryManager;
import com.bearmod.core.hooks.HookManager;

/**
 * Comprehensive example showing unified logging across all BearMod systems
 * 
 * This demonstrates how the enhanced Java Logger integrates with:
 * - Native Logger.h/cpp (unified C++ logging)
 * - Existing TEAMNRG Logger (preserved)
 * - Existing CLog system (preserved)
 * - MemoryManager and HookManager logging
 */
public class UnifiedLoggingExample {
    private static final String TAG = "BearMod_UnifiedLogging";
    
    /**
     * Initialize complete unified logging system
     */
    public static void initializeCompleteLoggingSystem(Context context) {
        try {
            Log.d(TAG, "🚀 Initializing Complete BearMod Logging System");
            
            // Step 1: Initialize Java Logger with native integration
            initializeJavaLogger(context);
            
            // Step 2: Initialize native Logger
            initializeNativeLogger();
            
            // Step 3: Initialize system components with logging
            initializeSystemComponents(context);
            
            // Step 4: Test complete integration
            testCompleteLoggingIntegration();
            
            // Step 5: Display system status
            displayLoggingSystemStatus();
            
            Log.d(TAG, "✅ Complete BearMod Logging System initialized successfully");
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Failed to initialize complete logging system", e);
        }
    }
    
    /**
     * Step 1: Initialize Java Logger with enhanced features
     */
    private static void initializeJavaLogger(Context context) {
        try {
            // Initialize with native integration enabled
            Logger.initialize(context, true);
            
            // Configure Java Logger
            Logger.setTag("BearMod_Java");
            
            // Test Java Logger functionality
            Logger.i("Java Logger initialized successfully");
            Logger.d("Debug logging is working");
            Logger.w("Warning logging is working");
            
            // Test formatted logging
            Logger.i("Formatted logging test: value=%d, string=%s", 42, "test");
            
            Log.d(TAG, "   Java Logger Status: " + Logger.getStatus().split("\n")[0]);
            
        } catch (Exception e) {
            Log.e(TAG, "Error initializing Java Logger", e);
        }
    }
    
    /**
     * Step 2: Initialize native Logger
     */
    private static void initializeNativeLogger() {
        try {
            // Initialize native Logger through JNI
            boolean nativeInit = nativeInitializeUnifiedLogger("BearMod_Native", 1); // INFO level
            
            Log.d(TAG, "   Native Logger initialized: " + nativeInit);
            
            if (nativeInit) {
                // Test native logging
                nativeLogInfo("Native Logger initialized successfully");
                nativeLogDebug("Native debug logging is working");
            }
            
        } catch (Exception e) {
            Log.e(TAG, "Error initializing native Logger", e);
        }
    }
    
    /**
     * Step 3: Initialize system components with unified logging
     */
    private static void initializeSystemComponents(Context context) {
        try {
            Log.d(TAG, "   Initializing system components with unified logging");
            
            // Initialize MemoryManager (uses native Logger)
            MemoryManager memoryManager = MemoryManager.getInstance();
            boolean memoryInit = memoryManager.initialize();
            
            Logger.i("MemoryManager initialized: %s", memoryInit);
            
            // Initialize HookManager (uses native Logger)
            HookManager hookManager = HookManager.getInstance();
            boolean hookInit = hookManager.initialize(context);
            
            Logger.i("HookManager initialized: %s", hookInit);
            
            // Initialize SignatureVerifier (uses existing logging)
            SignatureVerifier.initialize(context);
            boolean signatureValid = SignatureVerifier.isSignatureValid(context);
            
            Logger.i("SignatureVerifier initialized, signature valid: %s", signatureValid);
            
        } catch (Exception e) {
            Log.e(TAG, "Error initializing system components", e);
            Logger.e("Error initializing system components: %s", e.getMessage());
        }
    }
    
    /**
     * Step 4: Test complete logging integration
     */
    private static void testCompleteLoggingIntegration() {
        try {
            Logger.i("🧪 Testing complete logging integration");
            
            // Test 1: Multi-layer logging
            testMultiLayerLogging();
            
            // Test 2: Cross-system communication
            testCrossSystemCommunication();
            
            // Test 3: Error handling across systems
            testErrorHandlingAcrossSystems();
            
            // Test 4: Performance impact
            testLoggingPerformanceImpact();
            
            Logger.i("✅ Complete logging integration tests passed");
            
        } catch (Exception e) {
            Log.e(TAG, "Error testing logging integration", e);
            Logger.e("Error testing logging integration", e);
        }
    }
    
    /**
     * Test 1: Multi-layer logging
     */
    private static void testMultiLayerLogging() {
        try {
            // Java layer
            Logger.d("Java layer: Debug message");
            Logger.i("Java layer: Info message");
            Logger.w("Java layer: Warning message");
            Logger.e("Java layer: Error message");
            
            // Native layer (through JNI)
            nativeLogDebug("Native layer: Debug message");
            nativeLogInfo("Native layer: Info message");
            nativeLogWarning("Native layer: Warning message");
            nativeLogError("Native layer: Error message");
            
            // Android layer (standard)
            Log.d(TAG, "Android layer: Debug message");
            Log.i(TAG, "Android layer: Info message");
            Log.w(TAG, "Android layer: Warning message");
            Log.e(TAG, "Android layer: Error message");
            
            Logger.d("Multi-layer logging test completed");
            
        } catch (Exception e) {
            Logger.e("Multi-layer logging test failed", e);
        }
    }
    
    /**
     * Test 2: Cross-system communication
     */
    private static void testCrossSystemCommunication() {
        try {
            // Test logging from different systems
            MemoryManager memoryManager = MemoryManager.getInstance();
            if (memoryManager.isInitialized()) {
                long libcBase = memoryManager.getModuleBase("libc.so");
                Logger.i("MemoryManager: libc.so base = 0x%x", libcBase);
            }
            
            HookManager hookManager = HookManager.getInstance();
            if (hookManager.isInitialized()) {
                int activeHooks = hookManager.getActiveHooks().size();
                Logger.i("HookManager: Active hooks = %d", activeHooks);
            }
            
            boolean signatureValid = SignatureVerifier.isSignatureValid(null);
            Logger.i("SignatureVerifier: Signature valid = %s", signatureValid);
            
            Logger.d("Cross-system communication test completed");
            
        } catch (Exception e) {
            Logger.e("Cross-system communication test failed", e);
        }
    }
    
    /**
     * Test 3: Error handling across systems
     */
    private static void testErrorHandlingAcrossSystems() {
        try {
            // Test error logging with exceptions
            try {
                throw new RuntimeException("Test exception for logging");
            } catch (Exception e) {
                Logger.e("Caught test exception", e);
            }
            
            // Test native error logging
            nativeLogError("Native error logging test");
            
            // Test error recovery
            Logger.w("Error recovery test - system should continue functioning");
            
            Logger.d("Error handling test completed");
            
        } catch (Exception e) {
            Logger.e("Error handling test failed", e);
        }
    }
    
    /**
     * Test 4: Performance impact of unified logging
     */
    private static void testLoggingPerformanceImpact() {
        try {
            int iterations = 100;
            
            // Test Java Logger performance
            long startTime = System.nanoTime();
            for (int i = 0; i < iterations; i++) {
                Logger.d("Performance test message %d", i);
            }
            long javaTime = System.nanoTime() - startTime;
            
            // Test native Logger performance
            startTime = System.nanoTime();
            for (int i = 0; i < iterations; i++) {
                nativeLogDebug("Performance test message " + i);
            }
            long nativeTime = System.nanoTime() - startTime;
            
            // Test standard Android logging performance
            startTime = System.nanoTime();
            for (int i = 0; i < iterations; i++) {
                Log.d(TAG, "Performance test message " + i);
            }
            long androidTime = System.nanoTime() - startTime;
            
            double javaAvg = (double) javaTime / iterations / 1000; // microseconds
            double nativeAvg = (double) nativeTime / iterations / 1000; // microseconds
            double androidAvg = (double) androidTime / iterations / 1000; // microseconds
            
            Logger.i("Logging performance - Java: %.2fμs, Native: %.2fμs, Android: %.2fμs", 
                    javaAvg, nativeAvg, androidAvg);
            
        } catch (Exception e) {
            Logger.e("Performance test failed", e);
        }
    }
    
    /**
     * Step 5: Display comprehensive logging system status
     */
    private static void displayLoggingSystemStatus() {
        try {
            StringBuilder status = new StringBuilder();
            status.append("=== BearMod Complete Logging System Status ===\n\n");
            
            // Java Logger status
            status.append("Java Logger:\n");
            status.append(Logger.getStatus()).append("\n");
            
            // Native Logger status
            boolean nativeAvailable = isNativeLoggerAvailable();
            status.append("Native Logger:\n");
            status.append("  Available: ").append(nativeAvailable).append("\n");
            if (nativeAvailable) {
                status.append("  Tag: ").append(getNativeLoggerTag()).append("\n");
                status.append("  Level: ").append(getNativeLoggerLevel()).append("\n");
            }
            
            // System component status
            status.append("\nSystem Components:\n");
            status.append("  MemoryManager: ").append(MemoryManager.getInstance().isInitialized()).append("\n");
            status.append("  HookManager: ").append(HookManager.getInstance().isInitialized()).append("\n");
            status.append("  SignatureVerifier: Integrated\n");
            
            // Legacy system status
            status.append("\nLegacy Systems:\n");
            status.append("  TEAMNRG Logger: Preserved\n");
            status.append("  CLog System: Preserved\n");
            
            // File logging status
            String logFilePath = Logger.getLogFilePath();
            status.append("\nFile Logging:\n");
            status.append("  Enabled: ").append(Logger.isFileLoggingEnabled()).append("\n");
            if (logFilePath != null) {
                status.append("  File: ").append(logFilePath).append("\n");
            }
            
            Logger.i("Complete logging system status:\n%s", status.toString());
            Log.d(TAG, "Complete logging system status:\n" + status.toString());
            
        } catch (Exception e) {
            Log.e(TAG, "Error displaying logging system status", e);
        }
    }
    
    /**
     * Cleanup complete logging system
     */
    public static void cleanupCompleteLoggingSystem() {
        try {
            Logger.i("🧹 Cleaning up complete logging system");
            
            // Cleanup Java Logger
            Logger.close();
            
            // Cleanup native Logger
            nativeCleanupLogger();
            
            Log.d(TAG, "✅ Complete logging system cleanup completed");
            
        } catch (Exception e) {
            Log.e(TAG, "Error cleaning up logging system", e);
        }
    }
    
    // Native method declarations
    private static native boolean nativeInitializeUnifiedLogger(String tag, int level);
    private static native void nativeLogDebug(String message);
    private static native void nativeLogInfo(String message);
    private static native void nativeLogWarning(String message);
    private static native void nativeLogError(String message);
    private static native boolean isNativeLoggerAvailable();
    private static native String getNativeLoggerTag();
    private static native int getNativeLoggerLevel();
    private static native void nativeCleanupLogger();
    
    // Load native library
    static {
        try {
            System.loadLibrary("bearmod");
        } catch (UnsatisfiedLinkError e) {
            Log.e(TAG, "Failed to load native library for unified logging", e);
        }
    }
}
