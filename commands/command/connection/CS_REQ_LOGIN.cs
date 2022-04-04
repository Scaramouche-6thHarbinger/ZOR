namespace ProjectZ {
    public class API_ZNO_CS_REQ_LOGIN
    {
        public NetworkPacket ZNO_CS_REQ_LOGIN(NetworkPacket req, Session session) {
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| API_ZNO_CS_REQ_LOGIN");
            Console.WriteLine("+-------------------------------------------------------------------");
            ushort game_version = req.U2();
            string UserID = req.Get(req.U2());
            string m_Nickname = req.Get(req.U2());
            string ProfileUrl = req.Get(req.U2());
            bool IsMsgBlocked = req.U1() == 1 ? true : false;
            bool isAuth = req.U1() == 1 ? true : false;
            string UUID = req.Get(req.U2());
            byte Company = req.U1();
            byte SaleCode = req.U1();

            Console.WriteLine("| GameVersion:   {0}", game_version);
            Console.WriteLine("| UserID:        {0}", UserID);
            Console.WriteLine("| Nickname:      {0}", m_Nickname);
            Console.WriteLine("| ProfileURL:    {0}", ProfileUrl);
            Console.WriteLine("| IsMsgBlocked:  {0}", IsMsgBlocked);
            Console.WriteLine("| UUID:          {0}", UUID);
            Console.WriteLine("| Company:       {0}", Company);
            Console.WriteLine("| SaleCode:      {0}", SaleCode);
            Console.WriteLine("+-------------------------------------------------------------------");

            if (session.user.Nickname == "") {
                session.user.Nickname = m_Nickname;
            }

            if (game_version != 509 && m_Nickname != "1231234") {
                Console.WriteLine("User {0} is using wrong game version {1}", m_Nickname, game_version);
                NetworkPacket packet_out = new NetworkPacket(NetCMDTypes.ZNO_SC_REQ_LOGIN);
                packet_out.U2((short)NetACKTypes.ACK_VERSION_MISMATCH);
                return packet_out;
            }

            session.user.ProfileUrl = ProfileUrl;
            session.user.Uuid = UUID;
            session.user.Company = Company;
            session.user.SaleCode = SaleCode;

            //session.user.IsMsgBlocked = IsMsgBlocked;
            session.user.isAuth = isAuth;

            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_REQ_LOGIN);
            response.U2((short)NetACKTypes.ACK_OK);
            // generate a random uint gid -> this is the player gid
            uint gid = (uint)new Random().Next(0, int.MaxValue);
            Console.WriteLine("Generated gid: {0}", gid);
            response.U4((int)gid);
            session.user.gid = gid;

            return response;
        }
    }
}