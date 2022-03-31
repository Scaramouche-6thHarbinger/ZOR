#ifndef __CONSTANT_H__
#define __CONSTANT_H__

const int INVALID_VALUE	= -1;
const int MAX_SOCIALID_LEN	= 20;
const int MAX_CLASS_TYPE	= 5;
const int MAX_SKILL		= 20;
const int FAIRY_TID_START	= 15;
const int UPSTONE_TID		= 13;

// for PVP
const int PVP_P1_START_X			= 366;
const int PVP_P1_START_Y			= 322;
const int PVP_P2_START_X			= 1074;
const int PVP_P2_START_Y			= 554;
const int PVP_MAP_ID				= 120;
const int PVP_BUFF_MAX_SCORE		= 20;
const int PVP_BUFF_START_TID		= 178;
const int PVP_BUFF_END_TID			= 185;

// for dungeon
//const int DUNGEON_INVITE_USER		= 3;

// for PK
const int MAX_PK_INVITE				= 3;
const int MIN_PK_INVITE				= 2;
const int MAX_PK_TIME				= 30;

// for battle common
#define CHECK_LATENCY
const int MAX_BATTLE_LATENCY		= 1000;		// ms

//const int ConstPosX = 1764;
//const int ConstPosY = 502;

const int radius = 50;
const int ConstPosX = 1804;
const int ConstPosY = 508;
const int ConstDegree = 90;

const int MAX_RANDOM_STAT = 3;

#define STAT_SET_MAX	10
#define STAT_MIN		6
#define STAT_MAX		13
#define STAT_SUM_MAX	40

const int MAX_DUNGEON_COUNT = 150;

const int MAX_PARTY_DUNGEON_INVITE = 2;

const int MAX_SPACE_POOL = 1024;

const int MAX_NEW_PARTY_ROOM = 999;
const int MAX_WORLDBOSS_PARTY_ROOM = 999;

const int MAX_NEW_PK_ROOM = 999;
const int MAX_NEW_PVP_ROOM		= 999;

const int STAMINA_MAX = 5;

const unsigned int MAX_GOLD = 2000000000;

const int MAX_OPEN_ITEM_QUALITY = 7;
const int MAX_OPEN_FAIRY_QUALITY = 6;

#endif // __CONSTANT_H__