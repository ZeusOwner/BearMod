#!/bin/bash
# build.sh for BearMod (Java + C++)

cd "$(dirname "$0")"

# Make gradle wrapper executable
chmod +x ./gradlew

# Build debug APK
./gradlew assembleDebug --no-daemon
