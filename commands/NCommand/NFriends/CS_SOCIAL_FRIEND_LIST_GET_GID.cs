namespace ProjectZ {
    public class API_ZNO_CS_SOCIAL_FRIEND_LIST_GET_GID
    {
        public NetworkPacket ZNO_CS_SOCIAL_FRIEND_LIST_GET_GID(NetworkPacket req, Session session) {
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| API_ZNO_CS_SOCIAL_FRIEND_LIST_GET_GID");
            Console.WriteLine("+-------------------------------------------------------------------");
            UInt16 count = req.U2();
            Console.WriteLine("| count: " + count);

            NetworkPacket rsp = new NetworkPacket(NetCMDTypes.ZNO_SC_SOCIAL_FRIEND_LIST_GET_GID);

            if (100 < count) {
                Console.WriteLine("| count is too big");
                rsp.U2((short)NetACKTypes.ACK_UNKNOWN_ERROR);
                rsp.U1(0);
                return rsp;
            }

            List<UInt64> array_social_id = new List<UInt64>();

            for (int i = 0; i < count; i++) {
                UInt64 social_id = req.U8();
                Console.WriteLine("| social_id: " + social_id);
                array_social_id.Add(social_id);
            }
            Console.WriteLine("+-------------------------------------------------------------------");
            rsp.U2((short)NetACKTypes.ACK_OK);
            rsp.U2((short)array_social_id.Count);
            foreach (UInt64 social_id in array_social_id) {
                rsp.U8((Int64)social_id);
                rsp.U4(0); // userseq
                rsp.U1(0); // is_delete
            }
            return rsp;
        }
    }
}