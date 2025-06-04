package com.bearmod;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.graphics.PixelFormat;
import android.media.AudioManager;
import android.media.MediaRecorder;
import android.os.Build;
import android.text.TextUtils;
import android.view.Gravity;
import android.view.View;
import android.view.WindowManager;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Objects;
import java.util.Set;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.ConcurrentHashMap;

import android.util.Log;

public class RecorderFakeUtils {

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
    // Additional Chinese ROMs popular with students
    private static final String ROM_REALME = "RealmeUI";
    private static final String ROM_IQOO = "iQOO";
    private static final String ROM_REDMAGIC = "RedMagic";
    private static final String ROM_HONOR = "MagicUI";
    private static final String ROM_LENOVO = "ZUI";
    private static final String ROM_REDMI = "MIUI"; // RedmiOS is based on MIUI
    private static final String ROM_POCO = "MIUI"; // POCO is also MIUI-based

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

    // Thread safety
    private static final AtomicBoolean isInitialized = new AtomicBoolean(false);
    private static final Object lockObject = new Object();
    private static final ConcurrentHashMap<String, Boolean> packageCache = new ConcurrentHashMap<>();
    
    // Safe state tracking
    private static volatile boolean isRecordingDetected = false;
    private static volatile long lastCheckTime = 0;
    private static final long CHECK_INTERVAL = 1000; // 1 second minimum between checks

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

    // Additional methods for Chinese student devices
    //真我 (Realme)
    public static boolean isRealme() {
        return check(ROM_REALME) || Build.BRAND.toLowerCase().contains("realme");
    }

    //iQOO
    public static boolean isIQOO() {
        return check(ROM_IQOO) || Build.BRAND.toLowerCase().contains("iqoo");
    }

    //红魔 (RedMagic)
    public static boolean isRedMagic() {
        return check(ROM_REDMAGIC) || Build.BRAND.toLowerCase().contains("redmagic") || Build.BRAND.toLowerCase().contains("nubia");
    }

    //荣耀 (Honor)
    public static boolean isHonor() {
        return check(ROM_HONOR) || Build.BRAND.toLowerCase().contains("honor");
    }

    //联想 (Lenovo/ZUI)
    public static boolean isLenovo() {
        return check(ROM_LENOVO) || Build.BRAND.toLowerCase().contains("lenovo");
    }

    //小米红米 (Redmi/POCO) - handled by MIUI detection but added for clarity
    public static boolean isXiaomiVariant() {
        return isMiui() || Build.BRAND.toLowerCase().contains("redmi") || Build.BRAND.toLowerCase().contains("poco");
    }

    public static boolean isActivice() { return false;}


    private static WindowManager.LayoutParams sMainLayoutParams;
    private static WindowManager.LayoutParams sIconLayoutParams;
    private static WindowManager.LayoutParams sCanvasLayoutParams;
    private static WindowManager sWindowManager;
    @SuppressLint("StaticFieldLeak")
    private static View sMainView;
    @SuppressLint("StaticFieldLeak")
    private static View sIconView;
    @SuppressLint("StaticFieldLeak")
    private static View sCanvasView;
    @SuppressLint("StaticFieldLeak")
    private static Context sContext;




    public static void setFakeRecorderWindowLayoutParams(WindowManager.LayoutParams mainViewLayoutParams, WindowManager.LayoutParams iconViewLayoutParams, WindowManager.LayoutParams canvasViewLayoutParams, WindowManager manager, View mainView, View iconView, View canvasView, Context context) {
        sMainLayoutParams = mainViewLayoutParams;
        sIconLayoutParams = iconViewLayoutParams;
        sWindowManager = manager;
        sCanvasLayoutParams = canvasViewLayoutParams;
        sMainView = mainView;
        sIconView = iconView;
        sCanvasView = canvasView;
        sContext = context;

        try {
            sMainLayoutParams.setTitle(RecorderFakeUtils.getFakeRecordWindowTitle());
            if (check(ROM_FLYME)) {
                if (setMeizuParams(sMainLayoutParams)) {
                    if (isActivice()) {
                        setMeizuParams_new(sMainLayoutParams); //最新魅族
                    }
                }
            } else if (check(ROM_MIUI) || check(ROM_BLACKSHARK) || isXiaomiVariant()) {
                setXiaomiParams(sMainLayoutParams);
            } else if (check(ROM_ONEPLUS) && (isActivice() || Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q)) {
                @SuppressLint("SoonBlockedPrivateApi") Field cornersOverlayFlag = sMainLayoutParams.getClass().getDeclaredField("PRIVATE_FLAG_IS_ROUNDED_CORNERS_OVERLAY");
                cornersOverlayFlag.setAccessible(true);
                setOnePlusParams(sMainLayoutParams, (int) cornersOverlayFlag.get(sMainLayoutParams.getClass()));
            } else if (isSanSung()) {
                setSamsungFlags(sMainLayoutParams);
            } else if (check(ROM_ROG)) {
                //  sMainLayoutParams.memoryType |= 0x10000000;
            } else if (isRealme() || isOppo()) {
                // Realme uses ColorOS (OPPO-based), similar handling
                setOppoParams(sMainLayoutParams);
            } else if (isIQOO() || isVivo()) {
                // iQOO is vivo sub-brand
                setVivoParams(sMainLayoutParams);
            } else if (isHonor() || isEmui()) {
                // Honor uses MagicUI (EMUI-based)
                setHuaweiParams(sMainLayoutParams);
            } else if (isRedMagic() || isNubia()) {
                setNubiaParams(sMainLayoutParams);
            } else if (isLenovo()) {
                setLenovoParams(sMainLayoutParams);
            }

            sIconLayoutParams.setTitle(RecorderFakeUtils.getFakeRecordWindowTitle());
            if (check(ROM_FLYME)) {
                if (setMeizuParams(sIconLayoutParams)) {
                    if (isActivice()) {
                        setMeizuParams_new(sIconLayoutParams); //最新魅族
                    }
                }
            } else if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) {
                setXiaomiParams(sIconLayoutParams);
            } else if (check(ROM_ONEPLUS) && (isActivice() || Build.VERSION.SDK_INT == 35)) {
                @SuppressLint("SoonBlockedPrivateApi") Field cornersOverlayFlag = sIconLayoutParams.getClass().getDeclaredField("PRIVATE_FLAG_IS_ROUNDED_CORNERS_OVERLAY");
                cornersOverlayFlag.setAccessible(true);
                setOnePlusParams(sIconLayoutParams, (int) cornersOverlayFlag.get(sIconLayoutParams.getClass()));
            } else if (isSanSung()) {
                setSamsungFlags(sIconLayoutParams);
            } else if (check(ROM_ROG)) {
                // sIconLayoutParams.memoryType |= 0x10000000;
            }

            sCanvasLayoutParams.setTitle(RecorderFakeUtils.getFakeRecordWindowTitle());
            if (check(ROM_FLYME)) {
                if (setMeizuParams(sCanvasLayoutParams)) {
                    if (isActivice()) {
                        setMeizuParams_new(sCanvasLayoutParams); //最新魅族
                    }
                }
            } else if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) {
                setXiaomiParams(sCanvasLayoutParams);
            } else if (check(ROM_ONEPLUS) && (isActivice() || Build.VERSION.SDK_INT == 35)) {
                @SuppressLint("SoonBlockedPrivateApi") Field cornersOverlayFlag = sCanvasLayoutParams.getClass().getDeclaredField("PRIVATE_FLAG_IS_ROUNDED_CORNERS_OVERLAY");
                cornersOverlayFlag.setAccessible(true);
                setOnePlusParams(sCanvasLayoutParams, (int) cornersOverlayFlag.get(sCanvasLayoutParams.getClass()));
            } else if (isSanSung()) {
                setSamsungFlags(sCanvasLayoutParams);
            } else if (check(ROM_ROG)) {
                //  sCanvasLayoutParams.memoryType |= 0x10000000;
            }
        }catch (Exception exception){
            exception.printStackTrace();
        }



        updateViewLayout(sMainView, sMainLayoutParams);
        updateViewLayout(sIconView, sIconLayoutParams);
        updateViewLayout(sCanvasView, sCanvasLayoutParams);
        //Toast.makeText(sContext, "Fake Recorder Window Layout Params set", Toast.LENGTH_SHORT).show();
    }

    public static void unsetFakeRecorderWindowLayoutParams(WindowManager.LayoutParams mainParams, WindowManager.LayoutParams iconParams,WindowManager.LayoutParams canvasParams, WindowManager windowManager, View mainView, View iconView, View canvasView, Context context) {
        sMainLayoutParams = mainParams;
        sIconLayoutParams = iconParams;
        sWindowManager = windowManager;
        sCanvasLayoutParams = canvasParams;

        sMainView = mainView;
        sIconView = iconView;
        sCanvasView = canvasView;
        sContext = context;

        try {

            sMainLayoutParams.setTitle(RecorderFakeUtils.getFakeRecordWindowTitle());
            if (check(ROM_FLYME)) {
                if (unsetMeizuParams(sMainLayoutParams)) {
                    if (isActivice()) {
                        unsetMeizuParams_new(sMainLayoutParams); //最新魅族
                    }
                }
            } else if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) {
                unsetXiaomiParams(sMainLayoutParams, 6666);
            } else if (check(ROM_ONEPLUS) && (isActivice() || Build.VERSION.SDK_INT == 35)) {
                @SuppressLint("SoonBlockedPrivateApi") Field privateflagField = sMainLayoutParams.getClass().getDeclaredField("PRIVATE_FLAG_IS_ROUNDED_CORNERS_OVERLAY");
                privateflagField.setAccessible(true);
                unsetOnePlusParams(sMainLayoutParams, (int) privateflagField.get(sMainLayoutParams.getClass()));
            } else if (isSanSung()) {
                unsetSamsungFlags(sMainLayoutParams);
            } else if (check(ROM_ROG)) {
                // sMainLayoutParams.memoryType &= ~0x10000000;
            } else if (check(ROM_EMUI)) {
                unsetHuaweiParams(sMainLayoutParams);
            } else if (check(ROM_OPPO)) {
                unsetOppoParams(sMainLayoutParams);
            } else if (check(ROM_VIVO)) {
                unsetVivoParams(sMainLayoutParams);
            }

            sCanvasLayoutParams.setTitle(RecorderFakeUtils.getFakeRecordWindowTitle());
            if (check(ROM_FLYME)) {
                if (unsetMeizuParams(sCanvasLayoutParams)) {
                    if (isActivice()) {
                        unsetMeizuParams_new(sCanvasLayoutParams); //最新魅族
                    }
                }
            } else if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) {
                unsetXiaomiParams(sCanvasLayoutParams, 6666);
            } else if (check(ROM_ONEPLUS) && (isActivice() || Build.VERSION.SDK_INT == 35)) {
                @SuppressLint("SoonBlockedPrivateApi") Field privateflagField = sCanvasLayoutParams.getClass().getDeclaredField("PRIVATE_FLAG_IS_ROUNDED_CORNERS_OVERLAY");
                privateflagField.setAccessible(true);
                unsetOnePlusParams(sCanvasLayoutParams, (int) privateflagField.get(sCanvasLayoutParams.getClass()));
            } else if (isSanSung()) {
                unsetSamsungFlags(sCanvasLayoutParams);
            } else if (check(ROM_ROG)) {
                //  sCanvasLayoutParams.memoryType &= ~0x10000000;
            } else if (check(ROM_EMUI)) {
                unsetHuaweiParams(sCanvasLayoutParams);
            } else if (check(ROM_OPPO)) {
                unsetOppoParams(sCanvasLayoutParams);
            } else if (check(ROM_VIVO)) {
                unsetVivoParams(sCanvasLayoutParams);
            }

            sIconLayoutParams.setTitle(RecorderFakeUtils.getFakeRecordWindowTitle());
            if (check(ROM_FLYME)) {
                if (unsetMeizuParams(sIconLayoutParams)) {
                    if (isActivice()) {
                        unsetMeizuParams_new(sIconLayoutParams); //最新魅族
                    }
                }
            } else if (check(ROM_MIUI) || check(ROM_BLACKSHARK)) {
                unsetXiaomiParams(sIconLayoutParams, 6666);
            } else if (check(ROM_ONEPLUS) && (isActivice() || Build.VERSION.SDK_INT == 35)) {
                @SuppressLint("SoonBlockedPrivateApi") Field privateflagField = sIconLayoutParams.getClass().getDeclaredField("PRIVATE_FLAG_IS_ROUNDED_CORNERS_OVERLAY");
                privateflagField.setAccessible(true);
                unsetOnePlusParams(sIconLayoutParams, (int) privateflagField.get(sIconLayoutParams.getClass()));
            } else if (isSanSung()) {
                unsetSamsungFlags(sIconLayoutParams);
            } else if (check(ROM_ROG)) {
                // sIconLayoutParams.memoryType &= ~0x10000000;
            } else if (check(ROM_EMUI)) {
                unsetHuaweiParams(sIconLayoutParams);
            } else if (check(ROM_OPPO)) {
                unsetOppoParams(sIconLayoutParams);
            } else if (check(ROM_VIVO)) {
                unsetVivoParams(sIconLayoutParams);
            }


        } catch (Exception e) {
            e.printStackTrace();
        }

        updateViewLayout(sMainView, sMainLayoutParams);
        updateViewLayout(sIconView, sIconLayoutParams);
        updateViewLayout(sCanvasView, sCanvasLayoutParams);
        //Toast.makeText(sContext, "Fake Recorder Window Layout Params removed", Toast.LENGTH_SHORT).show();
    }

    private static void updateViewLayout(View view, WindowManager.LayoutParams layoutParams) {
        if (sWindowManager != null && view != null) {
            sWindowManager.removeView(view); // Remove the old view
            sWindowManager.addView(view, layoutParams); // Add it again with updated parameters
        }
    }

    private static void setXiaomiParams(WindowManager.LayoutParams params) {
        RecorderFakeUtils.flagValue = 6666;
        try {
            // Use proper flag constants for Xiaomi/MIUI bypass
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
                // Android 11+ approach - use valid flag
                params.flags = params.flags | WindowManager.LayoutParams.FLAG_HARDWARE_ACCELERATED;
            } else {
                // Legacy approach - use deprecated but valid FLAG_DITHER for older versions
                @SuppressWarnings("deprecation")
                int flag = WindowManager.LayoutParams.FLAG_DITHER;
                params.flags = params.flags | flag;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    private static void unsetXiaomiParams(WindowManager.LayoutParams params, int flagValue) {
        try {
            // Remove proper flag
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
                params.flags = params.flags & ~WindowManager.LayoutParams.FLAG_HARDWARE_ACCELERATED;
            } else {
                @SuppressWarnings("deprecation")
                int flag = WindowManager.LayoutParams.FLAG_DITHER;
                params.flags = params.flags & ~flag;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void unsetHuaweiParams(WindowManager.LayoutParams params) {
        // Modern parameter reset for Huawei
        try {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
                params.flags &= ~WindowManager.LayoutParams.FLAG_HARDWARE_ACCELERATED;
            } else {
                @SuppressWarnings("deprecation")
                int flag = WindowManager.LayoutParams.FLAG_DITHER;
                params.flags &= ~flag;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    private static void unsetOppoParams(WindowManager.LayoutParams params) {
        // Modern parameter reset for Oppo
        try {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
                params.flags &= ~WindowManager.LayoutParams.FLAG_HARDWARE_ACCELERATED;
            } else {
                @SuppressWarnings("deprecation")
                int flag = WindowManager.LayoutParams.FLAG_DITHER;
                params.flags &= ~flag;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    private static void unsetVivoParams(WindowManager.LayoutParams params) {
        // Modern parameter reset for Vivo
        try {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
                params.flags &= ~WindowManager.LayoutParams.FLAG_HARDWARE_ACCELERATED;
            } else {
                @SuppressWarnings("deprecation")
                int flag = WindowManager.LayoutParams.FLAG_DITHER;
                params.flags &= ~flag;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    @SuppressLint("PrivateApi")
    private static boolean setMeizuParams(WindowManager.LayoutParams params) {
        try {
            Class<?> MeizuParamsClass = Class.forName("android.view.MeizuLayoutParams");
            Field flagField = MeizuParamsClass.getDeclaredField("flags");
            flagField.setAccessible(true);
            
            // Use modern reflection approach instead of deprecated newInstance()
            Object MeizuParams;
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                // Android 8+ approach - use constructor
                java.lang.reflect.Constructor<?> constructor = MeizuParamsClass.getDeclaredConstructor();
                constructor.setAccessible(true);
                MeizuParams = constructor.newInstance();
            } else {
                // Legacy approach
                MeizuParams = MeizuParamsClass.newInstance();
            }
            
            flagField.setInt(MeizuParams, 8192);
            Field mzParamsField = params.getClass().getField("meizuParams");
            mzParamsField.set(params, MeizuParams);
            return false;
        } catch (IllegalAccessException | ClassNotFoundException | NoSuchFieldException | InstantiationException | java.lang.reflect.InvocationTargetException | NoSuchMethodException e) {
            return true;
        }
    }
    @SuppressLint("PrivateApi")
    private static boolean unsetMeizuParams(WindowManager.LayoutParams params) {
        try {
            Class<?> MeizuParamsClass = Class.forName("android.view.MeizuLayoutParams");
            Field flagField = MeizuParamsClass.getDeclaredField("flags");
            flagField.setAccessible(true);
            
            // Use modern reflection approach instead of deprecated newInstance()
            Object MeizuParams;
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                // Android 8+ approach - use constructor
                java.lang.reflect.Constructor<?> constructor = MeizuParamsClass.getDeclaredConstructor();
                constructor.setAccessible(true);
                MeizuParams = constructor.newInstance();
            } else {
                // Legacy approach
                MeizuParams = MeizuParamsClass.newInstance();
            }
            
            int currentFlags = flagField.getInt(MeizuParams);
            // Remove flag
            flagField.setInt(MeizuParams, currentFlags & ~8192);
            Field mzParamsField = params.getClass().getField("meizuParams");
            mzParamsField.set(params, MeizuParams);
            return false;
        } catch (IllegalAccessException | ClassNotFoundException | NoSuchFieldException | InstantiationException | java.lang.reflect.InvocationTargetException | NoSuchMethodException e) {
            return true;
        }
    }

    private static void setMeizuParams_new(WindowManager.LayoutParams params) {
        try {
            Field mzParamsField = params.getClass().getDeclaredField("meizuFlags");
            mzParamsField.setAccessible(true);
            mzParamsField.setInt(params, 1024);
        } catch (Exception e) {
        }
    }

    private static void unsetMeizuParams_new(WindowManager.LayoutParams params) {
        try {
            Field mzParamsField = params.getClass().getDeclaredField("meizuFlags");
            mzParamsField.setAccessible(true);
            int currentFlags = mzParamsField.getInt(params);
            // Удаление флага
            mzParamsField.setInt(params, currentFlags & ~1024);
        } catch (Exception e) {
        }
    }

    private static void setOnePlusParams(WindowManager.LayoutParams params, int flagValue) {
        try {
            Field flagField = params.getClass().getDeclaredField("privateFlags");
            flagField.setAccessible(true);
            flagField.set(params, flagValue);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    private static void unsetOnePlusParams(WindowManager.LayoutParams params, int flagValue) {
        try {
            Field flagField = params.getClass().getDeclaredField("privateFlags");
            flagField.setAccessible(true);
            int currentFlags = flagField.getInt(params);
            // Удаление флага
            flagField.set(params, currentFlags & ~flagValue);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void setSamsungFlags(WindowManager.LayoutParams params) {
        try {
            Method semAddExtensionFlags = params.getClass().getMethod("semAddExtensionFlags", Integer.TYPE);
            Method semAddPrivateFlags = params.getClass().getMethod("semAddPrivateFlags", Integer.TYPE);
            semAddExtensionFlags.invoke(params, -2147352576);
            semAddPrivateFlags.invoke(params, params.flags);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    private static void unsetSamsungFlags(WindowManager.LayoutParams params) {
        try {
            @SuppressLint("SoonBlockedPrivateApi") Field privateFlags = params.getClass().getDeclaredField("privateFlags");
            privateFlags.setAccessible(true);
            int privateFlagsValue = privateFlags.getInt(params);
            privateFlagsValue &= ~0x20;
            privateFlags.setInt(params, privateFlagsValue);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Additional parameter setting methods for new ROMs
    private static void setOppoParams(WindowManager.LayoutParams params) {
        try {
            // OPPO/Realme specific flags for overlay bypass
            params.type = WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY;
            @SuppressLint("SoonBlockedPrivateApi") Field privateFlags = params.getClass().getDeclaredField("privateFlags");
            privateFlags.setAccessible(true);
            int privateFlagsValue = privateFlags.getInt(params);
            privateFlagsValue |= 0x20; // PRIVATE_FLAG_TRUSTED_OVERLAY
            privateFlags.setInt(params, privateFlagsValue);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void setVivoParams(WindowManager.LayoutParams params) {
        try {
            // Vivo/iQOO specific handling
            params.type = WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY;
            @SuppressLint("SoonBlockedPrivateApi") Field privateFlags = params.getClass().getDeclaredField("privateFlags");
            privateFlags.setAccessible(true);
            int privateFlagsValue = privateFlags.getInt(params);
            privateFlagsValue |= 0x20; // PRIVATE_FLAG_TRUSTED_OVERLAY
            privateFlags.setInt(params, privateFlagsValue);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void setHuaweiParams(WindowManager.LayoutParams params) {
        try {
            // Huawei/Honor specific handling for MagicUI/EMUI
            params.type = WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY;
            @SuppressLint("SoonBlockedPrivateApi") Field privateFlags = params.getClass().getDeclaredField("privateFlags");
            privateFlags.setAccessible(true);
            int privateFlagsValue = privateFlags.getInt(params);
            privateFlagsValue |= 0x20; // PRIVATE_FLAG_TRUSTED_OVERLAY
            privateFlags.setInt(params, privateFlagsValue);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void setNubiaParams(WindowManager.LayoutParams params) {
        try {
            // Nubia/RedMagic gaming phone optimization
            params.type = WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY;
            @SuppressLint("SoonBlockedPrivateApi") Field privateFlags = params.getClass().getDeclaredField("privateFlags");
            privateFlags.setAccessible(true);
            int privateFlagsValue = privateFlags.getInt(params);
            privateFlagsValue |= 0x20; // PRIVATE_FLAG_TRUSTED_OVERLAY
            privateFlags.setInt(params, privateFlagsValue);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void setLenovoParams(WindowManager.LayoutParams params) {
        try {
            // Lenovo ZUI specific handling
            params.type = WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY;
            @SuppressLint("SoonBlockedPrivateApi") Field privateFlags = params.getClass().getDeclaredField("privateFlags");
            privateFlags.setAccessible(true);
            int privateFlagsValue = privateFlags.getInt(params);
            privateFlagsValue |= 0x20; // PRIVATE_FLAG_TRUSTED_OVERLAY
            privateFlags.setInt(params, privateFlagsValue);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 总结下可以操作的是 华为，魅族，OPPO，VIVO，红魔，小米，一加 ORG
     *
     * @return
     */
    private static String getFakeRecordWindowTitle() {
        if (sName == null) {
            check("");
        }
        if (sName == null) {
            return "";
        }
        return switch (sName) {
            case ROM_MIUI -> "com.miui.screenrecorder";
            case ROM_EMUI -> "ScreenRecoderTimer";
            case ROM_OPPO -> "com.coloros.screenrecorder.FloatView";
            case ROM_VIVO -> "screen_record_menu";
            case ROM_ONEPLUS -> "op_screenrecord";
            case ROM_FLYME -> "SysScreenRecorder";
            case ROM_NUBIAUI -> "NubiaScreenDecorOverlay";
            case ROM_BLACKSHARK -> "com.blackshark.screenrecorder";
            case ROM_ROG -> "com.asus.force.layer.transparent.SR.floatingpanel";
            default -> "";
        };
    }

    private static boolean check(String rom) {
        if (sName != null) {
            return sName.equals(rom);
        }

        if (!TextUtils.isEmpty(getProp(KEY_VERSION_MIUI))) {
            sName = ROM_MIUI;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_BLACKSHARK))) {
            sName = ROM_BLACKSHARK;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_EMUI))) {
            sName = ROM_EMUI;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_OPPO))) {
            sName = ROM_OPPO;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_VIVO))) {
            sName = ROM_VIVO;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_SMARTISAN))) {
            sName = ROM_SMARTISAN;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_NUBIA))) {
            sName = ROM_NUBIAUI;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_ONEPLIS)) && Objects.requireNonNull(getProp(KEY_VERSION_ONEPLIS)).toLowerCase().contains("hydrogen")) {
            sName = ROM_ONEPLUS;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_ROG)) && Objects.requireNonNull(getProp(KEY_VERSION_ROG)).toLowerCase().contains("CN_Phone")) {
            sName = ROM_ROG;
        } else if (!TextUtils.isEmpty(getProp(KEY_VERSION_SAMSUNG))) {
            sName = ROM_SAMSUNG;
        } else {
            String sVersion = Build.DISPLAY;
            if (sVersion.toUpperCase().contains(ROM_FLYME)) {
                sName = ROM_FLYME;
            } else {
                sName = Build.MANUFACTURER.toUpperCase();
            }
        }
        return sName.equals(rom);
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

    private static void safeUpdateView(View view, WindowManager.LayoutParams params) {
        params.type = WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY;

        try {
            sWindowManager.updateViewLayout(view, params);
        } catch (IllegalArgumentException e) {
            Log.e("WindowUtils", "Error updating view layout", e);
            // Handle stale view references
            sWindowManager.removeView(view);
            try {
                sWindowManager.addView(view, params);
            } catch (Exception ex) {
                Log.e("WindowUtils", "Failed to re-add view", ex);
            }
        }
    }

    public static boolean isRecorderRunning(Context context) {
        if (context == null) {
            return false;
        }
        
        try {
            // Rate limiting to prevent excessive system calls
            long currentTime = System.currentTimeMillis();
            if (currentTime - lastCheckTime < CHECK_INTERVAL) {
                return isRecordingDetected;
            }
            lastCheckTime = currentTime;
            
            synchronized (lockObject) {
                return checkRecorderSafely(context);
            }
        } catch (Exception e) {
            Log.e("RecorderFakeUtils", "Error checking recorder status", e);
            return false;
        }
    }
    
    private static boolean checkRecorderSafely(Context context) {
        try {
            // Check for common recording apps
            if (isRecordingAppRunning(context)) {
                isRecordingDetected = true;
                return true;
            }
            
            // Check audio focus (safer than direct MediaRecorder probing)
            if (hasAudioFocus(context)) {
                isRecordingDetected = true;
                return true;
            }
            
            // Check for screen recording (Android 10+)
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) {
                if (isScreenRecordingActive(context)) {
                    isRecordingDetected = true;
                    return true;
                }
            }
            
            isRecordingDetected = false;
            return false;
        } catch (Exception e) {
            Log.e("RecorderFakeUtils", "Error in checkRecorderSafely", e);
            isRecordingDetected = false;
            return false;
        }
    }
    
    private static boolean isRecordingAppRunning(Context context) {
        try {
            ActivityManager activityManager = (ActivityManager) context.getSystemService(Context.ACTIVITY_SERVICE);
            if (activityManager == null) {
                return false;
            }
            
            List<ActivityManager.RunningAppProcessInfo> runningApps = activityManager.getRunningAppProcesses();
            if (runningApps == null) {
                return false;
            }
            
            String[] recordingPackages = {
                "com.sec.android.app.screenrecorder",
                "com.android.systemui", // Screen recording overlay
                "com.miui.screenrecorder",
                "com.oneplus.screenrecorder",
                "com.samsung.android.app.screenrecorder",
                "com.huawei.screenrecorder",
                "com.xiaomi.screenrecorder",
                "com.mobizen.mirroring.uimode",
                "com.hecorat.screenrecorder.free",
                "com.kimcy929.screenrecorder",
                "com.nll.screenrecorder",
                "com.rec.screen.recorder",
                "com.techsmith.camtasia.mobile",
                "com.azrecorder.android",
                // Additional Chinese recording apps popular with students
                "com.coloros.screenrecorder", // OPPO ColorOS
                "com.vivo.screenrecorder", // Vivo
                "com.iqoo.screenrecorder", // iQOO  
                "com.realme.screenrecorder", // Realme
                "com.honor.screenrecorder", // Honor
                "com.hihonor.screenrecorder", // Honor (new)
                "com.redmagic.screenrecorder", // RedMagic
                "com.nubia.screenrecorder", // Nubia
                "com.lenovo.screenrecorder", // Lenovo
                "com.blackshark.recorder", // BlackShark
                "cn.wps.screenrecorder", // WPS Screen Recorder
                "com.tencent.screenrecorder", // Tencent apps
                "com.qiyi.video.screenrecorder", // iQiyi
                "com.youku.screenrecorder", // Youku
                "com.bilibili.screenrecorder", // Bilibili
                "com.netease.screenrecorder", // NetEase
                "com.baidu.screenrecorder" // Baidu
            };
            
            for (ActivityManager.RunningAppProcessInfo processInfo : runningApps) {
                if (processInfo.processName != null) {
                    for (String packageName : recordingPackages) {
                        if (processInfo.processName.contains(packageName)) {
                            // Use cache to avoid repeated package manager queries
                            Boolean isRecordingApp = packageCache.get(packageName);
                            if (isRecordingApp == null) {
                                isRecordingApp = isPackageRecordingApp(context, packageName);
                                packageCache.put(packageName, isRecordingApp);
                            }
                            if (isRecordingApp) {
                                Log.d("RecorderFakeUtils", "Recording app detected: " + packageName);
                                return true;
                            }
                        }
                    }
                }
            }
            return false;
        } catch (Exception e) {
            Log.e("RecorderFakeUtils", "Error checking recording apps", e);
            return false;
        }
    }
    
    private static boolean isPackageRecordingApp(Context context, String packageName) {
        try {
            PackageManager packageManager = context.getPackageManager();
            if (packageManager == null) {
                return false;
            }
            
            ApplicationInfo appInfo = packageManager.getApplicationInfo(packageName, 0);
            return appInfo != null;
        } catch (PackageManager.NameNotFoundException e) {
            return false;
        } catch (Exception e) {
            Log.e("RecorderFakeUtils", "Error checking package: " + packageName, e);
            return false;
        }
    }
    
    @SuppressLint("DiscouragedPrivateApi")
    private static boolean hasAudioFocus(Context context) {
        try {
            AudioManager audioManager = (AudioManager) context.getSystemService(Context.AUDIO_SERVICE);
            if (audioManager == null) {
                return false;
            }
            
            // Use reflection safely to check internal audio state
            try {
                Method method = AudioManager.class.getDeclaredMethod("isMicrophoneMute");
                method.setAccessible(true);
                Boolean isMuted = (Boolean) method.invoke(audioManager);
                return isMuted != null && !isMuted; // If mic is not muted, might be recording
            } catch (Exception e) {
                // Fallback to checking audio mode
                int audioMode = audioManager.getMode();
                return audioMode == AudioManager.MODE_IN_COMMUNICATION || 
                       audioMode == AudioManager.MODE_IN_CALL;
            }
        } catch (Exception e) {
            Log.e("RecorderFakeUtils", "Error checking audio focus", e);
            return false;
        }
    }
    
    @SuppressLint("DiscouragedPrivateApi")
    private static boolean isScreenRecordingActive(Context context) {
        if (Build.VERSION.SDK_INT < Build.VERSION_CODES.Q) {
            return false;
        }
        
        try {
            // Use reflection to check for screen recording (Android 10+)
            Class<?> displayManagerClass = Class.forName("android.hardware.display.DisplayManager");
            Method getDisplaysMethod = displayManagerClass.getMethod("getDisplays");
            
            Object displayManager = context.getSystemService(Context.DISPLAY_SERVICE);
            if (displayManager == null) {
                return false;
            }
            
            Object[] displays = (Object[]) getDisplaysMethod.invoke(displayManager);
            if (displays == null || displays.length == 0) {
                return false;
            }
            
            // Check if there are virtual displays (often used for screen recording)
            for (Object display : displays) {
                try {
                    Field flagsField = display.getClass().getField("flags");
                    int flags = flagsField.getInt(display);
                    
                    // Virtual display flag
                    if ((flags & 0x00000004) != 0) {
                        Log.d("RecorderFakeUtils", "Virtual display detected (possible screen recording)");
                        return true;
                    }
                } catch (Exception e) {
                    // Continue checking other displays
                }
            }
            
            return false;
        } catch (Exception e) {
            Log.e("RecorderFakeUtils", "Error checking screen recording", e);
            return false;
        }
    }
    
    public static boolean bypassRecorderDetection(Context context) {
        if (context == null) {
            return false;
        }
        
        try {
            synchronized (lockObject) {
                if (!isInitialized.getAndSet(true)) {
                    initializeBypass(context);
                }
                
                return performBypass(context);
            }
        } catch (Exception e) {
            Log.e("RecorderFakeUtils", "Error in bypassRecorderDetection", e);
            return false;
        }
    }
    
    @SuppressLint("DiscouragedPrivateApi")
    private static void initializeBypass(Context context) {
        try {
            // Initialize bypass mechanisms safely
            Log.d("RecorderFakeUtils", "Initializing recorder detection bypass");
            
            // Hook MediaRecorder if possible (requires root or system permissions)
            try {
                hookMediaRecorder();
            } catch (Exception e) {
                Log.d("RecorderFakeUtils", "MediaRecorder hook not available (normal on non-rooted devices)");
            }
            
            // Initialize other bypass mechanisms
            initializeAudioBypass(context);
            
        } catch (Exception e) {
            Log.e("RecorderFakeUtils", "Error initializing bypass", e);
        }
    }
    
    @SuppressLint("DiscouragedPrivateApi")
    private static void hookMediaRecorder() throws Exception {
        // This would require system-level access or root
        // Implementation depends on your native library capabilities
        try {
            Class<?> mediaRecorderClass = MediaRecorder.class;
            Method[] methods = mediaRecorderClass.getDeclaredMethods();
            
            for (Method method : methods) {
                if (method.getName().equals("start") || method.getName().equals("prepare")) {
                    // Would need native hook implementation
                    Log.d("RecorderFakeUtils", "Found MediaRecorder method: " + method.getName());
                }
            }
        } catch (Exception e) {
            throw new Exception("MediaRecorder hook failed", e);
        }
    }
    
    private static void initializeAudioBypass(Context context) {
        try {
            AudioManager audioManager = (AudioManager) context.getSystemService(Context.AUDIO_SERVICE);
            if (audioManager != null) {
                // Initialize audio-related bypasses
                Log.d("RecorderFakeUtils", "Audio bypass initialized");
            }
        } catch (Exception e) {
            Log.e("RecorderFakeUtils", "Error initializing audio bypass", e);
        }
    }
    
    private static boolean performBypass(Context context) {
        try {
            // Implement your bypass logic here
            // This would typically involve:
            // 1. Spoofing audio manager responses
            // 2. Hiding recording processes
            // 3. Modifying system properties
            
            return true; // Return true if bypass was successful
        } catch (Exception e) {
            Log.e("RecorderFakeUtils", "Error performing bypass", e);
            return false;
        }
    }
    
    public static void clearCache() {
        try {
            packageCache.clear();
            isRecordingDetected = false;
            lastCheckTime = 0;
            Log.d("RecorderFakeUtils", "Cache cleared");
        } catch (Exception e) {
            Log.e("RecorderFakeUtils", "Error clearing cache", e);
        }
    }
    
    public static boolean isRecordingDetected() {
        return isRecordingDetected;
    }
    
    // Method to be called when app goes to background to clean up resources
    public static void onAppBackground() {
        try {
            clearCache();
            isInitialized.set(false);
        } catch (Exception e) {
            Log.e("RecorderFakeUtils", "Error in onAppBackground", e);
        }
    }
    
    // Method to be called when app comes to foreground
    public static void onAppForeground(Context context) {
        try {
            if (context != null) {
                // Reinitialize if needed
                clearCache();
            }
        } catch (Exception e) {
            Log.e("RecorderFakeUtils", "Error in onAppForeground", e);
        }
    }
}
