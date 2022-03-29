#include <Packet.h>

namespace Network {

Packet::Packet(unsigned short wCMD)
{
    header = new NetHeader();
    body = new byte[MAX_PACKET_SIZE];
    memset(header, 0, MAX_PACKET_SIZE);
    size = MAX_PACKET_SIZE;
    offset = 0;

    setCMD(wCMD);
}

Packet::Packet(byte* body, unsigned int size)
{
    header = new NetHeader();
    this->body = new byte[size];
    this->size = size;
    this->offset = 0;

    memcpy(this->body, body, size);
}

Packet::~Packet()
{
    LOGD("Packet::~Packet()");
    delete header;
}

bool Packet::Read1(byte* d)
{
    if (IsAvailable(1)) {
        *d = getPtr()[offset];
        offset++;
        return true;
    } else {
        LOGE("Packet::Read1() failed, offset=%d, size=%d", offset, size);
        assert(false);
        return false;
    }
}

bool Packet::Read2(short* d)
{
    if (IsAvailable(2)) {
        *d = ByteArray::GetUInt16(getPtr(), offset);
        offset += 2;
        return true;
    } else {
        LOGE("Packet::Read2() failed, offset=%d, size=%d", offset, size);
        assert(false);
        return false;
    }
}

bool Packet::Read4(int* d)
{
    if (IsAvailable(4)) {
        *d = ByteArray::GetUInt32(getPtr(), offset);
        offset += 4;
        return true;
    } else {
        LOGE("Packet::Read4() failed, offset=%d, size=%d", offset, size);
        assert(false);
        return false;
    }
}

bool Packet::Read4(float* d)
{
    if (IsAvailable(4)) {
        *d = ByteArray::GetUInt32(getPtr(), offset);
        offset += 4;
        return true;
    } else {
        LOGE("Packet::Read4() failed, offset=%d, size=%d", offset, size);
        assert(false);
        return false;
    }
}

bool Packet::Read8(int64_t* d)
{
    if (IsAvailable(8)) {
        *d = ByteArray::GetUInt64(getPtr(), offset);
        offset += 8;
        return true;
    } else {
        LOGE("Packet::Read8() failed, offset=%d, size=%d", offset, size);
        assert(false);
        return false;
    }
}

bool Packet::Read8(double* d)
{
    if (IsAvailable(8)) {
        *d = ByteArray::GetUInt64(getPtr(), offset);
        offset += 8;
        return true;
    } else {
        LOGE("Packet::Read8() failed, offset=%d, size=%d", offset, size);
        assert(false);
        return false;
    }
}

uint32_t Packet::ReadBin(byte* buf, uint32_t buf_len)
{
    uint32_t rl = MIN((uint32_t)(size - offset), buf_len);
    if (rl > 0)
	{
		memcpy(buf, getOffsetPtr(), rl);
		offset += rl;
		return rl;
	}
	else
	{
		memset(buf, 0, buf_len);
		return 0;
	}
}

uint32_t Packet::ReadStr(byte* buf, uint32_t max_len)
{
    return ReadBin(buf, max_len);
}

bool Packet::Write1(byte d)
{
    if (IsAvailable(1)) {
        getPtr()[offset] = d;
        offset++;
        return true;
    } else {
        LOGE("Packet::Write1() failed, offset=%d, size=%d", offset, size);
        assert(false);
        return false;
    }
}

bool Packet::Write2(short d)
{
    if (IsAvailable(2)) {
        ByteArray::SetUInt16(getPtr(), offset, d);
        offset += 2;
        return true;
    } else {
        LOGE("Packet::Write2() failed, offset=%d, size=%d", offset, size);
        assert(false);
        return false;
    }
}

bool Packet::Write4(int d)
{
    if (IsAvailable(4)) {
        ByteArray::SetUInt32(getPtr(), offset, d);
        offset += 4;
        return true;
    } else {
        LOGE("Packet::Write4() failed, offset=%d, size=%d", offset, size);
        assert(false);
        return false;
    }
}

bool Packet::Write4(float d)
{
    if (IsAvailable(4)) {
        ByteArray::SetUInt32(getPtr(), offset, d);
        offset += 4;
        return true;
    } else {
        LOGE("Packet::Write4() failed, offset=%d, size=%d", offset, size);
        assert(false);
        return false;
    }
}

bool Packet::Write8(int64_t d)
{
    if (IsAvailable(8)) {
        ByteArray::SetUInt64(getPtr(), offset, d);
        offset += 8;
        return true;
    } else {
        LOGE("Packet::Write8() failed, offset=%d, size=%d", offset, size);
        assert(false);
        return false;
    }
}

bool Packet::Write8(double d)
{
    if (IsAvailable(8)) {
        ByteArray::SetUInt64(getPtr(), offset, d);
        offset += 8;
        return true;
    } else {
        LOGE("Packet::Write8() failed, offset=%d, size=%d", offset, size);
        assert(false);
        return false;
    }
}

uint32_t Packet::WriteBin(const byte* buf, uint32_t buf_len)
{
	uint32_t wl = MIN((uint32_t)(size - offset), buf_len);

	memcpy(getOffsetPtr(), buf, wl);
	offset += wl;

	return wl;
}

uint32_t Packet::WriteStr(const byte* buf, uint32_t len)
{
    return WriteBin(buf, len);
}

NetPacket *Packet::MakeNetPacket(unsigned short wCMD)
{
    NetPacket *p = new NetPacket();
    // cut remaining data
    if (offset <= size) {
        LOGI("Packet::MakeNetPacket() cut remaining data, offset=%d, size=%d", offset, size);
        p->body = new byte[offset];
        memcpy(p->body, getPtr(), offset);
        p->bodyLen = offset;
    } else {
        LOGF("wait whut");
    }
    p->header.wCMD = wCMD;
    p->header.wLen = offset + 3;
    p->header.byStartFlag = 0xFF;
    p->header.byReserve = 0;
    LOGD("new NetPacket, wCMD=%d, wLen=%d", wCMD, p->header.wLen);
    return p;
}
} /* namespace Network */
