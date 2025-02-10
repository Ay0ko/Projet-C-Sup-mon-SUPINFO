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
    return (rand() % 9) + 1;
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

void doMove(struct Supemon *opSupemon, struct Player *joueur) {
    printf("");
};

void changeSupemon(struct Player *joueur) {
    printf("");
};

void useItem(struct Player *joueur) {
    printf("");
};

void catchSupemon(struct Supemon *opSupemon, struct Player *joueur) {
    printf("");
};

void battleOption(struct Supemon *opSupemon, struct Player *joueur) {
    printf("You've come across a %c.\n");
    int option = choix();
    while (option < 1 || option > 4) {
        printf("\nInvalid choice ! Choose a valid option.\n");
        printf("Enter 1, 2, 3, 4 or 5: ");
        option = choix();
    }
    if (option == 1) {
        printf("");
    }
    else if (option == 2) {
        printf("");
    }
    else if (option == 3) {
        printf("");
    }
    else if (option == 4) {
        printf("");
    }
    else {
        printf("");
    }
};