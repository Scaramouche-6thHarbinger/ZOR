namespace ProjectZ {
    public class API_ZNO_CS_GET_NEW_MAIL_COUNT
    {
        public NetworkPacket ZNO_CS_GET_NEW_MAIL_COUNT(NetworkPacket req, Session session) {
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| API_ZNO_CS_GET_NEW_MAIL_COUNT");
            Console.WriteLine("+-------------------------------------------------------------------");

            sbyte newMailCount = 0;
            NetworkPacket rsp = new NetworkPacket(NetCMDTypes.ZNO_SC_GET_NEW_MAIL_COUNT);
            rsp.U2((short)NetACKTypes.ACK_OK);
            rsp.U1(newMailCount);
            return rsp;
        }
    }
}
