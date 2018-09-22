#include "Owca.h"
#include "World.h"
#include "myHeader.h"

Owca::Owca(int x, int y, int tura_powst, World* world)
	:Zwierze(x, y, 4, 4, world->getTura(), OWCA, true, world)
{
}

Owca::Owca(int x, int y, int tura_powst, World * world, int sila)
	: Zwierze(x, y, sila, 4, world->getTura(), OWCA, true, world)
{
}

char Owca::rysuj() const
{
	return 'o';
}

Owca::~Owca()
{
}
