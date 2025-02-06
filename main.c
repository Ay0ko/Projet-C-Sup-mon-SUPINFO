#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
}

void leChoix(struct Player *joueur){
    int nombre = choix();
        while (nombre < 1 || nombre > 3) {  
        printf("Invalid choice! Choose your Supemon again!\n");
        printf("Enter 1, 2, or 3: ");
        nombre = choix();  
    }
    if (nombre == 1) {
        joueur->SelectedSupemon[0] = Supmander.id;
        printf("You chose Supmander!\n");
    } else if (nombre == 2) {
        joueur->SelectedSupemon[0] = Supasaur.id;
        printf("You chose Supasaur!\n");
    } else {
        joueur->SelectedSupemon[0] = Supirtle.id;
        printf("You chose Supirtle!\n");
    }
}

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
    printf("Enter 1, 2, or 3: \n");

    leChoix(&Supdresseur);

    int choice2;
    printf("+--------------------------------------+\n");
    printf("| Where do you want to go ?            |\n");
    printf("|      1 - Into the Wild               |\n");
    printf("|      2 - In the shop                 |\n");
    printf("|      3 - In the Supemon center       |\n");
    printf("|      4 - Leave the game              |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2, 3 or 4 \n");
    scanf("%d", &choice2);


    printf("+--------------------------------------+\n");
    printf("| What do you want to do ?             |\n");
    printf("|      1 - Buy                         |\n");
    printf("|      2 - Sell                        |\n");
    printf("|      3 - Cancel                      |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2 or 3\n");
    
    printf("+--------------------------------------+\n");
    printf("| What do you want to buy ?            |\n");
    printf("|      1 - Potion (%d Supcoins)       |\n", shop.Potion[2]);
    printf("|      2 - Super Potion (%d Supcoins) |\n", shop.SuperPotion[2]);
    printf("|      4 - Rare Candy (%d Supcoins)   |\n", shop.RareCandy[2]);
    printf("|      4 - Cancel                      |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2, 3 or 4 \n");

    printf("+--------------------------------------+\n");
    printf("| What do you want to sell ?           |\n");
    printf("|      1 - Potion (%d Supcoins)        |\n", shop.Potion[3]);
    printf("|      2 - Super Potion (%d Supcoins) |\n", shop.SuperPotion[3]);
    printf("|      4 - Rare Candy (%d Supcoins)   |\n", shop.RareCandy[3]);
    printf("|      4 - Cancel                      |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2, 3 or 4");

    return 0;
}