#include "Antylopa.h"
#include "World.h"
#include "myHeader.h"

Antylopa::Antylopa(int x, int y, int tura_powst, World * world, int sila)
	: Zwierze(x, y, 4, 4, tura_powst, ANTYLOPA, true, world)
{
}

Antylopa::Antylopa(int x, int y, int tura_powst, World* world)
	:Zwierze(x, y, 4, 4, world->getTura(), ANTYLOPA, true, world)
{
}

char Antylopa::rysuj() const
{
	return 'H';
}

wynik_t Antylopa::kolizja(Organizm * org)
{
	srand(time(NULL));
	int ucieczka = rand() % 2;
	if (typeid(*this) == typeid(*org))
	{
		return Zwierze::kolizja(org);
	}
	if (ucieczka) // akcja
	{
		world->getKomentator()->komentujUcieczkaAntylopy();
		xy_t xy;
		do
		{
			xy = world->findAnyField(x, y);
		} while (xy.x == org->getX() && xy.y == org->getY());

		if (world->isXYfree(xy.x, xy.y))
		{
			(*world)[y][x] = EMPTY;
			(*world)[xy.y][xy.x] = this->getFieldType();
			x = xy.x;
			y = xy.y;
		}
		else
		{
			Organizm* przeciwnik = world->getOrganizm(xy.x, xy.y);
			if (przeciwnik)
			{
				switch (przeciwnik->kolizja(this))
				{
				case LOST:
					(*world)[y][x] = EMPTY;
					(*world)[xy.y][xy.x] = this->getFieldType();
					x = xy.x;
					y = xy.y;
					break;
				case WIN:
					(*world)[y][x] = EMPTY;
					break;
				}
			}
		}
	}
	else
		return Zwierze::kolizja(org);
}

void Antylopa::akcja() // moze przeskakiwac pola? 2xAkcja czy o 2 pola
{
	for (int i = 0; i < 2; i++)
	{
		if (this->isAlive())
			Zwierze::akcja();
	}
}

Antylopa::~Antylopa()
{
}
