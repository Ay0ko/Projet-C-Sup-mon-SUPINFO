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
   if (strcmp(joueur->selectedSupemon->moves[choosed].name, "Scratch") == 0 || strcmp(joueur->selectedSupemon->moves[choosed].name, "Pound") == 0) {
        if (!chanceEsquive(opJoueur->selectedSupemon, joueur)) {
            opJoueur->selectedSupemon->HP-=joueur->selectedSupemon->moves[choosed].damage;
            printf("\033[H\033[J");
            choixEnemymove(opJoueur, joueur, rand() % 2);
        }
        else {
            printf("Oh no, %s managed to dodge your attack !", opJoueur->selectedSupemon->nameSupe);
            usleep(2500000);
            printf("\033[H\033[J");
            battleOption(opJoueur, joueur);
        }
   }
   else if (joueur->selectedSupemon->moves[choosed].name == "Shell") {
    joueur->selectedSupemon->actuDEF+=joueur->selectedSupemon->moves[choosed].BoostDEF;
    printf("\033[H\033[J");
    printf("Your %s used 'Shell' !\n", joueur->selectedSupemon->nameSupe);
    usleep(2500000);
    printf("\033[H\033[J");
    battleOption(opJoueur, joueur);
   }
   else if (joueur->selectedSupemon->moves[choosed].name == "Grawl") {
    joueur->selectedSupemon->actuATK+=joueur->selectedSupemon->moves[choosed].BoostATK;
    printf("\033[H\033[J");
    printf("Your %s used 'Grawll' !\n", joueur->selectedSupemon->nameSupe);
    usleep(2500000);
    printf("\033[H\033[J");
    battleOption(opJoueur, joueur);
   }
   else {
    joueur->selectedSupemon->actuEvasion+=joueur->selectedSupemon->moves[choosed].BoostEvasion;
    printf("\033[H\033[J");
    printf("Your %s used 'Foliage' !\n", joueur->selectedSupemon->nameSupe);
    usleep(2500000);
    printf("\033[H\033[J");
    battleOption(opJoueur, joueur);
   }
};

void RecompencePiece(struct Player *joueur){
    int RecompenceMin= 100;
    int RecompenceMax= 500;
    int Recompence = rand() % (RecompenceMax - RecompenceMin + 1) + RecompenceMin;
    joueur->Supcoins+=Recompence;
    printf("\nYou've earned %d Supcoins !\n", Recompence);
};

void choixEnemymove(struct Player *opJoueur, struct Player *joueur, int choosed) {
    if (strcmp(opJoueur->selectedSupemon->moves[choosed].name, "Scratch") == 0 || 
        strcmp(opJoueur->selectedSupemon->moves[choosed].name, "Pound") == 0) {
        
        if (!chanceEsquive(joueur->selectedSupemon, opJoueur)) {
            joueur->selectedSupemon->HP -= opJoueur->selectedSupemon->moves[choosed].damage;
            printf("\nThe enemy used %s! You took %d damage.\n",
                   opJoueur->selectedSupemon->moves[choosed].name,
                   opJoueur->selectedSupemon->moves[choosed].damage);
        } else {
            printf("\033[H\033[J");
            printf("You managed to dodge the attack!\n");
            usleep(2500000);
        }
    }
}

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
    printf("Wich Supemon would you like to swap with your %s ?\n", joueur->selectedSupemon->nameSupe);
    printf("Enter 1, 2, 3, 4, 5, 6 or 7 to cancel: ");
    int supSwap = choix();
    while(supSwap < 1 || supSwap > 7) {
        printf("\nInvalid choice ! Choose a valid option.\n");
        printf("Enter 1, 2, 3, 4, 5, 6 or 7 to cancel: ");
        int supSwap = choix();
    }
    if (supSwap == 7) {
        int i;
    }
};

void capture(struct Player *opJoueur, struct Player *joueur) {
    if (captureSupemon(opJoueur)) {
        addSupemon(opJoueur->selectedSupemon, joueur);
        printf("\033[H\033[J");
        printf("\nCongratulations, you've captured %s ! %s as joined your team !\n",opJoueur->selectedSupemon->nameSupe, opJoueur->selectedSupemon->nameSupe);
        usleep(2500000);
    }
    else {
        printf("\033[H\033[J");
        printf("\nOh nooo, you failed to capture %s !\n",opJoueur->selectedSupemon->nameSupe);
        usleep(2500000);
        printf("\033[H\033[J");
        choixEnemymove(opJoueur, joueur, rand() % 2);
    }
};

void FuiteCombat(struct Player *opJoueur, struct Player *joueur) {
    if (chancefuite(joueur->selectedSupemon, opJoueur)) {
        printf("\nYou're on the run !\n");
        printf("\033[H\033[J");
        choisirDirection(opJoueur, joueur);
    }
    else {
        printf("\033[H\033[J");
        printf("\nYou failed to escape !\n");
        usleep(2000000);
        printf("\033[H\033[J");
        enemyMove(opJoueur, joueur);
        printf("\033[H\033[J");
        battleOption(opJoueur, joueur);
    }
};

void useItem(struct Player *joueur) {
    printf("m");
};

void enemyMove(struct Player *opJoueur, struct Player *joueur) {
    printf("\n%s's turn...\n", opJoueur->selectedSupemon->nameSupe);
    usleep(2500000);
    srand(time(NULL));  
    int attaque = rand() % 2; 
    printf("\n%s uses %s!\n", opJoueur->selectedSupemon->nameSupe, opJoueur->selectedSupemon->moves[attaque].name);
    usleep(2000000);
    printf("\033[H\033[J");
    choixEnemymove(opJoueur, joueur, attaque);
};


void SetBattle(struct Player *opJoueur, struct Player *joueur) {
    printf("\nYou've come across a %s.\n", opJoueur->selectedSupemon->nameSupe);
    usleep(3000000);
    printf("\033[H\033[J");
    int joueurStart;
    if (joueur->selectedSupemon->speed > opJoueur->selectedSupemon->speed) {
        joueurStart = 1;
    } else if (joueur->selectedSupemon->speed < opJoueur->selectedSupemon->speed) {
        joueurStart = 0;
    } else {
        joueurStart = aleaArrondi(0.5); 
    }
    while (joueur->selectedSupemon->HP > 0 && opJoueur->selectedSupemon->HP > 0) {
        if (joueurStart){
            printf("\nYour turn...\n");
            battleOption(opJoueur, joueur);
        }
        else {
            enemyMove(opJoueur, joueur);
        }   
        joueurStart = !joueurStart;
        }
        if (joueur->selectedSupemon->HP <= 0) {
            printf("\nYour Supemon has been defeated ! You have been forced to flee !\n");
        } else if (opJoueur->selectedSupemon->HP <= 0) {
            printf("\nYou have won %s !\n", opJoueur->selectedSupemon->nameSupe);
            RecompencePiece(joueur);
        }
};



void battleOption(struct Player *opJoueur, struct Player *joueur) {
    displayBattle(opJoueur, joueur);

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

        if (mvt == 1 || mvt == 2) {
            doMove(opJoueur, joueur, mvt - 1);
        }
    } else if (option == 2) {
        changeSupemon(joueur);
    } else if (option == 3) {
        printf("m");
    } else if (option == 4) {
        capture(opJoueur, joueur);
    } else {
        FuiteCombat(opJoueur, joueur);
    }
}
