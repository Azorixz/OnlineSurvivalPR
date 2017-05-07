#pragma once

#include <SFML/Graphics.hpp>
#include <PlatMapy.h>


#include "ObiektNaMapie.h"
#include <unordered_map>

#define MAX_ROZMIAR_PLATA 500;
#define MIN_ROZMIAR_STREFY 25;


class Mapa {
public:
	// tymczasowa funkcja do przerobienia
	void dodajObiekt(ObiektNaMapie*);
	// tymczasowa funkcja
    void rysuj(sf::RenderWindow*);
    Mapa(sf::Vector2u, sf::Vector2u);
	~Mapa();
protected:
	int liczbaPlatowNaX;
	int liczbaPlatowNaY;
	// kamera wlascie
    sf::RenderTexture teksturaMapy;
    std::unordered_map<int, ObiektNaMapie*> obiekty;//tymczas
	PlatMapy*** platy;
};