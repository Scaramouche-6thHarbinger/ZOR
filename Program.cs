using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;
using ProjectZ;
using ProjectZ.Common.Protocol.Protobuf;
using ProjectZ.Common.Protocol;

public class server {
    public static void Main() {
        // run in background thread
        TcpServer server = new TcpServer(54000);
        while (server.isRunning) {
            Thread.Sleep(1000);
        }
    }
}
