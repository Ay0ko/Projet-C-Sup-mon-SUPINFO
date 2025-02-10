#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>
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
    printf("m");
};

void changeSupemon(struct Player *joueur) {
    printf("m");
};

void useItem(struct Player *joueur) {
    printf("m");
};

void catchSupemon(struct Supemon *opSupemon, struct Player *joueur) {
    printf("m");
};

void battleOption(struct Supemon *opSupemon, struct Player *joueur) {
    printf("You've come across a %s.\n", opSupemon->nameSupe);
    usleep(350000);
    system("clear");
    printf("Your turn...\n");
    printf("%49s  (enemy)\n", opSupemon->nameSupe);
    printf("----------------------------------------\n");
    printf("    HP: %3d/%-3d           Lvl: %2d\n", opSupemon->HP, opSupemon->maxHP, opSupemon->lvl);
    printf("    Atk: %2d               Def: %2d\n", opSupemon->actuATK, opSupemon->actuDEF);
    printf("    Acc: %2d               Eva: %2d\n", opSupemon->actuAccuracy, opSupemon->actuEvasion);
    printf("----------------------------------------\n");
    printf("%s  (%s)\n", joueur->selectedSupemon->nameSupe, joueur->name);
    printf("----------------------------------------\n");
    printf("    HP: %3d/%-3d           Lvl: %2d\n", joueur->selectedSupemon->HP, joueur->selectedSupemon->maxHP, joueur->selectedSupemon->lvl);
    printf("    Atk: %2d               Def: %2d\n", joueur->selectedSupemon->actuATK, joueur->selectedSupemon->actuDEF);
    printf("    Acc: %2d               Eva: %2d\n", joueur->selectedSupemon->actuAccuracy, joueur->selectedSupemon->actuEvasion);
    printf("----------------------------------------\n");

    printf("\n+--------------------------------------+\n");
    printf("| What will you do ?                   |\n");
    printf("|   1 - Move                           |\n");
    printf("|   2 - Change Supemon                 |\n");
    printf("|   3 - Use item                       |\n");
    printf("|   4 - Capture                        |\n");
    printf("|   5 - Run away                       |\n");
    printf("+--------------------------------------+\n");
    printf("1, 2, 3, 4 or 5: ");
    int option = choix();
    while (option < 1 || option > 4) {
        printf("\nInvalid choice ! Choose a valid option.\n");
        printf("Enter 1, 2, 3, 4 or 5: ");
        option = choix();
    }
    if (option == 1) {
        printf("m");
    }
    else if (option == 2) {
        printf("m");
    }
    else if (option == 3) {
        printf("m");
    }
    else if (option == 4) {
        printf("m");
    }
    else {
        printf("m");
    }
};