package com.bearmod;

import android.content.Context;
import android.graphics.Color;
import android.graphics.drawable.GradientDrawable;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CompoundButton;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.SeekBar;
import android.widget.Switch;
import android.widget.TextView;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

/**
 * Modern Menu Manager for BearMod
 * Uses Material Design 3 principles and proper language management
 */
public class ModernMenuManager implements LanguageManager.LanguageChangeListener {
    private static final String TAG = "BearMod_ModernMenuManager";
    
    private final Context context;
    private final LanguageManager languageManager;
    private final ThemeManager themeManager;
    
    // UI References
    private final List<TextView> textViews = new ArrayList<>();
    private final List<Switch> switches = new ArrayList<>();
    private final List<SeekBar> seekBars = new ArrayList<>();
    private final Map<String, View> componentCache = new ConcurrentHashMap<>();
    
    // Configuration interfaces
    public interface ConfigProvider {
        boolean getBoolean(String key);
        int getInteger(String key);
        void updateConfig(String key, Object value);
        void saveConfig();
    }
    
    public interface SwitchHandler {
        void onSwitch(int code);
    }
    
    private ConfigProvider configProvider;
    private SwitchHandler switchHandler;
    
    public ModernMenuManager(Context context) {
        this.context = context;
        this.languageManager = LanguageManager.getInstance(context);
        this.themeManager = ThemeManager.getInstance(context);
        
        // Register for language changes
        languageManager.addLanguageChangeListener("ModernMenuManager", this);
        
        Log.d(TAG, "ModernMenuManager initialized");
    }
    
    /**
     * Set configuration provider
     */
    public void setConfigProvider(ConfigProvider provider) {
        this.configProvider = provider;
    }
    
    /**
     * Set switch handler
     */
    public void setSwitchHandler(SwitchHandler handler) {
        this.switchHandler = handler;
    }
    
    /**
     * Create modern section title
     */
    public TextView createSectionTitle(String titleKey) {
        try {
            TextView title = new TextView(context);
            title.setText(languageManager.getString(R.string.class.getField(titleKey).getInt(null)));
            themeManager.styleTextView(title, "title");
            title.setPadding(
                themeManager.dpToPx(12), 
                themeManager.dpToPx(16), 
                themeManager.dpToPx(12), 
                themeManager.dpToPx(8)
            );
            
            textViews.add(title);
            return title;
        } catch (Exception e) {
            Log.e(TAG, "Error creating section title", e);
            TextView fallback = new TextView(context);
            fallback.setText(titleKey);
            themeManager.styleTextView(fallback, "title");
            return fallback;
        }
    }
    
    /**
     * Create modern switch with proper styling
     */
    public LinearLayout createModernSwitch(String labelKey, String configKey, int switchCode) {
        try {
            LinearLayout container = new LinearLayout(context);
            container.setOrientation(LinearLayout.HORIZONTAL);
            container.setLayoutParams(new LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT, 
                ViewGroup.LayoutParams.WRAP_CONTENT
            ));
            container.setPadding(
                themeManager.dpToPx(12), 
                themeManager.dpToPx(8), 
                themeManager.dpToPx(12), 
                themeManager.dpToPx(8)
            );
            container.setGravity(Gravity.CENTER_VERTICAL);
            
            // Create label
            TextView label = new TextView(context);
            try {
                label.setText(languageManager.getString(R.string.class.getField(labelKey).getInt(null)));
            } catch (Exception e) {
                label.setText(labelKey);
            }
            themeManager.styleTextView(label, "body");
            
            LinearLayout.LayoutParams labelParams = new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT);
            labelParams.weight = 1;
            label.setLayoutParams(labelParams);
            
            // Create switch
            Switch switchView = new Switch(context);
            if (configProvider != null) {
                switchView.setChecked(configProvider.getBoolean(configKey));
            }
            themeManager.styleSwitch(switchView);
            
            switchView.setOnCheckedChangeListener((buttonView, isChecked) -> {
                try {
                    if (configProvider != null) {
                        configProvider.updateConfig(configKey, isChecked ? 1 : 0);
                    }
                    if (switchHandler != null) {
                        switchHandler.onSwitch(switchCode);
                    }
                } catch (Exception e) {
                    Log.e(TAG, "Error handling switch change", e);
                }
            });
            
            container.addView(label);
            container.addView(switchView);
            
            // Add to tracking lists
            textViews.add(label);
            switches.add(switchView);
            componentCache.put(configKey, container);
            
            return container;
        } catch (Exception e) {
            Log.e(TAG, "Error creating modern switch", e);
            return new LinearLayout(context);
        }
    }
    
    /**
     * Create modern seek bar with proper styling
     */
    public LinearLayout createModernSeekBar(String labelKey, String configKey, int min, int max, SeekBarChangeListener listener) {
        try {
            LinearLayout container = new LinearLayout(context);
            container.setOrientation(LinearLayout.VERTICAL);
            container.setLayoutParams(new LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT, 
                ViewGroup.LayoutParams.WRAP_CONTENT
            ));
            container.setPadding(
                themeManager.dpToPx(12), 
                themeManager.dpToPx(8), 
                themeManager.dpToPx(12), 
                themeManager.dpToPx(8)
            );
            
            // Create label with value
            TextView label = new TextView(context);
            int currentValue = configProvider != null ? configProvider.getInteger(configKey) : min;
            try {
                String labelText = languageManager.getString(R.string.class.getField(labelKey).getInt(null));
                label.setText(labelText + ": " + currentValue);
            } catch (Exception e) {
                label.setText(labelKey + ": " + currentValue);
            }
            themeManager.styleTextView(label, "body");
            
            // Create seek bar
            SeekBar seekBar = new SeekBar(context);
            seekBar.setMax(max - min);
            seekBar.setProgress(currentValue - min);
            
            seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
                @Override
                public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                    if (fromUser) {
                        int value = progress + min;
                        try {
                            String labelText = languageManager.getString(R.string.class.getField(labelKey).getInt(null));
                            label.setText(labelText + ": " + value);
                        } catch (Exception e) {
                            label.setText(labelKey + ": " + value);
                        }
                        
                        if (configProvider != null) {
                            configProvider.updateConfig(configKey, value);
                        }
                        if (listener != null) {
                            listener.onProgressChanged(value);
                        }
                    }
                }
                
                @Override
                public void onStartTrackingTouch(SeekBar seekBar) {}
                
                @Override
                public void onStopTrackingTouch(SeekBar seekBar) {}
            });
            
            container.addView(label);
            container.addView(seekBar);
            
            // Add to tracking lists
            textViews.add(label);
            seekBars.add(seekBar);
            componentCache.put(configKey, container);
            
            return container;
        } catch (Exception e) {
            Log.e(TAG, "Error creating modern seek bar", e);
            return new LinearLayout(context);
        }
    }
    
    /**
     * Create modern radio button group
     */
    public RadioGroup createModernRadioGroup(String[] optionKeys, String configKey, RadioGroupChangeListener listener) {
        try {
            RadioGroup radioGroup = new RadioGroup(context);
            radioGroup.setOrientation(RadioGroup.HORIZONTAL);
            radioGroup.setLayoutParams(new LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT, 
                ViewGroup.LayoutParams.WRAP_CONTENT
            ));
            radioGroup.setPadding(
                themeManager.dpToPx(12), 
                themeManager.dpToPx(8), 
                themeManager.dpToPx(12), 
                themeManager.dpToPx(8)
            );
            
            int currentValue = configProvider != null ? configProvider.getInteger(configKey) : 0;
            
            for (int i = 0; i < optionKeys.length; i++) {
                RadioButton radioButton = new RadioButton(context);
                try {
                    radioButton.setText(languageManager.getString(R.string.class.getField(optionKeys[i]).getInt(null)));
                } catch (Exception e) {
                    radioButton.setText(optionKeys[i]);
                }
                radioButton.setTextColor(ThemeManager.Colors.TEXT_PRIMARY);
                radioButton.setId(i);
                
                if (i == currentValue) {
                    radioButton.setChecked(true);
                }
                
                radioGroup.addView(radioButton);
                textViews.add(radioButton);
            }
            
            radioGroup.setOnCheckedChangeListener((group, checkedId) -> {
                try {
                    if (configProvider != null) {
                        configProvider.updateConfig(configKey, checkedId);
                    }
                    if (listener != null) {
                        listener.onSelectionChanged(checkedId);
                    }
                } catch (Exception e) {
                    Log.e(TAG, "Error handling radio group change", e);
                }
            });
            
            componentCache.put(configKey, radioGroup);
            return radioGroup;
        } catch (Exception e) {
            Log.e(TAG, "Error creating modern radio group", e);
            return new RadioGroup(context);
        }
    }
    
    /**
     * Create modern card container
     */
    public LinearLayout createCard() {
        LinearLayout card = new LinearLayout(context);
        card.setOrientation(LinearLayout.VERTICAL);
        card.setLayoutParams(new LinearLayout.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT, 
            ViewGroup.LayoutParams.WRAP_CONTENT
        ));
        card.setPadding(
            themeManager.dpToPx(12), 
            themeManager.dpToPx(8), 
            themeManager.dpToPx(12), 
            themeManager.dpToPx(8)
        );
        card.setBackground(themeManager.createCardBackground());
        
        LinearLayout.LayoutParams cardParams = (LinearLayout.LayoutParams) card.getLayoutParams();
        cardParams.setMargins(0, themeManager.dpToPx(4), 0, themeManager.dpToPx(4));
        card.setLayoutParams(cardParams);
        
        return card;
    }
    
    @Override
    public void onLanguageChanged(int newLanguage) {
        try {
            refreshAllText();
            Log.d(TAG, "UI refreshed for language change: " + newLanguage);
        } catch (Exception e) {
            Log.e(TAG, "Error refreshing UI for language change", e);
        }
    }
    
    /**
     * Refresh all text elements
     */
    private void refreshAllText() {
        // This would need to be implemented based on specific UI structure
        // For now, we'll just log that refresh is needed
        Log.d(TAG, "Text refresh requested - " + textViews.size() + " text views to update");
    }
    
    /**
     * Cleanup resources
     */
    public void cleanup() {
        try {
            languageManager.removeLanguageChangeListener("ModernMenuManager");
            textViews.clear();
            switches.clear();
            seekBars.clear();
            componentCache.clear();
            Log.d(TAG, "ModernMenuManager cleaned up");
        } catch (Exception e) {
            Log.e(TAG, "Error during cleanup", e);
        }
    }
    
    // Listener interfaces
    public interface SeekBarChangeListener {
        void onProgressChanged(int value);
    }
    
    public interface RadioGroupChangeListener {
        void onSelectionChanged(int selectedIndex);
    }
}
