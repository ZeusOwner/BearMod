#pragma once

// SDKGen by @xninjaleaks | @talhaeens 
// Send message for SDKGen and Offset Finder Tool

namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// Class EngineSettings.ConsoleSettings
// 0x0048 (0x0070 - 0x0028)
class UConsoleSettings : public UObject
{
public:
	int                                                MaxScrollbackSize;                                        // 0x0028(0x0004) (Edit, ZeroConstructor, Config, GlobalConfig, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x002C(0x0004) MISSED OFFSET
	TArray<struct FAutoCompleteCommand>                ManualAutoCompleteList;                                   // 0x0030(0x0010) (Edit, ZeroConstructor, Config)
	TArray<struct FString>                             AutoCompleteMapPaths;                                     // 0x0040(0x0010) (Edit, ZeroConstructor, Config)
	float                                              BackgroundOpacityPercentage;                              // 0x0050(0x0004) (Edit, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bOrderTopToBottom;                                        // 0x0054(0x0001) (Edit, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0055(0x0003) MISSED OFFSET
	struct FColor                                      InputColor;                                               // 0x0058(0x0004) (Edit, Config, IsPlainOldData)
	struct FColor                                      HistoryColor;                                             // 0x005C(0x0004) (Edit, Config, IsPlainOldData)
	struct FColor                                      AutoCompleteCommandColor;                                 // 0x0060(0x0004) (Edit, Config, IsPlainOldData)
	struct FColor                                      AutoCompleteCVarColor;                                    // 0x0064(0x0004) (Edit, Config, IsPlainOldData)
	struct FColor                                      AutoCompleteFadedColor;                                   // 0x0068(0x0004) (Edit, Config, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x006C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class EngineSettings.ConsoleSettings");
		return pStaticClass;
	}

};


// Class EngineSettings.GameMapsSettings
// 0x00E0 (0x0108 - 0x0028)
class UGameMapsSettings : public UObject
{
public:
	struct FSoftObjectPath                             EditorStartupMap;                                         // 0x0028(0x0018) (Edit, Config)
	struct FString                                     LocalMapOptions;                                          // 0x0040(0x0010) (Edit, ZeroConstructor, Config)
	struct FSoftObjectPath                             TransitionMap;                                            // 0x0050(0x0018) (Edit, Config)
	bool                                               bUseSplitscreen;                                          // 0x0068(0x0001) (Edit, ZeroConstructor, Config, IsPlainOldData)
	TEnumAsByte<ETwoPlayerSplitScreenType>             TwoPlayerSplitscreenLayout;                               // 0x0069(0x0001) (Edit, ZeroConstructor, Config, IsPlainOldData)
	TEnumAsByte<EThreePlayerSplitScreenType>           ThreePlayerSplitscreenLayout;                             // 0x006A(0x0001) (Edit, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bOffsetPlayerGamepadIds;                                  // 0x006B(0x0001) (Edit, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x006C(0x0004) MISSED OFFSET
	struct FSoftClassPath                              GameInstanceClass;                                        // 0x0070(0x0018) (Edit, Config, NoClear)
	struct FSoftObjectPath                             GameDefaultMap;                                           // 0x0088(0x0018) (Edit, Config)
	struct FSoftObjectPath                             ServerDefaultMap;                                         // 0x00A0(0x0018) (Edit, Config)
	struct FSoftClassPath                              GlobalDefaultGameMode;                                    // 0x00B8(0x0018) (Edit, Config, NoClear)
	struct FSoftClassPath                              GlobalDefaultServerGameMode;                              // 0x00D0(0x0018) (Edit, Config)
	TArray<struct FGameModeName>                       GameModeMapPrefixes;                                      // 0x00E8(0x0010) (Edit, ZeroConstructor, Config)
	TArray<struct FGameModeName>                       GameModeClassAliases;                                     // 0x00F8(0x0010) (Edit, ZeroConstructor, Config)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class EngineSettings.GameMapsSettings");
		return pStaticClass;
	}

};


// Class EngineSettings.GameNetworkManagerSettings
// 0x0030 (0x0058 - 0x0028)
class UGameNetworkManagerSettings : public UObject
{
public:
	int                                                MinDynamicBandwidth;                                      // 0x0028(0x0004) (Edit, ZeroConstructor, Config, GlobalConfig, IsPlainOldData)
	int                                                MaxDynamicBandwidth;                                      // 0x002C(0x0004) (Edit, ZeroConstructor, Config, GlobalConfig, IsPlainOldData)
	int                                                TotalNetBandwidth;                                        // 0x0030(0x0004) (Edit, ZeroConstructor, Config, GlobalConfig, IsPlainOldData)
	int                                                BadPingThreshold;                                         // 0x0034(0x0004) (Edit, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      bIsStandbyCheckingEnabled : 1;                            // 0x0038(0x0001) (Edit, Config)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0039(0x0003) MISSED OFFSET
	float                                              StandbyRxCheatTime;                                       // 0x003C(0x0004) (Edit, ZeroConstructor, Config, IsPlainOldData)
	float                                              StandbyTxCheatTime;                                       // 0x0040(0x0004) (Edit, ZeroConstructor, Config, IsPlainOldData)
	float                                              PercentMissingForRxStandby;                               // 0x0044(0x0004) (Edit, ZeroConstructor, Config, IsPlainOldData)
	float                                              PercentMissingForTxStandby;                               // 0x0048(0x0004) (Edit, ZeroConstructor, Config, IsPlainOldData)
	float                                              PercentForBadPing;                                        // 0x004C(0x0004) (Edit, ZeroConstructor, Config, IsPlainOldData)
	float                                              JoinInProgressStandbyWaitTime;                            // 0x0050(0x0004) (Edit, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0054(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class EngineSettings.GameNetworkManagerSettings");
		return pStaticClass;
	}

};


// Class EngineSettings.GameSessionSettings
// 0x0010 (0x0038 - 0x0028)
class UGameSessionSettings : public UObject
{
public:
	int                                                MaxSpectators;                                            // 0x0028(0x0004) (Edit, ZeroConstructor, Config, GlobalConfig, IsPlainOldData)
	int                                                MaxPlayers;                                               // 0x002C(0x0004) (Edit, ZeroConstructor, Config, GlobalConfig, IsPlainOldData)
	unsigned char                                      bRequiresPushToTalk : 1;                                  // 0x0030(0x0001) (Edit, Config, GlobalConfig)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0031(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class EngineSettings.GameSessionSettings");
		return pStaticClass;
	}

};


// Class EngineSettings.GeneralEngineSettings
// 0x0000 (0x0028 - 0x0028)
class UGeneralEngineSettings : public UObject
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class EngineSettings.GeneralEngineSettings");
		return pStaticClass;
	}

};


// Class EngineSettings.GeneralProjectSettings
// 0x00F8 (0x0120 - 0x0028)
class UGeneralProjectSettings : public UObject
{
public:
	struct FString                                     CompanyName;                                              // 0x0028(0x0010) (Edit, ZeroConstructor, Config)
	struct FString                                     CompanyDistinguishedName;                                 // 0x0038(0x0010) (Edit, ZeroConstructor, Config)
	struct FString                                     CopyrightNotice;                                          // 0x0048(0x0010) (Edit, ZeroConstructor, Config)
	struct FString                                     Description;                                              // 0x0058(0x0010) (Edit, ZeroConstructor, Config)
	struct FString                                     Homepage;                                                 // 0x0068(0x0010) (Edit, ZeroConstructor, Config)
	struct FString                                     LicensingTerms;                                           // 0x0078(0x0010) (Edit, ZeroConstructor, Config)
	struct FString                                     PrivacyPolicy;                                            // 0x0088(0x0010) (Edit, ZeroConstructor, Config)
	struct FGuid                                       ProjectID;                                                // 0x0098(0x0010) (Edit, Config, IsPlainOldData)
	struct FString                                     ProjectName;                                              // 0x00A8(0x0010) (Edit, ZeroConstructor, Config)
	struct FString                                     ProjectVersion;                                           // 0x00B8(0x0010) (Edit, ZeroConstructor, Config)
	struct FString                                     ProjectBranch;                                            // 0x00C8(0x0010) (Edit, ZeroConstructor, Config)
	struct FString                                     SupportContact;                                           // 0x00D8(0x0010) (Edit, ZeroConstructor, Config)
	struct FText                                       ProjectDisplayedTitle;                                    // 0x00E8(0x0018) (Edit, Config)
	struct FText                                       ProjectDebugTitleInfo;                                    // 0x0100(0x0018) (Edit, Config)
	bool                                               bShouldWindowPreserveAspectRatio;                         // 0x0118(0x0001) (Edit, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bUseBorderlessWindow;                                     // 0x0119(0x0001) (Edit, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bStartInVR;                                               // 0x011A(0x0001) (Edit, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bStartInAR;                                               // 0x011B(0x0001) (Edit, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bAllowWindowResize;                                       // 0x011C(0x0001) (Edit, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bAllowClose;                                              // 0x011D(0x0001) (Edit, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bAllowMaximize;                                           // 0x011E(0x0001) (Edit, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bAllowMinimize;                                           // 0x011F(0x0001) (Edit, ZeroConstructor, Config, IsPlainOldData)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class EngineSettings.GeneralProjectSettings");
		return pStaticClass;
	}

};


// Class EngineSettings.HudSettings
// 0x0018 (0x0040 - 0x0028)
class UHudSettings : public UObject
{
public:
	unsigned char                                      bShowHUD : 1;                                             // 0x0028(0x0001) (Edit, Config)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0029(0x0007) MISSED OFFSET
	TArray<struct FName>                               DebugDisplay;                                             // 0x0030(0x0010) (Edit, ZeroConstructor, Config, GlobalConfig)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class EngineSettings.HudSettings");
		return pStaticClass;
	}

};


}

