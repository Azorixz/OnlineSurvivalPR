//
// Created by Bartosz on 27.03.2017.
//

#include "ObiektWyswietlany.h"


void  ObiektWyswietlany::rysuj(sf::RenderTexture* cel, sf::Vector2f pozycjaKamery) {
	pozycja_mutex.lock();
	sprite.setPosition(pozycja - pozycjaKamery);
	pozycja_mutex.unlock();
	kat_mutex.lock();
	sprite.setRotation(kat);
	kat_mutex.unlock();
	cel->draw(sprite);
}
ObiektWyswietlany::ObiektWyswietlany(int id, sf::Vector2f pozycja, float kat) {
	this->id = id;
	this->pozycja = pozycja;
	this->kat = kat;
}

void ObiektWyswietlany::ustawTeksture(sf::Texture* tekstura) {
	sprite.setTexture(*tekstura);
	sprite.setOrigin(tekstura->getSize().x / 2.f, tekstura->getSize().y / 2.f);
}



void ObiektWyswietlany::obroc(float kat) {
	kat_mutex.lock();
	this->kat += kat;
	kat_mutex.unlock();
}

void ObiektWyswietlany::przesun(sf::Vector2f v) {
	pozycja_mutex.lock();
	pozycja += v;
	pozycja_mutex.unlock();
}

void ObiektWyswietlany::ustawPozycje(sf::Vector2f nowa) {
	pozycja_mutex.lock();
	pozycja = nowa;
	pozycja_mutex.unlock();
}