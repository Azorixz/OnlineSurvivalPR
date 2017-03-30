#pragma once

#include <SFML/Graphics.hpp>
#include "ObiektNaMapie.h"
#include <unordered_map>




class Mapa {
public:
	void dodajObiekt(ObiektNaMapie*);
    void rysuj(sf::RenderWindow*);
    Mapa(float, float);
protected:
    sf::RenderTexture teksturaMapy;
    std::unordered_map<int, ObiektNaMapie*> obiekty;
};
