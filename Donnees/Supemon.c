#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"

struct Starter {
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

struct Starter Supmander = {1,0,10,10,1, 1, 1, 2, 1};
struct Starter Supasaur = {1,0,9,9,1, 1, 3, 2, 2};
struct Starter Supirtle = {1,0,11,11,1, 2, 2, 1, 2};

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

struct Supemon Patrat = {4, 1, 100, 8, 8,1, 1, 1, 2, 1, 2};
struct Supemon Eevee = {5, 1, 110, 10, 10,1, 2, 1, 2, 1, 1};
struct Supemon Grimer = {6, 2, 150, 11, 11, 2, 1, 2, 1, 2, 1};
struct Supemon Abra = {7, 2, 170, 11, 11, 1, 1, 5, 2, 2};
struct Supemon Turtwig = {8, 3, 190, 12, 12, 3, 1, 2, 1, 2, 2};
struct Supemon Glaceon = {9, 3, 200, 12, 12, 2, 2, 1, 2, 1, 3};



