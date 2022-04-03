using System.IO;

namespace ProjectZ {
    public class NetworkPacket {
        private const uint HEADER_LEN = 6;

        private byte flag;
        private UInt16 length;
        private byte reserved;
        private UInt16 cmd;

        public byte[] data {get; set;}
        private int pos;
        private static readonly byte FLAG_MAGIC = 0xFF;

        public uint Length {
            get {
                return length;
            }
        }

        public NetCMDTypes Cmd {
            get {
                return (NetCMDTypes)cmd;
            }
        }

        public void setBody(byte[] body) {
            data = body;
            if (length != body.Length) {
                throw new Exception("Packet length does not match body length -> header/data mismatch");
            }
        }

        public NetworkPacket( byte[] header ) {
            uint len = ParseHeader( header );
            if (len > 0) {
                data = new byte[len];
            } else {
                // empty packet -> do nothing
            }
            pos = 0;
        }

        public NetworkPacket( NetCMDTypes wCMD ) {
            flag = FLAG_MAGIC;
            length = 0;
            reserved = 0;
            this.cmd = (ushort)wCMD;

            pos = 0;
        }

        private uint ParseHeader( byte[] packet ) {
            if (packet.Length < 6 || packet.Length <= 0) {
                throw new Exception("Invalid packet length");
            }
            flag = packet[0];
            length = ByteArray.GetUInt16(packet, 1);
            length -= 3;
            reserved = packet[3];
            cmd = ByteArray.GetUInt16(packet, 4);

            if (flag != FLAG_MAGIC) {
                throw new Exception("Invalid packet flag");
            }

            return length;
        }

        private void extendBody(uint len) {
            if (data == null) {
                data = new byte[len];
            } else {
                byte[] tmp = new byte[data.Length + len];
                Array.Copy(data, tmp, data.Length);
                data = tmp;
            }
            length += (ushort)len;
        }

        public void U1( sbyte value ) {
            extendBody(1);
            data[pos] = (byte)value;
            pos++;
        }

        public void U2 ( UInt16 value ) {
            extendBody(2);
            ByteArray.SetUInt16(data, pos, value);
            pos += 2;
        }

        public void U4 ( UInt32 value ) {
            extendBody(4);
            ByteArray.SetUInt32(data, pos, value);
            pos += 4;
        }

        public void U8( UInt64 value ) {
            extendBody(8);
            ByteArray.SetUInt64(data, pos, value);
            pos += 8;
        }

        public void Set( string value ) {
            extendBody((uint)value.Length);
            byte[] bytes = System.Text.Encoding.UTF8.GetBytes(value);
            Array.Copy(bytes, 0, data, pos, bytes.Length);
            pos += bytes.Length;
        }

        public void SeekStart() {
            pos = 0;
        }

        public byte U1() {
            return data[pos++];
        }

        public UInt16 U2() {
            UInt16 ret = ByteArray.GetUInt16(data, pos);
            pos += 2;
            return ret;
        }

        public UInt32 U4() {
            UInt32 ret = ByteArray.GetUInt32(data, pos);
            pos += 4;
            return ret;
        }

        public UInt64 U8() {
            UInt64 ret = ByteArray.GetUInt64(data, pos);
            pos += 8;
            return ret;
        }

        public string Get( int len ) {
            string ret = System.Text.Encoding.UTF8.GetString(data, pos, len);
            pos += len;
            return ret;
        }

        public byte[] GetHeader() {
            byte[] header = new byte[HEADER_LEN];
            header[0] = flag;
            ByteArray.SetUInt16(header, 1, (ushort)(data.Length + 3));
            header[3] = reserved;
            ByteArray.SetUInt16(header, 4, cmd);
            return header;
        }

        public byte[] AsBytes() {
            byte[] header = new byte[HEADER_LEN];
            ByteArray.SetUInt16(header, 0, flag);
            ByteArray.SetUInt16(header, 1, (ushort)(data.Length + 3)); // idk why +3
            header[3] = reserved;
            ByteArray.SetUInt16(header, 4, cmd);
            if (length > 0) {
                byte[] packet = new byte[HEADER_LEN + length];
                Array.Copy(header, packet, HEADER_LEN);
                Array.Copy(data, 0, packet, HEADER_LEN, length);
                return packet;
            } else {
                return header;
            }
        }
    }
}