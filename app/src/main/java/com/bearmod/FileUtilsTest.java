package com.bearmod;

import android.content.Context;
import android.util.Log;
import com.bearmod.utils.FileUtils;
import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Comprehensive test suite for enhanced FileUtils
 * Tests all functionality including BearMod-specific features
 */
public class FileUtilsTest {
    private static final String TAG = "BearMod_FileUtilsTest";
    
    private final Context context;
    private final AtomicInteger testsPassed = new AtomicInteger(0);
    private final AtomicInteger testsFailed = new AtomicInteger(0);
    
    public FileUtilsTest(Context context) {
        this.context = context;
    }
    
    /**
     * Run comprehensive FileUtils tests
     */
    public TestResults runFileUtilsTests() {
        Log.d(TAG, "🧪 Starting FileUtils Test Suite");
        
        long startTime = System.currentTimeMillis();
        
        try {
            // Test 1: Basic file operations
            testBasicFileOperations();
            
            // Test 2: Binary file operations
            testBinaryFileOperations();
            
            // Test 3: Directory operations
            testDirectoryOperations();
            
            // Test 4: BearMod-specific directories
            testBearModDirectories();
            
            // Test 5: Backup and restore
            testBackupAndRestore();
            
            // Test 6: Archive operations
            testArchiveOperations();
            
            // Test 7: Encryption operations
            testEncryptionOperations();
            
            // Test 8: Utility functions
            testUtilityFunctions();
            
            long endTime = System.currentTimeMillis();
            
            TestResults results = new TestResults(
                testsPassed.get(),
                testsFailed.get(),
                endTime - startTime
            );
            
            generateTestReport(results);
            return results;
            
        } catch (Exception e) {
            Log.e(TAG, "❌ FileUtils test suite failed", e);
            testsFailed.incrementAndGet();
            return new TestResults(testsPassed.get(), testsFailed.get(), 0);
        }
    }
    
    /**
     * Test 1: Basic file operations
     */
    private void testBasicFileOperations() {
        Log.d(TAG, "🧪 Testing basic file operations");
        
        try {
            File testDir = new File(context.getCacheDir(), "fileutils_test");
            testDir.mkdirs();
            
            // Test text file operations
            File textFile = new File(testDir, "test.txt");
            String testContent = "Hello, BearMod!\nThis is a test file.\n";
            
            boolean writeSuccess = FileUtils.writeFile(textFile, testContent);
            String readContent = FileUtils.readFile(textFile);
            boolean contentMatches = testContent.equals(readContent);
            
            // Test file properties
            boolean isReadable = FileUtils.isReadable(textFile);
            boolean isWritable = FileUtils.isWritable(textFile);
            long fileSize = FileUtils.getFileSize(textFile);
            
            // Test copy operation
            File copyFile = new File(testDir, "test_copy.txt");
            boolean copySuccess = FileUtils.copyFile(textFile, copyFile);
            
            // Test MD5 calculation
            String md5Hash = FileUtils.calculateMD5(textFile);
            
            boolean basicTestsPassed = writeSuccess && contentMatches && isReadable && 
                                     isWritable && fileSize > 0 && copySuccess && !md5Hash.isEmpty();
            
            Log.d(TAG, "   Write/Read: " + (writeSuccess && contentMatches));
            Log.d(TAG, "   File properties: " + (isReadable && isWritable));
            Log.d(TAG, "   File size: " + fileSize + " bytes");
            Log.d(TAG, "   Copy operation: " + copySuccess);
            Log.d(TAG, "   MD5 hash: " + (!md5Hash.isEmpty() ? "Generated" : "Failed"));
            
            // Cleanup
            FileUtils.delete(testDir);
            
            if (basicTestsPassed) {
                Log.d(TAG, "✅ Basic file operations test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Basic file operations test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Basic file operations test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 2: Binary file operations
     */
    private void testBinaryFileOperations() {
        Log.d(TAG, "🧪 Testing binary file operations");
        
        try {
            File testDir = new File(context.getCacheDir(), "binary_test");
            testDir.mkdirs();
            
            // Create test binary data
            byte[] testData = new byte[256];
            for (int i = 0; i < testData.length; i++) {
                testData[i] = (byte) i;
            }
            
            // Test binary write/read
            File binaryFile = new File(testDir, "test.bin");
            boolean writeSuccess = FileUtils.writeBinaryFile(binaryFile, testData);
            byte[] readData = FileUtils.readBinaryFile(binaryFile);
            
            // Verify data integrity
            boolean dataMatches = testData.length == readData.length;
            if (dataMatches) {
                for (int i = 0; i < testData.length; i++) {
                    if (testData[i] != readData[i]) {
                        dataMatches = false;
                        break;
                    }
                }
            }
            
            boolean binaryTestsPassed = writeSuccess && dataMatches;
            
            Log.d(TAG, "   Binary write: " + writeSuccess);
            Log.d(TAG, "   Binary read: " + (readData.length > 0));
            Log.d(TAG, "   Data integrity: " + dataMatches);
            Log.d(TAG, "   Data size: " + readData.length + " bytes");
            
            // Cleanup
            FileUtils.delete(testDir);
            
            if (binaryTestsPassed) {
                Log.d(TAG, "✅ Binary file operations test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Binary file operations test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Binary file operations test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 3: Directory operations
     */
    private void testDirectoryOperations() {
        Log.d(TAG, "🧪 Testing directory operations");
        
        try {
            File testDir = new File(context.getCacheDir(), "dir_test");
            testDir.mkdirs();
            
            // Create test files
            File file1 = new File(testDir, "test1.txt");
            File file2 = new File(testDir, "test2.json");
            File file3 = new File(testDir, "test3.log");
            
            FileUtils.writeFile(file1, "Test 1");
            FileUtils.writeFile(file2, "Test 2");
            FileUtils.writeFile(file3, "Test 3");
            
            // Test file listing with extension filter
            List<File> txtFiles = FileUtils.listFilesWithExtension(testDir, ".txt");
            List<File> jsonFiles = FileUtils.listFilesWithExtension(testDir, ".json");
            
            // Test directory size calculation
            long dirSize = FileUtils.getDirectorySize(testDir);
            String formattedSize = FileUtils.formatFileSize(dirSize);
            
            // Test cleanup
            int cleanedFiles = FileUtils.cleanupTempFiles(testDir, 0); // Clean all files
            
            boolean directoryTestsPassed = txtFiles.size() == 1 && jsonFiles.size() == 1 && 
                                         dirSize > 0 && cleanedFiles == 3;
            
            Log.d(TAG, "   TXT files found: " + txtFiles.size());
            Log.d(TAG, "   JSON files found: " + jsonFiles.size());
            Log.d(TAG, "   Directory size: " + formattedSize);
            Log.d(TAG, "   Files cleaned: " + cleanedFiles);
            
            // Cleanup
            FileUtils.delete(testDir);
            
            if (directoryTestsPassed) {
                Log.d(TAG, "✅ Directory operations test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Directory operations test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Directory operations test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 4: BearMod-specific directories
     */
    private void testBearModDirectories() {
        Log.d(TAG, "🧪 Testing BearMod-specific directories");
        
        try {
            // Test BearMod directory structure
            File bearModDir = FileUtils.getBearModDir(context);
            File configDir = FileUtils.getConfigDir(context);
            File logsDir = FileUtils.getLogsDir(context);
            File backupDir = FileUtils.getBackupDir(context);
            File tempDir = FileUtils.getTempDir(context);
            
            boolean dirsExist = bearModDir.exists() && configDir.exists() && 
                              logsDir.exists() && backupDir.exists() && tempDir.exists();
            
            // Test creating files in each directory
            File configFile = new File(configDir, "test" + FileUtils.CONFIG_EXT);
            File logFile = new File(logsDir, "test" + FileUtils.LOG_EXT);
            
            boolean configWrite = FileUtils.writeFile(configFile, "{\"test\": true}");
            boolean logWrite = FileUtils.writeFile(logFile, "Test log entry");
            
            boolean bearModTestsPassed = dirsExist && configWrite && logWrite;
            
            Log.d(TAG, "   BearMod directories exist: " + dirsExist);
            Log.d(TAG, "   Config file write: " + configWrite);
            Log.d(TAG, "   Log file write: " + logWrite);
            Log.d(TAG, "   BearMod dir: " + bearModDir.getAbsolutePath());
            
            if (bearModTestsPassed) {
                Log.d(TAG, "✅ BearMod directories test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ BearMod directories test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ BearMod directories test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 5: Backup and restore
     */
    private void testBackupAndRestore() {
        Log.d(TAG, "🧪 Testing backup and restore");
        
        try {
            File testDir = new File(context.getCacheDir(), "backup_test");
            File backupDir = new File(testDir, "backup");
            testDir.mkdirs();
            backupDir.mkdirs();
            
            // Create original file
            File originalFile = new File(testDir, "original.txt");
            String originalContent = "Original content for backup test";
            FileUtils.writeFile(originalFile, originalContent);
            
            // Create backup
            boolean backupSuccess = FileUtils.createBackup(originalFile, backupDir);
            File backupFile = new File(backupDir, originalFile.getName() + FileUtils.BACKUP_EXT);
            
            // Modify original file
            String modifiedContent = "Modified content";
            FileUtils.writeFile(originalFile, modifiedContent);
            
            // Restore from backup
            boolean restoreSuccess = FileUtils.restoreFromBackup(backupFile, originalFile);
            String restoredContent = FileUtils.readFile(originalFile);
            
            boolean backupTestsPassed = backupSuccess && restoreSuccess && 
                                      originalContent.equals(restoredContent);
            
            Log.d(TAG, "   Backup creation: " + backupSuccess);
            Log.d(TAG, "   Restore operation: " + restoreSuccess);
            Log.d(TAG, "   Content integrity: " + originalContent.equals(restoredContent));
            
            // Cleanup
            FileUtils.delete(testDir);
            
            if (backupTestsPassed) {
                Log.d(TAG, "✅ Backup and restore test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Backup and restore test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Backup and restore test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 6: Archive operations
     */
    private void testArchiveOperations() {
        Log.d(TAG, "🧪 Testing archive operations");
        
        try {
            File testDir = new File(context.getCacheDir(), "archive_test");
            File extractDir = new File(testDir, "extracted");
            testDir.mkdirs();
            
            // Create test files
            List<File> testFiles = new ArrayList<>();
            for (int i = 1; i <= 3; i++) {
                File file = new File(testDir, "test" + i + ".txt");
                FileUtils.writeFile(file, "Test file " + i + " content");
                testFiles.add(file);
            }
            
            // Create ZIP archive
            File zipFile = new File(testDir, "test_archive.zip");
            boolean createSuccess = FileUtils.createZipArchive(testFiles, zipFile);
            
            // Extract ZIP archive
            boolean extractSuccess = FileUtils.extractZipArchive(zipFile, extractDir);
            
            // Verify extracted files
            int extractedCount = 0;
            if (extractDir.exists()) {
                File[] extractedFiles = extractDir.listFiles();
                if (extractedFiles != null) {
                    extractedCount = extractedFiles.length;
                }
            }
            
            boolean archiveTestsPassed = createSuccess && extractSuccess && extractedCount == 3;
            
            Log.d(TAG, "   ZIP creation: " + createSuccess);
            Log.d(TAG, "   ZIP extraction: " + extractSuccess);
            Log.d(TAG, "   Extracted files: " + extractedCount + "/3");
            Log.d(TAG, "   ZIP file size: " + FileUtils.formatFileSize(FileUtils.getFileSize(zipFile)));
            
            // Cleanup
            FileUtils.delete(testDir);
            
            if (archiveTestsPassed) {
                Log.d(TAG, "✅ Archive operations test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Archive operations test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Archive operations test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 7: Encryption operations
     */
    private void testEncryptionOperations() {
        Log.d(TAG, "🧪 Testing encryption operations");
        
        try {
            File testDir = new File(context.getCacheDir(), "encryption_test");
            testDir.mkdirs();
            
            // Create test file
            File originalFile = new File(testDir, "original.txt");
            String originalContent = "Secret content for encryption test";
            FileUtils.writeFile(originalFile, originalContent);
            
            // Encrypt file
            File encryptedFile = new File(testDir, "encrypted.txt");
            byte[] key = "BearModKey123456".getBytes(); // 16-byte key
            boolean encryptSuccess = FileUtils.encryptFile(originalFile, encryptedFile, key);
            
            // Verify encrypted content is different
            String encryptedContent = FileUtils.readFile(encryptedFile);
            boolean contentDifferent = !originalContent.equals(encryptedContent);
            
            // Decrypt file
            File decryptedFile = new File(testDir, "decrypted.txt");
            boolean decryptSuccess = FileUtils.decryptFile(encryptedFile, decryptedFile, key);
            String decryptedContent = FileUtils.readFile(decryptedFile);
            
            boolean encryptionTestsPassed = encryptSuccess && decryptSuccess && 
                                          contentDifferent && originalContent.equals(decryptedContent);
            
            Log.d(TAG, "   Encryption: " + encryptSuccess);
            Log.d(TAG, "   Decryption: " + decryptSuccess);
            Log.d(TAG, "   Content different: " + contentDifferent);
            Log.d(TAG, "   Round-trip integrity: " + originalContent.equals(decryptedContent));
            
            // Cleanup
            FileUtils.delete(testDir);
            
            if (encryptionTestsPassed) {
                Log.d(TAG, "✅ Encryption operations test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Encryption operations test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Encryption operations test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Test 8: Utility functions
     */
    private void testUtilityFunctions() {
        Log.d(TAG, "🧪 Testing utility functions");
        
        try {
            File testDir = new File(context.getCacheDir(), "utility_test");
            testDir.mkdirs();
            
            // Create test file
            File testFile = new File(testDir, "test.config.json");
            FileUtils.writeFile(testFile, "Test content");
            
            // Test file extension functions
            String extension = FileUtils.getFileExtension(testFile);
            String nameWithoutExt = FileUtils.getFileNameWithoutExtension(testFile);
            
            // Test file size formatting
            long[] testSizes = {512, 1536, 1572864, 1610612736L}; // 512B, 1.5KB, 1.5MB, 1.5GB
            String[] formattedSizes = new String[testSizes.length];
            for (int i = 0; i < testSizes.length; i++) {
                formattedSizes[i] = FileUtils.formatFileSize(testSizes[i]);
            }
            
            boolean utilityTestsPassed = extension.equals(".json") && 
                                       nameWithoutExt.equals("test.config") &&
                                       formattedSizes[0].contains("B") &&
                                       formattedSizes[1].contains("KB") &&
                                       formattedSizes[2].contains("MB") &&
                                       formattedSizes[3].contains("GB");
            
            Log.d(TAG, "   File extension: " + extension);
            Log.d(TAG, "   Name without ext: " + nameWithoutExt);
            Log.d(TAG, "   Size formatting: " + String.join(", ", formattedSizes));
            
            // Cleanup
            FileUtils.delete(testDir);
            
            if (utilityTestsPassed) {
                Log.d(TAG, "✅ Utility functions test passed");
                testsPassed.incrementAndGet();
            } else {
                Log.w(TAG, "⚠️ Utility functions test failed");
                testsFailed.incrementAndGet();
            }
            
        } catch (Exception e) {
            Log.e(TAG, "❌ Utility functions test failed", e);
            testsFailed.incrementAndGet();
        }
    }
    
    /**
     * Generate test report
     */
    private void generateTestReport(TestResults results) {
        Log.d(TAG, "📊 FileUtils Test Report");
        Log.d(TAG, "═══════════════════════════");
        Log.d(TAG, "Total Tests: " + results.getTotalTests());
        Log.d(TAG, "Tests Passed: " + results.getTestsPassed());
        Log.d(TAG, "Tests Failed: " + results.getTestsFailed());
        Log.d(TAG, "Success Rate: " + String.format("%.1f%%", results.getSuccessRate()));
        Log.d(TAG, "Total Time: " + results.getTotalTime() + "ms");
        Log.d(TAG, "═══════════════════════════");
        
        if (results.getSuccessRate() >= 90) {
            Log.d(TAG, "🎉 FileUtils Test Suite: PASSED");
        } else if (results.getSuccessRate() >= 75) {
            Log.w(TAG, "⚠️ FileUtils Test Suite: PARTIAL PASS");
        } else {
            Log.e(TAG, "❌ FileUtils Test Suite: FAILED");
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
