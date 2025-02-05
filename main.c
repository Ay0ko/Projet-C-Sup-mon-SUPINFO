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

int choix(poke1, poke2, poke3, pokechoisi){
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            pokechoisi = poke1;
            printf("You chose Supmander!\n");
            break;
        case 2:
            pokechoisi = poke2;
            printf("You chose Supasaur!\n");
            break;
        case 3:
            pokechoisi = poke3;
            printf("You chose Supirtle!\n");
            break;
        default:
            printf("Invalid choice! Chose your Supemon ! \n");
            choix(poke1, poke2, poke3, pokechoisi);
    }
}

int main(){
    char name[50];
    printf("Hello trainer, what's your name ? \n");
    scanf("%s", name);
    printf("Hello %s !\n Welcome in Supemon World ! \n", name);

    struct Starter Supmander = {1,10, 1, 1, 1, 2, 1};
    struct Starter Supasaur = {1,9, 1, 1, 3, 2, 2};
    struct Starter Supirtle = {1,11, 1, 2, 2, 1, 2};
    struct Starter chosenSupemon;

    printf("Choose your starter Supémon: \n");
    printf("1 - Supmander (Balanced)\n");
    printf("2 - Supasaur (Evasive)\n");
    printf("3 - Supirtle (Defensive)\n");
    printf("Enter 1, 2, or 3: ");

    choix(Supmander, Supasaur, Supirtle, chosenSupemon);



    return 0;
}





