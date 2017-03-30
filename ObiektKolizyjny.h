#pragma once
#include <SFML\System\Vector2.hpp>
#include <vector>
class ObiektKolizyjny
{
public:
	ObiektKolizyjny( sf::Vector2f& pozycja );
	~ObiektKolizyjny();
protected:
	sf::Vector2f& pozycjaRef;
	std::vector<sf::Vector2f>* ksztalt;
};