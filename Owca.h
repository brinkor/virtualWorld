#pragma once
#include "Zwierze.h"
class Owca :
	public Zwierze
{
public:
	Owca(int x, int y, int tura_powst, World* world);
	Owca(int x, int y, int tura_powst, World* world, int sila);
	char rysuj() const;
	~Owca();
};

