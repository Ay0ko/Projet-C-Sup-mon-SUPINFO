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

bool addItem(struct Item object, struct Player *joueur) {
    for (int i = 0; i < 11; i++) {
        if (joueur->Items[i] == 0) {
            joueur->Items[i] = object.nameItem;
            return true;
            break;
        }
    }
    return false;
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
        printf("+--------------------------------------+\n");
        printf("| This is a 'Potion', its a common     |");
        printf("| item that restores additional 5hps   |");
        printf("| to your Supemon's current health. It |");
        printf("| cost 100 Supcoins and you can sell   |");
        printf("| it for half the price : 50 Supcoins. |");
        printf("+--------------------------------------+\n");
        printf("Are you sure you want to buy one (1 for yes, 0 for no) ? ");
        int buy = choix();
        if (buy == 1) {
            if (checkMoula(Potion.cost, joueur)) {
                if (addItem(Potion, joueur)) {
                    printf("Your '%s' has been successfuly bought !\n", Potion.nameItem);
                }
                printf("Your inventory is full ! Please sell items or use them in battles.\n");
            }
            printf("You don't have enought 'Supcoins' to buy this one, please go earn more 'Supcoins' in battles or by selling some items of yours.");
        }
        else {
            buyOption(struct Player *joueur);
        }
    }
    else if (choice == 2) {
        if (checkMoula(SuperPotion.cost, joueur)) {
            if (addItem(SuperPotion, joueur)) {
                printf("Your '%s' has been successfuly bought !\n", SuperPotion.nameItem);
            }
            printf("Your inventory is full ! Please sell items or use them in battles.\n");
        }
        printf("You don't have enought 'Supcoins' to buy this one, please go earn more 'Supcoins' in battles or by selling some items of yours.");
    }
    else if (choice == 3) {
        if (checkMoula(RareCandy.cost, joueur)) {
            if (addItem(RareCandy, joueur)) {
                printf("Your '%s' has been successfuly bought !\n", RareCandy.nameItem);
            }
            printf("Your inventory is full ! Please sell items or use them in battles.\n");
        }
        printf("You don't have enought 'Supcoins' to buy this one, please go earn more 'Supcoins' in battles or by selling some items of yours.");
    }
    else {
        buyOption(struct Player *joueur);
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