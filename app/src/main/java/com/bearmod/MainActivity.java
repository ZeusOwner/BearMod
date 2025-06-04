package com.bearmod;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.res.Configuration;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.provider.Settings;
import android.util.Log;
import android.widget.Toast;
import java.util.concurrent.atomic.AtomicBoolean;

public class MainActivity extends Activity {
    private static final String TAG = "BearMod_MainActivity";
    private final AtomicBoolean isDestroyed = new AtomicBoolean(false);
    private final AtomicBoolean hasInitialized = new AtomicBoolean(false);
    private Handler mainHandler;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        try {
            super.onCreate(savedInstanceState);
            // Load native library safely
            try {
                System.loadLibrary("bearmod");
            } catch (UnsatisfiedLinkError | Exception e) {
                Log.e(TAG, "Failed to load native library", e);
                Toast.makeText(this, "Native features disabled", Toast.LENGTH_LONG).show();
            }
            mainHandler = new Handler(Looper.getMainLooper());
            
            Log.d(TAG, "MainActivity onCreate");
            
            // Safety check for overlay permission before proceeding
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                if (!Settings.canDrawOverlays(this)) {
                    Log.d(TAG, "Requesting overlay permission");
                    requestOverlayPermission();
                    return;
                }
            }
            
            initializeLauncher();
        } catch (Exception e) {
            Log.e(TAG, "Error in onCreate", e);
            handleError("Failed to initialize application");
        }
    }
    
    private void handleBackPress() {
        // Common back press logic
        try {
            Log.d(TAG, "Handling back press");
            // Add any custom back press logic here if needed
            finish();
        } catch (Exception e) {
            Log.e(TAG, "Error in handleBackPress", e);
            finish();
        }
    }

    private void requestOverlayPermission() {
        try {
            Intent intent = new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION, 
                Uri.parse("package:" + getPackageName()));
            intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            startActivityForResult(intent, Floating.REQUEST_OVERLAY_PERMISSION);
        } catch (Exception e) {
            Log.e(TAG, "Failed to request overlay permission", e);
            Toast.makeText(this, "Please grant overlay permission manually in settings", Toast.LENGTH_LONG).show();
            finish();
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        
        try {
            if (requestCode == Floating.REQUEST_OVERLAY_PERMISSION) {
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                    if (Settings.canDrawOverlays(this)) {
                        Log.d(TAG, "Overlay permission granted");
                        initializeLauncher();
                    } else {
                        Log.w(TAG, "Overlay permission denied");
                        Toast.makeText(this, "Overlay permission is required for this app to work", Toast.LENGTH_LONG).show();
                        finish();
                    }
                }
            }
        } catch (Exception e) {
            Log.e(TAG, "Error in onActivityResult", e);
            handleError("Failed to handle permission result");
        }
    }

    private void initializeLauncher() {
        try {
            if (isDestroyed.get() || hasInitialized.getAndSet(true)) {
                return;
            }
            
            Log.d(TAG, "Initializing launcher");
            
            // Use a background thread for initialization to avoid ANR
            new Thread(() -> {
                try {
                    Thread.sleep(100); // Small delay to ensure activity is fully ready
                    
                    if (!isDestroyed.get()) {
                        mainHandler.post(() -> {
                            try {
                                if (!isDestroyed.get()) {
                                    Launcher.Init(MainActivity.this);
                                    // PATCH: Do NOT auto-finish MainActivity after initialization.
                                    // If you want to close the activity, do it only after user action or dialog dismiss.
                                    // (Removed: finish() call here)
                                }
                            } catch (Exception e) {
                                Log.e(TAG, "Error in launcher initialization", e);
                                handleError("Failed to initialize launcher");
                            }
                        });
                    }
                } catch (Exception e) {
                    Log.e(TAG, "Error in background initialization", e);
                    mainHandler.post(() -> handleError("Initialization failed"));
                }
            }).start();
            
        } catch (Exception e) {
            Log.e(TAG, "Error in initializeLauncher", e);
            handleError("Failed to start initialization");
        }
    }

    private void handleError(String message) {
        try {
            if (!isDestroyed.get()) {
                Log.e(TAG, message);
                Toast.makeText(this, message, Toast.LENGTH_LONG).show();
                
                // Delay before finishing to show the toast
                new Handler(Looper.getMainLooper()).postDelayed(() -> {
                    try {
                        if (!isDestroyed.get()) {
                            finish();
                        }
                    } catch (Exception e) {
                        Log.e(TAG, "Error in delayed finish", e);
                    }
                }, 2000);
            }
        } catch (Exception e) {
            Log.e(TAG, "Error in handleError", e);
            finish();
        }
    }

    @Override
    protected void onResume() {
        try {
            super.onResume();
            Log.d(TAG, "MainActivity onResume");
        } catch (Exception e) {
            Log.e(TAG, "Error in onResume", e);
        }
    }

    @Override
    protected void onPause() {
        try {
            super.onPause();
            Log.d(TAG, "MainActivity onPause");
        } catch (Exception e) {
            Log.e(TAG, "Error in onPause", e);
        }
    }

    @Override
    protected void onDestroy() {
        try {
            isDestroyed.set(true);
            Log.d(TAG, "MainActivity onDestroy");
            super.onDestroy();
        } catch (Exception e) {
            Log.e(TAG, "Error in onDestroy", e);
        }
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        try {
            super.onConfigurationChanged(newConfig);
            Log.d(TAG, "Configuration changed");
        } catch (Exception e) {
            Log.e(TAG, "Error in onConfigurationChanged", e);
        }
    }

    // Keep the old method for backward compatibility
    @Override
    @Deprecated
    public void onBackPressed() {
        try {
            Log.d(TAG, "Back pressed (legacy handler)");
            handleBackPress();
        } catch (Exception e) {
            Log.e(TAG, "Error in onBackPressed", e);
            finish();
        }
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        try {
            super.onSaveInstanceState(outState);
        } catch (Exception e) {
            Log.e(TAG, "Error in onSaveInstanceState", e);
        }
    }

    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState) {
        try {
            super.onRestoreInstanceState(savedInstanceState);
        } catch (Exception e) {
            Log.e(TAG, "Error in onRestoreInstanceState", e);
        }
    }
}
