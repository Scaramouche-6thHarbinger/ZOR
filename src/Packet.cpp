#include <Packet.h>

namespace Network {

Packet::Packet(unsigned short wCMD)
{
    header = new NetHeader();
    body = new byte[MAX_PACKET_SIZE];
    size = 0;
    offset = 0;

    setCMD(wCMD);

}

Packet::Packet(unsigned int size)
{
    header = new NetHeader();
    this->body = new byte[size];
    this->size = size;
    this->offset = 0;
}

Packet::Packet(byte* body, unsigned int size)
{
    header = new NetHeader();
    this->body = new byte[size];
    this->size = size;
    this->offset = 0;

    memcpy(this->body, body, size);
}

bool Packet::Read1(byte* d)
{
    if (IsAvailable(1)) {
        *d = *(getOffsetPtr());
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
        *d = *(short*)getOffsetPtr();
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
        *d = *(int*)getOffsetPtr();
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
        *d = *(float*)getOffsetPtr();
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
        *d = *(int64_t*)getOffsetPtr();
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
        *d = *(double*)getOffsetPtr();
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
    uint32_t rl = MIN((uint32_t)(size - offset), max_len);
    byte* dst = buf;
	byte* src = getOffsetPtr();
	byte* end = src + rl;

    while (src < end && *src && (*dst++ = *src++))
	{
		// Nothing to do
	}
	*dst = 0;

	rl = dst - buf;
	offset += rl;
	return rl;
}

bool Packet::Write1(byte d)
{
    if (IsAvailable(1)) {
        *(getOffsetPtr()) = d;
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
        *(short*)getOffsetPtr() = d;
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
        *(int*)getOffsetPtr() = d;
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
        *(float*)getOffsetPtr() = d;
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
        *(int64_t*)getOffsetPtr() = d;
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
        *(double*)getOffsetPtr() = d;
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

uint32_t Packet::WriteStr(const byte* buf, uint32_t max_len)
{
    uint32_t wl = MIN((uint32_t)(size - offset), max_len);
    byte* dst = getOffsetPtr();
    const byte* src = buf;
    const byte* end = src + wl;

    while (src < end && *src && (*dst++ = *src++))
    {
        // Nothing to do
    }
    *dst = 0;

    wl = dst - buf;
    offset += wl;
    return wl;
}

} /* namespace Network */
