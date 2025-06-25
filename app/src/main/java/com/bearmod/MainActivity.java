package com.bearmod;

import android.animation.Animator;
import android.animation.AnimatorSet;
import android.animation.ObjectAnimator;
import android.animation.ValueAnimator;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.provider.Settings;
import android.util.Log;
import android.view.View;
import android.view.Window;
import android.view.WindowInsetsController;
import android.view.WindowManager;
import android.view.animation.AccelerateDecelerateInterpolator;
import android.view.animation.OvershootInterpolator;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Button;
import android.widget.LinearLayout;

import androidx.annotation.NonNull;

// HmacUtil removed - KeyAuth API v1.3 doesn't use application secrets
// import com.bearmod.webhook.WebhookTestActivity; // Disabled - using simple license verification

/**
 * MainActivity - Main App Activity for BearMod
 * 
 * This is the main activity that stays alive throughout the app lifecycle.
 * It initializes the native mod library and starts the floating overlay service.
 * Unlike a launcher app, this activity remains active and provides the main app UI.
 */
public class MainActivity extends Activity {
    private static final String TAG = "MainActivity";
    
    // UI Components
    private View splashLayout;
    private View mainAppLayout;
    private ImageView logo;
    private TextView title, status, welcomeText;
    private ProgressBar logoProgress;
    private Button settingsButton, aboutButton, exitButton;

    // State Management
    private AnimatorSet currentAnimation;
    private boolean isInitializing = false;
    private boolean isModInitialized = false;
    private boolean splashCompleted = false;


    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        // Load native library first - this matches the original BearMod pattern
        try {
            System.loadLibrary("bearmod");
            Log.d(TAG, "Native library loaded successfully in MainActivity");
        } catch (UnsatisfiedLinkError e) {
            Log.e(TAG, "Failed to load native library: " + e.getMessage());
        }
        
        // Configure KeyAuth webhook if needed
        // TODO: Set your webhook endpoint from KeyAuth dashboard
        // KeyAuthVerifier.configureWebhook("https://your-webhook-endpoint.com/keyauth", true);
        
        // Test HMAC generation with your known values
        testHmacGeneration();
        
        // Configure window for fullscreen experience
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        
        // Modern fullscreen approach for Android 11+ with fallback
        // Use modern WindowInsetsController for Android 11+
        getWindow().setDecorFitsSystemWindows(false);

        setContentView(R.layout.activity_main);
        
        initializeViews();
        startInitializationSequence();
    }

    private void initializeViews() {
        // Splash screen components
        splashLayout = findViewById(R.id.splash_layout);
        FrameLayout logoContainer = findViewById(R.id.logo_container);
        logo = findViewById(R.id.logo);
        title = findViewById(R.id.title);
        status = findViewById(R.id.status);
        logoProgress = findViewById(R.id.logo_progress);
        
        // Main app components
        mainAppLayout = findViewById(R.id.main_app_layout);
        welcomeText = findViewById(R.id.welcome_text);
        settingsButton = findViewById(R.id.settings_button);
        aboutButton = findViewById(R.id.about_button);
        exitButton = findViewById(R.id.exit_button);
        
        // Set initial states
        logo.setScaleX(0);
        logo.setScaleY(0);
        title.setAlpha(0);
        status.setAlpha(0);
        logoProgress.setProgress(0);
        
        // Hide main app initially
        mainAppLayout.setVisibility(View.GONE);
        
        setupButtonListeners();
    }
    
    private void setupButtonListeners() {
        settingsButton.setOnClickListener(v -> {
            // Note: Floating doesn't have static show method
            // The floating icon will be visible automatically when service starts
            Log.d(TAG, "Settings button clicked - floating menu should be visible");
        });
        
        aboutButton.setOnClickListener(v -> showAboutDialog());
        
        exitButton.setOnClickListener(v -> {
            // Properly exit the app
            if (isModInitialized) {
                // Stop floating service
                Intent serviceIntent = new Intent(this, PremiumFloatingService.class);
                stopService(serviceIntent);
            }
            finish();
            System.exit(0);
        });
        
        // Add long-press webhook test for developers
        settingsButton.setOnLongClickListener(v -> {
            openWebhookTester();
            return true;
        });
    }

    private void startInitializationSequence() {
        if (currentAnimation != null) {
            currentAnimation.cancel();
        }

        // Check if user needs to login first
        if (!Launcher.hasValidKey(this)) {
            Log.d(TAG, "No valid license key - showing login");
            startLoginActivity();
            return;
        }

        // User has valid key - start splash animation and initialization
        startSplashAnimation();
    }
    
    private void startLoginActivity() {
        Intent loginIntent = new Intent(this, LauncherLoginActivity.class);
        startActivityForResult(loginIntent, 1001);
    }
    
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        
        if (requestCode == 1001) { // Login activity result
            if (resultCode == RESULT_OK) {
                // Login successful - start initialization
                Log.d(TAG, "Login successful - starting initialization");
                startSplashAnimation();
            } else {
                // Login failed or cancelled - exit app
                Log.d(TAG, "Login failed or cancelled - exiting");
                finish();
            }
        } else if (requestCode == 1002) { // Overlay permission result
            if (resultCode == RESULT_OK) {
                // Permission granted - start initialization
                Log.d(TAG, "Overlay permission granted - starting initialization");
                startSplashAnimation();
            } else {
                // Permission denied - exit app
                Log.d(TAG, "Overlay permission denied - exiting");
                finish();
            }
        }
    }

    private void startSplashAnimation() {
        isInitializing = true;
        
        AnimatorSet animatorSet = new AnimatorSet();

        // Logo scale animation with bounce
        ObjectAnimator scaleX = ObjectAnimator.ofFloat(logo, "scaleX", 0f, 1f);
        ObjectAnimator scaleY = ObjectAnimator.ofFloat(logo, "scaleY", 0f, 1f);
        scaleX.setInterpolator(new OvershootInterpolator());
        scaleY.setInterpolator(new OvershootInterpolator());

        // Progress bar animation
        ValueAnimator progressAnimator = ValueAnimator.ofInt(0, 100);
        progressAnimator.addUpdateListener(animation -> 
            logoProgress.setProgress((Integer) animation.getAnimatedValue()));

        // Title and status fade in
        ObjectAnimator titleFade = ObjectAnimator.ofFloat(title, "alpha", 0f, 1f);
        ObjectAnimator statusFade = ObjectAnimator.ofFloat(status, "alpha", 0f, 1f);

        // Logo rotation
        ObjectAnimator rotation = ObjectAnimator.ofFloat(logo, "rotation", 0f, 360f);
        rotation.setInterpolator(new AccelerateDecelerateInterpolator());

        // Combine animations
        AnimatorSet initialSet = new AnimatorSet();
        initialSet.playTogether(scaleX, scaleY, progressAnimator, rotation);

        animatorSet.playSequentially(
            initialSet,
            titleFade,
            statusFade
        );

        // Set durations
        scaleX.setDuration(1000);
        scaleY.setDuration(1000);
        progressAnimator.setDuration(1500);
        rotation.setDuration(1000);
        titleFade.setDuration(500);
        statusFade.setDuration(500);

        // Initialize mod after animations
        animatorSet.addListener(new Animator.AnimatorListener() {
            @SuppressLint("SetTextI18n")
            @Override
            public void onAnimationStart(@NonNull Animator animation) {
                status.setText("Initializing BearMod...");
            }

            @Override
            public void onAnimationEnd(@NonNull Animator animation) {
                if (!isInitializing) return;
                
                // Start mod initialization
                new Handler(Looper.getMainLooper()).postDelayed(() -> {
                    initializeMod();
                }, 500);
            }

            @Override
            public void onAnimationCancel(@NonNull Animator animation) {
                isInitializing = false;
            }

            @Override
            public void onAnimationRepeat(@NonNull Animator animation) {}
        });

        currentAnimation = animatorSet;
        animatorSet.start();
    }
    
    @SuppressLint("SetTextI18n")
    private void initializeMod() {
        try {
            status.setText("Loading native library...");
            
            // Check overlay permission first
            if (!Settings.canDrawOverlays(this)) {
                status.setText("Requesting overlay permission...");
                requestOverlayPermission();
                return;
            }

            // Initialize native library
            Launcher.safeInit(this);
            
            // Verify native library is working
            if (!Launcher.isNativeLibraryLoaded()) {
                status.setText("Running in demo mode...");
                Log.w(TAG, "Native library not loaded - running in demo mode");
            }
            
            status.setText("Starting floating overlay...");
            
            // Start premium floating service (this runs in background)
            Intent serviceIntent = new Intent(this, PremiumFloatingService.class);
            startService(serviceIntent);
            
            status.setText("BearMod ready!");
            
            // Mark as initialized
            isModInitialized = true;
            
            // Transition to main app after short delay
            new Handler(Looper.getMainLooper()).postDelayed(this::transitionToMainApp, 1000);
            
        } catch (Exception e) {
            Log.e(TAG, "Error initializing mod", e);
            status.setText("Error: " + e.getMessage());
            
            // Show retry option
            new Handler(Looper.getMainLooper()).postDelayed(this::showRetryDialog, 2000);
        }
    }
    
    private void requestOverlayPermission() {
        Intent intent = new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION,
                Uri.parse("package:" + getPackageName()));
        startActivityForResult(intent, 1002);
    }
    
    private void transitionToMainApp() {
        splashCompleted = true;
        
        // Animate splash screen out
        AnimatorSet exitAnimation = new AnimatorSet();

        // Scale down logo
        ObjectAnimator scaleDownX = ObjectAnimator.ofFloat(logo, "scaleX", 1f, 0f);
        ObjectAnimator scaleDownY = ObjectAnimator.ofFloat(logo, "scaleY", 1f, 0f);

        // Fade out splash elements
        ObjectAnimator titleFadeOut = ObjectAnimator.ofFloat(title, "alpha", 1f, 0f);
        ObjectAnimator statusFadeOut = ObjectAnimator.ofFloat(status, "alpha", 1f, 0f);
        ObjectAnimator splashFadeOut = ObjectAnimator.ofFloat(splashLayout, "alpha", 1f, 0f);

        // Fade in main app
        ObjectAnimator mainAppFadeIn = ObjectAnimator.ofFloat(mainAppLayout, "alpha", 0f, 1f);

        // Combine animations
        AnimatorSet exitSet = new AnimatorSet();
        exitSet.playTogether(scaleDownX, scaleDownY, titleFadeOut, statusFadeOut, splashFadeOut);
        
        exitAnimation.playSequentially(exitSet, mainAppFadeIn);
        exitAnimation.setDuration(800);

        exitAnimation.addListener(new Animator.AnimatorListener() {
            @Override
            public void onAnimationStart(@NonNull Animator animation) {}

            @Override
            public void onAnimationEnd(@NonNull Animator animation) {
                splashLayout.setVisibility(View.GONE);
                mainAppLayout.setVisibility(View.VISIBLE);
                
                // Update welcome text
                welcomeText.setText("BearMod is running!\nThe floating menu is available.");
            }

            @Override
            public void onAnimationCancel(@NonNull Animator animation) {
                splashLayout.setVisibility(View.GONE);
                mainAppLayout.setVisibility(View.VISIBLE);
            }

            @Override
            public void onAnimationRepeat(@NonNull Animator animation) {}
        });

        exitAnimation.start();
    }
    
    private void showRetryDialog() {
        new android.app.AlertDialog.Builder(this)
            .setTitle("Initialization Failed")
            .setMessage("Failed to initialize BearMod. Would you like to retry?")
            .setPositiveButton("Retry", (dialog, which) -> {
                // Reset and retry
                initializeMod();
            })
            .setNegativeButton("Exit", (dialog, which) -> {
                finish();
            })
            .setCancelable(false)
            .show();
    }
    
    private void showAboutDialog() {
        new android.app.AlertDialog.Builder(this)
            .setTitle("About BearMod")
            .setMessage("BearMod v3.8.0\n\nA powerful modding framework for Android games.\n\nFeatures:\n• ESP/Wallhack\n• Aimbot\n• Anti-recording\n• Performance optimization")
            .setPositiveButton("OK", null)
            .show();
    }

    @Override
    public void onBackPressed() {
        if (splashCompleted) {
            // Show exit confirmation
            new android.app.AlertDialog.Builder(this)
                .setTitle("Exit BearMod")
                .setMessage("Are you sure you want to exit?")
                .setPositiveButton("Yes", (dialog, which) -> {
                    if (isModInitialized) {
                        Intent serviceIntent = new Intent(this, PremiumFloatingService.class);
                        stopService(serviceIntent);
                    }
                    finish();
                    System.exit(0);
                })
                .setNegativeButton("No", null)
                .show();
        } else {
            // During splash, just minimize
            moveTaskToBack(true);
        }
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        if (hasFocus) {
            hideSystemUI();
        }
    }
    
    private void hideSystemUI() {
        // Modern approach for Android 11+
        WindowInsetsController controller = getWindow().getInsetsController();
        if (controller != null) {
            controller.hide(android.view.WindowInsets.Type.statusBars() |
                           android.view.WindowInsets.Type.navigationBars());
            controller.setSystemBarsBehavior(
                WindowInsetsController.BEHAVIOR_SHOW_TRANSIENT_BARS_BY_SWIPE);
        }
    }
    
    @Override
    protected void onResume() {
        super.onResume();
        Log.d(TAG, "MainActivity resumed - mod active: " + isModInitialized);
    }
    
    @Override
    protected void onPause() {
        super.onPause();
        Log.d(TAG, "MainActivity paused");
    }
    
    /**
     * KeyAuth API v1.3 initialization - no secrets needed
     */
    private void testHmacGeneration() {
        Log.d(TAG, "KeyAuth API v1.3 - No application secrets required");
        Log.d(TAG, "Using simplified license verification");
    }
    
    /**
     * Developer debugging function (placeholder for future features)
     */
    private void openWebhookTester() {
        Log.d(TAG, "Long-press detected - webhook functionality disabled");
        // Webhook testing removed - using simple license verification
        
        // Show simple debug info instead
        String hwid = Launcher.getDeviceHWID(this);
        new android.app.AlertDialog.Builder(this)
            .setTitle("Debug Info")
            .setMessage("Device HWID: " + hwid.substring(0, Math.min(12, hwid.length())) + "...")
            .setPositiveButton("OK", null)
            .show();
    }
    
    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.d(TAG, "MainActivity destroyed");
        
        // Clean up
        if (currentAnimation != null) {
            currentAnimation.cancel();
        }
        
        // Stop floating service if running
        if (isModInitialized) {
            Intent serviceIntent = new Intent(this, PremiumFloatingService.class);
            stopService(serviceIntent);
        }
    }
}
