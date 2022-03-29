#ifndef __COMDEF_H__
#define __COMDEF_H__

#include <Logger.h>

#include <stdio.h>

typedef unsigned char byte;

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
} __attribute__ ((packed)) NetHeader;

typedef struct tagNetPacket
{
    NetHeader			header;
    byte                *body;
    uint                bodyLen;
} __attribute__ ((packed)) NetPacket;

#endif // __COMDEF_H__