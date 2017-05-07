//
// Created by Bartosz on 27.03.2017.
//

#include "ObiektNaMapie.h"



void  ObiektNaMapie::rysuj(sf::RenderTexture* cel) {
	sprite.setPosition(pozycja);
    cel->draw(sprite);
}
ObiektNaMapie::ObiektNaMapie(int id, sf::Vector2f pozycja, sf::Texture* tekstura) {
	this->id = id;
	this->pozycja = pozycja;
	ustawTeksture(tekstura);
}

void ObiektNaMapie::ustawTeksture(sf::Texture* tekstura) {
	sprite.setTexture(*tekstura);
	sprite.setOrigin(tekstura->getSize().x / 2.f, tekstura->getSize().y / 2.f);
}