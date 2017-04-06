#include <iostream>
#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "ObiektBezwladny.h"
#include "KolizyjneKolo.h"
#include "KolizyjnyProstokat.h"
#include <ctime>
using namespace std;


sf::Clock FPSClock;
float getFPS(const sf::Time& time) {
	return (1000000.0f / time.asMicroseconds());
}


int main(int argc, char* argv[]) {
//takie fgd
	sf::Font font;
	font.loadFromFile("good times rg.ttf");
	sf::Text fpsT("0", font, 12);
	fpsT.setFillColor(sf::Color::Black);
	fpsT.setPosition(sf::Vector2f(0, 0));


	sf::Vector2f pozycjaA(150,300);
	sf::Vector2f pozycjaB(230,300);
	sf::Vector2f pozycjaC(400, 300);
	sf::Vector2f pozycjaD(300, 500);
	ObiektKolizyjny* a = new KolizyjneKolo(50,pozycjaA);
	ObiektKolizyjny* b = new KolizyjneKolo(30,pozycjaB);
	ObiektKolizyjny* c = new KolizyjneKolo(60,pozycjaC);
	ObiektKolizyjny* d = new KolizyjnyProstokat(sf::Vector2f(60,60), 0, pozycjaD);
	sf::CircleShape bKszt, aKszt, cKszt;
	sf::RectangleShape dKszt;
	aKszt.setOrigin(sf::Vector2f(50, 50));
	bKszt.setOrigin(sf::Vector2f(30, 30));
	cKszt.setOrigin(sf::Vector2f(60, 60));
	dKszt.setOrigin(sf::Vector2f(30, 30));
	bKszt.setRadius(30);
	aKszt.setRadius(50);
	cKszt.setRadius(60);
	dKszt.setSize(sf::Vector2f(60, 60));
	aKszt.setPosition(pozycjaA);
	bKszt.setPosition(pozycjaB);
	cKszt.setPosition(pozycjaC);
	dKszt.setPosition(pozycjaD);
	aKszt.setFillColor(sf::Color(200, 200, 200));
	bKszt.setFillColor(sf::Color(200, 200, 100));
	cKszt.setFillColor(sf::Color(200, 200, 100));
	dKszt.setFillColor(sf::Color(200, 200, 100));
	sf::Vector2f przes;
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
			switch (Event.type)
			{
			case sf::Event::Closed:
				okno.close();
				break;
			case sf::Event::KeyPressed: 
				switch (Event.key.code)
				{
					
				case sf::Keyboard::Up:
					przes = sf::Vector2f(0, -5);
					przes += a->kolizja(przes, b);
					przes += a->kolizja(przes, c);
					przes += a->kolizja(przes, d);
					pozycjaA += przes;
					aKszt.setPosition(pozycjaA);
					break;
				case sf::Keyboard::Down:
					przes = sf::Vector2f(0, 5);
					przes += a->kolizja(przes, b);
					przes += a->kolizja(przes, c);
					przes += a->kolizja(przes, d);
					pozycjaA += przes;
					aKszt.setPosition(pozycjaA);
					break;
				case sf::Keyboard::Left:
					przes = sf::Vector2f(-5, 0);
					przes += a->kolizja(przes, b);
					przes += a->kolizja(przes, c);
					przes += a->kolizja(przes, d);
					pozycjaA += przes;
					aKszt.setPosition(pozycjaA);
					break;
				case sf::Keyboard::Right:
					przes = sf::Vector2f(5, 0);
					przes += a->kolizja(przes, b);
					przes += a->kolizja(przes, c);
					przes += a->kolizja(przes, d);
					pozycjaA += przes;
					aKszt.setPosition(pozycjaA);
					break;
				default:
					break;
				}
			default:
				break;
			}
				
        }
		r.obroc(0.1f);
		((ObiektBezwladny*)r2)->aktualizacja(1);
        okno.clear(sf::Color(0,255,0,255));
        mapa.rysuj(&okno);
		okno.draw(aKszt);
		okno.draw(bKszt);
		okno.draw(cKszt);
		okno.draw(dKszt);


		float fps = getFPS(FPSClock.restart());
		fpsT.setString(std::to_string(fps));
		okno.draw(fpsT);
        okno.display();
		
    }
	delete r2;
}