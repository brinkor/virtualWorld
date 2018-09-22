#include "Zolw.h"
#include "World.h"
#include "myHeader.h"

Zolw::Zolw(int x, int y, int tura_powst, World* world)
	:Zwierze(x, y, 2, 1, world->getTura(), ZOLW, true, world)
{
}

Zolw::Zolw(int x, int y, int tura_powst, World * world, int sila)
	: Zwierze(x, y, sila, 1, world->getTura(), ZOLW, true, world)
{
}

char Zolw::rysuj() const
{
	return 'D';
}

void Zolw::akcja()
{
	srand(time(NULL));
	if (rand() % 100 + 1 > 75)
		Zwierze::akcja();
}

wynik_t Zolw::kolizja(Organizm * org)
{
	if (org->getSila() < 5)
	{
		world->getKomentator()->komentujOdbicieAtaku(org, this);
		return NEW;
	}
	else
		return Zwierze::kolizja(org);
}

Zolw::~Zolw()
{
}
