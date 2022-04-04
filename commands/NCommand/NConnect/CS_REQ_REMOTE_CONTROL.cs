namespace ProjectZ {
    public class API_ZNO_CS_REQ_REMOTE_CONTROL
    {
        public NetworkPacket ZNO_CS_REQ_REMOTE_CONTROL(NetworkPacket req, Session session) {
            Console.WriteLine("+-------------------------------------------------------------------");
	        Console.WriteLine("| TODO!: API_ZNO_CS_REQ_REMOTE_CONTROL");
            Console.WriteLine("+-------------------------------------------------------------------");

            sbyte _front_news_banner = 0;
            sbyte _top_news_banner = 0;
            sbyte _cpi_button = 0;

            if (session.user.MainSlotIndex != -1) {
                _cpi_button = 1;
            }

            NetworkPacket rsp = new NetworkPacket(NetCMDTypes.ZNO_SC_REQ_REMOTE_CONTROL);
            rsp.U2(1);
            rsp.U1(_front_news_banner);
            rsp.U1(_top_news_banner);
            rsp.U1(_cpi_button);

            Console.WriteLine("| front_news_banner: " + _front_news_banner);
            Console.WriteLine("| top_news_banner: " + _top_news_banner);
            Console.WriteLine("| cpi_button: " + _cpi_button);
            Console.WriteLine("+-------------------------------------------------------------------");

            return rsp;
        }
    }
}
            