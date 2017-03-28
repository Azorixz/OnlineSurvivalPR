//
// Created by Bartosz on 27.03.2017.
//
#include <SFML/Graphics.hpp>
#include "ObiektNaMapie.h"
#include <set>


#ifndef ONLINESURVIVAL_MAPA_H
#define ONLINESURVIVAL_MAPA_H

#define ROZMIARSTREFY 50;

class Mapa {
public:
    void rysuj(sf::RenderWindow*);
    Mapa(float, float);
protected:
    sf::RenderTexture teksturaMapy;
    std::set<ObiektNaMapie> obiekty;
};


#endif //ONLINESURVIVAL_MAPA_H
