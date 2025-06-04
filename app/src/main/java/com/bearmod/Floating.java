package com.bearmod;

import static android.graphics.Typeface.*;

import android.annotation.SuppressLint;
import android.content.res.Configuration;
import android.graphics.Color;
import android.graphics.Paint;

import android.graphics.drawable.GradientDrawable;
import android.os.Build;
import android.os.Process;
import android.os.Vibrator;
import android.os.VibrationEffect;
import android.os.Looper;
import android.util.TypedValue;
import android.content.Context;

import android.view.GestureDetector;
import android.view.Gravity;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.CompoundButton;
import android.widget.HorizontalScrollView;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.RelativeLayout;
import android.widget.ScrollView;
import android.widget.SeekBar;
import android.widget.Space;
import android.widget.Switch;
import android.widget.TextView;
import android.util.Base64;
import android.view.Display;

import android.app.ActivityManager;

import android.content.Intent;
import android.graphics.PixelFormat;
import android.os.IBinder;

import android.graphics.Point;
import android.util.DisplayMetrics;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

import android.app.Service;
import android.content.SharedPreferences;
import android.content.res.ColorStateList;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.drawable.Drawable;
import android.os.Handler;
import android.os.Message;

import android.view.WindowManager.LayoutParams;
import android.widget.ImageView;
import android.widget.Toast;

import androidx.annotation.NonNull;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.concurrent.atomic.AtomicBoolean;

import com.google.android.material.tabs.TabLayout;

import android.provider.Settings;
import android.net.Uri;

import com.bearmod.MenuManager;

public class Floating extends Service {

    // Thread safety improvements
    private final Object lockObject = new Object();
    private final AtomicBoolean isDestroyed = new AtomicBoolean(false);
    private final AtomicBoolean isInitialized = new AtomicBoolean(false);

    private static volatile WindowManager windowManager;
    private View floatingView;

    private TabLayout tabLayout;
    static Map<String, String> configMap = new HashMap<>(); // Use generics
    public static int REQUEST_OVERLAY_PERMISSION = 5469;

    volatile int screenWidth, screenHeight, type, CheckAttY = 0;
    boolean EnableFakeRecord = false;
    GradientDrawable gdMenuBody, gdAnimation = new GradientDrawable();
    LayoutParams layoutParams;

    public static volatile LayoutParams iconLayoutParams, mainLayoutParams, canvasLayoutParams;
    public static LayoutParams vParams;

    private String TimeHari;
    private String TimeJam;
    private String TimeMenit;
    private String TimeDetik;

    public static volatile RelativeLayout iconLayout;
    public static volatile LinearLayout mainLayout, bodyLayout;
    public static volatile ESPView canvasLayout;

    TextView textTitle;
    RelativeLayout closeLayout, maximizeLayout, minimizeLayout;
    RelativeLayout.LayoutParams closeLayoutParams, maximizeLayoutParams, minimizeLayoutParams;

    private int EspMenuTextthi = 0;
    private static final int currentLanguageIndex = 0;
    private LinearLayout contentLayout;

    private native String ChannelName();
    private native String FeedBackName();
    private native String channellink();
    private native String feedbacklink();
    private native String onlinename();
    public native void Switch(int i);
    public static native void DrawOn(ESPView espView, Canvas canvas);

    ImageView iconImg;
    private native String iconenc();

    private final List<LinearLayout> scrollBarContainers = new ArrayList<>();
    private final List<TextView> textViewList = new ArrayList<>();
    private final List<TextView> textViewList2 = new ArrayList<>();
    public static List<TextView> textViewList3 = new ArrayList<>();
    private final List<View> LineViewList = new ArrayList<>();
    private final List<GradientDrawable> comboViewList = new ArrayList<>();

    public static boolean DarkMode;
    private ScrollView scrollView;
    private LinearLayout pageLayout;
    private final int c_Background = Color.argb(255, 242, 241, 247);
    private final int c_Text = Color.BLACK;
    private final int c_Child = Color.WHITE;
    private final int c_Text2 = Color.argb(240, 143, 143, 142);
    private final int c_Line = Color.argb(80, 150, 150, 150);
    public static int c_WidgetsText = Color.BLACK;
    private final int c_Combo = Color.WHITE;

    private static final int MENU_WIDTH_DP = 300;
    private static final int MENU_HEIGHT_DP = 400;
    private static final int ICON_SIZE_DP = 64;

    public static boolean LanguageTest;

    String[] listTab = {"MAIN", "ESP", "AIM", "ITEMS", "SKIN"};
    LinearLayout[] pageLayouts = new LinearLayout[listTab.length];
    LayoutParams params;

    int lastSelectedPage = 0;
    static boolean isBullet;
    boolean CheckAtt;
    SharedPreferences configPrefs;

    int ToggleON = Color.WHITE;
    int ToggleOFF = Color.LTGRAY;
    boolean isMaximized = false;
    int lastMaximizedX = 0, lastMaximizedY = 0;
    int lastMaximizedW = 0, lastMaximizedH = 0;
    int action;
    int layoutWidth;
    int layoutHeight;
    int iconSize;
    int iconSize2;
    int menuButtonSize;
    int tabWidth;
    int tabHeight;

    int MENU_TEXT_COLOR = Color.parseColor("#FFFFFFFF");
    int MENU_LIST_STROKE = Color.argb(255, 200, 100, 0);

    private native boolean IsHideEsp();

    private boolean SaveKey;
    int RadioColor = Color.parseColor("#FFFF9700");
    int MENU_BG_COLOR = Color.parseColor("#fff7f7f7"); // #AARRGGBB

    static boolean isHIDE;
    int Storage_Permission = 142;
    TextView mTitle;

    float mediumSize = 5.0f;

    private native String cfg();
    private native void onSendConfig(String s, String v);

    private volatile Thread thread;
    private volatile boolean isRunning;
    private Paint paint;
    private long startTime;
    private int frames;

    long days;
    long hours;
    long minutes;
    long seconds;

    public static volatile Context g_context;
    private final int fpsViewId = View.generateViewId();
    private final long lastTime = 0;
    private final int frameCount = 0;
    private TextView fpsTextView;

    private MenuManager menuManager;

    // Auto-detection monitoring
    private Handler autoDetectionHandler;
    private Runnable autoDetectionRunnable;
    private boolean isAutoDetectionEnabled = false;
    private boolean lastRecordingState = false;
    
    public void startAutoDetectionMonitoring() {
        try {
            if (autoDetectionHandler != null) {
                stopAutoDetectionMonitoring();
            }
            
            autoDetectionHandler = new Handler(Looper.getMainLooper());
            autoDetectionRunnable = new Runnable() {
                @Override
                public void run() {
                    try {
                        if (isAutoDetectionEnabled && GetBoolean("RECORDER_AUTO_DETECT")) {
                            boolean isCurrentlyRecording = RecorderFakeUtils.isRecorderRunning(g_context);
                            
                            // Only act on state changes to avoid repeated calls
                            if (isCurrentlyRecording != lastRecordingState) {
                                lastRecordingState = isCurrentlyRecording;
                                
                                if (isCurrentlyRecording) {
                                    // Recording detected - hide mod elements
                                    android.util.Log.d("Floating", "AUTO-DETECTION: Recording detected, hiding mod elements");
                                    hideesp();
                                    UpdateConfiguration("RECORDER_HIDE", 1);
                                    
                                    // Show notification
                                    Toast.makeText(g_context, 
                                        getEspMenuText("🔴 Recording detected - Mod hidden", "🔴 检测到录制 - 模组已隐藏"), 
                                        Toast.LENGTH_SHORT).show();
                                } else {
                                    // Recording stopped - restore mod elements if auto-detection is enabled
                                    android.util.Log.d("Floating", "AUTO-DETECTION: Recording stopped, restoring mod elements");
                                    stopHideesp();
                                    UpdateConfiguration("RECORDER_HIDE", 0);
                                    
                                    // Show notification
                                    Toast.makeText(g_context, 
                                        getEspMenuText("🟢 Recording stopped - Mod visible", "🟢 录制已停止 - 模组可见"), 
                                        Toast.LENGTH_SHORT).show();
                                }
                                
                                SaveConfiguration();
                            }
                        }
                        
                        // Schedule next check based on sensitivity
                        int sensitivity = GetInteger("RECORDER_SENSITIVITY");
                        int checkInterval = Math.max(500, 3000 - (sensitivity * 500)); // 500ms to 2500ms
                        
                        if (autoDetectionHandler != null && isAutoDetectionEnabled) {
                            autoDetectionHandler.postDelayed(this, checkInterval);
                        }
                    } catch (Exception e) {
                        android.util.Log.e("Floating", "Error in auto-detection monitoring", e);
                        // Continue monitoring even if there's an error
                        if (autoDetectionHandler != null && isAutoDetectionEnabled) {
                            autoDetectionHandler.postDelayed(this, 2000);
                        }
                    }
                }
            };
            
            isAutoDetectionEnabled = true;
            autoDetectionHandler.post(autoDetectionRunnable);
            android.util.Log.d("Floating", "Auto-detection monitoring started");
            
        } catch (Exception e) {
            android.util.Log.e("Floating", "Error starting auto-detection monitoring", e);
        }
    }
    
    public void stopAutoDetectionMonitoring() {
        try {
            isAutoDetectionEnabled = false;
            if (autoDetectionHandler != null && autoDetectionRunnable != null) {
                autoDetectionHandler.removeCallbacks(autoDetectionRunnable);
            }
            autoDetectionHandler = null;
            autoDetectionRunnable = null;
            android.util.Log.d("Floating", "Auto-detection monitoring stopped");
        } catch (Exception e) {
            android.util.Log.e("Floating", "Error stopping auto-detection monitoring", e);
        }
    }

    public static void hideesp() {
        try {
            android.util.Log.d("Floating", "hideesp() called - attempting to enable anti-recording");
            if (g_context != null && mainLayoutParams != null && iconLayoutParams != null && 
                canvasLayoutParams != null && windowManager != null && mainLayout != null && 
                iconLayout != null && canvasLayout != null) {
                android.util.Log.d("Floating", "All required parameters available, calling RecorderFakeUtils.setFakeRecorderWindowLayoutParams");
                RecorderFakeUtils.setFakeRecorderWindowLayoutParams(mainLayoutParams, iconLayoutParams, 
                    canvasLayoutParams, windowManager, mainLayout, iconLayout, canvasLayout, g_context);
                android.util.Log.d("Floating", "RecorderFakeUtils.setFakeRecorderWindowLayoutParams completed successfully");
            } else {
                android.util.Log.e("Floating", "Missing required parameters for hideesp: " +
                    "g_context=" + (g_context != null) +
                    ", mainLayoutParams=" + (mainLayoutParams != null) +
                    ", iconLayoutParams=" + (iconLayoutParams != null) +
                    ", canvasLayoutParams=" + (canvasLayoutParams != null) +
                    ", windowManager=" + (windowManager != null) +
                    ", mainLayout=" + (mainLayout != null) +
                    ", iconLayout=" + (iconLayout != null) +
                    ", canvasLayout=" + (canvasLayout != null));
            }
        } catch (Exception e) {
            android.util.Log.e("Floating", "Error in hideesp()", e);
            e.printStackTrace();
        }
    }

    public static void stopHideesp() {
        try {
            android.util.Log.d("Floating", "stopHideesp() called - attempting to disable anti-recording");
            if (g_context != null && mainLayoutParams != null && iconLayoutParams != null && 
                canvasLayoutParams != null && windowManager != null && mainLayout != null && 
                iconLayout != null && canvasLayout != null) {
                android.util.Log.d("Floating", "All required parameters available, calling RecorderFakeUtils.unsetFakeRecorderWindowLayoutParams");
                RecorderFakeUtils.unsetFakeRecorderWindowLayoutParams(mainLayoutParams, iconLayoutParams, 
                    canvasLayoutParams, windowManager, mainLayout, iconLayout, canvasLayout, g_context);
                android.util.Log.d("Floating", "RecorderFakeUtils.unsetFakeRecorderWindowLayoutParams completed successfully");
            } else {
                android.util.Log.e("Floating", "Missing required parameters for stopHideesp: " +
                    "g_context=" + (g_context != null) +
                    ", mainLayoutParams=" + (mainLayoutParams != null) +
                    ", iconLayoutParams=" + (iconLayoutParams != null) +
                    ", canvasLayoutParams=" + (canvasLayoutParams != null) +
                    ", windowManager=" + (windowManager != null) +
                    ", mainLayout=" + (mainLayout != null) +
                    ", iconLayout=" + (iconLayout != null) +
                    ", canvasLayout=" + (canvasLayout != null));
            }
        } catch (Exception e) {
            android.util.Log.e("Floating", "Error in stopHideesp()", e);
            e.printStackTrace();
        }
    }

    private Boolean GetBoolean(String str) {
        try {
            synchronized (lockObject) {
                String value = configMap.get(str);
                return value != null && Integer.parseInt(value) == 1;
            }
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    private Integer GetInteger(String str) {
        try {
            synchronized (lockObject) {
                String value = configMap.get(str);
                return value != null ? Integer.parseInt(value) : 0;
            }
        } catch (Exception e) {
            e.printStackTrace();
            return 0;
        }
    }

    Date time;
    SimpleDateFormat formatter;
    SimpleDateFormat formatter2;

    void CreateCanvas() {
        try {
            if (isDestroyed.get()) return;
            
            canvasLayoutParams = new LayoutParams(
                    LayoutParams.MATCH_PARENT,
                    LayoutParams.MATCH_PARENT,
                    getLayoutType(),
                    LayoutParams.FLAG_NOT_FOCUSABLE | LayoutParams.FLAG_NOT_TOUCHABLE | LayoutParams.FLAG_NOT_TOUCH_MODAL,
                    PixelFormat.TRANSLUCENT);
            canvasLayoutParams.gravity = Gravity.TOP | Gravity.START;
            canvasLayoutParams.x = 0;
            canvasLayoutParams.y = 0;
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) {
                canvasLayoutParams.layoutInDisplayCutoutMode = LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
            }
            canvasLayout = new ESPView(this);
            if (windowManager != null && !isDestroyed.get()) {
                windowManager.addView(canvasLayout, canvasLayoutParams);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public int getLayoutType() {
        // For Android 10+ (API 29+), we use TYPE_APPLICATION_OVERLAY
        // Since we target Android 10+, we don't need the TYPE_PHONE fallback
        return LayoutParams.TYPE_APPLICATION_OVERLAY;
    }

    private boolean isNotInGame() {
        try {
            ActivityManager.RunningAppProcessInfo runningAppProcessInfo = new ActivityManager.RunningAppProcessInfo();
            ActivityManager.getMyMemoryState(runningAppProcessInfo);
            return runningAppProcessInfo.importance != 100;
        } catch (Exception e) {
            e.printStackTrace();
            return true;
        }
    }

    private void Thread() {
        try {
            WindowManager wm = windowManager;
            if (wm == null || isDestroyed.get()) return;
            
            if (isNotInGame()) {
                try {
                    if (mainLayout != null && mainLayout.getParent() != null) {
                        wm.removeView(mainLayout);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            } else {
                mainLayoutParams = new LayoutParams(layoutWidth, layoutHeight, LayoutParams.TYPE_APPLICATION_OVERLAY, LayoutParams.FLAG_NOT_FOCUSABLE, PixelFormat.TRANSLUCENT);

                try {
                    if (mainLayout != null && mainLayout.getParent() == null && !isDestroyed.get()) {
                        wm.addView(mainLayout, mainLayoutParams);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void LoadConfiguration() {
        try {
            synchronized (lockObject) {
                File file = new File(getFilesDir(), "NRG_SaveFile.cfg");
                if (!file.exists()) return;
                
                try (BufferedReader bufferedReader = new BufferedReader(new FileReader(file))) {
                    String readLine;
                    while ((readLine = bufferedReader.readLine()) != null) {
                        String[] split = readLine.split(" = ");
                        if (split.length == 2) {
                            configMap.put(split[0], split[1]);
                        }
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void onSendConfig(String split, Object parseInt) {
        try {
            synchronized (lockObject) {
                configMap.put(split, parseInt.toString());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void SaveConfiguration() {
        try {
            synchronized (lockObject) {
                File file = new File(getFilesDir(), "NRG_SaveFile.cfg");
                try (PrintWriter printWriter = new PrintWriter(new FileOutputStream(file), true)) {
                    for (Map.Entry<String, String> entry : configMap.entrySet()) {
                        printWriter.println(entry.getKey() + " = " + entry.getValue());
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void UpdateConfiguration2(String s, Object v) {
        try {
            synchronized (lockObject) {
                configMap.put(s, v.toString());
                onSendConfig(s, v.toString());
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private void UpdateConfiguration(String s, Object v) {
        try {
            synchronized (lockObject) {
                configMap.put(s, v.toString());
                onSendConfig(s, v.toString());

                if (configPrefs != null) {
                    SharedPreferences.Editor configEditor = configPrefs.edit();
                    configEditor.putString(s, v.toString());
                    configEditor.apply();
                }
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private class CanvasView extends View {
        public CanvasView(Context context) {
            super(context);
            g_context = context;
        }
    }

    private int seconds2 = 0;

    @Override
    public void onDestroy() {
        try {
            isDestroyed.set(true);
            
            // Stop auto-detection monitoring
            stopAutoDetectionMonitoring();

            // Remove views safely
            WindowManager wm = windowManager;
            if (wm != null) {
                safeRemoveView(wm, floatingView);
                safeRemoveView(wm, iconLayout);
                safeRemoveView(wm, mainLayout);
                safeRemoveView(wm, canvasLayout);
            }

            // Clean up RecorderFakeUtils
            RecorderFakeUtils.onAppBackground();
            
            GetBoolean("RECORDER_HIDE");
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            super.onDestroy();
        }
    }

    private void safeRemoveView(WindowManager wm, View view) {
        try {
            if (view != null && view.getParent() != null) {
                wm.removeView(view);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        super.onStartCommand(intent, flags, startId);
        return START_NOT_STICKY;
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    public static volatile Floating instance = null;

    public void onCreate() {
        try {
            if (isDestroyed.get()) return;
            try {
            System.loadLibrary("bearmod");
            } catch (UnsatisfiedLinkError | Exception e) {
                e.printStackTrace();
                Toast.makeText(this, "Native library missing. Some features will not work.", Toast.LENGTH_LONG).show();
            }
            super.onCreate();
            
            // Note: Overlay permission should be checked in MainActivity before starting this service
            // Services cannot request permissions directly
            
            synchronized (lockObject) {
                instance = this;
                g_context = getApplicationContext();
                configPrefs = getSharedPreferences("config", MODE_PRIVATE);
                windowManager = (WindowManager) getSystemService(WINDOW_SERVICE);

                if (windowManager == null) {
                    stopSelf();
                    return;
                }

                time = new Date();
                formatter = new SimpleDateFormat(" HH:mm:ss", Locale.getDefault());
                formatter2 = new SimpleDateFormat("yyyy-MM-dd", Locale.getDefault());

                // Set fixed default screen size for all devices
                DisplayMetrics displayMetrics = getResources().getDisplayMetrics();
                screenWidth = displayMetrics.widthPixels;   // Use actual screen width
                screenHeight = displayMetrics.heightPixels; // Use actual screen height

                layoutWidth = dpToPx(480); // Reduced from 550 to 480
                layoutHeight = dpToPx(280); // Reduced from 350 to 280 - more compact
                iconSize = dpToPx(64);
                iconSize2 = 150;

                menuButtonSize = dpToPx(30);
                tabWidth = dpToPx(0);
                tabHeight = dpToPx(0);
                type = getLayoutType();

                GetBoolean("RECORDER_HIDE");

                CreateCanvas();
                CreateLayout();
                CreateIcon();

                // Ensure mainLayout is not already added
                if (mainLayout != null && mainLayout.getParent() != null && windowManager != null) {
                    windowManager.removeView(mainLayout);
                }
                if (mainLayout != null && windowManager != null && !isDestroyed.get()) {
                    windowManager.addView(mainLayout, mainLayoutParams);
                    mainLayout.setVisibility(View.GONE); // Start hidden
                }

                // Configuration defaults
                initDefaultConfigurations();
                setLanguageBasedOnSystemLocale();
                
                // FIXED: Initialize LiveStreamMod state based on saved configuration
                try {
                    boolean recorderHideEnabled = GetBoolean("RECORDER_HIDE");
                    if (recorderHideEnabled) {
                        android.util.Log.d("Floating", "Initializing LiveStreamMod as enabled");
                        // Apply the recorder hiding immediately if it was previously enabled
                        new Handler(Looper.getMainLooper()).postDelayed(() -> {
                            try {
                                hideesp(); // Enable anti-recording protection
                            } catch (Exception e) {
                                android.util.Log.e("Floating", "Error initializing LiveStreamMod", e);
                            }
                        }, 1000); // Small delay to ensure views are ready
                    }
                    
                    // Start auto-detection monitoring if enabled
                    boolean autoDetectEnabled = GetBoolean("RECORDER_AUTO_DETECT");
                    if (autoDetectEnabled) {
                        new Handler(Looper.getMainLooper()).postDelayed(() -> {
                            try {
                                startAutoDetectionMonitoring();
                                android.util.Log.d("Floating", "Auto-detection monitoring started on app startup");
                            } catch (Exception e) {
                                android.util.Log.e("Floating", "Error starting auto-detection on startup", e);
                            }
                        }, 2000); // Delay to ensure all components are ready
                    }
                } catch (Exception e) {
                    android.util.Log.e("Floating", "Error checking LiveStreamMod state", e);
                }
                
                isInitialized.set(true);
            }
        } catch (Exception e) {
            e.printStackTrace();
            stopSelf();
        }
    }

    private void initDefaultConfigurations() {
        try {
            UpdateConfiguration("AIM::TRIGGER1", (byte) 1);
            UpdateConfiguration("AIM::TARGET1", (byte) 1);
            UpdateConfiguration("ESP::BOXTYPE1", (byte) 1);
            UpdateConfiguration("AIM_MOD1", (byte) 1);
            UpdateConfiguration("SMOOT::HNESS1", (byte) 1);
            UpdateConfiguration("RADAR::SIZE", (byte) 60);
            
            // Initialize anti-recording default settings
            if (!configMap.containsKey("RECORDER_AUTO_DETECT")) {
                UpdateConfiguration("RECORDER_AUTO_DETECT", 0); // Default: disabled
            }
            if (!configMap.containsKey("RECORDER_SENSITIVITY")) {
                UpdateConfiguration("RECORDER_SENSITIVITY", 3); // Default: medium sensitivity
            }
            if (!configMap.containsKey("RECORDER_HIDE")) {
                UpdateConfiguration("RECORDER_HIDE", 0); // Default: not hidden
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void setLanguageBasedOnSystemLocale() {
        try {
            String deviceLanguage = Locale.getDefault().getLanguage();
            EspMenuTextthi = "zh".equals(deviceLanguage) ? 1 : 0;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        try {
            super.onConfigurationChanged(newConfig);
            setLanguageBasedOnSystemLocale();
            translateMenuElements();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private String GetString(String key, String defaultValue) {
        try {
            synchronized (lockObject) {
                String value = configMap.get(key);
                return value != null ? value : defaultValue;
            }
        } catch (Exception e) {
            e.printStackTrace();
            return defaultValue;
        }
    }

    String getEspMenuText(String engText, String cnText) {
        try {
            switch (EspMenuTextthi) {
                case 0:
                    return engText;
                case 1:
                    return cnText;
                default:
                    return engText;
            }
        } catch (Exception e) {
            e.printStackTrace();
            return engText;
        }
    }

    private void translateMenuElements() {
        try {
            // Update floating window title
            if (textTitle != null) {
                textTitle.setText(getEspMenuText("BEAR-MOD", "熊模组"));
            }

            // FIXED: Update MenuManager language and refresh all UI
            if (menuManager != null) {
                // Sync language setting
                menuManager.EspMenuTextthi = this.EspMenuTextthi;
                // Trigger comprehensive UI refresh
                menuManager.refreshUILanguage();
            }
            
            // Update other floating window elements if they exist
            if (mTitle != null) {
                mTitle.setText(getEspMenuText("Settings", "设置"));
            }
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @SuppressLint({"ClickableViewAccessibility", "SetTextI18n"})
    void CreateLayout() {
        try {
            if (isDestroyed.get()) return;
            
            LoadConfiguration();

            // Set up layout params - Increase height to accommodate all 5 menu items
            mainLayoutParams = new WindowManager.LayoutParams(layoutWidth, layoutHeight, type, 
                WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE | WindowManager.LayoutParams.FLAG_LAYOUT_NO_LIMITS, 
                PixelFormat.RGBA_8888);
            mainLayoutParams.x = 150;
            mainLayoutParams.y = 150;
            mainLayoutParams.gravity = Gravity.START | Gravity.TOP;

            // Main container with horizontal layout (sidebar + content)
            mainLayout = new LinearLayout(this);
            mainLayout.setOrientation(LinearLayout.HORIZONTAL);
            mainLayout.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));
            
            // Modern dark background with rounded corners
            GradientDrawable mainBg = new GradientDrawable();
            mainBg.setColor(Color.parseColor("#2d2d2d"));
            mainBg.setCornerRadius(dpToPx(15));
            mainBg.setStroke(dpToPx(1), Color.parseColor("#444444"));
            mainLayout.setBackground(mainBg);

            // Create content layout for menu pages
            contentLayout = new LinearLayout(this);
            contentLayout.setOrientation(LinearLayout.VERTICAL);
            contentLayout.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
            contentLayout.setPadding(dpToPx(16), dpToPx(16), dpToPx(16), dpToPx(16));

            // Wrap content layout in ScrollView
            scrollView = new ScrollView(this);
            scrollView.setLayoutParams(new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.MATCH_PARENT, 1f));
            scrollView.setFillViewport(true);
            scrollView.addView(contentLayout);

            // Create MenuManager
            menuManager = new MenuManager(
                this, // context
                listTab,
                pageLayouts,
                contentLayout,
                textTitle
            );
            
            // FIXED: Properly set up all callbacks with correct references
            menuManager.getEspMenuText = this::getEspMenuText;
            menuManager.GetBoolean = this::GetBoolean;
            menuManager.GetInteger = this::GetInteger;
            menuManager.UpdateConfiguration = this::UpdateConfiguration;
            menuManager.Switch = this::Switch;
            menuManager.SaveConfiguration = this::SaveConfiguration;
            
            // FIXED: Create proper language refresh callback
            menuManager.refreshUILanguage = () -> {
                try {
                    // Update MenuManager's language index
                    menuManager.EspMenuTextthi = this.EspMenuTextthi;
                    // Call MenuManager's refresh method
                    menuManager.refreshUILanguage();
                    // Also update floating window title if needed
                    if (textTitle != null) {
                        textTitle.setText(getEspMenuText("BEAR-MOD", "熊模组"));
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            };
            
            menuManager.EspMenuTextthi = this.EspMenuTextthi;
            menuManager.mediumSize = this.mediumSize;

            // Create sidebar (which will be added to mainLayout)
            menuManager.createSidebar(mainLayout, iconLayout, () -> {
                            mainLayout.setVisibility(View.GONE);
                            iconLayout.setVisibility(View.VISIBLE);
            });

            // Add scrollable content area to mainLayout
            mainLayout.addView(scrollView);

            // Create pages (this will populate contentLayout with menu content)
            menuManager.createPages();

            // After menuManager.createSidebar(...)
            if (menuManager.sidebarHeaderRef != null) {
                menuManager.sidebarHeaderRef.setOnTouchListener(new View.OnTouchListener() {
                    float pressedX;
                    float pressedY;
                    float deltaX;
                    float deltaY;

                    @Override
                    public boolean onTouch(View v, MotionEvent event) {
                        try {
                            switch (event.getActionMasked()) {
                                case MotionEvent.ACTION_DOWN:
                                    pressedX = event.getRawX();
                                    pressedY = event.getRawY();
                                    deltaX = mainLayoutParams.x - pressedX;
                                    deltaY = mainLayoutParams.y - pressedY;
                                    break;
                                case MotionEvent.ACTION_MOVE:
                                    if (!isDestroyed.get() && windowManager != null && mainLayoutParams != null) {
                                        float newX = event.getRawX() + deltaX;
                                        float newY = event.getRawY() + deltaY;
                                        float maxX = screenWidth - mainLayout.getWidth();
                                        float maxY = screenHeight - mainLayout.getHeight();
                                        if (newX < 0) newX = 0;
                                        if (newX > maxX) newX = maxX;
                                        if (newY < 0) newY = 0;
                                        if (newY > maxY) newY = maxY;
                                        mainLayoutParams.x = (int) newX;
                                        mainLayoutParams.y = (int) newY;
                                        try {
                                            windowManager.updateViewLayout(mainLayout, mainLayoutParams);
                                        } catch (Exception e) {
                                            e.printStackTrace();
                                        }
                                    }
                                    break;
                            }
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                        return true;
                    }
                });
            }
            
            // Start background threads after layout is created
            // startBackgroundThreads();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @SuppressLint("RtlHardcoded")
    void CreateIcon() {
        try {
            if (isDestroyed.get()) return;
            
            iconLayout = new RelativeLayout(this);
            RelativeLayout.LayoutParams iconParams = new RelativeLayout.LayoutParams(
                    dpToPx(48),  // Fixed width
                    dpToPx(48)   // Fixed height
            );
            iconLayout.setLayoutParams(iconParams);

            iconImg = new ImageView(this);
            ViewGroup.LayoutParams iconImgParams = new ViewGroup.LayoutParams(
                    dpToPx(48),  // Fixed width
                    dpToPx(48)   // Fixed height
            );
            iconImg.setLayoutParams(iconImgParams);
            iconImg.setScaleType(ImageView.ScaleType.FIT_CENTER);  // Ensure icon fits properly
            GetBoolean("RECORDER_HIDE");
            iconLayout.addView(iconImg);

            try {
                String iconBase64 = iconenc();
                if (iconBase64 != null && !iconBase64.isEmpty()) {
                    byte[] iconData = Base64.decode(iconBase64, Base64.DEFAULT);
                    Bitmap bmp = BitmapFactory.decodeByteArray(iconData, 0, iconData.length);
                    if (bmp != null) {
                        iconImg.setImageBitmap(bmp);
                    }
                }
            } catch (Exception ex) {
                ex.printStackTrace();
            }

            iconLayoutParams = new WindowManager.LayoutParams();
            iconLayoutParams.width = iconSize;
            iconLayoutParams.height = iconSize;
            iconLayoutParams.type = type;
            iconLayoutParams.format = PixelFormat.RGBA_8888;
            iconLayoutParams.flags = WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE
                    | WindowManager.LayoutParams.FLAG_NOT_TOUCH_MODAL
                    | WindowManager.LayoutParams.FLAG_LAYOUT_NO_LIMITS
                    | WindowManager.LayoutParams.FLAG_WATCH_OUTSIDE_TOUCH
                    | WindowManager.LayoutParams.FLAG_LAYOUT_IN_SCREEN;

            iconLayoutParams.gravity = Gravity.START | Gravity.TOP;
            iconLayoutParams.x = 0;
            iconLayoutParams.y = 0;
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) { // Android 10+ (API 29)
            iconLayoutParams.layoutInDisplayCutoutMode = LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
            }
            iconLayout.setVisibility(View.VISIBLE);
            
            iconLayout.setOnTouchListener(new View.OnTouchListener() {
                int lastX;
                int lastY;
                float pressedX;
                float pressedY;
                float deltaX;
                float deltaY;
                float newX;
                float newY;
                float maxX;
                float maxY;
                
                @Override
                public boolean onTouch(View v, MotionEvent event) {
                    try {
                        if (isDestroyed.get()) return false;
                        
                        switch (event.getAction()) {
                            case MotionEvent.ACTION_DOWN:
                                lastX = iconLayoutParams.x;
                                lastY = iconLayoutParams.y;
                                deltaX = lastX - event.getRawX();
                                deltaY = lastY - event.getRawY();

                                pressedX = event.getRawX();
                                pressedY = event.getRawY();

                                try {
                                    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) {
                                        // Android 12+ (API 31+)
                                        android.os.VibratorManager vibratorManager = (android.os.VibratorManager) getSystemService(Context.VIBRATOR_MANAGER_SERVICE);
                                        if (vibratorManager != null) {
                                            Vibrator vibrator = vibratorManager.getDefaultVibrator();
                                            if (vibrator != null) {
                                                vibrator.vibrate(VibrationEffect.createOneShot(50, VibrationEffect.DEFAULT_AMPLITUDE));
                                            }
                                        }
                                    } else if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                                        // Android 8+ (API 26+)
                                        Vibrator vibrator = (Vibrator) getSystemService(Context.VIBRATOR_SERVICE);
                                        if (vibrator != null) {
                                            vibrator.vibrate(VibrationEffect.createOneShot(50, VibrationEffect.DEFAULT_AMPLITUDE));
                                        }
                                    } else {
                                        // Older Android versions
                                        @SuppressWarnings("deprecation")
                                        Vibrator vibrator = (Vibrator) getSystemService(Context.VIBRATOR_SERVICE);
                                        if (vibrator != null) {
                                            vibrator.vibrate(50);
                                        }
                                    }
                                } catch (Exception e) {
                                    e.printStackTrace();
                                }
                                break;
                                
                            case MotionEvent.ACTION_UP:
                                int Xdiff = (int) (event.getRawX() - pressedX);
                                int Ydiff = (int) (event.getRawY() - pressedY);

                                if (Xdiff == 0 && Ydiff == 0) {
                                    if (mainLayout != null) {
                                        mainLayout.setVisibility(View.VISIBLE);
                                    }
                                    if (iconLayout != null) {
                                        iconLayout.setVisibility(View.GONE);
                                    }
                                }
                                return false;

                            case MotionEvent.ACTION_MOVE:
                                if (!isDestroyed.get() && windowManager != null && iconLayoutParams != null) {
                                    newX = event.getRawX() + deltaX;
                                    newY = event.getRawY() + deltaY;

                                    maxX = screenWidth - v.getWidth();
                                    maxY = screenHeight - v.getHeight();

                                    if (newX < 0) newX = 0;
                                    if (newX > maxX) newX = (int) maxX;
                                    if (newY < 0) newY = 0;
                                    if (newY > maxY) newY = (int) maxY;

                                    iconLayoutParams.x = (int) newX;
                                    iconLayoutParams.y = (int) newY;

                                    if (mainLayoutParams != null) {
                                        mainLayoutParams.x = iconLayoutParams.x;
                                        mainLayoutParams.y = iconLayoutParams.y;
                                        try {
                                            windowManager.updateViewLayout(mainLayout, mainLayoutParams);
                                        } catch (Exception e) {
                                            e.printStackTrace();
                                        }
                                    }
                                    
                                    try {
                                        windowManager.updateViewLayout(iconLayout, iconLayoutParams);
                                    } catch (Exception e) {
                                        e.printStackTrace();
                                    }
                                }
                                break;
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    return false;
                }
            });

            if (windowManager != null && !isDestroyed.get()) {
                windowManager.addView(iconLayout, iconLayoutParams);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Add a local dpToPx utility method
    private int dpToPx(int dp) {
        return Math.round(dp * getResources().getDisplayMetrics().density);
    }
}
