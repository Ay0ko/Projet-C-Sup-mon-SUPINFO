#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"


void initializeItems() {
    Potion = (struct Item) {"Potion", 1, 5, 100, 50};
    SuperPotion = (struct Item) {"Super Potion", 2, 10, 300, 150};
    RareCandy = (struct Item) {"Rare Candy", 3, 1, 700, 350};

};

bool checkMoula(int price, struct Player *joueur) {
    return joueur->Supcoins >= price;
};

void addItem(char nomItem, struct Player *joueur) {
    int i;
};

void buyOption(struct Player *joueur) {
    int choice = choix();
    printf("+--------------------------------------+\n");
    printf("| What do you want to buy ?            |\n");
    printf("|      1 - Potion (%3d Supcoins)       |\n", Potion.cost);
    printf("|      2 - Super Potion (%3d Supcoins) |\n", SuperPotion.cost);
    printf("|      4 - Rare Candy (%3d Supcoins)   |\n", RareCandy.cost);
    printf("|      4 - Cancel                      |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2, 3 or 4  ");
    while (choice < 1 || choice > 4) {
        printf("Invalid choice ! Choose an item please.");
        printf("Enter 1, 2, 3 or 4: ");
        choice = choix();
    }
    if (choice == 1) {
        if (checkMoula(Potion.cost, joueur)) {
            char toma[1];
        }
    }
};

void shopOption(struct Player *joueur) {
    int choice = choix();
    printf("+--------------------------------------+\n");
    printf("| What do you want to do ?             |\n");
    printf("|      1 - Buy                         |\n");
    printf("|      2 - Sell                        |\n");
    printf("|      3 - Cancel                      |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2 or 3: ");
    while (choice < 1 || choice > 3) {
        printf("Invalid choice ! Choose wisely.");
        printf("Enter 1, 2 or 3: ");
        choice = choix();
    }
    if (choice == 1) {

    }
};