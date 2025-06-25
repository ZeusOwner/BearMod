package com.bearmod;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;

public class PremiumFloatingService extends Service {
    private static final String TAG = "PremiumFloatingService";
    private Floating floating;
    
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }
    
    @Override
    public void onCreate() {
        super.onCreate();
        Log.d(TAG, "PremiumFloatingService created");
        
        try {
            // Initialize the floating system
            floating = new Floating(this);
            Log.d(TAG, "Floating initialized successfully");
        } catch (Exception e) {
            Log.e(TAG, "Error creating Floating", e);
        }
    }
    
    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        Log.d(TAG, "PremiumFloatingService started");
        return START_STICKY; // Restart service if it gets killed
    }
    
    @Override
    public void onDestroy() {
        super.onDestroy();
        Log.d(TAG, "PremiumFloatingService destroyed");
        
        if (floating != null) {
            try {
                floating.destroy();
                Log.d(TAG, "Floating destroyed successfully");
            } catch (Exception e) {
                Log.e(TAG, "Error destroying Floating", e);
            }
        }
    }
} 