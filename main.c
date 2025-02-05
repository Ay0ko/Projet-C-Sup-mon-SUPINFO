#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

int choix(int choice){
    scanf("%d", &choice);
    return choice;
}

int leChoix(int nombre){
    choix(nombre);
    if (nombre == 1) {
        chosenSupemon = Supmander;
        printf("You chose Supmander !\n");
    } else if (nombre == 2) {
        chosenSupemon = Supasaur;
        printf("You chose Supasaur !\n");
    } else if (nombre == 3) {
        chosenSupemon = Supirtle;
        printf("You chose Supirtle !\n");
    } else {
        printf("Invalid choice! Chose your Supemon ! \n");
        printf("Enter 1, 2, or 3: ");
        choix(nombre);
    }
}

int main(){
    char name[50];
    printf("Hello trainer, what's your name ? \n");
    scanf("%s", name);
    printf("Hello %s !\n Welcome in Supemon World ! \n", name);

    printf("+-----------------------------------+\n");
    printf("| Choose your starter Supémon:      |\n");
    printf("|                                   |\n");
    printf("| 1 - Supmander (Balanced)          |\n");
    printf("| 2 - Supasaur (Evasive)            |\n");
    printf("| 3 - Supirtle (Defensive)          |\n");
    printf("+-----------------------------------+\n");
    printf("Enter 1, 2, or 3: ");

    int choisi;
    leChoix(choisi);

    printf("+-----------------------------------+\n");
    printf("| Where do you want to go ?         |\n");
    printf("|      1 - Into the Wild            |\n");
    printf("|      2 - In the shop              |\n");
    printf("|      3 - In the Supémon center    |\n");
    printf("|      4 - Leave the game           |\n");
    printf("+-----------------------------------+\n");
    printf("Enter 1, 2, 3 or 4");


    return 0;
}





