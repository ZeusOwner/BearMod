package com.bearmod.utils;

import android.content.Context;
import android.util.Log;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;
import java.util.zip.ZipOutputStream;

/**
 * Enhanced utility class for file operations in BearMod
 * 
 * Provides file utilities specifically designed for game modding,
 * including binary file operations, encryption, backup/restore,
 * and game file handling.
 */
public class FileUtils {
    private static final String TAG = "BearMod_FileUtils";
    
    // Directory names for BearMod
    public static final String BEARMOD_DIR = "bearmod";
    public static final String CONFIG_DIR = "config";
    public static final String LOGS_DIR = "logs";
    public static final String BACKUP_DIR = "backup";
    public static final String CACHE_DIR = "cache";
    public static final String TEMP_DIR = "temp";
    
    // File extensions
    public static final String CONFIG_EXT = ".json";
    public static final String LOG_EXT = ".log";
    public static final String BACKUP_EXT = ".bak";
    public static final String PATCH_EXT = ".patch";
    
    /**
     * Read text from a file (your original method, enhanced)
     * 
     * @param file The file to read from
     * @return The content of the file as a string
     */
    public static String readFile(File file) {
        if (file == null || !file.exists() || !file.isFile()) {
            Log.w(TAG, "File does not exist or is not a file: " + 
                    (file != null ? file.getAbsolutePath() : "null"));
            return "";
        }
        
        StringBuilder content = new StringBuilder();
        
        try (FileInputStream fis = new FileInputStream(file);
             InputStreamReader isr = new InputStreamReader(fis, StandardCharsets.UTF_8);
             BufferedReader reader = new BufferedReader(isr)) {
            
            String line;
            while ((line = reader.readLine()) != null) {
                content.append(line).append("\n");
            }
            
            Log.d(TAG, "Successfully read file: " + file.getAbsolutePath() + 
                    " (" + content.length() + " bytes)");
            
        } catch (IOException e) {
            Log.e(TAG, "Error reading file: " + file.getAbsolutePath(), e);
        }
        
        return content.toString();
    }
    
    /**
     * Write text to a file (your original method, enhanced)
     * 
     * @param file The file to write to
     * @param content The content to write
     * @return true if successful, false otherwise
     */
    public static boolean writeFile(File file, String content) {
        if (file == null || content == null) {
            Log.w(TAG, "Invalid parameters for writeFile");
            return false;
        }
        
        try {
            // Create parent directories if they don't exist
            File parentDir = file.getParentFile();
            if (parentDir != null && !parentDir.exists()) {
                boolean created = parentDir.mkdirs();
                if (!created) {
                    Log.w(TAG, "Failed to create parent directories for: " + file.getAbsolutePath());
                }
            }
            
            try (FileOutputStream fos = new FileOutputStream(file)) {
                fos.write(content.getBytes(StandardCharsets.UTF_8));
                
                Log.d(TAG, "Successfully wrote file: " + file.getAbsolutePath() + 
                        " (" + content.length() + " bytes)");
                return true;
            }
            
        } catch (IOException e) {
            Log.e(TAG, "Error writing to file: " + file.getAbsolutePath(), e);
            return false;
        }
    }
    
    /**
     * Read binary data from a file
     * Essential for memory dumps and game file operations
     * 
     * @param file The file to read from
     * @return The binary content as byte array, or empty array on error
     */
    public static byte[] readBinaryFile(File file) {
        if (file == null || !file.exists() || !file.isFile()) {
            Log.w(TAG, "Binary file does not exist: " + 
                    (file != null ? file.getAbsolutePath() : "null"));
            return new byte[0];
        }
        
        try (FileInputStream fis = new FileInputStream(file);
             ByteArrayOutputStream baos = new ByteArrayOutputStream()) {
            
            byte[] buffer = new byte[8192];
            int bytesRead;
            
            while ((bytesRead = fis.read(buffer)) != -1) {
                baos.write(buffer, 0, bytesRead);
            }
            
            byte[] result = baos.toByteArray();
            Log.d(TAG, "Successfully read binary file: " + file.getAbsolutePath() + 
                    " (" + result.length + " bytes)");
            
            return result;
            
        } catch (IOException e) {
            Log.e(TAG, "Error reading binary file: " + file.getAbsolutePath(), e);
            return new byte[0];
        }
    }
    
    /**
     * Write binary data to a file
     * Essential for memory patches and game file modifications
     * 
     * @param file The file to write to
     * @param data The binary data to write
     * @return true if successful, false otherwise
     */
    public static boolean writeBinaryFile(File file, byte[] data) {
        if (file == null || data == null) {
            Log.w(TAG, "Invalid parameters for writeBinaryFile");
            return false;
        }
        
        try {
            // Create parent directories if they don't exist
            File parentDir = file.getParentFile();
            if (parentDir != null && !parentDir.exists()) {
                parentDir.mkdirs();
            }
            
            try (FileOutputStream fos = new FileOutputStream(file)) {
                fos.write(data);
                
                Log.d(TAG, "Successfully wrote binary file: " + file.getAbsolutePath() + 
                        " (" + data.length + " bytes)");
                return true;
            }
            
        } catch (IOException e) {
            Log.e(TAG, "Error writing binary file: " + file.getAbsolutePath(), e);
            return false;
        }
    }
    
    /**
     * Delete a file or directory (your original method, enhanced)
     * 
     * @param file The file or directory to delete
     * @return true if successful, false otherwise
     */
    public static boolean delete(File file) {
        if (file == null || !file.exists()) {
            return true; // Already doesn't exist
        }
        
        try {
            if (file.isDirectory()) {
                File[] children = file.listFiles();
                if (children != null) {
                    for (File child : children) {
                        if (!delete(child)) {
                            Log.w(TAG, "Failed to delete child: " + child.getAbsolutePath());
                            return false;
                        }
                    }
                }
            }
            
            boolean deleted = file.delete();
            if (deleted) {
                Log.d(TAG, "Successfully deleted: " + file.getAbsolutePath());
            } else {
                Log.w(TAG, "Failed to delete: " + file.getAbsolutePath());
            }
            
            return deleted;
            
        } catch (Exception e) {
            Log.e(TAG, "Error deleting file: " + file.getAbsolutePath(), e);
            return false;
        }
    }
    
    /**
     * Copy file from source to destination
     * 
     * @param source Source file
     * @param destination Destination file
     * @return true if successful, false otherwise
     */
    public static boolean copyFile(File source, File destination) {
        if (source == null || destination == null || !source.exists()) {
            Log.w(TAG, "Invalid parameters for copyFile");
            return false;
        }
        
        try {
            // Create parent directories if they don't exist
            File parentDir = destination.getParentFile();
            if (parentDir != null && !parentDir.exists()) {
                parentDir.mkdirs();
            }
            
            Files.copy(source.toPath(), destination.toPath(), StandardCopyOption.REPLACE_EXISTING);
            
            Log.d(TAG, "Successfully copied file: " + source.getAbsolutePath() + 
                    " -> " + destination.getAbsolutePath());
            return true;
            
        } catch (IOException e) {
            Log.e(TAG, "Error copying file: " + source.getAbsolutePath() + 
                    " -> " + destination.getAbsolutePath(), e);
            return false;
        }
    }
    
    /**
     * Get file size in bytes
     * 
     * @param file The file to check
     * @return File size in bytes, or -1 if file doesn't exist
     */
    public static long getFileSize(File file) {
        if (file == null || !file.exists() || !file.isFile()) {
            return -1;
        }
        return file.length();
    }
    
    /**
     * Calculate MD5 hash of a file
     * Useful for integrity checking
     * 
     * @param file The file to hash
     * @return MD5 hash as hex string, or empty string on error
     */
    public static String calculateMD5(File file) {
        if (file == null || !file.exists() || !file.isFile()) {
            return "";
        }
        
        try (FileInputStream fis = new FileInputStream(file)) {
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] buffer = new byte[8192];
            int bytesRead;
            
            while ((bytesRead = fis.read(buffer)) != -1) {
                md.update(buffer, 0, bytesRead);
            }
            
            byte[] hash = md.digest();
            return StringUtils.bytesToHex(hash).toLowerCase();
            
        } catch (IOException | NoSuchAlgorithmException e) {
            Log.e(TAG, "Error calculating MD5 for file: " + file.getAbsolutePath(), e);
            return "";
        }
    }
    
    /**
     * Check if file exists and is readable
     * 
     * @param file The file to check
     * @return true if file exists and is readable, false otherwise
     */
    public static boolean isReadable(File file) {
        return file != null && file.exists() && file.isFile() && file.canRead();
    }
    
    /**
     * Check if file exists and is writable
     * 
     * @param file The file to check
     * @return true if file exists and is writable, false otherwise
     */
    public static boolean isWritable(File file) {
        if (file == null) {
            return false;
        }
        
        if (file.exists()) {
            return file.canWrite();
        } else {
            // Check if parent directory is writable
            File parent = file.getParentFile();
            return parent != null && parent.exists() && parent.canWrite();
        }
    }
    
    /**
     * Get the app's private files directory (your original method)
     * 
     * @param context The application context
     * @return The app's private files directory
     */
    public static File getAppFilesDir(Context context) {
        return context.getFilesDir();
    }
    
    /**
     * Get the app's private cache directory (your original method)
     *
     * @param context The application context
     * @return The app's private cache directory
     */
    public static File getAppCacheDir(Context context) {
        return context.getCacheDir();
    }

    // Missing methods that are being called in the project

    /**
     * Get BearMod directory
     */
    public static File getBearModDir(Context context) {
        File dir = new File(context.getFilesDir(), BEARMOD_DIR);
        if (!dir.exists()) {
            dir.mkdirs();
        }
        return dir;
    }

    /**
     * Get config directory
     */
    public static File getConfigDir(Context context) {
        File dir = new File(getBearModDir(context), CONFIG_DIR);
        if (!dir.exists()) {
            dir.mkdirs();
        }
        return dir;
    }

    /**
     * Get logs directory
     */
    public static File getLogsDir(Context context) {
        File dir = new File(getBearModDir(context), LOGS_DIR);
        if (!dir.exists()) {
            dir.mkdirs();
        }
        return dir;
    }

    /**
     * Get backup directory
     */
    public static File getBackupDir(Context context) {
        File dir = new File(getBearModDir(context), BACKUP_DIR);
        if (!dir.exists()) {
            dir.mkdirs();
        }
        return dir;
    }

    /**
     * Get temp directory
     */
    public static File getTempDir(Context context) {
        File dir = new File(getBearModDir(context), TEMP_DIR);
        if (!dir.exists()) {
            dir.mkdirs();
        }
        return dir;
    }

    /**
     * List files with specific extension
     */
    public static List<File> listFilesWithExtension(File directory, String extension) {
        List<File> result = new ArrayList<>();
        if (directory == null || !directory.exists() || !directory.isDirectory()) {
            return result;
        }

        File[] files = directory.listFiles();
        if (files != null) {
            for (File file : files) {
                if (file.isFile() && file.getName().endsWith(extension)) {
                    result.add(file);
                }
            }
        }
        return result;
    }

    /**
     * Get directory size
     */
    public static long getDirectorySize(File directory) {
        if (directory == null || !directory.exists() || !directory.isDirectory()) {
            return 0;
        }

        long size = 0;
        File[] files = directory.listFiles();
        if (files != null) {
            for (File file : files) {
                if (file.isFile()) {
                    size += file.length();
                } else if (file.isDirectory()) {
                    size += getDirectorySize(file);
                }
            }
        }
        return size;
    }

    /**
     * Format file size
     */
    public static String formatFileSize(long bytes) {
        if (bytes < 1024) {
            return bytes + " B";
        } else if (bytes < 1024 * 1024) {
            return String.format("%.1f KB", bytes / 1024.0);
        } else if (bytes < 1024 * 1024 * 1024) {
            return String.format("%.1f MB", bytes / (1024.0 * 1024.0));
        } else {
            return String.format("%.1f GB", bytes / (1024.0 * 1024.0 * 1024.0));
        }
    }

    /**
     * Cleanup temp files
     */
    public static int cleanupTempFiles(File directory, int maxAgeHours) {
        if (directory == null || !directory.exists() || !directory.isDirectory()) {
            return 0;
        }

        int cleaned = 0;
        long cutoffTime = System.currentTimeMillis() - (maxAgeHours * 60 * 60 * 1000L);

        File[] files = directory.listFiles();
        if (files != null) {
            for (File file : files) {
                if (file.lastModified() < cutoffTime) {
                    if (delete(file)) {
                        cleaned++;
                    }
                }
            }
        }
        return cleaned;
    }

    /**
     * Create backup
     */
    public static boolean createBackup(File sourceFile, File backupDir) {
        if (sourceFile == null || !sourceFile.exists() || backupDir == null) {
            return false;
        }

        if (!backupDir.exists()) {
            backupDir.mkdirs();
        }

        String backupName = sourceFile.getName() + BACKUP_EXT;
        File backupFile = new File(backupDir, backupName);

        return copyFile(sourceFile, backupFile);
    }

    /**
     * Restore from backup
     */
    public static boolean restoreFromBackup(File backupFile, File targetFile) {
        if (backupFile == null || !backupFile.exists() || targetFile == null) {
            return false;
        }

        return copyFile(backupFile, targetFile);
    }

    /**
     * Create ZIP archive
     */
    public static boolean createZipArchive(List<File> files, File zipFile) {
        if (files == null || files.isEmpty() || zipFile == null) {
            return false;
        }

        try (ZipOutputStream zos = new ZipOutputStream(new FileOutputStream(zipFile))) {
            for (File file : files) {
                if (file.exists() && file.isFile()) {
                    addFileToZip(zos, file, file.getName());
                }
            }
            return true;
        } catch (IOException e) {
            Log.e(TAG, "Error creating ZIP archive", e);
            return false;
        }
    }

    private static void addFileToZip(ZipOutputStream zos, File file, String entryName) throws IOException {
        ZipEntry entry = new ZipEntry(entryName);
        zos.putNextEntry(entry);

        try (FileInputStream fis = new FileInputStream(file)) {
            byte[] buffer = new byte[8192];
            int bytesRead;
            while ((bytesRead = fis.read(buffer)) != -1) {
                zos.write(buffer, 0, bytesRead);
            }
        }

        zos.closeEntry();
    }

    /**
     * Extract ZIP archive
     */
    public static boolean extractZipArchive(File zipFile, File extractDir) {
        if (zipFile == null || !zipFile.exists() || extractDir == null) {
            return false;
        }

        if (!extractDir.exists()) {
            extractDir.mkdirs();
        }

        try (ZipInputStream zis = new ZipInputStream(new FileInputStream(zipFile))) {
            ZipEntry entry;
            while ((entry = zis.getNextEntry()) != null) {
                File entryFile = new File(extractDir, entry.getName());

                // Create parent directories
                File parentDir = entryFile.getParentFile();
                if (parentDir != null && !parentDir.exists()) {
                    parentDir.mkdirs();
                }

                // Extract file
                try (FileOutputStream fos = new FileOutputStream(entryFile)) {
                    byte[] buffer = new byte[8192];
                    int bytesRead;
                    while ((bytesRead = zis.read(buffer)) != -1) {
                        fos.write(buffer, 0, bytesRead);
                    }
                }

                zis.closeEntry();
            }
            return true;
        } catch (IOException e) {
            Log.e(TAG, "Error extracting ZIP archive", e);
            return false;
        }
    }

    /**
     * Encrypt file (simple XOR encryption for demo)
     */
    public static boolean encryptFile(File sourceFile, File encryptedFile, byte[] key) {
        if (sourceFile == null || !sourceFile.exists() || encryptedFile == null || key == null) {
            return false;
        }

        try {
            byte[] data = readBinaryFile(sourceFile);
            byte[] encrypted = new byte[data.length];

            for (int i = 0; i < data.length; i++) {
                encrypted[i] = (byte) (data[i] ^ key[i % key.length]);
            }

            return writeBinaryFile(encryptedFile, encrypted);
        } catch (Exception e) {
            Log.e(TAG, "Error encrypting file", e);
            return false;
        }
    }

    /**
     * Decrypt file (simple XOR decryption for demo)
     */
    public static boolean decryptFile(File encryptedFile, File decryptedFile, byte[] key) {
        // XOR encryption is symmetric, so decryption is the same as encryption
        return encryptFile(encryptedFile, decryptedFile, key);
    }

    /**
     * Get file extension
     */
    public static String getFileExtension(File file) {
        if (file == null) {
            return "";
        }

        String name = file.getName();
        int lastDot = name.lastIndexOf('.');
        if (lastDot > 0 && lastDot < name.length() - 1) {
            return name.substring(lastDot);
        }
        return "";
    }

    /**
     * Get file name without extension
     */
    public static String getFileNameWithoutExtension(File file) {
        if (file == null) {
            return "";
        }

        String name = file.getName();
        int lastDot = name.lastIndexOf('.');
        if (lastDot > 0) {
            return name.substring(0, lastDot);
        }
        return name;
    }
}
