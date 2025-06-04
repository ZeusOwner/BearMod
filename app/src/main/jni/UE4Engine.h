#include <cmath>
#include <array>
#include <unordered_map>
#include <locale>
#include <codecvt>
#include <ctime>



#include "Tools.h" // Assuming Tools is defined in Tools.h
#include "Helper/Quaternion.hpp"

template<typename T = uintptr_t>
T ReadType(uintptr_t addr) {
    T result{};
    if (Tools::PVM_ReadAddr((void *) addr, &result, sizeof(T))) {
        return result;
    }
    return result;
}


class FPSCounter {
protected:
    unsigned int m_fps;
    unsigned int m_fpscount;
    long m_fpsinterval;
public:
    FPSCounter()
        : m_fps(0)
        , m_fpscount(0)
        , m_fpsinterval(0)
    {
    }
    void update()
    {
        m_fpscount++;

        if (m_fpsinterval < time(nullptr)) {
            m_fps = m_fpscount;

            m_fpscount = 0;
            m_fpsinterval = time(nullptr) + 1;
        }
    }
    [[nodiscard]] unsigned int get() const
    {
        return m_fps;
    }
};

[[maybe_unused]] FPSCounter fps;
struct FRotator
{
    float Pitch;
    float Yaw;
    float Roll;
};
struct FTransform
{
    Quaternion Rotation;
    Vector3 Translation;
    Vector3 Scale3D;
    char pad2[0x8];
};
struct MinimalViewInfo
{
    Vector3 Location{};
    Vector3 LocationLocalSpace{};
    FRotator Rotation{};
	float FOV{};
};
struct CameraCacheEntry
{
    float TimeStamp{};
    [[maybe_unused]] char pad1[0xC]{};
    MinimalViewInfo POV;
};
struct Matrix {
    float M[4][4];
};
template<typename T>
struct TArray {
	struct FString;
	T * Data;
	int32_t Count;
	int32_t Max;
	T & operator[](int idx) {
		return Data[idx];
	}
	T & operator[](int idx) const {
		return Data[idx];
	}
};


struct FString : private TArray<unsigned short>
{
    FString() : TArray()
    {
    }

    explicit FString(const std::wstring& s) : TArray() {
        Max = Count = !s.empty() ? (s.length() * 2) + 1 : 0;
        if (Count) {
            Data = (unsigned short *)(s.data());
        }
    }
    explicit FString(const wchar_t *s) : FString(std::wstring(s)) {
    }
    FString(const wchar_t *s, int len) : FString(std::wstring(s, s + len)) {
    }

    explicit FString(const std::string s) : TArray() {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring ws = converter.from_bytes(s);
        Max = Count = !ws.empty() ? (ws.length() * 2) + 1 : 0;
        if (Count) {
            Data = (unsigned short *)(ws.data());
        }
    }

    explicit FString(const char *s) : FString(std::string(s)) {
    }

    FString(const char *s, int len) : FString(std::string(s, s + len)) {
    }

    [[nodiscard]] bool IsValid() const
    {
        return Data != nullptr;
    }

    [[maybe_unused]] [[nodiscard]] const wchar_t* ToWString() const
    {
        auto *output = new wchar_t[Count + 1];

        for (int i = 0; i < Count; i++) {
            const char16_t uc = Data[i];
            if (uc - 0xd800u >= 2048u) {
                output[i] = uc;
            } else {
                output[i] = L'?';
            }
        }

        output[Count] = 0;
        return output;
    }

    [[maybe_unused]] [[nodiscard]] std::string ToString() const {
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> converter;
        std::wstring wideStr(reinterpret_cast<const wchar_t*>(Data), Count);
        return converter.to_bytes(wideStr);
    }
/*
   const char* ToString() const
    {
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert;
        return convert.to_bytes(std::u16string(Data, Data + Count)).c_str();
    }*/
};


enum BoneID {
    Root = 0,
    Pelvis = 1,
    spine_01 = 2,
    spine_02 = 3,
    spine_03 = 4,
    neck_01 = 5,
    Head = 6,
    face_root = 7,
    eyebrows_pos_root = 8,
    eyebrows_root = 9,
    eyebrows_r = 10,
    eyebrows_l = 11,
    eyebrow_l = 12,
    eyebrow_r = 13,
    forehead_root = 14,
    forehead = 15,
    jaw_pos_root = 16,
    jaw_root = 17,
    jaw = 18,
    mouth_down_pos_root = 19,
    mouth_down_root = 20,
    lip_bm_01 = 21,
    lip_bm_02 = 22,
    lip_br = 23,
    lip_bl = 24,
    jaw_01 = 25,
    jaw_02 = 26,
    cheek_pos_root = 27,
    cheek_root = 28,
    cheek_r = 29,
    cheek_l = 30,
    nose_side_root = 31,
    nose_side_r_01 = 32,
    nose_side_r_02 = 33,
    nose_side_l_01 = 34,
    nose_side_l_02 = 35,
    eye_pos_r_root = 36,
    eye_r_root = 37,
    eye_rot_r_root = 38,
    eye_lid_u_r = 39,
    eye_r = 40,
    eye_lid_b_r = 41,
    eye_pos_l_root = 42,
    eye_l_root = 43,
    eye_rot_l_root = 44,
    eye_lid_u_l = 45,
    eye_l = 46,
    eye_lid_b_l = 47,
    nose_pos_root = 48,
    nose = 49,
    mouth_up_pos_root = 50,
    mouth_up_root = 51,
    lip_ul = 52,
    lip_um_01 = 53,
    lip_um_02 = 54,
    lip_ur = 55,
    lip_l = 56,
    lip_r = 57,
    hair_root = 58,
    hair_b_01 = 59,
    hair_b_02 = 60,
    hair_l_01 = 61,
    hair_l_02 = 62,
    hair_r_01 = 63,
    hair_r_02 = 64,
    hair_f_02 = 65,
    hair_f_01 = 66,
    hair_b_pt_01 = 67,
    hair_b_pt_02 = 68,
    hair_b_pt_03 = 69,
    hair_b_pt_04 = 70,
    hair_b_pt_05 = 71,
    camera_fpp = 72,
    GunReferencePoint = 73,
    GunRef = 74,
    breast_l = 75,
    breast_r = 76,
    clavicle_l = 77,
    upperarm_l = 78,
    lowerarm_l = 79,
    hand_l = 80,
    thumb_01_l = 81,
    thumb_02_l = 82,
    thumb_03_l = 83,
    thumb_04_l_MBONLY = 84,
    index_01_l = 85,
    index_02_l = 86,
    index_03_l = 87,
    index_04_l_MBONLY = 88,
    middle_01_l = 89,
    middle_02_l = 90,
    middle_03_l = 91,
    middle_04_l_MBONLY = 92,
    ring_01_l = 93,
    ring_02_l = 94,
    ring_03_l = 95,
    ring_04_l_MBONLY = 96,
    pinky_01_l = 97,
    pinky_02_l = 98,
    pinky_03_l = 99,
    pinky_04_l_MBONLY = 100,
    item_l = 101,
    lowerarm_twist_01_l = 102,
    upperarm_twist_01_l = 103,
    clavicle_r = 104,
    upperarm_r = 105,
    lowerarm_r = 106,
    hand_r = 107,
    thumb_01_r = 108,
    thumb_02_r = 109,
    thumb_03_r = 110,
    thumb_04_r_MBONLY = 111,
    index_01_r = 112,
    index_02_r = 113,
    index_03_r = 114,
    index_04_r_MBONLY = 115,
    middle_01_r = 116,
    middle_02_r = 117,
    middle_03_r = 118,
    middle_04_r_MBONLY = 119,
    ring_01_r = 120,
    ring_02_r = 121,
    ring_03_r = 122,
    ring_04_r_MBONLY = 123,
    pinky_01_r = 124,
    pinky_02_r = 125,
    pinky_03_r = 126,
    pinky_04_r_MBONLY = 127,
    item_r = 128,
    lowerarm_twist_01_r = 129,
    upperarm_twist_01_r = 130,
    BackPack = 131,
    backpack_01 = 132,
    backpack_02 = 133,
    Slot_Primary = 134,
    Slot_Secondary = 135,
    Slot_Melee = 136,
    slot_throwable = 137,
    coat_l_01 = 138,
    coat_l_02 = 139,
    coat_l_03 = 140,
    coat_l_04 = 141,
    coat_fl_01 = 142,
    coat_fl_02 = 143,
    coat_fl_03 = 144,
    coat_fl_04 = 145,
    coat_b_01 = 146,
    coat_b_02 = 147,
    coat_b_03 = 148,
    coat_b_04 = 149,
    coat_r_01 = 150,
    coat_r_02 = 151,
    coat_r_03 = 152,
    coat_r_04 = 153,
    coat_fr_01 = 154,
    coat_fr_02 = 155,
    coat_fr_03 = 156,
    coat_fr_04 = 157,
    thigh_l = 158,
    calf_l = 159,
    foot_l = 160,
    ball_l = 161,
    calf_twist_01_l = 162,
    thigh_twist_01_l = 163,
    thigh_r = 164,
    calf_r = 165,
    foot_r = 166,
    ball_r = 167,
    calf_twist_01_r = 168,
    thigh_twist_01_r = 169,
    Slot_SideArm = 170,
    skirt_l_01 = 171,
    skirt_l_02 = 172,
    skirt_l_03 = 173,
    skirt_f_01 = 174,
    skirt_f_02 = 175,
    skirt_f_03 = 176,
    skirt_b_01 = 177,
    skirt_b_02 = 178,
    skirt_b_03 = 179,
    skirt_r_01 = 180,
    skirt_r_02 = 181,
    skirt_r_03 = 182,
    ik_hand_root = 183,
    ik_hand_gun = 184,
    ik_hand_r = 185,
    ik_hand_l = 186,
    ik_aim_root = 187,
    ik_aim_l = 188,
    ik_aim_r = 189,
    ik_foot_root = 190,
    ik_foot_l = 191,
    ik_foot_r = 192,
    camera_tpp = 193,
    ik_target_root = 194,
    ik_target_l = 195,
    ik_target_r = 196,
    VB_spine_03_spine_03 = 197,
    VB_upperarm_r_lowerarm_r = 198
};
/*
Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
    Matrix result {};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                result.M[i][j] += lhs.M[i][k] * rhs.M[k][j];
            }
        }
    }
    return result;
}
*/
Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
    Matrix result{};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.M[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                result.M[i][j] += lhs.M[i][k] * rhs.M[k][j];
            }
        }
    }
    return result;
}

Vector3 MatrixToVector(Matrix matrix) {
    return {matrix.M[3][0], matrix.M[3][1], matrix.M[3][2]};
}


[[maybe_unused]] Matrix RotatorToMatrix(FRotator rotation) {
    float radPitch = rotation.Pitch * ((float) 3.14159265358979323846 / 180.0f);
    float radYaw = rotation.Yaw * ((float) 3.14159265358979323846 / 180.0f);
    float radRoll = rotation.Roll * ((float) 3.14159265358979323846 / 180.0f);

    float SP = sinf(radPitch);
    float CP = cosf(radPitch);
    float SY = sinf(radYaw);
    float CY = cosf(radYaw);
    float SR = sinf(radRoll);
    float CR = cosf(radRoll);

    Matrix matrix{};

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


Matrix TransformToMatrix(FTransform transform) {
    Matrix matrix{};
    // ... (existing code)
    // Add validation for quaternion normalization


    matrix.M[3][0] = transform.Translation.X;
    matrix.M[3][1] = transform.Translation.Y;
    matrix.M[3][2] = transform.Translation.Z;

    float x2 = transform.Rotation.X + transform.Rotation.X;
    float y2 = transform.Rotation.Y + transform.Rotation.Y;
    float z2 = transform.Rotation.Z + transform.Rotation.Z;

    float xx2 = transform.Rotation.X * x2;
    float yy2 = transform.Rotation.Y * y2;
    float zz2 = transform.Rotation.Z * z2;

    matrix.M[0][0] = (1.f - (yy2 + zz2)) * transform.Scale3D.X;
    matrix.M[1][1] = (1.f - (xx2 + zz2)) * transform.Scale3D.Y;
    matrix.M[2][2] = (1.f - (xx2 + yy2)) * transform.Scale3D.Z;

    float yz2 = transform.Rotation.Y * z2;
    float wx2 = transform.Rotation.W * x2;
    matrix.M[2][1] = (yz2 - wx2) * transform.Scale3D.Z;
    matrix.M[1][2] = (yz2 + wx2) * transform.Scale3D.Y;

    float xy2 = transform.Rotation.X * y2;
    float wz2 = transform.Rotation.W * z2;
    matrix.M[1][0] = (xy2 - wz2) * transform.Scale3D.Y;
    matrix.M[0][1] = (xy2 + wz2) * transform.Scale3D.X;

    float xz2 = transform.Rotation.X * z2;
    float wy2 = transform.Rotation.W * y2;
    matrix.M[2][0] = (xz2 + wy2) * transform.Scale3D.Z;
    matrix.M[0][2] = (xz2 - wy2) * transform.Scale3D.X;

    matrix.M[0][3] = 0;
    matrix.M[1][3] = 0;
    matrix.M[2][3] = 0;
    matrix.M[3][3] = 1;


    float norm = sqrt(transform.Rotation.X * transform.Rotation.X +
                      transform.Rotation.Y * transform.Rotation.Y +
                      transform.Rotation.Z * transform.Rotation.Z +
                      transform.Rotation.W * transform.Rotation.W);
    if (norm != 0) {
        transform.Rotation.X /= norm;
        transform.Rotation.Y /= norm;
        transform.Rotation.Z /= norm;
        transform.Rotation.W /= norm;
    }
    // ... rest of the code
}

/*
Matrix TransformToMatrix(FTransform transform) {
    Matrix matrix{};

    matrix.M[3][0] = transform.Translation.X;
    matrix.M[3][1] = transform.Translation.Y;
    matrix.M[3][2] = transform.Translation.Z;

    float x2 = transform.Rotation.X + transform.Rotation.X;
    float y2 = transform.Rotation.Y + transform.Rotation.Y;
    float z2 = transform.Rotation.Z + transform.Rotation.Z;

    float xx2 = transform.Rotation.X * x2;
    float yy2 = transform.Rotation.Y * y2;
    float zz2 = transform.Rotation.Z * z2;

    matrix.M[0][0] = (1.f - (yy2 + zz2)) * transform.Scale3D.X;
    matrix.M[1][1] = (1.f - (xx2 + zz2)) * transform.Scale3D.Y;
    matrix.M[2][2] = (1.f - (xx2 + yy2)) * transform.Scale3D.Z;

    float yz2 = transform.Rotation.Y * z2;
    float wx2 = transform.Rotation.W * x2;
    matrix.M[2][1] = (yz2 - wx2) * transform.Scale3D.Z;
    matrix.M[1][2] = (yz2 + wx2) * transform.Scale3D.Y;

    float xy2 = transform.Rotation.X * y2;
    float wz2 = transform.Rotation.W * z2;
    matrix.M[1][0] = (xy2 - wz2) * transform.Scale3D.Y;
    matrix.M[0][1] = (xy2 + wz2) * transform.Scale3D.X;

    float xz2 = transform.Rotation.X * z2;
    float wy2 = transform.Rotation.W * y2;
    matrix.M[2][0] = (xz2 + wy2) * transform.Scale3D.Z;
    matrix.M[0][2] = (xz2 - wy2) * transform.Scale3D.X;

    matrix.M[0][3] = 0;
    matrix.M[1][3] = 0;
    matrix.M[2][3] = 0;
    matrix.M[3][3] = 1;

    return matrix;
}
*/
[[maybe_unused]] Vector3 TransformToLocation(FTransform transform, FTransform c2w) {
    return MatrixToVector(TransformToMatrix(transform) * TransformToMatrix(c2w));
}

[[maybe_unused]] FRotator VectorToRotator(Vector3 rotation) {
    float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);

    FRotator newViewAngle = {0};
    newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Roll = (float) 0.f;

    if (rotation.X >= 0.f)
        newViewAngle.Yaw += 180.0f;

    return newViewAngle;
}

[[maybe_unused]] void ClampAngles(FRotator &angles) {
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

[[maybe_unused]] void ClampAngles(float *angles) {
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

[[maybe_unused]] void VectorToAngles(Vector3 v, Vector3 &a) {
    float tmp, yaw, pitch;

    if (v.Y == 0 && v.X == 0) {
        yaw = 0;
        if (v.Z > 0)
            pitch = 270;
        else
            pitch = 90;
    } else {
        yaw = (atan2(v.Y, v.X) * 180 / M_PI);
        if (yaw < 0)
            yaw += 360;

        tmp = sqrt(v.X * v.X + v.Y * v.Y);
        pitch = (atan2(-v.Z, tmp) * 180 / M_PI);
        if (pitch < 0)
            pitch += 360;
    }

    a.X = pitch;
    a.Y = yaw;
    a.Z = 0;
}
const char *GetVehicleName(uint8_t type) {
    switch (type) {
        case 1:  return "Motorcycle";
        case 2:  return "Sidecar Motorcycle";
        case 3:  return "Dacia";
        case 4:  return "Mini Bus";
        case 5:  return "Pickup (Open Top)";
        case 6:  return "Pickup (Closed Top)";
        case 7:  return "Buggy";
        case 8:  return "UAZ";
        case 9:  return "UAZ (Closed Top)";
        case 10: return "UAZ (Open Top)";
        case 11: return "PG-117";
        case 12: return "Jet Ski";
        case 14: return "Mirado (Closed Top)";
        case 15: return "Mirado (Open Top)";
        case 16: return "Rony";
        case 17: return "Scooter";
        case 18: return "Snowmobile";
        case 19: return "Tukshai";
        case 20: return "Snowbike";
        case 23: return "Helicopter UH-60";
        case 33: return "Mirado (Gold)";
        case 35: return "Armed Dacia";
        case 36: return "Armed Pickup";
        case 37: return "Armed Buggy";
        case 38: return "Armed UAZ";
        case 39: return "Armed Helicopter UH-60";
        case 60: return "Motor Glider";
        case 24: return "BRDM";
        case 53: return "Monster Truck";
        case 61: return "Coupe RB";
        case 51: return "Zima UAZ";
        case 65: return "Mountain Bike";
    }
    return "Vehicle";
}


FRotator ToRotator(Vector3 local, Vector3 target) {
    Vector3 rotation = local - target;
    FRotator newViewAngle = {0};
    float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);
    newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Roll = (float) 0.f;
    if (rotation.X >= 0.f)
        newViewAngle.Yaw += 180.0f;
    return newViewAngle;
}
