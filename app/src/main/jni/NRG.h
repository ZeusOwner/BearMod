#ifndef NRG_H
#define NRG_H

#include "Helper/StrEnc.h"
#include "Helper/struct.h"
#include "Helper/Includes.h"

#include "Helper/obfuscate.h"
#include <curl/curl.h>
#include "Tools.h"
#include "Helper/json.hpp"
#include "base64/base64.h"
#include "md5.h"
#include "enc.h"

#include "Engine/Vector2.hpp"
#include "Engine/Vector3.hpp"
#include "Engine/Rect.h"
#include "KittyMemory/MemoryPatch.h"

#include "TEAMNRG/Utils.h"
//#include "TEAMNRG/Macros.h"
#include "ESP.h"
#include "timer.h"
#include "all_items_data.h"

// ===== MODULAR SKIN SYSTEM =====
#include "JOIN_SKIN.h"  // Basic skin data structures and application logic
#include "ESP_SKIN.h"   // Advanced skin features and anti-detection systems

ESP espOverlay;
using json = nlohmann::json;
json items_data;
//using json = nlohmann::ordered_json;

using namespace std;
//#include "Quaternion.hpp"

#include "SDK.hpp"

using namespace SDK;

extern void StartRuntimeHook(const char *);

#include "UE4.h"

#define PI 3.14159265358979323846f
#define SLEEP_TIME 1000LL / 60LL
#define W2S(w, s) UGameplayStatics::ProjectWorldToScreen(localController, w, true, s)


bool BYPASSLOGO;
bool BYPASSISLAND;
int g_screenWidth = 0, g_screenHeight = 0, g_screenDensity = 0;
float density = -1;
//static bool switchState;
std::string g_Token, g_Auth;
std::map<std::string, u_long> Config;
char extra[30];

bool bValid = true;
bool bScanPatternCompleted = false;
bool SOON_OPEN = false;
bool BypassLogo = true;
std::string expiredDate;
std::string DisplayNotice;

uintptr_t UE4 = 0, anogs, gcloud;
time_t rng = 0;
static int a = 0;
static std::string EXP = " ";
std::map<int, bool> itemConfig;
json itemData;


struct sRegion {
    uintptr_t start, end;
};

std::vector<sRegion> trapRegions;

int SizeXx = 0;
int SizeYy = 0;
int MainSuit = 0;

//#define GEngine_Offset 0xde49de8
#define GNames_Offset 0x78cfc08
#define GUObject_Offset 0xdb0dfb0
#define GetActorArray_Offset 0x994dc6c
#define Process_Event_Offset 0x646e420
#define Actors_Offset 0xA0

//===========================================================================================================================================================================\\




int pid = -1;
int initPid() {
    pid = getpid();
    return pid;
}

#define BYTE1024 0x00000400
#define BYTE16 0x00000010

long GetModuleBase(const char *moduleName) {
    initPid();
    char path[BYTE1024], line[BYTE1024];
    if (pid == -1)
        sprintf(path, "/proc/self/maps");
    else
        sprintf(path, "/proc/%d/maps", pid);
    FILE *file = fopen(path, "r");
    long len = 0;
    if (file) {
        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, moduleName) != NULL) {
                len = strtoul(line, NULL, BYTE16);
                break;
            }
        }
    }
    return len;
}


ASTExtraPlayerCharacter *g_LocalPlayer;
ASTExtraPlayerController *g_PlayerController;
FCameraCacheEntry CameraCache = FCameraCacheEntry();


android_app *g_App = nullptr;

template<typename T>
void Write(uintptr_t addr, T value) {
    Tools::WriteAddr((void *) addr, &value, sizeof(T));
}

template<typename T = uintptr_t>
T Read(uintptr_t addr) {
    T result{};
    if (Tools::ReadAddr((void *) addr, &result, sizeof(T))) {
        return result;
    }
    return result;
}


TNameEntryArray *GetGNames() {
    return ((TNameEntryArray *(*)()) (UE4 + GNames_Offset))();
}

/*
static UEngine *GEngine = 0;
UWorld *GetWorld() {
    while (!GEngine) {
        GEngine = UObject::FindObject<UEngine>("UAEGameEngine Transient.UAEGameEngine_1"); // Auto
        sleep(1);
    }
    if (GEngine) {
        auto ViewPort = GEngine->GameViewport;

        if (ViewPort) {
   //return {};
            return ViewPort->World;
        }
    }
    return 0;
}

*/


UWorld *GEWorld;
int GWorldNum = 0;
TUObjectArray gobjects;

UWorld *GetWorld() {
    if (GWorldNum == 0) {
        gobjects = UObject::GUObjectArray->ObjObjects;
        for (int i = 0; i < gobjects.Num(); i++)
            if (auto obj = gobjects.GetByIndex(i)) {
                if (obj->IsA(UEngine::StaticClass())) {
                    auto GEngine = (UEngine *) obj;
                    if (GEngine) {
                        auto ViewPort = GEngine->GameViewport;
                        if (ViewPort) {
                            GEWorld = ViewPort->World;
                            GWorldNum = i;
                            return ViewPort->World;
                        }
                    }
                }
            }
    } else {
        auto GEngine = (UEngine *) (gobjects.GetByIndex(GWorldNum));
        if (GEngine) {
            auto ViewPort = GEngine->GameViewport;
            if (ViewPort) {
                GEWorld = ViewPort->World;
                return ViewPort->World;
            }
        }
    }
    return 0;
}


/*

UWorld *GetWorld() {
    auto GEngine = *(ULocalPlayer **) (UE4 + GEngine_Offset);
    if (GEngine) {
        auto ViewPort = GEngine->ViewportClient;
        if (ViewPort) {
            return ViewPort->World;
        }
    }
    return 0;
}*/

std::vector<AActor *> getActors() {
    UGameplayStatics *gGameplayStatics = (UGameplayStatics *) gGameplayStatics->StaticClass();
    AActor *Actor1 = (AActor *) Actor1->StaticClass();
    auto GWorld = GetWorld();
    if (!GWorld)
        return std::vector<AActor *>();

    auto Level = GWorld->PersistentLevel;
    if (!Level)
        return std::vector<AActor *>();

    std::vector<AActor *> actor;
    TArray<AActor *> Actors;
    gGameplayStatics->GetAllActorsOfClass((UObject *) GWorld, Actor1->StaticClass(), &Actors);
    for (int i = 0; i < Actors.Num(); i++) {
        auto Actor = Actors[i];
        actor.push_back((AActor *) Actor);
    }
    return actor;
}

/*
std::vector<AActor *> getActors() {
    auto World = GetWorld();
    if (!World)
        return std::vector<AActor *>();

    auto PersistentLevel = World->PersistentLevel;
    if (!PersistentLevel)
        return std::vector<AActor *>();

    auto Actors = *(TArray<AActor *> *)((uintptr_t) PersistentLevel + 0xA0);

    std::vector<AActor *> actors;
    for (int i = 0; i < Actors.Num(); i++) {
        auto Actor = Actors[i];
        if (Actor) {
            actors.push_back(Actor);
        }
    }
    return actors;
}

*/
bool isObjectInvalid(UObject *obj) {
    if (!Tools::IsPtrValid(obj)) {
        return true;
    }

    if (!Tools::IsPtrValid(obj->ClassPrivate)) {
        return true;
    }

    if (obj->InternalIndex <= 0) {
        return true;
    }

    if (obj->NamePrivate.ComparisonIndex <= 0) {
        return true;
    }

    if ((uintptr_t) (obj) % sizeof(uintptr_t) != 0x0 &&
        (uintptr_t) (obj) % sizeof(uintptr_t) != 0x4) {
        return true;
    }

    if (std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) {
        return ((uintptr_t) obj) >= region.start && ((uintptr_t) obj) <= region.end;
    }) ||
        std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) {
            return ((uintptr_t) obj->ClassPrivate) >= region.start &&
                   ((uintptr_t) obj->ClassPrivate) <= region.end;
        })) {
        return true;
    }

    return false;
}

bool isObjectController(UObject *Object) {
    if (!Tools::IsPtrValid(Object)) {
        return false;
    }
    for (auto super = Object->ClassPrivate; Tools::IsPtrValid(
            super); super = (UClass *) super->SuperStruct) {
        if (super == ASTExtraPlayerController::StaticClass()) {
            return true;
        }
    }
    return false;
}


string getObjectPath(UObject *Object) {
    string s;
    for (auto super = Object->ClassPrivate; super; super = (UClass *) super->SuperStruct) {
        if (!s.empty())
            s += ".";
        s += super->GetName();
    }
    return s;
}

bool isObjectPlayer(UObject *Object) {
    if (!Tools::IsPtrValid(Object)) {
        return false;
    }
    for (auto super = Object->ClassPrivate; Tools::IsPtrValid(
            super); super = (UClass *) super->SuperStruct) {
        if (super == ASTExtraPlayerCharacter::StaticClass()) {
            return true;
        }
    }
    return false;
}

bool isObjectGrenade(UObject *Object) {
    if (!Tools::IsPtrValid(Object)) {
        return false;
    }
    for (auto super = Object->ClassPrivate; Tools::IsPtrValid(
            super); super = (UClass *) super->SuperStruct) {
        if (super == ASTExtraGrenadeBase::StaticClass()) {
            return true;
        }
    }
    return false;
}

bool isObjectVehicle(UObject *Object) {
    if (!Tools::IsPtrValid(Object)) {
        return false;
    }
    for (auto super = Object->ClassPrivate; Tools::IsPtrValid(
            super); super = (UClass *) super->SuperStruct) {
        if (super == ASTExtraVehicleBase::StaticClass()) {
            return true;
        }
    }
    return false;
}

bool isObjectLoot(UObject *Object) {
    if (!Tools::IsPtrValid(Object)) {
        return false;
    }
    for (auto super = Object->ClassPrivate; Tools::IsPtrValid(
            super); super = (UClass *) super->SuperStruct) {
        if (super == APickUpWrapperActor::StaticClass()) {
            return true;
        }
    }
    return false;
}

bool isObjectLootBox(UObject *Object) {
    if (!Tools::IsPtrValid(Object)) {
        return false;
    }
    for (auto super = Object->ClassPrivate; Tools::IsPtrValid(
            super); super = (UClass *) super->SuperStruct) {
        if (super == APickUpListWrapperActor::StaticClass()) {
            return true;
        }
    }
    return false;
}


FVector GetBoneLocation(ASTExtraPlayerCharacter *Actor, const char *BoneName) {
    return Actor->GetBonePos(BoneName, FVector());
}


FMatrix RotatorToMatrix(FRotator rotation) {
    float radPitch = rotation.Pitch * ((float) PI / 180.f);
    float radYaw = rotation.Yaw * ((float) PI / 180.f);
    float radRoll = rotation.Roll * ((float) PI / 180.f);

    float SP = sinf(radPitch);
    float CP = cosf(radPitch);
    float SY = sinf(radYaw);
    float CY = cosf(radYaw);
    float SR = sinf(radRoll);
    float CR = cosf(radRoll);

    FMatrix matrix;

    matrix.M[0][0] = (CP * CY);
    matrix.M[0][1] = (CP * SY);
    matrix.M[0][2] = (SP);
    matrix.M[0][3] = 0;

    matrix.M[1][0] = (SR * SP * CY - CR * SY);
    matrix.M[1][1] = (SR * SP * SY + CR * CY);
    matrix.M[1][2] = (-SR * CP);
    matrix.M[1][3] = 0;

    matrix.M[2][0] = (-(CR * SP * CY + SR * SY));
    matrix.M[2][1] = (CY * SR - CR * SP * SY);
    matrix.M[2][2] = (CR * CP);
    matrix.M[2][3] = 0;

    matrix.M[3][0] = 0;
    matrix.M[3][1] = 0;
    matrix.M[3][2] = 0;
    matrix.M[3][3] = 1;

    return matrix;
}


FVector WorldToScreen(FVector world) {
    if (!g_PlayerController->PlayerCameraManager)
        return {0, 0, 0};

    FMinimalViewInfo camViewInfo = g_PlayerController->PlayerCameraManager->CameraCache.POV;

    auto CameraLocation = camViewInfo.Location;
    auto CameraRotation = camViewInfo.Rotation;

    FMatrix tempMatrix = RotatorToMatrix(CameraRotation);

    FVector vAxisX(tempMatrix.M[0][0], tempMatrix.M[0][1], tempMatrix.M[0][2]);
    FVector vAxisY(tempMatrix.M[1][0], tempMatrix.M[1][1], tempMatrix.M[1][2]);
    FVector vAxisZ(tempMatrix.M[2][0], tempMatrix.M[2][1], tempMatrix.M[2][2]);

    FVector vDelta = world - CameraLocation;

    FVector vTransformed(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

    auto FovAngle = camViewInfo.FOV;
    float screenCenterX = g_screenWidth / 2;
    float screenCenterY = g_screenHeight / 2;

    float X = (screenCenterX +
               vTransformed.X * (screenCenterX / tanf(FovAngle * ((float) PI / 360.0f))) /
               vTransformed.Z);
    float Y = (screenCenterY -
               vTransformed.Y * (screenCenterX / tanf(FovAngle * ((float) PI / 360.0f))) /
               vTransformed.Z);
    float Z = vTransformed.Z;

    return {X, Y, Z};
}


FVector2D WorldToScreen33(FVector worldLocation) {
    FMinimalViewInfo camViewInfo = g_PlayerController->PlayerCameraManager->CameraCache.POV;

    FMatrix tempMatrix = RotatorToMatrix(camViewInfo.Rotation);


    FVector vAxisX(tempMatrix.M[0][0], tempMatrix.M[0][1], tempMatrix.M[0][2]);
    FVector vAxisY(tempMatrix.M[1][0], tempMatrix.M[1][1], tempMatrix.M[1][2]);
    FVector vAxisZ(tempMatrix.M[2][0], tempMatrix.M[2][1], tempMatrix.M[2][2]);

    FVector vDelta = worldLocation - camViewInfo.Location;

    FVector vTransformed(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

    if (vTransformed.Z < 1.0f) {
        vTransformed.Z = 1.0f;
    }

    float fov = camViewInfo.FOV;
    float screenCenterX = g_screenWidth / 2;
    float screenCenterY = g_screenHeight / 2;

    return FVector2D(
            (screenCenterX +
             vTransformed.X * (screenCenterX / tanf(fov * ((float) M_PI / 360.0f))) /
             vTransformed.Z),
            (screenCenterY -
             vTransformed.Y * (screenCenterX / tanf(fov * ((float) M_PI / 360.0f))) /
             vTransformed.Z)
    );


}



//screenWidth screenHeight


FVector2D
WorldToScreen360(FVector worldLocation, FMinimalViewInfo camViewInfo, int width, int height) {
    FMatrix tempMatrix = RotatorToMatrix(camViewInfo.Rotation);


    FVector vAxisX(tempMatrix.M[0][0], tempMatrix.M[0][1], tempMatrix.M[0][2]);
    FVector vAxisY(tempMatrix.M[1][0], tempMatrix.M[1][1], tempMatrix.M[1][2]);
    FVector vAxisZ(tempMatrix.M[2][0], tempMatrix.M[2][1], tempMatrix.M[2][2]);

    FVector vDelta = worldLocation - camViewInfo.Location;

    FVector vTransformed(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

    if (vTransformed.Z < 1.0f) {
        vTransformed.Z = 1.0f;
    }

    float fov = camViewInfo.FOV;
    float screenCenterX = g_screenWidth / 2;
    float screenCenterY = g_screenHeight / 2;

    return FVector2D(
            (screenCenterX +
             vTransformed.X * (screenCenterX / tanf(fov * ((float) M_PI / 360.0f))) /
             vTransformed.Z),
            (screenCenterY -
             vTransformed.Y * (screenCenterX / tanf(fov * ((float) M_PI / 360.0f))) /
             vTransformed.Z)
    );


}


FRotator ToRotator(FVector local, FVector target) {
    FVector rotation;
    rotation.X = local.X - target.X;
    rotation.Y = local.Y - target.Y;
    rotation.Z = local.Z - target.Z;

    FRotator newViewAngle = {0};

    float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);

    newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Roll = (float) 0.f;

    if (rotation.X >= 0.f)
        newViewAngle.Yaw += 180.0f;

    return newViewAngle;
}



namespace Stream {
    bool Switch{false};
};

template<class T>
void GetAllActors(std::vector<T *> &Actors) {
    UGameplayStatics *gGameplayStatics = (UGameplayStatics *) gGameplayStatics->StaticClass();
    auto GWorld = GetWorld();
    if (GWorld) {
        TArray<AActor *> Actors2;
        gGameplayStatics->GetAllActorsOfClass((UObject *) GWorld, T::StaticClass(), &Actors2);
        for (int i = 0; i < Actors2.Num(); i++) {
            Actors.push_back((T *) Actors2[i]);
        }
    }
}

void NekoHook(FRotator &angles) {
    if (angles.Pitch > 180)
        angles.Pitch -= 360;
    if (angles.Pitch < -180)
        angles.Pitch += 360;

    if (angles.Pitch < -75.f)
        angles.Pitch = -75.f;
    else if (angles.Pitch > 75.f)
        angles.Pitch = 75.f;

    while (angles.Yaw < -180.0f)
        angles.Yaw += 360.0f;
    while (angles.Yaw > 180.0f)
        angles.Yaw -= 360.0f;
}

void NekoHook(float *angles) {
    if (angles[0] > 180)
        angles[0] -= 360;
    if (angles[0] < -180)
        angles[0] += 360;

    if (angles[0] < -75.f)
        angles[0] = -75.f;
    else if (angles[0] > 75.f)
        angles[0] = 75.f;

    while (angles[1] < -180.0f)
        angles[1] += 360.0f;
    while (angles[1] > 180.0f)
        angles[1] -= 360.0f;
}


void NekoHook(Vector3 angles) {
    if (angles.X > 180)
        angles.X -= 360;
    if (angles.X < -180)
        angles.X += 360;

    if (angles.X < -75.f)
        angles.X = -75.f;
    else if (angles.X > 75.f)
        angles.X = 75.f;

    while (angles.Y < -180.0f)
        angles.Y += 360.0f;
    while (angles.Y > 180.0f)
        angles.Y -= 360.0f;
}

FVector GetBoneLocationByName(ASTExtraPlayerCharacter *Actor, const char *BoneName) {
    return Actor->GetBonePos(BoneName, FVector());
}

struct Threat_t {
    ASTExtraPlayerCharacter *m_Player;
    bool bAiming;
    bool bBehind;
    float mFOV;
    float mDIS;
};

std::vector<Threat_t> GetThreats() {
    std::vector<Threat_t> result;
    auto Actors = getActors();
    auto localPlayer = g_LocalPlayer;
    auto localController = g_PlayerController;
    if (localPlayer) {
        for (auto Actor: Actors) {
            if (isObjectInvalid(Actor))
                continue;
            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                auto Player = (ASTExtraPlayerCharacter *) Actor;
                if (Player->PlayerKey == localPlayer->PlayerKey)
                    continue;
                if (Player->TeamID == localPlayer->TeamID)
                    continue;
                if (Player->bDead)
                    continue;
                auto RootComponent = Player->RootComponent;
                if (RootComponent) {
                    FRotator RelativeRotation = RootComponent->RelativeRotation;
                    ClampAngles(RelativeRotation);
                    FVector myHeadPosition = localPlayer->GetBonePos("Head", {});
                    FVector headLocation = Player->GetBonePos("Head", {});
                    auto Angle = UKismetMathLibrary::Conv_VectorToRotator(
                            UKismetMathLibrary::Subtract_VectorVector(headLocation,
                                                                      myHeadPosition));
                    ClampAngles(Angle);
                    float num = abs(RelativeRotation.Pitch - Angle.Pitch);
                    float num2 = abs(RelativeRotation.Yaw - Angle.Yaw);
                    bool num3 = (num + num2) >= 60.f && (num + num2) <= 80.f;
                    if (num + num2 >= 65.f) {
                        //	if (localController->LineOfSightTo(Player, {0, 0, 0}, true)) {
                        float dist = localPlayer->GetDistanceTo(Player);
                        FVector2D HeadPosSC;
                        result.push_back({Player, num3, NULL, num + num2, dist});
                    }
                    //}
                }
            }
        }
    }
    std::sort(result.begin(), result.end(),
              [](const Threat_t &a, const Threat_t &b) -> bool {
                  return a.mDIS < b.mDIS;
              });
    return result;
}

// ================================================================================================================================ //
class FPSCounter {
protected:
    unsigned int m_fps;
    unsigned int m_fpscount;
    long m_fpsinterval;
public:
    FPSCounter() : m_fps(0), m_fpscount(0), m_fpsinterval(0) {
    }

    void update() {
        m_fpscount++;
        if (m_fpsinterval < time(0)) {
            m_fps = m_fpscount;
            m_fpscount = 0;
            m_fpsinterval = time(0) + 1;
        }
    }

    unsigned int get() const {
        return m_fps;
    }
};

[[maybe_unused]] FPSCounter fps;

bool isInsideFOV(int x, int y) {
    if (!Config["NRG_AIMBOT"])
        return true;
    int circle_x = g_screenWidth / 2;
    int circle_y = g_screenHeight / 2;
    int rad = Config["AIM_SIZE"];
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}


bool isInsideFOV2(int x, int y) {
    if (!Config["NRG_AIMBOT"])
        return true;
    int circle_x = SizeXx / 2;
    int circle_y = SizeYy / 2;
    int rad = Config["AIM_SIZE"];
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}

auto GetTargetForAimBot() {
    ASTExtraPlayerCharacter *result = 0;
    float max = std::numeric_limits<float>::infinity();
    auto GWorld = GetWorld();
    if (GWorld) {
        ULevel *PersistentLevel = GWorld->PersistentLevel;
        if (PersistentLevel) {
            TArray<AActor *> Actors = *(TArray<AActor *> *) ((uintptr_t) PersistentLevel + 0xA0);
            auto localPlayer = g_LocalPlayer;
            auto localController = g_PlayerController;
            if (localPlayer) {
                for (int i = 0; i < Actors.Num(); i++) {
                    auto Actor = Actors[i];
                    if (isObjectInvalid(Actor))
                        continue;

                    if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                        auto Player = (ASTExtraPlayerCharacter *) Actor;

                        if (Player->PlayerKey == localPlayer->PlayerKey)
                            continue;

                        if (Player->TeamID == localPlayer->TeamID)
                            continue;


                        float Distance = localPlayer->GetDistanceTo(Player) / 100.0f;
                        if (Distance > Config["AIM_DISTANCE"])
                            continue;

                        if (Player->bDead)
                            continue;


                        if (Player->bHidden)
                            continue;
                        if (!Config["AIM_KNOCKED"]) {
                            if (Player->Health == 0.0f)
                                continue;
                        }
                        if (Config["AIM_VISCHECK"]) {
                            //  if (!localController->LineOfSightTo(Actor, {0, 0, 0}, true)) {
                            if (!localController->LineOfSightTo(
                                    localController->PlayerCameraManager,
                                    Player->GetBonePos("Head", {}), true)) {
                                continue;
                            }
                            // }
                        }
                        if (Config["AIM_IGNOREBOTS"]) {
                            if (Player->bEnsure)
                                continue;
                        }


                        //    auto Root = Player->GetBonePos("Root", {});
                        auto Head = Player->GetBonePos("Head", {});

                        FVector2D /*RootSc,*/ HeadSc;
                        if (/*W2S(Root, &RootSc) && */W2S(Head, &HeadSc)) {
                            //  float height = abs(HeadSc.Y - RootSc.Y);
                            //  float width = height * 0.65f;

                            //  FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
                            if ((HeadSc.X >= 0 && HeadSc.X <= SizeXx) &&
                                (HeadSc.Y >= 0 && HeadSc.Y <= SizeYy)) {
                                FVector2D v2Middle = FVector2D((float) (SizeXx / 2),
                                                               (float) (SizeYy / 2));
                                FVector2D v2Loc = FVector2D(HeadSc.X, HeadSc.Y);
                                if (isInsideFOV2((int) HeadSc.X, (int) HeadSc.Y)) {
                                    float dist = FVector2D::Distance(v2Middle, v2Loc);
                                    if (dist < max) {
                                        max = dist;
                                        result = Player;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return result;
        }
    }
}




ASTExtraPlayerCharacter *GetTargetByCrosshairDistance() {
    ASTExtraPlayerCharacter *result = 0;
    float max = std::numeric_limits<float>::infinity();
    auto localPlayer = g_LocalPlayer;
    auto localController = g_PlayerController;
    auto Actors = getActors();

    if (localPlayer && localController) {
        for (int i = 0; i < Actors.size(); i++) {
            if (Actors[i] && isObjectPlayer(Actors[i])) {
                auto Actor = (ASTExtraPlayerCharacter *) Actors[i];
                if (Actor->PlayerKey == localPlayer->PlayerKey)
                    continue;
                if (Actor->TeamID == localPlayer->TeamID)
                    continue;
                if (Actor->bDead)
                    continue;
                if (Actor->bHidden)
                    continue;
                float Distance = localPlayer->GetDistanceTo(Actor) / 100.0f;
                if (Distance > Config["AIM_DISTANCE"])
                    continue;

                for (int i = 0; i < Actors.size(); i++) {
                    if (!isObjectInvalid(Actors[i]) && isObjectPlayer(Actors[i])) {
                        auto actor = (ASTExtraPlayerCharacter *) Actors[i];
                        if (actor->PlayerKey == localController->PlayerKey) {
                            localPlayer = actor;
                            break;
                        }
                    }
                }
                if (Config["AIM_VISCHECK"]) {
                    if (!localController->LineOfSightTo(Actor, {0, 0, 0}, true)) {
                        if (!localController->LineOfSightTo(localController->PlayerCameraManager,
                                                            Actor->GetBonePos("Head", {}), true)) {
                            continue;
                        }
                    }
                }
                if (!Config["AIM_KNOCKED"]) {
                    if (Actor->Health == 0.0f)
                        continue;
                }
                if (Config["AIM_IGNOREBOTS"]) {
                    if (Actor->bEnsure)
                        continue;
                }
                auto Root = GetBoneLocation(Actor, "pelvis");
                auto Head = GetBoneLocation(Actor, "Head");
                auto PlayerCameraManager = localController->PlayerCameraManager;
                CameraCache = PlayerCameraManager->CameraCache;


                FVector RootSc = WorldToScreen(Root);
                FVector HeadSc = WorldToScreen(Head);
                if (RootSc.Z > 0 && HeadSc.Z > 0) {

                    //   float height = abs(HeadSc.Y - RootSc.Y);
                    //  float width = height * 0.65f;
                    FVector middlePoint = {HeadSc.X, HeadSc.Y, 0};
                    if ((middlePoint.X >= 0 && middlePoint.X <= g_screenWidth) &&
                        (middlePoint.Y >= 0 && middlePoint.Y <= g_screenHeight)) {
                        FVector2D v2Middle = FVector2D((float) (g_screenWidth / 2),
                                                       (float) (g_screenHeight / 2));
                        FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);
                        if (isInsideFOV((int) middlePoint.X, (int) middlePoint.Y)) {
                            float dist = FVector2D::Distance(v2Middle, v2Loc);
                            if (dist < max) {
                                max = dist;
                                result = Actor;
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

ASTExtraPlayerCharacter *GetTargetByDistance() {
    ASTExtraPlayerCharacter *result = nullptr;
    float max = numeric_limits<float>::infinity();

    auto localPlayer = g_LocalPlayer;
    auto localController = g_PlayerController;

    FVector LocalPos{0, 0, 0}, ViewPos{0, 0, 0};
    if (localPlayer) {
        LocalPos = GetBoneLocationByName(localPlayer, "Root");
        ViewPos = GetBoneLocationByName(localPlayer, "Head");
        ViewPos.Z += 15.f;
    }

    auto GWorld = GetWorld();
    if (GWorld) {
        ULevel *PersistentLevel = GWorld->PersistentLevel;
        if (GWorld->PersistentLevel) {
            TArray<AActor *> Actors = *(TArray<AActor *> *) ((uintptr_t) PersistentLevel + 0xA0);

            if (localPlayer && localController) {
                for (int i = 0; i < Actors.Num(); i++) {
                    if (Actors[i] && isObjectPlayer(Actors[i])) {
                        auto Actor = (ASTExtraPlayerCharacter *) Actors[i];
                        if (Actor->PlayerKey == localPlayer->PlayerKey)
                            continue;

                        if (Actor->TeamID == localPlayer->TeamID)
                            continue;

                        if (Actor->bDead)
                            continue;
                        if (Actor->bHidden)
                            continue;
                        float Distance = localPlayer->GetDistanceTo(Actor) / 100.0f;
                        if (Distance > Config["AIM_DISTANCE"])
                            continue;

                        for (int i = 0; i < Actors.Num(); i++) {
                            if (!isObjectInvalid(Actors[i]) && isObjectPlayer(Actors[i])) {
                                auto actor = (ASTExtraPlayerCharacter *) Actors[i];
                                if (actor->PlayerKey == localController->PlayerKey) {
                                    localPlayer = actor;
                                    break;
                                }
                            }
                        }


                        if (Config["AIM_VISCHECK"]) {
                            if (!localController->LineOfSightTo(Actor, {0, 0, 0}, true)) {
                                if (!localController->LineOfSightTo(
                                        localController->PlayerCameraManager,
                                        Actor->GetBonePos("Head", {}), true)) {
                                    continue;
                                }
                            }
                        }
                        if (!Config["AIM_KNOCKED"]) {
                            if (Actor->Health == 0.0f)
                                continue;
                        }
                        if (Config["AIM_IGNOREBOTS"]) {
                            if (Actor->bEnsure)
                                continue;
                        }

                        float dist = g_LocalPlayer->GetDistanceTo(Actor);
                        if (dist < max) {
                            max = dist;
                            result = Actor;
                        }
                    }
                }
            }
        }
    }
    return result;
}


void
(*orig_shoot_event)(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1,
                    int unk2) = nullptr;

void shoot_event(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot,
                 ASTExtraShootWeapon *weapon, int unk1) {
    if (Config["NRG_AIMBOT"]) {
        if (Config["AIM_MOD2"] || Config["AIM_MOD3"]) {
            ASTExtraPlayerCharacter *Target = GetTargetByCrosshairDistance();

            if (Target) {
                bool triggerOk = false;
                if (Config["AIM::TRIGGER1"]) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring;
                } else if (Config["AIM::TRIGGER2"]) {
                    triggerOk = g_LocalPlayer->bIsGunADS;
                } else if (Config["AIM::TRIGGER3"]) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;

                } else triggerOk = true;
                if (triggerOk) {
                    FVector targetAimPos = GetBoneLocation(Target,
                                                           "Head");//Target->GetBonePos("Head", {});


                    UShootWeaponEntity *ShootWeaponEntityComponent = thiz->ShootWeaponEntityComponent;


                    if (ShootWeaponEntityComponent) {
                        ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                        if (CurrentVehicle) {
                            FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;

                            float dist = g_LocalPlayer->GetDistanceTo(Target);
                            auto timeToTravel = dist / ShootWeaponEntityComponent->BulletFireSpeed;

                            targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos,
                                                                                UKismetMathLibrary::Multiply_VectorFloat(
                                                                                        LinearVelocity,
                                                                                        timeToTravel));
                        } else {
                            FVector Velocity = Target->GetVelocity();

                            float dist = g_LocalPlayer->GetDistanceTo(Target);
                            auto timeToTravel = dist / ShootWeaponEntityComponent->BulletFireSpeed;

                            targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos,
                                                                                UKismetMathLibrary::Multiply_VectorFloat(
                                                                                        Velocity,
                                                                                        timeToTravel));
                        }
                        if (Config["AIM_MOD2"]) {
                            FVector fDir = UKismetMathLibrary::Subtract_VectorVector(targetAimPos,
                                                                                     g_PlayerController->PlayerCameraManager->CameraCache.POV.Location);
                            rot = UKismetMathLibrary::Conv_VectorToRotator(fDir);
                        }

                        if (Config["AIM_MOD3"]) {
                            FVector fDir = UKismetMathLibrary::Subtract_VectorVector(targetAimPos,
                                                                                     start);
                            FRotator sex = UKismetMathLibrary::Conv_VectorToRotator(fDir);
                            rot = sex;
                        }
                    }
                }
            }
        }

    }
    return orig_shoot_event(thiz, start, rot, weapon, unk1);
    //  return orig_shoot_event(thiz, start, sex, weapon, unk1);
}

/*
Fix Silent Aim Fake Damage

Search:
return orig_shoot_event(thiz, targetAimPos, sex, weapon, unk1);
Replace:
return orig_shoot_event(thiz, start, sex, weapon, unk1);


void (*orig_shoot_event)(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1, int unk2) = 0;

void shoot_event(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, ASTExtraShootWeapon *weapon, int unk1) {

             if (Config["NRG::AIMBOT"]) {
                   if (Config["AIM::MOD2"]) {
          ASTExtraPlayerCharacter *Target = 0;
                                   if (Config["AIM::TARGET1"]) {
                                        Target = GetTargetByDistance();
                                    }
                                    if (Config["AIM::TARGET2"]) {

                                        Target = GetTargetByCrosshairDistance();
                                    }


                    if (Target)
                    {
                        bool triggerOk = false;
                       if (Config["AIM::TRIGGER1"]) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring;
                } else if (Config["AIM::TRIGGER2"]) {
                    triggerOk = g_LocalPlayer->bIsGunADS;
                } else if (Config["AIM::TRIGGER3"]) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;

            } else triggerOk = true;
                        if (triggerOk)
                        {
                                        FVector targetAimPos = GetBoneLocation(Target, "Head");//Target->GetBonePos("Head", {});


                UShootWeaponEntity *ShootWeaponEntityComponent = thiz->ShootWeaponEntityComponent;
                if (ShootWeaponEntityComponent) {
                    ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                    if (CurrentVehicle) {
                        FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;

                        float dist = g_LocalPlayer->GetDistanceTo(Target);
                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;

                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel));
                    } else {
                        FVector Velocity = Target->GetVelocity();

                        float dist = g_LocalPlayer->GetDistanceTo(Target);
                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;

                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(Velocity, timeToTravel));
                    }

                    FVector fDir = UKismetMathLibrary::Subtract_VectorVector(targetAimPos, start);
                   FRotator sex = UKismetMathLibrary::Conv_VectorToRotator(fDir);
                   rot = sex;
                }
            }
        }
       }
    }
    return orig_shoot_event(thiz, start, rot, weapon, unk1);
}

*/
std::string playerstatus(int GetEnemyState) {
    switch (GetEnemyState) {
        case 0:
            return "AFK";
            break;
        case 1032:
            return "TILT HEAD";
            break;
        case 268435464:
            return "PLAY EMOTION";
            break;
        case 1552:
            return "AIMING";
            break;
        case 8388616:
            return "PARACHUTE";
            break;
        case 131072:
            return "KNOCKED";
            break;
        case 33554440:
            return "PLANE";
            break;
        case 8205:
            return "SHOT";
            break;
        case 32:
            return "SIT";
            break;
        case 4194303:
            return "SWIMMING";
            break;
        case 72:
            return "JUMPING";
            break;
        case 8388608:
            return "PARACHUTE";
            break;
        case 16392:
            return "THROW SOMETHING";
            break;
        case 262:
            return "RELOADING";
            break;
        case 1048584:
            return "RIDE";
            break;
        case 8200:
            return "FIST";
            break;
        case 2056:
            return "CUT GUN";
            break;
        case 4194302:
            return "SWIMMING";
            break;
        case 269:
            return "RELOADING";
            break;
        case 16777224:
            return "CLIMBING";
            break;
        case 10:
            return "RUN";
            break;
        case 263:
            return "RELOADING";
            break;
        case 65568 || 65544:
            return "FIGHT MEDICINE";
            break;
        case 4194308:
            return "SWIMMING";
            break;
        case 268:
            return "RELOADING";
            break;
        case 35:
            return "GET SIT";
            break;
        case 8388617:
            return "PARACHUTE";
            break;
        case 33:
            return "AIMING";
            break;
        case 75:
            return "JUMPING";
            break;
        case 8201:
            return "FIST";
            break;
        case 266:
            return "RELOADING";
            break;
        case 32776:
            return "KNOCKED";
            break;
        case 270:
            return "RELOADING";
            break;
        case 4194301:
            return "SWIMMING";
            break;
        case 1033:
            return "RUN";
            break;
        case 131073:
            return "KNOCKED";
            break;
        case 524296:
            return "DRIVING";
            break;
        case 1114120:
            return "FIGHT MEDICINE";
            break;
        case 265:
            return "RELOADING";
            break;
        case 9:
            return "RUN";
            break;
        case 262144:
            return "SMOKE";
            break;
        case 8203:
            return "FIST";
            break;
        case 8202:
            return "SHOT";
            break;
        case 262152:
            return "DEATH";
            break;
        case 17416:
            return "THROW SOMETHING";
            break;
        case 17:
            return "SIT";
            break;
        case 11:
            return "RUN";
            break;
        case 65545:
            return "FIGHT MEDICINE";
            break;
        case 33554432:
            return "PLANE";
            break;
        case 19:
            return "SQUAT";
            break;
        case 8208:
            return "SHOT";
            break;
        case 520:
            return "AIMING";
            break;
        case 8206:
            return "SHOT";
            break;
        case 8:
            return "STAND";
            break;
        case 16:
            return "SIT";
            break;
        case 13180:
            return "KNOCKED";
            break;
        case 4194310:
            return "SWIMMING";
            break;
        case 16393:
            return "THROW SOMETHING";
            break;
        case 4194309:
            return "SWIMMING";
            break;
        case 264:
            return "RELOADING";
            break;
        case 4194305:
            return "SWIMMING";
            break;
        case 8207:
            return "SHOT";
            break;
        case 4194307:
            return "SWIMMING";
            break;
            return "";
    }
}


std::string playerstatusAim(int GetEnemyState) {
    switch (GetEnemyState) {
/*
            case 33:
            return "1 ⚠️ ENEMY AIMING AT YOU! ⚠️";
            break;
        */
        case 1552:
            return "2  ⚠️ ENEMY AIMING AT YOU! ⚠️";
            break;

        case 520:
            return "3   ⚠️ ENEMY AIMING AT YOU! ⚠️";
            break;


            return "";
    }
}
/*
void Canvas::drawNrg3DBox(FVector extends, FVector origin,float thickness ,int color)
{
    origin.X -= extends.X / 2.f;
    origin.Y -= extends.Y / 2.f;
    origin.Z -= extends.Z / 2.f;


 FVector one = origin;
 FVector two = origin; two.X += extends.X;
 FVector tree = origin; tree.X += extends.X; tree.Y += extends.Y;
 FVector four = origin; four.Y += extends.Y;

 FVector five = one; five.Z += extends.Z;
 FVector six = two; six.Z += extends.Z;
 FVector seven = tree; seven.Z += extends.Z;
 FVector eight = four; eight.Z += extends.Z;
 auto PlayerCameraManager = g_PlayerController->PlayerCameraManager;
                    CameraCache =PlayerCameraManager->CameraCache;




 FVector s1 = WorldToScreen(one);
 FVector s2 = WorldToScreen(two);
 FVector s3 = WorldToScreen(tree);
 FVector s4 = WorldToScreen(four);
 FVector s5 = WorldToScreen(five);
 FVector s6 = WorldToScreen(six);
 FVector s7 = WorldToScreen(seven);
 FVector s8 = WorldToScreen(eight);



 drawLine(s1.X,s1.Y,s2.X,s2.Y,thickness,color);
 drawLine(s2.X,s2.Y,s3.X,s3.Y,thickness,color);
 drawLine(s3.X,s3.Y,s4.X,s4.Y,thickness,color);
 drawLine(s4.X,s4.Y,s1.X,s1.Y,thickness,color);

 drawLine(s5.X,s5.Y,s6.X,s6.Y,thickness,color);
 drawLine(s6.X,s6.Y,s7.X,s7.Y,thickness,color);
 drawLine(s7.X,s7.Y,s8.X,s8.Y,thickness,color);
 drawLine(s8.X,s8.Y,s5.X,s5.Y,thickness,color);

 drawLine(s1.X,s1.Y,s5.X,s5.Y,thickness,color);
 drawLine(s2.X,s2.Y,s6.X,s6.Y,thickness,color);
 drawLine(s3.X,s3.Y,s7.X,s7.Y,thickness,color);
 drawLine(s4.X,s4.Y,s8.X,s8.Y,thickness,color);

}
*/






/*
FVector GetBoneLocation(ASTExtraPlayerCharacter* Actor, FName Name) {
    auto Mesh = Actor->Mesh;
    if (Mesh) {
        auto Idx = Mesh->GetBoneIndex(Name);
        if (Idx != -1) {
            auto CachedComponentSpaceTransforms = Mesh->CachedComponentSpaceTransforms;
            if (CachedComponentSpaceTransforms.IsValidIndex(Idx)) {
                auto ComponentToWorld = Mesh->K2_GetComponentToWorld();
                auto Bone = CachedComponentSpaceTransforms[Idx];
                return TransformToLocation(ComponentToWorld, Bone);
            }
        }
    }
    return {0, 0, 0};
}
FVector GetBoneLocation(ASTExtraPlayerCharacter* Actor, int Idx) {
    auto Mesh = Actor->Mesh;
    if (Mesh) {

            auto CachedComponentSpaceTransforms = Mesh->CachedComponentSpaceTransforms;
            if (CachedComponentSpaceTransforms.IsValidIndex(Idx)) {
                auto ComponentToWorld = Mesh->K2_GetComponentToWorld();
                auto Bone = CachedComponentSpaceTransforms[Idx];
                return TransformToLocation(ComponentToWorld, Bone);
            }
        }
   
    return {0, 0, 0};
}
*/
unsigned long getModuleBase(char *module_name) {
    char *phgsr;
    char jjjj_N[64];
    long startaddr = 0;
    char path[256], line[1024];
    bool bssOF = false, LastIsSo = false;
    strcpy(jjjj_N, module_name);
    phgsr = strtok(jjjj_N, ":");
    module_name = phgsr;
    phgsr = strtok(nullptr, ":");
    if (phgsr) {
        if (strcmp(phgsr, "bss") == 0) {
            bssOF = true;
        }
    }
    sprintf(path, "/proc/%d/maps", getpid());
    FILE *p = fopen(path, "r");
    if (p) {
        while (fgets(line, sizeof(line), p)) {
            if (LastIsSo) {
                if (strstr(line, "[anon:.bss]") != NULL) {
                    sscanf(line, "%lx-%*lx", &startaddr);
                    break;
                } else {
                    LastIsSo = false;
                }
            }
            if (strstr(line, module_name) != nullptr) {
                if (!bssOF) {
                    sscanf(line, "%lx-%*lx", &startaddr);
                    break;
                } else {
                    LastIsSo = true;
                }
            }
        }
        fclose(p);
    }
    return startaddr;
}


// TODO : FPS DATA
uint64_t GetTickCount() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

class Interval {
private:
    int initial_;

public:
    inline Interval() : initial_(GetTickCount()) {
    }

    virtual ~ Interval() = default;

    inline unsigned int value() const {
        return GetTickCount() - initial_;
    }
};

class FPS {
protected:
    int32_t m_fps;
    int32_t m_fpscount;
    Interval m_fpsinterval;
public:
    FPS() : m_fps(0), m_fpscount(0) {
    }

    void Update() {
        m_fpscount++;
        if (m_fpsinterval.value() > 1000) {
            m_fps = m_fpscount;
            m_fpscount = 0;
            m_fpsinterval = Interval();
        }
    }

    int32_t get() const {
        return m_fps;
    }
};

FPS m_fps;

float BulletFireSpeed = 0;

FRotator aimproAIM(FVector targetAimPos) {


}


void aim(FRotator rot) {


    g_PlayerController->AController::SetControlRotation(rot, "");


}

bool bull = 0;


#define ARGB(a, r, g, b) 0 | a << 24 | r << 16 | g << 8 | b

// ================================================================================================================================ //
void DrawESP(ESP esp, int screenWidth, int screenHeight) {
// void native_onCanvasDraw(JNIEnv *env, jobject thiz, jobject canvas, jint screenWidth, jint screenHeight, jfloat screenDensity) {


    g_screenWidth = screenWidth;
    g_screenHeight = screenHeight;
    if (!g_Token.empty() && !g_Auth.empty() && g_Token == g_Auth) {


        //   m_fps.Update();

        /*
       int screenWidth = g_screenWidth;
         int screenHeight = g_screenHeight;
    */
        sprintf(extra, "%s", "BEAR-ENGINE");
        esp.DrawText(Color::White(), extra, FVector2D(screenWidth / 2, 95), 45);
       


        if (!bScanPatternCompleted)
            return;


        auto GWorld = GetWorld();
        if (GWorld) {
            ULevel *PersistentLevel = GWorld->PersistentLevel;
            if (GWorld->PersistentLevel) {
                TArray<AActor *> Actors = *(TArray<AActor *> *) ((uintptr_t) PersistentLevel +
                                                                 0xA0);

                int totalEnemies = 0, totalBots = 0;
                auto localPlayer = g_LocalPlayer;
                auto localController = g_PlayerController;
                if (localController) {

                    if (Config["ESP_RADAR"]) {
                        struct Vector3 Pos;
                        Pos.X = screenWidth / 5.5;//4.395
                        Pos.Y = screenHeight / 10;//40

                        struct Vector3 Size;
                        Size.X = Config["RADAR_SIZE"];
                        Size.Y = Config["RADAR_SIZE"];
                        float RadarCenterX = Pos.X + (Size.X / 2);
                        float RadarCenterY = Pos.Y + (Size.Y / 2);
                        esp.DrawFilledRect(Color(0, 0, 0, 130), {Pos.X, Pos.Y}, {Size.X, Size.Y});
                        esp.DrawLine2(Color::White(), 1.5, FVector2D{Pos.X, Pos.Y},
                                      FVector2D{Pos.X + Size.X, Pos.Y});
                        esp.DrawLine2(Color::White(), 1.5, FVector2D{Pos.X, Pos.Y + Size.Y},
                                      FVector2D{Pos.X + Size.X, Pos.Y + Size.Y});
                        esp.DrawLine2(Color::White(), 1.5, FVector2D{Pos.X, Pos.Y},
                                      FVector2D{Pos.X, Pos.Y + Size.Y});
                        esp.DrawLine2(Color::White(), 1.5, FVector2D{Pos.X + Size.X, Pos.Y},
                                      FVector2D{Pos.X + Size.X, Pos.Y + Size.Y});
                        esp.DrawLine2(Color::White(), 1.5, FVector2D{RadarCenterX, Pos.Y},
                                      FVector2D{RadarCenterX, Pos.Y + Size.Y});
                        esp.DrawLine2(Color::White(), 1.5, FVector2D{Pos.X, RadarCenterY},
                                      FVector2D{Pos.X + Size.X, RadarCenterY});
                        esp.DrawRect(Color(255, 255, 255), 1.5, {Pos.X, Pos.Y}, {Size.X, Size.Y});
                        esp.DrawCircle(Color(255, 0, 0), FVector2D{RadarCenterX, RadarCenterY},
                                       3.0f, 10);
//esp.DrawText(Color::Red(), "•", FVector2D(RadarCenterX, RadarCenterY), 40);//20
                    }
                    if (localPlayer) {



                        for (int i = 0; i < Actors.Num(); i++) {
                            if (isObjectPlayer(Actors[i])) {
                                auto Player = (ASTExtraPlayerCharacter *) Actors[i];
                                auto RootComponent = Player->RootComponent;
                                if (!RootComponent)
                                    continue;


                                float Distance = localPlayer->GetDistanceTo(Player) / 100.0f;
                                if (Distance < 1000.f) {

                                    int Visible;


                                    if (localPlayer) {
                                        if (Player->PlayerKey == localPlayer->PlayerKey)
                                            continue;

                                        if (Player->TeamID == localPlayer->TeamID)
                                            continue;
                                    }

                                    if (Player->bDead)
                                        continue;


                                    if (Player->bHidden)
                                        continue;

                                    Color RADARColor;
                                    Color NameColor;
                                    if (Player->bEnsure) {
                                        RADARColor = Color::Green();
                                        NameColor = Color::White();
                                    } else {
                                        RADARColor = Color::Red();
                                        NameColor = Color::Yellow();
                                    }

                                    if (Config["ESP_RADAR"]) {
                                        bool out = false;
                                        struct Vector3 Pos;
                                        Pos.X = screenWidth / 5.5;//4.395
                                        Pos.Y = screenHeight / 10;//40

                                        struct Vector3 Size;
                                        Size.X = Config["RADAR_SIZE"];
                                        Size.Y = Config["RADAR_SIZE"];
                                        float RadarCenterX = Pos.X + (Size.X / 2);
                                        float RadarCenterY = Pos.Y + (Size.Y / 2);
                                        FVector MyPosition, EnemyPosition;
                                        ASTExtraVehicleBase *CurrentVehiclea = Player->CurrentVehicle;
                                        if (CurrentVehiclea) {
                                            MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
                                        } else {
                                            MyPosition = Player->RootComponent->RelativeLocation;
                                        }
                                        ASTExtraVehicleBase *CurrentVehicle = localPlayer->CurrentVehicle;
                                        if (CurrentVehicle) {
                                            EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
                                        } else {
                                            EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                                        }
                                        FVector RadarSketch = WorldToRadar(
                                                localController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw,
                                                MyPosition, EnemyPosition, Pos.X, Pos.Y,
                                                Vector3(Size.X, Size.Y, 0), out);

                                        //   DrawFilledCircleM(HUD, FVector2D{RadarSketch.X,RadarSketch.Y}, 4.0, colV);
                                        //  esp.DrawCircle(RADARColor, FVector2D{RadarSketch.X,RadarSketch.Y}, 3.0f, 16);
                                        esp.DrawCircle(RADARColor,
                                                       FVector2D{RadarSketch.X, RadarSketch.Y},
                                                       3.0f, 10);
                                        std::string s;
                                        s += std::to_string((int) Distance);

                                        esp.DrawText(Color::White(), s.c_str(),
                                                     FVector2D(RadarSketch.X, RadarSketch.Y + 3),
                                                     16);


                                    }

                                    if (Config["ESP_IGNOREBOTS"]) {
                                        if (Player->bEnsure)
                                            continue;
                                    }


                                    if (Player->bEnsure)
                                        totalBots++;
                                    else totalEnemies++;

                                    Color LineColor;
                                    if (!localController->LineOfSightTo(
                                            localController->PlayerCameraManager,
                                            Player->GetBonePos("Head", {}), true)) {

                                        LineColor = Color::White();
                                    } else {


                                        if (Player->bEnsure) {
                                            LineColor = Color::White();
                                        } else {
                                            LineColor = Color::Green();
                                        }

                                    }


                                    Color clrHealth;
                                    if (Player->bEnsure) {
                                        //   SCOLOR4 = WHITE;
                                        // HPColormmm = GREEN2;

                                        clrHealth = Color(0, 255, 0, 190);
                                    } else {
                                        //  SCOLOR4 = YELLOW;
                                        //  HPColormmm = RED;
                                        clrHealth = Color(255, 0, 0, 190);

                                    }


                                    FVector Head = GetBoneLocation(Player,
                                                                   "Head");//Player->GetBonePos("Head", {});
                                    FVector Root = GetBoneLocation(Player,
                                                                   "Root");//Player->GetBonePos("Root", {});
                                    FVector RootPos = GetBoneLocation(Player, "Root");
                                    FVector HeadPos2 = GetBoneLocation(Player, "Head");
                                    HeadPos2.Z += 17.5f;//16.5f;
                                    FVector RootPos2 = GetBoneLocation(Player, "Root");
                                    RootPos2.Z -= 6.5f;//5.5f;
                                    //targetAimPos.Z -= 25.f;

                                    auto Head_RootZ = HeadPos2.Z - RootPos2.Z;
                                    FVector uparmr = GetBoneLocation(Player,
                                                                     "upperarm_r");//GetBoneLocationByName
                                    FVector uparml = GetBoneLocation(Player, "upperarm_l");
                                    FVector lowarmr = GetBoneLocation(Player, "lowerarm_r");
                                    FVector lowarml = GetBoneLocation(Player, "lowerarm_l");
                                    FVector handr = GetBoneLocation(Player, "hand_r");
                                    FVector handl = GetBoneLocation(Player, "hand_l");
                                    FVector itemr = GetBoneLocation(Player, "item_r");
                                    FVector iteml = GetBoneLocation(Player, "item_l");

                                    FVector clavicler = GetBoneLocation(Player, "clavicle_r");
                                    FVector claviclel = GetBoneLocation(Player, "clavicle_l");

                                    FVector neck = GetBoneLocation(Player, "neck_01");
                                    FVector spain01 = GetBoneLocation(Player, "spine_01");
                                    FVector spain02 = GetBoneLocation(Player, "spine_02");
                                    FVector spain03 = GetBoneLocation(Player, "spine_03");
                                    FVector pelvis = GetBoneLocation(Player, "pelvis");

                                    FVector calfl = GetBoneLocation(Player, "calf_l");
                                    FVector calfr = GetBoneLocation(Player, "calf_r");
                                    FVector thighl = GetBoneLocation(Player, "thigh_l");
                                    FVector thighr = GetBoneLocation(Player, "thigh_r");


                                    FVector footr = GetBoneLocation(Player, "foot_r");
                                    FVector footl = GetBoneLocation(Player, "foot_l");

                                    FVector uparmrSC = WorldToScreen(uparmr);
                                    FVector uparmlSC = WorldToScreen(uparml);
                                    FVector lowarmrSC = WorldToScreen(lowarmr);
                                    FVector lowarmlSC = WorldToScreen(lowarml);
                                    FVector handrSC = WorldToScreen(handr);
                                    FVector handlSC = WorldToScreen(handl);
                                    FVector itemrSC = WorldToScreen(itemr);
                                    FVector itemlSC = WorldToScreen(iteml);

                                    FVector claviclerSC = WorldToScreen(clavicler);
                                    FVector claviclelSC = WorldToScreen(claviclel);

                                    FVector neckSC = WorldToScreen(neck);
                                    FVector spain01SC = WorldToScreen(spain01);
                                    FVector spain02SC = WorldToScreen(spain02);
                                    FVector spain03SC = WorldToScreen(spain03);
                                    FVector pelvisSC = WorldToScreen(pelvis);

                                    FVector calflSC = WorldToScreen(calfl);
                                    FVector calfrSC = WorldToScreen(calfr);
                                    FVector thighlSC = WorldToScreen(thighl);
                                    FVector thighrSC = WorldToScreen(thighr);

                                    FVector footrSC = WorldToScreen(footr);
                                    FVector footlSC = WorldToScreen(footl);


                                    FVector HeadSc = WorldToScreen(Head);
                                    FVector RootSc = WorldToScreen(Root);
                                    Vector2 screen(screenWidth, screenHeight);
                                    Vector2 location(RootSc.X, HeadSc.Y);
                                    float boxHeight = fabsf(RootSc.Y - HeadSc.Y);
                                    float boxWidth = boxHeight * 0.68;
                                    Rect2 Box(HeadSc.X - (boxWidth / 2), HeadSc.Y, boxWidth,
                                              boxHeight);

                                    FVector HeadNrg = GetBoneLocation(Player, "Head");
                                    HeadNrg.Z += 35.f;
                                    FVector2D HeadNrgSc;
                                    auto PlayerCameraManager = localController->PlayerCameraManager;
                                    CameraCache = PlayerCameraManager->CameraCache;

                                    HeadNrgSc = WorldToScreen360(HeadNrg, CameraCache.POV,
                                                                 screenWidth, screenHeight);


                                    auto isvis = localController->LineOfSightTo(localPlayer, Head,
                                                                                false);


                                    if (HeadSc.Z > 0 && RootSc.Z > 0) {
                                        //   auto Root = Player->GetBonePos("Root", {});
                                        //   auto Head = Player->GetBonePos("Head", {});

                                        if (Config["ESP_LINE"]) {

                                            auto gunHead = Player->GetHeadLocation(true);
                                            gunHead.Z += 35.f;


                                            FVector GunHeadSc = WorldToScreen(gunHead);
                                            auto mWidthScaleGun = std::min(0.006f * Distance,
                                                                           100.f);
                                            auto mWidthGun = 20.f - mWidthScaleGun;
                                            auto mHeightGun = mWidthGun * 0.125f;
                                            //   GunHeadSc.X -= (mWidthGun / 2 - 20);
                                            GunHeadSc.Y -= (mHeightGun * 1.4f + 15);


                                            esp.DrawLine2(LineColor, 2,
                                                          FVector2D(screenWidth / 2, 0),
                                                          FVector2D(HeadSc.X,
                                                                    GunHeadSc.Y - 16));//- 56
                                        }



                                        if (Config["ESP_BONE"]) {

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, neck,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(HeadSc.X, HeadSc.Y),
                                                              FVector2D(neckSC.X, neckSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(HeadSc.X, HeadSc.Y),
                                                              FVector2D(neckSC.X, neckSC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, clavicler,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(neckSC.X, neckSC.Y),
                                                              FVector2D(claviclerSC.X,
                                                                        claviclerSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(neckSC.X, neckSC.Y),
                                                              FVector2D(claviclerSC.X,
                                                                        claviclerSC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, uparmr,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(claviclerSC.X,
                                                                        claviclerSC.Y),
                                                              FVector2D(uparmrSC.X, uparmrSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(claviclerSC.X,
                                                                        claviclerSC.Y),
                                                              FVector2D(uparmrSC.X, uparmrSC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, lowarmr,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(uparmrSC.X, uparmrSC.Y),
                                                              FVector2D(lowarmrSC.X, lowarmrSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(uparmrSC.X, uparmrSC.Y),
                                                              FVector2D(lowarmrSC.X, lowarmrSC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, handr,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(lowarmrSC.X, lowarmrSC.Y),
                                                              FVector2D(handrSC.X, handrSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(lowarmrSC.X, lowarmrSC.Y),
                                                              FVector2D(handrSC.X, handrSC.Y));

//esp.DrawLine2(Color::Green(), 2.2f, FVector2D(lowarmrSC.X, lowarmrSC.Y), FVector2D(handrSC.X, handrSC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, itemr,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(handrSC.X, handrSC.Y),
                                                              FVector2D(itemrSC.X, itemrSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(handrSC.X, handrSC.Y),
                                                              FVector2D(itemrSC.X, itemrSC.Y));
                                            }


                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, claviclel,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(neckSC.X, neckSC.Y),
                                                              FVector2D(claviclelSC.X,
                                                                        claviclelSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(neckSC.X, neckSC.Y),
                                                              FVector2D(claviclelSC.X,
                                                                        claviclelSC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, uparml,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(claviclelSC.X,
                                                                        claviclelSC.Y),
                                                              FVector2D(uparmlSC.X, uparmlSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(claviclelSC.X,
                                                                        claviclelSC.Y),
                                                              FVector2D(uparmlSC.X, uparmlSC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, lowarml,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(uparmlSC.X, uparmlSC.Y),
                                                              FVector2D(lowarmlSC.X, lowarmlSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(uparmlSC.X, uparmlSC.Y),
                                                              FVector2D(lowarmlSC.X, lowarmlSC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, handl,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(lowarmlSC.X, lowarmlSC.Y),
                                                              FVector2D(handlSC.X, handlSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(lowarmlSC.X, lowarmlSC.Y),
                                                              FVector2D(handlSC.X, handlSC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, iteml,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(handlSC.X, handlSC.Y),
                                                              FVector2D(itemlSC.X, itemlSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(handlSC.X, handlSC.Y),
                                                              FVector2D(itemlSC.X, itemlSC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, spain03,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(neckSC.X, neckSC.Y),
                                                              FVector2D(spain03SC.X, spain03SC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(neckSC.X, neckSC.Y),
                                                              FVector2D(spain03SC.X, spain03SC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, spain02,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(spain03SC.X, spain03SC.Y),
                                                              FVector2D(spain02SC.X, spain02SC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(spain03SC.X, spain03SC.Y),
                                                              FVector2D(spain02SC.X, spain02SC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, spain01,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(spain02SC.X, spain02SC.Y),
                                                              FVector2D(spain01SC.X, spain01SC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(spain02SC.X, spain02SC.Y),
                                                              FVector2D(spain01SC.X, spain01SC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, pelvis,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(spain01SC.X, spain01SC.Y),
                                                              FVector2D(pelvisSC.X, pelvisSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(spain01SC.X, spain01SC.Y),
                                                              FVector2D(pelvisSC.X, pelvisSC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, thighr,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(pelvisSC.X, pelvisSC.Y),
                                                              FVector2D(thighrSC.X, thighrSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(pelvisSC.X, pelvisSC.Y),
                                                              FVector2D(thighrSC.X, thighrSC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, calfr,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(thighrSC.X, thighrSC.Y),
                                                              FVector2D(calfrSC.X, calfrSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(thighrSC.X, thighrSC.Y),
                                                              FVector2D(calfrSC.X, calfrSC.Y));
                                            }
                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, footr,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(calfrSC.X, calfrSC.Y),
                                                              FVector2D(footrSC.X, footrSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(calfrSC.X, calfrSC.Y),
                                                              FVector2D(footrSC.X, footrSC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, thighl,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(pelvisSC.X, pelvisSC.Y),
                                                              FVector2D(thighlSC.X, thighlSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(pelvisSC.X, pelvisSC.Y),
                                                              FVector2D(thighlSC.X, thighlSC.Y));
                                            }

                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, calfl,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(thighlSC.X, thighlSC.Y),
                                                              FVector2D(calflSC.X, calflSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(thighlSC.X, thighlSC.Y),
                                                              FVector2D(calflSC.X, calflSC.Y));
                                            }
                                            if (!localController->LineOfSightTo(
                                                    localController->PlayerCameraManager, footl,
                                                    true)) {
                                                esp.DrawLine2(Color::Red(), 2.2f,
                                                              FVector2D(calflSC.X, calflSC.Y),
                                                              FVector2D(footlSC.X, footlSC.Y));
                                            } else {
                                                esp.DrawLine2(Color::Green(), 2.2f,
                                                              FVector2D(calflSC.X, calflSC.Y),
                                                              FVector2D(footlSC.X, footlSC.Y));
                                            }
                                        }


                                        if (Config["ESP_INFO"]) {
                                            int CurHP = (int) std::max(0, std::min(
                                                    (int) Player->Health, (int) Player->HealthMax));
                                            int MaxHP = (int) Player->HealthMax;

                                            //     long curHP_Color = ARGB(155, std::min(((510 * (MaxHP - CurHP)) / MaxHP), 255), std::min(((510 * CurHP) / MaxHP), 255), 0);

                                            if (Player->Health == 0.0f && !Player->bDead) {
                                                //     curHP_Color = ARGB(255, 255, 0, 0);

                                                clrHealth = Color(255, 255, 0, 190);

                                                CurHP = Player->NearDeathBreath;
                                                if (Player->NearDeatchComponent) {
                                                    MaxHP = Player->NearDeatchComponent->BreathMax;
                                                }
                                            }


                                            auto mWidthScale = std::min(0.0f * 24.0f,
                                                                        0.0f); //100  75 50 | 24
                                            //    auto mWidthScale = std::min(0.10f * Distance, 50.f);

                                            auto mWidth2 = 10.0f - mWidthScale;
                                            auto mWidth3 = 20.0f - mWidthScale;
                                            auto mWidth4 = 30.0f - mWidthScale;
                                            auto mWidth5 = 40.0f - mWidthScale;
                                            auto mWidth = 50.0f - mWidthScale;
                                            auto mWidth99 = 5.0f - mWidthScale;


                                            //   float boxHeight = abs(HeadSc.Y - RootSc.Y);
                                            //   auto mHeight = mWidth * 0.070f;//098f //0.07f
                                            auto mHeight = mWidth * 0.078f;
                                            auto mHeightgg = mWidth * -0.0f;//098f //0.07f
                                            //    auto mHeight2 = mWidth * 0.140f; //180f
                                            HeadSc.X -= (mWidth / 2);
                                            HeadSc.Y -= (mHeight * 1.5f);


                                            auto HpHead = Player->GetHeadLocation(true);
                                            HpHead.Z += 35.f;


                                            FVector HpHeadSc = WorldToScreen(HpHead);
                                            auto mWidthScaleGun = std::min(0.006f * Distance,
                                                                           100.f);
                                            auto mWidthGun = 20.f - mWidthScaleGun;
                                            auto mHeightGun = mWidthGun * 0.125f;
                                            HpHeadSc.X -= (mWidthGun / 2/* - 20*/);
                                            HpHeadSc.Y -= (mHeightGun * 1.4f + 8);//10


                                            esp.DrawFilledRect(clrHealth,
                                                               FVector2D(HeadSc.X, HpHeadSc.Y),
                                                               FVector2D(CurHP * mWidth / MaxHP,
                                                                         mHeight));

                                            esp.DrawRect(Color(0, 0, 0), 1.5,
                                                         FVector2D(HeadSc.X, HpHeadSc.Y),
                                                         FVector2D(mWidth2, mHeight));
                                            esp.DrawRect(Color(0, 0, 0), 1.5,
                                                         FVector2D(HeadSc.X, HpHeadSc.Y),
                                                         FVector2D(mWidth3, mHeight));
                                            esp.DrawRect(Color(0, 0, 0), 1.5,
                                                         FVector2D(HeadSc.X, HpHeadSc.Y),
                                                         FVector2D(mWidth4, mHeight));
                                            esp.DrawRect(Color(0, 0, 0), 1.5,
                                                         FVector2D(HeadSc.X, HpHeadSc.Y),
                                                         FVector2D(mWidth5, mHeight));
                                            esp.DrawRect(Color(0, 0, 0), 1.5,
                                                         FVector2D(HeadSc.X, HpHeadSc.Y),
                                                         FVector2D(mWidth, mHeight));


                                        }

                                        if (Config["ESP_INFO"]) {

                                            std::string s;
                                            s += std::to_string((int) Distance);
                                            s += "M";

                                            esp.DrawText(Color::White(), s.c_str(),
                                                         FVector2D(RootSc.X, RootSc.Y + 15), 14);
                                        }

                                        if (Config["ESP_INFO"] || Config["ESP_WEAPON"]) {
                                            auto gunHead = Player->GetHeadLocation(true);
                                            gunHead.Z += 35.f;

                                            auto nameHead = Player->GetHeadLocation(true);
                                            nameHead.Z += 35.f;

                                            FVector NameHeadSc = WorldToScreen(nameHead);
                                            FVector GunHeadSc = WorldToScreen(gunHead);
                                            auto mWidthScaleGun = std::min(0.006f * Distance, 100.f);
                                            auto mWidthGun = 20.f - mWidthScaleGun;
                                            auto mHeightGun = mWidthGun * 0.125f;
                                            GunHeadSc.X -= (mWidthGun / 2 - 20);
                                            GunHeadSc.Y -= (mHeightGun * 1.4f + 15);

                                            auto mWidthScaleName = std::min(0.006f * Distance, 100.f);
                                            auto mWidthName = 20.f - mWidthScaleName;
                                            auto mHeightName = mWidthName * 0.125f;
                                            NameHeadSc.Y -= (mHeightName * 1.4f + 15);

                                            std::string ws;
                                            std::string ws2;
                                            auto WeaponManagerComponent = Player->WeaponManagerComponent;
                                            if (WeaponManagerComponent) {
                                                auto CurrentWeapon = (ASTExtraShootWeapon*)WeaponManagerComponent->CurrentWeaponReplicated;
                                                if (CurrentWeapon) {
                                                    auto WeaponName = CurrentWeapon->GetWeaponName();
                                                    if (WeaponName.IsValid()) {
                                                        const char* utf8Name = WeaponName.ToString(); // Returns const char*
                                                        if (utf8Name) {
                                                            ws2 = "(" + std::string(utf8Name) + ")"; // ✅ No .get()
                                                        } else {
                                                            ws2 = "(Unknown)";
                                                        }
                                                    }
                                                }
                                            }
                                            if (Player->bEnsure) {
                                                ws = std::to_string(Player->TeamID) + " Bot";
                                            } else {
                                                auto playerNameStr = Player->PlayerName;
                                                if (playerNameStr.IsValid()) {
                                                    const char* utf8Name = playerNameStr.ToString(); // Returns const char*
                                                    ws = utf8Name ? std::string(utf8Name) : "Player"; // ✅ No .get()
                                                } else {
                                                    ws = "Invalid";
                                                }
                                            }
                                            if (Config["ESP_WEAPON"] && !ws2.empty()) {
                                                esp.DrawText(Color::White(), ws2.c_str(), FVector2D(GunHeadSc.X - 11.2, GunHeadSc.Y - 19.5), 14.8f);
                                            }

                                            if (Config["ESP_INFO"] && !ws.empty()) {
                                                esp.DrawText(NameColor, ws.c_str(), FVector2D(NameHeadSc.X, NameHeadSc.Y - 2.7), 15.8);
                                            }
                                        }

                                            //  esp.DrawText(Color::White(), ws.c_str(), FVector2D(HeadSc.X - 9, HeadSc.Y - 7), 18);


                                        }


                                  //  }


                                    if (Config["ESP_ALERT"]) {

                                        bool shit = false;
                                        FVector MyPosition, EnemyPosition;
                                        ASTExtraVehicleBase *CurrentVehiclea = Player->CurrentVehicle;
                                        if (CurrentVehiclea) {
                                            MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
                                        } else {
                                            MyPosition = Player->RootComponent->RelativeLocation;
                                        }
                                        ASTExtraVehicleBase *CurrentVehicle = localPlayer->CurrentVehicle;
                                        if (CurrentVehicle) {
                                            EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
                                        } else {
                                            EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                                        }
                                        FVector EntityPos = WorldToRadar(
                                                localController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw,
                                                MyPosition, EnemyPosition, NULL, NULL,
                                                Vector3(screenWidth, screenHeight, 0), shit);
                                        FVector angle = FVector();
                                        Vector3 forward = Vector3(
                                                (float) (screenWidth / 2) - EntityPos.X,
                                                (float) (screenHeight / 2) - EntityPos.Y, 0.0f);
                                        VectorAnglesRadar(forward, angle);

                                        const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f + 360.f);
                                        const auto new_point_x = (screenWidth / 2) + (55) / 2 * 13 *
                                                                                     cosf(angle_yaw_rad);
                                        const auto new_point_y = (screenHeight / 2) +
                                                                 (55) / 2 * 13 *
                                                                 sinf(angle_yaw_rad);
                                        std::array<Vector3, 3> points{
                                                Vector3(new_point_x - ((120) / 4 + 18.0f) / 2,
                                                        new_point_y - ((44) / 4 + 18.0f) / 2, 0.f),
                                                Vector3(new_point_x + ((120) / 4 + 18.0f) / 4,
                                                        new_point_y, 0.f),
                                                Vector3(new_point_x - ((120) / 4 + 18.0f) / 2,
                                                        new_point_y + ((44) / 4 + 18.0f) / 2, 0.f)};
                                        RotateTriangle(points, angle.Y + 180.f);
                                        Point a2{points[0].X, points[0].Y};
                                        Point b2{points[1].X, points[1].Y};
                                        Point c2{points[2].X, points[2].Y};

                                        // m_Canvas->drawFilledTriangle(a2, b2, c2, SCOLOR2);
                                        esp.DrawText(Color::Red(), "🔴",
                                                     FVector2D(points[0].X, points[0].Y), 15);

                                    }



                                }


                            }




                            for (int i = 0; i < Actors.Num(); i++) {
                                if (isObjectInvalid(Actors[i]))
                                    continue;
                                if (Config["ESP_WARNING"]) {
                                    if (isObjectGrenade(Actors[i])) {
                                        auto *Grenade = (ASTExtraGrenadeBase *) Actors[i];
                                        std::string n = getObjectPath(Grenade);
                                        auto RootComponent = Actors[i]->RootComponent;
                                        if (!RootComponent)
                                            continue;
                                        float Distance = Grenade->GetDistanceTo(localPlayer) / 100.f;
                                        FVector2D grenadePos;
                                        FVector Location = WorldToScreen(
                                                RootComponent->RelativeLocation);
                                        if (Distance <= 100.f) {

                                            if (Location.Z > 0) {
                                                std::string s;

                                                if (n ==
                                                    "BP_Grenade_Burn_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object" ||
                                                    n ==
                                                    "BP_Grenade_Shoulei_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object") {

                                                    //    esp.DrawText(skeletonByDistance(Distance), "⚠️ WARNING ⚠️", FVector2D(screenWidth / 2, 195), 28);

                                                    esp.DrawText(Color::Red(), "⚠️ WARNING ⚠️",
                                                                 FVector2D(screenWidth / 2, 195), 28);
                                                }
                                                if (n ==
                                                    "BP_Grenade_Burn_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object") {

                                                    s += "Molotov";
                                                    s += " - [";
                                                    s += std::to_string((int) Distance);
                                                    s += "M]";
                                                } else if (n ==
                                                           "BP_Grenade_Shoulei_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object") {
                                                    //   m_Canvas->drawText(OBFUSCATE("⚠️ WARNING ⚠️"), screenWidth / 2, 195, 35.f, Align::CENTER, skeletonByDistance(Distance), BLACK);

                                                    s += "Grenade";
                                                    s += " - [";
                                                    s += std::to_string((int) Distance);
                                                    s += "M]";
                                                }

                                                //  char fmt[512];
                                                //  sprintf(fmt, "⚠ %dm", (int) Distance);
                                                //   m_Canvas->drawText(s.c_str(), Location.X, Location.Y, 25.0f, Align::CENTER, skeletonByDistance(Distance), BLACK);
                                                esp.DrawText(Color::Red(), s.c_str(),
                                                             FVector2D(Location.X, Location.Y), 15);


                                            }

                                        }
                                    }
                                }
                            }


                            if (Config["ESP::VEHICLE"]) {
                                if (isObjectVehicle(Actors[i])) {
                                    auto *Vehicle = (ASTExtraVehicleBase *) Actors[i];
                                    auto RootComponent = Vehicle->RootComponent;
                                    if (!RootComponent)
                                        continue;

                                    float vDistance = Vehicle->GetDistanceTo(localPlayer) / 100.f;
                                    if (vDistance < 700.f) {
                                        FVector Location = WorldToScreen(
                                                RootComponent->RelativeLocation);
                                        if (Location.Z > 0) {
                                            std::string s = GetVehicleName(Vehicle);
                                            s += " - ";
                                            s += std::to_string((int) vDistance);
                                            s += "M";
                                            //   auto mText = m_Canvas->getTextBounds(s.c_str(), 0, s.size());
                                            esp.DrawText(Color(255, 50, 255, 255), s.c_str(),
                                                         FVector2D(Location.X, Location.Y + 10),
                                                         15);

                                            //    m_Canvas->drawText(s.c_str(), Location.X, Location.Y + mText->getHeight(), 15.0f, Align::CENTER, ARGB(255,50,255,255), BLACK);

                                        }
                                    }
                                }
                            }

                            if (isObjectLoot(Actors[i])) {
                                auto *PickUp = (APickUpWrapperActor *) Actors[i];
                                if (Tools::IsPtrValid(PickUp)) {
                                    if (itemConfig[PickUp->DefineID.TypeSpecificID]) {

                                        auto RootComponent = PickUp->RootComponent;
                                        if (!RootComponent)
                                            continue;

                                        float Distance = PickUp->GetDistanceTo(localPlayer) / 100.f;

                                        std::string s;
                                        int tc = 0xFF000000, oc = 0xFFFFFFFF;

                                        for (auto &e: itemData) {
                                            if (e["itemId"] == PickUp->DefineID.TypeSpecificID) {
                                                s = "[ ";
                                                s += e["itemName"].get<std::string>();
                                                tc = strtoul(
                                                        e["itemTextColor"].get<std::string>().c_str(),
                                                        0, 16);
                                                oc = strtoul(
                                                        e["itemOutlineColor"].get<std::string>().c_str(),
                                                        0, 16);
                                                break;
                                            }
                                        }

                                        s += " ";
                                        s += std::to_string((int) Distance);
                                        s += "M ]";

                                        FVector Location = WorldToScreen(
                                                RootComponent->RelativeLocation);
                                        if (Location.Z > 0) {
                                            //   if (!Config["FIGHT_MODE"]) {
                                            esp.DrawText(Color(255, 255, 255, 255), s.c_str(),
                                                         FVector2D(Location.X, Location.Y), 16);

                                            //   m_Canvas->drawText(s.c_str(), Location.X, Location.Y, 16.5f, Align::CENTER, tc, oc);
                                        }
                                    }
                                }
                            }
                            if (Config["ESP::LOOTBOX"]) {
                                if (isObjectLootBox(Actors[i])) {
                                    auto *PickUpList = (APickUpListWrapperActor *) Actors[i];
                                    auto PickUpDataList = (TArray<FPickUpItemData>) PickUpList->GetDataList();
                                    auto RootComponent = PickUpList->RootComponent;
                                    if (!RootComponent)
                                        continue;

                                    float Distance = PickUpList->GetDistanceTo(localPlayer) / 100.f;
                                    if (Distance <= 50.f) {
                                        std::string s = GetLootName(PickUpList);
                                        s += " [";
                                        s += std::to_string((int) Distance);
                                        s += "m]";

                                        FVector Location = WorldToScreen(
                                                RootComponent->RelativeLocation);
                                        if (Location.Z > 0) {
                                            // m_Canvas->drawText(s.c_str(), Location.X, Location.Y, 14.0f,Align::LEFT, WHITE, BLACK);
                                            esp.DrawText(Color(255, 255, 255, 255), s.c_str(),
                                                         FVector2D(Location.X, Location.Y), 14);

                                            if (Config["ESP::LOOT_BOX_ITEMS"]) {
                                                if (Distance <= 15.f) {
                                                    for (int j = 0; j < PickUpDataList.Num(); j++) {
                                                        std::vector<std::string> s2;
                                                        long tc = 0xFF000000, oc = 0xFFFFFFFF;


                                                        for (auto &e: items_data) {
                                                            if (e["itemId"] ==
                                                                PickUpDataList[j].ID.TypeSpecificID) {
                                                                s2.push_back(
                                                                        e["itemName"].get<std::string>());
                                                                tc = strtoul(
                                                                        e["itemTextColor"].get<std::string>().c_str(),
                                                                        0, 16);
                                                                oc = strtoul(
                                                                        e["itemOutlineColor"].get<std::string>().c_str(),
                                                                        0, 16);
                                                                break;
                                                            }
                                                        }
                                                        if (!s2.empty()) {
                                                            if (PickUpDataList[j].Count > 1) {
                                                                s2.push_back(" * ");
                                                                s2.push_back(std::to_string(
                                                                        PickUpDataList[j].Count));

                                                            }

                                                            std::string s3;
                                                            for (auto &s4: s2) {
                                                                s3 += s4;
                                                            }

                                                            //     m_Canvas->drawText(s2, Location.X, posY, 14.5f,Align::LEFT, {tc, WHITE, LIME},{oc, BLACK, BLACK});
                                                            esp.DrawText(Color(255, 255, 255, 255),
                                                                         s.c_str(),
                                                                         FVector2D(Location.X,
                                                                                   Location.Y), 14);


                                                            //   m_Rect = m_Canvas->getTextBounds(s3.c_str(), 0,s3.size());
                                                            //  posY -= m_Rect->getHeight() * 1.38f;//25f
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }///





                    }

                    if (totalEnemies > 0) {

                        sprintf(extra, OBFUSCATE("[ALERT] %d Enemies in Area"), totalEnemies);
//sprintf(extra, "[ALERT] %d Enemies in Area", totalEnemies);
                        esp.DrawText(Color::Red(), extra, FVector2D(screenWidth / 2, 155), 40);


                        // m_Canvas->drawText(extra, screenWidth / 2, 155, 40.0f, Align::CENTER, RED, BLACK);
                    }


                    //}}
                }

                if (Config["NRG_AIMBOT"]) {
                    // float FOVSIZE = Config["AIM::SIZE"];

                    esp.DrawCircle(Color(255, 0, 0), FVector2D(screenWidth / 2, screenHeight / 2),
                                   Config["AIM_SIZE"], 2);
                }
                //      }



                //     g_LocalPlayer = localPlayer;
//        g_PlayerController = localController;
                ////     fps.update();
            }
        }


    }
}

#define TSL_FONT_DEFAULT_SIZE 20
static UFont *tslFont = nullptr, *robotoTinyFont = nullptr;

[[maybe_unused]] void *LoadFont(void *) {
    while (!tslFont || !robotoTinyFont) {
        tslFont = UObject::FindObject<UFont>("Font Roboto.Roboto"); // Font Roboto.Roboto
        robotoTinyFont = UObject::FindObject<UFont>("Font RobotoDistanceField.RobotoDistanceField");
        sleep(1);
    }
    return 0;
}



// Weapon change timing for skin application
std::chrono::steady_clock::time_point lastWeaponChangeTime;


void RenderESP(/*AHUD *HUD, *int SizeX, int SizeY*/) {

    ASTExtraPlayerCharacter *localPlayer = 0;
    ASTExtraPlayerController *localPlayerController = 0;

    updateSkin();
    //  SizeXx = SizeX;
    //  SizeYy = SizeY;
    UGameplayStatics *gGameplayStatics = (UGameplayStatics *) UGameplayStatics::StaticClass();
    UKismetMathLibrary *UMC = (UKismetMathLibrary *) UKismetMathLibrary::StaticClass();
    auto GWorld = GetWorld();
    if (GWorld) {
        UNetDriver *NetDriver = GWorld->NetDriver;
        if (NetDriver) {
            UNetConnection *ServerConnection = NetDriver->ServerConnection;
            if (ServerConnection) {
                localPlayerController = (ASTExtraPlayerController *) ServerConnection->PlayerController;
            }
        }


        if (localPlayerController) {
            std::vector<ASTExtraPlayerCharacter *> PlayerCharacter;
            GetAllActors(PlayerCharacter);

            for (auto actor = PlayerCharacter.begin(); actor != PlayerCharacter.end(); actor++) {
                auto Actor = *actor;
                if (Actor->PlayerKey ==
                    ((ASTExtraPlayerController *) localPlayerController)->PlayerKey) {
                    localPlayer = Actor;
                    break;
                }
            }
            if (localPlayer) {


                if (Config["SKIN_ENABLE"]) {
                    if (localPlayerController->BackpackComponent) {
                        auto data = localPlayerController->BackpackComponent->ItemListNet;
                        auto bag = data.IncArray;
                        for (int j = 0; j < bag.Num(); j++) {
                            int ID = bag[j].Unit.DefineID.TypeSpecificID;

                            for (int i = 0; i < sizeof(bag333) / sizeof(bag333[0]); i++) {
                                if (ID == bag333[i]) {
                                    bag[j].Unit.DefineID.TypeSpecificID = new_Skin.baglv3;
                                    break;
                                }
                            }

                            for (int i = 0; i < sizeof(Helmet3) / sizeof(Helmet3[0]); i++) {
                                if (ID == Helmet3[i]) {
                                    bag[j].Unit.DefineID.TypeSpecificID = new_Skin.helmetlv3;
                                    break;
                                }
                            }


                        }
                    }
                }



//if (Config.SkinEnable) {
                if (Config["SKIN_ENABLE"]) {
                    if (localPlayer && localPlayer->AvatarComponent2) {
                        auto AvatarComp = localPlayer->AvatarComponent2;
                        FNetAvatarSyncData NetAvatarComp = *(FNetAvatarSyncData *) (
                                (uintptr_t) AvatarComp + 0x388);

                        auto Slotsybc = NetAvatarComp.SlotSyncData;

                        // ===== ENHANCED ANTI-DETECTION X-SUIT APPLICATION =====
                        // Replace direct assignment with protected scrambling
                        int targetXSuitId = 0;
                        int targetMaskId = 0;

                        if (Config["SKIN_XSUIT"] == 1) {
                            targetXSuitId = 1405909; //Blood Raven X-Suit
                        } else if (Config["SKIN_XSUIT"] == 2) {
                            targetXSuitId = 1405628; //Golden Pharaoh X-Suit
                        } else if (Config["SKIN_XSUIT"] == 3) {
                            targetXSuitId = 1406152; //Avalanche X-suit
                        } else if (Config["SKIN_XSUIT"] == 4) {
                            targetXSuitId = 1406475; //Irresidence X-suit
                        } else if (Config["SKIN_XSUIT"] == 5) {
                            targetXSuitId = 1405983; //Poseidon X-suit
                        } else if (Config["SKIN_XSUIT"] == 6) {
                            targetXSuitId = 1406638; //Arcane Jester X-Suit
                        } else if (Config["SKIN_XSUIT"] == 7) {
                            targetXSuitId = 1406311; //Silvanus X-Suit
                        } else if (Config["SKIN_XSUIT"] == 8) {
                            targetXSuitId = 1406971;//Marmoris X-Suit
                        } else if (Config["SKIN_XSUIT"] == 9) {
                            targetXSuitId = 1407103; //Fiore X-Suit
                        } else if (Config["SKIN_XSUIT"] == 10) {
                            targetXSuitId = 1407259; // Ignis X-Suit
                        } else if (Config["SKIN_XSUIT"] == 11) {
                            targetXSuitId = 1406872; // Stygian Liege X-Suit
                            targetMaskId = 1403577; // Stygian Liege Mask
                        } else if (Config["SKIN_XSUIT"] == 12) {
                            targetXSuitId = 1407275; // Temperance's Virtue Set
                            targetMaskId = 1410646; // Temperance's Virtue Mask
                        } else if (Config["SKIN_XSUIT"] == 13) {
                            targetXSuitId = 1407276; // The Lover's Grace Set
                        }

                        // Apply with enhanced protection if valid ID
                        if (targetXSuitId > 0 && XSuitAntiDetection::isSafeToApply(targetXSuitId)) {
                            // Enhanced memory scrambling before application
                            if (!memoryProtection.isProtected) {
                                InitializeMemoryProtection();
                            }
                            ScrambleMemory(memoryProtection.scrambleKey.data(), memoryProtection.scrambleKey.size());

                            // Apply scrambled X-Suit ID
                            int scrambledXSuitId = XSuitAntiDetection::scrambleXSuitId(targetXSuitId);
                            Slotsybc[5].ItemId = scrambledXSuitId;

                            // Apply mask if present
                            if (targetMaskId > 0) {
                                int scrambledMaskId = XSuitAntiDetection::scrambleXSuitId(targetMaskId);
                                Slotsybc[4].ItemId = scrambledMaskId;
                            }

                            // Update tracking
                            auto now = std::chrono::duration_cast<std::chrono::milliseconds>(
                                std::chrono::steady_clock::now().time_since_epoch()).count();
                            XSuitAntiDetection::lastApplicationTimes[targetXSuitId] = now;
                            XSuitAntiDetection::applicationCounts[targetXSuitId]++;

                            LOGI("🛡️ Protected X-Suit Applied: %d -> %d", targetXSuitId, scrambledXSuitId);
                        }

///new
                        if (Config["SKIN_SET1"] == 1) {
                            Slotsybc[5].ItemId = 1400782;//Glacier Set
                        } else if (Config["SKIN_SET1"] == 2) {
                            Slotsybc[5].ItemId = 1400119;//Wanderer Outfit
                        } else if (Config["SKIN_SET1"] == 3) {
                            Slotsybc[5].ItemId = 1400117;//FireMan Set
                        } else if (Config["SKIN_SET1"] == 4) {
                            Slotsybc[5].ItemId = 1400693;//Vampire Set
                        } else if (Config["SKIN_SET1"] == 5) {
                            Slotsybc[5].ItemId = 1405092;//The Fool Set
                            Slotsybc[4].ItemId = 1403028;//The Fool Mask
                        } else if (Config["SKIN_SET1"] == 6) {
                            Slotsybc[5].ItemId = 1405090;//Smooth Hitman Set (Cat) {
                        } else if (Config["SKIN_SET1"] == 8) {
                            Slotsybc[5].ItemId = 1405482;//Anniversary Unicorn Set
                        } else if (Config["SKIN_SET1"] == 5) {
                            Slotsybc[5].ItemId = 1405583;//Dazzling Youth Set
                        } else if (Config["SKIN_SET1"] == 9) {
                            Slotsybc[5].ItemId = 1405593;//Red Commander Set
                        } else if (Config["SKIN_SET1"] == 10) {
                            Slotsybc[5].ItemId = 1405629;//Dark Widow Set
                        } else if (Config["SKIN_SET1"] == 11) {
                            Slotsybc[5].ItemId = 1405582;//Violet Halo Set
                        } else if (Config["SKIN_SET1"] == 12) {
                            Slotsybc[5].ItemId = 1405623; //Yellow Mummy
                        } else if (Config["SKIN_SET1"] == 13) {
                            Slotsybc[5].ItemId = 1400687; //White Mummy
                        } else if (Config["SKIN_SET1"] == 14) {
                            Slotsybc[5].ItemId = 1405102; //Golden Trigger
                        } else if (Config["SKIN_SET1"] == 15) {
                            Slotsybc[5].ItemId = 1405207; //Ryan Set
                        } else if (Config["SKIN_SET1"] == 16) {
                            Slotsybc[5].ItemId = 1406398; //Flamewraith Set
                        } else if (Config["SKIN_SET1"] == 17) {
                            Slotsybc[5].ItemId = 1406742; //Silver Guru - Set
                        } else if (Config["SKIN_SET1"] == 18) {
                            Slotsybc[5].ItemId = 1407225; //luminous Set
                        } else if (Config["SKIN_SET1"] == 19) {
                            Slotsybc[5].ItemId = 1407180; //
                        } else if (Config["SKIN_SET1"] == 20) {
                            Slotsybc[5].ItemId = 1407800; //
                        } else if (Config["SKIN_SET1"] == 21) {
                            Slotsybc[5].ItemId = 1407145; //
                        } else if (Config["SKIN_SET1"] == 22) {
                            Slotsybc[5].ItemId = 1407159; //
                        } else if (Config["SKIN_SET1"] == 23) {
                            Slotsybc[5].ItemId = 1407187; //
                        } else if (Config["SKIN_SET1"] == 24) {
                            Slotsybc[5].ItemId = 1407229; //
                        } else if (Config["SKIN_SET1"] == 25) {
                            Slotsybc[5].ItemId = 1407240; //
                        } else if (Config["SKIN_SET1"] == 26) {
                            Slotsybc[5].ItemId = 1407222; //
                        } else if (Config["SKIN_SET1"] == 27) {
                            Slotsybc[5].ItemId = 1407085; // Dream Striker Set
                        } else if (Config["SKIN_SET1"] == 28) {
                            Slotsybc[5].ItemId = 1406390; // Dream Striker Set
                        }


                        if (Config["SKIN_SET2"] == 1) {
                            Slotsybc[5].ItemId = 1407247; //
                        } else if (Config["SKIN_SET2"] == 2) {
                            Slotsybc[5].ItemId = 1407186; //
                        } else if (Config["SKIN_SET2"] == 3) {
                            Slotsybc[5].ItemId = 1407239; //
                        } else if (Config["SKIN_SET2"] == 4) {
                            Slotsybc[5].ItemId = 1407232; //
                        } else if (Config["SKIN_SET2"] == 5) {
                            Slotsybc[5].ItemId = 1407250; //
                        } else if (Config["SKIN_SET2"] == 6) {
                            Slotsybc[5].ItemId = 1416657; //
                        } else if (Config["SKIN_SET2"] == 7) {
                            Slotsybc[5].ItemId = 1406660; //
                        } else if (Config["SKIN_SET2"] == 8) {
                            Slotsybc[5].ItemId = 1405186; //
                        } else if (Config["SKIN_SET2"] == 9) {
                            Slotsybc[5].ItemId = 1405015; //
                        } else if (Config["SKIN_SET2"] == 10) {
                            Slotsybc[5].ItemId = 1407160; //
                        } else if (Config["SKIN_SET2"] == 11) {
                            Slotsybc[5].ItemId = 1407161; //
                        } else if (Config["SKIN_SET2"] == 12) {
                            Slotsybc[5].ItemId = 1400690; //
                        } else if (Config["SKIN_SET2"] == 13) {
                            Slotsybc[5].ItemId = 1405005; //
                        } else if (Config["SKIN_SET2"] == 14) {
                            Slotsybc[5].ItemId = 1400692; //
                        } else if (Config["SKIN_SET2"] == 15) {
                            Slotsybc[5].ItemId = 1400678; //
                        } else if (Config["SKIN_SET2"] == 16) {
                            Slotsybc[5].ItemId = 1406658; //
                        } else if (Config["SKIN_SET2"] == 17) {
                            Slotsybc[5].ItemId = 1405013; //
                        } else if (Config["SKIN_SET2"] == 18) {
                            Slotsybc[5].ItemId = 1405004; //
                        } else if (Config["SKIN_SET2"] == 19) {
                            Slotsybc[5].ItemId = 1400668; // Avant Garde Set
                        } else if (Config["SKIN_SET2"] == 20) {
                            Slotsybc[5].ItemId = 1406555; // Nether Visage Set
                        } else if (Config["SKIN_SET2"] == 21) {
                            Slotsybc[5].ItemId = 1406482; // Bramble Overlor
//Slotsybc[3].ItemId = 1402281; // Bramble Overlor
                        } else if (Config["SKIN_SET2"] == 22) {
                            Slotsybc[5].ItemId = 1406483; // Lightning Nebula
                        } else if (Config["SKIN_SET2"] == 23) {
                            Slotsybc[5].ItemId = 1407094; // Midnight Muse Set
                        } else if (Config["SKIN_SET2"] == 24) {
                            Slotsybc[5].ItemId = 1400268; // The Skulls
                        } else if (Config["SKIN_SET2"] == 25) {
                            Slotsybc[5].ItemId = 1407079; // The Fool's Delight Set
                        } else if (Config["SKIN_SET2"] == 26) {
                            Slotsybc[5].ItemId = 1406891; // Psychophage Set
                        } else if (Config["SKIN_SET2"] == 27) {
                            Slotsybc[5].ItemId = 1406154; // Draconic Paladin Set
                        } else if (Config["SKIN_SET2"] == 28) {
                            Slotsybc[5].ItemId = 1407107; // Winter Highness Set
                        }


                        if (Config["SKIN_TDMSET"] == 1) {//TDM
                            Slotsybc[5].ItemId = 1406673; //Sweet Bunny Set
                        } else if (Config["SKIN_TDMSET"] == 2) {
                            Slotsybc[5].ItemId = 1406728; //Bruce Lee Kung Fu set
                        } else if (Config["SKIN_TDMSET"] == 3) {
                            Slotsybc[5].ItemId = 1406817; //Sacred Maiden Set
                        } else if (Config["SKIN_TDMSET"] == 4) {
                            Slotsybc[5].ItemId = 1405132; //Forest Elf Set
                        } else if (Config["SKIN_TDMSET"] == 5) {
                            Slotsybc[5].ItemId = 1407151; // Line Friends LEONARD Raincoat Set
                        } else if (Config["SKIN_TDMSET"] == 6) {
                            Slotsybc[5].ItemId = 1407150; // LINE FRIENDS CHOCO Dress Set
                        } else if (Config["SKIN_TDMSET"] == 7) {
                            Slotsybc[5].ItemId = 1407484; //Sushi Fantasy Set
                        } else if (Config["SKIN_TDMSET"] == 8) {
                            Slotsybc[5].ItemId = 1404049; //BAPE X PUBGM CAMO Hoodie
                            Slotsybc[6].ItemId = 1404050; //BAPE X PUBGM CAMO Shorts
                            Slotsybc[7].ItemId = 1404051; //BAPE X PUBGM CAMO Shoes
                        } else if (Config["SKIN_TDMSET"] == 9) {
                            Slotsybc[5].ItemId = 1400569; // BAPE MIX CAMO HOODIE
                            Slotsybc[6].ItemId = 1400650; // BAPE MIX CAMO SHORTS
                            Slotsybc[7].ItemId = 1400651; // BAPE STA MID
                        } else if (Config["SKIN_TDMSET"] == 10) {
                            Slotsybc[5].ItemId = 1400324; // Urban Walker Top
                            Slotsybc[6].ItemId = 1404191; // Urban Walker Pants
                            Slotsybc[7].ItemId = 1404192; // Urban Walker Shoes
                        } else if (Config["SKIN_TDMSET"] == 11) {
                            Slotsybc[5].ItemId = 1405334; // Masked Psychic Robe set
                            Slotsybc[3].ItemId = 1402280; // Masked Psychic Hat
                        } else if (Config["SKIN_TDMSET"] == 12) {
                            Slotsybc[5].ItemId = 1407277; // Inferno Fiend Set
                        } else if (Config["SKIN_TDMSET"] == 13) {
                            Slotsybc[5].ItemId = 1407307; // Dark Arts Gentleman Set
                        } else if (Config["SKIN_TDMSET"] == 14) {
                            Slotsybc[5].ItemId = 1405749; // Leopard Suit Outfit
                        } else if (Config["SKIN_TDMSET"] == 15) {
                            Slotsybc[5].ItemId = 1404133; // Dark Gold Top
                            Slotsybc[4].ItemId = 1403660; // Shinobi Spirit mask
                            Slotsybc[6].ItemId = 1404137; // Glinting Dancer Pants
                        }


/////////////////////////////////////////////////////////////////??????


                        if (Config["SKIN_HELMET"] == 1)
                            Slotsybc[9].ItemId = 1502003028; //Scarlet Beast Helmet (Lv. 3)
                        if (Config["SKIN_HELMET"] == 2)
                            Slotsybc[9].ItemId = 1502003014; //Inferno Rider Helmet (Lv. 3)
                        if (Config["SKIN_HELMET"] == 3)
                            Slotsybc[9].ItemId = 1502003023; //Glacier Helmet (Lv. 3)
                        if (Config["SKIN_HELMET"] == 4)
                            Slotsybc[9].ItemId = 1502003065; //Moon Bunny Helmet (Lv. 3)
                        if (Config["SKIN_HELMET"] == 5)
                            Slotsybc[9].ItemId = 1502003031; //Mutated Helmet (Lv. 3)
                        if (Config["SKIN_HELMET"] == 6)
                            Slotsybc[9].ItemId = 1502003033; //Intergalactic Helmet (Lv. 3)
                        if (Config["SKIN_HELMET"] == 7)
                            Slotsybc[9].ItemId = 1502003069; //Masked Psychic Helmet (Lv. 3)
                        if (Config["SKIN_HELMET"] == 8)
                            Slotsybc[9].ItemId = 1502003261; //Atlantic Tech Helmet (Lv. 3)
                        if (Config["SKIN_HELMET"] == 9)
                            Slotsybc[9].ItemId = 1502003272; //Mystic Battle Helmet (Lv. 3)
                        if (Config["SKIN_HELMET"] == 10)
                            Slotsybc[9].ItemId = 1502003183; //Godzilla Helmet (Lv. 3)


                        if (Config["SKIN_BACKPACK"] == 1)
                            Slotsybc[8].ItemId = 1501003220; //Blood Raven Backpack (Lv. 3)
                        if (Config["SKIN_BACKPACK"] == 2)
                            Slotsybc[8].ItemId = 1501003174; //Pharaoh's Regalia Backpack (Lv. 3)
                        if (Config["SKIN_BACKPACK"] == 3)
                            Slotsybc[8].ItemId = 1501003051; //The Fool Backpack (Lv. 3)
                        if (Config["SKIN_BACKPACK"] == 4)
                            Slotsybc[8].ItemId = 1501003443; //Luminous Galaxy Backpack (Lv. 3)
                        if (Config["SKIN_BACKPACK"] == 5)
                            Slotsybc[8].ItemId = 1501003265; //Poseidon Backpack (Lv. 3)
                        if (Config["SKIN_BACKPACK"] == 6)
                            Slotsybc[8].ItemId = 1501003321; //Gackt Moonsaga Backpack(Lv. 3)
                        if (Config["SKIN_BACKPACK"] == 7)
                            Slotsybc[8].ItemId = 1501003277; //Godzilla Backpack (Lv. 3)
                        if (Config["SKIN_BACKPACK"] == 8)
                            Slotsybc[8].ItemId = 1501003550; //Frosty Snowglobe Backpack (Lv. 3)
                        if (Config["SKIN_BACKPACK"] == 9)
                            Slotsybc[8].ItemId = 1501003552; //Ebil Bunny Backpack (Lv. 3)
                        if (Config["SKIN_BACKPACK"] == 10)
                            Slotsybc[8].ItemId = 1501003061; //Godzilla Backpack (Lv. 3)
                        if (Config["SKIN_BACKPACK"] == 11)
                            Slotsybc[8].ItemId = 1501003058; //BAPE X PUBGM CAMO Backpack
                        if (Config["SKIN_BACKPACK"] == 12)
                            Slotsybc[8].ItemId = 1501003062; //King Ghidorah Backpack (Lv. 3)
                        if (Config["SKIN_BACKPACK"] == 13)
                            Slotsybc[8].ItemId = 1501003422; // Bramble Overlord Backpack (Lv. 3)
                        if (Config["SKIN_BACKPACK"] == 14)
                            Slotsybc[8].ItemId = 1501003503; // Bramble Overlord Backpack (Lv. 1)
                        if (Config["SKIN_BACKPACK"] == 15)
                            Slotsybc[8].ItemId = 1501003546; // Bramble Overlord Backpack (Lv. 1)
                        if (Config["SKIN_BACKPACK"] == 16)
                            Slotsybc[8].ItemId = 1501000558; // Shinobi Spirit Backpack



                        if (MainSuit != Slotsybc[5].ItemId) {
                            MainSuit = Slotsybc[5].ItemId;
                            localPlayer->AvatarComponent2->OnRep_BodySlotStateChanged();
                        }

                    }

                }


                if (Config["SKIN_ENABLE"]) {
                    if (localPlayer->WeaponManagerComponent != 0) {
                        if (localPlayer->WeaponManagerComponent->CurrentWeaponReplicated != 0) {
                            int weapowep = localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponID();
                            auto currentTime = std::chrono::steady_clock::now();
                            auto landchud = localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->synData;
                            auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(
                                    currentTime - lastWeaponChangeTime).count();
                            if (timeDiff > 1000) {
                                for (int j = 0; j < landchud.Num(); j++) {
                                    auto &weaponInfo = landchud[j];
                                    auto weaponid = weaponInfo.DefineID.TypeSpecificID;
                                    if (weaponid != 0) {


                                        if (weapowep == 101001) {
                                            for (int i = 0;
                                                 i < sizeof(akmv) / sizeof(akmv[0]); i++) {
                                                if (weaponid == akmv[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.AKM;
                                                    break;
                                                }
                                            }
                                            for (int i = 0;
                                                 i < sizeof(akmmag) / sizeof(akmmag[0]); i++) {
                                                if (weaponid == akmmag[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.AKM_Mag;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        if (weapowep == 103001) {
                                            for (int i = 0; i < sizeof(kar) / sizeof(kar[0]); i++) {
                                                if (weaponid == kar[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.K98;
                                                    break;
                                                }
                                            }
                                        }
                                        if (weapowep == 103002) {
                                            for (int i = 0; i < sizeof(m24) / sizeof(m24[0]); i++) {
                                                if (weaponid == m24[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M24;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        if (weapowep == 103003) {
                                            for (int i = 0; i < sizeof(awm) / sizeof(awm[0]); i++) {
                                                if (weaponid == awm[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.AWM;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                        if (weapowep == 103012) {
                                            for (int i = 0; i < sizeof(amr) / sizeof(amr[0]); i++) {
                                                if (weaponid == amr[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.AMR;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        if (weapowep == 103007) {
                                            for (int i = 0;
                                                 i < sizeof(mk14) / sizeof(mk14[0]); i++) {
                                                if (weaponid == mk14[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.MK14;
                                                    break;
                                                }
                                            }
                                        }

                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




                                        if (weapowep == 101102) {
                                            for (int i = 0;
                                                 i < sizeof(ace32) / sizeof(ace32[0]); i++) {
                                                if (weaponid == ace32[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.ACE32;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        if (weapowep == 102003) {
                                            for (int i = 0;
                                                 i < sizeof(vector2) / sizeof(vector2[0]); i++) {
                                                if (weaponid == vector2[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.Vector;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        if (weapowep == 102002) {
                                            for (int i = 0; i < sizeof(ump) / sizeof(ump[0]); i++) {
                                                if (weaponid == ump[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.UMP;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        if (weapowep == 102001) {
                                            for (int i = 0; i < sizeof(uzi) / sizeof(uzi[0]); i++) {
                                                if (weaponid == uzi[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.UZI;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        if (weapowep == 101002) {
                                            for (int i = 0; i < sizeof(m16) / sizeof(m16[0]); i++) {
                                                if (weaponid == m16[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4;
                                                    break;
                                                }
                                            }
                                            for (int i = 0;
                                                 i < sizeof(m16s) / sizeof(m16s[0]); i++) {
                                                if (weaponid == m16s[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4_Stock;
                                                    break;
                                                }
                                            }
                                            for (int i = 0;
                                                 i < sizeof(m16mag) / sizeof(m16mag[0]); i++) {
                                                if (weaponid == m16mag[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M16A4_Mag;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                        if (weapowep == 101006) {
                                            for (int i = 0; i < sizeof(aug) / sizeof(aug[0]); i++) {
                                                if (weaponid == aug[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.AUG;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        if (weapowep == 101005) {
                                            for (int i = 0;
                                                 i < sizeof(groza) / sizeof(groza[0]); i++) {
                                                if (weaponid == groza[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.Groza;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        if (weapowep == 105002) {
                                            for (int i = 0; i < sizeof(dp) / sizeof(dp[0]); i++) {
                                                if (weaponid == dp[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.DP28;
                                                    break;
                                                }
                                            }
                                        }
                                        if (weapowep == 105001) {
                                            for (int i = 0;
                                                 i < sizeof(m249) / sizeof(m249[0]); i++) {
                                                if (weaponid == m249[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M249;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                        if (weapowep == 105010) {
                                            for (int i = 0; i < sizeof(mg3) / sizeof(mg3[0]); i++) {
                                                if (weaponid == mg3[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.MG3;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




                                        if (weapowep == 101003) {
                                            for (int i = 0;
                                                 i < sizeof(scar) / sizeof(scar[0]); i++) {
                                                if (weaponid == scar[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.Scar;
                                                    break;
                                                }
                                            }
                                            for (int i = 0;
                                                 i < sizeof(scarmag) / sizeof(scarmag[0]); i++) {
                                                if (weaponid == scarmag[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.Scar_Mag;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        if (weapowep == 101008) {
                                            for (int i = 0; i < sizeof(m7) / sizeof(m7[0]); i++) {
                                                if (weaponid == m7[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M762;
                                                    break;
                                                }
                                            }
                                            for (int i = 0;
                                                 i < sizeof(m7mag) / sizeof(m7mag[0]); i++) {
                                                if (weaponid == m7mag[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M762_Mag;
                                                    break;
                                                }
                                            }
                                        }
                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                                        if (weapowep == 101004) {
                                            for (int i = 0;
                                                 i < sizeof(M4161) / sizeof(M4161[0]); i++) {
                                                if (weaponid == M4161[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_1;
                                                    break;
                                                }
                                            }

                                            for (int i = 0;
                                                 i < sizeof(M4162) / sizeof(M4162[0]); i++) {
                                                if (weaponid == M4162[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_2;
                                                    break;
                                                }
                                            }

                                            for (int i = 0;
                                                 i < sizeof(M4163) / sizeof(M4163[0]); i++) {
                                                if (weaponid == M4163[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_3;
                                                    break;
                                                }
                                            }

                                            for (int i = 0;
                                                 i < sizeof(m4stock) / sizeof(m4stock[0]); i++) {
                                                if (weaponid == m4stock[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_4;
                                                    break;
                                                }
                                            }

                                            for (int i = 0; i < sizeof(M416flash) /
                                                                sizeof(M416flash[0]); i++) {
                                                if (weaponid == M416flash[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_flash;
                                                    break;
                                                }
                                            }

                                            for (int i = 0; i < sizeof(M416compe) /
                                                                sizeof(M416compe[0]); i++) {
                                                if (weaponid == M416compe[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_compe;
                                                    break;
                                                }
                                            }

                                            for (int i = 0; i < sizeof(M416silent) /
                                                                sizeof(M416silent[0]); i++) {
                                                if (weaponid == M416silent[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_silent;
                                                    break;
                                                }
                                            }
                                            for (int i = 0;
                                                 i < sizeof(M416holo) / sizeof(M416holo[0]); i++) {
                                                if (weaponid == M416holo[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_holo;
                                                    break;
                                                }
                                            }

                                            for (int i = 0;
                                                 i < sizeof(M416x2) / sizeof(M416x2[0]); i++) {
                                                if (weaponid == M416x2[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x2;
                                                    break;
                                                }
                                            }

                                            for (int i = 0;
                                                 i < sizeof(M416x3) / sizeof(M416x3[0]); i++) {
                                                if (weaponid == M416x3[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x3;
                                                    break;
                                                }
                                            }

                                            for (int i = 0;
                                                 i < sizeof(M416x4) / sizeof(M416x4[0]); i++) {
                                                if (weaponid == M416x4[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x4;
                                                    break;
                                                }
                                            }

                                            for (int i = 0;
                                                 i < sizeof(M416x6) / sizeof(M416x6[0]); i++) {
                                                if (weaponid == M416x6[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_x6;
                                                    break;
                                                }
                                            }

                                            for (int i = 0; i < sizeof(M416quickMag) /
                                                                sizeof(M416quickMag[0]); i++) {
                                                if (weaponid == M416quickMag[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_quickMag;
                                                    break;
                                                }
                                            }

                                            for (int i = 0; i < sizeof(M416extendedMag) /
                                                                sizeof(M416extendedMag[0]); i++) {
                                                if (weaponid == M416extendedMag[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_extendedMag;
                                                    break;
                                                }
                                            }

                                            for (int i = 0; i < sizeof(M416quickNextended) /
                                                                sizeof(M416quickNextended[0]); i++) {
                                                if (weaponid == M416quickNextended[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_quickNextended;
                                                    break;
                                                }
                                            }

                                            for (int i = 0; i < sizeof(M416stock) /
                                                                sizeof(M416stock[0]); i++) {
                                                if (weaponid == M416stock[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_stock;
                                                    break;
                                                }
                                            }

                                            for (int i = 0; i < sizeof(M416angle) /
                                                                sizeof(M416angle[0]); i++) {
                                                if (weaponid == M416angle[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_angle;
                                                    break;
                                                }
                                            }

                                            for (int i = 0; i < sizeof(M416thumb) /
                                                                sizeof(M416thumb[0]); i++) {
                                                if (weaponid == M416thumb[i]) {
                                                    weaponInfo.DefineID.TypeSpecificID = new_Skin.M416_thumb;
                                                    break;
                                                }
                                            }
                                        }

                                        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                                    }
                                    localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->DelayHandleAvatarMeshChanged();
                                    lastWeaponChangeTime = currentTime;
                                }
                            }
                        }
                    }
                }
              

                if (Config["MEMORY_WIDEVIEW"]) {
                    localPlayer->ThirdPersonCameraComponent->SetFieldOfView(110);
                }

                if (localPlayer->PartHitComponent) {
                    auto ConfigCollisionDistSqAngles = localPlayer->PartHitComponent->ConfigCollisionDistSqAngles;
                    for (int j = 0; j < ConfigCollisionDistSqAngles.Num(); j++) {
                        ConfigCollisionDistSqAngles[j].Angle = 120.0f;//120
                    }
                    localPlayer->PartHitComponent->ConfigCollisionDistSqAngles = ConfigCollisionDistSqAngles;
                }
              
                if (Config["NRG_AIMBOT"]) {
                    if (Config["AIM_MOD1"]) {
                        ASTExtraPlayerCharacter *Target = GetTargetByCrosshairDistance();


                        if (Target) {
                            bool triggerOk = false;
                            if (Config["AIM::TRIGGER1"]) {
                                triggerOk = g_LocalPlayer->bIsWeaponFiring;
                            } else if (Config["AIM::TRIGGER2"]) {
                                triggerOk = g_LocalPlayer->bIsGunADS;
                            } else if (Config["AIM::TRIGGER3"]) {
                                triggerOk =
                                        g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;

                            } else triggerOk = true;
                            if (triggerOk) {
                                FVector targetAimPos = Target->GetBonePos("Head", {});


                                if (Config["RECOI_LCOMPARISON"]) {
                                    if (localPlayer->bIsGunADS) {
                                        if (localPlayer->bIsWeaponFiring) {
                                            float dist = localPlayer->GetDistanceTo(Target) / 100.f;
                                            targetAimPos.Z -=
                                                    dist * (float) Config["RECOIL_SIZE"] * 0.1f; //
                                        }
                                    }
                                }


                                auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                                if (WeaponManagerComponent) {
                                    auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                                    if ((int) propSlot.GetValue() >= 1 &&
                                        (int) propSlot.GetValue() <= 3) {
                                        auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                                        if (CurrentWeaponReplicated) {
                                            auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                            if (ShootWeaponComponent) {
                                                UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
                                                if (ShootWeaponEntityComponent) {
                                                    ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                                                    if (CurrentVehicle) {
                                                        FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;

                                                        float dist = localPlayer->GetDistanceTo(
                                                                Target);
                                                        auto timeToTravel = dist /
                                                                            ShootWeaponEntityComponent->BulletFireSpeed;
                                                        targetAimPos = UMC->Add_VectorVector(
                                                                targetAimPos,
                                                                UMC->Multiply_VectorFloat(
                                                                        LinearVelocity,
                                                                        timeToTravel));
                                                    } else {
                                                        FVector Velocity = Target->GetVelocity();
                                                        float dist = localPlayer->GetDistanceTo(
                                                                Target);
                                                        auto timeToTravel = dist /
                                                                            ShootWeaponEntityComponent->BulletFireSpeed;
                                                        targetAimPos = UMC->Add_VectorVector(
                                                                targetAimPos,
                                                                UMC->Multiply_VectorFloat(Velocity,
                                                                                          timeToTravel));
                                                    }

                                                    
                                                    localPlayerController->ClientSetLocation(
                                                            localPlayer->K2_GetActorLocation(),
                                                            ToRotator(
                                                                    localPlayerController->PlayerCameraManager->CameraCache.POV.Location,
                                                                    targetAimPos));


                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

            }


            //   }
        }
    }

    g_LocalPlayer = localPlayer;
    g_PlayerController = localPlayerController;
    //}
}


/*

timer worldAutoSleep;
void *FPS_thread(void *) {

    worldAutoSleep.SetFps(120);
    worldAutoSleep.AutoFPS_init(0);
    for (;;)
    {

        worldAutoSleep.AutoFPS();
    }
}
*/
void *maps_thread(void *) {
    while (true) {
        auto t1 = std::chrono::steady_clock::now();
/*
sleep(15);
    bScanPatternCompleted = true;
   */

        std::vector<sRegion> tmp;
        FILE *f = fopen("/proc/self/maps", "r");
        if (f) {
            char line[512];
            while (fgets(line, sizeof line, f)) {
                uintptr_t start, end;
                char tmpProt[16];
                if (sscanf(line, "%" PRIXPTR "-%" PRIXPTR " %16s %*s %*s %*s %*s", &start, &end,
                           tmpProt) > 0) {
                    if (tmpProt[0] != 'r') {
                        tmp.push_back({start, end});
                    }
                }
            }
            fclose(f);
        }

        trapRegions = std::move(tmp); // Move assignment
        auto td = std::chrono::steady_clock::now() - t1;
        std::chrono::milliseconds sleep_time = std::chrono::milliseconds(
                std::max(0LL, -std::chrono::duration_cast<std::chrono::milliseconds>(td).count()));
        std::this_thread::sleep_for(sleep_time);
    }
}


void *MemoryThread(void *) {
    while (bValid) {
        auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count();

        if (!g_Token.empty()) {
            if (!g_Auth.empty()) {
                if (g_Token == g_Auth) {


                    auto localPlayer = g_LocalPlayer;
                    auto localController = g_PlayerController;
                    if (localPlayer && localController) {
  

                        float PlayView;

                        PlayView = Config["MEMORY::WIDEVIEWSIZE"];

                        if (Config["MEMORY::WIDEVIEW"]) {
                            localPlayer->ThirdPersonCameraComponent->SetFieldOfView(110);
                        }

                    }

                }
                // }
            }
        }
        auto td = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count() - t1;
        std::this_thread::sleep_for(
                std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
    }
    return 0;
}

int glWidth, glHeight;


// ===== ENHANCED ESP ANTI-DETECTION SYSTEM =====

struct ESPAntiDetectionState {
    static std::random_device rd;
    static std::mt19937 gen;
    static std::map<std::string, uint64_t> lastDrawTimes;
    static std::map<std::string, int> drawCounts;
    static bool isRecordingDetected;
    static uint64_t lastAntiDetectionCheck;
    static const uint64_t ANTI_DETECTION_INTERVAL = 100; // Check every 100ms

    // Enhanced rendering parameters
    static float colorVariationFactor;
    static float positionJitterFactor;
    static int dynamicFrameRate;
    static bool useRandomizedShapes;

    // Check if ESP rendering should proceed
    static bool shouldRenderESP() {
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count();

        // Periodic anti-detection check
        if (now - lastAntiDetectionCheck > ANTI_DETECTION_INTERVAL) {
            // Update dynamic parameters
            colorVariationFactor = 0.05f + (gen() % 100) / 1000.0f; // 0.05-0.15
            positionJitterFactor = 0.3f + (gen() % 70) / 100.0f; // 0.3-1.0
            dynamicFrameRate = 45 + (gen() % 30); // 45-75 FPS

            lastAntiDetectionCheck = now;
        }

        // Check recording protection
        if (isRecordingDetected) {
            return false;
        }

        // Dynamic frame rate limiting
        static uint64_t lastFrameTime = 0;
        uint64_t targetFrameTime = 1000 / dynamicFrameRate;
        uint64_t jitter = gen() % 10; // 0-10ms jitter

        if (now - lastFrameTime < targetFrameTime + jitter) {
            return false;
        }

        lastFrameTime = now;
        return true;
    }

    // Apply color scrambling
    static int scrambleColor(int originalColor) {
        if (!memoryProtection.isProtected) {
            InitializeMemoryProtection();
        }

        // Extract color components
        int alpha = (originalColor >> 24) & 0xFF;
        int red = (originalColor >> 16) & 0xFF;
        int green = (originalColor >> 8) & 0xFF;
        int blue = originalColor & 0xFF;

        // Apply controlled variation
        int variation = (int)(255 * colorVariationFactor);
        red = std::max(0, std::min(255, red + (int)(gen() % (variation * 2)) - variation));
        green = std::max(0, std::min(255, green + (int)(gen() % (variation * 2)) - variation));
        blue = std::max(0, std::min(255, blue + (int)(gen() % (variation * 2)) - variation));

        return (alpha << 24) | (red << 16) | (green << 8) | blue;
    }

    // Apply position jitter
    static FVector2D scramblePosition(FVector2D original) {
        float jitterRange = positionJitterFactor;
        float jitterX = ((gen() % 1000) / 1000.0f - 0.5f) * 2 * jitterRange;
        float jitterY = ((gen() % 1000) / 1000.0f - 0.5f) * 2 * jitterRange;

        return FVector2D(original.X + jitterX, original.Y + jitterY);
    }
};

// Static member definitions
std::random_device ESPAntiDetectionState::rd;
std::mt19937 ESPAntiDetectionState::gen(ESPAntiDetectionState::rd());
std::map<std::string, uint64_t> ESPAntiDetectionState::lastDrawTimes;
std::map<std::string, int> ESPAntiDetectionState::drawCounts;
bool ESPAntiDetectionState::isRecordingDetected = false;
uint64_t ESPAntiDetectionState::lastAntiDetectionCheck = 0;
float ESPAntiDetectionState::colorVariationFactor = 0.1f;
float ESPAntiDetectionState::positionJitterFactor = 0.5f;
int ESPAntiDetectionState::dynamicFrameRate = 60;
bool ESPAntiDetectionState::useRandomizedShapes = true;

extern "C"
JNIEXPORT void JNICALL
Java_com_bearmod_Floating_DrawOn(JNIEnv *env, jclass type, jobject espView, jobject canvas) {
    try {
        // Enhanced anti-detection check
        if (!ESPAntiDetectionState::shouldRenderESP()) {
            return; // Skip rendering for anti-detection
        }

        // Enhanced memory scrambling before ESP operations
        if (memoryProtection.isProtected) {
            ScrambleMemory(memoryProtection.scrambleKey.data(), memoryProtection.scrambleKey.size());
        }

        espOverlay = ESP(env, espView, canvas);

        if (espOverlay.isValid()) {
            // Apply enhanced ESP rendering with anti-detection
            DrawESP(espOverlay, espOverlay.getWidth(), espOverlay.getHeight());
        }

    } catch (...) {
        // Graceful error handling to prevent crashes
        LOGE("[-] Error in enhanced ESP rendering");
    }
}

void *(*oProcessEvent)(UObject *pObj, UFunction *pFunc, void *pArgs);
void *hkProcessEvent(UObject *pObj, UFunction *pFunc, void *pArgs) {
    if (pFunc) {


        if (Config["SKIN_ENABLE"]) {


            if (g_PlayerController == 0) {
                //LOGO

            } else {
                //ISLAND

                if (pFunc) {
                    if (pFunc->GetFullName() ==
                        "Function ShadowTrackerExtra.STExtraPlayerController.BroadcastFatalDamageToClientWithStruct") {
                        auto *pController = (ASTExtraPlayerController *) pObj;
                        if (pController) {
                            auto Params = (ASTExtraPlayerController_BroadcastFatalDamageToClientWithStruct_Params *) pArgs;
                            if (Params) {
                                auto GWorld = GetWorld();
                                if (GWorld) {
                                    if (GWorld->NetDriver->ServerConnection)
                                        if (GWorld->NetDriver->ServerConnection->PlayerController) {
                                            auto *localController = (ASTExtraPlayerController *) GWorld->NetDriver->ServerConnection->PlayerController;
                                            auto *localPlayer = (ASTExtraPlayerCharacter *) localController->AcknowledgedPawn;
                                            if (localController->PlayerKey ==
                                                Params->FatalDamageParameter.CauserKey &&
                                                !localController->STExtraBaseCharacter->CurrentVehicle &&
                                                localPlayer->WeaponManagerComponent->CurrentWeaponReplicated) {
                                                int weapowep = localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponID();

                                                // ===== ENHANCED KILL FEED X-SUIT PROTECTION =====
                                                int killFeedXSuitId = 0;

                                                // ===== ENHANCED X-SUIT KILL FEED MAPPING =====
                                                if (Config["SKIN_XSUIT"] == 1) {
                                                    killFeedXSuitId = 1405909; //Blood Raven X-Suit
                                                } else if (Config["SKIN_XSUIT"] == 2) {
                                                    killFeedXSuitId = 1405628; //Golden Pharaoh X-Suit
                                                } else if (Config["SKIN_XSUIT"] == 3) {
                                                    killFeedXSuitId = 1406152; //Avalanche X-suit
                                                } else if (Config["SKIN_XSUIT"] == 4) {
                                                    killFeedXSuitId = 1406475; //Irresidence X-suit
                                                } else if (Config["SKIN_XSUIT"] == 5) {
                                                    killFeedXSuitId = 1405983; //Poseidon X-suit
                                                } else if (Config["SKIN_XSUIT"] == 6) {
                                                    killFeedXSuitId = 1406638; //Arcane Jester X-Suit
                                                } else if (Config["SKIN_XSUIT"] == 7) {
                                                    killFeedXSuitId = 1406311; //Silvanus X-Suit
                                                } else if (Config["SKIN_XSUIT"] == 8) {
                                                    killFeedXSuitId = 1406971; //Marmoris X-Suit
                                                } else if (Config["SKIN_XSUIT"] == 9) {
                                                    killFeedXSuitId = 1407103; //Fiore X-Suit
                                                } else if (Config["SKIN_XSUIT"] == 10) {
                                                    killFeedXSuitId = 1407259; //Ignis X-Suit
                                                } else if (Config["SKIN_XSUIT"] == 11) {
                                                    killFeedXSuitId = 1406872; //Stygian Liege X-Suit
                                                } else if (Config["SKIN_XSUIT"] == 12) {
                                                    killFeedXSuitId = 1407275; //Temperance's Virtue X-Suit
                                                } else if (Config["SKIN_XSUIT"] == 13) {
                                                    killFeedXSuitId = 1407276; //The Lover's Grace X-Suit
                                                }

                                                // Apply scrambled X-Suit ID to kill feed
                                                if (killFeedXSuitId > 0) {
                                                    // Enhanced memory protection for kill feed
                                                    ScrambleMemory(memoryProtection.scrambleKey.data(), memoryProtection.scrambleKey.size());

                                                    // Apply scrambled ID to prevent detection
                                                    int scrambledKillFeedId = XSuitAntiDetection::scrambleXSuitId(killFeedXSuitId);
                                                    Params->FatalDamageParameter.CauserClothAvatarID = scrambledKillFeedId;

                                                    LOGI("🎯 Protected Kill Feed X-Suit: %d -> %d", killFeedXSuitId, scrambledKillFeedId);
                                                }



                                                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 101001) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.AKM;
                                                }
                                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 103001) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.K98;
                                                }
                                                if (weapowep == 103002) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M24;
                                                }
                                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 103003) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.AWM;
                                                }
                                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 103012) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.AMR;
                                                }
                                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 103007) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.MK14;
                                                }
                                                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 103006) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.Mini14;
                                                }
                                                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 101102) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.ACE32;
                                                }
                                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 102003) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.Vector;
                                                }
                                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 102002) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.UMP;
                                                }
                                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 102001) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.UZI;
                                                }
                                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 101002) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M16A4;
                                                }
                                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                if (weapowep == 101006) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.AUG;
                                                }
                                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 101005) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.Groza;
                                                }
                                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 105002) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.DP28;
                                                }
                                                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 105001) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M249;
                                                }
                                                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 105010) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.MG3;
                                                }
                                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 101003) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.Scar;
                                                }
                                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 101008) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M762;
                                                }
                                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                if (weapowep == 101004) {
                                                    Params->FatalDamageParameter.CauserWeaponAvatarID = new_Skin.M416_1;
                                                }
                                                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                            }
                                        }
                                }
                            }
                        }
                    }
                }
            }


            if (g_PlayerController == 0) {
                //LOGO

            } else {
                //ISLAND

                if (Config["GUN_BOX"]) {
                    if (std::string(pObj->GetName().c_str()).find("DeadBoxAvatarComponent") !=
                        std::string::npos) {
                        auto DeadBoxPointer = (UDeadBoxAvatarComponent *) pObj;

                        auto *localPlayer = (ASTExtraPlayerCharacter *) g_PlayerController->AcknowledgedPawn;
                        if (std::string(pFunc->GetFullName().c_str()).find("GetLuaFilePath") !=
                            std::string::npos) {
                            if (g_PlayerController->PlayerKey &&
                                !g_PlayerController->STExtraBaseCharacter->CurrentVehicle &&
                                localPlayer->WeaponManagerComponent->CurrentWeaponReplicated) {

                                int weapowep = localPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponID();


                                if (DeadBoxPointer)

                                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                    if (weapowep == 101001) {
                                        DeadBoxPointer->ChangeItemAvatar(new_Skin.AKM, true);
                                    }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 103001) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.K98, true);
                                }
                                if (weapowep == 103002) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.M24, true);
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 103003) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.AWM, true);
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 103012) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.AMR, true);
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 103007) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.MK14, true);
                                }
                                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 103006) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.Mini14, true);
                                }
                                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 101102) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.ACE32, true);
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 102003) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.Vector, true);
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 102002) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.UMP, true);
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 102001) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.UZI, true);
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 102004) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.Thompson, true);
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 101002) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.M16A4, true);
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                if (weapowep == 101006) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.AUG, true);
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 101005) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.Groza, true);
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 105002) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.DP28, true);
                                }
                                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 105001) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.M249, true);
                                }
                                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 105010) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.MG3, true);
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 101003) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.Scar, true);
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 101008) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.M762, true);
                                }
                                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (weapowep == 101004) {
                                    DeadBoxPointer->ChangeItemAvatar(new_Skin.M416_1, true);
                                }
                                //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                            }
                        }
                    }
                }
            }
        }


        if (pFunc->GetFullName() == "Function Engine.HUD.ReceiveDrawHUD") {
            /*
            AHUD *pHUD = (AHUD *)pObj;
            if (pHUD)
            {
                */
            RenderESP();
            //    auto Params = (AHUD_ReceiveDrawHUD_Params *)pArgs;
            //   if (Params)
            //   {
            //      RenderESP(/*pHUD, */Params->SizeX, Params->SizeY);

            //   }
            //  }
        }
    }
    return oProcessEvent(pObj, pFunc, pArgs);
}

__int64_t __fastcall (*osub_5F60864)(__int64_t result, float a2);
__int64_t __fastcall sub_5F60864(__int64_t result, float a2)
{
    auto Upload = (UBulletHitInfoUploadComponent*)result;
    Upload->bEnableTssSdkAntiData = false;
    Upload->bEnableTssSdkAntiDataFilter = false;
    Upload->bEnableTssSdkAntiDataFilterNew = false;
    Upload->bDisableDsTick = true;
    Upload->bDisableDsAntiDataReport = true;
    Upload->bEnableAddSPCShootData = false;
    Upload->NeedSendSimpleCharacterHitData = false;
    return osub_5F60864(result, a2);
}


void *Init_Thread(void *) {
    while (!UE4) {
        UE4 = getModuleBase("libUE4.so");
//UE4 = GetModuleBase("libUE4.so");
        sleep(1);
    }


    LOGI("libUE4.so: %lu", UE4);
    FName::GNames = GetGNames();
    while (!FName::GNames) {
        FName::GNames = GetGNames();
        sleep(1);
    }


    Tools::Hook((void *) (UE4 + 0x5F60864), (void *) sub_5F60864, (void **) &osub_5F60864);
    Tools::Hook((void *) (UE4 + Process_Event_Offset), (void *) hkProcessEvent,
                (void **) &oProcessEvent);
    UObject::GUObjectArray = (FUObjectArray *) (UE4 + GUObject_Offset);

    Config["MEMORY_WIDEVIEWSIZE"] = 80;
    Config["AIM_SPEED"] = 10;
    Config["RADAR_SIZE"] = 60;
    Config["SKIN_SUIT"] = 0;
    bScanPatternCompleted = true;
///////////////
    items_data = json::parse(JSON_ITEMS222);
    pthread_t t;
//pthread_create(&t, 0, maps_thread, 0);

    return 0;
}


const char *GetAndroidID(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass(/*android/content/Context*/
            StrEnc("`L+&0^[S+-:J^$,r9q92(as",
                   "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07",
                   23).c_str());
    jmethodID getContentResolverMethod = env->GetMethodID(contextClass, /*getContentResolver*/
                                                          StrEnc("E8X\\7r7ys_Q%JS+L+~",
                                                                 "\x22\x5D\x2C\x1F\x58\x1C\x43\x1C\x1D\x2B\x03\x40\x39\x3C\x47\x3A\x4E\x0C",
                                                                 18).c_str(), /*()Landroid/content/ContentResolver;*/
                                                          StrEnc("8^QKmj< }5D:9q7f.BXkef]A*GYLNg}B!/L",
                                                                 "\x10\x77\x1D\x2A\x03\x0E\x4E\x4F\x14\x51\x6B\x59\x56\x1F\x43\x03\x40\x36\x77\x28\x0A\x08\x29\x24\x44\x33\x0B\x29\x3D\x08\x11\x34\x44\x5D\x77",
                                                                 35).c_str());
    jclass settingSecureClass = env->FindClass(/*android/provider/Settings$Secure*/
            StrEnc("T1yw^BCF^af&dB_@Raf}\\FS,zT~L(3Z\"",
                   "\x35\x5F\x1D\x05\x31\x2B\x27\x69\x2E\x13\x09\x50\x0D\x26\x3A\x32\x7D\x32\x03\x09\x28\x2F\x3D\x4B\x09\x70\x2D\x29\x4B\x46\x28\x47",
                   32).c_str());
    jmethodID getStringMethod = env->GetStaticMethodID(settingSecureClass, /*getString*/
                                                       StrEnc("e<F*J5c0Y",
                                                              "\x02\x59\x32\x79\x3E\x47\x0A\x5E\x3E",
                                                              9).c_str(), /*(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;*/
                                                       StrEnc("$6*%R*!XO\"m18o,0S!*`uI$IW)l_/_knSdlRiO1T`2sH|Ouy__^}%Y)JsQ:-\"(2_^-$i{?H",
                                                              "\x0C\x7A\x4B\x4B\x36\x58\x4E\x31\x2B\x0D\x0E\x5E\x56\x1B\x49\x5E\x27\x0E\x69\x0F\x1B\x3D\x41\x27\x23\x7B\x09\x2C\x40\x33\x1D\x0B\x21\x5F\x20\x38\x08\x39\x50\x7B\x0C\x53\x1D\x2F\x53\x1C\x01\x0B\x36\x31\x39\x46\x0C\x15\x43\x2B\x05\x30\x15\x41\x43\x46\x55\x70\x0D\x59\x56\x00\x15\x58\x73",
                                                              71).c_str());
    auto obj = env->CallObjectMethod(context, getContentResolverMethod);
    auto str = (jstring) env->CallStaticObjectMethod(settingSecureClass, getStringMethod, obj,
                                                     env->NewStringUTF(/*android_id*/
                                                             StrEnc("ujHO)8OfOE",
                                                                    "\x14\x04\x2C\x3D\x46\x51\x2B\x39\x26\x21",
                                                                    10).c_str()));
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceModel(JNIEnv *env) {
    jclass buildClass = env->FindClass(/*android/os/Build*/StrEnc("m5I{GKGWBP-VOxkA",
                                                                  "\x0C\x5B\x2D\x09\x28\x22\x23\x78\x2D\x23\x02\x14\x3A\x11\x07\x25",
                                                                  16).c_str());
    jfieldID modelId = env->GetStaticFieldID(buildClass, /*MODEL*/
                                             StrEnc("|}[q:", "\x31\x32\x1F\x34\x76",
                                                    5).c_str(), /*Ljava/lang/String;*/
                                             StrEnc(".D:C:ETZ1O-Ib&^h.Y",
                                                    "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62",
                                                    18).c_str());
    auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceBrand(JNIEnv *env) {
    jclass buildClass = env->FindClass(/*android/os/Build*/StrEnc("0iW=2^>0zTRB!B90",
                                                                  "\x51\x07\x33\x4F\x5D\x37\x5A\x1F\x15\x27\x7D\x00\x54\x2B\x55\x54",
                                                                  16).c_str());
    jfieldID modelId = env->GetStaticFieldID(buildClass, /*BRAND*/
                                             StrEnc("@{[FP", "\x02\x29\x1A\x08\x14",
                                                    5).c_str(), /*Ljava/lang/String;*/
                                             StrEnc(".D:C:ETZ1O-Ib&^h.Y",
                                                    "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62",
                                                    18).c_str());
    auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetPackageName(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass(/*android/content/Context*/
            StrEnc("`L+&0^[S+-:J^$,r9q92(as",
                   "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07",
                   23).c_str());
    jmethodID getPackageNameId = env->GetMethodID(contextClass, /*getPackageName*/
                                                  StrEnc("YN4DaP)!{wRGN}",
                                                         "\x3E\x2B\x40\x14\x00\x33\x42\x40\x1C\x12\x1C\x26\x23\x18",
                                                         14).c_str(), /*()Ljava/lang/String;*/
                                                  StrEnc("VnpibEspM(b]<s#[9cQD",
                                                         "\x7E\x47\x3C\x03\x03\x33\x12\x5F\x21\x49\x0C\x3A\x13\x20\x57\x29\x50\x0D\x36\x7F",
                                                         20).c_str());
    auto str = (jstring) env->CallObjectMethod(context, getPackageNameId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceUniqueIdentifier(JNIEnv *env, const char *uuid) {
    jclass uuidClass = env->FindClass(/*java/util/UUID*/
            StrEnc("B/TxJ=3BZ_]SFx", "\x28\x4E\x22\x19\x65\x48\x47\x2B\x36\x70\x08\x06\x0F\x3C",
                   14).c_str());
    auto len = strlen(uuid);
    jbyteArray myJByteArray = env->NewByteArray(len);
    env->SetByteArrayRegion(myJByteArray, 0, len, (jbyte *) uuid);
    jmethodID nameUUIDFromBytesMethod = env->GetStaticMethodID(uuidClass, /*nameUUIDFromBytes*/
                                                               StrEnc("P6LV|'0#A+zQmoat,",
                                                                      "\x3E\x57\x21\x33\x29\x72\x79\x67\x07\x59\x15\x3C\x2F\x16\x15\x11\x5F",
                                                                      17).c_str(), /*([B)Ljava/util/UUID;*/
                                                               StrEnc("sW[\"Q[W3,7@H.vT0) xB",
                                                                      "\x5B\x0C\x19\x0B\x1D\x31\x36\x45\x4D\x18\x35\x3C\x47\x1A\x7B\x65\x7C\x69\x3C\x79",
                                                                      20).c_str());
    jmethodID toStringMethod = env->GetMethodID(uuidClass, /*toString*/StrEnc("2~5292eW",
                                                                              "\x46\x11\x66\x46\x4B\x5B\x0B\x30",
                                                                              8).c_str(), /*()Ljava/lang/String;*/
                                                StrEnc("P$BMc' #j?<:myTh_*h0",
                                                       "\x78\x0D\x0E\x27\x02\x51\x41\x0C\x06\x5E\x52\x5D\x42\x2A\x20\x1A\x36\x44\x0F\x0B",
                                                       20).c_str());
    auto obj = env->CallStaticObjectMethod(uuidClass, nameUUIDFromBytesMethod, myJByteArray);
    auto str = (jstring) env->CallObjectMethod(obj, toStringMethod);
    return env->GetStringUTFChars(str, 0);
}

#include <curl/curl.h>

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;
    mem->memory = (char *) realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        return 0;
    }
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}


void native_Init(JNIEnv *env, jclass clazz, jobject mContext) {
    auto pkgName = GetPackageName(env, mContext);
    // StartRuntimeHook(pkgName);
    //    pthread_t t;
    //pthread_create(&t, 0, Init_Thread, 0);
}

jstring native_Check(JNIEnv *env, jclass clazz, jobject mContext, jstring mUserKey) {
    auto userKey = env->GetStringUTFChars(mUserKey, 0);
    std::string hwid = userKey;
    hwid += GetAndroidID(env, mContext);
    hwid += GetDeviceModel(env);
    hwid += GetDeviceBrand(env);
    std::string UUID = GetDeviceUniqueIdentifier(env, hwid.c_str());

    std::string errMsg;
    struct MemoryStruct chunk{};
    chunk.memory = (char *) malloc(1);
    chunk.size = 0;
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, _enc_("POST"));
        curl_easy_setopt(curl, CURLOPT_URL, _enc_("https://api.mod-key.click/BearUser/connect"));

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, _enc_("https"));

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers,
                                    _enc_("Content-Type: application/x-www-form-urlencoded"));
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        char data[4096];
        sprintf(data, _enc_("game=PUBG&user_key=%s&serial=%s"), userKey, UUID.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json result = json::parse(chunk.memory);
                if (result[("status")] == 5700) {
                    std::string token = result[("data")][("token")].get<std::string>();
                    auto rng = result[("data")][("rng")].get<time_t>();
                    if (rng + 30 > time(0)) {
                        std::string auth = enc("PUBG");
                        auth += "-";
                        auth += userKey;
                        auth += "-";
                        auth += UUID;
                        auth += "-";
                        auth += enc("555396e7422dacedc7c4057dd984d99c");
                        std::string outputAuth = Tools::CalcMD5(auth);
                        g_Token = token;
                        g_Auth = outputAuth;
                        EXP = result["data"]["EXP"];
                        bValid = g_Token == g_Auth;

                    }
                } else {
                    errMsg = result[("reason")].get<std::string>();
                }
            } catch (json::exception &e) {
                errMsg = e.what();
            }
        } else {
            errMsg = curl_easy_strerror(res);
        }
    }
    curl_easy_cleanup(curl);
    return bValid ? env->NewStringUTF("OK") : env->NewStringUTF(errMsg.c_str());

}


extern "C"
JNIEXPORT void JNICALL
Java_com_bearmod_Floating_Switch(JNIEnv *env, jobject thiz, jint i) {
    // TODO: implement Switch()
}

// Enhanced JNI function with validation and fallback support
extern "C"
JNIEXPORT void JNICALL
Java_com_bearmod_SkinManager_updateSkinValue(JNIEnv *env, jclass clazz, jstring key, jint value) {
    if (!key) return; // Safety check
    
    const char *skinKey = env->GetStringUTFChars(key, 0);
    if (!skinKey) return; // Safety check
    
    // Validate skin ID is reasonable (basic range check)
    bool isValidSkin = (value >= 1100000000 && value <= 1999999999) || value == 0;
    
    // Direct mapping with validation and fallback
    if (strcmp(skinKey, "M416") == 0) {
        new_Skin.M416_1 = isValidSkin ? value : 1101004003; // Fallback to default
    }
    else if (strcmp(skinKey, "AKM") == 0) {
        new_Skin.AKM = isValidSkin ? value : 1101001003; // Fallback to default
    }
    else if (strcmp(skinKey, "SCAR") == 0) {
        new_Skin.Scar = isValidSkin ? value : 1101003003; // Fallback to default
    }
    else if (strcmp(skinKey, "AWM") == 0) {
        new_Skin.AWM = isValidSkin ? value : 1103003003; // Fallback to default
    }
    else if (strcmp(skinKey, "K98") == 0) {
        new_Skin.K98 = isValidSkin ? value : 1103001003; // Fallback to default
    }
    else if (strcmp(skinKey, "UMP") == 0) {
        new_Skin.UMP = isValidSkin ? value : 1102002003; // Fallback to default
    }
    else if (strcmp(skinKey, "UZI") == 0) {
        new_Skin.UZI = isValidSkin ? value : 1102001003; // Fallback to default
    }
    else if (strcmp(skinKey, "Vector") == 0) {
        new_Skin.Vector = isValidSkin ? value : 1102003003; // Fallback to default
    }
    else if (strcmp(skinKey, "GROZA") == 0) {
        new_Skin.Groza = isValidSkin ? value : 1101005003; // Fallback to default
    }
    else if (strcmp(skinKey, "M24") == 0) {
        new_Skin.M24 = isValidSkin ? value : 1103002003; // Fallback to default
    }
    else if (strcmp(skinKey, "MK14") == 0) {
        new_Skin.MK14 = isValidSkin ? value : 1103007003; // Fallback to default
    }
    else if (strcmp(skinKey, "MG3") == 0) {
        new_Skin.MG3 = isValidSkin ? value : 1105010003; // Fallback to default
    }
    else if (strcmp(skinKey, "QBZ") == 0) {
        new_Skin.QBZ = isValidSkin ? value : 1101007003; // Fallback to default
    }
    
    env->ReleaseStringUTFChars(key, skinKey);
}

// JNI function to get skin name by weapon and skin ID
extern "C"
JNIEXPORT jstring JNICALL
Java_com_bearmod_SkinManager_getSkinName(JNIEnv *env, jclass clazz, jstring weaponKey, jint skinId) {
    if (!weaponKey) return env->NewStringUTF("Unknown");
    
    const char *weapon = env->GetStringUTFChars(weaponKey, 0);
    if (!weapon) return env->NewStringUTF("Unknown");
    
    std::string skinName = getSkinName(std::string(weapon), skinId);
    
    env->ReleaseStringUTFChars(weaponKey, weapon);
    return env->NewStringUTF(skinName.c_str());
}

// JNI function to get all available skin IDs for a weapon
extern "C"
JNIEXPORT jintArray JNICALL
Java_com_bearmod_SkinManager_getAvailableSkinIds(JNIEnv *env, jclass clazz, jstring weaponKey) {
    if (!weaponKey) return env->NewIntArray(0);
    
    const char *weapon = env->GetStringUTFChars(weaponKey, 0);
    if (!weapon) return env->NewIntArray(0);
    
    std::vector<int> skinIds = getAvailableSkinIds(std::string(weapon));
    
    jintArray result = env->NewIntArray(skinIds.size());
    if (result != nullptr) {
        env->SetIntArrayRegion(result, 0, skinIds.size(), skinIds.data());
    }
    
    env->ReleaseStringUTFChars(weaponKey, weapon);
    return result;
}

// JNI function to get current skin ID for a weapon
extern "C"
JNIEXPORT jint JNICALL
Java_com_bearmod_SkinManager_getCurrentSkinId(JNIEnv *env, jclass clazz, jstring weaponKey) {
    if (!weaponKey) return 0;
    
    const char *weapon = env->GetStringUTFChars(weaponKey, 0);
    if (!weapon) return 0;
    
    int currentSkinId = 0;
    
    // Get current skin ID from new_Skin struct
    if (strcmp(weapon, "M416") == 0) {
        currentSkinId = new_Skin.M416_1;
    }
    else if (strcmp(weapon, "AKM") == 0) {
        currentSkinId = new_Skin.AKM;
    }
    else if (strcmp(weapon, "SCAR") == 0) {
        currentSkinId = new_Skin.Scar;
    }
    else if (strcmp(weapon, "AWM") == 0) {
        currentSkinId = new_Skin.AWM;
    }
    else if (strcmp(weapon, "K98") == 0) {
        currentSkinId = new_Skin.K98;
    }
    else if (strcmp(weapon, "UMP") == 0) {
        currentSkinId = new_Skin.UMP;
    }
    else if (strcmp(weapon, "UZI") == 0) {
        currentSkinId = new_Skin.UZI;
    }
    else if (strcmp(weapon, "Vector") == 0) {
        currentSkinId = new_Skin.Vector;
    }
    else if (strcmp(weapon, "GROZA") == 0) {
        currentSkinId = new_Skin.Groza;
    }
    else if (strcmp(weapon, "M24") == 0) {
        currentSkinId = new_Skin.M24;
    }
    else if (strcmp(weapon, "MK14") == 0) {
        currentSkinId = new_Skin.MK14;
    }
    else if (strcmp(weapon, "MG3") == 0) {
        currentSkinId = new_Skin.MG3;
    }
    else if (strcmp(weapon, "QBZ") == 0) {
        currentSkinId = new_Skin.QBZ;
    }
    
    env->ReleaseStringUTFChars(weaponKey, weapon);
    return currentSkinId;
}

// ===== STREAMLINED SKIN CONFIGURATION =====
// Configuration moved to JOIN_SKIN.h for centralized management
// This reduces code duplication and improves maintainability

// Memory protection functionality moved to JOIN_SKIN.h

// Skin verification functionality moved to JOIN_SKIN.h

// Dynamic skin management functionality moved to JOIN_SKIN.h

// ===== ENHANCED ANTI-DETECTION X-SUIT SYSTEM =====
// XSuitAntiDetection moved to top of file to avoid redefinition errors

// ===== COMPREHENSIVE SKIN SYSTEM =====
// All skin data structures and management moved to ESP_SKIN.h and JOIN_SKIN.h
// This includes:
// - WeaponSkinInfo, VehicleSkinInfo, DeadboxSkinInfo, KillMessageSkinInfo
// - Global skin maps (g_WeaponSkinMap, g_VehicleSkinMap, etc.)
// - Enhanced skin management systems
// - Memory protection and anti-detection systems

// ===== ENHANCED SKIN MANAGEMENT SYSTEM =====
// EnhancedSkinManager moved to ESP_SKIN.h and JOIN_SKIN.h to avoid redefinition
// All EnhancedSkinManager implementation moved to ESP_SKIN.h

// ===== WEAPON DATA STRUCTURES =====
// All weapon data structures and functions moved to JOIN_SKIN.h and ESP_SKIN.h

// ===== DUPLICATE REMOVAL NOTICE =====
// All duplicate functions and structures removed to avoid redefinition errors
// The following are now defined in the modular system:
// - JOIN_SKIN.h: Basic skin data structures and application logic
// - ESP_SKIN.h: Advanced features, anti-detection, memory protection
// - WeaponData, XSuitState, DeadboxState, KillMessageState
// - Global state maps and initialization functions

// Kill message initialization moved to ESP_SKIN.h

// All duplicate functions moved to ESP_SKIN.h:
// - ApplyXSuitEffectWithKillMessage
// - UpdateDeadboxWithKillMessage
// - GetRealTimeKillMessage
// - InitializeMemoryProtection
// - ScrambleMemory
// - InitializeXSuitEffects
// - InitializeDeadboxItems
// - InitializeKillMessages
// - snew_Skin struct and bearSkins array

// All BearMod skin patch functions moved to ESP_SKIN_IMPL.cpp:
// - findPattern
// - mprotectPatchRegion

// All skin patch functions moved to ESP_SKIN_IMPL.cpp:
// - applySkinPatch
// - applyEnhancedSkinPatch

// ===== JNI INTEGRATION =====
// All JNI methods moved to ESP_SKIN_IMPL.cpp for better organization:
// - Java_com_bearmod_MemoryScrambler_scrambleSkinIDNative

// All remaining JNI methods moved to ESP_SKIN_IMPL.cpp:
// - Java_com_bearmod_MemoryScrambler_unscrambleSkinIDNative

// ===== MODULAR SKIN SYSTEM COMPLETE =====
// All skin-related functionality has been moved to the modular system:
// - ESP_SKIN.h: Advanced skin features, anti-detection, memory protection
// - ESP_SKIN_IMPL.cpp: Core implementation functions
// - ESP_SKIN_JNI.cpp: JNI interface methods
// - JOIN_SKIN.h: Basic skin data structures and application logic

#endif // NRG_H










