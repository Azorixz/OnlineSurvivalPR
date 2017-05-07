#include "Socket.h"
Socket::Socket() {

}

Socket::~Socket() {

}

bool Socket::Open(unsigned short port) {
	this->handle = socket(AF_INET,
		SOCK_DGRAM,
		IPPROTO_UDP);	
	if (this->handle <= 0) {
		printf("failed to create socket\n");
		return false;
	}
	sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);
	if (bind((SOCKET) this->handle,
		(const sockaddr *)&address,
		sizeof(sockaddr_in)) < 0) {
		printf("failed to bind socket\n");
		return false;
	}
	DWORD nonBlocking = 1;
	if (ioctlsocket((SOCKET) this->handle,
		FIONBIO,
		&nonBlocking) != 0) {
		printf("failed to set non-blocking\n");
		return false;
	}
	return true;
}

void Socket::Close() {
	closesocket((SOCKET) this->handle);
}

bool Socket::ISOpen() const {
	return this->handle > 0;
}

bool Socket::Send(const Address &destination,
					const void *data,
					int size) {
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(destination.GetAddress());
	addr.sin_port = htons(destination.GetPort());	
	int sent_bytes = sendto((SOCKET)this->handle,
		(const char*)data,
		size,
		0,
		(sockaddr*)&addr,
		sizeof(sockaddr_in));
	if (sent_bytes != size)
	{
		printf("failed to send packet\n");
		return false;
	}
	return true;
}

int Socket::Receive(Address &sender, void *data, int size) {
	
		typedef int socklen_t;
		sockaddr_in from;
		socklen_t fromLength = sizeof(from);
		int bytes = recvfrom((SOCKET)this->handle,
			(char*)data,
			size,
			0,
			(sockaddr*)&from,
			&fromLength);
		unsigned int from_address =
			ntohl(from.sin_addr.s_addr);
		unsigned int from_port =
			ntohs(from.sin_port);
	
		sender = Address(from_address, from_port);
	return bytes;
}