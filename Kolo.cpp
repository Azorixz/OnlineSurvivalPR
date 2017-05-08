#include "Kolo.h"

sf::Texture Kolo::teksturaKola;

Kolo::Kolo(int id, sf::Vector2f pozycja)
	:Slup(id, pozycja, PROMIEN_KOLA, 0)
{
	ustawTeksture(&teksturaKola);
}


Kolo::~Kolo()
{
}

void Kolo::ustawTekstureKola() {
	sf::RenderTexture tekstura;
	tekstura.create(PROMIEN_KOLA*2, PROMIEN_KOLA*2);
	tekstura.clear(sf::Color(0, 0, 0, 0));
	sf::CircleShape kolo;
	kolo.setOrigin(sf::Vector2f(PROMIEN_KOLA,PROMIEN_KOLA));
	kolo.setRadius(PROMIEN_KOLA);
	kolo.setPosition(sf::Vector2f(PROMIEN_KOLA, PROMIEN_KOLA));
	kolo.setFillColor(sf::Color::Cyan);
	tekstura.draw(kolo);
	Kolo::teksturaKola = tekstura.getTexture();
}