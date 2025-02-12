#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"


int choix(){
    int choice;
    scanf("%d", &choice);
    return choice;
};

void initializePlayer(struct Player *player, const char *name) {
    if (!player || !name) {
        return;
    }
    
    strncpy(player->name, name, 49);
    player->name[49] = '\0';
    
    memset(player->team, 0, sizeof(player->team));
    player->selectedSupemon = NULL;
    player->Supcoins = 500;
    player->SupemonCount = 0; 
    memset(player->inventory, 0, sizeof(player->inventory));
}