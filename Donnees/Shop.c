#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"

struct Shop shop;

void initializeShop() {
    shop = (struct Shop) {{"Potion", 1, 5, 100, 50}, {"SuperPotion", 2, 10, 300, 150}, {"RareCandy", 3, 1, 700, 350}};
};

void checkMoula(int price, struct Player *joueur) {
    return joueur->Supcoins >= price;
};

void buyOption(struct Player *joueur) {
    int choice = choix();
    printf("+--------------------------------------+\n");
    printf("| What do you want to buy ?            |\n");
    printf("|      1 - Potion (%3d Supcoins)       |\n", shop.Potion[2]);
    printf("|      2 - Super Potion (%3d Supcoins) |\n", shop.SuperPotion[2]);
    printf("|      4 - Rare Candy (%3d Supcoins)   |\n", shop.RareCandy[2]);
    printf("|      4 - Cancel                      |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2, 3 or 4  ");
    while (choice < 1 || choice > 4) {
        printf("Invalid choice ! Choose an item please.");
        printf("Enter 1, 2, 3 or 4: ");
        choice = choix();
    }
    if (choice == 1) {
        if (checkMoula(shop.Potion[2], joueur)) {

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