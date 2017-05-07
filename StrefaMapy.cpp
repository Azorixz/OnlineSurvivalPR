#include "Mapa.h"



StrefaMapy::StrefaMapy(sf::Vector2f start, sf::Vector2f koniec)
{
	this->start = start;
	this->koniec = koniec;
}


StrefaMapy::~StrefaMapy()
{

}

void StrefaMapy::dodajSasiada(Kierunek k, StrefaMapy* s) {
	sasiedzi[k] = s;
}
