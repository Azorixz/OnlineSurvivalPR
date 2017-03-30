#include "ObiektBezwladny.h"
#include <cmath>


ObiektBezwladny::ObiektBezwladny(int id, float x, float y, sf::Texture* tekstura,
		float predkosc, float kierunek)
	:ObiektNaMapie(id, x, y, tekstura)
{
	this->predkosc = predkosc;
	this->kierunek = kierunek;
}


ObiektBezwladny::~ObiektBezwladny()
{
}

void ObiektBezwladny::aktualizacja(int czas) {
	pozycja.x += cos(kierunek) * predkosc * czas;
	pozycja.y += sin(kierunek) * predkosc * czas;
}