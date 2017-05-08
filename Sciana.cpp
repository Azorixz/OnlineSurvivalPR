#include "Sciana.h"



Sciana::Sciana(int id, sf::Vector2f pozycja, sf::Vector2f wymiary,float kat)
	:KolizyjnyProstokat(id, pozycja, wymiary, kat)
{
}


Sciana::~Sciana()
{
}

void Sciana::akcjaNaKolizji(ObiektKolizyjny* kolidujacy) {
	kolidujacy->przesun(-kolidujacy->kolizja(sf::Vector2f(0,0),this));
}