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
    printf("+---------------------------------------+\n");
    printf("| Would you like to heal your Supemons ?|\n");
    printf("|      1 - Yes                          |\n");
    printf("|      2 - No, thanks                   |\n");
    printf("+---------------------------------------+\n");
    printf("Enter 1 or 2 : ");
    int choice = choix();
    while (choice < 1 || choice > 2) {
        printf("Invalid choice ! Choose a valid option.\n");
        printf("Enter 1 or 2 : ");
        choice = choix();
    }
    if (choice == 1) {
        for (int i = 0; i < joueur->SupemonCount + 1; i++) {
            joueur->team[i].HP = joueur->team[i].maxHP;
        }
        printf("+---------------------------------------+\n");
        printf("|                Thanks                 |\n");
        printf("|    Your Supemons have been healed     |\n");
        printf("|         Hope to see you again         |\n");
        printf("+---------------------------------------+\n");
        usleep(2000000);
        system("clear");
        restore_hp(joueur);
    }
    else {
        system("clear");
        choisirDirection(joueur);
    }
};
 