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

void choix(int choice){
    scanf("%d", &choice);
}

int main(){
    char name[50];
    printf("Hello trainer, what's your name ? \n");
    scanf("%s", name);
    printf("Hello %s !\n Welcome in Supemon World ! \n", name);

    printf("Choose your starter Supémon: \n");
    printf("1 - Supmander (Balanced)\n");
    printf("2 - Supasaur (Evasive)\n");
    printf("3 - Supirtle (Defensive)\n");
    printf("Enter 1, 2, or 3: ");

    int choisi;
    switch (choisi) {
        case 1:
            chosenSupemon = Supmander;
            printf("You chose Supmander!\n");
            break;
        case 2:
            chosenSupemon = Supasaur;
            printf("You chose Supasaur!\n");
            break;
        case 3:
            chosenSupemon = Supirtle;
            printf("You chose Supirtle!\n");
            break;
        default:
            printf("Invalid choice! Chose your Supemon ! \n");
            choix(choisi);
    }



    return 0;
}





