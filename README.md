# 🐻 BearMod - PUBG Mobile Enhanced Gameplay

[![Version](https://img.shields.io/badge/version-3.8.0-blue.svg)](https://github.com/BearMod/releases)
[![Android](https://img.shields.io/badge/android-10%2B-green.svg)](https://developer.android.com)
[![Architecture](https://img.shields.io/badge/arch-ARM64--v8a-orange.svg)](https://developer.android.com/ndk)

Advanced game enhancement tool for PUBG Mobile with ESP, aimbot, and performance optimizations.

## 📱 System Requirements

- **Android Version**: 10+ (API 29+)
- **Architecture**: ARM64-v8a (64-bit devices)
- **RAM**: 4GB+ recommended
- **Storage**: 50MB free space
- **Device Support**: Chinese ROMs prioritized (Realme, iQOO, Honor, RedMagic, Lenovo, Redmi/POCO)

## 🚀 Installation

### Option 1: LD Player (Recommended for Testing)
1. Install LD Player emulator
2. Enable Developer Options and USB Debugging
3. Install APK: `adb install app-release.apk`

### Option 2: Physical Device
1. Enable **Developer Options** in Settings
2. Turn on **USB Debugging** 
3. Allow **Unknown Sources** for APK installation
4. Install the APK file

## 📦 APK Versions

- **Release**: `app-release.apk` (12MB) - Optimized for production
- **Debug**: `app-debug.apk` (14MB) - For development/testing

## ✨ Features

### 🎯 Core Functionality
- **ESP (Extra Sensory Perception)**: Visual overlays for enhanced gameplay awareness
- **Aimbot**: Precision targeting assistance  
- **Floating Menu**: Easy access overlay interface
- **Performance Optimization**: Dynamic FPS scaling (60-144 FPS support)

### 🔧 Android 10+ Compatibility
- Modern API compliance (API 29-35)
- Display cutout handling
- Overlay permission management
- Background service optimization

### 📱 Chinese ROM Support  
- **Realme/OnePlus**: ColorOS optimizations
- **iQOO/Vivo**: FuntouchOS/OriginOS support
- **Honor**: MagicUI compatibility
- **RedMagic**: Nubia UI enhancements
- **Lenovo**: ZUI optimizations
- **Redmi/POCO**: MIUI variants support

### 🛡️ Bypass Features
- **Screen Recording Detection**: Evades recording app detection
- **Anti-Ban Protection**: RecorderFakeUtils implementation
- **Root Bypass**: Works on non-rooted devices

## 🎮 Performance Settings

- **Gaming Mode**: Full device FPS (60-144 Hz)
- **Configuration Mode**: Reduced FPS (30-60 Hz) for battery saving
- **Memory Optimization**: Reduced impact from 5% to 2-3%

## 🔨 Building from Source

### Prerequisites
- Android Studio 2024.1+
- Android SDK 34+
- NDK 27.1.12297006
- JDK 17+
- Gradle 8.10.1+

### Build Commands
```bash
# Clean build
.\gradlew clean

# Debug APK
.\gradlew assembleDebug

# Release APK  
.\gradlew assembleRelease
```

### Native Library Build
Note: NDK build may encounter file locking issues on Windows. The APK builds successfully without native libraries for core functionality.

## 📋 Configuration

### Overlay Permissions
1. Grant **Display over other apps** permission
2. Allow **Background app refresh**
3. Disable **Battery optimization** for BearMod

### Game Integration
1. Launch BearMod first
2. Open PUBG Mobile
3. Use floating icon to access menu
4. Configure features as needed

## ⚠️ Important Notes

- **Use Responsibly**: Follow game terms of service
- **Performance**: Optimized for 80% Chinese student user base
- **Compatibility**: Primarily tested on PUBG Mobile
- **Updates**: Check for latest versions regularly

## 🛠️ Troubleshooting

### Common Issues
- **Overlay not showing**: Check display permissions
- **Game crashes**: Verify Android 10+ compatibility
- **Performance drops**: Adjust FPS settings in menu
- **Build errors**: Clear Gradle cache and rebuild

### Device-Specific Fixes
- **Realme/OnePlus**: Enable "Allow display over other apps"
- **Xiaomi/Redmi**: Disable MIUI optimizations
- **Honor**: Allow background activity
- **Vivo/iQOO**: Grant system alert window permission

## 📚 Technical Details

### Architecture
- **Main Application**: Java/Kotlin overlay system
- **Native Libraries**: C++ game hooks and memory patches  
- **Bypass Systems**: Multi-layer detection avoidance
- **Performance Engine**: Dynamic resource management

### Key Components
- `MainActivity.java`: App initialization and permissions
- `Floating.java`: Main overlay interface (2204 lines)
- `RecorderFakeUtils.java`: Bypass detection system
- `Launcher.java`: KeyAuth integration
- `ESPView.java`: Visual overlay rendering

## 🔄 Version History

- **v3.8.0**: Android 10+ compatibility, Chinese ROM support, performance optimization
- **v3.7.x**: Core ESP and aimbot functionality
- **v3.6.x**: Initial floating menu implementation

## 📞 Support

For issues or questions:
1. Check troubleshooting section
2. Verify device compatibility  
3. Ensure proper permissions granted
4. Test on LD Player emulator first

---
**Disclaimer**: This tool is for educational purposes. Users are responsible for compliance with game terms of service and local laws. 