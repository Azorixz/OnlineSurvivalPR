#include "Odbiornik.h"

void Odbiornik::nasluchuj() {
	Address adres;
	Socket port;
	while (nasluchiwanie)
	{
		Beep(500, 200);
	}
}

Odbiornik::Odbiornik()
{
	nasluchiwanie = true;
	std::thread odbiornik([this] {nasluchuj(); });
	odbiornik.detach();
}



Odbiornik::~Odbiornik()
{
	nasluchiwanie = false;
	Sleep(1000);
}
