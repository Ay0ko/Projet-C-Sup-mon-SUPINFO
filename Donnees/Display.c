#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"


void displayBattle(struct Supemon *opSupemon, struct Player *joueur) {
    printf("\n%14s  (enemy)\n", opSupemon->nameSupe);
    printf("----------------------------------------\n");
    printf("    HP: %3d/%-3d           Lvl: %2d\n", opSupemon->HP, opSupemon->maxHP, opSupemon->lvl);
    printf("    Atk: %2d               Def: %2d\n", opSupemon->actuATK, opSupemon->actuDEF);
    printf("    Acc: %2d               Eva: %2d\n", opSupemon->actuAccuracy, opSupemon->actuEvasion);
    printf("----------------------------------------\n");
    printf("%s  (%s)\n", joueur->selectedSupemon->nameSupe, joueur->name);
    printf("----------------------------------------\n");
    printf("    HP: %3d/%-3d           Lvl: %2d\n", joueur->selectedSupemon->HP, joueur->selectedSupemon->maxHP, joueur->selectedSupemon->lvl);
    printf("    Atk: %2d               Def: %2d\n", joueur->selectedSupemon->actuATK, joueur->selectedSupemon->actuDEF);
    printf("    Acc: %2d               Eva: %2d\n", joueur->selectedSupemon->actuAccuracy, joueur->selectedSupemon->actuEvasion);
    printf("----------------------------------------\n");

    printf("\n+--------------------------------------+\n");
    printf("| What will you do ?                   |\n");
    printf("|   1 - Move                           |\n");
    printf("|   2 - Change Supemon                 |\n");
    printf("|   3 - Use item                       |\n");
    printf("|   4 - Capture                        |\n");
    printf("|   5 - Run away                       |\n");
    printf("+--------------------------------------+\n");
    printf("1, 2, 3, 4 or 5: ");
};

void displayTeam(struct Player *joueur) {
    printf("\n+--------------------------------------+\n");
    printf("| Supemon : %d/6                        |\n", countSupemons(joueur));
    printf("| --> %14s                   |\n", joueur->team[0].nameSupe);
    printf("| --> %14s                   |\n", joueur->team[1].nameSupe);
    printf("| --> %14s                   |\n", joueur->team[2].nameSupe);
    printf("| --> %14s                   |\n", joueur->team[3].nameSupe);
    printf("| --> %14s                   |\n", joueur->team[4].nameSupe);
    printf("| --> %14s                   |\n", joueur->team[5].nameSupe);
    printf("+--------------------------------------+\n");
};



void displayShop() {
    printf("+--------------------------------------+\n");
    printf("| What do you want to do ?             |\n");
    printf("|      1 - Buy                         |\n");
    printf("|      2 - Sell                        |\n");
    printf("|      3 - Go back                     |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2 or 3: ");
};

void displayBuy(struct Player *joueur) {
    printf("+--------------------------------------+\n");
    printf("| You have : %4d Supcoins.            |\n", joueur->Supcoins);
    printf("|                                      |\n");
    printf("| Inventory : %2d/10                    |\n", getNbitems(joueur));
    printf("|                                      |\n");
    printf("| Potion : %2d    Super Potions : %2d    |\n", getPotion(joueur), getSuperpotion(joueur));
    printf("|                                      |\n");
    printf("| Rare Candy : %2d                      |\n", getRarecandy(joueur));
    printf("|                                      |\n");
    printf("| What do you want to buy ?            |\n");
    printf("|      1 - Potion (%3d Supcoins)       |\n", Potion.cost);
    printf("|      2 - Super Potion (%3d Supcoins) |\n", SuperPotion.cost);
    printf("|      3 - Rare Candy (%3d Supcoins)   |\n", RareCandy.cost);
    printf("|      4 - Go back                     |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2, 3 or 4: ");
};

void displaySell(struct Player *joueur) {
    printf("+--------------------------------------+\n");
    printf("| You have : %4d Supcoins.            |\n", joueur->Supcoins);
    printf("|                                      |\n");
    printf("| Inventory : %2d/10                    |\n", getNbitems(joueur));
    printf("|                                      |\n");
    printf("| Potion : %2d    Super Potions : %2d    |\n", getPotion(joueur), getSuperpotion(joueur));
    printf("|                                      |\n");
    printf("| Rare Candy : %2d                      |\n", getRarecandy(joueur));
    printf("|                                      |\n");
    printf("| What do you want to sell ?           |\n");
    printf("|      1 - Potion (%3d Supcoins)       |\n", Potion.sell);
    printf("|      2 - Super Potion (%3d Supcoins) |\n", SuperPotion.sell);
    printf("|      3 - Rare Candy (%3d Supcoins)   |\n", RareCandy.sell);
    printf("|      4 - Go back                     |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2, 3 or 4: ");
};

void displayPotion() {
    printf("+--------------------------------------+\n");
    printf("| This is a 'Potion', its a common     |\n");
    printf("| item that restores additional 5 HP   |\n");
    printf("| to your Supemon's current health. It |\n");
    printf("| costs 100 Supcoins and you can sell  |\n");
    printf("| it for half its price : 50 Supcoins. |\n");
    printf("+--------------------------------------+\n");
    printf("Are you sure you want to buy one (1 for yes, 0 for no) ? ");
};

void displaySuperpotion() {
    printf("+--------------------------------------+\n");
    printf("| This is a 'Super Potion', its a      |\n");
    printf("| rare item that restores additional   |\n");
    printf("| 10 HP to your Supemon's current      |\n");
    printf("| health. It costs 300 Supcoins and    |\n");
    printf("| you can sell it for half its price : |\n");
    printf("| 150 Supcoins.                        |\n");
    printf("+--------------------------------------+\n");
    printf("Are you sure you want to buy one (1 for yes, 0 for no) ? ");
};

void displayRarecandy() {
    printf("+--------------------------------------+\n");
    printf("| This is a 'Rare Candy', its a super  |\n");
    printf("| rare item that adds 1 additional     |\n");
    printf("| level to your Supemon's current      |\n");
    printf("| level. It costs 700 Supcoins and     |\n");
    printf("| you can sell it for half its price : |\n");
    printf("| 350 Supcoins.                        |\n");
    printf("+--------------------------------------+\n");
    printf("Are you sure you want to buy one (1 for yes, 0 for no) ? ");
};