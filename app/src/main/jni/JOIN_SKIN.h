#include "Nrg.h"

struct JsonPreferences {
  
int xsuit = 0;
int skinm4 = 0;
int skinakm = 0;
int para = 0;
int bag = 0;
int helmet = 0;
bool CoupeRB = false;
bool Dacia = false;
bool UAZ = false;
bool MiniBus = false;
bool BigFoot = false;
bool Boat = false;
bool Mirado = false;
bool Buggy = false;
bool RZR = false;
bool OMirado = false;
bool Moto = false;
bool Emote = false;
bool Helmett = false;
bool Bagg = false;
bool Fac= false;
bool Face= false;
bool Outfit = false;
bool Parachute = false;
bool Hieuungbay = false;
bool Comrade = false;
bool M416 = false;
bool AKM = false;
bool SCARL = false;
bool M762 = false;
bool MG3 = false;
bool Honey = false;
bool S12K = false;
bool DBS = false;
bool S1897 = false;
bool AWM = false;
bool Machete = false;
bool AMR = false;
bool MK14 = false;
bool MINI14 =false;
bool KAR98 = false;
bool M24 = false;
bool M16 = false;
bool M249 = false;
bool DP28 = false;
bool GROZA = false;
bool FAMAS = false;
bool AUG = false;
bool QBZ = false;
bool PAN = false;
bool UZI = false;
bool UMP = false;
bool TOMMY = false;
bool P90 = false;
bool BIZON = false;
bool ACE32 = false;
bool VECTOR = false;

    struct sConfig {
     
        struct sModSkin {
  bool Enable = 1;
  bool HitEffect = 0;
  bool KillMessage = 0;
  bool DeadBox = 0;
  int XSuits = 1;
  int AKM = 1;
  int M16A4 = 1;
  int Scar = 1;
  int M416 = 1;
  int Groza = 1;
  int Famas =1;
  int AUG = 1;
  int QBZ = 1;
  int M762 = 1;
  int MG3 = 1;
  int Honey = 1;
  int S12K = 1;
  int DBS = 1;
  int S1897 = 1;
  int ACE32 = 1;
  int Parachute = 1;
  int Fac = 1;
  int Hieuungbay = 1;
  int Comrade = 1;
  int UZI = 1;
  int UMP = 1;
  int Vector = 1;
  int Thompson = 1;
  int P90 = 1;
  int Bizon = 1;
  int K98 = 1;
  int M24 = 1;
  int AWM = 1;
  int AMR = 1;
  int Machete = 1;
  int MK14 = 1;
  int MINI14 =1;
  int DP28 = 1;
  int M249 = 1;
  int Pan = 1;
  int Moto = 1;
  int CoupeRP = 1;
  int UAZ = 1;
  int Dacia = 1;
  int Bigfoot = 1;
  int Mirado = 1;
  int OMirado = 1;
  int Buggy = 1;
  int RZR = 1;
  int MiniBus = 1;
  int Boat = 1;
};
sModSkin Skin{false};
        
    };
    sConfig Config{false};

} preferences;

static int helmett1 = 1;
static int helmett2 = 1;
static int helmett3 = 1;
static int bag1 = 1;
static int bag2 = 1;
static int bag3 = 1;
bool ModSkinn = false;
bool KillMessage = false;
bool DeadBox = false;
int sEmote1 = 2200101;
int sEmote2 = 2200201;
int sEmote3 = 2200301;
int ModEmote1 = 1;
namespace Active {
   int SkinCarDefault = 0;
   int SkinCarMod = 0;
   int SkinCarNew = 0;
}
int newUAZID = 0;
int lastUAZID = 0;
int newDaciaID = 0;
int lastDaciaID = 0;
int newCoupeID = 0;
int lastCoupeID = 0;

struct snew_Skin {
    [[maybe_unused]] int XSuits = 403003; // Áo
    [[maybe_unused]] int XSuits1 = 40604002; // Đầu
    int quan = 404026; // quan
    int giay = 0;
    int Kaaba = 410517;


    [[maybe_unused]] int Balo1 = 501001;
    [[maybe_unused]] int Balo2 = 501002;
    [[maybe_unused]] int Balo3 = 501003;
    [[maybe_unused]] int Balo4 = 501004;
    [[maybe_unused]] int Balo5 = 501005;
    [[maybe_unused]] int Balo6 = 501006;
    [[maybe_unused]] [[maybe_unused]] int Helmet1 = 502001;
    [[maybe_unused]] int Helmet2 = 502002;
    [[maybe_unused]] int Helmet3 = 502003;
    [[maybe_unused]] int Helmet4 = 502004;
    [[maybe_unused]] int Helmet5 = 502005;

    [[maybe_unused]] int Helmet6 = 502114;
    [[maybe_unused]] int Helmet7 = 502115;
    [[maybe_unused]] int Helmet8 = 502116;
  int Parachute = 703001;
  int Fac = 1400560;
  int Hieuungbay = 4151001;
  int Comrade = 1601051;
    
    
  int AKM = 101001;
  int AKM_Mag = 291001;
    int AKM_flash = 201010;
    int AKM_compe = 201009;
    int AKM_silent = 201011;
    int AKM_reddot = 203001;
    int AKM_holo = 203002;
    int AKM_x2 = 203003;
    int AKM_x3 = 203014;
    int AKM_x4 = 203004;
    int AKM_x6 = 203015;
    int AKM_quickMag = 204012;
    int AKM_extendedMag = 204011;
    int AKM_quickNextended = 204013;
    
  int M16A4 = 101002;
  int M16A4_Stock = 205007;
  int M16A4_Mag = 291002;
    
    
  int Scar = 101003;
  int Scar_Mag = 291003;
    int Scar_3 = 203007;
    int Scar_flash = 201010;
    int Scar_compe = 201009;
    int Scar_silent = 201011;
    int Scar_reddot = 203001;
    int Scar_holo = 203002;
    int Scar_x2 = 203003;
    int Scar_x3 = 203014;
    int Scar_x4 = 203004;
    int Scar_x6 = 203015;
    int Scar_quickMag = 204012;
    int Scar_extendedMag = 204011;
    int Scar_quickNextended = 204013;
    int Scar_verical = 202002;
    int Scar_angle = 202001;
    int Scar_lightgrip = 202004;
    int Scar_pink = 202005;
    int Scar_lazer = 202007;
    int Scar_thumb = 202006;
    
    
  int Pan = 108004;

  int M416_1 = 101004;
  int M416_2 = 291004;
  int M416_3 = 203008;
  int M416_4 = 205005;
  int M416_flash = 201010;
  int M416_compe = 201009;
  int M416_silent = 201011;
  int M416_reddot = 203001;
  int M416_holo = 203002;
  int M416_x2 = 203003;
  int M416_x3 = 203014;
  int M416_x4 = 203004;
  int M416_x6 = 203015;
  int M416_quickMag = 204012;
  int M416_extendedMag = 204011;
  int M416_quickNextended = 204013;
  int M416_stock = 205002;
  int M416_verical = 203015;
  int M416_angle = 202001;
  int M416_lightgrip = 202004;
  int M416_pink = 202005;
  int M416_lazer = 202007;
  int M416_thumb = 202006;
    
    int K98 = 103001;
  int K98_reddot = 203001;
    int K98_holo = 203002;
    int K98_x2 = 203003;
    int K98_x3 = 203014;
    int K98_x4 = 203004;
    int K98_x6 = 203015;
    int K98_x8 = 203005;
    
    
    

  int Groza = 101005;
    int Groza_2 = 291005;
    int Groza_silent = 201011;
    int Groza_reddot = 203001;
    int Groza_holo = 203002;
    int Groza_x2 = 203003;
    int Groza_x3 = 203014;
    int Groza_x4 = 203004;
    int Groza_x6 = 203015;
    int Groza_quickMag = 204012;
    int Groza_extendedMag = 204011;
    int Groza_quickNextended = 204013;
    
    int Famas = 101100;
    int Famas_reddot = 203001;
      int Famas_holo = 203002;
      int Famas_x2 = 203003;
      int Famas_x3 = 203014;
      int Famas_x4 = 203004;
      int Famas_x6 = 203015;
    
    
    
    
    
  int QBZ = 101007;
    
    
    
    
  int AUG = 101006;
    int AUG_reddot = 203001;
    int AUG_holo = 203002;
    int AUG_x2 = 203003;
    int AUG_x3 = 203014;
    int AUG_x4 = 203004;
    int AUG_x6 = 203015;
    int AUG_lazer = 202007;
    int AUG_flash = 201010;

    
    
    
  int M762 = 101008;
  int M762_Mag = 291008;
    int M762_reddot = 203001;
    int M762_holo = 203002;
    int M762_x2 = 203003;
    int M762_x3 = 203014;
    int M762_x4 = 203004;
    int M762_x6 = 203015;
    int M762_lazer = 202007;
    int M762_flash = 201010;

    
    
    
    
    
    
  int ACE32 = 101102;
      int ACE32_reddot = 203001;
      int ACE32_holo = 203002;
      int ACE32_x2 = 203003;
      int ACE32_x3 = 203014;
      int ACE32_x4 = 203004;
      int ACE32_x6 = 203015;
    
    
    
  int Honey = 101012;
  int UZI = 102001;
    
  int UMP = 102002;
    int UMP_reddot = 203001;
    int UMP_holo = 203002;
    int UMP_x2 = 203003;
    int UMP_x3 = 203014;
    int UMP_x4 = 203004;
    int UMP_x6 = 203015;
    
    
    
  int Vector = 102003;
  int Thompson = 102004;
  int P90 = 102105;
  int Bizon = 102005;
  int M24 = 103002;
    int M24_reddot = 203001;
      int M24_holo = 203002;
      int M24_x2 = 203003;
      int M24_x3 = 203014;
      int M24_x4 = 203004;
      int M24_x6 = 203015;
      int M24_x8 = 203005;
    
    
    
    
  int AWM = 103003;
    int AWM_reddot = 203001;
      int AWM_holo = 203002;
      int AWM_x2 = 203003;
      int AWM_x3 = 203014;
      int AWM_x4 = 203004;
      int AWM_x6 = 203015;
      int AWM_x8 = 203005;
    
    
    
    
  int AMR = 103012;
    int AMR_reddot = 203001;
      int AMR_holo = 203002;
      int AMR_x2 = 203003;
      int AMR_x3 = 203014;
      int AMR_x4 = 203004;
      int AMR_x6 = 203015;
      int AMR_x8 = 203005;
 
int FAMAS = 101100;
    int FAMAS_reddot = 203001;
      int FAMAS_holo = 203002;
      int FAMAS_x2 = 203003;
      int FAMAS_x3 = 203014;
      int FAMAS_x4 = 203004;
      int FAMAS_x6 = 203015;
    
    
    
  int Machete = 108001;
  int VSS = 103005;
  int SKS = 103004;
  int Mini14 = 103006;
  int MK14 = 103007;
  int SLR = 103009;
  int S1897 = 104002;
  int DP28 = 105002;
  int M249 = 105001;
    
    
  int MG3 = 105010;
    int MG3_reddot = 203001;
    int MG3_holo = 203002;
    int MG3_x2 = 203003;
    int MG3_x3 = 203014;
    int MG3_x4 = 203004;
    int MG3_x6 = 203015;
    
    
    
    
    
    
    
    
  int DBS = 104004;
  int S12K = 104003;
  int Skorpion = 106008;
  int Moto = 1901001;
  int CoupeRP = 1961001;
  int Dacia = 1903001;
  int UAZ = 1908001;
  int Bigfoot = 1953001;
  int Mirado = 1914004;
  int OMirado = 1915001;
  int Buggy = 1907001;
  int RZR = 1966017;
  int MiniBus = 1904001;
  int Boat = 1911001;
  int M249s = 205009;

};

inline snew_Skin new_Skin;

std::chrono::steady_clock::time_point lastChangeTime;
std::chrono::steady_clock::time_point lastWeaponChangeTime;

void updateSkin() {
    if (preferences.bag == 0)
        bag1 = 501001;
    if (preferences.bag == 1)
        bag1 = 1501003174; //blood raven x suit
    if (preferences.bag == 2)
        bag1 = 1501003220; //Golden Pharaoh X-Suit
    if (preferences.bag == 3)
        bag1 = 1501003607; //Avalanche
    if (preferences.bag == 4)
        bag1 = 1501003318; //Irresidence
    if (preferences.bag == 5)
        bag1 = 1501003411; //Poseidon
    if (preferences.bag == 6)
        bag1 = 1501003422; //Arcane Jester X-suit
    if (preferences.bag == 7)
        bag1 = 1501003443; //Silvanus X-Suit
    if (preferences.bag == 8)
        bag1 = 1501003466;
    if (preferences.bag == 9)
        bag1 = 1501003061;
    if (preferences.bag == 10)
        bag1 = 1501003047;
    if (preferences.bag == 11)
        bag1 = 1501003039;
    if (preferences.bag == 12)
        bag1 = 1501003471;
    if (preferences.bag == 13)
        bag1 = 1501003487;
    if (preferences.bag == 14)
        bag1 = 1501003503;
    if (preferences.bag == 15)
        bag1 = 1501003515;
    if (preferences.bag == 16)
        bag1 = 1501003550;
    if (preferences.bag == 17)
        bag1 = 1501003558;
    if (preferences.bag == 18)
        bag1 = 1501003058;
    if (preferences.bag == 19)
        bag1 = 1501003057;
    if (preferences.bag == 20)
        bag1 = 1501003051;
    if (preferences.bag == 21)
        bag1 = 1501003043;
    if (preferences.bag == 22)
        bag1 = 1501003042;
    if (preferences.bag == 23)
        bag1 = 1501003229;
    if (preferences.bag == 24)
        bag1 = 1501003023;
    if (preferences.bag == 25)
        bag1 = 1501003022;
    if (preferences.bag == 26)
        bag1 = 1501003608;
    if (preferences.bag == 27)
        bag1 = 1501003605;
    
    
    
    if (preferences.bag == 0)
        bag2 = 501002;
    if (preferences.bag == 1)
        bag2 = 1501003174; //blood raven x suit
    if (preferences.bag == 2)
        bag2 = 1501003220; //Golden Pharaoh X-Suit
    if (preferences.bag == 3)
        bag2 = 1501003607; //Avalanche
    if (preferences.bag == 4)
        bag2 = 1501003318; //Irresidence
    if (preferences.bag == 5)
        bag2 = 1501003411; //Poseidon
    if (preferences.bag == 6)
        bag2 = 1501003422; //Arcane Jester X-suit
    if (preferences.bag == 7)
        bag2 = 1501003443; //Silvanus X-Suit
    if (preferences.bag == 8)
        bag2 = 1501003466;
    if (preferences.bag == 9)
        bag2 = 1501003061;
    if (preferences.bag == 10)
        bag2 = 1501003047;
    if (preferences.bag == 11)
        bag2 = 1501003039;
    if (preferences.bag == 12)
        bag2 = 1501003471;
    if (preferences.bag == 13)
        bag2 = 1501003487;
    if (preferences.bag == 14)
        bag2 = 1501003503;
    if (preferences.bag == 15)
        bag2 = 1501003515;
    if (preferences.bag == 16)
        bag2 = 1501003550;
    if (preferences.bag == 17)
        bag2 = 1501003558;
    if (preferences.bag == 18)
        bag2 = 1501003058;
    if (preferences.bag == 19)
        bag2 = 1501003057;
    if (preferences.bag == 20)
        bag2 = 1501003051;
    if (preferences.bag == 21)
        bag2 = 1501003043;
    if (preferences.bag == 22)
        bag2 = 1501003042;
    if (preferences.bag == 23)
        bag2 = 1501003229;
    if (preferences.bag == 24)
        bag2 = 1501003023;
    if (preferences.bag == 25)
        bag2 = 1501003022;
    if (preferences.bag == 26)
        bag2 = 1501003608;
    if (preferences.bag == 27)
        bag2 = 1501003605;
    
    
    
    
    
    if (preferences.bag == 0)
        bag3 = 501003;
    if (preferences.bag == 1)
        bag3 = 1501003174; //blood raven x suit
    if (preferences.bag == 2)
        bag3 = 1501003220; //Golden Pharaoh X-Suit
    if (preferences.bag == 3)
        bag3 = 1501003607; //Avalanche
    if (preferences.bag == 4)
        bag3 = 1501003318; //Irresidence
    if (preferences.bag == 5)
        bag3 = 1501003411; //Poseidon
    if (preferences.bag == 6)
        bag3 = 1501003422; //Arcane Jester X-suit
    if (preferences.bag == 7)
        bag3 = 1501003443; //Silvanus X-Suit
    if (preferences.bag == 8)
        bag3 = 1501003466;
    if (preferences.bag == 9)
        bag3 = 1501003061;
    if (preferences.bag == 10)
        bag3 = 1501003047;
    if (preferences.bag == 11)
        bag3 = 1501003039;
    if (preferences.bag == 12)
        bag3 = 1501003471;
    if (preferences.bag == 13)
        bag3 = 1501003487;
    if (preferences.bag == 14)
        bag3 = 1501003503;
    if (preferences.bag == 15)
        bag3 = 1501003515;
    if (preferences.bag == 16)
        bag3 = 1501003550;
    if (preferences.bag == 17)
        bag3 = 1501003558;
    if (preferences.bag == 18)
        bag3 = 1501003058;
    if (preferences.bag == 19)
        bag3 = 1501003057;
    if (preferences.bag == 20)
        bag3 = 1501003051;
    if (preferences.bag == 21)
        bag3 = 1501003043;
    if (preferences.bag == 22)
        bag3 = 1501003042;
    if (preferences.bag == 23)
        bag3 = 1501003229;
    if (preferences.bag == 24)
        bag3 = 1501003023;
    if (preferences.bag == 25)
        bag3 = 1501003022;
    if (preferences.bag == 26)
        bag3 = 1501003608;
    if (preferences.bag == 27)
        bag3 = 1501003605;
    
    
    
    
    if (preferences.helmet == 0)
        helmett1 = 502001;
    if (preferences.helmet == 1)
        helmett1 = 1502003014; //blood raven x suit
    if (preferences.helmet == 2)
        helmett1 = 1502003349; //Golden Pharaoh X-Suit
    if (preferences.helmet == 3)
        helmett1 = 1502003012; //Avalanche
    if (preferences.helmet == 4)
        helmett1 = 1502003009; //Irresidence
    if (preferences.helmet == 5)
        helmett1 = 1502003397; //Poseidon
    if (preferences.helmet == 6)
        helmett1 = 1502003390; //Arcane Jester X-suit
    if (preferences.helmet == 7)
        helmett1 = 1502003381; //Silvanus X-Suit
    if (preferences.helmet == 8)
        helmett1 = 1502003358;
    if (preferences.helmet == 9)
        helmett1 = 1502003350;
    if (preferences.helmet == 10)
        helmett1= 1502003342;
    if (preferences.helmet == 11)
        helmett1 = 1502003336;
    if (preferences.helmet == 12)
        helmett1 = 1502003333;
    if (preferences.helmet == 13)
        helmett1 = 1502003327;
    if (preferences.helmet == 14)
        helmett1 = 1502003325;
    if (preferences.helmet == 15)
        helmett1 = 1502003299;
    if (preferences.helmet == 16)
        helmett1 = 1502003295;
    if (preferences.helmet == 17)
        helmett1 = 1502003222;
    if (preferences.helmet == 18)
        helmett1 = 1502003069;
    if (preferences.helmet == 19)
        helmett1 = 1502003054;
    if (preferences.helmet == 20)
        helmett1 = 1502003033;
    if (preferences.helmet == 21)
        helmett1 = 1502003016;
    if (preferences.helmet == 22)
        helmett1 = 1502003031;
    if (preferences.helmet == 23)
        helmett1 = 1502003023;
    if (preferences.helmet == 24)
        helmett1 = 1502003018;
    if (preferences.helmet == 25)
        helmett1 = 1502003410;
    if (preferences.helmet == 26)
        helmett1 = 1502003408;
    
    if (preferences.helmet == 0)
        helmett2 = 502002;
    if (preferences.helmet == 1)
        helmett2 = 1502003014; //blood raven x suit
    if (preferences.helmet == 2)
        helmett2 = 1502003349; //Golden Pharaoh X-Suit
    if (preferences.helmet == 3)
        helmett2 = 1502003012; //Avalanche
    if (preferences.helmet == 4)
        helmett2 = 1502003009; //Irresidence
    if (preferences.helmet == 5)
        helmett2 = 1502003397; //Poseidon
    if (preferences.helmet == 6)
        helmett2 = 1502003390; //Arcane Jester X-suit
    if (preferences.helmet == 7)
        helmett2 = 1502003381; //Silvanus X-Suit
    if (preferences.helmet == 8)
        helmett2 = 1502003358;
    if (preferences.helmet == 9)
        helmett2 = 1502003350;
    if (preferences.helmet == 10)
        helmett2 = 1502003342;
    if (preferences.helmet == 11)
        helmett2 = 1502003336;
    if (preferences.helmet == 12)
        helmett2 = 1502003333;
    if (preferences.helmet == 13)
        helmett2 = 1502003327;
    if (preferences.helmet == 14)
        helmett2 = 1502003325;
    if (preferences.helmet == 15)
        helmett2 = 1502003299;
    if (preferences.helmet == 16)
        helmett2 = 1502003295;
    if (preferences.helmet == 17)
        helmett2 = 1502003222;
    if (preferences.helmet == 18)
        helmett2 = 1502003069;
    if (preferences.helmet == 19)
        helmett2 = 1502003054;
    if (preferences.helmet == 20)
        helmett2 = 1502003033;
    if (preferences.helmet == 21)
        helmett2 = 1502003016;
    if (preferences.helmet == 22)
        helmett2 = 1502003031;
    if (preferences.helmet == 23)
        helmett2 = 1502003023;
    if (preferences.helmet == 24)
        helmett2 = 1502003018;
    if (preferences.helmet == 25)
        helmett2 = 1502003410;
    if (preferences.helmet == 26)
        helmett2  = 1502003408;
    
    
    if (preferences.helmet == 0)
        helmett3 = 502003;
    if (preferences.helmet == 1)
        helmett3 = 1502003014; //blood raven x suit
    if (preferences.helmet == 2)
        helmett3 = 1502003349; //Golden Pharaoh X-Suit
    if (preferences.helmet == 3)
        helmett3 = 1502003012; //Avalanche
    if (preferences.helmet == 4)
        helmett3 = 1502003009; //Irresidence
    if (preferences.helmet == 5)
        helmett3 = 1502003397; //Poseidon
    if (preferences.helmet == 6)
        helmett3 = 1502003390; //Arcane Jester X-suit
    if (preferences.helmet == 7)
        helmett3 = 1502003381; //Silvanus X-Suit
    if (preferences.helmet == 8)
        helmett3 = 1502003358;
    if (preferences.helmet == 9)
        helmett3 = 1502003350;
    if (preferences.helmet == 10)
        helmett3 = 1502003342;
    if (preferences.helmet == 11)
        helmett3 = 1502003336;
    if (preferences.helmet == 12)
        helmett3 = 1502003333;
    if (preferences.helmet == 13)
        helmett3 = 1502003327;
    if (preferences.helmet == 14)
        helmett3 = 1502003325;
    if (preferences.helmet == 15)
        helmett3 = 1502003299;
    if (preferences.helmet == 16)
        helmett3 = 1502003295;
    if (preferences.helmet == 17)
        helmett3 = 1502003222;
    if (preferences.helmet == 18)
        helmett3 = 1502003069;
    if (preferences.helmet == 19)
        helmett3 = 1502003054;
    if (preferences.helmet == 20)
        helmett3 = 1502003033;
    if (preferences.helmet == 21)
        helmett3 = 1502003016;
    if (preferences.helmet == 22)
        helmett3 = 1502003031;
    if (preferences.helmet == 23)
        helmett3 = 1502003023;
    if (preferences.helmet == 24)
        helmett3 = 1502003018;
    if (preferences.helmet == 25)
        helmett3 = 1502003410;
    if (preferences.helmet == 26)
        helmett3 = 1502003408;
    
    
    
    
    
    
    
    
    if (ModEmote1 == 0)
        sEmote1 = 2200101;
    if (ModEmote1 == 1)
        sEmote1 = 12220023;
    if (ModEmote1 == 2)
        sEmote1 = 12219677;
    if (ModEmote1 == 3)
        sEmote1 = 12219716;
    if (ModEmote1 == 4)
        sEmote1 = 12209401;
    if (ModEmote1 == 5)
        sEmote1 = 12209501;
    if (ModEmote1 == 6)
        sEmote1 = 12209701;
    if (ModEmote1 == 7)
        sEmote1 = 12209801;
    if (ModEmote1 == 8)
        sEmote1 = 12209901;
    
    
    if (ModEmote1 == 0)
        sEmote2 = 2200201;
    if (ModEmote1 == 1)
        sEmote2 = 12210201;
    if (ModEmote1 == 2)
        sEmote2 = 12210601;
    if (ModEmote1 == 3)
        sEmote2 = 12220028;
    if (ModEmote1 == 4)
        sEmote2 = 12219819;
    if (ModEmote1 == 5)
        sEmote2 = 12211801;
    if (ModEmote1 == 6)
        sEmote2 = 12212001;
    if (ModEmote1 == 7)
        sEmote2 = 12212201;
    if (ModEmote1 == 8)
        sEmote2 = 12212401;
    
    
    if (ModEmote1 == 0)
        sEmote3 = 2200301;
    if (ModEmote1 == 1)
        sEmote3 = 12212601;
    if (ModEmote1 == 2)
        sEmote3 = 12213201;
    if (ModEmote1 == 3)
        sEmote3 = 12219715;
    if (ModEmote1 == 4)
        sEmote3 = 12219814;
    if (ModEmote1 == 5)
        sEmote3 = 12213601;
    if (ModEmote1 == 6)
        sEmote3 = 12213801;
    if (ModEmote1 == 7)
        sEmote3 = 12214001;
    if (ModEmote1 == 8)
        sEmote3 = 12214201;
    
    
    
    if (preferences.Config.Skin.Parachute == 0)
        new_Skin.Parachute = 703001;
    if (preferences.Config.Skin.Parachute == 1)
        new_Skin.Parachute = 1401619; //Pharaoh's Scarab Parachute
    if (preferences.Config.Skin.Parachute == 2)
        new_Skin.Parachute = 1401625; // Enigmatic Nomad Parachute
    if (preferences.Config.Skin.Parachute == 3)
        new_Skin.Parachute = 1401624; //parashot Parachute
    if (preferences.Config.Skin.Parachute == 4)
        new_Skin.Parachute = 1401836; //Paperfold Gambit Parachute
    if (preferences.Config.Skin.Parachute == 5)
        new_Skin.Parachute = 1401833; //Labyrinth Beast Parachute
    if (preferences.Config.Skin.Parachute == 6)
        new_Skin.Parachute = 1401287; //Flamewraith Parachute
    if (preferences.Config.Skin.Parachute == 7)
        new_Skin.Parachute = 1401282; //Mega Kitty Parachute
    if (preferences.Config.Skin.Parachute == 8)
        new_Skin.Parachute = 1401385; //Mega Yeti Parachute
    if (preferences.Config.Skin.Parachute == 9)
        new_Skin.Parachute = 1401549; //Endless Glory Parachute
    if (preferences.Config.Skin.Parachute == 10)
        new_Skin.Parachute = 1401336; //Magma Skull Parachute
    if (preferences.Config.Skin.Parachute == 11)
        new_Skin.Parachute = 1401335; //Aquatic Fury Parachute
    if (preferences.Config.Skin.Parachute == 12)
        new_Skin.Parachute = 1401629; //CyberGen: Zero Parachute
    if (preferences.Config.Skin.Parachute == 13)
        new_Skin.Parachute = 1401628; //Radiant Phoenix Adarna Parachute
    if (preferences.Config.Skin.Parachute == 14)
        new_Skin.Parachute = 1401615; //Will of Horus
    if (preferences.Config.Skin.Parachute == 15)
        new_Skin.Parachute = 1401613; //Anubian Magistrate Parachute
    
    
    if (preferences.Config.Skin.Hieuungbay == 0)
        new_Skin.Hieuungbay = 4151001;
    if (preferences.Config.Skin.Hieuungbay == 1)
        new_Skin.Hieuungbay = 4151050; //Pharaoh's Scarab Parachute
    if (preferences.Config.Skin.Hieuungbay == 2)
        new_Skin.Hieuungbay = 4151052; // Enigmatic Nomad Parachute
    if (preferences.Config.Skin.Hieuungbay == 3)
        new_Skin.Hieuungbay = 4151054; //parashot Parachute
    if (preferences.Config.Skin.Hieuungbay == 4)
        new_Skin.Hieuungbay = 4151039; //Paperfold Gambit Parachute
    if (preferences.Config.Skin.Hieuungbay == 5)
        new_Skin.Hieuungbay = 4151048;
    if (preferences.Config.Skin.Hieuungbay == 6)
        new_Skin.Hieuungbay = 4151065;
    if (preferences.Config.Skin.Hieuungbay == 7)
        new_Skin.Hieuungbay = 4151066;
    if (preferences.Config.Skin.Hieuungbay == 8)
        new_Skin.Hieuungbay = 4151068;
    if (preferences.Config.Skin.Hieuungbay == 9)
        new_Skin.Hieuungbay = 4151070;
    if (preferences.Config.Skin.Hieuungbay == 10)
        new_Skin.Hieuungbay = 4151064;
    if (preferences.Config.Skin.Hieuungbay == 10)
        new_Skin.Hieuungbay = 4151067;
    if (preferences.Config.Skin.Hieuungbay == 11)
        new_Skin.Hieuungbay = 4151072;
    if (preferences.Config.Skin.Hieuungbay == 12)
        new_Skin.Hieuungbay = 4151075;
    if (preferences.Config.Skin.Hieuungbay == 13)
        new_Skin.Hieuungbay = 4151073;
    if (preferences.Config.Skin.Hieuungbay == 14)
        new_Skin.Hieuungbay = 4151085;
    if (preferences.Config.Skin.Hieuungbay == 15)
        new_Skin.Hieuungbay = 4151041;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    if (preferences.Config.Skin.Hieuungbay == 0)
        new_Skin.Hieuungbay = 4151001;
    if (preferences.Config.Skin.Hieuungbay == 1)
        new_Skin.Hieuungbay = 4151050; //Pharaoh's Scarab Parachute
    if (preferences.Config.Skin.Hieuungbay == 2)
        new_Skin.Hieuungbay = 4151052; // Enigmatic Nomad Parachute
    
    
    
    
    
    
    
    if (preferences.Config.Skin.Fac == 0)
        new_Skin.Fac = 1400560;
    if (preferences.Config.Skin.Fac == 1)
        new_Skin.Fac = 1400563; //Pharaoh's Scarab Parachute
    if (preferences.Config.Skin.Fac == 2)
        new_Skin.Fac = 1406001; // Enigmatic N
    
    
    
    if (preferences.Config.Skin.Pan == 0)
        new_Skin.Pan = 108004; // 108004 - Pan
    if (preferences.Config.Skin.Pan == 1)
        new_Skin.Pan = 1108004125; // Honeypot - Pan
    if (preferences.Config.Skin.Pan == 2)
        new_Skin.Pan = 1108004145; // Night of Rock - Pan
    if (preferences.Config.Skin.Pan == 3)
        new_Skin.Pan = 1108004160; // Crocodile - Pan
    if (preferences.Config.Skin.Pan == 4)
        new_Skin.Pan = 1108004283; // Accolade - Pan
    if (preferences.Config.Skin.Pan == 5)
        new_Skin.Pan = 1108004337; // Break Pad - Pan
    if (preferences.Config.Skin.Pan == 6)
        new_Skin.Pan = 1108004356; // Chicken Hot - Pan
    if (preferences.Config.Skin.Pan == 7)
        new_Skin.Pan = 1108004365; // Faerie Luster - Pan
    if (preferences.Config.Skin.Pan == 8)
        new_Skin.Pan = 1108004054; // Chicken Hot - Pan
    if (preferences.Config.Skin.Pan == 9)
        new_Skin.Pan = 1108004008;
    
    
    //--- Trang Phục -------
    
    if (preferences.Config.Skin.XSuits == 0) {
        new_Skin.XSuits = 403003;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 1) {
        new_Skin.XSuits = 1405628;
        new_Skin.XSuits1 = 1402578;
    }
    if (preferences.Config.Skin.XSuits == 2) {
        new_Skin.XSuits = 1405870;
        new_Skin.XSuits1 = 1403257;
    }
    if (preferences.Config.Skin.XSuits == 3) {
        new_Skin.XSuits = 1407140;
        new_Skin.XSuits1 = 1402874;
    }
    if (preferences.Config.Skin.XSuits == 4) {
        new_Skin.XSuits = 1407141;
        new_Skin.XSuits1 = 1403393;
    }
    if (preferences.Config.Skin.XSuits == 5) {
        new_Skin.XSuits = 1406311;
        new_Skin.XSuits1 = 1410011; //Mặt nạ 1.403.414
    }
    if (preferences.Config.Skin.XSuits == 6) {
        new_Skin.XSuits = 1406475;
        new_Skin.XSuits1 = 1410131;
    }
    if (preferences.Config.Skin.XSuits == 7) {
        new_Skin.XSuits = 1406638;
        new_Skin.XSuits1 = 1410242;
    }
    if (preferences.Config.Skin.XSuits == 8) {
        new_Skin.XSuits = 1406872;
        //new_Skin.XSuits1 = 1410346; // khung
        new_Skin.XSuits1 = 402133;
    }
    if (preferences.Config.Skin.XSuits == 9) {
        new_Skin.XSuits = 1406971;
        new_Skin.XSuits1 = 402147;
    }
    if (preferences.Config.Skin.XSuits == 10) {
        new_Skin.XSuits = 1407103;
        new_Skin.XSuits1 = 40604002;
    }
    
    if (preferences.Config.Skin.XSuits == 11) {
        new_Skin.XSuits = 1407391;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 12) {
        new_Skin.XSuits = 1407366;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 13) {
        new_Skin.XSuits = 1407330;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 14) {
        new_Skin.XSuits = 1407329;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 15) {
        new_Skin.XSuits = 1407286;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 16) {
        new_Skin.XSuits = 1407285;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 17) {
        new_Skin.XSuits = 1407277;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 18) {
        new_Skin.XSuits = 1407276;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 19) {
        new_Skin.XSuits = 1407275;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 20) {
        new_Skin.XSuits = 1407225;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 21) {
        new_Skin.XSuits = 1407224;
        new_Skin.XSuits1 = 40604002;
    }
    
    if (preferences.Config.Skin.XSuits == 23) {
        new_Skin.XSuits = 1407259;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 24) {
        new_Skin.XSuits = 1407161;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 25) {
        new_Skin.XSuits = 1407160;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 26) {
        new_Skin.XSuits = 1407107;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 27) {
        new_Skin.XSuits = 1407106;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 28) {
        new_Skin.XSuits = 1407079;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 29) {
        new_Skin.XSuits = 1407048;
        new_Skin.XSuits1 = 40604002;
    }
    
    if (preferences.Config.Skin.XSuits == 30) {
        new_Skin.XSuits = 1406977;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 31) {
        new_Skin.XSuits = 1406976;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 32) {
        new_Skin.XSuits = 1406898;
        new_Skin.XSuits1 = 40604002;
    }
    
    if (preferences.Config.Skin.XSuits == 33) {
        new_Skin.XSuits = 1400569;
        new_Skin.quan = 1400650;
        new_Skin.giay = 1404003;
    }
    if (preferences.Config.Skin.XSuits == 34) {
        new_Skin.XSuits = 1404000;
        new_Skin.quan = 1404002;
        new_Skin.giay = 1404003;
        new_Skin.Kaaba = 1410323;
    }
    if (preferences.Config.Skin.XSuits == 35) {
        new_Skin.XSuits = 1404049;
        new_Skin.quan = 1404050;
        new_Skin.giay = 1404051;
    }
    if (preferences.Config.Skin.XSuits == 36) {
        new_Skin.XSuits = 1400119;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 37) {
        new_Skin.XSuits = 1400117;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 38) {
        new_Skin.XSuits = 1406060;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 39) {
        new_Skin.XSuits = 1406891;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 40) {
        new_Skin.XSuits = 1400687;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 41) {
        new_Skin.XSuits = 1405160;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 42) {
        new_Skin.XSuits = 1405145;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 43) {
        new_Skin.XSuits = 1405436;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 44) {
        new_Skin.XSuits = 1405435;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 45) {
        new_Skin.XSuits = 1405434;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 46) {
        new_Skin.XSuits = 1405064;
        new_Skin.XSuits1 = 40604002;
    }
    
    
    if (preferences.Config.Skin.XSuits == 47) {
        new_Skin.XSuits = 1405207;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 48) {
        new_Skin.XSuits = 1406895;
        new_Skin.XSuits1 = 40604002;
    }
    
    if (preferences.Config.Skin.XSuits == 49) {
        new_Skin.XSuits = 1400333;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 50) {
        new_Skin.XSuits = 1400377;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 51) {
        new_Skin.XSuits = 1405092;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 52) {
        new_Skin.XSuits = 1405121;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 53) {
        new_Skin.XSuits = 1406889;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 54) {
        new_Skin.XSuits = 1407278;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 55) {
        new_Skin.XSuits = 1407279;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 56) {
        new_Skin.XSuits = 1407381;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 57) {
        new_Skin.XSuits = 1407380;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 58) {
        new_Skin.XSuits = 1407385;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 59) {
        new_Skin.XSuits = 1406389;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 60) {
        new_Skin.XSuits = 1406388;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 61) {
        new_Skin.XSuits = 1406387;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 62) {
        new_Skin.XSuits = 1406386;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 63) {
        new_Skin.XSuits = 1406385;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 64) {
        new_Skin.XSuits = 1406140;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 65) {
        new_Skin.XSuits = 1400782;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 66) {
        new_Skin.XSuits = 1407392;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 67) {
        new_Skin.XSuits = 1407318;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 68) {
        new_Skin.XSuits = 1407317;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 69) {
        new_Skin.XSuits = 1407404;
        new_Skin.XSuits1 = 40604002;
    }
    
    if (preferences.Config.Skin.XSuits == 70) {
        new_Skin.XSuits = 1407402;
        new_Skin.XSuits1 = 40604002;
    }
    
    
    if (preferences.Config.Skin.XSuits == 71) {
        new_Skin.XSuits = 1407401;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 72) {
        new_Skin.XSuits = 1407387;
        new_Skin.XSuits1 = 40604002;
    }
    if (preferences.Config.Skin.XSuits == 73) {
        new_Skin.XSuits = 1407066;
        new_Skin.XSuits1 = 40604002;
        new_Skin.Kaaba = 1410517;
    }
  
    
    
    
    
    
    //----------------------
    
    if (preferences.Config.Skin.AKM == 0) {
        new_Skin.AKM = 101001;
        new_Skin.AKM_Mag = 291001;
        new_Skin.AKM_flash = 201010;
        new_Skin.AKM_compe = 201009;
        new_Skin.AKM_silent = 201011;
        new_Skin.AKM_reddot = 203001;
        new_Skin.AKM_holo = 203002;
        new_Skin.AKM_x2 = 203003;
        new_Skin.AKM_x3 = 203014;
        new_Skin.AKM_x4 = 203004;
        new_Skin.AKM_x6 = 203015;
        new_Skin.AKM_quickMag = 204012;
        new_Skin.AKM_extendedMag = 204011;
        new_Skin.AKM_quickNextended = 204013;
    }
    if (preferences.Config.Skin.AKM == 1){
        new_Skin.AKM = 1101001213;
        new_Skin.AKM_Mag = 1010012131;
        new_Skin.AKM_flash = 1010012067;
        new_Skin.AKM_compe = 1010012068;
        new_Skin.AKM_silent = 1010012069;
        new_Skin.AKM_reddot = 1010012066;
        new_Skin.AKM_holo = 1010012065;
        new_Skin.AKM_x2 = 1010012064;
        new_Skin.AKM_x3 = 1010012063;
        new_Skin.AKM_x4 = 1010012062;
        new_Skin.AKM_x6 = 203015;
        new_Skin.AKM_quickMag = 1010012070;
        new_Skin.AKM_extendedMag = 1010012072;
        new_Skin.AKM_quickNextended = 1010012073;
    }
    if (preferences.Config.Skin.AKM == 2) {
        new_Skin.AKM = 1101001103;
        new_Skin.AKM_Mag = 1010011031;
        new_Skin.AKM_flash = 201010;
        new_Skin.AKM_compe = 201009;
        new_Skin.AKM_silent = 201011;
        new_Skin.AKM_reddot = 203001;
        new_Skin.AKM_holo = 203002;
        new_Skin.AKM_x2 = 203003;
        new_Skin.AKM_x3 = 203014;
        new_Skin.AKM_x4 = 203004;
        new_Skin.AKM_x6 = 203015;
        new_Skin.AKM_quickMag = 204012;
        new_Skin.AKM_extendedMag = 204011;
        new_Skin.AKM_quickNextended = 204013;
    }
    if (preferences.Config.Skin.AKM == 3) {
        new_Skin.AKM = 1101001116;
        new_Skin.AKM_Mag = 1010011161;
        new_Skin.AKM_compe = 1010011107;
        new_Skin.AKM_silent = 1010011108;
        new_Skin.AKM_reddot = 1010011105;
        new_Skin.AKM_holo = 1010011104;
        new_Skin.AKM_x2 = 1010011103;
        new_Skin.AKM_x3 = 203014;
        new_Skin.AKM_x4 = 1010011102;
        new_Skin.AKM_x6 = 203015;
        new_Skin.AKM_quickMag = 1010011109;
        new_Skin.AKM_extendedMag = 204011;
        new_Skin.AKM_quickNextended = 1010011112;
    }
    if (preferences.Config.Skin.AKM == 4) {
        new_Skin.AKM = 1101001128;
        new_Skin.AKM_Mag = 1010011281;
        new_Skin.AKM_flash = 1010011232;
        new_Skin.AKM_compe = 1010011233;
        new_Skin.AKM_silent = 1010011234;
        new_Skin.AKM_reddot = 1010011226;
        new_Skin.AKM_holo = 1010011225;
        new_Skin.AKM_x2 = 1010011224;
        new_Skin.AKM_x3 = 1010011223;
        new_Skin.AKM_x4 = 1010011222;
        new_Skin.AKM_x6 = 203015;
        new_Skin.AKM_quickMag = 1010011227;
        new_Skin.AKM_extendedMag = 1010011228;
        new_Skin.AKM_quickNextended = 1010011229;
    }
    if (preferences.Config.Skin.AKM == 5) {
        new_Skin.AKM = 1101001143;
        new_Skin.AKM_Mag = 1010011431;
        new_Skin.AKM_flash = 201010;
        new_Skin.AKM_compe = 201009;
        new_Skin.AKM_silent = 201011;
        new_Skin.AKM_reddot = 203001;
        new_Skin.AKM_holo = 203002;
        new_Skin.AKM_x2 = 203003;
        new_Skin.AKM_x3 = 203014;
        new_Skin.AKM_x4 = 203004;
        new_Skin.AKM_x6 = 203015;
        new_Skin.AKM_quickMag = 204012;
        new_Skin.AKM_extendedMag = 204011;
        new_Skin.AKM_quickNextended = 204013;
    }
    if (preferences.Config.Skin.AKM == 6) {
        new_Skin.AKM = 1101001154;
        new_Skin.AKM_Mag = 1010011541;
        new_Skin.AKM_flash = 1010011487;
        new_Skin.AKM_compe = 1010011488;
        new_Skin.AKM_silent = 1010011489;
        new_Skin.AKM_reddot = 1010011486;
        new_Skin.AKM_holo = 1010011485;
        new_Skin.AKM_x2 = 1010011484;
        new_Skin.AKM_x3 = 1010011483;
        new_Skin.AKM_x4 = 1010011482;
        new_Skin.AKM_x6 = 203015;
        new_Skin.AKM_quickMag = 1010011490;
        new_Skin.AKM_extendedMag = 1010011493;
        new_Skin.AKM_quickNextended = 1010011494;
    }
    if (preferences.Config.Skin.AKM == 7) {
        new_Skin.AKM = 1101001174;
        new_Skin.AKM_Mag = 1010011741;
        new_Skin.AKM_flash = 1010011667;
        new_Skin.AKM_compe = 1010011668;
        new_Skin.AKM_silent = 1010011669;
        new_Skin.AKM_reddot = 1010011666;
        new_Skin.AKM_holo = 1010012265;
        new_Skin.AKM_x2 = 1010011664;
        new_Skin.AKM_x3 = 1010011663;
        new_Skin.AKM_x4 = 1010011662;
        new_Skin.AKM_x6 = 203015;
        new_Skin.AKM_quickMag = 1010011670;
        new_Skin.AKM_extendedMag = 1010011673;
        new_Skin.AKM_quickNextended = 1010011674;
    }
    if (preferences.Config.Skin.AKM == 8) {
        new_Skin.AKM = 1101001231;
        new_Skin.AKM_Mag = 1010012311;
        new_Skin.AKM_flash = 1010012267;
        new_Skin.AKM_compe = 1010012274;
        new_Skin.AKM_silent = 1010012269;
        new_Skin.AKM_reddot = 1010012266;
        new_Skin.AKM_holo = 1010012265;
        new_Skin.AKM_x2 = 1010012264;
        new_Skin.AKM_x3 = 1010012263;
        new_Skin.AKM_x4 = 1010012262;
        new_Skin.AKM_x6 = 1010012276;
        new_Skin.AKM_quickMag = 204012;
        new_Skin.AKM_extendedMag = 204011;
        new_Skin.AKM_quickNextended = 204013;
    }
    if (preferences.Config.Skin.AKM == 9) {
        new_Skin.AKM = 1101001089;
        new_Skin.AKM_Mag = 1010010891;
        new_Skin.AKM_flash = 201010;
        new_Skin.AKM_compe = 201009;
        new_Skin.AKM_silent = 201011;
        new_Skin.AKM_reddot = 203001;
        new_Skin.AKM_holo = 203002;
        new_Skin.AKM_x2 = 203003;
        new_Skin.AKM_x3 = 203014;
        new_Skin.AKM_x4 = 203004;
        new_Skin.AKM_x6 = 203015;
        new_Skin.AKM_quickMag = 204012;
        new_Skin.AKM_extendedMag = 204011;
        new_Skin.AKM_quickNextended = 204013;
    }
    
    if (preferences.Config.Skin.AKM == 10) {
        new_Skin.AKM = 1101001242;
        new_Skin.AKM_Mag = 1010012421;
        new_Skin.AKM_flash = 201010;
        new_Skin.AKM_compe = 201009;
        new_Skin.AKM_silent = 201011;
        new_Skin.AKM_reddot = 203001;
        new_Skin.AKM_holo = 203002;
        new_Skin.AKM_x2 = 203003;
        new_Skin.AKM_x3 = 203014;
        new_Skin.AKM_x4 = 203004;
        new_Skin.AKM_x6 = 203015;
        new_Skin.AKM_quickMag = 204012;
        new_Skin.AKM_extendedMag = 204011;
        new_Skin.AKM_quickNextended = 204013;
    }
    if (preferences.Config.Skin.AKM == 11) {
        new_Skin.AKM = 1101001249;
        new_Skin.AKM_Mag = 1010012491;
        new_Skin.AKM_flash = 1010012507;
        new_Skin.AKM_compe = 1010012508;
        new_Skin.AKM_silent = 1010012509;
        new_Skin.AKM_reddot = 203001;
        new_Skin.AKM_holo = 1010012505;
        new_Skin.AKM_x2 = 1010012504;
        new_Skin.AKM_x3 = 1010012503;
        new_Skin.AKM_x4 = 1010012502;
        new_Skin.AKM_x6 = 1010012516;
        new_Skin.AKM_quickMag = 1010012512;
        new_Skin.AKM_extendedMag = 1010012513;
        new_Skin.AKM_quickNextended = 1010012514;
    }
    if (preferences.Config.Skin.AKM == 12) {
        new_Skin.AKM = 1101001256;
        new_Skin.AKM_Mag = 1010012491;
        new_Skin.AKM_flash = 1010012507;
        new_Skin.AKM_compe = 1010012508;
        new_Skin.AKM_silent = 1010012509;
        new_Skin.AKM_reddot = 203001;
        new_Skin.AKM_holo = 1010012505;
        new_Skin.AKM_x2 = 1010012504;
        new_Skin.AKM_x3 = 1010012503;
        new_Skin.AKM_x4 = 1010012502;
        new_Skin.AKM_x6 = 1010012516;
        new_Skin.AKM_quickMag = 1010012512;
        new_Skin.AKM_extendedMag = 1010012513;
        new_Skin.AKM_quickNextended = 1010012514;
    }
    if (preferences.Config.Skin.AKM == 13) {
        new_Skin.AKM = 1101001023;
        new_Skin.AKM_Mag = 291001;
        new_Skin.AKM_flash = 201010;
        new_Skin.AKM_compe = 201009;
        new_Skin.AKM_silent = 201011;
        new_Skin.AKM_reddot = 203001;
        new_Skin.AKM_holo = 203002;
        new_Skin.AKM_x2 = 203003;
        new_Skin.AKM_x3 = 203014;
        new_Skin.AKM_x4 = 203004;
        new_Skin.AKM_x6 = 203015;
        new_Skin.AKM_quickMag = 204012;
        new_Skin.AKM_extendedMag = 204011;
        new_Skin.AKM_quickNextended = 204013;
    }
    if (preferences.Config.Skin.AKM == 14) {
        new_Skin.AKM = 1101001068;
        new_Skin.AKM_Mag = 291001;
        new_Skin.AKM_flash = 201010;
        new_Skin.AKM_compe = 201009;
        new_Skin.AKM_silent = 201011;
        new_Skin.AKM_reddot = 203001;
        new_Skin.AKM_holo = 203002;
        new_Skin.AKM_x2 = 203003;
        new_Skin.AKM_x3 = 203014;
        new_Skin.AKM_x4 = 203004;
        new_Skin.AKM_x6 = 203015;
        new_Skin.AKM_quickMag = 204012;
        new_Skin.AKM_extendedMag = 204011;
        new_Skin.AKM_quickNextended = 204013;
    }
    
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    if (preferences.Config.Skin.M16A4 == 0) {
        new_Skin.M16A4 = 101002;
        new_Skin.M16A4_Stock = 205007;
        new_Skin.M16A4_Mag = 291002;
    }
    if (preferences.Config.Skin.M16A4 == 1) {
        new_Skin.M16A4 = 1101002029;
        new_Skin.M16A4_Stock = 1010020292;
        new_Skin.M16A4_Mag = 1010020291;
    }
    if (preferences.Config.Skin.M16A4 == 2) {
        new_Skin.M16A4 = 1101002056;
        new_Skin.M16A4_Stock = 1010020562;
        new_Skin.M16A4_Mag = 1010020561;
    }
    if (preferences.Config.Skin.M16A4 == 3) {
        new_Skin.M16A4 = 1101002068;
        new_Skin.M16A4_Stock = 1010020682;
        new_Skin.M16A4_Mag = 1010020681;
    }
    if (preferences.Config.Skin.M16A4 == 4) {
        new_Skin.M16A4 = 1101002081;
        new_Skin.M16A4_Stock = 1010020812;
        new_Skin.M16A4_Mag = 1010020811;
    }
    if (preferences.Config.Skin.M16A4 == 5) {
        new_Skin.M16A4 = 1101002103;
        new_Skin.M16A4_Stock = 1010021032;
        new_Skin.M16A4_Mag = 1010021031;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    if (preferences.Config.Skin.Scar == 0) {
        new_Skin.Scar = 101003;
        new_Skin.Scar_Mag = 291003;
        new_Skin.Scar_3 = 203007;
        new_Skin.Scar_flash = 201010;
        new_Skin.Scar_compe = 201009;
        new_Skin.Scar_silent = 201011;
        new_Skin.Scar_reddot = 203001;
        new_Skin.Scar_holo = 203002;
        new_Skin.Scar_x2 = 203003;
        new_Skin.Scar_x3 = 203014;
        new_Skin.Scar_x4 = 203004;
        new_Skin.Scar_x6 = 203015;
        new_Skin.Scar_quickMag = 204012;
        new_Skin.Scar_extendedMag = 204011;
        new_Skin.Scar_quickNextended = 204013;
        new_Skin.Scar_verical = 202002;
        new_Skin.Scar_angle = 202001;
        new_Skin.Scar_lightgrip = 202004;
        new_Skin.Scar_pink = 202005;
        new_Skin.Scar_lazer = 202007;
        new_Skin.Scar_thumb = 202006;
    }
    if (preferences.Config.Skin.Scar == 1){
        
        new_Skin.Scar = 1101003167;
        new_Skin.Scar_Mag = 1010031671;
        new_Skin.Scar_3 = 1010031672;
        new_Skin.Scar_flash = 1010031609;
        new_Skin.Scar_compe = 1010031610;
        new_Skin.Scar_silent = 1010031613;
        new_Skin.Scar_reddot = 1010031606;
        new_Skin.Scar_holo = 1010031605;
        new_Skin.Scar_x2 = 1010031604;
        new_Skin.Scar_x3 = 1010031603;
        new_Skin.Scar_x4 = 1010031602;
        new_Skin.Scar_quickMag = 1010031607;
        new_Skin.Scar_extendedMag = 1010031608;
        new_Skin.Scar_quickNextended = 1010031617;
        new_Skin.Scar_verical = 1010031615;
        new_Skin.Scar_angle = 1010031614;
        new_Skin.Scar_lightgrip = 202004;
        new_Skin.Scar_thumb = 1010031616;
        
    }
    if (preferences.Config.Skin.Scar == 2) {
        new_Skin.Scar = 1101003070;
        new_Skin.Scar_Mag = 1010030701;
        new_Skin.Scar_3 = 1010030702;
    }
    if (preferences.Config.Skin.Scar == 3) {
        new_Skin.Scar = 1101003080;
        new_Skin.Scar_Mag = 1010030801;
        new_Skin.Scar_3 = 1010030802;
    }
    if (preferences.Config.Skin.Scar == 4) {
        new_Skin.Scar = 1101003119;
        new_Skin.Scar_Mag = 1010031191;
        new_Skin.Scar_3 = 1010031192;
        new_Skin.Scar_flash = 1010031139;
        new_Skin.Scar_compe = 1010031140;
        new_Skin.Scar_silent = 1010031142;
        new_Skin.Scar_reddot = 1010031136;
        new_Skin.Scar_holo = 1010031135;
        new_Skin.Scar_x2 = 1010031134;
        new_Skin.Scar_x3 = 1010031133;
        new_Skin.Scar_x4 = 1010031132;
        new_Skin.Scar_quickMag = 1010031137;
        new_Skin.Scar_extendedMag = 1010031138;
        new_Skin.Scar_quickNextended = 1010031146;
        new_Skin.Scar_verical = 1010031144;
        new_Skin.Scar_angle = 1010031143;
        new_Skin.Scar_lightgrip = 202004;
        new_Skin.Scar_pink = 202005;
        new_Skin.Scar_lazer = 202007;
        new_Skin.Scar_thumb = 202006;
    }
    if (preferences.Config.Skin.Scar == 5) {
        new_Skin.Scar = 1101003146;
        new_Skin.Scar_Mag = 1010031461;
        new_Skin.Scar_3 = 1010031462;
    }
    if (preferences.Config.Skin.Scar == 6) {
        new_Skin.Scar = 1101003181;
        new_Skin.Scar_Mag = 1010031811;
        new_Skin.Scar_flash = 1010031765;
        new_Skin.Scar_compe = 1010031764;
        new_Skin.Scar_silent = 1010031766;
        new_Skin.Scar_reddot = 1010031757;
        new_Skin.Scar_holo = 1010031756;
        new_Skin.Scar_x2 = 1010031755;
        new_Skin.Scar_x3 = 1010031754;
        new_Skin.Scar_x4 = 1010031753;
        new_Skin.Scar_x6 = 1010031752;
        new_Skin.Scar_quickMag = 1010031758;
        new_Skin.Scar_extendedMag = 1010031759;
        new_Skin.Scar_quickNextended = 1010031763;
        new_Skin.Scar_verical = 1010031769;
        new_Skin.Scar_angle = 1010031767;
        new_Skin.Scar_lightgrip = 1010031773;
        new_Skin.Scar_pink = 1010031774;
        new_Skin.Scar_lazer = 1010031772;
        new_Skin.Scar_thumb = 1010031768;
    }
    
    if (preferences.Config.Skin.Scar == 7) {
        new_Skin.Scar = 1101003195;
        new_Skin.Scar_Mag = 291003;
        new_Skin.Scar_3 = 203007;
        new_Skin.Scar_flash = 201010;
        new_Skin.Scar_compe = 201009;
        new_Skin.Scar_silent = 201011;
        new_Skin.Scar_reddot = 203001;
        new_Skin.Scar_holo = 203002;
        new_Skin.Scar_x2 = 203003;
        new_Skin.Scar_x3 = 203014;
        new_Skin.Scar_x4 = 203004;
        new_Skin.Scar_x6 = 203015;
        new_Skin.Scar_quickMag = 204012;
        new_Skin.Scar_extendedMag = 204011;
        new_Skin.Scar_quickNextended = 204013;
        new_Skin.Scar_verical = 202002;
        new_Skin.Scar_angle = 202001;
        new_Skin.Scar_lightgrip = 202004;
        new_Skin.Scar_pink = 202005;
        new_Skin.Scar_lazer = 202007;
        new_Skin.Scar_thumb = 202006;
    }
    
    if (preferences.Config.Skin.Scar == 8) {
        new_Skin.Scar = 1101003099;
        new_Skin.Scar_Mag = 291003;
        new_Skin.Scar_3 = 203007;
        new_Skin.Scar_flash = 201010;
        new_Skin.Scar_compe = 201009;
        new_Skin.Scar_silent = 201011;
        new_Skin.Scar_reddot = 203001;
        new_Skin.Scar_holo = 203002;
        new_Skin.Scar_x2 = 203003;
        new_Skin.Scar_x3 = 203014;
        new_Skin.Scar_x4 = 203004;
        new_Skin.Scar_x6 = 203015;
        new_Skin.Scar_quickMag = 204012;
        new_Skin.Scar_extendedMag = 204011;
        new_Skin.Scar_quickNextended = 204013;
        new_Skin.Scar_verical = 202002;
        new_Skin.Scar_angle = 202001;
        new_Skin.Scar_lightgrip = 202004;
        new_Skin.Scar_pink = 202005;
        new_Skin.Scar_lazer = 202007;
        new_Skin.Scar_thumb = 202006;
    }
    
    if (preferences.Config.Skin.Scar == 9) {
        new_Skin.Scar = 1101003173;
        new_Skin.Scar_Mag = 291003;
        new_Skin.Scar_3 = 203007;
        new_Skin.Scar_flash = 201010;
        new_Skin.Scar_compe = 201009;
        new_Skin.Scar_silent = 201011;
        new_Skin.Scar_reddot = 203001;
        new_Skin.Scar_holo = 203002;
        new_Skin.Scar_x2 = 203003;
        new_Skin.Scar_x3 = 203014;
        new_Skin.Scar_x4 = 203004;
        new_Skin.Scar_x6 = 203015;
        new_Skin.Scar_quickMag = 204012;
        new_Skin.Scar_extendedMag = 204011;
        new_Skin.Scar_quickNextended = 204013;
        new_Skin.Scar_verical = 202002;
        new_Skin.Scar_angle = 202001;
        new_Skin.Scar_lightgrip = 202004;
        new_Skin.Scar_pink = 202005;
        new_Skin.Scar_lazer = 202007;
        new_Skin.Scar_thumb = 202006;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    if (preferences.Config.Skin.M416 == 0) {
        new_Skin.M416_1 = 101004;
        new_Skin.M416_2 = 291004;
        new_Skin.M416_3 = 203008;
        new_Skin.M416_4 = 205005;
        new_Skin.M416_flash = 201010;
        new_Skin.M416_compe = 201009;
        new_Skin.M416_silent = 201011;
        new_Skin.M416_reddot = 203001;
        new_Skin.M416_holo = 203002;
        new_Skin.M416_x2 = 203003;
        new_Skin.M416_x3 = 203014;
        new_Skin.M416_x4 = 203004;
        new_Skin.M416_x6 = 203015;
        new_Skin.M416_quickMag = 204012;
        new_Skin.M416_extendedMag = 204011;
        new_Skin.M416_quickNextended = 204013;
        new_Skin.M416_stock = 205002;
        new_Skin.M416_verical = 203015;
        new_Skin.M416_angle = 202001;
        new_Skin.M416_lightgrip = 202004;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 202006;
    }
    if (preferences.Config.Skin.M416 == 1) {
        new_Skin.M416_1 = 1101004046;
        new_Skin.M416_2 = 1010040461;
        new_Skin.M416_3 = 1010040462;
        new_Skin.M416_4 = 1010040463;
        new_Skin.M416_flash = 1010040474;
        new_Skin.M416_compe = 1010040475;
        new_Skin.M416_silent = 1010040476;
        new_Skin.M416_reddot = 1010040470;
        new_Skin.M416_holo = 1010040469;
        new_Skin.M416_x2 = 1010040468;
        new_Skin.M416_x3 = 1010040467;
        new_Skin.M416_x4 = 1010040466;
        new_Skin.M416_x6 = 1010040481;
        new_Skin.M416_quickMag = 1010040471;
        new_Skin.M416_extendedMag = 1010040472;
        new_Skin.M416_quickNextended = 1010040473;
        new_Skin.M416_stock = 1010040480;
        new_Skin.M416_verical = 1010040479;
        new_Skin.M416_thumb = 1010040478;
        new_Skin.M416_angle = 1010040477;
        new_Skin.M416_lightgrip = 1010040482;
        new_Skin.M416_pink = 1010040483;
        new_Skin.M416_lazer = 1010040484;
    }
    if (preferences.Config.Skin.M416 == 2) {
        new_Skin.M416_1 = 1101004062;
        new_Skin.M416_2 = 1010040611;
        new_Skin.M416_3 = 1010040612;
        new_Skin.M416_4 = 1010040613;
        new_Skin.M416_flash = 201010;
        new_Skin.M416_compe = 201009;
        new_Skin.M416_silent = 201011;
        new_Skin.M416_reddot = 203001;
        new_Skin.M416_holo = 203002;
        new_Skin.M416_x2 = 203003;
        new_Skin.M416_x3 = 203014;
        new_Skin.M416_x4 = 203004;
        new_Skin.M416_x6 = 203015;
        new_Skin.M416_quickMag = 204012;
        new_Skin.M416_extendedMag = 204011;
        new_Skin.M416_quickNextended = 204013;
        new_Skin.M416_stock = 205002;
        new_Skin.M416_verical = 203015;
        new_Skin.M416_angle = 202001;
        new_Skin.M416_lightgrip = 202004;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 202006;
    }
    if (preferences.Config.Skin.M416 == 3) {
        new_Skin.M416_1 = 1101004078;
        new_Skin.M416_2 = 1010040781;
        new_Skin.M416_3 = 1010040782;
        new_Skin.M416_4 = 1010040783;
        new_Skin.M416_flash = 201010;
        new_Skin.M416_compe = 201009;
        new_Skin.M416_silent = 201011;
        new_Skin.M416_reddot = 203001;
        new_Skin.M416_holo = 203002;
        new_Skin.M416_x2 = 203003;
        new_Skin.M416_x3 = 203014;
        new_Skin.M416_x4 = 203004;
        new_Skin.M416_x6 = 203015;
        new_Skin.M416_quickMag = 204012;
        new_Skin.M416_extendedMag = 204011;
        new_Skin.M416_quickNextended = 204013;
        new_Skin.M416_stock = 205002;
        new_Skin.M416_verical = 203015;
        new_Skin.M416_angle = 202001;
        new_Skin.M416_lightgrip = 202004;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 202006;
    }
    if (preferences.Config.Skin.M416 == 4) {
        new_Skin.M416_1 = 1101004086;
        new_Skin.M416_2 = 1010040861;
        new_Skin.M416_3 = 1010040862;
        new_Skin.M416_4 = 1010040863;
        new_Skin.M416_flash = 201010;
        new_Skin.M416_compe = 201009;
        new_Skin.M416_silent = 201011;
        new_Skin.M416_reddot = 203001;
        new_Skin.M416_holo = 203002;
        new_Skin.M416_x2 = 203003;
        new_Skin.M416_x3 = 203014;
        new_Skin.M416_x4 = 203004;
        new_Skin.M416_x6 = 203015;
        new_Skin.M416_quickMag = 204012;
        new_Skin.M416_extendedMag = 204011;
        new_Skin.M416_quickNextended = 204013;
        new_Skin.M416_stock = 205002;
        new_Skin.M416_verical = 203015;
        new_Skin.M416_angle = 202001;
        new_Skin.M416_lightgrip = 202004;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 202006;
    }
    if (preferences.Config.Skin.M416 == 5) {
        new_Skin.M416_1 = 1101004098;
        new_Skin.M416_2 = 1010040981;
        new_Skin.M416_3 = 1010040982;
        new_Skin.M416_4 = 1010040983;
        new_Skin.M416_flash = 201010;
        new_Skin.M416_compe = 201009;
        new_Skin.M416_silent = 201011;
        new_Skin.M416_reddot = 203001;
        new_Skin.M416_holo = 203002;
        new_Skin.M416_x2 = 203003;
        new_Skin.M416_x3 = 203014;
        new_Skin.M416_x4 = 203004;
        new_Skin.M416_x6 = 203015;
        new_Skin.M416_quickMag = 204012;
        new_Skin.M416_extendedMag = 204011;
        new_Skin.M416_quickNextended = 204013;
        new_Skin.M416_stock = 205002;
        new_Skin.M416_verical = 203015;
        new_Skin.M416_angle = 202001;
        new_Skin.M416_lightgrip = 202004;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 202006;
    }
    if (preferences.Config.Skin.M416 == 6) {
        new_Skin.M416_1 = 1101004138;
        new_Skin.M416_2 = 1010041381;
        new_Skin.M416_3 = 1010041382;
        new_Skin.M416_4 = 1010041383;
        new_Skin.M416_flash = 1010041136;
        new_Skin.M416_compe = 1010041137;
        new_Skin.M416_silent = 1010041138;
        new_Skin.M416_reddot = 1010041128;
        new_Skin.M416_holo = 1010041127;
        new_Skin.M416_x2 = 1010041126;
        new_Skin.M416_x3 = 1010041125;
        new_Skin.M416_x4 = 1010041124;
        new_Skin.M416_x6 = 203015;
        new_Skin.M416_quickMag = 1010041134;
        new_Skin.M416_extendedMag = 1010041129;
        new_Skin.M416_quickNextended = 1010041135;
        new_Skin.M416_stock = 1010041146;
        new_Skin.M416_verical = 1010041145;
        new_Skin.M416_angle = 1010041139;
        new_Skin.M416_lightgrip = 202004;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 202006;
    }
    if (preferences.Config.Skin.M416 == 7) {
        new_Skin.M416_1 = 1101004163;
        new_Skin.M416_2 = 1010041631;
        new_Skin.M416_3 = 1010041632;
        new_Skin.M416_4 = 1010041633;
        new_Skin.M416_flash = 201010;
        new_Skin.M416_compe = 1010041574;
        new_Skin.M416_silent = 1010041575;
        new_Skin.M416_reddot = 1010041566;
        new_Skin.M416_holo = 1010041565;
        new_Skin.M416_x2 = 1010041564;
        new_Skin.M416_x3 = 1010041560;
        new_Skin.M416_x4 = 1010041554;
        new_Skin.M416_x6 = 203015;
        new_Skin.M416_quickMag = 1010041568;
        new_Skin.M416_extendedMag = 1010041569;
        new_Skin.M416_quickNextended = 1010041567;
        new_Skin.M416_stock = 1010041579;
        new_Skin.M416_verical = 1010041578;
        new_Skin.M416_angle = 1010041576;
        new_Skin.M416_lightgrip = 20200400;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 1010041577;
    }
    if (preferences.Config.Skin.M416 == 8) {
        new_Skin.M416_1 = 1101004201;
        new_Skin.M416_2 = 1010042011;
        new_Skin.M416_3 = 1010042012;
        new_Skin.M416_4 = 1010042013;
        new_Skin.M416_flash = 1010041956;
        new_Skin.M416_compe = 1010041957;
        new_Skin.M416_silent = 1010041958;
        new_Skin.M416_reddot = 1010041948;
        new_Skin.M416_holo = 1010041947;
        new_Skin.M416_x2 = 1010041946;
        new_Skin.M416_x3 = 1010041945;
        new_Skin.M416_x4 = 1010041944;
        new_Skin.M416_x6 = 1010041967;
        new_Skin.M416_quickMag = 1010041949;
        new_Skin.M416_extendedMag = 1010041950;
        new_Skin.M416_quickNextended = 1010041955;
        new_Skin.M416_stock = 1010041966;
        new_Skin.M416_verical = 1010041965;
        new_Skin.M416_angle = 1010041959;
        new_Skin.M416_lightgrip = 202004;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 202006;
    }
    if (preferences.Config.Skin.M416 == 9) {
        new_Skin.M416_1 = 1101004209;
        new_Skin.M416_2 = 1010042073;
        new_Skin.M416_3 = 1010042083;
        new_Skin.M416_4 = 1010042093;
        new_Skin.M416_flash = 20101000;
        new_Skin.M416_compe = 1010042037;
        new_Skin.M416_silent = 1010042039;
        new_Skin.M416_reddot = 1010042029;
        new_Skin.M416_holo = 1010042028;
        new_Skin.M416_x2 = 1010042027;
        new_Skin.M416_x3 = 1010042026;
        new_Skin.M416_x4 = 1010042025;
        new_Skin.M416_x6 = 1010042024;
        new_Skin.M416_quickMag = 1010042034;
        new_Skin.M416_extendedMag = 1010042035;
        new_Skin.M416_quickNextended = 1010042036;
        new_Skin.M416_stock = 1010042047;
        new_Skin.M416_verical = 1010042046;
        new_Skin.M416_angle = 1010042044;
        new_Skin.M416_lightgrip = 202004;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 202006;
    }
    if (preferences.Config.Skin.M416 == 10) {
        new_Skin.M416_1 = 1101004218;
        new_Skin.M416_2 = 1010042181;
        new_Skin.M416_3 = 1010042182;
        new_Skin.M416_4 = 1010042183;
        new_Skin.M416_flash = 1010042128;
        new_Skin.M416_compe = 1010042127;
        new_Skin.M416_silent = 1010042129;
        new_Skin.M416_reddot = 1010042119;
        new_Skin.M416_holo = 1010042118;
        new_Skin.M416_x2 = 1010042117;
        new_Skin.M416_x3 = 1010042116;
        new_Skin.M416_x4 = 1010042115;
        new_Skin.M416_x6 = 1010042114;
        new_Skin.M416_quickMag = 1010042125;
        new_Skin.M416_extendedMag = 1010042124;
        new_Skin.M416_quickNextended = 1010042126;
        new_Skin.M416_stock = 1010042137;
        new_Skin.M416_verical = 1010042136;
        new_Skin.M416_angle = 1010042134;
        new_Skin.M416_lightgrip = 1010042138;
        new_Skin.M416_pink = 1010042139;
        new_Skin.M416_lazer = 1010042144;
        new_Skin.M416_thumb = 1010042135;
        
    }
    if (preferences.Config.Skin.M416 == 11) {
        new_Skin.M416_1 = 1101004226;
        new_Skin.M416_2 = 1010042214;
        new_Skin.M416_3 = 1010042215;
        new_Skin.M416_4 = 1010042216;
        new_Skin.M416_flash = 1010042238;
        new_Skin.M416_compe = 1010042237;
        new_Skin.M416_silent = 1010042239;
        new_Skin.M416_reddot = 1010042233;
        new_Skin.M416_holo = 1010042232;
        new_Skin.M416_x2 = 1010042231;
        new_Skin.M416_x3 = 1010042219;
        new_Skin.M416_x4 = 1010042218;
        new_Skin.M416_x6 = 1010042217;
        new_Skin.M416_quickMag = 1010042235;
        new_Skin.M416_extendedMag = 1010042234;
        new_Skin.M416_quickNextended = 1010042236;
        new_Skin.M416_stock = 1010042244;
        new_Skin.M416_verical = 1010042243;
        new_Skin.M416_angle = 1010042241;
        new_Skin.M416_lightgrip = 1010042245;
        new_Skin.M416_pink = 1010042246;
        new_Skin.M416_lazer = 1010042247;
        new_Skin.M416_thumb = 1010042242;
        
    }
    
    if (preferences.Config.Skin.M416 == 12) {
        new_Skin.M416_1 = 1101004154;
        new_Skin.M416_2 = 291004;
        new_Skin.M416_3 = 203008;
        new_Skin.M416_4 = 205005;
        new_Skin.M416_flash = 201010;
        new_Skin.M416_compe = 201009;
        new_Skin.M416_silent = 201011;
        new_Skin.M416_reddot = 203001;
        new_Skin.M416_holo = 203002;
        new_Skin.M416_x2 = 203003;
        new_Skin.M416_x3 = 203014;
        new_Skin.M416_x4 = 203004;
        new_Skin.M416_x6 = 203015;
        new_Skin.M416_quickMag = 204012;
        new_Skin.M416_extendedMag = 204011;
        new_Skin.M416_quickNextended = 204013;
        new_Skin.M416_stock = 205002;
        new_Skin.M416_verical = 203015;
        new_Skin.M416_angle = 202001;
        new_Skin.M416_lightgrip = 202004;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 202006;
    }
    if (preferences.Config.Skin.M416 == 13) {
        new_Skin.M416_1 = 1101004151;
        new_Skin.M416_2 = 291004;
        new_Skin.M416_3 = 203008;
        new_Skin.M416_4 = 205005;
        new_Skin.M416_flash = 201010;
        new_Skin.M416_compe = 201009;
        new_Skin.M416_silent = 201011;
        new_Skin.M416_reddot = 203001;
        new_Skin.M416_holo = 203002;
        new_Skin.M416_x2 = 203003;
        new_Skin.M416_x3 = 203014;
        new_Skin.M416_x4 = 203004;
        new_Skin.M416_x6 = 203015;
        new_Skin.M416_quickMag = 204012;
        new_Skin.M416_extendedMag = 204011;
        new_Skin.M416_quickNextended = 204013;
        new_Skin.M416_stock = 205002;
        new_Skin.M416_verical = 203015;
        new_Skin.M416_angle = 202001;
        new_Skin.M416_lightgrip = 202004;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 202006;
    }
    if (preferences.Config.Skin.M416 == 14) {
        new_Skin.M416_1 = 1101004089;
        new_Skin.M416_2 = 291004;
        new_Skin.M416_3 = 203008;
        new_Skin.M416_4 = 205005;
        new_Skin.M416_flash = 201010;
        new_Skin.M416_compe = 201009;
        new_Skin.M416_silent = 201011;
        new_Skin.M416_reddot = 203001;
        new_Skin.M416_holo = 203002;
        new_Skin.M416_x2 = 203003;
        new_Skin.M416_x3 = 203014;
        new_Skin.M416_x4 = 203004;
        new_Skin.M416_x6 = 203015;
        new_Skin.M416_quickMag = 204012;
        new_Skin.M416_extendedMag = 204011;
        new_Skin.M416_quickNextended = 204013;
        new_Skin.M416_stock = 205002;
        new_Skin.M416_verical = 203015;
        new_Skin.M416_angle = 202001;
        new_Skin.M416_lightgrip = 202004;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 202006;
    }
    if (preferences.Config.Skin.M416 == 15) {
        new_Skin.M416_1 = 1101004034;
        new_Skin.M416_2 = 291004;
        new_Skin.M416_3 = 203008;
        new_Skin.M416_4 = 205005;
        new_Skin.M416_flash = 201010;
        new_Skin.M416_compe = 201009;
        new_Skin.M416_silent = 201011;
        new_Skin.M416_reddot = 203001;
        new_Skin.M416_holo = 203002;
        new_Skin.M416_x2 = 203003;
        new_Skin.M416_x3 = 203014;
        new_Skin.M416_x4 = 203004;
        new_Skin.M416_x6 = 203015;
        new_Skin.M416_quickMag = 204012;
        new_Skin.M416_extendedMag = 204011;
        new_Skin.M416_quickNextended = 204013;
        new_Skin.M416_stock = 205002;
        new_Skin.M416_verical = 203015;
        new_Skin.M416_angle = 202001;
        new_Skin.M416_lightgrip = 202004;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 202006;
    }
    if (preferences.Config.Skin.M416 == 16) {
        new_Skin.M416_1 = 1101004002;
        new_Skin.M416_2 = 291004;
        new_Skin.M416_3 = 203008;
        new_Skin.M416_4 = 205005;
        new_Skin.M416_flash = 201010;
        new_Skin.M416_compe = 201009;
        new_Skin.M416_silent = 201011;
        new_Skin.M416_reddot = 203001;
        new_Skin.M416_holo = 203002;
        new_Skin.M416_x2 = 203003;
        new_Skin.M416_x3 = 203014;
        new_Skin.M416_x4 = 203004;
        new_Skin.M416_x6 = 203015;
        new_Skin.M416_quickMag = 204012;
        new_Skin.M416_extendedMag = 204011;
        new_Skin.M416_quickNextended = 204013;
        new_Skin.M416_stock = 205002;
        new_Skin.M416_verical = 203015;
        new_Skin.M416_angle = 202001;
        new_Skin.M416_lightgrip = 202004;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 202006;
    }
    if (preferences.Config.Skin.M416 == 17) {
        new_Skin.M416_1 = 1101004227;
        new_Skin.M416_2 = 291004;
        new_Skin.M416_3 = 203008;
        new_Skin.M416_4 = 205005;
        new_Skin.M416_flash = 201010;
        new_Skin.M416_compe = 201009;
        new_Skin.M416_silent = 201011;
        new_Skin.M416_reddot = 203001;
        new_Skin.M416_holo = 203002;
        new_Skin.M416_x2 = 203003;
        new_Skin.M416_x3 = 203014;
        new_Skin.M416_x4 = 203004;
        new_Skin.M416_x6 = 203015;
        new_Skin.M416_quickMag = 204012;
        new_Skin.M416_extendedMag = 204011;
        new_Skin.M416_quickNextended = 204013;
        new_Skin.M416_stock = 205002;
        new_Skin.M416_verical = 203015;
        new_Skin.M416_angle = 202001;
        new_Skin.M416_lightgrip = 202004;
        new_Skin.M416_pink = 202005;
        new_Skin.M416_lazer = 203015;
        new_Skin.M416_thumb = 202006;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.Groza == 0) {
        new_Skin.Groza = 101005;
        new_Skin.Groza_2 = 291005;
        new_Skin.Groza_silent = 201011;
        new_Skin.Groza_reddot = 203001;
        new_Skin.Groza_holo = 203002;
        new_Skin.Groza_x2 = 203003;
        new_Skin.Groza_x3 = 203014;
        new_Skin.Groza_x4 = 203004;
        new_Skin.Groza_x6 = 203015;
        new_Skin.Groza_quickMag = 204012;
        new_Skin.Groza_extendedMag = 204011;
        new_Skin.Groza_quickNextended = 204013;
    }
    if (preferences.Config.Skin.Groza == 1) {
        
        new_Skin.Groza = 1101005052;
        new_Skin.Groza_2 = 1010050521;
        new_Skin.Groza_silent = 1010050467;
        new_Skin.Groza_reddot = 1010050466;
        new_Skin.Groza_holo = 1010050465;
        new_Skin.Groza_x2 = 1010050464;
        new_Skin.Groza_x3 = 1010050463;
        new_Skin.Groza_x4 = 1010050462;
        new_Skin.Groza_x6 = 203015;
        new_Skin.Groza_quickMag = 1010050468;
        new_Skin.Groza_extendedMag = 1010050469;
        new_Skin.Groza_quickNextended = 1010050470;
    }
    if (preferences.Config.Skin.Groza == 2) {
        new_Skin.Groza = 1101005025;
        new_Skin.Groza_2 = 1010050251;
        new_Skin.Groza_silent = 201011;
        new_Skin.Groza_reddot = 203001;
        new_Skin.Groza_holo = 203002;
        new_Skin.Groza_x2 = 203003;
        new_Skin.Groza_x3 = 203014;
        new_Skin.Groza_x4 = 203004;
        new_Skin.Groza_x6 = 203015;
        new_Skin.Groza_quickMag = 204012;
        new_Skin.Groza_extendedMag = 204011;
        new_Skin.Groza_quickNextended = 204013;
    }
    if (preferences.Config.Skin.Groza == 3) {
        new_Skin.Groza = 1101005019;
        new_Skin.Groza_2 = 1010050191;
        new_Skin.Groza_silent = 201011;
        new_Skin.Groza_reddot = 203001;
        new_Skin.Groza_holo = 203002;
        new_Skin.Groza_x2 = 203003;
        new_Skin.Groza_x3 = 203014;
        new_Skin.Groza_x4 = 203004;
        new_Skin.Groza_x6 = 203015;
        new_Skin.Groza_quickMag = 204012;
        new_Skin.Groza_extendedMag = 204011;
        new_Skin.Groza_quickNextended = 204013;
    }
    if (preferences.Config.Skin.Groza == 4) {
        new_Skin.Groza = 1101005043;
        new_Skin.Groza_2 = 1010050431;
        new_Skin.Groza_silent = 201011;
        new_Skin.Groza_reddot = 203001;
        new_Skin.Groza_holo = 203002;
        new_Skin.Groza_x2 = 203003;
        new_Skin.Groza_x3 = 203014;
        new_Skin.Groza_x4 = 203004;
        new_Skin.Groza_x6 = 203015;
        new_Skin.Groza_quickMag = 204012;
        new_Skin.Groza_extendedMag = 204011;
        new_Skin.Groza_quickNextended = 204013;
    }
    if (preferences.Config.Skin.Groza == 5) {
        new_Skin.Groza = 1101005038;
        new_Skin.Groza_2 = 1010050381;
        new_Skin.Groza_silent = 1010050327;
        new_Skin.Groza_reddot = 1010050326;
        new_Skin.Groza_holo = 1010050325;
        new_Skin.Groza_x2 = 1010050324;
        new_Skin.Groza_x3 = 1010050323;
        new_Skin.Groza_x4 = 1010050322;
        new_Skin.Groza_x6 = 203015;
        new_Skin.Groza_quickMag = 1010050328;
        new_Skin.Groza_extendedMag = 1010050329;
        new_Skin.Groza_quickNextended = 1010050330;
    }
    if (preferences.Config.Skin.Groza == 6) {
        new_Skin.Groza = 1101005082;
        new_Skin.Groza_2 = 1010050821;
        new_Skin.Groza_silent = 201011;
        new_Skin.Groza_reddot = 203001;
        new_Skin.Groza_holo = 203002;
        new_Skin.Groza_x2 = 203003;
        new_Skin.Groza_x3 = 203014;
        new_Skin.Groza_x4 = 203004;
        new_Skin.Groza_x6 = 203015;
        new_Skin.Groza_quickMag = 204012;
        new_Skin.Groza_extendedMag = 204011;
        new_Skin.Groza_quickNextended = 204013;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.Famas == 0) {
        new_Skin.Famas = 101100;
        new_Skin.Famas_reddot = 203001;
        new_Skin.Famas_holo = 203002;
        new_Skin.Famas_x2 = 203003;
        new_Skin.Famas = 203014;
        new_Skin.Famas_x4 = 203004;
        new_Skin.Famas_x6 = 203015;
    }
    if (preferences.Config.Skin.Famas == 1) {
        new_Skin.Famas = 1101100012;
        new_Skin.Famas_reddot = 203001;
        new_Skin.Famas_holo = 203002;
        new_Skin.Famas_x2 = 203003;
        new_Skin.Famas = 203014;
        new_Skin.Famas_x4 = 203004;
        new_Skin.Famas_x6 = 203015;
    }
    if (preferences.Config.Skin.Famas == 2) {
        new_Skin.Famas = 1101100013;
        new_Skin.Famas_reddot = 203001;
        new_Skin.Famas_holo = 203002;
        new_Skin.Famas_x2 = 203003;
        new_Skin.Famas = 203014;
        new_Skin.Famas_x4 = 203004;
        new_Skin.Famas_x6 = 203015;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.AUG == 0){
        new_Skin.AUG = 101006;
        new_Skin.AUG_reddot = 203001;
        new_Skin.AUG_holo = 203002;
        new_Skin.AUG_x2 = 203003;
        new_Skin.AUG_x3 = 203014;
        new_Skin.AUG_x4 = 203004;
        new_Skin.AUG_x6 = 203015;
    }
    
    if (preferences.Config.Skin.AUG == 1){
        new_Skin.AUG = 1101006062;
        new_Skin.AUG_reddot = 1010060562;
        new_Skin.AUG_holo = 1010060561;
        new_Skin.AUG_x2 = 1010060554;
        new_Skin.AUG_x3 = 1010060553;
        new_Skin.AUG_x4 = 1010060552;
        new_Skin.AUG_x6 = 1010060551;
        new_Skin.AUG_lazer = 1010060574;
        new_Skin.AUG_flash = 1010060571;
    }
    
    
    
    if (preferences.Config.Skin.AUG == 2){
        new_Skin.AUG = 1101006044;
        new_Skin.AUG = 101006;
        new_Skin.AUG_reddot = 203001;
        new_Skin.AUG_holo = 203002;
        new_Skin.AUG_x2 = 203003;
        new_Skin.AUG_x3 = 203014;
        new_Skin.AUG_x4 = 203004;
        new_Skin.AUG_x6 = 203015;
    }
    if (preferences.Config.Skin.AUG == 3){
        new_Skin.AUG = 1101006033;
        new_Skin.AUG = 101006;
        new_Skin.AUG_reddot = 203001;
        new_Skin.AUG_holo = 203002;
        new_Skin.AUG_x2 = 203003;
        new_Skin.AUG_x3 = 203014;
        new_Skin.AUG_x4 = 203004;
        new_Skin.AUG_x6 = 203015;
        new_Skin.AUG_lazer = 202007;
        new_Skin.AUG_flash = 201010;
    }
    
    if (preferences.Config.Skin.AUG == 4){
        new_Skin.AUG = 1101006075;
        new_Skin.AUG_reddot = 1010060696;
        new_Skin.AUG_holo = 1010060695;
        new_Skin.AUG_x2 = 1010060694;
        new_Skin.AUG_x3 = 1010060693;
        new_Skin.AUG_x4 = 1010060692;
        new_Skin.AUG_x6 = 1010060691;
        new_Skin.AUG_lazer = 1010060707;
        new_Skin.AUG_flash = 1010060699;
    }
    if (preferences.Config.Skin.AUG == 5){
        new_Skin.AUG = 1101006067;
        new_Skin.AUG = 101006;
        new_Skin.AUG_reddot = 203001;
        new_Skin.AUG_holo = 203002;
        new_Skin.AUG_x2 = 203003;
        new_Skin.AUG_x3 = 203014;
        new_Skin.AUG_x4 = 203004;
        new_Skin.AUG_x6 = 203015;
        new_Skin.AUG_lazer = 202007;
        new_Skin.AUG_flash = 201010;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.QBZ == 0)
        new_Skin.QBZ = 101007;
    if (preferences.Config.Skin.QBZ == 1)
        new_Skin.QBZ = 1101007062;
    if (preferences.Config.Skin.QBZ == 2)
        new_Skin.QBZ = 1101007046;
    if (preferences.Config.Skin.QBZ == 3)
        new_Skin.QBZ = 1101007036;
    if (preferences.Config.Skin.QBZ == 4)
        new_Skin.QBZ = 1101007025;
    
    
    
    
    
    
    
    
    
    
    if (preferences.Config.Skin.MG3 == 0){
        new_Skin.MG3 = 105010;
        new_Skin.MG3_reddot = 203001;
        new_Skin.MG3_holo = 203002;
        new_Skin.MG3_x2 = 203003;
        new_Skin.MG3_x3 = 203014;
        new_Skin.MG3_x4 = 203004;
        new_Skin.MG3_x6 = 203015;
    }
    if (preferences.Config.Skin.MG3 == 1){
        new_Skin.MG3 = 1105010019;
        new_Skin.MG3_reddot = 203001;
        new_Skin.MG3_holo = 203002;
        new_Skin.MG3_x2 = 203003;
        new_Skin.MG3_x3 = 203014;
        new_Skin.MG3_x4 = 203004;
        new_Skin.MG3_x6 = 203015;
    }
    if (preferences.Config.Skin.MG3 == 2){
        new_Skin.MG3 = 1105010008;
        new_Skin.MG3_reddot = 203001;
        new_Skin.MG3_holo = 203002;
        new_Skin.MG3_x2 = 203003;
        new_Skin.MG3_x3 = 203014;
        new_Skin.MG3_x4 = 203004;
        new_Skin.MG3_x6 = 203015;
    }
    
    
    
    
    
    
    
    
    
    if (preferences.Config.Skin.Honey == 0)
        new_Skin.Honey = 101012;
    if (preferences.Config.Skin.Honey == 1)
        new_Skin.Honey = 1101012009;
    
    
    if (preferences.Config.Skin.S1897 == 0)
        new_Skin.S1897 = 104002;
    if (preferences.Config.Skin.S1897 == 1)
        new_Skin.S1897 = 1104002022;
    if (preferences.Config.Skin.S1897 == 2)
        new_Skin.S1897 = 1104002035;
    if (preferences.Config.Skin.S1897 == 3)
        new_Skin.S1897 = 1104002004;
    
    
    
    
    
    if (preferences.Config.Skin.DBS == 0)
        new_Skin.DBS = 104004;
    if (preferences.Config.Skin.DBS == 1)
        new_Skin.DBS = 1104004035;
    if (preferences.Config.Skin.DBS == 2)
        new_Skin.DBS = 1104004014;
    if (preferences.Config.Skin.DBS == 3)
        new_Skin.DBS = 1104004015;
    if (preferences.Config.Skin.DBS == 4)
        new_Skin.DBS = 1104004024;
    
    
    
    
    if (preferences.Config.Skin.S12K == 0)
        new_Skin.S12K = 104003;
    if (preferences.Config.Skin.S12K == 1)
        new_Skin.S12K = 1104003038;
    if (preferences.Config.Skin.S12K == 2)
        new_Skin.S12K = 1104003037;
    
    if (preferences.Config.Skin.S12K == 3)
        new_Skin.S12K = 1104003026;
    
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.M762 == 0) {
        new_Skin.M762 = 101008;
        new_Skin.M762_Mag = 291008;
        new_Skin.M762_reddot = 203001;
        new_Skin.M762_holo = 203002;
        new_Skin.M762_x2 = 203003;
        new_Skin.M762_x3 = 203014;
        new_Skin.M762_x4 = 203004;
        new_Skin.M762_x6 = 203015;
        new_Skin.M762_lazer = 202007;
        new_Skin.M762_flash = 201010;
        
    }
    if (preferences.Config.Skin.M762 == 1) {
        
        new_Skin.M762 = 1101008081;
        new_Skin.M762_Mag = 1010080811;
        new_Skin.M762_reddot = 203001;
        new_Skin.M762_holo = 203002;
        new_Skin.M762_x2 = 203003;
        new_Skin.M762_x3 = 203014;
        new_Skin.M762_x4 = 203004;
        new_Skin.M762_x6 = 203015;
        new_Skin.M762_lazer = 202007;
        new_Skin.M762_flash = 201010;
        
    }
    if (preferences.Config.Skin.M762 == 2) {
        new_Skin.M762 = 1101008051;
        new_Skin.M762_Mag = 1010080511;
        new_Skin.M762_reddot = 203001;
        new_Skin.M762_holo = 203002;
        new_Skin.M762_x2 = 203003;
        new_Skin.M762_x3 = 203014;
        new_Skin.M762_x4 = 203004;
        new_Skin.M762_x6 = 203015;
        new_Skin.M762_lazer = 202007;
        new_Skin.M762_flash = 201010;
    }
    if (preferences.Config.Skin.M762 == 3) {
        new_Skin.M762 = 1101008061;
        new_Skin.M762_Mag = 1010080611;
        new_Skin.M762_reddot = 203001;
        new_Skin.M762_holo = 203002;
        new_Skin.M762_x2 = 203003;
        new_Skin.M762_x3 = 203014;
        new_Skin.M762_x4 = 203004;
        new_Skin.M762_x6 = 203015;
        new_Skin.M762_lazer = 202007;
        new_Skin.M762_flash = 201010;
    }
    if (preferences.Config.Skin.M762 == 4) {
        new_Skin.M762 = 1101008026;
        new_Skin.M762_Mag = 1010080261;
        new_Skin.M762_reddot = 203001;
        new_Skin.M762_holo = 203002;
        new_Skin.M762_x2 = 203003;
        new_Skin.M762_x3 = 203014;
        new_Skin.M762_x4 = 203004;
        new_Skin.M762_x6 = 203015;
        new_Skin.M762_lazer = 202007;
        new_Skin.M762_flash = 201010;
    }
    if (preferences.Config.Skin.M762 == 5) {
        new_Skin.M762 = 1101008104;
        new_Skin.M762_Mag = 1010081041;
        new_Skin.M762_reddot = 203001;
        new_Skin.M762_holo = 203002;
        new_Skin.M762_x2 = 203003;
        new_Skin.M762_x3 = 203014;
        new_Skin.M762_x4 = 203004;
        new_Skin.M762_x6 = 203015;
        new_Skin.M762_lazer = 202007;
        new_Skin.M762_flash = 201010;
    }
    if (preferences.Config.Skin.M762 == 6) {
        new_Skin.M762 = 1101008116;
        new_Skin.M762_Mag = 1010081161;
        new_Skin.M762_reddot = 203001;
        new_Skin.M762_holo = 203002;
        new_Skin.M762_x2 = 203003;
        new_Skin.M762_x3 = 203014;
        new_Skin.M762_x4 = 203004;
        new_Skin.M762_x6 = 203015;
        new_Skin.M762_lazer = 202007;
        new_Skin.M762_flash = 201010;
    }
    if (preferences.Config.Skin.M762 == 7) {
        new_Skin.M762 = 1101008126;
        new_Skin.M762_Mag = 1010081261;
        new_Skin.M762_reddot = 203001;
        new_Skin.M762_holo = 203002;
        new_Skin.M762_x2 = 203003;
        new_Skin.M762_x3 = 203014;
        new_Skin.M762_x4 = 203004;
        new_Skin.M762_x6 = 203015;
        new_Skin.M762_lazer = 202007;
        new_Skin.M762_flash = 201010;
    }
    if (preferences.Config.Skin.M762 == 8) {
        new_Skin.M762 = 1101008136;
        new_Skin.M762_Mag = 1010081361;
        new_Skin.M762_reddot = 203001;
        new_Skin.M762_holo = 203002;
        new_Skin.M762_x2 = 203003;
        new_Skin.M762_x3 = 203014;
        new_Skin.M762_x4 = 203004;
        new_Skin.M762_x6 = 203015;
        new_Skin.M762_lazer = 202007;
        new_Skin.M762_flash = 201010;
    }
    if (preferences.Config.Skin.M762 == 9) {
        new_Skin.M762 = 1101008070;
        new_Skin.M762_Mag = 1010081361;
        new_Skin.M762_reddot = 203001;
        new_Skin.M762_holo = 203002;
        new_Skin.M762_x2 = 203003;
        new_Skin.M762_x3 = 203014;
        new_Skin.M762_x4 = 203004;
        new_Skin.M762_x6 = 203015;
        new_Skin.M762_lazer = 202007;
        new_Skin.M762_flash = 201010;
    }
    if (preferences.Config.Skin.M762 == 10) {
        new_Skin.M762 = 1101008146;
        new_Skin.M762_Mag = 1010081361;
        new_Skin.M762_reddot = 1010081396;
        new_Skin.M762_holo = 1010081395;
        new_Skin.M762_x2 = 1010081394;
        new_Skin.M762_x3 = 1010081393;
        new_Skin.M762_x4 = 1010081392;
        new_Skin.M762_x6 = 1010081391;
        new_Skin.M762_lazer = 1010081409;
        new_Skin.M762_flash = 1010081399;
    }
    if (preferences.Config.Skin.M762 == 11) {
        new_Skin.M762 = 1101008154;
        new_Skin.M762_Mag = 1010081361;
        new_Skin.M762_reddot = 1010081396;
        new_Skin.M762_holo = 1010081395;
        new_Skin.M762_x2 = 1010081394;
        new_Skin.M762_x3 = 1010081393;
        new_Skin.M762_x4 = 1010081392;
        new_Skin.M762_x6 = 1010081391;
        new_Skin.M762_lazer = 1010081409;
        new_Skin.M762_flash = 1010081399;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.ACE32 == 0)
        new_Skin.ACE32 = 101102;
    if (preferences.Config.Skin.ACE32 == 1){
        new_Skin.ACE32 = 1101102007;
        new_Skin.ACE32_reddot = 1010081396;
        new_Skin.ACE32_holo = 1010081395;
        new_Skin.ACE32_x2 = 1010081394;
        new_Skin.ACE32_x3 = 1010081393;
        new_Skin.ACE32_x4 = 1010081392;
        new_Skin.ACE32_x6 = 1010081391;
    }
    if (preferences.Config.Skin.ACE32 == 2){
        new_Skin.ACE32 = 1101102017;
        new_Skin.ACE32_reddot = 1010081396;
        new_Skin.ACE32_holo = 1010081395;
        new_Skin.ACE32_x2 = 1010081394;
        new_Skin.ACE32_x3 = 1010081393;
        new_Skin.ACE32_x4 = 1010081392;
        new_Skin.ACE32_x6 = 1010081391;
    }
    if (preferences.Config.Skin.ACE32 == 3){
        new_Skin.ACE32 = 1101102025;
        new_Skin.ACE32_reddot = 1010081396;
        new_Skin.ACE32_holo = 1010081395;
        new_Skin.ACE32_x2 = 1010081394;
        new_Skin.ACE32_x3 = 1010081393;
        new_Skin.ACE32_x4 = 1010081392;
        new_Skin.ACE32_x6 = 1010081391;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.UZI == 0)
        new_Skin.UZI = 102001;
    if (preferences.Config.Skin.UZI == 1)
        new_Skin.UZI = 1102001102;
    if (preferences.Config.Skin.UZI == 2)
        new_Skin.UZI = 1102001036;
    if (preferences.Config.Skin.UZI == 3)
        new_Skin.UZI = 1102001058;
    if (preferences.Config.Skin.UZI == 4)
        new_Skin.UZI = 1102001069;
    if (preferences.Config.Skin.UZI == 5)
        new_Skin.UZI = 1102001089;
    if (preferences.Config.Skin.UZI == 6)
        new_Skin.UZI = 1102001024;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.UMP == 0){
        new_Skin.UMP = 102002;
        new_Skin.UMP_reddot = 203001;
        new_Skin.UMP_holo = 203002;
        new_Skin.UMP_x2 = 203003;
        new_Skin.UMP_x3 = 203014;
        new_Skin.UMP_x4 = 203004;
        new_Skin.UMP_x6 = 203015;
    }
    
    if (preferences.Config.Skin.UMP == 1){
        new_Skin.UMP = 1102002136;
        new_Skin.UMP_reddot = 203001;
        new_Skin.UMP_holo = 203002;
        new_Skin.UMP_x2 = 203003;
        new_Skin.UMP_x3 = 203014;
        new_Skin.UMP_x4 = 203004;
        new_Skin.UMP_x6 = 203015;
    }
    if (preferences.Config.Skin.UMP == 2){
        new_Skin.UMP = 1102002061;
        new_Skin.UMP_reddot = 203001;
        new_Skin.UMP_holo = 203002;
        new_Skin.UMP_x2 = 203003;
        new_Skin.UMP_x3 = 203014;
        new_Skin.UMP_x4 = 203004;
        new_Skin.UMP_x6 = 203015;
    }
    if (preferences.Config.Skin.UMP == 3){
        new_Skin.UMP = 1102002090;
        new_Skin.UMP_reddot = 203001;
        new_Skin.UMP_holo = 203002;
        new_Skin.UMP_x2 = 203003;
        new_Skin.UMP_x3 = 203014;
        new_Skin.UMP_x4 = 203004;
        new_Skin.UMP_x6 = 203015;
    }
    
    if (preferences.Config.Skin.UMP == 4){
        new_Skin.UMP = 1102002117;
        new_Skin.UMP_reddot = 203001;
        new_Skin.UMP_holo = 203002;
        new_Skin.UMP_x2 = 203003;
        new_Skin.UMP_x3 = 203014;
        new_Skin.UMP_x4 = 203004;
        new_Skin.UMP_x6 = 203015;
    }
    if (preferences.Config.Skin.UMP == 5){
        new_Skin.UMP = 1102002124;
        new_Skin.UMP_reddot = 203001;
        new_Skin.UMP_holo = 203002;
        new_Skin.UMP_x2 = 203003;
        new_Skin.UMP_x3 = 203014;
        new_Skin.UMP_x4 = 203004;
        new_Skin.UMP_x6 = 203015;
    }
    if (preferences.Config.Skin.UMP == 6){
        new_Skin.UMP = 1102002129;
        new_Skin.UMP_reddot = 203001;
        new_Skin.UMP_holo = 203002;
        new_Skin.UMP_x2 = 203003;
        new_Skin.UMP_x3 = 203014;
        new_Skin.UMP_x4 = 203004;
        new_Skin.UMP_x6 = 203015;
    }
    if (preferences.Config.Skin.UMP == 7){
        new_Skin.UMP = 1102002043;
        new_Skin.UMP_reddot = 203001;
        new_Skin.UMP_holo = 203002;
        new_Skin.UMP_x2 = 203003;
        new_Skin.UMP_x3 = 203014;
        new_Skin.UMP_x4 = 203004;
        new_Skin.UMP_x6 = 203015;
    }
    if (preferences.Config.Skin.UMP == 8){
        new_Skin.UMP = 1102002030;
        new_Skin.UMP_reddot = 203001;
        new_Skin.UMP_holo = 203002;
        new_Skin.UMP_x2 = 203003;
        new_Skin.UMP_x3 = 203014;
        new_Skin.UMP_x4 = 203004;
        new_Skin.UMP_x6 = 203015;
    }
    if (preferences.Config.Skin.UMP == 9){
        new_Skin.UMP = 1102002083;
        new_Skin.UMP_reddot = 203001;
        new_Skin.UMP_holo = 203002;
        new_Skin.UMP_x2 = 203003;
        new_Skin.UMP_x3 = 203014;
        new_Skin.UMP_x4 = 203004;
        new_Skin.UMP_x6 = 203015;
    }
    
    
    
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.Vector == 0)
        new_Skin.Vector = 102003;
    if (preferences.Config.Skin.Vector == 1)
        
        new_Skin.Vector = 1102003080;
    if (preferences.Config.Skin.Vector == 2)
        new_Skin.Vector = 1102003031;
    if (preferences.Config.Skin.Vector == 3)
        new_Skin.Vector = 1102003065;
    if (preferences.Config.Skin.Vector == 4)
        new_Skin.Vector = 1102003020;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.Thompson == 0)
        new_Skin.Thompson = 102004;
    if (preferences.Config.Skin.Thompson == 1)
        new_Skin.Thompson = 1102004018;
    if (preferences.Config.Skin.Thompson == 2)
        new_Skin.Thompson = 1102004034;
    
    //-------------------------------------------------------//
    if (preferences.Config.Skin.P90 == 0)
        new_Skin.P90 = 102105;
    if (preferences.Config.Skin.P90 == 1)
        new_Skin.P90 = 1102105012;
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.Bizon == 0)
        new_Skin.Bizon = 102005;
    if (preferences.Config.Skin.Bizon == 1)
        new_Skin.Bizon = 1102005007;
    if (preferences.Config.Skin.Bizon == 2)
        new_Skin.Bizon = 1102005020;
    if (preferences.Config.Skin.Bizon == 3)
        new_Skin.Bizon = 1102005041;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    {
        if (preferences.Config.Skin.K98 == 0)
            new_Skin.K98 = 103001;
        new_Skin.K98_reddot = 203001;
        new_Skin.K98_holo = 203002;
        new_Skin.K98_x2 = 203003;
        new_Skin.K98_x3 = 203014;
        new_Skin.K98_x4 = 203004;
        new_Skin.K98_x6 = 203015;
        new_Skin.K98_x8 = 203005;
    }
    
    if (preferences.Config.Skin.K98 == 1){
        new_Skin.K98 = 1103001179;
        new_Skin.K98_reddot = 203001;
        new_Skin.K98_holo = 203002;
        new_Skin.K98_x2 = 203003;
        new_Skin.K98_x3 = 203014;
        new_Skin.K98_x4 = 203004;
        new_Skin.K98_x6 = 203015;
        new_Skin.K98_x8 = 203005;
    }
    
    if (preferences.Config.Skin.K98 == 2){
        new_Skin.K98 = 1103001079;
        new_Skin.K98_reddot = 203001;
        new_Skin.K98_holo = 203002;
        new_Skin.K98_x2 = 203003;
        new_Skin.K98_x3 = 203014;
        new_Skin.K98_x4 = 203004;
        new_Skin.K98_x6 = 203015;
        new_Skin.K98_x8 = 203005;
    }
    
    
    if (preferences.Config.Skin.K98 == 3){
        new_Skin.K98 = 1103001101;
        new_Skin.K98_reddot = 203001;
        new_Skin.K98_holo = 203002;
        new_Skin.K98_x2 = 203003;
        new_Skin.K98_x3 = 203014;
        new_Skin.K98_x4 = 203004;
        new_Skin.K98_x6 = 203015;
        new_Skin.K98_x8 = 203005;
    }
    
    
    if (preferences.Config.Skin.K98 == 4){
        new_Skin.K98 = 1103001145;
        new_Skin.K98_reddot = 203001;
        new_Skin.K98_holo = 203002;
        new_Skin.K98_x2 = 203003;
        new_Skin.K98_x3 = 203014;
        new_Skin.K98_x4 = 203004;
        new_Skin.K98_x6 = 203015;
        new_Skin.K98_x8 = 203005;
    }
    
    if (preferences.Config.Skin.K98 == 5){
        new_Skin.K98 = 1103001160;
        new_Skin.K98_reddot = 203001;
        new_Skin.K98_holo = 203002;
        new_Skin.K98_x2 = 203003;
        new_Skin.K98_x3 = 203014;
        new_Skin.K98_x4 = 203004;
        new_Skin.K98_x6 = 203015;
        new_Skin.K98_x8 = 203005;
    }
    
    if (preferences.Config.Skin.K98 == 6){
        new_Skin.K98 = 1103001060;
        new_Skin.K98_reddot = 203001;
        new_Skin.K98_holo = 203002;
        new_Skin.K98_x2 = 203003;
        new_Skin.K98_x3 = 203014;
        new_Skin.K98_x4 = 203004;
        new_Skin.K98_x6 = 203015;
        new_Skin.K98_x8 = 203005;
    }
    
    
    if (preferences.Config.Skin.K98 == 7){
        new_Skin.K98 = 1103001191;
        new_Skin.K98_reddot = 1030011857;
        new_Skin.K98_holo = 1030011856;
        new_Skin.K98_x2 = 1030011855;
        new_Skin.K98_x3 = 1030011854;
        new_Skin.K98_x4 = 1030011853;
        new_Skin.K98_x6 = 1030011852;
        new_Skin.K98_x8 = 1030011851;
    }
    
    if (preferences.Config.Skin.K98 == 8){
        new_Skin.K98 = 1103001183;
        new_Skin.K98_reddot = 203001;
        new_Skin.K98_holo = 203002;
        new_Skin.K98_x2 = 203003;
        new_Skin.K98_x3 = 203014;
        new_Skin.K98_x4 = 203004;
        new_Skin.K98_x6 = 203015;
        new_Skin.K98_x8 = 203005;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.M24 == 0){
        new_Skin.M24 = 103002;
        new_Skin.M24_reddot = 203001;
        new_Skin.M24_holo = 203002;
        new_Skin.M24_x2 = 203003;
        new_Skin.M24_x3 = 203014;
        new_Skin.M24_x4 = 203004;
        new_Skin.M24_x6 = 203015;
        new_Skin.M24_x8 = 203005;
    }
    if (preferences.Config.Skin.M24 == 1){
        new_Skin.M24 = 1103002087;
        new_Skin.M24_reddot = 203001;
        new_Skin.M24_holo = 203002;
        new_Skin.M24_x2 = 203003;
        new_Skin.M24_x3 = 203014;
        new_Skin.M24_x4 = 203004;
        new_Skin.M24_x6 = 203015;
        new_Skin.M24_x8 = 203005;
    }
    if (preferences.Config.Skin.M24 == 2){
        new_Skin.M24 = 1103002030;
        new_Skin.M24_reddot = 203001;
        new_Skin.M24_holo = 203002;
        new_Skin.M24_x2 = 203003;
        new_Skin.M24_x3 = 203014;
        new_Skin.M24_x4 = 203004;
        new_Skin.M24_x6 = 203015;
        new_Skin.M24_x8 = 203005;
    }
    
    if (preferences.Config.Skin.M24 == 3){
        new_Skin.M24 = 1103002048;
        new_Skin.M24_reddot = 203001;
        new_Skin.M24_holo = 203002;
        new_Skin.M24_x2 = 203003;
        new_Skin.M24_x3 = 203014;
        new_Skin.M24_x4 = 203004;
        new_Skin.M24_x6 = 203015;
        new_Skin.M24_x8 = 203005;
    }
    if (preferences.Config.Skin.M24 == 4){
        new_Skin.M24 = 1103002056;
        new_Skin.M24_reddot = 203001;
        new_Skin.M24_holo = 203002;
        new_Skin.M24_x2 = 203003;
        new_Skin.M24_x3 = 203014;
        new_Skin.M24_x4 = 203004;
        new_Skin.M24_x6 = 203015;
        new_Skin.M24_x8 = 203005;
    }
    if (preferences.Config.Skin.M24 == 5){
        new_Skin.M24 = 1103002059;
        new_Skin.M24_reddot = 203001;
        new_Skin.M24_holo = 203002;
        new_Skin.M24_x2 = 203003;
        new_Skin.M24_x3 = 203014;
        new_Skin.M24_x4 = 203004;
        new_Skin.M24_x6 = 203015;
        new_Skin.M24_x8 = 203005;
    }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.AWM == 0){
        new_Skin.AWM = 103003;
        new_Skin.AWM_reddot = 203001;
        new_Skin.AWM_holo = 203002;
        new_Skin.AWM_x2 = 203003;
        new_Skin.AWM_x3 = 203014;
        new_Skin.AWM_x4 = 203004;
        new_Skin.AWM_x6 = 203015;
        new_Skin.AWM_x8 = 203005;
    }
    if (preferences.Config.Skin.AWM == 1){
        new_Skin.AWM = 1103003087;
        new_Skin.AWM_reddot = 203001;
        new_Skin.AWM_holo = 203002;
        new_Skin.AWM_x2 = 203003;
        new_Skin.AWM_x3 = 203014;
        new_Skin.AWM_x4 = 203004;
        new_Skin.AWM_x6 = 203015;
        new_Skin.AWM_x8 = 203005;
    }
    if (preferences.Config.Skin.AWM == 2){
        new_Skin.AWM = 1103003022;
        new_Skin.AWM_reddot = 203001;
        new_Skin.AWM_holo = 203002;
        new_Skin.AWM_x2 = 203003;
        new_Skin.AWM_x3 = 203014;
        new_Skin.AWM_x4 = 203004;
        new_Skin.AWM_x6 = 203015;
        new_Skin.AWM_x8 = 203005;
    }
    if (preferences.Config.Skin.AWM == 3){
        new_Skin.AWM = 1103003042;
        new_Skin.AWM_reddot = 203001;
        new_Skin.AWM_holo = 203002;
        new_Skin.AWM_x2 = 203003;
        new_Skin.AWM_x3 = 203014;
        new_Skin.AWM_x4 = 203004;
        new_Skin.AWM_x6 = 203015;
        new_Skin.AWM_x8 = 203005;
    }
    if (preferences.Config.Skin.AWM == 4){
        new_Skin.AWM = 1103003051;
        new_Skin.AWM_reddot = 203001;
        new_Skin.AWM_holo = 203002;
        new_Skin.AWM_x2 = 203003;
        new_Skin.AWM_x3 = 203014;
        new_Skin.AWM_x4 = 203004;
        new_Skin.AWM_x6 = 203015;
        new_Skin.AWM_x8 = 203005;
    }
    if (preferences.Config.Skin.AWM == 5){
        new_Skin.AWM = 1103003062;
        new_Skin.AWM_reddot = 203001;
        new_Skin.AWM_holo = 203002;
        new_Skin.AWM_x2 = 203003;
        new_Skin.AWM_x3 = 203014;
        new_Skin.AWM_x4 = 203004;
        new_Skin.AWM_x6 = 203015;
        new_Skin.AWM_x8 = 203005;
    }
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.AMR == 0){
      new_Skin.AMR = 103012;
        new_Skin.AMR_reddot = 203001;
        new_Skin.AMR_holo = 203002;
        new_Skin.AMR_x2 = 203003;
        new_Skin.AMR_x3 = 203014;
        new_Skin.AMR_x4 = 203004;
        new_Skin.AMR_x6 = 203015;
        new_Skin.AMR_x8 = 203005;
    }
    if (preferences.Config.Skin.AMR == 1){
      new_Skin.AMR = 1103012019;
        new_Skin.AMR_reddot = 203001;
        new_Skin.AMR_holo = 203002;
        new_Skin.AMR_x2 = 203003;
        new_Skin.AMR_x3 = 203014;
        new_Skin.AMR_x4 = 203004;
        new_Skin.AMR_x6 = 203015;
        new_Skin.AMR_x8 = 203005;
    }
    
    if (preferences.Config.Skin.AMR == 2){
      new_Skin.AMR = 1103012010;
        new_Skin.AMR_reddot = 203001;
        new_Skin.AMR_holo = 203002;
        new_Skin.AMR_x2 = 203003;
        new_Skin.AMR_x3 = 203014;
        new_Skin.AMR_x4 = 203004;
        new_Skin.AMR_x6 = 203015;
        new_Skin.AMR_x8 = 203005;
    }
    
    if (preferences.Config.Skin.AMR == 3){
      new_Skin.AMR = 1030120101;
        new_Skin.AMR_reddot = 203001;
        new_Skin.AMR_holo = 203002;
        new_Skin.AMR_x2 = 203003;
        new_Skin.AMR_x3 = 203014;
        new_Skin.AMR_x4 = 203004;
        new_Skin.AMR_x6 = 203015;
        new_Skin.AMR_x8 = 203005;
    }
    
        
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.MK14 == 0)
      new_Skin.MK14 = 103007;
    if (preferences.Config.Skin.MK14 == 1)
      new_Skin.MK14 =1103007028;
    if (preferences.Config.Skin.MK14 == 2)
      new_Skin.MK14 = 1103007020;
    
    
    
    
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.Machete == 0)
      new_Skin.Machete = 103003;
    if (preferences.Config.Skin.Machete == 1)
      new_Skin.Machete = 1108001069;
    if (preferences.Config.Skin.Machete == 2)
      new_Skin.Machete = 1108001064;

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (preferences.Config.Skin.MINI14 == 0)
      new_Skin.Mini14 = 103006;
    if (preferences.Config.Skin.MINI14 == 1)
      new_Skin.Mini14 =1103006030;
    if (preferences.Config.Skin.MINI14 == 2)
      new_Skin.Mini14 = 1103006058;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (preferences.Config.Skin.DP28 == 0)
    new_Skin.DP28 = 105002;
  if (preferences.Config.Skin.DP28 == 1)
    new_Skin.DP28 = 1105002018;
  if (preferences.Config.Skin.DP28 == 2)
    new_Skin.DP28 = 1105002035;
  if (preferences.Config.Skin.DP28 == 3)
    new_Skin.DP28 = 1105002058;
  if (preferences.Config.Skin.DP28 == 4)
    new_Skin.DP28 = 1105002063;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if (preferences.Config.Skin.M249 == 0)
    new_Skin.M249 = 105001;
    new_Skin.M249s = 205009;
  if (preferences.Config.Skin.M249 == 1)
    
    new_Skin.M249 = 1105001048;
 //   new_Skin.M249s = 1050010542;
  if (preferences.Config.Skin.M249 == 2)
    new_Skin.M249 = 1105001054;
  //  new_Skin.M249s = 1050010412;
  if (preferences.Config.Skin.M249 == 3)
    new_Skin.M249 = 1105001034;
  //  new_Skin.M249s = 1050010482;
  if (preferences.Config.Skin.M249 == 4)
      new_Skin.M249 = 1105001020;
   //   new_Skin.M249s = 1050010351;
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   if (preferences.Config.Skin.Bigfoot == 0)
    new_Skin.Bigfoot = 1953001;
  if (preferences.Config.Skin.Bigfoot == 1)
    new_Skin.Bigfoot = 1953004;
    if (preferences.Config.Skin.Bigfoot == 2)
      new_Skin.Bigfoot = 1953008;
    
    if (preferences.Config.Skin.RZR == 0)
     new_Skin.RZR = 1966017;
   if (preferences.Config.Skin.RZR == 1)
     new_Skin.RZR = 1966017;
     if (preferences.Config.Skin.RZR == 2)
       new_Skin.RZR = 1966016;
     
    
    
    
    
    
    
    
    
    
  if (preferences.Config.Skin.Mirado == 0)
    new_Skin.Mirado = 1914001;
  if (preferences.Config.Skin.Mirado == 1)
    new_Skin.Mirado = 1915011;
    if (preferences.Config.Skin.Mirado == 2)
      new_Skin.Mirado = 1915009;
    if (preferences.Config.Skin.Mirado == 3)
      new_Skin.Mirado = 1915008;
    if (preferences.Config.Skin.Mirado == 4)
      new_Skin.Mirado = 1915007;
    if (preferences.Config.Skin.Mirado == 5)
      new_Skin.Mirado = 1915006;
    if (preferences.Config.Skin.Mirado == 6)
      new_Skin.Mirado = 1915005;
    if (preferences.Config.Skin.Mirado == 7)
      new_Skin.Mirado = 1915012;
    if (preferences.Config.Skin.Mirado == 8)
      new_Skin.Mirado = 1915010;
    
    
    
    
    
    
    
    
    
    
    
  if (preferences.Config.Skin.Moto == 0)
    new_Skin.Moto = 1901001;
  if (preferences.Config.Skin.Moto == 1)
    new_Skin.Moto = 1901073;
  if (preferences.Config.Skin.Moto == 2)
    new_Skin.Moto = 1901074;
  if (preferences.Config.Skin.Moto == 3)
    new_Skin.Moto = 1901075;
  if (preferences.Config.Skin.Moto == 4)
    new_Skin.Moto = 1901047;
  if (preferences.Config.Skin.Moto == 5)
    new_Skin.Moto = 1901085;
  if (preferences.Config.Skin.Moto == 6)
    new_Skin.Moto = 1901076;
  if (preferences.Config.Skin.Moto == 7)
    new_Skin.Moto = 1901027;
  if (preferences.Config.Skin.Moto == 8)
    new_Skin.Moto = 1901018;
  if (preferences.Config.Skin.Moto == 9)
    new_Skin.Moto = 1901085;
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if (preferences.Config.Skin.Buggy == 0)
    new_Skin.Buggy = 1907001;
  if (preferences.Config.Skin.Buggy == 1)
    new_Skin.Buggy = 1907047;
  if (preferences.Config.Skin.Buggy == 2)
    new_Skin.Buggy = 1907009;
if (preferences.Config.Skin.Buggy == 3)
    new_Skin.Buggy = 1907010;
if (preferences.Config.Skin.Buggy == 4)
    new_Skin.Buggy = 1907011;
if (preferences.Config.Skin.Buggy == 5)
    new_Skin.Buggy = 1907012;
if (preferences.Config.Skin.Buggy == 6)
    new_Skin.Buggy = 1907013;
if (preferences.Config.Skin.Buggy == 7)
    new_Skin.Buggy = 1907014;
if (preferences.Config.Skin.Buggy == 8)
    new_Skin.Buggy = 1907015;
if (preferences.Config.Skin.Buggy == 9)
    new_Skin.Buggy = 1907016;
if (preferences.Config.Skin.Buggy == 10)
    new_Skin.Buggy = 1907017;
if (preferences.Config.Skin.Buggy == 11)
    new_Skin.Buggy = 1907018;
if (preferences.Config.Skin.Buggy == 12)
    new_Skin.Buggy = 1907019;
if (preferences.Config.Skin.Buggy == 13)
    new_Skin.Buggy = 1907020;
if (preferences.Config.Skin.Buggy == 14)
    new_Skin.Buggy = 1907021;
if (preferences.Config.Skin.Buggy == 15)
    new_Skin.Buggy = 1907022;
if (preferences.Config.Skin.Buggy == 16)
    new_Skin.Buggy = 1907023;
if (preferences.Config.Skin.Buggy == 17)
    new_Skin.Buggy = 1907024;
if (preferences.Config.Skin.Buggy == 18)
    new_Skin.Buggy = 1907025;
if (preferences.Config.Skin.Buggy == 19)
    new_Skin.Buggy = 1907026;
if (preferences.Config.Skin.Buggy == 20)
    new_Skin.Buggy = 1907027;
if (preferences.Config.Skin.Buggy == 21)
    new_Skin.Buggy = 1907028;
if (preferences.Config.Skin.Buggy == 22)
    new_Skin.Buggy = 1907029;
if (preferences.Config.Skin.Buggy == 23)
    new_Skin.Buggy = 1907030;
if (preferences.Config.Skin.Buggy == 24)
    new_Skin.Buggy = 1907031;
if (preferences.Config.Skin.Buggy == 25)
    new_Skin.Buggy = 1907032;
if (preferences.Config.Skin.Buggy == 26)
    new_Skin.Buggy = 1907033;
if (preferences.Config.Skin.Buggy == 27)
    new_Skin.Buggy = 1907034;
if (preferences.Config.Skin.Buggy == 28)
    new_Skin.Buggy = 1907035;
if (preferences.Config.Skin.Buggy == 29)
    new_Skin.Buggy = 1907036;
if (preferences.Config.Skin.Buggy == 30)
    new_Skin.Buggy = 1907037;
if (preferences.Config.Skin.Buggy == 31)
    new_Skin.Buggy = 1907038;
if (preferences.Config.Skin.Buggy == 32)
    new_Skin.Buggy = 1907039;
if (preferences.Config.Skin.Buggy == 33)
    new_Skin.Buggy = 1907040;
    
    
    
    
    
  if (preferences.Config.Skin.Dacia == 0)
    new_Skin.Dacia = 1903001;
  if (preferences.Config.Skin.Dacia == 1)
    new_Skin.Dacia =1903201;
  if (preferences.Config.Skin.Dacia == 2)
    new_Skin.Dacia =1903200;
  if (preferences.Config.Skin.Dacia == 3)
    new_Skin.Dacia = 1903193;
  if (preferences.Config.Skin.Dacia == 4)
    new_Skin.Dacia = 1903192;
  if (preferences.Config.Skin.Dacia == 5)
    new_Skin.Dacia = 1903191;
  if (preferences.Config.Skin.Dacia == 6)
    new_Skin.Dacia = 1903080;
  if (preferences.Config.Skin.Dacia == 7)
    new_Skin.Dacia = 1903079;
  if (preferences.Config.Skin.Dacia == 8)
    new_Skin.Dacia = 1903076;
  if (preferences.Config.Skin.Dacia == 9)
    new_Skin.Dacia = 1903075;
  if (preferences.Config.Skin.Dacia == 10)
    new_Skin.Dacia = 1903074;
  if (preferences.Config.Skin.Dacia == 11)
    new_Skin.Dacia = 1903071;
  if (preferences.Config.Skin.Dacia == 12)
    new_Skin.Dacia = 1903073;
  if (preferences.Config.Skin.Dacia == 13)
    new_Skin.Dacia = 1903072;
  if (preferences.Config.Skin.Dacia == 14)
    new_Skin.Dacia = 1903090;
  if (preferences.Config.Skin.Dacia == 15)
    new_Skin.Dacia = 1903089;
  if (preferences.Config.Skin.Dacia == 16)
    new_Skin.Dacia = 1903088;
  if (preferences.Config.Skin.Dacia == 17)
    new_Skin.Dacia = 1903204;
  if (preferences.Config.Skin.Dacia == 18)
    new_Skin.Dacia = 1903203;
  if (preferences.Config.Skin.Dacia == 19)
    new_Skin.Dacia = 1903202;
  if (preferences.Config.Skin.Dacia == 20)
    new_Skin.Dacia = 1903017;
  if (preferences.Config.Skin.Dacia == 21)
    new_Skin.Dacia = 1903014;
    if (preferences.Config.Skin.Dacia == 22)
      new_Skin.Dacia = 1903023;
    if (preferences.Config.Skin.Dacia == 23)
      new_Skin.Dacia = 1903022;
    if (preferences.Config.Skin.Dacia == 24)
      new_Skin.Dacia = 1903019;
      
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  
if (preferences.Config.Skin.MiniBus == 0)
    new_Skin.MiniBus = 1904001;
  if (preferences.Config.Skin.MiniBus == 1)
    new_Skin.MiniBus = 1904005;
  if (preferences.Config.Skin.MiniBus == 2)
    new_Skin.MiniBus = 1904006;
if (preferences.Config.Skin.MiniBus == 3)
    new_Skin.MiniBus = 1904007;
if (preferences.Config.Skin.MiniBus == 4)
    new_Skin.MiniBus = 1904008;
if (preferences.Config.Skin.MiniBus == 5)
    new_Skin.MiniBus = 1904009;
if (preferences.Config.Skin.MiniBus == 6)
    new_Skin.MiniBus = 1904010;
if (preferences.Config.Skin.MiniBus == 7)
    new_Skin.MiniBus = 1904011;
if (preferences.Config.Skin.MiniBus == 8)
    new_Skin.MiniBus = 1904012;
if (preferences.Config.Skin.MiniBus == 9)
    new_Skin.MiniBus = 1904013;
if (preferences.Config.Skin.MiniBus == 10)
    new_Skin.MiniBus = 1904014;
if (preferences.Config.Skin.MiniBus == 11)
    new_Skin.MiniBus = 1904015;
if (preferences.Config.Skin.MiniBus == 12)
    new_Skin.MiniBus = 1904004;
  
  if (preferences.Config.Skin.CoupeRP == 0)
    new_Skin.CoupeRP = 1961001;
  if (preferences.Config.Skin.CoupeRP == 1)
    new_Skin.CoupeRP = 1961024;
  if (preferences.Config.Skin.CoupeRP == 2)
    new_Skin.CoupeRP = 1961047;
  if (preferences.Config.Skin.CoupeRP == 3)
    new_Skin.CoupeRP = 1961034;
  if (preferences.Config.Skin.CoupeRP == 4)
    new_Skin.CoupeRP = 1961018;
  if (preferences.Config.Skin.CoupeRP == 5)
    new_Skin.CoupeRP = 1961007;
  if (preferences.Config.Skin.CoupeRP == 6)
    new_Skin.CoupeRP = 1961010;
  if (preferences.Config.Skin.CoupeRP == 7)
    new_Skin.CoupeRP = 1961049;
  if (preferences.Config.Skin.CoupeRP == 8)
    new_Skin.CoupeRP = 1961048;
  if (preferences.Config.Skin.CoupeRP == 9)
    new_Skin.CoupeRP = 1961012;
  if (preferences.Config.Skin.CoupeRP == 10)
    new_Skin.CoupeRP = 1961013;
  if (preferences.Config.Skin.CoupeRP == 11)
    new_Skin.CoupeRP = 1961014;
  if (preferences.Config.Skin.CoupeRP == 12)
    new_Skin.CoupeRP = 1961015;
  if (preferences.Config.Skin.CoupeRP == 13)
    new_Skin.CoupeRP = 1961016;
  if (preferences.Config.Skin.CoupeRP == 14)
    new_Skin.CoupeRP = 1961017;
  if (preferences.Config.Skin.CoupeRP == 15)
    new_Skin.CoupeRP = 1961020;
  if (preferences.Config.Skin.CoupeRP == 16)
    new_Skin.CoupeRP = 1961021;
  if (preferences.Config.Skin.CoupeRP == 17)
    new_Skin.CoupeRP = 1961025;
  if (preferences.Config.Skin.CoupeRP == 18)
    new_Skin.CoupeRP = 1961029;
  if (preferences.Config.Skin.CoupeRP == 19)
    new_Skin.CoupeRP = 1961030;
  if (preferences.Config.Skin.CoupeRP == 20)
    new_Skin.CoupeRP = 1961031;
  if (preferences.Config.Skin.CoupeRP == 21)
    new_Skin.CoupeRP = 1961032;
  if (preferences.Config.Skin.CoupeRP == 22)
    new_Skin.CoupeRP = 1961033;
  if (preferences.Config.Skin.CoupeRP == 23)
    new_Skin.CoupeRP = 1961035;
  if (preferences.Config.Skin.CoupeRP == 24)
    new_Skin.CoupeRP = 1961036;
  if (preferences.Config.Skin.CoupeRP == 22)
    new_Skin.CoupeRP = 1961037;
  if (preferences.Config.Skin.CoupeRP == 26)
    new_Skin.CoupeRP = 1961038;
  if (preferences.Config.Skin.CoupeRP == 27)
    new_Skin.CoupeRP = 1961039;
  if (preferences.Config.Skin.CoupeRP == 28)
    new_Skin.CoupeRP = 1961040;
  if (preferences.Config.Skin.CoupeRP == 29)
    new_Skin.CoupeRP = 1961041;
  if (preferences.Config.Skin.CoupeRP == 30)
    new_Skin.CoupeRP = 1961042;
  if (preferences.Config.Skin.CoupeRP == 31)
    new_Skin.CoupeRP = 1961043;
  if (preferences.Config.Skin.CoupeRP == 32)
    new_Skin.CoupeRP = 1961044;
  if (preferences.Config.Skin.CoupeRP == 33)
    new_Skin.CoupeRP = 1961045;
  if (preferences.Config.Skin.CoupeRP == 34)
    new_Skin.CoupeRP = 1961046;
  if (preferences.Config.Skin.CoupeRP == 35)
    new_Skin.CoupeRP = 1961050;
  if (preferences.Config.Skin.CoupeRP == 36)
    new_Skin.CoupeRP = 1961051;
  if (preferences.Config.Skin.CoupeRP == 37)
    new_Skin.CoupeRP = 1961052;
  if (preferences.Config.Skin.CoupeRP == 38)
    new_Skin.CoupeRP = 1961053;
  if (preferences.Config.Skin.CoupeRP == 39)
    new_Skin.CoupeRP = 1961054;
  if (preferences.Config.Skin.CoupeRP == 40)
    new_Skin.CoupeRP = 1961055;
  if (preferences.Config.Skin.CoupeRP == 41)
    new_Skin.CoupeRP = 1961056;
  if (preferences.Config.Skin.CoupeRP == 42)
    new_Skin.CoupeRP = 1961057;
    if (preferences.Config.Skin.CoupeRP == 43)
      new_Skin.CoupeRP = 1961138;
    if (preferences.Config.Skin.CoupeRP == 44)
      new_Skin.CoupeRP = 1961139;
    
    

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  if (preferences.Config.Skin.UAZ == 0)
    new_Skin.UAZ = 1908001;
  if (preferences.Config.Skin.UAZ == 1)
    new_Skin.UAZ = 1908095;
  if (preferences.Config.Skin.UAZ == 2)
    new_Skin.UAZ = 1908094;
  if (preferences.Config.Skin.UAZ == 3)
    new_Skin.UAZ = 1908085;
  if (preferences.Config.Skin.UAZ == 4)
    new_Skin.UAZ = 1908084;
  if (preferences.Config.Skin.UAZ == 5)
    new_Skin.UAZ = 1908078;
  if (preferences.Config.Skin.UAZ == 6)
    new_Skin.UAZ = 1908077;
  if (preferences.Config.Skin.UAZ == 7)
    new_Skin.UAZ = 1908076;
  if (preferences.Config.Skin.UAZ == 8)
    new_Skin.UAZ = 1908075;
  if (preferences.Config.Skin.UAZ == 9)
    new_Skin.UAZ = 1908070;
  if (preferences.Config.Skin.UAZ == 10)
    new_Skin.UAZ = 1908069;
  if (preferences.Config.Skin.UAZ == 11)
    new_Skin.UAZ = 1908078;
  if (preferences.Config.Skin.UAZ == 12)
    new_Skin.UAZ = 1908067;
  if (preferences.Config.Skin.UAZ == 13)
    new_Skin.UAZ = 1908066;
  if (preferences.Config.Skin.UAZ == 14)
    new_Skin.UAZ = 1908019;
  if (preferences.Config.Skin.UAZ == 15)
    new_Skin.UAZ = 1908013;
  if (preferences.Config.Skin.UAZ == 16)
    new_Skin.UAZ = 1908036;
  if (preferences.Config.Skin.UAZ == 17)
    new_Skin.UAZ = 1908032;
    if (preferences.Config.Skin.UAZ == 18)
      new_Skin.UAZ = 1908010;
    
 
 if (preferences.Config.Skin.Boat == 0)
    new_Skin.Boat = 1911001;
  if (preferences.Config.Skin.Boat == 1)
    new_Skin.Boat = 1911013;
  if (preferences.Config.Skin.Boat == 2)
    new_Skin.Boat = 1911003;
if (preferences.Config.Skin.Boat == 3)
    new_Skin.Boat = 1911004;
if (preferences.Config.Skin.Boat == 4)
    new_Skin.Boat = 1911005;
if (preferences.Config.Skin.Boat == 5)
    new_Skin.Boat = 1911006;
if (preferences.Config.Skin.Boat == 6)
    new_Skin.Boat = 1911007;
if (preferences.Config.Skin.Boat == 7)
    new_Skin.Boat = 1911008;
if (preferences.Config.Skin.Boat == 8)
    new_Skin.Boat = 1911009;
if (preferences.Config.Skin.Boat == 9)
    new_Skin.Boat = 1911010;
if (preferences.Config.Skin.Boat == 10)
    new_Skin.Boat = 1911011;
if (preferences.Config.Skin.Boat == 11)
    new_Skin.Boat = 1911012;

}

static int prevXSuits = preferences.Config.Skin.XSuits;
static auto start = std::chrono::high_resolution_clock::now();
static bool callFunction = false;

int m4v[] = { 101004, 1101004046, 1101004062, 1101004078, 1101004086, 1101004098, 1101004138, 1101004163,1101004201,1101004209,1101004218,1101004226,1101004154,1101004151,1101004089,1101004034,1101004002,1101004227};

int scar[] = { 101003, 1101003057, 1101003070, 1101003080, 1101003119, 1101003146, 1101003167, 1101003181,1101003195,1101003099,1101003173};
int akmv[] = { 101001,1101001213, 1101001103, 1101001116, 1101001128, 1101001143, 1101001154, 1101001174,1101001089,1101001231,1101001242,1101001249, 1101001256,1101001023,1101001068};






//----------------------------------------------------------------//

int m7[] = { 101008, 1101008026, 1101008051, 1101008061, 1101008081, 1101008104, 1101008116, 1101008126,1101008136,1101008070,1101008146,1101008154};

int m7reddot[] = {         203001,203001,203001,203001,203001,203001,203001,203001,203001,203001,1010081396,1010081396};
int m7holo[] = {           203002,203002,203002,203002,203002,203002,203002,203002,203002,203002,1010081395,1010081395};
int m7x2[] = {             203003,203003,203003,203003,203003,203003,203003,203003,203003,203003,1010081394,1010081394};
int m7x3[] = {             203014,203014,203014,203014,203014,203014,203014,203014,203014,203014,1010081393,1010081393};
int m7x4[] = {             203004,203004,203004,203004,203004,203004,203004,203004,203004,203004,1010081392,1010081392};
int m7x6[] = {             203015,203015,203015,203015,203015,203015,203015,203015,203015,203015,1010081391,1010081391};
int m7Lazer[] = {          202007,202007,202007,202007,202007,202007,202007,202007,202007,202007,1010081409,1010081409};
int m7Flash[] = {          201010,201010,201010,201010,201010,201010,201010,201010,201010,201010,1010081399,1010081399};

//-------------------------------------------------------------------//












//----------------------------------------------------------------//

int awm[] = { 103003, 1103003087, 1103003022, 1103003042, 1103003051, 1103003062};

int awmreddot[] = {         203001,203001,203001,203001,203001,203001,};
int awmholo[] = {           203002,203002,203002,203002,203002,203002,};
int awmx2[] = {             203003,203003,203003,203003,203003,203003,};
int awmx3[] = {             203014,203014,203014,203014,203014,203014,};
int awmx4[] = {             203004,203004,203004,203004,203004,203004,};
int awmx6[] = {             203015,203015,203015,203015,203015,203015,};
int awmx8[] = {             203005,203005,203005,203005,203005,203005,};

//-------------------------------------------------------------------//






//----------------------------------------------------------------//

int amr[] = { 103012, 1103012019, 1103012010,1030120101};

int amrreddot[] = {         203001,203001,203001,203001,};
int amrholo[] = {           203002,203002,203002,203002,};
int amrx2[] = {             203003,203003,203003,203003,};
int amrx3[] = {             203014,203014,203014,203014,};
int amrx4[] = {             203004,203004,203004,203004,};
int amrx6[] = {             203015,203015,203015,203015,};
int amrx8[] = {             203005,203005,203005,203005,};

//-------------------------------------------------------------------//






int machete[] = { 108001, 1108001069, 1108001064};
int mk14[] = { 103007, 1103007028, 1103007020};
int mini14[] = { 103006, 1103006030, 1103006058};

//----------------------------------------------------------------//

int kar[] = { 103001, 1103001060, 1103001079, 1103001101, 1103001145, 1103001160, 1103001179,1103001191,1103001183};

int karreddot[] = {         203001,203001,203001,203001,203001,203001,203001,1030011857};
int karholo[] = {           203002,203002,203002,203002,203002,203002,203002,1030011856};
int karx2[] = {             203003,203003,203003,203003,203003,203003,203003,1030011855};
int karx3[] = {             203014,203014,203014,203014,203014,203014,203014,1030011854};
int karx4[] = {             203004,203004,203004,203004,203004,203004,203004,1030011853};
int karx6[] = {             203015,203015,203015,203015,203015,203015,203015,1030011852};
int karx8[] = {             203005,203005,203005,203005,203005,203005,203005,1030011851};

//-------------------------------------------------------------------//





int mg3[] = { 105010, 1105010019,1105010008};

int mg3reddot[] = {         203001,203001,};
int mg3holo[] = {           203002,203002,};
int mg3x2[] = {             203003,203003,};
int mg3x3[] = {             203014,203014,};
int mg3x4[] = {             203004,203004,};
int mg3x6[] = {             203015,203015,};

//-------------------------------------------------------------------//

int s1897[] = { 104002, 1104002022,1104002035,1104002004};
int dbs[] = { 104004, 1104004035,1104004014,1104004015,1104004024};
int s12k[] = { 104003, 1104003038,1104003037,1104003026};
int honey[] = { 101012, 1101012009};




//----------------------------------------------------------------//

int m24[] = { 103002, 1103002087, 1103002030, 1103002048, 1103002056, 1103002059};

int m24reddot[] = {         203001,203001,203001,203001,203001,203001,};
int m24holo[] = {           203002,203002,203002,203002,203002,203002,};
int m24x2[] = {             203003,203003,203003,203003,203003,203003,};
int m24x3[] = {             203014,203014,203014,203014,203014,203014,};
int m24x4[] = {             203004,203004,203004,203004,203004,203004,};
int m24x6[] = {             203015,203015,203015,203015,203015,203015,};
int m24x8[] = {             203005,203005,203005,203005,203005,203005,};

//-------------------------------------------------------------------//



int dp[] = { 105002, 1105002018, 1105002035, 1105002058, 1105002063};
int m249[] = { 105001, 1105001020, 1105001034, 1105001048, 1105001054};

//----------------------------------------------------------------//
int groza[] = { 101005, 1101005019, 1101005025, 1101005038, 1101005043, 1101005052, 1101005082};
int Groza_2[] = {             291005,1010050381,1010050521,1010050821,1010050191,1010050251,1010050431};
int grozareddot[] = {         203001,1010050326,1010050466,203001,    203001,    203001,    203001};
int grozasilent[] = {         201011,1010050327,1010050467,201011,    201011,    201011,    201011};
int grozaholo[] = {           203002,1010050325,1010050465,203002,    203002,    203002,    203002};
int grozax2[] = {             203003,1010050324,1010050464,203003,    203003,    203003,    203003};
int grozax3[] = {             203014,1010050323,1010050463,203014,    203014,    203014,    203014};
int grozax4[] = {             203004,1010050322,1010050462,203004,    203004,    203004,    203004};
int grozax6[] = {             203015,203015,    203015,    203015,    203015,    203015,    203015};
int grozaquickMag[] = {       204012,1010050328,1010050468,204012,    204012,    204012,    204012};
int grozaextendedMag[] = {    204011,1010050329,1010050469,204011,    204011,    204011,    204011};
int grozaquickNextended[] = { 204013,1010050330,1010050470,204013,    204013,    204013,    204013};
//----------------------------------------------------------------//

int famas[] ={ 101100,1101100012,1101100013};

int famasreddot[] = {         203001,203001,203001,};
int famasholo[] = {           203002,203002,203002,};
int famasx2[] = {             203003,203003,203003,};
int famasx3[] = {             203014,203014,203014,};
int famasx4[] = {             203004,203004,203004,};
int famasx6[] = {             203015,203015,203015,};



//----------------------------------------------------------------//

int aug[] = { 101006, 1101006033, 1101006044, 1101006062,1101006075,1101006067};

int augreddot[] = {         203001,1010060562,203001,203001,1010060696,};
int augholo[] = {           203002,1010060561,203002,203002,1010060695,};
int augx2[] = {             203003,1010060554,203003,203003,1010060694,};
int augx3[] = {             203014,1010060553,203014,203014,1010060693,};
int augx4[] = {             203004,1010060552,203004,203004,1010060692,};
int augx6[] = {             203015,1010060551,203015,203015,1010060691,};
int augLazer[] = {             202007,1010060574,202007,202007,1010060707,};
int augFlash[] = {            201010,1010060571,201010,201010,1010060699,};

//-------------------------------------------------------------------//





int qbz[] = { 101007, 1101007062, 1101007046, 1101007036, 1101007025};
int m16[] = { 101002, 1101002029, 1101002056, 1101002068, 1101002081, 1101002103};
int uzi[] = { 102001, 1102001024, 1102001036, 1102001058, 1102001069, 1102001089, 1102001102};

//-----------------------------------------------------------------//
int ump[] = { 102002,1102002136, 1102002061, 1102002090, 1102002117, 1102002124, 1102002129, 1102002043,1102002030,1102002083};

int umpreddot[] = {         203001,203001,203001,203001,203001,203001,203001,203001,203001,203001};
int umpholo[] = {           203002,203002,203002,203002,203002,203002,203002,203002,203002,203002};
int umpx2[] = {             203003,203003,203003,203003,203003,203003,203003,203003,203003,203003};
int umpx3[] = {             203014,203014,203014,203014,203014,203014,203014,203014,203014,203014};
int umpx4[] = {             203004,203004,203004,203004,203004,203004,203004,203004,203004,203004};
int umpx6[] = {             203015,203015,203015,203015,203015,203015,203015,203015,203015,203015};


//----------------------------------------------------------------//

int vectorr[] = { 102003, 1102003020, 1102003031, 1102003065, 1102003080};
int tommy[] = { 102004, 1102004018, 1102004034};
int p90[] = { 102105, 1102105012};
int bizon[] = { 102005, 1102005007, 1102005020, 1102005041};


//-------------------------------------------------------------------//





int ace32[] = { 101102, 1101102007, 1101102017,1101102025};


int ace32reddot[] = {         203001,203001,203001,203001};
int ace32holo[] = {           203002,203002,203002,203002};
int ace32x2[] = {             203003,203003,203003,203003};
int ace32x3[] = {             203014,203014,203014,203014};
int ace32x4[] = {             203004,203004,203004,203004};
int ace32x6[] = {             203015,203015,203015,203015};

//-------------------------------------------------------------------//





int pan[] = { 108004, 1108004125, 1108004145, 1108004160, 1108004283, 1108004337, 1108004356, 1108004365, 1108004054, 1108004008};

int m249s[] = { 205009, 1050010351, 1050010412, 1050010482, 1050010542};

//-------------------------------------------------------------------//

namespace VehicleSkins {
    // Vehicle skin constants
    constexpr int DACIA_KOENIGSEGG = 131072;
    constexpr int COUPE_LAMBORGHINI = 262144;
    constexpr int SPORTS_CAR_VINTAGE = 524296;
    constexpr int CLASSIC_MUSCLE = 262152;
    constexpr int XSUIT_PREMIUM = 403003;
}

{{ ... }}
