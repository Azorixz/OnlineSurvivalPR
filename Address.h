#pragma once
class Address
{
public:
	Address();
	Address(unsigned char a,
		unsigned char b, 
		unsigned char c, 
		unsigned char d,
		unsigned short port);
	Address(unsigned int address, 
		unsigned short port);
	unsigned int GetAddress() const;	
	unsigned short GetPort() const;
private:
	unsigned int address;
	unsigned short port;
};