namespace ProjectZ {
    public class API_ZNO_CS_SOCIAL_NEWS_COUNT
    {
        public NetworkPacket ZNO_CS_SOCIAL_NEWS_COUNT(NetworkPacket req, Session session) {
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| API_ZNO_CS_SOCIAL_NEWS_COUNT");
            Console.WriteLine("+-------------------------------------------------------------------");

            Int16 count = 0;
            NetworkPacket rsp = new NetworkPacket(NetCMDTypes.ZNO_SC_SOCIAL_NEWS_COUNT);
            rsp.U2((short)NetACKTypes.ACK_OK);
            rsp.U2(count);
            return rsp;
        }
    }
}
