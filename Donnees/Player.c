#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>
#include "DossierH.h"


int choix(){
    int choice;
    scanf("%d", &choice);
    return choice;
};

void initializePlayer(struct Player *player, const char *name) {
    strncpy(player->name, name, 50);
    player->SupemonCount = 0;
    player->selectedSupemon = NULL;
    player->Supcoins = 0;
};