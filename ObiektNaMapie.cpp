//
// Created by Bartosz on 27.03.2017.
//

#include "ObiektNaMapie.h"

void  ObiektNaMapie::rysuj(sf::RenderTexture* cel) const {
    cel->draw(sprite);
}