#include <iostream>
#include <SFML/Graphics.hpp>
#include "Mapa.h"
#include "Prostokat.h"
#include "Kolo.h"
#include "TestowyLudzikSerwerowy.h"
#include "Odbiornik.h"
#include <ctime>
using namespace std;


sf::Clock FPSClock;
float getFPS(const sf::Time& time) {
	return (1000000.0f / time.asMicroseconds());
}

void wyswietlanie(Mapa* mapa, sf::RenderWindow* okno,volatile bool* open) {
	sf::Font font;
	font.loadFromFile("good times rg.ttf");
	sf::Text fpsT("0", font, 12);
	fpsT.setFillColor(sf::Color::Black);
	fpsT.setPosition(sf::Vector2f(0, 0));

	while (*open) {

		okno->clear(sf::Color(0, 255, 0));
		mapa->rysuj(okno);

		while (getFPS(FPSClock.getElapsedTime()) > 60) {
			Sleep(1);
		}
		float fps = getFPS(FPSClock.restart());
		fpsT.setString(std::to_string((int)fps));
		okno->draw(fpsT);
		okno->display();
	}
	okno->close();
}

int main(int argc, char* argv[]) {
//takie fgd
	Odbiornik* o = new Odbiornik();
	Mapa mapa(sf::Vector2u(3122, 2868), sf::Vector2u(600, 600));
	

	


	Prostokat::ustawTekstureProstokata();
	Kolo::ustawTekstureKola();
	TestowyLudzikSerwerowy::zaladujLudzika();
	TestowyLudzikSerwerowy ludzik(0, sf::Vector2f(300, 500), 40);
	Kolo a(1, sf::Vector2f(200, 300));
	Kolo b(2, sf::Vector2f(120, 100));
	Kolo c(3, sf::Vector2f(220, 150));
	Kolo d(4, sf::Vector2f(500, 450));
	Kolo e(5, sf::Vector2f(600, 100));
	Prostokat f(6, sf::Vector2f(100, 500),2);
	mapa.dodajObiektStatyczny(&a);
	mapa.dodajObiektStatyczny(&b);
	mapa.dodajObiektStatyczny(&c);
	mapa.dodajObiektStatyczny(&d);
	mapa.dodajObiektStatyczny(&e);
	mapa.dodajObiektStatyczny(&f);
	mapa.dodajObiektAktywny(&ludzik);

	sf::RenderWindow okno(sf::VideoMode(800, 600), "Online Survival");
	okno.setActive(false);
	volatile bool open = true;
	std::thread wysw(wyswietlanie, &mapa, &okno, &open);
	while (okno.isOpen()) {
		sf::Event Event;
		while (okno.pollEvent(Event)) {
			switch (Event.type)
			{
			case sf::Event::Closed:
				open = false;
				wysw.join();
				break;
				case sf::Event::KeyPressed:
				switch (Event.key.code)
				{

				case sf::Keyboard::Up:
					mapa.przesunKamere(sf::Vector2f(0, -5));
				break;
				case sf::Keyboard::Down:
					mapa.przesunKamere(sf::Vector2f(0, 5));
					break;
				case sf::Keyboard::Left:
					mapa.przesunKamere(sf::Vector2f(-5, 0));
				break;
				case sf::Keyboard::Right:
					mapa.przesunKamere(sf::Vector2f(5, 0));
				break;
				case sf::Keyboard::W:
					ludzik.przesun(sf::Vector2f(0, -5));
				break;
				case sf::Keyboard::S:
					ludzik.przesun(sf::Vector2f(0, 5));
					break;
				case sf::Keyboard::D:
					ludzik.przesun(sf::Vector2f(5, 0));
					break;
				case sf::Keyboard::A:
					ludzik.przesun(sf::Vector2f(-5, 0));
					break;

				default:
				break;
				}
			default:
				break;
			}
		}
	}
}