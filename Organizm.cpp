#include "Organizm.h"
#include "World.h"

Organizm::Organizm(int x, int y, int sila, int inicjatywa, int tura_powst, pole_t field_type, bool alive, World* world)
	:x(x), y(y), sila(sila), inicjatywa(inicjatywa), world(world), field_type(field_type), alive(alive), tura_powst(tura_powst)
{
}

wynik_t Organizm::kolizja(Organizm * org)
{
	bool win;
	if (sila == org->getSila())
	{
		if (tura_powst < org->getTura())
			win = true;
		else
			win = false;
	}
	else if (sila > org->getSila())
		win = true;
	else
		win = false;
	if (win == true)
	{
		world->getKomentator()->komentujWalke(this, org);
		org->die();
	}
	else
	{
		world->getKomentator()->komentujWalke(org, this);
		this->die();
	}
	if (win == true)
		return WIN;
	else
		return LOST;
}


Organizm::~Organizm()
{
}

int Organizm::getSila() const
{
	return sila;
}

int Organizm::getInicjatywa() const
{
	return inicjatywa;
}

int Organizm::getX() const
{
	return x;
}

int Organizm::getY() const
{
	return y;
}

int Organizm::getTura() const
{
	return tura_powst;
}

void Organizm::setSila(int sila)
{
	this->sila = sila;
}

bool Organizm::isAlive() const
{
	return alive;
}

void Organizm::die()
{
	(*world)[y][x] = EMPTY;
	alive = false;
}

pole_t Organizm::getFieldType() const
{
	return field_type;
}
