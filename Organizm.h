#pragma once
extern class World;
#include "myHeader.h"

class Organizm
{
protected:
	int sila, inicjatywa, x, y, tura_powst;
	pole_t field_type;
	bool alive;
	World* world;
public:
	Organizm(int x, int y, int sila, int inicjatywa, int tura_powst, pole_t field_type, bool alive, World* world);
	virtual char rysuj() const = 0;
	virtual wynik_t kolizja(Organizm* org);
	virtual void akcja() = 0;
	virtual int getSila() const;
	virtual int getInicjatywa() const;
	virtual int getX() const;
	virtual int getY() const;
	virtual int getTura() const;
	virtual void setSila(int sila);
	virtual bool isAlive() const;
	virtual void die();
	virtual pole_t getFieldType() const;
	virtual ~Organizm();
};