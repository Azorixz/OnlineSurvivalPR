#include "TestowyLudzikSerwerowy.h"

sf::Texture TestowyLudzikSerwerowy::teksturaLudzika;

TestowyLudzikSerwerowy::TestowyLudzikSerwerowy(int id, sf::Vector2f pozycja, float kat)
	:KolizyjneKolo(id, pozycja, 50, kat)
{
	ustawTeksture(&teksturaLudzika);
}


TestowyLudzikSerwerowy::~TestowyLudzikSerwerowy()
{
}
void TestowyLudzikSerwerowy::zaladujLudzika() {
	sf::Image tmp;
	tmp.loadFromFile("ludzik.png");
	tmp.createMaskFromColor(sf::Color::White);
	teksturaLudzika.loadFromImage(tmp);
}