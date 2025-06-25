package com.bearmod;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.PixelFormat;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.SeekBar;
import android.widget.Switch;
import android.widget.TextView;


import android.view.Display;
import android.hardware.display.DisplayManager;
import android.os.Build;
import java.util.concurrent.atomic.AtomicBoolean;
import android.os.Handler;
import android.os.Looper;
import android.content.SharedPreferences;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class Floating {
    private static final String TAG = "Floating";
    
    // Static instance for JNI callbacks (native library expects this)
    @SuppressLint("StaticFieldLeak")
    private static Floating instance;
    
    private final Context context;
    private final WindowManager windowManager;
    private View floatingIcon;
    private View floatingMenu;
    private boolean isMenuVisible = false;
    
    // Current active category
    private String currentCategory = "players";
    
    // UI Components
    private TextView categoryTitle;
    private LinearLayout contentFrame;
    private LinearLayout quickActions;

    private int menuMaxWidth;

    // Thread safety improvements from original
    private final Object lockObject = new Object();
    private final AtomicBoolean isDestroyed = new AtomicBoolean(false);
    private final AtomicBoolean isInitialized = new AtomicBoolean(false);
    
    // Configuration management from original
    private static Map<String, String> configMap = new ConcurrentHashMap<>();
    private SharedPreferences configPrefs;
    
    // Enhanced state management
    private Handler uiHandler;
    private boolean isDarkMode = false;
    private int currentLanguage = 0;

    public Floating(Context context) {
        this.context = context;
        this.windowManager = (WindowManager) context.getSystemService(Context.WINDOW_SERVICE);
        
        // Initialize UI handler for smooth operations
        this.uiHandler = new Handler(Looper.getMainLooper());
        
        // Initialize configuration
        initializeConfiguration();
        
        // Load native library for JNI callbacks
        try {
            System.loadLibrary("bearmod");
            Log.d(TAG, "Native library loaded successfully in Floating");
        } catch (UnsatisfiedLinkError e) {
            Log.e(TAG, "Failed to load native library in Floating: " + e.getMessage());
        }
        
        // Set static instance for JNI callbacks
        instance = this;
        
        try {
            // Get screen dimensions for responsive design
            calculateResponsiveSizes();
            
            createFloatingIcon();
            createFloatingMenu();
            
            // Mark as initialized
            isInitialized.set(true);
            
            Log.d(TAG, "Floating initialized with responsive design and enhanced state management");
        } catch (Exception e) {
            Log.e(TAG, "Error initializing Floating", e);
            throw new RuntimeException("Failed to initialize Floating: " + e.getMessage(), e);
        }
    }

    private void initializeConfiguration() {
        try {
            configPrefs = context.getSharedPreferences("bearmod_config", Context.MODE_PRIVATE);
            loadConfiguration();
            setDefaultConfigurations();
        } catch (Exception e) {
            Log.e(TAG, "Error initializing configuration", e);
        }
    }
    
    private void loadConfiguration() {
        try {
            synchronized (lockObject) {
                Map<String, ?> allPrefs = configPrefs.getAll();
                for (Map.Entry<String, ?> entry : allPrefs.entrySet()) {
                    configMap.put(entry.getKey(), entry.getValue().toString());
                }
                Log.d(TAG, "Loaded " + configMap.size() + " configuration items");
            }
        } catch (Exception e) {
            Log.e(TAG, "Error loading configuration", e);
        }
    }
    
    private void setDefaultConfigurations() {
        setConfigDefault("SHOW_PLAYERS", "1");
        setConfigDefault("SHOW_AIMBOT", "0");
        setConfigDefault("SHOW_ITEMS", "1");
        setConfigDefault("DARK_MODE", "0");
        setConfigDefault("LANGUAGE", "0");
        setConfigDefault("PERFORMANCE_MODE", "0");
    }
    
    private void setConfigDefault(String key, String defaultValue) {
        if (!configMap.containsKey(key)) {
            updateConfiguration(key, defaultValue);
        }
    }
    
    public void updateConfiguration(String key, String value) {
        try {
            synchronized (lockObject) {
                configMap.put(key, value);
                configPrefs.edit().putString(key, value).apply();
                
                // Handle special configurations
                handleConfigurationChange(key, value);
            }
        } catch (Exception e) {
            Log.e(TAG, "Error updating configuration", e);
        }
    }
    
    private void handleConfigurationChange(String key, String value) {
        switch (key) {
            case "DARK_MODE":
                isDarkMode = "1".equals(value);
                applyTheme();
                break;
            case "LANGUAGE":
                currentLanguage = Integer.parseInt(value);
                updateLanguage();
                break;
            case "PERFORMANCE_MODE":
                boolean perfMode = "1".equals(value);
                adjustPerformanceMode(perfMode);
                break;
        }
    }
    
    private void applyTheme() {
        if (uiHandler != null) {
            uiHandler.post(() -> {
                // Apply theme changes to UI elements
                updateMenuTheme();
            });
        }
    }
    
    private void updateLanguage() {
        if (uiHandler != null) {
            uiHandler.post(() -> {
                // Update UI text based on language
                updateMenuLanguage();
            });
        }
    }
    
    private void adjustPerformanceMode(boolean enabled) {
        // Adjust UI performance settings
        Log.d(TAG, "Performance mode " + (enabled ? "enabled" : "disabled"));
    }
    
    private void updateMenuTheme() {
        // Update theme for menu elements
        Log.d(TAG, "Applying " + (isDarkMode ? "dark" : "light") + " theme");
    }
    
    private void updateMenuLanguage() {
        // Update language for menu elements
        Log.d(TAG, "Updating language to index: " + currentLanguage);
    }
    
    public String getConfig(String key) {
        synchronized (lockObject) {
            return configMap.getOrDefault(key, "0");
        }
    }
    
    public boolean getBooleanConfig(String key) {
        return "1".equals(getConfig(key));
    }
    
    public int getIntegerConfig(String key) {
        try {
            return Integer.parseInt(getConfig(key));
        } catch (NumberFormatException e) {
            return 0;
        }
    }

    private void calculateResponsiveSizes() {
        try {
            DisplayMetrics displayMetrics = new DisplayMetrics();
            
            // Use WindowManager to get display metrics - more reliable for Service context
            if (windowManager != null) {
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
                    // For Android 11+, try to get display through DisplayManager
                    try {
                        DisplayManager dm = (DisplayManager) context.getSystemService(Context.DISPLAY_SERVICE);
                        if (dm != null) {
                            Display display = dm.getDisplay(Display.DEFAULT_DISPLAY);
                            if (display != null) {
                                display.getMetrics(displayMetrics);
                            } else {
                                // Fallback to WindowManager
                                windowManager.getDefaultDisplay().getMetrics(displayMetrics);
                            }
                        } else {
                            // Fallback to WindowManager
                            windowManager.getDefaultDisplay().getMetrics(displayMetrics);
                        }
                    } catch (Exception e) {
                        Log.w(TAG, "Failed to get display from DisplayManager, using WindowManager fallback", e);
                        windowManager.getDefaultDisplay().getMetrics(displayMetrics);
                    }
                } else {
                    // For older Android versions, use WindowManager directly
                    windowManager.getDefaultDisplay().getMetrics(displayMetrics);
                }
            } else {
                Log.w(TAG, "WindowManager is null, using default values");
                // Fallback values
                displayMetrics.widthPixels = 1080;
                displayMetrics.heightPixels = 1920;
                displayMetrics.density = 2.0f;
            }

            int screenWidth = displayMetrics.widthPixels;
            int screenHeight = displayMetrics.heightPixels;

            // Ensure we have valid screen dimensions
            if (screenWidth <= 0 || screenHeight <= 0) {
                Log.w(TAG, "Invalid screen dimensions, using defaults");
                screenWidth = 1080;
                screenHeight = 1920;
            }

            // Adjust sizes based on screen width
            if (screenWidth <= 720) {
                menuMaxWidth = (int) (screenWidth * 0.75f);
            } else if (screenWidth <= 1080) {
                menuMaxWidth = (int) (screenWidth * 0.65f);
            } else {
                menuMaxWidth = Math.min(800, (int) (screenWidth * 0.5f));
            }
            
            Log.d(TAG, String.format("Screen: %dx%d, Menu max width: %d, Density: %.2f",
                    screenWidth, screenHeight, menuMaxWidth, displayMetrics.density));
                    
        } catch (Exception e) {
            Log.e(TAG, "Error calculating responsive sizes, using defaults", e);
            // Safe fallback values
            menuMaxWidth = 300;
        }
    }
    
    
    @SuppressLint("InflateParams")
    private void createFloatingIcon() {
        try {
            floatingIcon = LayoutInflater.from(context).inflate(R.layout.floating_icon, null);
        
        WindowManager.LayoutParams iconParams = new WindowManager.LayoutParams(
            WindowManager.LayoutParams.WRAP_CONTENT,
            WindowManager.LayoutParams.WRAP_CONTENT,
            WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY,
            WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE | 
            WindowManager.LayoutParams.FLAG_WATCH_OUTSIDE_TOUCH,
            PixelFormat.TRANSLUCENT
        );
        
        iconParams.gravity = Gravity.TOP | Gravity.START;
        iconParams.x = 100;
        iconParams.y = 200;
        
        // Touch handling for icon
        floatingIcon.setOnTouchListener(new View.OnTouchListener() {
            private int initialX, initialY;
            private float initialTouchX, initialTouchY;
            private boolean isDragging = false;
            private long touchStartTime;
            
            @SuppressLint("ClickableViewAccessibility")
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        initialX = iconParams.x;
                        initialY = iconParams.y;
                        initialTouchX = event.getRawX();
                        initialTouchY = event.getRawY();
                        isDragging = false;
                        touchStartTime = System.currentTimeMillis();
                        break;
                        
                    case MotionEvent.ACTION_MOVE:
                        if (!isDragging) {
                            float deltaX = Math.abs(event.getRawX() - initialTouchX);
                            float deltaY = Math.abs(event.getRawY() - initialTouchY);
                            if (deltaX > 10 || deltaY > 10) {
                                isDragging = true;
                            }
                        }
                        
                        if (isDragging) {
                            iconParams.x = initialX + (int)(event.getRawX() - initialTouchX);
                            iconParams.y = initialY + (int)(event.getRawY() - initialTouchY);
                            windowManager.updateViewLayout(floatingIcon, iconParams);
                        }
                        break;
                        
                    case MotionEvent.ACTION_UP:
                        long touchDuration = System.currentTimeMillis() - touchStartTime;
                        if (!isDragging && touchDuration < 200) {
                            toggleMenu();
                        }
                        break;
                }
                return true;
            }
        });
        
        windowManager.addView(floatingIcon, iconParams);
        Log.d(TAG, "Floating icon created");
        } catch (Exception e) {
            Log.e(TAG, "Error creating floating icon", e);
            throw new RuntimeException("Failed to create floating icon: " + e.getMessage(), e);
        }
    }
    
    @SuppressLint("InflateParams")
    private void createFloatingMenu() {
        try {
            floatingMenu = LayoutInflater.from(context).inflate(R.layout.premium_floating_menu, null);
        
        // Initialize UI components
        categoryTitle = floatingMenu.findViewById(R.id.category_title);
        contentFrame = floatingMenu.findViewById(R.id.content_frame);
            View statusIndicator = floatingMenu.findViewById(R.id.status_indicator);
        quickActions = floatingMenu.findViewById(R.id.quick_actions);
        
        // Set responsive sizing
        LinearLayout contentContainer = floatingMenu.findViewById(R.id.content_container);
        ViewGroup.LayoutParams layoutParams = contentContainer.getLayoutParams();
        if (layoutParams instanceof LinearLayout.LayoutParams linearParams) {
            linearParams.width = Math.min(menuMaxWidth - 50, 300); // Account for sidebar width
            linearParams.height = ViewGroup.LayoutParams.WRAP_CONTENT;
            contentContainer.setLayoutParams(linearParams);
        }
        
        setupNavigationListeners();
        setupMenuContent();
        
        Log.d(TAG, "Floating menu created with responsive sizing");
        } catch (Exception e) {
            Log.e(TAG, "Error creating floating menu", e);
            throw new RuntimeException("Failed to create floating menu: " + e.getMessage(), e);
        }
    }
    
    private void setupNavigationListeners() {
        // Navigation icons
        setupNavIcon(R.id.nav_players, "players");
        setupNavIcon(R.id.nav_aimbot, "aimbot");
        setupNavIcon(R.id.nav_items, "items");
        setupNavIcon(R.id.nav_vehicles, "vehicles");
        setupNavIcon(R.id.nav_settings, "settings");
        
        // Close button
        ImageView closeButton = floatingMenu.findViewById(R.id.close_menu);
        closeButton.setOnClickListener(v -> hideMenu());
        
        // Quick actions
        TextView enableAll = floatingMenu.findViewById(R.id.action_enable_all);
        TextView disableAll = floatingMenu.findViewById(R.id.action_disable_all);
        
        enableAll.setOnClickListener(v -> enableAllFeatures());
        disableAll.setOnClickListener(v -> disableAllFeatures());
    }
    
    private void setupNavIcon(int iconId, String category) {
        ImageView navIcon = floatingMenu.findViewById(iconId);
        navIcon.setOnClickListener(v -> switchCategory(category));
    }
    
    private void switchCategory(String category) {
        if (currentCategory.equals(category)) return;
        
        currentCategory = category;
        updateCategoryDisplay();
        populateCategoryContent();
        
        Log.d(TAG, "Switched to category: " + category);
    }
    
    private void updateCategoryDisplay() {
        // Update category title
        String title = currentCategory.substring(0, 1).toUpperCase() + 
                      currentCategory.substring(1);
        categoryTitle.setText(title);
        
        // Update navigation icon states (visual feedback)
        resetNavigationStates();
        highlightCurrentNavigation();
    }
    
    private void resetNavigationStates() {
        int[] navIds = {R.id.nav_players, R.id.nav_aimbot, R.id.nav_items, 
                       R.id.nav_vehicles, R.id.nav_settings};
        
        for (int id : navIds) {
            ImageView navIcon = floatingMenu.findViewById(id);
            navIcon.setAlpha(0.6f);
        }
    }
    
    private void highlightCurrentNavigation() {
        int currentNavId = getNavigationIdForCategory(currentCategory);
        if (currentNavId != -1) {
            ImageView currentNav = floatingMenu.findViewById(currentNavId);
            currentNav.setAlpha(1.0f);
        }
    }
    
    private int getNavigationIdForCategory(String category) {
        return switch (category) {
            case "players" -> R.id.nav_players;
            case "aimbot" -> R.id.nav_aimbot;
            case "items" -> R.id.nav_items;
            case "vehicles" -> R.id.nav_vehicles;
            case "settings" -> R.id.nav_settings;
            default -> -1;
        };
    }
    
    private void populateCategoryContent() {
        contentFrame.removeAllViews();
        
        switch (currentCategory) {
            case "players":
                populatePlayersContent();
                quickActions.setVisibility(View.VISIBLE);
                break;
            case "aimbot":
                populateAimbotContent();
                quickActions.setVisibility(View.GONE);
                break;
            case "items":
                populateItemsContent();
                quickActions.setVisibility(View.VISIBLE);
                break;
            case "vehicles":
                populateVehiclesContent();
                quickActions.setVisibility(View.VISIBLE);
                break;
            case "settings":
                populateSettingsContent();
                quickActions.setVisibility(View.GONE);
                break;
        }
    }
    
    private void populatePlayersContent() {
        addToggleItem("Snaplines", true);
        addToggleItem("Skeleton", false);
        addToggleItem("Corner Box", true);
        addToggleItem("Name", false);
        addSliderItem("Distance", 7.0f, 1.0f, 20.0f);
        addToggleItem("Weapon", false);
        addToggleItem("Check Visibility", true);
        addToggleItem("Draw Health Bar", true);
    }
    
    private void populateAimbotContent() {
        addToggleItem("Enable", false);
        addToggleItem("Prediction", true);
        addToggleItem("Recoil Compensation", true);
        addToggleItem("Skip Knocked Enemies", true);
        addToggleItem("Skip Invisible Enemies", false);
        addToggleItem("Skip Bots", true);
        addSliderItem("Smoothness", 7.0f, 1.0f, 10.0f);
        addSliderItem("Max Distance", 244.0f, 50.0f, 500.0f);
        addSliderItem("Field of View", 76.0f, 10.0f, 180.0f);
    }
    
    private void populateItemsContent() {
        addToggleItem("Weapons", true);
        addToggleItem("Armor", false);
        addToggleItem("Helmets", true);
        addToggleItem("Backpacks", false);
        addToggleItem("Medical Items", true);
        addToggleItem("Throwables", false);
        addSliderItem("Max Distance", 100.0f, 20.0f, 300.0f);
    }
    
    private void populateVehiclesContent() {
        addToggleItem("Cars", true);
        addToggleItem("Boats", false);
        addToggleItem("Planes", true);
        addToggleItem("Show Health", false);
        addSliderItem("Max Distance", 200.0f, 50.0f, 500.0f);
    }
    
    private void populateSettingsContent() {
        addToggleItem("Performance Mode", false);
        addToggleItem("Chinese Device Optimization", true);
        addToggleItem("Auto-Hide Menu", false);
        addToggleItem("Show FPS", true);
    }
    
    private void addToggleItem(String name, boolean enabled) {
        @SuppressLint("InflateParams") View toggleView = LayoutInflater.from(context).inflate(R.layout.menu_toggle_item, null);
        
        TextView featureName = toggleView.findViewById(R.id.feature_name);
        @SuppressLint("UseSwitchCompatOrMaterialCode") Switch featureToggle = toggleView.findViewById(R.id.feature_toggle);
        View statusDot = toggleView.findViewById(R.id.status_dot);
        
        // Create config key from name
        String configKey = name.toUpperCase().replace(" ", "_");
        
        // Load current state from configuration
        boolean currentState = getBooleanConfig(configKey);
        
        featureName.setText(name);
        featureToggle.setChecked(currentState);
        statusDot.setBackgroundColor(currentState ? 0xFF00FF00 : 0xFF808080);
        
        featureToggle.setOnCheckedChangeListener((buttonView, isChecked) -> {
            // Update configuration
            updateConfiguration(configKey, isChecked ? "1" : "0");
            
            // Update UI
            statusDot.setBackgroundColor(isChecked ? 0xFF00FF00 : 0xFF808080);
            
            // Call native switch if needed
            try {
                // You can add native calls here based on the feature
                Log.d(TAG, name + " " + (isChecked ? "enabled" : "disabled"));
            } catch (Exception e) {
                Log.e(TAG, "Error calling native switch for " + name, e);
            }
        });
        
        contentFrame.addView(toggleView);
    }
    
    @SuppressLint("DefaultLocale")
    private void addSliderItem(String name, float value, float min, float max) {
        @SuppressLint("InflateParams") View sliderView = LayoutInflater.from(context).inflate(R.layout.menu_slider_item, null);
        
        TextView featureName = sliderView.findViewById(R.id.feature_name);
        TextView currentValue = sliderView.findViewById(R.id.current_value);
        SeekBar featureSlider = sliderView.findViewById(R.id.feature_slider);
        View statusDot = sliderView.findViewById(R.id.status_dot);
        
        // Create config key from name
        String configKey = name.toUpperCase().replace(" ", "_");
        
        // Load current value from configuration
        float currentVal = value; // Default value
        try {
            String configValue = getConfig(configKey + "_VALUE");
            if (configValue != null && !configValue.equals("0")) {
                currentVal = Float.parseFloat(configValue);
            }
        } catch (NumberFormatException e) {
            Log.w(TAG, "Invalid float value for " + configKey + ", using default: " + value);
            currentVal = value;
        }
        
        featureName.setText(name);
        currentValue.setText(String.format("%.2f", currentVal));
        
        int progress = (int)((currentVal - min) / (max - min) * 100);
        featureSlider.setProgress(progress);
        
        featureSlider.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                if (fromUser) {
                    float newValue = min + (progress / 100.0f) * (max - min);
                    currentValue.setText(String.format("%.2f", newValue));
                }
            }
            
            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {}
            
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                int progress = seekBar.getProgress();
                float newValue = min + (progress / 100.0f) * (max - min);
                
                // Update configuration
                updateConfiguration(configKey + "_VALUE", String.valueOf(newValue));
                
                Log.d(TAG, name + " set to: " + newValue);
            }
        });
        
        contentFrame.addView(sliderView);
    }
    
    private void enableAllFeatures() {
        for (int i = 0; i < contentFrame.getChildCount(); i++) {
            View child = contentFrame.getChildAt(i);
            @SuppressLint("UseSwitchCompatOrMaterialCode") Switch toggle = child.findViewById(R.id.feature_toggle);
            if (toggle != null) {
                toggle.setChecked(true);
            }
        }
        Log.d(TAG, "All features enabled for category: " + currentCategory);
    }
    
    private void disableAllFeatures() {
        for (int i = 0; i < contentFrame.getChildCount(); i++) {
            View child = contentFrame.getChildAt(i);
            @SuppressLint("UseSwitchCompatOrMaterialCode") Switch toggle = child.findViewById(R.id.feature_toggle);
            if (toggle != null) {
                toggle.setChecked(false);
            }
        }
        Log.d(TAG, "All features disabled for category: " + currentCategory);
    }
    
    private void toggleMenu() {
        if (isMenuVisible) {
            hideMenu();
        } else {
            showMenu();
        }
    }
    
    private void showMenu() {
        if (isMenuVisible) return;
        
        WindowManager.LayoutParams menuParams = new WindowManager.LayoutParams(
            WindowManager.LayoutParams.WRAP_CONTENT,
            WindowManager.LayoutParams.WRAP_CONTENT,
            WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY,
            WindowManager.LayoutParams.FLAG_NOT_TOUCH_MODAL,
            PixelFormat.TRANSLUCENT
        );
        
        menuParams.gravity = Gravity.CENTER;
        
        windowManager.addView(floatingMenu, menuParams);
        isMenuVisible = true;
        
        // Initialize with players category
        switchCategory("players");
        
        Log.d(TAG, "Premium menu shown with responsive design");
    }
    
    private void hideMenu() {
        if (!isMenuVisible) return;
        
        try {
            windowManager.removeView(floatingMenu);
            isMenuVisible = false;
            Log.d(TAG, "Premium menu hidden");
        } catch (Exception e) {
            Log.e(TAG, "Error hiding menu: " + e.getMessage());
        }
    }
    
    public void setupMenuContent() {
        // Initial setup - will be populated when menu is shown
        populateCategoryContent();
    }
    
    public void destroy() {
        try {
            // Mark as destroyed to prevent further operations
            isDestroyed.set(true);
            
            // Cleanup UI handler
            if (uiHandler != null) {
                uiHandler.removeCallbacksAndMessages(null);
                uiHandler = null;
            }
            
            // Remove views safely
            if (floatingIcon != null) {
                try {
                    windowManager.removeView(floatingIcon);
                } catch (Exception e) {
                    Log.e(TAG, "Error removing floating icon", e);
                }
                floatingIcon = null;
            }
            
            if (isMenuVisible && floatingMenu != null) {
                try {
                    windowManager.removeView(floatingMenu);
                } catch (Exception e) {
                    Log.e(TAG, "Error removing floating menu", e);
                }
                floatingMenu = null;
            }
            
            // Clear configuration if needed
            synchronized (lockObject) {
                // Save any pending configurations
                if (configPrefs != null) {
                    try {
                        configPrefs.edit().apply();
                    } catch (Exception e) {
                        Log.e(TAG, "Error saving final configuration", e);
                    }
                }
            }
            
            // Clear static instance
            if (instance == this) {
                instance = null;
            }
            
            isMenuVisible = false;
            Log.d(TAG, "Floating destroyed successfully with cleanup");
        } catch (Exception e) {
            Log.e(TAG, "Error during destroy", e);
        }
    }
    
    // ========================================================================
    // JNI CALLBACK METHODS - Required by native library
    // ========================================================================
    
    // Static getter for native access
    public static Floating getInstance() {
        return instance;
    }
    
    // Common JNI callback methods that the native library expects
    public static void onNativeCallback() {
        Log.d(TAG, "onNativeCallback called");
    }
    
    public static void onNativeCallback(String message) {
        Log.d(TAG, "onNativeCallback called with message: " + message);
    }
    
    public void onUpdate() {
        Log.d(TAG, "onUpdate called");
    }
    
    public void onRender() {
        Log.d(TAG, "onRender called");
    }
    
    // ESP and mod-related callbacks that might be expected
    public static void onESPUpdate() {
        Log.d(TAG, "onESPUpdate called");
    }
    
    public static void onAimbotUpdate() {
        Log.d(TAG, "onAimbotUpdate called");
    }
    
    public static void onModUpdate() {
        Log.d(TAG, "onModUpdate called");
    }
    
    // Configuration callbacks
    public static void onConfigUpdate(String key, String value) {
        Log.d(TAG, "onConfigUpdate called: " + key + " = " + value);
    }
    
    // JNI native methods expected by native code - CRITICAL: Do not remove or rename
    public static native void onSendConfig(String config, String value);
    public static native void Init();
    public static native void saveConfiguration();
    public static native void DrawOn(ESPView espView, android.graphics.Canvas canvas);
    public static native boolean IsHideEsp();
    
    // Context-related methods
    public static void setContext(Context context) {
        Log.d(TAG, "setContext called");
    }
    
    public static Context getContext() {
        Log.d(TAG, "getContext called");
        return instance != null ? instance.context : null;
    }
    
    // State management
    public static boolean isInitialized() {
        return instance != null;
    }
    
    public static void initialize() {
        Log.d(TAG, "initialize called");
        // Floating is initialized by the service, not directly
    }
    
    public static void destroyInstance() {
        Log.d(TAG, "static destroyInstance called");
        if (instance != null) {
            instance.destroy();
        }
    }
} 