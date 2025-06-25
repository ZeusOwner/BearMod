package com.bearmod;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Bitmap;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.os.SystemClock;
import android.view.View;
import android.graphics.Matrix;
import android.graphics.RectF;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.graphics.PixelFormat;

import androidx.annotation.NonNull;

public class ESPView extends SurfaceView implements SurfaceHolder.Callback, Runnable {
    private static final String TAG = "ESPView";

    private int mFPS = 0;
    private int mFPSCounter = 0;
    private long mFPSTime = 0;
  
    Paint p;
    Bitmap bitmap;
    Bitmap out;
    Bitmap out2;
    Paint mStrokePaint;
    Paint mTextPaint;
    Paint mFilledPaint;
    
    // Thread management
    private Thread mThread;
    private volatile boolean mRunning = false; // Added for proper thread control
    private SurfaceHolder holder;
    private Context context;
    
	int screenWidth, screenHeight;
    Bitmap[] OTHER = new Bitmap[4];
    private int mTargetFps = 60; // Default, can be set dynamically
    
    // Performance optimization variables
    private static final int TARGET_FPS_HIGH = 144;
    private static final int TARGET_FPS_MID = 90;
    private static final int TARGET_FPS_LOW = 60;
    private static final int TARGET_FPS_POWER_SAVE = 30;
    
    private int currentTargetFPS = TARGET_FPS_LOW; // Default to 60 FPS
    private long lastFrameTime = 0;
    private long frameTime = 1000 / TARGET_FPS_LOW; // 60 FPS default
    
    // Performance monitoring
    private long totalFrames = 0;
    private long totalFrameTime = 0;
    private long lastPerformanceCheck = 0;
    private static final long PERFORMANCE_CHECK_INTERVAL = 5000; // Check every 5 seconds
    
    // CPU usage monitoring
    private long lastCpuCheck = 0;
    private static final long CPU_CHECK_INTERVAL = 2000; // Check every 2 seconds
    private boolean isHighCpuUsage = false;
    
    // Memory management
    private static final int MAX_FRAME_SKIP = 3;
    private int frameSkipCount = 0;
    private Paint espPaint;
    private Canvas surfaceCanvas;
    
    // Device performance level
    private enum PerformanceLevel {
        HIGH, // Gaming phones, flagships
        MEDIUM, // Mid-range devices
        LOW, // Budget phones
        POWER_SAVE // Very low-end or overheating
    }
    
    private PerformanceLevel currentPerformanceLevel = PerformanceLevel.MEDIUM;

    public ESPView(Context context) {
        super(context);
        this.context = context;
        holder = getHolder();
        holder.addCallback(this);
        
        // Make the surface transparent
        holder.setFormat(PixelFormat.TRANSLUCENT);
        setZOrderOnTop(true);
        
        InitializePaints();
        
        // LAG FIX / full smooth
        setFocusableInTouchMode(false);
        setEnabled(false);
        setFitsSystemWindows(false);
        setHapticFeedbackEnabled(false);
        setFocusable(false);
        setFocusedByDefault(false);
        setFocusable(false);

        setForceDarkAllowed(false);
        setHovered(false);
        setKeepScreenOn(false);
      //  setAutoHandwritingEnabled(false);//Crash
        setActivated(false);
       setHovered(false);

        setBackgroundColor(Color.TRANSPARENT);
        
        // Auto-detect device performance level
        detectDevicePerformance();
        adjustFPSBasedOnPerformance();
        
        // Don't start the rendering thread here - wait for surface creation
    }

    private void startRenderingThread() {
        if (mThread == null || !mThread.isAlive()) {
            mRunning = true;
            mThread = new Thread(this, "ESPView-Render");
            mThread.start();
        }
    }
    
    // Add method to safely stop the rendering thread
    public void stopRenderingThread() {
        mRunning = false;
        if (mThread != null) {
            mThread.interrupt();
            try {
                mThread.join(1000); // Wait up to 1 second for thread to finish
            } catch (InterruptedException e) {
                Log.w(TAG, "Thread interrupted while waiting for render thread to stop", e);
                Thread.currentThread().interrupt();
            }
            mThread = null;
        }
    }

    public void InitializePaints() {
        mStrokePaint = new Paint();
        mStrokePaint.setStyle(Paint.Style.STROKE);
        mStrokePaint.setAntiAlias(true);
        mStrokePaint.setColor(Color.rgb(0, 0, 0));
        
        mFilledPaint = new Paint();
        mFilledPaint.setStyle(Paint.Style.FILL);
        mFilledPaint.setAntiAlias(true);
        mFilledPaint.setColor(Color.rgb(0, 0, 0));
        
        mTextPaint = new Paint();
        mTextPaint.setStyle(Paint.Style.FILL_AND_STROKE);
        mTextPaint.setAntiAlias(true);
        mTextPaint.setColor(Color.rgb(0, 0, 0));
        mTextPaint.setTextAlign(Paint.Align.CENTER);
        mTextPaint.setStrokeWidth(1.1f);
    }
    
    @SuppressLint("SuspiciousIndentation")
    @Override
    protected void onDraw(@NonNull Canvas canvas) {
        if (this.getVisibility() == View.VISIBLE) {
            this.ClearCanvas(canvas);
            try {
                // ESP drawing will be handled by native code when available
                drawDemoESP(canvas);
            } catch (Exception e) {
                Log.e(TAG, "Error in DrawOn", e);
            }
        }
    }
             
    public void DrawText5(Canvas canvas, int n, int n2, int n3, int n4, float f, String string2, float f2, float f3, float f4) {
        if (canvas == null || mTextPaint == null) return;
        
        this.mTextPaint.setARGB(n, n2, n3, n4);
        this.mTextPaint.setTextSize(f4);
        if (SystemClock.uptimeMillis() - this.mFPSTime > (long) 1000) {
            this.mFPSTime = SystemClock.uptimeMillis();
            this.mFPS = this.mFPSCounter;
            this.mFPSCounter = 0;
        } else {
            this.mFPSCounter = 1 + this.mFPSCounter;
        }
        String s = "" + this.mFPS;
        this.mTextPaint.setColor(Color.rgb((int)n2, (int)n3, (int)n4));
        this.mTextPaint.setAlpha(n);
        this.mTextPaint.setStrokeWidth(f);
        if (this.getRight() > 1950 || this.getBottom() > 1920) {
            this.mTextPaint.setTextSize(f4 + (float)4);
        } else if (this.getRight() == 1950 || this.getBottom() == 1920) {
            this.mTextPaint.setTextSize(f4 + (float)2);
        } else {
            this.mTextPaint.setTextSize(f4);
        }
        canvas.drawText(string2, f2, f3+20, this.mTextPaint);
    }
    
    public void NRG_DrawText(Canvas cvs, int a, int r, int g, int b, String txt, float posX, float posY, float size) {
        if (cvs == null || mTextPaint == null || txt == null) return;
        
        mTextPaint.setShadowLayer(3, 0,0, Color.BLACK);
        mTextPaint.setColor(Color.rgb(r, g, b));
        mTextPaint.setTextSize(size);
        cvs.drawText(txt, posX, posY, mTextPaint);
    }
	
    public void NRG_DrawRect(Canvas cvs, int a, int r, int g, int b, float stroke, float x, float y, float width, float height) {
        if (cvs == null || mStrokePaint == null) return;
        
        mStrokePaint.setStrokeWidth(stroke);
        mStrokePaint.setColor(Color.rgb(r, g, b));
        mStrokePaint.setAlpha(a);
        cvs.drawRoundRect(new RectF(x, y, width, height), 5, 5, mStrokePaint);
    }

    public void NRG_DrawCircle(Canvas cvs, int a, int r, int g, int b, float posX, float posY, float radius, float stroke) {
        if (cvs == null || mStrokePaint == null) return;
        
        mStrokePaint.setARGB(a, r, g, b);
        mStrokePaint.setStrokeWidth(stroke);
        cvs.drawCircle(posX, posY, radius, mStrokePaint);
    }
    
    public void NRG_DrawLine(Canvas cvs, int a, int r, int g, int b, float lineWidth, float fromX, float fromY, float toX, float toY) {
        if (cvs == null || mStrokePaint == null) return;
        
        mStrokePaint.setColor(Color.rgb(r, g, b));
        mStrokePaint.setAlpha(a);
        mStrokePaint.setStrokeWidth(lineWidth);
        cvs.drawLine(fromX, fromY, toX, toY, mStrokePaint);
    }
    
    public void NRG_DrawFilledRect(Canvas cvs, int a, int r, int g, int b, float x, float y, float width, float height) {
        if (cvs == null || mFilledPaint == null) return;
        
        mFilledPaint.setColor(Color.rgb(r, g, b));
        mFilledPaint.setAlpha(a);
        cvs.drawRoundRect(new RectF(x, y, width, height), 5, 5, mFilledPaint);
    }
    
    public void DrawRect(Canvas cvs, int a, int r, int g, int b, float stroke, float x, float y, float width, float height) {
        if (cvs == null || mStrokePaint == null) return;
        
        mStrokePaint.setStrokeWidth(stroke);
        mStrokePaint.setColor(Color.rgb(r, g, b));
        mStrokePaint.setAlpha(a);
        cvs.drawRoundRect(new RectF(x, y, width, height), 5, 5, mStrokePaint);
    }
    
    private int getWeaponIcon(int id) {
        return 0;
    }
    
    public void ClearCanvas(Canvas cvs) {
        if (cvs != null) {
            // Clear the canvas properly to ensure transparency
            cvs.drawColor(Color.TRANSPARENT, PorterDuff.Mode.CLEAR);
        }
    }
    
    private void drawDemoESP(Canvas canvas) {
        // Simple demo ESP - shows that the system is working
        if (canvas != null && mTextPaint != null) {
            mTextPaint.setColor(android.graphics.Color.GREEN);
            mTextPaint.setTextSize(30);
            canvas.drawText("ESP Ready", 50, 100, mTextPaint);
        }
    }

    public static Bitmap scale(Bitmap bitmap, int maxWidth, int maxHeight) {
        if (bitmap == null || bitmap.isRecycled()) {
            return null;
        }
        
        int width;
        int height;
        float widthRatio = (float) bitmap.getWidth() / maxWidth;
        float heightRatio = (float) bitmap.getHeight() / maxHeight;

        if (widthRatio >= heightRatio) {
            width = maxWidth;
            height = (int) (((float) width / bitmap.getWidth()) * bitmap.getHeight());
        } else {
            height = maxHeight;
            width = (int) (((float) height / bitmap.getHeight()) * bitmap.getWidth());
        }

        Bitmap scaledBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
        float ratioX = (float) width / bitmap.getWidth();
        float ratioY = (float) height / bitmap.getHeight();
        float middleX = width / 2.0f;
        float middleY = height / 2.0f;
        Matrix scaleMatrix = new Matrix();
        scaleMatrix.setScale(ratioX, ratioY, middleX, middleY);

        Canvas canvas = new Canvas(scaledBitmap);
        canvas.setMatrix(scaleMatrix);
        canvas.drawBitmap(bitmap, middleX - (float) bitmap.getWidth() / 2, middleY - (float) bitmap.getHeight() / 2, new Paint(Paint.FILTER_BITMAP_FLAG));
        return scaledBitmap;
    }

    public void setTargetFps(int fps) {
        mTargetFps = Math.max(1, Math.min(fps, 144)); // Clamp between 1-144 FPS
        
        // Sync with new optimization system
        if (fps >= TARGET_FPS_POWER_SAVE && fps <= TARGET_FPS_HIGH) {
            currentTargetFPS = fps;
            frameTime = 1000 / currentTargetFPS;
            Log.d(TAG, "Target FPS manually set to: " + currentTargetFPS);
        }
    }

    @Override
    public void run() {
        android.os.Process.setThreadPriority(android.os.Process.THREAD_PRIORITY_DISPLAY);
        Log.d(TAG, "ESP render thread started with dynamic FPS optimization");
        
        while (mRunning && !Thread.currentThread().isInterrupted()) {
            long frameStartTime = System.currentTimeMillis();
            
            try {
                // Skip frames if we're falling behind (adaptive frame skipping)
                if (frameSkipCount >= MAX_FRAME_SKIP) {
                    frameSkipCount = 0;
                    renderToSurface();
                } else if (System.currentTimeMillis() - lastFrameTime >= frameTime) {
                    frameSkipCount = 0;
                    renderToSurface();
                    lastFrameTime = System.currentTimeMillis();
                } else {
                    frameSkipCount++;
                    // Sleep briefly to avoid busy waiting
                    try {
                        Thread.sleep(1);
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                        break;
                    }
                    continue;
                }
                
                // Performance monitoring and adaptive FPS
                long frameEndTime = System.currentTimeMillis();
                long currentFrameTime = frameEndTime - frameStartTime;
                totalFrameTime += currentFrameTime;
                totalFrames++;
                
                // Adjust FPS based on performance every few seconds
                if (totalFrames > 0 && totalFrames % (currentTargetFPS * 3) == 0) { // Every 3 seconds
                    long averageFrameTime = totalFrameTime / totalFrames;
                    adjustFPSBasedOnPerformance(averageFrameTime);
                    monitorCPUUsage();
                    
                    // Reset counters to prevent overflow
                    if (totalFrames > 10000) {
                        totalFrameTime = averageFrameTime * 100; // Keep recent average
                        totalFrames = 100;
                    }
                }
                
                // Frame rate limiting with adaptive sleep
                long timeToSleep = frameTime - currentFrameTime;
                if (timeToSleep > 0) {
                    try {
                        Thread.sleep(timeToSleep);
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                        break;
                    }
                }
                
            } catch (Exception e) {
                Log.e(TAG, "Error in optimized render loop", e);
                
                // If we get repeated errors, reduce performance to try to recover
                if (currentTargetFPS > TARGET_FPS_POWER_SAVE) {
                    currentTargetFPS = TARGET_FPS_POWER_SAVE;
                    frameTime = 1000 / currentTargetFPS;
                    mTargetFps = currentTargetFPS; // Sync with old variable
                    Log.w(TAG, "Reducing FPS due to errors");
                }
                
                try {
                    Thread.sleep(100); // Brief pause on error
                } catch (InterruptedException ie) {
                    Thread.currentThread().interrupt();
                    break;
                }
            }
        }
        
        Log.d(TAG, "ESP render thread stopped");
    }
    
    /**
     * Optimized surface rendering method
     */
    private void renderToSurface() {
        if (!mRunning || getHolder() == null) {
            return;
        }

        Canvas canvas = null;
        try {
            canvas = getHolder().lockCanvas();
            if (canvas == null) {
                return;
            }

            // Clear canvas with optimized method
            canvas.drawColor(Color.TRANSPARENT, PorterDuff.Mode.CLEAR);
            
            // Call the optimized ESP drawing logic with performance monitoring
            if (this.getVisibility() == View.VISIBLE) {
                try {
                    // ESP drawing will be handled by native code when available
                    drawDemoESP(canvas);
                } catch (Exception e) {
                    Log.e(TAG, "Error in DrawOn during surface render", e);
                }
            }
            
        } catch (Exception e) {
            Log.e(TAG, "Error rendering to surface", e);
        } finally {
            if (canvas != null) {
                try {
                    getHolder().unlockCanvasAndPost(canvas);
                } catch (Exception e) {
                    Log.e(TAG, "Error posting canvas", e);
                }
            }
        }
    }

    @Override
    protected void onDetachedFromWindow() {
        super.onDetachedFromWindow();
        // Cleanup when view is detached
        stopRenderingThread();
        cleanupResources();
    }
    
    private void cleanupResources() {
        // Clean up bitmaps if they exist
        if (bitmap != null && !bitmap.isRecycled()) {
            bitmap.recycle();
            bitmap = null;
        }
        if (out != null && !out.isRecycled()) {
            out.recycle();
            out = null;
        }
        if (out2 != null && !out2.isRecycled()) {
            out2.recycle();
            out2 = null;
        }
        
        // Clean up bitmap array
        if (OTHER != null) {
            for (int i = 0; i < OTHER.length; i++) {
                if (OTHER[i] != null && !OTHER[i].isRecycled()) {
                    OTHER[i].recycle();
                    OTHER[i] = null;
                }
            }
        }
    }

    /**
     * Detect device performance level based on hardware specs
     */
    private void detectDevicePerformance() {
        try {
            // Get available processors
            int processors = Runtime.getRuntime().availableProcessors();
            
            // Get available memory
            long maxMemory = Runtime.getRuntime().maxMemory();
            long totalMemory = Runtime.getRuntime().totalMemory();
            long freeMemory = Runtime.getRuntime().freeMemory();
            
            // Simple heuristic based on CPU cores and memory
            if (processors >= 8 && maxMemory > 1024 * 1024 * 1024) { // 8+ cores, 1GB+ heap
                currentPerformanceLevel = PerformanceLevel.HIGH;
            } else if (processors >= 6 && maxMemory > 512 * 1024 * 1024) { // 6+ cores, 512MB+ heap
                currentPerformanceLevel = PerformanceLevel.MEDIUM;
            } else if (processors >= 4 && maxMemory > 256 * 1024 * 1024) { // 4+ cores, 256MB+ heap
                currentPerformanceLevel = PerformanceLevel.LOW;
            } else {
                currentPerformanceLevel = PerformanceLevel.POWER_SAVE;
            }
            
            android.util.Log.d("ESPView", "Detected performance level: " + currentPerformanceLevel + 
                " (Cores: " + processors + ", MaxMem: " + (maxMemory / 1024 / 1024) + "MB)");
                
        } catch (Exception e) {
            android.util.Log.w("ESPView", "Could not detect device performance, using default", e);
            currentPerformanceLevel = PerformanceLevel.MEDIUM;
        }
    }
    
    /**
     * Adjust FPS based on device performance level
     */
    private void adjustFPSBasedOnPerformance() {
        switch (currentPerformanceLevel) {
            case HIGH:
                currentTargetFPS = TARGET_FPS_HIGH; // 144 FPS for gaming phones
                break;
            case MEDIUM:
                currentTargetFPS = TARGET_FPS_MID; // 90 FPS for mid-range
                break;
            case LOW:
                currentTargetFPS = TARGET_FPS_LOW; // 60 FPS for budget phones
                break;
            case POWER_SAVE:
                currentTargetFPS = TARGET_FPS_POWER_SAVE; // 30 FPS for very low-end
                break;
        }
        
        frameTime = 1000 / currentTargetFPS;
        android.util.Log.d("ESPView", "Target FPS set to: " + currentTargetFPS);
    }
    
    /**
     * Dynamic FPS adjustment based on real-time performance
     */
    private void adjustFPSBasedOnPerformance(long averageFrameTime) {
        long currentTime = System.currentTimeMillis();
        
        // Only adjust every few seconds
        if (currentTime - lastPerformanceCheck < PERFORMANCE_CHECK_INTERVAL) {
            return;
        }
        lastPerformanceCheck = currentTime;
        
        // Check if we're dropping frames consistently
        if (averageFrameTime > frameTime * 2) {
            // Dropping frames, reduce FPS
            if (currentTargetFPS > TARGET_FPS_POWER_SAVE) {
                currentTargetFPS = Math.max(TARGET_FPS_POWER_SAVE, currentTargetFPS - 15);
                frameTime = 1000 / currentTargetFPS;
                android.util.Log.d("ESPView", "Reducing FPS to: " + currentTargetFPS + " due to frame drops");
            }
        } else if (averageFrameTime < frameTime * 0.7 && !isHighCpuUsage) {
            // Running smoothly and not using too much CPU, try to increase FPS
            int maxFPS = getMaxFPSForPerformanceLevel();
            if (currentTargetFPS < maxFPS) {
                currentTargetFPS = Math.min(maxFPS, currentTargetFPS + 15);
                frameTime = 1000 / currentTargetFPS;
                android.util.Log.d("ESPView", "Increasing FPS to: " + currentTargetFPS + " (smooth performance)");
            }
        }
    }
    
    /**
     * Get maximum FPS for current performance level
     */
    private int getMaxFPSForPerformanceLevel() {
        switch (currentPerformanceLevel) {
            case HIGH: return TARGET_FPS_HIGH;
            case MEDIUM: return TARGET_FPS_MID;
            case LOW: return TARGET_FPS_LOW;
            case POWER_SAVE: return TARGET_FPS_POWER_SAVE;
            default: return TARGET_FPS_LOW;
        }
    }
    
    /**
     * Monitor CPU usage and adjust performance accordingly
     */
    private void monitorCPUUsage() {
        long currentTime = System.currentTimeMillis();
        if (currentTime - lastCpuCheck < CPU_CHECK_INTERVAL) {
            return;
        }
        lastCpuCheck = currentTime;
        
        try {
            // Simple heuristic: if we're consistently taking longer than expected to render frames,
            // assume high CPU usage
            if (totalFrames > 0) {
                long averageFrameTime = totalFrameTime / totalFrames;
                boolean wasHighCpu = isHighCpuUsage;
                isHighCpuUsage = averageFrameTime > frameTime * 1.5;
                
                if (isHighCpuUsage && !wasHighCpu) {
                    android.util.Log.d("ESPView", "High CPU usage detected, enabling power saving mode");
                    if (currentTargetFPS > TARGET_FPS_POWER_SAVE) {
                        currentTargetFPS = TARGET_FPS_POWER_SAVE;
                        frameTime = 1000 / currentTargetFPS;
                    }
                } else if (!isHighCpuUsage && wasHighCpu) {
                    android.util.Log.d("ESPView", "CPU usage normalized, restoring performance");
                    adjustFPSBasedOnPerformance();
                }
            }
        } catch (Exception e) {
            android.util.Log.w("ESPView", "Error monitoring CPU usage", e);
        }
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        Log.d(TAG, "Surface created - starting render thread");
        startRenderingThread();
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        // Surface changed, no action needed for ESP
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        stopRenderingThread();
    }

    /**
     * Optimized rendering loop with dynamic FPS and memory management
     */
    private void renderLoop() {
        android.util.Log.d("ESPView", "ESP render loop started");
        
        while (mRunning) {
            long frameStartTime = System.currentTimeMillis();
            
            try {
                // Skip frames if we're falling behind
                if (frameSkipCount >= MAX_FRAME_SKIP) {
                    frameSkipCount = 0;
                    renderFrame();
                } else if (System.currentTimeMillis() - lastFrameTime >= frameTime) {
                    frameSkipCount = 0;
                    renderFrame();
                    lastFrameTime = System.currentTimeMillis();
                } else {
                    frameSkipCount++;
                    // Sleep briefly to avoid busy waiting
                    try {
                        Thread.sleep(1);
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                        break;
                    }
                    continue;
                }
                
                // Performance monitoring
                long frameEndTime = System.currentTimeMillis();
                long currentFrameTime = frameEndTime - frameStartTime;
                totalFrameTime += currentFrameTime;
                totalFrames++;
                
                // Adjust FPS based on performance every few seconds
                if (totalFrames > 0 && totalFrames % (currentTargetFPS * 3) == 0) { // Every 3 seconds
                    long averageFrameTime = totalFrameTime / totalFrames;
                    adjustFPSBasedOnPerformance(averageFrameTime);
                    monitorCPUUsage();
                    
                    // Reset counters to prevent overflow
                    if (totalFrames > 10000) {
                        totalFrameTime = averageFrameTime * 100; // Keep recent average
                        totalFrames = 100;
                    }
                }
                
                // Frame rate limiting with adaptive sleep
                long timeToSleep = frameTime - currentFrameTime;
                if (timeToSleep > 0) {
                    try {
                        Thread.sleep(timeToSleep);
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                        break;
                    }
                }
                
            } catch (Exception e) {
                android.util.Log.e("ESPView", "Error in render loop", e);
                
                // If we get repeated errors, reduce performance to try to recover
                if (currentTargetFPS > TARGET_FPS_POWER_SAVE) {
                    currentTargetFPS = TARGET_FPS_POWER_SAVE;
                    frameTime = 1000 / currentTargetFPS;
                    android.util.Log.w("ESPView", "Reducing FPS due to errors");
                }
                
                try {
                    Thread.sleep(100); // Brief pause on error
                } catch (InterruptedException ie) {
                    Thread.currentThread().interrupt();
                    break;
                }
            }
        }
        
        android.util.Log.d("ESPView", "ESP render loop stopped");
    }

    /**
     * Optimized frame rendering with memory management
     */
    private void renderFrame() {
        if (!mRunning || holder == null) {
            return;
        }

        try {
            surfaceCanvas = holder.lockCanvas();
            if (surfaceCanvas == null) {
                return;
            }

            // Clear canvas with optimized method
            surfaceCanvas.drawColor(Color.TRANSPARENT, PorterDuff.Mode.CLEAR);
            
            // Render ESP elements here
            // This is where you would add your ESP drawing code
            // For now, just drawing a simple indicator
            renderESPElements(surfaceCanvas);
            
        } catch (Exception e) {
            android.util.Log.e("ESPView", "Error rendering frame", e);
        } finally {
            if (surfaceCanvas != null) {
                try {
                    holder.unlockCanvasAndPost(surfaceCanvas);
                } catch (Exception e) {
                    android.util.Log.e("ESPView", "Error posting canvas", e);
                }
                surfaceCanvas = null;
            }
        }
    }
    
    /**
     * Render ESP elements (placeholder for actual ESP drawing)
     */
    private void renderESPElements(Canvas canvas) {
        // This is where you would implement your ESP drawing logic
        // For performance, use hardware acceleration when possible
        
        // Example: Draw a simple FPS indicator
        if (espPaint != null) {
            espPaint.setColor(Color.GREEN);
            espPaint.setTextSize(24);
            canvas.drawText("FPS: " + currentTargetFPS + " (" + currentPerformanceLevel + ")", 20, 50, espPaint);
        }
    }

    /**
     * Clean up resources
     */
    private void cleanup() {
        try {
            if (espPaint != null) {
                espPaint = null;
            }
            
            // Force garbage collection for better memory management
            if (totalFrames > 0) {
                android.util.Log.d("ESPView", "ESP performance stats - Total frames: " + totalFrames + 
                    ", Avg frame time: " + (totalFrameTime / totalFrames) + "ms, Final FPS: " + currentTargetFPS);
            }
            
            System.gc();
        } catch (Exception e) {
            android.util.Log.e("ESPView", "Error during cleanup", e);
        }
    }
    
    /**
     * Public method to manually adjust FPS (for settings)
     */
    public void setTargetFPS(int fps) {
        if (fps >= TARGET_FPS_POWER_SAVE && fps <= TARGET_FPS_HIGH) {
            currentTargetFPS = fps;
            frameTime = 1000 / currentTargetFPS;
            android.util.Log.d("ESPView", "Manual FPS set to: " + currentTargetFPS);
        }
    }
    
    /**
     * Get current performance statistics
     */
    public String getPerformanceStats() {
        if (totalFrames == 0) return "No performance data yet";
        
        long avgFrameTime = totalFrameTime / totalFrames;
        return String.format("FPS: %d, Avg Frame: %dms, Level: %s, Frames: %d", 
            currentTargetFPS, avgFrameTime, currentPerformanceLevel, totalFrames);
    }
    
    /**
     * Enable/disable power saving mode
     */
    public void setPowerSaveMode(boolean enabled) {
        if (enabled) {
            currentTargetFPS = TARGET_FPS_POWER_SAVE;
            currentPerformanceLevel = PerformanceLevel.POWER_SAVE;
        } else {
            detectDevicePerformance();
            adjustFPSBasedOnPerformance();
        }
        frameTime = 1000 / currentTargetFPS;
        android.util.Log.d("ESPView", "Power save mode: " + (enabled ? "enabled" : "disabled"));
    }
}
    
    
