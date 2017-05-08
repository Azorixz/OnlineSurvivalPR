//
// Created by Bartosz on 27.03.2017.
//

#include "Mapa.h"

void Mapa::uruchomSprawdzanieKolizji(int liczbaWatkow) {
	if (liczbaWatkow == 0)return;
	int liczbaPlatow = liczbaPlatowNaX*liczbaPlatowNaY;
	int odstep = liczbaPlatow / liczbaWatkow;
	sprawdzanieKolizji = true;
	for (int i = 0; i < liczbaWatkow; i++) {
		watkiSprawdzaniaKolizji.push_back(std::thread(&Mapa::watekSprawdzaniaKolizji,
									this,
									sf::Vector2i((i*odstep)%liczbaPlatowNaX,
												 (i*odstep)/liczbaPlatowNaX)));
	}
	
}

void Mapa::watekSprawdzaniaKolizji(sf::Vector2i start) {
	while (sprawdzanieKolizji)
	{
		for (int i = start.x; i < liczbaPlatowNaX; i++) {
			for (int j = start.y; j < liczbaPlatowNaY; j++) {
				platy[i][j]->sprawdzKolizje();
			}
		}
	}
}
void Mapa::rysuj(sf::RenderWindow* okno) {
    teksturaMapy.clear(sf::Color(255,0,0,255));
	pozycjaKamery_mutex.lock();
	for (int i = 0; i < liczbaPlatowNaX; i++) {
		for (int j = 0; j < liczbaPlatowNaY; j++) {
			platy[i][j]->rysuj(&teksturaMapy, pozycjaKamery);
		}
	}
	pozycjaKamery_mutex.unlock();
    teksturaMapy.display();
    okno->draw(sf::Sprite(teksturaMapy.getTexture()));
}

Mapa::Mapa(sf::Vector2u rozmiarMapy, sf::Vector2u rozmiarKamery) {
	pozycjaKamery = sf::Vector2f(0, 0);
	teksturaMapy.create(rozmiarKamery.x,rozmiarKamery.y);
	liczbaPlatowNaX = rozmiarMapy.x / MAX_ROZMIAR_PLATA + 1;
	liczbaPlatowNaY = rozmiarMapy.y / MAX_ROZMIAR_PLATA + 1;
	wymiaryPlata.x = (float)rozmiarMapy.x / (float)liczbaPlatowNaX;
	wymiaryPlata.y = (float)rozmiarMapy.y / (float)liczbaPlatowNaY;
	float x1, y1;
	x1 = 0;
	y1 = 0;
	platy = new PlatMapy**[liczbaPlatowNaX];
	for (int i = 0; i < liczbaPlatowNaX; i++) {
		platy[i] = new PlatMapy*[liczbaPlatowNaY];
		for (int j = 0; j < liczbaPlatowNaY; j++) {
			platy[i][j] = new PlatMapy(sf::Vector2f(x1,y1), sf::Vector2f(wymiaryPlata.x, wymiaryPlata.y));
			
			y1 += wymiaryPlata.y;
		}
		x1 += wymiaryPlata.x;
		y1 = 0;
	}
	for (int i = 0; i < liczbaPlatowNaX; i++) {
		for (int j = 0; j < liczbaPlatowNaY; j++) {
			if (i > 0) {
				platy[i][j]->dodajSasiada(LEWO, platy[i - 1][j]);
			}
			if (i > 0 && j > 0) {
				platy[i][j]->dodajSasiada(LEWO_GORA, platy[i - 1][j - 1]);
			}
			if (j > 0) {
				platy[i][j]->dodajSasiada(GORA, platy[i][j - 1]);
			}
			if (i < liczbaPlatowNaX - 1 && j>0) {
				platy[i][j]->dodajSasiada(PRAWO_GORA, platy[i + 1][j - 1]);
			}
			if (i < liczbaPlatowNaX - 1) {
				platy[i][j]->dodajSasiada(PRAWO, platy[i + 1][j]);
			}
			if (i < liczbaPlatowNaX - 1 && j < liczbaPlatowNaY - 1) {
				platy[i][j]->dodajSasiada(PRAWO_DOL, platy[i + 1][j + 1]);
			}
			if (j < liczbaPlatowNaY - 1) {
				platy[i][j]->dodajSasiada(DOL, platy[i][j + 1]);
			}
			if (i > 0 && j < liczbaPlatowNaY - 1) {
				platy[i][j]->dodajSasiada(LEWO_DOL, platy[i - 1][j + 1]);
			}
		}
	}

	for (int i = 0; i < liczbaPlatowNaX; i++) {
		for (int j = 0; j < liczbaPlatowNaY; j++) {
			platy[i][j]->dodajSasiadowStrefom();
		}
	}

	for (int i = 0; i < liczbaPlatowNaX; i++) {
		for (int j = 0; j < liczbaPlatowNaY; j++) {
			if (rozmiarKamery.y < wymiaryPlata.y*(j -1))
				break;
			platy[i][j]->aktywuj();
		}
		if (rozmiarKamery.x < wymiaryPlata.x*(i - 1))
			break;
	}
}

Mapa::~Mapa() {
	sprawdzanieKolizji = false;
	for (int i = 0; i < watkiSprawdzaniaKolizji.size(); i++) {
		watkiSprawdzaniaKolizji[i].join();
	}
	for (int i = 0; i < liczbaPlatowNaX; i++) {
		for (int j = 0; j < liczbaPlatowNaY; j++) {
			delete platy[i][j];
		}
		delete[] platy[i];
	}
	delete[] platy;
}

void Mapa::dodajObiektAktywny(ObiektKolizyjny* nowy) {
	sf::Vector2f pozycja = nowy->getPozycja();
	int x = (int)(pozycja.x / wymiaryPlata.x);
	int y = (int)(pozycja.y / wymiaryPlata.y);
	if (x >= liczbaPlatowNaX) x = liczbaPlatowNaX - 1;
	if (y >= liczbaPlatowNaY) y = liczbaPlatowNaY - 1;
	platy[x][y]->dodajObiektAktywny(nowy);
}

void Mapa::dodajObiektStatyczny(ObiektKolizyjny* nowy) {
	sf::Vector2f pozycja = nowy->getPozycja();
	int x = (int)(pozycja.x / wymiaryPlata.x);
	int y = (int)(pozycja.y / wymiaryPlata.y);
	if (x >= liczbaPlatowNaX) x = liczbaPlatowNaX - 1;
	if (y >= liczbaPlatowNaY) y = liczbaPlatowNaY - 1;
	platy[x][y]->dodajObiektStatyczny(nowy);
}

void Mapa::przesunKamere(sf::Vector2f v) {
	pozycjaKamery_mutex.lock();
	pozycjaKamery += v;
	pozycjaKamery_mutex.unlock();
}