#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#ifndef DOSSIERH_H_INCLUDED
#define DOSSIERH_H_INCLUDED

struct Shop {
    int Potion[3];
    int SuperPotion[3];
    int RareCandy[3];
};

extern struct Shop shop;

struct Player {
    char name;
    int Supemons[6];
    int SupemonCount;
    int SelectedSupemon;
    int Supcoins;
    char Items[500];
};

struct Starter {
    int id;
    int lvl;
    int xp;
    int HP;
    int maxHP;
    int ATK;
    int DEF;
    int evasion;
    int accuracy;
    int speed;
};

struct Supemon{
    int id;
    int lvl;
    int xprap;
    int HP;
    int maxHP;
    int ATK;
    int DEF;
    int evasion;
    int accuracy;
    int speed;
};

extern struct Starter Supmander;
extern struct Starter Supasaur;
extern struct Starter Supirtle;
extern struct Supemon Patrat;
extern struct Supemon Eevee;
extern struct Supemon Grimer;
extern struct Supemon Abra;
extern struct Supemon Turtwig;
extern struct Supemon Glaceon;

#endif // DOSSIERH_H_INCLUDED