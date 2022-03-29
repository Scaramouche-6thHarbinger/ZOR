#ifndef __ENCRYPTION_H__
#define __ENCRYPTION_H__

#include <Protocol.h>
#include <Singleton.h>
#include <util.h>
#include <Packet.h>

#include <algorithm>
#include <vector>

#include <stdint.h>
#include <string.h>

const int s_count = sizeof(NOTENCODECMDS) / sizeof(int);
const std::vector<int> s_cmds(NOTENCODECMDS, NOTENCODECMDS+s_count);

class Encryption : public Singleton<Encryption>
{
public:
    Encryption() : _key1(0), _key2(0), _key3(0), _key4(0) {}
	~Encryption() {}

public:
    void MakeKey()
	{
		uint16_t array[2] = {0,};
		array[0] = 0x5555;
		array[1] = 0x5555;
		_key1 = * ( (int *)(& array[0]));
		_key2 = * ( (int *)(& array[0]));
		_key3 = * ( (int *)(& array[0]));
		_key4 = * ( (int *)(& array[0]));

		_key1 |= 0x1234;
		_key2 |= 0x5678;
		_key3 |= 0x8765;
		_key4 |= 0x4321;
	}

    int GetKey() { return _key1; }
	int GetKey1() { return _key2; }
	int GetKey2() { return _key3; }
	int GetKey3() { return _key4; }

	void Decrypt_First(::Network::Packet * pPacket)
	{
		char public_key[] = "ZenoniaOnline";
		int public_key_len = strlen(public_key);

		if( public_key_len >= 17 )
			public_key_len = 16;

		unsigned char * pArray = reinterpret_cast<unsigned char *>(pPacket->getPtr());

		for (int i = 0; i < (int)pPacket->getLength(); ++i)
		{
			pArray[i] ^= public_key[i % public_key_len];
		}
	}

	void Encrypt_First(unsigned char *social_id, int len, ::Network::Packet * pPacket)
	{
		if( len >= 17 )
			len = 16;

		unsigned char * pArray = reinterpret_cast<unsigned char *>(pPacket->getPtr());

		for (int i = 0; i < (int)pPacket->getLength(); ++i)
		{
			pArray[i] ^= social_id[i % len];
		}
	}
private:
	int _key1;
	int _key2;
	int _key3;
	int _key4;
};

#endif // __ENCRYPTION_H__