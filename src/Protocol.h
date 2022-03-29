#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_

#define 	CMD_CS_PING 				0x0201
#define 	CMD_CS_CONNECT				0x0202
#define 	CMD_SC_CONNECT				0x0203
#define 	CMD_CS_RECONNECT			0x0204
#define 	CMD_SC_RECONNECT			0x0205
#define     CMD_CS_REQ_SERVER_ADDR		0x0206
#define     CMD_SC_REQ_SERVER_ADDR		0x0207

const int NOTENCODECMDS[] = {

		// normal
		CMD_CS_PING,

		CMD_CS_RECONNECT,
		CMD_SC_RECONNECT,
};

#endif // _PROTOCOL_H_