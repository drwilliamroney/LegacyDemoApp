// WITPAE_Monitor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <windows.h>


enum Rank {
	WO=0,
	LT2=1,
	LT1=2,
	CPT=3,
	MAJ=4,
	LTC=5,
	COL=6,
	MGEN=7,
	LGEN=8,
	GEN=9,
	PO2=10,
	PO1=11,
	CPO=12,
	WOa=13,
	ENS=14,
	LTJG=15,
	LT=16,
	LCDR=17,
	CDR=18,
	CPTa=19,
	RADM=20,
	VADM=21,
	ADM=22,
	ENSa=23,
	LTJGa=24,
	LTa=25,
	LCDRa=26,
	CDRa=27,
	CPTb=28,
	RADMa=29,
	VADMa=30,
	ADMa=31,
	FO=32,
	LT2a=33,
	LT1a=34,
	CPTc=35,
	MAJa=36,
	LTCa=37,
	COLa=38,
	BGEN=39,
	MGENa=40,
	LGENa=41,
	GENa=42,
	WOb=43,
	PO=44,
	FOa=45,
	FLT=46,
	SLDR=47,
	WCDR=48,
	GCPT=49,
	ACOM=50,
	AVM=51,
	AIRMARSHAL=52,
	AIRCMARSHAL=53,
};

const char* convertRank(Rank r) 
{
	static char buffer[25];
	std::snprintf(buffer, 25, "Unknown (%d)", (unsigned short)r);
	switch (r) {
	case WO:
	case WOa:
	case WOb:
		return "WO";
	case LT2:
	case LT2a:
		return "2LT";
	case LT1:
	case LT1a:
		return "1LT";
	case CPT:
	case CPTa:
	case CPTb:
	case CPTc:
		return "CPT";
	case MAJ:
	case MAJa:
		return "MAJ";
	case LTC:
	case LTCa:
		return "LTC";
	case COL:
	case COLa:
		return "COL";
	case MGEN:
	case MGENa:
		return "MGEN";
	case LGEN:
	case LGENa:
		return "LGEN";
	case GEN:
	case GENa:
		return "GEN";
	case PO2:
		return "PO2";
	case PO1:
		return "PO1";
	case PO:
		return "PO";
	case CPO:
		return "CPO";
	case ENS:
	case ENSa:
		return "ENS";
	case LTJG:
	case LTJGa:
		return "LTJG";
	case LT:
	case LTa:
		return "LT";
	case LCDR:
	case LCDRa:
		return "LCDR";
	case CDR:
	case CDRa:
		return "CDR";
	case RADM:
	case RADMa:
		return "RADM";
	case VADM:
	case VADMa:
		return "VADM";
	case ADM:
	case ADMa:
		return "ADM";
	case FO:
	case FOa:
		return "FO";
	case BGEN:
		return "BGEN";
	case FLT:
		return "FLT";
	case SLDR:
		return "SLDR";
	case WCDR:
		return "WCDR";
	case GCPT:
		return "GCPT";
	case ACOM:
		return "ACOM";
	case AVM:
		return "AVM";
	case AIRMARSHAL:
		return "AM";
	case AIRCMARSHAL:
		return "ACM";
	default:
		return buffer;
	}
}

enum RecType {
	SCENARIO=1,
	HEADER=38,
	AIRGROUP=20,
	PILOT=22,
	AIRCRAFT=32,
	TASKFORCE=70,
	SHIPCLASS=27,
	DEVICE=31,
	LOCATION=19,
	SHIP=8,
	MINES=30,
	LEADER=21,
	PLAYERPREF=45,
};

enum Side {
	JAPAN = 0, 
	ALLIED = 1, 
	BOTHSIDES = 2,
};

enum DeviceType {
	ACCANNON = 0,
	GAROCKET = 1,
	PGM = 2,
	GPBOMB = 3,
	APBOMB = 4,
	DROPTANK = 5,
	RADARDETECT = 6,
	JAMMER = 7,
	NAVRADAR = 8,
	ACRADAR = 9,
	SURFRADAR = 10,
	AAROCKET = 11,
	FLAK = 12,
	BALLOON = 13,
	FACMACH = 14,
	ELINT = 15,
	TORPEDO = 16,
	DPGUN = 17,
	NAVYGUN = 18,
	ARMYWEAP = 19,
	ASW = 20,
	MINE = 21,
	AFV = 22,
	SQUAD = 23,
	ENGR = 24,
	VEHICLE = 25,
	RESOURCE = 26,
	ENGINE = 27,
};
const char* convertDeviceType(DeviceType type)
{
	static char buffer[25];
	std::snprintf(buffer, 25, "Unknown (%d)", (unsigned short)type);
	switch (type)
	{
	case ACCANNON:
		return "ACCANNON";
		break;
	case GAROCKET:
		return "GAROCKET";
		break;
	case PGM:
		return "PGM";
		break;
	case GPBOMB:
		return "GPBOMB";
		break;
	case APBOMB:
		return "APBOMB";
		break;
	case DROPTANK:
		return "DROPTANK";
		break;
	case RADARDETECT:
		return "RADARDETECT";
		break;
	case JAMMER:
		return "JAMMER";
		break;
	case NAVRADAR:
		return "NAVRADAR";
		break;
	case ACRADAR:
		return "ACRADAR";
		break;
	case SURFRADAR:
		return "SURFRADAR";
		break;
	case AAROCKET:
		return "AAROCKET";
		break;
	case FLAK:
		return "FLAK";
		break;
	case BALLOON:
		return "BALLOON";
		break;
	case FACMACH:
		return "FACMACH";
		break;
	case ELINT:
		return "ELINT";
		break;
	case TORPEDO:
		return "TORPEDO";
		break;
	case DPGUN:
		return "DPGUN";
		break;
	case NAVYGUN:
		return "NAVYGUN";
		break;
	case ARMYWEAP:
		return "ARMYWEAP";
		break;
	case ASW:
		return "ASW";
		break;
	case MINE:
		return "MINE";
		break;
	case AFV:
		return "AFV";
		break;
	case SQUAD:
		return "SQUAD";
		break;
	case ENGR:
		return "ENGR";
		break;
	case VEHICLE:
		return "VEHICLE";
		break;
	case RESOURCE:
		return "RESOURCE";
		break;
	case ENGINE:
		return "ENGINE";
		break;
	default:
		return buffer;
	}
}

enum ShipClassType {
	CVB = 1, CV = 2, CVL = 3, CVE = 4,
	BB = 5, BC = 6, CB = 7,
	CA = 8, CL = 9, CLAA = 10, CS = 11,
	DD = 12, DE = 13, TB = 14,
	E = 15, PG = 16, PF = 17, KV = 18, PC = 19, PB = 20, SC = 21,
	PT = 22, MTB = 23, MGB = 24,
	ML = 25,
	SS = 26, SST = 27, SSX = 28,
	AMC = 29,
	CM = 30, CMc = 31,
	DM = 32, DMS = 33,
	AM = 34,
	AS = 35, AD = 36, AV = 37, AVD = 38, AVP = 39, AR = 40, ARD = 41, AGP = 42, AG = 43, AO = 44, AE = 45, AGC = 46,
	APA = 47, LSIL = 48, LSIM = 49, LSIS = 50, APD = 51, AKA = 52, LSD = 53, LSV = 54, AP = 55, AK = 56, AKV = 57, AKE = 58,
	AKL = 59, TK = 60,
	LST = 61, LCI = 62, LCIG = 63, LCIM = 64, LCIR = 65,
	LSM = 66, LSMR = 67, LCM = 68, LCT = 69, LB = 70, LCVP = 71, LCSL = 72,
	YO = 73, ACM = 74, YMS = 75, YP = 76, HDML = 77, APc = 78, AMc = 79,
	xAP = 80, xAPc = 81, xAK = 82, xAKL = 83,
};
const char* convertShipClassType(ShipClassType type)
{
	static char buffer[25];
	std::snprintf(buffer, 25, "Unknown (%d)", (unsigned short)type);
	switch (type)
	{
	case CVB:
	case CV:
	case CVL:
	case CVE:
	case CB:
		return "Carrier";
		break;
	case BB:
	case BC:
		return "Dreadnaught";
		break;
	case CA:
	case CL:
	case CLAA: 
	case CS:
		return "Cruiser";
		break;
	case DD:
	case DE:
	case DM:
	case DMS:
		return "Destroyer";
		break;
	case KV:
	case PG:
	case PF:
	case E:
	case PC:
	case PB:
	case SC:
	case AM:
	case TB:
		return "Corvette";
		break;
	case CM:
	case CMc:
		return "Minelayer";
		break;
	case ML:
		return "Minesweeper";
		break;
	case SS:
	case SSX:
	case SST:
		return "Sub";
		break;
	case PT:
	case MGB:
	case MTB:
	case HDML:
		return "PT";
		break;
	case AS:
	case AD:
	case AV:
	case AR:
	case ARD:
	case AE:
	case AG:
	case AO:
		return "Support";
		break;
	case AVD:
	case AMC:
		return "FastTransport";
		break;
	case AP:
	case APA:
	case APc:
	case xAP:
	case xAPc:
	case LST:
	case LCI:
	case LCIG:
	case LCIM:
	case LCIR:
	case LSM:
	case LSMR:
	case LCM:
	case LCT:
	case LB:
	case LCVP:
	case LCSL:
	case LSIL:
	case LSIM:
	case LSIS:
	case APD:
	case LSD:
	case LSV:
		return "Transport";
		break;
	case AK:
	case xAK:
	case AKA:
	case AKV:
	case AKE:
	case AKL:
		return "Freighter";
		break;
	case TK:
		return "Tanker";
		break;
	case AGC:
	case AGP:
	case AVP:
	case YO:
	case ACM:
	case YMS:
	case YP:
	case AMc:
		return "LocalPatrol";
		break;
	default:
		return buffer;
	}
}

enum LocationType {
	BEACH = 0,
	BASE = 1,
	AA = 3,
	HQ = 4,
	AF = 5,
	INF = 7,
	ARM = 8,
	ARTY = 9,
	ENGRS = 10,
	CD = 11,
	TF = 12,
};
const char* convertLocation(LocationType loc)
{
	static char buffer[25];
	std::snprintf(buffer, 25, "Unknown (%d)", (unsigned short)loc);
	switch (loc)
	{
	case BEACH:
		return "BEACH";
		break;
	case BASE:
		return "BASE";
		break;
	case AA:
		return "AA";
		break;
	case HQ:
		return "HQ";
		break;
	case AF:
		return "AF";
		break;
	case INF:
		return "INF";
		break;
	case ARM:
		return "ARM";
		break;
	case ARTY:
		return "ARTY";
		break;
	case ENGRS:
		return "ENGRS";
		break;
	case CD:
		return "CD";
		break;
	case TF:
		return "TF";
		break;
	default:
		return buffer;
	}
}

enum Nationality {
	NONATIONALITY = 0,
	IJARMY = 1,
	IJNAVY = 2,
	DIVIDER = 3,
	USNAVY = 4,
	USARMY = 5,
	USMARINES = 6,
	AUSTRALIAN = 7,
	NZ = 8,
	BRITISH = 9,
	FRENCH = 10,
	DUTCH = 11,
	CHINESE = 12,
	SOVIET = 13,
	INDIAN = 14,
	CW = 15,
	PHIL = 16,
	COMCHINESE = 17,
	CANADIAN = 18,
};

const char* convertNationality(Nationality nation) 
{
	static char buffer[25];
	std::snprintf(buffer, 25, "Unknown (%d)", (unsigned short)nation);
	switch (nation)
	{
	case IJARMY:
		return "IJARMY";
		break;
	case IJNAVY:
		return "IJNAVY";
		break;
	case USNAVY:
		return "USNAVY";
		break;
	case USARMY:
		return "USARMY";
		break;
	case USMARINES:
		return "USMARINES";
		break;
	case AUSTRALIAN:
		return "AUSTRALIAN";
		break;
	case NZ:
		return "NZ";
		break;
	case BRITISH:
		return "BRITISH";
		break;
	case FRENCH:
		return "FRENCH";
		break;
	case DUTCH:
		return "DUTCH";
		break;
	case CHINESE:
		return "CHINESE";
		break;
	case SOVIET:
		return "SOVIET";
		break;
	case INDIAN:
		return "INDIAN";
		break;
	case CW:
		return "CW";
		break;
	case PHIL:
		return "PHIL";
		break;
	case COMCHINESE:
		return "COMCHINESE";
		break;
	case CANADIAN:
		return "CANADIAN";
		break;
	default:
		return buffer;
		break;
	}
}

enum AircraftType {
	FI = 0,
	FB = 1,
	NF = 2,
	DB = 3,
	LongB = 4,
	REC = 5,
	MedB = 8,
	PBY = 9,
	FP = 10,
	TBF = 12,
};
const char * convertAircraftType(AircraftType type)
{
	static char buffer[25];
	std::snprintf(buffer, 25, "Unknown (%d)", (unsigned short)type);
	switch (type)
	{
	case REC:
		return "REC";
		break;
	case FI:
		return "F";
		break;
	case FB:
		return "FB";
		break;
	case NF:
		return "FP";
		break;
	case DB:
		return "DB";
		break;
	case LongB:
		return "LRB";
		break;
	case MedB:
		return "MRB";
		break;
	case FP:
		return "FP";
		break;
	case TBF:
		return "TBF";
		break;
	case PBY:
		return "PBY";
		break;
	default:
		return buffer;
	}
}

enum Convert {
	NONE = 0,
	TO = 8,
	FROM = 16,
	BOTH = 24,
};

enum Fate {
	ACTIVE = 1,
	WIA = 2,
	MIA = 3,
	KIA = 4,
	RES = 0,
	TRACOM = 30000,
};
const char* convertFate(Fate f)
{
	static char buffer[25];
	std::snprintf(buffer, 25, "Unknown (%d)", (unsigned short)f);
	switch (f)
	{
	case ACTIVE:
		return "TRACOM";
		break;
	case WIA:
		return "WIA";
		break;
	case MIA:
		return "MIA";
		break;
	case KIA:
		return "KIA";
		break;
	case RES:
		return "RES";
		break;
	case TRACOM:
		return "TRACOM";
		break;
	default:
		return buffer;
	}
}

enum TaskForceMission {
	AIRCOMBAT=1,
	SURFACE=2,
	BOMBARDMENT=3,
	FASTTRANSPORT = 4,
	TRANSPORT = 5,
	REPLENISHMENT = 6,
	MINELAYING=7,
	SUBPATROL=8,
	SUBMINELAYING=9,
	SUBTRANSPORT=10,
	CARGO = 11,
	/*12*/
	AIRTRANSPORT=13,
	CVESCORT=14,
	AMPHIB = 15,
	ASWCOMBAT=16,
	PTBOAT=17,
	TANKER = 18,
	MINESWEEPING=19,
	LANDINGCRAFT=20,
	/*21*/
	SUPPORT=22,
	LOCALMINESWEEPING=23,
	/*24*/
	ESCORT=25,
};

const char* convertTFMission(TaskForceMission mission) 
{
	static char buffer[25];
	std::snprintf(buffer, 25, "Unknown (%d)", (unsigned short)mission);
	switch (mission)
	{
	case AIRCOMBAT:
		return "AIRCOMBAT";
		break;
	case SURFACE:
		return "SURFACE";
		break;
	case BOMBARDMENT:
		return "BOMBARDMENT";
		break;
	case REPLENISHMENT:
		return "REPLENISHMENT";
		break;
	case MINELAYING:
		return "MINELAYING";
		break;
	case SUBPATROL:
		return "SUBPATROL";
		break;
	case SUBMINELAYING:
		return "SUBMINELAYING";
		break;
	case SUBTRANSPORT:
		return "SUBTRANSPORT";
		break;
	case AIRTRANSPORT:
		return "AIRTRANSPORT";
		break;
	case CVESCORT:
		return "CVESCORT";
		break;
	case ASWCOMBAT:
		return "ASWCOMBAT";
		break;
	case PTBOAT:
		return "PTBOAT";
		break;
	case MINESWEEPING:
		return "MINESWEEPING";
		break;
	case LANDINGCRAFT:
		return "LANDINGCRAFT";
		break;
	case SUPPORT:
		return "SUPPORT";
		break;
	case LOCALMINESWEEPING:
		return "LOCALMINESWEEPING";
		break;
	case ESCORT:
		return "ESCORT";
		break;
	case TRANSPORT:
		return "TRANSPORT";
		break;
	case FASTTRANSPORT:
		return "FASTTRANSPORT";
		break;
	case CARGO:
		return "CARGO";
		break;
	case AMPHIB:
		return "AMPHIB";
		break;
	case TANKER:
		return "TANKER";
		break;
	default:
		return buffer;
	}
}

enum TaskForceSpeed {
	MISSION = 0,
	CRUISE = 1,
	MAXIMUM = 2,
};

enum OpMode {
	STRAT = 2,
};
const char* convertOperationMode(OpMode mode)
{
	static char buffer[25];
	std::snprintf(buffer, 25, "Unknown (%d)", (unsigned short)mode);
	switch (mode)
	{
	case STRAT:
		return "STRAT";
		break;
	default:
		return buffer;
	}
}

enum CombatMode {
};
const char* convertCombatMode(CombatMode mode)
{
	static char buffer[25];
	std::snprintf(buffer, 25, "Unknown (%d)", (unsigned short)mode);
	switch (mode)
	{
	default:
		return buffer;
	}
}

enum RepairMode {
	READINESS=0,
	PIERSIDE=1,
	REPAIRSHIP=2,
	SHIPYARD=3
};
const char* convertRepairMode(RepairMode mode)
{
	static char buffer[25];
	std::snprintf(buffer, 25, "Unknown (%d)", (unsigned short)mode);
	switch (mode)
	{
	case READINESS:
		return "READINESS";
		break;
	case PIERSIDE:
		return "PIERSIDE";
		break;
	case REPAIRSHIP:
		return "REPAIRSHIP";
		break;
	case SHIPYARD:
		return "SHIPYARD";
		break;
	default:
		return buffer;
	}
}
enum RepairPriority {
	LOW = 0,
	NORMAL = 1,
	HIGH = 2,
	CRITICAL = 3
};
const char* convertRepairPriority(RepairPriority mode)
{
	static char buffer[25];
	std::snprintf(buffer, 25, "Unknown (%d)", (unsigned short)mode);
	switch (mode)
	{
	case LOW:
		return "LOW";
		break;
	case NORMAL:
		return "NORMAL";
		break;
	case HIGH:
		return "HIGH";
		break;
	case CRITICAL:
		return "CRITICAL";
		break;
	default:
		return buffer;
	}
}
enum HQType {
	COMMAND=1,
	ARMY=3,
	AIRFORCE=4,
	FLEET = 5,
};
const char* convertHQType(HQType hqtype)
{
	static char buffer[25];
	std::snprintf(buffer, 25, "Unknown (%d)", (unsigned short)hqtype);
	switch (hqtype)
	{
	case COMMAND:
		return "COMMAND";
		break;
	case ARMY:
		return "ARMY";
		break;
	case AIRFORCE:
		return "AIRFORCE";
		break;
	case FLEET:
		return "FLEET";
		break;
	default:
		return buffer;
	}
}

typedef struct {
	char buffer[600000];
} __debug_struct;


typedef struct {
	char skip[30];
	unsigned short gameturn;
	char skip2[84];
	int japanVP;
	int alliedVP;
	char skip3[60];
	struct {
		int poolJ;
		int poolA;
	}__planesBuilt[1000];
	struct {
		int poolJ;
		int poolA;
	}__armamentBuilt[2000];
	int planeTLoss[1000];
	struct {
		int poolJ;
		int poolA;
	}__planeTUsed[1000];
	struct {
		int poolJ;
		int poolA;
	}__armamentUsed[2000];

	char skip4[12692];
	int japanLCULoss;
	int alliedLCULoss;
	int japanLCUdayLoss;
	int alliedLCUdayLoss;
	char skip5;
	unsigned char gametype;
	unsigned char pbemphase;
	char password1[9];
	char password2[9];
	char skip6[19];
	char scenario[66];
	char skip6a[134];
	char pilotpool_skip[654];
	char skip8[2];
	int politicalPointsJapan;
	int politicalPointsAllied;
	unsigned short scenPolPtsJapan;
	unsigned short scenPolPtsAllied;
	char all_the_rest;
}__scen_info;

typedef struct {
	char comment[1000];
	char timestamp[800];
} __header;

typedef struct {
	struct {
		char groupname[26];
		char skip[4];
		short acType;
		int leaderID;
		short hqID;
		char skip2[2];
		short baseID;
		short reinforceBaseID;
		short primaryMission;
		short secondaryMission;
		short targetID;
		char skip3[8];
		short fragmentNumber;
		char skip4[3];
		char acPercent;
		char skip5[120];
		char pilotMorale;
		char pilotExp;
		char skip6[6];
		int targetX;
		int targetY;
		char skip7[4];
		char acReady;
		char skip8;
		char acMaintained;
		char acReserve;
		char skip9;
		char acDamaged;
		char skip10[2];
		short acAlt;
		char skip11[4];
		char nation;
		char skip12;
		int delay;
		char delayReinforcement;
		char skip13[7];
		short acKills;
		char skip14[2];
		short pilotsAvail;
		char skip15[7];
		char maxplanes;
		char skip16[58];
		short acRange;
		char skip17[2];
		short upgradeTo;
		char skip18[60];
		short agrUpgrade[10];
		char skip19[2];
		int withdraw;
		int delay2;
		char skip20[112];
		byte acReinfAvail;
		char skip21[33];
		short pilotsActive;
		char skip22[12];
		char acPctCAP;
		char acPctLRCAP;
		char acPctASW;
		char acPctSearch;
		char acPctTrain;
		char acPctRest;
		char skip23[62];
		char acSearchASWStart;
		char acSearchASWEnd;
		char acSearchNavStart;
		char acSearchNavEnd;
		char skip24[48];
	} __airgroup[30000];
}__airgroup_info;

typedef struct {
	struct {
		union {
			char skipc[4];
			unsigned short skips[2];
		} skip;
		int tfEndurance;
		int tfEnduranceReq;
		union {
			char skipc[32];
			unsigned short skips[16];
			unsigned long skipl[8];
		}skip2;
		int tfFlagship;
		char skip3[6];
		unsigned short tfHomePort;
		union {
			char skipc[292];
			unsigned short skips[146];
			unsigned long skipl[73];
		}skip4;
		char skip4a;
		char tfMission;
		char skip5[3];
		char tfSpeed;
		union {
			char skipc[202];
//			unsigned short skips[101];
		}skip6;
	} __taskgroup[4000];
}__taskgroup_info;

typedef struct {
	struct {
		unsigned short x;
		unsigned short y;
		unsigned short side;
		char skip[4];
		unsigned short number;
		char skip2[8];
	}__minefield[6000];
}__minefield_info;

typedef struct {
	struct {
		char name[25];
		char rank;
		char leadership;
		char inspiration;
		char naval;
		char air;
		char land;
		char admin;
		char aggression;
		char skip[9];
		char nation;
		char skip2;
		int delay;
		char polPoints;
		char type;
		char skip3[130];
	}__leader[50000];
}__leader_info;

typedef struct {
	struct {
		char name[25];
		char nation;
		char skip;
		char shipExpDay;
		char shipExpNight;
		char shipStopBuild;
		char skip2[2];
		int shipLeader;
		int shipDelay;
		unsigned short shipArrivalPort;
		char skip3[2];
		int shipWithdrawal;
		int shipReturn;
		unsigned short shipClass;
		char shipSpeed;
		char skip4[3];
		unsigned short shipEndurance;
		unsigned short shipBase;
		unsigned short shipTF;
		char skip5[6];
		unsigned short shipWeapon[20];
		char skip6[60];
		unsigned short shipWpnAmmo[20];
		char skip7[20];
		unsigned short shipWpnArmor[20];
		char shipWpnDmg[20];
		unsigned short shipOps;
		char skip8[8];
		int shipUnitLoaded;
		char skip9[10];
		unsigned short shipSupplyLoaded;
		unsigned short shipFuelLoaded;
		unsigned short shipResourcesLoaded;
		unsigned short shipOilLoaded;
		char skip10[9];
		char shipFireDmg;
		char shipSysDmg;
		char shipFloatDmg;
		char shipMajorFloatDmg;
		char shipEngineDmg;
		char shipMajorEngineDmg;
		char shipFOWStatus;
		char shipRepairPriority;
		char shipRepairMode;
		char skip11a;
		char shipTempAPConv;
		unsigned short shipRepairDelay;
		unsigned short shipConversionDelay;
		char skip11[2];
		unsigned short shipSunkDevice;
		unsigned short shipSunkDelay;
		unsigned short shipSunkX;
		unsigned short shipSunkY;
		unsigned short shipSunkBase;
		char shipSunkYear;
		char shipSunkMonth;
		char shipSunkDay;
		char shipBuild;
		char skip12;
		char shipScuttled;
		char skip13;
		char shipUpgrade;
		char skip14[30];
		unsigned short shipFOWDelay;
		unsigned short shipFOWShip;
		char skip15[64];
	}__ship[20000];
}__ship_info;

typedef struct {
	struct {
		char name[25];
		char type;
		char nation;
		char skip;
		int tonnage;
		unsigned short fuel;
		unsigned short endurance;
		char maxSpd;
		char cruiseSpd;
		char manSpeed;
		unsigned char durability;
		unsigned short bitmap;
		unsigned short beltArmor;
		unsigned short deckArmor;
		unsigned short towerArmor;
		unsigned short capacity;
		unsigned short troopCapacity;
		unsigned short cargoCapacity;
		unsigned short liquidCapacity;
		unsigned short wepID[20];
		unsigned short wepNum[20];
		char wepFace[20];
		unsigned short wepAmmo[20];
		char wepTurret[20];
		unsigned short wepArmor[20];
		unsigned short upgradeID;
		char availMonth;
		char availYear;
		char upgradeShipyardSize;
		char skip2;
		unsigned short classConvertSet;
		unsigned short upgradeDmg;
		unsigned short minUpgDelay;
		unsigned short minConvDelay;
		char skip3[22];
		char specialAttribute;
		char skip4[5];
		unsigned short repairPtsPerDmgPt;
		char skip5[80];
	}__shipclass[5000];
}__shipclass_info;

typedef struct {
	struct {
		char name[25];
		char skip[7];
		unsigned short agrp;
		char skip2[4];
		unsigned short kills;
		unsigned short missions;
		char skip3;
		char rank;
		char exp;
		char fatigue;
		char fate;
		char wound;
		unsigned short delay;
		char skip4[6];
		char nationality;
		char skip5[8];
		char air;
		char navB;
		char navT;
		char navS;
		char recN;
		char asw;
		char tran;
		char grndB;
		char lowN;
		char lowG;
		char staf;
		char defN;
		char skip6[41];
		char type;
		char skip7[61];
	}__pilot[50000];
}__pilot_info;

typedef struct {
	struct {
		char name[25];
		char type;
		char skip[2];
		unsigned short maxAlt;
		unsigned short maxSpd;
		unsigned short cruiseSpd;
		unsigned short climbRate;
		unsigned short man;
		unsigned short endurance;
		char armor;
		char durability;
		unsigned short wepID[10];
		char skip2[20];
		unsigned short wepNum[10];
		char skip3[20];
		char wepFace[10];
		char skip4[50];
		unsigned short maxLoad;
		char availMonth;
		char availYear;
		char skip5[2];
		unsigned short buildRate;
		unsigned short bitmap;
		unsigned short upgrade;
		unsigned short research;
		int dayair;
		int dayground;
		int dayflak;
		int dayops;
		int totair;
		int totground;
		int totflak;
		int totops;
		char side;
		char svcrating;
		char skip6[2];
		char attrib;
		char skip7[38];
		char man10;
		char man15;
		char man20;
		char man31;
		char man32;
		char rangeNormal;
		char skip8[5];
		char endMonth;
		char endYear;
		char nation;
		char skip9[3];
		char rangeExtended;
		char skip10[5];
		char rangeDTNormal;
		char skip11[3];
		char rangeDTExtended;
		char skip12[3];
		char rangeDTMax;
		char skip13[93];
	}__aircraft[1000];
}__aircraft_info;

typedef struct {
	struct {
		char name[25];
		char skip;
		unsigned short type;
		unsigned short load;
		unsigned short range;
		unsigned short eff;
		unsigned short pen;
		unsigned short acc;
		char skip2[8];
		unsigned short dud;
		unsigned short ceiling;
		unsigned short armor;
		unsigned short antiarm;
		unsigned short antisoft;
		unsigned short upgrade;
		unsigned short buildrate;
		unsigned short availYear;
		unsigned short availMonth;
		char skip2a[4];
		char side;
		char skip3[7];
		char endYear;
		char endMonth;
		char skip4[158];
	}__device[2000];
}__device_info;

typedef struct {
	struct {
		char name[25];
		char skip;
		unsigned short owner;
		unsigned short type;
		unsigned short symbol;
		char skip2[4];
		unsigned short X;
		unsigned short Y;
		unsigned short TOE;
		unsigned short arrive;
		union {
			char skipc[8];
			unsigned short skips[4];
			unsigned long skipl[2];
		}skip3;
		unsigned short indFail;
		char skip3a[48];
		unsigned short locNear;
		unsigned short prepPercent;
		char skip4[4];
		char combatMode;
		char skip5[7];
		unsigned short HQtype;
		unsigned short radius;
		unsigned short attachedHQ;
		char skip6[4];
		int leaderID;
		char skip7[4];
		unsigned short deviceID[20];
		unsigned short deviceNumber[20];
		unsigned short deviceDis[20];
		signed short skip8[40];
		unsigned short deviceTOE[20];
		unsigned short deviceTOENum[20];
		int airfieldSPS;
		unsigned short portSPS;
		unsigned short port;
		unsigned short portExpand;
		unsigned short airfield;
		unsigned short airfieldExpand;
		unsigned short fort;
		unsigned short fortExpand;
		char skip9[6];
		unsigned short runwayDmg;
		unsigned short portDmg;
		unsigned short airfieldDmg;
		unsigned short skip10[20];
		char skip10a[7];
		int shipRepair;
		char skip11[7];
//		char skip11[11];
		int resources;
		int resourcesNeeded;
		char skip12[4];
		int oil;
		int oilNeeded;
		int fuel;
		int fuelRequested;
		int supply;
		int supplyNeeded;
		union {
			char skipc[4];
			unsigned short skips[2];
			unsigned long skipl;
		}skip13;
		int supportReq;
		int supportTotal;
		int AVsupportReq;
		int AVsupportTotal;
		int delay;
		union {
			char skipc[8];
			unsigned short skips[4];
		}skip14;
		unsigned short suffix;
		unsigned short skip15;
		short artillery;
		short aa;
		short hasAircraft;
		unsigned short skip16;
		short avSquads;
		union {
			char skipc[58];
			unsigned short skips[29];
		}skip17;
		char exp;
		char morale;
		char fatigue;
		char marchDir;
		char marchLen;
		char skip18[3];
		int shipCount;
		char skip19[2];
		unsigned short destX;
		unsigned short destY;
		unsigned short loadedUnit;
		unsigned short parentID;
		unsigned short fragMbr;
		char detectionLevel;
		char maxDetectionLevel;
		union {
			char skipc[108];
			unsigned short skips[40];
		}skip20;
		unsigned short japanVP;
		unsigned short alliedVP;
		union {
			char skipc[28];
			unsigned short skips[10];
		}skip21;
		char nation;
		char skip22[9];
		unsigned short dailySupply;
		unsigned short dailyFuel;
		unsigned short dailyOil;
		unsigned short dailyRes;
		union {
			char skipc[8];
			unsigned short skips[4];
		}skip23;
		char replace;
		char skip24[3];
		char deviceBld[20];
		union {
			char skipc[6];
			unsigned short skips[3];
		}skip25;
		char deviceRep[20];
		union {
			char skipc[12];
			unsigned short skips[6];
		}skip26;
		unsigned short japGarrison;
		unsigned short upgradeTOE;
		unsigned short operationsMode;
		unsigned short withdrawal;
		union {
			char skipc[10];
			unsigned short skips[5];
		}skip27;
		int upgradeTOEdelay;
		union {
			char skipc[30];
			unsigned short skips[15];
		}skip28;
		char pack;
		char skip29;
		unsigned short primaryUnit;
		char skip30[2];
		unsigned short airgroupStack;
		unsigned short aircraftStack;
		int attr;
		char skip31[2];
		char airHQTorpMax;
		char skip32[3];
		char airHQTorpCur;
		char skip33[3];
		unsigned short alliedGarrison;
		char skip34[140];
		char lcuUpgrade;
		char skip35[51];
	}__location[18000];
}__location_info;

typedef struct {
	int PWSopened;
	RecType PWSid;
	int PWSrec;
	union {
		__debug_struct* debug;
		__scen_info* sceninfo;
		__header* header;
		__airgroup_info* airgroups;
		__taskgroup_info* taskgroups;
		__minefield_info* minefields;
		__leader_info* leaders;
		__ship_info* ships;
		__shipclass_info* shipclasses;
		__pilot_info* pilots;
		__aircraft_info* aircrafts;
		__device_info* devices;
		__location_info* locations;
	} PWSaddress;
	char* PWSMessage;
} _pws_struct;


typedef int (*PWSOPENFILE)(_pws_struct*, const char*, bool);
typedef int (*PWSCLOSEFILE)(_pws_struct*);
typedef int (*PWSGETNEXT)(_pws_struct*);

static char strbuf[50 + 1];
const char* embeddedQuotes(const char* str) {
	for (size_t i = 0, j = 0; i <= strlen(str); i++, j++) {
		if (str[i] == '"') {
			strbuf[j] = '\\';
			j++;
			strbuf[j] = str[i];
		}
		else {
			strbuf[j] = str[i];
		}
	}
	return strbuf;
}

void loadScenario(const __scen_info& info)
{
	std::cout << "\"gameturn\": " << info.gameturn << ",";
}

void loadHeader(const __header& info)
{
	std::cout << "\"gameinfo\": \"" << info.comment << "\",";
	/* Add more here when concerned about production pools, victory, and political points */
}

void loadAirGroups(const __airgroup_info& info)
{
	std::cout << "\"airgroups\": [";
	for (int i = 1; i < 30000; i++) {
		if ((strlen(info.__airgroup[i].groupname)>0) && (info.__airgroup[i].nation > (Nationality)DIVIDER)) {
			std::cout << "{\"GroupName\": \"" << embeddedQuotes(info.__airgroup[i].groupname);
			std::cout << "\",\"ID\": " << i;
			std::cout << ",\"fragmentNumber\": " << (int)info.__airgroup[i].fragmentNumber;
			std::cout << ",\"acType\": " << (int)info.__airgroup[i].acType;
			std::cout << ",\"leaderID\": " << (int)info.__airgroup[i].leaderID;
			std::cout << ",\"hqID\": " << (int)info.__airgroup[i].hqID;
			std::cout << ",\"baseID\": " << (int)info.__airgroup[i].baseID;
			std::cout << ",\"acReady\": " << (int)info.__airgroup[i].acReady;
			std::cout << ",\"maxplanes\": " << (int)info.__airgroup[i].maxplanes;
			std::cout << ",\"acDamaged\": " << (int)info.__airgroup[i].acDamaged;
			std::cout << ",\"acMaintained\": " << (int)info.__airgroup[i].acMaintained;
			std::cout << ",\"acReserve\": " << (int)info.__airgroup[i].acReserve;
			std::cout << ",\"pilotsAvail\": " << (int)info.__airgroup[i].pilotsAvail;
			std::cout << ",\"pilotsActive\": " << (int)info.__airgroup[i].pilotsActive;
			std::cout << ",\"withdraw\": " << (int)info.__airgroup[i].withdraw;
			std::cout << "},";
		}
	}
	std::cout << "{}],";
}

void loadTaskGroups(const __taskgroup_info& info)
{
	std::cout << "\"taskgroups\": [";
	for (int i = 1; i < 4000; i++) {
		std::cout << "{\"Mission\": \"" << convertTFMission((TaskForceMission)info.__taskgroup[i].tfMission);
		std::cout << "\",\"ID\": " << i;
		std::cout << ",\"flagshipID\": " << info.__taskgroup[i].tfFlagship;
		std::cout << ",\"enduranceReq\": " << info.__taskgroup[i].tfEnduranceReq;
		std::cout << ",\"speed\": " << (unsigned short) info.__taskgroup[i].tfSpeed;
		std::cout << ",\"homePort\": " << info.__taskgroup[i].tfHomePort;
		std::cout << "},";
	}
	std::cout << "{}],";
}

void loadMinefields(const __minefield_info& info)
{
	std::cout << "\"minefields\": [";
	for (int i = 1; i < 6000; i++) {
		if ((info.__minefield[i].side != (Side)JAPAN) &&
			((info.__minefield[i].x > 0) &&
			 (info.__minefield[i].y > 0))
			) {
			std::cout << "{\"x\": " << info.__minefield[i].x;
			std::cout << ",\"y\": " << info.__minefield[i].y;
			std::cout << ",\"size\": " << info.__minefield[i].number;
			std::cout << ",\"ID\": " << i;
			std::cout << "},";
		}
	}
	std::cout << "{}],";
}

void loadLeaders(const __leader_info& info)
{
	std::cout << "\"leaders\": [";
	for (int i = 1; i < 50000; i++) {
		if ((strlen(info.__leader[i].name) > 0) && (info.__leader[i].nation > (Nationality)DIVIDER)) {
			std::cout << "{\"Name\": \"" << embeddedQuotes(info.__leader[i].name);
			std::cout << "\",\"ID\": " << i;
			std::cout << ",\"Rank\": \"" << convertRank((Rank)info.__leader[i].rank);
			std::cout << "\",\"Nation\": \"" << convertNationality((Nationality)info.__leader[i].nation);
			std::cout << "\",\"Type\": " << (unsigned short)info.__leader[i].type;
			std::cout << "},";
		}
	}
	std::cout << "{}],";
}

void loadShips(const __ship_info& info)
{
	std::cout << "\"ships\": [";
	for (int i = 1; i < 20000; i++) {
		if (strlen(info.__ship[i].name) > 0) {
			if (info.__ship[i].nation > (Nationality)DIVIDER) {
				std::cout << "{\"Name\": \"" << embeddedQuotes(info.__ship[i].name);
				std::cout << "\",\"ID\": " << i;
				std::cout << ",\"Nation\": \"" << convertNationality((Nationality)info.__ship[i].nation);
				std::cout << "\",\"leaderID\": " << info.__ship[i].shipLeader;
				std::cout << ",\"delay\": " << info.__ship[i].shipDelay;
				std::cout << ",\"arrivalLoc\": " << info.__ship[i].shipArrivalPort;
				std::cout << ",\"withdraw\": " << info.__ship[i].shipWithdrawal;
				std::cout << ",\"classID\": " << info.__ship[i].shipClass;
				std::cout << ",\"shipTF\": " << info.__ship[i].shipTF;
				std::cout << ",\"unitLoaded\": " << info.__ship[i].shipUnitLoaded;
				std::cout << ",\"supplyLoaded\": " << info.__ship[i].shipSupplyLoaded;
				std::cout << ",\"fuelLoaded\": " << info.__ship[i].shipFuelLoaded;
				std::cout << ",\"resourcesLoaded\": " << info.__ship[i].shipResourcesLoaded;
				std::cout << ",\"oilLoaded\": " << info.__ship[i].shipOilLoaded;
				std::cout << ",\"fireDmg\": " << (unsigned short)info.__ship[i].shipFireDmg;
				std::cout << ",\"sysDmg\": " << (unsigned short)info.__ship[i].shipSysDmg;
				std::cout << ",\"floatDmg\": " << (unsigned short)info.__ship[i].shipFloatDmg;
				std::cout << ",\"majorFloatDmg\": " << (unsigned short)info.__ship[i].shipMajorFloatDmg;
				std::cout << ",\"engineDmg\": " << (unsigned short)info.__ship[i].shipEngineDmg;
				std::cout << ",\"majorEngineDmg\": " << (unsigned short)info.__ship[i].shipMajorEngineDmg;
				std::cout << ",\"repairPriority\": \"" << convertRepairPriority((RepairPriority)info.__ship[i].shipRepairPriority);
				std::cout << "\",\"repairMode\": \"" << convertRepairMode((RepairMode)info.__ship[i].shipRepairMode);
				std::cout << "\",\"baseID\": " << info.__ship[i].shipBase;
				std::cout << ",\"repairDelay\": " << info.__ship[i].shipRepairDelay;
				std::cout << ",\"convDelay\": " << info.__ship[i].shipConversionDelay;
				std::cout << ",\"sunkDevice\": " << info.__ship[i].shipSunkDevice;
				std::cout << ",\"scuttled\": " << (unsigned short)info.__ship[i].shipScuttled;
				std::cout << "},";
			}
			else {
				std::cout << "{\"Name\": \"" << embeddedQuotes(info.__ship[i].name);
				std::cout << "\",\"ID\": " << i;
				std::cout << ",\"Nation\": \"" << convertNationality((Nationality)info.__ship[i].nation);
				std::cout << "\",\"leaderID\": -1";
				std::cout << ",\"delay\": -1";
				std::cout << ",\"arrivalLoc\": -1";
				std::cout << ",\"withdraw\": -1";
				std::cout << ",\"classID\": " << info.__ship[i].shipClass;
				std::cout << ",\"shipTF\": -1";
				std::cout << ",\"unitLoaded\": -1";
				std::cout << ",\"supplyLoaded\": -1";
				std::cout << ",\"fuelLoaded\": -1";
				std::cout << ",\"resourcesLoaded\": -1";
				std::cout << ",\"oilLoaded\": -1";
				std::cout << ",\"fireDmg\": -1";
				std::cout << ",\"sysDmg\": -1";
				std::cout << ",\"floatDmg\": -1";
				std::cout << ",\"majorFloatDmg\": -1";
				std::cout << ",\"engineDmg\": -1";
				std::cout << ",\"majorEngineDmg\": -1";
				std::cout << ",\"repairPriority\": \"";
				std::cout << "\",\"repairMode\": \"";
				std::cout << "\",\"baseID\": -1";
				std::cout << ",\"repairDelay\": -1";
				std::cout << ",\"convDelay\": -1";
				std::cout << ",\"sunkDevice\": -1";
				std::cout << ",\"scuttled\": -1";
				std::cout << "},";
			}
		} 
	}
	std::cout << "{}],";
}

void loadShipClasses(const __shipclass_info& info)
{
	std::cout << "\"shipclasses\": [";
	for (int i = 1; i < 5000; i++) {
		if (strlen(info.__shipclass[i].name) > 0) {
			std::cout << "{\"Name\": \"" << embeddedQuotes(info.__shipclass[i].name);
			std::cout << "\",\"Nation\": \"" << convertNationality((Nationality)info.__shipclass[i].nation);
			std::cout << "\",\"Type\": \"" << convertShipClassType((ShipClassType)info.__shipclass[i].type);
			std::cout << "\",\"ID\": " << i;
			std::cout << ",\"Tonnage\": " << info.__shipclass[i].tonnage;
			std::cout << "},";
		}
	}
	std::cout << "{}],";
}

void loadPilots(const __pilot_info& info)
{
	std::cout << "\"pilots\": [";
	for (int i = 1; i < 50000; i++) {
		if ((info.__pilot[i].name) && (info.__pilot[i].nationality > (Nationality)DIVIDER)) {
			std::cout << "{\"Name\": \"" << embeddedQuotes(info.__pilot[i].name);
			std::cout << "\",\"airgroupID\": \"" << convertRank((Rank)info.__pilot[i].rank);
			std::cout << "\",\"Nationality\": \"" << convertNationality((Nationality)info.__pilot[i].nationality);
			std::cout << "\",\"Fate\": \"" << convertFate((Fate)info.__pilot[i].fate);
			std::cout << "\",\"ID\": " << i;
			std::cout << ",\"airgroupID\": " << info.__pilot[i].agrp;
			std::cout << ",\"kills\": " << info.__pilot[i].kills;
			std::cout << ",\"missions\": " << info.__pilot[i].missions;
			std::cout << "},";
		}
	}
	std::cout << "{}],";
}

void loadAircraft(const __aircraft_info& info)
{
	std::cout << "\"planes\": [";
	for (int i = 1; i < 1000; i++) {
		if (strlen(info.__aircraft[i].name) > 0) {
			std::cout << "{\"Name\": \"" << embeddedQuotes(info.__aircraft[i].name);
			std::cout << "\",\"Type\": \"" << convertAircraftType((AircraftType)info.__aircraft[i].type);
			std::cout << "\",\"Nation\": \"" << convertNationality((Nationality)info.__aircraft[i].nation);
			std::cout << "\",\"ID\": " << i;
			std::cout << "},";
		}
	}
	std::cout << "{}],";
}

void loadDevices(const __device_info& info)
{
	std::cout << "\"devices\": [";
	for (int i = 1; i < 2000; i++) {
		if (strlen(info.__device[i].name) > 0) {
			std::cout << "{\"Name\": \"" << embeddedQuotes(info.__device[i].name);
			std::cout << "\",\"Type\": \"" << convertDeviceType((DeviceType)info.__device[i].type);
			std::cout << "\",\"ID\": " << i;
			std::cout << "},";
		}
	}
	std::cout << "{}],";
}

void loadLocations(const __location_info& info)
{
	std::cout << "\"locations\": [";
	for (int i = 1; i < 18000; i++) {
		if ((info.__location[i].owner == (Side)ALLIED) || 
			(info.__location[i].type == (LocationType)BASE) ||
			(info.__location[i].type == (LocationType)BEACH) ||
			(info.__location[i].type == (LocationType)AF)) {
			std::cout << "{\"Name\": \"" << embeddedQuotes(info.__location[i].name);
			std::cout << "\",\"ID\": " << i;
			std::cout << ",\"Type\": \"" << convertLocation((LocationType)info.__location[i].type);
			std::cout << "\",\"Nation\": \"" << convertNationality((Nationality)info.__location[i].nation);
			std::cout << "\",\"X\": " << info.__location[i].X;
			std::cout << ",\"Y\": " << info.__location[i].Y;
			std::cout << ",\"DestX\": " << info.__location[i].destX;
			std::cout << ",\"DestY\": " << info.__location[i].destY;
			std::cout << ",\"CombatMode\": \"" << convertCombatMode((CombatMode)info.__location[i].combatMode);
			std::cout << "\",\"attachedHQID\": " << info.__location[i].attachedHQ;
			std::cout << ",\"leaderID\": " << info.__location[i].leaderID;
			std::cout << ",\"prepTargetID\": " << info.__location[i].locNear;
			std::cout << ",\"prepPerc\": " << info.__location[i].prepPercent;
			std::cout << ",\"shiprepair\": " << info.__location[i].shipRepair;
			std::cout << ",\"devices\": [";
			for (int j = 0; j < 20; j++) {
				if (info.__location[i].deviceID[j] > 0) {
					std::cout << "{\"ID\": " << info.__location[i].deviceID[j] << ", \"Count\": " << info.__location[i].deviceNumber[j] << "},";
				}
			}
			std::cout << "{\"Done\": 1}],\"airfield\": {\"Max\": " << info.__location[i].airfieldSPS << ", \"Current\": " << info.__location[i].airfield << "}";
			std::cout << ",\"port\": {\"Max\": " << info.__location[i].portSPS << ", \"Current\": " << info.__location[i].port << "}";
			std::cout << ",\"fortifications\": " << info.__location[i].fort;
			std::cout << ",\"damage\": {\"Airfield\": " << info.__location[i].airfieldDmg << ", \"Port\": " << info.__location[i].portDmg << ", \"Runway\": " << info.__location[i].runwayDmg << "}";
			std::cout << ",\"resources\": {\"Requested\": " << info.__location[i].resourcesNeeded << ", \"Current\": " << info.__location[i].resources << "}";
			std::cout << ",\"oil\": {\"Requested\": " << info.__location[i].oilNeeded << ", \"Current\": " << info.__location[i].oil << "}";
			std::cout << ",\"supply\": {\"Requested\": " << info.__location[i].supplyNeeded << ", \"Current\": " << info.__location[i].supply << "}";
			std::cout << ",\"fuel\": {\"Requested\": " << info.__location[i].fuelRequested << ", \"Current\": " << info.__location[i].fuel << "}";
			std::cout << ",\"loadedunitID\": " << info.__location[i].loadedUnit;
			std::cout << ",\"parentID\": " << info.__location[i].parentID;
			std::cout << ",\"fragMbr\": " << info.__location[i].fragMbr;
			std::cout << ",\"OpMode\": \"" << convertOperationMode((OpMode)info.__location[i].operationsMode);
			std::cout << "\",\"Pack\": " << (unsigned short)info.__location[i].pack;
			std::cout << ",\"primaryUnit\": " << info.__location[i].primaryUnit;
			std::cout << ",\"currentShipCount\": " << info.__location[i].shipCount;
			std::cout << ",\"airgroupMax\": " << info.__location[i].airgroupStack;
			std::cout << ",\"currentAircraftCount\": " << info.__location[i].hasAircraft;
			std::cout << ",\"aircraftMax\": " << info.__location[i].aircraftStack;
			std::cout << ",\"HQType\": \"" << convertHQType((HQType)info.__location[i].HQtype);
			std::cout << "\",\"radius\": " << info.__location[i].radius;
			std::cout << ",\"attachedHQ\": " << info.__location[i].attachedHQ;
			std::cout << "},";
		}
	}
	std::cout << "{}],";
}

void usage(const char * appname)
{
	std::cerr << "Usage:  " << appname << " <pws file/path" << std::endl;
}

void dumpPWS(const char* pwsfname)
{
	std::cerr << "Processing " << pwsfname << std::endl;
	HMODULE hLib = LoadLibraryA("pwsdll.dll");
	if (hLib == NULL) {
		std::cerr << "Unable to load pwsdll.dll.  Error: " << GetLastError() << std::endl;
		return;
	}
	PWSOPENFILE pOpenFunc = NULL;
	PWSCLOSEFILE pCloseFunc = NULL;
	PWSGETNEXT pGetNextFunc = NULL;

	pOpenFunc = (PWSOPENFILE)GetProcAddress(hLib, "PWSOpenFile");
	pCloseFunc = (PWSCLOSEFILE)GetProcAddress(hLib, "PWSCloseFile");
	pGetNextFunc = (PWSGETNEXT)GetProcAddress(hLib, "PWSGetNextItem");
	if (pOpenFunc == NULL) {
		std::cerr << "Unable to find PWSOpenFile()" << std::endl;
		return;
	}
	if (pCloseFunc == NULL) {
		std::cerr << "Unable to find PWSCloseFile()" << std::endl;
		return;
	}
	if (pGetNextFunc == NULL) {
		std::cerr << "Unable to find PWSGetNextItem()" << std::endl;
		return;
	}
	std::cerr << "Loaded pwsdll.dll successfully" << std::endl;
	_pws_struct x;
	std::cerr << "Attempting to open " << pwsfname << std::endl;
	int ret = pOpenFunc(&x, pwsfname, true);
	if (x.PWSopened == -1) {
		std::cout << x.PWSMessage << std::endl;
	}
	else {
		std::cerr << "Opened pws file" << std::endl;
		std::cout << "{";
		while (x.PWSopened != -1) {
			switch (x.PWSid) {
				case SCENARIO:
					loadScenario(*x.PWSaddress.sceninfo);
					break;
				case HEADER:
					loadHeader(*x.PWSaddress.header);
					break;
				case AIRGROUP:
					loadAirGroups(*x.PWSaddress.airgroups);
					break;
				case TASKFORCE:
					loadTaskGroups(*x.PWSaddress.taskgroups);
					break;
				case MINES:
					loadMinefields(*x.PWSaddress.minefields);
					break;
				case LEADER:
					loadLeaders(*x.PWSaddress.leaders);
					break;
				case SHIP:
					loadShips(*x.PWSaddress.ships);
					break;
				case SHIPCLASS:
					loadShipClasses(*x.PWSaddress.shipclasses);
					break;
				case PILOT:
					loadPilots(*x.PWSaddress.pilots);
					break;
				case AIRCRAFT:
					loadAircraft(*x.PWSaddress.aircrafts);
					break;
				case DEVICE:
					loadDevices(*x.PWSaddress.devices);
					break;
				case LOCATION:
					loadLocations(*x.PWSaddress.locations);
					break;
				case PLAYERPREF:
				default:
					break;
			}
			pGetNextFunc(&x);
		}
		std::cout << "\"Done\": 1}";
		pCloseFunc(&x);
	}

	FreeLibrary(hLib);
}

int main(int argc, char ** argv)
{
	if (argc != 2) {
		usage(argv[0]);
		exit(-1);
	}
	const char * pwsfile = argv[1];
	dumpPWS(pwsfile);
	return 0;
}

