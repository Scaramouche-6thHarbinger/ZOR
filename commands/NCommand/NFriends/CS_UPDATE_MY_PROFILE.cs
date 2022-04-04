namespace ProjectZ {
    public class API_ZNO_CS_UPDATE_MY_PROFILE
    {
        public NetworkPacket ZNO_CS_UPDATE_MY_PROFILE(NetworkPacket req, Session session) {
            Console.WriteLine("+-------------------------------------------------------------------");
            Console.WriteLine("| API_ZNO_CS_UPDATE_MY_PROFILE");
            Console.WriteLine("+-------------------------------------------------------------------");

            session.user.Gender = req.U1();
            session.user.IsGenderOpen = req.U1();
            session.user.Birthday = req.Get(req.U2());
            session.user.IsBirthdayOpen = req.U1();
            session.user.IsProfileOpen = req.U1();

            Console.WriteLine("| Gender:        " + session.user.Gender);
            Console.WriteLine("| IsGenderOpen:  " + session.user.IsGenderOpen);
            Console.WriteLine("| Birthday:      " + session.user.Birthday);
            Console.WriteLine("| IsBirthdayOpen:" + session.user.IsBirthdayOpen);
            Console.WriteLine("| IsProfileOpen: " + session.user.IsProfileOpen);
            Console.WriteLine("+-------------------------------------------------------------------");

            NetworkPacket rsp = new NetworkPacket(NetCMDTypes.ZNO_SC_UPDATE_MY_PROFILE);
            rsp.U2((short)NetACKTypes.ACK_OK);
            return rsp;
        }
    }
}