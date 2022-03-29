#ifndef __BYTEARRAY_H__
#define __BYTEARRAY_H__

#define htonll(x) ((1==htonl(1)) ? (x) : ((uint64_t)htonl((x) & 0xFFFFFFFF) << 32) | htonl((x) >> 32))
#define ntohll(x) ((1==ntohl(1)) ? (x) : ((uint64_t)ntohl((x) & 0xFFFFFFFF) << 32) | ntohl((x) >> 32))

#include <util.h>
#include <arpa/inet.h>

typedef unsigned char byte;

class ByteArray
{
public:
    static void SetUInt16(byte* p, int offset, unsigned short value, bool bigEndian = false) {
        if (bigEndian) value = htons(value);
        p[offset + 0] = (value & 0xFF);
        p[offset + 1] = ((value & 0xFF00) >> 8);
    }

    static void SetUInt32(byte* p, int offset, unsigned int value, bool bigEndian = false) {
        if (bigEndian) value = htonl(value);
        p[offset + 0] = (value & 0xFF);
        p[offset + 1] = ((value & 0xFF00) >> 8);
        p[offset + 2] = ((value & 0xFF0000) >> 16);
        p[offset + 3] = ((value & 0xFF000000) >> 24);
    }

    static void SetUInt64(byte* p, int offset, uint64_t value, bool bigEndian = false) {
        if (bigEndian) value = htonll(value);
        p[offset + 0] = (value & 0xFF);
        p[offset + 1] = ((value & 0xFF00) >> 8);
        p[offset + 2] = ((value & 0xFF0000) >> 16);
        p[offset + 3] = ((value & 0xFF000000) >> 24);
        p[offset + 4] = ((value & 0xFF00000000) >> 32);
        p[offset + 5] = ((value & 0xFF0000000000) >> 40);
        p[offset + 6] = ((value & 0xFF000000000000) >> 48);
        p[offset + 7] = ((value & 0xFF00000000000000) >> 56);
    }

    static ushort GetUInt16(byte* p, int offset, bool bigEndian = false) {
        ushort value = p[offset + 0] | (p[offset + 1] << 8);
        if (bigEndian) value = ntohs(value);
        return value;
    }

    static uint GetUInt32(byte* p, int offset, bool bigEndian = false) {
        uint value = p[offset + 0] | (p[offset + 1] << 8) | (p[offset + 2] << 16) | (p[offset + 3] << 24);
        if (bigEndian) value = ntohl(value);
        return value;
    }

    static uint64_t GetUInt64(byte* p, int offset, bool bigEndian = false) {
        uint64_t value = p[offset + 0] | (p[offset + 1] << 8) | (p[offset + 2] << 16) | (p[offset + 3] << 24) |
                          (p[offset + 4] << 32) | (p[offset + 5] << 40) | (p[offset + 6] << 48) | (p[offset + 7] << 56);
        if (bigEndian) value = ntohll(value);
        return value;
    }
};

#endif // __BYTEARRAY_H__