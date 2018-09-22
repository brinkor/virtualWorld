#include "Zwierze.h"
#include "Wilk.h"
#include "World.h"
#include "Owca.h"
#include <string>


Zwierze::Zwierze(int x, int y, int sila, int inicjatywa, int tura_powst, pole_t field_type, bool alive, World* world)
	:Organizm(x, y, sila, inicjatywa, tura_powst, field_type, alive, world)
{
}

void Zwierze::akcja()
{
	xy_t xy = world->findAnyField(x, y);
	if (world->isXYfree(xy.x, xy.y))
	{
		(*world)[y][x] = EMPTY;
		(*world)[xy.y][xy.x] = this->getFieldType();
		x = xy.x;
		y = xy.y; // musi aktualizowac pole bo kolizja nastepnego org
	}
	else
	{
		Organizm* org = world->getOrganizm(xy.x, xy.y);
		if (org)
		{
			switch (org->kolizja(this))
			{
			case LOST:
				(*world)[y][x] = EMPTY;
				(*world)[xy.y][xy.x] = this->getFieldType();
				x = xy.x;
				y = xy.y;
				break;
			case WIN:
				(*world)[y][x] = EMPTY;
				break;
			}
		}
	}
}

wynik_t Zwierze::kolizja(Organizm* org)
{
	// czy org jest ta sama rasa co this? rozmnazanie
	// proble owca vs gracz wyjatek
	if (typeid(*org) == typeid(*this))
	{
		//rozmnazanie
		Zwierze* zwierze = dynamic_cast<Zwierze*>(this);
		zwierze->rozmnazaj();
		return NEW;
	}
	Organizm::kolizja(org);
}

void Zwierze::rozmnazaj()
{
	xy_t puste = world->findEmpty(x, y);
	if (puste.x == -1 || puste.y == -1)
		return;
	(*world)[puste.y][puste.x] = this->getFieldType();
	Organizm* nowyOrg = world->stworzOrganizmTypu(this->getFieldType(), puste.x, puste.y);
	if (nowyOrg != NULL)
		world->getKomentator()->komentujRozmnazanie(this);
}


Zwierze::~Zwierze()
{
}
