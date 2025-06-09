package com.bearmod;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Bitmap;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.os.SystemClock;
import android.os.Build;
import android.view.View;
import android.graphics.Matrix;
import android.graphics.RectF;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.Random;
import java.util.Map;

public class ESPView extends View implements Runnable {

    // Thread safety improvements
    private final AtomicBoolean isDestroyed = new AtomicBoolean(false);
    private final AtomicBoolean isRunning = new AtomicBoolean(false);
    private final Object drawLock = new Object();

    // Enhanced anti-detection system
    private ESPAntiDetection antiDetection;
    private RecorderFakeUtils recorderUtils;
    private final Random secureRandom = new Random();

    private volatile int mFPS = 0;
    private volatile int mFPSCounter = 0;
    private volatile long mFPSTime = 0;
  
    Paint p;
    Bitmap bitmap;
    Bitmap out;
    Bitmap out2;
    Paint mStrokePaint;
    Paint mTextPaint;
    Paint mFilledPaint;
    
    private volatile Thread mThread;
    
    int screenWidth, screenHeight;
    Bitmap[] OTHER = new Bitmap[4];
    
    // Memory management improvements
    private volatile boolean isPaused = false;
    private static final int MAX_FPS_SAMPLES = 10;
    private final long[] fpsHistory = new long[MAX_FPS_SAMPLES];
    private int fpsHistoryIndex = 0;
    
    public ESPView(Context context) {
        super(context, null, 0);

        try {
            // Initialize anti-detection system
            antiDetection = ESPAntiDetection.getInstance();
            recorderUtils = new RecorderFakeUtils(context);

            // Set up integration
            try {
                MemoryScrambler memScrambler = MemoryScrambler.getInstance();
                LanguageManager langManager = LanguageManager.getInstance(context);
                antiDetection.setIntegrationComponents(memScrambler, recorderUtils, langManager);
            } catch (Exception e) {
                // Graceful fallback if components not available
            }

            InitializePaints();

            // LAG FIX / full smooth - Android 10+ compatible
            setFocusableInTouchMode(false);
            setEnabled(false);
            setFitsSystemWindows(false);
            setHapticFeedbackEnabled(false);
            setFocusable(false);
            
            // API level checks for newer methods
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) { // Android 8.0+
                setFocusedByDefault(false);
            }
            
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.Q) { // Android 10+
                setForceDarkAllowed(false);
            }
            
            setHovered(false);
            setKeepScreenOn(false);
            
            // Remove setAutoHandwritingEnabled() - it's Android 14+ only and causes crashes
            // setAutoHandwritingEnabled(false); // REMOVED - causes crashes on Android 10-13
            
            setActivated(false);
            setBackgroundColor(Color.TRANSPARENT);
            
            // Start thread safely
            startRenderThread();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    private void startRenderThread() {
        try {
            if (mThread == null || !mThread.isAlive()) {
                isRunning.set(true);
                mThread = new Thread(this, "ESPView-Render");
                mThread.setDaemon(true);
                mThread.start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public void stopRenderThread() {
        try {
            isRunning.set(false);
            isDestroyed.set(true);
            if (mThread != null && mThread.isAlive()) {
                mThread.interrupt();
                try {
                    mThread.join(1000); // Wait up to 1 second for thread to finish
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void InitializePaints() {
        try {
            // Reuse existing paints if available to reduce allocations
            if (mStrokePaint == null) {
                mStrokePaint = new Paint(Paint.ANTI_ALIAS_FLAG);
                mStrokePaint.setStyle(Paint.Style.STROKE);
                mStrokePaint.setColor(Color.rgb(0, 0, 0));
            }
            
            if (mFilledPaint == null) {
                mFilledPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
                mFilledPaint.setStyle(Paint.Style.FILL);
                mFilledPaint.setColor(Color.rgb(0, 0, 0));
            }
            
            if (mTextPaint == null) {
                mTextPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
                mTextPaint.setStyle(Paint.Style.FILL_AND_STROKE);
                mTextPaint.setColor(Color.rgb(0, 0, 0));
                mTextPaint.setTextAlign(Paint.Align.CENTER);
                mTextPaint.setStrokeWidth(1.1f);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    @Override
    protected void onDraw(Canvas canvas) {
        try {
            if (canvas != null && this.getVisibility() == View.VISIBLE && !isDestroyed.get() && !isPaused) {
                // Enhanced anti-detection check
                if (!antiDetection.shouldRender()) {
                    return; // Skip rendering for anti-detection
                }

                // Check recording protection
                if (recorderUtils != null && recorderUtils.isRecordingDetected()) {
                    this.ClearCanvas(canvas); // Clear canvas during recording
                    return;
                }

                synchronized (drawLock) {
                    this.ClearCanvas(canvas);
                    Floating.DrawOn(this, canvas);

                    // Update FPS with smoothing
                    updateFPS();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    @Override
    protected void onDetachedFromWindow() {
        super.onDetachedFromWindow();
        stopRenderThread();
    }
             
    public void DrawText5(Canvas canvas, int n, int n2, int n3, int n4, float f, String string2, float f2, float f3, float f4) {
        try {
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
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
             
    public void NRG_DrawText(Canvas cvs, int a, int r, int g, int b, String txt, float posX, float posY, float size) {
        try {
            // Enhanced anti-detection text drawing
            mTextPaint.setShadowLayer(3, 0, 0, Color.BLACK);
            mTextPaint.setColor(Color.rgb(r, g, b));
            mTextPaint.setTextSize(size);

            // Use anti-detection system for secure drawing
            antiDetection.drawTextSecure(cvs, mTextPaint, txt, posX, posY, size);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
	
    public void NRG_DrawRect(Canvas cvs, int a, int r, int g, int b, float stroke, float x, float y, float width, float height) {
        try {
            mStrokePaint.setStrokeWidth(stroke);
            mStrokePaint.setColor(Color.rgb(r, g, b));
            mStrokePaint.setAlpha(a);

            // Use anti-detection system for secure rectangle drawing
            antiDetection.drawRectSecure(cvs, mStrokePaint, x, y, width - x, height - y);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void NRG_DrawCircle(Canvas cvs, int a, int r, int g, int b, float posX, float posY, float radius, float stroke) {
        try {
            mStrokePaint.setARGB(a, r, g, b);
            mStrokePaint.setStrokeWidth(stroke);

            // Use anti-detection system for secure circle drawing
            antiDetection.drawCircleSecure(cvs, mStrokePaint, posX, posY, radius);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public void NRG_DrawLine(Canvas cvs, int a, int r, int g, int b, float lineWidth, float fromX, float fromY, float toX, float toY) {
        try {
            mStrokePaint.setColor(Color.rgb(r, g, b));
            mStrokePaint.setAlpha(a);
            mStrokePaint.setStrokeWidth(lineWidth);

            // Use anti-detection system for secure line drawing
            antiDetection.drawLineSecure(cvs, mStrokePaint, fromX, fromY, toX, toY);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public void NRG_DrawFilledRect(Canvas cvs, int a, int r, int g, int b, float x, float y, float width, float height) {
        try {
            mFilledPaint.setColor(Color.rgb(r, g, b));
            mFilledPaint.setAlpha(a);

            // Use anti-detection system for secure filled rectangle drawing
            antiDetection.drawRectSecure(cvs, mFilledPaint, x, y, width - x, height - y);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public void DrawRect(Canvas cvs, int a, int r, int g, int b, float stroke, float x, float y, float width, float height) {
        try {
            mStrokePaint.setStrokeWidth(stroke);
            mStrokePaint.setColor(Color.rgb(r, g, b));
            mStrokePaint.setAlpha(a);
            cvs.drawRoundRect(new RectF(x, y, width, height), 5, 5, mStrokePaint);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    private int getWeaponIcon(int id) {
        return 0;
    }
     
    public void ClearCanvas(Canvas cvs) {
        try {
            cvs.drawColor(Color.TRANSPARENT, PorterDuff.Mode.CLEAR);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static Bitmap scale(Bitmap bitmap, int maxWidth, int maxHeight) {
        try {
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
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    @Override
    public void run() {
        try {
            // Enhanced render loop with dynamic frame rate and anti-detection
            long lastFrameTime = SystemClock.uptimeMillis();
            long frameCount = 0;

            while (isRunning.get() && !isDestroyed.get()) {
                try {
                    long currentTime = SystemClock.uptimeMillis();

                    // Get dynamic frame rate from anti-detection system
                    Map<String, Object> stats = antiDetection.getAntiDetectionStats();
                    int dynamicFPS = (Integer) stats.getOrDefault("dynamicFPS", 60);
                    long targetFrameTime = 1000L / dynamicFPS;

                    long deltaTime = currentTime - lastFrameTime;

                    // Anti-detection frame rate limiting with jitter
                    if (deltaTime >= targetFrameTime) {
                        // Add random jitter to prevent timing pattern detection
                        long jitter = secureRandom.nextInt(5); // 0-5ms jitter

                        if (deltaTime >= targetFrameTime + jitter) {
                            post(() -> {
                                try {
                                    if (!isDestroyed.get() && getVisibility() == View.VISIBLE) {
                                        // Check anti-detection before invalidating
                                        if (antiDetection.shouldRender()) {
                                            invalidate();
                                        }
                                    }
                                } catch (Exception e) {
                                    // Ignore rendering exceptions
                                }
                            });
                            lastFrameTime = currentTime;
                            frameCount++;
                        }
                    }

                    // Adaptive sleep with randomization to prevent CPU usage patterns
                    long baseSleepTime = Math.max(1, targetFrameTime - (SystemClock.uptimeMillis() - currentTime));
                    long randomSleep = secureRandom.nextInt(3); // 0-2ms additional randomization
                    long sleepTime = baseSleepTime + randomSleep;

                    Thread.sleep(sleepTime);

                    // Periodically clear operation history for security
                    if (frameCount % 1800 == 0) { // Every ~30 seconds at 60 FPS
                        antiDetection.clearOperationHistory();
                    }

                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    break;
                } catch (Exception e) {
                    // Log and continue with fallback
                    e.printStackTrace();
                    try {
                        // Fallback sleep with randomization
                        int fallbackSleep = 16 + secureRandom.nextInt(8); // 16-24ms
                        Thread.sleep(fallbackSleep);
                    } catch (InterruptedException ie) {
                        Thread.currentThread().interrupt();
                        break;
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void updateFPS() {
        try {
            long currentTime = SystemClock.uptimeMillis();
            fpsHistory[fpsHistoryIndex] = currentTime;
            fpsHistoryIndex = (fpsHistoryIndex + 1) % MAX_FPS_SAMPLES;
            
            // Calculate average FPS over last samples
            if (fpsHistoryIndex == 0) {
                long timeDiff = fpsHistory[MAX_FPS_SAMPLES - 1] - fpsHistory[0];
                if (timeDiff > 0) {
                    mFPS = (int) (MAX_FPS_SAMPLES * 1000L / timeDiff);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    // Enhanced resource cleanup with anti-detection
    public void cleanup() {
        try {
            stopRenderThread();

            // Clean up anti-detection system
            if (antiDetection != null) {
                antiDetection.clearOperationHistory();
            }

            // Clean up bitmaps
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

            // Clean up OTHER bitmaps array
            for (int i = 0; i < OTHER.length; i++) {
                if (OTHER[i] != null && !OTHER[i].isRecycled()) {
                    OTHER[i].recycle();
                    OTHER[i] = null;
                }
            }

            // Clear references for security
            antiDetection = null;
            recorderUtils = null;

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Get ESP anti-detection statistics
     */
    public Map<String, Object> getESPStats() {
        try {
            if (antiDetection != null) {
                return antiDetection.getAntiDetectionStats();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return new java.util.HashMap<>();
    }

    /**
     * Enable/disable randomized shapes for anti-detection
     */
    public void setRandomizedShapes(boolean enabled) {
        try {
            if (antiDetection != null) {
                antiDetection.setRandomizedShapes(enabled);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void onPause() {
        isPaused = true;
        // Reduce rendering when not visible
    }
    
    public void onResume() {
        isPaused = false;
    }
}
    
    
