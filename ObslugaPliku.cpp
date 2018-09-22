#include "ObslugaPliku.h"
#include <iterator>
#include "myHeader.h"

ObslugaPliku::ObslugaPliku(string nazwaPliku)
{
	this->nazwaPliku = nazwaPliku + ".txt";
	plik = NULL;
}

bool ObslugaPliku::otworzPlikDoOdczytu()
{
	plik = fopen(nazwaPliku.c_str(), "r");
	if (plik != NULL)
		return true;
	else
		return false;
}

bool ObslugaPliku::otworzPlikDoZapisu()
{
	plik = fopen(nazwaPliku.c_str(), "w");
	if (plik != NULL)
		return true;
	else
		return false;
}

bool ObslugaPliku::zamknijPlik()
{
	if (fclose(plik))
		return true;
	return false;
}

void ObslugaPliku::zapiszSwiat(World * world)
{
	char x[40];
	_itoa(world->getX(),x,10);
	char y[10];
	_itoa(world->getY(), y, 10);
	char tura[10];
	_itoa(world->getTura(), tura, 10);
	strcat(x, " ");
	strcat(x, y);
	strcat(x, " ");
	strcat(x, tura);
	strcat(x, " \n");
	fputs(x, plik);
}

void ObslugaPliku::zapiszClowieka(Czlowiek * czlowiek)
{
	char sila[50];
	_itoa(czlowiek->getSila(), sila, 10);
	char tura[10];
	_itoa(czlowiek->getTura(), tura, 10);
	char x[10];
	_itoa(czlowiek->getX(), x, 10);
	char y[10];
	_itoa(czlowiek->getY(), y, 10);
	char licznik[10];
	_itoa(czlowiek->getLicznik(), licznik, 10);
	strcat(sila, " ");
	strcat(sila, tura);
	strcat(sila, " ");
	strcat(sila, x);
	strcat(sila, " ");
	strcat(sila, y);
	strcat(sila, " ");
	strcat(sila, licznik); // czy jest /0?
	strcat(sila, " \n");
	fputs(sila, plik);
}

void ObslugaPliku::zapiszOrganizmy(list<Organizm*> organizmy)
{
	string org;
	list <Organizm*> ::iterator it;
	bool rozpoznano = false;
	char liczbaOrg[10];
	_itoa(organizmy.size() - 1, liczbaOrg, 10);
	strcat(liczbaOrg, " \n");
	fputs(liczbaOrg, plik);
	for (it = organizmy.begin(); it != organizmy.end(); it++)
	{
		switch ((*it)->getFieldType())
		{
		case TRAWA:
			org = "TRAWA ";
			rozpoznano = true;
			break;
		case WILK:
			org = "WILK ";
			rozpoznano = true;
			break;
		case OWCA:
			org = "OWCA ";
			rozpoznano = true;
			break;
		case LIS:
			org = "LIS ";
			rozpoznano = true;
			break;
		case ZOLW:
			org = "ZOLW ";
			rozpoznano = true;
			break;
		case ANTYLOPA:
			org = "ANTYLOPA ";
			rozpoznano = true;
			break;
		case MLECZ:
			org = "MLECZ ";
			rozpoznano = true;
			break;
		case GUARANA:
			org = "GUARANA ";
			rozpoznano = true;
			break;
		case WILCZE_JAG:
			org = "WILCZE_JAG ";
			rozpoznano = true;
			break;
		case BARSZCZ:
			org = "BARSZCZ ";
			rozpoznano = true;
			break;
		default:
			break;
		}
		if (rozpoznano == true)
		{
			char tab[50];
			strcpy(tab, org.c_str());
			char x[10];
			char y[10];
			char sila[10];
			char tura[10];
			_itoa((*it)->getX(), x, 10);
			_itoa((*it)->getY(), y, 10);
			_itoa((*it)->getSila(), sila, 10);
			_itoa((*it)->getTura(), tura, 10);
			strcat(tab, x);
			strcat(tab, " ");
			strcat(tab, y);
			strcat(tab, " ");
			strcat(tab, sila);
			strcat(tab, " ");
			strcat(tab, tura);
			strcat(tab, " \n");
			fputs(tab, plik);
		}
		rozpoznano = false;
	}
}

bool ObslugaPliku::zapiszGre(list<Organizm*> organizmy, Czlowiek* czlowiek, World * world)
{
	if (otworzPlikDoZapisu())
	{
		zapiszSwiat(world);
		zapiszClowieka(czlowiek);
		zapiszOrganizmy(organizmy);
		zamknijPlik();
		return true;
	}
	return false;

}

void ObslugaPliku::wczytajSwiat(World * world)
{
	int i = 0;
	int j = 0;
	char tab[50];
	char x[10];
	fgets(tab, 50, plik);
	while (tab[i] != ' ')
	{
		x[j] = tab[i];
		i++;
		j++;
	}
	int liczbaX = atoi(x);
	i++;
	j = 0;
	char y[10];
	while (tab[i] != ' ')
	{
		y[j] = tab[i];
		i++;
		j++;
	}
	int liczbaY = atoi(y);
	i++;
	j = 0;
	char tura[10];
	while (tab[i] != ' ')
	{
		tura[j] = tab[i];
		i++;
		j++;
	}
	int liczbaTura = atoi(tura);
	world->nowaPlansza(liczbaX, liczbaY, liczbaTura);
}

void ObslugaPliku::wczytajClowieka(World* world)
{
	int i = 0;
	int j = 0;
	char tab[40];
	fgets(tab, 40, plik);
	char dane[5][10];
	for (int liczbaDanych = 0; liczbaDanych < 5; liczbaDanych++)
	{
		while (tab[i] != ' ')
		{
			dane[liczbaDanych][j] = tab[i];
			i++;
			j++;
		}
		i++;
		j = 0;
	}
	world->wczytajOrganizm(CZLOWIEK, atoi(dane[2]), atoi(dane[3]), atoi(dane[0]), atoi(dane[1]), atoi(dane[4]));
}

void ObslugaPliku::wczytajOrganizmy(World* world)
{
	char tmpLOrg[10];
	fgets(tmpLOrg, 10, plik);
	int liczbaOrg = atoi(tmpLOrg);
	int i, j;
	for (int nrOrg = 0; nrOrg < liczbaOrg; nrOrg++)
	{
		i = 0;
		j = 0;
		char tab[40] = {};
		fgets(tab, 40, plik);
		char dane[4][10] = {};
		char nazwa[20] = {};
		while (tab[i] != ' ')
		{
			nazwa[j] = tab[i];
			i++;
			j++;
		}
		nazwa[j] = '\0';
		i++;
		j = 0;
		for (int liczbaDanych = 0; liczbaDanych < 4; liczbaDanych++)
		{
			while (tab[i] != ' ')
			{
				dane[liczbaDanych][j] = tab[i];
				i++;
				j++;
			}
			i++;
			j = 0;
		}
		string name = nazwa;
		if (name == "TRAWA")
			world->wczytajOrganizm(TRAWA, atoi(dane[0]), atoi(dane[1]), atoi(dane[2]), atoi(dane[3]), 0);
		else if (name == "MLECZ")
			world->wczytajOrganizm(MLECZ, atoi(dane[0]), atoi(dane[1]), atoi(dane[2]), atoi(dane[3]), 0);
		else if (name == "GUARANA")
			world->wczytajOrganizm(GUARANA, atoi(dane[0]), atoi(dane[1]), atoi(dane[2]), atoi(dane[3]), 0);
		else if (name == "WILCZE_JAG")
			world->wczytajOrganizm(WILCZE_JAG, atoi(dane[0]), atoi(dane[1]), atoi(dane[2]), atoi(dane[3]), 0);
		else if (name == "BARSZCZ")
			world->wczytajOrganizm(BARSZCZ, atoi(dane[0]), atoi(dane[1]), atoi(dane[2]), atoi(dane[3]), 0);
		else if (name == "WILK")
			world->wczytajOrganizm(WILK, atoi(dane[0]), atoi(dane[1]), atoi(dane[2]), atoi(dane[3]), 0);
		else if (name == "OWCA")
			world->wczytajOrganizm(OWCA, atoi(dane[0]), atoi(dane[1]), atoi(dane[2]), atoi(dane[3]), 0);
		else if (name == "LIS")
			world->wczytajOrganizm(LIS, atoi(dane[0]), atoi(dane[1]), atoi(dane[2]), atoi(dane[3]), 0);
		else if (name == "ZOLW")
			world->wczytajOrganizm(ZOLW, atoi(dane[0]), atoi(dane[1]), atoi(dane[2]), atoi(dane[3]), 0);
		else if (name == "ANTYLOPA")
			world->wczytajOrganizm(ANTYLOPA, atoi(dane[0]), atoi(dane[1]), atoi(dane[2]), atoi(dane[3]), 0);
	}
}

bool ObslugaPliku::wczytajGre(World * world)
{
	if (otworzPlikDoOdczytu())
	{
		wczytajSwiat(world);
		world->usunListe();
		wczytajClowieka(world);
		wczytajOrganizmy(world);
		return true;
	}
	return false;
}

ObslugaPliku::~ObslugaPliku()
{
}
