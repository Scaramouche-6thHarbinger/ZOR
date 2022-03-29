#ifndef __COMDEF_H__
#define __COMDEF_H__

#include <ByteArray.h>
#include <Logger.h>

#include <stdio.h>

typedef struct tagNetHeader
{
	unsigned char		byStartFlag;     // 0xFF
	unsigned short		wLen;            // body len + 3
	unsigned char		byReserve;
	unsigned short		wCMD;            // cmd

public:
	bool				isValid() { return (byStartFlag == 0xFF); }
	unsigned short		getCMD(void) { return wCMD; }
	unsigned short		getLength(void) { return wLen; }
	byte*				getBytes(void) {
		byte *p = new byte[6];
		p[0] = byStartFlag;
		LOGW("wlen=%d", wLen);
		ByteArray::SetUInt16(p, 1, wLen);
		p[3] = byReserve;
		LOGW("wcmd=%d", wCMD);
		ByteArray::SetUInt16(p, 4, wCMD);
		return p;
	}
} __attribute__ ((packed)) NetHeader;

typedef struct tagNetPacket
{
    NetHeader			header;
    byte                *body;
    uint                bodyLen;
} __attribute__ ((packed)) NetPacket;



#endif // __COMDEF_H__