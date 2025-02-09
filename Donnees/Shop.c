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


struct Item Potion;
struct Item SuperPotion;
struct Item RareCandy;

void initializeItems() {
    Potion = (struct Item) {"Potion", 1, 5, 100, 50};
    SuperPotion = (struct Item) {"Super Potion", 2, 10, 300, 150};
    RareCandy = (struct Item) {"Rare Candy", 3, 1, 700, 350};
};

bool checkMoula(int price, struct Player *joueur) {
    return joueur->Supcoins >= price;
};

bool addItem(struct Item *object, struct Player *joueur) {
    for (int i = 0; i < 11; i++) {
        if (joueur->inventory[i].idItem == 0) {
            strcpy(joueur->inventory[i].nameItem, object->nameItem);
            joueur->inventory[i].idItem = object->idItem;
            joueur->inventory[i].effect = object->effect;
            joueur->inventory[i].cost = object->cost;
            joueur->inventory[i].sell = object->sell;
            joueur->Supcoins-=object->cost;
            return true;
        }
    }
    return false;
};

bool checkItem(struct Item *object, struct Player *joueur) {
    for (int i = 0; i < 11; i++) {
        if (joueur->inventory[i].idItem == object->idItem) {
            return true;
        }
    }
    return false;
};

void removeItem(struct Item *object, struct Player *joueur) {
    for (int i = 0; i < 11; i++) {
        if (joueur->inventory[i].idItem == object->idItem) {
            joueur->inventory[i] = (struct Item) {0};
            joueur->Supcoins+=object->sell;
        }
    }
};

void buyOption(struct Player *joueur) {
    printf("+--------------------------------------+\n");
    printf("| What do you want to buy ?            |\n");
    printf("|      1 - Potion (%3d Supcoins)       |\n", Potion.cost);
    printf("|      2 - Super Potion (%3d Supcoins) |\n", SuperPotion.cost);
    printf("|      3 - Rare Candy (%3d Supcoins)   |\n", RareCandy.cost);
    printf("|      4 - Go back                     |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2, 3 or 4: ");
    int choice = choix();
    while (choice < 1 || choice > 4) {
        printf("\nInvalid choice ! Choose a valid option.\n");
        printf("Enter 1, 2, 3 or 4: ");
        choice = choix();
    }
    if (choice == 1) {
        system("clear");
        printf("+--------------------------------------+\n");
        printf("| This is a 'Potion', its a common     |\n");
        printf("| item that restores additional 5 HP   |\n");
        printf("| to your Supemon's current health. It |\n");
        printf("| costs 100 Supcoins and you can sell  |\n");
        printf("| it for half its price : 50 Supcoins. |\n");
        printf("+--------------------------------------+\n");
        printf("Are you sure you want to buy one (1 for yes, 0 for no) ? ");
        int buy = choix();
        if (buy == 1) {
            if (checkMoula(Potion.cost, joueur)) {
                if (addItem(&Potion, joueur)) {
                    system("clear");
                    usleep(300000);
                    printf("\nYour '%s' has been successfuly bought !\n\n", Potion.nameItem);
                    buyOption(joueur);
                }
                system("clear");
                usleep(300000);
                printf("\nYour inventory is full ! Please sell items or use them in battles.\n\n");
                buyOption(joueur);
            }
            system("clear");
            usleep(300000);
            printf("\nYou don't have enought 'Supcoins' to buy this one, please go earn more 'Supcoins' in battles or by selling some items of yours.\n\n");
            buyOption(joueur);
        }
        else {
            system("clear");
            buyOption(joueur);
        }
    }
    else if (choice == 2) {
        system("clear");
        printf("+--------------------------------------+\n");
        printf("| This is a 'Super Potion', its a      |\n");
        printf("| rare item that restores additional   |\n");
        printf("| 10 HP to your Supemon's current      |\n");
        printf("| health. It costs 300 Supcoins and    |\n");
        printf("| you can sell it for half its price : |\n");
        printf("| 150 Supcoins.                        |\n");
        printf("+--------------------------------------+\n");
        printf("Are you sure you want to buy one (1 for yes, 0 for no) ? ");
        int buy = choix();
        if (buy == 1) {
            if (checkMoula(SuperPotion.cost, joueur)) {
                if (addItem(&SuperPotion, joueur)) {
                    system("clear");
                    usleep(300000);
                    printf("\nYour '%s' has been successfuly bought !\n\n", SuperPotion.nameItem);
                    buyOption(joueur);
                }
                system("clear");
                usleep(300000);
                printf("\nYour inventory is full ! Please sell items or use them in battles.\n\n");
                buyOption(joueur);
            }
            system("clear");
            usleep(300000);
            printf("\nYou don't have enought 'Supcoins' to buy this one, please go earn more 'Supcoins' in battles or by selling some items of yours.\n\n");
            buyOption(joueur);
        }
        else {
            system("clear");
            buyOption(joueur);
        }
    }
    else if (choice == 3) {
        system("clear");
        printf("+--------------------------------------+\n");
        printf("| This is a 'Rare Candy', its a super  |\n");
        printf("| rare item that adds 1 additional     |\n");
        printf("| level to your Supemon's current      |\n");
        printf("| level. It costs 700 Supcoins and     |\n");
        printf("| you can sell it for half its price : |\n");
        printf("| 350 Supcoins.                        |\n");
        printf("+--------------------------------------+\n");
        printf("Are you sure you want to buy one (1 for yes, 0 for no) ? ");
        int buy = choix();
        if (buy == 1) {
            if (checkMoula(RareCandy.cost, joueur)) {
                if (addItem(&RareCandy, joueur)) {
                    system("clear");
                    usleep(300000);
                    printf("\nYour '%s' has been successfuly bought !\n\n", RareCandy.nameItem);
                    buyOption(joueur);
                }
                system("clear");
                usleep(300000);
                printf("\nYour inventory is full ! Please sell items or use them in battles.\n\n");
                buyOption(joueur);
            }
            system("clear");
            usleep(300000);
            printf("\nYou don't have enought 'Supcoins' to buy this one, please go earn more 'Supcoins' in battles or by selling some items of yours.\n\n");
            buyOption(joueur);
        }
        else {
            system("clear");
            buyOption(joueur);
        }
    }
    else {
        system("clear");
        shopOption(joueur);
    }
};

void sellOption(struct Player *joueur) {
    printf("+--------------------------------------+\n");
    printf("| What do you want to sell ?           |\n");
    printf("|      1 - Potion (%3d Supcoins)       |\n", Potion.sell);
    printf("|      2 - Super Potion (%3d Supcoins) |\n", SuperPotion.sell);
    printf("|      3 - Rare Candy (%3d Supcoins)   |\n", RareCandy.sell);
    printf("|      4 - Go back                     |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2, 3 or 4: ");
    int choice = choix();
    while (choice < 1 || choice > 4) {
        printf("\nInvalid choice ! Choose a valid option.\n");
        printf("Enter 1, 2, 3 or 4: ");
        choice = choix();
    }
    if (choice == 1) {
        system("clear");
        printf("+--------------------------------------+\n");
        printf("| Quick reminder: you are going to     |\n");
        printf("| sell a 'Potion' half its price :     |\n");
        printf("| 50 Supcoins.                         |\n");
        printf("+--------------------------------------+\n");
        printf("Are you sure you want to sell one (1 for yes, 0 for no) ? ");
        int sell = choix();
        if (sell == 1) {
            if (checkItem(&Potion, joueur)) {
                removeItem(&Potion, joueur);
                system("clear");
                usleep(300000);
                printf("\nYou have successfuly sold your '%s' for %d Supcoins.\n\n", Potion.nameItem, Potion.sell);
                sellOption(joueur);
            }
            system("clear");
            usleep(300000);
            printf("\nYou don't have any '%s' in your inventory !\n\n", Potion.nameItem);
            sellOption(joueur);
        }
        else {
            system("clear");
            sellOption(joueur);
        }
    }
    else if (choice == 2) {
        system("clear");
        printf("+--------------------------------------+\n");
        printf("| Quick reminder: you are going to     |\n");
        printf("| sell a 'Super Potion' half its price |\n");
        printf("| : 150 Supcoins.                      |\n");
        printf("+--------------------------------------+\n");
        printf("Are you sure you want to sell one (1 for yes, 0 for no) ? ");
        int sell = choix();
        if (sell == 1) {
            if (checkItem(&SuperPotion, joueur)) {
                removeItem(&SuperPotion, joueur);
                system("clear");
                usleep(300000);
                printf("\nYou have successfuly sold your '%s' for %d Supcoins.\n\n", SuperPotion.nameItem, SuperPotion.sell);
                sellOption(joueur);
            }
            system("clear");
            usleep(300000);
            printf("\nYou don't have any '%s' in your inventory !\n\n", SuperPotion.nameItem);
            sellOption(joueur);
        }
        else {
            system("clear");
            sellOption(joueur);
        }  
    }
    else if (choice == 3) {
        system("clear");
        printf("+--------------------------------------+\n");
        printf("| Quick reminder: you are going to     |\n");
        printf("| sell a 'Rare Candy' half its price : |\n");
        printf("| 350 Supcoins.                        |\n");
        printf("+--------------------------------------+\n");
        printf("Are you sure you want to sell one (1 for yes, 0 for no) ? ");
        int sell = choix();
        if (sell == 1) {
            if (checkItem(&RareCandy, joueur)) {
                removeItem(&RareCandy, joueur);
                system("clear");
                usleep(300000);
                printf("\nYou have successfuly sold your '%s' for %d Supcoins.\n\n", RareCandy.nameItem, RareCandy.sell);
                sellOption(joueur);
            }
            system("clear");
            usleep(300000);
            printf("\nYou don't have any '%s' in your inventory !\n\n", RareCandy.nameItem);
            sellOption(joueur);
        }
        else {
            system("clear");
            sellOption(joueur);
        }
    }
    else {
        system("clear");
        shopOption(joueur);
    }
};

void shopOption(struct Player *joueur) {
    printf("+--------------------------------------+\n");
    printf("| What do you want to do ?             |\n");
    printf("|      1 - Buy                         |\n");
    printf("|      2 - Sell                        |\n");
    printf("|      3 - Go back                     |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2 or 3: ");
    int choice = choix();
    while (choice < 1 || choice > 3) {
        printf("\nInvalid choice ! Choose a valid option.\n");
        printf("Enter 1, 2 or 3: ");
        choice = choix();
    }
    if (choice == 1) {
        system("clear");
        buyOption(joueur);
    }
    else if (choice == 2) {
        system("clear");
        sellOption(joueur);
    }
    else {
        system("clear");
        choisirDirection(joueur);
    }
};