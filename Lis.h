#pragma once
#include "Zwierze.h"
class Lis :
	public Zwierze
{
public:
	Lis(int x, int y, int tura_powst, World* world);
	Lis(int x, int y, int tura_powst, World* world, int sila);
	char rysuj() const;
	void akcja() override;
	xy_t znajdzBezpiecznePole();
	bool isWeaker(int x, int y);
	~Lis();
};

