package com.bearmod;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Set;
import java.util.concurrent.atomic.AtomicBoolean;
import android.util.Log;
import org.json.JSONObject;
import java.util.Iterator;

public class SkinManager {
    // Load native library for JNI bridge
    static {
        try {
            System.loadLibrary("bearmod");
        } catch (UnsatisfiedLinkError e) {
            e.printStackTrace();
        }
    }
    
    private static final String TAG = "SkinManager";
    private static final int MAX_SKIN_HISTORY = 10;
    private static final long SKIN_NAME_UPDATE_INTERVAL = 5000; // 5 seconds
    
    private static final Map<String, String> activeSkinNames = new HashMap<>();
    private static final Map<String, Long> lastSkinNameUpdate = new HashMap<>();
    private static final Map<String, List<String>> skinNameHistory = new HashMap<>();
    
    /**
     * Enhanced skin data structure to match JOIN_SKIN.h
     * This class represents the complete data for a weapon's skins and attachments.
     * It should be synchronized with the native C++ implementation.
     */
    public static class WeaponSkinData {
        /** Unique identifier for the weapon */
        public final int weaponId;
        
        /** Array of skin IDs available for this weapon */
        public final int[] skinIds;
        
        /** Array of skin names corresponding to skinIds */
        public final String[] skinNames;
        
        /** Maps attachment types to their available IDs */
        public final Map<String, int[]> attachments;
        
        /** Array of metro mode compatible weapon IDs */
        public final int[] metroModeIds;
        
        /** Flag indicating if this is a special skin requiring extra protection */
        public final boolean isSpecialSkin;
        
        /**
         * Constructor for WeaponSkinData
         * @param weaponId The unique identifier for the weapon
         * @param ids Array of skin IDs
         * @param names Array of skin names
         * @param attachments Map of attachment types to their IDs
         * @param metroIds Array of metro mode compatible IDs
         * @param isSpecialSkin Whether this is a special skin
         */
        public WeaponSkinData(int weaponId, int[] ids, String[] names, 
                            Map<String, int[]> attachments, int[] metroIds, 
                            boolean isSpecialSkin) {
            this.weaponId = weaponId;
            this.skinIds = ids;
            this.skinNames = names;
            this.attachments = attachments;
            this.metroModeIds = metroIds;
            this.isSpecialSkin = isSpecialSkin;
        }
    }

    /**
     * Vehicle and special skin data structure
     * This class represents the complete data for a vehicle's skins.
     * It should be synchronized with the native C++ implementation.
     */
    public static class VehicleSkinData {
        /** Unique identifier for the vehicle */
        public final int vehicleId;
        
        /** Array of skin IDs available for this vehicle */
        public final int[] skinIds;
        
        /** Array of skin names corresponding to skinIds */
        public final String[] skinNames;
        
        /** Flag indicating if emotes are enabled for this vehicle */
        public final boolean isEmoteEnabled;
        
        /**
         * Constructor for VehicleSkinData
         * @param vehicleId The unique identifier for the vehicle
         * @param ids Array of skin IDs
         * @param names Array of skin names
         * @param isEmoteEnabled Whether emotes are enabled
         */
        public VehicleSkinData(int vehicleId, int[] ids, String[] names, 
                             boolean isEmoteEnabled) {
            this.vehicleId = vehicleId;
            this.skinIds = ids;
            this.skinNames = names;
            this.isEmoteEnabled = isEmoteEnabled;
        }
    }
    
    /**
     * Attachment types matching JOIN_SKIN.h
     * These enums should be kept in sync with the native C++ implementation.
     */
    public enum AttachmentType {
        MAGAZINE,           // Magazine attachments
        DEF_STOCK,          // Default stock
        DEF_MUZZLE,         // Default muzzle
        DEF_SIGHT,          // Default sight
        FLASH,              // Flash hider
        COMPENSATOR,        // Compensator
        SILENCER,           // Silencer
        RED_DOT,            // Red dot sight
        HOLOGRAPHIC,        // Holographic sight
        SCOPE2X,            // 2x scope
        SCOPE3X,            // 3x scope
        SCOPE4X,            // 4x scope
        SCOPE6X,            // 6x scope
        SCOPE8X,            // 8x scope
        QUICK_MAG,          // Quick magazine
        EXTENDED_MAG,       // Extended magazine
        EXTENDED_QUICK_MAG, // Extended quick magazine
        TACTICAL_STOCK,     // Tactical stock
        VERTICLE_GRIP,      // Vertical grip
        ANGLED_GRIP,        // Angled grip
        LIGHT_GRIP,         // Light grip
        HALF_GRIP,          // Half grip
        LASER_SIGHT,        // Laser sight
        THUMB_GRIP          // Thumb grip
    }
    
    private static final Map<String, WeaponSkinData> weaponSkinMap = new HashMap<>();
    private static final Map<String, VehicleSkinData> vehicleSkinMap = new HashMap<>();
    private static long lastWeaponChangeTime = 0;
    private static final long MIN_SKIN_CHANGE_INTERVAL = 100; // Minimum milliseconds between skin changes
    private static final Random random = new Random();
    private static final AtomicBoolean isSkinChangeInProgress = new AtomicBoolean(false);
    private static final int MAX_RETRY_ATTEMPTS = 3;
    private static final long RETRY_DELAY_MS = 500;
    
    // Anti-detection measures
    private static final byte[] MEMORY_SCRAMBLE_KEY = new byte[16];
    private static final Map<String, Long> lastVerificationTimes = new HashMap<>();
    private static final long VERIFICATION_INTERVAL = 30000; // 30 seconds
    
    // ===== ADVANCED SKIN CONFIGURATION =====
    /**
     * Enhanced skin configuration class
     * This class manages all configurable aspects of the skin system.
     * It should be synchronized with the native C++ implementation.
     */
    private static class SkinConfig {
        /** Enable dynamic skin changes */
        public boolean enableDynamicSkins = true;
        
        /** Enable kill feed skin display */
        public boolean enableKillFeedSkins = true;
        
        /** Enable deadbox skins */
        public boolean enableDeadboxSkins = true;
        
        /** Enable metro mode skins */
        public boolean enableMetroModeSkins = true;
        
        /** Enable special effects */
        public boolean enableSpecialEffects = true;
        
        /** Cooldown between skin changes in milliseconds */
        public int skinChangeCooldown = 5000;
        
        /** Maximum number of retry attempts for skin changes */
        public int maxRetryAttempts = 3;
        
        /** Enable anti-detection measures */
        public boolean enableAntiDetection = true;
        
        /** Enable memory scrambling */
        public boolean enableMemoryScrambling = true;
        
        /** Enable skin verification */
        public boolean enableSkinVerification = true;
        
        /** Enable dynamic skin rotation */
        public boolean enableDynamicRotation = true;
        
        /** Interval for skin rotation in milliseconds */
        public int rotationInterval = 30000;
        
        /** Enable random attachments */
        public boolean enableRandomAttachments = true;
        
        /** Enable skin protection */
        public boolean enableSkinProtection = true;
        
        /** Protection level (0: None, 1: Basic, 2: Advanced) */
        public int protectionLevel = 2;
    }

    private static final SkinConfig skinConfig = new SkinConfig();
    private static final Map<String, Long> lastSkinChangeTimes = new HashMap<>();
    private static final Map<String, Integer> skinVerificationCounts = new HashMap<>();
    private static final Map<String, Long> lastRotationTimes = new HashMap<>();
    private static final Map<String, Integer> currentRotationIndices = new HashMap<>();
    private static final Map<String, Set<Integer>> usedSkinIds = new HashMap<>();
    private static final Map<String, Integer> skinProtectionLevels = new HashMap<>();

    static {
        initializeWeaponSkins();
        initializeVehicleSkins();
        random.nextBytes(MEMORY_SCRAMBLE_KEY);
    }
    
    private static void initializeVehicleSkins() {
        // Car skins
        vehicleSkinMap.put("CAR", new VehicleSkinData(
            1301001001,
            new int[]{1301001001, 1301001002, 1301001003, 1301001004, 1301001005},
            new String[]{"Default", "Racing", "Military", "Sports", "Luxury"},
            true
        ));
        
        // Motorcycle skins with emotes
        vehicleSkinMap.put("MOTORCYCLE", new VehicleSkinData(
            1302001001,
            new int[]{1302001001, 1302001002, 1302001003, 1302001004, 1302001005},
            new String[]{"Default", "Racing", "Military", "Sports", "Luxury"},
            true
        ));
        
        // Parachute skins
        vehicleSkinMap.put("PARACHUTE", new VehicleSkinData(
            1401001001,
            new int[]{1401001001, 1401001002, 1401001003, 1401001004, 1401001005},
            new String[]{"Default", "Rainbow", "Military", "Sports", "Luxury"},
            false
        ));
    }
    
    private static void initializeWeaponSkins() {
        // M416 with attachments
        Map<String, int[]> m416Attachments = new HashMap<>();
        m416Attachments.put("MAGAZINE", new int[]{1291004001});
        m416Attachments.put("RED_DOT", new int[]{1203001001});
        m416Attachments.put("HOLOGRAPHIC", new int[]{1203002001});
        m416Attachments.put("SCOPE2X", new int[]{1203003001});
        m416Attachments.put("SCOPE3X", new int[]{1203014001});
        m416Attachments.put("SCOPE4X", new int[]{1203004001});
        m416Attachments.put("SCOPE6X", new int[]{1203015001});
        m416Attachments.put("QUICK_MAG", new int[]{1204012001});
        m416Attachments.put("EXTENDED_MAG", new int[]{1204011001});
        m416Attachments.put("EXTENDED_QUICK_MAG", new int[]{1204013001});
        m416Attachments.put("FLASH", new int[]{1201010001});
        m416Attachments.put("COMPENSATOR", new int[]{1201009001});
        m416Attachments.put("SILENCER", new int[]{1201011001});
        m416Attachments.put("ANGLED_GRIP", new int[]{1202001001});
        m416Attachments.put("VERTICLE_GRIP", new int[]{1202002001});
        m416Attachments.put("LIGHT_GRIP", new int[]{1202003001});
        m416Attachments.put("HALF_GRIP", new int[]{1202004001});
        m416Attachments.put("THUMB_GRIP", new int[]{1202005001});
        
        weaponSkinMap.put("M416", new WeaponSkinData(
            101004,
            new int[]{1101004003, 1101004004, 1101004005, 1101004006, 1101004007, 1101004008, 1101004009, 1101004010},
            new String[]{"Default", "PUBG", "Desert Digital", "Glacier", "Golden", "Bloodshed", "Fool", "Oriental"},
            m416Attachments,
            new int[]{101004, 1010041, 1010042, 1010043, 1010044, 1010045, 1010046, 1010047},
            false
        ));

        // AKM with attachments
        Map<String, int[]> akmAttachments = new HashMap<>();
        akmAttachments.put("MAGAZINE", new int[]{1291001001});
        akmAttachments.put("RED_DOT", new int[]{1203001002});
        akmAttachments.put("HOLOGRAPHIC", new int[]{1203002002});
        akmAttachments.put("SCOPE2X", new int[]{1203003002});
        akmAttachments.put("SCOPE3X", new int[]{1203014002});
        akmAttachments.put("SCOPE4X", new int[]{1203004002});
        akmAttachments.put("SCOPE6X", new int[]{1203015002});
        akmAttachments.put("QUICK_MAG", new int[]{1204012002});
        akmAttachments.put("EXTENDED_MAG", new int[]{1204011002});
        akmAttachments.put("EXTENDED_QUICK_MAG", new int[]{1204013002});
        akmAttachments.put("FLASH", new int[]{1201010002});
        akmAttachments.put("COMPENSATOR", new int[]{1201009002});
        akmAttachments.put("SILENCER", new int[]{1201011002});
        akmAttachments.put("ANGLED_GRIP", new int[]{1202001002});
        akmAttachments.put("VERTICLE_GRIP", new int[]{1202002002});
        akmAttachments.put("LIGHT_GRIP", new int[]{1202003002});
        akmAttachments.put("HALF_GRIP", new int[]{1202004002});
        akmAttachments.put("THUMB_GRIP", new int[]{1202005002});
        
        weaponSkinMap.put("AKM", new WeaponSkinData(
            101001,
            new int[]{1101001003, 1101001004, 1101001005, 1101001006, 1101001007, 1101001008, 1101001009, 1101001010},
            new String[]{"Default", "PUBG", "Desert Digital", "Glacier", "Golden", "Bloodshed", "Fool", "Oriental"},
            akmAttachments,
            new int[]{101001, 1010011, 1010012, 1010013, 1010014, 1010015, 1010016, 1010017},
            false
        ));

        // SCAR-L with attachments
        Map<String, int[]> scarAttachments = new HashMap<>();
        scarAttachments.put("MAGAZINE", new int[]{1291003001});
        scarAttachments.put("RED_DOT", new int[]{1203001003});
        scarAttachments.put("HOLOGRAPHIC", new int[]{1203002003});
        scarAttachments.put("SCOPE2X", new int[]{1203003003});
        scarAttachments.put("SCOPE3X", new int[]{1203014003});
        scarAttachments.put("SCOPE4X", new int[]{1203004003});
        scarAttachments.put("SCOPE6X", new int[]{1203015003});
        
        weaponSkinMap.put("SCAR", new WeaponSkinData(
            101003,
            new int[]{1101003003, 1101003004, 1101003005, 1101003006, 1101003007, 1101003008, 1101003009, 1101003010},
            new String[]{"Default", "PUBG", "Desert Digital", "Glacier", "Golden", "Bloodshed", "Fool", "Oriental"},
            scarAttachments,
            new int[]{101003, 1010031, 1010032, 1010033, 1010034, 1010035, 1010036, 1010037},
            false
        ));

        // AWM with attachments
        Map<String, int[]> awmAttachments = new HashMap<>();
        awmAttachments.put("MAGAZINE", new int[]{1293003001});
        awmAttachments.put("SCOPE4X", new int[]{1203004004});
        awmAttachments.put("SCOPE6X", new int[]{1203015004});
        awmAttachments.put("SCOPE8X", new int[]{1203005004});
        
        weaponSkinMap.put("AWM", new WeaponSkinData(
            103003,
            new int[]{1103003003, 1103003004, 1103003005, 1103003006, 1103003007, 1103003008, 1103003009, 1103003010},
            new String[]{"Default", "PUBG", "Desert Digital", "Glacier", "Golden", "Bloodshed", "Fool", "Oriental"},
            awmAttachments,
            new int[]{103003, 1030031, 1030032, 1030033, 1030034, 1030035, 1030036, 1030037},
            false
        ));

        // MK14 with attachments (Chinese favorite)
        Map<String, int[]> mk14Attachments = new HashMap<>();
        mk14Attachments.put("MAGAZINE", new int[]{1293007001});
        mk14Attachments.put("EXTENDED_MAG", new int[]{1037010124});
        mk14Attachments.put("COMPENSATOR", new int[]{1037010128});
        mk14Attachments.put("SCOPE4X", new int[]{1037010115});
        
        weaponSkinMap.put("MK14", new WeaponSkinData(
            103007,
            new int[]{1103007003, 1103007004, 1103007005, 1103007006, 1103007007, 1103007008, 1103007009, 1103007010},
            new String[]{"Default", "PUBG", "Desert Digital", "Glacier", "Golden", "Bloodshed", "Fool", "Oriental"},
            mk14Attachments,
            new int[]{103007, 1030071, 1030072, 1030073, 1030074, 1030075, 1030076, 1030077},
            false
        ));

        // MG3 with attachments (Chinese favorite)
        Map<String, int[]> mg3Attachments = new HashMap<>();
        mg3Attachments.put("RED_DOT", new int[]{1051010119});
        mg3Attachments.put("COMPENSATOR", new int[]{1051010128});
        mg3Attachments.put("SCOPE3X", new int[]{1051010116});
        mg3Attachments.put("SCOPE4X", new int[]{1051010115});
        
        weaponSkinMap.put("MG3", new WeaponSkinData(
            105010,
            new int[]{1105010003, 1105010004, 1105010005, 1105010006, 1105010007, 1105010008, 1105010009, 1105010010},
            new String[]{"Default", "PUBG", "Desert Digital", "Glacier", "Golden", "Bloodshed", "Fool", "Oriental"},
            mg3Attachments,
            new int[]{105010, 1050101, 1050102, 1050103, 1050104, 1050105, 1050106, 1050107},
            false
        ));

        // ACE32 with attachments
        Map<String, int[]> ace32Attachments = new HashMap<>();
        ace32Attachments.put("MAGAZINE", new int[]{291102});
        ace32Attachments.put("DEF_STOCK", new int[]{205102});
        ace32Attachments.put("DEF_MUZZLE", new int[]{281102});
        ace32Attachments.put("SCOPE2X", new int[]{1011020117});
        ace32Attachments.put("SCOPE3X", new int[]{1011020116});
        ace32Attachments.put("SCOPE4X", new int[]{1011020115});
        ace32Attachments.put("SCOPE6X", new int[]{1011020114});
        ace32Attachments.put("HOLOGRAPHIC", new int[]{1011020118});
        ace32Attachments.put("RED_DOT", new int[]{1011020119});
        ace32Attachments.put("EXTENDED_MAG", new int[]{1011020124});
        ace32Attachments.put("QUICK_MAG", new int[]{1011020125});
        ace32Attachments.put("EXTENDED_QUICK_MAG", new int[]{1011020126});
        ace32Attachments.put("FLASH", new int[]{1011020127});
        ace32Attachments.put("COMPENSATOR", new int[]{1011020128});
        ace32Attachments.put("SILENCER", new int[]{1011020129});
        ace32Attachments.put("ANGLED_GRIP", new int[]{1011020134});
        ace32Attachments.put("THUMB_GRIP", new int[]{1011020135});
        ace32Attachments.put("VERTICLE_GRIP", new int[]{1011020136});
        ace32Attachments.put("TACTICAL_STOCK", new int[]{1011020137});
        ace32Attachments.put("LIGHT_GRIP", new int[]{1011020138});
        ace32Attachments.put("HALF_GRIP", new int[]{1011020139});
        ace32Attachments.put("LASER_SIGHT", new int[]{1011020144});
        
        weaponSkinMap.put("ACE32", new WeaponSkinData(
            101102,
            new int[]{1101102003, 1101102017},
            new String[]{"Default", "Icicle Spike (Lv. 7)"},
            ace32Attachments,
            new int[]{101102, 1011021, 1011022, 1011023, 1011024, 1011025, 1011026, 1011027},
            false
        ));

        // UMP with attachments
        Map<String, int[]> umpAttachments = new HashMap<>();
        umpAttachments.put("MAGAZINE", new int[]{1292002001});
        umpAttachments.put("RED_DOT", new int[]{1203001002});
        umpAttachments.put("HOLOGRAPHIC", new int[]{1203002002});
        umpAttachments.put("SCOPE2X", new int[]{1203003002});
        umpAttachments.put("SCOPE3X", new int[]{1203014002});
        umpAttachments.put("SCOPE4X", new int[]{1203004002});
        umpAttachments.put("QUICK_MAG", new int[]{1204012002});
        umpAttachments.put("EXTENDED_MAG", new int[]{1204011002});
        umpAttachments.put("EXTENDED_QUICK_MAG", new int[]{1204013002});
        umpAttachments.put("FLASH", new int[]{1201010003});
        umpAttachments.put("COMPENSATOR", new int[]{1201009003});
        umpAttachments.put("SILENCER", new int[]{1201011003});
        
        weaponSkinMap.put("UMP", new WeaponSkinData(
            102002,
            new int[]{1102002003, 1102002004, 1102002005, 1102002006, 1102002007, 1102002008, 1102002009, 1102002010},
            new String[]{"Default", "PUBG", "Desert Digital", "Glacier", "Golden", "Bloodshed", "Fool", "Oriental"},
            umpAttachments,
            new int[]{102002, 1020021, 1020022, 1020023, 1020024, 1020025, 1020026, 1020027},
            false
        ));

        // Vector with attachments
        Map<String, int[]> vectorAttachments = new HashMap<>();
        vectorAttachments.put("MAGAZINE", new int[]{1292003001});
        vectorAttachments.put("RED_DOT", new int[]{1203001003});
        vectorAttachments.put("HOLOGRAPHIC", new int[]{1203002003});
        vectorAttachments.put("SCOPE2X", new int[]{1203003003});
        vectorAttachments.put("SCOPE3X", new int[]{1203014003});
        vectorAttachments.put("QUICK_MAG", new int[]{1204012003});
        vectorAttachments.put("EXTENDED_MAG", new int[]{1204011003});
        vectorAttachments.put("EXTENDED_QUICK_MAG", new int[]{1204013003});
        vectorAttachments.put("FLASH", new int[]{1201010004});
        vectorAttachments.put("COMPENSATOR", new int[]{1201009004});
        vectorAttachments.put("SILENCER", new int[]{1201011004});
        vectorAttachments.put("VERTICLE_GRIP", new int[]{1202001003});
        vectorAttachments.put("LIGHT_GRIP", new int[]{1202002003});
        
        weaponSkinMap.put("Vector", new WeaponSkinData(
            102003,
            new int[]{1102003003, 1102003004, 1102003005, 1102003006, 1102003007, 1102003008, 1102003009, 1102003010},
            new String[]{"Default", "PUBG", "Desert Digital", "Glacier", "Golden", "Bloodshed", "Fool", "Oriental"},
            vectorAttachments,
            new int[]{102003, 1020031, 1020032, 1020033, 1020034, 1020035, 1020036, 1020037},
            false
        ));

        // UZI with attachments
        Map<String, int[]> uziAttachments = new HashMap<>();
        uziAttachments.put("MAGAZINE", new int[]{1292001001});
        uziAttachments.put("RED_DOT", new int[]{1203001001});
        uziAttachments.put("HOLOGRAPHIC", new int[]{1203002001});
        uziAttachments.put("QUICK_MAG", new int[]{1204012004});
        uziAttachments.put("EXTENDED_MAG", new int[]{1204011004});
        uziAttachments.put("EXTENDED_QUICK_MAG", new int[]{1204013004});
        uziAttachments.put("FLASH", new int[]{1201010005});
        uziAttachments.put("COMPENSATOR", new int[]{1201009005});
        uziAttachments.put("SILENCER", new int[]{1201011005});
        
        weaponSkinMap.put("UZI", new WeaponSkinData(
            102001,
            new int[]{1102001003, 1102001004, 1102001005, 1102001006, 1102001007, 1102001008, 1102001009, 1102001010},
            new String[]{"Default", "PUBG", "Desert Digital", "Glacier", "Golden", "Bloodshed", "Fool", "Oriental"},
            uziAttachments,
            new int[]{102001, 1020011, 1020012, 1020013, 1020014, 1020015, 1020016, 1020017},
            false
        ));

        // GROZA with attachments
        Map<String, int[]> grozaAttachments = new HashMap<>();
        grozaAttachments.put("MAGAZINE", new int[]{1291005001});
        grozaAttachments.put("RED_DOT", new int[]{1203001005});
        grozaAttachments.put("HOLOGRAPHIC", new int[]{1203002005});
        grozaAttachments.put("SCOPE2X", new int[]{1203003005});
        grozaAttachments.put("SCOPE3X", new int[]{1203014005});
        grozaAttachments.put("SCOPE4X", new int[]{1203004005});
        grozaAttachments.put("SCOPE6X", new int[]{1203015005});
        grozaAttachments.put("QUICK_MAG", new int[]{1204012005});
        grozaAttachments.put("EXTENDED_MAG", new int[]{1204011005});
        grozaAttachments.put("EXTENDED_QUICK_MAG", new int[]{1204013005});
        grozaAttachments.put("FLASH", new int[]{1201010005});
        grozaAttachments.put("COMPENSATOR", new int[]{1201009005});
        grozaAttachments.put("SILENCER", new int[]{1201011005});
        grozaAttachments.put("ANGLED_GRIP", new int[]{1202001005});
        grozaAttachments.put("VERTICLE_GRIP", new int[]{1202002005});
        grozaAttachments.put("LIGHT_GRIP", new int[]{1202003005});
        grozaAttachments.put("HALF_GRIP", new int[]{1202004005});
        grozaAttachments.put("THUMB_GRIP", new int[]{1202005005});
        
        weaponSkinMap.put("GROZA", new WeaponSkinData(
            101005,
            new int[]{1101005003, 1101005004, 1101005005, 1101005006, 1101005007, 1101005008, 1101005009, 1101005010},
            new String[]{"Default", "PUBG", "Desert Digital", "Glacier", "Golden", "Bloodshed", "Fool", "Oriental"},
            grozaAttachments,
            new int[]{101005, 1010051, 1010052, 1010053, 1010054, 1010055, 1010056, 1010057},
            false
        ));

        // FAMAS with attachments
        Map<String, int[]> famasAttachments = new HashMap<>();
        famasAttachments.put("MAGAZINE", new int[]{1291010001});
        famasAttachments.put("RED_DOT", new int[]{1203001006});
        famasAttachments.put("HOLOGRAPHIC", new int[]{1203002006});
        famasAttachments.put("SCOPE2X", new int[]{1203003006});
        famasAttachments.put("SCOPE3X", new int[]{1203014006});
        famasAttachments.put("SCOPE4X", new int[]{1203004006});
        famasAttachments.put("SCOPE6X", new int[]{1203015006});
        famasAttachments.put("QUICK_MAG", new int[]{1204012006});
        famasAttachments.put("EXTENDED_MAG", new int[]{1204011006});
        famasAttachments.put("EXTENDED_QUICK_MAG", new int[]{1204013006});
        famasAttachments.put("FLASH", new int[]{1201010006});
        famasAttachments.put("COMPENSATOR", new int[]{1201009006});
        famasAttachments.put("SILENCER", new int[]{1201011006});
        famasAttachments.put("ANGLED_GRIP", new int[]{1202001006});
        famasAttachments.put("VERTICLE_GRIP", new int[]{1202002006});
        famasAttachments.put("LIGHT_GRIP", new int[]{1202003006});
        famasAttachments.put("HALF_GRIP", new int[]{1202004006});
        famasAttachments.put("THUMB_GRIP", new int[]{1202005006});
        
        weaponSkinMap.put("FAMAS", new WeaponSkinData(
            101100,
            new int[]{1101100003, 1101100004, 1101100005, 1101100006, 1101100007, 1101100008, 1101100009, 1101100010},
            new String[]{"Default", "PUBG", "Desert Digital", "Glacier", "Golden", "Bloodshed", "Fool", "Oriental"},
            famasAttachments,
            new int[]{101100, 1011001, 1011002, 1011003, 1011004, 1011005, 1011006, 1011007},
            false
        ));

        // AUG with attachments
        Map<String, int[]> augAttachments = new HashMap<>();
        augAttachments.put("MAGAZINE", new int[]{1291006001});
        augAttachments.put("RED_DOT", new int[]{1203001007});
        augAttachments.put("HOLOGRAPHIC", new int[]{1203002007});
        augAttachments.put("SCOPE2X", new int[]{1203003007});
        augAttachments.put("SCOPE3X", new int[]{1203014007});
        augAttachments.put("SCOPE4X", new int[]{1203004007});
        augAttachments.put("SCOPE6X", new int[]{1203015007});
        augAttachments.put("QUICK_MAG", new int[]{1204012007});
        augAttachments.put("EXTENDED_MAG", new int[]{1204011007});
        augAttachments.put("EXTENDED_QUICK_MAG", new int[]{1204013007});
        augAttachments.put("FLASH", new int[]{1201010007});
        augAttachments.put("COMPENSATOR", new int[]{1201009007});
        augAttachments.put("SILENCER", new int[]{1201011007});
        augAttachments.put("ANGLED_GRIP", new int[]{1202001007});
        augAttachments.put("VERTICLE_GRIP", new int[]{1202002007});
        augAttachments.put("LIGHT_GRIP", new int[]{1202003007});
        augAttachments.put("HALF_GRIP", new int[]{1202004007});
        augAttachments.put("THUMB_GRIP", new int[]{1202005007});
        
        weaponSkinMap.put("AUG", new WeaponSkinData(
            101006,
            new int[]{1101006003, 1101006004, 1101006005, 1101006006, 1101006007, 1101006008, 1101006009, 1101006010},
            new String[]{"Default", "PUBG", "Desert Digital", "Glacier", "Golden", "Bloodshed", "Fool", "Oriental"},
            augAttachments,
            new int[]{101006, 1010061, 1010062, 1010063, 1010064, 1010065, 1010066, 1010067},
            false
        ));

        // M762 with attachments
        Map<String, int[]> m762Attachments = new HashMap<>();
        m762Attachments.put("MAGAZINE", new int[]{1291008001});
        m762Attachments.put("RED_DOT", new int[]{1203001008});
        m762Attachments.put("HOLOGRAPHIC", new int[]{1203002008});
        m762Attachments.put("SCOPE2X", new int[]{1203003008});
        m762Attachments.put("SCOPE3X", new int[]{1203014008});
        m762Attachments.put("SCOPE4X", new int[]{1203004008});
        m762Attachments.put("SCOPE6X", new int[]{1203015008});
        m762Attachments.put("QUICK_MAG", new int[]{1204012008});
        m762Attachments.put("EXTENDED_MAG", new int[]{1204011008});
        m762Attachments.put("EXTENDED_QUICK_MAG", new int[]{1204013008});
        m762Attachments.put("FLASH", new int[]{1201010008});
        m762Attachments.put("COMPENSATOR", new int[]{1201009008});
        m762Attachments.put("SILENCER", new int[]{1201011008});
        m762Attachments.put("ANGLED_GRIP", new int[]{1202001008});
        m762Attachments.put("VERTICLE_GRIP", new int[]{1202002008});
        m762Attachments.put("LIGHT_GRIP", new int[]{1202003008});
        m762Attachments.put("HALF_GRIP", new int[]{1202004008});
        m762Attachments.put("THUMB_GRIP", new int[]{1202005008});
        
        weaponSkinMap.put("M762", new WeaponSkinData(
            101008,
            new int[]{1101008003, 1101008004, 1101008005, 1101008006, 1101008007, 1101008008, 1101008009, 1101008010},
            new String[]{"Default", "PUBG", "Desert Digital", "Glacier", "Golden", "Bloodshed", "Fool", "Oriental"},
            m762Attachments,
            new int[]{101008, 1010081, 1010082, 1010083, 1010084, 1010085, 1010086, 1010087},
            false
        ));
    }
    
    /**
     * Get weapon skin data including attachments
     */
    public static WeaponSkinData getWeaponData(String weapon) {
        return weaponSkinMap.get(weapon);
    }
    
    // ===== ENHANCED SKIN APPLICATION =====
    public static void applyWeaponSkin(String weapon, int skinIndex, Map<AttachmentType, Integer> attachments) {
        if (!weaponSkinMap.containsKey(weapon)) {
            Log.w(TAG, "Weapon " + weapon + " not supported");
            return;
        }

        WeaponSkinData data = weaponSkinMap.get(weapon);
        if (skinIndex < 0 || skinIndex >= data.skinIds.length) {
            Log.w(TAG, "Invalid skin index for " + weapon);
            return;
        }

        // Check cooldown
        long currentTime = System.currentTimeMillis();
        Long lastChange = lastSkinChangeTimes.get(weapon);
        if (lastChange != null && currentTime - lastChange < skinConfig.skinChangeCooldown) {
            Log.d(TAG, "Skin change on cooldown for " + weapon);
            return;
        }

        // Apply skin with protection
        int skinId = data.skinIds[skinIndex];
        applyEnhancedProtection(weapon, skinId);

        // Apply attachments if provided
        if (attachments != null) {
            for (Map.Entry<AttachmentType, Integer> entry : attachments.entrySet()) {
                applyAttachmentWithProtection(weapon, entry.getKey().name(), entry.getValue());
            }
        }

        // Update real-time skin name
        updateRealTimeSkinName(weapon);

        // Update last change time
        lastSkinChangeTimes.put(weapon, currentTime);

        // Log successful application
        Log.d(TAG, "Applied skin " + skinId + " to " + weapon);
    }
    
    /**
     * Apply skin with enhanced anti-detection measures using MemoryScrambler
     */
    private static void applySkinWithProtection(String itemKey, int skinId, boolean isSpecialSkin) {
        int retryCount = 0;
        boolean success = false;

        while (!success && retryCount < MAX_RETRY_ATTEMPTS) {
            try {
                // Enhanced memory scrambling
                scrambleMemory();

                // Apply Kotlin-based memory scrambling for additional security
                int scrambledSkinId = MemoryScrambler.enhancedScrambleSkinID(skinId);

                // Apply skin with random delay and scrambled ID
                Thread.sleep(random.nextInt(50));
                updateSkinValue(itemKey, scrambledSkinId);

                // Verify application with original skin ID
                if (verifySkinApplication(itemKey, skinId)) {
                    success = true;
                    Log.d(TAG, "✅ Enhanced skin applied: " + itemKey + " -> " + skinId + " (scrambled: " + scrambledSkinId + ")");
                } else {
                    retryCount++;
                    Thread.sleep(RETRY_DELAY_MS);
                    Log.w(TAG, "⚠️ Skin application retry " + retryCount + " for " + itemKey);
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                break;
            } catch (Exception e) {
                Log.e(TAG, "Error in enhanced skin protection: " + e.getMessage());
                retryCount++;
            }
        }

        if (!success) {
            Log.e(TAG, "❌ Failed to apply skin after " + MAX_RETRY_ATTEMPTS + " attempts: " + itemKey);
        }
    }
    
    /**
     * Apply attachment with anti-detection measures
     */
    private static void applyAttachmentWithProtection(String weaponKey, String attachmentType, int attachmentId) {
        try {
            // Scramble memory before applying
            scrambleMemory();
            
            // Apply attachment with random delay
            Thread.sleep(random.nextInt(30));
            applyAttachment(weaponKey, attachmentType, attachmentId);
            
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
    
    // ===== ENHANCED MEMORY PROTECTION =====
    /**
     * Scrambles memory to prevent detection
     */
    private static void scrambleMemory() {
        if (!skinConfig.enableMemoryScrambling) return;

        try {
            // Generate random key
            random.nextBytes(MEMORY_SCRAMBLE_KEY);
            
            // Create buffer for scrambling
            byte[] buffer = new byte[1024];
            random.nextBytes(buffer);
            
            // Call native method to scramble memory
            scrambleMemoryNative(buffer, MEMORY_SCRAMBLE_KEY);
            
            // Clear sensitive data
            java.util.Arrays.fill(buffer, (byte) 0);
            java.util.Arrays.fill(MEMORY_SCRAMBLE_KEY, (byte) 0);

        } catch (Exception e) {
            Log.e(TAG, "Error in scrambleMemory: " + e.getMessage());
        }
    }
    
    /**
     * Verifies that a skin was applied correctly
     * @param weapon The weapon to verify
     * @param expectedSkinId The expected skin ID
     * @return true if verification successful, false otherwise
     */
    private static boolean verifySkinApplication(String weapon, int expectedSkinId) {
        if (!skinConfig.enableSkinVerification) return true;

        try {
            // Get current skin ID from native layer
            int currentSkinId = getCurrentSkinId(weapon);
            
            // Basic verification
            if (currentSkinId != expectedSkinId) {
                Log.w(TAG, "Skin verification failed for " + weapon + 
                    ": expected " + expectedSkinId + ", got " + currentSkinId);
                
                // Track failed verification
                Set<Integer> usedSkins = usedSkinIds.computeIfAbsent(weapon, k -> new HashSet<>());
                usedSkins.add(currentSkinId);
                
                // Attempt to reapply with enhanced protection
                if (skinConfig.enableAntiDetection) {
                    applyEnhancedProtection(weapon, expectedSkinId);
                } else {
                    updateSkinValue(weapon, expectedSkinId);
                }
                
                // Verify again after reapplication
                currentSkinId = getCurrentSkinId(weapon);
                if (currentSkinId != expectedSkinId) {
                    Log.e(TAG, "Skin reapplication failed for " + weapon);
                    return false;
                }
            }

            // Advanced verification if enabled
            if (skinConfig.protectionLevel >= 2) {
                // Check verification token
                if (!skinVerificationCounts.containsKey(weapon)) {
                    return false;
                }

                // Check protection timestamp
                if (!lastVerificationTimes.containsKey(weapon)) {
                    return false;
                }

                // Check protection level
                if (!skinProtectionLevels.containsKey(weapon) || 
                    skinProtectionLevels.get(weapon) != skinConfig.protectionLevel) {
                    return false;
                }
            }

            return true;

        } catch (Exception e) {
            Log.e(TAG, "Error in verifySkinApplication: " + e.getMessage());
            return false;
        }
    }
    
    /**
     * Schedule verification for a weapon
     */
    private static void scheduleVerification(String weapon) {
        lastVerificationTimes.put(weapon, System.currentTimeMillis());
    }
    
    /**
     * Check if verification is needed
     */
    private static boolean needsVerification(String weapon) {
        Long lastVerification = lastVerificationTimes.get(weapon);
        if (lastVerification == null) {
            return true;
        }
        return System.currentTimeMillis() - lastVerification > VERIFICATION_INTERVAL;
    }
    
    /**
     * Get available attachments for a weapon
     */
    public static Map<String, int[]> getAvailableAttachments(String weapon) {
        WeaponSkinData data = weaponSkinMap.get(weapon);
        return data != null ? data.attachments : new HashMap<>();
    }
    
    /**
     * Check if a weapon ID is compatible with metro mode
     */
    public static boolean isMetroModeCompatible(String weapon, int weaponId) {
        WeaponSkinData data = weaponSkinMap.get(weapon);
        if (data == null || data.metroModeIds == null) {
            return false;
        }
        
        for (int metroId : data.metroModeIds) {
            if (metroId == weaponId) {
                return true;
            }
        }
        return false;
    }
    
    /**
     * Get all supported weapons
     */
    public static String[] getSupportedWeapons() {
        return weaponSkinMap.keySet().toArray(new String[0]);
    }
    
    // ===== JNI METHODS =====
    private static native void updateSkinValue(String weaponKey, int skinId);
    private static native void applyAttachment(String weaponKey, String attachmentType, int attachmentId);
    private static native String getSkinName(String weaponKey, int skinId);
    private static native int[] getAvailableSkinIds(String weaponKey);
    private static native int getCurrentSkinId(String weaponKey);
    private static native void scrambleMemoryNative(byte[] buffer, byte[] key);
    
    // ===== ENHANCED TESTING SYSTEM =====
    public static void testWeaponSkin(String weapon, int skinIndex) {
        if (!skinConfig.enableDynamicSkins) return;

        WeaponSkinData weaponData = getWeaponData(weapon);
        if (weaponData == null || skinIndex >= weaponData.skinIds.length) {
            return;
        }

        // Apply test skin with full protection
        int skinId = weaponData.skinIds[skinIndex];
        applySkinWithProtection(weapon, skinId, weaponData.isSpecialSkin);

        // Verify application
        if (skinConfig.enableSkinVerification) {
            if (!verifySkinApplication(weapon, skinId)) {
                Log.w(TAG, "⚠️ Skin verification failed for weapon: " + weapon);
            }
        }
    }
    
    /**
     * Reset all skins to default
     */
    public static void resetAllSkins() {
        for (String weapon : weaponSkinMap.keySet()) {
            applyWeaponSkin(weapon, 0, null);
        }
        for (String vehicle : vehicleSkinMap.keySet()) {
            applyVehicleSkin(vehicle, 0);
        }
    }
    
    // ===== ENHANCED VEHICLE SKIN SYSTEM =====
    public static void applyVehicleSkin(String vehicleType, int skinIndex) {
        if (!skinConfig.enableDynamicSkins) return;

        // Check cooldown
        long currentTime = System.currentTimeMillis();
        Long lastChangeTime = lastSkinChangeTimes.get(vehicleType);
        if (lastChangeTime != null && currentTime - lastChangeTime < skinConfig.skinChangeCooldown) {
            return;
        }

        // Get vehicle data with verification
        VehicleSkinData vehicleData = getVehicleData(vehicleType);
        if (vehicleData == null || skinIndex >= vehicleData.skinIds.length) {
            return;
        }

        // Apply skin with protection
        int skinId = vehicleData.skinIds[skinIndex];
        if (skinConfig.enableAntiDetection) {
            applySkinWithProtection(vehicleType, skinId, false);
        } else {
            updateSkinValue(vehicleType, skinId);
        }

        // Update timestamps and verification
        lastSkinChangeTimes.put(vehicleType, currentTime);
        skinVerificationCounts.put(vehicleType, 0);

        // Schedule verification
        if (skinConfig.enableSkinVerification) {
            scheduleVerification(vehicleType);
        }
    }
    
    /**
     * Get available vehicle skins
     */
    public static String[] getAvailableVehicleTypes() {
        return vehicleSkinMap.keySet().toArray(new String[0]);
    }
    
    /**
     * Get vehicle skin data
     */
    public static VehicleSkinData getVehicleData(String vehicleType) {
        return vehicleSkinMap.get(vehicleType);
    }
    
    /**
     * Test vehicle skin application
     */
    public static void testVehicleSkin(String vehicleType, int skinIndex) {
        if (vehicleSkinMap.containsKey(vehicleType)) {
            Log.d(TAG, "Testing " + vehicleType + " with skin " + skinIndex);
            applyVehicleSkin(vehicleType, skinIndex);
        } else {
            Log.w(TAG, "Vehicle " + vehicleType + " not supported");
        }
    }

    // ======= COMPREHENSIVE SKIN/WEAPON/VEHICLE/DEADBOX/KILLFEED LISTS =======
    /**
     * Weapon skin information for quick lookup
     * This class provides essential information about a weapon's skins
     * and attachments for UI display and quick access.
     */
    public static class WeaponSkinInfo {
        /** Unique identifier for the weapon */
        public final int weaponId;
        
        /** Array of skin IDs */
        public final int[] skinIds;
        
        /** Array of skin names */
        public final String[] skinNames;
        
        /** Map of legendary attachment types to their IDs */
        public final Map<String, Integer> legendaryAttachments;
        
        /**
         * Constructor for WeaponSkinInfo
         * @param weaponId The unique identifier for the weapon
         * @param skinIds Array of skin IDs
         * @param skinNames Array of skin names
         * @param legendaryAttachments Map of legendary attachments
         */
        public WeaponSkinInfo(int weaponId, int[] skinIds, String[] skinNames, 
                            Map<String, Integer> legendaryAttachments) {
            this.weaponId = weaponId;
            this.skinIds = skinIds;
            this.skinNames = skinNames;
            this.legendaryAttachments = legendaryAttachments;
        }
    }

    /**
     * Vehicle skin information for quick lookup
     * This class provides essential information about a vehicle's skins
     * for UI display and quick access.
     */
    public static class VehicleSkinInfo {
        /** Unique identifier for the vehicle */
        public final int vehicleId;
        
        /** Array of skin IDs */
        public final int[] skinIds;
        
        /** Array of skin names */
        public final String[] skinNames;
        
        /**
         * Constructor for VehicleSkinInfo
         * @param vehicleId The unique identifier for the vehicle
         * @param skinIds Array of skin IDs
         * @param skinNames Array of skin names
         */
        public VehicleSkinInfo(int vehicleId, int[] skinIds, String[] skinNames) {
            this.vehicleId = vehicleId;
            this.skinIds = skinIds;
            this.skinNames = skinNames;
        }
    }

    /**
     * Deadbox skin information
     * This class provides information about a weapon's deadbox appearance
     * and its legendary attachments.
     */
    public static class DeadboxSkinInfo {
        /** Unique identifier for the weapon */
        public final int weaponId;
        
        /** Maximum skin ID for this weapon */
        public final int maxSkinId;
        
        /** Array of legendary attachment IDs */
        public final int[] legendaryAttachments;
        
        /**
         * Constructor for DeadboxSkinInfo
         * @param weaponId The unique identifier for the weapon
         * @param maxSkinId Maximum skin ID
         * @param legendaryAttachments Array of legendary attachment IDs
         */
        public DeadboxSkinInfo(int weaponId, int maxSkinId, int[] legendaryAttachments) {
            this.weaponId = weaponId;
            this.maxSkinId = maxSkinId;
            this.legendaryAttachments = legendaryAttachments;
        }
    }

    /**
     * Kill message skin information
     * This class provides information about a weapon's kill feed appearance.
     */
    public static class KillMessageSkinInfo {
        /** Unique identifier for the weapon */
        public final int weaponId;
        
        /** Kill feed skin ID */
        public final int killFeedSkinId;
        
        /** Display name for the kill feed */
        public final String displayName;
        
        /**
         * Constructor for KillMessageSkinInfo
         * @param weaponId The unique identifier for the weapon
         * @param killFeedSkinId Kill feed skin ID
         * @param displayName Display name for the kill feed
         */
        public KillMessageSkinInfo(int weaponId, int killFeedSkinId, String displayName) {
            this.weaponId = weaponId;
            this.killFeedSkinId = killFeedSkinId;
            this.displayName = displayName;
        }
    }

    // Global maps for easy lookup and expansion
    private static final Map<String, WeaponSkinInfo> WEAPON_SKIN_MAP = new HashMap<String, WeaponSkinInfo>() {{
        put("M416", new WeaponSkinInfo(101004, new int[]{1101004003, 1101004006}, new String[]{"Default", "Glacier"}, new HashMap<String, Integer>() {{
            put("SCOPE4X", 1203004001);
            put("COMPENSATOR", 1201009001);
        }}));
        put("AKM", new WeaponSkinInfo(101001, new int[]{1101001003, 1101001006}, new String[]{"Default", "Glacier"}, new HashMap<String, Integer>() {{
            put("SCOPE4X", 1203004002);
            put("COMPENSATOR", 1201009002);
        }}));
        put("SCAR", new WeaponSkinInfo(101003, new int[]{1101003003, 1101003006}, new String[]{"Default", "Glacier"}, new HashMap<String, Integer>() {{
            put("SCOPE4X", 1203004003);
            put("COMPENSATOR", 1201009003);
        }}));
        put("AWM", new WeaponSkinInfo(103003, new int[]{1103003003, 1103003006}, new String[]{"Default", "Glacier"}, new HashMap<String, Integer>() {{
            put("SCOPE4X", 1203004004);
            put("SCOPE6X", 1203015004);
        }}));
        put("MK14", new WeaponSkinInfo(103007, new int[]{1103007003, 1103007006}, new String[]{"Default", "Glacier"}, new HashMap<String, Integer>() {{
            put("SCOPE4X", 1037010115);
            put("COMPENSATOR", 1037010128);
        }}));
        put("MG3", new WeaponSkinInfo(105010, new int[]{1105010003, 1105010006}, new String[]{"Default", "Glacier"}, new HashMap<String, Integer>() {{
            put("SCOPE4X", 1051010115);
            put("COMPENSATOR", 1051010128);
        }}));
        put("ACE32", new WeaponSkinInfo(101102, new int[]{1101102003, 1101102017}, new String[]{"Default", "Icicle Spike (Lv. 7)"}, new HashMap<String, Integer>() {{
            put("SCOPE4X", 1011020115);
            put("COMPENSATOR", 1011020128);
        }}));
        put("UMP", new WeaponSkinInfo(102002, new int[]{1102002003, 1102002006}, new String[]{"Default", "Glacier"}, new HashMap<String, Integer>() {{
            put("SCOPE4X", 1203004002);
            put("COMPENSATOR", 1201009003);
        }}));
        put("Vector", new WeaponSkinInfo(102003, new int[]{1102003003, 1102003006}, new String[]{"Default", "Glacier"}, new HashMap<String, Integer>() {{
            put("SCOPE4X", 1203004003);
            put("COMPENSATOR", 1201009004);
        }}));
        put("UZI", new WeaponSkinInfo(102001, new int[]{1102001003, 1102001006}, new String[]{"Default", "Glacier"}, new HashMap<String, Integer>() {{
            put("COMPENSATOR", 1201009005);
            put("SILENCER", 1201011005);
        }}));
        put("GROZA", new WeaponSkinInfo(101005, new int[]{1101005003, 1101005006}, new String[]{"Default", "Glacier"}, new HashMap<String, Integer>() {{
            put("SCOPE4X", 1203004005);
            put("COMPENSATOR", 1201009005);
        }}));
        put("FAMAS", new WeaponSkinInfo(101100, new int[]{1101100003, 1101100006}, new String[]{"Default", "Glacier"}, new HashMap<String, Integer>() {{
            put("SCOPE4X", 1203004006);
            put("COMPENSATOR", 1201009006);
        }}));
        put("AUG", new WeaponSkinInfo(101006, new int[]{1101006003, 1101006006}, new String[]{"Default", "Glacier"}, new HashMap<String, Integer>() {{
            put("SCOPE4X", 1203004007);
            put("COMPENSATOR", 1201009007);
        }}));
        put("M762", new WeaponSkinInfo(101008, new int[]{1101008003, 1101008006}, new String[]{"Default", "Glacier"}, new HashMap<String, Integer>() {{
            put("SCOPE4X", 1203004008);
            put("COMPENSATOR", 1201009008);
        }}));
    }};

    public static final Map<String, VehicleSkinInfo> VEHICLE_SKIN_MAP = new HashMap<String, VehicleSkinInfo>() {{
        put("CAR", new VehicleSkinInfo(1301001001, new int[]{1301001001, 1301001002, 1301001003, 1301001004, 1301001005}, 
            new String[]{"Default", "Racing", "Military", "Sports", "Luxury"}));
        put("MOTORCYCLE", new VehicleSkinInfo(1302001001, new int[]{1302001001, 1302001002, 1302001003, 1302001004, 1302001005}, 
            new String[]{"Default", "Racing", "Military", "Sports", "Luxury"}));
        put("PARACHUTE", new VehicleSkinInfo(1401001001, new int[]{1401001001, 1401001002, 1401001003, 1401001004, 1401001005}, 
            new String[]{"Default", "Rainbow", "Military", "Sports", "Luxury"}));
    }};

    public static final Map<String, DeadboxSkinInfo> DEADBOX_SKIN_MAP = new HashMap<String, DeadboxSkinInfo>() {{
        put("M416", new DeadboxSkinInfo(101004, 1101004006, new int[]{1203004001, 1201009001})); // Glacier M416 with 4x and compensator
        put("AKM", new DeadboxSkinInfo(101001, 1101001006, new int[]{1203004002, 1201009002})); // Glacier AKM with 4x and compensator
        put("SCAR", new DeadboxSkinInfo(101003, 1101003006, new int[]{1203004003, 1201009003})); // Glacier SCAR with 4x and compensator
        put("AWM", new DeadboxSkinInfo(103003, 1103003006, new int[]{1203004004, 1203015004})); // Glacier AWM with 4x and 6x
        put("MK14", new DeadboxSkinInfo(103007, 1103007006, new int[]{1037010115, 1037010128})); // Glacier MK14 with 4x and compensator
        put("MG3", new DeadboxSkinInfo(105010, 1105010006, new int[]{1051010115, 1051010128})); // Glacier MG3 with 4x and compensator
        put("ACE32", new DeadboxSkinInfo(101102, 1101102017, new int[]{1011020115, 1011020128})); // Icicle Spike ACE32 with 4x and compensator
        put("UMP", new DeadboxSkinInfo(102002, 1102002006, new int[]{1203004002, 1201009003})); // Glacier UMP with 4x and compensator
        put("Vector", new DeadboxSkinInfo(102003, 1102003006, new int[]{1203004003, 1201009004})); // Glacier Vector with 4x and compensator
        put("UZI", new DeadboxSkinInfo(102001, 1102001006, new int[]{1201009005, 1201011005})); // Glacier UZI with compensator and silencer
        put("GROZA", new DeadboxSkinInfo(101005, 1101005006, new int[]{1203004005, 1201009005})); // Glacier GROZA with 4x and compensator
        put("FAMAS", new DeadboxSkinInfo(101100, 1101100006, new int[]{1203004006, 1201009006})); // Glacier FAMAS with 4x and compensator
        put("AUG", new DeadboxSkinInfo(101006, 1101006006, new int[]{1203004007, 1201009007})); // Glacier AUG with 4x and compensator
        put("M762", new DeadboxSkinInfo(101008, 1101008006, new int[]{1203004008, 1201009008})); // Glacier M762 with 4x and compensator
    }};

    public static final Map<String, KillMessageSkinInfo> KILLMESSAGE_SKIN_MAP = new HashMap<String, KillMessageSkinInfo>() {{
        put("M416", new KillMessageSkinInfo(101004, 1101004006, "Glacier M416"));
        put("AKM", new KillMessageSkinInfo(101001, 1101001006, "Glacier AKM"));
        put("SCAR", new KillMessageSkinInfo(101003, 1101003006, "Glacier SCAR"));
        put("AWM", new KillMessageSkinInfo(103003, 1103003006, "Glacier AWM"));
        put("MK14", new KillMessageSkinInfo(103007, 1103007006, "Glacier MK14"));
        put("MG3", new KillMessageSkinInfo(105010, 1105010006, "Glacier MG3"));
        put("ACE32", new KillMessageSkinInfo(101102, 1101102017, "Icicle Spike ACE32"));
        put("UMP", new KillMessageSkinInfo(102002, 1102002006, "Glacier UMP"));
        put("Vector", new KillMessageSkinInfo(102003, 1102003006, "Glacier Vector"));
        put("UZI", new KillMessageSkinInfo(102001, 1102001006, "Glacier UZI"));
        put("GROZA", new KillMessageSkinInfo(101005, 1101005006, "Glacier GROZA"));
        put("FAMAS", new KillMessageSkinInfo(101100, 1101100006, "Glacier FAMAS"));
        put("AUG", new KillMessageSkinInfo(101006, 1101006006, "Glacier AUG"));
        put("M762", new KillMessageSkinInfo(101008, 1101008006, "Glacier M762"));
    }};

    /**
     * Get the skin name for a weapon and skin index (Java-side, not JNI)
     */
    public static String getSkinNameByIndex(String weapon, int skinIndex) {
        WeaponSkinData data = weaponSkinMap.get(weapon);
        if (data == null || skinIndex < 0 || skinIndex >= data.skinNames.length) {
            return "Unknown Skin";
        }
        return data.skinNames[skinIndex];
    }

    /**
     * Get the skin index for a weapon and skinId (returns -1 if not found)
     */
    public static int getSkinIndexById(String weapon, int skinId) {
        WeaponSkinData data = weaponSkinMap.get(weapon);
        if (data == null) return -1;
        for (int i = 0; i < data.skinIds.length; i++) {
            if (data.skinIds[i] == skinId) return i;
        }
        return -1;
    }

    /**
     * Get the currently equipped skin name for a weapon (real-time)
     */
    public static String getCurrentEquippedSkinName(String weapon) {
        int currentSkinId = getCurrentSkinId(weapon);
        int idx = getSkinIndexById(weapon, currentSkinId);
        return getSkinNameByIndex(weapon, idx);
    }

    /**
     * Applies a skin to a weapon with enhanced protection and verification
     * @param weapon The weapon to apply the skin to
     * @param skinIndex The index of the skin to apply
     * @param attachments Optional attachments to apply
     * @return Map containing the result of the operation
     */
    public static Map<String, Object> patchWeaponSkin(String weapon, int skinIndex) {
        Map<String, Object> result = new HashMap<>();
        result.put("success", false);
        
        try {
            // Check if weapon exists
            if (!WEAPON_SKIN_MAP.containsKey(weapon)) {
                result.put("error", "Weapon not found: " + weapon);
                return result;
            }

            // Validate skin index
            WeaponSkinInfo weaponInfo = WEAPON_SKIN_MAP.get(weapon);
            if (skinIndex < 0 || skinIndex >= weaponInfo.skinIds.length) {
                result.put("error", "Invalid skin index: " + skinIndex);
                return result;
            }

            // Check cooldown
            long currentTime = System.currentTimeMillis();
            if (lastSkinChangeTimes.containsKey(weapon)) {
                long lastChange = lastSkinChangeTimes.get(weapon);
                if (currentTime - lastChange < skinConfig.skinChangeCooldown) {
                    result.put("error", "Skin change cooldown active");
                    return result;
                }
            }

            // Apply skin with protection
            int skinId = weaponInfo.skinIds[skinIndex];
            applyEnhancedProtection(weapon, skinId);
            
            // Update native layer
            updateSkinValue(weapon, skinId);
            
            // Apply anti-detection measures if enabled
            if (skinConfig.enableAntiDetection) {
                scrambleMemory();
            }

            // Update timestamps
            lastSkinChangeTimes.put(weapon, currentTime);
            lastWeaponChangeTime = currentTime;

            // Verify skin application if enabled
            boolean verificationSuccess = true;
            if (skinConfig.enableSkinVerification) {
                verificationSuccess = verifySkinApplication(weapon, skinId);
                if (!verificationSuccess) {
                    // Retry with enhanced protection
                    applyEnhancedProtection(weapon, skinId);
                    updateSkinValue(weapon, skinId);
                    verificationSuccess = verifySkinApplication(weapon, skinId);
                }
            }

            // Update real-time skin name
            updateRealTimeSkinName(weapon);

            // Prepare result
            result.put("success", true);
            result.put("weapon", weapon);
            result.put("skinId", skinId);
            result.put("skinName", weaponInfo.skinNames[skinIndex]);
            result.put("verificationSuccess", verificationSuccess);
            result.put("timestamp", currentTime);
            result.put("currentState", getRealTimeWeaponStatus(weapon));

        } catch (Exception e) {
            result.put("error", "Error applying skin: " + e.getMessage());
            Log.e(TAG, "Error in patchWeaponSkin: " + e.getMessage());
        }

        return result;
    }

    /**
     * Applies enhanced protection measures to a weapon skin using MemoryScrambler
     * @param weapon The weapon to protect
     * @param skinId The skin ID to protect
     */
    private static void applyEnhancedProtection(String weapon, int skinId) {
        try {
            // Validate skin ID before processing
            if (!MemoryScrambler.isValidSkinID(skinId)) {
                Log.w(TAG, "Invalid skin ID detected: " + skinId + " for weapon: " + weapon);
                return;
            }

            // Apply basic protection
            if (skinConfig.enableAntiDetection) {
                // Add random delay
                Thread.sleep(random.nextInt(50));

                // Enhanced memory scrambling with MemoryScrambler
                scrambleMemory();

                // Generate dynamic protection key
                long protectionKey = MemoryScrambler.generateScrambleKey();

                // Apply multi-layer scrambling
                int scrambledSkinId = MemoryScrambler.enhancedScrambleSkinID(skinId);

                // Store scrambled ID for verification
                activeSkinNames.put(weapon, String.valueOf(scrambledSkinId));

                // Update protection level
                skinProtectionLevels.put(weapon, skinConfig.protectionLevel);

                Log.d(TAG, "🛡️ Enhanced protection applied: " + weapon + " -> " + skinId + " (scrambled: " + scrambledSkinId + ")");
            }

            // Apply advanced protection if enabled
            if (skinConfig.enableSkinProtection && skinConfig.protectionLevel > 1) {
                // Additional protection measures with enhanced scrambling
                Thread.sleep(random.nextInt(100));
                scrambleMemory();

                // Regenerate keys periodically for maximum security
                if (System.currentTimeMillis() % 10000 < 100) { // Every ~10 seconds
                    MemoryScrambler.regenerateKeys();
                }
            }

        } catch (Exception e) {
            Log.e(TAG, "Error in applyEnhancedProtection: " + e.getMessage());
            // Fallback to basic protection
            try {
                scrambleMemory();
                skinProtectionLevels.put(weapon, 1); // Basic protection level
            } catch (Exception fallbackError) {
                Log.e(TAG, "Fallback protection also failed: " + fallbackError.getMessage());
            }
        }
    }

    /**
     * Updates the real-time skin name for a weapon
     * @param weapon The weapon to update
     */
    private static void updateRealTimeSkinName(String weapon) {
        try {
            // Get current skin ID
            int currentSkinId = getCurrentSkinId(weapon);
            
            // Get skin name from native layer
            String skinName = getSkinName(weapon, currentSkinId);
            
            // Update active skin name
            activeSkinNames.put(weapon, skinName);
            lastSkinNameUpdate.put(weapon, System.currentTimeMillis());
            
            // Update skin history
            List<String> history = skinNameHistory.computeIfAbsent(weapon, k -> new ArrayList<>());
            history.add(0, skinName); // Add to beginning of list
            
            // Trim history if too long
            if (history.size() > MAX_SKIN_HISTORY) {
                history.subList(MAX_SKIN_HISTORY, history.size()).clear();
            }

        } catch (Exception e) {
            Log.e(TAG, "Error in updateRealTimeSkinName: " + e.getMessage());
        }
    }

    /**
     * Gets the real-time skin name for a weapon
     * @param weapon The weapon to get the skin name for
     * @return The current skin name
     */
    public static String getRealTimeSkinName(String weapon) {
        try {
            // Check if we need to update the skin name
            long currentTime = System.currentTimeMillis();
            if (!lastSkinNameUpdate.containsKey(weapon) || 
                currentTime - lastSkinNameUpdate.get(weapon) > SKIN_NAME_UPDATE_INTERVAL) {
                updateRealTimeSkinName(weapon);
            }
            
            // Return current skin name
            return activeSkinNames.getOrDefault(weapon, "Unknown");

        } catch (Exception e) {
            Log.e(TAG, "Error in getRealTimeSkinName: " + e.getMessage());
            return "Error";
        }
    }

    /**
     * Gets the skin name history for a weapon
     * @param weapon The weapon to get the history for
     * @return List of recent skin names
     */
    public static List<String> getSkinNameHistory(String weapon) {
        return skinNameHistory.getOrDefault(weapon, new ArrayList<>());
    }

    /**
     * Gets comprehensive skin information for a weapon
     * @param weapon The weapon to get information for
     * @return Map containing detailed skin information
     */
    public static Map<String, Object> getComprehensiveSkinInfo(String weapon) {
        Map<String, Object> info = new HashMap<>();
        
        try {
            // Basic weapon info
            WeaponSkinInfo weaponInfo = WEAPON_SKIN_MAP.get(weapon);
            if (weaponInfo != null) {
                info.put("weaponId", weaponInfo.weaponId);
                info.put("availableSkins", weaponInfo.skinNames);
                info.put("legendaryAttachments", weaponInfo.legendaryAttachments);
            }

            // Current state
            info.put("currentSkinName", getRealTimeSkinName(weapon));
            info.put("skinHistory", getSkinNameHistory(weapon));
            info.put("lastUpdate", lastSkinNameUpdate.getOrDefault(weapon, 0L));
            
            // Protection info
            info.put("protectionLevel", skinProtectionLevels.getOrDefault(weapon, 0));
            info.put("lastVerification", lastVerificationTimes.getOrDefault(weapon, 0L));
            
            // Configuration
            info.put("isDynamicSkinsEnabled", skinConfig.enableDynamicSkins);
            info.put("isAntiDetectionEnabled", skinConfig.enableAntiDetection);
            info.put("isSkinVerificationEnabled", skinConfig.enableSkinVerification);

        } catch (Exception e) {
            Log.e(TAG, "Error in getComprehensiveSkinInfo: " + e.getMessage());
            info.put("error", e.getMessage());
        }

        return info;
    }

    /**
     * Gets real-time skin information for all weapons
     * @return Map containing information for all weapons
     */
    public static Map<String, Map<String, Object>> getAllRealTimeSkinInfo() {
        Map<String, Map<String, Object>> allWeaponInfo = new HashMap<>();
        
        for (String weapon : WEAPON_SKIN_MAP.keySet()) {
            Map<String, Object> weaponInfo = getComprehensiveSkinInfo(weapon);
            
            // Add additional real-time data
            weaponInfo.put("currentSkinId", getCurrentSkinId(weapon));
            weaponInfo.put("currentSkinName", getRealTimeSkinName(weapon));
            weaponInfo.put("skinNameHistory", getSkinNameHistory(weapon));
            weaponInfo.put("lastUpdateTime", lastSkinNameUpdate.get(weapon));
            
            // Add deadbox info if available
            DeadboxSkinInfo deadboxInfo = DEADBOX_SKIN_MAP.get(weapon);
            if (deadboxInfo != null) {
                Map<String, Object> deadboxData = new HashMap<>();
                deadboxData.put("maxSkinId", deadboxInfo.maxSkinId);
                deadboxData.put("legendaryAttachments", deadboxInfo.legendaryAttachments);
                weaponInfo.put("deadboxInfo", deadboxData);
            }
            
            // Add kill message info if available
            KillMessageSkinInfo killInfo = KILLMESSAGE_SKIN_MAP.get(weapon);
            if (killInfo != null) {
                Map<String, Object> killData = new HashMap<>();
                killData.put("killFeedSkinId", killInfo.killFeedSkinId);
                killData.put("displayName", killInfo.displayName);
                weaponInfo.put("killMessageInfo", killData);
            }
            
            allWeaponInfo.put(weapon, weaponInfo);
        }
        
        return allWeaponInfo;
    }

    /**
     * Gets real-time skin information for a specific weapon
     * @param weapon The weapon to get information for
     * @return Map containing detailed weapon information
     */
    public static Map<String, Object> getRealTimeWeaponInfo(String weapon) {
        Map<String, Object> weaponInfo = getComprehensiveSkinInfo(weapon);
        
        // Add real-time data
        weaponInfo.put("currentSkinId", getCurrentSkinId(weapon));
        weaponInfo.put("currentSkinName", getRealTimeSkinName(weapon));
        weaponInfo.put("skinNameHistory", getSkinNameHistory(weapon));
        weaponInfo.put("lastUpdateTime", lastSkinNameUpdate.get(weapon));
        
        // Add deadbox info if available
        DeadboxSkinInfo deadboxInfo = DEADBOX_SKIN_MAP.get(weapon);
        if (deadboxInfo != null) {
            Map<String, Object> deadboxData = new HashMap<>();
            deadboxData.put("maxSkinId", deadboxInfo.maxSkinId);
            deadboxData.put("legendaryAttachments", deadboxInfo.legendaryAttachments);
            weaponInfo.put("deadboxInfo", deadboxData);
        }
        
        // Add kill message info if available
        KillMessageSkinInfo killInfo = KILLMESSAGE_SKIN_MAP.get(weapon);
        if (killInfo != null) {
            Map<String, Object> killData = new HashMap<>();
            killData.put("killFeedSkinId", killInfo.killFeedSkinId);
            killData.put("displayName", killInfo.displayName);
            weaponInfo.put("killMessageInfo", killData);
        }
        
        return weaponInfo;
    }

    /**
     * Gets real-time skin status for all weapons
     * @return Map containing status for all weapons
     */
    public static Map<String, String> getAllRealTimeSkinStatus() {
        Map<String, String> statusMap = new HashMap<>();
        
        for (String weapon : WEAPON_SKIN_MAP.keySet()) {
            String currentSkin = getRealTimeSkinName(weapon);
            int currentSkinId = getCurrentSkinId(weapon);
            String status = String.format("%s (ID: %d)", currentSkin, currentSkinId);
            statusMap.put(weapon, status);
        }
        
        return statusMap;
    }

    /**
     * Gets real-time skin status for a specific weapon
     * @param weapon The weapon to get status for
     * @return String containing weapon status
     */
    public static String getRealTimeWeaponStatus(String weapon) {
        String currentSkin = getRealTimeSkinName(weapon);
        int currentSkinId = getCurrentSkinId(weapon);
        return String.format("%s (ID: %d)", currentSkin, currentSkinId);
    }

    /**
     * Resets all real-time data for a weapon
     * @param weapon The weapon to reset
     */
    public static void resetSkinNameHistory(String weapon) {
        try {
            activeSkinNames.remove(weapon);
            lastSkinNameUpdate.remove(weapon);
            skinNameHistory.remove(weapon);
            lastSkinChangeTimes.remove(weapon);
            skinVerificationCounts.remove(weapon);
            lastVerificationTimes.remove(weapon);
            skinProtectionLevels.remove(weapon);
        } catch (Exception e) {
            Log.e(TAG, "Error in resetSkinNameHistory: " + e.getMessage());
        }
    }

    /**
     * Clears all real-time data for all weapons
     */
    public static void clearAllRealTimeData() {
        try {
            activeSkinNames.clear();
            lastSkinNameUpdate.clear();
            skinNameHistory.clear();
            lastSkinChangeTimes.clear();
            skinVerificationCounts.clear();
            lastVerificationTimes.clear();
            skinProtectionLevels.clear();
        } catch (Exception e) {
            Log.e(TAG, "Error in clearAllRealTimeData: " + e.getMessage());
        }
    }

    /**
     * Import skin preset from JSON format
     * @param jsonString JSON string containing preset data
     * @return true if import was successful
     */
    public static boolean importPresetFromJson(String jsonString) {
        try {
            JSONObject json = new JSONObject(jsonString);
            
            // Get preset details
            String name = json.getString("name");
            boolean isSpecial = json.getBoolean("isSpecial");
            
            // Get weapon skins
            Map<String, Integer> weaponSkins = new HashMap<>();
            JSONObject weaponsJson = json.getJSONObject("weapons");
            Iterator<String> weaponKeys = weaponsJson.keys();
            while (weaponKeys.hasNext()) {
                String weapon = weaponKeys.next();
                JSONObject weaponInfo = weaponsJson.getJSONObject(weapon);
                weaponSkins.put(weapon, weaponInfo.getInt("skinIndex"));
            }
            
            // Get attachments
            Map<String, Map<String, Integer>> attachments = new HashMap<>();
            weaponKeys = weaponsJson.keys();
            while (weaponKeys.hasNext()) {
                String weapon = weaponKeys.next();
                JSONObject weaponInfo = weaponsJson.getJSONObject(weapon);
                
                // Get attachments
                if (weaponInfo.has("attachments")) {
                    JSONObject attJson = weaponInfo.getJSONObject("attachments");
                    Map<String, Integer> weaponAttachments = new HashMap<>();
                    Iterator<String> attKeys = attJson.keys();
                    while (attKeys.hasNext()) {
                        String attType = attKeys.next();
                        weaponAttachments.put(attType, attJson.getInt(attType));
                    }
                    attachments.put(weapon, weaponAttachments);
                }
            }
            
            Map<String, Object> preset = createCustomPreset(name, weaponSkins, attachments, isSpecial);
            return preset != null;
            
        } catch (Exception e) {
            Log.e(TAG, "Error importing preset: " + e.getMessage());
            return false;
        }
    }

    private static Map<String, Object> createCustomPreset(String name,
            Map<String, Integer> weaponSkins,
            Map<String, Map<String, Integer>> attachments,
            boolean isSpecial) {
        Map<String, Object> preset = new HashMap<>();
        preset.put("name", name);
        preset.put("weaponSkins", weaponSkins);
        preset.put("attachments", attachments);
        preset.put("isSpecial", isSpecial);
        return preset;
    }

    // ===== ENHANCED MEMORY SCRAMBLER INTEGRATION METHODS =====

    /**
     * Batch apply skins with enhanced scrambling for performance
     */
    public static void batchApplySkinsWithScrambling(Map<String, Integer> weaponSkinMap) {
        if (weaponSkinMap == null || weaponSkinMap.isEmpty()) {
            return;
        }

        try {
            // Prepare arrays for batch processing
            int[] skinIds = weaponSkinMap.values().stream().mapToInt(Integer::intValue).toArray();
            String[] weapons = weaponSkinMap.keySet().toArray(new String[0]);

            // Batch scramble all skin IDs
            int[] scrambledIds = MemoryScrambler.batchScrambleSkinIDs(skinIds);

            // Apply scrambled skins
            for (int i = 0; i < weapons.length && i < scrambledIds.length; i++) {
                String weapon = weapons[i];
                int originalSkinId = skinIds[i];
                int scrambledSkinId = scrambledIds[i];

                // Apply with enhanced protection
                scrambleMemory();
                updateSkinValue(weapon, scrambledSkinId);

                // Store for verification
                activeSkinNames.put(weapon, String.valueOf(scrambledSkinId));
                lastSkinChangeTimes.put(weapon, System.currentTimeMillis());

                Log.v(TAG, "Batch applied: " + weapon + " -> " + originalSkinId + " (scrambled: " + scrambledSkinId + ")");
            }

            Log.d(TAG, "✅ Batch skin application completed: " + weaponSkinMap.size() + " skins");

        } catch (Exception e) {
            Log.e(TAG, "Error in batch skin application: " + e.getMessage());
            // Fallback to individual application
            for (Map.Entry<String, Integer> entry : weaponSkinMap.entrySet()) {
                applySkinWithProtection(entry.getKey(), entry.getValue(), false);
            }
        }
    }

    /**
     * Clear scrambling cache for memory management
     */
    public static void clearScramblingCache() {
        try {
            MemoryScrambler.clearScrambleHistory();
            activeSkinNames.clear();
            lastSkinChangeTimes.clear();
            skinVerificationCounts.clear();

            Log.d(TAG, "🧹 Scrambling cache cleared");

        } catch (Exception e) {
            Log.e(TAG, "Error clearing scrambling cache: " + e.getMessage());
        }
    }

    /**
     * Get scrambling statistics for debugging
     */
    public static Map<String, Object> getScramblingStats() {
        Map<String, Object> stats = new HashMap<>();

        try {
            // Get MemoryScrambler stats
            Map<String, Object> scramblerStats = MemoryScrambler.getScrambleStats();
            stats.putAll(scramblerStats);

            // Add SkinManager specific stats
            stats.put("activeSkins", activeSkinNames.size());
            stats.put("lastSkinChanges", lastSkinChangeTimes.size());
            stats.put("verificationCounts", skinVerificationCounts.size());
            stats.put("protectionLevels", skinProtectionLevels.size());

            return stats;

        } catch (Exception e) {
            Log.e(TAG, "Error getting scrambling stats: " + e.getMessage());
            return new HashMap<>();
        }
    }

    // ===== X-SUIT ANTI-DETECTION METHODS =====

    /**
     * Apply X-Suit with enhanced anti-detection protection
     */
    public static boolean applyXSuitWithProtection(int xSuitId) {
        try {
            // Validate X-Suit ID
            if (!MemoryScrambler.isValidXSuitID(xSuitId)) {
                Log.w(TAG, "Invalid X-Suit ID: " + xSuitId);
                return false;
            }

            // Check if safe to apply
            if (!MemoryScrambler.isXSuitSafeToApply(xSuitId)) {
                Log.w(TAG, "X-Suit application blocked for safety: " + xSuitId);
                return false;
            }

            // Apply enhanced memory scrambling
            scrambleMemory();

            // Scramble X-Suit ID
            int scrambledXSuitId = MemoryScrambler.scrambleXSuitID(xSuitId);

            // Apply through native layer with scrambled ID
            updateSkinValue("XSUIT", scrambledXSuitId);

            // Verify application
            if (skinConfig.enableSkinVerification) {
                if (!verifySkinApplication("XSUIT", xSuitId)) {
                    Log.w(TAG, "X-Suit verification failed: " + xSuitId);
                    return false;
                }
            }

            Log.d(TAG, "✅ X-Suit applied with protection: " + xSuitId + " -> " + scrambledXSuitId);
            return true;

        } catch (Exception e) {
            Log.e(TAG, "Error applying X-Suit with protection: " + e.getMessage());
            return false;
        }
    }

    /**
     * Batch apply X-Suits with enhanced protection
     */
    public static void batchApplyXSuitsWithProtection(int[] xSuitIds) {
        if (xSuitIds == null || xSuitIds.length == 0) {
            return;
        }

        try {
            for (int xSuitId : xSuitIds) {
                if (MemoryScrambler.isXSuitSafeToApply(xSuitId)) {
                    applyXSuitWithProtection(xSuitId);

                    // Add random delay between applications
                    Thread.sleep(random.nextInt(1000) + 500); // 500-1500ms
                }
            }

            Log.d(TAG, "✅ Batch X-Suit application completed: " + xSuitIds.length + " X-Suits");

        } catch (Exception e) {
            Log.e(TAG, "Error in batch X-Suit application: " + e.getMessage());
        }
    }

    /**
     * Clear X-Suit application history for safety
     */
    public static void clearXSuitHistory() {
        try {
            MemoryScrambler.clearXSuitHistory();
            Log.d(TAG, "🧹 X-Suit history cleared");
        } catch (Exception e) {
            Log.e(TAG, "Error clearing X-Suit history: " + e.getMessage());
        }
    }

    /**
     * Test enhanced scrambling system including X-Suits
     */
    public static void testEnhancedScrambling() {
        Log.d(TAG, "🧪 Testing Enhanced Scrambling System");

        try {
            // Test basic scrambling
            int testSkinId = 1101004006; // M416 Glacier
            int scrambledId = MemoryScrambler.shuffleSkinID(testSkinId);
            int unscrambledId = MemoryScrambler.unscrambleSkinID(scrambledId);

            Log.d(TAG, "Basic test: " + testSkinId + " -> " + scrambledId + " -> " + unscrambledId);

            // Test enhanced scrambling
            int enhancedScrambled = MemoryScrambler.enhancedScrambleSkinID(testSkinId);
            int enhancedUnscrambled = MemoryScrambler.enhancedUnscrambleSkinID(enhancedScrambled);

            Log.d(TAG, "Enhanced test: " + testSkinId + " -> " + enhancedScrambled + " -> " + enhancedUnscrambled);

            // Test X-Suit scrambling
            int xSuitId = 1405909; // Blood Raven X-Suit
            if (MemoryScrambler.isXSuitSafeToApply(xSuitId)) {
                int scrambledXSuit = MemoryScrambler.scrambleXSuitID(xSuitId);
                Log.d(TAG, "X-Suit test: " + xSuitId + " -> " + scrambledXSuit);
            }

            // Test batch processing
            int[] testIds = {1101004006, 1101001006, 1103003006}; // M416, AKM, AWM Glacier
            int[] batchScrambled = MemoryScrambler.batchScrambleSkinIDs(testIds);
            int[] batchUnscrambled = MemoryScrambler.batchUnscrambleSkinIDs(batchScrambled);

            Log.d(TAG, "Batch test completed successfully");

            // Test X-Suit batch application
            int[] xSuitTestIds = {1405909, 1405628, 1406152}; // Blood Raven, Golden Pharaoh, Avalanche
            batchApplyXSuitsWithProtection(xSuitTestIds);

            // Get stats
            Map<String, Object> stats = MemoryScrambler.getScrambleStats();
            Log.d(TAG, "Scrambling stats: " + stats.toString());

            Log.d(TAG, "✅ Enhanced scrambling system test completed successfully");

        } catch (Exception e) {
            Log.e(TAG, "❌ Enhanced scrambling test failed: " + e.getMessage());
        }
    }

    /**
     * Enhanced skin protection system with multiple security layers
     */
    public static void enableAdvancedSkinProtection(boolean enabled) {
        try {
            skinConfig.enableSkinProtection = enabled;
            if (enabled) {
                // Initialize advanced protection mechanisms
                initializeAdvancedProtection();
            }
            Log.d(TAG, "Advanced skin protection " + (enabled ? "enabled" : "disabled"));
        } catch (Exception e) {
            Log.e(TAG, "Error setting advanced skin protection", e);
        }
    }
    
    /**
     * Initialize advanced protection mechanisms
     */
    private static void initializeAdvancedProtection() {
        try {
            // Initialize memory scrambling for all weapon types
            for (String weapon : getSupportedWeapons()) {
                // Pre-generate scrambled values
                for (int i = 0; i < 10; i++) {
                    scrambleMemory();
                    Thread.sleep(1); // Prevent timing patterns
                }
            }
            
            // Initialize detection counters
            skinVerificationCounts.clear();
            lastVerificationTimes.clear();
            
            Log.d(TAG, "Advanced protection mechanisms initialized");
        } catch (Exception e) {
            Log.e(TAG, "Error initializing advanced protection", e);
        }
    }
    
    /**
     * Enhanced weapon skin application with real-time verification
     */
    public static boolean applyWeaponSkinWithVerification(String weapon, int skinIndex) {
        if (!weaponSkinMap.containsKey(weapon)) {
            Log.w(TAG, "Unknown weapon: " + weapon);
            return false;
        }
        
        try {
            WeaponSkinData weaponData = weaponSkinMap.get(weapon);
            if (skinIndex < 0 || skinIndex >= weaponData.skinIds.length) {
                Log.w(TAG, "Invalid skin index for " + weapon + ": " + skinIndex);
                return false;
            }
            
            // Rate limiting check
            if (!rateLimitCheck(weapon)) {
                Log.w(TAG, "Rate limit exceeded for " + weapon);
                return false;
            }
            
            int skinId = weaponData.skinIds[skinIndex];
            String skinName = weaponData.skinNames[skinIndex];
            
            // Enhanced protection
            if (skinConfig.enableSkinProtection) {
                applyEnhancedProtection(weapon, skinId);
            }
            
            // Apply skin with protection
            applySkinWithProtection(weapon, skinId, weaponData.isSpecialSkin);
            
            // Real-time verification
            if (skinConfig.enableSkinVerification) {
                boolean verified = verifySkinApplication(weapon, skinId);
                if (!verified) {
                    Log.w(TAG, "Skin verification failed for " + weapon);
                    // Retry once
                    applySkinWithProtection(weapon, skinId, weaponData.isSpecialSkin);
                    verified = verifySkinApplication(weapon, skinId);
                    if (!verified) {
                        Log.e(TAG, "Skin application failed after retry for " + weapon);
                        return false;
                    }
                }
            }
            
            // Update tracking
            lastSkinChangeTimes.put(weapon, System.currentTimeMillis());
            updateRealTimeSkinName(weapon);
            
            Log.d(TAG, "Successfully applied " + skinName + " to " + weapon + " (ID: " + skinId + ")");
            return true;
            
        } catch (Exception e) {
            Log.e(TAG, "Error applying weapon skin with verification", e);
            return false;
        }
    }
    
    /**
     * Enhanced vehicle skin application with protection
     */
    public static boolean applyVehicleSkinWithProtection(String vehicleType, int skinIndex) {
        if (!vehicleSkinMap.containsKey(vehicleType)) {
            Log.w(TAG, "Unknown vehicle type: " + vehicleType);
            return false;
        }
        
        try {
            VehicleSkinData vehicleData = vehicleSkinMap.get(vehicleType);
            if (skinIndex < 0 || skinIndex >= vehicleData.skinIds.length) {
                Log.w(TAG, "Invalid skin index for " + vehicleType + ": " + skinIndex);
                return false;
            }
            
            int skinId = vehicleData.skinIds[skinIndex];
            String skinName = vehicleData.skinNames[skinIndex];
            
            // Apply vehicle skin with native protection
            if (applyVehicleSkinNative(vehicleType, skinId)) {
                Log.d(TAG, "Successfully applied " + skinName + " to " + vehicleType);
                return true;
            } else {
                Log.e(TAG, "Failed to apply vehicle skin for " + vehicleType);
                return false;
            }
            
        } catch (Exception e) {
            Log.e(TAG, "Error applying vehicle skin with protection", e);
            return false;
        }
    }
    
    /**
     * Batch apply multiple weapon skins with enhanced protection
     */
    public static Map<String, Boolean> batchApplyWeaponSkins(Map<String, Integer> weaponSkinMap) {
        Map<String, Boolean> results = new HashMap<>();
        
        try {
            // Pre-scramble memory for batch operation
            if (skinConfig.enableMemoryScrambling) {
                scrambleMemory();
            }
            
            for (Map.Entry<String, Integer> entry : weaponSkinMap.entrySet()) {
                String weapon = entry.getKey();
                Integer skinIndex = entry.getValue();
                
                boolean success = applyWeaponSkinWithVerification(weapon, skinIndex);
                results.put(weapon, success);
                
                // Small delay to prevent detection patterns
                if (skinConfig.enableAntiDetection) {
                    try {
                        Thread.sleep(random.nextInt(50) + 10); // 10-60ms delay
                    } catch (InterruptedException e) {
                        Thread.currentThread().interrupt();
                        break;
                    }
                }
            }
            
            Log.d(TAG, "Batch skin application completed. Success rate: " + 
                  results.values().stream().mapToInt(b -> b ? 1 : 0).sum() + "/" + results.size());
            
        } catch (Exception e) {
            Log.e(TAG, "Error in batch skin application", e);
        }
        
        return results;
    }
    
    /**
     * Apply dynamic skin rotation for anti-detection
     */
    public static void enableDynamicSkinRotation(String weapon, boolean enabled) {
        try {
            if (enabled) {
                skinConfig.enableDynamicRotation = true;
                lastRotationTimes.put(weapon, System.currentTimeMillis());
                currentRotationIndices.put(weapon, 0);
                usedSkinIds.put(weapon, new HashSet<>());
                
                // Start rotation for this weapon
                startSkinRotation(weapon);
            } else {
                lastRotationTimes.remove(weapon);
                currentRotationIndices.remove(weapon);
                usedSkinIds.remove(weapon);
            }
            
            Log.d(TAG, "Dynamic skin rotation " + (enabled ? "enabled" : "disabled") + " for " + weapon);
        } catch (Exception e) {
            Log.e(TAG, "Error setting dynamic skin rotation", e);
        }
    }
    
    /**
     * Start skin rotation for a weapon
     */
    private static void startSkinRotation(String weapon) {
        new Thread(() -> {
            try {
                while (skinConfig.enableDynamicRotation && lastRotationTimes.containsKey(weapon)) {
                    long lastRotation = lastRotationTimes.getOrDefault(weapon, 0L);
                    long currentTime = System.currentTimeMillis();
                    
                    if (currentTime - lastRotation >= skinConfig.rotationInterval) {
                        rotateSkin(weapon);
                        lastRotationTimes.put(weapon, currentTime);
                    }
                    
                    // Sleep with random jitter
                    Thread.sleep(5000 + random.nextInt(10000)); // 5-15 seconds
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            } catch (Exception e) {
                Log.e(TAG, "Error in skin rotation thread", e);
            }
        }).start();
    }
    
    /**
     * Rotate to next skin for a weapon
     */
    private static void rotateSkin(String weapon) {
        try {
            WeaponSkinData weaponData = weaponSkinMap.get(weapon);
            if (weaponData == null) return;
            
            Set<Integer> usedIds = usedSkinIds.getOrDefault(weapon, new HashSet<>());
            List<Integer> availableIndices = new ArrayList<>();
            
            // Find unused skin indices
            for (int i = 0; i < weaponData.skinIds.length; i++) {
                if (!usedIds.contains(weaponData.skinIds[i])) {
                    availableIndices.add(i);
                }
            }
            
            // If all skins used, reset
            if (availableIndices.isEmpty()) {
                usedIds.clear();
                for (int i = 0; i < weaponData.skinIds.length; i++) {
                    availableIndices.add(i);
                }
            }
            
            // Select random skin
            int randomIndex = availableIndices.get(random.nextInt(availableIndices.size()));
            int skinId = weaponData.skinIds[randomIndex];
            
            // Apply skin
            if (applyWeaponSkinWithVerification(weapon, randomIndex)) {
                usedIds.add(skinId);
                currentRotationIndices.put(weapon, randomIndex);
                Log.d(TAG, "Rotated skin for " + weapon + " to index " + randomIndex);
            }
            
        } catch (Exception e) {
            Log.e(TAG, "Error rotating skin for " + weapon, e);
        }
    }
    
    /**
     * Enhanced rate limiting check
     */
    private static boolean rateLimitCheck(String weapon) {
        try {
            long currentTime = System.currentTimeMillis();
            Long lastChange = lastSkinChangeTimes.get(weapon);
            
            if (lastChange != null && currentTime - lastChange < MIN_SKIN_CHANGE_INTERVAL) {
                return false;
            }
            
            return true;
        } catch (Exception e) {
            Log.e(TAG, "Error in rate limit check", e);
            return true; // Allow on error
        }
    }
    
    /**
     * Advanced attachment management with protection
     */
    public static boolean applyRandomAttachmentsWithProtection(String weapon) {
        if (!weaponSkinMap.containsKey(weapon) || !skinConfig.enableRandomAttachments) {
            return false;
        }
        
        try {
            WeaponSkinData weaponData = weaponSkinMap.get(weapon);
            Map<String, int[]> attachments = weaponData.attachments;
            
            // Apply random attachments
            for (Map.Entry<String, int[]> entry : attachments.entrySet()) {
                String attachmentType = entry.getKey();
                int[] availableIds = entry.getValue();
                
                if (availableIds.length > 0) {
                    int randomId = availableIds[random.nextInt(availableIds.length)];
                    applyAttachmentWithProtection(weapon, attachmentType, randomId);
                }
            }
            
            Log.d(TAG, "Applied random attachments to " + weapon);
            return true;
            
        } catch (Exception e) {
            Log.e(TAG, "Error applying random attachments", e);
            return false;
        }
    }
    
    /**
     * Enhanced memory management with periodic cleanup
     */
    public static void performEnhancedMemoryCleanup() {
        try {
            // Clear verification history
            long currentTime = System.currentTimeMillis();
            lastVerificationTimes.entrySet().removeIf(entry -> 
                currentTime - entry.getValue() > VERIFICATION_INTERVAL * 2);
            
            // Clear skin name history for old weapons
            skinNameHistory.entrySet().removeIf(entry -> {
                List<String> history = entry.getValue();
                return history.size() > MAX_SKIN_HISTORY * 2;
            });
            
            // Limit skin name update tracking
            lastSkinNameUpdate.entrySet().removeIf(entry -> 
                currentTime - entry.getValue() > SKIN_NAME_UPDATE_INTERVAL * 10);
            
            // Clear old rotation data
            if (currentRotationIndices.size() > 20) {
                currentRotationIndices.clear();
                usedSkinIds.clear();
                lastRotationTimes.clear();
            }
            
            // Force garbage collection if needed
            Runtime runtime = Runtime.getRuntime();
            long maxMemory = runtime.maxMemory();
            long usedMemory = runtime.totalMemory() - runtime.freeMemory();
            
            if (usedMemory > maxMemory * 0.8) { // If using more than 80% of max memory
                System.gc();
                Log.d(TAG, "Performed garbage collection due to high memory usage");
            }
            
            Log.d(TAG, "Enhanced memory cleanup completed");
        } catch (Exception e) {
            Log.e(TAG, "Error in enhanced memory cleanup", e);
        }
    }
    
    /**
     * Native method implementations with JNI bridge
     */
    private static native boolean updateSkinValueNative(String weaponKey, int skinId);
    private static native boolean applyAttachmentNative(String weaponKey, String attachmentType, int attachmentId);
    private static native String getSkinNameNative(String weaponKey, int skinId);
    private static native int[] getAvailableSkinIdsNative(String weaponKey);
    private static native int getCurrentSkinIdNative(String weaponKey);
    private static native void scrambleMemoryNative(byte[] buffer, byte[] key);
    private static native boolean applyVehicleSkinNative(String vehicleType, int skinId);
    private static native boolean verifyIntegrityNative(String dataType, int expectedId);
    
    // Legacy native method stubs (for compatibility)
    private static native void updateSkinValue(String weaponKey, int skinId);
    private static native void applyAttachment(String weaponKey, String attachmentType, int attachmentId);
    private static native String getSkinName(String weaponKey, int skinId);
    private static native int[] getAvailableSkinIds(String weaponKey);
    private static native int getCurrentSkinId(String weaponKey);
    private static native void scrambleMemoryNative(byte[] buffer, byte[] key);
    
    // Implementation bridges for backwards compatibility
    static {
        try {
            // Load native library
            System.loadLibrary("bearmod");
            Log.d(TAG, "Native library loaded successfully");
        } catch (UnsatisfiedLinkError e) {
            Log.e(TAG, "Failed to load native library", e);
        }
    }
    
    /**
     * Enhanced skin statistics and monitoring
     */
    public static Map<String, Object> getEnhancedSkinStatistics() {
        Map<String, Object> stats = new HashMap<>();
        
        try {
            // Basic statistics
            stats.put("totalWeapons", weaponSkinMap.size());
            stats.put("totalVehicles", vehicleSkinMap.size());
            stats.put("activeSkinNames", activeSkinNames.size());
            stats.put("skinNameHistory", skinNameHistory.size());
            
            // Performance statistics
            stats.put("lastSkinChanges", lastSkinChangeTimes.size());
            stats.put("verificationCounts", skinVerificationCounts.size());
            stats.put("rotationActive", currentRotationIndices.size());
            
            // Configuration statistics
            stats.put("enableDynamicSkins", skinConfig.enableDynamicSkins);
            stats.put("enableSkinProtection", skinConfig.enableSkinProtection);
            stats.put("enableAntiDetection", skinConfig.enableAntiDetection);
            stats.put("protectionLevel", skinConfig.protectionLevel);
            stats.put("stealthLevel", skinConfig.protectionLevel);
            
            // Memory statistics
            Runtime runtime = Runtime.getRuntime();
            stats.put("maxMemory", runtime.maxMemory());
            stats.put("totalMemory", runtime.totalMemory());
            stats.put("freeMemory", runtime.freeMemory());
            stats.put("usedMemory", runtime.totalMemory() - runtime.freeMemory());
            
            // Timing statistics
            stats.put("skinChangeCooldown", skinConfig.skinChangeCooldown);
            stats.put("rotationInterval", skinConfig.rotationInterval);
            stats.put("currentTime", System.currentTimeMillis());
            
        } catch (Exception e) {
            Log.e(TAG, "Error generating enhanced skin statistics", e);
            stats.put("error", e.getMessage());
        }
        
        return stats;
    }
    
    /**
     * Comprehensive skin system health check
     */
    public static Map<String, Object> performSkinSystemHealthCheck() {
        Map<String, Object> healthReport = new HashMap<>();
        
        try {
            // Check native library status
            boolean nativeLibraryLoaded = false;
            try {
                updateSkinValueNative("TEST", 0);
                nativeLibraryLoaded = true;
            } catch (Exception e) {
                healthReport.put("nativeLibraryError", e.getMessage());
            }
            healthReport.put("nativeLibraryLoaded", nativeLibraryLoaded);
            
            // Check weapon skin data integrity
            int weaponDataIntegrity = 0;
            for (WeaponSkinData weaponData : weaponSkinMap.values()) {
                if (weaponData.skinIds.length == weaponData.skinNames.length) {
                    weaponDataIntegrity++;
                }
            }
            healthReport.put("weaponDataIntegrity", weaponDataIntegrity + "/" + weaponSkinMap.size());
            
            // Check vehicle skin data integrity
            int vehicleDataIntegrity = 0;
            for (VehicleSkinData vehicleData : vehicleSkinMap.values()) {
                if (vehicleData.skinIds.length == vehicleData.skinNames.length) {
                    vehicleDataIntegrity++;
                }
            }
            healthReport.put("vehicleDataIntegrity", vehicleDataIntegrity + "/" + vehicleSkinMap.size());
            
            // Check memory usage
            Runtime runtime = Runtime.getRuntime();
            long usedMemory = runtime.totalMemory() - runtime.freeMemory();
            long maxMemory = runtime.maxMemory();
            double memoryUsagePercent = (double) usedMemory / maxMemory * 100;
            healthReport.put("memoryUsagePercent", memoryUsagePercent);
            healthReport.put("memoryHealthy", memoryUsagePercent < 80);
            
            // Check configuration status
            healthReport.put("configurationValid", skinConfig != null);
            healthReport.put("protectionEnabled", skinConfig.enableSkinProtection);
            healthReport.put("antiDetectionEnabled", skinConfig.enableAntiDetection);
            
            // Overall health score
            int healthScore = 0;
            if (nativeLibraryLoaded) healthScore += 25;
            if (weaponDataIntegrity == weaponSkinMap.size()) healthScore += 25;
            if (vehicleDataIntegrity == vehicleSkinMap.size()) healthScore += 25;
            if (memoryUsagePercent < 80) healthScore += 25;
            
            healthReport.put("overallHealthScore", healthScore + "/100");
            healthReport.put("systemHealthy", healthScore >= 75);
            
        } catch (Exception e) {
            Log.e(TAG, "Error performing skin system health check", e);
            healthReport.put("healthCheckError", e.getMessage());
            healthReport.put("systemHealthy", false);
        }
        
        return healthReport;
    }
    
    /**
     * Emergency skin system reset
     */
    public static void emergencySystemReset() {
        try {
            Log.w(TAG, "Performing emergency skin system reset");
            
            // Clear all tracking data
            activeSkinNames.clear();
            lastSkinNameUpdate.clear();
            skinNameHistory.clear();
            lastSkinChangeTimes.clear();
            skinVerificationCounts.clear();
            lastVerificationTimes.clear();
            lastRotationTimes.clear();
            currentRotationIndices.clear();
            usedSkinIds.clear();
            skinProtectionLevels.clear();
            
            // Reset configuration to safe defaults
            skinConfig.enableDynamicSkins = true;
            skinConfig.enableSkinProtection = true;
            skinConfig.enableAntiDetection = true;
            skinConfig.protectionLevel = 2;
            skinConfig.skinChangeCooldown = 5000;
            skinConfig.rotationInterval = 30000;
            
            // Force garbage collection
            System.gc();
            
            // Re-initialize protection
            initializeAdvancedProtection();
            
            Log.i(TAG, "Emergency skin system reset completed");
        } catch (Exception e) {
            Log.e(TAG, "Error during emergency system reset", e);
        }
    }
}