#include "KolizyjneKolo.h"
#include "KolizyjnyProstokat.h"



KolizyjneKolo::KolizyjneKolo(float promien, sf::Vector2f& pozycja)
	:ObiektKolizyjny(pozycja)
{
	this->promien = promien;
}


KolizyjneKolo::~KolizyjneKolo()
{
}

sf::Vector2f KolizyjneKolo::kolizja(sf::Vector2f przesuniecie, ObiektKolizyjny*  tenDrugi) {
	return tenDrugi->kolizja(przesuniecie, this);
}

sf::Vector2f KolizyjneKolo::kolizja(sf::Vector2f przesuniecie, KolizyjneKolo* tenPierwszy) {
	sf::Vector2f vOdleglosci = -this->pozycjaRef + tenPierwszy->pozycjaRef + przesuniecie;
	float odleglosc = sqrt(vOdleglosci.x*vOdleglosci.x + vOdleglosci.y * vOdleglosci.y);
	float kolizja = this->promien + tenPierwszy->promien - odleglosc;
	if (kolizja<0) {
		return sf::Vector2f(0, 0);
	}
	//zwracanie o ile trzeba sie cofnac
	return vOdleglosci * kolizja / odleglosc;
}

sf::Vector2f KolizyjneKolo::kolizja(sf::Vector2f przesuniecie, KolizyjnyProstokat* tenPierwszy) {
	
	return sf::Vector2f(0, 0);
}

bool KolizyjneKolo::czyKolizja(sf::Vector2f przesuniecie,ObiektKolizyjny* tenDrugi) {
	return tenDrugi->czyKolizja(przesuniecie, this);
}

bool KolizyjneKolo::czyKolizja(sf::Vector2f przesuniecie, KolizyjneKolo* tenPierwszy) {
	sf::Vector2f vOdleglosci = -this->pozycjaRef + tenPierwszy->pozycjaRef + przesuniecie;
	return sqrt(vOdleglosci.x*vOdleglosci.x + vOdleglosci.y * vOdleglosci.y) < this->promien + tenPierwszy->promien;
}

bool KolizyjneKolo::czyKolizja(sf::Vector2f przesuniecie, KolizyjnyProstokat* tenPierwszy) {
	return true;
}