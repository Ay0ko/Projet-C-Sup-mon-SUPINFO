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
    int i = (rand() % 9) + 1;
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

void doMove(struct Supemon *opSupemon, struct Player *joueur, int choosed) {
   if (joueur->selectedSupemon->moves[choosed].name == "Scratch" || joueur->selectedSupemon->moves[choosed].name == "Pound") {
        if (!chanceEsquive(opSupemon, joueur->selectedSupemon)) {
            opSupemon->HP-=aleaArrondi(joueur->selectedSupemon->actuATK*joueur->selectedSupemon->moves[0].damage/opSupemon->actuDEF);
            battleOption(opSupemon, joueur);
        }
        else {
            printf("Oh no, %s managed to dodge your attack !", opSupemon->nameSupe);
            battleOption(opSupemon, joueur);
        }
   }
   else if (joueur->selectedSupemon->moves[choosed].name == "Shell") {
    joueur->selectedSupemon->actuDEF+=joueur->selectedSupemon->moves[choosed].BoostDEF;
    battleOption(opSupemon, joueur);
   }
   else if (joueur->selectedSupemon->moves[choosed].name == "Grawl") {
    joueur->selectedSupemon->actuATK+=joueur->selectedSupemon->moves[choosed].BoostATK;
    battleOption(opSupemon, joueur);
   }
   else {
    joueur->selectedSupemon->actuEvasion+=joueur->selectedSupemon->moves[choosed].BoostEvasion;
    battleOption(opSupemon, joueur);
   }
};

void changeSupemon(struct Player *joueur) {
    printf("\n+--------------------------------------+\n");
    printf("| Supemon : %d/6                        |\n", countSupemons(joueur));
    printf("| --> %14s                   |\n", joueur->team[0].nameSupe);
    printf("|   2 - Change Supemon                 |\n");
    printf("|   3 - Use item                       |\n");
    printf("|   4 - Capture                        |\n");
    printf("|   5 - Run away                       |\n");
    printf("+--------------------------------------+\n");
};

void useItem(struct Player *joueur) {
    printf("m");
};

void catchSupemon(struct Supemon *opSupemon, struct Player *joueur) {
    printf("m");
};

void battleOption(struct Supemon *opSupemon, struct Player *joueur) {
    printf("\nYou've come across a %s.\n", opSupemon->nameSupe);
    usleep(3000000);
    system("clear");
    printf("\nYour turn...\n");
    displayBattle(opSupemon, joueur);
    int option = choix();
    while (option < 1 || option > 4) {
        printf("\nInvalid choice ! Choose a valid option.\n");
        printf("Enter 1, 2, 3, 4 or 5: ");
        option = choix();
    }
    if (option == 1) {
        printf("\n1 - %s\n", joueur->selectedSupemon->moves[0].name);
        printf("2 - %s\n", joueur->selectedSupemon->moves[1].name);
        printf("3 - Cancel\n");
        printf("Enter 1, 2 or 3: ");
        int mvt = choix();
        doMove(opSupemon, joueur, mvt);
    }
    else if (option == 2) {
        changeSupemon(joueur);
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