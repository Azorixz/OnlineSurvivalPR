#pragma once
#include <unordered_map>
#include <ObiektNaMapie.h>
enum Kierunek { GORA = 0, PRAWO_GORA = 1, PRAWO = 2, PRAWO_DOL = 3, DOL = 4, LEWO_DOL = 5, LEWO = 6, LEWO_GORA = 7 };
class StrefaMapy
{
public:
	StrefaMapy(sf::Vector2f start, sf::Vector2f koniec);
	~StrefaMapy();
	void dodajSasiada(Kierunek k, StrefaMapy* s);

private:
	//sasiednie strefy dla szybszego dostepu rowniez w innych platach
	StrefaMapy* sasiedzi[8];
	//koordynaty poczatku strefy wzgledem swiata gry
	sf::Vector2f start;
	//koordynaty konca strefy wzgledem swiata gry
	sf::Vector2f koniec;
	//obiekty zawarte w stefie
	//w przyszlosci podzial na kilka zbiorow
	std::unordered_map <int, ObiektNaMapie*> obiektyWstrefie;
};