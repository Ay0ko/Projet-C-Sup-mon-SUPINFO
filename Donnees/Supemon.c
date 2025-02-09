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
    Supmander = (struct Supemon){"SUPMANDER", 1, 1, 0, 0, 10, 10, 1, 1, 1, 2, 1, {Scratch, Grawl}};
    Supasaur = (struct Supemon){"SUPASAUR", 2, 1, 0, 0, 9, 9, 1, 1, 3, 2, 2, {Pound, Foliage}};
    Supirtle = (struct Supemon){"SUPIRTLE", 3, 1, 0, 0, 11, 11, 1, 2, 2, 1, 2, {Pound, Shell}};
    Patrat = (struct Supemon){"PATRAT", 4, 1, 3500, 100, 8, 8, 1, 1, 2, 1, 2, {Pound, Scratch}};
    Eevee = (struct Supemon){"EEVEE", 5, 1, 4500, 110, 10, 10, 1, 2, 2, 1, 1, {Scratch, Grawl}};
    Grimer = (struct Supemon){"GRIMER", 6, 2, 5500, 150, 11, 11, 2, 1, 1, 2, 1, {Pound, Shell}};
    Abra = (struct Supemon){"ABRA", 7, 2, 6500, 170, 11, 11, 1, 1, 2, 2, 0, {Foliage, Grawl}};
    Turtwig = (struct Supemon){"TURTWIG", 8, 3, 7500, 190, 12, 12, 3, 2, 1, 2, 2, {Scratch, Foliage}};
    Glaceon = (struct Supemon){"GLACEON", 9, 3, 8500, 200, 12, 12, 2, 1, 2, 1, 3, {Pound, Shell}};
};