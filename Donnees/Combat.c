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

int gainExperience(int enemyLevel) {
    srand(time(NULL));  
    int minXP = 100 * enemyLevel;
    int maxXP = 500 * enemyLevel;
    int Gainex = (rand() % (maxXP - minXP + 1)) + minXP;
    printf("\nYou've earned %d XP!\n", Gainex);
}


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
            printf("\nYour %s used '%s' ! This attack deals %d damages to the enemy's Supemon.\n", joueur->selectedSupemon->nameSupe, joueur->selectedSupemon->moves[choosed].name, joueur->selectedSupemon->moves[choosed].damage);
            usleep(3000000);
            printf("\033[H\033[J");
        }
        else {
            printf("\033[H\033[J");
            printf("Oh no, %s managed to dodge your attack !", opJoueur->selectedSupemon->nameSupe);
            usleep(2500000);
            printf("\033[H\033[J");
            battleOption(opJoueur, joueur);
        }
   }
   else if (strcmp(joueur->selectedSupemon->moves[choosed].name, "Shell") == 0) {
    joueur->selectedSupemon->actuDEF+=joueur->selectedSupemon->moves[choosed].BoostDEF;
    printf("\033[H\033[J");
    printf("Your %s used 'Shell' ! This ability increases your Supemon's DEF by %d.\n", joueur->selectedSupemon->nameSupe, joueur->selectedSupemon->moves[choosed].BoostDEF);
    usleep(3000000);
    printf("\033[H\033[J");
   }
   else if (strcmp(joueur->selectedSupemon->moves[choosed].name, "Grawl") == 0) {
    joueur->selectedSupemon->actuATK+=joueur->selectedSupemon->moves[choosed].BoostATK;
    printf("\033[H\033[J");
    printf("Your %s used 'Grawl' ! This ability increases your Supemon's ATK by %d.\n", joueur->selectedSupemon->nameSupe, joueur->selectedSupemon->moves[choosed].BoostATK);
    usleep(3000000);
    printf("\033[H\033[J");
   }
   else if (strcmp(joueur->selectedSupemon->moves[choosed].name, "Foliage") == 0) {
    joueur->selectedSupemon->actuEvasion+=joueur->selectedSupemon->moves[choosed].BoostEvasion;
    printf("\033[H\033[J");
    printf("Your %s used 'Foliage' ! This ability increases your Supemon's Evasion by %d.\n", joueur->selectedSupemon->nameSupe, joueur->selectedSupemon->moves[choosed].BoostEvasion);
    usleep(3000000);
    printf("\033[H\033[J");
   }
};


void RecompencePiece(struct Player *joueur) {
    int RecompenseMin = 100, RecompenseMax = 500;
    int Recompense = rand() % (RecompenseMax - RecompenseMin + 1) + RecompenseMin;
    joueur->Supcoins += Recompense;
    printf("\nYou've earned %d Supcoins!\n", Recompense);
};


void choixEnemymove(struct Player *opJoueur, struct Player *joueur, int choosed) {
    if (strcmp(opJoueur->selectedSupemon->moves[choosed].name, "Scratch") == 0 || strcmp(opJoueur->selectedSupemon->moves[choosed].name, "Pound") == 0) {
        if (!chanceEsquive(joueur->selectedSupemon, opJoueur)) {
            joueur->selectedSupemon->HP -= opJoueur->selectedSupemon->moves[choosed].damage;
            printf("\nThe enemy used %s! It will deals %d damages to your Supemon.\n", opJoueur->selectedSupemon->moves[choosed].name, opJoueur->selectedSupemon->moves[choosed].damage);
            usleep(3000000);
            printf("\033[H\033[J");
        } else {
            printf("\033[H\033[J");
            printf("You managed to dodge the attack!\n");
            usleep(3000000);
            printf("\033[H\033[J");
            displayBattle(opJoueur, joueur);
            int next = choix();
            doMove(opJoueur, joueur, next - 1);
        }
    }
    else if (strcmp(opJoueur->selectedSupemon->moves[choosed].name, "Shell") == 0) {
        opJoueur->selectedSupemon->actuDEF+=opJoueur->selectedSupemon->moves[choosed].BoostDEF;
        printf("\033[H\033[J");
        printf("%s uses 'Shell' ! This ability will increase its Supemon's DEF by %d.\n", opJoueur->selectedSupemon->nameSupe, opJoueur->selectedSupemon->moves[choosed].BoostDEF);
        usleep(3000000);
        printf("\033[H\033[J");
        displayBattle(opJoueur, joueur);
        int next = choix();
        doMove(opJoueur, joueur, next - 1);
       }
       else if (strcmp(joueur->selectedSupemon->moves[choosed].name, "Grawl") == 0) {
        opJoueur->selectedSupemon->actuATK+=opJoueur->selectedSupemon->moves[choosed].BoostATK;
        printf("\033[H\033[J");
        printf("%s used 'Grawl' ! This ability will increase its Supemon's ATK by %d.\n", opJoueur->selectedSupemon->nameSupe, opJoueur->selectedSupemon->moves[choosed].BoostATK);
        usleep(3000000);
        printf("\033[H\033[J");
        displayBattle(opJoueur, joueur);
        int next = choix();
        doMove(opJoueur, joueur, next - 1);
       }
       else if (strcmp(joueur->selectedSupemon->moves[choosed].name, "Foliage") == 0) {
        opJoueur->selectedSupemon->actuEvasion+=opJoueur->selectedSupemon->moves[choosed].BoostEvasion;
        printf("\033[H\033[J");
        printf("%s used 'Foliage' ! This ability will increase its Supemon's Evasion by %d.\n", opJoueur->selectedSupemon->nameSupe, opJoueur->selectedSupemon->moves[choosed].BoostEvasion);
        usleep(3000000);
        printf("\033[H\033[J");
        displayBattle(opJoueur, joueur);
        int next = choix();
        doMove(opJoueur, joueur, next - 1);
       }
};


void changeSupemon(struct Player *opSupemon, struct Player *joueur) {
    // printf("\n+--------------------------------------+\n");
    // printf("| Supemon : %d/6                        |\n", countSupemons(joueur));
    // printf("| --> %14s                   |\n", joueur->team[0].nameSupe);
    // printf("| --> %14s                   |\n", joueur->team[1].nameSupe);
    // printf("| --> %14s                   |\n", joueur->team[2].nameSupe);
    // printf("| --> %14s                   |\n", joueur->team[3].nameSupe);
    // printf("| --> %14s                   |\n", joueur->team[4].nameSupe);
    // printf("| --> %14s                   |\n", joueur->team[5].nameSupe);
    // printf("+--------------------------------------+\n");
    // printf("Wich Supemon would you like to swap with your %s ?\n", joueur->selectedSupemon->nameSupe);
    // printf("Enter 1, 2, 3, 4, 5, 6 or 7 to cancel: ");
    // int supSwap = choix();
    // while(supSwap < 1 || supSwap > 7) {
    //     printf("\nInvalid choice ! Choose a valid option.\n");
    //     printf("Enter 1, 2, 3, 4, 5, 6 or 7 to cancel: ");
    //     int supSwap = choix();
    // }
    // if (supSwap == 7) {
    //     // Going back
    // }
    // else {
    //     if (strcmp(joueur->team[supSwap - 1].nameSupe, joueur->selectedSupemon->nameSupe) == 0) {
    //         printf("\033[H\033[J");
    //         printf("Wrong choice, you choosed the fighting Supemon ! Please pick another one.");
    //         usleep(2500000);
    //         printf("\033[H\033[J");
    //         changeSupemon(opSupemon, joueur);
    //     }
    // }
};


void capture(struct Player *opJoueur, struct Player *joueur) {
    if (captureSupemon(opJoueur)) {
        addSupemon(opJoueur->selectedSupemon, joueur);
        printf("\033[H\033[J");
        printf("\nCongratulations, you've captured %s ! %s as joined your team !\n",opJoueur->selectedSupemon->nameSupe, opJoueur->selectedSupemon->nameSupe);
        usleep(3000000);
        choisirDirection(opJoueur, joueur);
    }
    else {
        printf("\033[H\033[J");
        printf("\nOh nooo, you failed to capture %s !\n",opJoueur->selectedSupemon->nameSupe);
        usleep(3000000);
        printf("\033[H\033[J");
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
        usleep(3000000);
        printf("\033[H\033[J");
        enemyMove(opJoueur, joueur);
    }
};


void useItem(struct Player *opJoueur, struct Player *joueur) {
    int itemChoice = 0;  
    while (1) {
        printf("What object would you like to use ?\n");
        printf("1. Potion (5 HP)\n");
        printf("2. Super Potion (10 HP)\n");
        printf("3. Rare Candy (level up)\n");
        printf("4. Cancel \n");
        printf("Enter 1, 2, 3 or 4 : ");
        scanf("%d", &itemChoice);

        if (itemChoice >= 1 && itemChoice <= 3) {
            break;
        } else if (itemChoice == 4) {
            battleOption(opJoueur, joueur);
        } else {
            printf("Invalid choice. Please choose between 1 and 4.\n");
        }
    }
    if (itemChoice == 1) {  
        int healAmount = 5;
        joueur->selectedSupemon->HP += healAmount;
        if (joueur->selectedSupemon->HP > joueur->selectedSupemon->maxHP) {
            joueur->selectedSupemon->HP = joueur->selectedSupemon->maxHP; 
        }
        printf("%s healed for %d HP!\n", joueur->selectedSupemon->nameSupe, healAmount);

    } else if (itemChoice == 2) {  
        int healAmount = 10;
        joueur->selectedSupemon->HP += healAmount;
        if (joueur->selectedSupemon->HP > joueur->selectedSupemon->maxHP) {
            joueur->selectedSupemon->HP = joueur->selectedSupemon->maxHP;  
        }
        printf("%s healed for %d HP!\n", joueur->selectedSupemon->nameSupe, healAmount);

    } else if (itemChoice == 3) {  
        printf("%s used a Rare Candy!\n", joueur->selectedSupemon->nameSupe);
        niveauSup(joueur->selectedSupemon);  
    }
    printf("\n");
}


void enemyMove(struct Player *opJoueur, struct Player *joueur) {
    printf("\n%s's turn...\n", opJoueur->selectedSupemon->nameSupe);
    usleep(3000000);
    srand(time(NULL));  
    int attaque = rand() % 2; 
    printf("\n%s uses %s!\n", opJoueur->selectedSupemon->nameSupe, opJoueur->selectedSupemon->moves[attaque].name);
    usleep(3000000);
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
            usleep(3000000);
            printf("We'll take care of your Supemon");
            joueur->selectedSupemon->HP = joueur->selectedSupemon->maxHP;
            joueur->selectedSupemon->actuATK = joueur->selectedSupemon->ATK;
            joueur->selectedSupemon->actuDEF = joueur->selectedSupemon->DEF;
            joueur->selectedSupemon->actuEvasion = joueur->selectedSupemon->evasion;
            joueur->selectedSupemon->actuAccuracy = joueur->selectedSupemon->accuracy;
            usleep(2500000);
            printf("\033[H\033[J");
            choisirDirection(opJoueur, joueur);
        } else if (opJoueur->selectedSupemon->HP <= 0) {
            printf("\nYou have won against %s !\n", opJoueur->selectedSupemon->nameSupe);
            RecompencePiece(joueur);
            int gainedXP = gainExperience(opJoueur->selectedSupemon->lvl); 
            joueur->selectedSupemon->xp += gainedXP;
            niveauSup(joueur->selectedSupemon);
            usleep(3000000);
            printf("\033[H\033[J");
            choisirDirection(opJoueur, joueur);
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
        changeSupemon(opJoueur, joueur);
    } else if (option == 3) {
        printf("m");
    } else if (option == 4) {
        capture(opJoueur, joueur);
    } else {
        FuiteCombat(opJoueur, joueur);
    }
};