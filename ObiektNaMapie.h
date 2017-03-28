//
// Created by Bartosz on 27.03.2017.
//

#ifndef ONLINESURVIVAL_OBIEKTNAMAPIE_H
#define ONLINESURVIVAL_OBIEKTNAMAPIE_H

#include <SFML/Graphics.hpp>




class ObiektNaMapie {
public:
     void rysuj(sf::RenderTexture*) const;
protected:
    sf::Vector2f pozycja;
    sf::Sprite sprite;
};


#endif //ONLINESURVIVAL_OBIEKTNAMAPIE_H
