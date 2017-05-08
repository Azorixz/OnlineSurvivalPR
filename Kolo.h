#pragma once
#include "Slup.h"

#define PROMIEN_KOLA 50

class Kolo : public Slup
{
public:
	Kolo(int id, sf::Vector2f pozycja);
	virtual ~Kolo();
	static void ustawTekstureKola();
private:
	static sf::Texture teksturaKola;
};

