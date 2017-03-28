//
// Created by Bartosz on 27.03.2017.
//

#include "Mapa.h"

void Mapa::rysuj(sf::RenderWindow* okno) {
    teksturaMapy.clear(sf::Color(255,0,0,255));
    std::set<ObiektNaMapie>::iterator it;
    for(it = obiekty.begin(); it != obiekty.end(); ++it){

        it->rysuj(&teksturaMapy);

    }
    teksturaMapy.display();
    okno->draw(sf::Sprite(teksturaMapy.getTexture()));
}

Mapa::Mapa(float x, float y) {
    teksturaMapy.create(x,y);
}
