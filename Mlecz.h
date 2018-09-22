#pragma once
#include "Roslina.h"
class Mlecz :
	public Roslina
{
public:
	Mlecz(int x, int y, int tura_powst, World* world);
	char rysuj() const override;
	void akcja() override;
	~Mlecz();
};

