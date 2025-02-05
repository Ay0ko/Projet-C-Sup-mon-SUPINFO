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
    int ATK;
    int DEF;
    int evasion;
    int accuracy;
    int speed;
};

struct Starter Supmander = {1,0,10, 1, 1, 1, 2, 1};
struct Starter Supasaur = {1,0,9, 1, 1, 3, 2, 2};
struct Starter Supirtle = {1,0,11, 1, 2, 2, 1, 2};

struct Supemon{
    int id;
    int lvl;
    int xprap;
    int HP;
    int ATK;
    int DEF;
    int evasion;
    int accuracy;
    int speed;
};

struct Supemon Patrat = (1, 1)
