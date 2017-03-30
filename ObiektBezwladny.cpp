#include "ObiektBezwladny.h"
#include <cmath>


ObiektBezwladny::ObiektBezwladny(int id, sf::Vector2f pozycja, sf::Texture* tekstura,
		 float predkosc, float kierunek)
	:ObiektNaMapie(id, pozycja, tekstura)
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