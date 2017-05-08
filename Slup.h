#pragma once
#include "KolizyjneKolo.h"
class Slup:public KolizyjneKolo
{
public:
	Slup(int id, sf::Vector2f pozycja, float promien, float kat);
	~Slup();
	virtual void akcjaNaKolizji(ObiektKolizyjny*);
};

