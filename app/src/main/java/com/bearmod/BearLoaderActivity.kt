package com.bearmod

import android.app.Activity
import android.content.Intent
import android.net.Uri
import android.os.Build
import android.os.Bundle
import android.provider.Settings
import android.util.Log
import android.widget.Toast
import androidx.lifecycle.lifecycleScope
import com.bearmod.loader.core.BearModCore
import com.bearmod.loader.core.LicenseValidationResult
import kotlinx.coroutines.launch

/**
 * Enhanced MainActivity that integrates Bear-Loader authentication with BearMod loading
 * This replaces the traditional MainActivity with a complete license + module loading flow
 */
class BearLoaderActivity : Activity() {
    
    companion object {
        private const val TAG = "BearLoaderActivity"
        private const val REQUEST_OVERLAY_PERMISSION = 1001
    }
    
    private lateinit var bearModCore: BearModCore
    private var isInitialized = false
    
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        
        try {
            Log.i(TAG, "BearLoader starting...")
            
            // Initialize BearMod core
            bearModCore = BearModCore.getInstance()
            
            // Check overlay permission first
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M && !Settings.canDrawOverlays(this)) {
                requestOverlayPermission()
                return
            }
            
            // Start initialization process
            initializeBearLoader()
            
        } catch (e: Exception) {
            Log.e(TAG, "Failed to start BearLoader", e)
            showError("Failed to initialize BearLoader: ${e.message}")
        }
    }
    
    /**
     * Initialize BearLoader with authentication and module loading
     */
    private fun initializeBearLoader() {
        lifecycleScope.launch {
            try {
                showProgress("Initializing BearMod...")
                
                // Step 1: Initialize BearMod core
                val coreInitialized = bearModCore.initialize(applicationContext)
                if (!coreInitialized) {
                    showError("Failed to initialize BearMod core")
                    return@launch
                }
                
                // Step 2: Show authentication UI
                showProgress("Waiting for authentication...")
                showAuthenticationDialog()
                
            } catch (e: Exception) {
                Log.e(TAG, "Initialization failed", e)
                showError("Initialization failed: ${e.message}")
            }
        }
    }
    
    /**
     * Show authentication dialog (integrate with your existing KeyAuth UI)
     */
    private fun showAuthenticationDialog() {
        // This would show your existing Bear-Loader authentication UI
        // For now, we'll simulate with a simple license key input
        
        // TODO: Replace with your actual KeyAuth authentication UI
        val testLicenseKey = "auUAiG-Ve9BFs-3qo79G-m" // From your screenshot
        
        lifecycleScope.launch {
            authenticateAndLoadModules(testLicenseKey)
        }
    }
    
    /**
     * Authenticate user and load appropriate modules
     */
    private suspend fun authenticateAndLoadModules(licenseKey: String) {
        try {
            showProgress("Validating license...")
            
            // Detect target game
            val targetPackage = detectTargetGame()
            if (targetPackage == null) {
                showGameSelectionDialog()
                return
            }
            
            // Validate license and load modules
            val result = bearModCore.validateLicenseAndLoadModules(licenseKey, targetPackage)
            
            when (result) {
                is LicenseValidationResult.Success -> {
                    handleSuccessfulAuthentication(result, targetPackage)
                }
                
                is LicenseValidationResult.InvalidLicense -> {
                    showError("Invalid license: ${result.reason}")
                }
                
                is LicenseValidationResult.Error -> {
                    showError("Authentication error: ${result.message}")
                }
            }
            
        } catch (e: Exception) {
            Log.e(TAG, "Authentication failed", e)
            showError("Authentication failed: ${e.message}")
        }
    }
    
    /**
     * Handle successful authentication and module loading
     */
    private suspend fun handleSuccessfulAuthentication(
        result: LicenseValidationResult.Success,
        targetPackage: String
    ) {
        try {
            showProgress("Loading features...")
            
            // Get available features
            val features = bearModCore.getAvailableFeatures()
            
            // Show success message
            val message = buildString {
                appendLine("✅ Authentication successful!")
                appendLine("User: ${result.userInfo.username}")
                appendLine("Subscription: ${result.userInfo.subscriptionType}")
                appendLine("Features loaded: ${features.size}")
                appendLine("Target: ${getGameName(targetPackage)}")
            }
            
            showSuccess(message)
            
            // Start the actual mod functionality
            startModFunctionality(targetPackage, features)
            
        } catch (e: Exception) {
            Log.e(TAG, "Failed to handle successful authentication", e)
            showError("Failed to start mod functionality: ${e.message}")
        }
    }
    
    /**
     * Start the actual mod functionality
     */
    private suspend fun startModFunctionality(targetPackage: String, features: List<com.bearmod.loader.core.Feature>) {
        try {
            // Initialize the traditional BearMod launcher
            Launcher.Init(this)
            
            // Enable features based on license
            for (feature in features) {
                val enabled = bearModCore.executeFeature(feature.id)
                Log.i(TAG, "Feature ${feature.name}: ${if (enabled) "enabled" else "failed"}")
            }
            
            // Show floating UI if available
            if (::bearModCore.isInitialized) {
                showFloatingUI()
            }
            
            // Minimize activity (don't finish, just move to background)
            moveTaskToBack(true)
            
        } catch (e: Exception) {
            Log.e(TAG, "Failed to start mod functionality", e)
            showError("Failed to start features: ${e.message}")
        }
    }
    
    /**
     * Detect target game package
     */
    private fun detectTargetGame(): String? {
        val supportedGames = listOf(
            "com.tencent.ig",                    // PUBG Mobile
            "com.activision.callofduty.shooter", // COD Mobile
            "com.garena.game.freefire",          // Free Fire
            "com.supercell.clashofclans"         // Clash of Clans
        )
        
        val packageManager = packageManager
        for (gamePackage in supportedGames) {
            try {
                packageManager.getPackageInfo(gamePackage, 0)
                Log.i(TAG, "Detected game: $gamePackage")
                return gamePackage
            } catch (e: Exception) {
                // Game not installed
            }
        }
        
        return null
    }
    
    /**
     * Show game selection dialog if no game detected
     */
    private fun showGameSelectionDialog() {
        // TODO: Implement game selection UI
        showError("No supported games detected. Please install PUBG Mobile, COD Mobile, or Free Fire.")
    }
    
    /**
     * Show floating UI
     */
    private fun showFloatingUI() {
        try {
            // Use existing Floating class if available
            val floating = Floating()
            floating.showFloatingWindow(this)
        } catch (e: Exception) {
            Log.w(TAG, "Failed to show floating UI", e)
        }
    }
    
    /**
     * Request overlay permission
     */
    private fun requestOverlayPermission() {
        try {
            val intent = Intent(
                Settings.ACTION_MANAGE_OVERLAY_PERMISSION,
                Uri.parse("package:$packageName")
            )
            startActivityForResult(intent, REQUEST_OVERLAY_PERMISSION)
        } catch (e: Exception) {
            Log.e(TAG, "Failed to request overlay permission", e)
            showError("Please grant overlay permission manually")
        }
    }
    
    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)
        
        if (requestCode == REQUEST_OVERLAY_PERMISSION) {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M && Settings.canDrawOverlays(this)) {
                initializeBearLoader()
            } else {
                showError("Overlay permission is required")
            }
        }
    }
    
    override fun onDestroy() {
        super.onDestroy()
        try {
            if (::bearModCore.isInitialized) {
                bearModCore.cleanup()
            }
        } catch (e: Exception) {
            Log.e(TAG, "Error during cleanup", e)
        }
    }
    
    // Helper methods for UI feedback
    private fun showProgress(message: String) {
        Log.i(TAG, "Progress: $message")
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show()
    }
    
    private fun showSuccess(message: String) {
        Log.i(TAG, "Success: $message")
        Toast.makeText(this, message, Toast.LENGTH_LONG).show()
    }
    
    private fun showError(message: String) {
        Log.e(TAG, "Error: $message")
        Toast.makeText(this, "Error: $message", Toast.LENGTH_LONG).show()
    }
    
    private fun getGameName(packageName: String): String {
        return when (packageName) {
            "com.tencent.ig" -> "PUBG Mobile"
            "com.activision.callofduty.shooter" -> "COD Mobile"
            "com.garena.game.freefire" -> "Free Fire"
            "com.supercell.clashofclans" -> "Clash of Clans"
            else -> packageName
        }
    }
}
