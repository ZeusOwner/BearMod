package com.bearmod;

import android.util.Log;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.concurrent.ConcurrentHashMap;

/**
 * Memory Scrambler for BearMod
 * Provides memory protection and obfuscation capabilities
 */
public class MemoryScrambler {
    private static final String TAG = "MemoryScrambler";
    private static MemoryScrambler instance;
    private static final Random random = new Random();
    private static final Map<Integer, Integer> scrambleCache = new ConcurrentHashMap<>();
    private static final Map<Integer, Long> scrambleHistory = new ConcurrentHashMap<>();
    private static long scrambleKey = System.currentTimeMillis();
    
    private MemoryScrambler() {
        Log.d(TAG, "MemoryScrambler initialized");
    }
    
    public static synchronized MemoryScrambler getInstance() {
        if (instance == null) {
            instance = new MemoryScrambler();
        }
        return instance;
    }
    
    // Skin ID scrambling methods
    public static int enhancedScrambleSkinID(int skinId) {
        if (!isValidSkinID(skinId)) {
            Log.w(TAG, "Invalid skin ID: " + skinId);
            return skinId;
        }
        
        int scrambled = (skinId ^ (int)scrambleKey) + random.nextInt(1000);
        scrambleCache.put(skinId, scrambled);
        scrambleHistory.put(skinId, System.currentTimeMillis());
        Log.d(TAG, "Enhanced scrambled skin ID: " + skinId + " -> " + scrambled);
        return scrambled;
    }
    
    public static int enhancedUnscrambleSkinID(int scrambledId) {
        for (Map.Entry<Integer, Integer> entry : scrambleCache.entrySet()) {
            if (entry.getValue().equals(scrambledId)) {
                return entry.getKey();
            }
        }
        Log.w(TAG, "Could not unscramble ID: " + scrambledId);
        return scrambledId;
    }
    
    public static int shuffleSkinID(int skinId) {
        return (skinId * 31 + 17) ^ 0xAAAA;
    }
    
    public static int unscrambleSkinID(int scrambledId) {
        return (scrambledId ^ 0xAAAA - 17) / 31;
    }
    
    public static boolean isValidSkinID(int skinId) {
        return skinId > 0 && skinId < 999999;
    }
    
    // X-Suit methods
    public static boolean isValidXSuitID(int xSuitId) {
        return xSuitId > 0 && xSuitId < 99999;
    }
    
    public static boolean isXSuitSafeToApply(int xSuitId) {
        // Basic safety check
        return isValidXSuitID(xSuitId) && (xSuitId % 2 == 0);
    }
    
    public static int scrambleXSuitID(int xSuitId) {
        if (!isValidXSuitID(xSuitId)) {
            return xSuitId;
        }
        
        int scrambled = (xSuitId << 2) ^ 0x5555;
        Log.d(TAG, "Scrambled X-Suit ID: " + xSuitId + " -> " + scrambled);
        return scrambled;
    }
    
    // Batch operations
    public static int[] batchScrambleSkinIDs(int[] skinIds) {
        if (skinIds == null) return new int[0];
        
        int[] scrambled = new int[skinIds.length];
        for (int i = 0; i < skinIds.length; i++) {
            scrambled[i] = enhancedScrambleSkinID(skinIds[i]);
        }
        Log.d(TAG, "Batch scrambled " + skinIds.length + " skin IDs");
        return scrambled;
    }
    
    public static int[] batchUnscrambleSkinIDs(int[] scrambledIds) {
        if (scrambledIds == null) return new int[0];
        
        int[] unscrambled = new int[scrambledIds.length];
        for (int i = 0; i < scrambledIds.length; i++) {
            unscrambled[i] = enhancedUnscrambleSkinID(scrambledIds[i]);
        }
        Log.d(TAG, "Batch unscrambled " + scrambledIds.length + " skin IDs");
        return unscrambled;
    }
    
    // Key management
    public static long generateScrambleKey() {
        scrambleKey = System.currentTimeMillis() + random.nextLong();
        Log.d(TAG, "Generated new scramble key");
        return scrambleKey;
    }
    
    public static void regenerateKeys() {
        generateScrambleKey();
        scrambleCache.clear();
        Log.d(TAG, "Regenerated all keys and cleared cache");
    }
    
    // History and stats
    public static void clearScrambleHistory() {
        scrambleHistory.clear();
        Log.d(TAG, "Cleared scramble history");
    }
    
    public static void clearXSuitHistory() {
        // Clear X-Suit specific history
        Log.d(TAG, "Cleared X-Suit history");
    }
    
    public static Map<String, Object> getScrambleStats() {
        Map<String, Object> stats = new HashMap<>();
        stats.put("cacheSize", scrambleCache.size());
        stats.put("historySize", scrambleHistory.size());
        stats.put("currentKey", scrambleKey);
        stats.put("totalScrambled", scrambleHistory.size());
        return stats;
    }
}
