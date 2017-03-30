//
// Created by Bartosz on 27.03.2017.
//

#ifndef ONLINESURVIVAL_OBIEKTNAMAPIE_H
#define ONLINESURVIVAL_OBIEKTNAMAPIE_H

#include <SFML/Graphics.hpp>




class ObiektNaMapie {
public:
     void rysuj(sf::RenderTexture*);
	 void ustawTeksture(sf::Texture*);
	 // obudowanie funkcji sf::transformable
	 void obroc(float kat) { sprite.rotate(kat); };
	 // get i set
	 int getId() { return id;};

	 // konstruktory
	 ObiektNaMapie(int, float, float, sf::Texture*);
	 virtual ~ObiektNaMapie() {};
protected:
	int id;
    sf::Vector2f pozycja;
    sf::Sprite sprite;
};


#endif //ONLINESURVIVAL_OBIEKTNAMAPIE_H
