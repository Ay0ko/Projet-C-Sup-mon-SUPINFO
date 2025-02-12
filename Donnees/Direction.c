#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"


void choisirDirection(struct Player *opJoueur, struct Player *joueuractu) {
    if (!opJoueur || !joueuractu || !joueuractu->selectedSupemon) {
        printf("Error: Invalid player or Supemon data!\n");
        return;
    }
    for (int i = 0; i < 10; i++) {
        listSupemons[i].HP = listSupemons[i].maxHP;
        listSupemons[i].actuATK = listSupemons[i].ATK;
        listSupemons[i].actuDEF = listSupemons[i].DEF;
        listSupemons[i].actuEvasion = listSupemons[i].evasion;
        listSupemons[i].actuAccuracy = listSupemons[i].accuracy;
    }

    while (1) {  // Boucle principale au lieu de la récursion
        printf("+--------------------------------------+\n");
        printf("|                                      |\n");
        printf("| %14s's XP: %4d/%-4d       |\n", 
               joueuractu->selectedSupemon->nameSupe, 
               joueuractu->selectedSupemon->xp, 
               (joueuractu->selectedSupemon->lvl - 1) * 1000 + 500);
        printf("|                                      |\n");
        printf("|      Your Supcoins: %4d             |\n", joueuractu->Supcoins);
        printf("|                                      |\n");
        printf("+--------------------------------------+\n");
        printf("\n+--------------------------------------+\n");
        printf("| Where do you want to go ?            |\n");
        printf("|      1 - Into the Wild               |\n");
        printf("|      2 - In the shop                 |\n");
        printf("|      3 - In the Supemon center       |\n");
        printf("|      4 - Leave the game              |\n");
        printf("+--------------------------------------+\n");
        printf("Enter 1, 2, 3 or 4: ");
        
        int choice2 = choix(1, 4);
        while (choice2 < 1 || choice2 > 4) {  
            printf("\nInvalid choice ! Please try again !\n");
            printf("Enter 1, 2, 3 or 4 : ");
            choice2 = choix(1, 4);  
        }

        printf("\033[H\033[J");
        
        switch (choice2) {
            case 1: {
                printf("\nYou venture into the wild !\n");
                int joueurLevel = joueuractu->selectedSupemon->lvl;
                struct Supemon *sameLevelSupemons[10]; 
                int count = 0;

                for (int i = 0; i < sizeof(listSupemons) / sizeof(listSupemons[0]); i++) {
                    if (listSupemons[i].lvl == joueurLevel) {
                        sameLevelSupemons[count] = &listSupemons[i];
                        count++;
                    }
                }
                if (count > 0) {
                    srand(time(NULL));
                    struct Supemon *wildSupemon = sameLevelSupemons[rand() % count];
                    opJoueur->selectedSupemon = wildSupemon;
                    SetBattle(opJoueur, joueuractu);
                }
                return;  // Sortir après le combat
            }
            
            case 2: {
                printf("\nWelcome to the shop !\n");
                shopOption(joueuractu, opJoueur);
                return;  // Sortir après le shop
            }
            
            case 3: {
                printf("\nWelcome to the Supemon Center !\n");
                restore_hp(joueuractu);
                break;  // Retour au menu principal
            }
            
            case 4: {
                printf("\nYou leave the game. Goodbye !\n");
                exit(0);
            }
        }
    }
}