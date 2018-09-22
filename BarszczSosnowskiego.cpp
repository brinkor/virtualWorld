#include "BarszczSosnowskiego.h"
#include "myHeader.h"
#include "World.h"

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, int tura_powst, World* world)
	:Roslina(x, y, 10, 0, tura_powst, BARSZCZ, true, world)
{
}

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, int tura_powst, World * world, int sila)
	: Roslina(x, y, sila, 0, tura_powst, BARSZCZ, true, world)
{
}

char BarszczSosnowskiego::rysuj() const
{
	return '$';
}

void BarszczSosnowskiego::akcja()
{
	Organizm* org;
	if (world->isXYinWorld(x - 1, y) && !(world->isXYfree(x - 1, y)) && !(world->czyRoslina(world->getOrganizm(x - 1, y))))
	{
		org = world->getOrganizm(x - 1, y);
		if (org != NULL) // wyjatek
		{
			world->getKomentator()->komentujZabojstwoBarszczu(org);
			org->die();
		}
	}
	if (world->isXYinWorld(x - 1, y - 1) && !(world->isXYfree(x - 1, y - 1)) && !(world->czyRoslina(world->getOrganizm(x - 1, y - 1))))
	{
		org = world->getOrganizm(x - 1, y - 1);
		if (org != NULL) // wyjatek
		{
			world->getKomentator()->komentujZabojstwoBarszczu(org);
			org->die();
		}
	}
	if (world->isXYinWorld(x - 1, y + 1) && !(world->isXYfree(x - 1, y + 1)) && !(world->czyRoslina(world->getOrganizm(x - 1, y + 1))))
	{
		org = world->getOrganizm(x - 1, y + 1);
		if (org != NULL) // wyjatek
		{
			world->getKomentator()->komentujZabojstwoBarszczu(org);
			org->die();
		}
	}
	if (world->isXYinWorld(x, y - 1) && !(world->isXYfree(x, y - 1)) && !(world->czyRoslina(world->getOrganizm(x, y - 1))))
	{
		org = world->getOrganizm(x, y - 1);
		if (org != NULL) // wyjatek
		{
			world->getKomentator()->komentujZabojstwoBarszczu(org);
			org->die();
		}
	}
	if (world->isXYinWorld(x, y + 1) && !(world->isXYfree(x, y + 1)) && !(world->czyRoslina(world->getOrganizm(x, y + 1))))
	{
		org = world->getOrganizm(x, y + 1);
		if (org != NULL) // wyjatek
		{
			world->getKomentator()->komentujZabojstwoBarszczu(org);
			org->die();
		}
	}
	if (world->isXYinWorld(x + 1, y - 1) && !(world->isXYfree(x + 1, y - 1)) && !(world->czyRoslina(world->getOrganizm(x + 1, y - 1))))
	{
		org = world->getOrganizm(x + 1, y - 1);
		if (org != NULL) // wyjatek
		{
			world->getKomentator()->komentujZabojstwoBarszczu(org);
			org->die();
		}
	}
	if (world->isXYinWorld(x + 1, y) && !(world->isXYfree(x + 1, y)) && !(world->czyRoslina(world->getOrganizm(x + 1, y))))
	{
		org = world->getOrganizm(x + 1, y);
		if (org != NULL) // wyjatek
		{
			world->getKomentator()->komentujZabojstwoBarszczu(org);
			org->die();
		}
	}
	if (world->isXYinWorld(x + 1, y + 1) && !(world->isXYfree(x + 1, y + 1)) && !(world->czyRoslina(world->getOrganizm(x + 1, y + 1))))
	{
		org = world->getOrganizm(x + 1, y + 1);
		if (org != NULL) // wyjatek
		{
			world->getKomentator()->komentujZabojstwoBarszczu(org);
			org->die();
		}
	}
}

wynik_t BarszczSosnowskiego::kolizja(Organizm * org)
{
	org->die();
	return Organizm::kolizja(org);
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
}
