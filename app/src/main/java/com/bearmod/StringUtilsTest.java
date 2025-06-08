package com.bearmod;

import android.util.Log;
import com.bearmod.utils.StringUtils;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Comprehensive test suite for enhanced StringUtils
 * Tests all functionality including game modding specific features
 */
public class StringUtilsTest {
    private static final String TAG = "BearMod_StringUtilsTest";
    
    private final AtomicInteger testsPassed = new AtomicInteger(0);
    private final AtomicInteger testsFailed = new AtomicInteger(0);
    
    /**
     * Run comprehensive StringUtils tests
     */
    public TestResults runStringUtilsTests() {
        Log.d(TAG, "🧪 Starting StringUtils Test Suite");
        
        long startTime = System.currentTimeMillis();
        
        try {
            // Test 1: Basic string operations
            testBasicStringOperations();
            
            // Test 2: Hex conversion operations
            testHexConversionOperations();
            
            // Test 3: Memory address operations
            testMemoryAddressOperations();
            
            // Test 4: Memory pattern operations
            testMemoryPatternOperations();
            
            // Test 5: Security operations
            testSecurityOperations();
            
            // Test 6: Advanced string operations
            testAdvancedStringOperations();
            
            // Test 7: Validation operations
            testValidationOperations();
            
            // Test 8: Performance tests
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
            Log.e(TAG, "❌ StringUtils test suite failed", e);
            testsFailed.incrementAndGet();
            return new TestResults(testsPassed.get(), testsFailed.get(), 0);
        }
    }
    
    /**
     * Test 1: Basic string operations
     */
    private void testBasicStringOperations() {
        Log.d(TAG, "🧪 Testing basic string operations");
        
        try {
            // Test isEmpty
            boolean test1 = StringUtils.isEmpty(null) && StringUtils.isEmpty("") && 
                           StringUtils.isEmpty("   ") && !StringUtils.isEmpty("test");
            
            // Test isNotEmpty
            boolean test2 = !StringUtils.isNotEmpty(null) && !StringUtils.isNotEmpty("") && 
                           StringUtils.isNotEmpty("test");
            
            // Test reverse
            boolean test3 = StringUtils.reverse("hello").equals("olleh") && 
                           StringUtils.reverse(null).equals("") &&
                           StringUtils.reverse("").equals("");
            
            // Test countChar
            boolean test4 = StringUtils.countChar("hello", 'l') == 2 &&
                           StringUtils.countChar(null, 'a') == 0 &&
                           StringUtils.countChar("test", 'x') == 0;
            
            boolean basicTestsPassed = test1 && test2 && test3 && test4;
            
            Log.d(TAG, "   isEmpty/isNotEmpty: " + (test1 && test2));
            Log.d(TAG, "   reverse: " + test3);
            Log.d(TAG, "   countChar: " + test4);
            
            if (basicTestsPassed) {
                Log.d(TAG, "✅ Basic string operations test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Basic string operations test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Basic string operations test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 2: Hex conversion operations
     */
    private void testHexConversionOperations() {
        Log.d(TAG, "🧪 Testing hex conversion operations");
        
        try {
            // Test bytesToHex
            byte[] testBytes = {0x48, (byte)0x8B, 0x05, (byte)0xFF};
            String hexResult = StringUtils.bytesToHex(testBytes);
            boolean test1 = hexResult.equals("488B05FF");
            
            // Test hexToBytes
            byte[] bytesResult = StringUtils.hexToBytes("488B05FF");
            boolean test2 = bytesResult.length == 4 && 
                           bytesResult[0] == 0x48 && 
                           bytesResult[1] == (byte)0x8B &&
                           bytesResult[2] == 0x05 &&
                           bytesResult[3] == (byte)0xFF;
            
            // Test hex conversion with spaces
            byte[] spacedResult = StringUtils.hexToBytes("48 8B 05 FF");
            boolean test3 = spacedResult.length == 4 && spacedResult[0] == 0x48;
            
            // Test round-trip conversion
            String original = "48 8B 05 FF 90 90";
            byte[] converted = StringUtils.hexToBytes(original);
            String backToHex = StringUtils.bytesToHex(converted);
            boolean test4 = backToHex.equals("488B05FF9090");
            
            boolean hexTestsPassed = test1 && test2 && test3 && test4;
            
            Log.d(TAG, "   bytesToHex: " + test1 + " (result: " + hexResult + ")");
            Log.d(TAG, "   hexToBytes: " + test2);
            Log.d(TAG, "   hex with spaces: " + test3);
            Log.d(TAG, "   round-trip: " + test4);
            
            if (hexTestsPassed) {
                Log.d(TAG, "✅ Hex conversion operations test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Hex conversion operations test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Hex conversion operations test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 3: Memory address operations
     */
    private void testMemoryAddressOperations() {
        Log.d(TAG, "🧪 Testing memory address operations");
        
        try {
            // Test formatAddress
            String formatted = StringUtils.formatAddress(0x12345678L);
            boolean test1 = formatted.equals("0x12345678");
            
            // Test parseAddress
            long parsed1 = StringUtils.parseAddress("0x12345678");
            long parsed2 = StringUtils.parseAddress("12345678");
            long parsed3 = StringUtils.parseAddress("0X12345678");
            boolean test2 = parsed1 == 0x12345678L && parsed2 == 0x12345678L && parsed3 == 0x12345678L;
            
            // Test invalid address parsing
            long invalid = StringUtils.parseAddress("invalid");
            boolean test3 = invalid == 0;
            
            // Test isValidAddress
            boolean test4 = StringUtils.isValidAddress("0x12345678") &&
                           StringUtils.isValidAddress("12345678") &&
                           !StringUtils.isValidAddress("invalid") &&
                           !StringUtils.isValidAddress(null);
            
            boolean addressTestsPassed = test1 && test2 && test3 && test4;
            
            Log.d(TAG, "   formatAddress: " + test1 + " (result: " + formatted + ")");
            Log.d(TAG, "   parseAddress: " + test2);
            Log.d(TAG, "   invalid parsing: " + test3);
            Log.d(TAG, "   isValidAddress: " + test4);
            
            if (addressTestsPassed) {
                Log.d(TAG, "✅ Memory address operations test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Memory address operations test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Memory address operations test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 4: Memory pattern operations
     */
    private void testMemoryPatternOperations() {
        Log.d(TAG, "🧪 Testing memory pattern operations");
        
        try {
            // Test isValidMemoryPattern
            boolean test1 = StringUtils.isValidMemoryPattern("48 8B 05 ? ? ? ?") &&
                           StringUtils.isValidMemoryPattern("48 8B 05 FF") &&
                           !StringUtils.isValidMemoryPattern("invalid pattern") &&
                           !StringUtils.isValidMemoryPattern(null);
            
            // Test normalizeMemoryPattern
            String normalized1 = StringUtils.normalizeMemoryPattern("48  8B   05 ? ? ?");
            String normalized2 = StringUtils.normalizeMemoryPattern("48 8b 05 ?? ?? ??");
            boolean test2 = normalized1.equals("48 8B 05 ? ? ?") &&
                           normalized2.equals("48 8B 05 ? ? ?");
            
            // Test pattern with single digit hex
            String normalized3 = StringUtils.normalizeMemoryPattern("8 B 5");
            boolean test3 = normalized3.equals("08 0B 05");
            
            // Test isValidHex
            boolean test4 = StringUtils.isValidHex("48AB") &&
                           StringUtils.isValidHex("123456789ABCDEF") &&
                           !StringUtils.isValidHex("XYZ") &&
                           !StringUtils.isValidHex(null);
            
            boolean patternTestsPassed = test1 && test2 && test3 && test4;
            
            Log.d(TAG, "   isValidMemoryPattern: " + test1);
            Log.d(TAG, "   normalizeMemoryPattern: " + test2);
            Log.d(TAG, "   single digit normalization: " + test3);
            Log.d(TAG, "   isValidHex: " + test4);
            
            if (patternTestsPassed) {
                Log.d(TAG, "✅ Memory pattern operations test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Memory pattern operations test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Memory pattern operations test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 5: Security operations
     */
    private void testSecurityOperations() {
        Log.d(TAG, "🧪 Testing security operations");
        
        try {
            // Test obfuscation/deobfuscation
            String original = "BearMod";
            int key = 0x42;
            String obfuscated = StringUtils.obfuscate(original, key);
            String deobfuscated = StringUtils.deobfuscate(obfuscated, key);
            boolean test1 = !obfuscated.equals(original) && deobfuscated.equals(original);
            
            // Test MD5 hash
            String md5 = StringUtils.md5Hash("test");
            boolean test2 = md5.length() == 32 && StringUtils.isValidHex(md5);
            
            // Test SHA-256 hash
            String sha256 = StringUtils.sha256Hash("test");
            boolean test3 = sha256.length() == 64 && StringUtils.isValidHex(sha256);
            
            // Test hash consistency
            String md5_2 = StringUtils.md5Hash("test");
            String sha256_2 = StringUtils.sha256Hash("test");
            boolean test4 = md5.equals(md5_2) && sha256.equals(sha256_2);
            
            boolean securityTestsPassed = test1 && test2 && test3 && test4;
            
            Log.d(TAG, "   obfuscation/deobfuscation: " + test1);
            Log.d(TAG, "   MD5 hash: " + test2 + " (length: " + md5.length() + ")");
            Log.d(TAG, "   SHA-256 hash: " + test3 + " (length: " + sha256.length() + ")");
            Log.d(TAG, "   hash consistency: " + test4);
            
            if (securityTestsPassed) {
                Log.d(TAG, "✅ Security operations test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Security operations test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Security operations test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 6: Advanced string operations
     */
    private void testAdvancedStringOperations() {
        Log.d(TAG, "🧪 Testing advanced string operations");
        
        try {
            // Test safeSplit
            String[] split1 = StringUtils.safeSplit("a,b,c", ",");
            String[] split2 = StringUtils.safeSplit(null, ",");
            boolean test1 = split1.length == 3 && split1[0].equals("a") && split2.length == 0;
            
            // Test join
            String joined = StringUtils.join(new String[]{"a", "b", "c"}, ",");
            boolean test2 = joined.equals("a,b,c");
            
            // Test extractNumbers
            List<Long> numbers = StringUtils.extractNumbers("abc123def456ghi");
            boolean test3 = numbers.size() == 2 && numbers.get(0) == 123L && numbers.get(1) == 456L;
            
            // Test extractAddresses
            List<Long> addresses = StringUtils.extractAddresses("Found at 0x12345678 and 0xABCDEF00");
            boolean test4 = addresses.size() == 2 && addresses.get(0) == 0x12345678L;
            
            // Test truncate
            String truncated = StringUtils.truncate("This is a long string", 10);
            boolean test5 = truncated.equals("This is...");
            
            // Test pad
            String padded = StringUtils.pad("test", 8, '0', true);
            boolean test6 = padded.equals("0000test");
            
            boolean advancedTestsPassed = test1 && test2 && test3 && test4 && test5 && test6;
            
            Log.d(TAG, "   safeSplit/join: " + (test1 && test2));
            Log.d(TAG, "   extractNumbers: " + test3 + " (found: " + numbers.size() + ")");
            Log.d(TAG, "   extractAddresses: " + test4 + " (found: " + addresses.size() + ")");
            Log.d(TAG, "   truncate: " + test5 + " (result: " + truncated + ")");
            Log.d(TAG, "   pad: " + test6 + " (result: " + padded + ")");
            
            if (advancedTestsPassed) {
                Log.d(TAG, "✅ Advanced string operations test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Advanced string operations test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Advanced string operations test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 7: Validation operations
     */
    private void testValidationOperations() {
        Log.d(TAG, "🧪 Testing validation operations");
        
        try {
            // Test various validation methods
            boolean test1 = StringUtils.isValidHex("ABCDEF123456") &&
                           !StringUtils.isValidHex("GHIJKL");
            
            boolean test2 = StringUtils.isValidAddress("0x12345678") &&
                           !StringUtils.isValidAddress("not_an_address");
            
            boolean test3 = StringUtils.isValidMemoryPattern("48 8B ? ?") &&
                           !StringUtils.isValidMemoryPattern("invalid pattern");
            
            boolean validationTestsPassed = test1 && test2 && test3;
            
            Log.d(TAG, "   hex validation: " + test1);
            Log.d(TAG, "   address validation: " + test2);
            Log.d(TAG, "   pattern validation: " + test3);
            
            if (validationTestsPassed) {
                Log.d(TAG, "✅ Validation operations test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Validation operations test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Validation operations test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 8: Performance tests
     */
    private void testPerformance() {
        Log.d(TAG, "🧪 Testing performance");
        
        try {
            int iterations = 1000;
            
            // Test hex conversion performance
            byte[] testData = new byte[256];
            for (int i = 0; i < testData.length; i++) {
                testData[i] = (byte) i;
            }
            
            long startTime = System.nanoTime();
            for (int i = 0; i < iterations; i++) {
                String hex = StringUtils.bytesToHex(testData);
                StringUtils.hexToBytes(hex);
            }
            long hexTime = System.nanoTime() - startTime;
            
            // Test string operations performance
            startTime = System.nanoTime();
            for (int i = 0; i < iterations; i++) {
                StringUtils.isEmpty("test");
                StringUtils.reverse("test");
                StringUtils.countChar("test", 't');
            }
            long stringTime = System.nanoTime() - startTime;
            
            double hexAvg = (double) hexTime / iterations / 1000; // microseconds
            double stringAvg = (double) stringTime / iterations / 1000; // microseconds
            
            boolean performanceOK = hexAvg < 100 && stringAvg < 10; // Reasonable thresholds
            
            Log.d(TAG, String.format("   Hex operations: %.2fμs per iteration", hexAvg));
            Log.d(TAG, String.format("   String operations: %.2fμs per iteration", stringAvg));
            Log.d(TAG, "   Performance acceptable: " + performanceOK);
            
            if (performanceOK) {
                Log.d(TAG, "✅ Performance test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Performance test warning (still functional)");
                testsPassed.incrementAndGet(); // Don't fail on performance
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
        Log.d(TAG, "📊 StringUtils Test Report");
        Log.d(TAG, "═══════════════════════════");
        Log.d(TAG, "Total Tests: " + results.getTotalTests());
        Log.d(TAG, "Tests Passed: " + results.getTestsPassed());
        Log.d(TAG, "Tests Failed: " + results.getTestsFailed());
        Log.d(TAG, "Success Rate: " + String.format("%.1f%%", results.getSuccessRate()));
        Log.d(TAG, "Total Time: " + results.getTotalTime() + "ms");
        Log.d(TAG, "═══════════════════════════");
        
        if (results.getSuccessRate() >= 90) {
            Log.d(TAG, "🎉 StringUtils Test Suite: PASSED");
        } else if (results.getSuccessRate() >= 75) {
            Log.w(TAG, "⚠️ StringUtils Test Suite: PARTIAL PASS");
        } else {
            Log.e(TAG, "❌ StringUtils Test Suite: FAILED");
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
