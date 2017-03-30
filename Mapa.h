//
// Created by Bartosz on 27.03.2017.
//
#include <SFML/Graphics.hpp>
#include "ObiektNaMapie.h"
#include <unordered_map>


#ifndef ONLINESURVIVAL_MAPA_H
#define ONLINESURVIVAL_MAPA_H



class Mapa {
public:
	void dodajObiekt(ObiektNaMapie*);
    void rysuj(sf::RenderWindow*);
    Mapa(float, float);
protected:
    sf::RenderTexture teksturaMapy;
    std::unordered_map<int, ObiektNaMapie*> obiekty;
};


#endif //ONLINESURVIVAL_MAPA_H
