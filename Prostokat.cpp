#include "Prostokat.h"

sf::Texture Prostokat::teksturaProstokata;

Prostokat::Prostokat(int id, sf::Vector2f pozycja, float kat)
	:Sciana(id, pozycja, sf::Vector2f(BOK_X, BOK_Y),kat)
{
	ustawTeksture(&teksturaProstokata);
}


Prostokat::~Prostokat()
{
}

void Prostokat::ustawTekstureProstokata() {
	sf::RenderTexture tekstura;
	tekstura.create(150, 100);
	tekstura.clear(sf::Color::Blue);
	teksturaProstokata = tekstura.getTexture();
}