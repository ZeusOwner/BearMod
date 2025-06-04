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

public class ESPView extends View implements Runnable {

    // Thread safety improvements
    private final AtomicBoolean isDestroyed = new AtomicBoolean(false);
    private final AtomicBoolean isRunning = new AtomicBoolean(false);
    private final Object drawLock = new Object();

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
            mTextPaint.setShadowLayer(3, 0, 0, Color.BLACK);
            mTextPaint.setColor(Color.rgb(r, g, b));
            mTextPaint.setTextSize(size);
            cvs.drawText(txt, posX, posY, mTextPaint);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
	
    public void NRG_DrawRect(Canvas cvs, int a, int r, int g, int b, float stroke, float x, float y, float width, float height) {
        try {
            mStrokePaint.setStrokeWidth(stroke);
            mStrokePaint.setColor(Color.rgb(r, g, b));
            mStrokePaint.setAlpha(a);
            cvs.drawRoundRect(new RectF(x, y, width, height), 5, 5, mStrokePaint);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void NRG_DrawCircle(Canvas cvs, int a, int r, int g, int b, float posX, float posY, float radius, float stroke) {
        try {
            mStrokePaint.setARGB(a, r, g, b);
            mStrokePaint.setStrokeWidth(stroke);
            cvs.drawCircle(posX, posY, radius, mStrokePaint);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public void NRG_DrawLine(Canvas cvs, int a, int r, int g, int b, float lineWidth, float fromX, float fromY, float toX, float toY) {
        try {
            mStrokePaint.setColor(Color.rgb(r, g, b));
            mStrokePaint.setAlpha(a);
            mStrokePaint.setStrokeWidth(lineWidth);
            cvs.drawLine(fromX, fromY, toX, toY, mStrokePaint);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public void NRG_DrawFilledRect(Canvas cvs, int a, int r, int g, int b, float x, float y, float width, float height) {
        try {
            mFilledPaint.setColor(Color.rgb(r, g, b));
            mFilledPaint.setAlpha(a);
            cvs.drawRoundRect(new RectF(x, y, width, height), 5, 5, mFilledPaint);
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
            // Optimized render loop with better frame pacing
            final long targetFrameTime = 1000L / 60L; // 60 FPS cap
            long lastFrameTime = SystemClock.uptimeMillis();
            
            while (isRunning.get() && !isDestroyed.get()) {
                try {
                    long currentTime = SystemClock.uptimeMillis();
                    long deltaTime = currentTime - lastFrameTime;
                    
                    // Only render if enough time has passed (frame rate limiting)
                    if (deltaTime >= targetFrameTime) {
                        post(() -> {
                            try {
                                if (!isDestroyed.get() && getVisibility() == View.VISIBLE) {
                                    invalidate();
                                }
                            } catch (Exception e) {
                                // Ignore rendering exceptions
                            }
                        });
                        lastFrameTime = currentTime;
                    }
                    
                    // Adaptive sleep to reduce CPU usage
                    long sleepTime = Math.max(1, targetFrameTime - (SystemClock.uptimeMillis() - currentTime));
                    Thread.sleep(sleepTime);
                    
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    break;
                } catch (Exception e) {
                    // Log and continue
                    e.printStackTrace();
                    try {
                        Thread.sleep(16); // Fallback sleep
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
    
    // Resource cleanup
    public void cleanup() {
        try {
            stopRenderThread();
            
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
    
    
