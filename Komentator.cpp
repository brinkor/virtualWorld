#include "Komentator.h"
#include <iterator>
#include <iostream>
#include "World.h"
using namespace std;

Komentator::Komentator(World* world)
	:world(world)
{
	dodajKomentarz("Powstal nowy swiat!");
}

void Komentator::wypiszKomentarze()
{
	list <string> ::iterator it;
	for (it = komentarze.begin(); it != komentarze.end(); it++)
		cout << *it << endl;
}

void Komentator::dodajKomentarz(string koment)
{
	komentarze.push_back(koment);
}

void Komentator::komentujWalke(Organizm * orgWin, Organizm * orgLost)
{
	string kom;
	if (world->czyRoslina(orgLost))
	{
		kom = usunSlowaClass(typeid(*orgWin).name());
		kom += " zjada ";
		kom += usunSlowaClass(typeid(*orgLost).name());
	}
	else if (world->czyRoslina(orgWin))
	{
		kom = usunSlowaClass(typeid(*orgLost).name());
		kom += " zjada ";
		kom += usunSlowaClass(typeid(*orgWin).name());
		kom += " i umiera";
	}
	else
	{
		kom = usunSlowaClass(typeid(*orgLost).name());
		kom += " polegl w walce z ";
		kom += usunSlowaClass(typeid(*orgWin).name());
	}
	dodajKomentarz(kom);
}

void Komentator::komentujRozmnazanie(Organizm * org)
{
	string kom = usunSlowaClass(typeid(*org).name());
	kom += " rozmnozyl sie.";
	dodajKomentarz(kom);
}

void Komentator::komentujZasianie(Organizm * org)
{
	string kom = usunSlowaClass(typeid(*org).name());
	kom += " zasial nowa rosline.";
	dodajKomentarz(kom);
}

void Komentator::komentujSmiercCzlowieka()
{
	string str = "Gracz umarl, koniec gry.";
	dodajKomentarz(str);
}

void Komentator::komentujUcieczkaAntylopy()
{
	string kom = "Antylopa ucieka przed walka";
	dodajKomentarz(kom);
}

void Komentator::komentujZabojstwoBarszczu(Organizm * org)
{
	string kom = "Barszcz Sosnowskiego zabija ";
	kom += usunSlowaClass(typeid(*org).name());
	dodajKomentarz(kom);
}

void Komentator::komentujOdbicieAtaku(Organizm * atak, Organizm * obr)
{
	string kom = usunSlowaClass(typeid(*obr).name());
	string atakujacy = usunSlowaClass(typeid(*atak).name());
	kom += " odbija atak " + atakujacy;
	dodajKomentarz(kom);
}

void Komentator::komentujAktywacjeUm()
{
	string kom = "Czlowiek aktywowal swoja umiejetnosc specjalna, posiada teraz 10 sily.";
	dodajKomentarz(kom);
}

void Komentator::komentujZapis()
{
	string kom = "Zapisano gre.";
	dodajKomentarz(kom);
}

void Komentator::komentujWczytanie()
{
	string kom = "Wczytano gre.";
	dodajKomentarz(kom);
}

const char* Komentator::usunSlowaClass(const char* klasaOrg)
{
	return (klasaOrg + 6);
}

void Komentator::usunKomentarze()
{
	list <string> ::iterator it;
	list <string> ::iterator toErase;
	int listSize = komentarze.size();
	it = komentarze.begin();
	for (int i = 0; i < listSize; i++)
	{
		toErase = it;
		it++;
		komentarze.erase(toErase);
	}
}



Komentator::~Komentator()
{
}
