#pragma once
#include "Zwierze.h"
#include "myHeader.h"

class Czlowiek :
	public Zwierze
{
	kierunek_t kierunek;
	short licznik;
public:
	Czlowiek(int x, int y, int tura_powst, World* world);
	Czlowiek(int x, int y, int tura_powst, World* world, int sila, int licznik);
	char rysuj() const;
	void akcja() override;
	void die() override;
	kierunek_t getKierunek() const;
	void setKierunek(kierunek_t kier);
	void przesun(int oX, int oY);
	bool aktywujUmiejetnosc();
	void sprawdzUmiejetnosc();
	short getLicznik();
	~Czlowiek();
};