//
// Created by Bartosz on 27.03.2017.
//

#include "Mapa.h"

void Mapa::rysuj(sf::RenderWindow* okno) {
    teksturaMapy.clear(sf::Color(255,0,0,255));
    std::unordered_map<int,ObiektNaMapie*>::iterator it;
    for(it = obiekty.begin(); it != obiekty.end(); ++it){

       it->second->rysuj(&teksturaMapy);

    }
    teksturaMapy.display();
    okno->draw(sf::Sprite(teksturaMapy.getTexture()));
}

Mapa::Mapa(sf::Vector2u rozmiarMapy, sf::Vector2u rozmiarKamery) {
    teksturaMapy.create(rozmiarKamery.x,rozmiarKamery.y);
	liczbaPlatowNaX = rozmiarMapy.x / MAX_ROZMIAR_PLATA + 1;
	liczbaPlatowNaY = rozmiarMapy.y / MAX_ROZMIAR_PLATA + 1;
	const float rozmiarPlataX = (float)rozmiarMapy.x / (float)liczbaPlatowNaX;
	const float rozmiarPlataY = (float)rozmiarMapy.y / (float)liczbaPlatowNaY;
	float x1, y1;
	x1 = 0;
	y1 = 0;
	platy = new PlatMapy**[liczbaPlatowNaX];
	for (int i = 0; i < liczbaPlatowNaX; i++) {
		platy[i] = new PlatMapy*[liczbaPlatowNaY];
		for (int j = 0; j < liczbaPlatowNaY; j++) {
			platy[i][j] = new PlatMapy(sf::Vector2f(x1,y1), sf::Vector2f(rozmiarPlataX, rozmiarPlataY));
			
			y1 += rozmiarPlataY;
		}
		x1 += rozmiarPlataX;
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
}

Mapa::~Mapa() {
	for (int i = 0; i < liczbaPlatowNaX; i++) {
		for (int j = 0; j < liczbaPlatowNaY; j++) {
			delete platy[i][j];
		}
		delete[] platy[i];
	}
	delete[] platy;
}


void Mapa::dodajObiekt(ObiektNaMapie* nowy) {
	obiekty.insert(std::pair<int,ObiektNaMapie*>(nowy->getId(), nowy));
}