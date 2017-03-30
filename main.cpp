#include <iostream>
#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "ObiektBezwladny.h"
using namespace std;

int main(int argc, char* argv[]) {
//takie fgd
    sf::RenderWindow okno(sf::VideoMode(800, 600), "Online Survival");
	std::vector<sf::Vector2f> ksztaltKwadrt;
	ksztaltKwadrt.push_back(sf::Vector2f(-25, -25));
	ksztaltKwadrt.push_back(sf::Vector2f(25, -25));
	ksztaltKwadrt.push_back(sf::Vector2f(25, 25));
	ksztaltKwadrt.push_back(sf::Vector2f(-25, 25));
	sf::RenderTexture t;
	t.create(50, 50);
	t.clear(sf::Color(0,0,255));
	sf::Texture f = t.getTexture();
	ObiektNaMapie r(1, sf::Vector2f(50,50), &f);
	ObiektNaMapie* r2 = new ObiektBezwladny(2, sf::Vector2f(100,100), &f, 0.5, 0.5);
	
    Mapa mapa(600,600);

	mapa.dodajObiekt(&r);
	mapa.dodajObiekt(r2);
    while (okno.isOpen()) {
        sf::Event Event;
        while (okno.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                okno.close();
        }
		r.obroc(0.1);
		((ObiektBezwladny*)r2)->aktualizacja(1);
        okno.clear(sf::Color(0,255,0,255));
        mapa.rysuj(&okno);
        okno.display();
    }
	delete r2;
}