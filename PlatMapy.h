#pragma once
#include <StrefaMapy.h>
#include <SFML\Graphics.hpp>
#include <mutex>
class PlatMapy
//obszar mapy ladowany gdy gracze sa w okolicy
{
public:
	PlatMapy(sf::Vector2f pozycja, sf::Vector2f wymiary);
	~PlatMapy();
	void sprawdzKolizje();
	void dodajSasiada(Kierunek, PlatMapy*);
	void dodajSasiadowStrefom();
	void dodajObiektAktywny(ObiektKolizyjny* nowy);
	void dodajObiektStatyczny(ObiektKolizyjny* nowy);
	void aktywuj() { czyAktywny = true; };
	void dezaktywuj() { czyAktywny = false; };
	void rysuj(sf::RenderTexture* tekstura, sf::Vector2f pozycjaKamery);
private:
	int liczbaStrefNaX;
	int liczbaStrefNaY;
	sf::Vector2f wymiaryStrefy;
	//tekstura na ktorej sa rysowana jest zawartosc plata
	//sf::RenderTexture tekstura;
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