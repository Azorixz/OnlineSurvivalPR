#pragma once
#include "ObiektKolizyjny.h"
class KolizyjneKolo :
	public ObiektKolizyjny
{
public:
	sf::Vector2f kolizja(sf::Vector2f, ObiektKolizyjny*);
	sf::Vector2f kolizja(sf::Vector2f, KolizyjneKolo*);
	sf::Vector2f kolizja(sf::Vector2f, KolizyjnyProstokat*);
	bool czyKolizja(sf::Vector2f, ObiektKolizyjny*);
	bool czyKolizja(sf::Vector2f, KolizyjneKolo*);
	bool czyKolizja(sf::Vector2f, KolizyjnyProstokat*);
	//konstruktory
	KolizyjneKolo(float promien, sf::Vector2f& pozycja);
	virtual ~KolizyjneKolo();
private:
	friend class KolizyjnyProstokat;
	float promien;
};