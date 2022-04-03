/**
using System.Net;
using System.Net.Sockets;
using System.Text;
using ProjectZ;
using System.Reflection;

namespace ProjectZ {
    public class ClientHandler {
        public TcpClient client;
        public NetworkStream stream;

        User user;
        public bool isRunning = true;

        bool IsNeedEnc(NetCMDTypes wCMD)
        {
            if (wCMD == NetCMDTypes.ZNO_CS_PING ||		
                wCMD == NetCMDTypes.ZNO_CS_MOVE || 
                wCMD == NetCMDTypes.ZNO_SC_MOVE ||
                wCMD == NetCMDTypes.ZNO_CS_STOP ||
                wCMD == NetCMDTypes.ZNO_SC_STOP ||
                wCMD == NetCMDTypes.ZNO_CS_DASH ||
                wCMD == NetCMDTypes.ZNO_SC_DASH ||
                wCMD == NetCMDTypes.ZNO_CS_RECONNECT ||
                wCMD == NetCMDTypes.ZNO_SC_RECONNECT ||
                wCMD == NetCMDTypes.ZNO_CS_REQ_LOCATION ||
                wCMD == NetCMDTypes.ZNO_SN_REQ_LOCATION ||
                wCMD == NetCMDTypes.ZNO_CS_MOVE_MOB ||
                wCMD == NetCMDTypes.ZNO_SC_MOVE_MOB ||
                wCMD == NetCMDTypes.ZNO_CN_LOCATION_MODIFY ||
                wCMD == NetCMDTypes.ZNO_SN_LOCATION_MODIFY ||
                wCMD == NetCMDTypes.ZNO_CS_ATTACK_START ||
                wCMD == NetCMDTypes.ZNO_SC_ATTACK_START ) {
                    return false;
                }
	        return true;
        }

        void xorEncode(byte[] src, uint srclen, byte[] key, uint keylen)
        {
            for (uint i = 0; i < srclen; i++)
            {
                src[i] ^= key[i % keylen];
            }
        }
        public void HandleClient(TcpClient client) {
            this.client = client;
            stream = client.GetStream();
            user = new User();
            Thread t = new Thread(run);
            t.Start();
        }
        private void run() {
            try {
                while (isRunning) {

                    byte[] data = new byte[1024 * 10]; // max packet len to send/recv is 10k
                    stream.Read(data, 0, data.Length);
                    // print how many bytes were read
                    Console.WriteLine("Read {0} bytes from stream.", data.Length);
                    
                    try {
                        NetworkPacket packet;
                        packet = new NetworkPacket(data);
                        Console.WriteLine("Received a packet");
                        // print the name of the cmd from the NetCMDTypes enum
                        Console.WriteLine("cmd " + packet.Cmd.ToString());
                        byte[] body = new byte[packet.Length];
                        if (packet.Length > 0) {
                            stream.Read(body, 0, body.Length);
                            if (IsNeedEnc(packet.Cmd)) {
                                if (packet.Cmd == NetCMDTypes.ZNO_CS_CONNECT || packet.Cmd == NetCMDTypes.ZNO_CS_REQ_SERVER_ADDR) {
                                    Console.WriteLine("Decrypting");
                                    xorEncode(body, (uint)body.Length, Encoding.ASCII.GetBytes("ZenoniaOnline"), (uint)Encoding.ASCII.GetBytes("ZenoniaOnline").Length);
                                } else {
                                    Console.WriteLine("Decrypting with user key");
                                    xorEncode(body, (uint)body.Length, Encoding.ASCII.GetBytes(user.Nickname), (uint)Encoding.ASCII.GetBytes(user.Nickname).Length);
                                }
                            }
                            packet.data = body;
                        }

                        String func = "API_" + packet.Cmd.ToString();
                        Console.WriteLine("func " + func);

                        Type thisType = typeof(CommandHandler);
                        MethodInfo theMethod = thisType.GetMethod(func);
                        CommandHandler handler = new CommandHandler();
                        NetworkPacket returnValue = (NetworkPacket)theMethod.Invoke(handler, new object[] {user, packet});
                        if (returnValue != null) {
                            Console.WriteLine("Sending a packet");
                            if (IsNeedEnc(returnValue.Cmd)) {
                                Console.WriteLine("Decrypting with user key");
                                xorEncode(returnValue.data, (uint)returnValue.Length, Encoding.ASCII.GetBytes(user.Nickname), (uint)Encoding.ASCII.GetBytes(user.Nickname).Length);
                            }
                            byte[] sendPacket = new byte[1024 * 10];
                            // copy the return value to the send packet
                            Array.Copy(returnValue.data, sendPacket, returnValue.Length);
                            // send the packet
                            stream.Write(sendPacket, 0, sendPacket.Length);
                        } else {
                            Console.WriteLine("No return value");
                        }
                    } catch (Exception e) {
                        // when there are no more packets in the stream, the stream will throw an exception
                        Console.WriteLine("Error: " + e.Message);
                        Console.WriteLine(e.StackTrace);
                        // print time
                        Console.WriteLine(DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss"));
                        Console.WriteLine("no more packets in stream");
                    }
                }
            } catch (Exception e) {
                // when the client disconnects
                Console.WriteLine("Error: " + e.Message);
                Console.WriteLine(e.StackTrace);
                Console.WriteLine(DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss"));
                Console.WriteLine("Closing connection");
                client.Close();
            }
        }
    }
    public class TcpServer {
        TcpListener server;

        public bool isRunning {get; set;}
        public TcpServer() {
            // create a new tcp server that listens on port 55000
            // listen on any IP address
            server = new TcpListener(IPAddress.Any, 55000);
            // start the server
            server.Start();
            isRunning = true;
            // run HandlePacketAsync in background
            while (true) {
                Console.WriteLine("waiting for connection...");
                TcpClient client = server.AcceptTcpClient();
                // create a new stream to read and write data
                NetworkStream stream = client.GetStream();
                Console.WriteLine("new client connected");
                ClientHandler handler = new ClientHandler();
                handler.HandleClient(client);
            }
        }
    }
}
**/