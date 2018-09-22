#include "Lis.h"
#include "World.h"
#include "myHeader.h"

Lis::Lis(int x, int y, int tura_powst, World* world)
	:Zwierze(x, y, 3, 7, world->getTura(), LIS, true, world)
{
}

Lis::Lis(int x, int y, int tura_powst, World * world, int sila)
	: Zwierze(x, y, sila, 7, world->getTura(), LIS, true, world)
{
}

char Lis::rysuj() const
{
	return 'i';
}

void Lis::akcja()
{
	xy_t xy = znajdzBezpiecznePole();
	if (xy.x != -1 || xy.y != -1)
	{
		if (world->isXYfree(xy.x, xy.y))
		{
			(*world)[y][x] = EMPTY;
			(*world)[xy.y][xy.x] = this->getFieldType();
			x = xy.x;
			y = xy.y;
		}
		else
		{
			Organizm* org = world->getOrganizm(xy.x, xy.y);
			if (org)
			{
				switch (org->kolizja(this))
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

}

xy_t Lis::znajdzBezpiecznePole()
{
	xy_t xy;
	srand(time(NULL));
	short losowy = rand() % 8;
	short zwiekszany = losowy;
	do
	{
		switch (zwiekszany)
		{
		case 0:
			if (world->isXYinWorld(x - 1, y) && (world->isXYfree(x - 1, y) || isWeaker(x - 1, y)))
			{
				xy.x = x - 1;
				xy.y = y;
				return xy;
			}
			break;
		case 1:
			if (world->isXYinWorld(x - 1, y - 1) && (world->isXYfree(x - 1, y - 1) || isWeaker(x - 1, y - 1)))
			{
				xy.x = x - 1;
				xy.y = y - 1;
				return xy;
			}
			break;
		case 2:
			if (world->isXYinWorld(x - 1, y + 1) && (world->isXYfree(x - 1, y + 1) || isWeaker(x - 1, y + 1)))
			{
				xy.x = x - 1;
				xy.y = y + 1;
				return xy;
			}
			break;
		case 3:
			if (world->isXYinWorld(x, y - 1) && (world->isXYfree(x, y - 1) || isWeaker(x, y - 1)))
			{
				xy.x = x;
				xy.y = y - 1;
				return xy;
			}
			break;
		case 4:
			if (world->isXYinWorld(x, y + 1) && (world->isXYfree(x, y + 1) || isWeaker(x, y + 1)))
			{
				xy.x = x;
				xy.y = y + 1;
				return xy;
			}
			break;
		case 5:
			if (world->isXYinWorld(x + 1, y - 1) && (world->isXYfree(x + 1, y - 1) || isWeaker(x + 1, y - 1)))
			{
				xy.x = x + 1;
				xy.y = y - 1;
				return xy;
			}
			break;
		case 6:
			if (world->isXYinWorld(x + 1, y) && (world->isXYfree(x + 1, y) || isWeaker(x + 1, y)))
			{
				xy.x = x + 1;
				xy.y = y;
				return xy;
			}
			break;
		case 7:
			if (world->isXYinWorld(x + 1, y + 1) && (world->isXYfree(x + 1, y + 1) || isWeaker(x + 1, y + 1)))
			{
				xy.x = x + 1;
				xy.y = y + 1;
				return xy;
			}
			break;
		}
		zwiekszany++;
	} while (losowy != zwiekszany);
	xy.x = -1;
	xy.y = -1;
	return xy;
}

bool Lis::isWeaker(int x, int y)
{
	Organizm* org = world->getOrganizm(x, y);
	if (org != NULL)
	{
		if (org->getSila() < this->getSila() || (org->getSila() == this->getSila() && org->getTura() < this->getTura()))
			return true;
		else
			return false;
	}
	return true; // wyjatek?
}

Lis::~Lis()
{
}
