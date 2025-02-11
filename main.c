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
#include "Donnees/Direction.c"
#include "Donnees/Center.c"
#include "Donnees/Combat.c"
#include "Donnees/Display.c"


int main() {
    srand(time(NULL));
    printf("\033[H\033[J");

    initializeSupemons();
    initializeItems();

    struct Player Supdresseur;
    struct Player Enemy;

    char namePlayer;
    printf("\nHello trainer, what's your name ? \n");
    scanf("%49s", &namePlayer);

    initializePlayer(&Supdresseur, &namePlayer);
    initializePlayer(&Enemy, "Enemy");

    printf("\033[H\033[J");

    printf("\nHello %s !\nWelcome in Supemon World ! \n", Supdresseur.name);
    printf("+--------------------------------------+\n");
    printf("| Choose your starter Supémon:         |\n");
    printf("|                                      |\n");
    printf("| 1 - Supmander                        |\n");
    printf("| 2 - Supasaur                         |\n");
    printf("| 3 - Supirtle                         |\n");
    printf("+--------------------------------------+\n");
    printf("Enter 1, 2, or 3: ");

    leChoix(&Supdresseur);

    choisirDirection(&Enemy, &Supdresseur);

    return 0;
}