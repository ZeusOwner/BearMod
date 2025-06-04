package com.bearmod;

import android.content.Context;
import android.graphics.Color;
import android.graphics.drawable.GradientDrawable;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.RadioGroup;
import android.widget.CompoundButton;
import android.widget.Switch;
import android.widget.SeekBar;
import android.widget.RelativeLayout;
import android.widget.ScrollView;
import android.widget.RadioButton;
import android.content.res.ColorStateList;
import android.widget.ImageView;
import android.os.Handler;
import android.os.Looper;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

public class MenuManager {
    private final Context context;
    private final LinearLayout[] pageLayouts;
    private final String[] listTab;
    private int lastSelectedPage = 0;
    private TextView textTitle;
    private LinearLayout contentLayout;

    // Store references for efficient updates
    private LinearLayout sidebarRef = null;
    private LinearLayout menuContainerRef = null;

    // Add a public field for the sidebar header
    public LinearLayout sidebarHeaderRef = null;

    // Add context reference for RecorderFakeUtils
    private Context contextRef;
    
    // Store all UI elements that need translation updates
    private TextView mainWelcomeTitle;
    private TextView mainAppTitle;
    private TextView mainAppDesc;
    private TextView mainQuickActionsTitle;
    private TextView mainLanguageTitle;
    private TextView mainSettingsTitle;
    private TextView mainStatusInfo;
    private TextView languageToggleBtn;
    private TextView saveSettingsBtn;
    private TextView resetSettingsBtn;
    private TextView clearCacheBtn;

    // Performance improvements - View recycling and caching
    private final Map<String, View> viewCache = new HashMap<>();
    private final List<TextView> recycledTextViews = new ArrayList<>();
    private final List<Switch> recycledSwitches = new ArrayList<>();
    private final List<SeekBar> recycledSeekBars = new ArrayList<>();
    
    // Memory optimization - Reuse views when possible
    private TextView getRecycledTextView() {
        if (!recycledTextViews.isEmpty()) {
            return recycledTextViews.remove(recycledTextViews.size() - 1);
        }
        return new TextView(context);
    }
    
    private Switch getRecycledSwitch() {
        if (!recycledSwitches.isEmpty()) {
            return recycledSwitches.remove(recycledSwitches.size() - 1);
        }
        return new Switch(context);
    }
    
    private SeekBar getRecycledSeekBar() {
        if (!recycledSeekBars.isEmpty()) {
            return recycledSeekBars.remove(recycledSeekBars.size() - 1);
        }
        return new SeekBar(context);
    }
    
    // Cleanup method for view recycling
    public void recycleViews() {
        try {
            // Clear existing recycled views
            recycledTextViews.clear();
            recycledSwitches.clear();
            recycledSeekBars.clear();
            viewCache.clear();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public MenuManager(Context context, String[] listTab, LinearLayout[] pageLayouts, LinearLayout contentLayout, TextView textTitle) {
        this.context = context;
        this.listTab = listTab;
        this.pageLayouts = pageLayouts;
        this.contentLayout = contentLayout;
        this.textTitle = textTitle;
        this.contextRef = context; // Store context reference for RecorderFakeUtils
    }

    // Example: create the sidebar (to be expanded)
    public LinearLayout createSidebar() {
        LinearLayout sidebar = new LinearLayout(context);
        sidebar.setOrientation(LinearLayout.VERTICAL);
        sidebar.setLayoutParams(new LinearLayout.LayoutParams(dpToPx(120), ViewGroup.LayoutParams.MATCH_PARENT));
        sidebar.setPadding(dpToPx(6), dpToPx(6), dpToPx(3), dpToPx(6));
        GradientDrawable sidebarBg = new GradientDrawable();
        sidebarBg.setColor(Color.parseColor("#1e1e1e"));
        sidebarBg.setCornerRadii(new float[]{dpToPx(10), dpToPx(10), 0, 0, 0, 0, dpToPx(10), dpToPx(10)});
        sidebar.setBackground(sidebarBg);
        // Add header, navigation, footer here...
        return sidebar;
    }

    // Utility method for dp to px
    private int dpToPx(int i) {
        return Math.round(i * context.getResources().getDisplayMetrics().density);
    }

    // --- Sidebar and Navigation Logic ---
    public void createSidebar(LinearLayout mainLayout, RelativeLayout iconLayout, Runnable onClose) {
        try {
            LinearLayout sidebar = new LinearLayout(context);
            sidebar.setOrientation(LinearLayout.VERTICAL);
            sidebar.setLayoutParams(new LinearLayout.LayoutParams(dpToPx(140), ViewGroup.LayoutParams.MATCH_PARENT));
            sidebar.setPadding(dpToPx(6), dpToPx(6), dpToPx(3), dpToPx(6));

            GradientDrawable sidebarBg = new GradientDrawable();
            sidebarBg.setColor(Color.parseColor("#1e1e1e"));
            sidebarBg.setCornerRadii(new float[]{dpToPx(10), dpToPx(10), 0, 0, 0, 0, dpToPx(10), dpToPx(10)});
            sidebar.setBackground(sidebarBg);

            createSidebarHeader(sidebar, mainLayout, iconLayout, onClose);
            createNavigationMenu(sidebar);
            createSidebarFooter(sidebar);

            mainLayout.addView(sidebar);
            sidebarRef = sidebar;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void createSidebarHeader(LinearLayout sidebar, LinearLayout mainLayout, RelativeLayout iconLayout, Runnable onClose) {
        try {
            LinearLayout headerContainer = new LinearLayout(context);
            headerContainer.setOrientation(LinearLayout.HORIZONTAL);
            headerContainer.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
            headerContainer.setPadding(dpToPx(6), dpToPx(8), dpToPx(6), dpToPx(8));
            headerContainer.setGravity(Gravity.CENTER_VERTICAL);

            textTitle = new TextView(context);
            textTitle.setText("BEAR-MOD"); // Language handled elsewhere
            textTitle.setTextColor(Color.WHITE);
            textTitle.setTextSize(14);
            textTitle.setTypeface(null, android.graphics.Typeface.BOLD);
            LinearLayout.LayoutParams titleParams = new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT);
            titleParams.weight = 1;
            textTitle.setLayoutParams(titleParams);

            TextView closeBtn = new TextView(context);
            closeBtn.setText("×");
            closeBtn.setTextColor(Color.parseColor("#FF5252"));
            closeBtn.setTextSize(16);
            closeBtn.setGravity(Gravity.CENTER);
            closeBtn.setLayoutParams(new LinearLayout.LayoutParams(dpToPx(20), dpToPx(20)));
            GradientDrawable closeBg = new GradientDrawable();
            closeBg.setShape(GradientDrawable.OVAL);
            closeBg.setColor(Color.parseColor("#33FF5252"));
            closeBtn.setBackground(closeBg);
            closeBtn.setOnClickListener(v -> {
                if (onClose != null) onClose.run();
                if (mainLayout != null) mainLayout.setVisibility(View.GONE);
                if (iconLayout != null) iconLayout.setVisibility(View.VISIBLE);
            });

            headerContainer.addView(textTitle);
            headerContainer.addView(closeBtn);
            sidebar.addView(headerContainer);
            sidebarHeaderRef = headerContainer;

            View divider = new View(context);
            divider.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, dpToPx(1)));
            divider.setBackgroundColor(Color.parseColor("#333333"));
            LinearLayout.LayoutParams dividerParams = (LinearLayout.LayoutParams) divider.getLayoutParams();
            dividerParams.setMargins(dpToPx(6), dpToPx(3), dpToPx(6), dpToPx(6));
            divider.setLayoutParams(dividerParams);
            sidebar.addView(divider);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void createNavigationMenu(LinearLayout sidebar) {
        try {
            LinearLayout menuContainer = new LinearLayout(context);
            menuContainer.setOrientation(LinearLayout.VERTICAL);
            LinearLayout.LayoutParams menuParams = new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, 0);
            menuParams.weight = 1;
            menuContainer.setLayoutParams(menuParams);
            menuContainer.setPadding(dpToPx(6), dpToPx(2), dpToPx(6), dpToPx(2));

            String[] menuItems = listTab;
            for (int i = 0; i < menuItems.length; i++) {
                LinearLayout menuBtn = createModernMenuButton(menuItems[i], i);
                menuContainer.addView(menuBtn);
                if (i < menuItems.length - 1) {
                    View spacing = new View(context);
                    spacing.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, dpToPx(1)));
                    menuContainer.addView(spacing);
                }
            }
            sidebar.addView(menuContainer);
            // Store reference for updates
            menuContainerRef = menuContainer;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private LinearLayout createModernMenuButton(String text, int index) {
        try {
            LinearLayout buttonContainer = new LinearLayout(context);
            buttonContainer.setOrientation(LinearLayout.HORIZONTAL);
            buttonContainer.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
            buttonContainer.setPadding(dpToPx(4), dpToPx(6), dpToPx(4), dpToPx(6));
            buttonContainer.setGravity(Gravity.CENTER_VERTICAL);

            // Add icon
            ImageView iconView = new ImageView(context);
            int iconRes = 0;
            switch (index) {
                case 0: iconRes = context.getResources().getIdentifier("ic_tab_main", "drawable", context.getPackageName()); break;
                case 1: iconRes = context.getResources().getIdentifier("ic_tab_esp", "drawable", context.getPackageName()); break;
                case 2: iconRes = context.getResources().getIdentifier("ic_tab_aim", "drawable", context.getPackageName()); break;
                case 3: iconRes = context.getResources().getIdentifier("ic_tab_items", "drawable", context.getPackageName()); break;
                case 4: iconRes = context.getResources().getIdentifier("ic_tab_skin", "drawable", context.getPackageName()); break;
            }
            if (iconRes != 0) {
                iconView.setImageResource(iconRes);
            }
            LinearLayout.LayoutParams iconParams = new LinearLayout.LayoutParams(dpToPx(18), dpToPx(18));
            iconParams.setMarginEnd(dpToPx(8));
            iconView.setLayoutParams(iconParams);
            buttonContainer.addView(iconView);

            TextView menuText = new TextView(context);
            menuText.setText(text);
            menuText.setTextColor(index == lastSelectedPage ? Color.WHITE : Color.parseColor("#CCCCCC"));
            menuText.setTextSize(12);
            menuText.setMaxLines(2);
            menuText.setEllipsize(android.text.TextUtils.TruncateAt.END);
            menuText.setGravity(Gravity.CENTER_VERTICAL);
            LinearLayout.LayoutParams textParams = new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT);
            textParams.weight = 1;
            textParams.setMarginStart(dpToPx(2));
            menuText.setLayoutParams(textParams);

            // Indicator dot (smaller, right-aligned)
            View indicator = new View(context);
            LinearLayout.LayoutParams indicatorParams = new LinearLayout.LayoutParams(dpToPx(6), dpToPx(6));
            indicatorParams.setMarginStart(dpToPx(8));
            indicatorParams.gravity = Gravity.CENTER_VERTICAL | Gravity.END;
            indicator.setLayoutParams(indicatorParams);
            GradientDrawable indicatorBg = new GradientDrawable();
            indicatorBg.setShape(GradientDrawable.OVAL);
            indicatorBg.setColor(index == lastSelectedPage ? Color.parseColor("#4CAF50") : Color.TRANSPARENT);
            indicator.setBackground(indicatorBg);

            buttonContainer.addView(menuText);
            buttonContainer.addView(indicator);

            // Only use subtle blue highlight for selected tab, no green background
            GradientDrawable containerBg = new GradientDrawable();
            containerBg.setCornerRadius(dpToPx(8));
            if (index == lastSelectedPage) {
                containerBg.setColor(Color.parseColor("#2633FF99"));
            } else {
                containerBg.setColor(Color.TRANSPARENT);
            }
            buttonContainer.setBackground(containerBg);

            final int pageIndex = index;
            buttonContainer.setOnClickListener(v -> switchToPage(pageIndex));

            return buttonContainer;
        } catch (Exception e) {
            e.printStackTrace();
            return new LinearLayout(context);
        }
    }

    private void createSidebarFooter(LinearLayout sidebar) {
        try {
            LinearLayout footerContainer = new LinearLayout(context);
            footerContainer.setOrientation(LinearLayout.VERTICAL);
            footerContainer.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
            footerContainer.setPadding(dpToPx(6), dpToPx(2), dpToPx(6), dpToPx(6));

            View divider = new View(context);
            divider.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, dpToPx(1)));
            divider.setBackgroundColor(Color.parseColor("#333333"));
            LinearLayout.LayoutParams dividerParams = (LinearLayout.LayoutParams) divider.getLayoutParams();
            dividerParams.setMargins(0, dpToPx(1), 0, dpToPx(3));
            divider.setLayoutParams(dividerParams);
            footerContainer.addView(divider);

            LinearLayout streamContainer = new LinearLayout(context);
            streamContainer.setOrientation(LinearLayout.HORIZONTAL);
            streamContainer.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
            streamContainer.setGravity(Gravity.CENTER_VERTICAL);

            TextView streamLabel = new TextView(context);
            streamLabel.setText(getEspMenuText != null ? getEspMenuText.get("LiveStreamMode(Recording Hide)", "直播隐藏模式") : "LiveStreamMode(Recording Hide)");
            streamLabel.setTextColor(Color.parseColor("#CCCCCC"));
            streamLabel.setTextSize(7);
            LinearLayout.LayoutParams labelParams = new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT);
            labelParams.weight = 1;
            streamLabel.setLayoutParams(labelParams);

            Switch streamSwitch = new Switch(context);
            if (GetBoolean != null) streamSwitch.setChecked(GetBoolean.get("RECORDER_HIDE"));
            streamSwitch.setScaleX(0.5f);
            streamSwitch.setScaleY(0.5f);
            ColorStateList thumbStates = new ColorStateList(
                new int[][]{new int[]{android.R.attr.state_checked}, new int[]{}},
                new int[]{Color.WHITE, Color.parseColor("#CCCCCC")}
            );
            ColorStateList trackStates = new ColorStateList(
                new int[][]{new int[]{android.R.attr.state_checked}, new int[]{}},
                new int[]{Color.parseColor("#4CAF50"), Color.parseColor("#555555")}
            );
            streamSwitch.setThumbTintList(thumbStates);
            streamSwitch.setTrackTintList(trackStates);
            streamSwitch.setOnCheckedChangeListener((buttonView, isChecked) -> {
                try {
                    // Update configuration
                    if (UpdateConfiguration != null) UpdateConfiguration.update("RECORDER_HIDE", isChecked ? 1 : 0);
                    
                    // FIXED: Actually call the RecorderFakeUtils functions
                    if (isChecked) {
                        // Enable anti-recording mode
                        android.util.Log.d("MenuManager", "Enabling LiveStreamMod anti-recording");
                        com.bearmod.Floating.hideesp(); // This calls RecorderFakeUtils.setFakeRecorderWindowLayoutParams
                    } else {
                        // Disable anti-recording mode  
                        android.util.Log.d("MenuManager", "Disabling LiveStreamMod anti-recording");
                        com.bearmod.Floating.stopHideesp(); // This calls RecorderFakeUtils.unsetFakeRecorderWindowLayoutParams
                    }
                    
                    // Save configuration
                    if (SaveConfiguration != null) SaveConfiguration.save();
                    
                    // Show feedback
                    String message = isChecked ? 
                        (getEspMenuText != null ? getEspMenuText.get("Recording protection enabled", "录屏保护已开启") : "Recording protection enabled") :
                        (getEspMenuText != null ? getEspMenuText.get("Recording protection disabled", "录屏保护已关闭") : "Recording protection disabled");
                    
                    android.widget.Toast.makeText(contextRef, message, android.widget.Toast.LENGTH_SHORT).show();
                    
                } catch (Exception e) {
                    android.util.Log.e("MenuManager", "Error toggling LiveStreamMod", e);
                    e.printStackTrace();
                }
            });
            streamContainer.addView(streamLabel);
            streamContainer.addView(streamSwitch);
            footerContainer.addView(streamContainer);
            sidebar.addView(footerContainer);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // --- Page Creation Logic ---
    public void createPages() {
        for (int i = 0; i < listTab.length; i++) {
            pageLayouts[i] = new LinearLayout(context);
            pageLayouts[i].setLayoutParams(new LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
            pageLayouts[i].setOrientation(LinearLayout.VERTICAL);
            pageLayouts[i].setPadding(5, 5, 5, 5);
            pageLayouts[i].setVisibility(i == lastSelectedPage ? View.VISIBLE : View.GONE);
        }
        if (contentLayout != null) {
            contentLayout.removeAllViews();
        }
        createMainPage();
        createESPPage();
        createAimPage();
        createItemsPage();
        createSkinPage();
        for (LinearLayout page : pageLayouts) {
            contentLayout.addView(page);
        }
    }

    // Helper interfaces for dependency injection
    public interface TextProvider { String get(String en, String cn); }
    public interface BooleanProvider { boolean get(String key); }
    public interface IntegerProvider { int get(String key); }
    public interface ConfigUpdater { void update(String key, Object value); }
    public interface SwitchInvoker { void invoke(int code); }
    public interface ConfigSaver { void save(); }
    public interface LanguageRefresher { void refresh(); }

    // These should be set by Floating.java after construction
    public TextProvider getEspMenuText;
    public BooleanProvider GetBoolean;
    public IntegerProvider GetInteger;
    public ConfigUpdater UpdateConfiguration;
    public SwitchInvoker Switch;
    public ConfigSaver SaveConfiguration;
    public LanguageRefresher refreshUILanguage;
    public int EspMenuTextthi = 0;
    public float mediumSize = 5.0f;

    private void createMainPage() {
        try {
            if (pageLayouts[0] == null) return;
            addSectionTitle(pageLayouts[0], getEspMenuText.get("Welcome to BearMod", "欢迎使用熊模组"));
            LinearLayout infoContainer = new LinearLayout(context);
            infoContainer.setOrientation(LinearLayout.VERTICAL);
            infoContainer.setPadding(10, 8, 10, 12);
            infoContainer.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
            GradientDrawable infoBg = new GradientDrawable();
            infoBg.setColor(Color.parseColor("#2a2a2a"));
            infoBg.setCornerRadius(dpToPx(10));
            infoBg.setStroke(dpToPx(1), Color.parseColor("#444444"));
            infoContainer.setBackground(infoBg);
            mainAppTitle = new TextView(context);
            mainAppTitle.setText(getEspMenuText.get("BearMod v1.0", "熊模组 v1.0"));
            mainAppTitle.setTextColor(Color.parseColor("#FFD700"));
            mainAppTitle.setTextSize(16);
            mainAppTitle.setTypeface(null, android.graphics.Typeface.BOLD);
            mainAppTitle.setPadding(8, 8, 8, 4);
            mainAppDesc = new TextView(context);
            mainAppDesc.setText(getEspMenuText.get(
                "Advanced game enhancement tool with ESP, Aimbot, and customization features.",
                "高级游戏增强工具，包含透视、自瞄和自定义功能。"));
            mainAppDesc.setTextColor(Color.parseColor("#CCCCCC"));
            mainAppDesc.setTextSize(12);
            mainAppDesc.setPadding(8, 4, 8, 8);
            infoContainer.addView(mainAppTitle);
            infoContainer.addView(mainAppDesc);
            pageLayouts[0].addView(infoContainer);
            mainQuickActionsTitle = new TextView(context);
            mainQuickActionsTitle.setText(getEspMenuText.get("Quick Actions", "快速操作"));
            mainQuickActionsTitle.setTextColor(Color.WHITE);
            mainQuickActionsTitle.setTextSize(14);
            mainQuickActionsTitle.setTypeface(null, android.graphics.Typeface.BOLD);
            mainQuickActionsTitle.setPadding(10, 15, 10, 10);
            pageLayouts[0].addView(mainQuickActionsTitle);
            addSwitch2(
                getEspMenuText.get("Master Enable", "主开关"),
                GetBoolean.get("MASTER::ENABLE"),
                (buttonView, isChecked) -> {
                    UpdateConfiguration.update("MASTER::ENABLE", isChecked ? 1 : 0);
                    Switch.invoke(1);
                },
                null,
                pageLayouts[0]
            );
            mainLanguageTitle = new TextView(context);
            mainLanguageTitle.setText(getEspMenuText.get("Language Settings", "语言设置"));
            mainLanguageTitle.setTextColor(Color.WHITE);
            mainLanguageTitle.setTextSize(14);
            mainLanguageTitle.setTypeface(null, android.graphics.Typeface.BOLD);
            mainLanguageTitle.setPadding(10, 15, 10, 10);
            pageLayouts[0].addView(mainLanguageTitle);
            String[] languages = {
                getEspMenuText.get("English", "英语"),
                getEspMenuText.get("Chinese", "中文")
            };
            addRadioButton(0, languages, GetInteger.get("SETTING_MENU"), (group, checkedId) -> {
                EspMenuTextthi = checkedId;
                UpdateConfiguration.update("SETTING_MENU", checkedId);
                SaveConfiguration.save();
                // Note: UI refresh will happen when language button is clicked or menu is reopened
            });
            mainStatusInfo = new TextView(context);
            mainStatusInfo.setText(getEspMenuText.get(
                "Status: Ready • Use sidebar to navigate between features",
                "状态：就绪 • 使用侧边栏在功能间导航"));
            mainStatusInfo.setTextColor(Color.parseColor("#4CAF50"));
            mainStatusInfo.setTextSize(11);
            mainStatusInfo.setPadding(12, 15, 12, 8);
            pageLayouts[0].addView(mainStatusInfo);
            // Add language toggle button to main page
            languageToggleBtn = new TextView(context);
            languageToggleBtn.setText(getEspMenuText != null ? getEspMenuText.get("Language: English", "语言: 中文") : "Language");
            languageToggleBtn.setTextColor(Color.parseColor("#4CAF50"));
            languageToggleBtn.setTextSize(14);
            languageToggleBtn.setPadding(dpToPx(12), dpToPx(8), dpToPx(12), dpToPx(8));
            GradientDrawable langBg = new GradientDrawable();
            langBg.setColor(Color.parseColor("#1A4CAF50"));
            langBg.setCornerRadius(dpToPx(6));
            langBg.setStroke(dpToPx(1), Color.parseColor("#4CAF50"));
            languageToggleBtn.setBackground(langBg);
            languageToggleBtn.setGravity(Gravity.CENTER);
            LinearLayout.LayoutParams langParams = new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT);
            langParams.setMargins(0, dpToPx(8), 0, dpToPx(4));
            languageToggleBtn.setLayoutParams(langParams);
            languageToggleBtn.setOnClickListener(v -> {
                // Toggle language
                EspMenuTextthi = (EspMenuTextthi == 0) ? 1 : 0;
                if (UpdateConfiguration != null) {
                    UpdateConfiguration.update("LANGUAGE", EspMenuTextthi);
                }
                // Update button text
                languageToggleBtn.setText(getEspMenuText != null ? getEspMenuText.get("Language: English", "语言: 中文") : "Language");
                // Refresh all UI text directly
                refreshUILanguage();
            });
            pageLayouts[0].addView(languageToggleBtn);
            
            // Settings Management Section
            mainSettingsTitle = new TextView(context);
            mainSettingsTitle.setText(getEspMenuText.get("Settings Management", "设置管理"));
            mainSettingsTitle.setTextColor(Color.WHITE);
            mainSettingsTitle.setTextSize(14);
            mainSettingsTitle.setTypeface(null, android.graphics.Typeface.BOLD);
            mainSettingsTitle.setPadding(10, 15, 10, 10);
            pageLayouts[0].addView(mainSettingsTitle);
            
            // Save Settings Button
            saveSettingsBtn = new TextView(context);
            saveSettingsBtn.setText(getEspMenuText.get("💾 Save Current Settings", "💾 保存当前设置"));
            saveSettingsBtn.setTextColor(Color.parseColor("#2196F3"));
            saveSettingsBtn.setTextSize(14);
            saveSettingsBtn.setPadding(dpToPx(12), dpToPx(10), dpToPx(12), dpToPx(10));
            saveSettingsBtn.setGravity(Gravity.CENTER);
            GradientDrawable saveBg = new GradientDrawable();
            saveBg.setColor(Color.parseColor("#1A2196F3"));
            saveBg.setCornerRadius(dpToPx(8));
            saveBg.setStroke(dpToPx(1), Color.parseColor("#2196F3"));
            saveSettingsBtn.setBackground(saveBg);
            LinearLayout.LayoutParams saveParams = new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT);
            saveParams.setMargins(0, dpToPx(8), 0, dpToPx(4));
            saveSettingsBtn.setLayoutParams(saveParams);
            saveSettingsBtn.setOnClickListener(v -> {
                try {
                    if (SaveConfiguration != null) {
                        SaveConfiguration.save();
                        // Show feedback
                        saveSettingsBtn.setText(getEspMenuText.get("✅ Settings Saved!", "✅ 设置已保存!"));
                        saveSettingsBtn.setTextColor(Color.parseColor("#4CAF50"));
                        // Reset text after 2 seconds
                        new Handler(android.os.Looper.getMainLooper()).postDelayed(() -> {
                            saveSettingsBtn.setText(getEspMenuText.get("💾 Save Current Settings", "💾 保存当前设置"));
                            saveSettingsBtn.setTextColor(Color.parseColor("#2196F3"));
                        }, 2000);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            });
            pageLayouts[0].addView(saveSettingsBtn);
            
            // Reset Settings Button
            resetSettingsBtn = new TextView(context);
            resetSettingsBtn.setText(getEspMenuText.get("🔄 Reset to Default", "🔄 重置为默认"));
            resetSettingsBtn.setTextColor(Color.parseColor("#FF9800"));
            resetSettingsBtn.setTextSize(14);
            resetSettingsBtn.setPadding(dpToPx(12), dpToPx(10), dpToPx(12), dpToPx(10));
            resetSettingsBtn.setGravity(Gravity.CENTER);
            GradientDrawable resetBg = new GradientDrawable();
            resetBg.setColor(Color.parseColor("#1AFF9800"));
            resetBg.setCornerRadius(dpToPx(8));
            resetBg.setStroke(dpToPx(1), Color.parseColor("#FF9800"));
            resetSettingsBtn.setBackground(resetBg);
            LinearLayout.LayoutParams resetParams = new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT);
            resetParams.setMargins(0, dpToPx(4), 0, dpToPx(4));
            resetSettingsBtn.setLayoutParams(resetParams);
            resetSettingsBtn.setOnClickListener(v -> {
                try {
                    // Reset all settings to default
                    resetAllSettings();
                    // Show feedback
                    resetSettingsBtn.setText(getEspMenuText.get("✅ Settings Reset!", "✅ 设置已重置!"));
                    resetSettingsBtn.setTextColor(Color.parseColor("#4CAF50"));
                    // Reset text after 2 seconds
                    new Handler(android.os.Looper.getMainLooper()).postDelayed(() -> {
                        resetSettingsBtn.setText(getEspMenuText.get("🔄 Reset to Default", "🔄 重置为默认"));
                        resetSettingsBtn.setTextColor(Color.parseColor("#FF9800"));
                        // Refresh UI to show reset values
                        refreshUILanguage();
                    }, 2000);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            });
            pageLayouts[0].addView(resetSettingsBtn);
            
            // Clear Cache Button
            clearCacheBtn = new TextView(context);
            clearCacheBtn.setText(getEspMenuText.get("🗑️ Clear Cache", "🗑️ 清除缓存"));
            clearCacheBtn.setTextColor(Color.parseColor("#F44336"));
            clearCacheBtn.setTextSize(14);
            clearCacheBtn.setPadding(dpToPx(12), dpToPx(10), dpToPx(12), dpToPx(10));
            clearCacheBtn.setGravity(Gravity.CENTER);
            GradientDrawable clearBg = new GradientDrawable();
            clearBg.setColor(Color.parseColor("#1AF44336"));
            clearBg.setCornerRadius(dpToPx(8));
            clearBg.setStroke(dpToPx(1), Color.parseColor("#F44336"));
            clearCacheBtn.setBackground(clearBg);
            LinearLayout.LayoutParams clearParams = new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT);
            clearParams.setMargins(0, dpToPx(4), 0, dpToPx(8));
            clearCacheBtn.setLayoutParams(clearParams);
            clearCacheBtn.setOnClickListener(v -> {
                try {
                    // Clear temporary cache/data
                    clearCache();
                    // Show feedback
                    clearCacheBtn.setText(getEspMenuText.get("✅ Cache Cleared!", "✅ 缓存已清除!"));
                    clearCacheBtn.setTextColor(Color.parseColor("#4CAF50"));
                    // Reset text after 2 seconds
                    new Handler(android.os.Looper.getMainLooper()).postDelayed(() -> {
                        clearCacheBtn.setText(getEspMenuText.get("🗑️ Clear Cache", "🗑️ 清除缓存"));
                        clearCacheBtn.setTextColor(Color.parseColor("#F44336"));
                    }, 2000);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            });
            pageLayouts[0].addView(clearCacheBtn);

            // Enhanced LiveStreamMod Section
            addSectionTitle(pageLayouts[0], getEspMenuText.get("🛡️ Anti-Recording Protection", "🛡️ 防录屏保护"));
            
            // Auto-detection toggle
            addSwitch2(
                getEspMenuText.get("🤖 Auto-Hide on Recording Detection", "🤖 检测录屏时自动隐藏"),
                GetBoolean.get("RECORDER_AUTO_DETECT"),
                (buttonView, isChecked) -> {
                    UpdateConfiguration.update("RECORDER_AUTO_DETECT", isChecked ? 1 : 0);
                    SaveConfiguration.save();
                    
                    if (isChecked) {
                        // Start auto-detection monitoring
                        try {
                            // Call Floating service method via reflection or callback
                            if (contextRef instanceof com.bearmod.Floating) {
                                ((com.bearmod.Floating) contextRef).startAutoDetectionMonitoring();
                            }
                            android.widget.Toast.makeText(contextRef, 
                                getEspMenuText.get("🤖 Auto-detection enabled - Will monitor for recording", "🤖 自动检测已启用 - 将监控录制状态"), 
                                android.widget.Toast.LENGTH_LONG).show();
                        } catch (Exception e) {
                            android.util.Log.e("MenuManager", "Error starting auto-detection", e);
                        }
                    } else {
                        // Stop auto-detection monitoring
                        try {
                            if (contextRef instanceof com.bearmod.Floating) {
                                ((com.bearmod.Floating) contextRef).stopAutoDetectionMonitoring();
                            }
                            android.widget.Toast.makeText(contextRef, 
                                getEspMenuText.get("⏹️ Auto-detection disabled", "⏹️ 自动检测已禁用"), 
                                android.widget.Toast.LENGTH_SHORT).show();
                        } catch (Exception e) {
                            android.util.Log.e("MenuManager", "Error stopping auto-detection", e);
                        }
                    }
                },
                null,
                pageLayouts[0]
            );
            
            // Manual toggle (existing)
            addSwitch2(
                getEspMenuText.get("🔒 Manual Hide Mode", "🔒 手动隐藏模式"),
                GetBoolean.get("RECORDER_HIDE"),
                (buttonView, isChecked) -> {
                    try {
                        UpdateConfiguration.update("RECORDER_HIDE", isChecked ? 1 : 0);
                        
                        if (isChecked) {
                            android.util.Log.d("MenuManager", "Enabling LiveStreamMod anti-recording");
                            com.bearmod.Floating.hideesp();
                        } else {
                            android.util.Log.d("MenuManager", "Disabling LiveStreamMod anti-recording");
                            com.bearmod.Floating.stopHideesp();
                        }
                        
                        SaveConfiguration.save();
                        
                        String message = isChecked ? 
                            getEspMenuText.get("📱 All mod elements hidden from recording", "📱 所有模组元素已从录制中隐藏") :
                            getEspMenuText.get("👁️ Mod elements visible again", "👁️ 模组元素重新可见");
                        
                        android.widget.Toast.makeText(contextRef, message, android.widget.Toast.LENGTH_SHORT).show();
                        
                    } catch (Exception e) {
                        android.util.Log.e("MenuManager", "Error toggling LiveStreamMod", e);
                    }
                },
                null,
                pageLayouts[0]
            );
            
            // Detection sensitivity
            addSeekBar(pageLayouts[0], 
                getEspMenuText.get("🔍 Detection Sensitivity", "🔍 检测灵敏度"), 
                GetInteger.get("RECORDER_SENSITIVITY"), 
                1, 5, 
                progress -> {
                    UpdateConfiguration.update("RECORDER_SENSITIVITY", progress);
                    SaveConfiguration.save();
                    
                    String[] sensitivityLevels = {
                        getEspMenuText.get("Very Low", "很低"),
                        getEspMenuText.get("Low", "低"),
                        getEspMenuText.get("Medium", "中"),
                        getEspMenuText.get("High", "高"),
                        getEspMenuText.get("Very High", "很高")
                    };
                    
                    if (progress >= 1 && progress <= 5) {
                        android.widget.Toast.makeText(contextRef, 
                            getEspMenuText.get("Sensitivity: ", "灵敏度: ") + sensitivityLevels[progress-1], 
                            android.widget.Toast.LENGTH_SHORT).show();
                    }
                });
            
            // Status indicator
            LinearLayout statusContainer = new LinearLayout(context);
            statusContainer.setOrientation(LinearLayout.HORIZONTAL);
            statusContainer.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
            statusContainer.setPadding(15, 8, 15, 12);
            statusContainer.setGravity(Gravity.CENTER_VERTICAL);
            
            TextView statusLabel = new TextView(context);
            statusLabel.setText(getEspMenuText.get("🔍 Recording Status:", "🔍 录制状态:"));
            statusLabel.setTextColor(Color.WHITE);
            statusLabel.setTextSize(12);
            statusLabel.setLayoutParams(new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT, 1));
            
            TextView statusIndicator = new TextView(context);
            boolean isRecording = false; // You can implement RecorderFakeUtils.isRecorderRunning(context) here
            statusIndicator.setText(isRecording ? 
                getEspMenuText.get("🔴 RECORDING DETECTED", "🔴 检测到录制") : 
                getEspMenuText.get("🟢 SAFE", "🟢 安全"));
            statusIndicator.setTextColor(isRecording ? Color.parseColor("#FF5252") : Color.parseColor("#4CAF50"));
            statusIndicator.setTextSize(12);
            statusIndicator.setTypeface(null, android.graphics.Typeface.BOLD);
            
            statusContainer.addView(statusLabel);
            statusContainer.addView(statusIndicator);
            pageLayouts[0].addView(statusContainer);
            
            // Info panel
            LinearLayout infoPanel = new LinearLayout(context);
            infoPanel.setOrientation(LinearLayout.VERTICAL);
            infoPanel.setPadding(12, 8, 12, 8);
            infoPanel.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
            GradientDrawable infoPanelBg = new GradientDrawable();
            infoPanelBg.setColor(Color.parseColor("#1A4CAF50"));
            infoPanelBg.setCornerRadius(dpToPx(8));
            infoPanelBg.setStroke(dpToPx(1), Color.parseColor("#4CAF50"));
            infoPanel.setBackground(infoPanelBg);
            
            TextView infoTitle = new TextView(context);
            infoTitle.setText(getEspMenuText.get("ℹ️ What gets hidden:", "ℹ️ 隐藏内容:"));
            infoTitle.setTextColor(Color.parseColor("#4CAF50"));
            infoTitle.setTextSize(12);
            infoTitle.setTypeface(null, android.graphics.Typeface.BOLD);
            infoTitle.setPadding(4, 4, 4, 2);
            
            TextView infoText = new TextView(context);
            infoText.setText(getEspMenuText.get(
                "• ESP boxes and overlays\n• Player names and distances\n• Aimbot indicators\n• Menu interface\n• Debug information",
                "• ESP框和覆盖层\n• 玩家姓名和距离\n• 自瞄指示器\n• 菜单界面\n• 调试信息"));
            infoText.setTextColor(Color.parseColor("#CCCCCC"));
            infoText.setTextSize(10);
            infoText.setPadding(4, 2, 4, 4);
            
            infoPanel.addView(infoTitle);
            infoPanel.addView(infoText);
            pageLayouts[0].addView(infoPanel);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    private void createESPPage() {
        try {
            if (pageLayouts[1] == null) return;
            addSectionTitle(pageLayouts[1], getEspMenuText.get("Player ESP", "玩家透视"));
            addSwitch2(getEspMenuText.get("Enable Player ESP", "启用玩家透视"), GetBoolean.get("ESP::ENABLE"), (buttonView, isChecked) -> { UpdateConfiguration.update("ESP::ENABLE", isChecked ? 1 : 0); Switch.invoke(101); }, null, pageLayouts[1]);
            addSwitch2(getEspMenuText.get("Player Box", "玩家方框"), GetBoolean.get("ESP::BOX"), (buttonView, isChecked) -> { UpdateConfiguration.update("ESP::BOX", isChecked ? 1 : 0); Switch.invoke(102); }, null, pageLayouts[1]);
            addSwitch2(getEspMenuText.get("Player Name", "玩家名称"), GetBoolean.get("ESP::NAME"), (buttonView, isChecked) -> { UpdateConfiguration.update("ESP::NAME", isChecked ? 1 : 0); Switch.invoke(103); }, null, pageLayouts[1]);
            addSwitch2(getEspMenuText.get("Player Distance", "玩家距离"), GetBoolean.get("ESP::DISTANCE"), (buttonView, isChecked) -> { UpdateConfiguration.update("ESP::DISTANCE", isChecked ? 1 : 0); Switch.invoke(104); }, null, pageLayouts[1]);
            addSwitch2(getEspMenuText.get("Health Bar", "血量条"), GetBoolean.get("ESP::HEALTH"), (buttonView, isChecked) -> { UpdateConfiguration.update("ESP::HEALTH", isChecked ? 1 : 0); Switch.invoke(105); }, null, pageLayouts[1]);
            addSectionTitle(pageLayouts[1], getEspMenuText.get("Box Settings", "方框设置"));
            String[] boxTypes = { getEspMenuText.get("2D Box", "2D方框"), getEspMenuText.get("3D Box", "3D方框"), getEspMenuText.get("Corner Box", "角落方框") };
            addRadioButton(1, boxTypes, GetInteger.get("ESP::BOXTYPE"), (group, checkedId) -> { UpdateConfiguration.update("ESP::BOXTYPE", checkedId); Switch.invoke(106); });
            addSeekBar(pageLayouts[1], getEspMenuText.get("ESP Distance", "透视距离"), GetInteger.get("ESP::DISTANCE_LIMIT"), 50, 500, progress -> { UpdateConfiguration.update("ESP::DISTANCE_LIMIT", progress); Switch.invoke(107); });
            addSectionTitle(pageLayouts[1], getEspMenuText.get("Other ESP", "其他透视"));
            addSwitch2(getEspMenuText.get("Vehicle ESP", "载具透视"), GetBoolean.get("ESP::VEHICLE"), (buttonView, isChecked) -> { UpdateConfiguration.update("ESP::VEHICLE", isChecked ? 1 : 0); Switch.invoke(108); }, null, pageLayouts[1]);
            addSwitch2(getEspMenuText.get("Warning Zone", "警告区域"), GetBoolean.get("ESP::ZONE"), (buttonView, isChecked) -> { UpdateConfiguration.update("ESP::ZONE", isChecked ? 1 : 0); Switch.invoke(109); }, null, pageLayouts[1]);
        } catch (Exception e) { e.printStackTrace(); }
    }
    private void createAimPage() {
        try {
            if (pageLayouts[2] == null) return;
            addSectionTitle(pageLayouts[2], getEspMenuText.get("Aimbot Settings", "自瞄设置"));
            addSwitch2(getEspMenuText.get("Enable Aimbot", "启用自瞄"), GetBoolean.get("AIM::ENABLE"), (buttonView, isChecked) -> { UpdateConfiguration.update("AIM::ENABLE", isChecked ? 1 : 0); Switch.invoke(201); }, null, pageLayouts[2]);
            addSwitch2(getEspMenuText.get("Auto Fire", "自动开火"), GetBoolean.get("AIM::AUTOFIRE"), (buttonView, isChecked) -> { UpdateConfiguration.update("AIM::AUTOFIRE", isChecked ? 1 : 0); Switch.invoke(202); }, null, pageLayouts[2]);
            addSwitch2(getEspMenuText.get("Silent Aim", "静默自瞄"), GetBoolean.get("AIM::SILENT"), (buttonView, isChecked) -> { UpdateConfiguration.update("AIM::SILENT", isChecked ? 1 : 0); Switch.invoke(203); }, null, pageLayouts[2]);
            addSectionTitle(pageLayouts[2], getEspMenuText.get("Target Settings", "目标设置"));
            String[] targetBones = { getEspMenuText.get("Head", "头部"), getEspMenuText.get("Chest", "胸部"), getEspMenuText.get("Body", "身体") };
            addRadioButton(2, targetBones, GetInteger.get("AIM::TARGET"), (group, checkedId) -> { UpdateConfiguration.update("AIM::TARGET", checkedId); Switch.invoke(204); });
            addSeekBar(pageLayouts[2], getEspMenuText.get("Aim Range", "自瞄范围"), GetInteger.get("AIM::RANGE"), 50, 300, progress -> { UpdateConfiguration.update("AIM::RANGE", progress); Switch.invoke(205); });
            addSeekBar(pageLayouts[2], getEspMenuText.get("Aim Speed", "自瞄速度"), GetInteger.get("AIM::SPEED"), 1, 10, progress -> { UpdateConfiguration.update("AIM::SPEED", progress); Switch.invoke(206); });
            addSeekBar(pageLayouts[2], getEspMenuText.get("Aim Smoothness", "自瞄平滑"), GetInteger.get("AIM::SMOOTH"), 1, 20, progress -> { UpdateConfiguration.update("AIM::SMOOTH", progress); Switch.invoke(207); });
            addSectionTitle(pageLayouts[2], getEspMenuText.get("Advanced", "高级设置"));
            addSwitch2(getEspMenuText.get("Prediction", "预判"), GetBoolean.get("AIM::PREDICTION"), (buttonView, isChecked) -> { UpdateConfiguration.update("AIM::PREDICTION", isChecked ? 1 : 0); Switch.invoke(208); }, null, pageLayouts[2]);
            addSwitch2(getEspMenuText.get("Ignore Knocked", "忽略倒地"), GetBoolean.get("AIM::IGNORE_KNOCKED"), (buttonView, isChecked) -> { UpdateConfiguration.update("AIM::IGNORE_KNOCKED", isChecked ? 1 : 0); Switch.invoke(209); }, null, pageLayouts[2]);
        } catch (Exception e) { e.printStackTrace(); }
    }
    private void createItemsPage() {
        try {
            if (pageLayouts[3] == null) return;
            addSectionTitle(pageLayouts[3], getEspMenuText.get("Weapon ESP", "武器透视"));
            addSwitch2(getEspMenuText.get("Show Weapons", "显示武器"), GetBoolean.get("ITEM::WEAPON"), (buttonView, isChecked) -> { UpdateConfiguration.update("ITEM::WEAPON", isChecked ? 1 : 0); Switch.invoke(301); }, null, pageLayouts[3]);
            addSwitch2(getEspMenuText.get("Show Attachments", "显示配件"), GetBoolean.get("ITEM::ATTACHMENT"), (buttonView, isChecked) -> { UpdateConfiguration.update("ITEM::ATTACHMENT", isChecked ? 1 : 0); Switch.invoke(302); }, null, pageLayouts[3]);
            addSectionTitle(pageLayouts[3], getEspMenuText.get("Supply ESP", "补给透视"));
            addSwitch2(getEspMenuText.get("Medical Items", "医疗用品"), GetBoolean.get("ITEM::MEDICAL"), (buttonView, isChecked) -> { UpdateConfiguration.update("ITEM::MEDICAL", isChecked ? 1 : 0); Switch.invoke(303); }, null, pageLayouts[3]);
            addSwitch2(getEspMenuText.get("Ammo", "弹药"), GetBoolean.get("ITEM::AMMO"), (buttonView, isChecked) -> { UpdateConfiguration.update("ITEM::AMMO", isChecked ? 1 : 0); Switch.invoke(304); }, null, pageLayouts[3]);
            addSwitch2(getEspMenuText.get("Armor & Helmet", "护甲头盔"), GetBoolean.get("ITEM::ARMOR"), (buttonView, isChecked) -> { UpdateConfiguration.update("ITEM::ARMOR", isChecked ? 1 : 0); Switch.invoke(305); }, null, pageLayouts[3]);
            addSectionTitle(pageLayouts[3], getEspMenuText.get("Special Items", "特殊物品"));
            addSwitch2(getEspMenuText.get("Airdrop", "空投"), GetBoolean.get("ITEM::AIRDROP"), (buttonView, isChecked) -> { UpdateConfiguration.update("ITEM::AIRDROP", isChecked ? 1 : 0); Switch.invoke(306); }, null, pageLayouts[3]);
            addSwitch2(getEspMenuText.get("Flare Gun", "信号枪"), GetBoolean.get("ITEM::FLARE"), (buttonView, isChecked) -> { UpdateConfiguration.update("ITEM::FLARE", isChecked ? 1 : 0); Switch.invoke(307); }, null, pageLayouts[3]);
            addSeekBar(pageLayouts[3], getEspMenuText.get("Item Distance", "物品距离"), GetInteger.get("ITEM::DISTANCE"), 20, 200, progress -> { UpdateConfiguration.update("ITEM::DISTANCE", progress); Switch.invoke(308); });
        } catch (Exception e) { e.printStackTrace(); }
    }
    private void createSkinPage() {
        try {
            if (pageLayouts[4] == null) return;
            
            // Main skin controls
            addSectionTitle(pageLayouts[4], getEspMenuText.get("Skin Settings", "皮肤设置"));
            addSwitch2(getEspMenuText.get("Skin-Enable", "启用皮肤"), 
                GetBoolean.get("SKIN_ENABLE"), 
                (buttonView, isChecked) -> {
                    UpdateConfiguration.update("SKIN_ENABLE", isChecked ? 1 : 0);
                    SaveConfiguration.save();
                }, 
                null, 
                pageLayouts[4]);
            
            addSwitch2(getEspMenuText.get("DeadBox (Ingame for open)", "死亡盒子（游戏内开启）"), 
                GetBoolean.get("SKIN_BOXENABLE"), 
                (buttonView, isChecked) -> {
                    UpdateConfiguration.update("SKIN_BOXENABLE", isChecked ? 1 : 0);
                    SaveConfiguration.save();
                }, 
                null, 
                pageLayouts[4]);
            
            // Character customization
            addSectionTitle(pageLayouts[4], getEspMenuText.get("Character Customization", "角色自定义"));
            addSeekBar(pageLayouts[4], getEspMenuText.get("X-suit", "X套装"), GetInteger.get("SKIN_XSUIT"), 0, 13, progress -> {
                UpdateConfiguration.update("SKIN_XSUIT", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], getEspMenuText.get("Set", "套装"), GetInteger.get("SKIN_SET"), 0, 72, progress -> {
                UpdateConfiguration.update("SKIN_SET", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], getEspMenuText.get("Skin-BackPack", "背包皮肤"), GetInteger.get("SKIN_BACKPACK"), 0, 16, progress -> {
                UpdateConfiguration.update("SKIN_BACKPACK", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], getEspMenuText.get("Skin-Helmet", "头盔皮肤"), GetInteger.get("SKIN_HELMET"), 0, 10, progress -> {
                UpdateConfiguration.update("SKIN_HELMET", progress);
                SaveConfiguration.save();
            });
            
            // Assault Rifles
            addSectionTitle(pageLayouts[4], getEspMenuText.get("Assault Rifles", "突击步枪"));
            addSeekBar(pageLayouts[4], "M416", GetInteger.get("SKIN_M416"), 0, 11, progress -> {
                UpdateConfiguration.update("SKIN_M416", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "AKM", GetInteger.get("SKIN_AKM"), 0, 10, progress -> {
                UpdateConfiguration.update("SKIN_AKM", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "SCAR-L", GetInteger.get("SKIN_SCARL"), 0, 7, progress -> {
                UpdateConfiguration.update("SKIN_SCARL", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "M762", GetInteger.get("SKIN_M762"), 0, 9, progress -> {
                UpdateConfiguration.update("SKIN_M762", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "M16A4", GetInteger.get("SKIN_M16A4"), 0, 5, progress -> {
                UpdateConfiguration.update("SKIN_M16A4", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "GROZAR", GetInteger.get("SKIN_GROZAR"), 0, 7, progress -> {
                UpdateConfiguration.update("SKIN_GROZAR", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "AUG", GetInteger.get("SKIN_AUG"), 0, 5, progress -> {
                UpdateConfiguration.update("SKIN_AUG", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "ACE32", GetInteger.get("SKIN_ACE32"), 0, 3, progress -> {
                UpdateConfiguration.update("SKIN_ACE32", progress);
                SaveConfiguration.save();
            });
            
            // Machine Guns
            addSectionTitle(pageLayouts[4], getEspMenuText.get("Machine Guns", "机枪"));
            addSeekBar(pageLayouts[4], "M249", GetInteger.get("SKIN_M249"), 0, 4, progress -> {
                UpdateConfiguration.update("SKIN_M249", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "DP28", GetInteger.get("SKIN_DP28"), 0, 4, progress -> {
                UpdateConfiguration.update("SKIN_DP28", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "MG3", GetInteger.get("SKIN_MG3"), 0, 1, progress -> {
                UpdateConfiguration.update("SKIN_MG3", progress);
                SaveConfiguration.save();
            });
            
            // SMGs
            addSectionTitle(pageLayouts[4], getEspMenuText.get("SMG", "冲锋枪"));
            addSeekBar(pageLayouts[4], "P90", GetInteger.get("SKIN_P90"), 0, 1, progress -> {
                UpdateConfiguration.update("SKIN_P90", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "UZI", GetInteger.get("SKIN_UZI"), 0, 6, progress -> {
                UpdateConfiguration.update("SKIN_UZI", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "UMP45", GetInteger.get("SKIN_UMP45"), 0, 8, progress -> {
                UpdateConfiguration.update("SKIN_UMP45", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "VECTOR", GetInteger.get("SKIN_VECTOR"), 0, 4, progress -> {
                UpdateConfiguration.update("SKIN_VECTOR", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "THOMPSON", GetInteger.get("SKIN_THOMPSON"), 0, 4, progress -> {
                UpdateConfiguration.update("SKIN_THOMPSON", progress);
                SaveConfiguration.save();
            });
            
            // Sniper Rifles
            addSectionTitle(pageLayouts[4], getEspMenuText.get("Sniper Rifles", "狙击步枪"));
            addSeekBar(pageLayouts[4], "M24", GetInteger.get("SKIN_M24"), 0, 5, progress -> {
                UpdateConfiguration.update("SKIN_M24", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "KAR98K", GetInteger.get("SKIN_KAR98K"), 0, 6, progress -> {
                UpdateConfiguration.update("SKIN_KAR98K", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "AWM", GetInteger.get("SKIN_AWM"), 0, 7, progress -> {
                UpdateConfiguration.update("SKIN_AWM", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "AMR", GetInteger.get("SKIN_AMR"), 0, 1, progress -> {
                UpdateConfiguration.update("SKIN_AMR", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "MK14", GetInteger.get("SKIN_MK14"), 0, 2, progress -> {
                UpdateConfiguration.update("SKIN_MK14", progress);
                SaveConfiguration.save();
            });
            
            // Vehicles
            addSectionTitle(pageLayouts[4], getEspMenuText.get("Vehicle Skins", "载具皮肤"));
            addSeekBar(pageLayouts[4], "Dacia", GetInteger.get("SKIN_DACIA"), 0, 23, progress -> {
                UpdateConfiguration.update("SKIN_DACIA", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "CoupeRP", GetInteger.get("SKIN_COUPERP"), 0, 35, progress -> {
                UpdateConfiguration.update("SKIN_COUPERP", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], "UAZ", GetInteger.get("SKIN_UAZ"), 0, 13, progress -> {
                UpdateConfiguration.update("SKIN_UAZ", progress);
                SaveConfiguration.save();
            });
            
            addSeekBar(pageLayouts[4], getEspMenuText.get("Moto", "摩托车"), GetInteger.get("SKIN_MOTO"), 0, 8, progress -> {
                UpdateConfiguration.update("SKIN_MOTO", progress);
                SaveConfiguration.save();
            });
            
        } catch (Exception e) { 
            e.printStackTrace(); 
        }
    }
    private void addSectionTitle(LinearLayout parent, String title) {
        try {
            if (parent == null) return;
            View divider = new View(context);
            divider.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, 1));
            divider.setBackgroundColor(Color.parseColor("#55FFFFFF"));
            parent.addView(divider);
            TextView titleText = new TextView(context);
            titleText.setText(title);
            titleText.setTextColor(Color.parseColor("#FFD700"));
            titleText.setTextSize(14);
            titleText.setTypeface(null, android.graphics.Typeface.BOLD);
            titleText.setPadding(10, 15, 10, 10);
            titleText.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
            parent.addView(titleText);
        } catch (Exception e) { e.printStackTrace(); }
    }
    private void addSwitch2(String label, boolean isChecked, CompoundButton.OnCheckedChangeListener listener, View.OnClickListener longClickListener, LinearLayout parent) {
        try {
            if (parent == null) return;
            LinearLayout containerLayout = new LinearLayout(context);
            containerLayout.setOrientation(LinearLayout.HORIZONTAL);
            containerLayout.setGravity(Gravity.CENTER_VERTICAL);
            containerLayout.setPadding(10, 0, 10, 10);
            LinearLayout.LayoutParams textParams = new LinearLayout.LayoutParams(0, ViewGroup.LayoutParams.WRAP_CONTENT);
            textParams.weight = 1;
            TextView labelText = new TextView(context);
            labelText.setText(label);
            labelText.setTextSize(13.0f);
            labelText.setTextColor(Color.WHITE);
            labelText.setPadding(20, 0, 20, 10);
            labelText.setLayoutParams(textParams);
            LinearLayout.LayoutParams switchParams = new LinearLayout.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT);
            switchParams.gravity = Gravity.END;
            Switch switchButton = new Switch(context);
            switchButton.setChecked(isChecked);
            switchButton.setLayoutParams(switchParams);
            ColorStateList thumbStates = new ColorStateList(new int[][]{ new int[]{android.R.attr.state_checked}, new int[]{} }, new int[]{ Color.WHITE, Color.GREEN });
            ColorStateList trackStates = new ColorStateList(new int[][]{ new int[]{android.R.attr.state_checked}, new int[]{} }, new int[]{ Color.parseColor("#4CAF50"), Color.parseColor("#555555") });
            switchButton.setThumbTintList(thumbStates);
            switchButton.setTrackTintList(trackStates);
            if (listener != null) switchButton.setOnCheckedChangeListener(listener);
            if (longClickListener != null) switchButton.setOnLongClickListener(v -> { longClickListener.onClick(v); return true; });
            containerLayout.addView(labelText);
            containerLayout.addView(switchButton);
            parent.addView(containerLayout);
            View lineView = new View(context);
            lineView.setBackgroundColor(Color.parseColor("#E0E0E0"));
            LinearLayout.LayoutParams lineParams = new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, 1);
            lineParams.setMargins(20, 5, 20, 10);
            lineView.setLayoutParams(lineParams);
            parent.addView(lineView);
            addSpacing(parent, 5);
        } catch (Exception e) { e.printStackTrace(); }
    }
    private void addSeekBar(LinearLayout parent, String label, int currentValue, int min, int max, OnSeekBarChangeListener listener) {
        try {
            if (parent == null) return;
            LinearLayout container = new LinearLayout(context);
            container.setOrientation(LinearLayout.VERTICAL);
            container.setPadding(10, 5, 10, 10);
            container.setLayoutParams(new LinearLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
            TextView labelText = new TextView(context);
            labelText.setText(label + ": " + currentValue);
            labelText.setTextColor(Color.WHITE);
            labelText.setTextSize(13);
            labelText.setPadding(5, 5, 5, 5);
            SeekBar seekBar = new SeekBar(context);
            seekBar.setMax(max - min);
            seekBar.setProgress(currentValue - min);
            seekBar.setPadding(10, 5, 10, 5);
            seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
                @Override public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                    if (fromUser) {
                        int value = progress + min;
                        labelText.setText(label + ": " + value);
                        if (listener != null) listener.onProgressChanged(value);
                    }
                }
                @Override public void onStartTrackingTouch(SeekBar seekBar) {}
                @Override public void onStopTrackingTouch(SeekBar seekBar) {}
            });
            container.addView(labelText);
            container.addView(seekBar);
            parent.addView(container);
            addSpacing(parent, 5);
        } catch (Exception e) { e.printStackTrace(); }
    }
    private interface OnSeekBarChangeListener { void onProgressChanged(int progress); }
    void addRadioButton(Object object, String[] list, int value, RadioGroup.OnCheckedChangeListener listener) {
        try {
            if (list == null || list.length == 0) return;
            RadioGroup rg = new RadioGroup(context);
            RadioButton[] radioButtonArr = new RadioButton[list.length];
            rg.setOrientation(RadioGroup.HORIZONTAL);
            for (int i = 0; i < list.length; i++) {
                radioButtonArr[i] = new RadioButton(context);
                if (i == value) radioButtonArr[i].setChecked(true);
                radioButtonArr[i].setPadding(15, 15, 15, 15);
                radioButtonArr[i].setText(list[i]);
                radioButtonArr[i].setTextSize(mediumSize);
                radioButtonArr[i].setId(i);
                radioButtonArr[i].setGravity(Gravity.RIGHT);
                radioButtonArr[i].setTextColor(Color.WHITE);
                ColorStateList colorStateList = new ColorStateList(new int[][]{ new int[]{-android.R.attr.state_checked}, new int[]{android.R.attr.state_checked} }, new int[]{ Color.BLACK, Color.WHITE });
                radioButtonArr[i].setButtonTintList(colorStateList);
                rg.addView(radioButtonArr[i]);
            }
            if (listener != null) rg.setOnCheckedChangeListener(listener);
            RelativeLayout.LayoutParams toggleP = new RelativeLayout.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT);
            rg.setLayoutParams(toggleP);
            if (object instanceof Integer && pageLayouts != null && (Integer) object < pageLayouts.length)
                this.pageLayouts[(Integer) object].addView(rg);
            else if (object instanceof ViewGroup)
                ((ViewGroup) object).addView(rg);
        } catch (Exception e) { e.printStackTrace(); }
    }
    void addSpacing(ViewGroup parentLayout, int i) {
        try {
            if (parentLayout == null) return;
            View spaceView = new View(context);
            spaceView.setLayoutParams(new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, 5));
            parentLayout.addView(spaceView);
        } catch (Exception e) { e.printStackTrace(); }
    }

    // --- Page Switching Logic ---
    public void switchToPage(int pageIndex) {
        if (pageIndex < 0 || pageIndex >= pageLayouts.length) return;
        for (int i = 0; i < pageLayouts.length; i++) {
            if (pageLayouts[i] != null) {
                pageLayouts[i].setVisibility(i == pageIndex ? View.VISIBLE : View.GONE);
            }
        }
        lastSelectedPage = pageIndex;
        updateSidebarMenu();
    }

    // --- Sidebar Menu State Update ---
    private void updateSidebarMenu() {
        if (menuContainerRef == null) return;
        int buttonIndex = 0;
        for (int i = 0; i < menuContainerRef.getChildCount(); i++) {
            View child = menuContainerRef.getChildAt(i);
            if (child instanceof LinearLayout) {
                LinearLayout buttonContainer = (LinearLayout) child;
                // Update text color
                if (buttonContainer.getChildCount() > 0) {
                    View textView = buttonContainer.getChildAt(0);
                    if (textView instanceof TextView) {
                        ((TextView) textView).setTextColor(buttonIndex == lastSelectedPage ? Color.WHITE : Color.parseColor("#CCCCCC"));
                    }
                }
                // Update indicator
                if (buttonContainer.getChildCount() > 1) {
                    View indicator = buttonContainer.getChildAt(1);
                    GradientDrawable indicatorBg = new GradientDrawable();
                    indicatorBg.setShape(GradientDrawable.OVAL);
                    indicatorBg.setColor(buttonIndex == lastSelectedPage ? Color.parseColor("#4CAF50") : Color.TRANSPARENT);
                    indicator.setBackground(indicatorBg);
                }
                // Update background
                GradientDrawable containerBg = new GradientDrawable();
                containerBg.setCornerRadius(dpToPx(8));
                if (buttonIndex == lastSelectedPage) {
                    containerBg.setColor(Color.parseColor("#2633FF99")); // Subtle blue highlight
                } else {
                    containerBg.setColor(Color.TRANSPARENT);
                }
                buttonContainer.setBackground(containerBg);
                buttonIndex++;
            }
        }
    }

    // --- Language Refresh ---
    public void refreshUILanguage() {
        try {
            // Update sidebar title
            if (textTitle != null && getEspMenuText != null) {
                textTitle.setText(getEspMenuText.get("BEAR-MOD", "熊模组"));
            }
            
            // Update all stored main page UI elements
            updateMainPageLanguage();
            
            // Update sidebar navigation menu items
            updateSidebarMenu();
            
            // Don't recreate pages - just update existing elements
            updateExistingPageContent();
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    private void updateMainPageLanguage() {
        try {
            if (getEspMenuText == null) return;
            
            // Update main page titles and text
            if (mainAppTitle != null) {
                mainAppTitle.setText(getEspMenuText.get("BearMod v1.0", "熊模组 v1.0"));
            }
            if (mainAppDesc != null) {
                mainAppDesc.setText(getEspMenuText.get(
                    "Advanced game enhancement tool with ESP, Aimbot, and customization features.",
                    "高级游戏增强工具，包含透视、自瞄和自定义功能。"));
            }
            if (mainQuickActionsTitle != null) {
                mainQuickActionsTitle.setText(getEspMenuText.get("Quick Actions", "快速操作"));
            }
            if (mainLanguageTitle != null) {
                mainLanguageTitle.setText(getEspMenuText.get("Language Settings", "语言设置"));
            }
            if (mainSettingsTitle != null) {
                mainSettingsTitle.setText(getEspMenuText.get("Settings Management", "设置管理"));
            }
            if (mainStatusInfo != null) {
                mainStatusInfo.setText(getEspMenuText.get(
                    "Status: Ready • Use sidebar to navigate between features",
                    "状态：就绪 • 使用侧边栏在功能间导航"));
            }
            if (languageToggleBtn != null) {
                languageToggleBtn.setText(getEspMenuText.get("Language: English", "语言: 中文"));
            }
            if (saveSettingsBtn != null) {
                saveSettingsBtn.setText(getEspMenuText.get("💾 Save Current Settings", "💾 保存当前设置"));
                saveSettingsBtn.setTextColor(android.graphics.Color.parseColor("#2196F3"));
            }
            if (resetSettingsBtn != null) {
                resetSettingsBtn.setText(getEspMenuText.get("🔄 Reset to Default", "🔄 重置为默认"));
                resetSettingsBtn.setTextColor(android.graphics.Color.parseColor("#FF9800"));
            }
            if (clearCacheBtn != null) {
                clearCacheBtn.setText(getEspMenuText.get("🗑️ Clear Cache", "🗑️ 清除缓存"));
                clearCacheBtn.setTextColor(android.graphics.Color.parseColor("#F44336"));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    private void updateExistingPageContent() {
        try {
            if (getEspMenuText == null || pageLayouts == null) return;
            
            // Update any existing switches, labels, and other UI elements
            for (int i = 0; i < pageLayouts.length; i++) {
                if (pageLayouts[i] != null) {
                    updatePageTexts(pageLayouts[i]);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    private void updatePageTexts(android.view.ViewGroup viewGroup) {
        try {
            if (viewGroup == null) return;
            
            for (int i = 0; i < viewGroup.getChildCount(); i++) {
                android.view.View child = viewGroup.getChildAt(i);
                
                if (child instanceof TextView) {
                    TextView textView = (TextView) child;
                    String currentText = textView.getText().toString();
                    
                    // Update specific known text elements
                    if (currentText.contains("Master Enable") || currentText.contains("主开关")) {
                        textView.setText(getEspMenuText.get("Master Enable", "主开关"));
                    } else if (currentText.contains("LiveStreamMode") || currentText.contains("直播隐藏模式")) {
                        textView.setText(getEspMenuText.get("LiveStreamMode(Recording Hide)", "直播隐藏模式"));
                    }
                    // Add more text updates as needed
                } else if (child instanceof android.view.ViewGroup) {
                    // Recursively update child view groups
                    updatePageTexts((android.view.ViewGroup) child);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void refreshPageText(int pageIndex) {
        try {
            // Instead of recreating pages, just update the current page content
            updateExistingPageContent();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Helper methods for settings management
    private void resetAllSettings() {
        try {
            if (UpdateConfiguration == null) return;
            
            // Reset main settings
            UpdateConfiguration.update("MASTER::ENABLE", 0);
            UpdateConfiguration.update("SETTING_MENU", 0);
            UpdateConfiguration.update("LANGUAGE", 0);
            
            // Reset ESP settings
            UpdateConfiguration.update("ESP::ENABLE", 0);
            UpdateConfiguration.update("ESP::BOX", 0);
            UpdateConfiguration.update("ESP::NAME", 0);
            UpdateConfiguration.update("ESP::DISTANCE", 0);
            UpdateConfiguration.update("ESP::HEALTH", 0);
            UpdateConfiguration.update("ESP::BOXTYPE", 0);
            UpdateConfiguration.update("ESP::DISTANCE_LIMIT", 100);
            UpdateConfiguration.update("ESP::VEHICLE", 0);
            UpdateConfiguration.update("ESP::ZONE", 0);
            
            // Reset AIM settings
            UpdateConfiguration.update("AIM::ENABLE", 0);
            UpdateConfiguration.update("AIM::AUTOFIRE", 0);
            UpdateConfiguration.update("AIM::SILENT", 0);
            UpdateConfiguration.update("AIM::TARGET", 0);
            UpdateConfiguration.update("AIM::RANGE", 100);
            UpdateConfiguration.update("AIM::SPEED", 5);
            UpdateConfiguration.update("AIM::SMOOTH", 10);
            UpdateConfiguration.update("AIM::PREDICTION", 0);
            UpdateConfiguration.update("AIM::IGNORE_KNOCKED", 0);
            
            // Reset ITEM settings
            UpdateConfiguration.update("ITEM::WEAPON", 0);
            UpdateConfiguration.update("ITEM::ATTACHMENT", 0);
            UpdateConfiguration.update("ITEM::MEDICAL", 0);
            UpdateConfiguration.update("ITEM::AMMO", 0);
            UpdateConfiguration.update("ITEM::ARMOR", 0);
            UpdateConfiguration.update("ITEM::AIRDROP", 0);
            UpdateConfiguration.update("ITEM::FLARE", 0);
            UpdateConfiguration.update("ITEM::DISTANCE", 50);
            
            // Reset SKIN settings
            UpdateConfiguration.update("SKIN_ENABLE", 0);
            UpdateConfiguration.update("SKIN_BOXENABLE", 0);
            UpdateConfiguration.update("SKIN_XSUIT", 0);
            UpdateConfiguration.update("SKIN_SET", 0);
            UpdateConfiguration.update("SKIN_BACKPACK", 0);
            UpdateConfiguration.update("SKIN_HELMET", 0);
            
            // Reset weapon skins
            UpdateConfiguration.update("SKIN_M416", 0);
            UpdateConfiguration.update("SKIN_AKM", 0);
            UpdateConfiguration.update("SKIN_SCARL", 0);
            UpdateConfiguration.update("SKIN_M762", 0);
            UpdateConfiguration.update("SKIN_M16A4", 0);
            UpdateConfiguration.update("SKIN_GROZAR", 0);
            UpdateConfiguration.update("SKIN_AUG", 0);
            UpdateConfiguration.update("SKIN_ACE32", 0);
            UpdateConfiguration.update("SKIN_M249", 0);
            UpdateConfiguration.update("SKIN_DP28", 0);
            UpdateConfiguration.update("SKIN_MG3", 0);
            UpdateConfiguration.update("SKIN_P90", 0);
            UpdateConfiguration.update("SKIN_UZI", 0);
            UpdateConfiguration.update("SKIN_UMP45", 0);
            UpdateConfiguration.update("SKIN_VECTOR", 0);
            UpdateConfiguration.update("SKIN_THOMPSON", 0);
            UpdateConfiguration.update("SKIN_M24", 0);
            UpdateConfiguration.update("SKIN_KAR98K", 0);
            UpdateConfiguration.update("SKIN_AWM", 0);
            UpdateConfiguration.update("SKIN_AMR", 0);
            UpdateConfiguration.update("SKIN_MK14", 0);
            
            // Reset vehicle skins
            UpdateConfiguration.update("SKIN_DACIA", 0);
            UpdateConfiguration.update("SKIN_COUPERP", 0);
            UpdateConfiguration.update("SKIN_UAZ", 0);
            UpdateConfiguration.update("SKIN_MOTO", 0);
            
            // Reset recorder settings
            UpdateConfiguration.update("RECORDER_HIDE", 0);
            
            // Reset language to default
            EspMenuTextthi = 0;
            
            // Save the reset configuration
            if (SaveConfiguration != null) {
                SaveConfiguration.save();
            }
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    private void clearCache() {
        try {
            // Clear any temporary files or cache data
            // This could include clearing temporary skin files, cached textures, etc.
            
            // For now, this is a placeholder for cache clearing logic
            // The actual implementation would depend on what kind of cache/temp data the mod uses
            
            // Example: Clear any temporary configuration backups or cached data
            java.io.File cacheDir = context.getCacheDir();
            if (cacheDir != null && cacheDir.exists()) {
                clearDirectory(cacheDir);
            }
            
            // Clear any temporary files in internal storage
            java.io.File filesDir = context.getFilesDir();
            if (filesDir != null && filesDir.exists()) {
                // Clear only temporary files, not the main config
                java.io.File[] files = filesDir.listFiles();
                if (files != null) {
                    for (java.io.File file : files) {
                        if (file.getName().contains("temp") || 
                            file.getName().contains("cache") ||
                            file.getName().endsWith(".tmp")) {
                            file.delete();
                        }
                    }
                }
            }
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    private void clearDirectory(java.io.File directory) {
        try {
            java.io.File[] files = directory.listFiles();
            if (files != null) {
                for (java.io.File file : files) {
                    if (file.isDirectory()) {
                        clearDirectory(file);
                    }
                    file.delete();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Add more methods for menu creation, page switching, etc.
} 