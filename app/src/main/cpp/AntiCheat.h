#pragma once

#include "SDK.hpp"
#include <cstring> // For memset

using namespace SDK;

// ===================================================================================================
// OPTIMIZED ANTI-CHEAT BYPASS SYSTEM
// ===================================================================================================
// This file centralizes all anti-cheat bypass mechanisms into a single, optimized function.
// It follows the user's improved design for better readability, safety, and maintenance.
// ===================================================================================================

void DisableAntiCheatSystems(ASTExtraPlayerCharacter* localPlayer, ASTExtraPlayerController* localPlayerController, ASTExtraShootWeapon* weapon) {
    if (!localPlayer) return;

    // --- Component & Value Bypasses ---

    // Zero out anti-cheat randomization values in the SceneComponent.
    if (localPlayer->RootComponent) {
        memset(&localPlayer->RootComponent->AntiCheatRandValue0, 0, sizeof(float) * 7);
    }

    // Disable movement-related checks.
    auto moveAC = localPlayer->MoveAntiCheatComponent;
    if (moveAC) {
        moveAC->bUseMoveAntiCheatCheck = false;
        moveAC->MinMoveAntiCheatCheckIntervel2 = 0.f;
        moveAC->TolerateDistanceFractor = 0.f;
        moveAC->MaxPacketLossRate = 99999.f;
        moveAC->MinDistanceSqAtStaticColliderCheck = 99999.f;
        moveAC->MaxTotalMoveCheatTimes = 999999;
        moveAC->bIsForceAdjustZWhenExceed = false;
        moveAC->MaxShootPointPassWall = 99999;
        moveAC->MaxGunPosErrorTimes = 99999;
        moveAC->MaxMuzzleHeightTime = 99999;
        moveAC->MaxLocusFailTime = 99999;
        moveAC->MaxBulletVictimClientPassWallTimes = 9999999;
        moveAC->MaxShooterDataNumErrorCnt = 9999999;
        moveAC->MaxJumpHeight = 9999999.f;
    }

    // Disable weapon-related checks.
    if (weapon && weapon->AntiCheatComp) {
        auto ac = weapon->AntiCheatComp;
        ac->ShootRateCheckInterval = 0;
        ac->ShootRateCheckTag = false;
        ac->ShootRateCheckMulCoff = 0;
        ac->ShootHitTargetIntervalMulCoff = 0;
        ac->ShootTimeInfoCheckClearInterval = 0;
        ac->ShootTimeInfoCheckLifeTime = 0;
        ac->ShootTimeGunPosBigCircle = 0;
        ac->ShootTimeGunPosMaxRightDif = 0;
        ac->ShootTimeGunPosMaxRightDifInVehicle = 0;
        ac->MaxClientCapsuleHalfHeight = 9999999;
        ac->ShootTimeMuzzleDistThres = 0;
        ac->ShootTimeMuzzleZThres = 0;
        ac->bVerifyTimeLineSync = false;
        ac->TimeLineCheckDnBorder = 0;
        ac->TimeLineCheckUpBorder = 0;
        ac->ShootTimeConnectionDeltaThres = 0;
        ac->bVerifyStartFireTime = false;
        ac->MaxShootPassTimeDeltaBetweenSysAndLevel = 0;
        ac->TolerateFlyTime = 0;
        ac->TolerateFlyDis = 0;
    }

    // Disable character movement checks.
    if (localPlayer->STCharacterMovement) {
        localPlayer->STCharacterMovement->bCheatFlying = false;
        localPlayer->STCharacterMovement->CheatCheckSumFailed = false;
        localPlayer->STCharacterMovement->bCheatClientLocation = false;
        localPlayer->STCharacterMovement->bUseTimeSpeedAntiCheatCheck = false;
    }

    // --- Controller & Manager Bypasses ---
    if (localPlayerController) {
        localPlayerController->AntiCheatManagerComp = nullptr;
        localPlayerController->bShouldReportAntiCheat = false;
        localPlayerController->CheatManager = nullptr;
    }

    // --- Reporting & Flag Bypasses ---
    localPlayer->IsEnableReportMrpcsFlow = false;
    localPlayer->IsEnableReportGameSetting = false;
    localPlayer->IsEnableReportPlayerKillFlow = false;
    localPlayer->IsEnableReportPlayerBehavior = false;
    localPlayer->IsEnableReportMrpcsInCircleFlow = false;
    localPlayer->IsEnableReportMrpcsInPartCircleFlow = false;
    localPlayer->LagCompensationComponent = nullptr;
    localPlayer->MoveAntiCheatComponent = nullptr; // Final clear as suggested
} 