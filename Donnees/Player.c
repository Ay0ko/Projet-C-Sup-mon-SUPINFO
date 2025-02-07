#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"

#define MAX_NAME_LENGTH 50
#define MAX_SUPEMONS 6
#define MAX_ITEMS 10

int choix(){
    int choice;
    scanf("%d", &choice);
    return choice;
};

struct Supemon{
    char name[MAX_NAME_LENGTH];
};

struct Item{
    char name[MAX_NAME_LENGTH];
    int effect;
};

struct Player {
    char name[MAX_NAME_LENGTH];
    Supemon supemons[MAX_SUPEMONS];
    int supemon_count;
    Supemon *selected_supemon;
    int supcoins;
    Item items[MAX_ITEMS];
    int item_count;
};

void init_player(Player *player, const char *name) {
    strncpy(player->name, name, MAX_NAME_LENGTH);
    player->supemon_count = 0;
    player->selected_supemon = NULL;
    player->supcoins = 0; 
    player->item_count = 0;
}