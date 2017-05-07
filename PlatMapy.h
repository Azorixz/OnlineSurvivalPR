#pragma once
#include <StrefaMapy.h>
#include <SFML\Graphics.hpp>

class PlatMapy
//obszar mapy ladowany gdy gracze sa w okolicy
{
public:
	PlatMapy(sf::Vector2f pozycja, sf::Vector2f wymiary);
	~PlatMapy();
	void dodajSasiada(Kierunek, PlatMapy*);
	void dodajSasiadowStrefom();
private:
	int liczbaStrefNaX;
	int liczbaStrefNaY;
	//tekstura na ktorej sa rysowana jest zawartosc plata
	//sf::RenderTexture tekstura;
	// pozycja wzgledem kamery
	sf::Vector2f pozycjaNaEkranie; 
	//pozycja wzgledem swiata gry
	sf::Vector2f pozycjaNaMapie;
	//koordynaty konca plata wzgledem swiata gry
	sf::Vector2f koniec; 
	// strefy zmiejszajace zakres badania kolizji
	StrefaMapy*** strefy;
	// czy plat jest rysowany i aktualizowany
	bool czyAktywny; 
	// sasiednie platy dla szybszego dostepu
	PlatMapy* sasiedzi[8];
};