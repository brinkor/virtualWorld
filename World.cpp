#include "World.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"
#include "Komentator.h"
#include "ObslugaPliku.h"

World::World(int x,int y)
	:tura(0),x(x),y(y),koniecGry(false)
{
	komentator = new Komentator(this);
	string nazwaPliku = "save";
	obs = new ObslugaPliku(nazwaPliku);
	pole = new pole_t*[y];
	for (int i = 0; i < y; i++)
		pole[i] = new pole_t[x];
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
			pole[i][j] = EMPTY;
	}
}

pole_t * World::operator[](size_t i)
{
	return pole[i];
}

int World::getTura() const
{
	return tura;
}

void World::generujSwiat()
{
	if (tura == 0)
	{
		//
		srand(time(NULL));
		short lOrg[LICZBA_ROZNYCH_ORGANIZMOW];
		Organizm* organizm;
		bool wpisano = false;
		int losX, losY;
		pole_t rodzaj_organizmu;
		//int chwilowy = 0;
		for (int i = 0; i < LICZBA_ROZNYCH_ORGANIZMOW - 1; i++) // -1 bo czlowiek oddzielnie
		{
			//if (chwilowy == 5) // same owce
			//	break;
			//chwilowy++;
			//i = 2;
			rodzaj_organizmu = static_cast<pole_t>(i);
			lOrg[i] = (rand() % 2) + 2;
			for (int j = 0; j < lOrg[i]; j++)
			{
				// znalezc wolne x,y w swiecie dla organizmu do inicjalizacji
				while (!wpisano)
				{
					losX = rand() % x;
					losY = rand() % y;
					if (pole[losY][losX] == EMPTY)
					{
						switch (rodzaj_organizmu) // po zaimplemoentowaniiu dodac do switcha
						{
						case TRAWA:
							organizm = new Trawa(losX, losY, tura, this);
							break;
						case WILK:
							organizm = new Wilk(losX, losY, tura, this);
							break;
						case OWCA:
							organizm = new Owca(losX, losY, tura, this);
							break;
						case LIS:
							organizm = new Lis(losX, losY, tura, this);
							break;
						case ZOLW:
							organizm = new Zolw(losX, losY, tura, this);
							break;
						case ANTYLOPA:
							organizm = new Antylopa(losX, losY, tura, this);
							break;
						case MLECZ:
							organizm = new Mlecz(losX, losY, tura, this);
							break;
						case GUARANA:
							organizm = new Guarana(losX, losY, tura, this);
							break;
						case WILCZE_JAG:
							organizm = new WilczeJagody(losX, losY, tura, this);
							break;
						case BARSZCZ:
							organizm = new BarszczSosnowskiego(losX, losY, tura, this);
							break;
						default:
							break;
						}
						dodajOrganizm(organizm);
						pole[losY][losX] = rodzaj_organizmu;
						wpisano = true;
					}
				}
				wpisano = false;
			}
		}
		// wstawienie czlowieka na plansze w losowe wolne miejsce
		while (!wpisano)
		{
			losX = rand() % x;
			losY = rand() % y;
			if (pole[losY][losX] == EMPTY)
			{
				organizm = new Czlowiek(losX, losY, tura, this);
				dodajOrganizm(organizm);
				pole[losY][losX] = CZLOWIEK;
				wpisano = true;
			}
		}
	}
}

void World::usunCiala()
{
	list <Organizm*> ::iterator it; 
	list <Organizm*> ::iterator toErase;
	int listSize = organizmy.size();
	it = organizmy.begin();
	for (int i = 0; i < listSize; i++)
	{
		if ((*it)->isAlive() == false)
		{
			toErase = it;
			it++;
			delete *toErase;
			organizmy.erase(toErase);
		}
		else
			it++;
	}
}

void World::smiercCzlowieka()
{
	koniecGry = true;
}

int World::getX() const
{
	return x;
}

int World::getY() const
{
	return y;
}

Komentator* World::getKomentator() const
{
	return komentator;
}

Organizm* World::getOrganizm(int x, int y)
{
	list <Organizm*> ::iterator it;
	for (it = organizmy.begin(); it != organizmy.end(); it++)
	{
		if ((*it)->getX() == x && (*it)->getY() == y)
			return *it;
	}
	return NULL;
}

void World::rysujSwiat()
{
	cout << "---Michal Hajdasz nr 172156---" << endl;
	wypiszLinieRamki();
	Organizm* organizmNaPolu;
	for (int i = 0; i < y; i++)
	{
		cout << '#';
		for (int j = 0; j < x; j++)
		{
			if (pole[i][j] == EMPTY)
				cout << ' ';
			else
			{
				organizmNaPolu = getOrganizm(j, i);
				if (organizmNaPolu)
					cout << organizmNaPolu->rysuj(); // zlapac wyjatek NULL dla getOrganizm
				else
					cout << ' ';
			}
		}
		cout << "#\n";
	}
	wypiszLinieRamki();
	/*
	list <Organizm*> ::iterator it;
	for (it = organizmy.begin(); it != organizmy.end(); it++)
	{
		cout << typeid(**it).name() << " x = " << (*it)->getX() << " y = " << (*it)->getY() << endl;
	}
	*/
	// wypisywanie informacji o walkach itp.
	komentator->wypiszKomentarze();
	komentator->usunKomentarze();
	//cout << getCzlowiek()->getSila() << endl;
	wypiszLinieRamki();
}
void World::wykonajTure()
{
	if (tura == 0)
		generujSwiat();
	else
	{
		system("cls");
		list <Organizm*> :: iterator it;
		dynamic_cast<Czlowiek*>(getCzlowiek())->sprawdzUmiejetnosc();
		for (it = organizmy.begin(); it != organizmy.end(); it++)
		{
			if ((*it)->isAlive() == true)
				(*it)->akcja();
		}
		usunCiala();
		generujSwiat();
		rysujSwiat();
	}
	tura++;
}

void World::wypiszLinieRamki() const
{
	for (int i = 0; i < x + 2; i++)
		cout << '#';
	cout << endl;
}

bool World::isXYfree(int x, int y) const
{
	if (pole[y][x] == EMPTY)
		return true;
	else
		return false;
}


void World::dodajOrganizm(Organizm* org)
{
	organizmy.push_back(org);
	organizmy.sort(org_comp_t());
}

xy_t World::findEmpty(int x, int y) const
{
	xy_t xy;
	if (isXYinWorld(x - 1, y) && isXYfree(x - 1, y))
	{
		xy.x = x - 1;
		xy.y = y;
		return xy;
	}
	if (isXYinWorld(x - 1, y - 1) && isXYfree(x - 1, y - 1))
	{
		xy.x = x - 1;
		xy.y = y - 1;
		return xy;
	}
	if (isXYinWorld(x - 1, y + 1) && isXYfree(x - 1, y + 1))
	{
		xy.x = x - 1;
		xy.y = y + 1;
		return xy;
	}
	if (isXYinWorld(x, y - 1) && isXYfree(x, y - 1))
	{
		xy.x = x ;
		xy.y = y - 1;
		return xy;
	}
	if (isXYinWorld(x, y + 1) && isXYfree(x, y + 1))
	{
		xy.x = x;
		xy.y = y + 1;
		return xy;
	}
	if (isXYinWorld(x + 1, y - 1) && isXYfree(x + 1, y - 1))
	{
		xy.x = x + 1;
		xy.y = y - 1;
		return xy;
	}
	if (isXYinWorld(x + 1, y) && isXYfree(x + 1, y))
	{
		xy.x = x + 1;
		xy.y = y;
		return xy;
	}
	if (isXYinWorld(x + 1, y + 1) && isXYfree(x + 1, y + 1))
	{
		xy.x = x + 1;
		xy.y = y + 1;
		return xy;
	}
	xy.x = -1;
	xy.y = -1;
	return xy;
}

xy_t World::findAnyField(int x, int y) const
{
	xy_t xy;
	bool found = false;
	while (!found)
	{
		switch (rand() % 8)
		{
		case 0:
			if (isXYinWorld(x + 1, y + 1))
			{
				found = true;
				xy.x = x + 1;
				xy.y = y;
			}
			break;
		case 1:
			if (isXYinWorld(x + 1, y))
			{
				found = true;
				xy.x = x + 1;
				xy.y = y;
			}
			break;
		case 2:
			if (isXYinWorld(x - 1, y))
			{
				found = true;
				xy.x = x - 1;
				xy.y = y;
			}
			break;
		case 3:
			if (isXYinWorld(x, y + 1))
			{
				found = true;
				xy.x = x;
				xy.y = y + 1;
			}
			break;
		case 4:
			if (isXYinWorld(x, y - 1))
			{
				found = true;
				xy.x = x;
				xy.y = y - 1;
			}
			break;
		case 5:
			if (isXYinWorld(x + 1, y - 1))
			{
				found = true;
				xy.x = x + 1;
				xy.y = y - 1;
			}
			break;
		case 6:
			if (isXYinWorld(x - 1, y - 1))
			{
				found = true;
				xy.x = x - 1;
				xy.y = y - 1;
			}
			break;
		case 7:
			if (isXYinWorld(x - 1, y + 1))
			{
				found = true;
				xy.x = x - 1;
				xy.y = y + 1;
			}
			break;
		}
	}
	return xy;
}

bool World::isXYinWorld(int x, int y) const
{
	if (x >= 0 && x < this->x && y >= 0 && y < this->y)
		return true;
	else
		return false;
}

bool World::porownajInicjatywe(const Organizm& org1, const Organizm& org2) const
{
	if (org1.getInicjatywa() == org2.getInicjatywa())
	{
		if (org1.getTura() < org2.getTura())
			return true;
		else
			return false;
	}
	else if (org1.getInicjatywa() > org2.getInicjatywa())
		return true;
	else
		return false;
}

bool World::czyRoslina(Organizm * org)
{
	if (typeid(*org) == typeid(Mlecz) || typeid(*org) == typeid(Trawa) || typeid(*org) == typeid(Guarana) ||
		typeid(*org) == typeid(WilczeJagody) || typeid(*org) == typeid(BarszczSosnowskiego))
		return true;
	else
		return false;
}

Organizm* World::getCzlowiek()
{
	try
	{
		list <Organizm*> ::iterator it;
		for (it = organizmy.begin(); it != organizmy.end(); it++)
		{
			if (typeid(**it) == typeid(Czlowiek))
				return *it;
		}
		throw std::invalid_argument("Nie znaleziono czlowieka");
	}
	catch (const std::invalid_argument& e)
	{
		system("cls");
		cout << e.what() << endl;
		_getch();
		return NULL;
	}
}

void World::setTura(int t)
{
	tura = t;
}

void World::usunPlansze()
{
	for (int i = 0; i < y; i++)
		delete[] pole[i];
	delete[] pole;
	pole = NULL;
}

void World::usunListe()
{
	list <Organizm*> ::iterator it;
	list <Organizm*> ::iterator toErase;
	int listSize = organizmy.size();
	it = organizmy.begin();
	for (int i = 0; i < listSize; i++)
	{
		toErase = it;
		it++;
		delete *toErase;
		organizmy.erase(toErase);
	}
}

void World::nowaPlansza(int x, int y, int tura)
{
	usunPlansze();
	this->x = x;
	this->y = y;
	pole = new pole_t*[y];
	for (int i = 0; i < y; i++)
		pole[i] = new pole_t[x];
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
			pole[i][j] = EMPTY;
	}
	this->tura = tura;
}

Organizm * World::stworzOrganizmTypu(pole_t pole, int x, int y)
{
	Organizm* organizm;
	switch (pole) // po zaimplemoentowaniiu dodac do switcha
	{
	case TRAWA:
		organizm = new Trawa(x, y, tura, this);
		break;
	case WILK:
		organizm = new Wilk(x, y, tura, this);
		break;
	case OWCA:
		organizm = new Owca(x, y, tura, this);
		break;
	case LIS:
		organizm = new Lis(x, y, tura, this);
		break;
	case ZOLW:
		organizm = new Zolw(x, y, tura, this);
		break;
	case ANTYLOPA:
		organizm = new Antylopa(x, y, tura, this);
		break;
	case MLECZ:
		organizm = new Mlecz(x, y, tura, this);
		break;
	case GUARANA:
		organizm = new Guarana(x, y, tura, this);
		break;
	case WILCZE_JAG:
		organizm = new WilczeJagody(x, y, tura, this);
		break;
	case BARSZCZ:
		organizm = new BarszczSosnowskiego(x, y, tura, this);
		break;
	default:
		organizm = NULL;
		break;
	}
	if (organizm != NULL)
	{
		this->pole[y][x] = pole;
		dodajOrganizm(organizm);
	}
	return organizm;
}

Organizm * World::wczytajOrganizm(pole_t pole, int x, int y, int sila, int tura, int licznik)
{
	Organizm* organizm;
	switch (pole) // po zaimplemoentowaniiu dodac do switcha
	{
	case TRAWA:
		organizm = new Trawa(x, y, tura, this);
		break;
	case WILK:
		organizm = new Wilk(x, y, tura, this, sila);
		break;
	case OWCA:
		organizm = new Owca(x, y, tura, this, sila);
		break;
	case LIS:
		organizm = new Lis(x, y, tura, this, sila);
		break;
	case ZOLW:
		organizm = new Zolw(x, y, tura, this, sila);
		break;
	case ANTYLOPA:
		organizm = new Antylopa(x, y, tura, this, sila);
		break;
	case MLECZ:
		organizm = new Mlecz(x, y, tura, this);
		break;
	case GUARANA:
		organizm = new Guarana(x, y, tura, this);
		break;
	case WILCZE_JAG:
		organizm = new WilczeJagody(x, y, tura, this);
		break;
	case BARSZCZ:
		organizm = new BarszczSosnowskiego(x, y, tura, this);
		break;
	case CZLOWIEK:
		organizm = new Czlowiek(x, y, tura, this, sila,licznik);
		break;
	default:
		organizm = NULL;
		break;
	}
	if (organizm != NULL)
	{
		this->pole[y][x] = pole;
		dodajOrganizm(organizm);
	}
	return organizm;
}
void World::zyj()
{
	bool dzialaj = true;
	generujSwiat();
	rysujSwiat();
	tura = 1;
	Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(getCzlowiek());
	while (dzialaj)
	{
		if (koniecGry)
		{
			komentator->komentujSmiercCzlowieka();
			system("cls");
			rysujSwiat();
			_getch();
			_getch();
			break;
		}
		switch (_getch())
		{
		case SPACE:
			if (czlowiek->aktywujUmiejetnosc())
			{
				komentator->komentujAktywacjeUm();
				system("cls");
				rysujSwiat();
			}
			break;
		case ESC:
			dzialaj = false;
			break;
		case S_KEY:
			if (obs->zapiszGre(organizmy, dynamic_cast<Czlowiek*>(getCzlowiek()), this))
			{
				komentator->komentujZapis();
				system("cls");
				rysujSwiat();
			}
			break;
		case L_KEY:
			if (obs->wczytajGre(this))
			{
				komentator->komentujWczytanie();
				system("cls");
				rysujSwiat();
				czlowiek = dynamic_cast<Czlowiek*>(getCzlowiek());
			}
			break;
		case SPECIAL_KEY:
			switch (_getch())
			{
			case UP:
				czlowiek->setKierunek(GORA);
				break;
			case DOWN:
				czlowiek->setKierunek(DOL);
				break;
			case LEFT:
				czlowiek->setKierunek(LEWO);
				break;
			case RIGHT:
				czlowiek->setKierunek(PRAWO);
				break;
			}
			wykonajTure();
			break;
		}
	}
	/*
	if (_getch() == SPACE)
	{
		czlowiek->aktywujUmiejetnosc();
		_getch();
	}
	int funkcja;
	while (dzialaj) // co po smierci?
	{
		
		switch (_getch()) // problem z podwojna spacja
		{
		case UP:
			czlowiek->setKierunek(GORA);
			break;
		case DOWN:
			czlowiek->setKierunek(DOL);
			break;
		case LEFT:
			czlowiek->setKierunek(LEWO);
			break;
		case RIGHT:
			czlowiek->setKierunek(PRAWO);
			break;
		case ESC:
			dzialaj = false;
			break;
		default:
			break;
		}
		wykonajTure();
		funkcja = _getch();
		if (funkcja == ESC)
			dzialaj = false;
		else if (funkcja == SPACE)
		{
			czlowiek->aktywujUmiejetnosc();
			_getch();
		}
		else if (funkcja == S_KEY)
		{
			obs->zapiszGre(organizmy,dynamic_cast<Czlowiek*>(getCzlowiek()),this);
			_getch();
		}
		else if (funkcja == L_KEY)
		{
			obs->wczytajGre(this);
			system("cls");
			rysujSwiat();
			_getch();
		}
	}
	*/
}

World::~World()
{
	//usuwanie planszy swiata
	usunPlansze();
	//usuwanie organizmow z listy
	usunListe();
	delete komentator;
	delete obs;
}
