#include "KolizyjnyProstokat.h"
#include "KolizyjneKolo.h"

KolizyjnyProstokat::KolizyjnyProstokat(sf::Vector2f wymiary, float kat, sf::Vector2f &pozycja)
	:ObiektKolizyjny(pozycja)
{
	wymiary.x /= 2;
	wymiary.y /= 2;
	wierzcholki[0] = pozycja + sf::Vector2f(-wymiary.x, -wymiary.y);
	wierzcholki[1] = pozycja + sf::Vector2f(wymiary.x, -wymiary.y);
	wierzcholki[2] = pozycja + sf::Vector2f(wymiary.x, wymiary.y);
	wierzcholki[3] = pozycja + sf::Vector2f(-wymiary.x, wymiary.y);
}


KolizyjnyProstokat::~KolizyjnyProstokat()
{

}

sf::Vector2f KolizyjnyProstokat::kolizja(sf::Vector2f przesuniecie, ObiektKolizyjny* tenDrugi) {
	return tenDrugi->kolizja(przesuniecie, this);
}

sf::Vector2f KolizyjnyProstokat::kolizja(sf::Vector2f przesuniecie, KolizyjneKolo* tenPierwszy) {
	sf::Vector2f nowaPozycja = tenPierwszy->pozycjaRef +przesuniecie;

	if (iloczynSkalarny(nowaPozycja,wierzcholki[3], wierzcholki[0]) < 0) {
		//srodek kola wzglednie ponad
		if (iloczynSkalarny(nowaPozycja, wierzcholki[0], wierzcholki[1]) < 0) {
			//1cwiartka poza
			return kolizjaKolaZpunktem(wierzcholki[1], nowaPozycja, tenPierwszy->promien);
		}
		else if (iloczynSkalarny(nowaPozycja, wierzcholki[1], wierzcholki[0]) < 0){
			//4cwiartka poza
			return kolizjaKolaZpunktem(wierzcholki[0], nowaPozycja, tenPierwszy->promien);
		}
		else {
			//dokladnie ponad
			float odl = odlegloscPunktuOdLini(wierzcholki[0], wierzcholki[1], nowaPozycja);
			if (odl > tenPierwszy->promien) {
				return sf::Vector2f(0, 0);
			}
			else {
				return sf::Vector2f(0, odl-tenPierwszy->promien);
			}
		}
	}
	else if ( iloczynSkalarny(nowaPozycja, wierzcholki[2], wierzcholki[3]) <0)
	{
		// wzglednie lewo

		if (iloczynSkalarny(nowaPozycja, wierzcholki[0], wierzcholki[3]) < 0) {
			// 3cwiartka poza
			return kolizjaKolaZpunktem(wierzcholki[3], nowaPozycja, tenPierwszy->promien);
		}
		else {
			// dokladnie lewo
			float odl = -odlegloscPunktuOdLini(wierzcholki[0], wierzcholki[3], nowaPozycja);
			if (odl > tenPierwszy->promien) {
				return sf::Vector2f(0, 0);
			}
			else {
				return sf::Vector2f( odl-tenPierwszy->promien, 0);
			}
		}
	}
	else if (iloczynSkalarny(nowaPozycja, wierzcholki[0], wierzcholki[3]) < 0) {
		//wzglednie w dol

		if (iloczynSkalarny(nowaPozycja, wierzcholki[3], wierzcholki[2]) < 0) {
			//2cwiartka poza
			return kolizjaKolaZpunktem(wierzcholki[2], nowaPozycja, tenPierwszy->promien);
		}
		else {
			//dokladnie dol
			float odl = odlegloscPunktuOdLini(wierzcholki[2], wierzcholki[3], nowaPozycja);
			if (odl > tenPierwszy->promien) {
				return sf::Vector2f(0, 0);
			}
			else {
				return sf::Vector2f(0, tenPierwszy->promien - odl);
			}
		}
	}
	else {
		//dokladnie prawo
		float odl = odlegloscPunktuOdLini(wierzcholki[1], wierzcholki[2], nowaPozycja);
		if (odl > tenPierwszy->promien) {
			return sf::Vector2f(0, 0);
		}
		else {
			return sf::Vector2f(tenPierwszy->promien - odl,0);
		}
	}
}

sf::Vector2f KolizyjnyProstokat::kolizja(sf::Vector2f przesuniecie, KolizyjnyProstokat* tenPierwszy) {
	return sf::Vector2f(0, 0);
}

bool KolizyjnyProstokat::czyKolizja(sf::Vector2f a, ObiektKolizyjny*) {
	return true;
}
bool KolizyjnyProstokat::czyKolizja(sf::Vector2f a, KolizyjnyProstokat*) {
	return true;
}
bool KolizyjnyProstokat::czyKolizja(sf::Vector2f a, KolizyjneKolo*) {
	return true;
}