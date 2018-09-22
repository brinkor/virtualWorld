#include "Guarana.h"
#include "myHeader.h"
#include "World.h"

Guarana::Guarana(int x, int y, int tura_powst, World* world)
	:Roslina(x, y, 0, 0, tura_powst, GUARANA, true, world)
{
}

wynik_t Guarana::kolizja(Organizm * org)
{
	org->setSila(org->getSila() + 3);
	return Organizm::kolizja(org);
}

char Guarana::rysuj() const
{
	return '@';
}

Guarana::~Guarana()
{
}
