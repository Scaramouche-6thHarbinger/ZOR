namespace ProjectZ {
    public class API_ZNO_CS_REQ_GAME_INFO
    {
        public NetworkPacket ZNO_CS_REQ_GAME_INFO(NetworkPacket req, Session session) {
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| API_ZNO_CS_REQ_GAME_INFO");
            Console.WriteLine("+-------------------------------------------------------------------");

            NetworkPacket rsp = new NetworkPacket(NetCMDTypes.ZNO_SC_REQ_GAME_INFO);
            // TODO get maxLevel and recoveryMinute from somewhere
            rsp.U2((short)2); // count of ints
            rsp.U4(99); // maxLevel
            rsp.U4(1); // recoveryMinute

            Console.WriteLine("| maxLevel: " + 99);
            Console.WriteLine("| recoveryMinute: " + 1);
            Console.WriteLine("+-------------------------------------------------------------------");
            return rsp;
        }
    }
}
           