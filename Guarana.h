#pragma once
#include "Roslina.h"
class Guarana :
	public Roslina
{
public:
	Guarana(int x, int y, int tura_powst, World* world);
	wynik_t kolizja(Organizm* org) override;
	char rysuj() const override;
	~Guarana();
};

