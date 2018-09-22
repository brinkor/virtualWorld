#pragma once
#include "Zwierze.h"
class Zolw :
	public Zwierze
{
public:
	Zolw(int x, int y, int tura_powst, World* world);
	Zolw(int x, int y, int tura_powst, World* world, int sila);
	char rysuj() const;
	void akcja() override;
	wynik_t kolizja(Organizm* org) override;
	~Zolw();
};