package com.bearmod;

import android.annotation.SuppressLint;
import android.os.Build;
import android.text.TextUtils;
import android.view.WindowManager;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Objects;

import android.view.View;
import android.content.Context;
import android.util.Log;
import android.os.Handler;
import android.os.Looper;

public class RecorderFakeUtils {

    private static final String TAG = "RecorderFakeUtils";
    
    // ===================================================================================================
    // SOPHISTICATED ANTI-RECORDING SYSTEM
    // Instead of black screen, this provides selective overlay hiding for clean gameplay recordings
    // ===================================================================================================
    
    // Performance optimization variables
    private static boolean isOptimizedMode = true;
    private static long lastUpdateTime = 0;
    private static final long UPDATE_THROTTLE_MS = 100;
    private static final Handler mainHandler = new Handler(Looper.getMainLooper());
    
    // Anti-recording state management
    private static boolean isAntiRecordingActive = false;
    private static boolean isScreenRecordingDetected = false;
    
    // Cache reflection fields to avoid repeated lookups
    private static Field cachedPrivateFlags = null;
    private static Field cachedExtraFlags = null;
    private static Field cachedMeizuFlags = null;
    private static boolean reflectionCacheInitialized = false;
    
    // Performance monitoring
    private static int updateCount = 0;
    private static long totalUpdateTime = 0;

    private static final String ROM_FLYME = "Flyme";
    private static final String ROM_MIUI = "MIUI";
    private static final String ROM_BLACKSHARK = "Blackshark";
    private static final String ROM_ONEPLUS = "OnePlus";
    private static final String ROM_ROG = "ROG";
    private static final String ROM_EMUI = "EMUI";
    private static final String ROM_OPPO = "OPPO";
    private static final String ROM_SMARTISAN = "SMARTISAN";
    private static final String ROM_VIVO = "VIVO";
    private static final String ROM_NUBIAUI = "NUBIAUI";
    private static final String ROM_SAMSUNG = "ONEUI";

    private static final String KEY_VERSION_MIUI = "ro.miui.ui.version.name";
    private static final String KEY_VERSION_EMUI = "ro.build.version.emui";
    private static final String KEY_VERSION_OPPO = "ro.build.version.opporom";
    private static final String KEY_VERSION_SMARTISAN = "ro.smartisan.version";
    private static final String KEY_VERSION_VIVO = "ro.vivo.os.version";
    private static final String KEY_VERSION_NUBIA = "ro.build.nubia.rom.name";
    private static final String KEY_VERSION_ONEPLIS = "ro.build.ota.versionname";
    private static final String KEY_VERSION_SAMSUNG = "ro.channel.officehubrow";
    private static final String KEY_VERSION_BLACKSHARK = "ro.blackshark.rom";
    private static final String KEY_VERSION_ROG = "ro.build.fota.version";
    
    private static String sName;
    private static int flagValue;
    private static WindowManager.LayoutParams params;

    // Window parameters for selective hiding
    private static WindowManager.LayoutParams sMainLayoutParams;
    private static WindowManager.LayoutParams sIconLayoutParams;
    private static WindowManager.LayoutParams sCanvasLayoutParams;
    private static WindowManager sWindowManager;
    private static View sMainView;
    private static View sIconView;
    private static View sCanvasView;
    private static Context sContext;

    // Original parameters backup for restoration
    private static WindowManager.LayoutParams originalMainParams;
    private static WindowManager.LayoutParams originalIconParams;
    private static WindowManager.LayoutParams originalCanvasParams;

    //华为
    public static boolean isEmui() {
        return check(ROM_EMUI);
    }

    //小米
    public static boolean isMiui() {
        return check(ROM_MIUI);
    }

    //vivo
    public static boolean isVivo() {
        return check(ROM_VIVO);
    }

    //oppo
    public static boolean isOppo() {
        return check(ROM_OPPO);
    }

    //魅族
    public static boolean isFlyme() {
        return check(ROM_FLYME);
    }

    //红魔
    public static boolean isNubia() {
        return check(ROM_NUBIAUI);
    }

    //一加
    public static boolean isOnePlus() {
        return check(ROM_ONEPLUS);
    }

    //三星
    public static boolean isSanSung() {
        return check(ROM_SAMSUNG);
    }

    //黑鲨
    public static boolean isBLACKSHARK() {
        return check(ROM_BLACKSHARK);
    }

    public static boolean isActivice() { return false;}

    // ===================================================================================================
    // SCREEN RECORDING DETECTION SYSTEM
    // ===================================================================================================
    
    /**
     * Check if screen recording is currently active
     * This method attempts multiple detection strategies based on ROM type
     */
    public static boolean isRecorderRunning(Context context) {
        try {
            // Check if anti-recording is already active (quick check)
            if (isAntiRecordingActive && isScreenRecordingDetected) {
                return true;
            }
            
            // Strategy 1: Check for screen recording media projection
            if (isMediaProjectionActive(context)) {
                isScreenRecordingDetected = true;
                return true;
            }
            
            // Strategy 2: Check for specific screen recorder processes
            if (isScreenRecorderProcessRunning()) {
                isScreenRecordingDetected = true;
                return true;
            }
            
            // Strategy 3: ROM-specific detection
            if (isRomSpecificRecorderActive()) {
                isScreenRecordingDetected = true;
                return true;
            }
            
            isScreenRecordingDetected = false;
            return false;
            
        } catch (Exception e) {
            Log.e(TAG, "Error detecting screen recording", e);
            return false;
        }
    }
    
    /**
     * Check if MediaProjection (screen recording) is active
     */
    @SuppressLint("DiscouragedPrivateApi")
    private static boolean isMediaProjectionActive(Context context) {
        try {
            // Use reflection to check MediaProjectionManager state
            Object mediaProjectionManager = context.getSystemService(Context.MEDIA_PROJECTION_SERVICE);
            if (mediaProjectionManager != null) {
                Method getActiveProjectionInfo = mediaProjectionManager.getClass().getDeclaredMethod("getActiveProjectionInfo");
                getActiveProjectionInfo.setAccessible(true);
                Object projectionInfo = getActiveProjectionInfo.invoke(mediaProjectionManager);
                return projectionInfo != null;
            }
        } catch (Exception e) {
            Log.d(TAG, "MediaProjection check failed (normal on some ROMs): " + e.getMessage());
        }
        return false;
    }
    
    /**
     * Check if common screen recorder processes are running
     */
    private static boolean isScreenRecorderProcessRunning() {
        try {
            Process process = Runtime.getRuntime().exec("ps");
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            
            while ((line = reader.readLine()) != null) {
                // Check for common screen recorder process names
                if (line.contains("screenrecord") ||
                    line.contains("ScreenRecorder") ||
                    line.contains("screen_recorder") ||
                    line.contains("com.miui.screenrecorder") ||
                    line.contains("com.android.systemui:screenrecord") ||
                    line.contains("com.oneplus.screenrecord") ||
                    line.contains("com.samsung.android.app.smartcapture") ||
                    line.contains("com.huawei.screenrecorder") ||
                    line.contains("com.oppo.screenrecorder") ||
                    line.contains("com.vivo.screenrecorder") ||
                    line.contains("com.meizu.media.recorder")) {
                    reader.close();
                    process.destroy();
                    Log.d(TAG, "Screen recorder process detected: " + line);
                    return true;
                }
            }
            reader.close();
            process.destroy();
        } catch (IOException e) {
            Log.e(TAG, "Error checking for screen recorder processes", e);
        }
        return false;
    }
    
    /**
     * ROM-specific screen recording detection
     */
    private static boolean isRomSpecificRecorderActive() {
        try {
            // MIUI/Xiaomi detection
            if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) {
                String miuiRecording = getProp("persist.sys.miui.screenrecorder");
                if ("1".equals(miuiRecording) || "true".equals(miuiRecording)) {
                    return true;
                }
            }
            
            // EMUI/Huawei detection
            if (check(ROM_EMUI)) {
                String emuiRecording = getProp("persist.sys.huawei.screenrecorder");
                if ("1".equals(emuiRecording) || "true".equals(emuiRecording)) {
                    return true;
                }
            }
            
            // OnePlus detection
            if (check(ROM_ONEPLUS)) {
                String opRecording = getProp("persist.sys.oem.screenrecorder");
                if ("1".equals(opRecording) || "true".equals(opRecording)) {
                    return true;
                }
            }
            
            // Generic Android 10+ detection
            String recording = getProp("debug.media.screenrecord");
            if ("1".equals(recording) || "true".equals(recording)) {
                return true;
            }

        } catch (Exception e) {
            Log.e(TAG, "Error in ROM-specific recorder detection", e);
        }
        
        return false;
    }
    
    // ===================================================================================================
    // SOPHISTICATED SELECTIVE OVERLAY HIDING SYSTEM
    // This system hides only ESP/mod overlays while keeping base game visible in recordings
    // ===================================================================================================

    /**
     * Enable selective anti-recording for ESP/mod overlays only
     * This creates clean gameplay recordings without black screens
     */
    public static void setFakeRecorderWindowLayoutParams(WindowManager.LayoutParams mainViewLayoutParams, 
                                                        WindowManager.LayoutParams iconViewLayoutParams, 
                                                        WindowManager.LayoutParams canvasViewLayoutParams, 
                                                        WindowManager manager, View mainView, View iconView, 
                                                        View canvasView, Context context) {
        
        Log.i(TAG, "Enabling selective anti-recording (clean gameplay mode)");
        
        // Performance optimization: throttle updates
        long currentTime = System.currentTimeMillis();
        if (isOptimizedMode && (currentTime - lastUpdateTime) < UPDATE_THROTTLE_MS) {
            Log.d(TAG, "Update throttled to improve performance");
            return;
        }
        lastUpdateTime = currentTime;
        
        long startTime = System.currentTimeMillis();
        
        // Store references
        sMainLayoutParams = mainViewLayoutParams;
        sIconLayoutParams = iconViewLayoutParams;
        sCanvasLayoutParams = canvasViewLayoutParams;
        sWindowManager = manager;
        sMainView = mainView;
        sIconView = iconView;
        sCanvasView = canvasView;
        sContext = context;

        // Backup original parameters for restoration
        backupOriginalParameters();

        // Initialize reflection cache for better performance
        initializeReflectionCache();

        try {
            // Apply selective anti-recording only to ESP/mod overlays
            applySelectiveAntiRecording();
            
            // Update view layouts with new parameters
            batchUpdateViewLayouts();
            
            isAntiRecordingActive = true;
            Log.i(TAG, "Selective anti-recording activated - recordings will show clean gameplay");
            
        } catch (Exception exception) {
            Log.e(TAG, "Error applying selective anti-recording", exception);
        }
        
        // Performance monitoring
        long endTime = System.currentTimeMillis();
        long updateTime = endTime - startTime;
        totalUpdateTime += updateTime;
        updateCount++;
        
        if (updateTime > 50) {
            Log.w(TAG, "Slow update detected: " + updateTime + "ms");
        }
    }

    /**
     * Disable selective anti-recording and restore normal overlay visibility
     */
    public static void unsetFakeRecorderWindowLayoutParams(WindowManager.LayoutParams mainParams, 
                                                          WindowManager.LayoutParams iconParams,
                                                          WindowManager.LayoutParams canvasParams, 
                                                          WindowManager windowManager, View mainView, 
                                                          View iconView, View canvasView, Context context) {
        
        Log.i(TAG, "Disabling selective anti-recording (normal mode)");
        
        sMainLayoutParams = mainParams;
        sIconLayoutParams = iconParams;
        sCanvasLayoutParams = canvasParams;
        sWindowManager = windowManager;
        sMainView = mainView;
        sIconView = iconView;
        sCanvasView = canvasView;
        sContext = context;

        try {
            // Restore original parameters to make overlays visible again
            restoreOriginalParameters();
            
            // Update view layouts to restore normal visibility
            batchUpdateViewLayouts();
            
            isAntiRecordingActive = false;
            Log.i(TAG, "Selective anti-recording deactivated - overlays visible in recordings");
            
        } catch (Exception e) {
            Log.e(TAG, "Error restoring normal recording mode", e);
        }
    }

    /**
     * Backup original window parameters for restoration
     */
    private static void backupOriginalParameters() {
        try {
            if (sMainLayoutParams != null) {
                originalMainParams = new WindowManager.LayoutParams();
                originalMainParams.copyFrom(sMainLayoutParams);
            }
            if (sIconLayoutParams != null) {
                originalIconParams = new WindowManager.LayoutParams();
                originalIconParams.copyFrom(sIconLayoutParams);
            }
            if (sCanvasLayoutParams != null) {
                originalCanvasParams = new WindowManager.LayoutParams();
                originalCanvasParams.copyFrom(sCanvasLayoutParams);
            }
            Log.d(TAG, "Original parameters backed up successfully");
        } catch (Exception e) {
            Log.e(TAG, "Error backing up original parameters", e);
        }
    }

    /**
     * Apply selective anti-recording flags only to ESP/mod overlay views
     * Base game remains visible in recordings
     */
    private static void applySelectiveAntiRecording() {
        Log.d(TAG, "Applying selective anti-recording to overlay views only");
        
        // Apply anti-recording to ESP canvas (this hides ESP overlays from recordings)
        if (sCanvasLayoutParams != null) {
            applyAntiRecordingFlags(sCanvasLayoutParams, "ESP_Canvas");
        }
        
        // Apply anti-recording to mod menu (this hides menu from recordings)
        if (sMainLayoutParams != null) {
            applyAntiRecordingFlags(sMainLayoutParams, "Mod_Menu");
        }
        
        // Apply anti-recording to icon (this hides icon from recordings)
        if (sIconLayoutParams != null) {
            applyAntiRecordingFlags(sIconLayoutParams, "Mod_Icon");
        }
        
        // NOTE: Base game view is NOT modified, so it remains visible in recordings
        Log.i(TAG, "Anti-recording applied to overlays only - base game will be visible");
    }

    /**
     * Restore original parameters to make overlays visible in recordings again
     */
    private static void restoreOriginalParameters() {
        Log.d(TAG, "Restoring original parameters for normal recording");
        
        try {
            if (originalMainParams != null && sMainLayoutParams != null) {
                sMainLayoutParams.copyFrom(originalMainParams);
                Log.d(TAG, "Main layout parameters restored");
            }
            if (originalIconParams != null && sIconLayoutParams != null) {
                sIconLayoutParams.copyFrom(originalIconParams);
                Log.d(TAG, "Icon layout parameters restored");
            }
            if (originalCanvasParams != null && sCanvasLayoutParams != null) {
                sCanvasLayoutParams.copyFrom(originalCanvasParams);
                Log.d(TAG, "Canvas layout parameters restored");
            }
        } catch (Exception e) {
            Log.e(TAG, "Error restoring original parameters", e);
        }
    }

    /**
     * Apply ROM-specific anti-recording flags to a specific layout
     */
    private static void applyAntiRecordingFlags(WindowManager.LayoutParams layoutParams, String viewName) {
        try {
            // Set window title to indicate overlay nature
            layoutParams.setTitle("BearMod_Overlay_" + viewName);
            
            // Apply ROM-specific anti-recording flags
            if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) {
                setXiaomiAntiRecording(layoutParams);
            } else if (check(ROM_EMUI)) {
                setHuaweiAntiRecording(layoutParams);
            } else if (check(ROM_OPPO)) {
                setOppoAntiRecording(layoutParams);
            } else if (check(ROM_VIVO)) {
                setVivoAntiRecording(layoutParams);
            } else if (check(ROM_ONEPLUS)) {
                setOnePlusAntiRecording(layoutParams);
            } else if (check(ROM_FLYME)) {
                setMeizuAntiRecording(layoutParams);
            } else if (isSanSung()) {
                setSamsungAntiRecording(layoutParams);
            } else {
                // Generic Android anti-recording
                setGenericAntiRecording(layoutParams);
            }
            
            Log.d(TAG, "Anti-recording flags applied to " + viewName);
            
        } catch (Exception e) {
            Log.w(TAG, "Error applying anti-recording flags to " + viewName, e);
        }
    }

    /**
     * Xiaomi/MIUI specific anti-recording for overlays
     */
    private static void setXiaomiAntiRecording(WindowManager.LayoutParams params) {
        try {
            // Set MIUI-specific title that gets filtered by screen recorder
            params.setTitle("com.miui.systemui.overlay");
            
            // Apply MIUI private flags to hide from recording
            if (cachedPrivateFlags != null) {
                int currentFlags = cachedPrivateFlags.getInt(params);
                cachedPrivateFlags.setInt(params, currentFlags | 0x20000000 | 0x8000000);
            }
            
            // MIUI extra flags for overlay hiding
            if (cachedExtraFlags != null) {
                cachedExtraFlags.setInt(params, 0x10000000);
            }
            
            Log.d(TAG, "MIUI anti-recording flags applied");
        } catch (Exception e) {
            Log.w(TAG, "Error setting MIUI anti-recording", e);
        }
    }

    /**
     * Huawei/EMUI specific anti-recording for overlays
     */
    private static void setHuaweiAntiRecording(WindowManager.LayoutParams params) {
        try {
            params.setTitle("com.huawei.systemui.overlay");
            
            if (cachedPrivateFlags != null) {
                int currentFlags = cachedPrivateFlags.getInt(params);
                cachedPrivateFlags.setInt(params, currentFlags | 0x40000000);
            }
            
            Log.d(TAG, "EMUI anti-recording flags applied");
        } catch (Exception e) {
            Log.w(TAG, "Error setting EMUI anti-recording", e);
        }
    }

    /**
     * OPPO specific anti-recording for overlays
     */
    private static void setOppoAntiRecording(WindowManager.LayoutParams params) {
        try {
            params.setTitle("com.oppo.systemui.overlay");
            
            if (cachedPrivateFlags != null) {
                int currentFlags = cachedPrivateFlags.getInt(params);
                cachedPrivateFlags.setInt(params, currentFlags | 0x10000000);
            }
            
            Log.d(TAG, "OPPO anti-recording flags applied");
        } catch (Exception e) {
            Log.w(TAG, "Error setting OPPO anti-recording", e);
        }
    }

    /**
     * Vivo specific anti-recording for overlays
     */
    private static void setVivoAntiRecording(WindowManager.LayoutParams params) {
        try {
            params.setTitle("com.vivo.systemui.overlay");
            
            if (cachedPrivateFlags != null) {
                int currentFlags = cachedPrivateFlags.getInt(params);
                cachedPrivateFlags.setInt(params, currentFlags | 0x20000000);
            }
            
            Log.d(TAG, "Vivo anti-recording flags applied");
        } catch (Exception e) {
            Log.w(TAG, "Error setting Vivo anti-recording", e);
        }
    }

    /**
     * OnePlus specific anti-recording for overlays
     */
    private static void setOnePlusAntiRecording(WindowManager.LayoutParams params) {
        try {
            params.setTitle("com.oneplus.systemui.overlay");
            
            if (cachedPrivateFlags != null) {
                int currentFlags = cachedPrivateFlags.getInt(params);
                cachedPrivateFlags.setInt(params, currentFlags | 0x8000000);
            }
            
            Log.d(TAG, "OnePlus anti-recording flags applied");
        } catch (Exception e) {
            Log.w(TAG, "Error setting OnePlus anti-recording", e);
        }
    }

    /**
     * Meizu specific anti-recording for overlays
     */
    private static void setMeizuAntiRecording(WindowManager.LayoutParams params) {
        try {
            params.setTitle("com.meizu.systemui.overlay");
            
            if (cachedMeizuFlags != null) {
                cachedMeizuFlags.setInt(params, 0x10000000);
            }
            
            Log.d(TAG, "Meizu anti-recording flags applied");
        } catch (Exception e) {
            Log.w(TAG, "Error setting Meizu anti-recording", e);
        }
    }

    /**
     * Samsung specific anti-recording for overlays
     */
    private static void setSamsungAntiRecording(WindowManager.LayoutParams params) {
        try {
            params.setTitle("com.samsung.systemui.overlay");
            
            if (cachedPrivateFlags != null) {
                int currentFlags = cachedPrivateFlags.getInt(params);
                cachedPrivateFlags.setInt(params, currentFlags | 0x4000000);
            }
            
            Log.d(TAG, "Samsung anti-recording flags applied");
        } catch (Exception e) {
            Log.w(TAG, "Error setting Samsung anti-recording", e);
        }
    }

    /**
     * Generic Android anti-recording for overlays
     */
    private static void setGenericAntiRecording(WindowManager.LayoutParams params) {
        try {
            params.setTitle("SystemUI_Overlay");
            
            // Generic Android flags to hide from recording
            if (cachedPrivateFlags != null) {
                int currentFlags = cachedPrivateFlags.getInt(params);
                cachedPrivateFlags.setInt(params, currentFlags | 0x8000000);
            }
            
            Log.d(TAG, "Generic anti-recording flags applied");
        } catch (Exception e) {
            Log.w(TAG, "Error setting generic anti-recording", e);
        }
    }

    // ===================================================================================================
    // SOPHISTICATED SELECTIVE OVERLAY HIDING SYSTEM
    // This system hides only ESP/mod overlays while keeping base game visible in recordings
    // ===================================================================================================
    
    // Anti-recording state management and parameter backup are now declared below
    
    /**
     * Initialize reflection cache to avoid repeated field lookups
     */
    @SuppressLint("DiscouragedPrivateApi")
    private static void initializeReflectionCache() {
        if (reflectionCacheInitialized) return;
        
        try {
            // Cache private flags field
            try {
                cachedPrivateFlags = WindowManager.LayoutParams.class.getDeclaredField("privateFlags");
                cachedPrivateFlags.setAccessible(true);
            } catch (Exception e) {
                Log.d(TAG, "privateFlags field not available");
            }
            
            // Cache extra flags field (MIUI)
            try {
                cachedExtraFlags = WindowManager.LayoutParams.class.getDeclaredField("extraFlags");
                cachedExtraFlags.setAccessible(true);
            } catch (Exception e) {
                Log.d(TAG, "extraFlags field not available");
            }
            
            // Cache meizu flags field
            try {
                cachedMeizuFlags = WindowManager.LayoutParams.class.getDeclaredField("meizuFlags");
                cachedMeizuFlags.setAccessible(true);
            } catch (Exception e) {
                Log.d(TAG, "meizuFlags field not available");
            }
            
            reflectionCacheInitialized = true;
            Log.d(TAG, "Reflection cache initialized successfully");
        } catch (Exception e) {
            Log.e(TAG, "Failed to initialize reflection cache", e);
        }
    }
    
    // Helper methods for selective anti-recording are defined later in the file
    
    /**
     * Check if device supports optimized mode based on performance
     */
    public static void enableOptimizedMode(boolean enabled) {
        isOptimizedMode = enabled;
        Log.d(TAG, "Optimized mode: " + (enabled ? "enabled" : "disabled"));
    }
    
    /**
     * Get performance statistics
     */
    @SuppressLint("DefaultLocale")
    public static String getPerformanceStats() {
        if (updateCount == 0) return "No updates performed yet";
        
        long avgUpdateTime = totalUpdateTime / updateCount;
        return String.format("Updates: %d, Avg time: %dms, Total: %dms", 
            updateCount, avgUpdateTime, totalUpdateTime);
    }

    /**
     * Batch update all view layouts for better performance
     */
    private static void batchUpdateViewLayouts() {
        if (sWindowManager == null) {
            Log.w(TAG, "Window manager is null, cannot update layouts");
            return;
        }
        
        // Update layouts in order: canvas first (most important), then others
        updateViewLayoutSafe(sCanvasView, sCanvasLayoutParams);
        updateViewLayoutSafe(sMainView, sMainLayoutParams);
        updateViewLayoutSafe(sIconView, sIconLayoutParams);
        
        Log.d(TAG, "Batch view layout update completed");
    }

    /**
     * Safely update a single view layout with error handling
     */
    private static void updateViewLayoutSafe(View view, WindowManager.LayoutParams layoutParams) {
        if (sWindowManager != null && view != null && layoutParams != null) {
            try {
                // Check if view is actually attached to window manager
                if (view.getParent() != null) {
                    sWindowManager.updateViewLayout(view, layoutParams);
                } else {
                    Log.w(TAG, "View not attached to window manager, skipping update");
                }
            } catch (IllegalArgumentException e) {
                Log.w(TAG, "View not found in window manager", e);
            } catch (Exception e) {
                Log.e(TAG, "Error updating view layout", e);
            }
        }
    }

    // ===================================================================================================
    // UTILITY METHODS
    // ===================================================================================================

    /**
     * Check if anti-recording is currently active
     */
    public static boolean isAntiRecordingActive() {
        return isAntiRecordingActive;
    }

    /**
     * Get status summary for debugging
     */
    @SuppressLint("DefaultLocale")
    public static String getStatusSummary() {
        return String.format("Anti-Recording: %s | Screen Recording Detected: %s | Updates: %d", 
            isAntiRecordingActive ? "ACTIVE" : "INACTIVE",
            isScreenRecordingDetected ? "YES" : "NO",
            updateCount);
    }

    private static String getFakeRecordWindowTitle() {
        return "BearMod_System_Overlay";
    }

    public static boolean check(String rom) {
        if (sName != null) {
            return sName.equals(rom);
        }

        if (ROM_MIUI.equals(rom)) {
            String prop = getProp(KEY_VERSION_MIUI);
            sName = TextUtils.isEmpty(prop) ? ROM_MIUI : prop;
        } else if (ROM_EMUI.equals(rom)) {
            String prop = getProp(KEY_VERSION_EMUI);
            sName = TextUtils.isEmpty(prop) ? ROM_EMUI : prop;
        } else if (ROM_OPPO.equals(rom)) {
            String prop = getProp(KEY_VERSION_OPPO);
            sName = TextUtils.isEmpty(prop) ? ROM_OPPO : prop;
        } else if (ROM_VIVO.equals(rom)) {
            String prop = getProp(KEY_VERSION_VIVO);
            sName = TextUtils.isEmpty(prop) ? ROM_VIVO : prop;
        } else if (ROM_SMARTISAN.equals(rom)) {
            String prop = getProp(KEY_VERSION_SMARTISAN);
            sName = TextUtils.isEmpty(prop) ? ROM_SMARTISAN : prop;
        } else if (ROM_NUBIAUI.equals(rom)) {
            String prop = getProp(KEY_VERSION_NUBIA);
            sName = TextUtils.isEmpty(prop) ? ROM_NUBIAUI : prop;
        } else if (ROM_ONEPLUS.equals(rom)) {
            String prop = getProp(KEY_VERSION_ONEPLIS);
            sName = TextUtils.isEmpty(prop) ? ROM_ONEPLUS : prop;
        } else if (ROM_SAMSUNG.equals(rom)) {
            String prop = getProp(KEY_VERSION_SAMSUNG);
            sName = TextUtils.isEmpty(prop) ? ROM_SAMSUNG : prop;
        } else if (ROM_BLACKSHARK.equals(rom)) {
            String prop = getProp(KEY_VERSION_BLACKSHARK);
            sName = TextUtils.isEmpty(prop) ? ROM_BLACKSHARK : prop;
        } else if (ROM_ROG.equals(rom)) {
            String prop = getProp(KEY_VERSION_ROG);
            sName = TextUtils.isEmpty(prop) ? ROM_ROG : prop;
        }

        return rom.equals(sName);
    }

    private static String getProp(String name) {
        String line = null;
        BufferedReader input = null;
        try {
            Process p = Runtime.getRuntime().exec("getprop " + name);
            input = new BufferedReader(new InputStreamReader(p.getInputStream()), 1024);
            line = input.readLine();
            input.close();
        } catch (IOException ex) {
            Log.e(TAG, "Unable to read prop " + name, ex);
            return null;
        } finally {
            if (input != null) {
                try {
                    input.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        return line;
    }
}
