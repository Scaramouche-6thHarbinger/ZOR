#ifndef __USER_H__
#define __USER_H__

#include <util.h>
#include <Session.h>
#include <Enum.h>

#include <Bag.h>
#include <Buff.h>
#include <Equip.h>
#include <Status.h>
#include <Card.h>

#include <map>
#include <algorithm>

#include <Cache.h>
#include <Constant.h>

class Session;

namespace NLogic {
class Bag;
class Equip;
class Buff;
class Status;
class Card;
}

class User {

public:
    enum class EnumState {
        __NONE__,

		PVP_QUICK_WAIT,
		PVP_FRIENDLY_WAIT,
		PVP_AMITY_WAIT,
		PVP_READY,
		PVP_BATTLE,
		PVP_BATTLE_END,

		FRIEND_PARTY_WAIT,
		RANDOM_PARTY_WAIT,

		SINGLE_DUNGEON,

		INVITE,
		ACCEPT_WAIT,
		READY_WAIT,
		DUNGEON_BATTLE,

		BATTLE_ROYAL_PARTY_WAIT,
		BATTLE_ROYAL_READY_WAIT,
		BATTLE_ROYAL_READY,
		BATTLE_ROYAL_BATTLE,
		BATTLE_ROYAL_END,

		RECONNECT_WAIT,

		RECALL,

		PHYSICAL_CHANGE,

		TUTORIAL,

		NEW_PVP_ROOM_WAIT,

		WORLDBOSS_SINGLE,
		WORLDBOSS_PARTY,

		ENTER_EVENT_DUNGEON,

		RECEIPT_CHECKING_CLOSE,

		__MAX__
    };

    enum class TimerID {
        __NONE__,
        NOTRESPONSE,
        DISCONNECT,
        __MAX__,
    };

public:
    class State {
    public:
        State() {}
        virtual ~State() {}

        typedef void(*Command)(User *user, Network::Packet *pPacket);

        Command GetCommanmd(unsigned short wCMD)
        {
            std::map<int, Command>::const_iterator citr;
            citr = clsCommandMap.find(wCMD);
            if (citr == clsCommandMap.end()) {
                return NULL;
            }
            return clsCommandMap[wCMD];
        }

        virtual std::string GetName() {
            return "";
        }

    protected:
        bool AddCommand(unsigned short wCMD, Command pCommand)
        {
            std::map<int, Command>::const_iterator citr;
            citr = clsCommandMap.find(wCMD);
            if (citr != clsCommandMap.end()) {
                LOGE("AddCommand: wCMD(%d) already exist", wCMD);
                return false;
            }
            clsCommandMap[wCMD] = pCommand;
            return true;
        }

    protected:
        std::map<int, Command> clsCommandMap;
    };

public:
    User();
    virtual ~User();

    virtual void Initialize();
    virtual void Finalize();

    void	Send(::Network::Packet *pPacket, bool printhex=false);
	void	SendOneshotEncrypt(::Network::Packet *pPacket, bool printhex=false);

    void	SetCoordinate(int x, int y, int degree=0);
	void	Set_PK_Coordinate(int x, int y, int degree=0);
	void	Set_PVP_Coordinate(int x, int y, int degree=0);

    void SetSession(Session *session);

public:
    typedef std::vector<NLogic::Bag *> BAGVECTOR;
    typedef std::vector<int>           VECTORINFO;

private:
    std::string _socialID;
    std::string _userNickName;
    std::string _uuid;

    uint32_t _company;
    uint32_t _sale_code;

    UserInfo 		_userInfo;
	CharacterInfo _characterInfo[8];

	std::vector<time_t>	_dailyEPTime;
	int				_userSeq;
	int				_encrypt_key;
	bool			_userInfoCache;
	bool			_characterInfoCache;
	bool			_locationRegist;
	bool			_bagInfoCache;
	int 			_openCharacterCount;
	int 			_loadCharacterCount;

    BAGVECTOR _clsBagVector;

    NLogic::Equip *		_equip;
	NLogic::Buff *		_buff;
	NLogic::Status *		_status;
	NLogic::Card *		_card;
	/**
	NLogic::SocialInfo * _socialInfo;
	NLogic::MailBox *	_mailBox;
	NLogic::BattleAfterEffect * _battleAfterEffect;
	NLogic::VirtualCurrency *	_virtualCurrency;
	NLogic::Score *		_score;
	NLogic::Reward *		_reward;
	NLogic::BattleResult * _battleResult;
	NLogic::UserLocation * _userLocation;
	NLogic::Trade *		_trade;
	NLogic::MemcachedKey * _memKey;
	NLogic::BackEndServerInfo * _backEndServerInfo;
	NLogic::QuestInfo *	_questInfo;
	NLogic::Fishing * _fishing;
	NLogic::Stamina * _stamina;
	**/

    State *_state;
    Session * _session;

    bool				_bClose;
	bool				_bDelUser;
	bool				_bZENEvent;
	bool				_bBattleReconnect;
    //NLogic::Space *	_space;
	//NLogic::Space *	_world;
	//NLogic::Space *	_reserveSpace;
	int 				_worldIndex;
	//NLogic::Battle *	_battle;

	EnumState			_enumStateType;
	//NLogic::Party *	_party;
	bool				_partyAccept;

	std::vector<int>	_array_dungeon_clear_info;
	std::vector<int>	_array_bag_order_info;
	bool				_battle_aftereffect;

	unsigned long		_latency;

	unsigned int		_refCount;
	time_t				_characterInfoSetTime;
	time_t				_loginTime;

public:
	void 				SetSocialID(const char * socialID) { _socialID = socialID; }
	std::string &		GetSocialID() { return _socialID; }

	void 				SetUserNickName(const char * nickName) { _userNickName = nickName; }
	std::string &		GetUserNickName() { return _userNickName; }

	void 				Setuuid(const char * uuid) { _uuid = uuid; }
	std::string &		Getuuid() { return _uuid; }

	void				SetCompany(uint32_t company) { _company = company; }
	uint32_t			GetCompany() { return _company; }

	void				SetSaleCode(uint32_t sale_code) { _sale_code = sale_code; }
	uint32_t			GetSaleCode() { return _sale_code; }

	void 				SetUserInfo(UserInfo & userInfo);
	UserInfo &			GetUserInfo() { return _userInfo; }

	void				SetState(State * state);
	State *				GetState() { return _state; }
};

#endif // __USER_H__