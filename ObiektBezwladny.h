#pragma once
#include "ObiektNaMapie.h"
#include "ObiektKolizyjny.h"
class ObiektBezwladny :
	public ObiektNaMapie 
{
public:
	void aktualizacja(int);
	//konstruktor
	ObiektBezwladny(int id, sf::Vector2f pozycja, sf::Texture* tekstura, float predkosc, float kierunek);
	virtual ~ObiektBezwladny();
protected:
	float kierunek;
	float predkosc;

};

