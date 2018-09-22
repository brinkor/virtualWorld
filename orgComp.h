#pragma once
#include "Organizm.h"

struct org_comp_t
{
	bool operator ()(Organizm* org1, Organizm* org2)
	{
		if (org1->getInicjatywa() == org2->getInicjatywa())
		{
			if (org1->getTura() > org2->getTura())
				return true;
			else
				return false;
		}
		else if (org1->getInicjatywa() > org2->getInicjatywa())
			return true;
		else
			return false;
	}
};