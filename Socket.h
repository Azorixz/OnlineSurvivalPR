#pragma once
#pragma comment( lib, "Ws2_32.lib" )
#include "Address.h"
#include <winsock2.h>
#include <Windows.h>
#include <cstdio>



class Socket {
public:
	Socket();

	~Socket();

	bool Open(unsigned short port);

	void Close();

	bool ISOpen() const;

	bool Send(const Address &destination,
		const void *data,
		int size);

	int Receive(Address &sender,
		void *data,
		int size);

private:
	int handle;
};