#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"

int choix(int debut, int fin) {
    int choice;
    char buffer[100];
    while (1) {
        fflush(stdout);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = 0;
            if (buffer[0] == '\0') {
                continue;
            }
            int valid = 1;
            for (int i = 0; buffer[i] != '\0'; i++) {
                if (!isdigit(buffer[i])) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                choice = atoi(buffer);
                if (choice >= debut && choice <= fin) {
                    return choice;
                } else {
                    printf("Erreur : veuillez entrer un nombre entre %d et %d.\n", debut, fin);
                }
            } else {
                printf("Erreur : veuillez entrer un nombre valide.\n");
            }
        } else {
            printf("Erreur de lecture, veuillez réessayer.\n");
            clearerr(stdin);
        }
    }
}

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