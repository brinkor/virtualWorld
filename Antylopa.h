#pragma once
#include "Zwierze.h"
class Antylopa :
	public Zwierze
{
public:
	Antylopa(int x, int y, int tura_powst, World* world, int sila);
	Antylopa(int x, int y, int tura_powst, World* world);
	char rysuj() const;
	wynik_t kolizja(Organizm* org) override;
	void akcja() override;
	~Antylopa();
};

