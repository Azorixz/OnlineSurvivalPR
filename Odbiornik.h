#pragma once

#include <Socket.h>
#include <thread>
class Odbiornik
{
public:
	Odbiornik();
	~Odbiornik();
	void DodajAdres(Address);
	void nasluchuj();
	
private:
	volatile bool nasluchiwanie;
};

