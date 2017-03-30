//
// Created by Bartosz on 27.03.2017.
//

#include "ObiektNaMapie.h"

void  ObiektNaMapie::rysuj(sf::RenderTexture* cel) {
	sprite.setPosition(pozycja);
    cel->draw(sprite);
}

ObiektNaMapie::ObiektNaMapie(int id, float x, float y, sf::Texture* tekstura) {
	this->id = id;
	this->pozycja.x = x;
	this->pozycja.y = y;
	ustawTeksture(tekstura);
}

void ObiektNaMapie::ustawTeksture(sf::Texture* tekstura) {
	sprite.setTexture(*tekstura);
	sprite.setOrigin(tekstura->getSize().x / 2, tekstura->getSize().y / 2);
}