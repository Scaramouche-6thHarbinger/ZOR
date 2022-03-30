#ifndef __USER_H__
#define __USER_H__

#include <util.h>
#include <Session.h>
#include <Enum.h>
#include <Bag.h>

#include <map>
#include <algorithm>

#include <Cache.h>

class Session;

namespace NLogic {
class Bag;
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

    State *_state;
    Session * _session;

    bool				_bClose;
	bool				_bDelUser;
	bool				_bZENEvent;
	bool				_bBattleReconnect;
};

#endif // __USER_H__