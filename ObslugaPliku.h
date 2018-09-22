#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "World.h"
#include "Organizm.h"
#include "Czlowiek.h"
#include <list>
using namespace std;

class ObslugaPliku
{
	string nazwaPliku;
	FILE *plik;
public:
	ObslugaPliku(string nazwaPliku); 
	bool otworzPlikDoOdczytu();
	bool otworzPlikDoZapisu();
	bool zamknijPlik();
	void zapiszSwiat(World* world);
	void zapiszClowieka(Czlowiek* czlowiek);
	void zapiszOrganizmy(list <Organizm*> organizmy);
	bool zapiszGre(list <Organizm*> organizmy, Czlowiek* czlowiek, World* world);
	void wczytajSwiat(World* world);
	void wczytajClowieka(World* world);
	void wczytajOrganizmy(World* world);
	bool wczytajGre(World* world);
	~ObslugaPliku();
};

