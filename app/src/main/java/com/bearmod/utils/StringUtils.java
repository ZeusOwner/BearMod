package com.bearmod.utils;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

/**
 * Enhanced utility class for string operations in BearMod
 * 
 * Provides string utilities specifically designed for game modding,
 * memory operations, pattern matching, and security operations.
 */
public class StringUtils {
    
    // Hex characters for conversion
    private static final char[] HEX_CHARS = "0123456789ABCDEF".toCharArray();
    
    // Pattern for hex strings
    private static final Pattern HEX_PATTERN = Pattern.compile("^[0-9A-Fa-f]+$");
    
    // Pattern for memory addresses
    private static final Pattern ADDRESS_PATTERN = Pattern.compile("^(0x)?[0-9A-Fa-f]+$");
    
    // Pattern for memory patterns (with wildcards)
    private static final Pattern MEMORY_PATTERN = Pattern.compile("^[0-9A-Fa-f\\s\\?]+$");
    
    /**
     * Checks if a string is null or empty
     * 
     * @param str The string to check
     * @return true if the string is null or empty, false otherwise
     */
    public static boolean isEmpty(String str) {
        return str == null || str.trim().length() == 0;
    }
    
    /**
     * Checks if a string is not null and not empty
     * 
     * @param str The string to check
     * @return true if the string is not null and not empty, false otherwise
     */
    public static boolean isNotEmpty(String str) {
        return !isEmpty(str);
    }
    
    /**
     * Reverses a string
     * 
     * @param str The string to reverse
     * @return The reversed string, or empty string if input is null
     */
    public static String reverse(String str) {
        if (str == null) {
            return "";
        }
        return new StringBuilder(str).reverse().toString();
    }
    
    /**
     * Counts the occurrences of a character in a string
     * 
     * @param str The string to search in
     * @param c The character to count
     * @return The number of occurrences, or 0 if the string is null
     */
    public static int countChar(String str, char c) {
        if (str == null) {
            return 0;
        }
        
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == c) {
                count++;
            }
        }
        return count;
    }
    
    // ==================== ENHANCED FEATURES FOR BEARMOD ====================
    
    /**
     * Convert byte array to hex string
     * Essential for memory operations and address display
     * 
     * @param bytes The byte array to convert
     * @return Hex string representation
     */
    public static String bytesToHex(byte[] bytes) {
        if (bytes == null || bytes.length == 0) {
            return "";
        }
        
        StringBuilder result = new StringBuilder(bytes.length * 2);
        for (byte b : bytes) {
            result.append(HEX_CHARS[(b >> 4) & 0xF]);
            result.append(HEX_CHARS[b & 0xF]);
        }
        return result.toString();
    }
    
    /**
     * Convert hex string to byte array
     * Essential for memory operations and pattern matching
     * 
     * @param hex The hex string to convert
     * @return Byte array representation
     */
    public static byte[] hexToBytes(String hex) {
        if (isEmpty(hex)) {
            return new byte[0];
        }
        
        // Remove spaces and make uppercase
        hex = hex.replaceAll("\\s+", "").toUpperCase();
        
        // Ensure even length
        if (hex.length() % 2 != 0) {
            hex = "0" + hex;
        }
        
        byte[] result = new byte[hex.length() / 2];
        for (int i = 0; i < result.length; i++) {
            int index = i * 2;
            result[i] = (byte) Integer.parseInt(hex.substring(index, index + 2), 16);
        }
        return result;
    }
    
    /**
     * Format memory address for display
     * 
     * @param address The memory address
     * @return Formatted address string (e.g., "0x12345678")
     */
    public static String formatAddress(long address) {
        return String.format(Locale.US, "0x%08X", address);
    }
    
    /**
     * Parse memory address from string
     * 
     * @param addressStr The address string (with or without 0x prefix)
     * @return Parsed address, or 0 if invalid
     */
    public static long parseAddress(String addressStr) {
        if (isEmpty(addressStr)) {
            return 0;
        }
        
        try {
            String cleanAddr = addressStr.trim().toUpperCase();
            if (cleanAddr.startsWith("0X")) {
                cleanAddr = cleanAddr.substring(2);
            }
            
            if (isValidHex(cleanAddr)) {
                return Long.parseLong(cleanAddr, 16);
            }
        } catch (NumberFormatException e) {
            // Invalid format
        }
        
        return 0;
    }
    
    /**
     * Validate hex string format
     * 
     * @param hex The string to validate
     * @return true if valid hex string, false otherwise
     */
    public static boolean isValidHex(String hex) {
        if (isEmpty(hex)) {
            return false;
        }
        return HEX_PATTERN.matcher(hex.trim()).matches();
    }
    
    /**
     * Validate memory address format
     * 
     * @param address The address string to validate
     * @return true if valid address format, false otherwise
     */
    public static boolean isValidAddress(String address) {
        if (isEmpty(address)) {
            return false;
        }
        return ADDRESS_PATTERN.matcher(address.trim()).matches();
    }
    
    /**
     * Validate memory pattern format (supports wildcards)
     * 
     * @param pattern The pattern string to validate (e.g., "48 8B 05 ? ? ? ?")
     * @return true if valid pattern format, false otherwise
     */
    public static boolean isValidMemoryPattern(String pattern) {
        if (isEmpty(pattern)) {
            return false;
        }
        return MEMORY_PATTERN.matcher(pattern.trim()).matches();
    }
    
    /**
     * Normalize memory pattern for scanning
     * 
     * @param pattern The pattern string (e.g., "48 8B 05 ? ? ? ?")
     * @return Normalized pattern with consistent spacing
     */
    public static String normalizeMemoryPattern(String pattern) {
        if (isEmpty(pattern)) {
            return "";
        }
        
        // Split by whitespace and rejoin with single spaces
        String[] parts = pattern.trim().split("\\s+");
        StringBuilder normalized = new StringBuilder();
        
        for (int i = 0; i < parts.length; i++) {
            if (i > 0) {
                normalized.append(" ");
            }
            
            String part = parts[i].toUpperCase();
            if (part.equals("?") || part.equals("??")) {
                normalized.append("?");
            } else if (isValidHex(part)) {
                // Ensure 2-digit hex
                if (part.length() == 1) {
                    normalized.append("0").append(part);
                } else {
                    normalized.append(part);
                }
            } else {
                // Invalid part, return original
                return pattern;
            }
        }
        
        return normalized.toString();
    }
    
    /**
     * Simple string obfuscation for anti-detection
     * 
     * @param input The string to obfuscate
     * @param key The obfuscation key
     * @return Obfuscated string
     */
    public static String obfuscate(String input, int key) {
        if (isEmpty(input)) {
            return "";
        }
        
        StringBuilder result = new StringBuilder();
        for (char c : input.toCharArray()) {
            result.append((char) (c ^ key));
        }
        return result.toString();
    }
    
    /**
     * Simple string deobfuscation
     * 
     * @param obfuscated The obfuscated string
     * @param key The deobfuscation key
     * @return Deobfuscated string
     */
    public static String deobfuscate(String obfuscated, int key) {
        // XOR is symmetric, so deobfuscation is the same as obfuscation
        return obfuscate(obfuscated, key);
    }
    
    /**
     * Generate MD5 hash of string (for checksums)
     * 
     * @param input The input string
     * @return MD5 hash as hex string, or empty string on error
     */
    public static String md5Hash(String input) {
        if (isEmpty(input)) {
            return "";
        }
        
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] hash = md.digest(input.getBytes(StandardCharsets.UTF_8));
            return bytesToHex(hash).toLowerCase();
        } catch (NoSuchAlgorithmException e) {
            return "";
        }
    }
    
    /**
     * Generate SHA-256 hash of string
     * 
     * @param input The input string
     * @return SHA-256 hash as hex string, or empty string on error
     */
    public static String sha256Hash(String input) {
        if (isEmpty(input)) {
            return "";
        }
        
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hash = md.digest(input.getBytes(StandardCharsets.UTF_8));
            return bytesToHex(hash).toLowerCase();
        } catch (NoSuchAlgorithmException e) {
            return "";
        }
    }
    
    /**
     * Split string by delimiter with null safety
     * 
     * @param str The string to split
     * @param delimiter The delimiter
     * @return Array of split strings, empty array if input is null
     */
    public static String[] safeSplit(String str, String delimiter) {
        if (isEmpty(str) || isEmpty(delimiter)) {
            return new String[0];
        }
        return str.split(Pattern.quote(delimiter));
    }
    
    /**
     * Join strings with delimiter
     * 
     * @param strings The strings to join
     * @param delimiter The delimiter
     * @return Joined string, empty string if input is null or empty
     */
    public static String join(String[] strings, String delimiter) {
        if (strings == null || strings.length == 0 || delimiter == null) {
            return "";
        }
        
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < strings.length; i++) {
            if (i > 0) {
                result.append(delimiter);
            }
            result.append(strings[i] != null ? strings[i] : "");
        }
        return result.toString();
    }
    
    /**
     * Extract numbers from string
     * 
     * @param str The input string
     * @return List of numbers found in the string
     */
    public static List<Long> extractNumbers(String str) {
        List<Long> numbers = new ArrayList<>();
        if (isEmpty(str)) {
            return numbers;
        }
        
        Pattern numberPattern = Pattern.compile("-?\\d+");
        Matcher matcher = numberPattern.matcher(str);
        
        while (matcher.find()) {
            try {
                numbers.add(Long.parseLong(matcher.group()));
            } catch (NumberFormatException e) {
                // Skip invalid numbers
            }
        }
        
        return numbers;
    }
    
    /**
     * Extract hex addresses from string
     * 
     * @param str The input string
     * @return List of hex addresses found in the string
     */
    public static List<Long> extractAddresses(String str) {
        List<Long> addresses = new ArrayList<>();
        if (isEmpty(str)) {
            return addresses;
        }
        
        Pattern addressPattern = Pattern.compile("0x[0-9A-Fa-f]+");
        Matcher matcher = addressPattern.matcher(str);
        
        while (matcher.find()) {
            try {
                String hexStr = matcher.group().substring(2); // Remove "0x"
                addresses.add(Long.parseLong(hexStr, 16));
            } catch (NumberFormatException e) {
                // Skip invalid addresses
            }
        }
        
        return addresses;
    }
    
    /**
     * Truncate string to specified length with ellipsis
     * 
     * @param str The string to truncate
     * @param maxLength Maximum length
     * @return Truncated string with "..." if needed
     */
    public static String truncate(String str, int maxLength) {
        if (isEmpty(str) || maxLength <= 0) {
            return "";
        }
        
        if (str.length() <= maxLength) {
            return str;
        }
        
        if (maxLength <= 3) {
            return str.substring(0, maxLength);
        }
        
        return str.substring(0, maxLength - 3) + "...";
    }
    
    /**
     * Pad string to specified length
     * 
     * @param str The string to pad
     * @param length Target length
     * @param padChar Character to pad with
     * @param leftPad true for left padding, false for right padding
     * @return Padded string
     */
    public static String pad(String str, int length, char padChar, boolean leftPad) {
        if (str == null) {
            str = "";
        }
        
        if (str.length() >= length) {
            return str;
        }
        
        StringBuilder result = new StringBuilder();
        int padCount = length - str.length();
        
        if (leftPad) {
            for (int i = 0; i < padCount; i++) {
                result.append(padChar);
            }
            result.append(str);
        } else {
            result.append(str);
            for (int i = 0; i < padCount; i++) {
                result.append(padChar);
            }
        }
        
        return result.toString();
    }
}
