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
            break;
        }
    }
};

int getPotion(struct Player *joueur) {
    int j = 0;
    for (int i = 0; i < 11; i++) {
        if (joueur->inventory[i].idItem == 1) {
            j+=1;
        }
    }
    return j;
};

int getSuperpotion(struct Player *joueur) {
    int j = 0;
    for (int i = 0; i < 11; i++) {
        if (joueur->inventory[i].idItem == 2) {
            j+=1;
        }
    }
    return j;
};

int getRarecandy(struct Player *joueur) {
    int j = 0;
    for (int i = 0; i < 11; i++) {
        if (joueur->inventory[i].idItem == 3) {
            j+=1;
        }
    }
    return j;
};

int getNbitems(struct Player *joueur) {
    int j = 10;
    for (int i = 0; i < 11; i++) {
        if (joueur->inventory[i].idItem == 0) {
            j-=1;
        }
    }
    return j;
};

void buyOption(struct Player* joueur, struct Player *opJoueur) {
    if (!joueur || !opJoueur) {
        printf("Error: Invalid player pointers!\n");
        return;
    }

    bool continueShopping = true;
    while (continueShopping) {
        printf("\n");
        displayBuy(joueur);
        int choice = choix(1, 4);
        
        while (choice < 1 || choice > 4) {
            printf("\nInvalid choice ! Choose a valid option.\n");
            printf("Enter 1, 2, 3 or 4: ");
            choice = choix(1, 4);
        }

        printf("\033[H\033[J");
        
        switch(choice) {
            case 1: {
                if (handleItemPurchase(joueur, &Potion)) {
                    continueShopping = false;
                }
                break;
            }
            case 2: {
                if (handleItemPurchase(joueur, &SuperPotion)) {
                    continueShopping = false;
                }
                break;
            }
            case 3: {
                if (handleItemPurchase(joueur, &RareCandy)) {
                    continueShopping = false;
                }
                break;
            }
            case 4: {
                continueShopping = false;
                shopOption(joueur, opJoueur);
                break;
            }
        }
    }
};


bool handleItemPurchase(struct Player *joueur, struct Item *item) {
    printf("\n");
    switch(item->idItem) { 
        case 1:
            displayPotion();
            break;
        case 2:
            displaySuperpotion();
            break;
        case 3:
            displayRarecandy();
            break;
    }   
    int buy = choix(1, 2);
    
    if (buy == 1) {
        if (checkMoula(item->cost, joueur)) {
            if (addItem(item, joueur)) {
                printf("\033[H\033[J");
                usleep(300000);
                printf("\nYour '%s' has been successfully bought!\n", item->nameItem);
                return false;
            }
            printf("\033[H\033[J");
            usleep(300000);
            printf("\nYour inventory is full! Please sell items or use them in battles.\n");
            return false;
        }
        printf("\033[H\033[J");
        usleep(300000);
        printf("\nYou don't have enough 'Supcoins' to buy this one.\n");
        return false;
    }
    return false;
};

void sellOption(struct Player *joueur, struct Player *opJoueur) {
    if (!joueur || !opJoueur) {
        printf("Error: Invalid player pointers!\n");
        return;
    }

    bool continueSelling = true;
    while (continueSelling) {
        printf("\n");
        displaySell(joueur);
        int choice = choix(1, 4);
        
        while (choice < 1 || choice > 4) {
            printf("\nInvalid choice ! Choose a valid option.\n");
            printf("Enter 1, 2, 3 or 4: ");
            choice = choix(1, 4);
        }

        printf("\033[H\033[J");
        
        if (choice == 4) {
            shopOption(joueur, opJoueur);
            continueSelling = false;
        } else {
            struct Item *itemToSell = NULL;
            switch(choice) {
                case 1: itemToSell = &Potion; break;
                case 2: itemToSell = &SuperPotion; break;
                case 3: itemToSell = &RareCandy; break;
            }
            
            if (itemToSell && handleItemSale(joueur, itemToSell)) {
                continueSelling = false;
            }
        }
    }
}
bool handleItemSale(struct Player *joueur, struct Item *item) {
    printf("\n+--------------------------------------+\n");
    printf("| Quick reminder: you are going to     |\n");
    printf("| sell this item for %3d Supcoins.     |\n", item->sell);
    printf("+--------------------------------------+\n");
    printf("Are you sure you want to sell one (1 for yes, 0 for no)? ");
    
    int sell = choix(1, 2);
    if (sell == 1) {
        if (checkItem(item, joueur)) {
            removeItem(item, joueur);
            printf("\033[H\033[J");
            usleep(300000);
            printf("\nYou have successfully sold your '%s' for %d Supcoins.\n", 
                   item->nameItem, item->sell);
            return false;
        }
        printf("\033[H\033[J");
        usleep(300000);
        printf("\nYou don't have any '%s' in your inventory!\n", item->nameItem);
        return false;
    }
    return false;
}

void shopOption(struct Player *joueur, struct Player *opJoueur) {
    if (!joueur || !opJoueur) {
        printf("Error: Invalid player pointers!\n");
        return;
    }

    while (1) {
        printf("\n");
        displayShop();
        int choice = choix(1, 3);
        while (choice < 1 || choice > 3) {
            printf("\nInvalid choice ! Choose a valid option.\n");
            printf("Enter 1, 2 or 3: ");
            choice = choix(1, 3);
        }
        
        printf("\033[H\033[J");
        
        switch (choice) {
            case 1:
                buyOption(joueur, opJoueur);
                return;
                
            case 2:
                sellOption(joueur, opJoueur);
                return;
                
            case 3:
                choisirDirection(opJoueur, joueur);
                return;
        }
    }
}