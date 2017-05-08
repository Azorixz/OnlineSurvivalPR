#pragma once
#include "Sciana.h"

#define BOK_X 150
#define BOK_Y 100

class Prostokat : public Sciana
{
public:
	Prostokat(int id, sf::Vector2f pozycja, float kat);
	virtual ~Prostokat();
	static void ustawTekstureProstokata();
	static sf::Texture teksturaProstokata;
private:
	
};

