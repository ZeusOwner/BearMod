package com.bearmod;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.view.View;
import android.view.WindowInsetsController;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

public class LauncherLoginActivity extends Activity {
    private static final String TAG = "LauncherLoginActivity";
    
    private EditText editLicenseKey;
    private Button buttonLogin;
    private ProgressBar progressBar;
    private TextView statusText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        // Set content view first
        setContentView(R.layout.activity_launcher_login);
        
        // Set fullscreen flags after content view is set
        setupFullscreen();
        
        initializeViews();
        setupClickListeners();
    }
    
    private void setupFullscreen() {
        try {
            getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
            
            // Modern fullscreen approach for Android 11+ with fallback
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
                // Use modern WindowInsetsController for Android 11+
                getWindow().setDecorFitsSystemWindows(false);
                WindowInsetsController controller = getWindow().getInsetsController();
                if (controller != null) {
                    controller.hide(android.view.WindowInsets.Type.statusBars() |
                                   android.view.WindowInsets.Type.navigationBars());
                    controller.setSystemBarsBehavior(
                        WindowInsetsController.BEHAVIOR_SHOW_TRANSIENT_BARS_BY_SWIPE);
                }
            } else {
                // Fallback for older Android versions
                getWindow().addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);
                getWindow().getDecorView().setSystemUiVisibility(
                    View.SYSTEM_UI_FLAG_FULLSCREEN |
                    View.SYSTEM_UI_FLAG_HIDE_NAVIGATION |
                    View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY);
            }
        } catch (Exception e) {
            // If fullscreen setup fails, continue anyway
            android.util.Log.e(TAG, "Error setting up fullscreen", e);
        }
    }
    
    private void initializeViews() {
        editLicenseKey = findViewById(R.id.edit_license_key);
        buttonLogin = findViewById(R.id.button_login);
        progressBar = findViewById(R.id.progress_bar);
        statusText = findViewById(R.id.status_text);
        View loginContainer = findViewById(R.id.login_container);
        
        // Set initial visibility
        progressBar.setVisibility(View.GONE);
        statusText.setVisibility(View.GONE);
    }
    
    private void setupClickListeners() {
        buttonLogin.setOnClickListener(v -> attemptLogin());
        
        // Allow enter key to trigger login
        editLicenseKey.setOnEditorActionListener((v, actionId, event) -> {
            attemptLogin();
            return true;
        });
    }
    
    @SuppressLint("SetTextI18n")
    private void attemptLogin() {
        String licenseKey = editLicenseKey.getText().toString().trim();
        
        if (licenseKey.isEmpty()) {
            Toast.makeText(this, "Please enter a license key", Toast.LENGTH_SHORT).show();
            return;
        }
        
        // Show loading state
        setLoadingState(true);
        statusText.setText("Verifying license...");
        statusText.setVisibility(View.VISIBLE);
        
        // Perform login on background thread
        Launcher.loginAsync(this, licenseKey, new Launcher.LoginCallback() {
            @Override
            public void onSuccess() {
                runOnUiThread(() -> {
                    statusText.setText("Login successful!");
                    
                    // Return success to MainActivity after short delay
                    new Handler(Looper.getMainLooper()).postDelayed(() -> {
                        setResult(RESULT_OK);
                        finish();
                    }, 1000);
                });
            }
            
            @Override
            public void onError(String errorMessage) {
                runOnUiThread(() -> {
                    setLoadingState(false);
                    statusText.setText("Login failed: " + errorMessage);
                    statusText.setTextColor(0xFFFF6B6B); // Red color for error
                    Toast.makeText(LauncherLoginActivity.this, 
                        "Login failed: " + errorMessage, Toast.LENGTH_LONG).show();
                });
            }
        });
    }
    
    private void setLoadingState(boolean loading) {
        buttonLogin.setEnabled(!loading);
        editLicenseKey.setEnabled(!loading);
        progressBar.setVisibility(loading ? View.VISIBLE : View.GONE);
        
        if (!loading) {
            statusText.setTextColor(0xFF4CAF50); // Green color for success
        }
    }
    
    @Override
    public void onBackPressed() {
        // Return cancelled result to MainActivity
        setResult(RESULT_CANCELED);
        finish();
    }
} 