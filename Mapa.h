#pragma once

#include <SFML/Graphics.hpp>
#include <PlatMapy.h>
#include <mutex>

#include <unordered_map>

#define MAX_ROZMIAR_PLATA 1000;
#define MIN_ROZMIAR_STREFY 1000;


class Mapa {
public:
	void uruchomSprawdzanieKolizji(int liczbaWatkow);
    void rysuj(sf::RenderWindow*);
	void dodajObiektAktywny(ObiektKolizyjny* nowy);
	void dodajObiektStatyczny(ObiektKolizyjny* nowy);
	void przesunKamere(sf::Vector2f v);
    Mapa(sf::Vector2u, sf::Vector2u);
	~Mapa();
protected:
	void watekSprawdzaniaKolizji(sf::Vector2i);

	std::vector <std::thread> watkiSprawdzaniaKolizji;
	volatile bool sprawdzanieKolizji;
	int liczbaPlatowNaX;
	int liczbaPlatowNaY;
	sf::Vector2f wymiaryPlata;
	std::mutex pozycjaKamery_mutex;
	sf::Vector2f pozycjaKamery;
	// kamera wlascie
    sf::RenderTexture teksturaMapy;
	PlatMapy*** platy;
	
};