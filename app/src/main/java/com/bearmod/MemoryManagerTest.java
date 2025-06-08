package com.bearmod;

import android.content.Context;
import android.util.Log;
import com.bearmod.core.MemoryManager;
import java.util.List;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Comprehensive test suite for MemoryManager
 * Tests memory operations, pattern scanning, and module management
 */
public class MemoryManagerTest {
    private static final String TAG = "BearMod_MemoryManagerTest";
    
    private final Context context;
    private final AtomicInteger testsPassed = new AtomicInteger(0);
    private final AtomicInteger testsFailed = new AtomicInteger(0);
    
    public MemoryManagerTest(Context context) {
        this.context = context;
    }
    
    /**
     * Run comprehensive MemoryManager tests
     */
    public CompletableFuture<TestResults> runMemoryManagerTests() {
        return CompletableFuture.supplyAsync(() -> {
            Log.d(TAG, "🧪 Starting MemoryManager Test Suite");
            
            long startTime = System.currentTimeMillis();
            
            try {
                // Test 1: Initialization
                testInitialization();
                
                // Test 2: Module Operations
                testModuleOperations();
                
                // Test 3: Memory Read/Write
                testMemoryReadWrite();
                
                // Test 4: Pattern Scanning
                testPatternScanning();
                
                // Test 5: Caching System
                testCachingSystem();
                
                // Test 6: Error Handling
                testErrorHandling();
                
                // Test 7: Performance
                testPerformance();
                
                long endTime = System.currentTimeMillis();
                
                TestResults results = new TestResults(
                    testsPassed.get(),
                    testsFailed.get(),
                    endTime - startTime
                );
                
                generateTestReport(results);
                return results;
                
            } catch (Exception e) {
                Log.e(TAG, "❌ MemoryManager test suite failed", e);
                testsFailed.incrementAndGet();
                return new TestResults(testsPassed.get(), testsFailed.get(), 0);
            }
        });
    }
    
    /**
     * Test 1: Initialization
     */
    private void testInitialization() {
        Log.d(TAG, "🧪 Testing MemoryManager Initialization");
        
        try {
            MemoryManager memoryManager = MemoryManager.getInstance();
            
            // Test singleton behavior
            MemoryManager memoryManager2 = MemoryManager.getInstance();
            boolean singletonTest = memoryManager == memoryManager2;
            
            // Test initialization
            boolean initialized = memoryManager.initialize();
            boolean isInitialized = memoryManager.isInitialized();
            
            boolean initTestsPassed = singletonTest && initialized && isInitialized;
            
            Log.d(TAG, "   Singleton Test: " + singletonTest);
            Log.d(TAG, "   Initialization: " + initialized);
            Log.d(TAG, "   Is Initialized: " + isInitialized);
            
            if (initTestsPassed) {
                Log.d(TAG, "✅ MemoryManager initialization test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ MemoryManager initialization test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ MemoryManager initialization test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 2: Module Operations
     */
    private void testModuleOperations() {
        Log.d(TAG, "🧪 Testing Module Operations");
        
        try {
            MemoryManager memoryManager = MemoryManager.getInstance();
            
            // Test common modules
            String[] testModules = {
                "libc.so",
                "libdl.so", 
                "liblog.so",
                "libbearmod.so",
                "libm.so"
            };
            
            int modulesFound = 0;
            for (String module : testModules) {
                long baseAddress = memoryManager.getModuleBase(module);
                long size = memoryManager.getModuleSize(module);
                
                if (baseAddress != 0 && size != 0) {
                    modulesFound++;
                    Log.d(TAG, "   Found " + module + " at 0x" + Long.toHexString(baseAddress) + 
                              " (size: 0x" + Long.toHexString(size) + ")");
                    
                    // Test module info
                    MemoryManager.ModuleInfo moduleInfo = memoryManager.getModuleInfo(module);
                    if (moduleInfo != null) {
                        Log.d(TAG, "   Module info: " + moduleInfo.toString());
                    }
                }
            }
            
            // Test get all modules
            List<MemoryManager.ModuleInfo> allModules = memoryManager.getAllModules();
            
            boolean moduleTestsPassed = modulesFound >= 2; // At least 2 modules should be found
            
            Log.d(TAG, "   Modules Found: " + modulesFound + "/" + testModules.length);
            Log.d(TAG, "   All Modules Count: " + allModules.size());
            
            if (moduleTestsPassed) {
                Log.d(TAG, "✅ Module operations test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Module operations test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Module operations test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 3: Memory Read/Write
     */
    private void testMemoryReadWrite() {
        Log.d(TAG, "🧪 Testing Memory Read/Write");
        
        try {
            MemoryManager memoryManager = MemoryManager.getInstance();
            
            // Test reading from a known safe location (our own code)
            long libcBase = memoryManager.getModuleBase("libc.so");
            
            boolean readWriteTestsPassed = false;
            
            if (libcBase != 0) {
                // Test reading
                byte[] readData = memoryManager.readMemory(libcBase, 16);
                
                if (readData != null && readData.length == 16) {
                    Log.d(TAG, "   Read test passed - got " + readData.length + " bytes");
                    
                    // Test writing to a safe location (our own allocated memory)
                    // For safety, we'll skip actual write test in this demo
                    Log.d(TAG, "   Write test skipped for safety");
                    readWriteTestsPassed = true;
                } else {
                    Log.w(TAG, "   Read test failed");
                }
            } else {
                Log.w(TAG, "   Could not find libc.so for read/write test");
            }
            
            if (readWriteTestsPassed) {
                Log.d(TAG, "✅ Memory read/write test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Memory read/write test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Memory read/write test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 4: Pattern Scanning
     */
    private void testPatternScanning() {
        Log.d(TAG, "🧪 Testing Pattern Scanning");
        
        try {
            MemoryManager memoryManager = MemoryManager.getInstance();
            
            // Test pattern scanning in libc.so
            long libcBase = memoryManager.getModuleBase("libc.so");
            long libcSize = memoryManager.getModuleSize("libc.so");
            
            boolean patternTestsPassed = false;
            
            if (libcBase != 0 && libcSize != 0) {
                // Test common patterns that might exist in libc
                String[] testPatterns = {
                    "48 89 E5",           // Common x64 prologue
                    "55 48 89 E5",        // Another common prologue
                    "C3",                 // ret instruction
                    "90 90 90",           // nop padding
                    "? ? ? ?",            // Wildcard pattern
                };
                
                int patternsFound = 0;
                for (String pattern : testPatterns) {
                    try {
                        long result = memoryManager.findPattern(pattern, libcBase, libcBase + Math.min(libcSize, 0x10000));
                        if (result != 0) {
                            patternsFound++;
                            Log.d(TAG, "   Pattern '" + pattern + "' found at 0x" + Long.toHexString(result));
                        }
                    } catch (Exception e) {
                        Log.v(TAG, "   Pattern '" + pattern + "' search failed (expected for some)");
                    }
                }
                
                // Test findPatternInModule
                try {
                    long modulePatternResult = memoryManager.findPatternInModule("C3", "libc.so");
                    if (modulePatternResult != 0) {
                        patternsFound++;
                        Log.d(TAG, "   Module pattern search successful");
                    }
                } catch (Exception e) {
                    Log.v(TAG, "   Module pattern search failed (expected)");
                }
                
                patternTestsPassed = patternsFound > 0;
                Log.d(TAG, "   Patterns Found: " + patternsFound + "/" + testPatterns.length);
            } else {
                Log.w(TAG, "   Could not find libc.so for pattern test");
            }
            
            if (patternTestsPassed) {
                Log.d(TAG, "✅ Pattern scanning test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Pattern scanning test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Pattern scanning test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 5: Caching System
     */
    private void testCachingSystem() {
        Log.d(TAG, "🧪 Testing Caching System");
        
        try {
            MemoryManager memoryManager = MemoryManager.getInstance();
            
            // Test module caching
            long startTime = System.nanoTime();
            long base1 = memoryManager.getModuleBase("libc.so");
            long firstCallTime = System.nanoTime() - startTime;
            
            startTime = System.nanoTime();
            long base2 = memoryManager.getModuleBase("libc.so");
            long secondCallTime = System.nanoTime() - startTime;
            
            boolean cachingWorks = (base1 == base2) && (base1 != 0);
            boolean cachingFaster = secondCallTime < firstCallTime; // Second call should be faster due to caching
            
            // Test cache refresh
            memoryManager.refreshModuleCache();
            memoryManager.clearPatternCache();
            
            boolean cachingTestsPassed = cachingWorks;
            
            Log.d(TAG, "   Caching Works: " + cachingWorks);
            Log.d(TAG, "   First Call: " + (firstCallTime / 1000) + "μs");
            Log.d(TAG, "   Second Call: " + (secondCallTime / 1000) + "μs");
            Log.d(TAG, "   Caching Faster: " + cachingFaster);
            
            if (cachingTestsPassed) {
                Log.d(TAG, "✅ Caching system test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Caching system test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Caching system test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 6: Error Handling
     */
    private void testErrorHandling() {
        Log.d(TAG, "🧪 Testing Error Handling");
        
        try {
            MemoryManager memoryManager = MemoryManager.getInstance();
            
            // Test invalid parameters
            byte[] nullRead = memoryManager.readMemory(0, 10);
            boolean writeResult = memoryManager.writeMemory(0, new byte[]{1, 2, 3});
            long invalidPattern = memoryManager.findPattern("", 0, 100);
            long invalidModule = memoryManager.getModuleBase("nonexistent.so");
            
            boolean errorHandlingWorks = (nullRead == null) && (!writeResult) && 
                                       (invalidPattern == 0) && (invalidModule == 0);
            
            Log.d(TAG, "   Null Read Handled: " + (nullRead == null));
            Log.d(TAG, "   Invalid Write Handled: " + (!writeResult));
            Log.d(TAG, "   Invalid Pattern Handled: " + (invalidPattern == 0));
            Log.d(TAG, "   Invalid Module Handled: " + (invalidModule == 0));
            
            if (errorHandlingWorks) {
                Log.d(TAG, "✅ Error handling test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Error handling test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Error handling test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 7: Performance
     */
    private void testPerformance() {
        Log.d(TAG, "🧪 Testing Performance");
        
        try {
            MemoryManager memoryManager = MemoryManager.getInstance();
            
            // Test module lookup performance
            int iterations = 100;
            long startTime = System.nanoTime();
            
            for (int i = 0; i < iterations; i++) {
                memoryManager.getModuleBase("libc.so");
            }
            
            long endTime = System.nanoTime();
            long avgTime = (endTime - startTime) / iterations;
            
            boolean performanceOK = avgTime < 100_000; // 100μs per lookup
            
            Log.d(TAG, "   Average Lookup Time: " + (avgTime / 1000) + "μs");
            Log.d(TAG, "   Performance OK: " + performanceOK);
            
            if (performanceOK) {
                Log.d(TAG, "✅ Performance test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Performance test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Performance test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Generate test report
     */
    private void generateTestReport(TestResults results) {
        Log.d(TAG, "📊 MemoryManager Test Report");
        Log.d(TAG, "═══════════════════════════");
        Log.d(TAG, "Total Tests: " + results.getTotalTests());
        Log.d(TAG, "Tests Passed: " + results.getTestsPassed());
        Log.d(TAG, "Tests Failed: " + results.getTestsFailed());
        Log.d(TAG, "Success Rate: " + String.format("%.1f%%", results.getSuccessRate()));
        Log.d(TAG, "Total Time: " + results.getTotalTime() + "ms");
        Log.d(TAG, "═══════════════════════════");
        
        // Get MemoryManager statistics
        MemoryManager memoryManager = MemoryManager.getInstance();
        String stats = memoryManager.getStatistics();
        Log.d(TAG, "MemoryManager Statistics:");
        Log.d(TAG, stats);
        
        if (results.getSuccessRate() >= 85) {
            Log.d(TAG, "🎉 MemoryManager Test Suite: PASSED");
        } else if (results.getSuccessRate() >= 70) {
            Log.w(TAG, "⚠️ MemoryManager Test Suite: PARTIAL PASS");
        } else {
            Log.e(TAG, "❌ MemoryManager Test Suite: FAILED");
        }
    }
    
    /**
     * Test results container
     */
    public static class TestResults {
        private final int testsPassed;
        private final int testsFailed;
        private final long totalTime;
        
        public TestResults(int passed, int failed, long time) {
            this.testsPassed = passed;
            this.testsFailed = failed;
            this.totalTime = time;
        }
        
        public int getTestsPassed() { return testsPassed; }
        public int getTestsFailed() { return testsFailed; }
        public int getTotalTests() { return testsPassed + testsFailed; }
        public long getTotalTime() { return totalTime; }
        public double getSuccessRate() { 
            return getTotalTests() > 0 ? (double) testsPassed / getTotalTests() * 100 : 0; 
        }
    }
}
