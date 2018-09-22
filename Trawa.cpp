#include "Trawa.h"
#include "myHeader.h"
#include "World.h"

Trawa::Trawa(int x, int y, int tura_powst, World* world)
	:Roslina(x, y, 0, 0, tura_powst, TRAWA, true, world)
{
}

char Trawa::rysuj() const
{
	return 'v';
}

Trawa::~Trawa()
{
}
