#include <iostream>
#include <SFML/Graphics.hpp>
#include "Mapa.h"
using namespace std;

int main(int argc, char* argv[]) {
//takie fgd
    sf::RenderWindow okno(sf::VideoMode(800, 600), "Online Survival");


    Mapa mapa(600,600);
    while (okno.isOpen()) {
        sf::Event Event;
        while (okno.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                okno.close();
        }
        okno.clear(sf::Color(0,255,0,255));
        mapa.rysuj(&okno);
        okno.display();
    }
}