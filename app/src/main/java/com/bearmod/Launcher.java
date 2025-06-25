package com.bearmod;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.net.Uri;
import android.provider.Settings;
import android.util.Log;

import android.app.Activity;

import com.bearmod.auth.SimpleLicenseVerifier;

import java.util.concurrent.atomic.AtomicBoolean;

public class Launcher {
    private static final String TAG = "Launcher";
    private static final AtomicBoolean isInitializing = new AtomicBoolean(false);
    private static final Object lockObject = new Object();
    private static volatile SharedPreferences gifs;

    public static native String LoginNameNrg();
    public static native String Pleaselog();
    public static native String KeyAdd();
    public static native String Login();
    public static native String Cancel();
    public static native String Error();
    public static native String Pleasecheck();
    public static native String Ok();
    public static native String Loging();
    
    // Fallback methods when native library is not available
    private static String getLoginNameNrg() {
        if (nativeLibraryLoaded) {
            try {
                return LoginNameNrg();
            } catch (UnsatisfiedLinkError e) {
                android.util.Log.w("Launcher", "Native method not available: LoginNameNrg");
            }
        }
        return "BearMod Login";
    }
    
    private static String getPleaselog() {
        if (nativeLibraryLoaded) {
            try {
                return Pleaselog();
            } catch (UnsatisfiedLinkError e) {
                android.util.Log.w("Launcher", "Native method not available: Pleaselog");
            }
        }
        return "Please log in";
    }
    
    private static String getKeyAdd() {
        if (nativeLibraryLoaded) {
            try {
                return KeyAdd();
            } catch (UnsatisfiedLinkError e) {
                android.util.Log.w("Launcher", "Native method not available: KeyAdd");
            }
        }
        return "Enter your key";
    }
    
    private static String getLogin() {
        if (nativeLibraryLoaded) {
            try {
                return Login();
            } catch (UnsatisfiedLinkError e) {
                android.util.Log.w("Launcher", "Native method not available: Login");
            }
        }
        return "Login";
    }
    
    private static String getCancel() {
        if (nativeLibraryLoaded) {
            try {
                return Cancel();
            } catch (UnsatisfiedLinkError e) {
                android.util.Log.w("Launcher", "Native method not available: Cancel");
            }
        }
        return "Cancel";
    }
    
    private static String getError() {
        if (nativeLibraryLoaded) {
            try {
                return Error();
            } catch (UnsatisfiedLinkError e) {
                android.util.Log.w("Launcher", "Native method not available: Error");
            }
        }
        return "Error";
    }
    
    private static String getPleasecheck() {
        if (nativeLibraryLoaded) {
            try {
                return Pleasecheck();
            } catch (UnsatisfiedLinkError e) {
                android.util.Log.w("Launcher", "Native method not available: Pleasecheck");
            }
        }
        return "Please check your key";
    }
    
    private static String getOk() {
        if (nativeLibraryLoaded) {
            try {
                return Ok();
            } catch (UnsatisfiedLinkError e) {
                android.util.Log.w("Launcher", "Native method not available: Ok");
            }
        }
        return "OK";
    }
    
    private static String getLoging() {
        if (nativeLibraryLoaded) {
            try {
                return Loging();
            } catch (UnsatisfiedLinkError e) {
                android.util.Log.w("Launcher", "Native method not available: Loging");
            }
        }
        return "Logging in...";
    }
    
    private static boolean nativeLibraryLoaded = false;
    
    static{
        try {
            System.loadLibrary("bearmod");
            nativeLibraryLoaded = true;
            android.util.Log.d("Launcher", "Native library loaded successfully");
        } catch (UnsatisfiedLinkError e) {
            android.util.Log.e("Launcher", "Failed to load native library: " + e.getMessage());
            nativeLibraryLoaded = false;
        }
    }

    void hideesp()
    {
        // Note: ESP hiding will be handled by native code when available
        android.util.Log.d("Launcher", "ESP hide requested");
    }

    void stopHideesp()
    {
        // Note: ESP show will be handled by native code when available
        android.util.Log.d("Launcher", "ESP show requested");
    }

    public static void Init(Object object) {
        try {
            if (object == null) return;
            if (!isInitializing.compareAndSet(false, true)) return;
            
            synchronized (lockObject) {
                final Context context = (Context) object;
                Activity activity = (Activity) object;

                Init(context);

                // Check overlay permission
                if (!Settings.canDrawOverlays(context)) {
                    Intent intent = new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION,
                            Uri.parse("package:" + context.getPackageName()));
                    activity.startActivity(intent);
                }

                try {
                    gifs = context.getSharedPreferences(context.getPackageName(), Context.MODE_PRIVATE);
                } catch (Exception e) {
                    e.printStackTrace();
                    isInitializing.set(false);
                    return;
                }

                // Login flow is now handled by MainActivity and LauncherLoginActivity
                // This method is only called to initialize native code
                android.util.Log.d("Launcher", "Native initialization completed");
            }
        } catch (Exception e) {
            e.printStackTrace();
            isInitializing.set(false);
        }
    }

    // Login dialog removed - now using LauncherLoginActivity

    // Old Login method removed - now using loginAsync for LauncherLoginActivity

    // Error dialog removed - errors now handled in LauncherLoginActivity

    private static String getEspMenuText(String en, String cn) {
        String lang = java.util.Locale.getDefault().getLanguage();
        return "zh".equals(lang) ? cn : en;
    }

    public static boolean hasValidKey(Context context) {
        // Simple check for stored license key
        return context.getSharedPreferences(context.getPackageName(), Context.MODE_PRIVATE).contains("USER_KEY");
    }
    
    public static boolean isNativeLibraryLoaded() {
        return nativeLibraryLoaded;
    }

    public static void clearKey(Context context) {
        SharedPreferences prefs = context.getSharedPreferences(context.getPackageName(), Context.MODE_PRIVATE);
        prefs.edit().remove("USER_KEY").apply();
    }

    // Native CURL authentication removed - using KeyAuth API only
    private static native void Init(Context mContext);
    
    // Only keep native Init for ESP/mod functionality
    public static void safeInit(Context mContext) {
        if (nativeLibraryLoaded) {
            try {
                Init(mContext);
                android.util.Log.d("Launcher", "Native Init called successfully");
            } catch (UnsatisfiedLinkError e) {
                android.util.Log.w("Launcher", "Native Init not available, using fallback");
            }
        } else {
            android.util.Log.i("Launcher", "Running in demo mode - native library not loaded");
        }
    }

    public interface LoginCallback {
        void onSuccess();
        void onError(String errorMessage);
    }

    public static void loginAsync(Context context, String userKey, LoginCallback callback) {
        Log.d(TAG, "Starting KeyAuth license verification...");
        
        // Use ONLY KeyAuth API - no fallback to CURL
        SimpleLicenseVerifier.verifyLicense(context, userKey, new SimpleLicenseVerifier.LicenseCallback() {
            @Override
            public void onSuccess(String message) {
                new android.os.Handler(android.os.Looper.getMainLooper()).post(() -> {
                    Log.d(TAG, "KeyAuth license verification successful: " + message);
                    // Save the key for future use
                    SharedPreferences prefs = context.getSharedPreferences(context.getPackageName(), Context.MODE_PRIVATE);
                    prefs.edit().putString("USER_KEY", userKey).apply();
                    callback.onSuccess();
                });
            }
            
            @Override
            public void onFailure(String error) {
                new android.os.Handler(android.os.Looper.getMainLooper()).post(() -> {
                    Log.e(TAG, "KeyAuth license verification failed: " + error);
                    // No fallback - KeyAuth API only
                    callback.onError("License verification failed: " + error);
                });
            }
        });
    }
    
    // CURL fallback method removed - using KeyAuth API only
    
    /**
     * Get device HWID for debugging/logging
     */
    public static String getDeviceHWID(Context context) {
        return SimpleLicenseVerifier.getDeviceHWID(context);
    }

}


