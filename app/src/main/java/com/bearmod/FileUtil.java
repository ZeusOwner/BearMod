package com.bearmod;

import android.annotation.SuppressLint;
import android.content.ContentResolver;
import android.content.ContentUris;
import android.content.Context;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.ColorFilter;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.graphics.LightingColorFilter;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffXfermode;
import android.graphics.Rect;
import android.graphics.RectF;
import androidx.exifinterface.media.ExifInterface;
import android.net.Uri;
import android.os.Build;
import android.os.Environment;
import android.os.Handler;
import android.os.Looper;
import android.provider.DocumentsContract;
import android.provider.MediaStore;
import android.text.TextUtils;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.net.URLDecoder;
import java.nio.charset.StandardCharsets;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Objects;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;
import java.util.zip.GZIPInputStream;
import java.util.zip.GZIPOutputStream;
import android.util.Log;
import android.util.LruCache;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.util.concurrent.atomic.AtomicBoolean;

public class FileUtil
{
	private static final String TAG = "FileUtil";
	private static final Object fileLock = new Object();
	private static final AtomicBoolean isInitialized = new AtomicBoolean(false);
	
	// Enhanced buffer management for better performance
	private static final int SMALL_BUFFER_SIZE = 8192;   // 8KB for small files
	private static final int MEDIUM_BUFFER_SIZE = 32768; // 32KB for medium files  
	private static final int LARGE_BUFFER_SIZE = 131072; // 128KB for large files
	private static final int MAX_CACHE_SIZE = 50; // Maximum cached operations
	
	// Async operations support
	private static final ExecutorService fileExecutor = Executors.newFixedThreadPool(
		Math.max(2, Runtime.getRuntime().availableProcessors() / 2)
	);
	private static final Handler mainHandler = new Handler(Looper.getMainLooper());
	
	// Operation result caching
	private static final LruCache<String, FileOperationResult> operationCache = 
		new LruCache<String, FileOperationResult>(MAX_CACHE_SIZE) {
			@Override
			protected int sizeOf(String key, FileOperationResult result) {
				return key.length() + (result.data != null ? result.data.length() : 0);
			}
		};
	
	// File metadata cache
	private static final ConcurrentHashMap<String, FileCacheEntry> fileMetadataCache = 
		new ConcurrentHashMap<>();
	
	// Performance monitoring
	private static long totalOperations = 0;
	private static long totalTime = 0;
	
	// Helper classes
	public static class FileOperationResult {
		public final boolean success;
		public final String data;
		public final long timestamp;
		public final String error;
		
		public FileOperationResult(boolean success, String data, String error) {
			this.success = success;
			this.data = data;
			this.error = error;
			this.timestamp = System.currentTimeMillis();
		}
	}
	
	private static class FileCacheEntry {
		public final long lastModified;
		public final long size;
		public final boolean exists;
		public final long cacheTime;
		
		public FileCacheEntry(long lastModified, long size, boolean exists) {
			this.lastModified = lastModified;
			this.size = size;
			this.exists = exists;
			this.cacheTime = System.currentTimeMillis();
		}
		
		public boolean isValid(long maxAge) {
			return (System.currentTimeMillis() - cacheTime) < maxAge;
		}
	}
	
	public interface FileOperationCallback {
		void onSuccess(String result);
		void onError(String error);
	}
	
	// Enhanced buffer size selection based on file size
	private static int getOptimalBufferSize(long fileSize) {
		if (fileSize < 64 * 1024) { // < 64KB
			return SMALL_BUFFER_SIZE;
		} else if (fileSize < 1024 * 1024) { // < 1MB
			return MEDIUM_BUFFER_SIZE;
		} else {
			return LARGE_BUFFER_SIZE;
		}
	}
	
	// Async file read with caching
	public static Future<FileOperationResult> readFileAsync(String fileName, Context context) {
		return fileExecutor.submit(() -> {
			long startTime = System.currentTimeMillis();
			
			try {
				// Check cache first
				String cacheKey = "read_" + fileName;
				FileOperationResult cached = operationCache.get(cacheKey);
				if (cached != null && isCacheValid(cached, fileName, context)) {
					Log.d(TAG, "Cache hit for file: " + fileName);
					return cached;
				}
				
				// Perform actual read
				String content = readFromFile(fileName, context);
				FileOperationResult result = new FileOperationResult(
					content != null, content, content == null ? "Read failed" : null
				);
				
				// Cache the result
				operationCache.put(cacheKey, result);
				
				long duration = System.currentTimeMillis() - startTime;
				updatePerformanceStats(duration);
				Log.d(TAG, "Async read completed: " + fileName + " (" + duration + "ms)");
				
				return result;
			} catch (Exception e) {
				Log.e(TAG, "Async read error: " + fileName, e);
				return new FileOperationResult(false, null, e.getMessage());
			}
		});
	}
	
	// Async file write with compression option
	public static Future<FileOperationResult> writeFileAsync(String fileName, String content, 
														   Context context, boolean compress) {
		return fileExecutor.submit(() -> {
			long startTime = System.currentTimeMillis();
			
			try {
				boolean success;
				if (compress && content.length() > 1024) { // Compress if > 1KB
					success = writeCompressedFile(fileName, content, context);
				} else {
					success = writeToFile(fileName, content, context);
				}
				
				FileOperationResult result = new FileOperationResult(
					success, null, success ? null : "Write failed"
				);
				
				// Invalidate cache
				String cacheKey = "read_" + fileName;
				operationCache.remove(cacheKey);
				fileMetadataCache.remove(fileName);
				
				long duration = System.currentTimeMillis() - startTime;
				updatePerformanceStats(duration);
				Log.d(TAG, "Async write completed: " + fileName + " (" + duration + "ms)");
				
				return result;
			} catch (Exception e) {
				Log.e(TAG, "Async write error: " + fileName, e);
				return new FileOperationResult(false, null, e.getMessage());
			}
		});
	}
	
	// Batch file operations for better performance
	public static Future<Integer> batchDeleteFiles(String[] fileNames, Context context) {
		return fileExecutor.submit(() -> {
			int successCount = 0;
			synchronized (fileLock) {
				for (String fileName : fileNames) {
					if (deleteFile(fileName, context)) {
						successCount++;
						// Clear from caches
						operationCache.remove("read_" + fileName);
						fileMetadataCache.remove(fileName);
					}
				}
			}
			Log.d(TAG, "Batch delete completed: " + successCount + "/" + fileNames.length);
			return successCount;
		});
	}
	
	// Compressed file operations for configuration files
	public static boolean writeCompressedFile(String fileName, String content, Context context) {
		if (fileName == null || content == null || context == null) {
			return false;
		}
		
		synchronized (fileLock) {
			try (FileOutputStream fos = new FileOutputStream(new File(context.getFilesDir(), fileName + ".gz"));
				 GZIPOutputStream gzos = new GZIPOutputStream(fos, MEDIUM_BUFFER_SIZE);
				 BufferedOutputStream bos = new BufferedOutputStream(gzos, MEDIUM_BUFFER_SIZE)) {
				
				byte[] contentBytes = content.getBytes(StandardCharsets.UTF_8);
				bos.write(contentBytes);
				bos.flush();
				
				Log.d(TAG, "Compressed file written: " + fileName + " (saved " + 
					   (contentBytes.length - new File(context.getFilesDir(), fileName + ".gz").length()) + " bytes)");
				return true;
			} catch (IOException e) {
				Log.e(TAG, "Error writing compressed file: " + fileName, e);
				return false;
			}
		}
	}
	
	public static String readCompressedFile(String fileName, Context context) {
		if (fileName == null || context == null) {
			return null;
		}
		
		synchronized (fileLock) {
			try (FileInputStream fis = new FileInputStream(new File(context.getFilesDir(), fileName + ".gz"));
				 GZIPInputStream gzis = new GZIPInputStream(fis, MEDIUM_BUFFER_SIZE);
				 BufferedInputStream bis = new BufferedInputStream(gzis, MEDIUM_BUFFER_SIZE);
				 ByteArrayOutputStream baos = new ByteArrayOutputStream()) {
				
				byte[] buffer = new byte[MEDIUM_BUFFER_SIZE];
				int bytesRead;
				
				while ((bytesRead = bis.read(buffer)) != -1) {
					baos.write(buffer, 0, bytesRead);
				}
				
				String content = baos.toString(StandardCharsets.UTF_8.name());
				Log.d(TAG, "Compressed file read: " + fileName);
				return content;
			} catch (IOException e) {
				Log.e(TAG, "Error reading compressed file: " + fileName, e);
				return null;
			}
		}
	}
	
	// Enhanced file existence check with caching
	public static boolean fileExistsCached(String fileName, Context context) {
		if (fileName == null || context == null) {
			return false;
		}
		
		FileCacheEntry cached = fileMetadataCache.get(fileName);
		if (cached != null && cached.isValid(30000)) { // 30 second cache
			return cached.exists;
		}
		
		// Update cache
		File file = new File(context.getFilesDir(), fileName);
		boolean exists = file.exists() && file.isFile();
		fileMetadataCache.put(fileName, new FileCacheEntry(
			file.lastModified(), file.length(), exists
		));
		
		return exists;
	}
	
	// Lazy bitmap loading with size optimization
	public static Bitmap loadBitmapLazy(String path, int targetWidth, int targetHeight) {
		try {
			// First decode with inJustDecodeBounds to get dimensions
			BitmapFactory.Options options = new BitmapFactory.Options();
			options.inJustDecodeBounds = true;
			BitmapFactory.decodeFile(path, options);
			
			// Calculate optimal sample size
			options.inSampleSize = calculateInSampleSize(options, targetWidth, targetHeight);
			options.inJustDecodeBounds = false;
			options.inPreferredConfig = Bitmap.Config.RGB_565; // Use less memory
			
			// Decode with sample size
			Bitmap bitmap = BitmapFactory.decodeFile(path, options);
			
			Log.d(TAG, "Lazy loaded bitmap: " + path + " (sample size: " + options.inSampleSize + ")");
			return bitmap;
		} catch (Exception e) {
			Log.e(TAG, "Error lazy loading bitmap: " + path, e);
			return null;
		}
	}
	
	// Performance monitoring
	private static void updatePerformanceStats(long duration) {
		synchronized (fileLock) {
			totalOperations++;
			totalTime += duration;
			
			if (totalOperations % 100 == 0) { // Log every 100 operations
				long avgTime = totalTime / totalOperations;
				Log.d(TAG, "Performance stats - Operations: " + totalOperations + ", Avg time: " + avgTime + "ms");
			}
		}
	}
	
	private static boolean isCacheValid(FileOperationResult cached, String fileName, Context context) {
		if (cached == null) return false;
		
		// Check if file was modified since cache
		File file = new File(context.getFilesDir(), fileName);
		return file.exists() && file.lastModified() <= cached.timestamp;
	}
	
	// Enhanced cleanup with performance stats
	public static void cleanup() {
		try {
			// Shutdown executor
			fileExecutor.shutdown();
			if (!fileExecutor.awaitTermination(5, TimeUnit.SECONDS)) {
				fileExecutor.shutdownNow();
			}
			
			// Clear caches
			operationCache.evictAll();
			fileMetadataCache.clear();
			
			// Log final performance stats
			if (totalOperations > 0) {
				long avgTime = totalTime / totalOperations;
				Log.d(TAG, "Final performance stats - Total operations: " + totalOperations + 
					   ", Total time: " + totalTime + "ms, Avg time: " + avgTime + "ms");
			}
			
			Log.d(TAG, "FileUtil cleanup completed with performance optimizations");
		} catch (Exception e) {
			Log.e(TAG, "Error during cleanup", e);
		}
	}
	
	// === CORE FILE OPERATIONS ===
	
	private static void createNewFile(String path) {
		int lastSep = path.lastIndexOf(File.separator);
		if (lastSep > 0) {
			String dirPath = path.substring(0, lastSep);
			makeDir(dirPath);
		}

		File file = new File(path);
		try {
			if (!file.exists())
				file.createNewFile();
		} catch(IOException e) {
			Log.e(TAG, "Error creating file: " + path, e);
		}
	}

	public static String readFile(String path) {
		createNewFile(path);
		StringBuilder sb = new StringBuilder();
		
		try (FileReader fr = new FileReader(new File(path))) {
			char[] buff = new char[getOptimalBufferSize(new File(path).length()) / 2]; // char buffer
			int length;
			while ((length = fr.read(buff)) > 0) {
				sb.append(new String(buff, 0, length));
			}
		} catch(IOException e) {
			Log.e(TAG, "Error reading file: " + path, e);
		}
		return sb.toString();
	}

	public static void writeFile(String path, String str) {
		createNewFile(path);
		try (FileWriter fileWriter = new FileWriter(new File(path), false)) {
			fileWriter.write(str);
			fileWriter.flush();
		} catch(IOException e) {
			Log.e(TAG, "Error writing file: " + path, e);
		}
	}

	public static void copyFile(String sourcePath, String destPath) {
		if (!isExistFile(sourcePath)) return;
		createNewFile(destPath);

		File sourceFile = new File(sourcePath);
		int bufferSize = getOptimalBufferSize(sourceFile.length());
		
		try (FileInputStream fis = new FileInputStream(sourcePath);
			 BufferedInputStream bis = new BufferedInputStream(fis, bufferSize);
			 FileOutputStream fos = new FileOutputStream(destPath, false);
			 BufferedOutputStream bos = new BufferedOutputStream(fos, bufferSize)) {
			
			byte[] buff = new byte[bufferSize];
			int length;
			while ((length = bis.read(buff)) > 0) {
				bos.write(buff, 0, length);
			}
		} catch(IOException e) {
			Log.e(TAG, "Error copying file: " + sourcePath + " -> " + destPath, e);
		}
	}

	public static void moveFile(String sourcePath, String destPath) {
		copyFile(sourcePath, destPath);
		deleteFile(sourcePath);
	}

	public static void deleteFile(String path) {
		File file = new File(path);
		if (!file.exists()) return;

		if (file.isFile()) {
			file.delete();
			return;
		}

		File[] fileArr = file.listFiles();
		if (fileArr != null) {
			for (File subFile : fileArr) {
				if (subFile.isDirectory()) {
					deleteFile(subFile.getAbsolutePath());
				}
				if (subFile.isFile()) {
					subFile.delete();
				}
			}
		}
		file.delete();
	}

	public static boolean isExistFile(String path) {
		return new File(path).exists();
	}

	public static void makeDir(String path) {
		if (!isExistFile(path)) {
			new File(path).mkdirs();
		}
	}

	// === DIRECTORY OPERATIONS ===
	
	public static void listDir(String path, ArrayList<String> list) {
		File dir = new File(path);
		if (!dir.exists() || dir.isFile()) return;

		File[] listFiles = dir.listFiles();
		if (listFiles == null || listFiles.length <= 0) return;

		if (list == null) return;
		list.clear();
		for (File file : listFiles) {
			list.add(file.getAbsolutePath());
		}
	}

	public static boolean isDirectory(String path) {
		if (!isExistFile(path)) return false;
		return new File(path).isDirectory();
	}

	public static boolean isFile(String path) {
		if (!isExistFile(path)) return false;
		return new File(path).isFile();
	}

	public static long getFileLength(String path) {
		if (!isExistFile(path)) return 0;
		return new File(path).length();
	}

	// === STORAGE UTILITIES ===
	
	public static String getExternalStorageDir() {
		return Environment.getExternalStorageDirectory().getAbsolutePath();
	}

	public static String getPackageDataDir(Context context) {
		return Objects.requireNonNull(context.getExternalFilesDir(null)).getAbsolutePath();
	}

	public static String getPublicDir(String type) {
		return Environment.getExternalStoragePublicDirectory(type).getAbsolutePath();
	}

	// === CONTEXT-BASED FILE OPERATIONS ===
	
	public static boolean writeToFile(String fileName, String content, Context context) {
		if (fileName == null || content == null || context == null) {
			Log.e(TAG, "Invalid parameters for writeToFile");
			return false;
		}
		
		synchronized (fileLock) {
			try (FileOutputStream fos = new FileOutputStream(new File(context.getFilesDir(), fileName));
				 BufferedOutputStream bos = new BufferedOutputStream(fos, MEDIUM_BUFFER_SIZE)) {
				
				File file = new File(context.getFilesDir(), fileName);
				File parentDir = file.getParentFile();
				if (parentDir != null && !parentDir.exists()) {
					if (!parentDir.mkdirs()) {
						Log.e(TAG, "Failed to create parent directory: " + parentDir.getAbsolutePath());
						return false;
					}
				}
				
				byte[] contentBytes = content.getBytes(StandardCharsets.UTF_8);
				bos.write(contentBytes);
				bos.flush();
				
				Log.d(TAG, "Successfully wrote file: " + fileName);
				return true;
				
			} catch (IOException e) {
				Log.e(TAG, "Error writing file: " + fileName, e);
				return false;
			}
		}
	}
	
	public static String readFromFile(String fileName, Context context) {
		if (fileName == null || context == null) {
			Log.e(TAG, "Invalid parameters for readFromFile");
			return null;
		}
		
		synchronized (fileLock) {
			try (FileInputStream fis = new FileInputStream(new File(context.getFilesDir(), fileName));
				 BufferedInputStream bis = new BufferedInputStream(fis, MEDIUM_BUFFER_SIZE);
				 ByteArrayOutputStream baos = new ByteArrayOutputStream()) {
				
				File file = new File(context.getFilesDir(), fileName);
				if (!file.exists() || !file.canRead()) {
					Log.w(TAG, "File does not exist or cannot be read: " + fileName);
					return null;
				}
				
				long fileSize = file.length();
				if (fileSize > 50 * 1024 * 1024) { // 50MB limit
					Log.e(TAG, "File too large to read into memory: " + fileName + " (" + fileSize + " bytes)");
					return null;
				}
				
				byte[] buffer = new byte[MEDIUM_BUFFER_SIZE];
				int bytesRead;
				
				while ((bytesRead = bis.read(buffer)) != -1) {
					baos.write(buffer, 0, bytesRead);
				}
				
				String content = baos.toString(StandardCharsets.UTF_8.name());
				Log.d(TAG, "Successfully read file: " + fileName + " (" + content.length() + " chars)");
				return content;
				
			} catch (IOException e) {
				Log.e(TAG, "Error reading file: " + fileName, e);
				return null;
			}
		}
	}
	
	public static boolean copyFile(String sourceFileName, String destFileName, Context context) {
		if (sourceFileName == null || destFileName == null || context == null) {
			Log.e(TAG, "Invalid parameters for copyFile");
			return false;
		}
		
		synchronized (fileLock) {
			try (FileInputStream fis = new FileInputStream(new File(context.getFilesDir(), sourceFileName));
				 BufferedInputStream bis = new BufferedInputStream(fis, MEDIUM_BUFFER_SIZE);
				 FileOutputStream fos = new FileOutputStream(new File(context.getFilesDir(), destFileName));
				 BufferedOutputStream bos = new BufferedOutputStream(fos, MEDIUM_BUFFER_SIZE)) {
				
				File sourceFile = new File(context.getFilesDir(), sourceFileName);
				File destFile = new File(context.getFilesDir(), destFileName);
				
				if (!sourceFile.exists() || !sourceFile.canRead()) {
					Log.e(TAG, "Source file does not exist or cannot be read: " + sourceFileName);
					return false;
				}
				
				File destParent = destFile.getParentFile();
				if (destParent != null && !destParent.exists()) {
					if (!destParent.mkdirs()) {
						Log.e(TAG, "Failed to create destination directory: " + destParent.getAbsolutePath());
						return false;
					}
				}
				
				byte[] buffer = new byte[MEDIUM_BUFFER_SIZE];
				int bytesRead;
				long totalBytes = 0;
				
				while ((bytesRead = bis.read(buffer)) != -1) {
					bos.write(buffer, 0, bytesRead);
					totalBytes += bytesRead;
				}
				
				bos.flush();
				
				Log.d(TAG, "Successfully copied file: " + sourceFileName + " -> " + destFileName + " (" + totalBytes + " bytes)");
				return true;
				
			} catch (IOException e) {
				Log.e(TAG, "Error copying file: " + sourceFileName + " -> " + destFileName, e);
				return false;
			}
		}
	}
	
	public static boolean deleteFile(String fileName, Context context) {
		if (fileName == null || context == null) {
			Log.e(TAG, "Invalid parameters for deleteFile");
			return false;
		}
		
		synchronized (fileLock) {
			try {
				File file = new File(context.getFilesDir(), fileName);
				if (!file.exists()) {
					Log.d(TAG, "File does not exist (already deleted?): " + fileName);
					return true;
				}
				
				boolean deleted = file.delete();
				if (deleted) {
					Log.d(TAG, "Successfully deleted file: " + fileName);
				} else {
					Log.e(TAG, "Failed to delete file: " + fileName);
				}
				return deleted;
				
			} catch (Exception e) {
				Log.e(TAG, "Error deleting file: " + fileName, e);
				return false;
			}
		}
	}
	
	public static boolean fileExists(String fileName, Context context) {
		if (fileName == null || context == null) {
			return false;
		}
		
		try {
			File file = new File(context.getFilesDir(), fileName);
			return file.exists() && file.isFile();
		} catch (Exception e) {
			Log.e(TAG, "Error checking file existence: " + fileName, e);
			return false;
		}
	}
	
	public static long getFileSize(String fileName, Context context) {
		if (fileName == null || context == null) {
			return -1;
		}
		
		try {
			File file = new File(context.getFilesDir(), fileName);
			if (file.exists() && file.isFile()) {
				return file.length();
			}
			return -1;
		} catch (Exception e) {
			Log.e(TAG, "Error getting file size: " + fileName, e);
			return -1;
		}
	}
	
	// === STORAGE STATE CHECKS ===
	
	public static boolean isExternalStorageWritable() {
		try {
			String state = Environment.getExternalStorageState();
			return Environment.MEDIA_MOUNTED.equals(state);
		} catch (Exception e) {
			Log.e(TAG, "Error checking external storage", e);
			return false;
		}
	}
	
	public static boolean isExternalStorageReadable() {
		try {
			String state = Environment.getExternalStorageState();
			return Environment.MEDIA_MOUNTED.equals(state) || 
				   Environment.MEDIA_MOUNTED_READ_ONLY.equals(state);
		} catch (Exception e) {
			Log.e(TAG, "Error checking external storage", e);
			return false;
		}
	}
	
	public static File getInternalStorageDir(Context context) {
		if (context == null) return null;
		
		try {
			return context.getFilesDir();
		} catch (Exception e) {
			Log.e(TAG, "Error getting internal storage directory", e);
			return null;
		}
	}
	
	public static File getCacheDir(Context context) {
		if (context == null) return null;
		
		try {
			return context.getCacheDir();
		} catch (Exception e) {
			Log.e(TAG, "Error getting cache directory", e);
			return null;
		}
	}
	
	public static boolean clearCache(Context context) {
		if (context == null) return false;
		
		synchronized (fileLock) {
			try {
				File cacheDir = context.getCacheDir();
				if (cacheDir != null && cacheDir.exists()) {
					return deleteDirectoryContents(cacheDir);
				}
				return true;
			} catch (Exception e) {
				Log.e(TAG, "Error clearing cache", e);
				return false;
			}
		}
	}
	
	private static boolean deleteDirectoryContents(File directory) {
		if (directory == null || !directory.exists() || !directory.isDirectory()) {
			return false;
		}
		
		try {
			File[] files = directory.listFiles();
			if (files == null) return true;
			
			boolean success = true;
			for (File file : files) {
				if (file.isDirectory()) {
					success &= deleteDirectoryContents(file);
					success &= file.delete();
				} else {
					success &= file.delete();
				}
			}
			return success;
		} catch (Exception e) {
			Log.e(TAG, "Error deleting directory contents: " + directory.getAbsolutePath(), e);
			return false;
		}
	}
	
	public static boolean writeToExternalFile(String fileName, String content, Context context) {
		if (!isExternalStorageWritable()) {
			Log.e(TAG, "External storage is not writable");
			return false;
		}
		
		if (fileName == null || content == null || context == null) {
			Log.e(TAG, "Invalid parameters for writeToExternalFile");
			return false;
		}
		
		synchronized (fileLock) {
			try (FileOutputStream fos = new FileOutputStream(new File(context.getExternalFilesDir(null), fileName));
				 BufferedOutputStream bos = new BufferedOutputStream(fos, MEDIUM_BUFFER_SIZE)) {
				
				File externalDir = context.getExternalFilesDir(null);
				if (externalDir == null) {
					Log.e(TAG, "External files directory is null");
					return false;
				}
				
				File file = new File(externalDir, fileName);
				File parentDir = file.getParentFile();
				if (parentDir != null && !parentDir.exists()) {
					if (!parentDir.mkdirs()) {
						Log.e(TAG, "Failed to create external parent directory: " + parentDir.getAbsolutePath());
						return false;
					}
				}
				
				byte[] contentBytes = content.getBytes(StandardCharsets.UTF_8);
				bos.write(contentBytes);
				bos.flush();
				
				Log.d(TAG, "Successfully wrote external file: " + fileName);
				return true;
				
			} catch (IOException e) {
				Log.e(TAG, "Error writing external file: " + fileName, e);
				return false;
			}
		}
	}

	// === URI CONVERSION ===
	
	public static String convertUriToFilePath(final Context context, final Uri uri) {
		String path = null;
		if (DocumentsContract.isDocumentUri(context, uri)) {
			if (isExternalStorageDocument(uri)) {
				final String docId = DocumentsContract.getDocumentId(uri);
				final String[] split = docId.split(":");
				final String type = split[0];

				if ("primary".equalsIgnoreCase(type)) {
					path = Environment.getExternalStorageDirectory() + "/" + split[1];
				}
			} else if (isDownloadsDocument(uri)) {
				final String id = DocumentsContract.getDocumentId(uri);

				if (!TextUtils.isEmpty(id)) {
					if (id.startsWith("raw:")) {
						return id.replaceFirst("raw:", "");
					}
				}

				final Uri contentUri = ContentUris.withAppendedId(
					Uri.parse("content://downloads/public_downloads"), Long.parseLong(id));
				path = getDataColumn(context, contentUri, null, null);
			} else if (isMediaDocument(uri)) {
				final String docId = DocumentsContract.getDocumentId(uri);
				final String[] split = docId.split(":");
				final String type = split[0];

				Uri contentUri = null;
				if ("image".equals(type)) {
					contentUri = MediaStore.Images.Media.EXTERNAL_CONTENT_URI;
				} else if ("video".equals(type)) {
					contentUri = MediaStore.Video.Media.EXTERNAL_CONTENT_URI;
				} else if ("audio".equals(type)) {
					contentUri = MediaStore.Audio.Media.EXTERNAL_CONTENT_URI;
				}

				final String selection = MediaStore.Audio.Media._ID + "=?";
				final String[] selectionArgs = new String[]{split[1]};
				path = getDataColumn(context, contentUri, selection, selectionArgs);
			}
		} else if (ContentResolver.SCHEME_CONTENT.equalsIgnoreCase(uri.getScheme())) {
			path = getDataColumn(context, uri, null, null);
		} else if (ContentResolver.SCHEME_FILE.equalsIgnoreCase(uri.getScheme())) {
			path = uri.getPath();
		}

		if (path != null) {
			try {
				if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) {
					return URLDecoder.decode(path, StandardCharsets.UTF_8);
				}
			} catch(Exception e) {
				Log.e(TAG, "Error decoding URI path", e);
				return null;
			}
		}
		return null;
	}

	private static String getDataColumn(Context context, Uri uri, String selection, String[] selectionArgs) {
		try (Cursor cursor = context.getContentResolver().query(uri, 
			new String[]{MediaStore.Images.Media.DATA}, selection, selectionArgs, null)) {
			
			if (cursor != null && cursor.moveToFirst()) {
				final int column_index = cursor.getColumnIndexOrThrow(MediaStore.Images.Media.DATA);
				return cursor.getString(column_index);
			}
		} catch(Exception e) {
			Log.e(TAG, "Error getting data column", e);
		}
		return null;
	}

	private static boolean isExternalStorageDocument(Uri uri) {
		return "com.android.externalstorage.documents".equals(uri.getAuthority());
	}

	private static boolean isDownloadsDocument(Uri uri) {
		return "com.android.providers.downloads.documents".equals(uri.getAuthority());
	}

	private static boolean isMediaDocument(Uri uri) {
		return "com.android.providers.media.documents".equals(uri.getAuthority());
	}

	// === BITMAP OPERATIONS ===
	
	private static void saveBitmap(Bitmap bitmap, String destPath) {
		createNewFile(destPath);
		try (FileOutputStream out = new FileOutputStream(new File(destPath))) {
			bitmap.compress(Bitmap.CompressFormat.PNG, 100, out);
		} catch(Exception e) {
			Log.e(TAG, "Error saving bitmap: " + destPath, e);
		}
	}

	public static Bitmap getScaledBitmap(String path, int max) {
		Bitmap src = BitmapFactory.decodeFile(path);
		if (src == null) return null;

		int width = src.getWidth();
		int height = src.getHeight();
		float rate;

		if (width > height) {
			rate = max / (float)width;
			height = (int)(height * rate);
			width = max;
		} else {
			rate = max / (float)height;
			width = (int)(width * rate);
			height = max;
		}

		return Bitmap.createScaledBitmap(src, width, height, true);
	}

	public static int calculateInSampleSize(BitmapFactory.Options options, int reqWidth, int reqHeight) {
		final int height = options.outHeight;
		final int width = options.outWidth;
		int inSampleSize = 1;

		if (height > reqHeight || width > reqWidth) {
			final int halfHeight = height / 2;
			final int halfWidth = width / 2;

			while ((halfHeight / inSampleSize) >= reqHeight && (halfWidth / inSampleSize) >= reqWidth) {
				inSampleSize *= 2;
			}
		}
		return inSampleSize;
	}

	public static Bitmap decodeSampleBitmapFromPath(String path, int reqWidth, int reqHeight) {
		final BitmapFactory.Options options = new BitmapFactory.Options();
		options.inJustDecodeBounds = true;
		BitmapFactory.decodeFile(path, options);

		options.inSampleSize = calculateInSampleSize(options, reqWidth, reqHeight);
		options.inJustDecodeBounds = false;
		return BitmapFactory.decodeFile(path, options);
	}

	public static void resizeBitmapFileRetainRatio(String fromPath, String destPath, int max) {
		if (!isExistFile(fromPath)) return;
		Bitmap bitmap = getScaledBitmap(fromPath, max);
		if (bitmap != null) saveBitmap(bitmap, destPath);
	}

	public static void resizeBitmapFileToSquare(String fromPath, String destPath, int max) {
		if (!isExistFile(fromPath)) return;
		Bitmap src = BitmapFactory.decodeFile(fromPath);
		if (src == null) return;
		Bitmap bitmap = Bitmap.createScaledBitmap(src, max, max, true);
		saveBitmap(bitmap, destPath);
	}

	public static void resizeBitmapFileToCircle(String fromPath, String destPath) {
		if (!isExistFile(fromPath)) return;
		Bitmap src = BitmapFactory.decodeFile(fromPath);
		if (src == null) return;
		
		Bitmap bitmap = Bitmap.createBitmap(src.getWidth(), src.getHeight(), Bitmap.Config.ARGB_8888);
		Canvas canvas = new Canvas(bitmap);

		final int color = 0xff424242;
		final Paint paint = new Paint();
		final Rect rect = new Rect(0, 0, src.getWidth(), src.getHeight());

		paint.setAntiAlias(true);
		canvas.drawARGB(0, 0, 0, 0);
		paint.setColor(color);
		canvas.drawCircle((float) src.getWidth() / 2, (float) src.getHeight() / 2, (float) src.getWidth() / 2, paint);
		paint.setXfermode(new PorterDuffXfermode(PorterDuff.Mode.SRC_IN));
		canvas.drawBitmap(src, rect, rect, paint);

		saveBitmap(bitmap, destPath);
	}

	public static void resizeBitmapFileWithRoundedBorder(String fromPath, String destPath, int pixels) {
		if (!isExistFile(fromPath)) return;
		Bitmap src = BitmapFactory.decodeFile(fromPath);
		if (src == null) return;
		
		Bitmap bitmap = Bitmap.createBitmap(src.getWidth(), src.getHeight(), Bitmap.Config.ARGB_8888);
		Canvas canvas = new Canvas(bitmap);

		final int color = 0xff424242;
		final Paint paint = new Paint();
		final Rect rect = new Rect(0, 0, src.getWidth(), src.getHeight());
		final RectF rectF = new RectF(rect);

		paint.setAntiAlias(true);
		canvas.drawARGB(0, 0, 0, 0);
		paint.setColor(color);
		canvas.drawRoundRect(rectF, (float) pixels, (float) pixels, paint);

		paint.setXfermode(new PorterDuffXfermode(PorterDuff.Mode.SRC_IN));
		canvas.drawBitmap(src, rect, rect, paint);

		saveBitmap(bitmap, destPath);
	}

	public static void cropBitmapFileFromCenter(String fromPath, String destPath, int w, int h) {
		if (!isExistFile(fromPath)) return;
		Bitmap src = BitmapFactory.decodeFile(fromPath);
		if (src == null) return;

		int width = src.getWidth();
		int height = src.getHeight();

		if (width < w && height < h) return;

		int x = 0, y = 0;
		if (width > w) x = (width - w) / 2;
		if (height > h) y = (height - h) / 2;

		int cw = Math.min(w, width);
		int ch = Math.min(h, height);

		Bitmap bitmap = Bitmap.createBitmap(src, x, y, cw, ch);
		saveBitmap(bitmap, destPath);
	}

	public static void rotateBitmapFile(String fromPath, String destPath, float angle) {
		if (!isExistFile(fromPath)) return;
		Bitmap src = BitmapFactory.decodeFile(fromPath);
		if (src == null) return;
		
		Matrix matrix = new Matrix();
		matrix.postRotate(angle);
		Bitmap bitmap = Bitmap.createBitmap(src, 0, 0, src.getWidth(), src.getHeight(), matrix, true);
		saveBitmap(bitmap, destPath);
	}

	public static void scaleBitmapFile(String fromPath, String destPath, float x, float y) {
		if (!isExistFile(fromPath)) return;
		Bitmap src = BitmapFactory.decodeFile(fromPath);
		if (src == null) return;
		
		Matrix matrix = new Matrix();
		matrix.postScale(x, y);
		Bitmap bitmap = Bitmap.createBitmap(src, 0, 0, src.getWidth(), src.getHeight(), matrix, true);
		saveBitmap(bitmap, destPath);
	}

	public static void skewBitmapFile(String fromPath, String destPath, float x, float y) {
		if (!isExistFile(fromPath)) return;
		Bitmap src = BitmapFactory.decodeFile(fromPath);
		if (src == null) return;
		
		Matrix matrix = new Matrix();
		matrix.postSkew(x, y);
		Bitmap bitmap = Bitmap.createBitmap(src, 0, 0, src.getWidth(), src.getHeight(), matrix, true);
		saveBitmap(bitmap, destPath);
	}

	public static void setBitmapFileColorFilter(String fromPath, String destPath, int color) {
		if (!isExistFile(fromPath)) return;
		Bitmap src = BitmapFactory.decodeFile(fromPath);
		if (src == null) return;
		
		Bitmap bitmap = Bitmap.createBitmap(src, 0, 0, src.getWidth() - 1, src.getHeight() - 1);
		Paint p = new Paint();
		ColorFilter filter = new LightingColorFilter(color, 1);
		p.setColorFilter(filter);
		Canvas canvas = new Canvas(bitmap);
		canvas.drawBitmap(bitmap, 0, 0, p);
		saveBitmap(bitmap, destPath);
	}

	public static void setBitmapFileBrightness(String fromPath, String destPath, float brightness) {
		if (!isExistFile(fromPath)) return;
		Bitmap src = BitmapFactory.decodeFile(fromPath);
		if (src == null) return;
		
		ColorMatrix cm = new ColorMatrix(new float[]{
			1, 0, 0, 0, brightness,
			0, 1, 0, 0, brightness,
			0, 0, 1, 0, brightness,
			0, 0, 0, 1, 0
		});

		Bitmap bitmap = Bitmap.createBitmap(src.getWidth(), src.getHeight(), 
			Objects.requireNonNull(src.getConfig()));
		Canvas canvas = new Canvas(bitmap);
		Paint paint = new Paint();
		paint.setColorFilter(new ColorMatrixColorFilter(cm));
		canvas.drawBitmap(src, 0, 0, paint);
		saveBitmap(bitmap, destPath);
	}

	public static void setBitmapFileContrast(String fromPath, String destPath, float contrast) {
		if (!isExistFile(fromPath)) return;
		Bitmap src = BitmapFactory.decodeFile(fromPath);
		if (src == null) return;
		
		ColorMatrix cm = new ColorMatrix(new float[]{
			contrast, 0, 0, 0, 0,
			0, contrast, 0, 0, 0,
			0, 0, contrast, 0, 0,
			0, 0, 0, 1, 0
		});

		Bitmap bitmap = Bitmap.createBitmap(src.getWidth(), src.getHeight(), 
			Objects.requireNonNull(src.getConfig()));
		Canvas canvas = new Canvas(bitmap);
		Paint paint = new Paint();
		paint.setColorFilter(new ColorMatrixColorFilter(cm));
		canvas.drawBitmap(src, 0, 0, paint);
		saveBitmap(bitmap, destPath);
	}

	public static int getJpegRotate(String filePath) {
		int rotate = 0;
		try {
			ExifInterface exif = new ExifInterface(filePath);
			int iOrientation = exif.getAttributeInt(ExifInterface.TAG_ORIENTATION, -1);

			rotate = switch (iOrientation) {
				case ExifInterface.ORIENTATION_ROTATE_90 -> 90;
				case ExifInterface.ORIENTATION_ROTATE_180 -> 180;
				case ExifInterface.ORIENTATION_ROTATE_270 -> 270;
				default -> 0;
			};
		} catch(IOException e) {
			Log.e(TAG, "Error reading JPEG rotation", e);
			return 0;
		}
		return rotate;
	}

	public static File createNewPictureFile(Context context) {
		@SuppressLint("SimpleDateFormat") 
		SimpleDateFormat date = new SimpleDateFormat("yyyyMMdd_HHmmss");
		String fileName = date.format(new Date()) + ".jpg";
		return new File(Objects.requireNonNull(context.getExternalFilesDir(Environment.DIRECTORY_DCIM))
			.getAbsolutePath() + File.separator + fileName);
	}

	// === UTILITY METHODS ===
	
	private static void closeQuietly(Closeable closeable) {
		if (closeable != null) {
			try {
				closeable.close();
			} catch (IOException e) {
				// Ignore close errors
			}
		}
	}

	public static boolean isValidFileName(String fileName) {
		if (fileName == null || fileName.trim().isEmpty()) {
			return false;
		}

		// Check for directory traversal attempts
		if (fileName.contains("..") || fileName.contains("/") || fileName.contains("\\")) {
			Log.w(TAG, "Invalid file name (directory traversal attempt): " + fileName);
			return false;
		}

		// Check for reserved characters
		char[] invalidChars = {'<', '>', ':', '"', '|', '?', '*'};
		for (char c : invalidChars) {
			if (fileName.indexOf(c) >= 0) {
				Log.w(TAG, "Invalid file name (contains reserved character): " + fileName);
				return false;
			}
		}
		return true;
	}
}
