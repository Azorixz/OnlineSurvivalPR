#include "Mapa.h"


PlatMapy::PlatMapy(sf::Vector2f pozycja, sf::Vector2f wymiary)
{
	czyAktywny = false;
	//pozycja na mapie, wzgledem swiata gry
	this->pozycjaNaMapie = pozycja; 
	//obliczenie koordynatow konca wzgledem swaiata 
	this->koniec = pozycja + wymiary;
	
	//stworzenie tekstury o podanych wymiarach
	//this->tekstura.create((int)wymiary.x, (int)wymiary.y);

	//obliczenie liczby stef w placie
	liczbaStrefNaX = (int)wymiary.x / MIN_ROZMIAR_STREFY;
	liczbaStrefNaY = (int)wymiary.y / MIN_ROZMIAR_STREFY;
	
	//obliczenie wymiarow strefy
	wymiaryStrefy = sf::Vector2f(wymiary.x / liczbaStrefNaX, wymiary.y / liczbaStrefNaY);

	//utworzenie stref
	strefy = new StrefaMapy**[liczbaStrefNaX];
	for (int i = 0; i < liczbaStrefNaX; i++) {
		strefy[i] = new StrefaMapy*[liczbaStrefNaY];
		for (int j = 0; j < liczbaStrefNaY; j++) {
			sf::Vector2f poczatekStrefy(wymiaryStrefy.x*i, wymiaryStrefy.y*j);
			strefy[i][j] = new StrefaMapy(poczatekStrefy, poczatekStrefy + wymiaryStrefy);
		}
	}
	for (int i = 0; i < 8; i++) {
		sasiedzi[i] = NULL;
	}
}


PlatMapy::~PlatMapy()
{
	for (int i = 0; i < liczbaStrefNaX; i++) {
		for (int j = 0; j < liczbaStrefNaY; j++) {
			delete strefy[i][j];
		}
		delete[] strefy[i];
	}
	delete[] strefy;
}

void PlatMapy::sprawdzKolizje() {
	for (int i = 0; i < liczbaStrefNaX; i++) {
		for (int j = 0; j < liczbaStrefNaY; j++) {
			strefy[i][j]->sprawdzKolizje();
		}
	}
}

void PlatMapy::dodajSasiada(Kierunek k, PlatMapy* s) {
	sasiedzi[k] = s;
}

void PlatMapy::dodajSasiadowStrefom() {
	for (int i = 0; i < liczbaStrefNaX; i++) {
		for (int j = 0; j < liczbaStrefNaY; j++) {

			if (i > 0) {
				strefy[i][j]->dodajSasiada(LEWO, strefy[i - 1][j]);
			}
			else if (sasiedzi[LEWO] != NULL) {
				strefy[i][j]->dodajSasiada(LEWO, sasiedzi[LEWO]->strefy[liczbaStrefNaX - 1][j]);
			}

			if (i > 0 && j > 0) {
				strefy[i][j]->dodajSasiada(LEWO_GORA, strefy[i - 1][j - 1]);
			}
			else if (sasiedzi[LEWO_GORA] != NULL) {
				strefy[i][j]->dodajSasiada(LEWO_GORA, sasiedzi[LEWO_GORA]->strefy[liczbaStrefNaX - 1][liczbaStrefNaY - 1]);
			}

			if (j > 0) {
				strefy[i][j]->dodajSasiada(GORA, strefy[i][j - 1]);
			}
			else if (sasiedzi[GORA] != NULL){
				strefy[i][j]->dodajSasiada(GORA, sasiedzi[GORA]->strefy[i][liczbaStrefNaY - 1]);
			}

			if (i < liczbaStrefNaX - 1 && j>0) {
				strefy[i][j]->dodajSasiada(PRAWO_GORA, strefy[i + 1][j - 1]);
			}
			else if (sasiedzi[PRAWO_GORA] != NULL) {
				strefy[i][j]->dodajSasiada(PRAWO_GORA, sasiedzi[PRAWO_GORA]->strefy[0][liczbaStrefNaY - 1]);
			}

			if (i < liczbaStrefNaX - 1) {
				strefy[i][j]->dodajSasiada(PRAWO, strefy[i + 1][j]);
			}
			else if (sasiedzi[PRAWO] != NULL) {
				strefy[i][j]->dodajSasiada(PRAWO, sasiedzi[PRAWO]->strefy[0][j]);
			}

			if (i < liczbaStrefNaX - 1 && j < liczbaStrefNaY - 1) {
				strefy[i][j]->dodajSasiada(PRAWO_DOL, strefy[i + 1][j + 1]);
			}
			else if (sasiedzi[PRAWO_DOL] != NULL) {
				strefy[i][j]->dodajSasiada(PRAWO_DOL, sasiedzi[PRAWO_DOL]->strefy[0][0]);
			}

			if (j < liczbaStrefNaY - 1) {
				strefy[i][j]->dodajSasiada(DOL, strefy[i][j + 1]);
			}
			else if (sasiedzi[DOL] != NULL) {
				strefy[i][j]->dodajSasiada(DOL, sasiedzi[DOL]->strefy[i][0]);
			}

			if (i > 0 && j < liczbaStrefNaY - 1) {
				strefy[i][j]->dodajSasiada(LEWO_DOL, strefy[i - 1][j + 1]);
			}
			else if (sasiedzi[LEWO_DOL] != NULL) {
				strefy[i][j]->dodajSasiada(LEWO_DOL, sasiedzi[LEWO_DOL]->strefy[liczbaStrefNaX-1][0]);
			}
		}
	}
}


void PlatMapy::dodajObiektAktywny(ObiektKolizyjny* nowy) {
	sf::Vector2f pozycja = nowy->getPozycja();
	int x = (int)(pozycja.x / wymiaryStrefy.x);
	int y = (int)(pozycja.y / wymiaryStrefy.y);
	if (x >= liczbaStrefNaX) x = liczbaStrefNaX - 1;
	if (y >= liczbaStrefNaY) y = liczbaStrefNaY - 1;
	strefy[x][y]->dodajObiektAktywny(nowy);
}

void PlatMapy::dodajObiektStatyczny(ObiektKolizyjny* nowy) {
	sf::Vector2f pozycja = nowy->getPozycja();
	int x = (int)(pozycja.x / wymiaryStrefy.x);
	int y = (int)(pozycja.y / wymiaryStrefy.y);
	if (x >= liczbaStrefNaX) x = liczbaStrefNaX - 1;
	if (y >= liczbaStrefNaY) y = liczbaStrefNaY - 1;
	strefy[x][y]->dodajObiektStatyczny(nowy);
}
void PlatMapy::rysuj(sf::RenderTexture* tekstura, sf::Vector2f pozycjaKamery) {
	if (!czyAktywny)return;
	for (int i = 0; i < liczbaStrefNaX; i++) {
		for (int j = 0; j < liczbaStrefNaY; j++) {
			strefy[i][j]->rysuj(tekstura, pozycjaKamery);
		}
	}

}