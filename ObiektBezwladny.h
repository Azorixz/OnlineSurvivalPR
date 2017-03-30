#pragma once
#include "E:\PR\Survival\OnlineSurvivalPR\ObiektNaMapie.h"
class ObiektBezwladny :
	public ObiektNaMapie
{
public:
	void aktualizacja(int);
	//konstruktor
	ObiektBezwladny(int, float, float, sf::Texture*, float, float);
	virtual ~ObiektBezwladny();
protected:
	float kierunek;
	float predkosc;

};

