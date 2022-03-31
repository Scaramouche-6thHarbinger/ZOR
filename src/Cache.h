#ifndef __Cache_H__
#define __Cache_H__
#include <string>
#include <list>
#include <vector>
#include <map>
#include <cstring>
#include <stdint.h>

//#include "other_idl.h"

struct slot {
	bool	open;
	uint32_t	character_seq;
	bool	makeCharacter;
	uint32_t	remainStatResetCount;
	uint32_t	classtype;
	uint32_t	level;
	std::string	reg_date;
	slot()	{
		open = false;
		character_seq = 0;
		makeCharacter = false;
		remainStatResetCount = 0;
		classtype = 0;
		level = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(bool);
		nSize += sizeof(uint32_t);
		nSize += sizeof(bool);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(int32_t); nSize += reg_date.length();
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(bool*)(*_buf_)) = open; (*_buf_) += sizeof(bool);
		(*(uint32_t*)(*_buf_)) = character_seq; (*_buf_) += sizeof(uint32_t);
		(*(bool*)(*_buf_)) = makeCharacter; (*_buf_) += sizeof(bool);
		(*(uint32_t*)(*_buf_)) = remainStatResetCount; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = classtype; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = level; (*_buf_) += sizeof(uint32_t);
		(*(int32_t*)(*_buf_)) = (int32_t)reg_date.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, reg_date.c_str(), reg_date.length());
		(*_buf_) += reg_date.length();
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(bool) > nSize) { return false; }	std::memcpy(&open, *_buf_, sizeof(bool));	(*_buf_) += sizeof(bool); nSize -= sizeof(bool);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&character_seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(bool) > nSize) { return false; }	std::memcpy(&makeCharacter, *_buf_, sizeof(bool));	(*_buf_) += sizeof(bool); nSize -= sizeof(bool);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&remainStatResetCount, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&classtype, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&level, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(int32_t) > nSize) { return false; }
		int32_t reg_date_length = 0; std::memcpy(&reg_date_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		reg_date.assign((char*)*_buf_, reg_date_length); (*_buf_) += reg_date_length; nSize -= reg_date_length;
		return true;
	}
}; //slot
struct slot_Serializer {
	static bool Store(char** _buf_, const slot& obj) { return obj.Store(_buf_); }
	static bool Load(slot& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const slot& obj) { return obj.Size(); }
};
struct UserInfo {
	uint32_t	userseq;
	slot	array_Slot[8];
	uint32_t	zen;
	int32_t	main_slot_index;
	std::string	nickname;
	std::string	profile_url;
	uint32_t	score;
	uint32_t	heart_blocked;
	uint32_t	invite_blocked;
	uint32_t	profile_opened;
	uint32_t	company;
	uint32_t	sale_code;
	uint32_t	u8intro_state;
	uint32_t	wp_last_week;
	uint32_t	wp_cur_week;
	uint64_t	wp_reg_date;
	uint32_t	array_tutorial[4];
	std::string	uuid;
	uint32_t	battle_aftereffect_time;
	std::string	reward;
	uint32_t	shard_Item_db_type;
	uint64_t	wp_last_reg_date;

	uint64_t	reserve1;
	uint64_t	reserve2;
	uint64_t	reserve3;
	uint64_t	reserve4;
	uint64_t	reserve5;

	uint64_t	worldboss_hit;
	uint64_t	worldboss_point;
	UserInfo()	{
		userseq = 0;
		zen = 0;
		main_slot_index = 0;
		score = 0;
		heart_blocked = 0;
		invite_blocked = 0;
		profile_opened = 0;
		company = 0;
		sale_code = 0;
		u8intro_state = 0;
		wp_last_week = 0;
		wp_cur_week = 0;
		wp_reg_date = 0;
		battle_aftereffect_time = 0;
		shard_Item_db_type = 0;
		wp_last_reg_date = 0;
		reserve1 = 0;
		reserve2 = 0;
		reserve3 = 0;
		reserve4 = 0;
		reserve5 = 0;
		worldboss_hit = 0;
		worldboss_point = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		for(int32_t i=0; i<8; i++) {
			nSize += slot_Serializer::Size(array_Slot[i]);
		}
		nSize += sizeof(uint32_t);
		nSize += sizeof(int32_t);
		nSize += sizeof(int32_t); nSize += nickname.length();
		nSize += sizeof(int32_t); nSize += profile_url.length();
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t); // wp_last_week
		nSize += sizeof(uint32_t); // wp_cur_week
		nSize += sizeof(uint64_t); // wp_reg_date
		nSize += sizeof(uint32_t) * 4; // array_tutorial
		nSize += sizeof(int32_t); nSize += uuid.length(); // uuid
		nSize += sizeof(uint32_t); // battle_aftereffect_time
		nSize += sizeof(int32_t); nSize += reward.length(); // reward
		nSize += sizeof(uint32_t); // shard_Item_db_type
		nSize += sizeof(uint64_t); // wp_last_reg_date
		nSize += sizeof(uint64_t); // reserve1
		nSize += sizeof(uint64_t); // reserve2
		nSize += sizeof(uint64_t); // reserve3
		nSize += sizeof(uint64_t); // reserve4
		nSize += sizeof(uint64_t); // reserve5
		nSize += sizeof(uint64_t); // worldboss_hit
		nSize += sizeof(uint64_t); // worldboss_point
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = userseq; (*_buf_) += sizeof(uint32_t);
		for(int32_t i=0; i<8; i++) {
			if(false == slot_Serializer::Store(_buf_, array_Slot[i])) { return false; }
		}
		(*(uint32_t*)(*_buf_)) = zen; (*_buf_) += sizeof(uint32_t);
		(*(int32_t*)(*_buf_)) = main_slot_index; (*_buf_) += sizeof(int32_t);
		(*(int32_t*)(*_buf_)) = (int32_t)nickname.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, nickname.c_str(), nickname.length());
		(*_buf_) += nickname.length();
		(*(int32_t*)(*_buf_)) = (int32_t)profile_url.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, profile_url.c_str(), profile_url.length());
		(*_buf_) += profile_url.length();
		(*(uint32_t*)(*_buf_)) = score; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = heart_blocked; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = invite_blocked; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = profile_opened; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = company; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = sale_code; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = u8intro_state; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = wp_last_week; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = wp_cur_week; (*_buf_) += sizeof(uint32_t);
		(*(uint64_t*)(*_buf_)) = wp_reg_date; (*_buf_) += sizeof(uint64_t);
		std::memcpy(*_buf_, array_tutorial, sizeof(uint32_t) * 4); (*_buf_) += sizeof(uint32_t) * 4;
		(*(int32_t*)(*_buf_)) = (int32_t)uuid.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, uuid.c_str(), uuid.length());
		(*_buf_) += uuid.length();
		(*(uint32_t*)(*_buf_)) = battle_aftereffect_time; (*_buf_) += sizeof(uint32_t);
		(*(int32_t*)(*_buf_)) = (int32_t)reward.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, reward.c_str(), reward.length());
		(*_buf_) += reward.length();
		(*(uint32_t*)(*_buf_)) = shard_Item_db_type; (*_buf_) += sizeof(uint32_t);
		(*(uint64_t*)(*_buf_)) = wp_last_reg_date; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = reserve1; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = reserve2; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = reserve3; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = reserve4; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = reserve5; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = worldboss_hit; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = worldboss_point; (*_buf_) += sizeof(uint64_t);
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&userseq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		for(int32_t i=0; i<8; i++) {
			slot array_Slot_val;
			if(false == slot_Serializer::Load(array_Slot_val, _buf_, nSize)) { return false; }
			array_Slot[i] = array_Slot_val;
		}
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&zen, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(int32_t) > nSize) { return false; }	std::memcpy(&main_slot_index, *_buf_, sizeof(int32_t));	(*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		if(sizeof(int32_t) > nSize) { return false; }
		int32_t nickname_length = 0; std::memcpy(&nickname_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		nickname.assign((char*)*_buf_, nickname_length); (*_buf_) += nickname_length; nSize -= nickname_length;
		if(sizeof(int32_t) > nSize) { return false; }
		int32_t profile_url_length = 0; std::memcpy(&profile_url_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		profile_url.assign((char*)*_buf_, profile_url_length); (*_buf_) += profile_url_length; nSize -= profile_url_length;
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&score, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&heart_blocked, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&invite_blocked, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&profile_opened, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&company, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&sale_code, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&u8intro_state, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// wp_last_week
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&wp_last_week, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// wp_cur_week
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&wp_cur_week, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// wp_reg_date
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&wp_reg_date, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// array_tutorial
		std::memcpy(array_tutorial, *_buf_, sizeof(uint32_t) * 4); (*_buf_) += sizeof(uint32_t) * 4; nSize -= sizeof(uint32_t) * 4;
		// uuid
		int32_t uuid_length = 0; std::memcpy(&uuid_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		uuid.assign((char*)*_buf_, uuid_length); (*_buf_) += uuid_length; nSize -= uuid_length;
		// battle_aftereffect_time
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&battle_aftereffect_time, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// reward_length
		int32_t reward_length = 0; std::memcpy(&reward_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		reward.assign((char*)*_buf_, reward_length); (*_buf_) += reward_length; nSize -= reward_length;
		// shard_Item_db_type
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&shard_Item_db_type, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// wp_last_reg_date
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&wp_last_reg_date, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// reserve1
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&reserve1, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// reserve2
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&reserve2, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// reserve3
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&reserve3, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// reserve4
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&reserve4, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// reserve5
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&reserve5, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// worldboss_hit
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&worldboss_hit, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// worldboss_point
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&worldboss_point, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		return true;
	}
}; //UserInfo
struct UserInfo_Serializer {
	static bool Store(char** _buf_, const UserInfo& obj) { return obj.Store(_buf_); }
	static bool Load(UserInfo& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const UserInfo& obj) { return obj.Size(); }
};
struct QuickSlot {
	uint32_t	type;
	uint64_t	index;
	QuickSlot()	{
		type = 0;
		index = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint64_t);
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = type; (*_buf_) += sizeof(uint32_t);
		(*(uint64_t*)(*_buf_)) = index; (*_buf_) += sizeof(uint64_t);
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&type, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&index, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		return true;
	}
}; //QuickSlot
struct QuickSlot_Serializer {
	static bool Store(char** _buf_, const QuickSlot& obj) { return obj.Store(_buf_); }
	static bool Load(QuickSlot& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const QuickSlot& obj) { return obj.Size(); }
};
struct CharacterInfo {
	uint32_t	characterseq;
	uint32_t	userSeq;
	uint32_t	classtype;
	uint32_t	slotindex;
	uint32_t	remain_stat_point;
	uint32_t	remain_skill_point;
	uint32_t	ap_current;
	uint32_t	ep_current;
	uint32_t	ep_max;

	uint64_t	weapon;
	uint32_t	weapon_iconidx;
	uint64_t	helmet;
	uint32_t	helmet_iconidx;
	uint64_t	armor;
	uint32_t	armor_iconidx;
	uint64_t	glove;
	uint64_t	shoes;
	uint64_t	necklace;
	uint64_t	cloak;
	uint64_t	ring;
	uint64_t	charm;
	uint64_t	avartar;

	uint32_t	avartar_iconidx;

	uint64_t	vehicle;

	uint32_t	vehicle_iconidx;

	uint64_t	title;
	uint64_t	fairy;
	uint64_t	battlepet;

	uint32_t	exp;
	uint32_t	level;
	uint32_t	str;
	uint32_t	dex;
	uint32_t	con;
	uint32_t	spi;

	QuickSlot	array_QuickSlot[8];
	uint32_t	array_Skill[20];
	uint32_t	gold;

	int32_t		event_stamina;
	uint64_t	recover_stamina_sec;

	uint32_t	drill_status;
	uint32_t	drill_time;
	uint64_t	drill_start;
	uint64_t	drill_end;

	uint32_t	consecutive_win;
	std::string	win_comment;

	uint64_t	reg_date;

	std::string	dungeon_clear_info;

	std::string					bag_order_info;

	std::string					buff_info;
	std::string					battle_afterEffect_info;
	uint32_t		daily_ep;

	uint64_t 	name_tag;
	uint32_t		name_tag_iconidx;

	uint64_t		reserve1;
	uint64_t		reserve2;
	uint64_t		reserve3;
	uint64_t		reserve4;
	uint64_t		reserve5;
	CharacterInfo()	{
		characterseq = 0;
		userSeq = 0;
		classtype = 0;
		slotindex = 0;
		remain_stat_point = 0;
		remain_skill_point = 0;
		ap_current = 0;
		ep_current = 0;
		ep_max = 0;
		weapon = 0;
		weapon_iconidx = 0;
		helmet = 0;
		helmet_iconidx = 0;
		armor = 0;
		armor_iconidx = 0;
		glove = 0;
		shoes = 0;
		necklace = 0;
		cloak = 0;
		ring = 0;
		charm = 0;
		avartar = 0;
		avartar_iconidx = 0; // NEW
		vehicle = 0;
		vehicle_iconidx = 0; // NEW
		title = 0;
		fairy = 0;
		battlepet = 0;
		exp = 0;
		level = 0;
		str = 0;
		dex = 0;
		con = 0;
		spi = 0;
		gold = 0;
		event_stamina = 0;
		recover_stamina_sec = 0;
		drill_status = 0;
		drill_time = 0;
		drill_start = 0;
		drill_end = 0;
		consecutive_win = 0;
		reg_date = 0;
		daily_ep = 0;
		name_tag = 0;
		name_tag_iconidx = 0;
		reserve1 = 0;
		reserve2 = 0;
		reserve3 = 0;
		reserve4 = 0;
		reserve5 = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint64_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint64_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint64_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint64_t);
		nSize += sizeof(uint64_t);
		nSize += sizeof(uint64_t);
		nSize += sizeof(uint64_t);
		nSize += sizeof(uint64_t);
		nSize += sizeof(uint64_t);
		nSize += sizeof(uint64_t);
		nSize += sizeof(uint32_t); // avartar_iconidx
		nSize += sizeof(uint64_t);
		nSize += sizeof(uint32_t); // vehicle_iconidx
		nSize += sizeof(uint64_t);
		nSize += sizeof(uint64_t);
		nSize += sizeof(uint64_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		for(int32_t i=0; i<8; i++) {
			nSize += QuickSlot_Serializer::Size(array_QuickSlot[i]);
		}
		nSize += sizeof(uint32_t) * 20;// array_Skill
		nSize += sizeof(uint32_t); // gold
		nSize += sizeof(int32_t); // event_stamina
		nSize += sizeof(uint64_t); // recover_stamina_sec
		nSize += sizeof(uint32_t) * 4; // drill_status, drill_time, drill_start, drill_end
		nSize += sizeof(uint32_t); // consecutive_win
		nSize += sizeof(int32_t); nSize += win_comment.length(); // win_comment
		nSize += sizeof(uint64_t); // reg_date
		nSize += sizeof(int32_t); nSize += dungeon_clear_info.length(); // dungeon_clear_info
		nSize += sizeof(int32_t); nSize += bag_order_info.length(); // bag_order_info
		nSize += sizeof(int32_t); nSize += buff_info.length(); // buff_info
		nSize += sizeof(int32_t); nSize += battle_afterEffect_info.length(); // battle_afterEffect_info
		nSize += sizeof(uint32_t); // daily_ep
		nSize += sizeof(uint64_t); // name_tag
		nSize += sizeof(uint32_t); // name_tag_iconidx
		nSize += sizeof(uint64_t); // reserve1
		nSize += sizeof(uint64_t); // reserve2
		nSize += sizeof(uint64_t); // reserve3
		nSize += sizeof(uint64_t); // reserve4
		nSize += sizeof(uint64_t); // reserve5
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = characterseq; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = userSeq; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = classtype; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = slotindex; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = remain_stat_point; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = remain_skill_point; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = ap_current; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = ep_current; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = ep_max; (*_buf_) += sizeof(uint32_t);
		(*(uint64_t*)(*_buf_)) = weapon; (*_buf_) += sizeof(uint64_t);
		(*(uint32_t*)(*_buf_)) = weapon_iconidx; (*_buf_) += sizeof(uint32_t);
		(*(uint64_t*)(*_buf_)) = helmet; (*_buf_) += sizeof(uint64_t);
		(*(uint32_t*)(*_buf_)) = helmet_iconidx; (*_buf_) += sizeof(uint32_t);
		(*(uint64_t*)(*_buf_)) = armor; (*_buf_) += sizeof(uint64_t);
		(*(uint32_t*)(*_buf_)) = armor_iconidx; (*_buf_) += sizeof(uint32_t);
		(*(uint64_t*)(*_buf_)) = glove; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = shoes; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = necklace; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = cloak; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = ring; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = charm; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = avartar; (*_buf_) += sizeof(uint64_t);
		(*(uint32_t*)(*_buf_)) = avartar_iconidx; (*_buf_) += sizeof(uint32_t);
		(*(uint64_t*)(*_buf_)) = vehicle; (*_buf_) += sizeof(uint64_t);
		(*(uint32_t*)(*_buf_)) = vehicle_iconidx; (*_buf_) += sizeof(uint32_t);
		(*(uint64_t*)(*_buf_)) = title; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = fairy; (*_buf_) += sizeof(uint64_t);
		(*(uint64_t*)(*_buf_)) = battlepet; (*_buf_) += sizeof(uint64_t);
		(*(uint32_t*)(*_buf_)) = exp; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = level; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = str; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = dex; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = con; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = spi; (*_buf_) += sizeof(uint32_t);
		for(int32_t i=0; i<8; i++) {
			if(false == QuickSlot_Serializer::Store(_buf_, array_QuickSlot[i])) { return false; }
		}
		std::memcpy(*_buf_, array_Skill, sizeof(uint32_t) * 20); (*_buf_) += sizeof(uint32_t) * 20; // array_Skill
		(*(uint32_t*)(*_buf_)) = gold; (*_buf_) += sizeof(uint32_t); // gold
		(*(int32_t*)(*_buf_)) = event_stamina; (*_buf_) += sizeof(int32_t); // event_stamina
		(*(uint64_t*)(*_buf_)) = recover_stamina_sec; (*_buf_) += sizeof(uint64_t); // recover_stamina_sec
		(*(uint32_t*)(*_buf_)) = drill_status; (*_buf_) += sizeof(uint32_t); // drill_status
		(*(uint32_t*)(*_buf_)) = drill_time; (*_buf_) += sizeof(uint32_t); // drill_time
		(*(uint64_t*)(*_buf_)) = drill_start; (*_buf_) += sizeof(uint64_t); // drill_start
		(*(uint64_t*)(*_buf_)) = drill_end; (*_buf_) += sizeof(uint64_t); // drill_end
		// consecutive_win
		(*(uint32_t*)(*_buf_)) = consecutive_win; (*_buf_) += sizeof(uint32_t);
		// string win_comment
		(*(int32_t*)(*_buf_)) = (int32_t)win_comment.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, win_comment.c_str(), win_comment.length());
		(*_buf_) += win_comment.length();
		(*(uint64_t*)(*_buf_)) = reg_date; (*_buf_) += sizeof(uint64_t);
		// dungeon_clear_info
		(*(int32_t*)(*_buf_)) = (int32_t)dungeon_clear_info.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, dungeon_clear_info.c_str(), dungeon_clear_info.length());
		(*_buf_) += dungeon_clear_info.length();
		// bag_order_info
		(*(int32_t*)(*_buf_)) = (int32_t)bag_order_info.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, bag_order_info.c_str(), bag_order_info.length());
		(*_buf_) += bag_order_info.length();
		// buff_info
		(*(int32_t*)(*_buf_)) = (int32_t)buff_info.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, buff_info.c_str(), buff_info.length());
		(*_buf_) += buff_info.length();
		// battle_afterEffect_info
		(*(int32_t*)(*_buf_)) = (int32_t)battle_afterEffect_info.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, battle_afterEffect_info.c_str(), battle_afterEffect_info.length());
		(*_buf_) += battle_afterEffect_info.length();
		// daily_ep
		(*(uint32_t*)(*_buf_)) = daily_ep; (*_buf_) += sizeof(uint32_t);
		// name_tag
		(*(uint64_t*)(*_buf_)) = name_tag; (*_buf_) += sizeof(uint64_t);
		// name_tag_iconidx
		(*(uint32_t*)(*_buf_)) = name_tag_iconidx; (*_buf_) += sizeof(uint32_t);

		// reserve1
		(*(uint64_t*)(*_buf_)) = reserve1; (*_buf_) += sizeof(uint64_t);
		// reserve2
		(*(uint64_t*)(*_buf_)) = reserve2; (*_buf_) += sizeof(uint64_t);
		// reserve3
		(*(uint64_t*)(*_buf_)) = reserve3; (*_buf_) += sizeof(uint64_t);
		// reserve4
		(*(uint64_t*)(*_buf_)) = reserve4; (*_buf_) += sizeof(uint64_t);
		// reserve5
		(*(uint64_t*)(*_buf_)) = reserve5; (*_buf_) += sizeof(uint64_t);
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&characterseq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&userSeq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&classtype, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&slotindex, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&remain_stat_point, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&remain_skill_point, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&ap_current, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&ep_current, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&ep_max, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&weapon, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&weapon_iconidx, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&helmet, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&helmet_iconidx, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&armor, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&armor_iconidx, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&glove, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&shoes, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&necklace, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&cloak, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&ring, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&charm, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&avartar, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&avartar_iconidx, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&vehicle, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&vehicle_iconidx, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&title, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&fairy, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&battlepet, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&exp, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&level, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&str, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&dex, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&con, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&spi, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		for(int32_t i=0; i<8; i++) {
			QuickSlot array_QuickSlot_val;
			if(false == QuickSlot_Serializer::Load(array_QuickSlot_val, _buf_, nSize)) { return false; }
			array_QuickSlot[i] = array_QuickSlot_val;
		}
		std::memcpy(array_Skill, *_buf_, sizeof(uint32_t) * 20); (*_buf_) += sizeof(uint32_t) * 20; nSize -= sizeof(uint32_t) * 20;
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&gold, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(int32_t) > nSize) { return false; }	std::memcpy(&event_stamina, *_buf_, sizeof(int32_t));	(*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&recover_stamina_sec, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&drill_status, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&drill_time, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&drill_start, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&drill_end, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&consecutive_win, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// string win_comment
		int32_t win_comment_length = 0; std::memcpy(&win_comment_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		win_comment.assign((char*)*_buf_, win_comment_length); (*_buf_) += win_comment_length; nSize -= win_comment_length;
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&reg_date, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);

		// string dungeon_clear_info
		int32_t dungeon_clear_info_length = 0; std::memcpy(&dungeon_clear_info_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		dungeon_clear_info.assign((char*)*_buf_, dungeon_clear_info_length); (*_buf_) += dungeon_clear_info_length; nSize -= dungeon_clear_info_length;

		// string bag_order_info
		int32_t bag_order_info_length = 0; std::memcpy(&bag_order_info_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		bag_order_info.assign((char*)*_buf_, bag_order_info_length); (*_buf_) += bag_order_info_length; nSize -= bag_order_info_length;
		
		// string buff_info
		int32_t buff_info_length = 0; std::memcpy(&buff_info_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		buff_info.assign((char*)*_buf_, buff_info_length); (*_buf_) += buff_info_length; nSize -= buff_info_length;

		// string battle_afterEffect_info
		int32_t battle_afterEffect_info_length = 0; std::memcpy(&battle_afterEffect_info_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		battle_afterEffect_info.assign((char*)*_buf_, battle_afterEffect_info_length); (*_buf_) += battle_afterEffect_info_length; nSize -= battle_afterEffect_info_length;

		// daily_ep;
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&daily_ep, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// uint64_t name_tag
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&name_tag, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		// uint32_t name_tag_iconidx;
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&name_tag_iconidx, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		// uint64_t reserve1;
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&reserve1, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		// uint64_t reserve2;
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&reserve2, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		// uint64_t reserve3;
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&reserve3, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		// uint64_t reserve4;
		if(sizeof(uint64_t) > nSize) { return false; }	std::memcpy(&reserve4, *_buf_, sizeof(uint64_t));	(*_buf_) += sizeof(uint64_t); nSize -= sizeof(uint64_t);
		// uint64_t reserve5;
		return true;
	}
}; //CharacterInfo
struct CharacterInfo_Serializer {
	static bool Store(char** _buf_, const CharacterInfo& obj) { return obj.Store(_buf_); }
	static bool Load(CharacterInfo& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const CharacterInfo& obj) { return obj.Size(); }
};
enum CacheResult {
		CACHE_SUCCESS,
		CACHE_NOT_EXIST_USER,
		CACHE_NOT_EXIST_CHARACTER,
		CACHE_DATABASE_ERROR,
}; // CacheResult
struct CacheResult_Serializer {
	static bool Store(char** _buf_, const CacheResult& obj) { 
		(*(CacheResult*)(*_buf_)) = obj;	(*_buf_) += sizeof(CacheResult);
		return true;
	}
	static bool Load(CacheResult& obj, const char** _buf_, size_t& nSize) { 
		if(sizeof(CacheResult) > nSize) { return false; }		std::memcpy(&obj, *_buf_, sizeof(CacheResult));		(*_buf_) += sizeof(CacheResult); nSize -= sizeof(CacheResult);
		return true;
	}
	static int32_t Size(const CacheResult& obj) { return sizeof(CacheResult); }
};
struct CacheOpenAck {
	enum { MSG_ID = 1 }; 
	CacheOpenAck()	{
	}
	int32_t Size() const {
		int32_t nSize = 0;
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		return true;
	}
}; //CacheOpenAck
struct CacheOpenAck_Serializer {
	static bool Store(char** _buf_, const CacheOpenAck& obj) { return obj.Store(_buf_); }
	static bool Load(CacheOpenAck& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const CacheOpenAck& obj) { return obj.Size(); }
};
struct CacheCloseAck {
	enum { MSG_ID = 2 }; 
	CacheCloseAck()	{
	}
	int32_t Size() const {
		int32_t nSize = 0;
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		return true;
	}
}; //CacheCloseAck
struct CacheCloseAck_Serializer {
	static bool Store(char** _buf_, const CacheCloseAck& obj) { return obj.Store(_buf_); }
	static bool Load(CacheCloseAck& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const CacheCloseAck& obj) { return obj.Size(); }
};
struct UserInfoSyn {
	enum { MSG_ID = 7001 }; 
	uint32_t	seq;
	UserInfoSyn()	{
		seq = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = seq; (*_buf_) += sizeof(uint32_t);
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		return true;
	}
}; //UserInfoSyn
struct UserInfoSyn_Serializer {
	static bool Store(char** _buf_, const UserInfoSyn& obj) { return obj.Store(_buf_); }
	static bool Load(UserInfoSyn& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const UserInfoSyn& obj) { return obj.Size(); }
};
struct UserInfoAck {
	enum { MSG_ID = 7002 }; 
	uint32_t	seq;
	CacheResult	result;
	std::string	strError;
	UserInfo	stUserInfo;
	UserInfoAck()	{
		seq = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		nSize += CacheResult_Serializer::Size(result);
		nSize += sizeof(int32_t); nSize += strError.length();
		nSize += UserInfo_Serializer::Size(stUserInfo);
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = seq; (*_buf_) += sizeof(uint32_t);
		if(false == CacheResult_Serializer::Store(_buf_, result)) { return false; }
		(*(int32_t*)(*_buf_)) = (int32_t)strError.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, strError.c_str(), strError.length());
		(*_buf_) += strError.length();
		if(false == UserInfo_Serializer::Store(_buf_, stUserInfo)) { return false; }
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(false == CacheResult_Serializer::Load(result, _buf_, nSize)) { return false; }
		if(sizeof(int32_t) > nSize) { return false; }
		int32_t strError_length = 0; std::memcpy(&strError_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		strError.assign((char*)*_buf_, strError_length); (*_buf_) += strError_length; nSize -= strError_length;
		if(false == UserInfo_Serializer::Load(stUserInfo, _buf_, nSize)) { return false; }
		return true;
	}
}; //UserInfoAck
struct UserInfoAck_Serializer {
	static bool Store(char** _buf_, const UserInfoAck& obj) { return obj.Store(_buf_); }
	static bool Load(UserInfoAck& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const UserInfoAck& obj) { return obj.Size(); }
};
struct CharacterInfoSyn {
	enum { MSG_ID = 7003 }; 
	uint32_t	seq;
	uint32_t	char_seq;
	CharacterInfoSyn()	{
		seq = 0;
		char_seq = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = seq; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = char_seq; (*_buf_) += sizeof(uint32_t);
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&char_seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		return true;
	}
}; //CharacterInfoSyn
struct CharacterInfoSyn_Serializer {
	static bool Store(char** _buf_, const CharacterInfoSyn& obj) { return obj.Store(_buf_); }
	static bool Load(CharacterInfoSyn& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const CharacterInfoSyn& obj) { return obj.Size(); }
};
struct CharacterInfoAck {
	enum { MSG_ID = 7004 }; 
	uint32_t	seq;
	CacheResult	result;
	std::string	strError;
	CharacterInfo	stCharacterInfo;
	CharacterInfoAck()	{
		seq = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		nSize += CacheResult_Serializer::Size(result);
		nSize += sizeof(int32_t); nSize += strError.length();
		nSize += CharacterInfo_Serializer::Size(stCharacterInfo);
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = seq; (*_buf_) += sizeof(uint32_t);
		if(false == CacheResult_Serializer::Store(_buf_, result)) { return false; }
		(*(int32_t*)(*_buf_)) = (int32_t)strError.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, strError.c_str(), strError.length());
		(*_buf_) += strError.length();
		if(false == CharacterInfo_Serializer::Store(_buf_, stCharacterInfo)) { return false; }
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(false == CacheResult_Serializer::Load(result, _buf_, nSize)) { return false; }
		if(sizeof(int32_t) > nSize) { return false; }
		int32_t strError_length = 0; std::memcpy(&strError_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		strError.assign((char*)*_buf_, strError_length); (*_buf_) += strError_length; nSize -= strError_length;
		if(false == CharacterInfo_Serializer::Load(stCharacterInfo, _buf_, nSize)) { return false; }
		return true;
	}
}; //CharacterInfoAck
struct CharacterInfoAck_Serializer {
	static bool Store(char** _buf_, const CharacterInfoAck& obj) { return obj.Store(_buf_); }
	static bool Load(CharacterInfoAck& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const CharacterInfoAck& obj) { return obj.Size(); }
};
struct FlushCharacterInfoSyn {
	enum { MSG_ID = 7005 }; 
	uint32_t	seq;
	uint32_t	char_seq;
	bool	flushDB;
	CharacterInfo	stCharacterInfo;
	FlushCharacterInfoSyn()	{
		seq = 0;
		char_seq = 0;
		flushDB = false;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += sizeof(bool);
		nSize += CharacterInfo_Serializer::Size(stCharacterInfo);
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = seq; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = char_seq; (*_buf_) += sizeof(uint32_t);
		(*(bool*)(*_buf_)) = flushDB; (*_buf_) += sizeof(bool);
		if(false == CharacterInfo_Serializer::Store(_buf_, stCharacterInfo)) { return false; }
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&char_seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(bool) > nSize) { return false; }	std::memcpy(&flushDB, *_buf_, sizeof(bool));	(*_buf_) += sizeof(bool); nSize -= sizeof(bool);
		if(false == CharacterInfo_Serializer::Load(stCharacterInfo, _buf_, nSize)) { return false; }
		return true;
	}
}; //FlushCharacterInfoSyn
struct FlushCharacterInfoSyn_Serializer {
	static bool Store(char** _buf_, const FlushCharacterInfoSyn& obj) { return obj.Store(_buf_); }
	static bool Load(FlushCharacterInfoSyn& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const FlushCharacterInfoSyn& obj) { return obj.Size(); }
};
struct FlushCharacterInfoAck {
	enum { MSG_ID = 7006 }; 
	uint32_t	seq;
	CacheResult	result;
	std::string	strError;
	FlushCharacterInfoAck()	{
		seq = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		nSize += CacheResult_Serializer::Size(result);
		nSize += sizeof(int32_t); nSize += strError.length();
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = seq; (*_buf_) += sizeof(uint32_t);
		if(false == CacheResult_Serializer::Store(_buf_, result)) { return false; }
		(*(int32_t*)(*_buf_)) = (int32_t)strError.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, strError.c_str(), strError.length());
		(*_buf_) += strError.length();
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(false == CacheResult_Serializer::Load(result, _buf_, nSize)) { return false; }
		if(sizeof(int32_t) > nSize) { return false; }
		int32_t strError_length = 0; std::memcpy(&strError_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		strError.assign((char*)*_buf_, strError_length); (*_buf_) += strError_length; nSize -= strError_length;
		return true;
	}
}; //FlushCharacterInfoAck
struct FlushCharacterInfoAck_Serializer {
	static bool Store(char** _buf_, const FlushCharacterInfoAck& obj) { return obj.Store(_buf_); }
	static bool Load(FlushCharacterInfoAck& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const FlushCharacterInfoAck& obj) { return obj.Size(); }
};
struct FlushUserInfoSyn {
	enum { MSG_ID = 7007 }; 
	uint32_t	seq;
	bool	flushDB;
	UserInfo	stUserInfo;
	FlushUserInfoSyn()	{
		seq = 0;
		flushDB = false;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		nSize += sizeof(bool);
		nSize += UserInfo_Serializer::Size(stUserInfo);
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = seq; (*_buf_) += sizeof(uint32_t);
		(*(bool*)(*_buf_)) = flushDB; (*_buf_) += sizeof(bool);
		if(false == UserInfo_Serializer::Store(_buf_, stUserInfo)) { return false; }
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(bool) > nSize) { return false; }	std::memcpy(&flushDB, *_buf_, sizeof(bool));	(*_buf_) += sizeof(bool); nSize -= sizeof(bool);
		if(false == UserInfo_Serializer::Load(stUserInfo, _buf_, nSize)) { return false; }
		return true;
	}
}; //FlushUserInfoSyn
struct FlushUserInfoSyn_Serializer {
	static bool Store(char** _buf_, const FlushUserInfoSyn& obj) { return obj.Store(_buf_); }
	static bool Load(FlushUserInfoSyn& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const FlushUserInfoSyn& obj) { return obj.Size(); }
};
struct FlushUserInfoAck {
	enum { MSG_ID = 7008 }; 
	uint32_t	seq;
	CacheResult	result;
	std::string	strError;
	FlushUserInfoAck()	{
		seq = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		nSize += CacheResult_Serializer::Size(result);
		nSize += sizeof(int32_t); nSize += strError.length();
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = seq; (*_buf_) += sizeof(uint32_t);
		if(false == CacheResult_Serializer::Store(_buf_, result)) { return false; }
		(*(int32_t*)(*_buf_)) = (int32_t)strError.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, strError.c_str(), strError.length());
		(*_buf_) += strError.length();
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(false == CacheResult_Serializer::Load(result, _buf_, nSize)) { return false; }
		if(sizeof(int32_t) > nSize) { return false; }
		int32_t strError_length = 0; std::memcpy(&strError_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		strError.assign((char*)*_buf_, strError_length); (*_buf_) += strError_length; nSize -= strError_length;
		return true;
	}
}; //FlushUserInfoAck
struct FlushUserInfoAck_Serializer {
	static bool Store(char** _buf_, const FlushUserInfoAck& obj) { return obj.Store(_buf_); }
	static bool Load(FlushUserInfoAck& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const FlushUserInfoAck& obj) { return obj.Size(); }
};
struct FlushUserSlotInfoSyn {
	enum { MSG_ID = 7009 }; 
	uint32_t	seq;
	uint32_t	slotIndex;
	slot	stSlot;
	FlushUserSlotInfoSyn()	{
		seq = 0;
		slotIndex = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += slot_Serializer::Size(stSlot);
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = seq; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = slotIndex; (*_buf_) += sizeof(uint32_t);
		if(false == slot_Serializer::Store(_buf_, stSlot)) { return false; }
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&slotIndex, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(false == slot_Serializer::Load(stSlot, _buf_, nSize)) { return false; }
		return true;
	}
}; //FlushUserSlotInfoSyn
struct FlushUserSlotInfoSyn_Serializer {
	static bool Store(char** _buf_, const FlushUserSlotInfoSyn& obj) { return obj.Store(_buf_); }
	static bool Load(FlushUserSlotInfoSyn& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const FlushUserSlotInfoSyn& obj) { return obj.Size(); }
};
struct FlushUserSlotInfoAck {
	enum { MSG_ID = 7010 }; 
	uint32_t	seq;
	uint32_t	slotIndex;
	CacheResult	result;
	std::string	strError;
	FlushUserSlotInfoAck()	{
		seq = 0;
		slotIndex = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		nSize += CacheResult_Serializer::Size(result);
		nSize += sizeof(int32_t); nSize += strError.length();
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = seq; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = slotIndex; (*_buf_) += sizeof(uint32_t);
		if(false == CacheResult_Serializer::Store(_buf_, result)) { return false; }
		(*(int32_t*)(*_buf_)) = (int32_t)strError.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, strError.c_str(), strError.length());
		(*_buf_) += strError.length();
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&slotIndex, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(false == CacheResult_Serializer::Load(result, _buf_, nSize)) { return false; }
		if(sizeof(int32_t) > nSize) { return false; }
		int32_t strError_length = 0; std::memcpy(&strError_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		strError.assign((char*)*_buf_, strError_length); (*_buf_) += strError_length; nSize -= strError_length;
		return true;
	}
}; //FlushUserSlotInfoAck
struct FlushUserSlotInfoAck_Serializer {
	static bool Store(char** _buf_, const FlushUserSlotInfoAck& obj) { return obj.Store(_buf_); }
	static bool Load(FlushUserSlotInfoAck& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const FlushUserSlotInfoAck& obj) { return obj.Size(); }
};
struct RemoveUserSyn {
	enum { MSG_ID = 7011 }; 
	uint32_t	seq;
	RemoveUserSyn()	{
		seq = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = seq; (*_buf_) += sizeof(uint32_t);
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		return true;
	}
}; //RemoveUserSyn
struct RemoveUserSyn_Serializer {
	static bool Store(char** _buf_, const RemoveUserSyn& obj) { return obj.Store(_buf_); }
	static bool Load(RemoveUserSyn& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const RemoveUserSyn& obj) { return obj.Size(); }
};
struct RemoveUserAck {
	enum { MSG_ID = 7012 }; 
	uint32_t	seq;
	CacheResult	result;
	std::string	strError;
	RemoveUserAck()	{
		seq = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		nSize += CacheResult_Serializer::Size(result);
		nSize += sizeof(int32_t); nSize += strError.length();
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = seq; (*_buf_) += sizeof(uint32_t);
		if(false == CacheResult_Serializer::Store(_buf_, result)) { return false; }
		(*(int32_t*)(*_buf_)) = (int32_t)strError.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, strError.c_str(), strError.length());
		(*_buf_) += strError.length();
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(false == CacheResult_Serializer::Load(result, _buf_, nSize)) { return false; }
		if(sizeof(int32_t) > nSize) { return false; }
		int32_t strError_length = 0; std::memcpy(&strError_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		strError.assign((char*)*_buf_, strError_length); (*_buf_) += strError_length; nSize -= strError_length;
		return true;
	}
}; //RemoveUserAck
struct RemoveUserAck_Serializer {
	static bool Store(char** _buf_, const RemoveUserAck& obj) { return obj.Store(_buf_); }
	static bool Load(RemoveUserAck& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const RemoveUserAck& obj) { return obj.Size(); }
};
struct NewCharacterInfoSyn {
	enum { MSG_ID = 7013 }; 
	uint32_t	seq;
	uint32_t	char_seq;
	NewCharacterInfoSyn()	{
		seq = 0;
		char_seq = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		nSize += sizeof(uint32_t);
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = seq; (*_buf_) += sizeof(uint32_t);
		(*(uint32_t*)(*_buf_)) = char_seq; (*_buf_) += sizeof(uint32_t);
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&char_seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		return true;
	}
}; //NewCharacterInfoSyn
struct NewCharacterInfoSyn_Serializer {
	static bool Store(char** _buf_, const NewCharacterInfoSyn& obj) { return obj.Store(_buf_); }
	static bool Load(NewCharacterInfoSyn& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const NewCharacterInfoSyn& obj) { return obj.Size(); }
};
struct NewCharacterInfoAck {
	enum { MSG_ID = 7014 }; 
	uint32_t	seq;
	CacheResult	result;
	std::string	strError;
	CharacterInfo	stCharacterInfo;
	NewCharacterInfoAck()	{
		seq = 0;
	}
	int32_t Size() const {
		int32_t nSize = 0;
		nSize += sizeof(uint32_t);
		nSize += CacheResult_Serializer::Size(result);
		nSize += sizeof(int32_t); nSize += strError.length();
		nSize += CharacterInfo_Serializer::Size(stCharacterInfo);
		return nSize;
	}
	bool Store(std::vector<char>& _buf_) const {
		size_t nSize = Size();
 		if(0 == nSize) { return true; }
		if(nSize > _buf_.size()) { 
			_buf_.resize(nSize);
		}
		char* pBuf = &(_buf_[0]);
		if(false == Store(&pBuf)) return false;
		return true;
	}
	bool Store(char** _buf_) const {
		(*(uint32_t*)(*_buf_)) = seq; (*_buf_) += sizeof(uint32_t);
		if(false == CacheResult_Serializer::Store(_buf_, result)) { return false; }
		(*(int32_t*)(*_buf_)) = (int32_t)strError.length(); (*_buf_) += sizeof(int32_t);
		std::memcpy(*_buf_, strError.c_str(), strError.length());
		(*_buf_) += strError.length();
		if(false == CharacterInfo_Serializer::Store(_buf_, stCharacterInfo)) { return false; }
		return true;
	}
	bool Load(const std::vector<char>& _buf_) {
		size_t nSize = _buf_.size();
 		if(0 == nSize) { return true; }
		const char* pBuf = &(_buf_[0]);
		if(false == Load(&pBuf, nSize)) return false;
		return true;
	}
	bool Load(const char** _buf_, size_t& nSize) {
		if(sizeof(uint32_t) > nSize) { return false; }	std::memcpy(&seq, *_buf_, sizeof(uint32_t));	(*_buf_) += sizeof(uint32_t); nSize -= sizeof(uint32_t);
		if(false == CacheResult_Serializer::Load(result, _buf_, nSize)) { return false; }
		if(sizeof(int32_t) > nSize) { return false; }
		int32_t strError_length = 0; std::memcpy(&strError_length, *_buf_, sizeof(int32_t)); (*_buf_) += sizeof(int32_t); nSize -= sizeof(int32_t);
		strError.assign((char*)*_buf_, strError_length); (*_buf_) += strError_length; nSize -= strError_length;
		if(false == CharacterInfo_Serializer::Load(stCharacterInfo, _buf_, nSize)) { return false; }
		return true;
	}
}; //NewCharacterInfoAck
struct NewCharacterInfoAck_Serializer {
	static bool Store(char** _buf_, const NewCharacterInfoAck& obj) { return obj.Store(_buf_); }
	static bool Load(NewCharacterInfoAck& obj, const char** _buf_, size_t& nSize) { return obj.Load(_buf_, nSize); }
	static int32_t Size(const NewCharacterInfoAck& obj) { return obj.Size(); }
};
#endif // __Cache_H__