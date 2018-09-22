#include "Wilk.h"
#include "World.h"
#include "myHeader.h"

Wilk::Wilk(int x, int y, int tura_powst, World* world)
	:Zwierze(x, y, 9, 5, world->getTura(), WILK, true, world)
{
}

Wilk::Wilk(int x, int y, int tura_powst, World * world, int sila)
	: Zwierze(x, y, sila, 5, world->getTura(), WILK, true, world)
{
}

char Wilk::rysuj() const
{
	return '!';
}

Wilk::~Wilk()
{
}
