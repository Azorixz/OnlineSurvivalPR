#include "Slup.h"


Slup::Slup(int id, sf::Vector2f pozycja, float promien, float kat)
	:KolizyjneKolo(id, pozycja, promien, kat)
{
}

Slup::~Slup()
{
}

void Slup::akcjaNaKolizji(ObiektKolizyjny* kolidujacy) {
	kolidujacy->przesun(-kolidujacy->kolizja(sf::Vector2f(0, 0), this));
}