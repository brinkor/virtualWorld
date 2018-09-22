#include "Mlecz.h"
#include "myHeader.h"
#include "World.h"

Mlecz::Mlecz(int x, int y, int tura_powst, World* world)
	:Roslina(x, y, 0, 0, tura_powst, MLECZ, true, world)
{
}

char Mlecz::rysuj() const
{
	return 'T';
}

void Mlecz::akcja()
{
	for (int i = 0; i < 3; i++)
		Roslina::akcja();
}

Mlecz::~Mlecz()
{
}
