# Drawable Files Cleanup Analysis

## 📊 **Current Status: 76 drawable files found**

After analyzing the current codebase, here's what's actually being used vs what can be cleaned up:

## ✅ **Currently Used Drawables (Keep These)**

### **SimpleFloating Service:**
- `icon.png` - Main floating icon image ✅
- `floating_icon_background.xml` - Icon background ✅
- `ic_close.xml` - Close button in menu ✅
- `sidebar_item_selector.xml` - Icon button backgrounds ✅
- `tab_selector.xml` - Tab button backgrounds ✅
- `premium_card_background.xml` - Menu background ✅

### **Login & Main Activity:**
- `edit_text_background.xml` - Login input field ✅
- `button_login_background.xml` - Login button ✅
- `button_start_background.xml` - Main activity buttons ✅
- `button_accent_background.xml` - Main activity buttons ✅
- `button_cancel_background.xml` - Main activity buttons ✅

### **App Icons (Required):**
- `ic_launcher.xml` - App launcher icon ✅
- `ic_launcher_background.xml` - Launcher background ✅
- `ic_launcher_foreground.xml` - Launcher foreground ✅

### **Styles & Components:**
- `seekbar_thumb.xml` - Used in styles ✅
- `seekbar_track.xml` - Used in styles ✅
- `seekbar_thumb_aimbot.xml` - Used in aimbot styles ✅
- `seekbar_track_aimbot.xml` - Used in aimbot styles ✅
- `tab_button_background.xml` - Used in styles ✅
- `value_display_background.xml` - Used in styles ✅
- `premium_button_primary.xml` - Used in styles ✅
- `button_outline_background.xml` - Used in styles ✅
- `modern_stepper_button.xml` - Used in styles ✅
- `modern_toggle_switch.xml` - Used in styles ✅
- `premium_slider_progress.xml` - Used in component ✅
- `premium_slider_thumb.xml` - Used in component ✅
- `toggle_selector.xml` - Toggle backgrounds ✅
- `toggle_on_bg.xml` - Toggle on state ✅
- `toggle_off_bg.xml` - Toggle off state ✅

**Total Used: 25 files**

## ❌ **Unused Drawables (Can Be Deleted)**

### **Old Complex UI System Leftovers:**
- `glass_morphism_background.xml` - From old complex menu ❌
- `main_panel_background.xml` - From old sidebar system ❌
- `sidebar_background.xml` - From old sidebar system ❌
- `glass_navigation_background.xml` - From old navigation ❌
- `nav_button_background.xml` - From old navigation ❌

### **Old Icons (Not Used in SimpleFloating):**
- `ic_settings_premium.xml` - Old sidebar icons ❌
- `ic_box_premium.xml` - Old sidebar icons ❌
- `ic_target_premium.xml` - Old sidebar icons ❌
- `ic_crosshair_premium.xml` - Old sidebar icons ❌
- `ic_menu_premium.xml` - Old sidebar icons ❌
- `ic_upload_modern.xml` - Not used ❌
- `ic_download_modern.xml` - Not used ❌
- `ic_game_controller.xml` - Not used ❌
- `ic_bear_logo.xml` - Not used ❌
- `ic_lock_modern.xml` - Not used ❌
- `ic_power_modern.xml` - Not used ❌
- `ic_visibility_off_modern.xml` - Not used ❌
- `ic_visibility_modern.xml` - Not used ❌
- `ic_speed_modern.xml` - Not used ❌
- `ic_shield_modern.xml` - Not used ❌
- `ic_weapon_modern.xml` - Not used ❌
- `ic_menu_dots.xml` - Not used ❌
- `ic_expand_less.xml` - Not used ❌
- `ic_expand_more.xml` - Not used ❌
- `ic_info_modern.xml` - Not used ❌
- `ic_warning_modern.xml` - Not used ❌
- `ic_premium_crown.xml` - Not used ❌
- `ic_status_connected.xml` - Not used ❌
- `ic_reset_modern.xml` - Not used ❌
- `ic_apply_modern.xml` - Not used ❌
- `ic_remove_modern.xml` - Not used ❌
- `ic_add_modern.xml` - Not used ❌
- `ic_skin_modern.xml` - Not used ❌
- `ic_settings_modern.xml` - Not used ❌
- `ic_items_modern.xml` - Not used ❌
- `ic_aimbot_modern.xml` - Not used ❌
- `ic_esp_modern.xml` - Not used ❌
- `ic_tab_hide.xml` - Old tab system ❌
- `ic_tab_skin.xml` - Old tab system ❌
- `ic_tab_aim.xml` - Old tab system ❌
- `ic_tab_esp.xml` - Old tab system ❌
- `ic_tab_main.xml` - Old tab system ❌
- `ic_remove.xml` - Old stepper system ❌
- `ic_add.xml` - Old stepper system ❌

### **Old Backgrounds & Styles:**
- `premium_main_background.xml` - From old system ❌
- `modern_button_danger.xml` - Not used ❌
- `modern_button_primary.xml` - Not used ❌
- `modern_stepper_modern.xml` - Not used ❌
- `combo_selector.xml` - Not used ❌
- `stepper_button_background.xml` - Old stepper ❌
- `icon_tint_selector.xml` - Not used ❌
- `content_pane_background.xml` - Old system ❌
- `menu_background.xml` - Old system ❌
- `dialog_background.xml` - Not used ❌

**Total Unused: 51 files**

## 🧹 **Cleanup Recommendation**

We can safely delete **51 unused drawable files** (67% of total) while keeping the **25 essential files** that the current system actually uses.

### **Benefits of Cleanup:**
1. **Reduced APK size** - Remove ~50KB+ of unused resources
2. **Cleaner project structure** - Easier to find relevant files
3. **Faster build times** - Less files to process
4. **Better maintainability** - No confusion about what's used

### **Safe to Delete Categories:**
1. **Old sidebar/navigation icons** (ic_*_premium.xml)
2. **Unused modern icons** (ic_*_modern.xml) 
3. **Old tab system icons** (ic_tab_*.xml)
4. **Old background files** (glass_*, main_panel_*, etc.)
5. **Unused button styles** (modern_button_*, etc.)

## 🎯 **Cleanup Action Plan**

1. **Phase 1:** Delete obvious old system files (sidebar, navigation, tabs)
2. **Phase 2:** Remove unused modern icons 
3. **Phase 3:** Clean up old background/style files
4. **Phase 4:** Test build to ensure nothing breaks

**Ready to start the drawable cleanup?** 🗑️ 