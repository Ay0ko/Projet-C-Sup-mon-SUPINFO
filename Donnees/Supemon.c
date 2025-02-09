#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"


#define MAX_MOVES 2

struct Move Scratch = {"Scratch", 3, 0, 0, 0};
struct Move Grawl = {"Grawl", 0, 0, 1, 0};
struct Move Foliage = {"Foliage", 0, 0, 0, 1};
struct Move Pound = {"Pound", 2, 0, 0, 0};
struct Move Shell = {"Shell", 0, 1, 0, 0};

struct Supemon Supmander;
struct Supemon Supasaur;
struct Supemon Supirtle;
struct Supemon Patrat;
struct Supemon Eevee;
struct Supemon Grimer;
struct Supemon Abra;
struct Supemon Turtwig;
struct Supemon Glaceon;

void initializeSupemons() {
    Supmander = (struct Supemon) {"SUPMANDER", 1, 1, 0, 0, 10, 10, 1, 1, 1, 1, 1, 1, 2, 2, 1, {Scratch, Grawl}};
    Supasaur = (struct Supemon) {"SUPASAUR", 2, 1, 0, 0, 9, 9, 1, 1, 1, 1, 3, 3, 2, 2, 2, {Pound, Foliage}};
    Supirtle = (struct Supemon) {"SUPIRTLE", 3, 1, 0, 0, 11, 11, 1, 1, 2, 2, 2, 2, 1, 1, 2, {Pound, Shell}};
    Patrat = (struct Supemon) {"PATRAT", 4, 1, 3500, 100, 8, 8, 1, 1, 1, 1, 2, 2, 1, 1, 2, {Pound, Scratch}};
    Eevee = (struct Supemon) {"EEVEE", 5, 1, 4500, 110, 10, 10, 1, 1, 2, 2, 2, 2, 1, 1, 1, {Scratch, Grawl}};
    Grimer = (struct Supemon) {"GRIMER", 6, 2, 5500, 150, 11, 11, 2, 2, 1, 1, 1, 1, 2, 2, 1, {Pound, Shell}};
    Abra = (struct Supemon) {"ABRA", 7, 2, 6500, 170, 11, 11, 1, 1, 1, 1, 2, 2, 2, 2, 0, {Foliage, Grawl}};
    Turtwig = (struct Supemon) {"TURTWIG", 8, 3, 7500, 190, 12, 12, 3, 3, 2, 2, 1, 1, 2, 2, 2, {Scratch, Foliage}};
    Glaceon = (struct Supemon) {"GLACEON", 9, 3, 8500, 200, 12, 12, 2, 2, 1, 1, 2, 2, 1, 1, 3, {Pound, Shell}};
};

void leChoix(struct Player *joueur) {
    int nombre = choix();
        while (nombre < 1 || nombre > 3) {  
        printf("\nInvalid choice ! Choose your Supemon again!\n");
        printf("Enter 1, 2, or 3: ");
        nombre = choix();  
    }
    if (nombre == 1) {
        joueur->selectedSupemon = &Supmander;
        system("clear");
        printf("\nYou chose Supmander !\n");
    } else if (nombre == 2) {
        joueur->selectedSupemon = &Supasaur;
        system("clear");
        printf("\nYou chose Supasaur !\n");
    } else {
        joueur->selectedSupemon = &Supirtle;
        system("clear");
        printf("\nYou chose Supirtle !\n");
    }
};

void addSupemon(struct Supemon *sup, struct Player *dresseur) {
    for (int i = 0; i < 7; i++) {
        if (dresseur->team[i].id == 0) {
            strcpy(dresseur->team[i].nameSupe, sup->nameSupe);
            dresseur->team[i].id = sup->id;
            dresseur->team[i].lvl = sup->lvl;
            dresseur->team[i].xp = sup->xp;
            dresseur->team[i].xprap = sup->xprap;
            dresseur->team[i].HP = sup->HP;
            dresseur->team[i].maxHP = sup-> maxHP;
            dresseur->team[i].ATK = sup->ATK;
            dresseur->team[i].actuATK = sup->ATK;
            dresseur->team[i].DEF = sup->DEF;
            dresseur->team[i].actuDEF = sup->DEF;
            dresseur->team[i].evasion = sup->evasion;
            dresseur->team[i].actuEvasion = sup->evasion;
            dresseur->team[i].accuracy = sup->accuracy;
            dresseur->team[i].actuAccuracy = sup->accuracy;
            dresseur->team[i].speed = sup->speed;
            for (int j = 0; j < MAX_MOVES; j++) {
                dresseur->team[i].moves[j] = sup->moves[j];
            }
            return;
        }
    }
};