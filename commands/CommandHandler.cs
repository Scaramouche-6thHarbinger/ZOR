/**
namespace ProjectZ {
    public class CommandHandler {
        public NetworkPacket API_ZNO_CS_MY_WALLET(User user, NetworkPacket packet) {
            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_MY_WALLET);
            response.U2((ushort)NetACKTypes.ACK_OK);
            response.U4(100000); // current gold
            response.U4(100000); // current zen
            return response;
        }
        public NetworkPacket API_ZNO_CS_REQ_OPEN_SLOT(User user, NetworkPacket packet) {
            uint cur_slot = packet.U1();
            Console.WriteLine("+-------------------------------------------------------------------");
	        Console.WriteLine("| TODO!: API_ZNO_CS_REQ_OPEN_SLOT");
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| CurSlot: " + cur_slot);
            Console.WriteLine("+-------------------------------------------------------------------");
            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_REQ_OPEN_SLOT);
            // check if the slot is available in inventory...
            // if not available, return error -> ACK_SLOT_NOT_AVAILABLE
            // for now we just return ACK_OK
            response.U2((ushort)NetACKTypes.ACK_OK);
            response.U1((sbyte)cur_slot); // is the slot free?
            return response;
        }
        public NetworkPacket API_ZNO_CS_GET_NEW_MAIL_COUNT(User user, NetworkPacket packet) {
            Console.WriteLine("+-------------------------------------------------------------------");
	        Console.WriteLine("| TODO!: API_ZNO_CS_GET_NEW_MAIL_COUNT");
            Console.WriteLine("+-------------------------------------------------------------------");
            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_GET_NEW_MAIL_COUNT);
            response.U2((ushort)NetACKTypes.ACK_OK);
            response.U1(0); // len of unread mail
            return response;
        }
        public NetworkPacket API_ZNO_CS_SOCIAL_NEWS_COUNT(User user, NetworkPacket packet) {
            Console.WriteLine("+-------------------------------------------------------------------");
	        Console.WriteLine("| TODO!: API_ZNO_CS_SOCIAL_NEWS_COUNT");
            Console.WriteLine("+-------------------------------------------------------------------");
            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_SOCIAL_NEWS_COUNT);
            response.U2((ushort)NetACKTypes.ACK_OK);
            response.U2(0); // len of unread news
            return response;
        }

        public NetworkPacket API_ZNO_CS_REQ_SLOT_LIST(User user, NetworkPacket packet) {
            Console.WriteLine("+-------------------------------------------------------------------");
	        Console.WriteLine("| TODO!: API_ZNO_CS_REQ_SLOT_LIST");
            Console.WriteLine("+-------------------------------------------------------------------");
            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_REQ_SLOT_LIST);
            sbyte mainslot = -1;
            uint nOpenSlotCount = 8; // all slots unused
            uint nSlotNum = 0;
            uint nClassCount = 5; // MAX_CLASS_TYPE
            response.U1(mainslot); // main slot; -1 indicates that the user logged in for the first time
            response.U1((sbyte)NetTUTORIALTypes.TUTORIAL_STEP_NONE); // tutorial step
            response.U1((sbyte)nOpenSlotCount); // nOpenSlotCount
            for (int i = 0; i < nOpenSlotCount; i++) {
                response.U1((sbyte)i); // nSlotIdx -> the character slot
                response.U1((sbyte)3); // remainStatResetCount -> default is 3
            }
            response.U1((sbyte)nSlotNum); // nSlotNum
            for (int i = 0; i < nSlotNum; i++) {
                response.U1((sbyte)i); // nSlotIdx -> the character slot
                response.U1((sbyte)EnumCharClassType.CHARACTER_CLASS_DEFAULT); // char class
                response.U1((sbyte)1); // nLevel
                string startdate = "2016-03-01";
                response.U2((ushort)startdate.Length);
                response.Set(startdate); // start date
                response.U1((sbyte)0); // IsTraining
                response.U1((sbyte)0); // TrainingTime
                // uint nTotalTime for 1 week
                uint nTotalTime = 0;
                nTotalTime += (uint)(7 * 24 * 3600); // 7 days
                response.U8(nTotalTime); // nTotalTime
                response.U1((sbyte)0); // CostumeHead
                response.U1((sbyte)0); // CostumeBody
                response.U1((sbyte)0); // CostumeWeapon
                response.U1((sbyte)0); // CostumeSubWeapon
                response.U1((sbyte)0); // CostumeEffect
            }
            response.U1((sbyte)nClassCount); // nClassCount
            for (int i = 0; i < nClassCount; i++) {
                response.U1((sbyte)0); // STAT_STR
                response.U1((sbyte)0); // STAT_DEX
                response.U1((sbyte)0); // STAT_CON
                response.U1((sbyte)0); // STAT_SPI
            }
            return response;
        }
        public NetworkPacket API_ZNO_CS_REQ_REMOTE_CONTROL(User user, NetworkPacket packet) {
            Console.WriteLine("+-------------------------------------------------------------------");
	        Console.WriteLine("| TODO!: API_ZNO_CS_REQ_REMOTE_CONTROL");
            Console.WriteLine("+-------------------------------------------------------------------");
            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_REQ_REMOTE_CONTROL);
            response.U2((ushort)NetACKTypes.ACK_OK);
            response.U1(1); // remote control 1
            response.U1(0); // remote control 2
            response.U1(0); // remote control 3
            // 4 is controlled by client
            return response;
        }
        public NetworkPacket API_ZNO_CS_SOCIAL_INGAME_FRIEND_LIST_GET_GID(User user, NetworkPacket packet) {
            Console.WriteLine("+-------------------------------------------------------------------");
	        Console.WriteLine("| TODO!: API_ZNO_CS_SOCIAL_INGAME_FRIEND_LIST_GET_GID");
            Console.WriteLine("+-------------------------------------------------------------------");
            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_SOCIAL_INGAME_FRIEND_LIST_GET_GID);
            response.U2((ushort)NetACKTypes.ACK_OK);
            response.U2(0); // len of in-game friend list
            return response;
        }
        public NetworkPacket API_ZNO_CS_SOCIAL_MYINFO(User user, NetworkPacket packet) {
            user.social_info = Database.loadUserSocialInfo();
            Console.WriteLine("+-------------------------------------------------------------------");
	        Console.WriteLine("| TODO!: API_ZNO_SC_SOCIAL_MYINFO");
            Console.WriteLine("+-------------------------------------------------------------------");
            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_SOCIAL_MYINFO);
            response.U2((ushort)NetACKTypes.ACK_OK);
            response.U4(user.gid);
            response.U4(user.social_info.win_point);
            response.U1((sbyte)user.social_info.can_heart);
            response.U1((sbyte)user.social_info.profile_open_cnt);
            response.U1((sbyte)user.social_info.invite_blocked);
            response.U1((sbyte)user.social_info.gender);
            response.U1((sbyte)user.social_info.can_view_gender);
            response.U2((ushort)user.social_info.birthday.Length);
            response.Set(user.social_info.birthday);
            response.U1((sbyte)user.social_info.can_view_birthday);
            return response;
        }
        public NetworkPacket API_ZNO_CS_REQ_GAME_INFO(User user, NetworkPacket packet) {
            Console.WriteLine("+-------------------------------------------------------------------");
	        Console.WriteLine("| TODO?: API_ZNO_CS_REQ_GAME_INFO");
            Console.WriteLine("+-------------------------------------------------------------------");
            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_REQ_GAME_INFO);
            response.U2((byte)1); // len of game_info
            response.U4(99); // character max lvl
            return response;
        }
        public NetworkPacket API_ZNO_CS_REQ_LOGIN(User user, NetworkPacket packet) {
            user.GameVersion = packet.U2();
            user.UserID = packet.Get(packet.U2());
            user.Nickname = packet.Get(packet.U2());
            user.ProfileURL = packet.Get(packet.U2());
            user.IsMsgBlocked = packet.U1() == 1 ? true : false;
            bool isAuth = packet.U1() == 1 ? true : false;
            user.UUID = packet.Get(packet.U2());
            user.Company = packet.U1();
            user.SaleCode = packet.U1();

            Console.WriteLine("User {0} is connecting", user.UserID);

            if (isAuth) {
                Console.WriteLine("User {0} is authenticated", user.UserID);
            }

            if (user.GameVersion != 509) {
                Console.WriteLine("User {0} is using wrong game version {1}", user.UserID, user.GameVersion);
                NetworkPacket packet_out = new NetworkPacket(NetCMDTypes.ZNO_SC_REQ_LOGIN);
                packet_out.U2((ushort)NetACKTypes.ACK_VERSION_MISMATCH);
                return packet_out;
            }
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| API_ZNO_CS_REQ_LOGIN");
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| GameVersion:   {0}", user.GameVersion);
            Console.WriteLine("| UserID:        {0}", user.UserID);
            Console.WriteLine("| Nickname:      {0}", user.Nickname);
            Console.WriteLine("| ProfileURL:    {0}", user.ProfileURL);
            Console.WriteLine("| IsMsgBlocked:  {0}", user.IsMsgBlocked);
            Console.WriteLine("| UUID:          {0}", user.UUID);
            Console.WriteLine("| Company:       {0}", user.Company);
            Console.WriteLine("| SaleCode:      {0}", user.SaleCode);
            Console.WriteLine("+-------------------------------------------------------------------");

            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_REQ_LOGIN);
            response.U2((ushort)NetACKTypes.ACK_OK);
            // generate a random uint gid -> this is the player gid
            uint gid = (uint)new Random().Next(0, int.MaxValue);
            Console.WriteLine("Generated gid: {0}", gid);
            response.U4(gid);
            user.gid = gid;

            return response;
        }
        public NetworkPacket API_ZNO_CS_CONNECT(User user, NetworkPacket packet) {
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| API_ZNO_CS_CONNECT");
            Console.WriteLine("+-------------------------------------------------------------------");
            UInt16 social_len = (UInt16)packet.U2();
            user.social_id = packet.Get(social_len);
            Console.WriteLine("social_id: " + user.social_id);
            // TODO load user from social_id
            user.Nickname = user.social_id;
            UInt16 type = packet.U1();
            UInt16 server_id = packet.U2();
            UInt16 channel_id = packet.U2();
            Console.WriteLine("type: " + type);
            Console.WriteLine("server_id: " + server_id);
            Console.WriteLine("channel_id: " + channel_id);

            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_CONNECT);
            response.U2((ushort)NetACKTypes.ACK_OK);
            // next 16 bytes are the new encryption key
            response.Set("ZENONIAONLINE@22");
            user.encryption_key = "ZENONIAONLINE@22";
            return response;
        }
        public NetworkPacket API_ZNO_CS_RECONNECT (User user, NetworkPacket packet) {
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| API_ZNO_CS_RECONNECT");
            Console.WriteLine("+-------------------------------------------------------------------");
            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_RECONNECT);
            if (user != null) {
                response.U2((ushort)NetACKTypes.ACK_OK); // ACK_OK, ACK_FAIL (-1) would indicate that the reconnect would be successfull??
            } else {
                return null;
            }
            return response;
        }
        public NetworkPacket API_ZNO_CS_PING (User user, NetworkPacket packet) {
            Console.WriteLine("Ping");
            return null;
        }
    }
}
**/