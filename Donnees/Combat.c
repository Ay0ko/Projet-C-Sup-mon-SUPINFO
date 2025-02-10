#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"


int aleaSupemon() {
    int debut = 4;
    int fin = 9;
    return debut + rand() % (fin - debut + 1);
};

int aleaArrondi(float val) {
    srand(time(NULL));
    int kifkif = rand() % 2;
    switch(kifkif) {
        case 0:
            return floor(val);
        case 1:
            return ceil(val);
        default:
            break;
    }
};

bool chanceEsquive(struct Supemon *jSupemon, struct Supemon *opSupemon) {
    float fuite = 0.0;
    fuite = jSupemon->accuracy / (jSupemon->accuracy + opSupemon->evasion) + 0.1;
    return (rand()/(double)RAND_MAX) < fuite ? 1 : 0;
};

bool captureSupemon(struct Supemon *opSupemon) {
    float capture = 0.0;
    capture = (opSupemon->maxHP - opSupemon->HP) / opSupemon->maxHP - 0.5;
    return (rand()/(double)RAND_MAX) < capture ? 1 : 0;
};

void niveauSup(struct Supemon *jSupemon) {
    if (jSupemon->xp > jSupemon->lvl-1 * 1000 + 500) {
        jSupemon->lvl+=1;
        float stat = 0;
        stat = jSupemon->maxHP * 1.30;
        jSupemon->maxHP = aleaArrondi(stat);
        stat = jSupemon->DEF * 1.30;
        jSupemon->DEF = aleaArrondi(stat);
        stat = jSupemon->evasion * 1.30;
        jSupemon->evasion = aleaArrondi(stat);
        stat = jSupemon->accuracy * 1.30;
        jSupemon->accuracy = aleaArrondi(stat);
        stat = jSupemon->speed * 1.30;
        jSupemon->speed = aleaArrondi(stat);
        stat = jSupemon->moves[0].damage * 1.30;
        jSupemon->moves[0].damage = aleaArrondi(stat);
        stat = jSupemon->moves[1].damage * 1.30;
        jSupemon->moves[1].damage = aleaArrondi(stat);
    }
};

int supemonAlea() {
    int i = rand(0, 9);
    printf("%d", i);
    return i;
};

void battleOption(struct Supemon *opSupemon, struct Player *joueur) {
    printf("You've come across a %c.\n");
};