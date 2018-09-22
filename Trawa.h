#pragma once
#include "Roslina.h"
class Trawa :
	public Roslina
{
public:
	Trawa(int x, int y, int tura_powst, World* world);
	char rysuj() const override;
	~Trawa();
};

