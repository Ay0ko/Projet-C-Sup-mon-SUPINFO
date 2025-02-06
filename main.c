#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "Donnees/DossierH.h"

struct Starter {
    int lvl;
    int HP;
    int ATK;
    int DEF;
    int evasion;
    int accuracy;
    int speed;
};

struct Starter Supmander = {1,10, 1, 1, 1, 2, 1};
struct Starter Supasaur = {1,9, 1, 1, 3, 2, 2};
struct Starter Supirtle = {1,11, 1, 2, 2, 1, 2};
struct Starter chosenSupemon;

int choix(){
    int choice;
    scanf("%d", &choice);
    return choice;
}

void leChoix(){
    int nombre = choix();
        while (nombre < 1 || nombre > 3) {  
        printf("Invalid choice! Choose your Supemon again!\n");
        printf("Enter 1, 2, or 3: ");
        nombre = choix();  
    }
    if (nombre == 1) {
        chosenSupemon = Supmander;
        printf("You chose Supmander!\n");
    } else if (nombre == 2) {
        chosenSupemon = Supasaur;
        printf("You chose Supasaur!\n");
    } else {
        chosenSupemon = Supirtle;
        printf("You chose Supirtle!\n");
    }
}

int main(){
    char name[50];
    printf("Hello trainer, what's your name ? \n");
    scanf("%[^\n]s", name);
    printf("Hello %s !\n Welcome in Supemon World ! \n", name);

    printf("+-----------------------------------+\n");
    printf("| Choose your starter Supémon:      |\n");
    printf("|                                   |\n");
    printf("| 1 - Supmander                     |\n");
    printf("| 2 - Supasaur                      |\n");
    printf("| 3 - Supirtle                      |\n");
    printf("+-----------------------------------+\n");
    printf("Enter 1, 2, or 3: \n");

    int choisi;
    leChoix(choisi);

    int choice2;

    printf("+-----------------------------------+\n");
    printf("| Where do you want to go ?         |\n");
    printf("|      1 - Into the Wild            |\n");
    printf("|      2 - In the shop              |\n");
    printf("|      3 - In the Supemon center    |\n");
    printf("|      4 - Leave the game           |\n");
    printf("+-----------------------------------+\n");
    printf("Enter 1, 2, 3 or 4 \n");
    scanf("%d", &choice2);

    


    void healSupemons(struct Player *player) {
    printf("\n Welcome to the Supemon Center!\n");
    for (int i = 0; i < player->SupemonCount; i++) {
        player->Supemons[i].HP = player->Supemons[i].maxHP; 
        printf("%s has been fully healed! (HP: %d/%d)\n",
               player->Supemons[i].name, player->Supemons[i].HP, player->Supemons[i].maxHP);
    }
    printf("All your Supemons are now at full health!\n\n");
}

    return 0;
}

