#pragma once
#include "Roslina.h"
class WilczeJagody :
	public Roslina
{
public:
	WilczeJagody(int x, int y, int tura_powst, World* world);
	char rysuj() const override;
	wynik_t kolizja(Organizm* org) override;
	~WilczeJagody();
};

