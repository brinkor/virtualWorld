#include "Roslina.h"
#include "World.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"

Roslina::Roslina(int x, int y, int sila, int inicjatywa, int tura_powst, pole_t field_type, bool alive, World* world)
	:Organizm(x, y, sila, inicjatywa, tura_powst, field_type, alive, world)
{
}

void Roslina::akcja()
{
	if (rand() % 100 < TEMPO_ROZROSTU)
	{
		xy_t xy = world->findEmpty(x, y);
		if (xy.x == -1 || xy.y == -1)
			return;
		Organizm* org = world->stworzOrganizmTypu(getFieldType(), xy.x, xy.y);
		if (org!=NULL)
			world->getKomentator()->komentujZasianie(this);
	}
}

Roslina::~Roslina()
{
}
