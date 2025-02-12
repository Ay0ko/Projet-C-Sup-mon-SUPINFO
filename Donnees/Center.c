#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"



void restore_hp(struct Player *joueur) {
    if (!joueur || joueur->SupemonCount <= 0) {
        printf("Error: Player or team not initialized!\n");
        return;
    }

    printf("+---------------------------------------+\n");
    printf("| Would you like to heal your Supemons? |\n");
    printf("|      1 - Yes                          |\n");
    printf("|      2 - No, thanks                   |\n");
    printf("+---------------------------------------+\n");
    printf("Enter 1 or 2: ");

    int choice = choix();
    while (choice < 1 || choice > 2) {
        printf("Invalid choice! Choose a valid option.\n");
        printf("Enter 1 or 2: ");
        choice = choix();
    }

    if (choice == 1) {
        if (joueur->selectedSupemon) {
            joueur->selectedSupemon->HP = joueur->selectedSupemon->maxHP;
            joueur->selectedSupemon->actuATK = joueur->selectedSupemon->ATK;
            joueur->selectedSupemon->actuDEF = joueur->selectedSupemon->DEF;
            joueur->selectedSupemon->actuEvasion = joueur->selectedSupemon->evasion;
            joueur->selectedSupemon->actuAccuracy = joueur->selectedSupemon->accuracy;
        }
        
        for (int i = 1; i < joueur->SupemonCount + 1; i++) {
            joueur->team[i].HP = joueur->team[i].maxHP;
            joueur->team[i].actuATK = joueur->team[i].ATK;
            joueur->team[i].actuDEF = joueur->team[i].DEF;
            joueur->team[i].actuEvasion = joueur->team[i].evasion;
            joueur->team[i].actuAccuracy = joueur->team[i].accuracy;
        }

        printf("+---------------------------------------+\n");
        printf("|                Thanks                 |\n");
        printf("|    Your Supemons have been healed     |\n");
        printf("|         Hope to see you again         |\n");
        printf("+---------------------------------------+\n");
        usleep(2000000);
    }

    printf("\033[H\033[J");
}