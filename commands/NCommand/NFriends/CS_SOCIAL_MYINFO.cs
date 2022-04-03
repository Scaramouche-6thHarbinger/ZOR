namespace ProjectZ {
    public class API_ZNO_CS_SOCIAL_MYINFO {
        public NetworkPacket ZNO_CS_SOCIAL_MYINFO(NetworkPacket req, Session session) {
            Console.WriteLine("+-------------------------------------------------------------------");
	        Console.WriteLine("| TODO!: API_ZNO_SC_SOCIAL_MYINFO");
            Console.WriteLine("+-------------------------------------------------------------------");
            NetworkPacket response = new NetworkPacket(NetCMDTypes.ZNO_SC_SOCIAL_MYINFO);
            response.U2((ushort)NetACKTypes.ACK_OK);
            response.U4(session.user.gid);
            response.U4(session.user.WpCurWeek);
            response.U1((sbyte)session.user.HeartBlocked);
            response.U1((sbyte)session.user.ProfileOpened);
            response.U1((sbyte)session.user.InviteBlocked);
            response.U1((sbyte)session.user.Gender);
            response.U1((sbyte)session.user.IsGenderOpen);
            response.U2((ushort)session.user.Birthday.Length);
            response.Set(session.user.Birthday);
            response.U1((sbyte)session.user.IsBirthdayOpen);
            
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| gid:           " + session.user.gid);
            Console.WriteLine("| WpCurWeek:     " + session.user.WpCurWeek);
            Console.WriteLine("| HeartBlocked:  " + session.user.HeartBlocked);
            Console.WriteLine("| ProfileOpened: " + session.user.ProfileOpened);
            Console.WriteLine("| InviteBlocked: " + session.user.InviteBlocked);
            Console.WriteLine("| Gender:        " + session.user.Gender);
            Console.WriteLine("| IsGenderOpen   " + session.user.IsGenderOpen);
            Console.WriteLine("| Birthday       " + session.user.Birthday);
            Console.WriteLine("| IsBirthdayOpen " + session.user.IsBirthdayOpen);
            Console.WriteLine("+-------------------------------------------------------------------");
            return response;
        }
    }
}