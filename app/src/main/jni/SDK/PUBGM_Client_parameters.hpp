#pragma once

// SDKGen by @xninjaleaks | @talhaeens 
// Send message for SDKGen and Offset Finder Tool

#include "../SDK.hpp"

namespace SDK
{
//---------------------------------------------------------------------------
//Parameters
//---------------------------------------------------------------------------

// Function Client.AsyncLoadHelper.SetMaxTaskNum
struct UAsyncLoadHelper_SetMaxTaskNum_Params
{
	int                                                Num;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.AsyncLoadHelper.RunNextTask
struct UAsyncLoadHelper_RunNextTask_Params
{
};

// Function Client.AsyncLoadHelper.OnLoadCallBack
struct UAsyncLoadHelper_OnLoadCallBack_Params
{
	struct FSoftObjectPath                             softObjPath;                                              // (Parm)
};

// Function Client.AsyncLoadHelper.ClearOneTask
struct UAsyncLoadHelper_ClearOneTask_Params
{
	struct FString                                     ObjectPath;                                               // (Parm, ZeroConstructor)
};

// Function Client.AsyncLoadHelper.ClearAllTask
struct UAsyncLoadHelper_ClearAllTask_Params
{
};

// Function Client.AsyncLoadHelper.AddTask
struct UAsyncLoadHelper_AddTask_Params
{
	struct FString                                     ObjectPath;                                               // (Parm, ZeroConstructor)
	int                                                LoadPriority;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.AsyncLoadWidgetBlueprint.Cancel
struct UAsyncLoadWidgetBlueprint_Cancel_Params
{
};

// Function Client.AsyncLoadWidgetBlueprint.AsyncLoadWidgetBlueprint
struct UAsyncLoadWidgetBlueprint_AsyncLoadWidgetBlueprint_Params
{
	struct FString                                     BlueprintPath;                                            // (Parm, ZeroConstructor)
	int                                                Priority;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	class UAsyncLoadWidgetBlueprint*                   ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.AsyncLoadWidgetBlueprint.AfterLoadCallback
struct UAsyncLoadWidgetBlueprint_AfterLoadCallback_Params
{
	struct FSoftObjectPath                             SoftObjectPath;                                           // (Parm, OutParm)
};

// Function Client.AsyncLoadWidgetBlueprint.Activate
struct UAsyncLoadWidgetBlueprint_Activate_Params
{
};

// Function Client.AsyncTaskCDNDownloader.DownloadCDNContent
struct UAsyncTaskCDNDownloader_DownloadCDNContent_Params
{
	struct FString                                     URL;                                                      // (ConstParm, Parm, ZeroConstructor)
	int                                                loaderType;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     savedDir;                                                 // (ConstParm, Parm, ZeroConstructor)
	bool                                               breakpointContinualTransfer;                              // (Parm, ZeroConstructor, IsPlainOldData)
	class UAsyncTaskCDNDownloader*                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.AsyncTaskDownloader.DownloadContent
struct UAsyncTaskDownloader_DownloadContent_Params
{
	struct FString                                     URL;                                                      // (ConstParm, Parm, ZeroConstructor)
	int                                                loaderType;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     savedDir;                                                 // (ConstParm, Parm, ZeroConstructor)
	bool                                               breakpointContinualTransfer;                              // (Parm, ZeroConstructor, IsPlainOldData)
	class UAsyncTaskDownloader*                        ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BattleScriptHelper.SyncNewBattlePlayer
struct UBattleScriptHelper_SyncNewBattlePlayer_Params
{
	class UBattleUtils*                                Utils;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	uint64_t                                           UID;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FPlayerInfoData                             Info;                                                     // (ConstParm, Parm, OutParm, ReferenceParm)
	uint32_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BattleScriptHelper.SyncGameInfo
struct UBattleScriptHelper_SyncGameInfo_Params
{
	class UBattleUtils*                                Utils;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FBattleGameInfo                             Info;                                                     // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.BattleScriptHelper.SyncGameExit
struct UBattleScriptHelper_SyncGameExit_Params
{
	class UBattleUtils*                                Utils;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.BattleScriptHelper.SyncBattlePlayerExit
struct UBattleScriptHelper_SyncBattlePlayerExit_Params
{
	class UBattleUtils*                                Utils;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	uint64_t                                           UID;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FName                                       PlayerType;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Reason;                                                   // (Parm, ZeroConstructor)
};

// Function Client.BattleScriptHelper.ResponPlayerWeaponDIYData
struct UBattleScriptHelper_ResponPlayerWeaponDIYData_Params
{
	class UBattleUtils*                                Utils;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	uint64_t                                           PlayerUID;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FWeaponDIYData                              InWeaponDIYData;                                          // (Parm)
};

// Function Client.BattleScriptHelper.GenerateAIPlayerParams
struct UBattleScriptHelper_GenerateAIPlayerParams_Params
{
	class UBattleUtils*                                Utils;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FPlayerInfoData                             Info;                                                     // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.BattlePlayer.ExtractGameModePlayerParams
struct UBattlePlayer_ExtractGameModePlayerParams_Params
{
	struct FGameModePlayerParams                       ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function Client.BattleAIPlayer.ExtractGameModeAIPlayerParams
struct UBattleAIPlayer_ExtractGameModeAIPlayerParams_Params
{
	struct FGameModeAIPlayerParams                     ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function Client.BattleUtils.SyncNewBattlePlayer
struct UBattleUtils_SyncNewBattlePlayer_Params
{
	uint64_t                                           UID;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FPlayerInfoData                             Info;                                                     // (ConstParm, Parm, OutParm, ReferenceParm)
	uint32_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BattleUtils.SyncGameInfo
struct UBattleUtils_SyncGameInfo_Params
{
	struct FBattleGameInfo                             Info;                                                     // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.BattleUtils.SyncGameExit
struct UBattleUtils_SyncGameExit_Params
{
};

// Function Client.BattleUtils.SyncBattlePlayerExit
struct UBattleUtils_SyncBattlePlayerExit_Params
{
	uint64_t                                           UID;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FName                                       PlayerType;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Reason;                                                   // (Parm, ZeroConstructor)
};

// Function Client.BattleUtils.RetrievePlayerParams
struct UBattleUtils_RetrievePlayerParams_Params
{
	struct FPlayerID                                   PlayerID;                                                 // (Parm)
	struct FGameModePlayerParams                       ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function Client.BattleUtils.RetrieveAIPlayerParams
struct UBattleUtils_RetrieveAIPlayerParams_Params
{
	struct FPlayerID                                   PlayerID;                                                 // (Parm)
	struct FGameModeAIPlayerParams                     ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function Client.BattleUtils.ResponPlayerWeaponDIYData
struct UBattleUtils_ResponPlayerWeaponDIYData_Params
{
	uint64_t                                           PlayerUID;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FWeaponDIYData                              InWeaponDIYData;                                          // (Parm)
};

// Function Client.BattleUtils.RequestSomePlayersBattleData
struct UBattleUtils_RequestSomePlayersBattleData_Params
{
	TArray<uint64_t>                                   PlayerUIDList;                                            // (Parm, ZeroConstructor)
	unsigned char                                      DataType;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.BattleUtils.RequestPlayerWeaponDIYData
struct UBattleUtils_RequestPlayerWeaponDIYData_Params
{
	uint64_t                                           PlayerUID;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                WeaponSkinID;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                PlanID;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.BattleUtils.RequestOnePlayersBattleData
struct UBattleUtils_RequestOnePlayersBattleData_Params
{
	uint64_t                                           PlayerUID;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	unsigned char                                      DataType;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.BattleUtils.RequestAllPlayersBattleData
struct UBattleUtils_RequestAllPlayersBattleData_Params
{
	unsigned char                                      DataType;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.BattleUtils.OnPostLoadMapWithWorld
struct UBattleUtils_OnPostLoadMapWithWorld_Params
{
	class UWorld*                                      World;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.BattleUtils.NewBattlePlayer
struct UBattleUtils_NewBattlePlayer_Params
{
	class UBattlePlayer*                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BattleUtils.NewBattleAIPlayer
struct UBattleUtils_NewBattleAIPlayer_Params
{
	class UBattleAIPlayer*                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BattleUtils.HandleGameModeStateChanged
struct UBattleUtils_HandleGameModeStateChanged_Params
{
	struct FGameModeStateChangedParams                 Params;                                                   // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.BattleUtils.GetBattleGameMode
struct UBattleUtils_GetBattleGameMode_Params
{
	class AUAEGameMode*                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BattleUtils.GenerateAIPlayerParams
struct UBattleUtils_GenerateAIPlayerParams_Params
{
	struct FPlayerInfoData                             Info;                                                     // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.BattleUtils.FindPlayerByUID
struct UBattleUtils_FindPlayerByUID_Params
{
	uint64_t                                           UID;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FName                                       PlayerType;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	class UBattlePlayer*                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BattleUtils.FindPlayerByPlayerName
struct UBattleUtils_FindPlayerByPlayerName_Params
{
	struct FString                                     PlayerName;                                               // (Parm, ZeroConstructor)
	struct FName                                       PlayerType;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	class UBattlePlayer*                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BattleUtils.FindPlayerByPlayerKey
struct UBattleUtils_FindPlayerByPlayerKey_Params
{
	uint32_t                                           PlayerKey;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FName                                       PlayerType;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	class UBattlePlayer*                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BattleWindowMgr.ShowUI
struct UBattleWindowMgr_ShowUI_Params
{
	class UObject*                                     WorldContextObject;                                       // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     WindowName;                                               // (Parm, ZeroConstructor)
	class UObject*                                     ObjectParam;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.BattleWindowMgr.SetInstance
struct UBattleWindowMgr_SetInstance_Params
{
	class UBattleWindowMgrLuaUtils*                    InInstance;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	class ULuaStateWrapper*                            InLuaStateWrapper;                                        // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.BattleWindowMgr.HideUI
struct UBattleWindowMgr_HideUI_Params
{
	class UObject*                                     WorldContextObject;                                       // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     WindowName;                                               // (Parm, ZeroConstructor)
};

// Function Client.BattleWindowMgr.CheckWindowOpen
struct UBattleWindowMgr_CheckWindowOpen_Params
{
	class UObject*                                     WorldContextObject;                                       // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     WindowName;                                               // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BugReporter.SendScreenShot
struct UBugReporter_SendScreenShot_Params
{
	struct FString                                     errorReason;                                              // (Parm, ZeroConstructor)
	struct FString                                     errorDescription;                                         // (Parm, ZeroConstructor)
	struct FString                                     ImagePath;                                                // (Parm, ZeroConstructor)
	float                                              X;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              Y;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              Z;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.BugReporter.SendLog
struct UBugReporter_SendLog_Params
{
	struct FString                                     errorReason;                                              // (Parm, ZeroConstructor)
	struct FString                                     errorDescription;                                         // (Parm, ZeroConstructor)
	float                                              X;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              Y;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              Z;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               pullAll;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               zipLogUpload;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.BugReporter.ReadZipLog
struct UBugReporter_ReadZipLog_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
};

// Function Client.BugReporter.CompressLog
struct UBugReporter_CompressLog_Params
{
	bool                                               pullAllLog;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<unsigned char>                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.XorEncryptDecrypt
struct UBusinessHelper_XorEncryptDecrypt_Params
{
	struct FString                                     Data;                                                     // (Parm, ZeroConstructor)
	bool                                               bEncrypt;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Key;                                                      // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.UIGetResWithPath
struct UBusinessHelper_UIGetResWithPath_Params
{
	struct FString                                     DesManagerName;                                           // (Parm, ZeroConstructor)
	class UObject*                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.UIGetLuaManagerByName
struct UBusinessHelper_UIGetLuaManagerByName_Params
{
	class UUAEUserWidget*                              pUIClass;                                                 // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FString                                     InManagerName;                                            // (Parm, ZeroConstructor)
	class ALuaClassObj*                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.UIGetLuaManager
struct UBusinessHelper_UIGetLuaManager_Params
{
	class UUAEUserWidget*                              pUIClass;                                                 // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	class ALuaClassObj*                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.StopUIStat
struct UBusinessHelper_StopUIStat_Params
{
	struct FString                                     UIName;                                                   // (Parm, ZeroConstructor)
	bool                                               bReport;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.BusinessHelper.StopTimeWatch
struct UBusinessHelper_StopTimeWatch_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.StartUIStat
struct UBusinessHelper_StartUIStat_Params
{
	struct FString                                     UIName;                                                   // (Parm, ZeroConstructor)
};

// Function Client.BusinessHelper.StartTimeWatch
struct UBusinessHelper_StartTimeWatch_Params
{
};

// Function Client.BusinessHelper.SpecialBase64Encode
struct UBusinessHelper_SpecialBase64Encode_Params
{
	struct FString                                     Data;                                                     // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.SpecialBase64Decode
struct UBusinessHelper_SpecialBase64Decode_Params
{
	struct FString                                     Data;                                                     // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.SetUIStatMaxClickTimes
struct UBusinessHelper_SetUIStatMaxClickTimes_Params
{
	int                                                Times;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.BusinessHelper.RemoveKnownMissingPackageRefObjectByObj
struct UBusinessHelper_RemoveKnownMissingPackageRefObjectByObj_Params
{
	class UObject*                                     RefedObject;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.BusinessHelper.LoadAssetFromPath
struct UBusinessHelper_LoadAssetFromPath_Params
{
	struct FString                                     DesManagerName;                                           // (Parm, ZeroConstructor)
	class UObject*                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.IsSplitMiniPakVersion
struct UBusinessHelper_IsSplitMiniPakVersion_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.IsSplitMapPakVersion
struct UBusinessHelper_IsSplitMapPakVersion_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.IsFit
struct UBusinessHelper_IsFit_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.IsClassOf
struct UBusinessHelper_IsClassOf_Params
{
	class UObject*                                     Object;                                                   // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	class UClass*                                      Class;                                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.IsChildOf
struct UBusinessHelper_IsChildOf_Params
{
	class UClass*                                      ChildClass;                                               // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	class UClass*                                      Class;                                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.IsCEVersion
struct UBusinessHelper_IsCEVersion_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.IsAppFromStore
struct UBusinessHelper_IsAppFromStore_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.HasDownloadedBasePak
struct UBusinessHelper_HasDownloadedBasePak_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.GetXORKey
struct UBusinessHelper_GetXORKey_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetWidgetByName
struct UBusinessHelper_GetWidgetByName_Params
{
	class UUAEUserWidget*                              pUIClass;                                                 // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FString                                     InManagerName;                                            // (Parm, ZeroConstructor)
	struct FString                                     InWidgtName;                                              // (Parm, ZeroConstructor)
	class UUAEUserWidget*                              ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.BusinessHelper.GetVoiceSdkGameId
struct UBusinessHelper_GetVoiceSdkGameId_Params
{
	uint64_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.GetTSSGameId
struct UBusinessHelper_GetTSSGameId_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.GetTime
struct UBusinessHelper_GetTime_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.GetSplitMapConfigInfo
struct UBusinessHelper_GetSplitMapConfigInfo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetPublishRegionID
struct UBusinessHelper_GetPublishRegionID_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.GetPublishRegion
struct UBusinessHelper_GetPublishRegion_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetPathFromUserWidgetToViewport
struct UBusinessHelper_GetPathFromUserWidgetToViewport_Params
{
	class UUserWidget*                                 UserWidget;                                               // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	bool                                               withObjectNum;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetPackChannel
struct UBusinessHelper_GetPackChannel_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetOpenId
struct UBusinessHelper_GetOpenId_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetObjectClassName
struct UBusinessHelper_GetObjectClassName_Params
{
	class UObject*                                     Object;                                                   // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetMobileBasePath
struct UBusinessHelper_GetMobileBasePath_Params
{
	struct FString                                     InPath;                                                   // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetLuaManagerByName
struct UBusinessHelper_GetLuaManagerByName_Params
{
	class UUAEUserWidget*                              pUIClass;                                                 // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FString                                     InManagerName;                                            // (Parm, ZeroConstructor)
	class ALuaClassObj*                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.GetITopGameId
struct UBusinessHelper_GetITopGameId_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetInGameLocalConnectURL
struct UBusinessHelper_GetInGameLocalConnectURL_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetIMSDKEnv
struct UBusinessHelper_GetIMSDKEnv_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.GetDeviceQualityLevel
struct UBusinessHelper_GetDeviceQualityLevel_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.GetDeviceOrientation
struct UBusinessHelper_GetDeviceOrientation_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.GetDataTable
struct UBusinessHelper_GetDataTable_Params
{
	struct FString                                     tableName;                                                // (Parm, ZeroConstructor)
	class UUAEDataTable*                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.GetCurrentNetworkState
struct UBusinessHelper_GetCurrentNetworkState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.GetChildByName
struct UBusinessHelper_GetChildByName_Params
{
	class UUserWidget*                                 pParent;                                                  // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FString                                     Name;                                                     // (Parm, ZeroConstructor)
	class UWidget*                                     ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.BusinessHelper.GetBuildURL
struct UBusinessHelper_GetBuildURL_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetBuildNo
struct UBusinessHelper_GetBuildNo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetBranchName
struct UBusinessHelper_GetBranchName_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetBase64Key
struct UBusinessHelper_GetBase64Key_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetAppVersion
struct UBusinessHelper_GetAppVersion_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.GetAOSSHOPID
struct UBusinessHelper_GetAOSSHOPID_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.BusinessHelper.GetAOSSHOP
struct UBusinessHelper_GetAOSSHOP_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.ClearDisplayLookupTable
struct UBusinessHelper_ClearDisplayLookupTable_Params
{
};

// Function Client.BusinessHelper.BroadCastMSG
struct UBusinessHelper_BroadCastMSG_Params
{
	class UFrontendHUD*                                FrontendHUD;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     DesManagerName;                                           // (Parm, ZeroConstructor)
	struct FString                                     Msg;                                                      // (Parm, ZeroConstructor)
};

// Function Client.BusinessHelper.Base64Encode
struct UBusinessHelper_Base64Encode_Params
{
	struct FString                                     Data;                                                     // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.Base64Decode
struct UBusinessHelper_Base64Decode_Params
{
	struct FString                                     Data;                                                     // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.BusinessHelper.AddKnownMissingPackage
struct UBusinessHelper_AddKnownMissingPackage_Params
{
	struct FString                                     PackageName;                                              // (Parm, OutParm, ZeroConstructor)
	class UObject*                                     BindObj;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bReplace;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.IntlHelper.UpdateXGPushNightTag
struct UIntlHelper_UpdateXGPushNightTag_Params
{
	bool                                               bInit;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.IntlHelper.UpdateXGPushDayTag
struct UIntlHelper_UpdateXGPushDayTag_Params
{
	bool                                               bInit;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.IntlHelper.UpdateVoiceUrl
struct UIntlHelper_UpdateVoiceUrl_Params
{
	struct FString                                     regionVoiceUrl;                                           // (Parm, ZeroConstructor)
};

// Function Client.IntlHelper.UnInitTweenMaker
struct UIntlHelper_UnInitTweenMaker_Params
{
};

// Function Client.IntlHelper.TimeFormatString
struct UIntlHelper_TimeFormatString_Params
{
	struct FString                                     Format;                                                   // (Parm, ZeroConstructor)
	int                                                hours;                                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	int                                                Mins;                                                     // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	int                                                secs;                                                     // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.SaveXGTags
struct UIntlHelper_SaveXGTags_Params
{
	struct FString                                     Language;                                                 // (Parm, ZeroConstructor)
	struct FString                                     timezone;                                                 // (Parm, ZeroConstructor)
	struct FString                                     Region;                                                   // (Parm, ZeroConstructor)
};

// Function Client.IntlHelper.OnSwitchLanguage
struct UIntlHelper_OnSwitchLanguage_Params
{
};

// Function Client.IntlHelper.OnChoosingZone
struct UIntlHelper_OnChoosingZone_Params
{
	int                                                ZoneID;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     AddrIP;                                                   // (Parm, ZeroConstructor)
	struct FString                                     regionVoiceUrl;                                           // (Parm, ZeroConstructor)
};

// Function Client.IntlHelper.IsRemoteNotificationsEnabled
struct UIntlHelper_IsRemoteNotificationsEnabled_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.IntlHelper.IsHelpshiftEnable4CurrentChannel
struct UIntlHelper_IsHelpshiftEnable4CurrentChannel_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.IntlHelper.IsHelpshiftEnable
struct UIntlHelper_IsHelpshiftEnable_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.IntlHelper.IsAwakedByAdjust
struct UIntlHelper_IsAwakedByAdjust_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.IntlHelper.InitTweenMaker
struct UIntlHelper_InitTweenMaker_Params
{
};

// Function Client.IntlHelper.HelpshiftUploadLog
struct UIntlHelper_HelpshiftUploadLog_Params
{
};

// Function Client.IntlHelper.HelpshiftShowSingleFAQWithInfo
struct UIntlHelper_HelpshiftShowSingleFAQWithInfo_Params
{
	struct FString                                     publishID;                                                // (Parm, ZeroConstructor)
	struct FString                                     PlayerName;                                               // (Parm, ZeroConstructor)
	struct FString                                     PlayerLevel;                                              // (Parm, ZeroConstructor)
	struct FString                                     PlayerGold;                                               // (Parm, ZeroConstructor)
	int                                                PlayerRecharge;                                           // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	int                                                PlayerRegisterTime;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ExtraTags;                                                // (Parm, ZeroConstructor)
};

// Function Client.IntlHelper.HelpshiftShowFAQsWithInfo
struct UIntlHelper_HelpshiftShowFAQsWithInfo_Params
{
	struct FString                                     PlayerName;                                               // (Parm, ZeroConstructor)
	struct FString                                     PlayerLevel;                                              // (Parm, ZeroConstructor)
	struct FString                                     PlayerGold;                                               // (Parm, ZeroConstructor)
	int                                                PlayerRecharge;                                           // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	int                                                PlayerRegisterTime;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ExtraTags;                                                // (Parm, ZeroConstructor)
};

// Function Client.IntlHelper.HelpshiftShowFAQs
struct UIntlHelper_HelpshiftShowFAQs_Params
{
};

// Function Client.IntlHelper.HelpshiftShowConversionWithInfo
struct UIntlHelper_HelpshiftShowConversionWithInfo_Params
{
	struct FString                                     Name;                                                     // (Parm, ZeroConstructor)
	struct FString                                     Level;                                                    // (Parm, ZeroConstructor)
	struct FString                                     Gold;                                                     // (Parm, ZeroConstructor)
};

// Function Client.IntlHelper.HelpshiftShowConversion
struct UIntlHelper_HelpshiftShowConversion_Params
{
};

// Function Client.IntlHelper.HelpshiftRequestUnreadMessagesCount
struct UIntlHelper_HelpshiftRequestUnreadMessagesCount_Params
{
};

// Function Client.IntlHelper.HelpshiftGetUnreadMessgesCount
struct UIntlHelper_HelpshiftGetUnreadMessgesCount_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.IntlHelper.HelpshiftClearUnreadMessgesCount
struct UIntlHelper_HelpshiftClearUnreadMessgesCount_Params
{
};

// Function Client.IntlHelper.GetTranslationText
struct UIntlHelper_GetTranslationText_Params
{
	struct FString                                     Key;                                                      // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetSavedXGTimezoneTag
struct UIntlHelper_GetSavedXGTimezoneTag_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetSavedXGRegionTag
struct UIntlHelper_GetSavedXGRegionTag_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetSavedXGPushNightTag
struct UIntlHelper_GetSavedXGPushNightTag_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetSavedXGPushDayTag
struct UIntlHelper_GetSavedXGPushDayTag_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetSavedXGLanguageTag
struct UIntlHelper_GetSavedXGLanguageTag_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetPlayerUCLevel
struct UIntlHelper_GetPlayerUCLevel_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetLocalTimezone
struct UIntlHelper_GetLocalTimezone_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.IntlHelper.GetLocalizeStringWithString
struct UIntlHelper_GetLocalizeStringWithString_Params
{
	struct FString                                     sourceString;                                             // (Parm, ZeroConstructor)
	int                                                numStringIndex;                                           // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     string1;                                                  // (Parm, ZeroConstructor)
	struct FString                                     string2;                                                  // (Parm, ZeroConstructor)
	struct FString                                     string3;                                                  // (Parm, ZeroConstructor)
	struct FString                                     string4;                                                  // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetLocalizeStringWithNum
struct UIntlHelper_GetLocalizeStringWithNum_Params
{
	int                                                ID;                                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	int                                                numStringIndex;                                           // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     string1;                                                  // (Parm, ZeroConstructor)
	struct FString                                     string2;                                                  // (Parm, ZeroConstructor)
	struct FString                                     string3;                                                  // (Parm, ZeroConstructor)
	struct FString                                     string4;                                                  // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetLocalizeStrByStr
struct UIntlHelper_GetLocalizeStrByStr_Params
{
	struct FString                                     Source;                                                   // (Parm, ZeroConstructor)
	struct FString                                     string1;                                                  // (Parm, ZeroConstructor)
	struct FString                                     string2;                                                  // (Parm, ZeroConstructor)
	struct FString                                     string3;                                                  // (Parm, ZeroConstructor)
	struct FString                                     string4;                                                  // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetLocalizeStrByID
struct UIntlHelper_GetLocalizeStrByID_Params
{
	int                                                ID;                                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     string1;                                                  // (Parm, ZeroConstructor)
	struct FString                                     string2;                                                  // (Parm, ZeroConstructor)
	struct FString                                     string3;                                                  // (Parm, ZeroConstructor)
	struct FString                                     string4;                                                  // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetLocalizationStringWithID
struct UIntlHelper_GetLocalizationStringWithID_Params
{
	int                                                ID;                                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetLocalizationString
struct UIntlHelper_GetLocalizationString_Params
{
	struct FString                                     Key;                                                      // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetLocalizationBattleStringWithID
struct UIntlHelper_GetLocalizationBattleStringWithID_Params
{
	int                                                ID;                                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetHistoryErrorCode
struct UIntlHelper_GetHistoryErrorCode_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetGameMasterVID
struct UIntlHelper_GetGameMasterVID_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetDeepLinkUrl
struct UIntlHelper_GetDeepLinkUrl_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.GetCurrentZoneID
struct UIntlHelper_GetCurrentZoneID_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.IntlHelper.FormatLocalizeStrByStr
struct UIntlHelper_FormatLocalizeStrByStr_Params
{
	struct FString                                     Source;                                                   // (Parm, ZeroConstructor)
	TArray<struct FString>                             stringArr;                                                // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IntlHelper.DirectToNotificationSetup
struct UIntlHelper_DirectToNotificationSetup_Params
{
};

// Function Client.IntlHelper.ClearAdjustDeepLink
struct UIntlHelper_ClearAdjustDeepLink_Params
{
};

// Function Client.IntlHelper.AdjustParaAnalysis
struct UIntlHelper_AdjustParaAnalysis_Params
{
};

// Function Client.IntlHelper.AddErrorCodeToHistory
struct UIntlHelper_AddErrorCodeToHistory_Params
{
	struct FString                                     InErrorCode;                                              // (Parm, ZeroConstructor)
};

// Function Client.TestHUD.TestFunctionNOParam
struct ATestHUD_TestFunctionNOParam_Params
{
};

// Function Client.TestHUD.TestFunctionBP_LUA
struct ATestHUD_TestFunctionBP_LUA_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TestHUD.TestFunctionBP
struct ATestHUD_TestFunctionBP_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TestHUD.Function_Lua
struct ATestHUD_Function_Lua_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TestHUD.Function_CPlus_Call
struct ATestHUD_Function_CPlus_Call_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TestHUD.Function_CPlus
struct ATestHUD_Function_CPlus_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TestHUD.Function_BP_CPP
struct ATestHUD_Function_BP_CPP_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TestHUD.Function_BP_Call_LUA
struct ATestHUD_Function_BP_Call_LUA_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TestHUD.Function_BP_Call_CPP
struct ATestHUD_Function_BP_Call_CPP_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TestHUD.Function_BP_Call_CPlus
struct ATestHUD_Function_BP_Call_CPlus_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TestHUD.Function_BP_Call
struct ATestHUD_Function_BP_Call_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TestHUD.Function_BP
struct ATestHUD_Function_BP_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.CDNUpdate.StartUpdateApp
struct UCDNUpdate_StartUpdateApp_Params
{
};

// Function Client.CDNUpdate.StartAppUpdate
struct UCDNUpdate_StartAppUpdate_Params
{
	bool                                               StartGrayUpdate;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.CDNUpdate.OnRequestProgress
struct UCDNUpdate_OnRequestProgress_Params
{
	struct FCDNDownloaderInfo                          Info;                                                     // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.CDNUpdate.OnRequestComplete
struct UCDNUpdate_OnRequestComplete_Params
{
	struct FCDNDownloaderInfo                          Info;                                                     // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.CDNUpdate.IsUpdating
struct UCDNUpdate_IsUpdating_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.CDNUpdate.IsGrayUpdate
struct UCDNUpdate_IsGrayUpdate_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.CDNUpdate.GetCurStage
struct UCDNUpdate_GetCurStage_Params
{
	float                                              percent;                                                  // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                GetCurVal;                                                // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                GetMaxVal;                                                // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.CDNUpdate.FinishUpdate
struct UCDNUpdate_FinishUpdate_Params
{
};

// Function Client.CDNUpdate.ContinueUpdate
struct UCDNUpdate_ContinueUpdate_Params
{
};

// Function Client.CDNUpdate.CancelUpdate
struct UCDNUpdate_CancelUpdate_Params
{
};

// Function Client.CentauriManager.TickCentauriPackage
struct UCentauriManager_TickCentauriPackage_Params
{
};

// Function Client.CentauriManager.Tick
struct UCentauriManager_Tick_Params
{
	float                                              DeltaTime;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.CentauriManager.SwitchPayChannel
struct UCentauriManager_SwitchPayChannel_Params
{
	ECentauriMultiPayChannelSwitch                     switchChannel;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.CentauriManager.Subscribe
struct UCentauriManager_Subscribe_Params
{
	struct FString                                     productid;                                                // (Parm, ZeroConstructor)
	struct FString                                     InPayItem;                                                // (Parm, ZeroConstructor)
	struct FString                                     Country;                                                  // (Parm, ZeroConstructor)
	struct FString                                     currency;                                                 // (Parm, ZeroConstructor)
	struct FString                                     serviceCode;                                              // (Parm, ZeroConstructor)
	struct FString                                     serviceName;                                              // (Parm, ZeroConstructor)
	bool                                               autoPay;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     basePlanId;                                               // (Parm, ZeroConstructor)
	struct FString                                     gwOfferId;                                                // (Parm, ZeroConstructor)
	struct FString                                     InChannelExtras;                                          // (Parm, ZeroConstructor)
	struct FString                                     InAppExtends;                                             // (Parm, ZeroConstructor)
};

// Function Client.CentauriManager.SetZoneID
struct UCentauriManager_SetZoneID_Params
{
	struct FString                                     inZoneID;                                                 // (Parm, ZeroConstructor)
	struct FString                                     inGoodsZoneID;                                            // (Parm, ZeroConstructor)
};

// Function Client.CentauriManager.SetRoleInfo
struct UCentauriManager_SetRoleInfo_Params
{
	int                                                InChannel;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     OpenID;                                                   // (Parm, ZeroConstructor)
};

// Function Client.CentauriManager.SetFrontendHUD
struct UCentauriManager_SetFrontendHUD_Params
{
	class UGameFrontendHUD*                            InFrontendHUD;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.CentauriManager.SetCentauriIDC
struct UCentauriManager_SetCentauriIDC_Params
{
	struct FString                                     idc;                                                      // (Parm, ZeroConstructor)
};

// Function Client.CentauriManager.Reprovide
struct UCentauriManager_Reprovide_Params
{
};

// Function Client.CentauriManager.Pay
struct UCentauriManager_Pay_Params
{
	struct FString                                     productid;                                                // (Parm, ZeroConstructor)
	struct FString                                     InPayItem;                                                // (Parm, ZeroConstructor)
	struct FString                                     Country;                                                  // (Parm, ZeroConstructor)
	struct FString                                     currency;                                                 // (Parm, ZeroConstructor)
	struct FString                                     InChannelExtras;                                          // (Parm, ZeroConstructor)
	struct FString                                     InAppExtends;                                             // (Parm, ZeroConstructor)
};

// Function Client.CentauriManager.ModifySubscribe
struct UCentauriManager_ModifySubscribe_Params
{
	struct FString                                     newProductid;                                             // (Parm, ZeroConstructor)
	struct FString                                     Country;                                                  // (Parm, ZeroConstructor)
	struct FString                                     currency;                                                 // (Parm, ZeroConstructor)
	struct FString                                     serviceCode;                                              // (Parm, ZeroConstructor)
	struct FString                                     serviceName;                                              // (Parm, ZeroConstructor)
	bool                                               autoPay;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     basePlanId;                                               // (Parm, ZeroConstructor)
	struct FString                                     gwOfferId;                                                // (Parm, ZeroConstructor)
	struct FString                                     InChannelExtras;                                          // (Parm, ZeroConstructor)
	struct FString                                     InAppExtends;                                             // (Parm, ZeroConstructor)
};

// Function Client.CentauriManager.IsH5PayEnable
struct UCentauriManager_IsH5PayEnable_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.CentauriManager.Initialize
struct UCentauriManager_Initialize_Params
{
	ECentauriMultiPayChannelSwitch                     envior;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.CentauriManager.H5Pay
struct UCentauriManager_H5Pay_Params
{
	struct FString                                     Country;                                                  // (Parm, ZeroConstructor)
	struct FString                                     InChannelExtras;                                          // (Parm, ZeroConstructor)
	struct FString                                     InAppExtends;                                             // (Parm, ZeroConstructor)
};

// Function Client.CentauriManager.GoodsPresent
struct UCentauriManager_GoodsPresent_Params
{
	struct FString                                     productid;                                                // (Parm, ZeroConstructor)
	struct FString                                     InPayItem;                                                // (Parm, ZeroConstructor)
	struct FString                                     Price;                                                    // (Parm, ZeroConstructor)
	struct FString                                     Country;                                                  // (Parm, ZeroConstructor)
	struct FString                                     currency;                                                 // (Parm, ZeroConstructor)
	struct FString                                     MetaData;                                                 // (Parm, ZeroConstructor)
	struct FString                                     InChannelExtras;                                          // (Parm, ZeroConstructor)
	struct FString                                     InAppExtends;                                             // (Parm, ZeroConstructor)
};

// Function Client.CentauriManager.Goods
struct UCentauriManager_Goods_Params
{
	struct FString                                     productid;                                                // (Parm, ZeroConstructor)
	struct FString                                     InPayItem;                                                // (Parm, ZeroConstructor)
	struct FString                                     Price;                                                    // (Parm, ZeroConstructor)
	struct FString                                     Country;                                                  // (Parm, ZeroConstructor)
	struct FString                                     currency;                                                 // (Parm, ZeroConstructor)
	struct FString                                     InChannelExtras;                                          // (Parm, ZeroConstructor)
	struct FString                                     InAppExtends;                                             // (Parm, ZeroConstructor)
};

// Function Client.CentauriManager.GetProductInfo
struct UCentauriManager_GetProductInfo_Params
{
	TMap<struct FString, struct FString>               listProductID;                                            // (Parm, ZeroConstructor)
};

// Function Client.CentauriManager.getPF
struct UCentauriManager_getPF_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.CentauriManager.GetPaymentProductId
struct UCentauriManager_GetPaymentProductId_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.CentauriManager.GetPayEnvironment
struct UCentauriManager_GetPayEnvironment_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.CentauriManager.GetPayChannel
struct UCentauriManager_GetPayChannel_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.CentauriManager.GetPackChannel
struct UCentauriManager_GetPackChannel_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.CentauriManager.GetOfferID
struct UCentauriManager_GetOfferID_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.CentauriManager.GetNativePackageTag
struct UCentauriManager_GetNativePackageTag_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.CentauriManager.GetMPInfo
struct UCentauriManager_GetMPInfo_Params
{
	struct FString                                     Country;                                                  // (Parm, ZeroConstructor)
	struct FString                                     currency;                                                 // (Parm, ZeroConstructor)
	struct FString                                     InAppExtends;                                             // (Parm, ZeroConstructor)
	struct FString                                     InDrmInfo;                                                // (Parm, ZeroConstructor)
};

// Function Client.CentauriManager.GetIntroPrice
struct UCentauriManager_GetIntroPrice_Params
{
	TMap<struct FString, struct FString>               listProductID;                                            // (Parm, ZeroConstructor)
};

// Function Client.CentauriManager.GetInstance
struct UCentauriManager_GetInstance_Params
{
	class UCentauriManager*                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.CentauriManager.GetInIDC
struct UCentauriManager_GetInIDC_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.CentauriManager.GetAOSSHOP
struct UCentauriManager_GetAOSSHOP_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.CompressTextureHelper.TestGetTexture2DFromDisk_KTX2
struct UCompressTextureHelper_TestGetTexture2DFromDisk_KTX2_Params
{
	struct FString                                     PathName;                                                 // (Parm, ZeroConstructor)
	class UTexture2D*                                  ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.CustomLayoutProxy.UnregisterCustomLayoutChange
struct UCustomLayoutProxy_UnregisterCustomLayoutChange_Params
{
	class UUAECustomizePanel*                          InCustomizePanel;                                         // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function Client.CustomLayoutProxy.RegisterCustomLayoutChange
struct UCustomLayoutProxy_RegisterCustomLayoutChange_Params
{
	class UUAECustomizePanel*                          InCustomizePanel;                                         // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function Client.CustomLayoutProxy.OnReleaseInGame
struct UCustomLayoutProxy_OnReleaseInGame_Params
{
};

// Function Client.CustomLayoutProxy.OnInitInGame
struct UCustomLayoutProxy_OnInitInGame_Params
{
};

// Function Client.CustomLayoutProxy.ClearCacheBySaveType
struct UCustomLayoutProxy_ClearCacheBySaveType_Params
{
	unsigned char                                      InSaveType;                                               // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.CustomLayoutProxy.CheckLayoutDetail
struct UCustomLayoutProxy_CheckLayoutDetail_Params
{
	int                                                InCustomType;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	unsigned char                                      InSaveType;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.CustomLayoutProxy.BroadcastCustomLayoutChangeForAll
struct UCustomLayoutProxy_BroadcastCustomLayoutChangeForAll_Params
{
	bool                                               bNotCheck;                                                // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.CustomLayoutProxy.BroadcastCustomLayoutChangeBySaveType
struct UCustomLayoutProxy_BroadcastCustomLayoutChangeBySaveType_Params
{
	unsigned char                                      InSaveType;                                               // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bNotCheck;                                                // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.CustomLayoutProxy.BroadcastCustomLayoutChangeByCustomType
struct UCustomLayoutProxy_BroadcastCustomLayoutChangeByCustomType_Params
{
	int                                                InCustomType;                                             // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bNotCheck;                                                // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.CustomLayoutProxy.AddInvalidCustomTypeCache
struct UCustomLayoutProxy_AddInvalidCustomTypeCache_Params
{
	int                                                InCustomType;                                             // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.CustomPanelProxy.SetSelectedImageOriginEffect
struct UCustomPanelProxy_SetSelectedImageOriginEffect_Params
{
};

// Function Client.CustomPanelProxy.SetSelectedImageFlashEffect
struct UCustomPanelProxy_SetSelectedImageFlashEffect_Params
{
};

// Function Client.CustomPanelProxy.IsSquareFlashEffectAssetName
struct UCustomPanelProxy_IsSquareFlashEffectAssetName_Params
{
	struct FString                                     InAssetName;                                              // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.CustomPanelProxy.IsCircleFlashEffectAssetName
struct UCustomPanelProxy_IsCircleFlashEffectAssetName_Params
{
	struct FString                                     InAssetName;                                              // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.CustomPanelProxy.GetWidgetByType
struct UCustomPanelProxy_GetWidgetByType_Params
{
	class UWidget*                                     RootWidget;                                               // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UClass*                                      WidgetType;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	class UWidget*                                     ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.CustomPanelProxy.GetWidgetByNameStartsWith
struct UCustomPanelProxy_GetWidgetByNameStartsWith_Params
{
	class UWidget*                                     RootWidget;                                               // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FString                                     Prefix;                                                   // (Parm, ZeroConstructor)
	class UWidget*                                     ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.CustomPanelProxy.GetSelectedImage
struct UCustomPanelProxy_GetSelectedImage_Params
{
	class UImage*                                      ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.CustomPanelProxy.GetScreenMargin
struct UCustomPanelProxy_GetScreenMargin_Params
{
	struct FMargin                                     ReturnValue;                                              // (Parm, OutParm, ReturnParm, IsPlainOldData)
};

// Function Client.CustomPanelProxy.GetParentWidget
struct UCustomPanelProxy_GetParentWidget_Params
{
	class UWidget*                                     ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.CustomPanelProxy.GetOptionalWidgetSwitcher
struct UCustomPanelProxy_GetOptionalWidgetSwitcher_Params
{
	class UWidgetSwitcher*                             ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.CustomPanelProxy.GetInvalidImage
struct UCustomPanelProxy_GetInvalidImage_Params
{
	class UImage*                                      ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.CustomPanelProxy.GetExpandAssociatedWidget
struct UCustomPanelProxy_GetExpandAssociatedWidget_Params
{
	struct FString                                     WidgetName;                                               // (Parm, ZeroConstructor)
	class UWidget*                                     ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.CustomPanelProxy.GetBorder_RealSize
struct UCustomPanelProxy_GetBorder_RealSize_Params
{
	class UBorder*                                     ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.CustomPanelProxy.CalculateLimitPosition
struct UCustomPanelProxy_CalculateLimitPosition_Params
{
	struct FMargin                                     ReturnValue;                                              // (Parm, OutParm, ReturnParm, IsPlainOldData)
};

// Function Client.GameBackendUtils.GetTableManager
struct UGameBackendUtils_GetTableManager_Params
{
	class UUAETableManager*                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameBackendHUD.GetUtils
struct UGameBackendHUD_GetUtils_Params
{
	class UGameBackendUtils*                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameBackendHUD.GetInstance
struct UGameBackendHUD_GetInstance_Params
{
	class UGameBackendHUD*                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameBackendHUD.GetGameFrontendHUDByGameInstance
struct UGameBackendHUD_GetGameFrontendHUDByGameInstance_Params
{
	class UGameInstance*                               GameInstance;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	class UGameFrontendHUD*                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameBackendHUD.GetFirstGameFrontendHUD
struct UGameBackendHUD_GetFirstGameFrontendHUD_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	class UGameFrontendHUD*                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameBusinessManager.GetWidget
struct UGameBusinessManager_GetWidget_Params
{
	int                                                Index;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	class UUAEUserWidget*                              ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.GameBusinessManager.GetLuaObject
struct UGameBusinessManager_GetLuaObject_Params
{
	class ALuaClassObj*                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameBusinessManager.GetGameFrontendHUD
struct UGameBusinessManager_GetGameFrontendHUD_Params
{
	class UGameFrontendHUD*                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.UnRegisterUIShowHideEventDelegate
struct UGameFrontendHUD_UnRegisterUIShowHideEventDelegate_Params
{
	struct FString                                     Source;                                                   // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.TimeStatisticStop
struct UGameFrontendHUD_TimeStatisticStop_Params
{
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Name;                                                     // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.TimeStatisticStart
struct UGameFrontendHUD_TimeStatisticStart_Params
{
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameFrontendHUD.TickUdpCollector
struct UGameFrontendHUD_TickUdpCollector_Params
{
	float                                              DeltaTime;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameFrontendHUD.StatisVisibilityWidget
struct UGameFrontendHUD_StatisVisibilityWidget_Params
{
	class UWidget*                                     Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function Client.GameFrontendHUD.StatisLoadedTexture
struct UGameFrontendHUD_StatisLoadedTexture_Params
{
	class UTexture*                                    Texture;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameFrontendHUD.StartUpdate
struct UGameFrontendHUD_StartUpdate_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.StartGrayUpdate
struct UGameFrontendHUD_StartGrayUpdate_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.StartDolphinUpdateAfterCDNUpdateFailed
struct UGameFrontendHUD_StartDolphinUpdateAfterCDNUpdateFailed_Params
{
};

// Function Client.GameFrontendHUD.StartCDNUpdateAfterDolphinUpdateFailed
struct UGameFrontendHUD_StartCDNUpdateAfterDolphinUpdateFailed_Params
{
};

// Function Client.GameFrontendHUD.ShutdownUnrealNetwork
struct UGameFrontendHUD_ShutdownUnrealNetwork_Params
{
};

// Function Client.GameFrontendHUD.SetShouldShowAdaptTipInLobby
struct UGameFrontendHUD_SetShouldShowAdaptTipInLobby_Params
{
	bool                                               bShoudShow;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameFrontendHUD.SetGameSubMode
struct UGameFrontendHUD_SetGameSubMode_Params
{
	struct FString                                     SubMode;                                                  // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.SetGameStatusMap
struct UGameFrontendHUD_SetGameStatusMap_Params
{
	TMap<struct FString, struct FString>               InGameStatusMap;                                          // (Parm, OutParm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.SetClientEnterBattleStage
struct UGameFrontendHUD_SetClientEnterBattleStage_Params
{
	struct FString                                     InStageStr;                                               // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.SetAccountByWebLogin
struct UGameFrontendHUD_SetAccountByWebLogin_Params
{
	int                                                Channel;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     OpenID;                                                   // (Parm, ZeroConstructor)
	struct FString                                     userID;                                                   // (Parm, ZeroConstructor)
	struct FString                                     TokenID;                                                  // (Parm, ZeroConstructor)
	int                                                expireTime;                                               // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameFrontendHUD.RetryDownload
struct UGameFrontendHUD_RetryDownload_Params
{
};

// Function Client.GameFrontendHUD.RetryCDNDownload
struct UGameFrontendHUD_RetryCDNDownload_Params
{
};

// Function Client.GameFrontendHUD.RequestPhotoPermission
struct UGameFrontendHUD_RequestPhotoPermission_Params
{
	struct FScriptDelegate                             PermissionResultEvent;                                    // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.RequestCameraPermission
struct UGameFrontendHUD_RequestCameraPermission_Params
{
	struct FScriptDelegate                             PermissionResultEvent;                                    // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.ReportNetContinuousSaturate
struct UGameFrontendHUD_ReportNetContinuousSaturate_Params
{
};

// Function Client.GameFrontendHUD.RemoveSuppotAdaptationBind
struct UGameFrontendHUD_RemoveSuppotAdaptationBind_Params
{
	class UPanelSlot*                                  PanelSlot;                                                // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function Client.GameFrontendHUD.ReleaseInGameUIManager
struct UGameFrontendHUD_ReleaseInGameUIManager_Params
{
};

// Function Client.GameFrontendHUD.ReleaseBattleUtils
struct UGameFrontendHUD_ReleaseBattleUtils_Params
{
};

// Function Client.GameFrontendHUD.RegisterUserSettingsDelegate
struct UGameFrontendHUD_RegisterUserSettingsDelegate_Params
{
	struct FScriptDelegate                             Delegate;                                                 // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.RegisterUIShowHideEventDelegate
struct UGameFrontendHUD_RegisterUIShowHideEventDelegate_Params
{
	struct FString                                     Source;                                                   // (Parm, ZeroConstructor)
	struct FScriptDelegate                             Delegate;                                                 // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.PickImageDetectQRCode
struct UGameFrontendHUD_PickImageDetectQRCode_Params
{
	struct FScriptDelegate                             ImagePickDetectEvent;                                     // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.OnWebviewNotify
struct UGameFrontendHUD_OnWebviewNotify_Params
{
	struct FWebviewInfoWrapper                         webviewinfo;                                              // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.GameFrontendHUD.OnWebviewActionNotify
struct UGameFrontendHUD_OnWebviewActionNotify_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.OnUAAssistantEvent
struct UGameFrontendHUD_OnUAAssistantEvent_Params
{
	struct FUAAssistantInfoWrapper                     UAAssistentInfo;                                          // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.GameFrontendHUD.OnSDKCallbackEvent
struct UGameFrontendHUD_OnSDKCallbackEvent_Params
{
	struct FSDKCallbackInfoWrapper                     sdkCallbackInfo;                                          // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.GameFrontendHUD.OnRequestComplete
struct UGameFrontendHUD_OnRequestComplete_Params
{
	struct FCDNDownloaderInfo                          Info;                                                     // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.GameFrontendHUD.OnRefreshAccountInfo
struct UGameFrontendHUD_OnRefreshAccountInfo_Params
{
	bool                                               Result;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                InChannel;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InOpenid;                                                 // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.OnQuickLoginNotify
struct UGameFrontendHUD_OnQuickLoginNotify_Params
{
	struct FWakeupInfoWrapper                          wakeupinfo;                                               // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.GameFrontendHUD.OnPlatformFriendNotify
struct UGameFrontendHUD_OnPlatformFriendNotify_Params
{
	struct FPlatformFriendInfoMap                      PlatformFriendInfoMap;                                    // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.GameFrontendHUD.OnNotUpdateFinished
struct UGameFrontendHUD_OnNotUpdateFinished_Params
{
};

// Function Client.GameFrontendHUD.OnLoginFlowNotify
struct UGameFrontendHUD_OnLoginFlowNotify_Params
{
	int                                                _Flow;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                _Param;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ExtraData;                                                // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.OnHttpImgResponse
struct UGameFrontendHUD_OnHttpImgResponse_Params
{
	class UTexture2D*                                  Texture;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	class UImageDownloader*                            downloader;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameFrontendHUD.OnGroupNotify
struct UGameFrontendHUD_OnGroupNotify_Params
{
	struct FGroupInfoWrapper                           groupInfo;                                                // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.GameFrontendHUD.OnGetTicketNotify
struct UGameFrontendHUD_OnGetTicketNotify_Params
{
	struct FString                                     Ticket;                                                   // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.OnGetShortUrlNotify
struct UGameFrontendHUD_OnGetShortUrlNotify_Params
{
	int                                                Ret;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ShortUrl;                                                 // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.OnGetCountryNoNotify
struct UGameFrontendHUD_OnGetCountryNoNotify_Params
{
	int                                                Country;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameFrontendHUD.OnGenQRImgNotify
struct UGameFrontendHUD_OnGenQRImgNotify_Params
{
	int                                                Ret;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Size;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     imgPath;                                                  // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.OnGameMasterEvent
struct UGameFrontendHUD_OnGameMasterEvent_Params
{
	struct FString                                     EventName;                                                // (Parm, ZeroConstructor)
	int                                                Ret;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameFrontendHUD.OnConnectorNetStateChangeNotify
struct UGameFrontendHUD_OnConnectorNetStateChangeNotify_Params
{
	int                                                State;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                EventParam1;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                EventParam2;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                EventParam3;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameFrontendHUD.OnCheckUpdateStateFinished
struct UGameFrontendHUD_OnCheckUpdateStateFinished_Params
{
	struct FDownloaderInfo                             Info;                                                     // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.GameFrontendHUD.OnAreaChanged
struct UGameFrontendHUD_OnAreaChanged_Params
{
	struct FString                                     InArea;                                                   // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.NotifyLoadingUIOperation
struct UGameFrontendHUD_NotifyLoadingUIOperation_Params
{
	int                                                OperationType;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameFrontendHUD.MakeToSuppotAdaptation
struct UGameFrontendHUD_MakeToSuppotAdaptation_Params
{
	class UPanelSlot*                                  PanelSlot;                                                // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function Client.GameFrontendHUD.LuaDoString
struct UGameFrontendHUD_LuaDoString_Params
{
	struct FString                                     LuaString;                                                // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.IsWindowOB
struct UGameFrontendHUD_IsWindowOB_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.IsODPaksBinLoaded
struct UGameFrontendHUD_IsODPaksBinLoaded_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.IsInstallPlatform
struct UGameFrontendHUD_IsInstallPlatform_Params
{
	struct FString                                     Platform;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.IsCEHideLobbyUI
struct UGameFrontendHUD_IsCEHideLobbyUI_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.HasAnyNetMsgToHandle
struct UGameFrontendHUD_HasAnyNetMsgToHandle_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetWidgetRenderCanChange
struct UGameFrontendHUD_GetWidgetRenderCanChange_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetVoiceSDKInterface
struct UGameFrontendHUD_GetVoiceSDKInterface_Params
{
	class UVoiceSDKInterface*                          ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetUserSettings
struct UGameFrontendHUD_GetUserSettings_Params
{
	class USaveGame*                                   ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetUpdater
struct UGameFrontendHUD_GetUpdater_Params
{
	class UGDolphinUpdater*                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetTranslator
struct UGameFrontendHUD_GetTranslator_Params
{
	class UTranslator*                                 ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetShouldShowAdaptTipInLobby
struct UGameFrontendHUD_GetShouldShowAdaptTipInLobby_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetSettingSubsystem
struct UGameFrontendHUD_GetSettingSubsystem_Params
{
	class USettingSubsystem*                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetPufferDownloader
struct UGameFrontendHUD_GetPufferDownloader_Params
{
	class UGCPufferDownloader*                         ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetPlayerStatusReportInfo
struct UGameFrontendHUD_GetPlayerStatusReportInfo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.GameFrontendHUD.GetPingReportInfo
struct UGameFrontendHUD_GetPingReportInfo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.GameFrontendHUD.GetPhotoPermission
struct UGameFrontendHUD_GetPhotoPermission_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetPacketLossReportInfo
struct UGameFrontendHUD_GetPacketLossReportInfo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.GameFrontendHUD.GetLuaStateWrapper
struct UGameFrontendHUD_GetLuaStateWrapper_Params
{
	class ULuaStateWrapper*                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetLuaEventBridge
struct UGameFrontendHUD_GetLuaEventBridge_Params
{
	class ULuaEventBridge*                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetLuaBlueprintSysMgr
struct UGameFrontendHUD_GetLuaBlueprintSysMgr_Params
{
	class ULuaBlueprintMgr*                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetHttpWrapper
struct UGameFrontendHUD_GetHttpWrapper_Params
{
	class UHttpWrapper*                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetGameSubMode
struct UGameFrontendHUD_GetGameSubMode_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.GameFrontendHUD.GetGameState
struct UGameFrontendHUD_GetGameState_Params
{
	class AGameStateBase*                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetFPSReportInfo
struct UGameFrontendHUD_GetFPSReportInfo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.GameFrontendHUD.GetEffectSettingMgr
struct UGameFrontendHUD_GetEffectSettingMgr_Params
{
	class UEffectSettingMgr*                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetDetailNetInfoFromDPM
struct UGameFrontendHUD_GetDetailNetInfoFromDPM_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetColorBlindnessMgr
struct UGameFrontendHUD_GetColorBlindnessMgr_Params
{
	class UColorBlindnessMgr*                          ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetClientNetObj
struct UGameFrontendHUD_GetClientNetObj_Params
{
	class UObject*                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetClientEnterBattleStageCostTime
struct UGameFrontendHUD_GetClientEnterBattleStageCostTime_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.GameFrontendHUD.GetClientEnterBattleStage
struct UGameFrontendHUD_GetClientEnterBattleStage_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.GameFrontendHUD.GetCameraPermission
struct UGameFrontendHUD_GetCameraPermission_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetBugReporter
struct UGameFrontendHUD_GetBugReporter_Params
{
	class UBugReporter*                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetBattleUtils
struct UGameFrontendHUD_GetBattleUtils_Params
{
	class UBattleUtils*                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.GetBattleIDHexStr
struct UGameFrontendHUD_GetBattleIDHexStr_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.GameFrontendHUD.GetAsyncLoadHelper
struct UGameFrontendHUD_GetAsyncLoadHelper_Params
{
	class UAsyncLoadHelper*                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.FinishModifyUserSettings
struct UGameFrontendHUD_FinishModifyUserSettings_Params
{
};

// Function Client.GameFrontendHUD.EnableFPSAndMemoryLog
struct UGameFrontendHUD_EnableFPSAndMemoryLog_Params
{
	bool                                               bEnable;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameFrontendHUD.DispatchLongTimeNoOperation
struct UGameFrontendHUD_DispatchLongTimeNoOperation_Params
{
	int                                                TimeOutCounter;                                           // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.DestroyDolphin
struct UGameFrontendHUD_DestroyDolphin_Params
{
};

// Function Client.GameFrontendHUD.CvmRotateClockwise
struct UGameFrontendHUD_CvmRotateClockwise_Params
{
	float                                              Yaw;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              DeltaTime;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.CreateQRCodeTexture
struct UGameFrontendHUD_CreateQRCodeTexture_Params
{
	struct FString                                     Text;                                                     // (Parm, ZeroConstructor)
	class UTexture2D*                                  ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameFrontendHUD.CreateInGameUIManager
struct UGameFrontendHUD_CreateInGameUIManager_Params
{
};

// Function Client.GameFrontendHUD.CreateBattleUtils
struct UGameFrontendHUD_CreateBattleUtils_Params
{
};

// Function Client.GameFrontendHUD.CallGlobalScriptFunction
struct UGameFrontendHUD_CallGlobalScriptFunction_Params
{
	struct FString                                     InFunctionName;                                           // (Parm, ZeroConstructor)
};

// Function Client.GameFrontendHUD.BeginModifyUserSettings
struct UGameFrontendHUD_BeginModifyUserSettings_Params
{
};

// Function Client.GameFrontendHUD.BattleUtilsGameEnd
struct UGameFrontendHUD_BattleUtilsGameEnd_Params
{
};

// Function Client.GameFrontendHUD.AfterLoadedEditorLogin
struct UGameFrontendHUD_AfterLoadedEditorLogin_Params
{
};

// Function Client.GameFrontendHUD.AddAdaptationWidgetDelegateEx
struct UGameFrontendHUD_AddAdaptationWidgetDelegateEx_Params
{
	class UPanelSlot*                                  PanelSlot;                                                // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function Client.GameFrontendHUD.AddAdaptationWidgetDelegate
struct UGameFrontendHUD_AddAdaptationWidgetDelegate_Params
{
	class UPanelSlot*                                  PanelSlot;                                                // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function Client.GameJoyInterface.ShareVideo
struct UGameJoyInterface_ShareVideo_Params
{
	int                                                Channel;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameJoyInterface.SetGameFrontendHUD
struct UGameJoyInterface_SetGameFrontendHUD_Params
{
	class UGameFrontendHUD*                            InHUD;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameJoyInterface.OnVideoShare
struct UGameJoyInterface_OnVideoShare_Params
{
	struct FString                                     Msg;                                                      // (Parm, ZeroConstructor)
};

// Function Client.GameJoyInterface.OnShowVideoPlayer
struct UGameJoyInterface_OnShowVideoPlayer_Params
{
	int                                                IsShow;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameJoyInterface.OnRecordingStart
struct UGameJoyInterface_OnRecordingStart_Params
{
	int                                                Status;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameJoyInterface.OnRecordingEnd
struct UGameJoyInterface_OnRecordingEnd_Params
{
	int64_t                                            Duration;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameJoyInterface.OnManualRecordingStart
struct UGameJoyInterface_OnManualRecordingStart_Params
{
	int                                                Status;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameJoyInterface.OnCheckSDKPermission
struct UGameJoyInterface_OnCheckSDKPermission_Params
{
	bool                                               IsSuccess;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameJoyInterface.OnCheckSDKFeature
struct UGameJoyInterface_OnCheckSDKFeature_Params
{
	int                                                sdkFeatureInt;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GameJoyInterface.IsSDKFeatureSupport
struct UGameJoyInterface_IsSDKFeatureSupport_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GameJoyInterface.GetInstance
struct UGameJoyInterface_GetInstance_Params
{
	class UGameJoyInterface*                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GDolphinUpdater.StartAppUpdate
struct UGDolphinUpdater_StartAppUpdate_Params
{
};

// Function Client.GDolphinUpdater.SetEnableCDNGetVersion
struct UGDolphinUpdater_SetEnableCDNGetVersion_Params
{
	bool                                               Enable;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GDolphinUpdater.OnUpdateError
struct UGDolphinUpdater_OnUpdateError_Params
{
	int                                                curVersionStage;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ErrorCode;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GDolphinUpdater.OnDolphinBGDownloadDone
struct UGDolphinUpdater_OnDolphinBGDownloadDone_Params
{
};

// Function Client.GDolphinUpdater.OnAreaChanged
struct UGDolphinUpdater_OnAreaChanged_Params
{
	struct FString                                     InArea;                                                   // (Parm, ZeroConstructor)
};

// Function Client.GDolphinUpdater.IsUpdating
struct UGDolphinUpdater_IsUpdating_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GDolphinUpdater.IsInstallInApp
struct UGDolphinUpdater_IsInstallInApp_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GDolphinUpdater.IsGrayUpdate
struct UGDolphinUpdater_IsGrayUpdate_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GDolphinUpdater.IsExamine
struct UGDolphinUpdater_IsExamine_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GDolphinUpdater.Install
struct UGDolphinUpdater_Install_Params
{
};

// Function Client.GDolphinUpdater.GetTotalValue
struct UGDolphinUpdater_GetTotalValue_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GDolphinUpdater.GetCurValue
struct UGDolphinUpdater_GetCurValue_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GDolphinUpdater.GetCurStage
struct UGDolphinUpdater_GetCurStage_Params
{
	float                                              percent;                                                  // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                GetCurVal;                                                // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                GetMaxVal;                                                // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GDolphinUpdater.GetCurPercent
struct UGDolphinUpdater_GetCurPercent_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GDolphinUpdater.GetChannelIDWithHUD
struct UGDolphinUpdater_GetChannelIDWithHUD_Params
{
	class UGameFrontendHUD*                            InGameFrontendHUD;                                        // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GDolphinUpdater.GetChannelID
struct UGDolphinUpdater_GetChannelID_Params
{
	uint32_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GDolphinUpdater.FinishUpdate
struct UGDolphinUpdater_FinishUpdate_Params
{
};

// Function Client.GDolphinUpdater.FinishPufferUpdate
struct UGDolphinUpdater_FinishPufferUpdate_Params
{
};

// Function Client.GDolphinUpdater.EnableIOSBGDownload4G
struct UGDolphinUpdater_EnableIOSBGDownload4G_Params
{
	bool                                               bEnableCellularAccess;                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GDolphinUpdater.EnableCDNGetVersion
struct UGDolphinUpdater_EnableCDNGetVersion_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GDolphinUpdater.DynamicAdjustDolphinSystemParameter
struct UGDolphinUpdater_DynamicAdjustDolphinSystemParameter_Params
{
	TMap<int, struct FString>                          InConiguration;                                           // (ConstParm, Parm, ZeroConstructor)
};

// Function Client.GDolphinUpdater.ContinueUpdate
struct UGDolphinUpdater_ContinueUpdate_Params
{
};

// Function Client.GDolphinUpdater.CancelUpdate
struct UGDolphinUpdater_CancelUpdate_Params
{
};

// Function Client.GDolphinUpdater.CancelAppUpdate
struct UGDolphinUpdater_CancelAppUpdate_Params
{
};

// Function Client.AvatarItemDownloadPuffer.StartDownloadItem
struct UAvatarItemDownloadPuffer_StartDownloadItem_Params
{
	uint32_t                                           ItemId;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           Priority;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FScriptDelegate                             OnItemDownloadDelegate;                                   // (Parm, ZeroConstructor)
};

// Function Client.AvatarItemDownloadPuffer.StartBatchDownloadItem
struct UAvatarItemDownloadPuffer_StartBatchDownloadItem_Params
{
	TArray<uint32_t>                                   ItemIDs;                                                  // (Parm, ZeroConstructor)
	uint32_t                                           Priority;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FScriptDelegate                             OnBatchItemDownloadDelegate;                              // (Parm, ZeroConstructor)
};

// Function Client.GCPufferDownloader.StopTask
struct UGCPufferDownloader_StopTask_Params
{
	uint64_t                                           TaskId;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.StopMergeBinDiffPak
struct UGCPufferDownloader_StopMergeBinDiffPak_Params
{
	int                                                outterTaskID;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.StopCheckDownloadFileFraming
struct UGCPufferDownloader_StopCheckDownloadFileFraming_Params
{
	int                                                outterTaskID;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.StopBGDownloadNotification
struct UGCPufferDownloader_StopBGDownloadNotification_Params
{
};

// Function Client.GCPufferDownloader.StopAllTask
struct UGCPufferDownloader_StopAllTask_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.StartDownloadItem
struct UGCPufferDownloader_StartDownloadItem_Params
{
	uint32_t                                           ItemId;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           Priority;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FScriptDelegate                             downloadDelegate;                                         // (Parm, ZeroConstructor)
};

// Function Client.GCPufferDownloader.StartBGDownloadNotification
struct UGCPufferDownloader_StartBGDownloadNotification_Params
{
	uint64_t                                           InDownloadedSize;                                         // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GCPufferDownloader.StartBatchDownloadItem
struct UGCPufferDownloader_StartBatchDownloadItem_Params
{
	TArray<uint32_t>                                   ItemIDs;                                                  // (Parm, ZeroConstructor)
	uint32_t                                           Priority;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FScriptDelegate                             OnBatchItemDownloadDelegate;                              // (Parm, ZeroConstructor)
};

// Function Client.GCPufferDownloader.SetTempProductIdBase
struct UGCPufferDownloader_SetTempProductIdBase_Params
{
	int                                                ProductIdRaw;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GCPufferDownloader.SetPrefetchConfig
struct UGCPufferDownloader_SetPrefetchConfig_Params
{
	bool                                               pakEnable;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               fileClearEnable;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               convertEnable;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                reserveredDiskSpace;                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     FileList;                                                 // (Parm, ZeroConstructor)
	int                                                InPreFetchODPaksMaxNum;                                   // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                InPreFetchODPaksBatchSize;                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GCPufferDownloader.SetIOSBGDownloadAttribute
struct UGCPufferDownloader_SetIOSBGDownloadAttribute_Params
{
	bool                                               bEnableCellularAccess;                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bEnableResumeData;                                        // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                nMinFileSize;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                nMaxTasks;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GCPufferDownloader.SetImmDLPollingTime
struct UGCPufferDownloader_SetImmDLPollingTime_Params
{
	int                                                InPollingTime;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.SetImmDLMaxTask
struct UGCPufferDownloader_SetImmDLMaxTask_Params
{
	int                                                InMaxTask;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.SetImmDLMaxSpeed
struct UGCPufferDownloader_SetImmDLMaxSpeed_Params
{
	uint64_t                                           MaxSpeed;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.SetImmDLMaxDownloadsPerTask
struct UGCPufferDownloader_SetImmDLMaxDownloadsPerTask_Params
{
	int                                                InMaxDownloadsPerTask;                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.SetImmDLGapSize
struct UGCPufferDownloader_SetImmDLGapSize_Params
{
	int                                                InGapSize;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.SetBattleDownloadSwitch
struct UGCPufferDownloader_SetBattleDownloadSwitch_Params
{
	bool                                               Enable;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GCPufferDownloader.ReturnSplitMiniPakFilelist_LuaState
struct UGCPufferDownloader_ReturnSplitMiniPakFilelist_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.ReturnLocalFiles_LuaState
struct UGCPufferDownloader_ReturnLocalFiles_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.RequestFile
struct UGCPufferDownloader_RequestFile_Params
{
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	bool                                               ForceUpdate;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InUA;                                                     // (Parm, ZeroConstructor)
	uint64_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.RemountPakFiles
struct UGCPufferDownloader_RemountPakFiles_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.ReadFile
struct UGCPufferDownloader_ReadFile_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.GCPufferDownloader.PreFetchPakFiles
struct UGCPufferDownloader_PreFetchPakFiles_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.PreFetchODPakFilesUpdate
struct UGCPufferDownloader_PreFetchODPakFilesUpdate_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.PreFetchODPakFilesPreProcess
struct UGCPufferDownloader_PreFetchODPakFilesPreProcess_Params
{
	bool                                               Start;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.PreFetchODPakFilesPostProcess
struct UGCPufferDownloader_PreFetchODPakFilesPostProcess_Params
{
	int                                                ErrorCode;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.PreFetchODPakFiles
struct UGCPufferDownloader_PreFetchODPakFiles_Params
{
	bool                                               Start;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.OnItemDownloadedInFighting
struct UGCPufferDownloader_OnItemDownloadedInFighting_Params
{
	struct FString                                     PackHash;                                                 // (Parm, ZeroConstructor)
	struct FString                                     ErrorCode;                                                // (Parm, ZeroConstructor)
};

// Function Client.GCPufferDownloader.OnHashGenerateFinished
struct UGCPufferDownloader_OnHashGenerateFinished_Params
{
	int                                                outterTaskID;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     hashCode;                                                 // (Parm, ZeroConstructor)
};

// Function Client.GCPufferDownloader.MoveFileTo
struct UGCPufferDownloader_MoveFileTo_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	struct FString                                     from;                                                     // (Parm, ZeroConstructor)
	struct FString                                     to;                                                       // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.MoveFile
struct UGCPufferDownloader_MoveFile_Params
{
	struct FString                                     from;                                                     // (Parm, ZeroConstructor)
	struct FString                                     to;                                                       // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.MergeBinDiffPak
struct UGCPufferDownloader_MergeBinDiffPak_Params
{
	int                                                outterTaskID;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     PakFilenameOld;                                           // (Parm, ZeroConstructor)
	struct FString                                     PakFilenameDiff;                                          // (Parm, ZeroConstructor)
	struct FString                                     PakFilenameNew;                                           // (Parm, ZeroConstructor)
	bool                                               fast;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.IsODPaks
struct UGCPufferDownloader_IsODPaks_Params
{
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.IsODFileExists
struct UGCPufferDownloader_IsODFileExists_Params
{
	struct FString                                     Path;                                                     // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.IsInitSuccess
struct UGCPufferDownloader_IsInitSuccess_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.IsFileReady
struct UGCPufferDownloader_IsFileReady_Params
{
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.IsFileExist
struct UGCPufferDownloader_IsFileExist_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	struct FString                                     extension;                                                // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.InitializeODPaks
struct UGCPufferDownloader_InitializeODPaks_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.GetTempWorkPath
struct UGCPufferDownloader_GetTempWorkPath_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.GCPufferDownloader.GetProductIDBase
struct UGCPufferDownloader_GetProductIDBase_Params
{
	TArray<int>                                        ProductIDs;                                               // (Parm, OutParm, ZeroConstructor)
};

// Function Client.GCPufferDownloader.GetProductID
struct UGCPufferDownloader_GetProductID_Params
{
	TArray<int>                                        ProductIDs;                                               // (Parm, OutParm, ZeroConstructor)
};

// Function Client.GCPufferDownloader.GetODPakNum
struct UGCPufferDownloader_GetODPakNum_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.GetODPakName
struct UGCPufferDownloader_GetODPakName_Params
{
	struct FString                                     Path;                                                     // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.GCPufferDownloader.GetInitErrcode
struct UGCPufferDownloader_GetInitErrcode_Params
{
	uint32_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.GetFileSizeCompressed
struct UGCPufferDownloader_GetFileSizeCompressed_Params
{
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	uint64_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.GetFileSize
struct UGCPufferDownloader_GetFileSize_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.GetDownloadPath
struct UGCPufferDownloader_GetDownloadPath_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.GCPufferDownloader.GetCurrentSpeed
struct UGCPufferDownloader_GetCurrentSpeed_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.GetBatchODPaksDownloadList_LuaState
struct UGCPufferDownloader_GetBatchODPaksDownloadList_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.EnableUseOldInterface
struct UGCPufferDownloader_EnableUseOldInterface_Params
{
	bool                                               Enable;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.GCPufferDownloader.DynamicAdjustPufferSystemParameter
struct UGCPufferDownloader_DynamicAdjustPufferSystemParameter_Params
{
	int                                                InPufferParameterKey;                                     // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InPufferParameterValue;                                   // (Parm, ZeroConstructor)
};

// Function Client.GCPufferDownloader.DeleteFileEvenIfUnfinished
struct UGCPufferDownloader_DeleteFileEvenIfUnfinished_Params
{
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.DeleteFile
struct UGCPufferDownloader_DeleteFile_Params
{
	struct FString                                     fullPath;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.ConvertPreFetchFiles
struct UGCPufferDownloader_ConvertPreFetchFiles_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.ConvertItemIdToPakName
struct UGCPufferDownloader_ConvertItemIdToPakName_Params
{
	uint32_t                                           ItemId;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.GCPufferDownloader.ClearUselessODPaks
struct UGCPufferDownloader_ClearUselessODPaks_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.ClearPreFetchODPaksFiles
struct UGCPufferDownloader_ClearPreFetchODPaksFiles_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.ClearPreFetchFiles
struct UGCPufferDownloader_ClearPreFetchFiles_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GCPufferDownloader.CheckDownloadFileFraming
struct UGCPufferDownloader_CheckDownloadFileFraming_Params
{
	int                                                outterTaskID;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	int                                                chunkSize;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.GMLogShare.ShareLogFile
struct UGMLogShare_ShareLogFile_Params
{
	struct FString                                     InLogFileName;                                            // (Parm, ZeroConstructor)
};

// Function Client.GMLogShare.Init
struct UGMLogShare_Init_Params
{
};

// Function Client.IMSDKNotice.GetNotice
struct UIMSDKNotice_GetNotice_Params
{
	struct FString                                     Scene;                                                    // (Parm, ZeroConstructor)
	TArray<struct FIMSDKNoticeInfo>                    ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.IMSDKNotice.GetInstance
struct UIMSDKNotice_GetInstance_Params
{
	class UIMSDKNotice*                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.IMSDKNotice.ClearNotice
struct UIMSDKNotice_ClearNotice_Params
{
};

// Function Client.HttpWrapper.SimplePostForLua
struct UHttpWrapper_SimplePostForLua_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
	int                                                Priority;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                QueueType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.HttpWrapper.SetQueueSize
struct UHttpWrapper_SetQueueSize_Params
{
	int                                                QueueType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                InSize;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.HttpWrapper.SetQueueEnable
struct UHttpWrapper_SetQueueEnable_Params
{
	bool                                               InEnableQueue;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.HttpWrapper.SetPoolEnable
struct UHttpWrapper_SetPoolEnable_Params
{
	bool                                               InEnablePool;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.HttpWrapper.RequestForLua
struct UHttpWrapper_RequestForLua_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Verb;                                                     // (Parm, ZeroConstructor)
	TMap<struct FString, struct FString>               Headers;                                                  // (Parm, OutParm, ZeroConstructor)
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
	int                                                Priority;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                QueueType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.HttpWrapper.ImageDownloadRequestForLua
struct UHttpWrapper_ImageDownloadRequestForLua_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Verb;                                                     // (Parm, ZeroConstructor)
	TMap<struct FString, struct FString>               Headers;                                                  // (Parm, OutParm, ZeroConstructor)
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
	int                                                Priority;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.HttpWrapper.GetQueueEnable
struct UHttpWrapper_GetQueueEnable_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.HttpWrapper.GetPoolEnable
struct UHttpWrapper_GetPoolEnable_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.HttpWrapper.GetInternalIndex
struct UHttpWrapper_GetInternalIndex_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.HttpWrapper.CancelRequestAll
struct UHttpWrapper_CancelRequestAll_Params
{
	int                                                QueueType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.HttpWrapper.CancelRequest
struct UHttpWrapper_CancelRequest_Params
{
	int                                                QueueType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReqIndex;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ImageDownloader.Start
struct UImageDownloader_Start_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
};

// Function Client.ImageDownloader.MakeDownloaderInGame
struct UImageDownloader_MakeDownloaderInGame_Params
{
	class UImageDownloader*                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ImageDownloader.MakeDownloader
struct UImageDownloader_MakeDownloader_Params
{
	class UImageDownloader*                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ImageDownloader.GetTextureFromUrlWithoutDownload
struct UImageDownloader_GetTextureFromUrlWithoutDownload_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	class UTexture2D*                                  ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ImageDownloader.CheckAndGetEncryptUrl
struct UImageDownloader_CheckAndGetEncryptUrl_Params
{
	struct FString                                     InURL;                                                    // (Parm, OutParm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ImageDownloadUtil.SaveImageDownloadDiskFile
struct UImageDownloadUtil_SaveImageDownloadDiskFile_Params
{
	TArray<unsigned char>                              OutArray;                                                 // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     SavePath;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ImageDownloadUtil.GetTextureFromMemory
struct UImageDownloadUtil_GetTextureFromMemory_Params
{
	struct FString                                     PathName;                                                 // (Parm, ZeroConstructor)
	class UTexture2D*                                  ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ImageDownloadUtil.GetTexture2DFromDisk
struct UImageDownloadUtil_GetTexture2DFromDisk_Params
{
	struct FString                                     SavePath;                                                 // (Parm, ZeroConstructor)
	bool                                               IsCompressed;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ImageDownloadUtil.GetTexture2DFromArray
struct UImageDownloadUtil_GetTexture2DFromArray_Params
{
	TArray<unsigned char>                              OutArray;                                                 // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	bool                                               IsCompressed;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ImageDownloadUtil.GetLocalImageFormat
struct UImageDownloadUtil_GetLocalImageFormat_Params
{
	struct FString                                     Path;                                                     // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ImageDownloadUtil.CheckDiskFile
struct UImageDownloadUtil_CheckDiskFile_Params
{
	struct FString                                     ImgDir;                                                   // (Parm, ZeroConstructor)
	struct FString                                     SubDir;                                                   // (Parm, ZeroConstructor)
};

// Function Client.InGameUIManager.SubUIWidgetListWithMountData
struct UInGameUIManager_SubUIWidgetListWithMountData_Params
{
	TArray<struct FInGameWidgetData>                   InGameWidgetDataList;                                     // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	TArray<struct FString>                             GameStatusStrList;                                        // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	bool                                               InPersistentUI;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               InUsedByControler;                                        // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               InOberverOnly;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                inUIControlState;                                         // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.InGameUIManager.SubUIWidgetList
struct UInGameUIManager_SubUIWidgetList_Params
{
	TArray<struct FGameWidgetConfig>                   InWidgetConfigList;                                       // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	TArray<struct FString>                             GameStatusStrList;                                        // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	bool                                               InPersistentUI;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               InUsedByControler;                                        // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               InOberverOnly;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.InGameUIManager.SubDynamicUIWidgetList
struct UInGameUIManager_SubDynamicUIWidgetList_Params
{
	TArray<struct FDynamicWidgetData>                  DynamicWidgetMap;                                         // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function Client.InGameUIManager.OnAsyncLoadWidgetClassObj
struct UInGameUIManager_OnAsyncLoadWidgetClassObj_Params
{
	class UObject*                                     InClassObj;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                RequestID;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.InGameUIManager.HandleUIMessage
struct UInGameUIManager_HandleUIMessage_Params
{
	struct FString                                     UIMessage;                                                // (Parm, ZeroConstructor)
};

// Function Client.InGameUIManager.HandleMountWidget
struct UInGameUIManager_HandleMountWidget_Params
{
	class UInGameUIManager*                            IngameManager;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.InGameUIManager.HandleDynamicDestroy
struct UInGameUIManager_HandleDynamicDestroy_Params
{
};

// Function Client.InGameUIManager.HandleDynamicCreation
struct UInGameUIManager_HandleDynamicCreation_Params
{
	bool                                               isAsyncLoad;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.InGameUIManager.GetWidgetHandleAsyncWithCallBack
struct UInGameUIManager_GetWidgetHandleAsyncWithCallBack_Params
{
	struct FString                                     WidgetKey;                                                // (Parm, ZeroConstructor)
	struct FScriptDelegate                             InCallback;                                               // (Parm, ZeroConstructor)
};

// Function Client.InGameUIManager.GetWidgetHandle
struct UInGameUIManager_GetWidgetHandle_Params
{
	struct FString                                     WidgetKey;                                                // (Parm, ZeroConstructor)
	class UUAEUserWidget*                              ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.InGameUIManager.GetMountCanvasPanel
struct UInGameUIManager_GetMountCanvasPanel_Params
{
	struct FString                                     MountOuterName;                                           // (Parm, ZeroConstructor)
	struct FString                                     MountName;                                                // (Parm, ZeroConstructor)
	class UCanvasPanel*                                ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.InGameUIManager.ChangeSubUIWidgetList
struct UInGameUIManager_ChangeSubUIWidgetList_Params
{
	TArray<struct FGameWidgetConfig>                   InWidgetConfigList;                                       // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function Client.IntlSDKComplianceHelper.SetUserProfile
struct UIntlSDKComplianceHelper_SetUserProfile_Params
{
	struct FString                                     InRegion;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.IntlSDKComplianceHelper.SetParentStatus
struct UIntlSDKComplianceHelper_SetParentStatus_Params
{
	int                                                ParentCertificateStatus;                                  // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.IntlSDKComplianceHelper.SetLogConfig
struct UIntlSDKComplianceHelper_SetLogConfig_Params
{
	bool                                               enableConsoleLog;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               enableFileLog;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                LogLevel;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.IntlSDKComplianceHelper.SetEUAgreeStatus
struct UIntlSDKComplianceHelper_SetEUAgreeStatus_Params
{
	int                                                AgreeStatus;                                              // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.IntlSDKComplianceHelper.SetAdulthood
struct UIntlSDKComplianceHelper_SetAdulthood_Params
{
	int                                                AgeStatus;                                                // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.IntlSDKComplianceHelper.SendVoiceControlEmail
struct UIntlSDKComplianceHelper_SendVoiceControlEmail_Params
{
	struct FString                                     InEmail;                                                  // (Parm, ZeroConstructor)
	struct FString                                     InUserName;                                               // (Parm, ZeroConstructor)
};

// Function Client.IntlSDKComplianceHelper.SendEmail
struct UIntlSDKComplianceHelper_SendEmail_Params
{
	struct FString                                     InEmail;                                                  // (Parm, ZeroConstructor)
	struct FString                                     UserName;                                                 // (Parm, ZeroConstructor)
};

// Function Client.IntlSDKComplianceHelper.QueryUserStatus
struct UIntlSDKComplianceHelper_QueryUserStatus_Params
{
};

// Function Client.IntlSDKComplianceHelper.QueryIsEEA
struct UIntlSDKComplianceHelper_QueryIsEEA_Params
{
	struct FString                                     InRegion;                                                 // (Parm, ZeroConstructor)
};

// Function Client.IntlSDKComplianceHelper.QueryConfig
struct UIntlSDKComplianceHelper_QueryConfig_Params
{
};

// Function Client.IntlSDKComplianceHelper.OnMSDKEvnSwitched
struct UIntlSDKComplianceHelper_OnMSDKEvnSwitched_Params
{
	int                                                Env;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.IntlSDKComplianceHelper.GetInstance
struct UIntlSDKComplianceHelper_GetInstance_Params
{
	class UIntlSDKComplianceHelper*                    ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.IntlSDKComplianceHelper.ComplianceInit
struct UIntlSDKComplianceHelper_ComplianceInit_Params
{
};

// Function Client.IntlSDKComplianceHelper.CommitBirthday
struct UIntlSDKComplianceHelper_CommitBirthday_Params
{
	struct FString                                     InBirthday;                                               // (Parm, ZeroConstructor)
};

// Function Client.IntlSDKComplianceHelper.ChangeRegion
struct UIntlSDKComplianceHelper_ChangeRegion_Params
{
	struct FString                                     InRegion;                                                 // (Parm, ZeroConstructor)
};

// Function Client.LiveBroadcast.SetFullScreen
struct ULiveBroadcast_SetFullScreen_Params
{
	bool                                               FullScreen;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.LiveBroadcast.OpenLiveBroadcast
struct ULiveBroadcast_OpenLiveBroadcast_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	float                                              Margin;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.LiveBroadcast.GetInstance
struct ULiveBroadcast_GetInstance_Params
{
	class ULiveBroadcast*                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.LiveBroadcast.CloseWebView
struct ULiveBroadcast_CloseWebView_Params
{
};

// Function Client.LiveBroadcast.C2JSetString
struct ULiveBroadcast_C2JSetString_Params
{
	struct FString                                     str;                                                      // (Parm, ZeroConstructor)
};

// Function Client.LiveBroadcast.C2JSetIndex
struct ULiveBroadcast_C2JSetIndex_Params
{
	int                                                Index;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.LoadTexture.LoadTexture2D
struct ULoadTexture_LoadTexture2D_Params
{
	struct FString                                     ImagePath;                                                // (Parm, ZeroConstructor)
	bool                                               IsValid;                                                  // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                OutWidth;                                                 // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                OutHeight;                                                // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.LoadTexture.GetTexture2DFromDiskFile
struct ULoadTexture_GetTexture2DFromDiskFile_Params
{
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	class UTexture2D*                                  ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.LobbyChatSecurity.GetKey
struct ULobbyChatSecurity_GetKey_Params
{
	struct FString                                     OpenID;                                                   // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.LobbyDecalBakingComponent.SwitchDecalParam
struct ULobbyDecalBakingComponent_SwitchDecalParam_Params
{
	int                                                from;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                to;                                                       // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.LobbyDecalBakingComponent.SavePng
struct ULobbyDecalBakingComponent_SavePng_Params
{
	class USceneCaptureComponent2D*                    SceneCapComp;                                             // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FString                                     ImagePath;                                                // (ConstParm, Parm, ZeroConstructor)
	struct FLinearColor                                ClearColor;                                               // (ConstParm, Parm, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.LobbyDecalBakingComponent.ReplaceOneDecalParam
struct ULobbyDecalBakingComponent_ReplaceOneDecalParam_Params
{
	class UStaticMeshComponent*                        MeshComp;                                                 // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                Index;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	class UDecalBakingParameterComponent*              DecalParamComponent;                                      // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function Client.LobbyDecalBakingComponent.Init
struct ULobbyDecalBakingComponent_Init_Params
{
};

// Function Client.LobbyDecalBakingComponent.DelOneDecalParam
struct ULobbyDecalBakingComponent_DelOneDecalParam_Params
{
	int                                                Index;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.LobbyDecalBakingComponent.Baking
struct ULobbyDecalBakingComponent_Baking_Params
{
	class UStaticMeshComponent*                        MeshComp;                                                 // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UMaterial*                                   DecaledMaterial;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               Async;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.LobbyDecalBakingComponent.AddOneDecalParam
struct ULobbyDecalBakingComponent_AddOneDecalParam_Params
{
	class UStaticMeshComponent*                        MeshComp;                                                 // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UDecalBakingParameterComponent*              DecalParamComponent;                                      // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function Client.LobbyMatChgActor.ChangeMaterialToIdx
struct ALobbyMatChgActor_ChangeMaterialToIdx_Params
{
	int                                                idx;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.LobbyModelUtils.TickAndRefreshBoneForGivenSkMeshComp
struct ULobbyModelUtils_TickAndRefreshBoneForGivenSkMeshComp_Params
{
	class USkeletalMeshComponent*                      InSkMesh;                                                 // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function Client.LobbyModelUtils.GetActorBoundingBox
struct ULobbyModelUtils_GetActorBoundingBox_Params
{
	class AActor*                                      InActor;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               EnableDrawDebugBox;                                       // (Parm, ZeroConstructor, IsPlainOldData)
	struct FAABBBox                                    ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function Client.LobbyModelUtils.DeprojectScreenToWorldFast
struct ULobbyModelUtils_DeprojectScreenToWorldFast_Params
{
	class APlayerController*                           Player;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FVector2D                                   ScreenPosition;                                           // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
	struct FVector                                     WorldPosition;                                            // (Parm, OutParm, IsPlainOldData)
	struct FVector                                     WorldDirection;                                           // (Parm, OutParm, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.LobbySceneCaptureActor.ResizeRT
struct ALobbySceneCaptureActor_ResizeRT_Params
{
};

// Function Client.LobbySceneCaptureActor.LogError
struct ALobbySceneCaptureActor_LogError_Params
{
	struct FString                                     FilePath;                                                 // (ConstParm, Parm, ZeroConstructor)
};

// Function Client.LobbySceneCaptureActor.Capture
struct ALobbySceneCaptureActor_Capture_Params
{
};

// Function Client.LuaBlueprintLibrary.StringToLVar
struct ULuaBlueprintLibrary_StringToLVar_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Value;                                                    // (Parm, ZeroConstructor)
	struct FLuaBPVar                                   ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function Client.LuaBlueprintLibrary.SetMemAllocLog
struct ULuaBlueprintLibrary_SetMemAllocLog_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bMemAllocLog;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.LuaBlueprintLibrary.RequireAndCallLuaWithArgs
struct ULuaBlueprintLibrary_RequireAndCallLuaWithArgs_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ModulePath;                                               // (Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     FunctionName;                                             // (Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FLuaBPVar                                   InA;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   InB;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   InC;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   InD;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   OutA;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutB;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutC;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutD;                                                     // (Parm, OutParm)
};

// Function Client.LuaBlueprintLibrary.ObjectToLVar
struct ULuaBlueprintLibrary_ObjectToLVar_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	class UObject*                                     O;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLuaBPVar                                   ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function Client.LuaBlueprintLibrary.LVarToString
struct ULuaBlueprintLibrary_LVarToString_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FLuaBPVar                                   Value;                                                    // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.LuaBlueprintLibrary.LVarToObject
struct ULuaBlueprintLibrary_LVarToObject_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FLuaBPVar                                   Value;                                                    // (ConstParm, Parm, OutParm, ReferenceParm)
	class UObject*                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.LuaBlueprintLibrary.LVarToInt
struct ULuaBlueprintLibrary_LVarToInt_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FLuaBPVar                                   Value;                                                    // (ConstParm, Parm, OutParm, ReferenceParm)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.LuaBlueprintLibrary.LVarToFloat
struct ULuaBlueprintLibrary_LVarToFloat_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FLuaBPVar                                   Value;                                                    // (ConstParm, Parm, OutParm, ReferenceParm)
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.LuaBlueprintLibrary.LVarToBool
struct ULuaBlueprintLibrary_LVarToBool_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FLuaBPVar                                   Value;                                                    // (ConstParm, Parm, OutParm, ReferenceParm)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.LuaBlueprintLibrary.IntToLVar
struct ULuaBlueprintLibrary_IntToLVar_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	int                                                Value;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLuaBPVar                                   ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function Client.LuaBlueprintLibrary.FloatToLVar
struct ULuaBlueprintLibrary_FloatToLVar_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	float                                              Value;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLuaBPVar                                   ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function Client.LuaBlueprintLibrary.CallLuaWithMultiArgs
struct ULuaBlueprintLibrary_CallLuaWithMultiArgs_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Function;                                                 // (Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FLuaBPVar                                   InA;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   InB;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   InC;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   InD;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   InE;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   InF;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   OutA;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutB;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutC;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutD;                                                     // (Parm, OutParm)
};

// Function Client.LuaBlueprintLibrary.CallLuaWithHUD
struct ULuaBlueprintLibrary_CallLuaWithHUD_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Function;                                                 // (Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FLuaBPVar                                   InA;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   InB;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   InC;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   InD;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   OutA;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutB;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutC;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutD;                                                     // (Parm, OutParm)
};

// Function Client.LuaBlueprintLibrary.CallLuaWithArgs
struct ULuaBlueprintLibrary_CallLuaWithArgs_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Function;                                                 // (Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FLuaBPVar                                   InA;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   InB;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   InC;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   InD;                                                      // (ConstParm, Parm, OutParm, ReferenceParm)
	struct FLuaBPVar                                   OutA;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutB;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutC;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutD;                                                     // (Parm, OutParm)
};

// Function Client.LuaBlueprintLibrary.CallLua
struct ULuaBlueprintLibrary_CallLua_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Function;                                                 // (Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FLuaBPVar                                   OutA;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutB;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutC;                                                     // (Parm, OutParm)
	struct FLuaBPVar                                   OutD;                                                     // (Parm, OutParm)
};

// Function Client.LuaBlueprintLibrary.BoolToLVar
struct ULuaBlueprintLibrary_BoolToLVar_Params
{
	class UObject*                                     WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               Value;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLuaBPVar                                   ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function Client.LuaBlueprintMgr.GetSystemByName
struct ULuaBlueprintMgr_GetSystemByName_Params
{
	struct FString                                     SystemName;                                               // (ConstParm, Parm, ZeroConstructor)
	class ULuaBluepirntSys*                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.LuaBlueprintMgr.AddSystem
struct ULuaBlueprintMgr_AddSystem_Params
{
	struct FString                                     SystemName;                                               // (ConstParm, Parm, ZeroConstructor)
	struct FString                                     BPPath;                                                   // (ConstParm, Parm, ZeroConstructor)
};

// Function Client.LuaBluepirntSys.Init
struct ULuaBluepirntSys_Init_Params
{
};

// Function Client.LuaClassObj.SubUIWidgetList
struct ALuaClassObj_SubUIWidgetList_Params
{
	TArray<struct FGameWidgetConfig>                   InWidgetConfigList;                                       // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	TArray<struct FString>                             GameStatusStrList;                                        // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	bool                                               bPersistentUI;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               InStatusConcern;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bDynamicWidget;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bKeepDynamicWidget;                                       // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.LuaClassObj.SubShowHideEvent
struct ALuaClassObj_SubShowHideEvent_Params
{
	TArray<struct FString>                             WidgetPathList;                                           // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function Client.LuaClassObj.SubDefaultSceneCamera
struct ALuaClassObj_SubDefaultSceneCamera_Params
{
	int                                                sceneCameraIndex;                                         // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.LuaClassObj.SubDefaultChildUI
struct ALuaClassObj_SubDefaultChildUI_Params
{
	TArray<struct FString>                             childList;                                                // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function Client.LuaClassObj.SubDefaultBaseUI
struct ALuaClassObj_SubDefaultBaseUI_Params
{
	struct FString                                     baseUI;                                                   // (Parm, ZeroConstructor)
};

// Function Client.LuaClassObj.SubCollapseWidgetList
struct ALuaClassObj_SubCollapseWidgetList_Params
{
	struct FString                                     RootWidgetName;                                           // (Parm, ZeroConstructor)
	TArray<struct FString>                             ChildWidgetNames;                                         // (Parm, OutParm, ZeroConstructor)
};

// Function Client.LuaClassObj.SetWidgetZorder
struct ALuaClassObj_SetWidgetZorder_Params
{
	int                                                Index;                                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	int                                                ZOrder;                                                   // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.LuaClassObj.RestoreWidgetZorder
struct ALuaClassObj_RestoreWidgetZorder_Params
{
	int                                                Index;                                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.LuaClassObj.RestoreAllWidgetZorder
struct ALuaClassObj_RestoreAllWidgetZorder_Params
{
};

// Function Client.LuaClassObj.IsTopStackPanel
struct ALuaClassObj_IsTopStackPanel_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.LuaClassObj.IsPushedPanel
struct ALuaClassObj_IsPushedPanel_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.LuaClassObj.HandleUIMessageNoFetch
struct ALuaClassObj_HandleUIMessageNoFetch_Params
{
	struct FString                                     UIMessage;                                                // (Parm, ZeroConstructor)
};

// Function Client.LuaClassObj.HandleUIMessage
struct ALuaClassObj_HandleUIMessage_Params
{
	struct FString                                     UIMessage;                                                // (Parm, ZeroConstructor)
};

// Function Client.LuaClassObj.HandleStopAsyncLoad
struct ALuaClassObj_HandleStopAsyncLoad_Params
{
};

// Function Client.LuaClassObj.HandleDynamicDestroy
struct ALuaClassObj_HandleDynamicDestroy_Params
{
};

// Function Client.LuaClassObj.HandleDynamicCreationInternal
struct ALuaClassObj_HandleDynamicCreationInternal_Params
{
	bool                                               isAsyncLoad;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.LuaClassObj.HandleDynamicCreation
struct ALuaClassObj_HandleDynamicCreation_Params
{
	bool                                               isAsyncLoad;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.LuaClassObj.HandleCollapseWidgetList
struct ALuaClassObj_HandleCollapseWidgetList_Params
{
	struct FString                                     RootWidgetName;                                           // (Parm, ZeroConstructor)
};

// Function Client.LuaClassObj.GetTopStackPanelSrcTag
struct ALuaClassObj_GetTopStackPanelSrcTag_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.LuaClassObj.GetTopStackPanelDstTag
struct ALuaClassObj_GetTopStackPanelDstTag_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.LuaClassObj.GetGameStatus
struct ALuaClassObj_GetGameStatus_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.LuaClassObj.ChangeSubUIWidgetList
struct ALuaClassObj_ChangeSubUIWidgetList_Params
{
	TArray<struct FGameWidgetConfig>                   InWidgetConfigList;                                       // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function Client.LuaClassObj.AddToTopStackPanel
struct ALuaClassObj_AddToTopStackPanel_Params
{
};

// Function Client.MaskBox.SetMaskTransformScale
struct UMaskBox_SetMaskTransformScale_Params
{
	struct FVector2D                                   Scale;                                                    // (Parm, IsPlainOldData)
};

// Function Client.MaskBox.SetMaskTransformPivot
struct UMaskBox_SetMaskTransformPivot_Params
{
	struct FVector2D                                   Pivot;                                                    // (Parm, IsPlainOldData)
};

// Function Client.MaskBox.SetMaskTransformAngle
struct UMaskBox_SetMaskTransformAngle_Params
{
	float                                              Angle;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.MaskBox.SetMaskMaterial
struct UMaskBox_SetMaskMaterial_Params
{
	class UMaterialInterface*                          EffectMaterial;                                           // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.MaskBox.SetBrushFromTexture
struct UMaskBox_SetBrushFromTexture_Params
{
	class UTexture2D*                                  Texture;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// DelegateFunction Client.MaskBox.GetVector2D__DelegateSignature
struct UMaskBox_GetVector2D__DelegateSignature_Params
{
	struct FVector2D                                   ReturnValue;                                              // (Parm, OutParm, ReturnParm, IsPlainOldData)
};

// Function Client.MaskBox.GetMaskMaterial
struct UMaskBox_GetMaskMaterial_Params
{
	class UMaterialInstanceDynamic*                    ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.MaskImage.SetMaskTransformScale
struct UMaskImage_SetMaskTransformScale_Params
{
	struct FVector2D                                   Scale;                                                    // (Parm, IsPlainOldData)
};

// Function Client.MaskImage.SetMaskTransformPivot
struct UMaskImage_SetMaskTransformPivot_Params
{
	struct FVector2D                                   Pivot;                                                    // (Parm, IsPlainOldData)
};

// Function Client.MaskImage.SetMaskTransformAngle
struct UMaskImage_SetMaskTransformAngle_Params
{
	float                                              Angle;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.MaskImage.SetMaskTexture
struct UMaskImage_SetMaskTexture_Params
{
	class UTexture2D*                                  Texture;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.MaskImage.SetMaskMaterial
struct UMaskImage_SetMaskMaterial_Params
{
	class UMaterialInterface*                          InEffectMaterial;                                         // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.MaskImage.GetMaskMaterial
struct UMaskImage_GetMaskMaterial_Params
{
	class UMaterialInstanceDynamic*                    ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.NewButton.SetClickSound
struct UNewButton_SetClickSound_Params
{
	EButtonClickSoundTypes                             inSoundType;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.PandoraV2Helper.SetUserData
struct UPandoraV2Helper_SetUserData_Params
{
	TMap<struct FString, struct FString>               InUserdata;                                               // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function Client.PandoraV2Helper.SetSDKVersion
struct UPandoraV2Helper_SetSDKVersion_Params
{
	int                                                InSDKVer;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.PandoraV2Helper.SetSDKCoreDataPath
struct UPandoraV2Helper_SetSDKCoreDataPath_Params
{
	struct FString                                     InPath;                                                   // (Parm, ZeroConstructor)
};

// Function Client.PandoraV2Helper.SetPandoraEnable
struct UPandoraV2Helper_SetPandoraEnable_Params
{
	bool                                               Enable;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.PandoraV2Helper.SetLogEnable
struct UPandoraV2Helper_SetLogEnable_Params
{
	bool                                               Enable;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.PandoraV2Helper.RefreshUserDataTokens
struct UPandoraV2Helper_RefreshUserDataTokens_Params
{
};

// Function Client.PandoraV2Helper.Init
struct UPandoraV2Helper_Init_Params
{
	bool                                               InEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                InEnv;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               InEnablePixUI;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.PandoraV2Helper.GetSDKVersion
struct UPandoraV2Helper_GetSDKVersion_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.PandoraV2Helper.Get
struct UPandoraV2Helper_Get_Params
{
	class UPandoraV2Helper*                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.PandoraV2Helper.Do
struct UPandoraV2Helper_Do_Params
{
	struct FString                                     InCmdJson;                                                // (Parm, ZeroConstructor)
	int                                                InMsgType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.PandoraV2Helper.Deinit
struct UPandoraV2Helper_Deinit_Params
{
};

// Function Client.PandoraV2Helper.Close
struct UPandoraV2Helper_Close_Params
{
};

// Function Client.PublishAreaMgr.SelectArea
struct UPublishAreaMgr_SelectArea_Params
{
	struct FString                                     InArea;                                                   // (Parm, ZeroConstructor)
};

// Function Client.PublishAreaMgr.IsMultiAreaBuild
struct UPublishAreaMgr_IsMultiAreaBuild_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.PublishAreaMgr.GetString
struct UPublishAreaMgr_GetString_Params
{
	struct FString                                     InKey;                                                    // (Parm, ZeroConstructor)
	struct FString                                     InDefaultValue;                                           // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.PublishAreaMgr.GetPublishAreas
struct UPublishAreaMgr_GetPublishAreas_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.PublishAreaMgr.GetInt
struct UPublishAreaMgr_GetInt_Params
{
	struct FString                                     InKey;                                                    // (Parm, ZeroConstructor)
	int                                                InDefaultValue;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.PublishAreaMgr.GetBool
struct UPublishAreaMgr_GetBool_Params
{
	struct FString                                     InKey;                                                    // (Parm, ZeroConstructor)
	bool                                               InDefaultValue;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.PublishAreaMgr.GetArea
struct UPublishAreaMgr_GetArea_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.SavedFileUtil.GetFileCreationTime
struct USavedFileUtil_GetFileCreationTime_Params
{
	struct FString                                     Filename;                                                 // (ConstParm, Parm, ZeroConstructor)
	int64_t                                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SavedFileUtil.GetDirSizeAsync
struct USavedFileUtil_GetDirSizeAsync_Params
{
	struct FString                                     Dir;                                                      // (ConstParm, Parm, ZeroConstructor)
	bool                                               Recursive;                                                // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FSluaBPVar                                  Callback;                                                 // (ConstParm, Parm)
};

// Function Client.SavedFileUtil.GetDirSize
struct USavedFileUtil_GetDirSize_Params
{
	struct FString                                     Dir;                                                      // (ConstParm, Parm, ZeroConstructor)
	bool                                               Recursive;                                                // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	int64_t                                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SavedFileUtil.FindFilesAsync
struct USavedFileUtil_FindFilesAsync_Params
{
	struct FString                                     Dir;                                                      // (ConstParm, Parm, ZeroConstructor)
	struct FString                                     Pattern;                                                  // (ConstParm, Parm, ZeroConstructor)
	bool                                               Recursive;                                                // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FSluaBPVar                                  Callback;                                                 // (ConstParm, Parm)
};

// Function Client.SavedFileUtil.FindFiles
struct USavedFileUtil_FindFiles_Params
{
	struct FString                                     dirPath;                                                  // (ConstParm, Parm, ZeroConstructor)
	struct FString                                     extension;                                                // (ConstParm, Parm, ZeroConstructor)
	bool                                               Recursive;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.SavedFileUtil.DeleteDirectoryAsync
struct USavedFileUtil_DeleteDirectoryAsync_Params
{
	struct FString                                     Dir;                                                      // (ConstParm, Parm, ZeroConstructor)
	struct FSluaBPVar                                  Callback;                                                 // (ConstParm, Parm)
};

// Function Client.SavedFileUtil.CancelLoadSavedImage
struct USavedFileUtil_CancelLoadSavedImage_Params
{
	int                                                Handle;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SavedFileUtil.AsyncLoadSavedImage
struct USavedFileUtil_AsyncLoadSavedImage_Params
{
	struct FString                                     AssetPath;                                                // (Parm, ZeroConstructor)
	bool                                               IsCompressed;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	struct FSluaBPVar                                  Callback;                                                 // (Parm)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScreenInput.Shutdown
struct UScreenInput_Shutdown_Params
{
};

// DelegateFunction Client.ScreenInput.OnScreenTouch__DelegateSignature
struct UScreenInput_OnScreenTouch__DelegateSignature_Params
{
};

// DelegateFunction Client.ScreenInput.OnMouseButtonDown__DelegateSignature
struct UScreenInput_OnMouseButtonDown__DelegateSignature_Params
{
	struct FVector2D                                   ContainerPos;                                             // (ConstParm, Parm, OutParm, ReferenceParm, IsPlainOldData)
};

// DelegateFunction Client.ScreenInput.OnMotionDetected__DelegateSignature
struct UScreenInput_OnMotionDetected__DelegateSignature_Params
{
	struct FVector                                     Tilt;                                                     // (ConstParm, Parm, IsPlainOldData)
	struct FVector                                     RotationRate;                                             // (ConstParm, Parm, IsPlainOldData)
	struct FVector                                     Gravity;                                                  // (ConstParm, Parm, IsPlainOldData)
	struct FVector                                     Acceleration;                                             // (ConstParm, Parm, IsPlainOldData)
};

// Function Client.ScreenInput.Init
struct UScreenInput_Init_Params
{
};

// Function Client.ScreenshotMaker.SetDefaultShowUI
struct UScreenshotMaker_SetDefaultShowUI_Params
{
	bool                                               ShowUI;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScreenshotMaker.SaveToPhotosAlbumEx
struct UScreenshotMaker_SaveToPhotosAlbumEx_Params
{
	struct FString                                     pathStr;                                                  // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScreenshotMaker.SaveToPhotosAlbum
struct UScreenshotMaker_SaveToPhotosAlbum_Params
{
	struct FString                                     pathStr;                                                  // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScreenshotMaker.ResizePicture
struct UScreenshotMaker_ResizePicture_Params
{
	struct FString                                     pathStr;                                                  // (Parm, ZeroConstructor)
	float                                              Scale;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     savePathStr;                                              // (Parm, ZeroConstructor)
};

// Function Client.ScreenshotMaker.ReMakePicture
struct UScreenshotMaker_ReMakePicture_Params
{
	struct FString                                     pathStr;                                                  // (Parm, ZeroConstructor)
	struct FVector4                                    Vector4;                                                  // (Parm, IsPlainOldData)
};

// Function Client.ScreenshotMaker.ReMakeMomentPicture
struct UScreenshotMaker_ReMakeMomentPicture_Params
{
	struct FString                                     srcPath;                                                  // (Parm, ZeroConstructor)
	struct FVector4                                    Vector4;                                                  // (Parm, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScreenshotMaker.MosaicPictureByLocalImage
struct UScreenshotMaker_MosaicPictureByLocalImage_Params
{
	TArray<struct FString>                             Paths;                                                    // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     toPath;                                                   // (Parm, ZeroConstructor)
	int                                                Width;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              Scale;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScreenshotMaker.MakeWidgetScreenshot
struct UScreenshotMaker_MakeWidgetScreenshot_Params
{
	class UWidget*                                     Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FVector2D                                   DrawSize;                                                 // (Parm, IsPlainOldData)
	float                                              Scale;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	class UTextureRenderTarget2D*                      ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScreenshotMaker.MakePictureWithName
struct UScreenshotMaker_MakePictureWithName_Params
{
	struct FString                                     PicName;                                                  // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScreenshotMaker.MakePictureToLua
struct UScreenshotMaker_MakePictureToLua_Params
{
	class UGameFrontendHUD*                            InFrontendHUD;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     tableName;                                                // (Parm, ZeroConstructor)
	struct FString                                     FunctionName;                                             // (Parm, ZeroConstructor)
	bool                                               isShowUI;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScreenshotMaker.MakePictureByName
struct UScreenshotMaker_MakePictureByName_Params
{
	struct FString                                     PicName;                                                  // (Parm, ZeroConstructor)
	bool                                               ShowUI;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScreenshotMaker.MakePicture
struct UScreenshotMaker_MakePicture_Params
{
	bool                                               isShowUI;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScreenshotMaker.MakeBugReprotPic
struct UScreenshotMaker_MakeBugReprotPic_Params
{
	bool                                               isShowUI;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScreenshotMaker.HasCaptured
struct UScreenshotMaker_HasCaptured_Params
{
	struct FString                                     pathStr;                                                  // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScreenshotMaker.GetSaveStatus
struct UScreenshotMaker_GetSaveStatus_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScreenshotMaker.GetPhotoHash
struct UScreenshotMaker_GetPhotoHash_Params
{
	struct FString                                     pathStr;                                                  // (Parm, ZeroConstructor)
	int                                                algorithmVersion;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScreenshotMaker.GetMomentThumbPictureFullPathFiles
struct UScreenshotMaker_GetMomentThumbPictureFullPathFiles_Params
{
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScreenshotMaker.GetMomentPictureFullPathFiles
struct UScreenshotMaker_GetMomentPictureFullPathFiles_Params
{
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScreenshotMaker.GetHashFromArray
struct UScreenshotMaker_GetHashFromArray_Params
{
	TArray<unsigned char>                              inArray;                                                  // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	int                                                algorithmVersion;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScreenshotMaker.CropAndResizePicture
struct UScreenshotMaker_CropAndResizePicture_Params
{
	struct FString                                     pathStr;                                                  // (Parm, ZeroConstructor)
	float                                              Scale;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              cropWidthScale;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              cropHeightScale;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     savePathStr;                                              // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.ZLIBDecompress
struct UScriptHelperClient_ZLIBDecompress_Params
{
	struct FString                                     CompressedData;                                           // (Parm, ZeroConstructor)
	int                                                CompressedSize;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                UnCompressedSize;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               IsHEX;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ZLIBCompress_LuaState
struct UScriptHelperClient_ZLIBCompress_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.WakeupFromSuspendSound
struct UScriptHelperClient_WakeupFromSuspendSound_Params
{
};

// Function Client.ScriptHelperClient.VPNTearDown
struct UScriptHelperClient_VPNTearDown_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.VPNSetUserInfo
struct UScriptHelperClient_VPNSetUserInfo_Params
{
	struct FString                                     InUserId;                                                 // (Parm, ZeroConstructor)
	struct FString                                     InUserToken;                                              // (Parm, ZeroConstructor)
	struct FString                                     InAppId;                                                  // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.VPNSetPortRange
struct UScriptHelperClient_VPNSetPortRange_Params
{
	int                                                Min;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Max;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.VPNSetNodelist
struct UScriptHelperClient_VPNSetNodelist_Params
{
	struct FString                                     InNodelist;                                               // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.VPNPrepare
struct UScriptHelperClient_VPNPrepare_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.VPNHandUp
struct UScriptHelperClient_VPNHandUp_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.VPNGetNodeRegionList
struct UScriptHelperClient_VPNGetNodeRegionList_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.VPNDialUp
struct UScriptHelperClient_VPNDialUp_Params
{
	struct FString                                     InRegion;                                                 // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.Vibrate
struct UScriptHelperClient_Vibrate_Params
{
	int                                                Param;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.VerifySavFileData
struct UScriptHelperClient_VerifySavFileData_Params
{
	int                                                CompressedSize;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                UnCompressedSize;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<unsigned char>                              ByteArray;                                                // (Parm, OutParm, ZeroConstructor)
	int                                                ToCheckEndWithCDLength;                                   // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.USFSIsNewestVersion
struct UScriptHelperClient_USFSIsNewestVersion_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.USFSGetUpgradeDiffList
struct UScriptHelperClient_USFSGetUpgradeDiffList_Params
{
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.USFSDeletePkg_V2
struct UScriptHelperClient_USFSDeletePkg_V2_Params
{
	struct FString                                     PkgOrig;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.USFSDeletePkg
struct UScriptHelperClient_USFSDeletePkg_Params
{
	struct FString                                     PkgOrig;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.USFSCacheSysContextUpdatePkgPatch
struct UScriptHelperClient_USFSCacheSysContextUpdatePkgPatch_Params
{
	TMap<struct FString, int>                          PkgPaths;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.USFSCacheSysContextUpdatePkgDiff
struct UScriptHelperClient_USFSCacheSysContextUpdatePkgDiff_Params
{
	TArray<struct FString>                             PkgDiffPaths;                                             // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.USFSCacheSysContextUpdatePkgBinDiff
struct UScriptHelperClient_USFSCacheSysContextUpdatePkgBinDiff_Params
{
	TArray<struct FString>                             PkgDiffPaths;                                             // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.USFSCacheSysContextUpdatePkg
struct UScriptHelperClient_USFSCacheSysContextUpdatePkg_Params
{
	TArray<struct FString>                             PkgPaths;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.USFSCacheSysContextSwitchWrite
struct UScriptHelperClient_USFSCacheSysContextSwitchWrite_Params
{
	bool                                               bSwitch;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.USFSCacheSysContextSwitchAll
struct UScriptHelperClient_USFSCacheSysContextSwitchAll_Params
{
	bool                                               bSwitch;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.USFSCacheSysContextStart
struct UScriptHelperClient_USFSCacheSysContextStart_Params
{
};

// Function Client.ScriptHelperClient.USFSCacheSysContextChangePkgName
struct UScriptHelperClient_USFSCacheSysContextChangePkgName_Params
{
	TArray<struct FString>                             PkgChgInfo;                                               // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.USFSCacheSysContexInit
struct UScriptHelperClient_USFSCacheSysContexInit_Params
{
	TMap<struct FString, struct FString>               PkgNameToConHash;                                         // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.UserName
struct UScriptHelperClient_UserName_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.UrlEncode
struct UScriptHelperClient_UrlEncode_Params
{
	struct FString                                     UnencodedString;                                          // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.UQMSetAppVersion
struct UScriptHelperClient_UQMSetAppVersion_Params
{
	struct FString                                     Version;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.UQMCrashPutUserData
struct UScriptHelperClient_UQMCrashPutUserData_Params
{
	struct FString                                     Key;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Value;                                                    // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.UQMCrashPostExceptionFull
struct UScriptHelperClient_UQMCrashPostExceptionFull_Params
{
	int                                                Category;                                                 // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Name;                                                     // (Parm, ZeroConstructor)
	struct FString                                     Msg;                                                      // (Parm, ZeroConstructor)
	struct FString                                     stack;                                                    // (Parm, ZeroConstructor)
	int                                                dumpNativeType;                                           // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.UQMCrashPostException
struct UScriptHelperClient_UQMCrashPostException_Params
{
	int                                                Category;                                                 // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Reason;                                                   // (Parm, ZeroConstructor)
	int                                                dumpNativeType;                                           // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.UQMCrashLog
struct UScriptHelperClient_UQMCrashLog_Params
{
	int                                                Level;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Tag;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Log;                                                      // (Parm, ZeroConstructor)
	bool                                               needDump;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.UploadGainCrashLogBackground
struct UScriptHelperClient_UploadGainCrashLogBackground_Params
{
};

// Function Client.ScriptHelperClient.UpdateServerTimeInSec
struct UScriptHelperClient_UpdateServerTimeInSec_Params
{
};

// Function Client.ScriptHelperClient.UpdatePublishRegionForBattle
struct UScriptHelperClient_UpdatePublishRegionForBattle_Params
{
};

// Function Client.ScriptHelperClient.UpdatePkgCompressionInfo
struct UScriptHelperClient_UpdatePkgCompressionInfo_Params
{
	TArray<struct FString>                             PkgList;                                                  // (Parm, ZeroConstructor)
	struct FString                                     CompressMethod;                                           // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.UpdateMemResource
struct UScriptHelperClient_UpdateMemResource_Params
{
	struct FString                                     ResType;                                                  // (Parm, ZeroConstructor)
	struct FString                                     KeyWord;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.UpdateAkAudioDeviceBluetoothDelay
struct UScriptHelperClient_UpdateAkAudioDeviceBluetoothDelay_Params
{
	int                                                InDelayTime;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.UnsubscribeFromTopic
struct UScriptHelperClient_UnsubscribeFromTopic_Params
{
	struct FString                                     Topic;                                                    // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.UnmountPakFile
struct UScriptHelperClient_UnmountPakFile_Params
{
	struct FString                                     InPakFilename;                                            // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.UnmapUnusedMap
struct UScriptHelperClient_UnmapUnusedMap_Params
{
};

// Function Client.ScriptHelperClient.UnitTestODPaksOpen
struct UScriptHelperClient_UnitTestODPaksOpen_Params
{
	int                                                fileCount;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Times;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                threadNum;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.TVMacroTesting
struct UScriptHelperClient_TVMacroTesting_Params
{
};

// Function Client.ScriptHelperClient.TrimEngineMemory
struct UScriptHelperClient_TrimEngineMemory_Params
{
};

// Function Client.ScriptHelperClient.TriggerTouchEvent
struct UScriptHelperClient_TriggerTouchEvent_Params
{
	float                                              X;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              Y;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                event_type;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.TriggerTestCmd
struct UScriptHelperClient_TriggerTestCmd_Params
{
	struct FString                                     Cmd;                                                      // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.TriggerOOMCrash
struct UScriptHelperClient_TriggerOOMCrash_Params
{
};

// Function Client.ScriptHelperClient.TriggerNativeDump
struct UScriptHelperClient_TriggerNativeDump_Params
{
	int                                                DumpCount;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	double                                             Timespan;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                NativeDumpType;                                           // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.TriggerLoginCrashTest
struct UScriptHelperClient_TriggerLoginCrashTest_Params
{
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.TriggerLobbyCrashTest
struct UScriptHelperClient_TriggerLobbyCrashTest_Params
{
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.TriggerBlockAndroidANR
struct UScriptHelperClient_TriggerBlockAndroidANR_Params
{
};

// Function Client.ScriptHelperClient.TPerforPlatReport
struct UScriptHelperClient_TPerforPlatReport_Params
{
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ExtraInfo;                                                // (Parm, ZeroConstructor)
	bool                                               Send;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.TPerforPlatPostLargeValueS
struct UScriptHelperClient_TPerforPlatPostLargeValueS_Params
{
	struct FString                                     catgory;                                                  // (Parm, ZeroConstructor)
	struct FString                                     Key;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Value;                                                    // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.TPerforPlatMarkTime
struct UScriptHelperClient_TPerforPlatMarkTime_Params
{
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.TPerforPlatMarkLevelFin
struct UScriptHelperClient_TPerforPlatMarkLevelFin_Params
{
};

// Function Client.ScriptHelperClient.TPerforPlatDisconnectReport
struct UScriptHelperClient_TPerforPlatDisconnectReport_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                EventID;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.TPerforPlatDataReport
struct UScriptHelperClient_TPerforPlatDataReport_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                EventID;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     EventInfo;                                                // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.TMFPSwitchRichTapMode
struct UScriptHelperClient_TMFPSwitchRichTapMode_Params
{
	struct FString                                     Mode;                                                     // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.TMFPStopRichTap
struct UScriptHelperClient_TMFPStopRichTap_Params
{
};

// Function Client.ScriptHelperClient.TMFPStartRichTapWithData
struct UScriptHelperClient_TMFPStartRichTapWithData_Params
{
	struct FString                                     InKey;                                                    // (Parm, ZeroConstructor)
	TMap<struct FString, struct FString>               InMapData;                                                // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function Client.ScriptHelperClient.TMFPStartRichTap
struct UScriptHelperClient_TMFPStartRichTap_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.TMFPLoadHeFile
struct UScriptHelperClient_TMFPLoadHeFile_Params
{
	struct FString                                     StrFilePath;                                              // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.TMFPGetRichTapSupport
struct UScriptHelperClient_TMFPGetRichTapSupport_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.TMFPGetRichTapAmplitudeSupport
struct UScriptHelperClient_TMFPGetRichTapAmplitudeSupport_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.TestSaveStringToFile
struct UScriptHelperClient_TestSaveStringToFile_Params
{
	struct FString                                     String;                                                   // (Parm, ZeroConstructor)
	struct FString                                     TargetDir;                                                // (Parm, ZeroConstructor)
	struct FString                                     FullPathName;                                             // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.TestLoadGameSlotMultiThread
struct UScriptHelperClient_TestLoadGameSlotMultiThread_Params
{
};

// Function Client.ScriptHelperClient.TestLoadGameSlot
struct UScriptHelperClient_TestLoadGameSlot_Params
{
};

// Function Client.ScriptHelperClient.TestCallCvmFuncWithVarArg
struct UScriptHelperClient_TestCallCvmFuncWithVarArg_Params
{
	int                                                FuncID;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<struct FString>                             Arguments;                                                // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	uint64_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.Tea2Encrypt_LuaState
struct UScriptHelperClient_Tea2Encrypt_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.Tea2Decrypt_LuaState
struct UScriptHelperClient_Tea2Decrypt_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SystemLanguageId
struct UScriptHelperClient_SystemLanguageId_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.SyncLoadPackageUpdateCurrentWorldStage
struct UScriptHelperClient_SyncLoadPackageUpdateCurrentWorldStage_Params
{
	struct FString                                     WorldStage;                                               // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SyncLoadPackageUpdateCurrentWorldName
struct UScriptHelperClient_SyncLoadPackageUpdateCurrentWorldName_Params
{
	struct FString                                     WorldName;                                                // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SyncLoadPackageInfoCollect
struct UScriptHelperClient_SyncLoadPackageInfoCollect_Params
{
	struct FString                                     PackageName;                                              // (Parm, ZeroConstructor)
	struct FString                                     WorldName;                                                // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SyncLoadPackageGetPackageListForWorld
struct UScriptHelperClient_SyncLoadPackageGetPackageListForWorld_Params
{
	struct FString                                     WorldName;                                                // (Parm, ZeroConstructor)
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.SyncLoadInfoCollector_Reset
struct UScriptHelperClient_SyncLoadInfoCollector_Reset_Params
{
};

// Function Client.ScriptHelperClient.SyncLoadInfoCollector_OnLevelStart
struct UScriptHelperClient_SyncLoadInfoCollector_OnLevelStart_Params
{
};

// Function Client.ScriptHelperClient.SyncLoadInfoCollector_OnLevelEnd
struct UScriptHelperClient_SyncLoadInfoCollector_OnLevelEnd_Params
{
};

// Function Client.ScriptHelperClient.SwitchUser
struct UScriptHelperClient_SwitchUser_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               useExternalAccount;                                       // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SwitchSceneCamera
struct UScriptHelperClient_SwitchSceneCamera_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     SceneCameraName;                                          // (Parm, ZeroConstructor)
	float                                              BlendTime;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bForce;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SwitchOutputDeviceFileLog
struct UScriptHelperClient_SwitchOutputDeviceFileLog_Params
{
};

// Function Client.ScriptHelperClient.SuspendSound
struct UScriptHelperClient_SuspendSound_Params
{
};

// Function Client.ScriptHelperClient.SubscribeToTopic
struct UScriptHelperClient_SubscribeToTopic_Params
{
	struct FString                                     Topic;                                                    // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.StringToJsonString
struct UScriptHelperClient_StringToJsonString_Params
{
	struct FString                                     String;                                                   // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.StringToFMargin
struct UScriptHelperClient_StringToFMargin_Params
{
	struct FString                                     MarginStr;                                                // (Parm, ZeroConstructor)
	struct FMargin                                     ReturnValue;                                              // (Parm, OutParm, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.StopUIStat
struct UScriptHelperClient_StopUIStat_Params
{
	struct FString                                     UIName;                                                   // (Parm, ZeroConstructor)
	bool                                               bReport;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.StopTouchRecord
struct UScriptHelperClient_StopTouchRecord_Params
{
	struct FTouchInputRecord                           ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function Client.ScriptHelperClient.StopTask
struct UScriptHelperClient_StopTask_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	uint64_t                                           TaskId;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.StopShaderPrecompile
struct UScriptHelperClient_StopShaderPrecompile_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.StopPuffer
struct UScriptHelperClient_StopPuffer_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.StopMonitorFileModified
struct UScriptHelperClient_StopMonitorFileModified_Params
{
};

// Function Client.ScriptHelperClient.StopHapticsEngine
struct UScriptHelperClient_StopHapticsEngine_Params
{
};

// Function Client.ScriptHelperClient.StopH5Downloading
struct UScriptHelperClient_StopH5Downloading_Params
{
};

// Function Client.ScriptHelperClient.StartUIStat
struct UScriptHelperClient_StartUIStat_Params
{
	struct FString                                     UIName;                                                   // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.StartTrace
struct UScriptHelperClient_StartTrace_Params
{
	struct FString                                     InHost;                                                   // (Parm, ZeroConstructor)
	int                                                InStartTTL;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                InMaxTTL;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                InCount;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InExtraData;                                              // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.StartTouchRecord
struct UScriptHelperClient_StartTouchRecord_Params
{
};

// Function Client.ScriptHelperClient.StartShaderPrecompile
struct UScriptHelperClient_StartShaderPrecompile_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.StartOpenReadCollect
struct UScriptHelperClient_StartOpenReadCollect_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bStart;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.StartMonitorFileModified
struct UScriptHelperClient_StartMonitorFileModified_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	int                                                Mask;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.StartHapticsEngine
struct UScriptHelperClient_StartHapticsEngine_Params
{
	struct FScriptDelegate                             Callback;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.StartGrayUpdate
struct UScriptHelperClient_StartGrayUpdate_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.StartDownloadItem
struct UScriptHelperClient_StartDownloadItem_Params
{
	uint32_t                                           ItemId;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           Priority;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FScriptDelegate                             OnItemDownloadDelegate;                                   // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.StartDolphinResourceUpdate
struct UScriptHelperClient_StartDolphinResourceUpdate_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.StartCDNUpdateAfterDolphinUpdateFailed
struct UScriptHelperClient_StartCDNUpdateAfterDolphinUpdateFailed_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.StartBatchDownloadItem
struct UScriptHelperClient_StartBatchDownloadItem_Params
{
	TArray<uint32_t>                                   ItemIDs;                                                  // (Parm, OutParm, ZeroConstructor)
	uint32_t                                           Priority;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FScriptDelegate                             OnBatchItemDownloadDelegate;                              // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.ShutdownUnrealNetwork
struct UScriptHelperClient_ShutdownUnrealNetwork_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ShutdownPuffer
struct UScriptHelperClient_ShutdownPuffer_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ShrinkUObjectHashTables
struct UScriptHelperClient_ShrinkUObjectHashTables_Params
{
};

// Function Client.ScriptHelperClient.ShowWebView
struct UScriptHelperClient_ShowWebView_Params
{
	bool                                               Show;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ShowVLink
struct UScriptHelperClient_ShowVLink_Params
{
	struct FString                                     jsonString;                                               // (Parm, ZeroConstructor)
	struct FString                                     signString;                                               // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.ShowVideoListDialog
struct UScriptHelperClient_ShowVideoListDialog_Params
{
};

// Function Client.ScriptHelperClient.ShowScreenDebugMessage
struct UScriptHelperClient_ShowScreenDebugMessage_Params
{
	struct FString                                     Message;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.ShowH5WebView
struct UScriptHelperClient_ShowH5WebView_Params
{
};

// Function Client.ScriptHelperClient.ShorterStreamingDistanceWhenGameEnd
struct UScriptHelperClient_ShorterStreamingDistanceWhenGameEnd_Params
{
	uint32_t                                           Distance;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ShareWithPhotoByChannel
struct UScriptHelperClient_ShareWithPhotoByChannel_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     _imgPath;                                                 // (Parm, ZeroConstructor)
	struct FString                                     _mediaTagName;                                            // (Parm, ZeroConstructor)
	struct FString                                     _messageExt;                                              // (Parm, ZeroConstructor)
	struct FString                                     _messageAction;                                           // (Parm, ZeroConstructor)
	int                                                _channel;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     _url;                                                     // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.ShareLogFile
struct UScriptHelperClient_ShareLogFile_Params
{
	struct FString                                     InLogFileName;                                            // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SHA256
struct UScriptHelperClient_SHA256_Params
{
	struct FString                                     str;                                                      // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.SHA1
struct UScriptHelperClient_SHA1_Params
{
	struct FString                                     str;                                                      // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.SetWebviewPosition
struct UScriptHelperClient_SetWebviewPosition_Params
{
	int                                                X;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Y;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                W;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                H;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetWebViewCacheInfoDelegate
struct UScriptHelperClient_SetWebViewCacheInfoDelegate_Params
{
	struct FScriptDelegate                             Delegate;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetVpnServiceStrategy
struct UScriptHelperClient_SetVpnServiceStrategy_Params
{
	struct FString                                     InKey;                                                    // (Parm, ZeroConstructor)
	int                                                InValue;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetVoiceSwitch
struct UScriptHelperClient_SetVoiceSwitch_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               FirstVoicePopupSwitch;                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               GDPRForbidVoiceSwitch;                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               GDPRSettingSwitch;                                        // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetVoiceReEneterInfo
struct UScriptHelperClient_SetVoiceReEneterInfo_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              Duration;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                MaxCount;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetUserVulkanSetting
struct UScriptHelperClient_SetUserVulkanSetting_Params
{
	bool                                               Enable;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetUserTMFPTapEnableFlag
struct UScriptHelperClient_SetUserTMFPTapEnableFlag_Params
{
	int                                                EnableFlag;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetUserProperty
struct UScriptHelperClient_SetUserProperty_Params
{
	struct FString                                     propertyKey;                                              // (Parm, ZeroConstructor)
	struct FString                                     propertyValue;                                            // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetUseMouseForTouch
struct UScriptHelperClient_SetUseMouseForTouch_Params
{
	bool                                               bUse;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetUpdatedSoPatchFile
struct UScriptHelperClient_SetUpdatedSoPatchFile_Params
{
	struct FString                                     InSourceFile;                                             // (Parm, ZeroConstructor)
	int                                                InABI;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetupAkAudioDeviceListener
struct UScriptHelperClient_SetupAkAudioDeviceListener_Params
{
};

// Function Client.ScriptHelperClient.SetUIStatMaxClickTimes
struct UScriptHelperClient_SetUIStatMaxClickTimes_Params
{
	int                                                Times;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetUIRectOffset
struct UScriptHelperClient_SetUIRectOffset_Params
{
	struct FString                                     uirect;                                                   // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetUIElemLayoutJsonConfigSwitch
struct UScriptHelperClient_SetUIElemLayoutJsonConfigSwitch_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               UIElemLayoutJsonConfigSwitch;                             // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetUIConfigTMFPTapEnableFlag
struct UScriptHelperClient_SetUIConfigTMFPTapEnableFlag_Params
{
	int                                                uiEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetUDPPingControlFlag
struct UScriptHelperClient_SetUDPPingControlFlag_Params
{
	int                                                Lock;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                BindType;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetTssNetworkStatus
struct UScriptHelperClient_SetTssNetworkStatus_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Status;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetTMFPTapWhiteListFlag
struct UScriptHelperClient_SetTMFPTapWhiteListFlag_Params
{
	int                                                TapWhiteList;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetTextureGroupLODBias
struct UScriptHelperClient_SetTextureGroupLODBias_Params
{
	unsigned char                                      GroupID;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                MipBias;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetTestEditorNum
struct UScriptHelperClient_SetTestEditorNum_Params
{
	int                                                PlayerCount;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Num;                                                      // (Parm, ZeroConstructor)
	struct FString                                     SceneName;                                                // (Parm, ZeroConstructor)
	int                                                Platform;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetSoundEffectQuality
struct UScriptHelperClient_SetSoundEffectQuality_Params
{
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetShowFriendObservers
struct UScriptHelperClient_SetShowFriendObservers_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bShow;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetServerTimeInSec
struct UScriptHelperClient_SetServerTimeInSec_Params
{
	int64_t                                            InServerTimeInSec;                                        // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetSelfieSwitch
struct UScriptHelperClient_SetSelfieSwitch_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               SelfieSwitch;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetSdkIoctl
struct UScriptHelperClient_SetSdkIoctl_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                request;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Token;                                                    // (Parm, OutParm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetReportBugSwitch
struct UScriptHelperClient_SetReportBugSwitch_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReportBugSwitch;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetRemoteResource
struct UScriptHelperClient_SetRemoteResource_Params
{
	struct FString                                     AssetId;                                                  // (Parm, OutParm, ZeroConstructor)
	class UObject*                                     DescObj;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetRegionNoByLua
struct UScriptHelperClient_SetRegionNoByLua_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                regionNo;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetRedBloodSwitch
struct UScriptHelperClient_SetRedBloodSwitch_Params
{
	bool                                               redBloodSwitch;                                           // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetPufferBuildInfo
struct UScriptHelperClient_SetPufferBuildInfo_Params
{
	struct FString                                     PipeLineID;                                               // (Parm, ZeroConstructor)
	struct FString                                     BuildNo;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetPublishRegion
struct UScriptHelperClient_SetPublishRegion_Params
{
	struct FString                                     Region;                                                   // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetPlayerBaseInfo
struct UScriptHelperClient_SetPlayerBaseInfo_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     OpenID;                                                   // (Parm, ZeroConstructor)
	uint64_t                                           RoleID;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     PlayerName;                                               // (Parm, ZeroConstructor)
	struct FString                                     HeadIconUrl;                                              // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetNationSwitch
struct UScriptHelperClient_SetNationSwitch_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               NationAllSwitch;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               NationBattleSwitch;                                       // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               NationRankSwitch;                                         // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetMyFriendObserversDetail
struct UScriptHelperClient_SetMyFriendObserversDetail_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<struct FFriendObserver>                     FriendObserversDetails;                                   // (Parm, OutParm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetMiniGameFinalAwardResId
struct UScriptHelperClient_SetMiniGameFinalAwardResId_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                AwardResId;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetMatchNoAuthMode
struct UScriptHelperClient_SetMatchNoAuthMode_Params
{
	bool                                               bUsingNoAuth;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetLuaFastGCMode
struct UScriptHelperClient_SetLuaFastGCMode_Params
{
	int                                                Mode;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetLinkStyle
struct UScriptHelperClient_SetLinkStyle_Params
{
	struct FString                                     StyleName;                                                // (Parm, ZeroConstructor)
	int                                                FontSize;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     FontPath;                                                 // (Parm, ZeroConstructor)
	struct FString                                     FontColor;                                                // (Parm, ZeroConstructor)
	bool                                               ShowUnderline;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     PathHyperLinkNormalBrush;                                 // (Parm, ZeroConstructor)
	struct FString                                     PathHyperLinkHoveredrBrush;                               // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetLevelStreamingUnloadTimeslice
struct UScriptHelperClient_SetLevelStreamingUnloadTimeslice_Params
{
	bool                                               Enabled;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetLevelGamePlayLoadPriority
struct UScriptHelperClient_SetLevelGamePlayLoadPriority_Params
{
	class ULevelStreaming*                             TargetLevel;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Priority;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetiTOPLbsDelay
struct UScriptHelperClient_SetiTOPLbsDelay_Params
{
	int                                                Delay;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetIPRegion
struct UScriptHelperClient_SetIPRegion_Params
{
	int                                                region_no;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetIosStuckEnableByServerConfig
struct UScriptHelperClient_SetIosStuckEnableByServerConfig_Params
{
	int                                                bEnable;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetIOSBGDownloadAttribute
struct UScriptHelperClient_SetIOSBGDownloadAttribute_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bEnableCellularAccess;                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bEnableResumeData;                                        // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                nMinFileSize;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                nMaxTasks;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetImageVersionString
struct UScriptHelperClient_SetImageVersionString_Params
{
	struct FString                                     oldVersion;                                               // (Parm, ZeroConstructor)
	struct FString                                     newVersion;                                               // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetImageStyle
struct UScriptHelperClient_SetImageStyle_Params
{
	struct FString                                     StyleName;                                                // (Parm, ZeroConstructor)
	int                                                ImageSize;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ImagePath;                                                // (Parm, ZeroConstructor)
	struct FString                                     ImageColor;                                               // (Parm, ZeroConstructor)
	bool                                               bPreLoad;                                                 // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetIGProxyData
struct UScriptHelperClient_SetIGProxyData_Params
{
	struct FString                                     InJsonData;                                               // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetHapticsEngineEnable
struct UScriptHelperClient_SetHapticsEngineEnable_Params
{
	bool                                               bEnable;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetGlobalRedBloodSwitch
struct UScriptHelperClient_SetGlobalRedBloodSwitch_Params
{
	bool                                               redBloodSwitch;                                           // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetGDPRUserType
struct UScriptHelperClient_SetGDPRUserType_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                GDPRUserType;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetGameThreadPriority
struct UScriptHelperClient_SetGameThreadPriority_Params
{
	int                                                NewPriority;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetGameThreadName
struct UScriptHelperClient_SetGameThreadName_Params
{
	struct FString                                     GameThreadName;                                           // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetGameStatusMap
struct UScriptHelperClient_SetGameStatusMap_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	TMap<struct FString, struct FString>               GameStatusMap;                                            // (Parm, OutParm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetGameSrvID
struct UScriptHelperClient_SetGameSrvID_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                GameSrvID;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetForceVulkanAvailable
struct UScriptHelperClient_SetForceVulkanAvailable_Params
{
	bool                                               Enable;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetFontStyle
struct UScriptHelperClient_SetFontStyle_Params
{
	struct FString                                     StyleName;                                                // (Parm, ZeroConstructor)
	int                                                FontSize;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     FontPath;                                                 // (Parm, ZeroConstructor)
	struct FString                                     FontColor;                                                // (Parm, ZeroConstructor)
	bool                                               UseShadow;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               IsBold;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetExtraLocalizationMap
struct UScriptHelperClient_SetExtraLocalizationMap_Params
{
	TMap<struct FString, struct FString>               translationMap;                                           // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function Client.ScriptHelperClient.SetExtraItemTableMappingByFix
struct UScriptHelperClient_SetExtraItemTableMappingByFix_Params
{
	TMap<int, struct FItemFixTableItem>                ItemFixMap;                                               // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function Client.ScriptHelperClient.SetDynamicLevels
struct UScriptHelperClient_SetDynamicLevels_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<struct FString>                             DynamicLevels;                                            // (Parm, OutParm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetDumpShaderCompile
struct UScriptHelperClient_SetDumpShaderCompile_Params
{
	int                                                iDumpVal;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetDownLoadLanguageName
struct UScriptHelperClient_SetDownLoadLanguageName_Params
{
	struct FString                                     Language;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetDisableGyrSensor
struct UScriptHelperClient_SetDisableGyrSensor_Params
{
	bool                                               InDisableSensor;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetCrashContextReportLevel
struct UScriptHelperClient_SetCrashContextReportLevel_Params
{
	int                                                Level;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetConfigString
struct UScriptHelperClient_SetConfigString_Params
{
	struct FString                                     IniFileName;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     SectionName;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     KeyName;                                                  // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     Value;                                                    // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function Client.ScriptHelperClient.SetConfigInt
struct UScriptHelperClient_SetConfigInt_Params
{
	struct FString                                     IniFileName;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     SectionName;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     KeyName;                                                  // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	int                                                Value;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetConfigBool
struct UScriptHelperClient_SetConfigBool_Params
{
	struct FString                                     IniFileName;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     SectionName;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     KeyName;                                                  // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	bool                                               Value;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetCentauriZoneID_LuaState
struct UScriptHelperClient_SetCentauriZoneID_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetCentauriIDC
struct UScriptHelperClient_SetCentauriIDC_Params
{
	struct FString                                     CentauriIdc;                                              // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetCanWatchEnemy
struct UScriptHelperClient_SetCanWatchEnemy_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bCan;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetBtnClickInCdFunc
struct UScriptHelperClient_SetBtnClickInCdFunc_Params
{
};

// Function Client.ScriptHelperClient.SetAppDetailInfo
struct UScriptHelperClient_SetAppDetailInfo_Params
{
	struct FString                                     appInfo;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SetAllLinkStyle
struct UScriptHelperClient_SetAllLinkStyle_Params
{
};

// Function Client.ScriptHelperClient.SetAllImageStyle
struct UScriptHelperClient_SetAllImageStyle_Params
{
};

// Function Client.ScriptHelperClient.SetAllFontStyle
struct UScriptHelperClient_SetAllFontStyle_Params
{
};

// Function Client.ScriptHelperClient.SetActivePufferTick
struct UScriptHelperClient_SetActivePufferTick_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ActivePufferTick;                                         // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SetAccountRegion
struct UScriptHelperClient_SetAccountRegion_Params
{
	struct FString                                     Region;                                                   // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SendRetriveBeginnerFinisheGuideReq
struct UScriptHelperClient_SendRetriveBeginnerFinisheGuideReq_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SendRecordFinishedGuideReq
struct UScriptHelperClient_SendRecordFinishedGuideReq_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     TipsID;                                                   // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SendPlayEmote
struct UScriptHelperClient_SendPlayEmote_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                EmoteIndex;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SendLobbyChat
struct UScriptHelperClient_SendLobbyChat_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     gid;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SendDirtyToFilter
struct UScriptHelperClient_SendDirtyToFilter_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     dirtyString;                                              // (Parm, ZeroConstructor)
	struct FString                                     prefixString;                                             // (Parm, ZeroConstructor)
	int                                                UID;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SendClientLog
struct UScriptHelperClient_SendClientLog_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     errorReason;                                              // (Parm, ZeroConstructor)
	struct FString                                     errorDescription;                                         // (Parm, ZeroConstructor)
	bool                                               pullAll;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ScheduleLocalNotificationAtTime
struct UScriptHelperClient_ScheduleLocalNotificationAtTime_Params
{
	int                                                Year;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Month;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Day;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Hour;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Minute;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Second;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               LocalTime;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Title;                                                    // (Parm, ZeroConstructor)
	struct FString                                     Body;                                                     // (Parm, ZeroConstructor)
	struct FString                                     Action;                                                   // (Parm, ZeroConstructor)
	int                                                NotificationID;                                           // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SaveStringToIntermediateFile
struct UScriptHelperClient_SaveStringToIntermediateFile_Params
{
	struct FString                                     String;                                                   // (Parm, ZeroConstructor)
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SaveStringToFile
struct UScriptHelperClient_SaveStringToFile_Params
{
	struct FString                                     String;                                                   // (Parm, ZeroConstructor)
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SaveStringArrayToFile
struct UScriptHelperClient_SaveStringArrayToFile_Params
{
	TArray<struct FString>                             Lines;                                                    // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SaveSMapsFile
struct UScriptHelperClient_SaveSMapsFile_Params
{
};

// Function Client.ScriptHelperClient.SaveSavFileByByteArray
struct UScriptHelperClient_SaveSavFileByByteArray_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	int                                                CompressedSize;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                UnCompressedSize;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<unsigned char>                              ByteArray;                                                // (Parm, OutParm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SaveSavFile
struct UScriptHelperClient_SaveSavFile_Params
{
	struct FString                                     CompressedData;                                           // (Parm, ZeroConstructor)
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	int                                                CompressedSize;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                UnCompressedSize;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               IsHEX;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SaveLuaMemoryFile
struct UScriptHelperClient_SaveLuaMemoryFile_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	struct FString                                     InputContent;                                             // (Parm, ZeroConstructor)
	bool                                               RmExistFile;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SaveLoadGameSlotCrashFlag
struct UScriptHelperClient_SaveLoadGameSlotCrashFlag_Params
{
};

// Function Client.ScriptHelperClient.SaveJankInfoToLocalFile
struct UScriptHelperClient_SaveJankInfoToLocalFile_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.SaveGameSlotMultiThread
struct UScriptHelperClient_SaveGameSlotMultiThread_Params
{
};

// Function Client.ScriptHelperClient.SaveArrayToFile
struct UScriptHelperClient_SaveArrayToFile_Params
{
	TArray<unsigned char>                              Content;                                                  // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.SaveAOSMemMapsInfo
struct UScriptHelperClient_SaveAOSMemMapsInfo_Params
{
};

// Function Client.ScriptHelperClient.RunTestCreateLobbyActor
struct UScriptHelperClient_RunTestCreateLobbyActor_Params
{
};

// Function Client.ScriptHelperClient.RunCvmTestCases
struct UScriptHelperClient_RunCvmTestCases_Params
{
	uint64_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.RunConsoleCommondAndGetString
struct UScriptHelperClient_RunConsoleCommondAndGetString_Params
{
	struct FString                                     commond;                                                  // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.RunConsoleCommond
struct UScriptHelperClient_RunConsoleCommond_Params
{
	struct FString                                     commond;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.RoomOwnerInterruptGame
struct UScriptHelperClient_RoomOwnerInterruptGame_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ReturnToLobby
struct UScriptHelperClient_ReturnToLobby_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.RestartShaderPrecompileBackend
struct UScriptHelperClient_RestartShaderPrecompileBackend_Params
{
};

// Function Client.ScriptHelperClient.RestartShaderPrecompile
struct UScriptHelperClient_RestartShaderPrecompile_Params
{
};

// Function Client.ScriptHelperClient.RestartPuffer
struct UScriptHelperClient_RestartPuffer_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               needCheck;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                maxDownloadsPerTask;                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                maxDownTask;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                maxDownloadSpeed;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               useOldInterface;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               removeOldWhenUpdate;                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                versionType;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InDownloadFuncDict;                                       // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.RestartGame
struct UScriptHelperClient_RestartGame_Params
{
};

// Function Client.ScriptHelperClient.ResolveDNSWithServerIP
struct UScriptHelperClient_ResolveDNSWithServerIP_Params
{
	struct FString                                     DomainName;                                               // (Parm, ZeroConstructor)
	struct FString                                     ServerIP;                                                 // (Parm, ZeroConstructor)
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ResolveDNS
struct UScriptHelperClient_ResolveDNS_Params
{
	struct FString                                     DomainName;                                               // (Parm, ZeroConstructor)
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ResetSlateTickEveryFrame
struct UScriptHelperClient_ResetSlateTickEveryFrame_Params
{
	int                                                SlateUIID;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ResetAllSlateTickEveryFrame
struct UScriptHelperClient_ResetAllSlateTickEveryFrame_Params
{
};

// Function Client.ScriptHelperClient.RequireSlateTickEveryFrameBeforeTargetFrame
struct UScriptHelperClient_RequireSlateTickEveryFrameBeforeTargetFrame_Params
{
	int                                                FrameNum;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.RequireSlateTickEveryFrame
struct UScriptHelperClient_RequireSlateTickEveryFrame_Params
{
	int                                                SlateUIID;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.RequestFile
struct UScriptHelperClient_RequestFile_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	bool                                               ForceUpdate;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InUA;                                                     // (Parm, ZeroConstructor)
	uint64_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ReportFirebaseEventWithString
struct UScriptHelperClient_ReportFirebaseEventWithString_Params
{
	struct FString                                     eventTypeString;                                          // (Parm, ZeroConstructor)
	struct FString                                     bundleExtraKey;                                           // (Parm, ZeroConstructor)
	struct FString                                     bundleExtraValue;                                         // (Parm, ZeroConstructor)
	bool                                               isUnique;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ReportFirebaseEventWithParam
struct UScriptHelperClient_ReportFirebaseEventWithParam_Params
{
	struct FString                                     eventTypeString;                                          // (Parm, ZeroConstructor)
	TMap<struct FString, struct FString>               _params;                                                  // (Parm, ZeroConstructor)
	bool                                               isUnique;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ReportEventRegisterCompleted
struct UScriptHelperClient_ReportEventRegisterCompleted_Params
{
};

// Function Client.ScriptHelperClient.ReportEventPurchaseConsider
struct UScriptHelperClient_ReportEventPurchaseConsider_Params
{
};

// Function Client.ScriptHelperClient.ReportEventLoadingCompleted
struct UScriptHelperClient_ReportEventLoadingCompleted_Params
{
};

// Function Client.ScriptHelperClient.ReportCrashLogWithFDNum
struct UScriptHelperClient_ReportCrashLogWithFDNum_Params
{
	struct FString                                     baseLogInfo;                                              // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.ReportContextValuesOnCrash
struct UScriptHelperClient_ReportContextValuesOnCrash_Params
{
	struct FString                                     Json;                                                     // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.ReportBattleChat
struct UScriptHelperClient_ReportBattleChat_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Msg;                                                      // (Parm, ZeroConstructor)
	int                                                MsgExtraParam;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ReplyInvite
struct UScriptHelperClient_ReplyInvite_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     gid;                                                      // (Parm, ZeroConstructor)
	bool                                               bReply;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.RemoveWebView
struct UScriptHelperClient_RemoveWebView_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.RemoveKnownMissingPackage
struct UScriptHelperClient_RemoveKnownMissingPackage_Params
{
	struct FString                                     PackageName;                                              // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.RemoveBPClassManager
struct UScriptHelperClient_RemoveBPClassManager_Params
{
};

// Function Client.ScriptHelperClient.RemountPakFiles
struct UScriptHelperClient_RemountPakFiles_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.RemapMemMap
struct UScriptHelperClient_RemapMemMap_Params
{
	struct FString                                     Name;                                                     // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	int                                                NewSize;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ReleaseSplashScreenImage
struct UScriptHelperClient_ReleaseSplashScreenImage_Params
{
};

// Function Client.ScriptHelperClient.ReleaseSlateTickEveryFrame
struct UScriptHelperClient_ReleaseSlateTickEveryFrame_Params
{
	int                                                SlateUIID;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ReleaseRTPoolSnapShots
struct UScriptHelperClient_ReleaseRTPoolSnapShots_Params
{
};

// Function Client.ScriptHelperClient.ReleaseRTPoolResources
struct UScriptHelperClient_ReleaseRTPoolResources_Params
{
};

// Function Client.ScriptHelperClient.ReInitializePuffer
struct UScriptHelperClient_ReInitializePuffer_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               needCheck;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                maxDownloadsPerTask;                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                maxDownTask;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                maxDownloadSpeed;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               useOldInterface;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               removeOldWhenUpdate;                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                versionType;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InDownloadFuncDict;                                       // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.ReInitializeCvm
struct UScriptHelperClient_ReInitializeCvm_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.RegisterMemoryWarningHandle
struct UScriptHelperClient_RegisterMemoryWarningHandle_Params
{
	struct FScriptDelegate                             OnMemoryWarning;                                          // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.ReduceVirMem
struct UScriptHelperClient_ReduceVirMem_Params
{
	int                                                Low;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Dec;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.RecoverWebView
struct UScriptHelperClient_RecoverWebView_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.RecoverShrunkODPaksBins
struct UScriptHelperClient_RecoverShrunkODPaksBins_Params
{
	TMap<uint32_t, struct FString>                     Keys;                                                     // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.RecordVirMemInfo
struct UScriptHelperClient_RecordVirMemInfo_Params
{
};

// Function Client.ScriptHelperClient.RecordLuaExceptionInfo
struct UScriptHelperClient_RecordLuaExceptionInfo_Params
{
	struct FString                                     exception;                                                // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.RebuildHISM
struct UScriptHelperClient_RebuildHISM_Params
{
	class UHierarchicalInstancedStaticMeshComponent*   comp;                                                     // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	bool                                               Async;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ForceUpdate;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.QuitFightChat
struct UScriptHelperClient_QuitFightChat_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.QuickLogin
struct UScriptHelperClient_QuickLogin_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                refreshTokenBeforeExpDays;                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ProjectSavedDir
struct UScriptHelperClient_ProjectSavedDir_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ProjectDir
struct UScriptHelperClient_ProjectDir_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ProjectContentDir
struct UScriptHelperClient_ProjectContentDir_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ProcessSoPatch
struct UScriptHelperClient_ProcessSoPatch_Params
{
	struct FString                                     InAppVerStr;                                              // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ProcessServerRelationChainError
struct UScriptHelperClient_ProcessServerRelationChainError_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ErrorMsg;                                                 // (Parm, ZeroConstructor)
	int                                                iForceLoginInterval;                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.PrintUAEDataTableManagerMemDetail
struct UScriptHelperClient_PrintUAEDataTableManagerMemDetail_Params
{
};

// Function Client.ScriptHelperClient.PostGameStatusToTMFPSMap
struct UScriptHelperClient_PostGameStatusToTMFPSMap_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Key;                                                      // (Parm, ZeroConstructor)
	TMap<struct FString, struct FString>               mapData;                                                  // (Parm, OutParm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.PlayHapticsFile
struct UScriptHelperClient_PlayHapticsFile_Params
{
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	int                                                Duration;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FScriptDelegate                             Callback;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.OpenWebviewInGameProcess
struct UScriptHelperClient_OpenWebviewInGameProcess_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	int                                                Left;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Top;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Right;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Bottom;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.OpenURLInSDK
struct UScriptHelperClient_OpenURLInSDK_Params
{
	struct FString                                     InURL;                                                    // (Parm, ZeroConstructor)
	bool                                               InVisibleToolbar;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               InSystemWebBrowser;                                       // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               InFullScreen;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ExtraJson;                                                // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.OpenShaderCodeLibrary
struct UScriptHelperClient_OpenShaderCodeLibrary_Params
{
	struct FString                                     Path;                                                     // (Parm, ZeroConstructor)
	struct FString                                     VersionNum;                                               // (Parm, ZeroConstructor)
	bool                                               bForceOpen;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.OpenH5FromCache
struct UScriptHelperClient_OpenH5FromCache_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ModuleName;                                               // (Parm, ZeroConstructor)
	struct FString                                     Language;                                                 // (Parm, ZeroConstructor)
	int                                                netType;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Top;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Left;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Right;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ViewParam;                                                // (Parm, ZeroConstructor)
};

// DelegateFunction Client.ScriptHelperClient.OnWebViewCacheInfoDelegate__DelegateSignature
struct UScriptHelperClient_OnWebViewCacheInfoDelegate__DelegateSignature_Params
{
	int                                                code;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.OnWebViewCache
struct UScriptHelperClient_OnWebViewCache_Params
{
	int                                                code;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.OnPakFileCRCCheck
struct UScriptHelperClient_OnPakFileCRCCheck_Params
{
	struct FString                                     PakFileName;                                              // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.OnNotifyFightFriendChat
struct UScriptHelperClient_OnNotifyFightFriendChat_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FFightFriendChat                            Data;                                                     // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.ScriptHelperClient.OnIslandPlayerInfoNotify
struct UScriptHelperClient_OnIslandPlayerInfoNotify_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                LandId;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.OnInviteNextBattle
struct UScriptHelperClient_OnInviteNextBattle_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     gid;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Name;                                                     // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.OnGetUpdateStateCDNConfigUrl
struct UScriptHelperClient_OnGetUpdateStateCDNConfigUrl_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
};

// DelegateFunction Client.ScriptHelperClient.OnGetItemBigIcon__DelegateSignature
struct UScriptHelperClient_OnGetItemBigIcon__DelegateSignature_Params
{
	struct FString                                     strPath;                                                  // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.OnFilterFinish
struct UScriptHelperClient_OnFilterFinish_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     filterText;                                               // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.OnEnterLobbyReloadLocalizationResource
struct UScriptHelperClient_OnEnterLobbyReloadLocalizationResource_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.OnEnterGameReleaseLocalizationResource
struct UScriptHelperClient_OnEnterGameReleaseLocalizationResource_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.OnDolphinAppUpdateFinished
struct UScriptHelperClient_OnDolphinAppUpdateFinished_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.OnCombatHitFeedback
struct UScriptHelperClient_OnCombatHitFeedback_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bCombatHitFeedbackEnable;                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.OnBattleResultCallBack
struct UScriptHelperClient_OnBattleResultCallBack_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FBattleResultData                           BattleResultData;                                         // (Parm, OutParm)
};

// Function Client.ScriptHelperClient.OnBattleResult
struct UScriptHelperClient_OnBattleResult_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FBattleResultData                           BattleResultData;                                         // (Parm, OutParm)
};

// Function Client.ScriptHelperClient.ObjectPoolServerSwitch
struct UScriptHelperClient_ObjectPoolServerSwitch_Params
{
	bool                                               bSwitchOn;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.NotifyBeginnerFinishedGuideUpdated
struct UScriptHelperClient_NotifyBeginnerFinishedGuideUpdated_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               GuideSwitch;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<struct FPlayerFinishedGuide>                finished_guide;                                           // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	int                                                player_level;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                player_exp_type;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.NoschatShareWithUrlInfo
struct UScriptHelperClient_NoschatShareWithUrlInfo_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     _descShare;                                               // (Parm, ZeroConstructor)
	struct FString                                     _titleShare;                                              // (Parm, ZeroConstructor)
	struct FString                                     _imgPath;                                                 // (Parm, ZeroConstructor)
	struct FString                                     _url;                                                     // (Parm, ZeroConstructor)
	int                                                _shareScene;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.NoschatShareToFriend
struct UScriptHelperClient_NoschatShareToFriend_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     OpenID;                                                   // (Parm, ZeroConstructor)
	struct FString                                     Title;                                                    // (Parm, ZeroConstructor)
	struct FString                                     Desc;                                                     // (Parm, ZeroConstructor)
	struct FString                                     mediaId;                                                  // (Parm, ZeroConstructor)
	struct FString                                     messageExt;                                               // (Parm, ZeroConstructor)
	struct FString                                     mediaTagName;                                             // (Parm, ZeroConstructor)
	struct FString                                     msdkExtInfo;                                              // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.NoschatShare
struct UScriptHelperClient_NoschatShare_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     _descShare;                                               // (Parm, ZeroConstructor)
	struct FString                                     _titleShare;                                              // (Parm, ZeroConstructor)
	struct FString                                     _imgPath;                                                 // (Parm, ZeroConstructor)
	struct FString                                     _mediaTagName;                                            // (Parm, ZeroConstructor)
	struct FString                                     _messageExt;                                              // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.MSDKWebViewCallJS
struct UScriptHelperClient_MSDKWebViewCallJS_Params
{
	struct FString                                     strJS;                                                    // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.MoveFollowTarget
struct UScriptHelperClient_MoveFollowTarget_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                FollowType;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	uint64_t                                           UID;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.MoveFile
struct UScriptHelperClient_MoveFile_Params
{
	struct FString                                     SrcFullPath;                                              // (Parm, ZeroConstructor)
	struct FString                                     DesFullPath;                                              // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.MountPakFile
struct UScriptHelperClient_MountPakFile_Params
{
	struct FString                                     InPakFilename;                                            // (Parm, ZeroConstructor)
	struct FString                                     Key;                                                      // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.MessageBoxExt
struct UScriptHelperClient_MessageBoxExt_Params
{
	struct FString                                     Caption;                                                  // (Parm, ZeroConstructor)
	struct FString                                     Text;                                                     // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.MediaCopyFromPakToLocal
struct UScriptHelperClient_MediaCopyFromPakToLocal_Params
{
	struct FString                                     from;                                                     // (Parm, ZeroConstructor)
	bool                                               bForce;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.MD5LuaString_LuaState
struct UScriptHelperClient_MD5LuaString_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.MD5HashAnsiString
struct UScriptHelperClient_MD5HashAnsiString_Params
{
	struct FString                                     str;                                                      // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ManualSleep
struct UScriptHelperClient_ManualSleep_Params
{
	float                                              Seconds;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.LuaLoadFileToString
struct UScriptHelperClient_LuaLoadFileToString_Params
{
	struct FString                                     InFileName;                                               // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.LogoutAllDevices
struct UScriptHelperClient_LogoutAllDevices_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.Logout
struct UScriptHelperClient_Logout_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.LoginWithExtraInfo
struct UScriptHelperClient_LoginWithExtraInfo_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           Channel;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InExtraJson;                                              // (Parm, ZeroConstructor)
	bool                                               SkipLocalCacheCheck;                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.Login
struct UScriptHelperClient_Login_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           Channel;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.LobbySetUserRegion
struct UScriptHelperClient_LobbySetUserRegion_Params
{
	int                                                InRegion;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.LobbySetProxyPortlist
struct UScriptHelperClient_LobbySetProxyPortlist_Params
{
	struct FString                                     InNodePortList;                                           // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.LobbySetProxyNodelist
struct UScriptHelperClient_LobbySetProxyNodelist_Params
{
	struct FString                                     InNodeIpList;                                             // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.LobbySetEchoPortlist
struct UScriptHelperClient_LobbySetEchoPortlist_Params
{
	struct FString                                     InEchoPortList;                                           // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.LobbyIsLinkProxy
struct UScriptHelperClient_LobbyIsLinkProxy_Params
{
	struct FString                                     InIp;                                                     // (Parm, ZeroConstructor)
	int                                                InPort;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.LobbyAddAddress
struct UScriptHelperClient_LobbyAddAddress_Params
{
	struct FString                                     InProtocol;                                               // (Parm, ZeroConstructor)
	struct FString                                     InIp;                                                     // (Parm, ZeroConstructor)
	int                                                InPort;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.LoadSOFromOBB
struct UScriptHelperClient_LoadSOFromOBB_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.LoadSavFileAsByteArray
struct UScriptHelperClient_LoadSavFileAsByteArray_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	struct FSavFileData                                ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function Client.ScriptHelperClient.LoadSavFile_LuaState
struct UScriptHelperClient_LoadSavFile_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.LoadIntermediateFileToString
struct UScriptHelperClient_LoadIntermediateFileToString_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.LoadH5FromCache
struct UScriptHelperClient_LoadH5FromCache_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ModuleName;                                               // (Parm, ZeroConstructor)
	struct FString                                     Language;                                                 // (Parm, ZeroConstructor)
	int                                                netType;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Top;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Left;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Right;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ViewParam;                                                // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.LoadFileToStringByFullPath
struct UScriptHelperClient_LoadFileToStringByFullPath_Params
{
	struct FString                                     FullPathName;                                             // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.LoadFileToString
struct UScriptHelperClient_LoadFileToString_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.LoadFileToArrayByFullPath
struct UScriptHelperClient_LoadFileToArrayByFullPath_Params
{
	struct FString                                     FullPathName;                                             // (Parm, ZeroConstructor)
	TArray<unsigned char>                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.LoadFileToArray
struct UScriptHelperClient_LoadFileToArray_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	TArray<unsigned char>                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.LoadAmendODs
struct UScriptHelperClient_LoadAmendODs_Params
{
	TMap<uint32_t, struct FString>                     Keys;                                                     // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.LoadAFDTranslation
struct UScriptHelperClient_LoadAFDTranslation_Params
{
};

// Function Client.ScriptHelperClient.ListDirectoryFiles
struct UScriptHelperClient_ListDirectoryFiles_Params
{
	struct FString                                     DirectoryPath;                                            // (Parm, ZeroConstructor)
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ListAllLoadedSymbols
struct UScriptHelperClient_ListAllLoadedSymbols_Params
{
};

// Function Client.ScriptHelperClient.LaunchUrl
struct UScriptHelperClient_LaunchUrl_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.IsWindowsClientReplay
struct UScriptHelperClient_IsWindowsClientReplay_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsWindows
struct UScriptHelperClient_IsWindows_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsWindowOB
struct UScriptHelperClient_IsWindowOB_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsUsingBluetooth
struct UScriptHelperClient_IsUsingBluetooth_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsUseTypicalResultFlowMode
struct UScriptHelperClient_IsUseTypicalResultFlowMode_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsUpdateSkip
struct UScriptHelperClient_IsUpdateSkip_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsTypicalMode
struct UScriptHelperClient_IsTypicalMode_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsTest
struct UScriptHelperClient_IsTest_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsSystemVPNOpened
struct UScriptHelperClient_IsSystemVPNOpened_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsSupportVulkan
struct UScriptHelperClient_IsSupportVulkan_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsSplitMiniPakVersion
struct UScriptHelperClient_IsSplitMiniPakVersion_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsSplitMapPakVersion
struct UScriptHelperClient_IsSplitMapPakVersion_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.isSkipUpdateByRepair
struct UScriptHelperClient_isSkipUpdateByRepair_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsShipping
struct UScriptHelperClient_IsShipping_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsSavFileData
struct UScriptHelperClient_IsSavFileData_Params
{
	struct FString                                     CompressedData;                                           // (Parm, ZeroConstructor)
	int                                                CompressedSize;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                UnCompressedSize;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ToCheckEndWithCDLenght;                                   // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               IsHEX;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsRuningOnVulkan
struct UScriptHelperClient_IsRuningOnVulkan_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsReleaseVersion
struct UScriptHelperClient_IsReleaseVersion_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsPVEMode
struct UScriptHelperClient_IsPVEMode_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsOpenAOS90FPSConfig
struct UScriptHelperClient_IsOpenAOS90FPSConfig_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsOpenAOS120FPSConfig
struct UScriptHelperClient_IsOpenAOS120FPSConfig_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsODPakMonted
struct UScriptHelperClient_IsODPakMonted_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsNotificationEnabled
struct UScriptHelperClient_IsNotificationEnabled_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsNoAuthMode
struct UScriptHelperClient_IsNoAuthMode_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsNetworkReachable
struct UScriptHelperClient_IsNetworkReachable_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsNeedClearHiddenUI
struct UScriptHelperClient_IsNeedClearHiddenUI_Params
{
	class UFrontendHUD*                                GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsMounted
struct UScriptHelperClient_IsMounted_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsMlAIDebug
struct UScriptHelperClient_IsMlAIDebug_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsMatchVersion
struct UScriptHelperClient_IsMatchVersion_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsMatchNoAuthMode
struct UScriptHelperClient_IsMatchNoAuthMode_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsLowMemoryDevice
struct UScriptHelperClient_IsLowMemoryDevice_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsLaunchedByLocalNotification
struct UScriptHelperClient_IsLaunchedByLocalNotification_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsLastSessionCrash
struct UScriptHelperClient_IsLastSessionCrash_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsJaguar
struct UScriptHelperClient_IsJaguar_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsIPhoneFiveSOriginal
struct UScriptHelperClient_IsIPhoneFiveSOriginal_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsIPhoneFiveS
struct UScriptHelperClient_IsIPhoneFiveS_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsIOSVersionAbove13
struct UScriptHelperClient_IsIOSVersionAbove13_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsInstallWX
struct UScriptHelperClient_IsInstallWX_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsInstallWhatsapp
struct UScriptHelperClient_IsInstallWhatsapp_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsInstallVK
struct UScriptHelperClient_IsInstallVK_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsInstallTwitter
struct UScriptHelperClient_IsInstallTwitter_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsInstallOpenRec
struct UScriptHelperClient_IsInstallOpenRec_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsInstallMirrativ
struct UScriptHelperClient_IsInstallMirrativ_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsInstallMessenger
struct UScriptHelperClient_IsInstallMessenger_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsInstallLite
struct UScriptHelperClient_IsInstallLite_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsInstallLine
struct UScriptHelperClient_IsInstallLine_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsInstallFaceBook
struct UScriptHelperClient_IsInstallFaceBook_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsInstallDiscord
struct UScriptHelperClient_IsInstallDiscord_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsInstallBgBgByiTOP
struct UScriptHelperClient_IsInstallBgBgByiTOP_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsInReplayState
struct UScriptHelperClient_IsInReplayState_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsHOS
struct UScriptHelperClient_IsHOS_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsHapticsEngineEnable
struct UScriptHelperClient_IsHapticsEngineEnable_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsGameFileExistsWithPakCheck
struct UScriptHelperClient_IsGameFileExistsWithPakCheck_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsForCE
struct UScriptHelperClient_IsForCE_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsFileReady
struct UScriptHelperClient_IsFileReady_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsFileExistsWithPakCheckMatchExt
struct UScriptHelperClient_IsFileExistsWithPakCheckMatchExt_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsFileExistsWithPakCheck
struct UScriptHelperClient_IsFileExistsWithPakCheck_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsFileExistsWithOutPakCheck
struct UScriptHelperClient_IsFileExistsWithOutPakCheck_Params
{
	struct FString                                     Path;                                                     // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsFileExistInCSCWithCheck
struct UScriptHelperClient_IsFileExistInCSCWithCheck_Params
{
	struct FString                                     Path;                                                     // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsFileExistByFileName
struct UScriptHelperClient_IsFileExistByFileName_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsFileExistByExtension
struct UScriptHelperClient_IsFileExistByExtension_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	struct FString                                     fileExtension;                                            // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsFileExist
struct UScriptHelperClient_IsFileExist_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsEnableDSGrayPublishFlag
struct UScriptHelperClient_IsEnableDSGrayPublishFlag_Params
{
	uint64_t                                           nGrayPublishFlag;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsEmulatorWhenInit
struct UScriptHelperClient_IsEmulatorWhenInit_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsEmulator
struct UScriptHelperClient_IsEmulator_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsEditorDedicatedServer
struct UScriptHelperClient_IsEditorDedicatedServer_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsEditor
struct UScriptHelperClient_IsEditor_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsEarlyZPassEnable
struct UScriptHelperClient_IsEarlyZPassEnable_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsDolbyAtmosSupported
struct UScriptHelperClient_IsDolbyAtmosSupported_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsDeviceSupportsViberation
struct UScriptHelperClient_IsDeviceSupportsViberation_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsDeviceSupportsHapticsEngine
struct UScriptHelperClient_IsDeviceSupportsHapticsEngine_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsDeviceSupportGyrSensor
struct UScriptHelperClient_IsDeviceSupportGyrSensor_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsDeviceOverheat
struct UScriptHelperClient_IsDeviceOverheat_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsDeviceHWSupportVulkan
struct UScriptHelperClient_IsDeviceHWSupportVulkan_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsDevelopment
struct UScriptHelperClient_IsDevelopment_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsConnected
struct UScriptHelperClient_IsConnected_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsCloudVersion
struct UScriptHelperClient_IsCloudVersion_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsCEVersion
struct UScriptHelperClient_IsCEVersion_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsCEHideLobbyUI
struct UScriptHelperClient_IsCEHideLobbyUI_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsBasePrefecthOpen
struct UScriptHelperClient_IsBasePrefecthOpen_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsAsanVersion
struct UScriptHelperClient_IsAsanVersion_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.IsAndroidHasGyr
struct UScriptHelperClient_IsAndroidHasGyr_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.InviteWhatsappOfflineFriends
struct UScriptHelperClient_InviteWhatsappOfflineFriends_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Title;                                                    // (Parm, ZeroConstructor)
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.InviteSystemOfflineFriends
struct UScriptHelperClient_InviteSystemOfflineFriends_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Title;                                                    // (Parm, ZeroConstructor)
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.InviteSMSOfflineFriends
struct UScriptHelperClient_InviteSMSOfflineFriends_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.InviteLineOfflineFriends
struct UScriptHelperClient_InviteLineOfflineFriends_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Title;                                                    // (Parm, ZeroConstructor)
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.InviteFBOfflineFriends
struct UScriptHelperClient_InviteFBOfflineFriends_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Title;                                                    // (Parm, ZeroConstructor)
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
	struct FString                                     link;                                                     // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.InstallNewApp
struct UScriptHelperClient_InstallNewApp_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.InitWebViewManager
struct UScriptHelperClient_InitWebViewManager_Params
{
};

// Function Client.ScriptHelperClient.InitVPN
struct UScriptHelperClient_InitVPN_Params
{
	struct FString                                     InVPNGUID;                                                // (Parm, ZeroConstructor)
	struct FString                                     InClientVersion;                                          // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.InitVlink
struct UScriptHelperClient_InitVlink_Params
{
};

// Function Client.ScriptHelperClient.InitQPlatformMisc
struct UScriptHelperClient_InitQPlatformMisc_Params
{
};

// Function Client.ScriptHelperClient.InitLoginAccount
struct UScriptHelperClient_InitLoginAccount_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	uint64_t                                           AccUin;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     AccPswd;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.InitJavaFunctions
struct UScriptHelperClient_InitJavaFunctions_Params
{
};

// Function Client.ScriptHelperClient.InitIOSNotchSize
struct UScriptHelperClient_InitIOSNotchSize_Params
{
};

// Function Client.ScriptHelperClient.InitIMSDKEnv
struct UScriptHelperClient_InitIMSDKEnv_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           iEnv;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.InitializePuffer
struct UScriptHelperClient_InitializePuffer_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               needCheck;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                maxDownloadsPerTask;                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                maxDownTask;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                maxDownloadSpeed;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               useOldInterface;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               removeOldWhenUpdate;                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                versionType;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InDownloadFuncDict;                                       // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.InitializeLaggingReporter
struct UScriptHelperClient_InitializeLaggingReporter_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               Enable;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.InitHF
struct UScriptHelperClient_InitHF_Params
{
};

// Function Client.ScriptHelperClient.InitHDmpveRemoteConfig
struct UScriptHelperClient_InitHDmpveRemoteConfig_Params
{
};

// Function Client.ScriptHelperClient.InitDH
struct UScriptHelperClient_InitDH_Params
{
	struct FString                                     gen;                                                      // (Parm, ZeroConstructor)
	struct FString                                     prime;                                                    // (Parm, ZeroConstructor)
	int                                                v_srand;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.HtmlEncode
struct UScriptHelperClient_HtmlEncode_Params
{
	struct FString                                     UnencodedString;                                          // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.HideH5WebView
struct UScriptHelperClient_HideH5WebView_Params
{
};

// Function Client.ScriptHelperClient.HDmpveRemoteConfigStartOnce
struct UScriptHelperClient_HDmpveRemoteConfigStartOnce_Params
{
};

// Function Client.ScriptHelperClient.HDmpveRemoteConfigSetUrl
struct UScriptHelperClient_HDmpveRemoteConfigSetUrl_Params
{
	struct FString                                     InRemoteConfigUrl;                                        // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.HDmpveRemoteConfigGetStringNotDefalut
struct UScriptHelperClient_HDmpveRemoteConfigGetStringNotDefalut_Params
{
	struct FString                                     InKey;                                                    // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.HDmpveRemoteConfigGetString
struct UScriptHelperClient_HDmpveRemoteConfigGetString_Params
{
	struct FString                                     InKey;                                                    // (Parm, ZeroConstructor)
	struct FString                                     InDefaultValue;                                           // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.HDmpveRemoteConfigGetIntNotDefalut
struct UScriptHelperClient_HDmpveRemoteConfigGetIntNotDefalut_Params
{
	struct FString                                     InKe;                                                     // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.HDmpveRemoteConfigGetInt
struct UScriptHelperClient_HDmpveRemoteConfigGetInt_Params
{
	struct FString                                     InKey;                                                    // (Parm, ZeroConstructor)
	int                                                InDefaultValue;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.HDmpveRemoteConfigGetBoolNotDefalut
struct UScriptHelperClient_HDmpveRemoteConfigGetBoolNotDefalut_Params
{
	struct FString                                     InKey;                                                    // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.HDmpveRemoteConfigGetBool
struct UScriptHelperClient_HDmpveRemoteConfigGetBool_Params
{
	struct FString                                     InKey;                                                    // (Parm, ZeroConstructor)
	bool                                               InDefaultValue;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.HDmpveRemoteConfigClear
struct UScriptHelperClient_HDmpveRemoteConfigClear_Params
{
};

// Function Client.ScriptHelperClient.HaveReceivedNoticeCallback
struct UScriptHelperClient_HaveReceivedNoticeCallback_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.HasRemoteConfigReady
struct UScriptHelperClient_HasRemoteConfigReady_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.HasNotice
struct UScriptHelperClient_HasNotice_Params
{
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Scene;                                                    // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.HasNotchInScreen
struct UScriptHelperClient_HasNotchInScreen_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.HasLoadGameSlotCrashFlag
struct UScriptHelperClient_HasLoadGameSlotCrashFlag_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.HasDownloadedBasePak
struct UScriptHelperClient_HasDownloadedBasePak_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.HasActiveWifi
struct UScriptHelperClient_HasActiveWifi_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GuestLogin
struct UScriptHelperClient_GuestLogin_Params
{
};

// Function Client.ScriptHelperClient.GotoPlatformAppraise
struct UScriptHelperClient_GotoPlatformAppraise_Params
{
};

// Function Client.ScriptHelperClient.GMTestAllocUObjs
struct UScriptHelperClient_GMTestAllocUObjs_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Num;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GMH5Enable
struct UScriptHelperClient_GMH5Enable_Params
{
	bool                                               Flag;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetYYXDeviceModel
struct UScriptHelperClient_GetYYXDeviceModel_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetWidgetsByClass
struct UScriptHelperClient_GetWidgetsByClass_Params
{
	class UWidget*                                     Parent;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UClass*                                      Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<class UWidget*>                             Children;                                                 // (Parm, OutParm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.GetWebViewTicket
struct UScriptHelperClient_GetWebViewTicket_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetWebviewFullScreenSize
struct UScriptHelperClient_GetWebviewFullScreenSize_Params
{
	int                                                OutSurfaceWidth;                                          // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                OutSurfaceHeight;                                         // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetWeaponDIYIconPath
struct UScriptHelperClient_GetWeaponDIYIconPath_Params
{
	struct FString                                     PlayerUID;                                                // (Parm, ZeroConstructor)
	int                                                WeaponId;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     PlanID;                                                   // (Parm, ZeroConstructor)
	bool                                               relativePath;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Width;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Height;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetVolume
struct UScriptHelperClient_GetVolume_Params
{
	int                                                InStreamType;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetVoiceSdkReconnectInfo
struct UScriptHelperClient_GetVoiceSdkReconnectInfo_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	TMap<struct FString, struct FString>               Data;                                                     // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function Client.ScriptHelperClient.GetUserVulkanSetting
struct UScriptHelperClient_GetUserVulkanSetting_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetUserTMFPTapEnableFlag
struct UScriptHelperClient_GetUserTMFPTapEnableFlag_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetUseMouseForTouch
struct UScriptHelperClient_GetUseMouseForTouch_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetUObjectName
struct UScriptHelperClient_GetUObjectName_Params
{
	class UObject*                                     uObj;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetUnrealNetworkStatus
struct UScriptHelperClient_GetUnrealNetworkStatus_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetUIRectOffset
struct UScriptHelperClient_GetUIRectOffset_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetToken
struct UScriptHelperClient_GetToken_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetTMFPTapDeviceSupportFlag
struct UScriptHelperClient_GetTMFPTapDeviceSupportFlag_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetTimezoneName
struct UScriptHelperClient_GetTimezoneName_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetTimeInMiliSeconds
struct UScriptHelperClient_GetTimeInMiliSeconds_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetTelecomSvr
struct UScriptHelperClient_GetTelecomSvr_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetTCDeviceLevel
struct UScriptHelperClient_GetTCDeviceLevel_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetTableCount
struct UScriptHelperClient_GetTableCount_Params
{
	struct FString                                     tableName;                                                // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetSystemProperty
struct UScriptHelperClient_GetSystemProperty_Params
{
	struct FString                                     InKey;                                                    // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetSystemLanguage_LuaState
struct UScriptHelperClient_GetSystemLanguage_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetSubsideFeatureLevel
struct UScriptHelperClient_GetSubsideFeatureLevel_Params
{
	uint32_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetSrcVersion
struct UScriptHelperClient_GetSrcVersion_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetSplitMapConfigInfo
struct UScriptHelperClient_GetSplitMapConfigInfo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetSpecialData
struct UScriptHelperClient_GetSpecialData_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetSoundEffectQuality
struct UScriptHelperClient_GetSoundEffectQuality_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetShaderPrecompileProgress
struct UScriptHelperClient_GetShaderPrecompileProgress_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetServerDelay
struct UScriptHelperClient_GetServerDelay_Params
{
	struct FString                                     ServerAddress;                                            // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetScreenWidthForWebview
struct UScriptHelperClient_GetScreenWidthForWebview_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetScreenWidth
struct UScriptHelperClient_GetScreenWidth_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetScreenHight
struct UScriptHelperClient_GetScreenHight_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetScreenHeightForWebview
struct UScriptHelperClient_GetScreenHeightForWebview_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetScreenDensity
struct UScriptHelperClient_GetScreenDensity_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetRingMode
struct UScriptHelperClient_GetRingMode_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetRemarkNameByGIDWithObj
struct UScriptHelperClient_GetRemarkNameByGIDWithObj_Params
{
	class UObject*                                     Obj;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     gid;                                                      // (Parm, ZeroConstructor)
	struct FString                                     PlayerName;                                               // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetRemarkNameByGID
struct UScriptHelperClient_GetRemarkNameByGID_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     gid;                                                      // (Parm, ZeroConstructor)
	struct FString                                     PlayerName;                                               // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetRegisterChannelID
struct UScriptHelperClient_GetRegisterChannelID_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetRedFlameSwitch
struct UScriptHelperClient_GetRedFlameSwitch_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetRedBloodSwitch
struct UScriptHelperClient_GetRedBloodSwitch_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetPufferInitResult
struct UScriptHelperClient_GetPufferInitResult_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetPufferInitErrCode
struct UScriptHelperClient_GetPufferInitErrCode_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetPublishRegion
struct UScriptHelperClient_GetPublishRegion_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetPublicKey
struct UScriptHelperClient_GetPublicKey_Params
{
	struct FString                                     cli_pri_key;                                              // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetPUBGModuleBaseAddr
struct UScriptHelperClient_GetPUBGModuleBaseAddr_Params
{
	struct FString                                     ParamModuleName;                                          // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetPrivateKey
struct UScriptHelperClient_GetPrivateKey_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetPkgsFromDir
struct UScriptHelperClient_GetPkgsFromDir_Params
{
	bool                                               bUseCheck;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InDir;                                                    // (Parm, ZeroConstructor)
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetPingReportInfo
struct UScriptHelperClient_GetPingReportInfo_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetPingReportData
struct UScriptHelperClient_GetPingReportData_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetPhysicalScreenWidth
struct UScriptHelperClient_GetPhysicalScreenWidth_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetPhysicalScreenHeight
struct UScriptHelperClient_GetPhysicalScreenHeight_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetPhysicalFileTime
struct UScriptHelperClient_GetPhysicalFileTime_Params
{
	struct FString                                     InPath;                                                   // (Parm, ZeroConstructor)
	int64_t                                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetPhoneType
struct UScriptHelperClient_GetPhoneType_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetPhoneDeviceID
struct UScriptHelperClient_GetPhoneDeviceID_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetPhoneAdvertisingID
struct UScriptHelperClient_GetPhoneAdvertisingID_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetPackChannel
struct UScriptHelperClient_GetPackChannel_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetOSVersion
struct UScriptHelperClient_GetOSVersion_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetOperator
struct UScriptHelperClient_GetOperator_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetODPaksFileUseTime
struct UScriptHelperClient_GetODPaksFileUseTime_Params
{
	struct FString                                     DumpFilename;                                             // (Parm, ZeroConstructor)
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetObjectArrayNum
struct UScriptHelperClient_GetObjectArrayNum_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetNotchSize
struct UScriptHelperClient_GetNotchSize_Params
{
	TArray<int>                                        ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetNetWorkType
struct UScriptHelperClient_GetNetWorkType_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetNativeVersion
struct UScriptHelperClient_GetNativeVersion_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetNativePackageTag
struct UScriptHelperClient_GetNativePackageTag_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetMyFriendObservers
struct UScriptHelperClient_GetMyFriendObservers_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetMountedPaks
struct UScriptHelperClient_GetMountedPaks_Params
{
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetMemoryStats_LuaState
struct UScriptHelperClient_GetMemoryStats_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetMemorySize
struct UScriptHelperClient_GetMemorySize_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetLuaRootDir
struct UScriptHelperClient_GetLuaRootDir_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetLoginChannel
struct UScriptHelperClient_GetLoginChannel_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetLoadGameSlotCrashInfo
struct UScriptHelperClient_GetLoadGameSlotCrashInfo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetLoadCostUseTime
struct UScriptHelperClient_GetLoadCostUseTime_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetLaunchLocalNotificationID
struct UScriptHelperClient_GetLaunchLocalNotificationID_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetLastSessionUserId
struct UScriptHelperClient_GetLastSessionUserId_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetKnownMissingPackage
struct UScriptHelperClient_GetKnownMissingPackage_Params
{
	struct FString                                     PackageName;                                              // (Parm, ZeroConstructor)
	struct FString                                     DumpFilename;                                             // (Parm, ZeroConstructor)
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetiTOPLbsDelay
struct UScriptHelperClient_GetiTOPLbsDelay_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetITopGameId
struct UScriptHelperClient_GetITopGameId_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetIsSecretVersion
struct UScriptHelperClient_GetIsSecretVersion_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetIsPlayerUsingVPN
struct UScriptHelperClient_GetIsPlayerUsingVPN_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetIsOpenBattlePlayback
struct UScriptHelperClient_GetIsOpenBattlePlayback_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetIPRegion
struct UScriptHelperClient_GetIPRegion_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetIpAddrByHost
struct UScriptHelperClient_GetIpAddrByHost_Params
{
	struct FString                                     Host;                                                     // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetIpAddr
struct UScriptHelperClient_GetIpAddr_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetInstallChannelID
struct UScriptHelperClient_GetInstallChannelID_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetIMSDKEnv
struct UScriptHelperClient_GetIMSDKEnv_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetHDmpveInstanceId
struct UScriptHelperClient_GetHDmpveInstanceId_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetH5CacheStatus
struct UScriptHelperClient_GetH5CacheStatus_Params
{
	struct FString                                     ModuleName;                                               // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetGroupInfo
struct UScriptHelperClient_GetGroupInfo_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                SnsAction;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FGroupInfoWrapper                           ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function Client.ScriptHelperClient.GetGPUFamily
struct UScriptHelperClient_GetGPUFamily_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetGoogleServiceVersionCode
struct UScriptHelperClient_GetGoogleServiceVersionCode_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetGLVersion
struct UScriptHelperClient_GetGLVersion_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetGLType
struct UScriptHelperClient_GetGLType_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetGameStatus
struct UScriptHelperClient_GetGameStatus_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetGameModeID
struct UScriptHelperClient_GetGameModeID_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetGameMasterGUID
struct UScriptHelperClient_GetGameMasterGUID_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetFrameCounter
struct UScriptHelperClient_GetFrameCounter_Params
{
	int64_t                                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetFPS
struct UScriptHelperClient_GetFPS_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetForceVulkanAvailable
struct UScriptHelperClient_GetForceVulkanAvailable_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetFireBaseFCMToken
struct UScriptHelperClient_GetFireBaseFCMToken_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetFileSizeOnDiskBytes
struct UScriptHelperClient_GetFileSizeOnDiskBytes_Params
{
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	int64_t                                            ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetFileSizeOnDisk
struct UScriptHelperClient_GetFileSizeOnDisk_Params
{
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	uint32_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetFileSizeCompressed
struct UScriptHelperClient_GetFileSizeCompressed_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	uint64_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetFileHash
struct UScriptHelperClient_GetFileHash_Params
{
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetFileDirPath
struct UScriptHelperClient_GetFileDirPath_Params
{
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetFBFriendsUnregistered
struct UScriptHelperClient_GetFBFriendsUnregistered_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           page;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           Count;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     extend;                                                   // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.GetExactDeviceLevel
struct UScriptHelperClient_GetExactDeviceLevel_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetEncodeUrl
struct UScriptHelperClient_GetEncodeUrl_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetEmulatorName
struct UScriptHelperClient_GetEmulatorName_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetDSVersion
struct UScriptHelperClient_GetDSVersion_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetDSConnectionState
struct UScriptHelperClient_GetDSConnectionState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetDSConnectionIP
struct UScriptHelperClient_GetDSConnectionIP_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetDownLoadLanguageName
struct UScriptHelperClient_GetDownLoadLanguageName_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetDeviceXID
struct UScriptHelperClient_GetDeviceXID_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetDeviceQualityLevel
struct UScriptHelperClient_GetDeviceQualityLevel_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetDevicePlatformName
struct UScriptHelperClient_GetDevicePlatformName_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetDeviceName
struct UScriptHelperClient_GetDeviceName_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetDeviceModel
struct UScriptHelperClient_GetDeviceModel_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetDeviceMaxSupportSoundEffect
struct UScriptHelperClient_GetDeviceMaxSupportSoundEffect_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetDeviceMake
struct UScriptHelperClient_GetDeviceMake_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetDeviceInfo
struct UScriptHelperClient_GetDeviceInfo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetDeviceFreeSpace
struct UScriptHelperClient_GetDeviceFreeSpace_Params
{
	uint64_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetDeviceABIInfoJson
struct UScriptHelperClient_GetDeviceABIInfoJson_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetDeivceNickName
struct UScriptHelperClient_GetDeivceNickName_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetDataTime_MDHMS
struct UScriptHelperClient_GetDataTime_MDHMS_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetCurrentRHILevel
struct UScriptHelperClient_GetCurrentRHILevel_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetCurrentLanguage_LuaState
struct UScriptHelperClient_GetCurrentLanguage_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetCurrentChannel
struct UScriptHelperClient_GetCurrentChannel_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetCpuType
struct UScriptHelperClient_GetCpuType_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetConfigString
struct UScriptHelperClient_GetConfigString_Params
{
	struct FString                                     IniFileName;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     SectionName;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     KeyName;                                                  // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetConfigInt
struct UScriptHelperClient_GetConfigInt_Params
{
	struct FString                                     IniFileName;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     SectionName;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     KeyName;                                                  // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetConfigBool
struct UScriptHelperClient_GetConfigBool_Params
{
	struct FString                                     IniFileName;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     SectionName;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     KeyName;                                                  // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetCleanFileName
struct UScriptHelperClient_GetCleanFileName_Params
{
	struct FString                                     FilePath;                                                 // (Parm, OutParm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetCentauriPF_LuaState
struct UScriptHelperClient_GetCentauriPF_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetCentauriPayChannel_LuaState
struct UScriptHelperClient_GetCentauriPayChannel_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetCDNUpdateInfo
struct UScriptHelperClient_GetCDNUpdateInfo_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	TMap<struct FString, struct FString>               Data;                                                     // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function Client.ScriptHelperClient.GetCarrierInfo
struct UScriptHelperClient_GetCarrierInfo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetBuildVersion
struct UScriptHelperClient_GetBuildVersion_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetBlockCRC
struct UScriptHelperClient_GetBlockCRC_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	int64_t                                            Offset;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           Size;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetBattleKey
struct UScriptHelperClient_GetBattleKey_Params
{
	struct FString                                     svr_pub_key;                                              // (Parm, ZeroConstructor)
	struct FString                                     cli_pri_key;                                              // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetAreaIPNo
struct UScriptHelperClient_GetAreaIPNo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetAppVersion
struct UScriptHelperClient_GetAppVersion_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetAppMountHandleInfo
struct UScriptHelperClient_GetAppMountHandleInfo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetApplicationVersion
struct UScriptHelperClient_GetApplicationVersion_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetAOSSHOP
struct UScriptHelperClient_GetAOSSHOP_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetAndroidVersion
struct UScriptHelperClient_GetAndroidVersion_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetAndroidSysInfo
struct UScriptHelperClient_GetAndroidSysInfo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetAndroidSOVersion
struct UScriptHelperClient_GetAndroidSOVersion_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetAndroidMaxStackSize
struct UScriptHelperClient_GetAndroidMaxStackSize_Params
{
	uint32_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetAndroidMaxFDNum
struct UScriptHelperClient_GetAndroidMaxFDNum_Params
{
	uint32_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetAndroidCurrentFDNum
struct UScriptHelperClient_GetAndroidCurrentFDNum_Params
{
	uint32_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetAndroidBuildForArm
struct UScriptHelperClient_GetAndroidBuildForArm_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GetAllLocalNotificationIDs
struct UScriptHelperClient_GetAllLocalNotificationIDs_Params
{
	TArray<int>                                        ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetAllFilesInDir
struct UScriptHelperClient_GetAllFilesInDir_Params
{
	struct FString                                     Dir;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Pattern;                                                  // (Parm, ZeroConstructor)
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetAccountRegion
struct UScriptHelperClient_GetAccountRegion_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GetAccessToken
struct UScriptHelperClient_GetAccessToken_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GenerateQRImage
struct UScriptHelperClient_GenerateQRImage_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                Tag;                                                      // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	int                                                Size;                                                     // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
	struct FString                                     logoPath;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.GEMReportSubEvent
struct UScriptHelperClient_GEMReportSubEvent_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     EventName;                                                // (Parm, ZeroConstructor)
	struct FString                                     SubEventName;                                             // (Parm, ZeroConstructor)
	TArray<struct FString>                             eventParams;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function Client.ScriptHelperClient.GEMReportLobbyCustomEvent
struct UScriptHelperClient_GEMReportLobbyCustomEvent_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                EventID;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               IsSuccess;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     strDesc;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.GEMReportEvent
struct UScriptHelperClient_GEMReportEvent_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     EventName;                                                // (Parm, ZeroConstructor)
	TMap<struct FString, struct FString>               eventParams;                                              // (Parm, OutParm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.GEMReportEnterLobbyEvent
struct UScriptHelperClient_GEMReportEnterLobbyEvent_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               IsSuccess;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     strDesc;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.GameMasterSetUserInfo
struct UScriptHelperClient_GameMasterSetUserInfo_Params
{
	struct FString                                     InPaidInfo;                                               // (Parm, ZeroConstructor)
	struct FString                                     InUserToken;                                              // (Parm, ZeroConstructor)
	struct FString                                     InAppId;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.GameMasterSetUsableRegion
struct UScriptHelperClient_GameMasterSetUsableRegion_Params
{
	struct FString                                     InRegion;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.GameMasterSetUdpEchoPort
struct UScriptHelperClient_GameMasterSetUdpEchoPort_Params
{
	int                                                InPort;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GameMasterSetOnlyWifiAccel
struct UScriptHelperClient_GameMasterSetOnlyWifiAccel_Params
{
	bool                                               InOn;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GameMasterSetFreeFlowUser
struct UScriptHelperClient_GameMasterSetFreeFlowUser_Params
{
	int                                                InType;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GameMasterOnNetDelay
struct UScriptHelperClient_GameMasterOnNetDelay_Params
{
	int                                                InMillis;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GameMasterIsAccelOpened
struct UScriptHelperClient_GameMasterIsAccelOpened_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GameMasterInit
struct UScriptHelperClient_GameMasterInit_Params
{
	int                                                InHookType;                                               // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InGuid;                                                   // (Parm, ZeroConstructor)
	struct FString                                     InLibs;                                                   // (Parm, ZeroConstructor)
	int                                                InEchoPort;                                               // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GameMasterGetWebUIUrl
struct UScriptHelperClient_GameMasterGetWebUIUrl_Params
{
	int                                                InType;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GameMasterGetVIPValidTime
struct UScriptHelperClient_GameMasterGetVIPValidTime_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GameMasterGetUserID
struct UScriptHelperClient_GameMasterGetUserID_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.GameMasterGetAccelerationStatus
struct UScriptHelperClient_GameMasterGetAccelerationStatus_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GameMasterClearAccelAddr
struct UScriptHelperClient_GameMasterClearAccelAddr_Params
{
};

// Function Client.ScriptHelperClient.GameMasterBeginRound
struct UScriptHelperClient_GameMasterBeginRound_Params
{
	struct FString                                     InOpenid;                                                 // (Parm, ZeroConstructor)
	struct FString                                     InPvpId;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.GameMasterAddNewArenaAddress
struct UScriptHelperClient_GameMasterAddNewArenaAddress_Params
{
	struct FString                                     InProtocol;                                               // (Parm, ZeroConstructor)
	struct FString                                     InIp;                                                     // (Parm, ZeroConstructor)
	int                                                InPort;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GameMasterAddAccelAddr
struct UScriptHelperClient_GameMasterAddAccelAddr_Params
{
	struct FString                                     InProtocol;                                               // (Parm, ZeroConstructor)
	struct FString                                     InIp;                                                     // (Parm, ZeroConstructor)
	int                                                InPort;                                                   // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GameJoySwitchOn
struct UScriptHelperClient_GameJoySwitchOn_Params
{
	int                                                isOn;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GameJoyStopManualRecord
struct UScriptHelperClient_GameJoyStopManualRecord_Params
{
};

// Function Client.ScriptHelperClient.GameJoyStartMomentsRecord
struct UScriptHelperClient_GameJoyStartMomentsRecord_Params
{
};

// Function Client.ScriptHelperClient.GameJoyStartManualRecord
struct UScriptHelperClient_GameJoyStartManualRecord_Params
{
};

// Function Client.ScriptHelperClient.GameJoySetVideoQuality
struct UScriptHelperClient_GameJoySetVideoQuality_Params
{
	int                                                Quality;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GameJoySetMomentRecordSwitchOn
struct UScriptHelperClient_GameJoySetMomentRecordSwitchOn_Params
{
	int                                                isOn;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GameJoySetLuaguage
struct UScriptHelperClient_GameJoySetLuaguage_Params
{
};

// Function Client.ScriptHelperClient.GameJoySetCurrentRecorderPosition
struct UScriptHelperClient_GameJoySetCurrentRecorderPosition_Params
{
	float                                              X;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              Y;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GameJoyIsSDKFeatureSupport
struct UScriptHelperClient_GameJoyIsSDKFeatureSupport_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.GameJoyEndMomentsRecord
struct UScriptHelperClient_GameJoyEndMomentsRecord_Params
{
};

// Function Client.ScriptHelperClient.GameJoyClearMomentsVideo
struct UScriptHelperClient_GameJoyClearMomentsVideo_Params
{
};

// Function Client.ScriptHelperClient.GainSystemLog
struct UScriptHelperClient_GainSystemLog_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.FullPathFileExist
struct UScriptHelperClient_FullPathFileExist_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.FullGC
struct UScriptHelperClient_FullGC_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.FlushKnownMissingPackageRefObject
struct UScriptHelperClient_FlushKnownMissingPackageRefObject_Params
{
};

// Function Client.ScriptHelperClient.FlushAndroidWindowMemory
struct UScriptHelperClient_FlushAndroidWindowMemory_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.FinishPufferUpdateInDolphin
struct UScriptHelperClient_FinishPufferUpdateInDolphin_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               IsFinished;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.FindObjectByPath
struct UScriptHelperClient_FindObjectByPath_Params
{
	struct FString                                     ObjectPath;                                               // (Parm, ZeroConstructor)
	class UObject*                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.FindFilesRecursiveSkipPakPlatform
struct UScriptHelperClient_FindFilesRecursiveSkipPakPlatform_Params
{
	struct FString                                     Dir;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Pattern;                                                  // (Parm, ZeroConstructor)
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.FindClassByPath
struct UScriptHelperClient_FindClassByPath_Params
{
	struct FString                                     ObjectPath;                                               // (Parm, ZeroConstructor)
	class UClass*                                      ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.FileSystemTesting
struct UScriptHelperClient_FileSystemTesting_Params
{
	uint32_t                                           Count;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.FetchFileFromPAK
struct UScriptHelperClient_FetchFileFromPAK_Params
{
	struct FString                                     InFilePathInPak;                                          // (Parm, ZeroConstructor)
	struct FString                                     InLocalFilePath;                                          // (Parm, ZeroConstructor)
	bool                                               Override;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ExitGameForSafety
struct UScriptHelperClient_ExitGameForSafety_Params
{
};

// Function Client.ScriptHelperClient.ExitGame
struct UScriptHelperClient_ExitGame_Params
{
};

// Function Client.ScriptHelperClient.ExeMemoryWarningHandle
struct UScriptHelperClient_ExeMemoryWarningHandle_Params
{
};

// Function Client.ScriptHelperClient.EnterLoading
struct UScriptHelperClient_EnterLoading_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.EnterFightChat
struct UScriptHelperClient_EnterFightChat_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     gid;                                                      // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.EnterBattleStandAlone
struct UScriptHelperClient_EnterBattleStandAlone_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     MapPath;                                                  // (Parm, ZeroConstructor)
	uint32_t                                           PlayerKey;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     PlayerName;                                               // (Parm, ZeroConstructor)
	struct FString                                     DynamicLevelsOp;                                          // (Parm, ZeroConstructor)
	struct FString                                     AdditionalURLSuffixes;                                    // (Parm, ZeroConstructor)
	uint32_t                                           ModeID;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.EnterBattle
struct UScriptHelperClient_EnterBattle_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     HostnameOrIP;                                             // (Parm, ZeroConstructor)
	uint32_t                                           Port;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           PlayerKey;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     PlayerName;                                               // (Parm, ZeroConstructor)
	struct FString                                     PacketKey;                                                // (Parm, ZeroConstructor)
	uint64_t                                           GameID;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               IsObserver;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	TMap<int, struct FString>                          AdvConfig;                                                // (Parm, OutParm, ZeroConstructor)
	int                                                WaterType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           WaterUserID;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           ModeID;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           MainModeID;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     DynamicLevelsOp;                                          // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.EncryptUID
struct UScriptHelperClient_EncryptUID_Params
{
	struct FString                                     sUid;                                                     // (Parm, ZeroConstructor)
	struct FString                                     sKey;                                                     // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.EncryptItemData
struct UScriptHelperClient_EncryptItemData_Params
{
	TArray<int>                                        EncryptionItemList;                                       // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
};

// Function Client.ScriptHelperClient.EnableUseOldInterface
struct UScriptHelperClient_EnableUseOldInterface_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               Enable;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.EnableUrlCheck
struct UScriptHelperClient_EnableUrlCheck_Params
{
	bool                                               bShouldEnable;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.EnableTxtCheck
struct UScriptHelperClient_EnableTxtCheck_Params
{
};

// Function Client.ScriptHelperClient.EnableShaderGroup
struct UScriptHelperClient_EnableShaderGroup_Params
{
	struct FString                                     GroupName;                                                // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.EnableReportVoiceSdkEvent
struct UScriptHelperClient_EnableReportVoiceSdkEvent_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               InitVoiceSdkComponentReportEnable;                        // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               VoiceSdkJoinRoomReportEnable;                             // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               VoiceSdkQuitRoomReportEnable;                             // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               VoiceSdkJoinLbsRoomReportEnable;                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               VoiceSdkQuitLbsRoomReportEnable;                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               VoiceSdkOnJoinTeamRoomReportEnable;                       // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               VoiceSdkOnJoinLbsRoomReportEnable;                        // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.EnableNativeDump
struct UScriptHelperClient_EnableNativeDump_Params
{
	int                                                EnableDump;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.EnableMergeVirtual
struct UScriptHelperClient_EnableMergeVirtual_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.EnableLowMemoryDevice
struct UScriptHelperClient_EnableLowMemoryDevice_Params
{
	bool                                               bEnable;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.EnableLocalizationStatus
struct UScriptHelperClient_EnableLocalizationStatus_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               Status;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.EnableIosStuckWork
struct UScriptHelperClient_EnableIosStuckWork_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bEnable;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.EnableDataTunnelReport
struct UScriptHelperClient_EnableDataTunnelReport_Params
{
	bool                                               InEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.EnableAutoObjectRefreshStage
struct UScriptHelperClient_EnableAutoObjectRefreshStage_Params
{
	bool                                               bEnable;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.EnableAkAudioSilenceMode
struct UScriptHelperClient_EnableAkAudioSilenceMode_Params
{
	bool                                               InEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.DynamicUpdatePakOrderBackUp
struct UScriptHelperClient_DynamicUpdatePakOrderBackUp_Params
{
	struct FString                                     Filename;                                                 // (ConstParm, Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.DynamicUpdatePakOrder
struct UScriptHelperClient_DynamicUpdatePakOrder_Params
{
	struct FString                                     Filename;                                                 // (ConstParm, Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.DumpPhysScene
struct UScriptHelperClient_DumpPhysScene_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.DumpPackageMemInfo
struct UScriptHelperClient_DumpPackageMemInfo_Params
{
	TArray<struct FString>                             AssetList;                                                // (Parm, OutParm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.DumpOpenReadCollect
struct UScriptHelperClient_DumpOpenReadCollect_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     DumpFilename;                                             // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.DumpLogFile
struct UScriptHelperClient_DumpLogFile_Params
{
	bool                                               backup;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.Disconnect
struct UScriptHelperClient_Disconnect_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.DisableRepairResource
struct UScriptHelperClient_DisableRepairResource_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.DisableAndroidHardwareAcceleration
struct UScriptHelperClient_DisableAndroidHardwareAcceleration_Params
{
};

// Function Client.ScriptHelperClient.DirectToSetting
struct UScriptHelperClient_DirectToSetting_Params
{
};

// Function Client.ScriptHelperClient.DestroyConnector
struct UScriptHelperClient_DestroyConnector_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.DeleteFile
struct UScriptHelperClient_DeleteFile_Params
{
	struct FString                                     fullPath;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.DeleteDirectory
struct UScriptHelperClient_DeleteDirectory_Params
{
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.DelayToSetAutoInitFacebookLog
struct UScriptHelperClient_DelayToSetAutoInitFacebookLog_Params
{
	bool                                               IsAutoInit;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.DelayToInitFacebookSDK
struct UScriptHelperClient_DelayToInitFacebookSDK_Params
{
	bool                                               IsAutoInit;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               WithLaunchOption;                                         // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.DelayInitThirdPartSDK
struct UScriptHelperClient_DelayInitThirdPartSDK_Params
{
};

// Function Client.ScriptHelperClient.CSCGetStatInfo
struct UScriptHelperClient_CSCGetStatInfo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.CreateQRCodeTexture
struct UScriptHelperClient_CreateQRCodeTexture_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Text;                                                     // (Parm, ZeroConstructor)
	class UTexture2D*                                  ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CreateHapticsEngine
struct UScriptHelperClient_CreateHapticsEngine_Params
{
	struct FScriptDelegate                             Callback;                                                 // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.CrashSetAppVersion
struct UScriptHelperClient_CrashSetAppVersion_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Version;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.CrashPutUserData
struct UScriptHelperClient_CrashPutUserData_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Key;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Value;                                                    // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.CrashPostExceptionFull
struct UScriptHelperClient_CrashPostExceptionFull_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                Category;                                                 // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Name;                                                     // (Parm, ZeroConstructor)
	struct FString                                     Msg;                                                      // (Parm, ZeroConstructor)
	struct FString                                     stack;                                                    // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.CrashPostException
struct UScriptHelperClient_CrashPostException_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                Category;                                                 // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Reason;                                                   // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.CrashLog
struct UScriptHelperClient_CrashLog_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                Level;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Tag;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Log;                                                      // (Parm, ZeroConstructor)
	bool                                               needDump;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ConvertToAbsolutePathForExternalAppForWrite
struct UScriptHelperClient_ConvertToAbsolutePathForExternalAppForWrite_Params
{
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ConvertToAbsolutePathForExternalAppForRead
struct UScriptHelperClient_ConvertToAbsolutePathForExternalAppForRead_Params
{
	struct FString                                     FilePath;                                                 // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ConvertTMap2JsonStr
struct UScriptHelperClient_ConvertTMap2JsonStr_Params
{
	TMap<struct FString, struct FString>               mapData;                                                  // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ConvertRelativePathToFull
struct UScriptHelperClient_ConvertRelativePathToFull_Params
{
	struct FString                                     InPath;                                                   // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ConvertGamePathToRelativeFilePath
struct UScriptHelperClient_ConvertGamePathToRelativeFilePath_Params
{
	struct FString                                     Path;                                                     // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ConvertDataToHEX
struct UScriptHelperClient_ConvertDataToHEX_Params
{
	struct FString                                     CompressedData;                                           // (Parm, ZeroConstructor)
	int                                                CompressedSize;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ConsumeLocalNotificationLaunchApp
struct UScriptHelperClient_ConsumeLocalNotificationLaunchApp_Params
{
};

// Function Client.ScriptHelperClient.ConsoleCommand
struct UScriptHelperClient_ConsoleCommand_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Command;                                                  // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.ConnectToURLWithDNSProxy
struct UScriptHelperClient_ConnectToURLWithDNSProxy_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ProxyIP;                                                  // (Parm, ZeroConstructor)
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	int                                                ConnectTimeOutSeconds;                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ConnectToURL
struct UScriptHelperClient_ConnectToURL_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	int                                                ConnectTimeOutSeconds;                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ComputerName
struct UScriptHelperClient_ComputerName_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.CloudVersionPipe_SendDataWithKey
struct UScriptHelperClient_CloudVersionPipe_SendDataWithKey_Params
{
	struct FString                                     MsgKey;                                                   // (Parm, ZeroConstructor)
	struct FString                                     MsgInfo;                                                  // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CloudVersionPipe_SendData
struct UScriptHelperClient_CloudVersionPipe_SendData_Params
{
	struct FString                                     MsgInfo;                                                  // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CloudVersionPipe_RecvDataTest
struct UScriptHelperClient_CloudVersionPipe_RecvDataTest_Params
{
	struct FString                                     MsgInfo;                                                  // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CloudVersionPipe_PipeHelper
struct UScriptHelperClient_CloudVersionPipe_PipeHelper_Params
{
	class UObject*                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CloudVersionPipe_Log
struct UScriptHelperClient_CloudVersionPipe_Log_Params
{
	struct FString                                     LogInfo;                                                  // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CloudVersionInitDataPipeline
struct UScriptHelperClient_CloudVersionInitDataPipeline_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CloseWebView
struct UScriptHelperClient_CloseWebView_Params
{
};

// Function Client.ScriptHelperClient.CloseVLink
struct UScriptHelperClient_CloseVLink_Params
{
};

// Function Client.ScriptHelperClient.CloseVideoListDialog
struct UScriptHelperClient_CloseVideoListDialog_Params
{
};

// Function Client.ScriptHelperClient.CloseH5WebView
struct UScriptHelperClient_CloseH5WebView_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ClipBoardCopy
struct UScriptHelperClient_ClipBoardCopy_Params
{
	struct FString                                     Text;                                                     // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.ClientKickPlayerFromGame
struct UScriptHelperClient_ClientKickPlayerFromGame_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ClientEnterWarMode
struct UScriptHelperClient_ClientEnterWarMode_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ClientConfirmReturnToGame
struct UScriptHelperClient_ClientConfirmReturnToGame_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ClientConfirmMisKill
struct UScriptHelperClient_ClientConfirmMisKill_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                bConfirm;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ClearUpdatedSoPatch
struct UScriptHelperClient_ClearUpdatedSoPatch_Params
{
};

// Function Client.ScriptHelperClient.ClearSyncLoadCacheSystem
struct UScriptHelperClient_ClearSyncLoadCacheSystem_Params
{
};

// Function Client.ScriptHelperClient.ClearNotifications
struct UScriptHelperClient_ClearNotifications_Params
{
};

// Function Client.ScriptHelperClient.ClearNotice
struct UScriptHelperClient_ClearNotice_Params
{
};

// Function Client.ScriptHelperClient.ClearJankStats
struct UScriptHelperClient_ClearJankStats_Params
{
};

// Function Client.ScriptHelperClient.ClearIGProxyData
struct UScriptHelperClient_ClearIGProxyData_Params
{
};

// Function Client.ScriptHelperClient.ClearHasLoadGameSlotCrashFlag
struct UScriptHelperClient_ClearHasLoadGameSlotCrashFlag_Params
{
};

// Function Client.ScriptHelperClient.ClearChannelID
struct UScriptHelperClient_ClearChannelID_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.ClearAllLocalNotifications
struct UScriptHelperClient_ClearAllLocalNotifications_Params
{
};

// Function Client.ScriptHelperClient.CheckRegisterGestureConflictWithZoom
struct UScriptHelperClient_CheckRegisterGestureConflictWithZoom_Params
{
};

// Function Client.ScriptHelperClient.CheckLocalPakContentHash
struct UScriptHelperClient_CheckLocalPakContentHash_Params
{
	struct FString                                     Filename;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CheckLocalizationExist
struct UScriptHelperClient_CheckLocalizationExist_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CheckFilesInPakLite
struct UScriptHelperClient_CheckFilesInPakLite_Params
{
	TArray<struct FString>                             Files;                                                    // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.CheckFilesInPak
struct UScriptHelperClient_CheckFilesInPak_Params
{
	TArray<struct FString>                             Files;                                                    // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	TArray<struct FString>                             ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperClient.CheckCanUseUrl
struct UScriptHelperClient_CheckCanUseUrl_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CheckBeforeInitPuffer
struct UScriptHelperClient_CheckBeforeInitPuffer_Params
{
};

// Function Client.ScriptHelperClient.ChangeLocalizationReleaseTestStatus
struct UScriptHelperClient_ChangeLocalizationReleaseTestStatus_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               Status;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CentauriSDKInit_LuaState
struct UScriptHelperClient_CentauriSDKInit_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CentauriReprovide_LuaState
struct UScriptHelperClient_CentauriReprovide_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CanUseHapticsEngine
struct UScriptHelperClient_CanUseHapticsEngine_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CancelLocalNotification
struct UScriptHelperClient_CancelLocalNotification_Params
{
	int                                                NotificationID;                                           // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.CallIngameFirstTimeTips
struct UScriptHelperClient_CallIngameFirstTimeTips_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     tableName;                                                // (Parm, ZeroConstructor)
	struct FString                                     FunctionName;                                             // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.CallEngineGC
struct UScriptHelperClient_CallEngineGC_Params
{
};

// Function Client.ScriptHelperClient.CacheH5WebView
struct UScriptHelperClient_CacheH5WebView_Params
{
	struct FString                                     ModuleName;                                               // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.BqBqShareToFriend
struct UScriptHelperClient_BqBqShareToFriend_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                act;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     OpenID;                                                   // (Parm, ZeroConstructor)
	struct FString                                     Title;                                                    // (Parm, ZeroConstructor)
	struct FString                                     Desc;                                                     // (Parm, ZeroConstructor)
	struct FString                                     targetUrl;                                                // (Parm, ZeroConstructor)
	struct FString                                     imgUrl;                                                   // (Parm, ZeroConstructor)
	struct FString                                     previewText;                                              // (Parm, ZeroConstructor)
	struct FString                                     gameTag;                                                  // (Parm, ZeroConstructor)
	struct FString                                     msdkExtInfo;                                              // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.BqBqShareH5WithPhoto
struct UScriptHelperClient_BqBqShareH5WithPhoto_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     _title;                                                   // (Parm, ZeroConstructor)
	struct FString                                     _fullURL;                                                 // (Parm, ZeroConstructor)
	int                                                Channel;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.BqBqShare
struct UScriptHelperClient_BqBqShare_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     _descShare;                                               // (Parm, ZeroConstructor)
	struct FString                                     _titleShare;                                              // (Parm, ZeroConstructor)
	struct FString                                     _imgPath;                                                 // (Parm, ZeroConstructor)
	struct FString                                     _imgUrl;                                                  // (Parm, ZeroConstructor)
	struct FString                                     _url;                                                     // (Parm, ZeroConstructor)
	int                                                _shareScene;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.BqBqAddFriend
struct UScriptHelperClient_BqBqAddFriend_Params
{
	TScriptInterface<class UClientNetInterface>        ClientNetInterface;                                       // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	struct FString                                     OpenID;                                                   // (Parm, ZeroConstructor)
	struct FString                                     Desc;                                                     // (Parm, ZeroConstructor)
	struct FString                                     Message;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.BindMotionDetectedDelegate
struct UScriptHelperClient_BindMotionDetectedDelegate_Params
{
	class ASTExtraPlayerController*                    PlayerController;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	class UScreenInput*                                InScreenInput;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.AskForNotificationPermission
struct UScriptHelperClient_AskForNotificationPermission_Params
{
};

// Function Client.ScriptHelperClient.AppendForcedKeepODPaks
struct UScriptHelperClient_AppendForcedKeepODPaks_Params
{
	TArray<struct FString>                             Filenames;                                                // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.AndroidShouldShowPermissionRationale
struct UScriptHelperClient_AndroidShouldShowPermissionRationale_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.AndroidCheckPermission
struct UScriptHelperClient_AndroidCheckPermission_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.AllocVirMem
struct UScriptHelperClient_AllocVirMem_Params
{
	int64_t                                            XMiB;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.AkAudio_UnloadInitBank
struct UScriptHelperClient_AkAudio_UnloadInitBank_Params
{
};

// Function Client.ScriptHelperClient.AkAudio_UnloadAllFilePackages
struct UScriptHelperClient_AkAudio_UnloadAllFilePackages_Params
{
};

// Function Client.ScriptHelperClient.AkAudio_StopAllSounds
struct UScriptHelperClient_AkAudio_StopAllSounds_Params
{
	bool                                               bShouldStopUISounds;                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.AkAudio_LoadInitBank
struct UScriptHelperClient_AkAudio_LoadInitBank_Params
{
};

// Function Client.ScriptHelperClient.AkAudio_Flush
struct UScriptHelperClient_AkAudio_Flush_Params
{
	class UWorld*                                      WorldToFlush;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.AkAudio_ClearBanks
struct UScriptHelperClient_AkAudio_ClearBanks_Params
{
};

// Function Client.ScriptHelperClient.AddStreamingLevel
struct UScriptHelperClient_AddStreamingLevel_Params
{
	class UWorld*                                      World;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     SubLevel;                                                 // (Parm, ZeroConstructor)
	bool                                               bShouldBeLoaded;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bShouldBeVisible;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bShouldBlockOnLoad;                                       // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.AddOnScreenDebugMessage
struct UScriptHelperClient_AddOnScreenDebugMessage_Params
{
	struct FString                                     Message;                                                  // (Parm, ZeroConstructor)
	int                                                Key;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              TimeToDisplay;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	struct FColor                                      Color;                                                    // (Parm, OutParm, IsPlainOldData)
	struct FVector2D                                   TextScale;                                                // (Parm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.AddMemoryLogSize
struct UScriptHelperClient_AddMemoryLogSize_Params
{
	int                                                b_size;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperClient.AddKnownMissingPackage
struct UScriptHelperClient_AddKnownMissingPackage_Params
{
	struct FString                                     PackageName;                                              // (Parm, OutParm, ZeroConstructor)
	class UObject*                                     BindObj;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bReplace;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.AddCrashContextData
struct UScriptHelperClient_AddCrashContextData_Params
{
	int                                                Key;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Val;                                                      // (Parm, ZeroConstructor)
	bool                                               bAppendTimeStamp;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                reportLevel;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ScriptHelperClient.AddAttachFileString
struct UScriptHelperClient_AddAttachFileString_Params
{
	struct FString                                     Type;                                                     // (Parm, ZeroConstructor)
	bool                                               bClear;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     strinfo;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperClient.AddAttachDataString
struct UScriptHelperClient_AddAttachDataString_Params
{
	struct FString                                     Type;                                                     // (Parm, ZeroConstructor)
	bool                                               bClear;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     strinfo;                                                  // (Parm, ZeroConstructor)
};

// Function Client.ScriptHelperEngine.TestLz4Decompress
struct UScriptHelperEngine_TestLz4Decompress_Params
{
	TArray<unsigned char>                              Source;                                                   // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	bool                                               bEnable;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<unsigned char>                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperEngine.TestLz4Compress
struct UScriptHelperEngine_TestLz4Compress_Params
{
	TArray<unsigned char>                              Source;                                                   // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	TArray<unsigned char>                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperEngine.ReplaceEmoji
struct UScriptHelperEngine_ReplaceEmoji_Params
{
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
	int                                                MaxEmojiNum;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     SpecialCharacter;                                         // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.ScriptHelperEngine.IsLowMemoryDevice
struct UScriptHelperEngine_IsLowMemoryDevice_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperEngine.Is64BitVersion
struct UScriptHelperEngine_Is64BitVersion_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperEngine.GetMemoryUsedVirtualInKB
struct UScriptHelperEngine_GetMemoryUsedVirtualInKB_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ScriptHelperEngine.GetMemoryUsedPhysicalInKB
struct UScriptHelperEngine_GetMemoryUsedPhysicalInKB_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SDKCallbackHelper.Init
struct USDKCallbackHelper_Init_Params
{
};

// Function Client.SDKCallbackHelper.GetInstance
struct USDKCallbackHelper_GetInstance_Params
{
	class USDKCallbackHelper*                          ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.UpdateCustomSetting
struct USettingSubsystem_UpdateCustomSetting_Params
{
	struct FString                                     InSlotName;                                               // (Parm, ZeroConstructor)
	class USaveGame*                                   InSaveGame;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.UnregisterUserSettingDelegate
struct USettingSubsystem_UnregisterUserSettingDelegate_Params
{
	int                                                Handle;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.SettingSubsystem.SetUserSettings_String
struct USettingSubsystem_SetUserSettings_String_Params
{
	struct FString                                     PropertyName;                                             // (Parm, ZeroConstructor)
	struct FString                                     Val;                                                      // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.SetUserSettings_Int
struct USettingSubsystem_SetUserSettings_Int_Params
{
	struct FString                                     PropertyName;                                             // (Parm, ZeroConstructor)
	int                                                Value;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.SetUserSettings_Float
struct USettingSubsystem_SetUserSettings_Float_Params
{
	struct FString                                     PropertyName;                                             // (Parm, ZeroConstructor)
	float                                              Value;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.SetUserSettings_Bool
struct USettingSubsystem_SetUserSettings_Bool_Params
{
	struct FString                                     PropertyName;                                             // (Parm, ZeroConstructor)
	bool                                               Value;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               IngoreSave;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.RegisterUserSettingsDelegate_Int
struct USettingSubsystem_RegisterUserSettingsDelegate_Int_Params
{
	struct FString                                     PropertyName;                                             // (Parm, ZeroConstructor)
	struct FScriptDelegate                             Delegate;                                                 // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.RegisterUserSettingsDelegate_Float
struct USettingSubsystem_RegisterUserSettingsDelegate_Float_Params
{
	struct FString                                     PropertyName;                                             // (Parm, ZeroConstructor)
	struct FScriptDelegate                             Delegate;                                                 // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.RegisterUserSettingsDelegate_Bool
struct USettingSubsystem_RegisterUserSettingsDelegate_Bool_Params
{
	struct FString                                     PropertyName;                                             // (Parm, ZeroConstructor)
	struct FScriptDelegate                             Delegate;                                                 // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.RegisterUserSettingsDelegate
struct USettingSubsystem_RegisterUserSettingsDelegate_Params
{
	struct FScriptDelegate                             Delegate;                                                 // (Parm, ZeroConstructor)
};

// Function Client.SettingSubsystem.RefreshSettingDataForReport
struct USettingSubsystem_RefreshSettingDataForReport_Params
{
};

// Function Client.SettingSubsystem.OnReportSettingConfigStart
struct USettingSubsystem_OnReportSettingConfigStart_Params
{
};

// Function Client.SettingSubsystem.OnRefreshReportSettingConfig
struct USettingSubsystem_OnRefreshReportSettingConfig_Params
{
};

// Function Client.SettingSubsystem.GetUserSettingsByDelegate
struct USettingSubsystem_GetUserSettingsByDelegate_Params
{
	struct FString                                     LayoutName;                                               // (Parm, ZeroConstructor)
	class USaveGame*                                   ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.GetUserSettings_String
struct USettingSubsystem_GetUserSettings_String_Params
{
	struct FString                                     PropertyName;                                             // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.SettingSubsystem.GetUserSettings_Int
struct USettingSubsystem_GetUserSettings_Int_Params
{
	struct FString                                     PropertyName;                                             // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.GetUserSettings_Float
struct USettingSubsystem_GetUserSettings_Float_Params
{
	struct FString                                     PropertyName;                                             // (Parm, ZeroConstructor)
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.GetUserSettings_Bool
struct USettingSubsystem_GetUserSettings_Bool_Params
{
	struct FString                                     PropertyName;                                             // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.GetUserSettings
struct USettingSubsystem_GetUserSettings_Params
{
	class USaveGame*                                   ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.GetUserLanguageSettingsProperty_String
struct USettingSubsystem_GetUserLanguageSettingsProperty_String_Params
{
	struct FString                                     PropertyName;                                             // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.SettingSubsystem.GetEffectSettingMgr
struct USettingSubsystem_GetEffectSettingMgr_Params
{
	class UEffectSettingMgr*                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.GetCustomSetting
struct USettingSubsystem_GetCustomSetting_Params
{
	struct FString                                     InSlotName;                                               // (Parm, ZeroConstructor)
	class USaveGame*                                   ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.FinishModifyUserSettings
struct USettingSubsystem_FinishModifyUserSettings_Params
{
};

// Function Client.SettingSubsystem.ClearCustomSetting
struct USettingSubsystem_ClearCustomSetting_Params
{
};

// Function Client.SettingSubsystem.CheckLocalizationLanguage
struct USettingSubsystem_CheckLocalizationLanguage_Params
{
};

// Function Client.SettingSubsystem.CheckChangeWithCache
struct USettingSubsystem_CheckChangeWithCache_Params
{
	class UObject*                                     Source;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	class UProperty*                                   Property;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     PropertyName;                                             // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SettingSubsystem.CacheRegisterValue
struct USettingSubsystem_CacheRegisterValue_Params
{
	class UObject*                                     Source;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	class UProperty*                                   Property;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     PropertyName;                                             // (Parm, ZeroConstructor)
};

// Function Client.SettingSubsystem.BeginModifyUserSettings
struct USettingSubsystem_BeginModifyUserSettings_Params
{
};

// Function Client.SettingSubsystem.AddCustomSetting
struct USettingSubsystem_AddCustomSetting_Params
{
	struct FString                                     InSlotName;                                               // (Parm, ZeroConstructor)
	class USaveGame*                                   InSaveGame;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.SoundTools.StopConversionByUser
struct USoundTools_StopConversionByUser_Params
{
	int                                                Index;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.SoundTools.SaveWavInIOS
struct USoundTools_SaveWavInIOS_Params
{
	struct FString                                     GameFilePath;                                             // (Parm, ZeroConstructor)
};

// Function Client.SoundTools.SaveToAndroidPath
struct USoundTools_SaveToAndroidPath_Params
{
	struct FString                                     GameFilePath;                                             // (Parm, ZeroConstructor)
};

// Function Client.SoundTools.GetSizeOfWwiseAudioToWav
struct USoundTools_GetSizeOfWwiseAudioToWav_Params
{
	struct FString                                     EventName;                                                // (Parm, ZeroConstructor)
	struct FString                                     BankName;                                                 // (Parm, ZeroConstructor)
	struct FString                                     OutFilePath;                                              // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SoundTools.GetConversionPercent
struct USoundTools_GetConversionPercent_Params
{
	int                                                Index;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SoundTools.ConvertWwiseAudioToWavSync
struct USoundTools_ConvertWwiseAudioToWavSync_Params
{
	struct FString                                     EventName;                                                // (Parm, ZeroConstructor)
	struct FString                                     BankName;                                                 // (Parm, ZeroConstructor)
	struct FString                                     OutFilePath;                                              // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SoundTools.ConvertWwiseAudioToWav
struct USoundTools_ConvertWwiseAudioToWav_Params
{
	struct FString                                     EventName;                                                // (Parm, ZeroConstructor)
	struct FString                                     BankName;                                                 // (Parm, ZeroConstructor)
	struct FString                                     OutFilePath;                                              // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.SoundTools.CanWwiseAudioToWav
struct USoundTools_CanWwiseAudioToWav_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.STExtraClientUtils.GetWidgetHandleAsyncWithCallBack
struct USTExtraClientUtils_GetWidgetHandleAsyncWithCallBack_Params
{
	class UObject*                                     WorldContext;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ModuleName;                                               // (Parm, ZeroConstructor)
	struct FString                                     WidgetKey;                                                // (Parm, ZeroConstructor)
	struct FScriptDelegate                             Callback;                                                 // (Parm, ZeroConstructor)
};

// Function Client.STExtraClientUtils.GetDynamicWidgetHandle
struct USTExtraClientUtils_GetDynamicWidgetHandle_Params
{
	class UObject*                                     WorldContext;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ModuleName;                                               // (Parm, ZeroConstructor)
	struct FString                                     WidetKey;                                                 // (Parm, ZeroConstructor)
	class UUAEUserWidget*                              ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.STExtraClientUtils.GetBPUtils
struct USTExtraClientUtils_GetBPUtils_Params
{
	class USTExtraClientUIBPUtils*                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.STExtraClientUtils.AsyncLoadAssetInstWithCallback
struct USTExtraClientUtils_AsyncLoadAssetInstWithCallback_Params
{
	struct FString                                     InPath;                                                   // (Parm, ZeroConstructor)
	struct FScriptDelegate                             Callback;                                                 // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.STExtraClientUIBPUtils.OnAsyncAssetLoaded
struct USTExtraClientUIBPUtils_OnAsyncAssetLoaded_Params
{
	struct FSoftObjectPath                             InSoftPath;                                               // (Parm)
	int                                                RequestIdx;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.STExtraClientUIBPUtils.AsyncLoadAssetInstWithCallback
struct USTExtraClientUIBPUtils_AsyncLoadAssetInstWithCallback_Params
{
	struct FString                                     InPath;                                                   // (Parm, ZeroConstructor)
	struct FScriptDelegate                             Callback;                                                 // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TPerfPlat.SetQuality
struct UTPerfPlat_SetQuality_Params
{
	int                                                Quality;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.TPerfPlat.requestResourceGuarantee
struct UTPerfPlat_requestResourceGuarantee_Params
{
	int                                                Condition;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                LoadType;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                applyType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.TPerfPlat.PostGameStatusToTMFPIS
struct UTPerfPlat_PostGameStatusToTMFPIS_Params
{
	int                                                Key;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Value;                                                    // (Parm, ZeroConstructor)
};

// Function Client.TPerfPlat.GetDeviceLevel
struct UTPerfPlat_GetDeviceLevel_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.Translator.TranslateV2
struct UTranslator_TranslateV2_Params
{
	int                                                Channel;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ID;                                                       // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Text;                                                     // (Parm, ZeroConstructor)
};

// Function Client.Translator.Translate
struct UTranslator_Translate_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Verb;                                                     // (Parm, ZeroConstructor)
	TMap<struct FString, struct FString>               Headers;                                                  // (ConstParm, Parm, ZeroConstructor)
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
};

// Function Client.Translator.PostMsg
struct UTranslator_PostMsg_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
};

// Function Client.Translator.OnTranslateV2
struct UTranslator_OnTranslateV2_Params
{
	bool                                               Success;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Data;                                                     // (Parm, ZeroConstructor)
};

// DelegateFunction Client.Translator.OnTranslate__DelegateSignature
struct UTranslator_OnTranslate__DelegateSignature_Params
{
	bool                                               IsSuccess;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     LanguageFrom;                                             // (Parm, ZeroConstructor)
	struct FString                                     Translation;                                              // (Parm, ZeroConstructor)
};

// Function Client.Translator.OnTranslate
struct UTranslator_OnTranslate_Params
{
	bool                                               Success;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Data;                                                     // (Parm, ZeroConstructor)
};

// Function Client.Translator.OnGetAccessTokenV2
struct UTranslator_OnGetAccessTokenV2_Params
{
	bool                                               Success;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Data;                                                     // (Parm, ZeroConstructor)
};

// DelegateFunction Client.Translator.OnGetAccessToken__DelegateSignature
struct UTranslator_OnGetAccessToken__DelegateSignature_Params
{
	bool                                               IsSuccess;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Token;                                                    // (Parm, ZeroConstructor)
};

// Function Client.Translator.OnGetAccessToken
struct UTranslator_OnGetAccessToken_Params
{
	bool                                               Success;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Data;                                                     // (Parm, ZeroConstructor)
};

// Function Client.Translator.OnDetectV2
struct UTranslator_OnDetectV2_Params
{
	bool                                               Success;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Data;                                                     // (Parm, ZeroConstructor)
};

// DelegateFunction Client.Translator.OnDetect__DelegateSignature
struct UTranslator_OnDetect__DelegateSignature_Params
{
	bool                                               IsSuccess;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     from;                                                     // (Parm, ZeroConstructor)
	struct FString                                     to;                                                       // (Parm, ZeroConstructor)
};

// Function Client.Translator.OnDetect
struct UTranslator_OnDetect_Params
{
	bool                                               Success;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Data;                                                     // (Parm, ZeroConstructor)
};

// Function Client.Translator.HasTranslating
struct UTranslator_HasTranslating_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.Translator.GetAccessToken
struct UTranslator_GetAccessToken_Params
{
	bool                                               bForceGet;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Verb;                                                     // (Parm, ZeroConstructor)
	TMap<struct FString, struct FString>               Headers;                                                  // (ConstParm, Parm, ZeroConstructor)
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
};

// Function Client.Translator.Detect
struct UTranslator_Detect_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	struct FString                                     Verb;                                                     // (Parm, ZeroConstructor)
	TMap<struct FString, struct FString>               Headers;                                                  // (ConstParm, Parm, ZeroConstructor)
	struct FString                                     Content;                                                  // (Parm, ZeroConstructor)
};

// Function Client.TssManager.SendSkdData_LuaState
struct UTssManager_SendSkdData_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TssManager.SendEigeninfoData_LuaState
struct UTssManager_SendEigeninfoData_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TssManager.SaveSendEigeninfoCode_LuaState
struct UTssManager_SaveSendEigeninfoCode_LuaState_Params
{
	uint32_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TssManager.OnRecvData_LuaState
struct UTssManager_OnRecvData_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TssManager.InvokeSDKIoctl
struct UTssManager_InvokeSDKIoctl_Params
{
	int                                                Command;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InCmdData;                                                // (Parm, ZeroConstructor)
	uint32_t                                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TssManager.GetUserTag4Lua_LuaState
struct UTssManager_GetUserTag4Lua_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TssManager.GetDeviceFeature_LuaState
struct UTssManager_GetDeviceFeature_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.TssManager.EigenArrayObfuscationVerify_LuaState
struct UTssManager_EigenArrayObfuscationVerify_LuaState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.UTRichTextBlock.SetText
struct UUTRichTextBlock_SetText_Params
{
	struct FText                                       InText;                                                   // (Parm)
};

// Function Client.UTRichTextBlock.SetGameFrontendHUD
struct UUTRichTextBlock_SetGameFrontendHUD_Params
{
	class UGameFrontendHUD*                            InHUD;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.UTRichTextBlock.SetFont
struct UUTRichTextBlock_SetFont_Params
{
	struct FSlateFontInfo                              InFontInfo;                                               // (Parm)
};

// DelegateFunction Client.UTRichTextBlock.OnHyperlinkClickedEvent__DelegateSignature
struct UUTRichTextBlock_OnHyperlinkClickedEvent__DelegateSignature_Params
{
	struct FMetaDataHolder                             MetaDataHolder;                                           // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.UTRichTextBlock.GetViewSizes
struct UUTRichTextBlock_GetViewSizes_Params
{
	TArray<struct FVector2D>                           ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.UTRichTextBlock.GetText
struct UUTRichTextBlock_GetText_Params
{
	struct FText                                       ReturnValue;                                              // (Parm, OutParm, ReturnParm)
};

// Function Client.UTRichTextBlock.EstimateDesiredSize
struct UUTRichTextBlock_EstimateDesiredSize_Params
{
	struct FVector2D                                   ReturnValue;                                              // (Parm, OutParm, ReturnParm, IsPlainOldData)
};

// Function Client.AEVarButton.SetTouchMethod
struct UAEVarButton_SetTouchMethod_Params
{
	TEnumAsByte<EButtonTouchMethod>                    InTouchMethod;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.AEVarButton.SetStyle
struct UAEVarButton_SetStyle_Params
{
	struct FButtonStyle                                InStyle;                                                  // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.AEVarButton.SetColorAndOpacity
struct UAEVarButton_SetColorAndOpacity_Params
{
	struct FLinearColor                                InColorAndOpacity;                                        // (Parm, IsPlainOldData)
};

// Function Client.AEVarButton.SetClickMethod
struct UAEVarButton_SetClickMethod_Params
{
	TEnumAsByte<EButtonClickMethod>                    InClickMethod;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.AEVarButton.SetBackgroundColor
struct UAEVarButton_SetBackgroundColor_Params
{
	struct FLinearColor                                InBackgroundColor;                                        // (Parm, IsPlainOldData)
};

// Function Client.AEVarButton.IsPressed
struct UAEVarButton_IsPressed_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReuseFallC.SetScrollOffset
struct UReuseFallC_SetScrollOffset_Params
{
	float                                              NewScrollOffset;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseFallC.SetItemSize
struct UReuseFallC_SetItemSize_Params
{
	int                                                __Idx;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              __Size;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseFallC.SetItemFullStyle
struct UReuseFallC_SetItemFullStyle_Params
{
	int                                                idx;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseFallC.SetCurItemClass
struct UReuseFallC_SetCurItemClass_Params
{
	struct FString                                     StrName;                                                  // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReuseFallC.ScrollToStart
struct UReuseFallC_ScrollToStart_Params
{
};

// Function Client.ReuseFallC.ScrollToEnd
struct UReuseFallC_ScrollToEnd_Params
{
};

// Function Client.ReuseFallC.ResetCurItemClassToDefault
struct UReuseFallC_ResetCurItemClassToDefault_Params
{
};

// Function Client.ReuseFallC.Reload
struct UReuseFallC_Reload_Params
{
	int                                                __ItemCount;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseFallC.RefreshOne
struct UReuseFallC_RefreshOne_Params
{
	int                                                __Idx;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseFallC.Refresh
struct UReuseFallC_Refresh_Params
{
};

// DelegateFunction Client.ReuseFallC.OnUpdateItemDelegate__DelegateSignature
struct UReuseFallC_OnUpdateItemDelegate__DelegateSignature_Params
{
	class UUserWidget*                                 Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                idx;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// DelegateFunction Client.ReuseFallC.OnTouchFinishDelegate__DelegateSignature
struct UReuseFallC_OnTouchFinishDelegate__DelegateSignature_Params
{
};

// Function Client.ReuseFallC.OnTouchFinishCallback
struct UReuseFallC_OnTouchFinishCallback_Params
{
};

// DelegateFunction Client.ReuseFallC.OnOverscrollStateDelegate__DelegateSignature
struct UReuseFallC_OnOverscrollStateDelegate__DelegateSignature_Params
{
	EReuseFallOverscrollState                          State;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// DelegateFunction Client.ReuseFallC.OnCreateItemDelegate__DelegateSignature
struct UReuseFallC_OnCreateItemDelegate__DelegateSignature_Params
{
	class UUserWidget*                                 Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                idx;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// DelegateFunction Client.ReuseFallC.OnBeforeNewItemDelegate__DelegateSignature
struct UReuseFallC_OnBeforeNewItemDelegate__DelegateSignature_Params
{
	int                                                idx;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// DelegateFunction Client.ReuseFallC.OnAfterNewItemDelegate__DelegateSignature
struct UReuseFallC_OnAfterNewItemDelegate__DelegateSignature_Params
{
	class UUserWidget*                                 Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                idx;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseFallC.JumpByIdx
struct UReuseFallC_JumpByIdx_Params
{
	int                                                __Idx;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bImmedia;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseFallC.GetViewSize
struct UReuseFallC_GetViewSize_Params
{
	struct FVector2D                                   ReturnValue;                                              // (ConstParm, Parm, OutParm, ReturnParm, ReferenceParm, IsPlainOldData)
};

// Function Client.ReuseFallC.GetScrollOffset
struct UReuseFallC_GetScrollOffset_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReuseFallC.GetScrollBox
struct UReuseFallC_GetScrollBox_Params
{
	class UScrollBox*                                  ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.ReuseFallC.GetOverscrollState
struct UReuseFallC_GetOverscrollState_Params
{
	EReuseFallOverscrollState                          ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReuseFallC.GetContentSize
struct UReuseFallC_GetContentSize_Params
{
	struct FVector2D                                   ReturnValue;                                              // (ConstParm, Parm, OutParm, ReturnParm, ReferenceParm, IsPlainOldData)
};

// Function Client.ReuseFallC.ClearItemFullStyle
struct UReuseFallC_ClearItemFullStyle_Params
{
};

// Function Client.ReuseFallC.Clear
struct UReuseFallC_Clear_Params
{
};

// Function Client.ReuseListC.SetTitleSlotAutoSize
struct UReuseListC_SetTitleSlotAutoSize_Params
{
	bool                                               as;                                                       // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseListC.SetTitleSize
struct UReuseListC_SetTitleSize_Params
{
	int                                                sz;                                                       // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseListC.SetScrollOffset
struct UReuseListC_SetScrollOffset_Params
{
	float                                              NewScrollOffset;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseListC.ScrollToStart
struct UReuseListC_ScrollToStart_Params
{
};

// Function Client.ReuseListC.ScrollToEnd
struct UReuseListC_ScrollToEnd_Params
{
};

// Function Client.ReuseListC.Reset
struct UReuseListC_Reset_Params
{
	class UClass*                                      __ItemClass;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	EReuseListStyle                                    __Style;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                __ItemWidth;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                __ItemHeight;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                __PaddingX;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                __PaddingY;                                               // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseListC.Reload
struct UReuseListC_Reload_Params
{
	int                                                __ItemCount;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseListC.RefreshParam
struct UReuseListC_RefreshParam_Params
{
	struct FString                                     _Param;                                                   // (Parm, ZeroConstructor)
};

// Function Client.ReuseListC.RefreshOneParam
struct UReuseListC_RefreshOneParam_Params
{
	int                                                __Idx;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     _Param;                                                   // (Parm, ZeroConstructor)
};

// Function Client.ReuseListC.RefreshOne
struct UReuseListC_RefreshOne_Params
{
	int                                                __Idx;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseListC.Refresh
struct UReuseListC_Refresh_Params
{
};

// DelegateFunction Client.ReuseListC.OnUpdateItemParamDelegate__DelegateSignature
struct UReuseListC_OnUpdateItemParamDelegate__DelegateSignature_Params
{
	class UUserWidget*                                 Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                idx;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     Param;                                                    // (Parm, ZeroConstructor)
};

// DelegateFunction Client.ReuseListC.OnUpdateItemDelegate__DelegateSignature
struct UReuseListC_OnUpdateItemDelegate__DelegateSignature_Params
{
	class UUserWidget*                                 Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                idx;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// DelegateFunction Client.ReuseListC.OnScrollItemDelegate__DelegateSignature
struct UReuseListC_OnScrollItemDelegate__DelegateSignature_Params
{
	int                                                BeginIdx;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                EndIdx;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// DelegateFunction Client.ReuseListC.OnCreateItemDelegate__DelegateSignature
struct UReuseListC_OnCreateItemDelegate__DelegateSignature_Params
{
	class UUserWidget*                                 Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function Client.ReuseListC.JumpByIdxStyle
struct UReuseListC_JumpByIdxStyle_Params
{
	int                                                __Idx;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	EReuseListJumpStyle                                __Style;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseListC.JumpByIdx
struct UReuseListC_JumpByIdx_Params
{
	int                                                __Idx;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReuseListC.GetViewSize
struct UReuseListC_GetViewSize_Params
{
	struct FVector2D                                   ReturnValue;                                              // (ConstParm, Parm, OutParm, ReturnParm, ReferenceParm, IsPlainOldData)
};

// Function Client.ReuseListC.GetScrollOffset
struct UReuseListC_GetScrollOffset_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReuseListC.GetPaddingY
struct UReuseListC_GetPaddingY_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReuseListC.GetPaddingX
struct UReuseListC_GetPaddingX_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReuseListC.GetItemWidthAndPaddingX
struct UReuseListC_GetItemWidthAndPaddingX_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReuseListC.GetItemWidth
struct UReuseListC_GetItemWidth_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReuseListC.GetItemHeightAndPaddingY
struct UReuseListC_GetItemHeightAndPaddingY_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReuseListC.GetItemHeight
struct UReuseListC_GetItemHeight_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReuseListC.GetContentSize
struct UReuseListC_GetContentSize_Params
{
	struct FVector2D                                   ReturnValue;                                              // (ConstParm, Parm, OutParm, ReturnParm, ReferenceParm, IsPlainOldData)
};

// Function Client.ReuseListC.GetAllWidgetItems
struct UReuseListC_GetAllWidgetItems_Params
{
	TArray<class UUserWidget*>                         ResultItemList;                                           // (Parm, OutParm, ZeroConstructor)
};

// Function Client.ReuseListC.FindItem
struct UReuseListC_FindItem_Params
{
	int                                                idx;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	class UUserWidget*                                 ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData)
};

// Function Client.ReuseListC.Clear
struct UReuseListC_Clear_Params
{
};

// Function Client.ReusePageC.SetAutoPlayRate
struct UReusePageC_SetAutoPlayRate_Params
{
	float                                              Rate;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReusePageC.SelectPage
struct UReusePageC_SelectPage_Params
{
	int                                                __Idx;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReusePageC.Reload
struct UReusePageC_Reload_Params
{
	int                                                __Count;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReusePageC.Play
struct UReusePageC_Play_Params
{
	bool                                               bPlay;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// DelegateFunction Client.ReusePageC.OnUpdateItemDelegate__DelegateSignature
struct UReusePageC_OnUpdateItemDelegate__DelegateSignature_Params
{
	class UUserWidget*                                 Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                idx;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// DelegateFunction Client.ReusePageC.OnPageChangedDelegate__DelegateSignature
struct UReusePageC_OnPageChangedDelegate__DelegateSignature_Params
{
	int                                                PageIdx;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// DelegateFunction Client.ReusePageC.OnEndScrollDelegate__DelegateSignature
struct UReusePageC_OnEndScrollDelegate__DelegateSignature_Params
{
	int                                                PageIdx;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// DelegateFunction Client.ReusePageC.OnEndDragDelegate__DelegateSignature
struct UReusePageC_OnEndDragDelegate__DelegateSignature_Params
{
	int                                                PageIdx;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// DelegateFunction Client.ReusePageC.OnCreateItemDelegate__DelegateSignature
struct UReusePageC_OnCreateItemDelegate__DelegateSignature_Params
{
	class UUserWidget*                                 Widget;                                                   // (Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// DelegateFunction Client.ReusePageC.OnBeginDragDelegate__DelegateSignature
struct UReusePageC_OnBeginDragDelegate__DelegateSignature_Params
{
};

// Function Client.ReusePageC.MovePrePage
struct UReusePageC_MovePrePage_Params
{
};

// Function Client.ReusePageC.MoveNextPage
struct UReusePageC_MoveNextPage_Params
{
};

// Function Client.ReusePageC.IsDraging
struct UReusePageC_IsDraging_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReusePageC.GetPageCount
struct UReusePageC_GetPageCount_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReusePageC.GetPage
struct UReusePageC_GetPage_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReusePageC.GetOffset
struct UReusePageC_GetOffset_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReusePageC.GetAutoPlayRate
struct UReusePageC_GetAutoPlayRate_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.ReusePageC.GetAllItems
struct UReusePageC_GetAllItems_Params
{
	TArray<class UUserWidget*>                         ResultItemList;                                           // (Parm, OutParm, ZeroConstructor)
	bool                                               OnlyVisible;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.ReusePageC.ClearCache
struct UReusePageC_ClearCache_Params
{
};

// Function Client.UDPPingCollector.TickUDPPing
struct UUDPPingCollector_TickUDPPing_Params
{
	float                                              DeltaTime;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.UDPPingCollector.setUDPPingServerAddress
struct UUDPPingCollector_setUDPPingServerAddress_Params
{
	struct FString                                     ServerIP;                                                 // (Parm, ZeroConstructor)
	struct FString                                     ServerPort;                                               // (Parm, ZeroConstructor)
	int                                                ZoneID;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                WaterMarkType;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.UDPPingCollector.SetPingSystemControlFlag
struct UUDPPingCollector_SetPingSystemControlFlag_Params
{
	int                                                TakeEffectModule;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ThreadReportTlog;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                EpollReportTlog;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.UDPPingCollector.PingServer
struct UUDPPingCollector_PingServer_Params
{
	struct FString                                     address;                                                  // (Parm, ZeroConstructor)
	float                                              Timeout;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                WaterMarkType;                                            // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.UDPPingCollector.OnPreSwitchGameStatus
struct UUDPPingCollector_OnPreSwitchGameStatus_Params
{
	struct FString                                     MapName;                                                  // (Parm, ZeroConstructor)
};

// DelegateFunction Client.UDPPingCollector.OnPingServerResultDelegate__DelegateSignature
struct UUDPPingCollector_OnPingServerResultDelegate__DelegateSignature_Params
{
	struct FString                                     address;                                                  // (Parm, ZeroConstructor)
	int                                                IsSuccess;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              Time;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                PingSystemType;                                           // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.UDPPingCollector.IsChooingZoneAccess
struct UUDPPingCollector_IsChooingZoneAccess_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.UDPPingCollector.isAllZoneHasPingValue
struct UUDPPingCollector_isAllZoneHasPingValue_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.UDPPingCollector.Init
struct UUDPPingCollector_Init_Params
{
	float                                              MinPingintervalTime;                                      // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              pingintervalTime;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              pingTimeoutSecond;                                        // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              normalDelayMilliSecond;                                   // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              maxAutoChooseZoneDelayMilliSecond;                        // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.UDPPingCollector.GetZoneServerDelay
struct UUDPPingCollector_GetZoneServerDelay_Params
{
	struct FString                                     ServerAddress;                                            // (Parm, ZeroConstructor)
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.UDPPingCollector.GetMinDealyAddress
struct UUDPPingCollector_GetMinDealyAddress_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.UDPPingCollector.ChoosingZone
struct UUDPPingCollector_ChoosingZone_Params
{
	int                                                ZoneID;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     AddrIP;                                                   // (Parm, ZeroConstructor)
};

// Function Client.VibrateSystemManager.StopVibrate
struct UVibrateSystemManager_StopVibrate_Params
{
};

// Function Client.VibrateSystemManager.SetVibrationLoopTime
struct UVibrateSystemManager_SetVibrationLoopTime_Params
{
	struct FString                                     InLoopTime;                                               // (Parm, ZeroConstructor)
};

// Function Client.VibrateSystemManager.PostVibrateTriggerActionDirectly
struct UVibrateSystemManager_PostVibrateTriggerActionDirectly_Params
{
	int                                                SpesifyID;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Amplitude;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.PostVibrateTriggerAction
struct UVibrateSystemManager_PostVibrateTriggerAction_Params
{
	struct FVibrateTriggerAction                       Action;                                                   // (ConstParm, Parm, OutParm, ReferenceParm)
	bool                                               bCheckGate;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bCheckInterval;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                SpesifyID;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.PlayVibrateEntity
struct UVibrateSystemManager_PlayVibrateEntity_Params
{
	struct FVibrateEntity                              Entity;                                                   // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.VibrateSystemManager.ModifyWeaponVibrationSwitch
struct UVibrateSystemManager_ModifyWeaponVibrationSwitch_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyWeaponVibrationLevel
struct UVibrateSystemManager_ModifyWeaponVibrationLevel_Params
{
	int                                                InVal;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyVehicleVibrationSwitch
struct UVibrateSystemManager_ModifyVehicleVibrationSwitch_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyVehicleVibrationLevel
struct UVibrateSystemManager_ModifyVehicleVibrationLevel_Params
{
	int                                                InVal;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyVehicleSoundUIVibrateSetting
struct UVibrateSystemManager_ModifyVehicleSoundUIVibrateSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyVehicleEngineVibrationSetting
struct UVibrateSystemManager_ModifyVehicleEngineVibrationSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyVehicleCrashVibrateSetting
struct UVibrateSystemManager_ModifyVehicleCrashVibrateSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyVehicleBeHitVibrateSetting
struct UVibrateSystemManager_ModifyVehicleBeHitVibrateSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifySoundUIVibrationSwitch
struct UVibrateSystemManager_ModifySoundUIVibrationSwitch_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifySoundUIVibrationLevel
struct UVibrateSystemManager_ModifySoundUIVibrationLevel_Params
{
	int                                                InVal;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifySemiAutoWeaponVibrateSetting
struct UVibrateSystemManager_ModifySemiAutoWeaponVibrateSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyOtherWeaponVibrateSetting
struct UVibrateSystemManager_ModifyOtherWeaponVibrateSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyGlassBrokenSoundUIVibrateSetting
struct UVibrateSystemManager_ModifyGlassBrokenSoundUIVibrateSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyFootstepSoundUIVibrateSetting
struct UVibrateSystemManager_ModifyFootstepSoundUIVibrateSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyFireShotSoundUIVibrateSetting
struct UVibrateSystemManager_ModifyFireShotSoundUIVibrateSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyEntireVibrationSwitch
struct UVibrateSystemManager_ModifyEntireVibrationSwitch_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyEntireVibrationLevel
struct UVibrateSystemManager_ModifyEntireVibrationLevel_Params
{
	int                                                InValue;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyCharacterVibrationSwitch
struct UVibrateSystemManager_ModifyCharacterVibrationSwitch_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyCharacterVibrationLevel
struct UVibrateSystemManager_ModifyCharacterVibrationLevel_Params
{
	int                                                InVal;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyCharacterSwimVibrateSetting
struct UVibrateSystemManager_ModifyCharacterSwimVibrateSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyCharacterFallVibrateSetting
struct UVibrateSystemManager_ModifyCharacterFallVibrateSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyCharacterClimbVibrateSetting
struct UVibrateSystemManager_ModifyCharacterClimbVibrateSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyCharacterBeHitVibrateSetting
struct UVibrateSystemManager_ModifyCharacterBeHitVibrateSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyBoltWeaponVibrateSetting
struct UVibrateSystemManager_ModifyBoltWeaponVibrateSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ModifyAutoWeaponVibrateSetting
struct UVibrateSystemManager_ModifyAutoWeaponVibrateSetting_Params
{
	bool                                               Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.LoadUserSettingData
struct UVibrateSystemManager_LoadUserSettingData_Params
{
	int                                                inCharacterVibrationLevel;                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                inWeaponVibrationLevel;                                   // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                inVehicleVibrationLevel;                                  // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                inSoundUIVibrationLevel;                                  // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binCharacterBeHitVibrate;                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binCharacterClimbVibrate;                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binCharacterFallVibrate;                                  // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binCharacterSwimVibrate;                                  // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binVehicleEngineVibrate;                                  // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binVehicleBeHitVibrate;                                   // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binVehicleCrashVibrate;                                   // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binFootstepSoundUIVibrate;                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binFireShotSoundUIVibrate;                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binGlassBrokenSoundUIVibrate;                             // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binVehicleSoundUIVibrate;                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                inEntireVibrationLevel;                                   // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binAutoWeaponVibrate;                                     // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binSemiAutoWeaponVibrate;                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binBoltWeaponVibrate;                                     // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               binOtherWeaponVibrate;                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.InvalidateVibrateEntityByEventType
struct UVibrateSystemManager_InvalidateVibrateEntityByEventType_Params
{
	EVibrateTriggerEventType                           EventType;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.InitUserSetting
struct UVibrateSystemManager_InitUserSetting_Params
{
};

// Function Client.VibrateSystemManager.InitSystem
struct UVibrateSystemManager_InitSystem_Params
{
};

// Function Client.VibrateSystemManager.HandleApplicationWillTerminate
struct UVibrateSystemManager_HandleApplicationWillTerminate_Params
{
};

// Function Client.VibrateSystemManager.HandleApplicationWillEnterBackground
struct UVibrateSystemManager_HandleApplicationWillEnterBackground_Params
{
};

// Function Client.VibrateSystemManager.HandleApplicationWillDeactivate
struct UVibrateSystemManager_HandleApplicationWillDeactivate_Params
{
};

// Function Client.VibrateSystemManager.HandleApplicationHasReactivated
struct UVibrateSystemManager_HandleApplicationHasReactivated_Params
{
};

// Function Client.VibrateSystemManager.HandleApplicationHasEnteredForeground
struct UVibrateSystemManager_HandleApplicationHasEnteredForeground_Params
{
};

// Function Client.VibrateSystemManager.GetInstance
struct UVibrateSystemManager_GetInstance_Params
{
	class UObject*                                     WorldContext;                                             // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bAutoCreate;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	class UVibrateSystemManager*                       ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VibrateSystemManager.GetEntireVibrationLevel
struct UVibrateSystemManager_GetEntireVibrationLevel_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VibrateSystemManager.GetCurrentPlayingVibrationDebugInfo
struct UVibrateSystemManager_GetCurrentPlayingVibrationDebugInfo_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.VibrateSystemManager.GetAmplitudeByAlpha
struct UVibrateSystemManager_GetAmplitudeByAlpha_Params
{
	float                                              Alpha;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ClearVibratePath2Json
struct UVibrateSystemManager_ClearVibratePath2Json_Params
{
};

// Function Client.VibrateSystemManager.ClearAllVibration
struct UVibrateSystemManager_ClearAllVibration_Params
{
};

// Function Client.VibrateSystemManager.CheckShootWeaponTypeVibrateGate
struct UVibrateSystemManager_CheckShootWeaponTypeVibrateGate_Params
{
	class ASTExtraWeapon*                              Weapon;                                                   // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VibrateSystemManager.CheckAndCopyFilesToSavedDir
struct UVibrateSystemManager_CheckAndCopyFilesToSavedDir_Params
{
	class UVibrateSystemManager*                       Mgr;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VibrateSystemManager.ActiveInGameVibration
struct UVibrateSystemManager_ActiveInGameVibration_Params
{
	bool                                               Inactive;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.UploadRecordFile
struct UVoiceSDKInterface_UploadRecordFile_Params
{
	bool                                               InPermanent;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.UploadRecordedFile
struct UVoiceSDKInterface_UploadRecordedFile_Params
{
	struct FString                                     InFilePath;                                               // (Parm, ZeroConstructor)
	int                                                InTimeout;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               InPermanent;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.UpdateVoiceCoordinate
struct UVoiceSDKInterface_UpdateVoiceCoordinate_Params
{
	struct FString                                     InRoomName;                                               // (Parm, ZeroConstructor)
	int64_t                                            X;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	int64_t                                            Y;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	int64_t                                            Z;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	int64_t                                            Radius;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.TestMic
struct UVoiceSDKInterface_TestMic_Params
{
};

// Function Client.VoiceSDKInterface.TeamSpeakerEnable
struct UVoiceSDKInterface_TeamSpeakerEnable_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.TeamMicphoneEnable
struct UVoiceSDKInterface_TeamMicphoneEnable_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SwitchMode
struct UVoiceSDKInterface_SwitchMode_Params
{
	ECharacterMainType                                 CharMode;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SwitchMicphoneWhenCorpsMode
struct UVoiceSDKInterface_SwitchMicphoneWhenCorpsMode_Params
{
};

// Function Client.VoiceSDKInterface.StopRecording
struct UVoiceSDKInterface_StopRecording_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.StopRecord
struct UVoiceSDKInterface_StopRecord_Params
{
};

// Function Client.VoiceSDKInterface.StopPlayRecordFile
struct UVoiceSDKInterface_StopPlayRecordFile_Params
{
};

// Function Client.VoiceSDKInterface.StopInterphone
struct UVoiceSDKInterface_StopInterphone_Params
{
};

// Function Client.VoiceSDKInterface.StartRecording
struct UVoiceSDKInterface_StartRecording_Params
{
	struct FString                                     InFilePath;                                               // (Parm, ZeroConstructor)
	bool                                               InNotVoip;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.StartRecord
struct UVoiceSDKInterface_StartRecord_Params
{
};

// Function Client.VoiceSDKInterface.StartInterphone
struct UVoiceSDKInterface_StartInterphone_Params
{
};

// Function Client.VoiceSDKInterface.ShowOpenSpeakerAtFirstMsg
struct UVoiceSDKInterface_ShowOpenSpeakerAtFirstMsg_Params
{
};

// Function Client.VoiceSDKInterface.ShowCorpsModeCannotUseLBSVoice
struct UVoiceSDKInterface_ShowCorpsModeCannotUseLBSVoice_Params
{
};

// Function Client.VoiceSDKInterface.SetVoiceServer
struct UVoiceSDKInterface_SetVoiceServer_Params
{
	struct FString                                     ServerInfo;                                               // (Parm, ZeroConstructor)
};

// Function Client.VoiceSDKInterface.SetVoiceSDKSupportBackgroundChat
struct UVoiceSDKInterface_SetVoiceSDKSupportBackgroundChat_Params
{
	bool                                               isSupportBGChat;                                          // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetVoiceSDKChatServiceEnable
struct UVoiceSDKInterface_SetVoiceSDKChatServiceEnable_Params
{
	bool                                               IsEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetVoiceMode
struct UVoiceSDKInterface_SetVoiceMode_Params
{
	int                                                Type;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetUserInfo
struct UVoiceSDKInterface_SetUserInfo_Params
{
	struct FString                                     InUserInfo;                                               // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetTransSecInfo
struct UVoiceSDKInterface_SetTransSecInfo_Params
{
	struct FString                                     InTransSecInfo;                                           // (Parm, ZeroConstructor)
};

// Function Client.VoiceSDKInterface.SetSpeakerVolum
struct UVoiceSDKInterface_SetSpeakerVolum_Params
{
	float                                              Value;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetSpeakerStatus
struct UVoiceSDKInterface_SetSpeakerStatus_Params
{
	bool                                               Flag;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetServerInfo
struct UVoiceSDKInterface_SetServerInfo_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
	struct FString                                     InDefaultIpSvr;                                           // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetRoomOperationTimeout
struct UVoiceSDKInterface_SetRoomOperationTimeout_Params
{
	int                                                InTimeout;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetResourePath
struct UVoiceSDKInterface_SetResourePath_Params
{
	struct FString                                     InResourcePath;                                           // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetReportBufferTime
struct UVoiceSDKInterface_SetReportBufferTime_Params
{
	int                                                nTimeSec;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetPlayerVolume
struct UVoiceSDKInterface_SetPlayerVolume_Params
{
	struct FString                                     InPlayerId;                                               // (Parm, ZeroConstructor)
	int                                                InVol;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetNotify
struct UVoiceSDKInterface_SetNotify_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetMode
struct UVoiceSDKInterface_SetMode_Params
{
	int                                                InGVMode;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetMicphoneVolum
struct UVoiceSDKInterface_SetMicphoneVolum_Params
{
	float                                              Value;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetMicphoneStatus
struct UVoiceSDKInterface_SetMicphoneStatus_Params
{
	bool                                               Flag;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetLbsVoiceRadius
struct UVoiceSDKInterface_SetLbsVoiceRadius_Params
{
	float                                              Radius;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetLbsRoomEnableStatus
struct UVoiceSDKInterface_SetLbsRoomEnableStatus_Params
{
	bool                                               Flag;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetKwsModelPath
struct UVoiceSDKInterface_SetKwsModelPath_Params
{
	struct FString                                     KwsPath;                                                  // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetGameFrontendHUD
struct UVoiceSDKInterface_SetGameFrontendHUD_Params
{
	class UGameFrontendHUD*                            InHUD;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetFeature
struct UVoiceSDKInterface_SetFeature_Params
{
	int8_t                                             InFeature;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               Inactive;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetDeliverData
struct UVoiceSDKInterface_SetDeliverData_Params
{
	TArray<unsigned char>                              pbuf;                                                     // (Parm, OutParm, ZeroConstructor)
	int                                                Len;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetCurrentDownloadFieldID
struct UVoiceSDKInterface_SetCurrentDownloadFieldID_Params
{
	struct FString                                     filedId;                                                  // (Parm, ZeroConstructor)
};

// Function Client.VoiceSDKInterface.SetAppInfo
struct UVoiceSDKInterface_SetAppInfo_Params
{
	struct FString                                     InAppId;                                                  // (Parm, ZeroConstructor)
	struct FString                                     InAppKey;                                                 // (Parm, ZeroConstructor)
	struct FString                                     InOpenid;                                                 // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.SetAllVoiceStatus
struct UVoiceSDKInterface_SetAllVoiceStatus_Params
{
	bool                                               Flag;                                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.RSTSStopRecording
struct UVoiceSDKInterface_RSTSStopRecording_Params
{
};

// Function Client.VoiceSDKInterface.RSTSSpeechToText
struct UVoiceSDKInterface_RSTSSpeechToText_Params
{
	int                                                InSrcLang;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.ResetWhenLogOut
struct UVoiceSDKInterface_ResetWhenLogOut_Params
{
};

// Function Client.VoiceSDKInterface.ReportPlayers
struct UVoiceSDKInterface_ReportPlayers_Params
{
	struct FString                                     InExtraInfo;                                              // (Parm, ZeroConstructor)
	TArray<struct FString>                             InOpenids;                                                // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.ReportFileForAbroad
struct UVoiceSDKInterface_ReportFileForAbroad_Params
{
	struct FString                                     InFilePath;                                               // (Parm, ZeroConstructor)
	bool                                               InTranslate;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               InChangeVoice;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                InTime;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.RecoverPlayersVolume
struct UVoiceSDKInterface_RecoverPlayersVolume_Params
{
	int                                                InVol;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.ReactiveLbsStatus
struct UVoiceSDKInterface_ReactiveLbsStatus_Params
{
};

// Function Client.VoiceSDKInterface.QuitVoiceRoom
struct UVoiceSDKInterface_QuitVoiceRoom_Params
{
	struct FString                                     InRoomName;                                               // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.QuitRoom
struct UVoiceSDKInterface_QuitRoom_Params
{
};

// Function Client.VoiceSDKInterface.QuitLbsRoom
struct UVoiceSDKInterface_QuitLbsRoom_Params
{
	bool                                               needReenterLbs;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.QuitCommonRoom
struct UVoiceSDKInterface_QuitCommonRoom_Params
{
	struct FString                                     InRoomName;                                               // (Parm, ZeroConstructor)
};

// Function Client.VoiceSDKInterface.Poll
struct UVoiceSDKInterface_Poll_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.PlayRecordFile
struct UVoiceSDKInterface_PlayRecordFile_Params
{
};

// Function Client.VoiceSDKInterface.PlayRecordedFile
struct UVoiceSDKInterface_PlayRecordedFile_Params
{
	struct FString                                     InDownloadInFilePath;                                     // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.OpenVoiceSpeaker
struct UVoiceSDKInterface_OpenVoiceSpeaker_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.OpenVoiceMic
struct UVoiceSDKInterface_OpenVoiceMic_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.OpenTeamSpeakerOnly
struct UVoiceSDKInterface_OpenTeamSpeakerOnly_Params
{
	bool                                               ShowTips;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.OpenTeamMicphoneOnly
struct UVoiceSDKInterface_OpenTeamMicphoneOnly_Params
{
	bool                                               ShowTips;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.OpenTeamInterphone
struct UVoiceSDKInterface_OpenTeamInterphone_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.OpenSpeaker
struct UVoiceSDKInterface_OpenSpeaker_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.OpenMicAndSpeakerAfterJoinLbsRoom
struct UVoiceSDKInterface_OpenMicAndSpeakerAfterJoinLbsRoom_Params
{
};

// Function Client.VoiceSDKInterface.OpenMic
struct UVoiceSDKInterface_OpenMic_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.OpenIngameSpeaker
struct UVoiceSDKInterface_OpenIngameSpeaker_Params
{
};

// Function Client.VoiceSDKInterface.OpenIngameMicphone
struct UVoiceSDKInterface_OpenIngameMicphone_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.OpenAllSpeaker
struct UVoiceSDKInterface_OpenAllSpeaker_Params
{
	bool                                               ShowTips;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.OpenAllMicphone
struct UVoiceSDKInterface_OpenAllMicphone_Params
{
	bool                                               ShowTips;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.OpenAllInterphone
struct UVoiceSDKInterface_OpenAllInterphone_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.OnRoomTypeChanged
struct UVoiceSDKInterface_OnRoomTypeChanged_Params
{
	struct FString                                     itemtext;                                                 // (Parm, ZeroConstructor)
};

// Function Client.VoiceSDKInterface.OnResume
struct UVoiceSDKInterface_OnResume_Params
{
};

// Function Client.VoiceSDKInterface.OnPause
struct UVoiceSDKInterface_OnPause_Params
{
};

// Function Client.VoiceSDKInterface.OnDeliverData
struct UVoiceSDKInterface_OnDeliverData_Params
{
	TArray<unsigned char>                              pbuf;                                                     // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	int                                                Len;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     OpenID;                                                   // (Parm, ZeroConstructor)
};

// Function Client.VoiceSDKInterface.LbsSpeakerEnable
struct UVoiceSDKInterface_LbsSpeakerEnable_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.LbsMicphoneEnable
struct UVoiceSDKInterface_LbsMicphoneEnable_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.JoinTeamRoom
struct UVoiceSDKInterface_JoinTeamRoom_Params
{
	struct FString                                     InRoomName;                                               // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.JoinRoom
struct UVoiceSDKInterface_JoinRoom_Params
{
	struct FString                                     room;                                                     // (Parm, ZeroConstructor)
	struct FString                                     userID;                                                   // (Parm, ZeroConstructor)
};

// Function Client.VoiceSDKInterface.JoinRangeRoom
struct UVoiceSDKInterface_JoinRangeRoom_Params
{
	struct FString                                     InRoomName;                                               // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.JoinLbsRoom
struct UVoiceSDKInterface_JoinLbsRoom_Params
{
	struct FString                                     lbsRoom;                                                  // (Parm, ZeroConstructor)
	struct FString                                     userID;                                                   // (Parm, ZeroConstructor)
};

// Function Client.VoiceSDKInterface.JoinCommonRoom
struct UVoiceSDKInterface_JoinCommonRoom_Params
{
	struct FString                                     InRoomName;                                               // (Parm, ZeroConstructor)
};

// Function Client.VoiceSDKInterface.IsVoiceSDKEnable
struct UVoiceSDKInterface_IsVoiceSDKEnable_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.IsTeamInterphoneOpenned
struct UVoiceSDKInterface_IsTeamInterphoneOpenned_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.IsSpeaking
struct UVoiceSDKInterface_IsSpeaking_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.IsLbsInterphoneOpenned
struct UVoiceSDKInterface_IsLbsInterphoneOpenned_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.IsInterphoneMode
struct UVoiceSDKInterface_IsInterphoneMode_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.IsEnableCivilFile
struct UVoiceSDKInterface_IsEnableCivilFile_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.Invoke
struct UVoiceSDKInterface_Invoke_Params
{
	uint32_t                                           InCmd;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           InParam1;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	uint32_t                                           InParam2;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InExterInfo;                                              // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.InstallSystemAudioEventListener
struct UVoiceSDKInterface_InstallSystemAudioEventListener_Params
{
	bool                                               InEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.InitVoiceSDKComponent
struct UVoiceSDKInterface_InitVoiceSDKComponent_Params
{
	struct FString                                     userID;                                                   // (Parm, ZeroConstructor)
};

// Function Client.VoiceSDKInterface.InitVoiceSDK
struct UVoiceSDKInterface_InitVoiceSDK_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.Init
struct UVoiceSDKInterface_Init_Params
{
};

// Function Client.VoiceSDKInterface.HaveTeamRoom
struct UVoiceSDKInterface_HaveTeamRoom_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.HaveLbsRoom
struct UVoiceSDKInterface_HaveLbsRoom_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.GetVoiceLength
struct UVoiceSDKInterface_GetVoiceLength_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.GetTeamRoomName
struct UVoiceSDKInterface_GetTeamRoomName_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.VoiceSDKInterface.GetRoomStatus
struct UVoiceSDKInterface_GetRoomStatus_Params
{
	struct FString                                     InRoomName;                                               // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.GetRoomMemberVoiceData
struct UVoiceSDKInterface_GetRoomMemberVoiceData_Params
{
	struct FString                                     InOpenid;                                                 // (Parm, ZeroConstructor)
	int                                                InIndexType;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                DataType;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               OnlyIncludeLatest;                                        // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.GetPlayerVolume
struct UVoiceSDKInterface_GetPlayerVolume_Params
{
	struct FString                                     InPlayerId;                                               // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.GetMicState
struct UVoiceSDKInterface_GetMicState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.GetLocalRecordFilePath
struct UVoiceSDKInterface_GetLocalRecordFilePath_Params
{
	struct FString                                     InFileName;                                               // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.VoiceSDKInterface.GetLbsRoomName
struct UVoiceSDKInterface_GetLbsRoomName_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

// Function Client.VoiceSDKInterface.GetAuthKey
struct UVoiceSDKInterface_GetAuthKey_Params
{
};

// Function Client.VoiceSDKInterface.GetAudioDeviceConnectionState
struct UVoiceSDKInterface_GetAudioDeviceConnectionState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.ForbidTeammateVoiceById
struct UVoiceSDKInterface_ForbidTeammateVoiceById_Params
{
	int                                                memberID;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               IsEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.ForbidMemberVoice
struct UVoiceSDKInterface_ForbidMemberVoice_Params
{
	int                                                InMember;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               InEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     InRoomName;                                               // (Parm, ZeroConstructor)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.ForbidLbsMemberVoiceById
struct UVoiceSDKInterface_ForbidLbsMemberVoiceById_Params
{
	int                                                memberID;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               IsEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.EnableVoiceSdk
struct UVoiceSDKInterface_EnableVoiceSdk_Params
{
	class UGameFrontendHUD*                            GameFrontendHUD;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               Enable;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.EnableVoiceRoomMicrophone
struct UVoiceSDKInterface_EnableVoiceRoomMicrophone_Params
{
	struct FString                                     InRoomName;                                               // (Parm, ZeroConstructor)
	bool                                               InEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.EnableVoiceChat
struct UVoiceSDKInterface_EnableVoiceChat_Params
{
	bool                                               InEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.EnableRSTSSubtitle
struct UVoiceSDKInterface_EnableRSTSSubtitle_Params
{
	bool                                               InEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                InSrcLang;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.EnableRoomSpeaker
struct UVoiceSDKInterface_EnableRoomSpeaker_Params
{
	struct FString                                     InRoomName;                                               // (Parm, ZeroConstructor)
	bool                                               InEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.EnableReportForAbroad
struct UVoiceSDKInterface_EnableReportForAbroad_Params
{
	bool                                               InIsWholeRoundaudit;                                      // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.EnableReportALLAbroad
struct UVoiceSDKInterface_EnableReportALLAbroad_Params
{
	bool                                               InEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               InWithEncryption;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                InTimeout;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.EnableMultiRoom
struct UVoiceSDKInterface_EnableMultiRoom_Params
{
	bool                                               InEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.EnableLog
struct UVoiceSDKInterface_EnableLog_Params
{
	bool                                               InEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.EnableKws
struct UVoiceSDKInterface_EnableKws_Params
{
	bool                                               bEnable;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.EnableCivilFile
struct UVoiceSDKInterface_EnableCivilFile_Params
{
	bool                                               Enable;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.EnableBluetoothSCO
struct UVoiceSDKInterface_EnableBluetoothSCO_Params
{
	bool                                               InEnable;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.DownloadRecordFile
struct UVoiceSDKInterface_DownloadRecordFile_Params
{
	bool                                               InPermanent;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.DownloadRecordedFile
struct UVoiceSDKInterface_DownloadRecordedFile_Params
{
	struct FString                                     InFileID;                                                 // (Parm, ZeroConstructor)
	struct FString                                     InDownloadInFilePath;                                     // (Parm, ZeroConstructor)
	int                                                InTimeout;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               InPermanent;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.CommonTestMic
struct UVoiceSDKInterface_CommonTestMic_Params
{
};

// Function Client.VoiceSDKInterface.CloseVoiceSpeaker
struct UVoiceSDKInterface_CloseVoiceSpeaker_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.CloseVoiceMic
struct UVoiceSDKInterface_CloseVoiceMic_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.CloseSpeaker
struct UVoiceSDKInterface_CloseSpeaker_Params
{
};

// Function Client.VoiceSDKInterface.CloseMic
struct UVoiceSDKInterface_CloseMic_Params
{
};

// Function Client.VoiceSDKInterface.CloseIngameSpeaker
struct UVoiceSDKInterface_CloseIngameSpeaker_Params
{
};

// Function Client.VoiceSDKInterface.CloseIngameMicphone
struct UVoiceSDKInterface_CloseIngameMicphone_Params
{
};

// Function Client.VoiceSDKInterface.CloseAllSpeaker
struct UVoiceSDKInterface_CloseAllSpeaker_Params
{
	bool                                               ShowTips;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.CloseAllMicphone
struct UVoiceSDKInterface_CloseAllMicphone_Params
{
	bool                                               ShowTips;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.CheckDeviceMuteState
struct UVoiceSDKInterface_CheckDeviceMuteState_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.CheckAndEnableRoomSpeaker
struct UVoiceSDKInterface_CheckAndEnableRoomSpeaker_Params
{
};

// Function Client.VoiceSDKInterface.ChatShowAgeRestrictionMsgInLobby
struct UVoiceSDKInterface_ChatShowAgeRestrictionMsgInLobby_Params
{
};

// Function Client.VoiceSDKInterface.ChatShowAgeRestrictionMsgInFighting
struct UVoiceSDKInterface_ChatShowAgeRestrictionMsgInFighting_Params
{
};

// Function Client.VoiceSDKInterface.ChatShowAgeRestrictionMsgInChat
struct UVoiceSDKInterface_ChatShowAgeRestrictionMsgInChat_Params
{
};

// Function Client.VoiceSDKInterface.ChatRequestPrivacyInSetting
struct UVoiceSDKInterface_ChatRequestPrivacyInSetting_Params
{
};

// Function Client.VoiceSDKInterface.ChatRequestPrivacyInGame
struct UVoiceSDKInterface_ChatRequestPrivacyInGame_Params
{
};

// Function Client.VoiceSDKInterface.ApplyMessageKey
struct UVoiceSDKInterface_ApplyMessageKey_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Client.VoiceSDKInterface.AlwaysDisableRoomMic
struct UVoiceSDKInterface_AlwaysDisableRoomMic_Params
{
	struct FString                                     InRoomName;                                               // (Parm, ZeroConstructor)
	bool                                               WithClear;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.WeaponDIYCaptureActor.ResizeRT
struct AWeaponDIYCaptureActor_ResizeRT_Params
{
	class UTextureRenderTarget2D*                      RenderTarget;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Width;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	int                                                Height;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// DelegateFunction Client.WINSDKFBWebLogin.OnWINSDKHttpResponed__DelegateSignature
struct UWINSDKFBWebLogin_OnWINSDKHttpResponed__DelegateSignature_Params
{
	bool                                               requestSucc;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     txtContent;                                               // (Parm, ZeroConstructor)
};

// DelegateFunction Client.WINSDKFBWebLogin.OnUrlChanged__DelegateSignature
struct UWINSDKFBWebLogin_OnUrlChanged__DelegateSignature_Params
{
	struct FText                                       Text;                                                     // (ConstParm, Parm, OutParm, ReferenceParm)
};

// Function Client.WINSDKFBWebLogin.LoadURL
struct UWINSDKFBWebLogin_LoadURL_Params
{
	struct FString                                     NewURL;                                                   // (Parm, ZeroConstructor)
};

// Function Client.WINSDKFBWebLogin.DoHttpRequest
struct UWINSDKFBWebLogin_DoHttpRequest_Params
{
	struct FString                                     URL;                                                      // (Parm, ZeroConstructor)
};

// Function Client.WINWebSocketServer.Tick
struct UWINWebSocketServer_Tick_Params
{
	int                                                DeltaTime;                                                // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.WINWebSocketServer.Stop
struct UWINWebSocketServer_Stop_Params
{
};

// Function Client.WINWebSocketServer.Start
struct UWINWebSocketServer_Start_Params
{
	int                                                InPort;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
};

// Function Client.WINWebSocketServer.Send
struct UWINWebSocketServer_Send_Params
{
	struct FString                                     InMsg;                                                    // (Parm, ZeroConstructor)
};

// Function Client.WINWebSocketServer.GetInstance
struct UWINWebSocketServer_GetInstance_Params
{
	class UWINWebSocketServer*                         ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

}

