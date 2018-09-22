#pragma once
#include <string>
#include <list>
#include "Organizm.h"
using namespace std;
class Komentator
{
	list <string> komentarze;
	World* world;
public:
	Komentator(World* world);
	void wypiszKomentarze();
	void dodajKomentarz(string koment);
	void komentujWalke(Organizm* orgWin, Organizm* orgLost);
	void komentujRozmnazanie(Organizm* org);
	void komentujZasianie(Organizm* org);
	void komentujSmiercCzlowieka();
	void komentujUcieczkaAntylopy();
	void komentujZabojstwoBarszczu(Organizm* org);
	void komentujOdbicieAtaku(Organizm* atak, Organizm* obr);
	void komentujAktywacjeUm();
	void komentujZapis();
	void komentujWczytanie();
	const char* usunSlowaClass(const char* klasaOrg);
	void usunKomentarze();
	~Komentator();
};

