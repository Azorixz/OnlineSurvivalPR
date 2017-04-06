#pragma once
#include "ObiektKolizyjny.h"
class KolizyjnyProstokat :
	public ObiektKolizyjny
{
public:
	sf::Vector2f kolizja(sf::Vector2f, ObiektKolizyjny*);
	sf::Vector2f kolizja(sf::Vector2f, KolizyjneKolo*);
	sf::Vector2f kolizja(sf::Vector2f, KolizyjnyProstokat*);
	bool czyKolizja(sf::Vector2f, ObiektKolizyjny*);
	bool czyKolizja(sf::Vector2f, KolizyjneKolo*);
	bool czyKolizja(sf::Vector2f, KolizyjnyProstokat*);

	KolizyjnyProstokat(sf::Vector2f wymiary, float kat, sf::Vector2f& pozycja);
	virtual ~KolizyjnyProstokat();
private:
	friend class KolizyjneKolo;
	sf::Vector2f wierzcholki[4];
};

