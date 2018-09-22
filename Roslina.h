#pragma once
#include "Organizm.h"

class Roslina :
	public Organizm
{
public:
	Roslina(int x, int y, int sila, int inicjatywa, int tura_powst, pole_t field_type, bool alive, World* world);
	virtual void akcja() override;
	virtual ~Roslina();
};

