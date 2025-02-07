#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "Donnees/DossierH.h"
#include "Donnees/Supemon.c"
#include "Donnees/Shop.c"
#include "Donnees/Player.c"

int choix(){
    int choice;
    scanf("%d", &choice);
    return choice;
};

void leChoix(struct Player *joueur){
    int nombre = choix();
        while (nombre < 1 || nombre > 3) {  
        printf("Invalid choice! Choose your Supemon again!\n");
        printf("Enter 1, 2, or 3: ");
        nombre = choix();  
    }
    if (nombre == 1) {
        joueur->selectedSupemon = Supmander;
        printf("You chose Supmander!\n");
    } else if (nombre == 2) {
        joueur->selectedSupemon = Supasaur;
        printf("You chose Supasaur!\n");
    } else {
        joueur->selectedSupemon = Supirtle;
        printf("You chose Supirtle!\n");
    }
};

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
        printf("Welcome to the shop !\n");
    } else if (choice2 == 3){
        printf("Welcome to the Supemon Center !\n");
    }
    else {
        printf("You leave the game. Goodbye!\n");
        exit(0);
    }
};

int main(){
    initializeSupemons();
    initializeShop();
    struct Player Supdresseur;

    printf("Hello trainer, what's your name ? \n");
    scanf("%49s", Supdresseur.name);
    printf("Hello %s !\n Welcome in Supemon World ! \n", Supdresseur.name);

    printf("+--------------------------------------+\n");
    printf("| Choose your starter Supémon:         |\n");
    printf("|                                      |\n");
    printf("| 1 - Supmander                        |\n");
    printf("| 2 - Supasaur                         |\n");
    printf("| 3 - Supirtle                         |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2, or 3: ");

    leChoix(&Supdresseur);

    choisirDirection();


    printf("+--------------------------------------+\n");
    printf("| What do you want to do ?             |\n");
    printf("|      1 - Buy                         |\n");
    printf("|      2 - Sell                        |\n");
    printf("|      3 - Cancel                      |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2 or 3 ");
    
    printf("+--------------------------------------+\n");
    printf("| What do you want to buy ?            |\n");
    printf("|      1 - Potion (%d Supcoins)       |\n", shop.Potion[2]);
    printf("|      2 - Super Potion (%d Supcoins) |\n", shop.SuperPotion[2]);
    printf("|      4 - Rare Candy (%d Supcoins)   |\n", shop.RareCandy[2]);
    printf("|      4 - Cancel                      |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2, 3 or 4  ");

    printf("+--------------------------------------+\n");
    printf("| What do you want to sell ?           |\n");
    printf("|      1 - Potion (%d Supcoins)        |\n", shop.Potion[3]);
    printf("|      2 - Super Potion (%d Supcoins) |\n", shop.SuperPotion[3]);
    printf("|      4 - Rare Candy (%d Supcoins)   |\n", shop.RareCandy[3]);
    printf("|      4 - Cancel                      |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2, 3 or 4 ");

    printf("Your turn...\n");
    printf("%s  (enemy)\n", Supasaur.nameSupe);
    printf("----------------------------------------\n");
    printf("    HP: %d/ %d            Lvl: %d\n", Supasaur.HP, Supasaur.maxHP, Supasaur.lvl);
    printf("    Atk: %d               Def: %d\n", Supasaur.ATK, Supasaur.DEF);
    printf("    Acc: %d               Eva: %d\n", Supasaur.speed, Supasaur.evasion);
    printf("----------------------------------------\n");
    printf("%s  (%s)\n", Supdresseur.selectedSupemon.nameSupe, Supdresseur.name);
    printf("----------------------------------------\n");
    printf("    HP: %d/ %d            Lvl: %d\n", Supdresseur.selectedSupemon.HP, Supdresseur.selectedSupemon.maxHP, Supdresseur.selectedSupemon.lvl);
    printf("    Atk: %d               Def: %d\n", Supdresseur.selectedSupemon.ATK, Supdresseur.selectedSupemon.DEF);
    printf("    Acc: %d               Eva: %d\n", Supdresseur.selectedSupemon.speed, Supdresseur.selectedSupemon.evasion);
    printf("----------------------------------------\n");

    printf("\n+--------------------------------------+\n");
    printf("| What will you do ?                    |\n");
    printf("|   1 - Move                            |\n");
    printf("|   2 - Change Supemon                  |\n");
    printf("|   3 - Use item                        |\n");
    printf("|   4 - Capture                         |\n");
    printf("|   5 - Run away                        |\n");
    printf("+--------------------------------------+\n");
    printf("1, 2, 3, 4 or 5: ");

    printf("1 - %s\n", Supdresseur.selectedSupemon.moves[0].name);
    printf("2 - %s\n", Supdresseur.selectedSupemon.moves[1].name);
    printf("3 - Cancel\n");
    printf("1, 2 or 3: ");

    return 0;
}