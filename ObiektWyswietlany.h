//
// Created by Bartosz on 27.03.2017.
//

#pragma once

#include <SFML/Graphics.hpp>
#include<vector>
#include<mutex>
static int ostatnieId = 0;

class ObiektWyswietlany {
public:
     void rysuj(sf::RenderTexture*, sf::Vector2f);
	 void ustawTeksture(sf::Texture*);

	// virtual void aktualizacja(float czas) = 0;
	 
	 void przesun(sf::Vector2f);
	 void ustawPozycje(sf::Vector2f);
	 void obroc(float kat);
	 // get i set
	 int getId() { return id;};
	 sf::Vector2f getPozycja() { return pozycja; };
	 float getKat() { return kat; };
	 //zaladowanie domysnej tekstury

	 // konstruktory
	 ObiektWyswietlany(int id, sf::Vector2f pozycja, float kat);
	 virtual ~ObiektWyswietlany() {};

protected:
	int id;
private:
	std::mutex pozycja_mutex;
	sf::Vector2f pozycja; 
	sf::Sprite sprite;
	std::mutex kat_mutex;
	float kat;
};
