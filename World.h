#pragma once
#include <list>
#include <iostream>
#include <ctime>
#include <iterator>
#include <conio.h>
#include "Trawa.h"
#include "myHeader.h"
#include "orgComp.h"
#include "Komentator.h"
using namespace std;

extern class ObslugaPliku;

class World
{
	list <Organizm*> organizmy;
	int tura;
	int x, y;
	pole_t** pole;
	Komentator* komentator;
	ObslugaPliku* obs;
	bool koniecGry;
public:
	World(int x,int y);
	pole_t* operator[] (size_t i);
	int getTura() const;
	int getX() const;
	int getY() const;
	Komentator* getKomentator() const;
	Organizm* getOrganizm(int x,int y);
	Organizm* getCzlowiek();
	void setTura(int t);
	void usunPlansze();
	void usunListe();
	void nowaPlansza(int x, int y, int tura);
	void rysujSwiat();
	void wypiszLinieRamki() const;
	void wykonajTure();
	void generujSwiat();
	void usunCiala();
	void smiercCzlowieka();
	bool isXYfree(int x, int y) const;
	void dodajOrganizm(Organizm* org);
	xy_t findEmpty(int x, int y) const;
	xy_t findAnyField(int x, int y) const;
	bool isXYinWorld(int x, int y) const;
	bool porownajInicjatywe(const Organizm& org1,const Organizm& org2) const;
	bool czyRoslina(Organizm* org);
	Organizm* stworzOrganizmTypu(pole_t pole, int x, int y);
	Organizm * wczytajOrganizm(pole_t pole, int x, int y, int sila, int tura, int licznik);
	void zyj();
	~World();
};

