#pragma once

// SDKGen by @xninjaleaks | @talhaeens 
// Send message for SDKGen and Offset Finder Tool

namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// Class Creative.CameraDeviceSpringArmComponent
// 0x0010 (0x0C30 - 0x0C20)
class UCameraDeviceSpringArmComponent : public UCustomSpringArmComponent
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0C20(0x0008) MISSED OFFSET
	float                                              DebugAngle;                                               // 0x0C28(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0C2C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CameraDeviceSpringArmComponent");
		return pStaticClass;
	}

};


// Class Creative.CreativeAbilitySystemComponent
// 0x0158 (0x1310 - 0x11B8)
class UCreativeAbilitySystemComponent : public USAbilitySystemComponent
{
public:
	class ASTExtraPlayerController*                    PlayerController;                                         // 0x11B8(0x0008) (ZeroConstructor, IsPlainOldData)
	class ASTExtraPlayerCharacter*                     PlayerCharacter;                                          // 0x11C0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x11C8(0x0008) MISSED OFFSET
	struct FTransform                                  GhostBuildingTransform;                                   // 0x11D0(0x0030) (IsPlainOldData)
	TArray<class AActor*>                              GetLocationActorsToIgnore;                                // 0x1200(0x0010) (ZeroConstructor)
	float                                              LandOnOffsetZ;                                            // 0x1210(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              LandHitPointZ;                                            // 0x1214(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              LandHitDeltaZ;                                            // 0x1218(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              WaterHeight;                                              // 0x121C(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bForceLandOnGround;                                       // 0x1220(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x1221(0x0003) MISSED OFFSET
	int                                                LandGroundType;                                           // 0x1224(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bUseLandOnOffsetZ;                                        // 0x1228(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bSnapTransValid;                                          // 0x1229(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bSnapGridEnable;                                          // 0x122A(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x5];                                       // 0x122B(0x0005) MISSED OFFSET
	class AActor*                                      SnapGrid;                                                 // 0x1230(0x0008) (ZeroConstructor, IsPlainOldData)
	bool                                               bIgnoreLandOn;                                            // 0x1238(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bIgnoreWaterHeightCheck;                                  // 0x1239(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bIgnoreCameraRotate;                                      // 0x123A(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x1];                                       // 0x123B(0x0001) MISSED OFFSET
	struct FRotator                                    ModifiedRotation;                                         // 0x123C(0x000C) (IsPlainOldData)
	struct FVector                                     ModifiedScale;                                            // 0x1248(0x000C) (IsPlainOldData)
	struct FRotator                                    RelativeRotation;                                         // 0x1254(0x000C) (IsPlainOldData)
	struct FVector                                     RelativeLocation;                                         // 0x1260(0x000C) (IsPlainOldData)
	struct FVector                                     RelativeScale;                                            // 0x126C(0x000C) (IsPlainOldData)
	unsigned char                                      UnknownData04[0x8];                                       // 0x1278(0x0008) MISSED OFFSET
	struct FTransform                                  SnapBaseTransform;                                        // 0x1280(0x0030) (IsPlainOldData)
	struct FVector                                     DeviceLocationOffset;                                     // 0x12B0(0x000C) (IsPlainOldData)
	struct FVector                                     InstanceBoxCenter;                                        // 0x12BC(0x000C) (IsPlainOldData)
	struct FVector                                     InstanceBoxExtent;                                        // 0x12C8(0x000C) (IsPlainOldData)
	bool                                               bSpecificPlaceStartEnd;                                   // 0x12D4(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x3];                                       // 0x12D5(0x0003) MISSED OFFSET
	struct FVector                                     PlaceRayStart;                                            // 0x12D8(0x000C) (IsPlainOldData)
	struct FVector                                     PlaceRayEnd;                                              // 0x12E4(0x000C) (IsPlainOldData)
	bool                                               bNeedGetBuildDistance;                                    // 0x12F0(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bOpenLandPosCheckDebug;                                   // 0x12F1(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x2];                                       // 0x12F2(0x0002) MISSED OFFSET
	struct FVector                                     OverridePos;                                              // 0x12F4(0x000C) (IsPlainOldData)
	struct FRotator                                    OverrideRot;                                              // 0x1300(0x000C) (IsPlainOldData)
	bool                                               bOverrideBuild;                                           // 0x130C(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData07[0x3];                                       // 0x130D(0x0003) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeAbilitySystemComponent");
		return pStaticClass;
	}


	void UpdateGridGhostBuildingLocation(float X, float Y, float Z);
	void UpdateGhostBuildingTransform();
	void SetSnapTargetTransform(const struct FTransform& SnapTargetTransform);
	void SetOverrideBuild(const struct FVector& Position, const struct FRotator& Rotation);
	void SetLuaGhostBuildingTransformScale(float X, float Y, float Z);
	void SetLuaGhostBuildingTransformRotation(float Roll, float Yaw, float Pitch);
	void SetLuaGhostBuildingTransformLocation(float X, float Y, float Z);
	void LuaGhostBuildingInstaUpdate();
	float GetSnappedLocAxisZ(float Loc, float Base);
	float GetSnappedLocAxis(float Value, int AxisType);
	int GetSetupBuildingID();
	class ASTExtraPlayerController* GetPlayerController();
	bool GetLuaSnapTargetTransform();
	float GetLuaInstanceBoundingBox();
	struct FTransform GetGhostBuildingTransform();
	struct FString GetBuildingInstanceID();
	float GetBuildDistance();
	void ClearOverrideBuild();
};


// Class Creative.CreativeModeActorInteractionComponent
// 0x0088 (0x0260 - 0x01D8)
class UCreativeModeActorInteractionComponent : public ULuaActorComponent
{
public:
	struct FString                                     HitComponentName;                                         // 0x01D8(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	bool                                               bSectorCheckEnabled;                                      // 0x01E8(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x01E9(0x0003) MISSED OFFSET
	float                                              SectorCheckCD;                                            // 0x01EC(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bTransformCrossHairCheckEnabled;                          // 0x01F0(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x01F1(0x0003) MISSED OFFSET
	float                                              TransformCrossHairCheckCD;                                // 0x01F4(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bPickCrossHairCheckEnabled;                               // 0x01F8(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x01F9(0x0003) MISSED OFFSET
	float                                              PickCrossHairCheckCD;                                     // 0x01FC(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x10];                                      // 0x0200(0x0010) MISSED OFFSET
	class APawn*                                       PlayerCharacter;                                          // 0x0210(0x0008) (ZeroConstructor, IsPlainOldData)
	class ASTExtraPlayerController*                    PlayerController;                                         // 0x0218(0x0008) (ZeroConstructor, IsPlainOldData)
	TArray<class AActor*>                              CrossHairCheckIgnoreActorArray;                           // 0x0220(0x0010) (ZeroConstructor)
	TArray<class AActor*>                              uTransformCrossHairCheckIgnoreActorArray;                 // 0x0230(0x0010) (ZeroConstructor)
	TArray<class AActor*>                              PickCrossHairCheckIgnoreActorArray;                       // 0x0240(0x0010) (ZeroConstructor)
	TArray<class UClass*>                              PickActorClassArray;                                      // 0x0250(0x0010) (ZeroConstructor)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeActorInteractionComponent");
		return pStaticClass;
	}


	void SortCanEditParamsObjs();
	void SetCrossHairTransformObjInstanceID(const struct FString& InstanceID);
	void SetCrossHairSelectedObjInstanceID(const struct FString& InstanceID);
	void SetCrossHairPickActor(class AActor* PickActor);
	float GetSectorCheckIntervalCfg();
	float GetSectorCheckDistance();
	float GetSectorCheckAngle();
	float GetPlayerHalfHeight();
	class ASTExtraPlayerController* GetPlayerController();
	float GetCrossHairTransformDistanceCfg();
	float GetCrossHairPickDistanceCfg();
	float GetCrossHairCheckIntervalCfg();
	float GetCrossHairCheckDistanceCfg();
	void ClearCanEditParamsObjs();
	void AddCanEditObject(class UObject* uCanEditObject, float Angle, float Distance);
};


// Class Creative.CreativeModeManagerBase
// 0x0000 (0x0108 - 0x0108)
class UCreativeModeManagerBase : public USTExtraManagerBase
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeManagerBase");
		return pStaticClass;
	}

};


// Class Creative.CreativeAdaptiveSchedulManager
// 0x0108 (0x0210 - 0x0108)
class UCreativeAdaptiveSchedulManager : public UCreativeModeManagerBase
{
public:
	bool                                               bOpenLuaProfile;                                          // 0x0108(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bOpenProfile;                                             // 0x0109(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bOpenFuncCPUProfile;                                      // 0x010A(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x5D];                                      // 0x010B(0x005D) MISSED OFFSET
	TMap<struct FString, int>                          ProjectTagMap;                                            // 0x0168(0x0050) (BlueprintVisible, ZeroConstructor)
	TMap<struct FString, int>                          LuaPathTagMap;                                            // 0x01B8(0x0050) (BlueprintVisible, ZeroConstructor)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0208(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeAdaptiveSchedulManager");
		return pStaticClass;
	}


	void SetObjectProfile(bool bOpen);
	void SetLuaProfile(bool bOpen);
	int RecordFunctionStart(const struct FString& ClassName, const struct FString& FunctionName);
	void RecordFunctionEnd(const struct FString& ClassName, const struct FString& FunctionName, int Cycles);
	int LuaPath2Tag(const struct FString& luaPath, const struct FString& FunctionName);
	void LogOutputObjectMemoryInfo(bool bClear);
	void LogOutputLuaFunctionCallInfo(bool bClear);
	TMap<int, int64_t> LogoutLuaRecord();
	static bool LLMEnabled();
	int InitTagIfNotExist(const struct FString& TagName);
	int InitNewLuaPath2Tag(const struct FString& luaPath, const struct FString& FunctionName);
	static uint64_t GetPureLuaUsedBytes();
	static uint64_t GetLuaUsedBytes();
	static class UCreativeAdaptiveSchedulManager* Get(class UObject* WorldContext);
	void AfterDead(int SpecType);
};


// Class Creative.CreativeLuaSignalObjectBase
// 0x00C8 (0x00F0 - 0x0028)
class UCreativeLuaSignalObjectBase : public UObject
{
public:
	unsigned char                                      UnknownData00[0x58];                                      // 0x0028(0x0058) MISSED OFFSET
	struct FString                                     LuaFilePath;                                              // 0x0080(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0090(0x0008) MISSED OFFSET
	class UGameLuaAPI*                                 GameLuaAPI;                                               // 0x0098(0x0008) (ZeroConstructor, IsPlainOldData)
	TMap<int, struct FCreativeSignalEventInfo>         SignalEventInfoMap;                                       // 0x00A0(0x0050) (ZeroConstructor)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeLuaSignalObjectBase");
		return pStaticClass;
	}


	void TryBeginPlay();
	void SetLuaFilePath(const struct FString& FilePath);
	void RemoveCommonEvent(int EventHandle);
	void ReceivePostBeginPlay();
	void ReceiveBeginPlay();
	void ClearAllCommonEvent();
	void AddCommonEvent(const struct FString& EventType, const struct FString& EventID, const struct FString& FunctionName);
};


// Class Creative.CreativeApiObject
// 0x0098 (0x0188 - 0x00F0)
class UCreativeApiObject : public UCreativeLuaSignalObjectBase
{
public:
	unsigned char                                      UnknownData00[0x50];                                      // 0x00F0(0x0050) MISSED OFFSET
	struct FString                                     ModuleName;                                               // 0x0140(0x0010) (BlueprintVisible, ZeroConstructor)
	TArray<struct FString>                             CrossVMAPIs;                                              // 0x0150(0x0010) (ZeroConstructor)
	TArray<struct FString>                             UGCVMAPIs;                                                // 0x0160(0x0010) (ZeroConstructor)
	struct FString                                     UGCVMAPILuaFilePath;                                      // 0x0170(0x0010) (ZeroConstructor)
	bool                                               bEnableRegisterCClosureApi;                               // 0x0180(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0181(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeApiObject");
		return pStaticClass;
	}


	void SetModuleName(const struct FString& NewName);
	struct FString GetModuleName();
};


// Class Creative.CreativeAssetManager
// 0x00C8 (0x01D0 - 0x0108)
class UCreativeAssetManager : public UCreativeModeManagerBase
{
public:
	unsigned char                                      UnknownData00[0xC8];                                      // 0x0108(0x00C8) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeAssetManager");
		return pStaticClass;
	}


	void ReceiveOnGameStateBeginPlay(class AGameStateBase* GameState);
	void ReceiveInitAssetInfo(int AssetId);
	void OnGameStateBeginPlay(class AGameStateBase* GameState);
	struct FString GetObbyMeshPath(int AssetId);
	struct FString GetMaterialPath(int MaterialID);
	static class UCreativeAssetManager* Get(class UObject* WorldContext);
	void AddAssetInfo(int AssetId, const struct FCreativeAssetInfo& AssetInfo);
};


// Class Creative.CreativeAudioApiObject
// 0x0000 (0x0188 - 0x0188)
class UCreativeAudioApiObject : public UCreativeApiObject
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeAudioApiObject");
		return pStaticClass;
	}

};


// Class Creative.CreativeAutoGenComponent
// 0x0000 (0x01D8 - 0x01D8)
class UCreativeAutoGenComponent : public ULuaActorComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeAutoGenComponent");
		return pStaticClass;
	}


	TArray<unsigned char> GetNodeSegmentContent(struct FCreativeAutoGenItemDataSegment* Segment);
	bool AddInstanceDataContent(TArray<unsigned char> Content, struct FCreativeAutoGenDataSegment* Segment);
};


// Class Creative.CreativeModeBackpackUtils
// 0x0000 (0x0028 - 0x0028)
class UCreativeModeBackpackUtils : public UBackpackUtilsClassical
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeBackpackUtils");
		return pStaticClass;
	}


	static int ResCanAddToBackpackNum(class UBackpackComponent* BackpackComponent, int resID, int AddNum);
	static int GetItemMaxCount(class UBackpackComponent* BackpackComponent, int resID);
	static void AddAIAvatarItem(class UBackpackComponent* BackpackComponent, int ID, int Color, int Pattern, int Num);
};


// Class Creative.CreativeBaseWidget
// 0x0000 (0x02C8 - 0x02C8)
class UCreativeBaseWidget : public ULuaUserWidget
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeBaseWidget");
		return pStaticClass;
	}

};


// Class Creative.CreativeBinaryDataManager
// 0x0020 (0x0128 - 0x0108)
class UCreativeBinaryDataManager : public USTExtraManagerBase
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x0108(0x0018) MISSED OFFSET
	uint32_t                                           InitBinaryDataSize;                                       // 0x0120(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0124(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeBinaryDataManager");
		return pStaticClass;
	}


	void SetInitBinaryDataSize(uint32_t DataSize);
	void ReceiveOnPreLoadMap(const struct FString& MapName);
	void ReceiveOnPostSetLuaEventBridgeInstance();
	void ReceiveOnPostLoadMapWithWorld(class UWorld* World);
	void OnRep_InitBinaryDataSize();
	void OnPreLoadMap(const struct FString& MapName);
	void OnPostSetLuaEventBridgeInstance();
	void OnPostLoadMapWithWorld(class UWorld* World);
	uint32_t GetInitBinaryDataSize();
	static class UCreativeBinaryDataManager* Get(class UObject* WorldContext);
};


// Class Creative.CreativeBlockyLuaManager
// 0x01F8 (0x0300 - 0x0108)
class UCreativeBlockyLuaManager : public UCreativeModeManagerBase
{
public:
	TMap<struct FString, struct FString>               BindStubFuncMap;                                          // 0x0108(0x0050) (ZeroConstructor)
	unsigned char                                      UnknownData00[0x1];                                       // 0x0158(0x0001) MISSED OFFSET
	bool                                               bConfigInited;                                            // 0x0159(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bDynamicConfigInited;                                     // 0x015A(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x5];                                       // 0x015B(0x0005) MISSED OFFSET
	TArray<class UPresetDesc*>                         DynamicAddPresetDescList;                                 // 0x0160(0x0010) (ZeroConstructor)
	TArray<class UPresetDesc*>                         CachePresetDescList;                                      // 0x0170(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData02[0x50];                                      // 0x0180(0x0050) MISSED OFFSET
	TArray<class UPresetDesc*>                         BatchRemovePresetDescList;                                // 0x01D0(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData03[0x50];                                      // 0x01E0(0x0050) MISSED OFFSET
	struct FString                                     AllTypesJsonPath;                                         // 0x0230(0x0010) (ZeroConstructor)
	struct FString                                     FunctionJsonPath;                                         // 0x0240(0x0010) (ZeroConstructor)
	struct FString                                     FunctionFolderPath;                                       // 0x0250(0x0010) (ZeroConstructor)
	struct FString                                     VariableJsonPath;                                         // 0x0260(0x0010) (ZeroConstructor)
	struct FString                                     PresetsJsonPath;                                          // 0x0270(0x0010) (ZeroConstructor)
	struct FString                                     PresetsFolderPath;                                        // 0x0280(0x0010) (ZeroConstructor)
	struct FString                                     TextrueRectParamJsonPath;                                 // 0x0290(0x0010) (ZeroConstructor)
	struct FString                                     ProjectTextrueRectParamJsonPath;                          // 0x02A0(0x0010) (ZeroConstructor)
	struct FString                                     ProjectAtlasRectParamJsonPath;                            // 0x02B0(0x0010) (ZeroConstructor)
	struct FString                                     TipsJsonPath;                                             // 0x02C0(0x0010) (ZeroConstructor)
	struct FString                                     SequenceJsonPath;                                         // 0x02D0(0x0010) (ZeroConstructor)
	struct FString                                     UAssetConfigDataPath;                                     // 0x02E0(0x0010) (ZeroConstructor)
	bool                                               ClearCacheCallBeginDestroy;                               // 0x02F0(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x7];                                       // 0x02F1(0x0007) MISSED OFFSET
	class UBlockyGraphData*                            GraphDataObject;                                          // 0x02F8(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeBlockyLuaManager");
		return pStaticClass;
	}


	void SetRTLOffsetY(float Offset);
	void SetLTROffsetY(float Offset);
	void SetFontSize(int FontSize);
	void SetBlockIdFromSlotString(const struct FString& BlockID, struct FBlockySlotString* SlotString);
	void ReturnPresetDescsToCache(TArray<class UPresetDesc*> ReturnDescs);
	void RemoveDynamicPresetDescs(TArray<class UPresetDesc*> PresetDescs);
	void RegisterNameCache(class UBlockyGraphData* GraphData);
	void RefreshBlockyFont(struct FSlateFontInfo* DefaultFont);
	void ReceivePresetFromCustomSelection(class UObjectDesc* Desc);
	void ReceiveOpenGuide();
	void ReceiveOnGameStateBeginPlay(class AGameStateBase* GameState);
	struct FString ReceivedGetLocalizeResStrHandleFailed(const struct FString& IdOrStr);
	void ReceiveCheckStringValidFunction(const struct FString& CheckString, const struct FCheckStringHandleData& Data);
	void ReceiveCheckStringResult(bool Result, const struct FString& ValidString, const struct FCheckStringHandleData& Data);
	void OnReceiveMessageData(TArray<struct FMessageDataWrapper> MessageDatas);
	void OnReceiveInitDisableFunc();
	void OnInitBlockyLuaConfig();
	void OnGameTypePreChanged(unsigned char LastGameType, unsigned char CurrentGameType);
	void OnGameStateBeginPlay(class AGameStateBase* GameState);
	bool IsLTRLanguage();
	bool IsLTR();
	void InitDisableFunction(TArray<struct FString> funcs);
	TArray<class UPresetDesc*> GetPresetDescs(int GetCount, struct FString* TypeName);
	class UPresetDesc* GetPresetDesc(struct FString* TypeName);
	class UBlockyGraphData* GetGraphDataObjectFormContent(TArray<unsigned char> GrapbAstContent, TArray<unsigned char> GlobalVarAstContent, bool CallLoadFinish);
	class UPresetDesc* GetDynamicPresetDescsByKey(const struct FString& KeyName);
	class UBlockyLuaConfig* GetBlockyLuaConfig();
	struct FString GetBlockNameByStr(const struct FString& BlockyId);
	struct FString GetBlockIdFromSlotString(struct FBlockySlotString* SlotString);
	static class UCreativeBlockyLuaManager* Get(class UObject* WorldContext);
	TArray<struct FString> GenerateLuaCodeFormJson(const struct FString& JsonText, const struct FString& GlobalVarJsonText, bool GenGlobalVarLua);
	TArray<struct FString> GenerateLuaCodeFormContent(TArray<unsigned char> GrapbAstContent, TArray<unsigned char> GlobalVarAstContent, bool GenGlobalVarLua, bool CallLoadFinish);
	void ClearNameIndexCache();
	TArray<class UPresetDesc*> ClearDynamicPresetDescs();
	void ClearCacheObjects(bool CallBeginDestroy);
	void ClearBlockyLuaHotfixUtility();
	void BlockyluaPresetSoundFunctionHandle(const struct FString& SoundPath);
	struct FText BlockyluaModifyTipHandle(const struct FText& OriginalTip);
	void BlockyluaMessageDataHandle(TArray<struct FMessageDataStruct> MessageDatas);
	struct FString BlockyluaGetLocalizeResStrHandle(const struct FString& IdOrStr);
	void BlockyluaCustomInputHandle(const struct FString& CustomClickType, class UObjectDesc* Desc, TArray<class UObjectDesc*> followers);
	bool BlockyluaCheckShowPresetFitlerBtnHandle(const struct FString& TypeName);
	bool BlockyluaCheckShowCustomInputHandle(const struct FString& CustomClickType, class UObjectDesc* Desc, TArray<class UObjectDesc*> followers);
	void BindBlockyLuaStubFunc(const struct FString& BindFuncName, const struct FString& OverrdeFuncName);
	void AddDynamicPresetDescs(TArray<class UPresetDesc*> PresetDescs);
};


// Class Creative.CreativeModeBlueprintLibrary
// 0x0000 (0x0028 - 0x0028)
class UCreativeModeBlueprintLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeBlueprintLibrary");
		return pStaticClass;
	}


	static bool ZSTDDecompressData(TArray<unsigned char> CompressedData, TArray<unsigned char>* DecompressedData);
	static bool ZSTDCompressData(TArray<unsigned char> UncompressedData, int CompressionLevel, TArray<unsigned char>* CompressedData);
	static struct FVector2D WidgetAbsoluteSizeToLocalSize(class UWidget* Widget, const struct FVector2D& AbsoluteSize);
	static void UObjSnapshot(class UWorld* MyWorld);
	static struct FTransform TransformRevert(const struct FTransform& TransformB, struct FTransform* TransformRelative);
	static void TransformMultiplyBy(const struct FTransform& M, struct FTransform* Source);
	static void TransformBounds(const struct FTransform& M, struct FBoxSphereBounds* Bounds);
	static double ToMilliseconds64(uint64_t Cycles);
	struct FString TakeSnapshot(class UWidget* WindowWidget, int X1, int Y1, int x2, int y2, const struct FString& Filename, bool bUseCrop, bool bFillRect);
	static bool SynchronizePropertiesWidget(class UWidget* TargetWidget);
	static bool ShouldCreatePhysicsState(class UPrimitiveComponent* Component);
	static float SetWorldGravityZ(float GravityZ, class UObject* WorldContext);
	static void SetWidgetVisiblePass(class UWidget* Widget, bool bVisiblePass);
	static void SetStaticMeshMobility(class UStaticMeshComponent* StaticMeshComponent, TEnumAsByte<EComponentMobility> NewMobility);
	static void SetSpeedOverLimit(class AActor* Actor);
	static void SetRelativeCamRotation(class APlayerController* PlayerController, class USceneComponent* Component);
	static void SetParticleCullingDistance(class UParticleSystemComponent* ParticleSystemComponent, float Distance);
	static void SetInstanceValue(class UObject* WorldContextObject, const struct FString& InstanceID, const struct FString& Key, const struct FString& Value);
	static void SetCommandLineValue(const struct FString& Key, const struct FString& NewValue);
	static void SetCollisionMobility(class UShapeComponent* Component, TEnumAsByte<EComponentMobility> NewMobility);
	static void SaveStringToFile(const struct FString& String, const struct FString& Filename);
	static void SaveAssetStringToFile(const struct FString& String, const struct FString& Filename);
	struct FRotator RotatorCrossInverse(const struct FRotator& Rot1, const struct FRotator& Rot2);
	struct FRotator RotatorCross(const struct FRotator& Rot1, const struct FRotator& Rot2);
	static struct FVector Rotation2Vector(const struct FRotator& Rotator, int Axis);
	void RenameObject(class UObject* Object, const struct FString& NewName);
	static void RecreatePhysicsState(class UPrimitiveComponent* Component);
	struct FQuat QuatCrossInverse(const struct FQuat& Quat1, const struct FQuat& Quat2);
	static struct FQuat QuatCross(const struct FQuat& Quat1, const struct FQuat& Quat2);
	static struct FString ProjectSavedDir();
	static struct FString ProjectContentDir();
	static void PopulateParticleProperties(class UParticleSystemComponent* ParticleSystemComponent);
	static void MinAreaRectangle(class UObject* WorldContextObject, TArray<struct FVector> InPoints, const struct FVector& SampleSurfaceNormal, bool bDebugDraw, struct FRotator* OutRectRotation, float* OutRectLengthX, float* OutRectLengthY, struct FVector* OutRectCenter, TArray<int>* PolyVertIndices);
	static struct FString MD5HashByteArray(TArray<unsigned char> inArray);
	static struct FString MD5HashAnsiString(const struct FString& str);
	static bool Lz4DecompressData(TArray<unsigned char> CompressedData, TArray<unsigned char>* DecompressedData);
	static bool Lz4CompressData(TArray<unsigned char> UncompressedData, TArray<unsigned char>* CompressedData);
	static struct FString LoadFileToStringByFullPath(const struct FString& FullPathName);
	static TArray<unsigned char> LoadFileToArrayByFullPath(const struct FString& FullPathName);
	static struct FString LoadAssetFileToString(const struct FString& Filename);
	static class USceneComponent* LineTraceTouchComponent(const struct FVector2D& TouchPos, class APlayerController* PlayerController, TArray<class AActor*> IgnoreActors, struct FVector* TouchHitLoc);
	static int LineTraceTouchAxis(const struct FVector2D& TouchPos, class APlayerController* PlayerController, TArray<class AActor*> IgnoreActors, struct FVector* TouchHitLoc);
	static struct FString LineTraceInstance(class UObject* WorldContextObject, const struct FVector& Start, const struct FVector& End, TArray<class AActor*> IgnoreActors);
	static bool IsPointWithinRotatedBounds(const struct FVector& BoxCenter, const struct FVector& BoxExtent, float YawDegrees, const struct FVector& Point);
	static bool IsPhysicsStateCreated(class UPrimitiveComponent* Component);
	static bool IsPersistentModeEnabled();
	static bool IsOfflineBuild();
	static bool IsMCPModeEnabled();
	static bool IsLLMEnabled();
	static bool IsCreativeMode(class UWorld* World);
	static bool IsBoxOverlapWithRotatedBox(const struct FVector& StaticBoxCenter, const struct FVector& StaticBoxExtent, const struct FVector& RotatedBoxCenter, const struct FVector& RotatedBoxExtent, float RotatedBoxYaw);
	static void IgnoreClientMovementErrorChecksAndCorrection(class ACharacter* Charcter, bool bIsIgnore);
	void GetWidgetRect(class UWidget* Widget, int* X1, int* Y1, int* x2, int* y2);
	static struct FString GetUrlValue(class UObject* WorldContext, const struct FString& Key);
	static struct FString GetUObjAssetPath(class UObject* Level);
	int GetRTValidMaxArea(class UTextureRenderTarget2D* TextureTarget);
	static int GetReplicateAddDataArrayVaildNum(class UObject* WorldContextObject, const struct FReplicateAddDataArray& ReplicateAddDataArray, int StartIndex);
	static float GetPlatformSeconds();
	static void GetObjectScreenPos(class UObject* WorldContextObject, const struct FString& InstanceID, struct FVector2D* Pos);
	static TMap<struct FString, class UObject*> GetObjectMap(class UObject* WorldContextObject);
	static float GetLastInteractionElapsedTime();
	static void GetInstanceSpaceBoundingBox(const struct FString& InstanceID, float Yaw, class UCreativeAbilitySystemComponent* Component);
	static void GetGroupInstanceSpaceBoundingBox(const struct FString& GroupID, TArray<struct FString> ChildrenIds, TMap<struct FString, struct FTransform> ChildrenTransforms, float Yaw, class UCreativeAbilitySystemComponent* Component);
	static class UWorld* GetGameWorld(class UObject* WorldContextObject);
	static struct FString GetGameTypeAsString(ECreativeModeGameType GameType);
	static TArray<unsigned char> GetDataConttentByInstanceDataContent(struct FCreativeInstanceDataContent* InstanceDataContent);
	static uint32_t GetCurFrameNumber();
	static uint32_t GetCurFrameCounter();
	static int GetCubeTouchAxisFace(class UWidget* Widget, float Width, float Distance, struct FVector2D* ScreenPosition, struct FVector* OffsetLocation);
	static bool GetContentPatchData(TArray<unsigned char> OldData, TArray<unsigned char> DiffData, TArray<unsigned char>* outNewData);
	static bool GetContentDiffData(TArray<unsigned char> OldData, TArray<unsigned char> NewData, TArray<unsigned char>* outDiffData);
	static struct FString GetCommandLineValue(const struct FString& Key);
	static void GetBoundingBoxOfInstances(class UObject* WorldContext, TArray<struct FString> Ids, float Yaw, struct FVector* Center, struct FVector* BoxExtent);
	static void GetBoundingBoxOfActors(TArray<class AActor*> Actors, float Yaw, struct FVector* Center, struct FVector* BoxExtent);
	static struct FString GetBigUObject(int MaxN);
	struct FString GetBigLuaValue(class UObject* WorldContext);
	static TArray<struct FString> GetAllInstanceInScreenBox(class UObject* WorldContext, const struct FVector2D& Start, const struct FVector2D& End, int CheckDistance, int CountLimit);
	static TArray<struct FString> GetAllInstanceInBox(class UObject* WorldContext, const struct FVector& Center, const struct FVector& Extent, const struct FRotator& Rotator);
	static void GetActorMeshBoundsByTag(class AActor* Actor, const struct FString& IgnoreTag, const struct FString& IncludeTag, struct FVector* Origin, struct FVector* BoxExtent);
	static uint32_t GenerateUIntGuid();
	static struct FString GenerateGuid();
	static class AActor* FindAttachedActorByName(class AActor* ParentActor, const struct FString& PartialName);
	static class AActor* FindActorByName(class UWorld* World, const struct FString& PartialName);
	struct FString EncryptToBase64(TArray<unsigned char> inArray);
	static void DumpActorNetReplicate(class UObject* WorldContext, const struct FString& Name);
	static void DrawLine(const struct FPaintContext& InContext, const struct FVector2D& Start, const struct FVector2D& End, const struct FLinearColor& LineColor, int LayerOffset, float LineThickness, bool bAntiAlias);
	static void DrawGrids(const struct FPaintContext& InContext, float CellSize, int CellCountX, int CellCountY, float PosOffsetX, float PosOffsetY, const struct FLinearColor& LineColor, float LineThickness, bool bAntiAlias, int LayerOffset);
	static void DrawGridCell(const struct FPaintContext& InContext, float CellSize, int CellIndexX, int CellIndexY, float PosOffsetX, float PosOffsetY, const struct FLinearColor& LineColor, int LayerOffset);
	static struct FString DestroyInstance(class UObject* WorldContextObject, const struct FString& InstanceID);
	TArray<unsigned char> DecryptFromBase64(const struct FString& inString);
	static struct FCreativeInstanceDataContent CreativeInstanceDataContent(TArray<unsigned char> DataContent);
	static struct FCreativeMovingAudio CreateCreativeMovingAudio(class AActor* Actor, int Sequence, int ConfigId, bool bShowMark, int Duration, float Volume);
	void ClearGrassByMaskTexture(class UObject* WorldContextObject, class UTexture2D* MaskTexture, const struct FVector2D& WorldStart, const struct FVector2D& WorldEnd);
	static bool CaptureWidget(class UObject* WorldContext, class UClass* WidgetClass, struct FString* Path, int* X, int* Y, bool* FlipY);
	static bool BoxOverlapComponents(class UObject* WorldContextObject, const struct FVector& BoxPos, const struct FVector& BoxExtent, TArray<int> ObjectTypes, class UClass* CompClassFilter, TArray<class AActor*> ActorsToIgnore, TArray<class UPrimitiveComponent*>* OutComps);
	static bool BoxOverlapActors(class UObject* WorldContextObject, const struct FVector& BoxPos, const struct FVector& BoxExtent, TArray<int> ObjectTypes, class UClass* ActorClassFilter, TArray<class AActor*> ActorsToIgnore, TArray<class AActor*>* OutActors);
	static class AActor* BeginDeferredActorSpawnWithName(class UObject* WorldContextObject, class UClass* ActorClass, const struct FTransform& SpawnTransform, const struct FName& Name, ESpawnActorCollisionHandlingMethod CollisionHandlingOverride, class AActor* Owner);
	static void AttachOutlineBox(class AActor* AttachedActor, float Yaw, class AActor* OutlineBox);
	static void AttachInstanceOutlineBox(const struct FString& AttachedId, bool bGridEnable, float Yaw, class AActor* OutlineBox);
	static void AttachGroupOutlineBox(class AActor* GroupObject, TArray<class AActor*> AttachedActors, float Yaw, class AActor* OutlineBox);
	static void AttachGroupInstanceOutlineBox(const struct FString& GroupID, TArray<struct FString> ChildrenIds, TMap<struct FString, struct FTransform> ChildrenTransforms, bool bGridEnable, float Yaw, class AActor* OutlineBox);
	static void AddOnScreenDebugMessage(const struct FString& Msg);
};


// Class Creative.CreativeModeLuaSpectatorPawn
// 0x00C8 (0x0588 - 0x04C0)
class ACreativeModeLuaSpectatorPawn : public ASpectatorPawn
{
public:
	unsigned char                                      UnknownData00[0x58];                                      // 0x04C0(0x0058) MISSED OFFSET
	struct FLuaNetSerialization                        LuaNetSerialization;                                      // 0x0518(0x0050) (Net)
	bool                                               IsTopView;                                                // 0x0568(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0569(0x0003) MISSED OFFSET
	int                                                TopViewRotateAngle;                                       // 0x056C(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	struct FString                                     LuaFilePath;                                              // 0x0570(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	unsigned char                                      UnknownData02[0x8];                                       // 0x0580(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeLuaSpectatorPawn");
		return pStaticClass;
	}


	void UnRegistLuaTick();
	void SetController(class APlayerController* InController);
	void SetAbilitySystemComponentAvatar();
	void RegistLuaTick(float TickInterval);
	void MoveRight(float Val);
	void MoveForward(float Val);
	class USpringArmComponent* GetActiveSpringArm();
};


// Class Creative.CreativeCameraDeviceActor
// 0x00C0 (0x0648 - 0x0588)
class ACreativeCameraDeviceActor : public ACreativeModeLuaSpectatorPawn
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0588(0x0008) MISSED OFFSET
	bool                                               bIsFollowing;                                             // 0x0590(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0591(0x0003) MISSED OFFSET
	int                                                FollowType;                                               // 0x0594(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsLerping;                                               // 0x0598(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x0599(0x0003) MISSED OFFSET
	float                                              LerpTime;                                                 // 0x059C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              BlendExp;                                                 // 0x05A0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              BlendTimeToGo;                                            // 0x05A4(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              BlendTime;                                                // 0x05A8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FVector                                     SocketOffset;                                             // 0x05AC(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	struct FRotator                                    RotatorOffset;                                            // 0x05B8(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	TWeakObjectPtr<class AActor>                       FollowTarget;                                             // 0x05C4(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EViewTargetBlendFunction>              BlendFunction;                                            // 0x05CC(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x3];                                       // 0x05CD(0x0003) MISSED OFFSET
	struct FRotator                                    ActorStartRot;                                            // 0x05D0(0x000C) (BlueprintVisible, IsPlainOldData)
	struct FRotator                                    ActorTargetRot;                                           // 0x05DC(0x000C) (BlueprintVisible, IsPlainOldData)
	struct FVector                                     targetPos;                                                // 0x05E8(0x000C) (BlueprintVisible, IsPlainOldData)
	struct FRotator                                    TargetRot;                                                // 0x05F4(0x000C) (BlueprintVisible, IsPlainOldData)
	struct FVector                                     StartPos;                                                 // 0x0600(0x000C) (BlueprintVisible, IsPlainOldData)
	struct FRotator                                    StartRot;                                                 // 0x060C(0x000C) (BlueprintVisible, IsPlainOldData)
	float                                              StartFOV;                                                 // 0x0618(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              StartArmLength;                                           // 0x061C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FRotator                                    EndRot;                                                   // 0x0620(0x000C) (BlueprintVisible, IsPlainOldData)
	float                                              EndFOV;                                                   // 0x062C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              EndArmLength;                                             // 0x0630(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x0634(0x0004) MISSED OFFSET
	struct FName                                       SocketName;                                               // 0x0638(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxPilotDist;                                             // 0x0640(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bPilotPosition;                                           // 0x0644(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x3];                                       // 0x0645(0x0003) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeCameraDeviceActor");
		return pStaticClass;
	}


	void UpdateFollowStatus();
	void UpdateFollowPos();
	void RotCamera(float Yaw, float Pitch);
	void OnEndViewTarget(class APlayerController* PC);
	void OnBecomeViewTarget(class APlayerController* PC);
	void MoveUp(float Val);
	void MoveRight(float Val);
	void MoveForward(float Val);
	void LerpToTarget(float DeltaSeconds);
	void LerpActor(float BlendPct);
	bool IsVecInvalid(const struct FVector& Vect);
	bool IsRotInvalid(const struct FRotator& Rot);
	void InterpolateToSpringRotation(float LerpValue);
	bool InitStartPoint();
	class USpringArmComponent* GetSpringArmForCamera(class UCameraComponent* Camera);
	float GetLerpTime(float BlendTimeToGo);
	struct FVector GetCameraPointPosition();
	class UCameraComponent* GetActiveCamera();
};


// Class Creative.CreativeCameraGetter
// 0x0000 (0x0028 - 0x0028)
class UCreativeCameraGetter : public UInterface
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeCameraGetter");
		return pStaticClass;
	}


	struct FVector GetCameraLocation();
};


// Class Creative.CreativeCustomCameraComponent
// 0x0020 (0x0960 - 0x0940)
class UCreativeCustomCameraComponent : public UCameraComponent
{
public:
	unsigned char                                      UnknownData00[0x4];                                       // 0x0940(0x0004) MISSED OFFSET
	float                                              ConfigFOV;                                                // 0x0944(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FRotator                                    ConfigRotation;                                           // 0x0948(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	unsigned char                                      UnknownData01[0xC];                                       // 0x0954(0x000C) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeCustomCameraComponent");
		return pStaticClass;
	}


	void InterpolateToTargetRotation(float LerpValue);
	void InterpolateToTargetFOV(float LerpValue);
};


// Class Creative.CreativeCustomParameterManager
// 0x00E0 (0x01E8 - 0x0108)
class UCreativeCustomParameterManager : public UCreativeModeManagerBase
{
public:
	struct FCreativeCustomParameterDataContainer       ReplicatedCustomParameterDataContainer;                   // 0x0108(0x00C8) (Net, Transient)
	unsigned char                                      UnknownData00[0x18];                                      // 0x01D0(0x0018) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeCustomParameterManager");
		return pStaticClass;
	}


	void RemoveCustomParameter(uint32_t ParameterID, uint32_t PlayerKey);
	void ReceiveOnGameStateBeginPlay(class AGameStateBase* GameState);
	void OnGameStateBeginPlay(class AGameStateBase* GameState);
	void GetCustomParameterDataNodes(uint32_t ParameterID, TArray<struct FCreativeCustomParameterDataNode>* OutCustomParameterDataNodes);
	static class UCreativeCustomParameterManager* Get(class UObject* WorldContext);
	void ChangeCustomParameter(uint32_t ParameterID, uint32_t PlayerKey, int8_t TeamID, TArray<unsigned char> DataContent);
	void AddCustomParameter(uint32_t ParameterID, uint32_t PlayerKey, int8_t TeamID, TArray<unsigned char> DataContent, bool bPropagateToChildren);
};


// Class Creative.CreativeCustomPrefabComponent
// 0x0000 (0x01D8 - 0x01D8)
class UCreativeCustomPrefabComponent : public ULuaActorComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeCustomPrefabComponent");
		return pStaticClass;
	}


	TArray<unsigned char> GetNodeSegmentContent(struct FCreativePrefabDataSegment* Segment);
	bool AddInstanceDataContent(TArray<unsigned char> Content, struct FCreativeCustomPrefabDataSegment* Segment);
};


// Class Creative.CreativeDestructibleMeshActor
// 0x0010 (0x0458 - 0x0448)
class ACreativeDestructibleMeshActor : public APhotonDestructibleMeshActor
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0448(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeDestructibleMeshActor");
		return pStaticClass;
	}


	void SetDamageEnable(bool bEnable);
	void OnHit(class AActor* SelfActor, class AActor* OtherActor, const struct FVector& NormalImpulse, const struct FHitResult& Hit);
	void InitHP(float fHP);
	class UPhotonDestructibleMeshComponent* GetFracturedComponent();
	void AddCanDamageWeapon(const struct FString& Weapon);
};


// Class Creative.CreativeDestructibleMeshBatchActor
// 0x00F8 (0x05F0 - 0x04F8)
class ACreativeDestructibleMeshBatchActor : public ALuaActor
{
public:
	int                                                AtLeastLengthHISMRequired;                                // 0x04F8(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              TickUpdateBatchInterval;                                  // 0x04FC(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                CellWidth;                                                // 0x0500(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0xEC];                                      // 0x0504(0x00EC) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeDestructibleMeshBatchActor");
		return pStaticClass;
	}


	void RemoveAllCacheReplicationData();
};


// Class Creative.CreativeModeLiteComponent
// 0x0118 (0x0158 - 0x0040)
class UCreativeModeLiteComponent : public ULiteComponent
{
public:
	unsigned char                                      UnknownData00[0x68];                                      // 0x0040(0x0068) MISSED OFFSET
	struct FLuaNetSerialization                        LuaNetSerialization;                                      // 0x00A8(0x0050) (Net)
	struct FString                                     LuaFilePath;                                              // 0x00F8(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	TMap<class UObject*, struct FCreativePoolObjectRecordInfo> PoolObjectRecordMap;                                      // 0x0108(0x0050) (ZeroConstructor)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeLiteComponent");
		return pStaticClass;
	}


	bool OnReturnToPool(class UObject* NewOuter, uint32_t RecycledSeq);
	class UObject* GetObjectFromPool(int PoolId, class UObject* NewOuter, struct FString* InName);
};


// Class Creative.CreativeModeGameModeBaseComponent
// 0x0010 (0x0168 - 0x0158)
class UCreativeModeGameModeBaseComponent : public UCreativeModeLiteComponent
{
public:
	ECreativeModeGameType                              GameType;                                                 // 0x0158(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0159(0x0007) MISSED OFFSET
	class UCreativeModeGameStateBaseComponent*         GameStateComponent;                                       // 0x0160(0x0008) (ZeroConstructor, Transient, IsPlainOldData)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeGameModeBaseComponent");
		return pStaticClass;
	}


	void SetGameStateComponent(class UCreativeModeGameStateBaseComponent* NewGameStateComponent);
	void ReceivePostInitializeComponents();
	ECreativeModeGameType GetGameType();
	class ACreativeModeGameMode* GetGameMode();
	class AActor* FindPlayerStartOverride(class AController* Player, const struct FString& IncomingName, bool bIsRevive);
};


// Class Creative.CreativeModeEditorModeComponent
// 0x0000 (0x0168 - 0x0168)
class UCreativeModeEditorModeComponent : public UCreativeModeGameModeBaseComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeEditorModeComponent");
		return pStaticClass;
	}

};


// Class Creative.CreativeModeEditorObject
// 0x0178 (0x0670 - 0x04F8)
class ACreativeModeEditorObject : public ALuaActor
{
public:
	unsigned char                                      UnknownData00[0x98];                                      // 0x04F8(0x0098) MISSED OFFSET
	ECreativeModeActorState                            ActorState;                                               // 0x0590(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0591(0x0007) MISSED OFFSET
	TMap<class UObject*, struct FCreativePoolObjectRecordInfo> PoolObjectRecordMap;                                      // 0x0598(0x0050) (ZeroConstructor)
	int8_t                                             CanEditFlag;                                              // 0x05E8(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bIgnoreCollisionCheck;                                    // 0x05E9(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x6];                                       // 0x05EA(0x0006) MISSED OFFSET
	TArray<class AActor*>                              IgnoreActors;                                             // 0x05F0(0x0010) (ZeroConstructor)
	struct FEditorObjectLiteComponentTickFunction      LiteComponentActorTick;                                   // 0x0600(0x0058) (Edit, DisableEditOnInstance)
	TArray<class ULiteComponent*>                      LiteComponents;                                           // 0x0658(0x0010) (ZeroConstructor, Transient)
	unsigned char                                      UnknownData03[0x8];                                       // 0x0668(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeEditorObject");
		return pStaticClass;
	}


	void UnregisterLiteComponent(class ULiteComponent* Component, bool Destroy);
	void ShowSelectedEffect(bool ShowEff, const struct FLinearColor& OutlineColor, float OutlineThickness);
	void ShowOutlineEffect(bool ShowEff, class UMaterialInstance* Material, const struct FString& IgnoreTag);
	void SetPhotographyMode(bool bIsCapturing);
	void SetLiteComponentTickEnable(bool bEnabled);
	void SetActorState(ECreativeModeActorState NewState);
	void ReturnObjectToPool(class UObject* Obj);
	void ReturnObjectsToPool(TArray<class UObject*> Objs);
	void RegisterLiteComponent(class ULiteComponent* Component);
	void ReceivePostBeginPlay();
	bool ReceiveIsDedicatedServer();
	void ReceiveInitializeLiteComponent();
	void ReceiveInitCanEditFlag();
	bool ReceiveHasAuthority();
	void OnRepActorStateOverride(ECreativeModeActorState NewState);
	void OnRep_ActorState(ECreativeModeActorState LastState);
	bool InCollisionState();
	TArray<class UObject*> GetObjectsFromPool(TArray<struct FCreativePoolGetObjectParamInfo>* ObjectParams);
	class UObject* GetObjectFromPool(int PoolId, class UObject* NewOuter, struct FString* InName);
	ECreativeModeActorState GetActorState();
	class ULiteComponent* FindLiteComponentByClass(class UClass* ComponentClass);
};


// Class Creative.CreativeModeGameStateBaseComponent
// 0x0008 (0x0160 - 0x0158)
class UCreativeModeGameStateBaseComponent : public UCreativeModeLiteComponent
{
public:
	ECreativeModeGameType                              GameType;                                                 // 0x0158(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0159(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeGameStateBaseComponent");
		return pStaticClass;
	}


	void ReceivePostInitializeComponents();
	ECreativeModePlayState GetPlayState();
	ECreativeModeGameType GetGameType();
	class ACreativeModeGameState* GetGameState();
};


// Class Creative.CreativeModeEditorStateComponent
// 0x0000 (0x0160 - 0x0160)
class UCreativeModeEditorStateComponent : public UCreativeModeGameStateBaseComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeEditorStateComponent");
		return pStaticClass;
	}

};


// Class Creative.CreativeEventObject
// 0x0000 (0x00F0 - 0x00F0)
class UCreativeEventObject : public UCreativeLuaSignalObjectBase
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeEventObject");
		return pStaticClass;
	}


	void ReHookObject();
	void EventObjectConditionalBeginDestroy();
};


// Class Creative.CreativeGameAPIObject
// 0x0000 (0x0188 - 0x0188)
class UCreativeGameAPIObject : public UCreativeApiObject
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeGameAPIObject");
		return pStaticClass;
	}


	TArray<int64_t> GetPlayersInSphere(const struct FVector& SphereCenter, float SphereRadius, int TeamID, bool FilterNonPlayable);
	TArray<int64_t> GetPlayersInRectangle(const struct FVector& RectangleCenter, float RectangleX, float RectangleY, float RectangleZ, int TeamID, bool FilterNonPlayable);
};


// Class Creative.CreativeModeGameMode
// 0x0130 (0x2480 - 0x2350)
class ACreativeModeGameMode : public ABattleRoyaleGameModeTeam
{
public:
	class UCreativeModeGameModeBaseComponent*          CurrentModeComponent;                                     // 0x2350(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	TArray<class UClass*>                              GameModeComponentClassArray;                              // 0x2358(0x0010) (ZeroConstructor, Transient)
	class UClass*                                      GameModeComponentClass;                                   // 0x2368(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TMap<struct FString, struct FGameModeParam>        MapPlaneRouteConfigs;                                     // 0x2370(0x0050) (Edit, ZeroConstructor, DisableEditOnInstance)
	TMap<struct FString, struct FString>               MapVehicleClassPathConfigs;                               // 0x23C0(0x0050) (Edit, ZeroConstructor, DisableEditOnInstance)
	ECreativeModeGameType                              EditorStartupGameType;                                    // 0x2410(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x2411(0x0001) MISSED OFFSET
	bool                                               bIsCreativeWoW;                                           // 0x2412(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x5];                                       // 0x2413(0x0005) MISSED OFFSET
	struct FGameModeLiteComponentTickFunction          LiteComponentActorTick;                                   // 0x2418(0x0058) (Edit, DisableEditOnInstance)
	TArray<class ULiteComponent*>                      LiteComponents;                                           // 0x2470(0x0010) (ZeroConstructor, Transient)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeGameMode");
		return pStaticClass;
	}


	void UnregisterLiteComponent(class ULiteComponent* Component);
	void SetLiteComponentTickEnable(bool bEnabled);
	void SetItemGenerate(bool bIsOpen);
	void SetCurrentGameType(ECreativeModeGameType NewGameType);
	void ReInitItemGenerate(struct FString* NewItemClassPath);
	void RegisterLiteComponent(class ULiteComponent* Component);
	void ReceiveInitializeLiteComponent();
	bool IsStandAloneGameMode();
	bool IsRestartPlayerUsePawnRotation();
	class UCreativeModeGameModeBaseComponent* GetCurrentModeComponent();
	int GetCreativeModeRealTeamNum();
	TArray<int> GetCreativeModeRealTeamIDs();
	class ULiteComponent* FindLiteComponentByClass(class UClass* ComponentClass);
	void DSPlayerKickOut(uint64_t UID, const struct FName& PlayerType, const struct FString& ExitReason);
	class AActor* CreativeModeFindPlayerStart(class AController* Player, const struct FString& IncomingName, bool bIsRevive);
};


// Class Creative.CreativeModeGameModeComponent
// 0x0030 (0x0198 - 0x0168)
class UCreativeModeGameModeComponent : public UCreativeModeGameModeBaseComponent
{
public:
	class UClass*                                      RaceCheckPointComponentClass;                             // 0x0168(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCreativeModeRaceCheckPointLiteComponent*    RaceCheckPointComponent;                                  // 0x0170(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UClass*                                      OccupationAreaComponentClass;                             // 0x0178(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCreativeOccupationAreaLiteComponent*        OccupationAreaComponent;                                  // 0x0180(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UClass*                                      TeleporterComponentClass;                                 // 0x0188(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCreativeModeLiteComponent*                  TeleporterComponent;                                      // 0x0190(0x0008) (ZeroConstructor, Transient, IsPlainOldData)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeGameModeComponent");
		return pStaticClass;
	}


	void ReceiveCallPlayStateFunction();
};


// Class Creative.CreativeModeGameObject
// 0x0168 (0x0190 - 0x0028)
class UCreativeModeGameObject : public UObject
{
public:
	unsigned char                                      UnknownData00[0xF0];                                      // 0x0028(0x00F0) MISSED OFFSET
	struct FString                                     LuaFilePath;                                              // 0x0118(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0128(0x0008) MISSED OFFSET
	TMap<class UObject*, struct FCreativePoolObjectRecordInfo> PoolObjectRecordMap;                                      // 0x0130(0x0050) (ZeroConstructor)
	TArray<class ULiteComponent*>                      LiteComponents;                                           // 0x0180(0x0010) (ZeroConstructor, Transient)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeGameObject");
		return pStaticClass;
	}


	void UnregisterLiteComponent(class ULiteComponent* Component, bool Destroy);
	void ReturnObjectToPool(class UObject* Obj);
	void ReturnObjectsToPool(TArray<class UObject*> Objs);
	void RegisterLiteComponent(class ULiteComponent* Component);
	void ReceivePostBeginPlay();
	bool ReceiveIsDedicatedServer();
	bool ReceiveHasAuthority();
	void ReceiveEndPlay();
	void ReceiveBeginPlay();
	TArray<class UObject*> GetObjectsFromPool(TArray<struct FCreativePoolGetObjectParamInfo>* ObjectParams);
	class UObject* GetObjectFromPool(int PoolId, class UObject* NewOuter, struct FString* InName);
};


// Class Creative.CreativeGameParameterManager
// 0x0218 (0x0320 - 0x0108)
class UCreativeGameParameterManager : public UCreativeModeManagerBase
{
public:
	struct FCreativeGameParameterContainer             GameParameterContainer;                                   // 0x0108(0x00C8) (Net, Transient)
	unsigned char                                      UnknownData00[0x4];                                       // 0x01D0(0x0004) MISSED OFFSET
	int                                                SingleSerializeNum;                                       // 0x01D4(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                SingleSerializeBytes;                                     // 0x01D8(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bGameParameterResumeEnable;                               // 0x01DC(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x01DD(0x0003) MISSED OFFSET
	struct FCreativeGameParameterResumeContainer       GameParameterResumeContainer;                             // 0x01E0(0x00C8) (Net, Transient)
	unsigned char                                      UnknownData02[0x64];                                      // 0x02A8(0x0064) MISSED OFFSET
	float                                              ResumeNodePullInterval;                                   // 0x030C(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                SinglePullResumeNodeNum;                                  // 0x0310(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                TotalPullResumeNodeNum;                                   // 0x0314(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              ResumeNodePullTimeroutInterval;                           // 0x0318(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x031C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeGameParameterManager");
		return pStaticClass;
	}


	void SetGameParameterResumeNodes(TArray<struct FCreativeGameParameter> GameParameterNodes);
	void RemoveGameParameter(const struct FString& ParameterKey, const struct FString& TemplateID);
	void ReceiveOnGameStateBeginPlay(class AGameStateBase* GameState);
	void OnReceivePreGameParameterRemove(const struct FString& ParameterKey, const struct FString& TemplateID);
	void OnReceivePostGameParameterChange(const struct FString& ParameterKey, const struct FString& TemplateID, TArray<unsigned char> Content);
	void OnReceivePostGameParameterAdd(const struct FString& ParameterKey, const struct FString& TemplateID, TArray<unsigned char> Content);
	void OnGameStateBeginPlay(class AGameStateBase* GameState);
	TArray<struct FCreativeGameParameter> GetGameParameterResumeNodes(TArray<uint32_t> ParameterHeadHashs);
	bool GetGameParameterContent(const struct FString& ParameterKey, const struct FString& TemplateID, TArray<unsigned char>* OutContent);
	static class UCreativeGameParameterManager* Get(class UObject* WorldContext);
	void ChangeGameParameter(const struct FString& ParameterKey, const struct FString& TemplateID, TArray<unsigned char> Content);
	void AddGameParameter(const struct FString& ParameterKey, const struct FString& TemplateID, TArray<unsigned char> Content);
};


// Class Creative.CreativeModeGameState
// 0x00C8 (0x1590 - 0x14C8)
class ACreativeModeGameState : public ASTExtraGameStateBase
{
public:
	unsigned char                                      UnknownData00[0x2];                                       // 0x14C8(0x0002) MISSED OFFSET
	unsigned char                                      bIsCreativeMode : 1;                                      // 0x14CA(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	ECreativeModeGameType                              CurrentGameType;                                          // 0x14CB(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	ECreativeModeGameType                              InitializeGameType;                                       // 0x14CC(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x14CD(0x0003) MISSED OFFSET
	int                                                CreativeModID;                                            // 0x14D0(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	int                                                CreativeModTemplateId;                                    // 0x14D4(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	class UCreativeModeGameStateBaseComponent*         CurrentStateComponent;                                    // 0x14D8(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	class UCreativeModeGameStateBaseComponent*         LastStateComponent;                                       // 0x14E0(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	TArray<class UClass*>                              GameStateComponentClassArray;                             // 0x14E8(0x0010) (ZeroConstructor, Transient)
	class UClass*                                      GameStateComponentClass;                                  // 0x14F8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsCreativeWoW;                                           // 0x1500(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x17];                                      // 0x1501(0x0017) MISSED OFFSET
	TArray<struct FBlockySlotString>                   BlockySlotStrings;                                        // 0x1518(0x0010) (Net, ZeroConstructor, Transient)
	struct FGameStateLiteComponentTickFunction         LiteComponentActorTick;                                   // 0x1528(0x0058) (Edit, DisableEditOnInstance)
	TArray<class ULiteComponent*>                      LiteComponents;                                           // 0x1580(0x0010) (ZeroConstructor, Transient)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeGameState");
		return pStaticClass;
	}


	void UnregisterLiteComponent(class ULiteComponent* Component);
	void SetLiteComponentTickEnable(bool bEnabled);
	void SetCurrentGameType(ECreativeModeGameType NewGameType);
	void RPC_Replay_SetInstanceDataContent(uint32_t InstanceID, const struct FCreativeInstanceDataContent& InstanceDataContent);
	void RegisterLiteComponent(class ULiteComponent* Component);
	void ReceiveInitializeLiteComponent();
	void ReceiveCreativeCollectGarbage();
	void ReceiveAddContextDataToCrashKit();
	void OnViewportSizeChanged(const struct FVector2D& OldViewportSize, const struct FVector2D& NewViewportSize);
	void OnRep_InitializeGameType(ECreativeModeGameType LastInitializeGameType);
	void OnRep_CurrentStateComponent(class UCreativeModeGameStateBaseComponent* LastComponent);
	void OnRep_CreativeModTemplateId(int LastCreativeModTemplateId);
	void OnRep_CreativeModID(int LastCreativeModID);
	void OnRep_BlockySlotStrings(TArray<struct FBlockySlotString>* BlockySlotStrings);
	void OnClientRecordingStateChange(EClientRecordingType Type);
	bool IsOfficialGame();
	bool IsEditorMode();
	bool IsDemoGame();
	bool IsCreativeMode();
	bool IsCreativeEditor();
	void InitCreativeModID(int ModID, int TemplateID);
	ECreativeModePlayState GetPlayState();
	ECreativeModeGameType GetInitializeGameType();
	TArray<struct FString> GetDisableDistanceLevelsOutsideBox(float X, float Y, int W, int L, float RotationAngle, bool bUseFilter);
	class UCreativeModeGameStateBaseComponent* GetCurrentStateComponent();
	ECreativeModeGameType GetCurrentGameType();
	int GetCurCreativeType();
	struct FString GetCurCreativeModResList();
	struct FString GetCurCreativeModMapID();
	int GetCreativeModTemplateId();
	int GetCreativeModID();
	class ULiteComponent* FindLiteComponentByClass(class UClass* ComponentClass);
	bool FilterLevelByName(const struct FName& LevelName);
	void ClearInstance();
	void ClearAndReImportInstance();
};


// Class Creative.CreativeModeGameStateComponent
// 0x0028 (0x0188 - 0x0160)
class UCreativeModeGameStateComponent : public UCreativeModeGameStateBaseComponent
{
public:
	class UClass*                                      IntegralMechanismComponentClass;                          // 0x0160(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCreativeModeIntegralMechanismLiteComponent* IntegralMechanismComponent;                               // 0x0168(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class UClass*                                      RuntimePlayerBattleDataObjectClass;                       // 0x0170(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class ACreativeRuntimePlayerBattleDataObject*      RuntimePlayerBattleDataObject;                            // 0x0178(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	ECreativeModePlayState                             CurPlayState;                                             // 0x0180(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0181(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeGameStateComponent");
		return pStaticClass;
	}


	void SetPlayState(ECreativeModePlayState newPlayState);
	void OnRep_RuntimePlayerBattleDataObject();
	void OnRep_IntegralMechanismComponent();
	void OnRep_CurPlayState();
	ECreativeModePlayState GetPlayState();
};


// Class Creative.CreativeGlobalApiObject
// 0x0000 (0x0188 - 0x0188)
class UCreativeGlobalApiObject : public UCreativeApiObject
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeGlobalApiObject");
		return pStaticClass;
	}


	void Print(const struct FString& LogText);
	float CPPExecutionConsumptionTest(int A, float B, double C);
};


// Class Creative.CreativeGridLevelsManager
// 0x0478 (0x0580 - 0x0108)
class UCreativeGridLevelsManager : public UCreativeModeManagerBase
{
public:
	bool                                               bDestructibleMeshForceHISM;                               // 0x0108(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bDestructibleMeshEnableBrokenEffect;                      // 0x0109(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2E];                                      // 0x010A(0x002E) MISSED OFFSET
	TArray<struct FString>                             GridLevelList;                                            // 0x0138(0x0010) (ZeroConstructor)
	TMap<struct FString, struct FCreativeModeGridLevelConfig> GridLevelConfigs;                                         // 0x0148(0x0050) (ZeroConstructor)
	TMap<struct FString, struct FCreativeModeGridLevelInfo> GridLevelsMap;                                            // 0x0198(0x0050) (ZeroConstructor)
	TMap<struct FString, struct FIntVector>            ObjectCellIndexMap;                                       // 0x01E8(0x0050) (ZeroConstructor)
	TArray<struct FString>                             AlwaysLoadLevel;                                          // 0x0238(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData01[0x10];                                      // 0x0248(0x0010) MISSED OFFSET
	TArray<struct FString>                             RefreshBatchDataInstances;                                // 0x0258(0x0010) (ZeroConstructor)
	bool                                               bStaticMeshObjectBatchSwitch;                             // 0x0268(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bAroundRelieveBatchSwitch;                                // 0x0269(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x2];                                       // 0x026A(0x0002) MISSED OFFSET
	float                                              EditorModeUpdateTime;                                     // 0x026C(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              DelayUpdateBatchTime;                                     // 0x0270(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              TickUpdateBatchInterval;                                  // 0x0274(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              ReBatchDistance;                                          // 0x0278(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              RelieveBatchDistance;                                     // 0x027C(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bRelieveBatchDelayUpdateSwitch;                           // 0x0280(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x3];                                       // 0x0281(0x0003) MISSED OFFSET
	float                                              RelieveBatchDelayTime;                                    // 0x0284(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bIncrementalRefreshEnable;                                // 0x0288(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bHISMBatchForceSwitch;                                    // 0x0289(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bFineBatchSwitch;                                         // 0x028A(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bDynamicChangeHISMSwitch;                                 // 0x028B(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bPostUpdateISMBufferCompleteEventFlag;                    // 0x028C(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x3];                                       // 0x028D(0x0003) MISSED OFFSET
	int                                                UpdateIsmNumPerFrame;                                     // 0x0290(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x18C];                                     // 0x0294(0x018C) MISSED OFFSET
	TMap<struct FString, class ACreativeModeStaticMeshBatchActor*> SingleBatchActorMap;                                      // 0x0420(0x0050) (ZeroConstructor)
	unsigned char                                      UnknownData06[0xF0];                                      // 0x0470(0x00F0) MISSED OFFSET
	TArray<struct FString>                             ChangeMaterialIdInstanceIDs;                              // 0x0560(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData07[0x10];                                      // 0x0570(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeGridLevelsManager");
		return pStaticClass;
	}


	void UpdateBatchActorInstances(const struct FString& GridName, int AssetId, int MaterialID, bool ReplaceAll);
	void UnLoadGridLevelsBatchActor(const struct FString& GridName, const struct FIntVector& CellIndex);
	void StaticMeshObjectRelieveBatch(struct FString* InstanceID);
	void StaticMeshObjectReBatch(struct FString* InstanceID);
	bool RemoveObject(const struct FString& InstanceID);
	void ReceiveRegistInstanceValueListener();
	void ReceiveDelayUpdateBatchActorInstances(const struct FString& GridName, int AssetId, int MaterialID, bool ReplaceAll, float MoveForwardTimeStamp);
	void ReceiveClearAllData();
	bool ReceiveCheckObjectCanBatch(const struct FString& InstanceID);
	void ObjectAddToGridCellMap(const struct FString& GridName, const struct FIntVector& Index, const struct FString& InstanceID);
	void LoadGridLevelsBatchActor(const struct FString& GridName, const struct FIntVector& CellIndex);
	bool IsCreativeEidtMode();
	void GridCellMapRemoveObject(const struct FString& GridName, const struct FIntVector& Index, const struct FString& InstanceID);
	struct FString GetStaticMeshBatchActorPath();
	class ACreativeDestructibleMeshBatchActor* GetSingleDestructibleMeshBatchActor();
	class ACreativeModeStaticMeshBatchActor* GetSingleBatchActor(const struct FString& GridName);
	float GetRelieveBatchDistance();
	float GetReBatchDistance();
	struct FIntVector GetOnCellIndex(const struct FString& GridName, const struct FVector& Location);
	struct FTransform GetObjectTransform(const struct FString& ID);
	ECreativeModeActorStreamingType GetObjectStreamingType(const struct FString& ID);
	struct FString GetObjectRuntimeGrid(const struct FString& ID);
	struct FIntVector GetObjectOnCellIndexByLocation(const struct FString& InstanceID, const struct FString& GridName, const struct FVector& Location);
	struct FIntVector GetObjectOnCellIndex(const struct FString& InstanceID);
	bool GetObjectIsPrefab(const struct FString& ID);
	int GetObjectAssetID(const struct FString& ID);
	float GetGridLoadingRange(const struct FString& GridName);
	TArray<struct FString> GetGridList();
	struct FString GetDestructibleMeshBatchActorPath();
	struct FString GetDefaultGridName();
	struct FVector2D GetCellWidthHeight(const struct FString& GridName);
	struct FVector GetCellCenterLocation(const struct FString& GridName, const struct FIntVector& CellIndex);
	int GetAxisIndex(float Pos, float BlockLenght);
	static class UCreativeGridLevelsManager* Get(class UObject* WorldContext);
	bool CheckObjectBeRelieveBatch(const struct FString& ID);
	bool CheckObjectBeBatch(const struct FString& ID);
	bool CheckAndRemoveObjectForBatchData(const struct FString& ID);
	bool CheckAndAddObjectToBatchData(const struct FString& ID);
	bool ChangeObjectTransform(const struct FString& InstanceID);
	bool ChangeObjectStreamingType(const struct FString& InstanceID, ECreativeModeActorStreamingType NewStremaingType);
	bool ChangeObjectMaterialIds();
	bool ChangeObjectMaterialId(const struct FString& InstanceID);
	bool ChangeObjectIsPrefab(const struct FString& InstanceID, bool bIsPrefab);
	bool AddObjectToGridLevels(struct FString* InstanceID);
	void ActivateAllAlwaysLoadCellIndex();
};


// Class Creative.CreativeGroupManager
// 0x0000 (0x0108 - 0x0108)
class UCreativeGroupManager : public UCreativeModeManagerBase
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeGroupManager");
		return pStaticClass;
	}


	static class UCreativeGroupManager* Get(class UObject* WorldContext);
};


// Class Creative.CreativeGuideComponent
// 0x0080 (0x0990 - 0x0910)
class UCreativeGuideComponent : public USplineComponent
{
public:
	unsigned char                                      UnknownData00[0x58];                                      // 0x0910(0x0058) MISSED OFFSET
	struct FString                                     LuaFilePath;                                              // 0x0968(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	TArray<class USplineMeshComponent*>                SplineMeshes;                                             // 0x0978(0x0010) (ExportObject, ZeroConstructor, Transient)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0988(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeGuideComponent");
		return pStaticClass;
	}


	bool SweepSingleByChannel(const struct FVector& Start, const struct FVector& End, TArray<class AActor*> IgnoreActors, struct FHitResult* OutHit);
	void GenereateSplineMeshes(TArray<struct FVector> Points);
};


// Class Creative.CreativeGuideMeshComponent
// 0x0010 (0x0AC0 - 0x0AB0)
class UCreativeGuideMeshComponent : public USplineMeshComponent
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0AB0(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeGuideMeshComponent");
		return pStaticClass;
	}


	bool OnReturnToPool(class UObject* NewOuter, uint32_t RecycledSeq);
	void OnPickFromPool(class UObject* NewOuter, const struct FString& InName);
};


// Class Creative.CreativeModeInGameManagerCenter
// 0x0048 (0x0480 - 0x0438)
class ACreativeModeInGameManagerCenter : public AActor
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0438(0x0010) MISSED OFFSET
	TArray<class USTExtraManagerBase*>                 ManagerArray;                                             // 0x0448(0x0010) (ZeroConstructor, Transient)
	TArray<class UClass*>                              ManagerClassArray;                                        // 0x0458(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	unsigned char                                      UnknownData01[0x18];                                      // 0x0468(0x0018) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeInGameManagerCenter");
		return pStaticClass;
	}


	bool GetIsBeginPlayEnded();
};


// Class Creative.CreativeInstanceManager
// 0x0578 (0x0680 - 0x0108)
class UCreativeInstanceManager : public UCreativeModeManagerBase
{
public:
	unsigned char                                      UnknownData00[0x70];                                      // 0x0108(0x0070) MISSED OFFSET
	TMap<struct FString, struct FCreativeInstanceDataNode> InstanceTreeData;                                         // 0x0178(0x0050) (ZeroConstructor)
	TMap<uint16_t, struct FCreativeBatchPullDataNode>  DataRequestMap;                                           // 0x01C8(0x0050) (ZeroConstructor)
	TArray<struct FCreativePullDataNode>               DataWaitingRquestQueue;                                   // 0x0218(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData01[0x10];                                      // 0x0228(0x0010) MISSED OFFSET
	struct FCreativeNodeContainer                      InstanceContainer;                                        // 0x0238(0x0120) (Net, Transient)
	struct FCreativeNodeContainer                      RPCReplicatedInstanceContainer;                           // 0x0358(0x0120) (Transient)
	bool                                               bRPCReplicatInstanceContainerEnable;                      // 0x0478(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x0479(0x0003) MISSED OFFSET
	int                                                CacheCacheHistoryContainerMaxCount;                       // 0x047C(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x50];                                      // 0x0480(0x0050) MISSED OFFSET
	int                                                ModBinInstanceCount;                                      // 0x04D0(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x04D4(0x0004) MISSED OFFSET
	int                                                SingleSerializeNum;                                       // 0x04D8(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                SinglePullDataNodeNum;                                    // 0x04DC(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                TotalPullDataNodeNum;                                     // 0x04E0(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              DataNodePullInterval;                                     // 0x04E4(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              DataPullTimeroutInterval;                                 // 0x04E8(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                FetchesPerFrame;                                          // 0x04EC(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              WaitInstanceReplicatTreeTimeout;                          // 0x04F0(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              BuildingResTime;                                          // 0x04F4(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              ClientPreAddBuildingResTime;                              // 0x04F8(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              BuildingTimeoutCheckInterval;                             // 0x04FC(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FString                                     DefaultDestructibleMeshObjectPath;                        // 0x0500(0x0010) (ZeroConstructor)
	struct FString                                     ExpiredAssetEditorPath;                                   // 0x0510(0x0010) (ZeroConstructor)
	struct FString                                     DebugObjectPath;                                          // 0x0520(0x0010) (ZeroConstructor)
	float                                              StartDownloadMapTimeStamp;                                // 0x0530(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              CompleteDownloadReplicatTreeTimeStamp;                    // 0x0534(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              CompleteDownloadDataNodeTreeTimeStamp;                    // 0x0538(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x4];                                       // 0x053C(0x0004) MISSED OFFSET
	TMap<struct FString, struct FCreativeInstanceNode> CppInstanceTree;                                          // 0x0540(0x0050) (ZeroConstructor)
	unsigned char                                      UnknownData06[0x38];                                      // 0x0590(0x0038) MISSED OFFSET
	unsigned char                                      UnknownData07[0x50];                                      // 0x0590(0x0050) UNKNOWN PROPERTY: SetProperty Creative.CreativeInstanceManager.ExpiredAssetID
	unsigned char                                      UnknownData08[0x50];                                      // 0x0618(0x0050) UNKNOWN PROPERTY: SetProperty Creative.CreativeInstanceManager.DebugAssetID
	uint32_t                                           RPCReplicatedInstanceContainerSeq;                        // 0x0668(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	float                                              ReqInstanceContainerContentTimeoutTimeStamp;              // 0x066C(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              ReqInstanceContainerContentTimeroutInterval;              // 0x0670(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bRPCReplicatInstanceContainerTickCheckEnable;             // 0x0674(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData09[0x3];                                       // 0x0675(0x0003) MISSED OFFSET
	float                                              RPCReplicatInstanceContainerTickCheckCD;                  // 0x0678(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      bRPCReplicatInstanceContainerReqing : 1;                  // 0x067C(0x0001)
	unsigned char                                      UnknownData10[0x3];                                       // 0x067D(0x0003) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeInstanceManager");
		return pStaticClass;
	}


	void UpdateModBinInstanceCount();
	void SetModBinInstanceCount(int Count);
	bool SetInstanceValue(const struct FString& InstanceID, const struct FString& Key, const struct FString& Value);
	void SetInstanceDataContents(uint16_t Seq, TArray<struct FCreativeInstanceDataContent> InstanceDataContents);
	void SetInstanceContainerContent(TArray<unsigned char> ContainerContent, uint32_t NewSeq);
	void SendModBinaryDataToReplay(TArray<unsigned char>* InBinaryData);
	void ReqInstanceContainerContentTimeoutCheck();
	void ReqInstanceContainerContentEnd(bool IsTimeout);
	void RemoveInstance(const struct FString& ID, bool bSkipCheck);
	bool RemoveCppInstanceNode(const struct FString& ID);
	void RecordAllInstanceDataByRPC();
	void ReceiveOnGameStateBeginPlay(class AGameStateBase* GameState);
	void OnRep_RPCReplicatedInstanceContainerSeq();
	void OnRep_ModBinInstanceCount();
	void OnReceivePreInstanceRemove(const struct FString& ID, bool IsRollback);
	void OnReceivePostInstanceChange(const struct FString& ID, TArray<unsigned char> Content, bool IsRollback);
	void OnReceivePostInstanceAdd(const struct FString& ID, TArray<unsigned char> Content, bool IsRollback);
	void OnReceiveClearNotReplicatedData();
	void OnReadyToAddInstance();
	void OnPlayerControllerBeginPlay(class APlayerController* PlayerController);
	void OnGameTypeChanged(unsigned char LastGameType, unsigned char CurrentGameType);
	void OnGameStateBeginPlay(class AGameStateBase* GameState);
	bool IsInstanceReplicatTreeReplicateComplete();
	bool IsInstanceDataTreeReplicateComplete();
	bool IsAssetRuntimeObjectBox(const struct FString& ID);
	void InitExpiredAndDebugAssetID(TArray<int>* ExpiredAssets, TArray<int>* DebugAssets);
	bool HasReadyToAddInstance();
	bool HasAuthorityOrReplay();
	struct FString GetObjectAssetPath(const struct FString& ID);
	int GetModBinInstanceCount();
	bool GetModBinaryDataFromReplay(TArray<unsigned char> InBinaryData);
	bool GetInstanceIsDestructible(const struct FString& ID);
	bool GetInstanceIsCustomUI(const struct FString& ID);
	int GetInstanceDataTreeCount();
	TArray<struct FCreativeInstanceRespondPullDataSegment> GetInstanceDataContents(TArray<uint32_t> InstanceIDs);
	TArray<unsigned char> GetInstanceDataContent(const struct FString& InstanceID);
	int GetInstanceContainerCount();
	TArray<unsigned char> GetInstanceContainerContent(uint32_t BaseSeq, uint32_t* OutSeq);
	struct FBox GetInstanceBox(const struct FString& ID);
	struct FCreativeInstanceNode GetCppInstanceNode(const struct FString& ID);
	struct FBox GetAssetBox(const struct FString& ID);
	static class UCreativeInstanceManager* Get(class UObject* WorldContext);
	uint32_t GenerateDestructionUniqueID(uint32_t ID);
	struct FString DestroyInstance(const struct FString& InstanceID);
	void ClientPreAddInstance(const struct FString& ID, TArray<unsigned char> Content);
	void ClearInstanceTree();
	void CheckAndReqRPCReplicatedInstanceContainerContent();
	void ChangeInstance(const struct FString& ID, TArray<unsigned char> Content, bool bCallReceiveChange);
	void ChangeCppInstanceNode(const struct FString& ID, const struct FString& Key, struct FCreativeInstanceNode* Node);
	void AddInstance(const struct FString& ID, TArray<unsigned char> Content);
	void AddCppInstanceNode(const struct FString& ID, struct FCreativeInstanceNode* Node);
	void AddBuildingFlag(const struct FString& ID);
};


// Class Creative.CreativeInstanceStaticMeshComponent
// 0x0050 (0x0BC0 - 0x0B70)
class UCreativeInstanceStaticMeshComponent : public UInstancedStaticMeshComponent
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x0B70(0x0018) MISSED OFFSET
	struct FSoftObjectPath                             SoftStaticMeshPath;                                       // 0x0B88(0x0018)
	class UMaterialInterface*                          WaitSetMaterial;                                          // 0x0BA0(0x0008) (ZeroConstructor, IsPlainOldData)
	TArray<struct FTransform>                          WaitSetAddInstanceTransforms;                             // 0x0BA8(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0BB8(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeInstanceStaticMeshComponent");
		return pStaticClass;
	}


	void UpdateAllInstanceByRelativeLocation(TArray<struct FVector> RelativeLocations, const struct FVector& Scale);
	void UnInitInstancedStaticMeshComponntByGroupBuild();
	void SetISMMaterial(class UMaterialInterface* NewMaterial);
	void OnStaticMeshAsyncLoaded(const struct FSoftObjectPath& SoftObjectPath);
	bool OnReturnToPool(class UObject* NewOuter, uint32_t RecycledSeq);
	void OnPickFromPool(class UObject* NewOuter, const struct FString& InName);
	void InitInstancedStaticMeshComponntByGroupBuild(class USceneComponent* Parent, TArray<struct FTransform> InstanceTransforms, const struct FString& MeshPath, class UMaterialInterface* Material);
};


// Class Creative.CreativeModeIntegralMechanismComponent
// 0x0010 (0x01E8 - 0x01D8)
class UCreativeModeIntegralMechanismComponent : public ULuaActorComponent
{
public:
	TArray<struct FPlayerIntegralInfo>                 PlayerIntegrals;                                          // 0x01D8(0x0010) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeIntegralMechanismComponent");
		return pStaticClass;
	}


	bool SetPlayerIntegral(const struct FString& UID, int TeamID, int curIntegral, int curStageIntegral, int integralAddSeq);
	void OnRepPlayerIntegralsOverride();
	void OnRep_PlayerIntegrals();
	void ClearPlayerIntegrals();
};


// Class Creative.CreativeModeIntegralMechanismLiteComponent
// 0x0018 (0x0170 - 0x0158)
class UCreativeModeIntegralMechanismLiteComponent : public UCreativeModeLiteComponent
{
public:
	TArray<struct FPlayerIntegralInfo>                 PlayerIntegrals;                                          // 0x0158(0x0010) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor)
	int                                                TestIndex;                                                // 0x0168(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x016C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeIntegralMechanismLiteComponent");
		return pStaticClass;
	}


	bool SetPlayerIntegral(const struct FString& UID, int TeamID, int curIntegral, int curStageIntegral, int integralAddSeq);
	bool PlayerIntegralContains(const struct FString& UID);
	void OnRepPlayerIntegralsOverride();
	void OnRep_TestIndex(int LastIndex);
	void OnRep_PlayerIntegrals();
	void ClearPlayerIntegrals();
};


// Class Creative.CreativeItemGeneratorComponent
// 0x0058 (0x09F0 - 0x0998)
class UCreativeItemGeneratorComponent : public UItemGeneratorComponent
{
public:
	unsigned char                                      UnknownData00[0x58];                                      // 0x0998(0x0058) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeItemGeneratorComponent");
		return pStaticClass;
	}


	void SetWeightMul(TMap<struct FString, int> Weight);
	void SetAddSpotPercentMul(float percent);
	void ClearWeightMul();
};


// Class Creative.CreativeLoadManager
// 0x0068 (0x0170 - 0x0108)
class UCreativeLoadManager : public UCreativeModeManagerBase
{
public:
	uint32_t                                           MaxLoadCountPerFrame;                                     // 0x0108(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x64];                                      // 0x010C(0x0064) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeLoadManager");
		return pStaticClass;
	}


	void UnloadSomeObjects(TArray<struct FString> InstanceIDs, bool bRemovePhysicsObject);
	void UnloadObject(const struct FString& InstanceID, bool bRemovePhysicsObject);
	void LoadSomeObjects(TArray<struct FString> InstanceIDs, bool bLoadImmediately);
	void LoadObject(const struct FString& InstanceID);
	static class UCreativeLoadManager* Get(class UObject* WorldContext);
	void AddObject(const struct FString& InstanceID, const struct FCreativeInstanceNode& InstanceNode);
};


// Class Creative.CreativeLuaCodeManager
// 0x0058 (0x0160 - 0x0108)
class UCreativeLuaCodeManager : public UCreativeModeManagerBase
{
public:
	TMap<unsigned char, struct FString>                CodeMap;                                                  // 0x0108(0x0050) (ZeroConstructor, Transient)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0158(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeLuaCodeManager");
		return pStaticClass;
	}


	void ReceiveOnGameStateBeginPlay(class AGameStateBase* GameState);
	void OnPreCreativeLuaVMUnLoad();
	void OnGameStateBeginPlay(class AGameStateBase* GameState);
	void OnCreativeLuaInitialized();
	static class UCreativeLuaCodeManager* Get(class UObject* WorldContext);
};


// Class Creative.CreativeLuaEntityManager
// 0x00F8 (0x0200 - 0x0108)
class UCreativeLuaEntityManager : public UCreativeModeManagerBase
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0108(0x0008) MISSED OFFSET
	TMap<int64_t, TWeakObjectPtr<class UObject>>       CacheMap;                                                 // 0x0110(0x0050) (ZeroConstructor)
	unsigned char                                      UnknownData01[0x50];                                      // 0x0160(0x0050) MISSED OFFSET
	unsigned char                                      UnknownData02[0x50];                                      // 0x0160(0x0050) UNKNOWN PROPERTY: SetProperty Creative.CreativeLuaEntityManager.UsedUUIDSet

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeLuaEntityManager");
		return pStaticClass;
	}


	class UObject* UUID2UObject(int64_t* UUID);
	bool UUID2Type(int64_t* UUID, EEntityType* Type, unsigned char* SubType);
	uint32_t UUID2Key(int64_t* UUID);
	void ResetAll();
	void RemoveUUID(int64_t* UUID);
	class UObject* LuaUUID2UObject(struct FString* UUID);
	bool LuaUUID2Type(struct FString* UUID, EEntityType* Type, unsigned char* SubType);
	struct FString LuaUUID2Key(struct FString* UUID, EEntityType* Type, unsigned char* SubType);
	void LuaRemoveUUID(struct FString* UUID);
	struct FString LuaCreateEntityIfNotExistsFromUObject(class UObject* Object, EEntityType* Type, unsigned char* SubType);
	int64_t GetInstanceObjectUUID(int64_t* UUID);
	static class UCreativeLuaEntityManager* Get(class UObject* WorldContext);
	int64_t GenUUID(struct FString* Key, EEntityType* Type, unsigned char* SubType);
	int64_t CreateEntityIfNotExistsFromUObject(class UObject* Object, EEntityType* Type, unsigned char* SubType);
	int64_t CreateEntityIfNotExistsFromKey(uint32_t* Key, EEntityType* Type, unsigned char* SubType);
};


// Class Creative.CreativeLuaSignalManager
// 0x0050 (0x0158 - 0x0108)
class UCreativeLuaSignalManager : public UCreativeModeManagerBase
{
public:
	TMap<struct FString, class UCreativeApiObject*>    ObjectMap;                                                // 0x0108(0x0050) (ZeroConstructor, Transient)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeLuaSignalManager");
		return pStaticClass;
	}


	void SpawnApiObjectsByConfig();
	void RegisterObject(class UCreativeApiObject* NewObject);
	void OnPreCreativeLuaVMUnLoad();
	void OnCreativeLuaVMLoaded();
	class UCreativeApiObject* GetObject(const struct FString& ModuleName);
	class UCreativeBridgeLuaVM* GetCreativeLuaVM();
	static class UCreativeLuaSignalManager* Get(class UObject* WorldContext);
	int ExecuteAPI(class UCreativeBridgeLuaVM* VM, struct FString* ModuleName, struct FString* FuncName);
	void ClearAllObjects();
};


// Class Creative.CreativeLuaTraitManager
// 0x0000 (0x0108 - 0x0108)
class UCreativeLuaTraitManager : public UCreativeModeManagerBase
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeLuaTraitManager");
		return pStaticClass;
	}


	TArray<struct FString> GetSupportEntitiesByTraits(TArray<struct FString> TraitNames);
	TArray<struct FString> GetSupportEntitiesByTrait(const struct FString& TraitName);
	static class UCreativeLuaTraitManager* Get(class UObject* WorldContext);
};


// Class Creative.CreativeLuaVMManager
// 0x0010 (0x0118 - 0x0108)
class UCreativeLuaVMManager : public UCreativeModeManagerBase
{
public:
	class UCreativeBridgeLuaVM*                        LuaVM;                                                    // 0x0108(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0110(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeLuaVMManager");
		return pStaticClass;
	}


	void UnRegisterGameTypePreChangedDelegate();
	void RegisterGameTypePreChangedDelegate();
	void ReceiveOnGameStateBeginPlay(class AGameStateBase* GameState);
	void ReceiveCheckAndLoadLuaVM();
	void OnLuaVMAtPanic(const struct FString& ErrMsg);
	void OnGameTypePreChanged(unsigned char LastGameType, unsigned char CurrentGameType);
	void OnGameStateBeginPlay(class AGameStateBase* GameState);
	void LoadLuaVM();
	class UCreativeBridgeLuaVM* GetCreativeLuaVM();
	static class UCreativeLuaVMManager* Get(class UObject* WorldContext);
	bool CreativeLuaVMLoaded();
	bool CreativeLuaInitialized();
};


// Class Creative.CreativeManagerCenterInterface
// 0x0000 (0x0028 - 0x0028)
class UCreativeManagerCenterInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeManagerCenterInterface");
		return pStaticClass;
	}

};


// Class Creative.CreativeModeModDataCheckManager
// 0x0000 (0x0108 - 0x0108)
class UCreativeModeModDataCheckManager : public UCreativeModeManagerBase
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeModDataCheckManager");
		return pStaticClass;
	}


	void ReceiveOnPreAddInstance();
	void ReceiveOnPostAddInstance();
	void OnPreAddInstance();
	void OnPostAddInstance();
	static class UCreativeModeModDataCheckManager* Get(class UObject* WorldContext);
};


// Class Creative.CreativeModeChatBubbleUI
// 0x0038 (0x0298 - 0x0260)
class UCreativeModeChatBubbleUI : public UUserWidget
{
public:
	struct FName                                       SocketName;                                               // 0x0260(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bMoveWithPawn;                                            // 0x0268(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0269(0x0003) MISSED OFFSET
	struct FVector                                     TargetOffset;                                             // 0x026C(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	TWeakObjectPtr<class AActor>                       CurTargetActor;                                           // 0x0278(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UCanvasPanelSlot*                            ChildSlot;                                                // 0x0280(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0288(0x0004) MISSED OFFSET
	struct FVector                                     CurrentTargetPosition;                                    // 0x028C(0x000C) (Edit, BlueprintVisible, IsPlainOldData)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeChatBubbleUI");
		return pStaticClass;
	}


	void TickLua();
	void ForceUpdatePosition();
};


// Class Creative.CreativeModeGlobalManagerCenter
// 0x0030 (0x0060 - 0x0030)
class UCreativeModeGlobalManagerCenter : public UGameInstanceSubsystem
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0030(0x0010) MISSED OFFSET
	TArray<class USTExtraManagerBase*>                 ManagerArray;                                             // 0x0040(0x0010) (ZeroConstructor, Transient)
	TArray<class UClass*>                              ManagerClassArray;                                        // 0x0050(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeGlobalManagerCenter");
		return pStaticClass;
	}


	void OnCreativeDelegateCreated();
};


// Class Creative.CreativeModeStaticMeshBatchActor
// 0x00F8 (0x05F0 - 0x04F8)
class ACreativeModeStaticMeshBatchActor : public ALuaActor
{
public:
	unsigned char                                      UnknownData00[0x48];                                      // 0x04F8(0x0048) MISSED OFFSET
	struct FCreativeBatchInstancedStaticMesh           InstancedStaticMeshInfo;                                  // 0x0540(0x0058)
	struct FCreativeFineBatchInstancedStaticMesh       BatchInstancedStaticMeshInfo;                             // 0x0598(0x0050)
	unsigned char                                      UnknownData01[0x8];                                       // 0x05E8(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeStaticMeshBatchActor");
		return pStaticClass;
	}


	void SetISMStaticMeshAndMaterials(class UInstancedStaticMeshComponent* InstancedStaticMeshComponent, int AssetId, int StaticMeshIndex, int MaterialID);
};


// Class Creative.CreativeModeTouchWidget
// 0x0000 (0x02C8 - 0x02C8)
class UCreativeModeTouchWidget : public ULuaUserWidget
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeTouchWidget");
		return pStaticClass;
	}


	struct FEventReply OnHandleTouchStart(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	struct FEventReply OnHandleTouchMove(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	struct FEventReply OnHandleTouchEnd(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	bool OnHandleTouch(int Type, int FingerIndex, const struct FVector2D& Pos);
};


// Class Creative.CreativeModeNavigationManager
// 0x0050 (0x0158 - 0x0108)
class UCreativeModeNavigationManager : public UCreativeModeManagerBase
{
public:
	unsigned char                                      UnknownData00[0x50];                                      // 0x0108(0x0050) UNKNOWN PROPERTY: SetProperty Creative.CreativeModeNavigationManager.CachedActors

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeNavigationManager");
		return pStaticClass;
	}


	void SetTimeSliceConfig(int MaxTaskPerSlice, int SliceTimeLen);
	void SetNavmeshBuildPolicy(int PolicyVal);
	void SetDynamicModeEnable(bool bEnable);
	void SetDebugOutputEnable(bool bEnable);
	void SetConcurrentTaskNum(int Num);
	TArray<unsigned char> SerializeDynamicTileToByteArr(int MaxFileSize, int MaxTileToAdd);
	void RevokePendingBuildingTasks();
	void ReceiveOnUnInit();
	void ReceiveOnInit();
	void RebuildDynamicTilesByCoord(TArray<struct FIntPoint>* DynamicTiles);
	void RebuildDynamicTiles(TArray<class AActor*>* Actors);
	bool IsBuildingInProgress();
	void ImportDynamicTile(struct FString* Path);
	int GetDynamicTilesCount();
	bool GetDynamicTileMemCost(int* Total, int* OctTree, int* TileCache, int* DynamicTile, int* DynamicTileCount);
	struct FIntPoint GetDynamicTileCoordByPos(const struct FVector& Pos);
	TArray<class AActor*> GetAllAssociateActors();
	static class UCreativeModeNavigationManager* Get(class UObject* WorldContext);
	void ExportDynamicTile(struct FString* Path);
	void DeserializeDynamicTileFromByteArr(TArray<unsigned char>* ByteArr);
	void ClearNavCollision();
	void ClearDynamicOctreeData();
	void ClearDynamicNavMesh();
	void ClearAssociateActors();
	TArray<struct FVector> CalSamplePointsInBoxLegacy(const struct FVector& BoxMin, const struct FVector& BoxMax, float StepSize, int MaxPoints);
	TArray<struct FVector> CalSamplePointsInBox(const struct FVector& BoxMin, const struct FVector& BoxMax, float StepSize, int MaxPoints);
	TArray<struct FVector> CalSamplePoints(const struct FVector& StartPos, float StepSize, int MaxPoints);
	void AddNavAffectedObjects(TArray<class AActor*> Actors);
	void AddNavAffectedObject(class AActor* Actor);
};


// Class Creative.CreativeObjectEditAxisActor
// 0x00B8 (0x05B0 - 0x04F8)
class ACreativeObjectEditAxisActor : public ALuaActor
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x04F8(0x0018) MISSED OFFSET
	struct FVector                                     AxisState;                                                // 0x0510(0x000C) (Edit, IsPlainOldData)
	struct FVector                                     ForceHideAxis;                                            // 0x051C(0x000C) (Edit, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0528(0x0008) MISSED OFFSET
	struct FTransform                                  WorldBaseTransform;                                       // 0x0530(0x0030) (Edit, IsPlainOldData)
	unsigned char                                      UnknownData02[0x48];                                      // 0x0560(0x0048) MISSED OFFSET
	class APlayerCameraManager*                        PlayerCameraManager;                                      // 0x05A8(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeObjectEditAxisActor");
		return pStaticClass;
	}


	void StartEdit(int Axis, const struct FVector2D& Pos, const struct FVector& HitPos);
	void SetForceHideAxis(const struct FVector& State);
	void SetFixedAxisSize(float FixedSize);
	void SetEditType(int InEditType, int InEditSubType);
	void SetComponentVisible(class USceneComponent* comp, bool bVisible);
	void SetAxisState(const struct FVector& State);
	void MarkEditing(bool bDoing);
	void CalScale(const struct FVector2D& Pos, struct FVector* OutScale);
	float CalRotation(const struct FVector2D& Pos, struct FRotator* OutRot);
	void CalLocation(const struct FVector2D& Pos, struct FVector* OutLoc);
};


// Class Creative.CreativeModeObjectFuncComponent
// 0x0000 (0x0158 - 0x0158)
class UCreativeModeObjectFuncComponent : public UCreativeModeLiteComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeObjectFuncComponent");
		return pStaticClass;
	}

};


// Class Creative.CreativeModeObjectInterface
// 0x0000 (0x0028 - 0x0028)
class UCreativeModeObjectInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeObjectInterface");
		return pStaticClass;
	}


	void ReceiveOnPostSetInstanceId(const struct FString& InstanceID);
};


// Class Creative.CreativeObjectLocalAxisActor
// 0x00B8 (0x05B0 - 0x04F8)
class ACreativeObjectLocalAxisActor : public ALuaActor
{
public:
	class AActor*                                      AttachActor;                                              // 0x04F8(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              AttachOffsetZ;                                            // 0x0500(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0504(0x0004) MISSED OFFSET
	class USceneComponent*                             AxisComponent;                                            // 0x0508(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USceneComponent*                             GridComponent;                                            // 0x0510(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0518(0x0008) MISSED OFFSET
	struct FTransform                                  BaseTransform;                                            // 0x0520(0x0030) (IsPlainOldData)
	struct FVector                                     Offset;                                                   // 0x0550(0x000C) (IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x055C(0x0004) MISSED OFFSET
	struct FTransform                                  AttachTransform;                                          // 0x0560(0x0030) (IsPlainOldData)
	bool                                               bAttach;                                                  // 0x0590(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bNoRotate;                                                // 0x0591(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bNoZClamp;                                                // 0x0592(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x1];                                       // 0x0593(0x0001) MISSED OFFSET
	float                                              SnapUnit;                                                 // 0x0594(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FVector                                     SnapAxisConfig;                                           // 0x0598(0x000C) (IsPlainOldData)
	float                                              HideDelayInterval;                                        // 0x05A4(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x8];                                       // 0x05A8(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeObjectLocalAxisActor");
		return pStaticClass;
	}


	void SetAxisComponents(class USceneComponent* Axis, class USceneComponent* Grid);
	void NeedUpdate();
};


// Class Creative.CreativeObjectManager
// 0x0128 (0x0230 - 0x0108)
class UCreativeObjectManager : public UCreativeModeManagerBase
{
public:
	TMap<struct FString, class UObject*>               ObjectMap;                                                // 0x0108(0x0050) (ZeroConstructor, Transient)
	TMap<struct FString, bool>                         ObjectActiveMap;                                          // 0x0158(0x0050) (ZeroConstructor)
	bool                                               bContainsSpawnCompleteCallback;                           // 0x01A8(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bReordering;                                              // 0x01A9(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x01AA(0x0002) MISSED OFFSET
	int                                                Client_FrameSpawnNum;                                     // 0x01AC(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                Ds_FrameSpawnNum;                                         // 0x01B0(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bFrameDestroyObjectEnable;                                // 0x01B4(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x01B5(0x0003) MISSED OFFSET
	int                                                Client_FrameDestroyNum;                                   // 0x01B8(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                Ds_FrameDestroyNum;                                       // 0x01BC(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bPostSpawnCompleteEventFlag;                              // 0x01C0(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x6F];                                      // 0x01C1(0x006F) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeObjectManager");
		return pStaticClass;
	}


	void SpawnObjectForStreaming(const struct FString& InstanceID);
	class UObject* SpawnObject(const struct FString& InstanceID, const struct FString& Path, const struct FTransform& SpawnTransform);
	bool SetObjectTempStreamingType(const struct FString& InstanceID, ECreativeModeActorStreamingType TempStreamingType);
	bool ResetObjectStreamingType(const struct FString& InstanceID);
	bool RemoveSpawnObjectInfoFormQueue(struct FString* InstanceID);
	void RemovePhysicsObject(const struct FString& InstanceID);
	bool RemoveObject(const struct FString& InstanceID, bool bRemovePhysicsObject);
	bool RemoveDestroyObjectInfoFormQueue(struct FString* InstanceID);
	void ReceiveUnregisterObject(const struct FString& InstanceID, class UObject* NewObject);
	void ReceiveRegisterObject(const struct FString& InstanceID, class UObject* NewObject);
	void ReceiveOnPostLoadMapWithWorld(class UWorld* World);
	void ReceiveClearAllObjects();
	void OnPostLoadMapWithWorld(class UWorld* World);
	void OnObjectSpawnComplete(const struct FString& ID);
	bool IsLogicObject(const struct FString& ID);
	bool IsGroupObject(const struct FString& ID);
	bool IsCanBatchObject(const struct FString& ID);
	struct FTransform GetObjectTransform(const struct FString& ID);
	uint32_t GetObjectNum();
	struct FString GetObjectAssetPath(const struct FString& ID);
	int GetObjectAssetID(const struct FString& ID);
	class UObject* GetObject(const struct FString& InstanceID);
	uint32_t GetActiveObjectNum();
	static class UCreativeObjectManager* Get(class UObject* WorldContext);
	void DestroyObjectForStreaming(const struct FString& InstanceID);
	bool DestroyObject(const struct FString& InstanceID);
	bool CheckObjectBeBatch(const struct FString& ID);
	bool ChangeObjectTransform(const struct FString& InstanceID, const struct FTransform& Transform);
	void AddSpawnObjectToQueue(const struct FString& InstanceID, const struct FString& Path, const struct FTransform& SpawnTransform);
	bool AddObject(const struct FString& InstanceID, const struct FCreativeModeStreamingParameters& StreamingParameters);
	void AddDestroyObjectToQueue(const struct FString& InstanceID);
};


// Class Creative.CreativeObjectStateManager
// 0x0008 (0x0110 - 0x0108)
class UCreativeObjectStateManager : public UCreativeModeManagerBase
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0108(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeObjectStateManager");
		return pStaticClass;
	}


	void ReceiveOnGameStateBeginPlay(class AGameStateBase* GameState);
	void OnGameStateBeginPlay(class AGameStateBase* GameState);
	static class UCreativeObjectStateManager* Get(class UObject* WorldContext);
};


// Class Creative.CreativeOccupationAreaLiteComponent
// 0x0000 (0x0158 - 0x0158)
class UCreativeOccupationAreaLiteComponent : public UCreativeModeLiteComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeOccupationAreaLiteComponent");
		return pStaticClass;
	}

};


// Class Creative.CreativeOfflineBuildManager
// 0x0000 (0x0108 - 0x0108)
class UCreativeOfflineBuildManager : public USTExtraManagerBase
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeOfflineBuildManager");
		return pStaticClass;
	}


	void ReceiveOnPostSetLuaEventBridgeInstance();
	void OnPostSetLuaEventBridgeInstance();
	static class UCreativeOfflineBuildManager* Get(class UObject* WorldContext);
};


// Class Creative.CreativePerfManager
// 0x0078 (0x0180 - 0x0108)
class UCreativePerfManager : public UCreativeModeManagerBase
{
public:
	TMap<class AActor*, struct FCreaitvePerfDataMap>   ActorPerfData;                                            // 0x0108(0x0050) (ZeroConstructor)
	struct FCreativeNetData                            BeginSampleNetData;                                       // 0x0158(0x0008)
	float                                              FPSStatInterval;                                          // 0x0160(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1C];                                      // 0x0164(0x001C) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativePerfManager");
		return pStaticClass;
	}


	void ReceiveOnGameStateBeginPlay(class AGameStateBase* GameState);
	void OnGameStateBeginPlay(class AGameStateBase* GameState);
	TMap<struct FName, float> GetUObjectMemoryUsage();
	TArray<struct FCreaitvePerfDataMap> GetResult();
	struct FCreativeNetData GetNetData();
	struct FCreativeMemoryData GetMemoryData();
	void GetCPUUsage(int Type, float* OutCPUTimePct, float* OutCPUTimePctRelative);
	static class UCreativePerfManager* Get(class UObject* WorldContext);
	void EndSample();
	void BeginSample();
	void AddActorToRecord(class AActor* Actor, int AssetId, const struct FName& ScopeName);
};


// Class Creative.CreativePhotonDestructibleMeshComponent
// 0x0050 (0x0D90 - 0x0D40)
class UCreativePhotonDestructibleMeshComponent : public UPhotonDestructibleMeshComponent
{
public:
	unsigned char                                      UnknownData00[0x20];                                      // 0x0D40(0x0020) MISSED OFFSET
	struct FPhotonDestructionParam                     DestructionParam;                                         // 0x0D60(0x0020)
	int                                                MaxFXFragmentNumber;                                      // 0x0D80(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0xC];                                       // 0x0D84(0x000C) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativePhotonDestructibleMeshComponent");
		return pStaticClass;
	}


	void SetInstanceActive(bool bActive);
	void SetDestructionParam(const struct FPhotonDestructionParam& Param);
	void SetCreativeServerDamagedDelegate(const struct FScriptDelegate& del);
	void SetCreativeClientFragmentStateChangedDelegate(const struct FScriptDelegate& del);
	bool RebornOneFragment(int FragmentIndex);
	bool RebornInstance();
	bool RandomRecoverOneFragment();
	void RandomDestroyOneFragment();
	void DestroyInstance();
	bool CheckFragmentOverlap(int FragmentIndex);
};


// Class Creative.CreativePhotonHierarchicalInstancedDestructibleMeshComponent
// 0x00D0 (0x0FD0 - 0x0F00)
class UCreativePhotonHierarchicalInstancedDestructibleMeshComponent : public UPhotonHierarchicalInstancedDestructibleMeshComponent
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0F00(0x0008) MISSED OFFSET
	struct FString                                     MinClusterInstanceID;                                     // 0x0F08(0x0010) (ZeroConstructor)
	TArray<uint32_t>                                   InstanceReplicationIndex;                                 // 0x0F18(0x0010) (ZeroConstructor)
	TMap<int, struct FPhotonDestructionParam>          InstanceToDestructionParams;                              // 0x0F28(0x0050) (ZeroConstructor)
	TMap<struct FString, int>                          UGCInstanceIDToInstanceIndex;                             // 0x0F78(0x0050) (ZeroConstructor)
	int                                                MaxFXFragmentNumber;                                      // 0x0FC8(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0FCC(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativePhotonHierarchicalInstancedDestructibleMeshComponent");
		return pStaticClass;
	}


	void SetServerDamagedInstancedDelegate(const struct FScriptDelegate& InDelegate);
	void SetInstanceMaxHp(int InstanceIndex, float MaxHP);
	void SetInstanceActive(const struct FString& InstanceID, bool bActive);
	void SetDestructionParam(TArray<int> InstanceIndex, TArray<struct FPhotonDestructionParam> DestructionParams);
	bool RebornOneFragment(const struct FString& InstanceID, int FragmentIndex);
	bool RebornInstance(const struct FString& InstanceID);
	bool RandomRecoverOneFragment(const struct FString& InstanceID);
	void RandomDestroyOneFragment(const struct FString& InstanceID);
	void OnClientInitial(int InstanceIndex, TArray<int> ImpactFragmentItemIndex);
	void OnClientDamaged(int InstanceIndex, TArray<int> ImpactFragmentItemIndex, const struct FVector& LocalImpactPoint, const struct FVector& LocalVelocity, int HitType);
	struct FString GetUGCInstanceID(int InstanceIndex);
	void DestroyInstance(const struct FString& InstanceID);
	bool CheckFragmentOverlap(int InstanceIndex, int FragmentIndex);
};


// Class Creative.CreativePhotonInstancedDestructibleMeshComponent
// 0x00E0 (0x0F00 - 0x0E20)
class UCreativePhotonInstancedDestructibleMeshComponent : public UPhotonInstancedDestructibleMeshComponent
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0E20(0x0010) MISSED OFFSET
	struct FString                                     MinClusterInstanceID;                                     // 0x0E30(0x0010) (ZeroConstructor)
	TArray<uint32_t>                                   InstanceReplicationIndex;                                 // 0x0E40(0x0010) (ZeroConstructor)
	TMap<int, struct FPhotonDestructionParam>          InstanceToDestructionParams;                              // 0x0E50(0x0050) (ZeroConstructor)
	TMap<struct FString, int>                          UGCInstanceIDToInstanceIndex;                             // 0x0EA0(0x0050) (ZeroConstructor)
	int                                                MaxFXFragmentNumber;                                      // 0x0EF0(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0xC];                                       // 0x0EF4(0x000C) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativePhotonInstancedDestructibleMeshComponent");
		return pStaticClass;
	}


	void SetServerDamagedInstancedDelegate(const struct FScriptDelegate& InDelegate);
	void SetInstanceMaxHp(int InstanceIndex, float MaxHP);
	void SetInstanceActive(const struct FString& InstanceID, bool bActive);
	void SetDestructionParam(TArray<int> InstanceIndex, TArray<struct FPhotonDestructionParam> DestructionParams);
	bool RebornOneFragment(const struct FString& InstanceID, int FragmentIndex);
	bool RebornInstance(const struct FString& InstanceID);
	bool RandomRecoverOneFragment(const struct FString& InstanceID);
	void RandomDestroyOneFragment(const struct FString& InstanceID);
	void OnClientInitial(int InstanceIndex, TArray<int> ImpactFragmentItemIndex);
	void OnClientDamaged(int InstanceIndex, TArray<int> ImpactFragmentItemIndex, const struct FVector& LocalImpactPoint, const struct FVector& LocalVelocity, int HitType);
	struct FString GetUGCInstanceID(int InstanceIndex);
	void DestroyInstance(const struct FString& InstanceID);
	bool CheckFragmentOverlap(int InstanceIndex, int FragmentIndex);
};


// Class Creative.CreativePhysicsBatchActor
// 0x0150 (0x0648 - 0x04F8)
class ACreativePhysicsBatchActor : public ALuaActor
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x04F8(0x0010) MISSED OFFSET
	TMap<struct FString, class UCreativePhysicsComponent*> InstancePhysicsComponentMap;                              // 0x0508(0x0050) (ExportObject, ZeroConstructor)
	unsigned char                                      UnknownData01[0x6C];                                      // 0x0558(0x006C) MISSED OFFSET
	int                                                TickRegisterMaxNum;                                       // 0x05C4(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FScriptDelegate                             MeshLoadSuccessDelegate;                                  // 0x05C8(0x0010) (ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             MeshLoadSuccessByPathDelegate;                            // 0x05D8(0x0010) (ZeroConstructor, InstancedReference)
	TMap<struct FString, struct FPhysicsComponentData> ComponentTempData;                                        // 0x05E8(0x0050) (ZeroConstructor)
	int                                                ReplicateLimit;                                           // 0x0638(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0xC];                                       // 0x063C(0x000C) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativePhysicsBatchActor");
		return pStaticClass;
	}


	void UpdatePhysicsComponentMaterial(struct FString* ComponentID, struct FString* MaterialPath);
	void UpdatePhysicsComponent(const struct FTransform& Transform, TEnumAsByte<ECollisionEnabled> CollisionEnabled, struct FString* ComponentID);
	bool UnRegisterPhysicsComponent(struct FString* ComponentID);
	void SetPhysicsComponentEnabled(TEnumAsByte<ECollisionEnabled> CollisionEnabled, struct FString* ComponentID);
	void RegisterPhysicsComponentByMesh(const struct FString& InstanceID, const struct FString& ComponentID, const struct FTransform& Transform, const struct FString& MeshPath, const struct FName& CollisionProfileName);
	void OnLoadMeshSuccessByPath(class UObject* Obj, const struct FString& ComponentID);
	void OnLoadMeshSuccess(class UObject* Obj, const struct FString& ComponentID);
	bool IsLoadFinish();
	int GetRegisterNum();
	class UCreativePhysicsComponent* GetPhysicsComponent(struct FString* ComponentID);
	void ClearAllPhysicsComponent();
};


// Class Creative.CreativePhysicsComponent
// 0x0070 (0x08E0 - 0x0870)
class UCreativePhysicsComponent : public UMeshComponent
{
public:
	class UBodySetup*                                  BodySetup;                                                // 0x0870(0x0008) (ZeroConstructor, IsPlainOldData)
	class UStaticMesh*                                 InStaticMesh;                                             // 0x0878(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FString                                     InstanceID;                                               // 0x0880(0x0010) (ZeroConstructor)
	struct FName                                       CollisionProfileName;                                     // 0x0890(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x30];                                      // 0x0898(0x0030) MISSED OFFSET
	struct FScriptDelegate                             MatLoadSuccessDelegate;                                   // 0x08C8(0x0010) (ZeroConstructor, InstancedReference)
	unsigned char                                      UnknownData01[0x8];                                       // 0x08D8(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativePhysicsComponent");
		return pStaticClass;
	}


	void SetIsReplicatedOnly(bool ShouldReplicate);
	void OnLoadMaterialSuccess(class UObject* Obj, const struct FString& Path);
};


// Class Creative.CreativePhysicsManager
// 0x01F8 (0x0300 - 0x0108)
class UCreativePhysicsManager : public UCreativeModeManagerBase
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x0108(0x0018) MISSED OFFSET
	TMap<struct FString, class UBodySetup*>            BodySetupMap;                                             // 0x0120(0x0050) (ZeroConstructor, Transient)
	TMap<struct FString, class UMaterialInterface*>    MaterialInterfaceMap;                                     // 0x0170(0x0050) (ZeroConstructor, Transient)
	TMap<struct FString, struct FCreativeInstanceGridCellInfo> InstanceCellMap;                                          // 0x01C0(0x0050) (ZeroConstructor, Transient)
	TMap<int, class ACreativePhysicsBatchActor*>       PhysicsBatchActorMap;                                     // 0x0210(0x0050) (ZeroConstructor, Transient)
	bool                                               StreamingEnable;                                          // 0x0260(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0261(0x0007) MISSED OFFSET
	TMap<struct FIntVector, bool>                      VisiblePhysicsBatchActors;                                // 0x0268(0x0050) (ZeroConstructor)
	unsigned char                                      UnknownData02[0x38];                                      // 0x02B8(0x0038) MISSED OFFSET
	TArray<class ACreativePhysicsBatchActor*>          OutAllBatchActorArray;                                    // 0x02F0(0x0010) (ZeroConstructor)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativePhysicsManager");
		return pStaticClass;
	}


	void UpdatePhysicsObjectCellInfo(const struct FString& InstanceID, const struct FString& GridName, const struct FIntVector& CellIndex);
	void SetStreamingEnable(bool Enable);
	void SetPhysicsActorVisible(const struct FString& GridName, const struct FIntVector& CellIndex, bool Visible);
	void RemovePhysicsObject(const struct FString& InstanceID);
	bool PreAddPhysicsObjectCheck(const struct FString& InstanceID);
	void OnPhysicsBatchActorLoadFinish();
	bool IsPhysicsActorVisible(const struct FString& GridName, const struct FIntVector& CellIndex);
	class ACreativePhysicsBatchActor* GetPhysicsBatchActorByInstanceID(const struct FString& InstanceID);
	class ACreativePhysicsBatchActor* GetPhysicsBatchActor(const struct FString& GridName, const struct FIntVector& Index);
	class ACreativePhysicsBatchActor* GetGlobalPhysicsBatchActor();
	TArray<class ACreativePhysicsBatchActor*> GetAllPhysicsActor();
	static class UCreativePhysicsManager* Get(class UObject* WorldContext);
	void ClearAllPhysicsBatchActor();
	void ChangePhysicsObjectIsPrefab(const struct FString& InstanceID, bool bIsPrefab);
	void AddPhysicsObject(const struct FString& InstanceID, const struct FString& GridName, const struct FIntVector& CellIndex);
};


// Class Creative.CreativePlayerAPIObject
// 0x0000 (0x0188 - 0x0188)
class UCreativePlayerAPIObject : public UCreativeApiObject
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativePlayerAPIObject");
		return pStaticClass;
	}


	bool SetPlayerDirection(int64_t PlayerUUID, const struct FVector& Direction);
	int GetPlayerTeamIndex(int64_t PlayerUUID);
	void GetPlayerTeamIDAndTeamIndexFromCPP(int64_t PlayerUUID, int* OutTeamID, int* OutTeamIndex);
	int GetPlayerTeamID(int64_t PlayerUUID);
	float GetPlayerMaxHealth(int64_t PlayerUUID);
	struct FVector GetPlayerLocation(int64_t PlayerUUID);
	float GetPlayerHealth(int64_t PlayerUUID);
	struct FVector GetPlayerDirection(int64_t PlayerUUID);
	float AddPlayerHealth(int64_t PlayerUUID, float AddHealth);
};


// Class Creative.CreativeModePlayerState
// 0x0008 (0x1C00 - 0x1BF8)
class ACreativeModePlayerState : public ASTExtraPlayerState
{
public:
	bool                                               bEnableAutoPickUp;                                        // 0x1BF8(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x1BF9(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModePlayerState");
		return pStaticClass;
	}


	void ServerRemoveInstance(const struct FString& InstanceID);
	TArray<unsigned char> ServerReceiveModifyContent(TArray<unsigned char> Content, int idx);
	void ServerAddInstanceAdvance(const struct FString& InstanceID, TArray<unsigned char> Content, int idx);
	void ServerAddInstance(const struct FString& InstanceID, TArray<unsigned char> Content);
};


// Class Creative.CreativePoolInterface
// 0x0000 (0x0028 - 0x0028)
class UCreativePoolInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativePoolInterface");
		return pStaticClass;
	}


	void SetRecycleTime(float RecycleTime);
	void SetIsRecycled(bool IsRecycled);
	void ReceiveOnReturnToPool(class UObject* NewOuter, int RecycledSeq);
	void ReceiveOnPickFromPool(class UObject* NewOuter, const struct FString& InName);
	bool OnReturnToPool(class UObject* NewOuter, uint32_t RecycledSeq);
	void OnPickFromPool(class UObject* NewOuter, const struct FString& InName);
	struct FString GetUnusedComponentName(class UObject* InOuter, struct FString* NamePrefix);
	float GetRecycleTime();
	bool CheckIsRecycled();
};


// Class Creative.CreativePoolManager
// 0x0060 (0x0168 - 0x0108)
class UCreativePoolManager : public UCreativeModeManagerBase
{
public:
	bool                                               bPoolManagerEnable;                                       // 0x0108(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0xF];                                       // 0x0109(0x000F) MISSED OFFSET
	TMap<int, struct FCreativeObjectPool>              CreativePools;                                            // 0x0118(0x0050) (ZeroConstructor, Transient)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativePoolManager");
		return pStaticClass;
	}


	void SetPoolManagerEnable(bool bPoolManagerEnable);
	void ReturnObject(int PoolId, class UObject* Obj);
	void OnReceivePickObjectHandle(int ID, class UObject* InObj);
	void OnReceiveObjectReturnHandle(int ID, class UObject* InObj);
	bool OnReceiveDestroyHandle(int ID, class UObject* InObj);
	class UObject* OnReceiveCreateHandle(int ID);
	bool InitPool(int PoolId, bool bPoolEnable, struct FCreativeObjectPoolClassConfig* PoolConfig);
	struct FString GetUnusedComponentName(class UObject* InOuter, struct FString* NamePrefix);
	class UObject* GetObject(int PoolId, class UObject* NewOuter, const struct FString& InName);
	static class UCreativePoolManager* Get(class UObject* WorldContext);
	void ClearPoolObject();
};


// Class Creative.CreativeModeRaceCheckPointComponent
// 0x0000 (0x01D8 - 0x01D8)
class UCreativeModeRaceCheckPointComponent : public ULuaActorComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeRaceCheckPointComponent");
		return pStaticClass;
	}

};


// Class Creative.CreativeModeRaceCheckPointLiteComponent
// 0x0000 (0x0158 - 0x0158)
class UCreativeModeRaceCheckPointLiteComponent : public UCreativeModeLiteComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeRaceCheckPointLiteComponent");
		return pStaticClass;
	}

};


// Class Creative.CreativeRuntimePlayerBattleDataObject
// 0x0300 (0x07F8 - 0x04F8)
class ACreativeRuntimePlayerBattleDataObject : public ALuaActor
{
public:
	struct FRuntimePlayerBattleDataInfo                DefaultPlayerBattleDataInfo;                              // 0x04F8(0x0068)
	struct FRuntimeTeamGameOutcomeConditionInfo        DefaultTeamGameOutcomeCondition;                          // 0x0560(0x001C)
	unsigned char                                      UnknownData00[0x4];                                       // 0x057C(0x0004) MISSED OFFSET
	struct FRuntimeCacheRoundBattleDataInfoContainer   RuntimeOldCacheRoundBattleDataContainer;                  // 0x0580(0x00C8) (Net, Transient)
	struct FRuntimeBattleDataInfoContainer             RuntimeCurRoundBattleDataInfoContainer;                   // 0x0648(0x00C8) (Net, Transient)
	struct FRuntimeTeamGameOutcomeConditionContainer   RuntimeTeamGameOutcomeConditionContainer;                 // 0x0710(0x00C8) (Net, Transient)
	struct FRuntimeCacheRoundBattleDataInfo            DefaultCacheRoundBattleDataInfo;                          // 0x07D8(0x0020)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeRuntimePlayerBattleDataObject");
		return pStaticClass;
	}


	bool SetTeamGameOutcomeCondition(int TeamID, bool bPropagateToChildren, struct FRuntimeTeamGameOutcomeConditionInfo* TeamGameOutcomeCondition);
	bool SetPlayerBattleData(uint64_t UID, uint32_t PlayerKey, bool bPropagateToChildren, struct FRuntimePlayerBattleDataInfo* PlayerBattleData);
	bool ResetCurRoundPlayerBattleDataList();
	void OnRepTeamGameOutcomeConditionInfo(int TeamID);
	void OnRepCurRoundPlayerBattleDataInfo(uint64_t PlayerUID, uint64_t PlayerKey, int ChangeTeamID);
	struct FRuntimeTeamGameOutcomeConditionInfo GetTeamGameOutcomeCondition(int TeamID);
	struct FRuntimePlayerBattleDataInfo GetCurRoundPlayerBattleData(uint64_t PlayerUID, uint32_t PlayerKey);
	TArray<struct FRuntimePlayerBattleDataInfo> GetCurRoundAllPlayerBattleData();
	struct FRuntimePlayerBattleDataInfo GetCacheRoundPlayerBattleData(int RoundIndex, uint64_t PlayerUID, uint32_t PlayerKey);
	struct FRuntimeCacheRoundBattleDataInfo GetCacheRoundBattleData(int RoundIndex);
	struct FRuntimePlayerBattleDataInfo GetAllRoundPlayerBattleData(uint64_t PlayerUID, uint32_t PlayerKey);
	void CacheCurRoundBattleData(int RoundIndex);
};


// Class Creative.CreativeSceneQueryManager
// 0x0118 (0x0220 - 0x0108)
class UCreativeSceneQueryManager : public UCreativeModeManagerBase
{
public:
	struct FCreativeReplicatedDataContainer            ReplicatedDataContainer;                                  // 0x0108(0x00C8) (Net, Transient)
	TMap<struct FString, struct FCreativeReplicatedObjectsInfo> MapReplicatedObjects;                                     // 0x01D0(0x0050) (ZeroConstructor, Transient)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeSceneQueryManager");
		return pStaticClass;
	}


	void RemoveReplicateObject(const struct FString& InstanceID, class UObject* Object);
	void RemoveReplicateData(const struct FString& InstanceID);
	void OnReceivePreReplicateDataRemove(const struct FString& ID);
	void OnReceivePostReplicateDataChange(const struct FString& ID, TArray<class UObject*> Objects);
	void OnReceivePostReplicateDataAdd(const struct FString& ID, TArray<class UObject*> Objects);
	TArray<class UObject*> GetReplicatedObjects(const struct FString& InstanceID);
	static class UCreativeSceneQueryManager* Get(class UObject* WorldContext);
	void AddReplicateObjectPostDeferred(const struct FString& InstanceID, const struct FTransform& SpawnTransform, class UObject* ReplicatedObject);
	class UObject* AddReplicateObjectDeferred(const struct FString& InstanceID, class UClass* ObjectClass, const struct FString& Name, const struct FTransform& SpawnTransform, ESpawnActorCollisionHandlingMethod CollisionHandlingOverride);
	class UObject* AddReplicateObject(const struct FString& InstanceID, class UClass* ObjectClass, const struct FString& Name, const struct FTransform& SpawnTransform, ESpawnActorCollisionHandlingMethod CollisionHandlingOverride);
};


// Class Creative.CreativeScreenCaptureWidget
// 0x0010 (0x02D8 - 0x02C8)
class UCreativeScreenCaptureWidget : public ULuaUserWidget
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x02C8(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeScreenCaptureWidget");
		return pStaticClass;
	}


	void OnPanelInitialized();
};


// Class Creative.CreativeModeSoftComponentManager
// 0x0050 (0x0158 - 0x0108)
class UCreativeModeSoftComponentManager : public UCreativeModeManagerBase
{
public:
	unsigned char                                      UnknownData00[0x50];                                      // 0x0108(0x0050) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeModeSoftComponentManager");
		return pStaticClass;
	}


	static class UCreativeModeSoftComponentManager* Get(class UObject* WorldContext);
	void ClearAllLoading();
};


// Class Creative.SoftStaticMeshComponent
// 0x0060 (0x0A80 - 0x0A20)
class USoftStaticMeshComponent : public UStaticMeshComponent
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0A20(0x0008) MISSED OFFSET
	unsigned char                                      bOnlyRender : 1;                                          // 0x0A28(0x0001) (Edit)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0A29(0x0007) MISSED OFFSET
	unsigned char                                      UnknownData02[0x28];                                      // 0x0A29(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Creative.SoftStaticMeshComponent.SoftStaticMesh
	struct FSoftObjectPath                             SoftStaticMeshPath;                                       // 0x0A58(0x0018)
	unsigned char                                      bAsyncLoad : 1;                                           // 0x0A70(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      UnknownData03[0xF];                                       // 0x0A71(0x000F) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.SoftStaticMeshComponent");
		return pStaticClass;
	}


	bool SetSoftStaticMeshAsync(struct FString* NewMeshPath);
	bool SetSoftStaticMesh(class UStaticMesh* NewMesh, bool bSetStaticMesh);
	void SetComponentOnlyRender(bool bOnlyRender);
	void OnClientAsyncLoaded(const struct FSoftObjectPath& SoftObjectPath);
	void LoadSoftStaticMeshImmediately();
};


// Class Creative.CreativeSoftStaticMeshComponent
// 0x0010 (0x0A90 - 0x0A80)
class UCreativeSoftStaticMeshComponent : public USoftStaticMeshComponent
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0A80(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeSoftStaticMeshComponent");
		return pStaticClass;
	}


	bool OnReturnToPool(class UObject* NewOuter, uint32_t RecycledSeq);
	void OnPickFromPool(class UObject* NewOuter, const struct FString& InName);
};


// Class Creative.CreativeSpawnManager
// 0x0000 (0x0108 - 0x0108)
class UCreativeSpawnManager : public UCreativeModeManagerBase
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeSpawnManager");
		return pStaticClass;
	}


	class AActor* SpawnTower(int ConfigId, const struct FTransform& Transform, int TeamID, int Campid, int ParamsID);
	class AActor* SpawnHumanBot(int ConfigId, const struct FTransform& Transform, int TeamID, int Campid, int ParamsID);
	class AActor* SpawnAIPlayer(int ConfigId, const struct FTransform& Transform, int TeamID, int Campid, int ParamsID);
	void OnUnitSpawned(class AActor* NewUnit, ESpecType SpecType);
	void OnOwnedTowerDead(class ASTExtraBaseCharacter* DeadCharacter, class AController* Killer, class AActor* DamageCauser, const struct FHitResult& KillingHitInfo, const struct FVector& KillingHitImpulseDir, class UClass* KillingHitDamageType);
	void OnOwnedFakePlayerDead(class ASTExtraBaseCharacter* DeadCharacter, class AController* Killer, class AActor* DamageCauser, const struct FHitResult& KillingHitInfo, const struct FVector& KillingHitImpulseDir, class UClass* KillingHitDamageType);
	void OnOwnedAIPlayerDead(class ASTExtraBaseCharacter* DeadCharacter, class AController* Killer, class AActor* DamageCauser, const struct FHitResult& KillingHitInfo, const struct FVector& KillingHitImpulseDir, class UClass* KillingHitDamageType);
	void OnMonsterUnitDead(class ASTExtraSimpleCharacter* DeadCharacter, class AController* Killer, class AActor* DamageCauser, const struct FHitResult& KillingHitInfo, const struct FVector& KillingHitImpulseDir, class UClass* KillingHitDamageType);
	void OnDeadWithCategory(ESpecType Category, class APawn* DeadCharacter);
	static class UCreativeSpawnManager* Get(class UObject* WorldContext);
};


// Class Creative.CreativeStaticMeshComponent
// 0x0010 (0x0A30 - 0x0A20)
class UCreativeStaticMeshComponent : public UStaticMeshComponent
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0A20(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeStaticMeshComponent");
		return pStaticClass;
	}


	bool OnReturnToPool(class UObject* NewOuter, uint32_t RecycledSeq);
	void OnPickFromPool(class UObject* NewOuter, const struct FString& InName);
};


// Class Creative.CreativeStreamingManager
// 0x0218 (0x0320 - 0x0108)
class UCreativeStreamingManager : public UCreativeModeManagerBase
{
public:
	bool                                               bStreamingManagerEnable;                                  // 0x0108(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bStreamingStateCheckStartup;                              // 0x0109(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bUseChildThreads;                                         // 0x010A(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x010B(0x0001) MISSED OFFSET
	float                                              StreamingTickFrequency;                                   // 0x010C(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              DestroyExtendDistance;                                    // 0x0110(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              DelayDestroyTime;                                         // 0x0114(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              NeedTickStreamingDistanceScale;                           // 0x0118(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               ChildThreadsReduceTickFrequency;                          // 0x011C(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2B];                                      // 0x011D(0x002B) MISSED OFFSET
	TMap<struct FString, struct FCreativeModeStreamingParameters> ObjectStreamingStateMap;                                  // 0x0148(0x0050) (ZeroConstructor, Transient)
	TArray<struct FString>                             ObjectStreamingStateKeyList;                              // 0x0198(0x0010) (ZeroConstructor, Transient)
	TMap<struct FString, bool>                         ObjectSpawnStateChangeMaps;                               // 0x01A8(0x0050) (ZeroConstructor, Transient)
	unsigned char                                      UnknownData02[0x50];                                      // 0x01F8(0x0050) MISSED OFFSET
	TArray<TWeakObjectPtr<class AActor>>               OuterStreamingSources;                                    // 0x0248(0x0010) (ZeroConstructor, Transient)
	unsigned char                                      UnknownData03[0xC8];                                      // 0x0258(0x00C8) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeStreamingManager");
		return pStaticClass;
	}


	void UnregisterStreamingSource(class AActor* Source);
	bool StreamingManagerEnable();
	bool RemoveStreamingObject(const struct FString& InstanceID);
	void RegisterStreamingSource(class AActor* Source);
	struct FIntVector GetOnGridCellIndex(const struct FString& GridName, const struct FVector& Location);
	float GetGridLoadingRange(const struct FString& GridName);
	TArray<struct FString> GetGridList();
	struct FVector2D GetGridCellWidthHeight(const struct FString& GridName);
	TArray<struct FVector> GetCreativeModeStreamingSourceList();
	static class UCreativeStreamingManager* Get(class UObject* WorldContext);
	ECreativeModeActorStreamingType ChangeStreamingObjectStreamingType(const struct FString& InstanceID, ECreativeModeActorStreamingType NewStremaingType);
	bool AddStreamingObject(const struct FString& InstanceID, const struct FCreativeModeStreamingParameters& StreamingParameters);
};


// Class Creative.CreativeTimerApiObject
// 0x0050 (0x01D8 - 0x0188)
class UCreativeTimerApiObject : public UCreativeApiObject
{
public:
	unsigned char                                      UnknownData00[0x50];                                      // 0x0188(0x0050) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeTimerApiObject");
		return pStaticClass;
	}


	void Clear();
};


// Class Creative.CreativeTriggerAreaActor
// 0x0070 (0x0568 - 0x04F8)
class ACreativeTriggerAreaActor : public ALuaActor
{
public:
	unsigned char                                      UnknownData00[0x70];                                      // 0x04F8(0x0070) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeTriggerAreaActor");
		return pStaticClass;
	}


	void OnTakeDamage(class AActor* DamageCauser);
};


// Class Creative.CreativeWebSocketManager
// 0x0030 (0x0138 - 0x0108)
class UCreativeWebSocketManager : public USTExtraManagerBase
{
public:
	TArray<struct FString>                             SendList;                                                 // 0x0108(0x0010) (ZeroConstructor)
	TArray<struct FString>                             ReceivedList;                                             // 0x0118(0x0010) (ZeroConstructor)
	float                                              LastTickSeconds;                                          // 0x0128(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              MessageTickFrequency;                                     // 0x012C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FTimerHandle                                TickTimerHandle;                                          // 0x0130(0x0008)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeWebSocketManager");
		return pStaticClass;
	}


	void SendMessage(const struct FString& Message);
	void ReceiveOnPostSetLuaEventBridgeInstance();
	void OnTickTimer();
	void OnReceiveConnected();
	void OnPostSetLuaEventBridgeInstance();
	bool OnMessageSent(const struct FString& Message);
	bool OnMessageReceived(const struct FString& Message);
	bool IsConnected();
	static class UCreativeWebSocketManager* Get(class UObject* WorldContext);
	void ConnectServer(const struct FString& ServerURL, const struct FString& ServerProtocol);
};


// Class Creative.CreativeWidgetComponent
// 0x0000 (0x09E0 - 0x09E0)
class UCreativeWidgetComponent : public UWidgetComponent
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeWidgetComponent");
		return pStaticClass;
	}

};


// Class Creative.CreativeWidgetObject
// 0x0168 (0x0190 - 0x0028)
class UCreativeWidgetObject : public UObject
{
public:
	unsigned char                                      UnknownData00[0xF0];                                      // 0x0028(0x00F0) MISSED OFFSET
	struct FString                                     LuaFilePath;                                              // 0x0118(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0128(0x0008) MISSED OFFSET
	TMap<class UObject*, struct FCreativePoolObjectRecordInfo> PoolObjectRecordMap;                                      // 0x0130(0x0050) (ZeroConstructor)
	TArray<class ULiteComponent*>                      LiteComponents;                                           // 0x0180(0x0010) (ZeroConstructor, Transient)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeWidgetObject");
		return pStaticClass;
	}


	void UnregisterLiteComponent(class ULiteComponent* Component, bool Destroy);
	void ReturnObjectToPool(class UObject* Obj);
	void ReturnObjectsToPool(TArray<class UObject*> Objs);
	void RegisterLiteComponent(class ULiteComponent* Component);
	void ReceivePostBeginPlay();
	bool ReceiveIsDedicatedServer();
	bool ReceiveHasAuthority();
	void ReceiveEndPlay();
	void ReceiveBeginPlay();
	TArray<class UObject*> GetObjectsFromPool(TArray<struct FCreativePoolGetObjectParamInfo>* ObjectParams);
	class UObject* GetObjectFromPool(int PoolId, class UObject* NewOuter, struct FString* InName);
};


// Class Creative.CreativeWorldSubSystem
// 0x0008 (0x0038 - 0x0030)
class UCreativeWorldSubSystem : public UWorldSubsystem
{
public:
	class AActor*                                      ManagerCenter;                                            // 0x0030(0x0008) (ZeroConstructor, Transient, IsPlainOldData)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeWorldSubSystem");
		return pStaticClass;
	}


	class AActor* GetManagerCenter();
};


// Class Creative.CreativeWoWInactiveCheckComponent
// 0x0038 (0x0210 - 0x01D8)
class UCreativeWoWInactiveCheckComponent : public ULuaActorComponent
{
public:
	float                                              InactivePlayerKickoutTime;                                // 0x01D8(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              InactiveCheckGap;                                         // 0x01DC(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              InactiveTimeForTipPreTime;                                // 0x01E0(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              PreActiveTime;                                            // 0x01E4(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              ClientSendActiveRPCGap;                                   // 0x01E8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bIsClientActive;                                          // 0x01EC(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	ESCWOWActiveType                                   CWOWActiveType;                                           // 0x01ED(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x01EE(0x0002) MISSED OFFSET
	struct FVector                                     PrePawnLoc;                                               // 0x01F0(0x000C) (BlueprintVisible, IsPlainOldData)
	struct FRotator                                    PreControllerRotation;                                    // 0x01FC(0x000C) (BlueprintVisible, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0208(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeWoWInactiveCheckComponent");
		return pStaticClass;
	}


	void ServerMarkPlayerActive();
	void MarkPlayerActive();
	void KickOutPlayer();
	void ClientShowKickOutTip(float RemainTime);
	void ClientCachedActiveState();
	bool CheckForMovement();
	void CheckForInactive();
};


// Class Creative.CreativeWoWManager
// 0x0008 (0x0110 - 0x0108)
class UCreativeWoWManager : public UCreativeModeManagerBase
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0108(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.CreativeWoWManager");
		return pStaticClass;
	}


	void ReceiveOnGameStateBeginPlay(class AGameStateBase* GameState);
	void OnGameStateBeginPlay(class AGameStateBase* GameState);
	static class UCreativeWoWManager* Get(class UObject* WorldContext);
};


// Class Creative.DancerDeviceActor
// 0x0018 (0x0510 - 0x04F8)
class ADancerDeviceActor : public ALuaActor
{
public:
	class APawn*                                       SyncPlayerCharacter;                                      // 0x04F8(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	TArray<int>                                        TempAvatarItemIDList;                                     // 0x0500(0x0010) (ZeroConstructor)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.DancerDeviceActor");
		return pStaticClass;
	}


	void OnRep_SyncPlayerCharacter();
};


// Class Creative.GameModeStateActive_CreativeMode
// 0x0000 (0x00C0 - 0x00C0)
class UGameModeStateActive_CreativeMode : public UGameModeStateActive
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.GameModeStateActive_CreativeMode");
		return pStaticClass;
	}

};


// Class Creative.GameModeStateFighting_CreativeMode
// 0x0000 (0x00D0 - 0x00D0)
class UGameModeStateFighting_CreativeMode : public UGameModeStateFightingTeam
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.GameModeStateFighting_CreativeMode");
		return pStaticClass;
	}


	void SetToInfinityTime();
	void PlayersInfoRecord();
};


// Class Creative.GameModeStateFinished_CreativeMode
// 0x0000 (0x00B8 - 0x00B8)
class UGameModeStateFinished_CreativeMode : public UGameModeStateFinishedTeam
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.GameModeStateFinished_CreativeMode");
		return pStaticClass;
	}

};


// Class Creative.GameModeStateReady_CreativeMode
// 0x0000 (0x0108 - 0x0108)
class UGameModeStateReady_CreativeMode : public UGameModeStateReady
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.GameModeStateReady_CreativeMode");
		return pStaticClass;
	}

};


// Class Creative.GameProcessEventObject
// 0x0000 (0x00F0 - 0x00F0)
class UGameProcessEventObject : public UCreativeEventObject
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.GameProcessEventObject");
		return pStaticClass;
	}


	void ReceivePostEvent(int ProcessType, int Round);
	void OnEnterPlayProcess();
};


// Class Creative.PlayerListenerEventObject
// 0x0008 (0x00F8 - 0x00F0)
class UPlayerListenerEventObject : public UCreativeEventObject
{
public:
	bool                                               bCppListenerEnable;                                       // 0x00F0(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x00F1(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.PlayerListenerEventObject");
		return pStaticClass;
	}


	void OnCppRemovePlayerListener(class UObject* Content, uint32_t PlayerKey);
	void OnCppAddPlayerListener(class UObject* Content, uint32_t PlayerKey);
};


// Class Creative.PlayerAttachedToVehicleEventObject
// 0x0050 (0x0148 - 0x00F8)
class UPlayerAttachedToVehicleEventObject : public UPlayerListenerEventObject
{
public:
	TMap<uint32_t, class UPlayerAttachedProxy*>        LambdaDelegateMap;                                        // 0x00F8(0x0050) (ZeroConstructor)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.PlayerAttachedToVehicleEventObject");
		return pStaticClass;
	}


	void OnOwnerAttachedToVehicle(class ASTExtraVehicleBase* InVehicle, uint32_t PlayerKey);
	void OnCppRemovePlayerListener(class UObject* Content, uint32_t PlayerKey);
	void OnCppAddPlayerListener(class UObject* Content, uint32_t PlayerKey);
};


// Class Creative.PlayerAttachedProxy
// 0x0018 (0x0040 - 0x0028)
class UPlayerAttachedProxy : public UObject
{
public:
	uint32_t                                           PlayerKey;                                                // 0x0028(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x002C(0x0004) MISSED OFFSET
	class UPlayerAttachedToVehicleEventObject*         Owner;                                                    // 0x0030(0x0008) (ZeroConstructor, IsPlainOldData)
	class ASTExtraBaseCharacter*                       PlayerCharacter;                                          // 0x0038(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.PlayerAttachedProxy");
		return pStaticClass;
	}


	void OnProxyAttachedToVehicle(class ASTExtraVehicleBase* InVehicle);
};


// Class Creative.ShowAllPlayerManagerActor
// 0x00B0 (0x05A8 - 0x04F8)
class AShowAllPlayerManagerActor : public ALuaActor
{
public:
	int                                                MapMarkID;                                                // 0x04F8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bEnableRefresh;                                           // 0x04FC(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x04FD(0x0003) MISSED OFFSET
	int                                                BatchNum;                                                 // 0x0500(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                CurBatchID;                                               // 0x0504(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	int                                                CurBatchNum;                                              // 0x0508(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x24];                                      // 0x050C(0x0024) MISSED OFFSET
	TArray<struct FVector_NetQuantize>                 TeamPosData;                                              // 0x0530(0x0010) (Net, ZeroConstructor)
	unsigned char                                      UnknownData02[0x50];                                      // 0x0540(0x0050) UNKNOWN PROPERTY: SetProperty Creative.ShowAllPlayerManagerActor.TriggerPlayerKeySet
	TArray<struct FMarkDispatchAction>                 MapMarkActionList;                                        // 0x0590(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData03[0x8];                                       // 0x05A0(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class Creative.ShowAllPlayerManagerActor");
		return pStaticClass;
	}


	void TriggerRefresh(class ASTExtraBaseCharacter* Character, bool bEnable);
	void RefreshTeamPoseData();
	void RefreshMapMarkData();
	void OnTeamPosDataChange();
	void OnRep_TeamPosData();
	bool IsCharacterValidForShow(class ASTExtraBaseCharacter* Character);
	void FlushBatchData(int BatchSize, int CurExtraSize);
	void EnableRefresh(bool bEnable);
	void ClearAllMark();
};


}

