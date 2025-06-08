package com.bearmod;

import android.content.Context;
import android.content.SharedPreferences;
import android.content.res.Configuration;
import android.content.res.Resources;
import android.util.Log;
import java.util.Locale;
import java.util.concurrent.ConcurrentHashMap;
import java.util.Map;

/**
 * Modern Language Manager for BearMod
 * Handles language switching and string resource management
 */
public class LanguageManager {
    private static final String TAG = "BearMod_LanguageManager";
    private static final String PREFS_NAME = "BearMod_Language";
    private static final String KEY_LANGUAGE = "selected_language";
    
    // Language constants
    public static final int LANGUAGE_ENGLISH = 0;
    public static final int LANGUAGE_CHINESE = 1;
    
    private static volatile LanguageManager instance;
    private static final Object lock = new Object();
    
    private Context context;
    private SharedPreferences prefs;
    private int currentLanguage = LANGUAGE_ENGLISH;
    private final Map<String, String> stringCache = new ConcurrentHashMap<>();
    
    private LanguageManager(Context context) {
        this.context = context.getApplicationContext();
        this.prefs = context.getSharedPreferences(PREFS_NAME, Context.MODE_PRIVATE);
        loadSavedLanguage();
    }
    
    /**
     * Get singleton instance
     */
    public static LanguageManager getInstance(Context context) {
        if (instance == null) {
            synchronized (lock) {
                if (instance == null) {
                    instance = new LanguageManager(context);
                }
            }
        }
        return instance;
    }
    
    /**
     * Load saved language preference
     */
    private void loadSavedLanguage() {
        try {
            currentLanguage = prefs.getInt(KEY_LANGUAGE, LANGUAGE_ENGLISH);
            applyLanguage(currentLanguage);
            Log.d(TAG, "Loaded language: " + (currentLanguage == LANGUAGE_ENGLISH ? "English" : "Chinese"));
        } catch (Exception e) {
            Log.e(TAG, "Error loading saved language", e);
            currentLanguage = LANGUAGE_ENGLISH;
        }
    }
    
    /**
     * Set language and save preference
     */
    public void setLanguage(int language) {
        try {
            if (language != currentLanguage) {
                currentLanguage = language;
                prefs.edit().putInt(KEY_LANGUAGE, language).apply();
                applyLanguage(language);
                clearCache();
                Log.d(TAG, "Language changed to: " + (language == LANGUAGE_ENGLISH ? "English" : "Chinese"));
            }
        } catch (Exception e) {
            Log.e(TAG, "Error setting language", e);
        }
    }
    
    /**
     * Apply language to context
     */
    private void applyLanguage(int language) {
        try {
            Locale locale = (language == LANGUAGE_CHINESE) ? Locale.CHINESE : Locale.ENGLISH;
            
            Resources resources = context.getResources();
            Configuration config = resources.getConfiguration();
            config.setLocale(locale);
            
            // Update configuration
            context.createConfigurationContext(config);
            
        } catch (Exception e) {
            Log.e(TAG, "Error applying language", e);
        }
    }
    
    /**
     * Get current language
     */
    public int getCurrentLanguage() {
        return currentLanguage;
    }
    
    /**
     * Check if current language is Chinese
     */
    public boolean isChinese() {
        return currentLanguage == LANGUAGE_CHINESE;
    }
    
    /**
     * Toggle between English and Chinese
     */
    public void toggleLanguage() {
        setLanguage(currentLanguage == LANGUAGE_ENGLISH ? LANGUAGE_CHINESE : LANGUAGE_ENGLISH);
    }
    
    /**
     * Get string resource with fallback
     */
    public String getString(int resId) {
        try {
            String cacheKey = resId + "_" + currentLanguage;
            String cached = stringCache.get(cacheKey);
            if (cached != null) {
                return cached;
            }
            
            String result = context.getString(resId);
            stringCache.put(cacheKey, result);
            return result;
            
        } catch (Exception e) {
            Log.e(TAG, "Error getting string resource: " + resId, e);
            return "String not found";
        }
    }
    
    /**
     * Get string with fallback text (for compatibility with old system)
     */
    public String getString(String englishText, String chineseText) {
        try {
            return currentLanguage == LANGUAGE_CHINESE ? chineseText : englishText;
        } catch (Exception e) {
            Log.e(TAG, "Error getting fallback string", e);
            return englishText;
        }
    }
    
    /**
     * Get formatted string
     */
    public String getString(int resId, Object... formatArgs) {
        try {
            return String.format(getString(resId), formatArgs);
        } catch (Exception e) {
            Log.e(TAG, "Error formatting string: " + resId, e);
            return getString(resId);
        }
    }
    
    /**
     * Clear string cache
     */
    public void clearCache() {
        stringCache.clear();
        Log.d(TAG, "String cache cleared");
    }
    
    /**
     * Get language display name
     */
    public String getLanguageDisplayName() {
        return currentLanguage == LANGUAGE_CHINESE ? "中文" : "English";
    }
    
    /**
     * Get language display name for UI
     */
    public String getLanguageButtonText() {
        return getString("Language: English", "语言: 中文");
    }
    
    /**
     * Interface for language change listeners
     */
    public interface LanguageChangeListener {
        void onLanguageChanged(int newLanguage);
    }
    
    // Language change listeners
    private final Map<String, LanguageChangeListener> listeners = new ConcurrentHashMap<>();
    
    /**
     * Add language change listener
     */
    public void addLanguageChangeListener(String key, LanguageChangeListener listener) {
        listeners.put(key, listener);
    }
    
    /**
     * Remove language change listener
     */
    public void removeLanguageChangeListener(String key) {
        listeners.remove(key);
    }
    
    /**
     * Notify all listeners of language change
     */
    private void notifyLanguageChanged() {
        for (LanguageChangeListener listener : listeners.values()) {
            try {
                listener.onLanguageChanged(currentLanguage);
            } catch (Exception e) {
                Log.e(TAG, "Error notifying language change listener", e);
            }
        }
    }
    
    /**
     * Get language statistics for debugging
     */
    public Map<String, Object> getLanguageStats() {
        Map<String, Object> stats = new ConcurrentHashMap<>();
        stats.put("currentLanguage", currentLanguage);
        stats.put("languageName", getLanguageDisplayName());
        stats.put("cacheSize", stringCache.size());
        stats.put("listenersCount", listeners.size());
        return stats;
    }
}
