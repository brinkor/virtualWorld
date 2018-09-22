#pragma once
#include "Zwierze.h"
class Wilk :
	public Zwierze
{
public:
	Wilk(int x, int y, int tura_powst, World* world);
	Wilk(int x, int y, int tura_powst, World* world, int sila);
	char rysuj() const;
	~Wilk();
};

