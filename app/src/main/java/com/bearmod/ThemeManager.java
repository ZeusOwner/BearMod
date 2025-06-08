package com.bearmod;

import android.content.Context;
import android.content.res.ColorStateList;
import android.graphics.Color;
import android.graphics.drawable.GradientDrawable;
import android.util.Log;
import android.view.View;
import android.widget.Switch;
import android.widget.TextView;
import java.util.HashMap;
import java.util.Map;

/**
 * Modern Theme Manager for BearMod
 * Handles Material Design 3 theming and consistent styling
 */
public class ThemeManager {
    private static final String TAG = "BearMod_ThemeManager";
    
    private static volatile ThemeManager instance;
    private static final Object lock = new Object();
    
    private Context context;
    private final Map<String, Integer> colorCache = new HashMap<>();
    
    // Material Design 3 Color Tokens
    public static class Colors {
        // Primary Colors
        public static final int PRIMARY = Color.parseColor("#4CAF50");
        public static final int PRIMARY_VARIANT = Color.parseColor("#388E3C");
        public static final int ON_PRIMARY = Color.parseColor("#FFFFFF");
        
        // Secondary Colors
        public static final int SECONDARY = Color.parseColor("#2196F3");
        public static final int SECONDARY_VARIANT = Color.parseColor("#1976D2");
        public static final int ON_SECONDARY = Color.parseColor("#FFFFFF");
        
        // Background Colors
        public static final int BACKGROUND = Color.parseColor("#121212");
        public static final int SURFACE = Color.parseColor("#1E1E1E");
        public static final int SURFACE_VARIANT = Color.parseColor("#2A2A2A");
        public static final int ON_BACKGROUND = Color.parseColor("#FFFFFF");
        public static final int ON_SURFACE = Color.parseColor("#FFFFFF");
        
        // Error Colors
        public static final int ERROR = Color.parseColor("#F44336");
        public static final int ON_ERROR = Color.parseColor("#FFFFFF");
        
        // Outline Colors
        public static final int OUTLINE = Color.parseColor("#444444");
        public static final int OUTLINE_VARIANT = Color.parseColor("#333333");
        
        // BearMod Specific
        public static final int ACCENT = Color.parseColor("#FFD700");
        public static final int SUCCESS = Color.parseColor("#4CAF50");
        public static final int WARNING = Color.parseColor("#FF9800");
        public static final int DANGER = Color.parseColor("#F44336");
        public static final int INFO = Color.parseColor("#2196F3");
        
        // Text Colors
        public static final int TEXT_PRIMARY = Color.parseColor("#FFFFFF");
        public static final int TEXT_SECONDARY = Color.parseColor("#CCCCCC");
        public static final int TEXT_HINT = Color.parseColor("#888888");
        
        // Component Colors
        public static final int DIVIDER = Color.parseColor("#333333");
        public static final int CARD_BACKGROUND = Color.parseColor("#2A2A2A");
        public static final int SIDEBAR_BACKGROUND = Color.parseColor("#1E1E1E");
    }
    
    private ThemeManager(Context context) {
        this.context = context.getApplicationContext();
        initializeColorCache();
    }
    
    /**
     * Get singleton instance
     */
    public static ThemeManager getInstance(Context context) {
        if (instance == null) {
            synchronized (lock) {
                if (instance == null) {
                    instance = new ThemeManager(context);
                }
            }
        }
        return instance;
    }
    
    /**
     * Initialize color cache
     */
    private void initializeColorCache() {
        try {
            colorCache.put("primary", Colors.PRIMARY);
            colorCache.put("secondary", Colors.SECONDARY);
            colorCache.put("background", Colors.BACKGROUND);
            colorCache.put("surface", Colors.SURFACE);
            colorCache.put("error", Colors.ERROR);
            colorCache.put("accent", Colors.ACCENT);
            colorCache.put("success", Colors.SUCCESS);
            colorCache.put("warning", Colors.WARNING);
            colorCache.put("danger", Colors.DANGER);
            colorCache.put("info", Colors.INFO);
            
            Log.d(TAG, "Color cache initialized with " + colorCache.size() + " colors");
        } catch (Exception e) {
            Log.e(TAG, "Error initializing color cache", e);
        }
    }
    
    /**
     * Get color by name
     */
    public int getColor(String colorName) {
        Integer color = colorCache.get(colorName);
        return color != null ? color : Colors.PRIMARY;
    }
    
    /**
     * Create modern card background
     */
    public GradientDrawable createCardBackground() {
        return createCardBackground(Colors.CARD_BACKGROUND, 10);
    }
    
    /**
     * Create card background with custom color and radius
     */
    public GradientDrawable createCardBackground(int backgroundColor, int cornerRadius) {
        try {
            GradientDrawable drawable = new GradientDrawable();
            drawable.setColor(backgroundColor);
            drawable.setCornerRadius(dpToPx(cornerRadius));
            drawable.setStroke(dpToPx(1), Colors.OUTLINE);
            return drawable;
        } catch (Exception e) {
            Log.e(TAG, "Error creating card background", e);
            return new GradientDrawable();
        }
    }
    
    /**
     * Create modern button background
     */
    public GradientDrawable createButtonBackground(int backgroundColor, int strokeColor) {
        try {
            GradientDrawable drawable = new GradientDrawable();
            drawable.setColor(backgroundColor);
            drawable.setCornerRadius(dpToPx(8));
            drawable.setStroke(dpToPx(1), strokeColor);
            return drawable;
        } catch (Exception e) {
            Log.e(TAG, "Error creating button background", e);
            return new GradientDrawable();
        }
    }
    
    /**
     * Style a TextView with modern design
     */
    public void styleTextView(TextView textView, String style) {
        try {
            switch (style.toLowerCase()) {
                case "title":
                    textView.setTextColor(Colors.TEXT_PRIMARY);
                    textView.setTextSize(16);
                    textView.setTypeface(null, android.graphics.Typeface.BOLD);
                    break;
                case "subtitle":
                    textView.setTextColor(Colors.TEXT_SECONDARY);
                    textView.setTextSize(14);
                    textView.setTypeface(null, android.graphics.Typeface.NORMAL);
                    break;
                case "body":
                    textView.setTextColor(Colors.TEXT_PRIMARY);
                    textView.setTextSize(12);
                    textView.setTypeface(null, android.graphics.Typeface.NORMAL);
                    break;
                case "caption":
                    textView.setTextColor(Colors.TEXT_HINT);
                    textView.setTextSize(10);
                    textView.setTypeface(null, android.graphics.Typeface.NORMAL);
                    break;
                case "accent":
                    textView.setTextColor(Colors.ACCENT);
                    textView.setTextSize(14);
                    textView.setTypeface(null, android.graphics.Typeface.BOLD);
                    break;
                default:
                    textView.setTextColor(Colors.TEXT_PRIMARY);
                    textView.setTextSize(12);
                    break;
            }
        } catch (Exception e) {
            Log.e(TAG, "Error styling TextView", e);
        }
    }
    
    /**
     * Style a Switch with modern design
     */
    public void styleSwitch(Switch switchView) {
        try {
            ColorStateList thumbStates = new ColorStateList(
                new int[][]{
                    new int[]{android.R.attr.state_checked},
                    new int[]{}
                },
                new int[]{
                    Color.WHITE,
                    Color.parseColor("#CCCCCC")
                }
            );
            
            ColorStateList trackStates = new ColorStateList(
                new int[][]{
                    new int[]{android.R.attr.state_checked},
                    new int[]{}
                },
                new int[]{
                    Colors.PRIMARY,
                    Color.parseColor("#555555")
                }
            );
            
            switchView.setThumbTintList(thumbStates);
            switchView.setTrackTintList(trackStates);
            
        } catch (Exception e) {
            Log.e(TAG, "Error styling Switch", e);
        }
    }
    
    /**
     * Create section divider
     */
    public View createDivider() {
        try {
            View divider = new View(context);
            divider.setBackgroundColor(Colors.DIVIDER);
            return divider;
        } catch (Exception e) {
            Log.e(TAG, "Error creating divider", e);
            return new View(context);
        }
    }
    
    /**
     * Convert dp to pixels
     */
    public int dpToPx(int dp) {
        try {
            return Math.round(dp * context.getResources().getDisplayMetrics().density);
        } catch (Exception e) {
            Log.e(TAG, "Error converting dp to px", e);
            return dp;
        }
    }
    
    /**
     * Create status indicator background
     */
    public GradientDrawable createStatusBackground(String status) {
        try {
            GradientDrawable drawable = new GradientDrawable();
            drawable.setShape(GradientDrawable.OVAL);
            
            switch (status.toLowerCase()) {
                case "success":
                case "online":
                case "safe":
                    drawable.setColor(Colors.SUCCESS);
                    break;
                case "error":
                case "offline":
                case "danger":
                    drawable.setColor(Colors.ERROR);
                    break;
                case "warning":
                    drawable.setColor(Colors.WARNING);
                    break;
                case "info":
                    drawable.setColor(Colors.INFO);
                    break;
                default:
                    drawable.setColor(Colors.TEXT_HINT);
                    break;
            }
            
            return drawable;
        } catch (Exception e) {
            Log.e(TAG, "Error creating status background", e);
            return new GradientDrawable();
        }
    }
    
    /**
     * Get theme statistics for debugging
     */
    public Map<String, Object> getThemeStats() {
        Map<String, Object> stats = new HashMap<>();
        stats.put("colorCacheSize", colorCache.size());
        stats.put("primaryColor", String.format("#%06X", (0xFFFFFF & Colors.PRIMARY)));
        stats.put("backgroundColor", String.format("#%06X", (0xFFFFFF & Colors.BACKGROUND)));
        return stats;
    }
}
