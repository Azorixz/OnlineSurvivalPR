#include "ObiektKolizyjny.h"



ObiektKolizyjny::ObiektKolizyjny(int id, sf::Vector2f pozycja, float kat)
	:ObiektWyswietlany(id, pozycja, kat)
{	
}


ObiektKolizyjny::~ObiektKolizyjny()
{
}

float ObiektKolizyjny::iloczynSkalarny(sf::Vector2f &a, sf::Vector2f &b, sf::Vector2f &srodek){
	return (a.x - srodek.x)*(b.x - srodek.x) + (a.y - srodek.y)*(b.y - srodek.y);
}

sf::Vector2f ObiektKolizyjny::kolizjaKolaZpunktem(sf::Vector2f& punkt, sf::Vector2f& srodek, float& promien) {
	sf::Vector2f vOdleglosc =  srodek - punkt;
	float odleglosc = sqrt(vOdleglosc.x*vOdleglosc.x + vOdleglosc.y*vOdleglosc.y);
	float kolizja =  promien-odleglosc;
	if (kolizja > 0) {
		return vOdleglosc * kolizja / odleglosc;
	}
	else{
		return sf::Vector2f(0, 0);
	}
}
float ObiektKolizyjny::odlegloscPunktuOdLini(sf::Vector2f& linia1, sf::Vector2f linia2, sf::Vector2f punkt) {
	linia2 -= linia1;
	punkt -= linia1;
	float pole = punkt.x * linia2.y - punkt.y * linia2.x;
	return pole / sqrt(linia2.x*linia2.x + linia2.y*linia2.y);
}