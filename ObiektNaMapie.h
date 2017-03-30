//
// Created by Bartosz on 27.03.2017.
//

#pragma once

#include <SFML/Graphics.hpp>
#include<vector>


class ObiektNaMapie {
public:
     void rysuj(sf::RenderTexture*);
	 void ustawTeksture(sf::Texture*);

	// virtual void aktualizacja(float czas) = 0;
	 
	 // obudowanie funkcji sf::transformable
	 void obroc(float kat) { sprite.rotate(kat); };
	 // get i set
	 int getId() { return id;};

	 // konstruktory
	 ObiektNaMapie(int id, sf::Vector2f pozycja, sf::Texture* tekstura);
	 virtual ~ObiektNaMapie() {};
protected:
	int id;
    sf::Vector2f pozycja;
    sf::Sprite sprite;
};
