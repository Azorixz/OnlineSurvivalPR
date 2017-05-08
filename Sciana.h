#pragma once
#include "KolizyjnyProstokat.h"
class Sciana :public KolizyjnyProstokat 
{
public:
	virtual void akcjaNaKolizji(ObiektKolizyjny*);
	Sciana(int id, sf::Vector2f pozycja, sf::Vector2f wymiary, float kat);
	~Sciana();
};

