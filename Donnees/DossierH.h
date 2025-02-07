#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#ifndef DOSSIERH_H_INCLUDED
#define DOSSIERH_H_INCLUDED

struct Shop {
    int Potion[4];
    int SuperPotion[4];
    int RareCandy[4];
};

extern struct Shop shop;

struct Player {
    char name[50];
    int Supemons[6];
    int SupemonCount;
    int SelectedSupemon[6];
    int Supcoins;
    int Items[10];
};

struct Move {
    char name[20];
    int damage;
    int BoostDEF;
    int BoostATK;
    int BoostEvasion;
};


struct Supemon {
    char nameSupe[50];
    int id;
    int lvl;
    int xp;
    int xprap;
    int HP;
    int maxHP;
    int ATK;
    int DEF;
    int evasion;
    int accuracy;
    int speed;
    struct Move moves[2];
};

extern struct Move Scratch; 
extern struct Move Grawl; 
extern struct Move Foliage; 
extern struct Move Pound;  
extern struct Move Shell;
extern struct Supemon Supmander;
extern struct Supemon Supasaur;
extern struct Supemon Supirtle;
extern struct Supemon Patrat;
extern struct Supemon Eevee;
extern struct Supemon Grimer;
extern struct Supemon Abra;
extern struct Supemon Turtwig;
extern struct Supemon Glaceon;

void initializeSupemons();
void initializeShop();

int aleaSupemon();
int aleaArrondi(float val);

#endif // DOSSIERH_H_INCLUDED