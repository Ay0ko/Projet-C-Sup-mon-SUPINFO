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

bool chanceEsquive(struct Supemon *jSupemon, struct Player *opJoueur) {
    float dodge = 0.0;
    dodge = jSupemon->actuAccuracy / (jSupemon->actuAccuracy + opJoueur->selectedSupemon->actuEvasion) + 0.1;
    return (rand()/(double)RAND_MAX) < dodge;
};

bool chancefuite(struct Supemon *jSupemon, struct Player *opJoueur) {
    float fuite = 0.0;
    fuite = jSupemon->speed / (jSupemon->speed + opJoueur->selectedSupemon->speed);
    return (rand() / (double)RAND_MAX) < fuite;
};

bool captureSupemon(struct Player *opJoueur) {
    float capture = 0.0;
    capture = ((opJoueur->selectedSupemon->maxHP - opJoueur->selectedSupemon->HP) / (float)opJoueur->selectedSupemon->maxHP) - 0.5;
    return (rand() / (double)RAND_MAX) < capture;
};

void niveauSup(struct Supemon *jSupemon) {
    if (jSupemon->xp > ((jSupemon->lvl-1) * 1000 + 500)) {
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

void doMove(struct Player *opJoueur, struct Player *joueur, int choosed) {
   if (strcmp(joueur->selectedSupemon->moves[choosed].name, "Scratch") || strcmp(joueur->selectedSupemon->moves[choosed].name, "Pound")) {
        if (!chanceEsquive(opJoueur, joueur->selectedSupemon)) {
            opJoueur->selectedSupemon->HP-=joueur->selectedSupemon->moves[choosed].damage;
            battleOption(opJoueur, joueur);
        }
        else {
            printf("Oh no, %s managed to dodge your attack !", opSupemon->nameSupe);
            battleOption(opJoueur, joueur);
        }
   }
   else if (joueur->selectedSupemon->moves[choosed].name == "Shell") {
    joueur->selectedSupemon->actuDEF+=joueur->selectedSupemon->moves[choosed].BoostDEF;
    battleOption(opJoueur, joueur);
   }
   else if (joueur->selectedSupemon->moves[choosed].name == "Grawl") {
    joueur->selectedSupemon->actuATK+=joueur->selectedSupemon->moves[choosed].BoostATK;
    battleOption(opJoueur, joueur);
   }
   else {
    joueur->selectedSupemon->actuEvasion+=joueur->selectedSupemon->moves[choosed].BoostEvasion;
    battleOption(opJoueur, joueur);
   }
};

void choixEnemymove(struct Player *opJoueur, struct Player *joueur, int choosed) {
    if (strcmp(opJoueur->selectedSupemon->moves[choosed].name, "Scratch") || strcmp(opJoueur->selectedSupemon->moves[choosed].name, "Pound")) {
        if (!chanceEsquive(joueur->selectedSupemon, opJoueur)) {
            joueur->selectedSupemon->HP-=opJoueur->selectedSupemon->moves[choosed].damage;
            battleOption(opJoueur, joueur);
        }
        else {
            system("clear");
            printf("You managed to dodge the attack !");
            usleep(2500000);
            system("clear");
            battleOption(opJoueur, joueur);
        }
    }
    else if (opJoueur->selectedSupemon->moves[choosed].name == "Shell") {
        opJoueur->selectedSupemon->actuDEF+=opJoueur->selectedSupemon->moves[choosed].BoostDEF;
        battleOption(opJoueur, joueur);
       }
       else if (opJoueur->selectedSupemon->moves[choosed].name == "Grawl") {
        opJoueur->selectedSupemon->actuATK+=opJoueur->selectedSupemon->moves[choosed].BoostATK;
        battleOption(opJoueur, joueur);
       }
       else {
        opJoueur->selectedSupemon->actuEvasion+=opJoueur->selectedSupemon->moves[choosed].BoostEvasion;
        battleOption(opJoueur, joueur);
       }
};

void changeSupemon(struct Player *joueur) {
    printf("\n+--------------------------------------+\n");
    printf("| Supemon : %d/6                        |\n", countSupemons(joueur));
    printf("| --> %14s                   |\n", joueur->team[0].nameSupe);
    printf("| --> %14s                   |\n", joueur->team[1].nameSupe);
    printf("| --> %14s                   |\n", joueur->team[2].nameSupe);
    printf("| --> %14s                   |\n", joueur->team[3].nameSupe);
    printf("| --> %14s                   |\n", joueur->team[4].nameSupe);
    printf("| --> %14s                   |\n", joueur->team[5].nameSupe);
    printf("+--------------------------------------+\n");
};

void capture(struct Player *opJoueur, struct Player *joueur) {
    if (captureSupemon(opSupemon)) {
        addSupemon(opSupemon, joueur);
        printf("\nCongratulations, you've captured %s ! %s as joined your team !\n",opSupemon->nameSupe, opSupemon->nameSupe);
    }
    else {
        printf("\nOh nooo, you failed to capture %s !\n",opSupemon->nameSupe);
        usleep(2000000);
        system("clear");
        enemyMove(opSupemon, joueur);
    }
};

void FuiteCombat(struct Supemon *opSupemon, struct Player *joueur) {
    if (chancefuite(joueur->selectedSupemon, opSupemon)) {
        printf("\nYou're on the run !\n");
        system("clear");
        choisirDirection(joueur);
    }
    else {
        system("clear");
        printf("\nYou failed to escape !\n");
        usleep(2000000);
        system("clear");
        enemyMove(opSupemon, joueur);
        system("clear");
        battleOption(opSupemon, joueur);
    }
};

void useItem(struct Player *joueur) {
    printf("m");
};

void enemyMove(struct Supemon *opSupemon, struct Player *joueur) {
    printf("\n%s's turn...\n", opSupemon->nameSupe);
    usleep(2500000);
    srand(time(NULL));  
    int attaque = rand() % 2; 
    printf("%s uses %s!\n", opSupemon->nameSupe, opSupemon->moves[attaque].name);
    usleep(2000000);
    system("clear");
    choixEnemymove(opSupemon, joueur, attaque);
};


void SetBattle(struct Player *opJoueur, struct Player *joueur) {
    printf("\nYou've come across a %s.\n", opSupemon->nameSupe);
    usleep(3000000);
    system("clear");
    int joueurStart;
    if (joueur->selectedSupemon->speed > opSupemon->speed) {
        joueurStart = 1;
    } else if (joueur->selectedSupemon->speed < opSupemon->speed) {
        joueurStart = 0;
    } else {
        joueurStart = aleaArrondi(0.5); 
    }
    while (1) { 
        if (joueurStart) {
            printf("\nYour turn...\n");
            displayBattle(opSupemon, joueur);
            int option = choix();
            while (option < 1 || option > 5) {
                printf("\nInvalid choice! Choose a valid option.\n");
                printf("Enter 1, 2, 3, 4 or 5: ");
                option = choix();
            }
            if (option == 1) {
                printf("\n1 - %s\n", joueur->selectedSupemon->moves[0].name);
                printf("2 - %s\n", joueur->selectedSupemon->moves[1].name);
                printf("3 - Cancel\n");
                printf("Enter 1, 2 or 3: ");
                int mvt = choix();
                doMove(opSupemon, joueur, mvt - 1);
            } else if (option == 2) {
                changeSupemon(joueur);
            } else if (option == 3) {
                printf("m");
            } else if (option == 4) {
                capture(opSupemon, joueur);
            } else {
                FuiteCombat(opSupemon, joueur);
            }
        } else {
            enemyMove(opSupemon, joueur);
        }
    }
};

void battleOption(struct Player *opJoueur, struct Player *joueur) {
    displayBattle(opSupemon, joueur);
    int option = choix();
    while (option < 1 || option > 5) {
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
        capture(opSupemon, joueur);
    }
    else {
        FuiteCombat(opSupemon, joueur);
    }
};