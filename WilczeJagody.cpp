#include "WilczeJagody.h"
#include "myHeader.h"
#include "World.h"

WilczeJagody::WilczeJagody(int x, int y, int tura_powst, World* world)
	:Roslina(x, y, 99, 0, tura_powst, WILCZE_JAG, true, world)
{
}

char WilczeJagody::rysuj() const
{
	return 'x';
}

wynik_t WilczeJagody::kolizja(Organizm * org)
{
	org->die();
	return Organizm::kolizja(org);
}

WilczeJagody::~WilczeJagody()
{
}
