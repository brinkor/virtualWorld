#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :
	public Roslina
{
public:
	BarszczSosnowskiego(int x, int y, int tura_powst, World* world);
	BarszczSosnowskiego(int x, int y, int tura_powst, World* world, int sila);
	char rysuj() const override;
	void akcja() override;
	wynik_t kolizja(Organizm * org) override;
	~BarszczSosnowskiego();
};