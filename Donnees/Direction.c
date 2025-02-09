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


void choisirDirection() {
    printf("+--------------------------------------+\n");
    printf("| Where do you want to go ?            |\n");
    printf("|      1 - Into the Wild               |\n");
    printf("|      2 - In the shop                 |\n");
    printf("|      3 - In the Supemon center       |\n");
    printf("|      4 - Leave the game              |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2, 3 or 4: ");
    int choice2 = choix();
        while (choice2 < 1 || choice2 > 4) {  
        printf("Invalid choice ! Please try again !\n");
        printf("Enter 1, 2, 3 or 4 : ");
        choice2 = choix();  
    }
    if (choice2 == 1) {
        printf("You venture into the wild !\n");
    } else if (choice2 == 2) {
        ;
    } else if (choice2 == 3){
        printf("Welcome to the Supemon Center !\n");
    }
    else {
        printf("You leave the game. Goodbye!\n");
        exit(0);
    }
};