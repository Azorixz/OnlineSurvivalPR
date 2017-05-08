#pragma once
#include "KolizyjneKolo.h"
class TestowyLudzikSerwerowy : public KolizyjneKolo
{
public:
	TestowyLudzikSerwerowy(int id, sf::Vector2f pozycja, float kat);
	~TestowyLudzikSerwerowy();
	static void zaladujLudzika();
	void akcjaNaKolizji(ObiektKolizyjny*) {};
private:
	static sf::Texture teksturaLudzika;
};

