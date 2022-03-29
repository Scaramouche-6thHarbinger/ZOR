/*
 * Packet.h
 *
 *  Created on: 2012. 8. 16.
 *      Author: jjaehuny
 */

#ifndef __NETWORK_PACKET_H__
#define __NETWORK_PACKET_H__

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>     // isdigit()
#include <sys/param.h> // MIN() MAX()
#include <stdint.h>
#include <assert.h>

#include <util.h>

#define MAX_PACKET_SIZE 2048

namespace Network {

class Packet
{
public:
    Packet(unsigned short wCMD);
    Packet(unsigned int size);
    Packet(byte* body, unsigned int size);
    ~Packet();

    NetPacket* MakeNetPacket(unsigned short wCMD);

private:
    NetHeader* header;

    byte* body;
    unsigned int size;
    unsigned int offset;

public:
    inline void setCMD(unsigned short wCMD) {
        header->wCMD = wCMD;
    }
    inline unsigned short getCMD() {
        return header->wCMD;
    }

    byte* getOffsetPtr() const {
        return body + offset;
    }

    byte* getOffsetEndPtr() const {
        return body + size;
    }

    byte* getPtr() const {
        return body;
    }

    bool IsAvailable(unsigned int len) const {
        return (offset + len) <= size;
    }

    uint32_t getLength() const {
        return size;
    }

    bool			Read1(byte* d);
	bool			Read2(short* d);
	bool			Read4(int* d);
	bool			Read4(float* d);
	bool			Read8(int64_t* d);
	bool			Read8(double* d);
	uint32_t		ReadBin(byte* buf, uint32_t buf_len);
	uint32_t		ReadStr(byte* buf, uint32_t max_len);

	bool			Write1(byte d);
	bool			Write2(short d);
	bool			Write4(int d);
	bool			Write4(float d);
	bool			Write8(int64_t d);
	bool			Write8(double d);
	unsigned int	WriteBin(const byte* buf, uint32_t buf_len);
	unsigned int	WriteStr(const byte* str, uint32_t max_len);
};

} /* namespace Network */

#endif // __NETWORK_PACKET_H__