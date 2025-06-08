package com.bearmod;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.Signature;
import android.util.Log;
import android.os.Build;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicLong;

/**
 * Enhanced Signature Verifier for BearMod
 * Provides comprehensive signature bypass and anti-detection measures
 * Alternative solution to avoid fixing libanogs crashes/black screen issues
 */
public class SignatureVerifier {
    private static final String TAG = "BearMod_SignatureVerifier";
    
    // Multiple expected signature hashes for different builds
    private static final List<String> EXPECTED_SIGNATURES = Arrays.asList(
        "your_expected_signature_hash_here",
        "fcb90d416dd2148f4287cbdd5", // MD5 from checksum
        "cd7fe12ade0fd15571d003bf15", // SHA1 from checksum
        "7e6a1d0165a629f9470ce3314", // SHA256 from checksum
        "9b1faa0d" // CRC32 from checksum
    );
    
    // Anti-detection parameters
    private static final Random secureRandom = new Random();
    private static volatile boolean bypassEnabled = true;
    private static volatile boolean debugMode = false;
    private static final AtomicBoolean isInitialized = new AtomicBoolean(false);
    private static final AtomicLong lastVerificationTime = new AtomicLong(0);
    
    // Integration with existing BearMod systems
    private static MemoryScrambler memoryScrambler;
    private static RecorderFakeUtils recorderUtils;

    /**
     * Initialize the signature verifier with enhanced security
     */
    public static void initialize(Context context) {
        if (isInitialized.compareAndSet(false, true)) {
            try {
                // Initialize integration components
                try {
                    memoryScrambler = MemoryScrambler.getInstance();
                    recorderUtils = new RecorderFakeUtils(context);
                } catch (Exception e) {
                    // Graceful fallback if components not available
                    Log.d(TAG, "Some integration components not available (expected)");
                }
                
                Log.d(TAG, "Enhanced SignatureVerifier initialized");
            } catch (Exception e) {
                Log.e(TAG, "Error initializing SignatureVerifier", e);
            }
        }
    }

    /**
     * Main signature verification method with enhanced bypass
     * This is the primary method to replace original signature checks
     *
     * @param context Application context
     * @return true if signature is valid (always true for bypass)
     */
    public static boolean isSignatureValid(Context context) {
        try {
            // Initialize if not already done
            if (!isInitialized.get()) {
                initialize(context);
            }
            
            // Anti-detection timing randomization
            long currentTime = System.currentTimeMillis();
            long lastTime = lastVerificationTime.get();
            
            // Add random delay to prevent timing analysis
            if (currentTime - lastTime < 100) {
                try {
                    Thread.sleep(secureRandom.nextInt(50) + 10); // 10-60ms delay
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
            lastVerificationTime.set(currentTime);
            
            // Enhanced bypass logic
            if (bypassEnabled) {
                if (debugMode) {
                    String signatureHex = getSignatureHex(context);
                    Log.d(TAG, "Signature verification bypassed - Current signature: " + signatureHex);
                }
                
                // Memory scrambling for additional protection
                if (memoryScrambler != null) {
                    // Use memory scrambler to obfuscate the bypass
                    int scrambledResult = memoryScrambler.shuffleSkinID(1); // Use 1 as success indicator
                    return scrambledResult > 0;
                }
                
                return true; // Always return true for bypass
            }
            
            // Fallback to actual verification (disabled by default)
            return performActualVerification(context);
            
        } catch (Exception e) {
            Log.e(TAG, "Error in signature verification", e);
            return true; // Return true even on error for bypass
        }
    }

    /**
     * Alternative verification method for different signature check scenarios
     */
    public static boolean verifyAppIntegrity(Context context) {
        return isSignatureValid(context); // Delegate to main method
    }

    /**
     * Check if app is properly signed (always returns true for bypass)
     */
    public static boolean isAppSigned(Context context) {
        return isSignatureValid(context);
    }

    /**
     * Verify package signature (bypass method)
     */
    public static boolean verifyPackageSignature(Context context, String packageName) {
        try {
            if (packageName == null) {
                packageName = context.getPackageName();
            }
            
            // Log the attempt but always return true
            if (debugMode) {
                Log.d(TAG, "Package signature verification bypassed for: " + packageName);
            }
            
            return true; // Always return true for bypass
        } catch (Exception e) {
            Log.e(TAG, "Error in package signature verification", e);
            return true; // Return true even on error
        }
    }

    /**
     * Gets the app's signature hash as a hexadecimal string
     * Enhanced with multiple hash algorithms
     *
     * @param context Application context
     * @return Signature hash as hex string, or empty string if error occurs
     */
    public static String getSignatureHex(Context context) {
        return getSignatureHex(context, "SHA-256");
    }

    /**
     * Gets the app's signature hash with specified algorithm
     */
    public static String getSignatureHex(Context context, String algorithm) {
        try {
            PackageInfo packageInfo = context.getPackageManager().getPackageInfo(
                    context.getPackageName(), PackageManager.GET_SIGNATURES);
            
            if (packageInfo.signatures != null && packageInfo.signatures.length > 0) {
                Signature signature = packageInfo.signatures[0];
                return getHash(signature.toByteArray(), algorithm);
            }
        } catch (PackageManager.NameNotFoundException e) {
            Log.e(TAG, "Package not found", e);
        } catch (Exception e) {
            Log.e(TAG, "Error getting signature", e);
        }
        
        return "";
    }

    /**
     * Get all signature hashes (MD5, SHA1, SHA256, CRC32)
     */
    public static SignatureInfo getAllSignatureHashes(Context context) {
        try {
            PackageInfo packageInfo = context.getPackageManager().getPackageInfo(
                    context.getPackageName(), PackageManager.GET_SIGNATURES);
            
            if (packageInfo.signatures != null && packageInfo.signatures.length > 0) {
                Signature signature = packageInfo.signatures[0];
                byte[] signatureBytes = signature.toByteArray();
                
                return new SignatureInfo(
                    getHash(signatureBytes, "MD5"),
                    getHash(signatureBytes, "SHA-1"),
                    getHash(signatureBytes, "SHA-256"),
                    getCRC32(signatureBytes)
                );
            }
        } catch (Exception e) {
            Log.e(TAG, "Error getting all signature hashes", e);
        }
        
        return new SignatureInfo("", "", "", "");
    }

    /**
     * Perform actual signature verification (disabled by default)
     */
    private static boolean performActualVerification(Context context) {
        try {
            String currentSignature = getSignatureHex(context);
            
            // Check against all expected signatures
            for (String expectedSig : EXPECTED_SIGNATURES) {
                if (expectedSig.equalsIgnoreCase(currentSignature)) {
                    return true;
                }
            }
            
            // Check with different algorithms
            SignatureInfo sigInfo = getAllSignatureHashes(context);
            return EXPECTED_SIGNATURES.contains(sigInfo.md5) ||
                   EXPECTED_SIGNATURES.contains(sigInfo.sha1) ||
                   EXPECTED_SIGNATURES.contains(sigInfo.sha256) ||
                   EXPECTED_SIGNATURES.contains(sigInfo.crc32);
                   
        } catch (Exception e) {
            Log.e(TAG, "Error in actual verification", e);
            return false;
        }
    }

    /**
     * Computes hash of the given data with specified algorithm
     */
    private static String getHash(byte[] data, String algorithm) {
        try {
            MessageDigest digest = MessageDigest.getInstance(algorithm);
            byte[] hash = digest.digest(data);
            return bytesToHex(hash);
        } catch (NoSuchAlgorithmException e) {
            Log.e(TAG, algorithm + " algorithm not found", e);
            return "";
        }
    }

    /**
     * Compute CRC32 checksum
     */
    private static String getCRC32(byte[] data) {
        try {
            java.util.zip.CRC32 crc32 = new java.util.zip.CRC32();
            crc32.update(data);
            return String.format("%08x", crc32.getValue());
        } catch (Exception e) {
            Log.e(TAG, "Error computing CRC32", e);
            return "";
        }
    }

    /**
     * Converts byte array to hexadecimal string
     */
    private static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }

    /**
     * Enable or disable signature bypass
     */
    public static void setBypassEnabled(boolean enabled) {
        bypassEnabled = enabled;
        Log.d(TAG, "Signature bypass " + (enabled ? "enabled" : "disabled"));
    }

    /**
     * Enable or disable debug mode
     */
    public static void setDebugMode(boolean enabled) {
        debugMode = enabled;
        Log.d(TAG, "Debug mode " + (enabled ? "enabled" : "disabled"));
    }

    /**
     * Check if bypass is currently enabled
     */
    public static boolean isBypassEnabled() {
        return bypassEnabled;
    }

    /**
     * Get signature verification statistics
     */
    public static String getVerificationStats(Context context) {
        try {
            SignatureInfo sigInfo = getAllSignatureHashes(context);
            return String.format(
                "Signature Stats:\n" +
                "MD5: %s\n" +
                "SHA1: %s\n" +
                "SHA256: %s\n" +
                "CRC32: %s\n" +
                "Bypass: %s\n" +
                "Debug: %s",
                sigInfo.md5, sigInfo.sha1, sigInfo.sha256, sigInfo.crc32,
                bypassEnabled ? "Enabled" : "Disabled",
                debugMode ? "Enabled" : "Disabled"
            );
        } catch (Exception e) {
            return "Error getting stats: " + e.getMessage();
        }
    }

    /**
     * Hook method for replacing original signature verification calls
     * Use this to replace any existing signature verification in the original code
     */
    public static boolean hookSignatureVerification(Context context, Object... params) {
        try {
            // Log the hook attempt
            if (debugMode) {
                Log.d(TAG, "Signature verification hook called with " + params.length + " parameters");
            }

            // Always return true regardless of parameters
            return isSignatureValid(context);
        } catch (Exception e) {
            Log.e(TAG, "Error in signature verification hook", e);
            return true; // Return true even on error
        }
    }

    /**
     * Native signature verification bypass (for JNI integration)
     */
    public static boolean nativeSignatureVerification(Context context) {
        return isSignatureValid(context);
    }

    /**
     * Anti-tamper check bypass
     */
    public static boolean checkAntiTamper(Context context) {
        if (debugMode) {
            Log.d(TAG, "Anti-tamper check bypassed");
        }
        return true; // Always return true to bypass anti-tamper
    }

    /**
     * Integrity verification bypass
     */
    public static boolean verifyIntegrity(Context context) {
        if (debugMode) {
            Log.d(TAG, "Integrity verification bypassed");
        }
        return true; // Always return true to bypass integrity checks
    }

    /**
     * License verification bypass
     */
    public static boolean verifyLicense(Context context) {
        if (debugMode) {
            Log.d(TAG, "License verification bypassed");
        }
        return true; // Always return true to bypass license checks
    }

    /**
     * Clear verification cache and reset state
     */
    public static void clearVerificationCache() {
        try {
            lastVerificationTime.set(0);
            Log.d(TAG, "Verification cache cleared");
        } catch (Exception e) {
            Log.e(TAG, "Error clearing verification cache", e);
        }
    }

    /**
     * Emergency bypass method - use when all else fails
     */
    public static boolean emergencyBypass() {
        Log.w(TAG, "Emergency signature bypass activated");
        return true;
    }

    /**
     * Signature information container
     */
    public static class SignatureInfo {
        public final String md5;
        public final String sha1;
        public final String sha256;
        public final String crc32;

        public SignatureInfo(String md5, String sha1, String sha256, String crc32) {
            this.md5 = md5;
            this.sha1 = sha1;
            this.sha256 = sha256;
            this.crc32 = crc32;
        }

        @Override
        public String toString() {
            return String.format("SignatureInfo{md5='%s', sha1='%s', sha256='%s', crc32='%s'}",
                               md5, sha1, sha256, crc32);
        }
    }
}
