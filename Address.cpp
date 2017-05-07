#include "Address.h"



Address::Address()
{
	this->address = 0;
	this->port = 0;
}

Address::Address(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned short port)
{
	this->address = (a << 24) |
		(b << 16) |
		(c << 8) |
		d;
	this->port = port;
}

Address::Address(unsigned int address, unsigned short port)
{
	this->address = address;
	this->port = port;
}

unsigned int Address::GetAddress() const
{
	return this->address;
}

unsigned short Address::GetPort() const
{
	return this->port;
}

