namespace ProjectZ {
    public class API_ZNO_CS_CONNECT
    {
        public NetworkPacket ZNO_CS_CONNECT(NetworkPacket req, Session session) {
            try {
            session.user = new User();
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| API_ZNO_CS_CONNECT");
            Console.WriteLine("+-------------------------------------------------------------------");
            UInt16 social_len = (UInt16)req.U2();
            string social_id = req.Get(social_len);
            // TODO load user from social_id
            //user.Nickname = user.social_id;
            UInt16 type = req.U1();
            UInt16 server_id = req.U2();
            UInt16 channel_id = req.U2();

            session.user = session.user.LoadUser(social_id);

            Console.WriteLine("| social_id:     " + session.user.SocialID);
            Console.WriteLine("| type:          " + type);
            Console.WriteLine("| server_id:     " + server_id);
            Console.WriteLine("| channel_id:    " + channel_id);
            Console.WriteLine("+-------------------------------------------------------------------");

            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_CONNECT);
            response.U2((ushort)NetACKTypes.ACK_OK);
            // next 16 bytes are the new encryption key
            response.Set("ZENONIAONLINE@22");
            session.user.encryption_key = "ZENONIAONLINE@22";
            return response;
            } catch (Exception e) {
                Console.WriteLine("API_ZNO_CS_CONNECT: " + e.Message);
                Console.WriteLine(e.StackTrace);
                return null;
            }
        }
    }
}