#include "Czlowiek.h"
#include "World.h"
#include "myHeader.h"

Czlowiek::Czlowiek(int x, int y, int tura_powst, World* world)
	:Zwierze(x, y, 5, 4, world->getTura(), CZLOWIEK, true, world)
{
	licznik = 0;
}

Czlowiek::Czlowiek(int x, int y, int tura_powst, World * world, int sila, int licznik)
	: Zwierze(x, y, 5, 4, world->getTura(), CZLOWIEK, true, world)
{
	this->licznik = licznik;
}

char Czlowiek::rysuj() const
{
	return '&';
}

void Czlowiek::akcja() // przesunac fieldtype czlowieka
{
	Organizm* org = NULL;
	switch (kierunek)
	{
	case GORA:
		if (!(world->isXYinWorld(x, y - 1)))
			break;
		if (world->isXYfree(x, y - 1))
			przesun(0, -1);
		else
		{
			org = world->getOrganizm(x, y - 1);
			if (org->kolizja(this) == LOST)
				przesun(0, -1);
		}
		break;
	case DOL:
		if (!(world->isXYinWorld(x, y + 1)))
			break;
		if (world->isXYfree(x, y + 1))
			przesun(0, 1);
		else
		{
			org = world->getOrganizm(x, y + 1);
			if (org->kolizja(this) == LOST)
				przesun(0, 1);
		}
		break;
	case LEWO:
		if (!(world->isXYinWorld(x - 1, y)))
			break;
		if (world->isXYfree(x - 1, y))
			przesun(-1, 0);
		else
		{
			org = world->getOrganizm(x - 1, y);
			if (org->kolizja(this) == LOST)
				przesun(-1, 0);
		}
		break;
	case PRAWO:
		if (!(world->isXYinWorld(x + 1, y)))
			break;
		if (world->isXYfree(x + 1, y))
			przesun(1, 0);
		else
		{
			org = world->getOrganizm(x + 1, y);
			if (org->kolizja(this) == LOST)
				przesun(1, 0);
		}
		break;
	}
}

void Czlowiek::die()
{
	Organizm::die();
	world->smiercCzlowieka();
}

kierunek_t Czlowiek::getKierunek() const
{
	return kierunek;
}

void Czlowiek::setKierunek(kierunek_t kier)
{
	kierunek = kier;
}

void Czlowiek::przesun(int oX, int oY)
{
	if (oX == 0 && oY != 0)
	{
		(*world)[y][x] = EMPTY;
		y += oY;
		(*world)[y][x] = CZLOWIEK;
	}
	if (oX != 0 && oY == 0)
	{
		(*world)[y][x] = EMPTY;
		x += oX;
		(*world)[y][x] = CZLOWIEK;
	}
}

bool Czlowiek::aktywujUmiejetnosc()
{
	if (licznik == 0)
	{
		//world->getKomentator()->komentujAktywacjeUm();
		licznik = SUPER_SILA;
		sila = SUPER_SILA + 1;
		return true;
	}
	return false;
}

void Czlowiek::sprawdzUmiejetnosc()
{
	if (licznik != 0)
	{
		if (licznik >= SUPER_SILA/2)
			sila--;
		licznik--;
	}
}

short Czlowiek::getLicznik()
{
	return licznik;
}

Czlowiek::~Czlowiek()
{
}
