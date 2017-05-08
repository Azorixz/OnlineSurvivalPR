#include "Mapa.h"


StrefaMapy::StrefaMapy(sf::Vector2f start, sf::Vector2f koniec)
{
	this->start = start;
	this->koniec = koniec;
	for (int i = 0; i < 8; i++) {
		sasiedzi[i] = NULL;
	}
}


StrefaMapy::~StrefaMapy()
{

}

void StrefaMapy::sprawdzKolizje() {
	obiektyAktywneMap_mutex.lock();
	std::unordered_map<int, ObiektKolizyjny*>::iterator obiektSprawdzany = obiektyAktywne.begin();
	while(obiektSprawdzany != obiektyAktywne.end()) {
		for (std::pair<int, ObiektKolizyjny*> obiektInny : obiektyAktywne) {
			if (obiektSprawdzany->first != obiektInny.first) {
				if (obiektSprawdzany->second->czyKolizja(sf::Vector2f(0, 0), obiektSprawdzany->second)) {
					obiektSprawdzany->second->akcjaNaKolizji(obiektInny.second);
					obiektInny.second->akcjaNaKolizji(obiektSprawdzany->second);
				}
			}
		}
		obiektyStatyczneMap_mutex.lock();
		for (std::pair<int, ObiektKolizyjny*> obiektInny : obiektyStatyczne) {
			if (obiektSprawdzany->second->czyKolizja(sf::Vector2f(0, 0), obiektSprawdzany->second)) {
				obiektSprawdzany->second->akcjaNaKolizji(obiektInny.second);
				obiektInny.second->akcjaNaKolizji(obiektSprawdzany->second);
			}
		}
		obiektyStatyczneMap_mutex.unlock();
		for (int i = 0; i < 8; i++) {
			if (sasiedzi[i] != NULL) {
				if (sasiedzi[i]->obiektyAktywneMap_mutex.try_lock()) {
					for (std::pair<int, ObiektKolizyjny*> obiektInny : sasiedzi[i]->obiektyAktywne) {
						if (obiektSprawdzany->second->czyKolizja(sf::Vector2f(0, 0), obiektSprawdzany->second)) {
							obiektSprawdzany->second->akcjaNaKolizji(obiektInny.second);
							obiektInny.second->akcjaNaKolizji(obiektSprawdzany->second);
						}
					}
					sasiedzi[i]->obiektyAktywneMap_mutex.unlock();
				}
				if (sasiedzi[i]->obiektyStatyczneMap_mutex.try_lock()) {
					for (std::pair<int, ObiektKolizyjny*> obiektInny : sasiedzi[i]->obiektyStatyczne) {
						if (obiektSprawdzany->second->czyKolizja(sf::Vector2f(0, 0), obiektSprawdzany->second)) {
							obiektSprawdzany->second->akcjaNaKolizji(obiektInny.second);
							obiektInny.second->akcjaNaKolizji(obiektSprawdzany->second);
						}
					}
					sasiedzi[i]->obiektyStatyczneMap_mutex.unlock();
				}
			}
		}
		sf::Vector2f pozycja = obiektSprawdzany->second->getPozycja();
		if (pozycja.x < start.x) {
			sasiedzi[LEWO]->obiektyAktywneMap_mutex.lock();
			sasiedzi[LEWO]->obiektyAktywne.insert(*obiektSprawdzany);
			sasiedzi[LEWO]->obiektyAktywneMap_mutex.unlock();
		    obiektSprawdzany = obiektyAktywne.erase(obiektSprawdzany);
			
		}
		else if (pozycja.x > koniec.x) {
			sasiedzi[PRAWO]->obiektyAktywneMap_mutex.lock();
			sasiedzi[PRAWO]->obiektyAktywne.insert(*obiektSprawdzany);
			sasiedzi[PRAWO]->obiektyAktywneMap_mutex.unlock();
			obiektSprawdzany = obiektyAktywne.erase(obiektSprawdzany);
		}
		else if (pozycja.y < start.y) {
			sasiedzi[GORA]->obiektyAktywneMap_mutex.lock();
			sasiedzi[GORA]->obiektyAktywne.insert(*obiektSprawdzany);
			sasiedzi[GORA]->obiektyAktywneMap_mutex.unlock();
			obiektSprawdzany = obiektyAktywne.erase(obiektSprawdzany);
		}
		else if (pozycja.y > koniec.x) {
			sasiedzi[DOL]->obiektyAktywneMap_mutex.lock();
			sasiedzi[DOL]->obiektyAktywne.insert(*obiektSprawdzany);
			sasiedzi[DOL]->obiektyAktywneMap_mutex.unlock();
			obiektSprawdzany = obiektyAktywne.erase(obiektSprawdzany);
		}
		else {
			obiektSprawdzany++;
		}
	}
	obiektyAktywneMap_mutex.unlock();
}

void StrefaMapy::dodajSasiada(Kierunek k, StrefaMapy* s) {
	sasiedzi[k] = s;
}

void StrefaMapy::dodajObiektAktywny(ObiektKolizyjny* nowy) {
	obiektyAktywneMap_mutex.lock();
	obiektyAktywne.insert(std::pair<int, ObiektKolizyjny*>(nowy->getId(), nowy));
	obiektyAktywneMap_mutex.unlock();
}
void StrefaMapy::dodajObiektStatyczny(ObiektKolizyjny* nowy) {
	obiektyStatyczneMap_mutex.lock();
	obiektyStatyczne.insert(std::pair<int, ObiektKolizyjny*>(nowy->getId(), nowy));
	obiektyStatyczneMap_mutex.unlock();
}

void StrefaMapy::rysuj(sf::RenderTexture* tekstura, sf::Vector2f pozycjaKamery) {
	obiektyAktywneMap_mutex.lock();
	for (std::pair<int, ObiektKolizyjny*> obiekt : obiektyAktywne) {
		obiekt.second->rysuj(tekstura, pozycjaKamery);
	}
	obiektyAktywneMap_mutex.unlock();
	obiektyStatyczneMap_mutex.lock();
	for (std::pair<int, ObiektKolizyjny*> obiekt : obiektyStatyczne) {
		obiekt.second->rysuj(tekstura, pozycjaKamery);
	}
	obiektyStatyczneMap_mutex.unlock();

}
