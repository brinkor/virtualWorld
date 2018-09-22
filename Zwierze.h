#pragma once
#include "Organizm.h"
#include "myHeader.h"
#include <typeinfo>
class Zwierze :
	public Organizm
{
public:
	Zwierze(int x, int y, int sila, int inicjatywa, int tura_powst, pole_t field_type, bool alive, World* world);
	virtual void akcja() override;
	virtual wynik_t kolizja(Organizm* org) override;
	void rozmnazaj();
	virtual ~Zwierze();
};

