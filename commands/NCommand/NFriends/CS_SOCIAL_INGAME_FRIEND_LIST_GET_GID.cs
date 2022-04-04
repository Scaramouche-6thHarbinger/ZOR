namespace ProjectZ {
    public class API_ZNO_CS_SOCIAL_INGAME_FRIEND_LIST_GET_GID
    {
        public NetworkPacket ZNO_CS_SOCIAL_INGAME_FRIEND_LIST_GET_GID(NetworkPacket req, Session session) {
            Console.WriteLine("+-------------------------------------------------------------------");
	        Console.WriteLine("| TODO!: API_ZNO_CS_SOCIAL_INGAME_FRIEND_LIST_GET_GID");
            Console.WriteLine("+-------------------------------------------------------------------");
            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_SOCIAL_INGAME_FRIEND_LIST_GET_GID);
            response.U2((short)NetACKTypes.ACK_OK);
            response.U2(0); // len of in-game friend list
            return response;
        }
    }
}