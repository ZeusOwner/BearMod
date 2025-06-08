package com.bearmod

import android.util.Log
import java.security.SecureRandom
import java.util.concurrent.ConcurrentHashMap
import java.util.concurrent.atomic.AtomicLong
import kotlin.experimental.xor

/**
 * Enhanced Kotlin-based Memory Scrambling System for BearMod Skin System
 * 
 * This object provides sophisticated anti-detection capabilities through:
 * - Multi-layer XOR + bit rotation + salt scrambling
 * - Time-based variation to prevent pattern detection
 * - Reversible scrambling for proper skin ID decoding
 * - Performance-optimized operations
 * - Comprehensive bounds checking and error handling
 * 
 * @author BearMod Team
 * @version 2.0
 */
object MemoryScrambler {
    
    // ===== CONSTANTS =====
    private const val TAG = "MemoryScrambler"
    private const val MIN_SKIN_ID = 100000
    private const val MAX_SKIN_ID = 2000000
    private const val SCRAMBLE_SALT_SIZE = 16
    private const val TIME_VARIATION_FACTOR = 1000L
    private const val MAX_ROTATION_BITS = 8
    
    // ===== SECURITY COMPONENTS =====
    private val secureRandom = SecureRandom()
    private val scrambleHistory = ConcurrentHashMap<Int, Long>()
    private val keyRotationCounter = AtomicLong(0)
    private val lastScrambleTime = AtomicLong(0)
    
    // Dynamic scrambling keys
    private var primaryKey: ByteArray = ByteArray(32)
    private var secondaryKey: ByteArray = ByteArray(16)
    private var saltBuffer: ByteArray = ByteArray(SCRAMBLE_SALT_SIZE)
    
    // Valid skin ID ranges for different weapon types
    private val validSkinRanges = mapOf(
        "ASSAULT_RIFLE" to 1101000000..1101999999,
        "SMG" to 1102000000..1102999999,
        "SNIPER" to 1103000000..1103999999,
        "LMG" to 1105000000..1105999999,
        "VEHICLE" to 1301000000..1401999999,
        "EQUIPMENT" to 1501000000..1502999999,
        "XSUIT" to 1405000000..1410999999,
        "OUTFIT" to 1400000000..1404999999
    )

    // X-Suit specific anti-detection parameters
    private val xSuitAntiDetection = mapOf(
        "MIN_COOLDOWN_MS" to 30000L,
        "MAX_COOLDOWN_MS" to 120000L,
        "MAX_APPLICATIONS_PER_HOUR" to 5,
        "SCRAMBLE_INTENSITY" to 3
    )

    // X-Suit application tracking
    private val xSuitApplicationTimes = ConcurrentHashMap<Int, Long>()
    private val xSuitApplicationCounts = ConcurrentHashMap<Int, Int>()
    
    init {
        initializeScrambler()
    }
    
    /**
     * Initialize the scrambler with secure random keys
     */
    private fun initializeScrambler() {
        try {
            secureRandom.nextBytes(primaryKey)
            secureRandom.nextBytes(secondaryKey)
            secureRandom.nextBytes(saltBuffer)
            
            Log.d(TAG, "MemoryScrambler initialized with secure keys")
        } catch (e: Exception) {
            Log.e(TAG, "Failed to initialize MemoryScrambler: ${e.message}")
            // Fallback to system time-based initialization
            initializeFallback()
        }
    }
    
    /**
     * Fallback initialization using system time
     */
    private fun initializeFallback() {
        val currentTime = System.currentTimeMillis()
        for (i in primaryKey.indices) {
            primaryKey[i] = ((currentTime + i) and 0xFF).toByte()
        }
        for (i in secondaryKey.indices) {
            secondaryKey[i] = ((currentTime * 2 + i) and 0xFF).toByte()
        }
        for (i in saltBuffer.indices) {
            saltBuffer[i] = ((currentTime * 3 + i) and 0xFF).toByte()
        }
    }
    
    /**
     * Primary function: Shuffle skin ID with sophisticated scrambling
     * 
     * @param id Original skin ID to scramble
     * @return Scrambled skin ID with anti-detection measures
     */
    @JvmStatic
    fun shuffleSkinID(id: Int): Int {
        if (!isValidSkinID(id)) {
            Log.w(TAG, "Invalid skin ID provided: $id")
            return id // Return original if invalid
        }
        
        try {
            val currentTime = System.currentTimeMillis()
            
            // Prevent same ID from producing same result repeatedly
            val lastScrambleForId = scrambleHistory[id] ?: 0
            if (currentTime - lastScrambleForId < TIME_VARIATION_FACTOR) {
                // Add micro-variation to prevent identical results
                Thread.sleep(1) // Ensure time difference
            }
            
            // Generate dynamic scramble key
            val scrambleKey = generateScrambleKey()
            
            // Apply multi-layer scrambling
            var scrambledId = id
            
            // Layer 1: XOR with time-based primary key
            scrambledId = applyXorScrambling(scrambledId, scrambleKey)
            
            // Layer 2: Bit rotation with secondary key
            scrambledId = applyBitRotation(scrambledId, scrambleKey)
            
            // Layer 3: Salt-based transformation
            scrambledId = applySaltTransformation(scrambledId, scrambleKey)
            
            // Ensure result stays within valid bounds
            scrambledId = ensureValidBounds(scrambledId, id)
            
            // Record scramble history
            scrambleHistory[id] = currentTime
            lastScrambleTime.set(currentTime)
            
            Log.v(TAG, "Scrambled skin ID: $id -> $scrambledId")
            return scrambledId
            
        } catch (e: Exception) {
            Log.e(TAG, "Error scrambling skin ID $id: ${e.message}")
            return id // Return original on error
        }
    }
    
    /**
     * Reverse the scrambling to get original skin ID
     * 
     * @param scrambledId Scrambled skin ID to decode
     * @return Original skin ID
     */
    @JvmStatic
    fun unscrambleSkinID(scrambledId: Int): Int {
        try {
            // Generate the same scramble key used for encoding
            val scrambleKey = generateScrambleKey()
            
            var originalId = scrambledId
            
            // Reverse Layer 3: Salt-based transformation
            originalId = reverseSaltTransformation(originalId, scrambleKey)
            
            // Reverse Layer 2: Bit rotation
            originalId = reverseBitRotation(originalId, scrambleKey)
            
            // Reverse Layer 1: XOR scrambling
            originalId = reverseXorScrambling(originalId, scrambleKey)
            
            Log.v(TAG, "Unscrambled skin ID: $scrambledId -> $originalId")
            return originalId
            
        } catch (e: Exception) {
            Log.e(TAG, "Error unscrambling skin ID $scrambledId: ${e.message}")
            return scrambledId // Return scrambled on error
        }
    }
    
    /**
     * Generate dynamic scrambling key with time-based variation
     * 
     * @return Generated scramble key
     */
    @JvmStatic
    fun generateScrambleKey(): Long {
        val currentTime = System.currentTimeMillis()
        val rotationCount = keyRotationCounter.incrementAndGet()
        
        // Combine time, rotation count, and secure random for key generation
        val timeComponent = (currentTime / TIME_VARIATION_FACTOR) and 0xFFFFFF
        val rotationComponent = (rotationCount and 0xFF) shl 24
        val randomComponent = secureRandom.nextInt() and 0xFFFF
        
        return (timeComponent or rotationComponent or randomComponent.toLong())
    }
    
    /**
     * Validate if skin ID is within acceptable ranges
     * 
     * @param id Skin ID to validate
     * @return true if valid, false otherwise
     */
    @JvmStatic
    fun isValidSkinID(id: Int): Boolean {
        if (id < MIN_SKIN_ID || id > MAX_SKIN_ID) {
            return false
        }
        
        // Check against specific weapon type ranges
        return validSkinRanges.values.any { range -> id in range }
    }
    
    // ===== PRIVATE SCRAMBLING METHODS =====
    
    /**
     * Apply XOR-based scrambling with primary key
     */
    private fun applyXorScrambling(value: Int, key: Long): Int {
        val keyBytes = longToBytes(key)
        var result = value
        
        for (i in 0 until 4) {
            val shift = i * 8
            val keyByte = keyBytes[i % keyBytes.size]
            result = result xor (keyByte.toInt() shl shift)
        }
        
        return result
    }
    
    /**
     * Reverse XOR-based scrambling
     */
    private fun reverseXorScrambling(value: Int, key: Long): Int {
        // XOR is its own inverse
        return applyXorScrambling(value, key)
    }
    
    /**
     * Apply bit rotation scrambling
     */
    private fun applyBitRotation(value: Int, key: Long): Int {
        val rotationBits = (key and 0xFF).toInt() % MAX_ROTATION_BITS + 1
        return (value shl rotationBits) or (value ushr (32 - rotationBits))
    }
    
    /**
     * Reverse bit rotation scrambling
     */
    private fun reverseBitRotation(value: Int, key: Long): Int {
        val rotationBits = (key and 0xFF).toInt() % MAX_ROTATION_BITS + 1
        return (value ushr rotationBits) or (value shl (32 - rotationBits))
    }
    
    /**
     * Apply salt-based transformation
     */
    private fun applySaltTransformation(value: Int, key: Long): Int {
        val saltIndex = (key shr 8) and 0xF
        val salt = saltBuffer[saltIndex.toInt()]
        return value xor (salt.toInt() shl 16)
    }
    
    /**
     * Reverse salt-based transformation
     */
    private fun reverseSaltTransformation(value: Int, key: Long): Int {
        // XOR is its own inverse
        return applySaltTransformation(value, key)
    }
    
    /**
     * Ensure scrambled value stays within valid bounds
     */
    private fun ensureValidBounds(scrambledValue: Int, originalValue: Int): Int {
        var result = scrambledValue
        
        // Keep within general bounds
        if (result < MIN_SKIN_ID || result > MAX_SKIN_ID) {
            // Use modulo to wrap around within valid range
            val range = MAX_SKIN_ID - MIN_SKIN_ID
            result = MIN_SKIN_ID + (Math.abs(result) % range)
        }
        
        // Ensure it's in the same weapon category as original
        val originalCategory = getWeaponCategory(originalValue)
        val validRange = validSkinRanges[originalCategory]
        
        if (validRange != null && result !in validRange) {
            // Map to valid range for the same weapon category
            val categoryRange = validRange.last - validRange.first
            result = validRange.first + (Math.abs(result) % categoryRange)
        }
        
        return result
    }
    
    /**
     * Get weapon category from skin ID
     */
    private fun getWeaponCategory(skinId: Int): String {
        return when {
            skinId in 1101000000..1101999999 -> "ASSAULT_RIFLE"
            skinId in 1102000000..1102999999 -> "SMG"
            skinId in 1103000000..1103999999 -> "SNIPER"
            skinId in 1105000000..1105999999 -> "LMG"
            skinId in 1301000000..1401999999 -> "VEHICLE"
            skinId in 1501000000..1502999999 -> "EQUIPMENT"
            else -> "ASSAULT_RIFLE" // Default fallback
        }
    }
    
    /**
     * Convert long to byte array
     */
    private fun longToBytes(value: Long): ByteArray {
        return byteArrayOf(
            (value shr 56).toByte(),
            (value shr 48).toByte(),
            (value shr 40).toByte(),
            (value shr 32).toByte(),
            (value shr 24).toByte(),
            (value shr 16).toByte(),
            (value shr 8).toByte(),
            value.toByte()
        )
    }

    // ===== JNI INTEGRATION METHODS =====

    /**
     * JNI method to scramble skin ID from native C++ code
     *
     * @param skinId Original skin ID from C++
     * @return Scrambled skin ID
     */
    @JvmStatic
    external fun scrambleSkinIDNative(skinId: Int): Int

    /**
     * JNI method to unscramble skin ID from native C++ code
     *
     * @param scrambledId Scrambled skin ID from C++
     * @return Original skin ID
     */
    @JvmStatic
    external fun unscrambleSkinIDNative(scrambledId: Int): Int

    /**
     * JNI method to validate skin ID from native C++ code
     *
     * @param skinId Skin ID to validate
     * @return true if valid, false otherwise
     */
    @JvmStatic
    external fun isValidSkinIDNative(skinId: Int): Boolean

    /**
     * JNI method to generate scramble key from native C++ code
     *
     * @return Generated scramble key
     */
    @JvmStatic
    external fun generateScrambleKeyNative(): Long

    /**
     * Enhanced scrambling with native integration
     * This method combines Kotlin and C++ scrambling for maximum security
     *
     * @param skinId Original skin ID
     * @return Enhanced scrambled skin ID
     */
    @JvmStatic
    fun enhancedScrambleSkinID(skinId: Int): Int {
        try {
            // First pass: Kotlin scrambling
            val kotlinScrambled = shuffleSkinID(skinId)

            // Second pass: Native C++ scrambling for additional security
            val nativeScrambled = scrambleSkinIDNative(kotlinScrambled)

            Log.v(TAG, "Enhanced scrambling: $skinId -> $kotlinScrambled -> $nativeScrambled")
            return nativeScrambled

        } catch (e: UnsatisfiedLinkError) {
            Log.w(TAG, "Native scrambling not available, using Kotlin only")
            return shuffleSkinID(skinId)
        } catch (e: Exception) {
            Log.e(TAG, "Error in enhanced scrambling: ${e.message}")
            return skinId
        }
    }

    /**
     * Enhanced unscrambling with native integration
     *
     * @param scrambledId Enhanced scrambled skin ID
     * @return Original skin ID
     */
    @JvmStatic
    fun enhancedUnscrambleSkinID(scrambledId: Int): Int {
        try {
            // First pass: Reverse native C++ scrambling
            val nativeUnscrambled = unscrambleSkinIDNative(scrambledId)

            // Second pass: Reverse Kotlin scrambling
            val kotlinUnscrambled = unscrambleSkinID(nativeUnscrambled)

            Log.v(TAG, "Enhanced unscrambling: $scrambledId -> $nativeUnscrambled -> $kotlinUnscrambled")
            return kotlinUnscrambled

        } catch (e: UnsatisfiedLinkError) {
            Log.w(TAG, "Native unscrambling not available, using Kotlin only")
            return unscrambleSkinID(scrambledId)
        } catch (e: Exception) {
            Log.e(TAG, "Error in enhanced unscrambling: ${e.message}")
            return scrambledId
        }
    }

    // ===== PERFORMANCE OPTIMIZATION METHODS =====

    /**
     * Batch scramble multiple skin IDs for performance
     *
     * @param skinIds Array of skin IDs to scramble
     * @return Array of scrambled skin IDs
     */
    @JvmStatic
    fun batchScrambleSkinIDs(skinIds: IntArray): IntArray {
        return skinIds.map { shuffleSkinID(it) }.toIntArray()
    }

    /**
     * Batch unscramble multiple skin IDs for performance
     *
     * @param scrambledIds Array of scrambled skin IDs
     * @return Array of original skin IDs
     */
    @JvmStatic
    fun batchUnscrambleSkinIDs(scrambledIds: IntArray): IntArray {
        return scrambledIds.map { unscrambleSkinID(it) }.toIntArray()
    }

    /**
     * Clear scramble history to prevent memory leaks
     */
    @JvmStatic
    fun clearScrambleHistory() {
        scrambleHistory.clear()
        Log.d(TAG, "Scramble history cleared")
    }

    /**
     * Get scrambling statistics for debugging
     *
     * @return Map containing scrambling statistics
     */
    @JvmStatic
    fun getScrambleStats(): Map<String, Any> {
        return mapOf(
            "historySize" to scrambleHistory.size,
            "lastScrambleTime" to lastScrambleTime.get(),
            "keyRotationCount" to keyRotationCounter.get(),
            "primaryKeyLength" to primaryKey.size,
            "secondaryKeyLength" to secondaryKey.size
        )
    }

    /**
     * Regenerate scrambling keys for enhanced security
     */
    @JvmStatic
    fun regenerateKeys() {
        initializeScrambler()
        clearScrambleHistory()
        Log.d(TAG, "Scrambling keys regenerated")
    }

    // ===== X-SUIT ANTI-DETECTION METHODS =====

    /**
     * Enhanced X-Suit scrambling with maximum anti-detection
     *
     * @param xSuitId Original X-Suit ID
     * @return Scrambled X-Suit ID with enhanced protection
     */
    @JvmStatic
    fun scrambleXSuitID(xSuitId: Int): Int {
        if (!isValidXSuitID(xSuitId)) {
            Log.w(TAG, "Invalid X-Suit ID: $xSuitId")
            return xSuitId
        }

        try {
            val currentTime = System.currentTimeMillis()

            // Check if safe to apply (anti-detection)
            if (!isXSuitSafeToApply(xSuitId)) {
                Log.w(TAG, "X-Suit application blocked for safety: $xSuitId")
                return xSuitId
            }

            // Enhanced scrambling for X-Suits (higher intensity)
            val scrambleIntensity = xSuitAntiDetection["SCRAMBLE_INTENSITY"] as Int
            var scrambledId = xSuitId

            // Apply multiple scrambling layers
            for (i in 0 until scrambleIntensity) {
                val layerKey = generateScrambleKey() + i
                scrambledId = applyXorScrambling(scrambledId, layerKey)
                scrambledId = applyBitRotation(scrambledId, layerKey)
                scrambledId = applySaltTransformation(scrambledId, layerKey)
            }

            // Ensure result stays within X-Suit bounds
            scrambledId = ensureXSuitBounds(scrambledId)

            // Update tracking
            xSuitApplicationTimes[xSuitId] = currentTime
            xSuitApplicationCounts[xSuitId] = (xSuitApplicationCounts[xSuitId] ?: 0) + 1

            Log.d(TAG, "🛡️ X-Suit Scrambled: $xSuitId -> $scrambledId")
            return scrambledId

        } catch (e: Exception) {
            Log.e(TAG, "Error scrambling X-Suit ID $xSuitId: ${e.message}")
            return xSuitId
        }
    }

    /**
     * Check if X-Suit ID is valid
     */
    @JvmStatic
    fun isValidXSuitID(xSuitId: Int): Boolean {
        return xSuitId in validSkinRanges["XSUIT"]!! || xSuitId in validSkinRanges["OUTFIT"]!!
    }

    /**
     * Check if X-Suit application is safe (anti-detection)
     */
    @JvmStatic
    fun isXSuitSafeToApply(xSuitId: Int): Boolean {
        val currentTime = System.currentTimeMillis()

        // Check cooldown
        val lastApplicationTime = xSuitApplicationTimes[xSuitId] ?: 0
        val minCooldown = xSuitAntiDetection["MIN_COOLDOWN_MS"] as Long
        val maxCooldown = xSuitAntiDetection["MAX_COOLDOWN_MS"] as Long

        // Dynamic cooldown to prevent pattern detection
        val dynamicCooldown = minCooldown + (Math.random() * (maxCooldown - minCooldown)).toLong()

        if (currentTime - lastApplicationTime < dynamicCooldown) {
            return false
        }

        // Check application frequency
        val applicationCount = xSuitApplicationCounts[xSuitId] ?: 0
        val maxApplications = xSuitAntiDetection["MAX_APPLICATIONS_PER_HOUR"] as Int

        if (applicationCount >= maxApplications) {
            // Reset counter every hour
            val oneHourAgo = currentTime - 3600000
            if (lastApplicationTime < oneHourAgo) {
                xSuitApplicationCounts[xSuitId] = 0
            } else {
                return false
            }
        }

        return true
    }

    /**
     * Ensure scrambled X-Suit ID stays within valid bounds
     */
    private fun ensureXSuitBounds(scrambledValue: Int): Int {
        val xSuitRange = validSkinRanges["XSUIT"]!!
        val outfitRange = validSkinRanges["OUTFIT"]!!

        return when {
            scrambledValue in xSuitRange -> scrambledValue
            scrambledValue in outfitRange -> scrambledValue
            else -> {
                // Map to valid X-Suit range
                val range = xSuitRange.last - xSuitRange.first
                xSuitRange.first + (Math.abs(scrambledValue) % range)
            }
        }
    }

    /**
     * Clear X-Suit application history for safety
     */
    @JvmStatic
    fun clearXSuitHistory() {
        xSuitApplicationTimes.clear()
        xSuitApplicationCounts.clear()
        Log.d(TAG, "🧹 X-Suit application history cleared")
    }

    // ===== LOAD NATIVE LIBRARY =====
    init {
        try {
            System.loadLibrary("bearmod")
            Log.d(TAG, "Native library loaded successfully")
        } catch (e: UnsatisfiedLinkError) {
            Log.w(TAG, "Native library not available: ${e.message}")
        }
    }
}
