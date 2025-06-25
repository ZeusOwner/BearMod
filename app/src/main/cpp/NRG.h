#include "Helper/StrEnc.h"
#include "Helper/struct.h"
#include "Helper/Includes.h"

#include <chrono>
#include <unordered_map>

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
#include "JOIN_SKIN.h"
#include "Outfit_Skin.h"
#include "Skin_System.h" // <-- NEW INCLUDE
#include "WEAPON_MODS.h"
// Include the new AntiCheat system at the top of NRG.h
#include "AntiCheat.h"

// At the top of NRG.h
#include "ESP_SKIN.h"


//MOD-SYSTEM INCLUDES

#include "AntiCheat.h"
#include "JOIN_SKIN.h"
#include "Outfit_Skin.h"
#include "ESP_SKIN.h"
#include "WEAPON_MODS.h"
#include "Skin_System.h"

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
std::map<std::string, long> Config;
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
//int MainSuit = 0;

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


//static Canvas *m_Canvas = 0;


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
  // C++ Performance monitoring integration
  // updateCppPerformanceMetrics(); // COMMENTED: Function not defined

  // Frame skipping optimization for low-performance devices
  // COMMENTED: Variables not defined - causing compilation errors
  /*
  if (!isHighPerformanceMode) {
      frameSkipCounter++;
      if (frameSkipCounter <= MAX_FRAME_SKIP) {
          return; // Skip this frame to maintain FPS
      }
      frameSkipCounter = 0; // Reset counter after skipping
  }
  */

  g_screenWidth = screenWidth;
  g_screenHeight = screenHeight;
  if (!g_Token.empty() && !g_Auth.empty() && g_Token == g_Auth) {

    sprintf(extra, "%s", "BEAR-MOD");
    esp.DrawText(Color::White(), extra, FVector2D(screenWidth / 2, 95), 45);

    // Add performance indicator for debugging
    // COMMENTED: Variables not defined - causing compilation errors
    /*
    if (frameCount % 60 == 0) { // Update every 60 frames
        char perfText[64];
        sprintf(perfText, "FPS: %.1f | LOD: %s", 1000.0f/averageFrameTime,
    enableLOD ? "ON" : "OFF"); esp.DrawText(Color::Green(), perfText,
    FVector2D(screenWidth / 2, 120), 25);
    }
    */

    if (!bScanPatternCompleted)
      return;

    auto GWorld = GetWorld();
    if (GWorld) {
      ULevel *PersistentLevel = GWorld->PersistentLevel;
      if (GWorld->PersistentLevel) {
        TArray<AActor *> Actors =
            *(TArray<AActor *> *)((uintptr_t)PersistentLevel + 0xA0);

        int totalEnemies = 0, totalBots = 0;
        auto localPlayer = g_LocalPlayer;
        auto localController = g_PlayerController;
        if (localController) {

          if (Config["ESP_RADAR"]) {
            struct Vector3 Pos;
            Pos.X = screenWidth / 5.5; // 4.395
            Pos.Y = screenHeight / 10; // 40

            struct Vector3 Size;
            Size.X = Config["RADAR_SIZE"];
            Size.Y = Config["RADAR_SIZE"];
            float RadarCenterX = Pos.X + (Size.X / 2);
            float RadarCenterY = Pos.Y + (Size.Y / 2);
            esp.DrawFilledRect(Color(0, 0, 0, 130), {Pos.X, Pos.Y},
                               {Size.X, Size.Y});
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
            esp.DrawRect(Color(255, 255, 255), 1.5, {Pos.X, Pos.Y},
                         {Size.X, Size.Y});
            esp.DrawCircle(Color(255, 0, 0),
                           FVector2D{RadarCenterX, RadarCenterY}, 3.0f, 10);
            // esp.DrawText(Color::Red(), "•", FVector2D(RadarCenterX, RadarCenterY), 40);//20
          }
          if (localPlayer) {

            int totalEnemies = 0; // Declare totalEnemies counter
            int totalBots = 0;    // Declare totalBots counter
            char extra[512];      // Declare extra string buffer

            for (int i = 0; i < Actors.Num(); i++) {
              if (isObjectPlayer(Actors[i])) {
                auto Player = (ASTExtraPlayerCharacter *)Actors[i];
                auto RootComponent = Player->RootComponent;
                if (!RootComponent)
                  continue;

                // Use original distance calculation
                FVector localPlayerPosition =
                    localPlayer->RootComponent->RelativeLocation;
                FVector enemyPosition = Player->RootComponent->RelativeLocation;
                float Distance =
                    localPlayerPosition.Distance(enemyPosition) / 100.0f;

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
                    Pos.X = screenWidth / 5.5; // 4.395
                    Pos.Y = screenHeight / 10; // 40

                    struct Vector3 Size;
                    Size.X = Config["RADAR_SIZE"];
                    Size.Y = Config["RADAR_SIZE"];
                    float RadarCenterX = Pos.X + (Size.X / 2);
                    float RadarCenterY = Pos.Y + (Size.Y / 2);
                    FVector MyPosition, EnemyPosition;
                    ASTExtraVehicleBase *CurrentVehiclea =
                        Player->CurrentVehicle;
                    if (CurrentVehiclea) {
                      MyPosition =
                          CurrentVehiclea->RootComponent->RelativeLocation;
                    } else {
                      MyPosition = Player->RootComponent->RelativeLocation;
                    }
                    ASTExtraVehicleBase *CurrentVehicle =
                        localPlayer->CurrentVehicle;
                    if (CurrentVehicle) {
                      EnemyPosition =
                          CurrentVehicle->RootComponent->RelativeLocation;
                    } else {
                      EnemyPosition =
                          localPlayer->RootComponent->RelativeLocation;
                    }
                    FVector RadarSketch =
                        WorldToRadar(localController->PlayerCameraManager
                                         ->CameraCache.POV.Rotation.Yaw,
                                     MyPosition, EnemyPosition, Pos.X, Pos.Y,
                                     Vector3(Size.X, Size.Y, 0), out);

                    esp.DrawCircle(RADARColor,
                                   FVector2D{RadarSketch.X, RadarSketch.Y},
                                   3.0f, 10);
                    std::string s;
                    s += std::to_string((int)Distance);

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
                  else
                    totalEnemies++;

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
                    clrHealth = Color(0, 255, 0, 190);
                  } else {
                    clrHealth = Color(255, 0, 0, 190);
                  }

                  FVector Head = GetBoneLocation(Player, "Head");
                  FVector Root = GetBoneLocation(Player, "Root");
                  FVector RootPos = GetBoneLocation(Player, "Root");
                  FVector HeadPos2 = GetBoneLocation(Player, "Head");
                  HeadPos2.Z += 17.5f; // 16.5f;
                  FVector RootPos2 = GetBoneLocation(Player, "Root");
                  RootPos2.Z -= 6.5f; // 5.5f;

                  auto Head_RootZ = HeadPos2.Z - RootPos2.Z;

                  FVector uparmr = GetBoneLocation(Player, "upperarm_r");
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
                  auto PlayerCameraManager =
                      localController->PlayerCameraManager;
                  CameraCache = PlayerCameraManager->CameraCache;

                  HeadNrgSc = WorldToScreen360(HeadNrg, CameraCache.POV,
                                               screenWidth, screenHeight);

                  auto isvis =
                      localController->LineOfSightTo(localPlayer, Head, false);

                  if (HeadSc.Z > 0 && RootSc.Z > 0) {
                    if (Config["ESP_LINE"]) {
                      auto gunHead = Player->GetHeadLocation(true);
                      gunHead.Z += 35.f;

                      FVector GunHeadSc = WorldToScreen(gunHead);
                      auto mWidthScaleGun = std::min(0.006f * Distance, 100.f);
                      auto mWidthGun = 20.f - mWidthScaleGun;
                      auto mHeightGun = mWidthGun * 0.125f;
                      GunHeadSc.Y -= (mHeightGun * 1.4f + 15);

                      esp.DrawLine2(LineColor, 2, FVector2D(screenWidth / 2, 0),
                                    FVector2D(HeadSc.X, GunHeadSc.Y - 16));
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
                                      FVector2D(claviclerSC.X, claviclerSC.Y));
                      } else {
                        esp.DrawLine2(Color::Green(), 2.2f,
                                      FVector2D(neckSC.X, neckSC.Y),
                                      FVector2D(claviclerSC.X, claviclerSC.Y));
                      }

                      if (!localController->LineOfSightTo(
                              localController->PlayerCameraManager, uparmr,
                              true)) {
                        esp.DrawLine2(Color::Red(), 2.2f,
                                      FVector2D(claviclerSC.X, claviclerSC.Y),
                                      FVector2D(uparmrSC.X, uparmrSC.Y));
                      } else {
                        esp.DrawLine2(Color::Green(), 2.2f,
                                      FVector2D(claviclerSC.X, claviclerSC.Y),
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
                                      FVector2D(claviclelSC.X, claviclelSC.Y));
                      } else {
                        esp.DrawLine2(Color::Green(), 2.2f,
                                      FVector2D(neckSC.X, neckSC.Y),
                                      FVector2D(claviclelSC.X, claviclelSC.Y));
                      }

                      if (!localController->LineOfSightTo(
                              localController->PlayerCameraManager, uparml,
                              true)) {
                        esp.DrawLine2(Color::Red(), 2.2f,
                                      FVector2D(claviclelSC.X, claviclelSC.Y),
                                      FVector2D(uparmlSC.X, uparmlSC.Y));
                      } else {
                        esp.DrawLine2(Color::Green(), 2.2f,
                                      FVector2D(claviclelSC.X, claviclelSC.Y),
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
                      int CurHP =
                          (int)std::max(0, std::min((int)Player->Health,
                                                    (int)Player->HealthMax));
                      int MaxHP = (int)Player->HealthMax;

                      Color clrHealthLocal;
                      if (Player->Health == 0.0f && !Player->bDead) {
                        clrHealthLocal = Color(255, 255, 0, 190);
                        CurHP = Player->NearDeathBreath;
                        if (Player->NearDeatchComponent) {
                          MaxHP = Player->NearDeatchComponent->BreathMax;
                        }
                      } else {
                        clrHealthLocal = Color(255, 0, 0, 190);
                      }

                      auto mWidthScale = std::min(0.0f * 24.0f, 0.0f);
                      auto mWidth2 = 10.0f - mWidthScale;
                      auto mWidth3 = 20.0f - mWidthScale;
                      auto mWidth4 = 30.0f - mWidthScale;
                      auto mWidth5 = 40.0f - mWidthScale;
                      auto mWidth = 50.0f - mWidthScale;
                      auto mWidth99 = 5.0f - mWidthScale;

                      auto mHeight = mWidth * 0.078f;
                      auto mHeightgg = mWidth * -0.0f;
                      HeadSc.X -= (mWidth / 2);
                      HeadSc.Y -= (mHeight * 1.5f);

                      auto HpHead = Player->GetHeadLocation(true);
                      HpHead.Z += 35.f;

                      FVector HpHeadSc = WorldToScreen(HpHead);
                      auto mWidthScaleGun = std::min(0.006f * Distance, 100.f);
                      auto mWidthGun = 20.f - mWidthScaleGun;
                      auto mHeightGun = mWidthGun * 0.125f;
                      HpHeadSc.X -= (mWidthGun / 2);
                      HpHeadSc.Y -= (mHeightGun * 1.4f + 8);

                      esp.DrawFilledRect(
                          clrHealthLocal, FVector2D(HeadSc.X, HpHeadSc.Y),
                          FVector2D(CurHP * mWidth / MaxHP, mHeight));

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

                      // Distance text
                      std::string s;
                      s += std::to_string((int)Distance);
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
                      auto WeaponManagerComponent =
                          Player->WeaponManagerComponent;
                      if (WeaponManagerComponent) {
                        auto CurrentWeapon =
                            (ASTExtraShootWeapon *)
                                WeaponManagerComponent->CurrentWeaponReplicated;
                        if (CurrentWeapon) {
                          auto WeaponName = CurrentWeapon->GetWeaponName();
                          if (WeaponName.IsValid()) {
                            const char *utf8Name = WeaponName.ToString();
                            if (utf8Name) {
                              ws2 = "(" + std::string(utf8Name) + ")";
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
                          const char *utf8Name = playerNameStr.ToString();
                          ws = utf8Name ? std::string(utf8Name) : "Player";
                        } else {
                          ws = "Invalid";
                        }
                      }
                      if (Config["ESP_WEAPON"] && !ws2.empty()) {
                        esp.DrawText(
                            Color::White(), ws2.c_str(),
                            FVector2D(GunHeadSc.X - 11.2, GunHeadSc.Y - 19.5),
                            14.8f);
                      }

                      if (Config["ESP_INFO"] && !ws.empty()) {
                        Color NameColor =
                            Player->bEnsure ? Color::White() : Color::Yellow();
                        esp.DrawText(
                            NameColor, ws.c_str(),
                            FVector2D(NameHeadSc.X, NameHeadSc.Y - 2.7), 15.8);
                      }
                    }

                    if (Config["ESP_ALERT"]) {
                      bool shit = false;
                      FVector MyPosition, EnemyPosition;
                      ASTExtraVehicleBase *CurrentVehiclea =
                          Player->CurrentVehicle;
                      if (CurrentVehiclea) {
                        MyPosition =
                            CurrentVehiclea->RootComponent->RelativeLocation;
                      } else {
                        MyPosition = Player->RootComponent->RelativeLocation;
                      }
                      ASTExtraVehicleBase *CurrentVehicle =
                          localPlayer->CurrentVehicle;
                      if (CurrentVehicle) {
                        EnemyPosition =
                            CurrentVehicle->RootComponent->RelativeLocation;
                      } else {
                        EnemyPosition =
                            localPlayer->RootComponent->RelativeLocation;
                      }
                      FVector EntityPos = WorldToRadar(
                          localController->PlayerCameraManager->CameraCache.POV
                              .Rotation.Yaw,
                          MyPosition, EnemyPosition, NULL, NULL,
                          Vector3(screenWidth, screenHeight, 0), shit);
                      FVector angle = FVector();
                      Vector3 forward = Vector3(
                          (float)(screenWidth / 2) - EntityPos.X,
                          (float)(screenHeight / 2) - EntityPos.Y, 0.0f);
                      VectorAnglesRadar(forward, angle);

                      const auto angle_yaw_rad =
                          DEG2RAD(angle.Y + 180.f + 360.f);
                      const auto new_point_x =
                          (screenWidth / 2) +
                          (55) / 2 * 13 * cosf(angle_yaw_rad);
                      const auto new_point_y =
                          (screenHeight / 2) +
                          (55) / 2 * 13 * sinf(angle_yaw_rad);
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

                      esp.DrawText(Color::Red(), "🔴",
                                   FVector2D(points[0].X, points[0].Y), 15);
                    }
                  } // Close HeadSc.Z > 0 && RootSc.Z > 0 check
                } // Close Distance < 1000.f check
              } // Close isObjectPlayer check
            } // Close main player loop

            // Separate loop for non-player objects
            for (int j = 0; j < Actors.Num(); j++) {
              if (isObjectInvalid(Actors[j]))
                continue;

              if (Config["ESP_WARNING"]) {
                if (isObjectGrenade(Actors[j])) {
                  auto *Grenade = (ASTExtraGrenadeBase *)Actors[j];
                  std::string n = getObjectPath(Grenade);
                  auto RootComponent = Actors[j]->RootComponent;
                  if (!RootComponent)
                    continue;
                  float Distance = Grenade->GetDistanceTo(localPlayer) / 100.f;
                  FVector2D grenadePos;
                  FVector Location =
                      WorldToScreen(RootComponent->RelativeLocation);
                  if (Distance <= 100.f) {
                    if (Location.Z > 0) {
                      std::string s;

                      if (n == "BP_Grenade_Burn_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object" ||
                          n == "BP_Grenade_Shoulei_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object") {
                        esp.DrawText(Color::Red(), "⚠️ WARNING ⚠️",
                                     FVector2D(screenWidth / 2, 195), 28);
                      }
                      if (n == "BP_Grenade_Burn_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object") {
                        s += "Molotov";
                        s += " - [";
                        s += std::to_string((int)Distance);
                        s += "M]";
                      } else if (n == "BP_Grenade_Shoulei_C.BP_Grenade_Base_C.STExtraGrenadeBase.UAEProjectile.LuaActor.Actor.Object") {
                        s += "Grenade";
                        s += " - [";
                        s += std::to_string((int)Distance);
                        s += "M]";
                      }

                      esp.DrawText(Color::Red(), s.c_str(),
                                   FVector2D(Location.X, Location.Y), 15);
                    }
                  }
                }
              }

              if (Config["ESP::VEHICLE"]) {
                if (isObjectVehicle(Actors[j])) {
                  auto *Vehicle = (ASTExtraVehicleBase *)Actors[j];
                  auto RootComponent = Vehicle->RootComponent;
                  if (!RootComponent)
                    continue;

                  float vDistance = Vehicle->GetDistanceTo(localPlayer) / 100.f;
                  if (vDistance < 700.f) {
                    FVector Location =
                        WorldToScreen(RootComponent->RelativeLocation);
                    if (Location.Z > 0) {
                      std::string s = GetVehicleName(Vehicle);
                      s += " - ";
                      s += std::to_string((int)vDistance);
                      s += "M";
                      esp.DrawText(Color(255, 50, 255, 255), s.c_str(),
                                   FVector2D(Location.X, Location.Y + 10), 15);
                    }
                  }
                }
              }

              if (isObjectLoot(Actors[j])) {
                auto *PickUp = (APickUpWrapperActor *)Actors[j];
                if (Tools::IsPtrValid(PickUp)) {
                  if (itemConfig[PickUp->DefineID.TypeSpecificID]) {
                    auto RootComponent = PickUp->RootComponent;
                    if (!RootComponent)
                      continue;

                    float Distance = PickUp->GetDistanceTo(localPlayer) / 100.f;

                    std::string s;
                    int tc = 0xFF000000, oc = 0xFFFFFFFF;

                    for (auto &e : itemData) {
                      if (e["itemId"] == PickUp->DefineID.TypeSpecificID) {
                        s = "[ ";
                        s += e["itemName"].get<std::string>();
                        tc = strtoul(
                            e["itemTextColor"].get<std::string>().c_str(), 0,
                            16);
                        oc = strtoul(
                            e["itemOutlineColor"].get<std::string>().c_str(), 0,
                            16);
                        break;
                      }
                    }

                    s += " ";
                    s += std::to_string((int)Distance);
                    s += "M ]";

                    FVector Location =
                        WorldToScreen(RootComponent->RelativeLocation);
                    if (Location.Z > 0) {
                      esp.DrawText(Color(255, 255, 255, 255), s.c_str(),
                                   FVector2D(Location.X, Location.Y), 16);
                    }
                  }
                }
              }

              if (Config["ESP::LOOTBOX"]) {
                if (isObjectLootBox(Actors[j])) {
                  auto *PickUpList = (APickUpListWrapperActor *)Actors[j];
                  auto PickUpDataList =
                      (TArray<FPickUpItemData>)PickUpList->GetDataList();
                  auto RootComponent = PickUpList->RootComponent;
                  if (!RootComponent)
                    continue;

                  float Distance =
                      PickUpList->GetDistanceTo(localPlayer) / 100.f;
                  if (Distance <= 50.f) {
                    std::string s = GetLootName(PickUpList);
                    s += " [";
                    s += std::to_string((int)Distance);
                    s += "m]";

                    FVector Location =
                        WorldToScreen(RootComponent->RelativeLocation);
                    if (Location.Z > 0) {
                      esp.DrawText(Color(255, 255, 255, 255), s.c_str(),
                                   FVector2D(Location.X, Location.Y), 14);

                      if (Config["ESP::LOOT_BOX_ITEMS"]) {
                        if (Distance <= 15.f) {
                          for (int k = 0; k < PickUpDataList.Num(); k++) {
                            std::vector<std::string> s2;
                            long tc = 0xFF000000, oc = 0xFFFFFFFF;

                            for (auto &e : items_data) {
                              if (e["itemId"] ==
                                  PickUpDataList[k].ID.TypeSpecificID) {
                                s2.push_back(e["itemName"].get<std::string>());
                                tc = strtoul(e["itemTextColor"]
                                                 .get<std::string>()
                                                 .c_str(),
                                             0, 16);
                                oc = strtoul(e["itemOutlineColor"]
                                                 .get<std::string>()
                                                 .c_str(),
                                             0, 16);
                                break;
                              }
                            }
                            if (!s2.empty()) {
                              if (PickUpDataList[k].Count > 1) {
                                s2.push_back(" * ");
                                s2.push_back(
                                    std::to_string(PickUpDataList[k].Count));
                              }

                              std::string s3;
                              for (auto &s4 : s2) {
                                s3 += s4;
                              }

                              esp.DrawText(Color(255, 255, 255, 255), s.c_str(),
                                           FVector2D(Location.X, Location.Y),
                                           14);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            } // Close non-player objects loop
          }

          if (totalEnemies > 0) {

            sprintf(extra, OBFUSCATE("[ALERT] %d Enemies in Area"),
                    totalEnemies);
            // sprintf(extra, "[ALERT] %d Enemies in Area", totalEnemies);
            esp.DrawText(Color::Red(), extra, FVector2D(screenWidth / 2, 155),
                         40);

            // m_Canvas->drawText(extra, screenWidth / 2, 155, 40.0f, Align::CENTER, RED, BLACK);
          }

          //}}
        }

        if (Config["NRG_AIMBOT"]) {
          // float FOVSIZE = Config["AIM::SIZE"];

          esp.DrawCircle(Color(255, 0, 0),
                         FVector2D(screenWidth / 2, screenHeight / 2),
                         Config["AIM_SIZE"], 2);
        }
        //      }

        //     g_LocalPlayer = localPlayer;
        //        g_PlayerController = localController;
        ////     fps.update();
      }
    }
  } // Close DrawESP function
}
#define TSL_FONT_DEFAULT_SIZE 20
static UFont *tslFont = nullptr, *robotoTinyFont = nullptr;

[[maybe_unused]] void *LoadFont(void *) {
    while (!tslFont || !robotoTinyFont) {
        tslFont = UObject::FindObject<UFont>("Font Roboto.Roboto"); // Font Roboto.Roboto
        robotoTinyFont = UObject::FindObject<UFont>("Font RobotoDistanceField.RobotoDistanceField");
        sleep(1);
    }
    return nullptr;
}

//#define JOIN_SKIN_H



// ===========================================================================================================
// METRO SKIN SYSTEM - MOVED TO JOIN_SKIN.h
// ===========================================================================================================
// All Metro skin arrays have been moved to JOIN_SKIN.h for unified management
// Use the new centralized system with Metro IDs 1-7 and Global premium skins
// Example: getWeaponSkinID("AKM", 1) for Metro skin, getWeaponSkinID("AKM", 8) for Global skin
// ===========================================================================================================

// Legacy equipment arrays (kept for compatibility)
//int bag111[] = { 501001, 1501001220, 1501001174, 1501001265, 1501001443, 1501001051, 1501001277, 1501001550, 1501001552, 1501001065, 1501001558, 1501001058, 1501001062, 1501001411, 1501001502, 1501001422};
//int bag222[] = { 501002, 1501002220, 1501002174, 1501002265, 1501002443, 1501002051, 1501002277, 1501002550, 1501002552, 1501002065, 1501002558, 1501002058, 1501002062, 1501002411, 1501002502, 1501002422};
//int bag333[] = { 501003, 1501003220, 1501003174, 1501003265, 1501003443, 1501003051, 1501003277, 1501003550, 1501003552, 1501003065, 1501003558, 1501003058, 1501003062, 1501003411, 1501003502, 1501003422};

//int Helmet1[] = { 502001, 1502001028, 1502001014, 1502001023, 1502001065, 1502001031, 1502001033, 1502001069, 1502001261, 1502001272, 1502001183};
//int Helmet2[] = { 502002, 1502002028, 1502002014, 1502002023, 1502002065, 1502002031, 1502002033, 1502002069, 1502002261, 1502002272, 1502002183};
//int Helmet3[] = { 502003, 1502003028, 1502003014, 1502003023, 1502003065, 1502003031, 1502003033, 1502003069, 1502003261, 1502003272, 1502003183};

// ===========================================================================================================
// LEGACY WEAPON ARRAYS - DEPRECATED (Use JOIN_SKIN.h instead)
// ===========================================================================================================
// These arrays are kept for backward compatibility but should be replaced with the new unified system
// See JOIN_SKIN.h for the complete Metro + Global skin system

// Legacy arrays (deprecated - use JOIN_SKIN.h instead)
int m4v[] = { 101004, 1101004046, 1101004062, 1101004078, 1101004086, 1101004098, 1101004138, 1101004163,1101004201,1101004209,1101004218,1101004226};
int scar[] = { 101003, 1010031, 1010032, 1010033, 1010034, 1010035, 1010036, 1010037, 1101003057, 1101003070, 1101003080, 1101003119, 1101003146, 1101003167, 1101003181, 1101003195}; //metro
int akmv[] = { 101001, 1010011, 1010012, 1010013, 1010014, 1010015, 1010016, 101001, 1101001089, 1101001103, 1101001116, 1101001128, 1101001143, 1101001154, 1101001174,1101001213,1101001231,1101001242,1101001249,1101001256,1101001063}; //Metro
int m7[] = { 101008, 1010081, 1010082, 1010083, 1010084, 1010085, 1010086, 1010087, 1101008026, 1101008051, 1101008061, 1101008081, 1101008104, 1101008116, 1101008126, 1101008070};
int awm[] = { 103003, 1030031, 1030032, 1030033, 1030034, 1030035, 1030036, 1030037, 1103003022, 1103003030, 1103003042, 1103003051, 1103003062}; //metro
int amr[] = { 103012, 1030121, 1030122, 1030123, 1030124, 1030125, 1030126, 1030127, 1103012010,1103012019}; //metro
int mk14[] = { 103007, 1030071, 1030072, 1030073, 1030074, 1030075, 1030076, 1030077, 1103007020, 1103007028}; //metro
int mg3[] = { 105010, 1050101, 1050102, 1050103, 1050104, 1050105, 1050106, 1050107, 1105010008,1105010019};
int kar[] = { 103001, 1030011, 1030012, 1030013, 1030014, 1030015, 1030016, 1030017, 1103001060, 1103001079, 1103001101, 1103001145, 1103001160, 1103001179}; //metro
int m24[] = { 103002, 1030021, 1030022, 1030023, 1030023, 1030024, 1030025, 1030026, 1030027, 1103002018, 1103002030, 1103002048, 1103002056, 1103002087}; //Metro 

int mini14[] = { 103006, 1103006030, 1103006046, 1103006058};
int dp[] = { 105002, 1105002018, 1105002035, 1105002058, 1105002063};
int m249[] = { 105001, 1105001020, 1105001034, 1105001048, 1105001054};

int groza[] = { 101005, 1010051, 1010052, 1010053, 1010054, 1010055, 1010056, 1010057, 1101005019, 1101005025, 1101005038, 1101005043, 1101005052, 1101005082};
int aug[] = { 101006, 1010061, 1010062, 1010063, 1010064, 1010065, 1010066, 1010067, 1101006033, 1101006044, 1101006062}; //metro
int m16[] = { 101002, 1010021, 1010022, 1010023, 1010024, 1010025, 1010026, 1010027, 1101002029, 1101002056, 1101002068, 1101002081, 1101002103}; //metro

int uzi[] = { 102001, 1020011, 1020012, 1020013, 1020014, 1020015, 1020016, 1020017, 1102001024, 1102001036, 1102001058, 1102001069, 1102001089, 1102001102}; //metro
int ump[] = { 102002, 1020021, 1020022, 1020023, 1020024, 1020025, 1020026, 1020027, 1102002043, 1102002061, 1102002090, 1102002117, 1102002124, 1102002129, 1102002136}; //Meteo

int thompson[] = {102004, 1102004018, 1102004034};
int vector[] = { 102003, 1020031, 1020032, 1020033, 1020034, 1020035, 1020036, 1020037, 1102003020, 1102003031, 1102003065, 1102003080}; //metro
int tommy[] = { 102004, 1102004018, 1102004034};
int bizon[] = { 102005, 1102005007, 1102005020, 1102005041};

int ace32[] = { 101102, 1011021, 1011022, 1011023, 1011024, 1011025, 1011026, 1011027, 1101102007, 1101102017,1101102025}; // metro

int pan[] = { 108004, 1108004125, 1108004145, 1108004160, 1108004283, 1108004337, 1108004356, 1108004365, 1108004054, 1108004008};

// ===========================================================================================================
// LEGACY MAGAZINE ARRAYS - DEPRECATED (Use JOIN_SKIN.h instead)
// ===========================================================================================================
int m249s[] = { 205009, 1050010351, 1050010412, 1050010482, 1050010542};
int akmmag[] = { 291001,204013,204011,204012,1010010891, 1010011031, 1010011161, 1010011281, 1010011431, 1010011541, 1010011741,1010012131,1010012311,1010012421};
int m7mag[] = { 291008,204013,204011,204012,1010080261, 1010080511, 1010080611, 1010080811, 1010081041, 1010081161, 1010081261};
int scarmag[] = { 291003,204013,204011,204012,1010030571, 1010030701, 1010030801, 1010031191, 1010031461, 1010031671, 1010031811};
int m4mag[] = { 291004,204013,204011,204012,1010040461,1010040611,1010040781,1010040861,1010040981,1010041381,1010041631,1010042011,1010042073,1010042153,1010042206  };

// ===========================================================================================================
// LEGACY ATTACHMENT ARRAYS - DEPRECATED (Use JOIN_SKIN.h instead)
// ===========================================================================================================
int m4sight[] = { 203008,1010040462,1010040612,1010040782,1010040862,1010040982,1010041382,1010041632,1010042012,1010042083,1010042163,1010042209  };

int m4stock[] = { 205005,1010040463,1010040613,1010040783,1010040863,1010040983,1010041383,1010041633,1010042013,1010042093,1010042173,1010042213  };

int m4stock1[] = { 205002,1010040480,205002,205002,205002,205002,1010041146,1010041579,1010041966,1010042137,1010042173,1010042213,1010042244  };

int m4reddot[] = { 203001,1010040470,203001,203001,203001,203001,1010041128,1010041566,1010041948,1010042029,1010042119,1010042233  };

int m16s[] = { 205007, 1010020292, 1010020562, 1010020682, 1010020812, 1010021032};
int m16mag[] = { 291002,204013,204011,204012, 1010020291, 1010020561, 1010020681, 1010020811, 1010021031};

// ===========================================================================================================
// LEGACY M416 ATTACHMENT ARRAYS - DEPRECATED (Use JOIN_SKIN.h instead)
// ===========================================================================================================
//M416 ONLY
int M4161[] = { 101004, 1010041, 1010042, 1010043, 1010044, 1010045, 1010046, 1010047, 1101004046, 1101004062, 1101004078, 1101004086, 1101004098, 1101004138, 1101004163, 1101004201, 1101004209, 1101004218,1101004226}; //Metro
int M4162[] = { 291004, 1010040461, 1010040611, 1010040781, 1010040861, 1010040981, 1010041381, 1010041631, 1010042011, 1010042073, 1010042153,1010042206};
int M4163[] = { 203008, 1010040462, 1010040612, 1010040782, 1010040862, 1010040982, 1010041382, 1010041632, 1010042012, 1010042083, 1010042163,1010042209};
int M4164[] = { 205005, 1010040463, 1010040613, 1010040783, 1010040863, 1010040983, 1010041383, 1010041633, 1010042013, 1010042093, 1010042173,1010042213};
int M416flash[] = { 201010, 1010040474, 201010, 201010, 201010, 201010, 1010041136, 201010, 1010041956, 20101000, 1010042128,1010042238};
int M416compe[] = { 201009, 1010040475, 201009, 201009, 201009, 201009, 1010041137, 1010041574, 1010041957, 1010042037, 1010042127,1010042237};
int M416silent[] = { 201011, 1010040476, 201011, 201011, 201011, 201011, 1010041138, 1010041575, 1010041958, 1010042039, 1010042129,1010042239};
int M416holo[] = { 203002, 1010040469, 203002, 203002, 203002, 203002, 1010041127, 1010041565, 1010041947, 1010042028, 1010042118,1010042232};
int M416x2[] = { 203003, 1010040468, 203003, 203003, 203003, 203003, 1010041126, 1010041564, 1010041946, 1010042027, 1010042117,1010042231};
int M416x3[] = { 203014, 1010040467, 203014, 203014, 203014, 203014, 1010041125, 1010041560, 1010041945, 1010042026, 1010042116,1010042219};
int M416x4[] = { 203004, 1010040466, 203004, 203004, 203004, 203004, 1010041124, 1010041554, 1010041944, 1010042025, 1010042115,1010042218};
int M416x6[] = { 203015, 1010040481, 203015, 203015, 203015, 203015, 203015, 203015, 1010041967, 1010042024, 1010042114,1010042217};
int M416quickMag[] = { 204012, 1010040472/*1010040471*/, 204012, 204012, 204012, 204012, 1010041134, 1010041568, 1010041949, 1010042034, 1010042124,1010042235};
int M416extendedMag[] = { 204011, 1010040473, 204011, 204011, 204011, 204011, 1010041129, 1010041569, 1010041950, 1010042035, 1010042125,1010042234};
int M416quickNextended[] = { 204013, 1010040473, 204013, 204013, 204013, 204013, 1010041135, 1010041567, 1010041955, 1010042036, 1010042126,1010042236};
int M416stock[] = { 205002, 1010040480, 205002, 205002, 205002, 205002, 1010041146, 1010041579, 1010041966, 1010042047, 1010042137,1010042244};
int M416angle[] = { 202001, 1010040477, 202001, 202001, 202001, 202001, 1010041139, 1010041576, 1010041959, 1010042044, 1010042134,1010042241};
int M416thumb[] = { 202006, 1010040478, 202006, 202006, 202006, 202006, 202006, 1010041577, 202006, 202006, 1010042135,1010042242};
    
int MainSuit = 0;
int MainSuit2 = 0;
     
int MainBaH = 0;
int MainBaH2 = 0;

namespace Active {
    inline int SkinCarDefault = 0;
    inline int SkinCarMod = 0;
    inline int SkinCarNew = 0;
}

void RenderESP(/*AHUD *HUD, *int SizeX, int SizeY*/) {

    ASTExtraPlayerCharacter *localPlayer = 0;
    ASTExtraPlayerController *localPlayerController = 0;

    updateSkin();
    initializeWeaponData(); // Initialize weapon attachment system
    updateInventoryWeaponSkins(localPlayerController); // UPDATE WEAPON SKINS IN INVENTORY
    //  SizeXx = SizeX;
    //  SizeYy = SizeY;
    auto *gGameplayStatics = (UGameplayStatics *) UGameplayStatics::StaticClass();
    auto *UMC = (UKismetMathLibrary *) UKismetMathLibrary::StaticClass();
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
            // ===========================================================================================================
            // NEW UNIFIED SKIN SYSTEM CALL
            // ===========================================================================================================
            // This single function call now handles all weapon, outfit, helmet, and backpack skins
            // with level-awareness and real-time inventory updates from the new Skin_System.h.
            updateInventoryWeaponSkins(localPlayerController);
            
            // 🔥 CRITICAL FIX: Actually apply skins to game objects!
            applyAllSkinsToGame(localPlayer, localPlayerController);
            // ===========================================================================================================

            std::vector<ASTExtraPlayerCharacter *> PlayerCharacter;
            GetAllActors(PlayerCharacter);

            for (auto Actor : PlayerCharacter) {
                if (Actor->PlayerKey ==
                    ((ASTExtraPlayerController *) localPlayerController)->PlayerKey) {
                    localPlayer = Actor;
                    break;
                }
            }
           if (localPlayer) {
    auto localPlayerController = g_PlayerController;
    if (Config["ANTICHEAT_ENABLE"] && localPlayerController) {
        auto weapon = localPlayer->WeaponManagerComponent ? localPlayer->WeaponManagerComponent->CurrentWeaponReplicated : nullptr;
        
        // ===========================================================================================
        // NEW UNIFIED ANTI-CHEAT BYPASS
        // ===========================================================================================
        // This single function call from AntiCheat.h now handles all anti-cheat bypasses
        // in a clean, organized, and maintainable way.
        // Cast to the correct type that the function expects
        auto shootWeapon = static_cast<ASTExtraShootWeapon*>(weapon);
        if (shootWeapon) {
            DisableAntiCheatSystems(localPlayer, localPlayerController, shootWeapon);
        }
        // ===========================================================================================
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
                                                        targetAimPos = SDK::UKismetMathLibrary::Add_VectorVector(
                                                                targetAimPos,
                                                                SDK::UKismetMathLibrary::Multiply_VectorFloat(
                                                                        LinearVelocity,
                                                                        timeToTravel));
                                                    } else {
                                                        FVector Velocity = Target->GetVelocity();
                                                        float dist = localPlayer->GetDistanceTo(
                                                                Target);
                                                        auto timeToTravel = dist /
                                                                            ShootWeaponEntityComponent->BulletFireSpeed;
                                                        targetAimPos = SDK::UKismetMathLibrary::Add_VectorVector(
                                                                targetAimPos,
                                                                SDK::UKismetMathLibrary::Multiply_VectorFloat(Velocity,
                                                                                          timeToTravel));
                                                    }


                                                    localPlayerController->ClientSetLocation(
                                                            localPlayer->K2_GetActorLocation(),
                                                            ToRotator(
                                                                    localPlayerController->PlayerCameraManager->CameraCache.POV.Location,
                                                                    targetAimPos));


    }}}}}}}}}}}} //12

    g_LocalPlayer = localPlayer;
    g_PlayerController = localPlayerController;
    //}
}


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
}}}}}//5

        auto td = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count() - t1;
        std::this_thread::sleep_for(
                std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
    }
    return 0;
}

int glWidth, glHeight;


extern "C"
JNIEXPORT void JNICALL
Java_com_bearmod_Floating_DrawOn(JNIEnv *env, jclass type, jobject espView, jobject canvas) {
    espOverlay = ESP(env, espView, canvas);

    if (espOverlay.isValid()) {
        // Performance integration: sync with Java FPS settings
        int screenWidth = espOverlay.getWidth();
        int screenHeight = espOverlay.getHeight();
        
        // Call optimized ESP rendering with C++ performance monitoring
        DrawESP(espOverlay, screenWidth, screenHeight);
    }
}

void *(*oProcessEvent)(UObject *pObj, UFunction *pFunc, void *pArgs);

void *hkProcessEvent(UObject *pObj, UFunction *pFunc, void *pArgs) {
  if (pFunc) {


    if (Config["SKIN_ENABLE"]) {


      if (g_PlayerController == nullptr) {
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

                        if (Config["SKIN_XSUIT"] == 1) {
                          Params->FatalDamageParameter.CauserClothAvatarID = 1405909; //Blood Raven X-Suit
                        } else if (Config["SKIN_XSUIT"] == 2) {
                          Params->FatalDamageParameter.CauserClothAvatarID = 1405628; //Golden Pharaoh X-Suit
                        } else if (Config["SKIN_XSUIT"] == 3) {
                          Params->FatalDamageParameter.CauserClothAvatarID = 1406152; //Avalanche X-suit
                        } else if (Config["SKIN_XSUIT"] == 4) {
                          Params->FatalDamageParameter.CauserClothAvatarID = 1406475; //Irresidence X-suit
                        } else if (Config["SKIN_XSUIT"] == 5) {
                          Params->FatalDamageParameter.CauserClothAvatarID = 1405983; //Poseidon X-suit
                        } else if (Config["SKIN_XSUIT"] == 6) {
                          Params->FatalDamageParameter.CauserClothAvatarID = 1406638; //Arcane Jester X-Suit
                        } else if (Config["SKIN_XSUIT"] == 7) {
                          Params->FatalDamageParameter.CauserClothAvatarID = 1406311; //Silvanus X-Suit
                        } else if (Config["SKIN_XSUIT"] == 8) {
                          Params->FatalDamageParameter.CauserClothAvatarID = 1406971;//Marmoris X-Suit
                        } else if (Config["SKIN_XSUIT"] == 9) {
                          Params->FatalDamageParameter.CauserClothAvatarID = 1407103; //Fiore X-Suit
                        } else if (Config["SKIN_XSUIT"] == 10) {
                          Params->FatalDamageParameter.CauserClothAvatarID = 1407259; //Ignis X-Suit
                        } else if (Config["SKIN_XSUIT"] == 11) {
                          Params->FatalDamageParameter.CauserClothAvatarID = 1406872; //Stygian Liege X-Suit
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

}}}}}}}} //8

      if (g_PlayerController == nullptr) {
        //LOGO

      } else {
        //ISLAND

        if (Config["GUN_BOX"]) {
          if (std::string(pObj->GetName()).find("DeadBoxAvatarComponent") !=
              std::string::npos) {
            auto DeadBoxPointer = (UDeadBoxAvatarComponent *) pObj;

            auto *localPlayer = (ASTExtraPlayerCharacter *) g_PlayerController->AcknowledgedPawn;
            if (std::string(pFunc->GetFullName()).find("GetLuaFilePath") !=
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


/*
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
*/

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


    //Tools::Hook((void *) (UE4 + 0x5F60864), (void *) sub_5F60864, (void **) &osub_5F60864);
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

    return nullptr;
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
    if (mem->memory == nullptr) {
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
        curl_easy_setopt(curl, CURLOPT_URL, _enc_("https://free-panel.gleeze.com/connect"));

        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, _enc_("https"));

        struct curl_slist *headers = nullptr;
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
                if (result[("status")] == true) {
                    auto token = result[("data")][("token")].get<std::string>();
                    auto rng = result[("data")][("rng")].get<time_t>();
                    if (rng + 30 > time(nullptr)) {
                        std::string auth = enc("PUBG");
                        auth += "-";
                        auth += userKey;
                        auth += "-";
                        auth += UUID;
                        auth += "-";
                        auth += enc("Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E");
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
