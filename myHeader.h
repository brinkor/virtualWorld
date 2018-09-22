#pragma once
#include <iostream>
using namespace std;

static const int LICZBA_ROZNYCH_ORGANIZMOW = 11;
static const int TEMPO_ROZROSTU = 3; // max 100
static const int SPECIAL_KEY = 224;
static const int UP = 72;
static const int DOWN = 80;
static const int LEFT = 75;
static const int RIGHT = 77;
static const int ESC = 27;
static const int SPACE = 32;
static const int S_KEY = 115;
static const int L_KEY = 108;
static const int SUPER_SILA = 10;

typedef enum
{
	GORA, DOL, LEWO, PRAWO
}kierunek_t;

typedef enum
{
	WIN,LOST,NEW
}wynik_t;

typedef enum
{
	TRAWA, MLECZ, GUARANA, WILCZE_JAG, BARSZCZ, WILK, OWCA, LIS, ZOLW, ANTYLOPA, CZLOWIEK, EMPTY
}pole_t;

typedef struct
{
	int x;
	int y;
}xy_t;