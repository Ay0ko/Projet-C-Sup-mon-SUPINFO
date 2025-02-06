#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"

struct Move{
    char name[20];
    int damage;
    int BoostDEF;
    int BoostATK;
    int BoostEvasion;
 };

#define MAX_MOVES 2

struct Move Scratch = {"Scratch", 3, 0, 0, 0}; 
struct Move Grawl = {"Grawl", 0, 0, 1, 0}; 
struct Move Foliage = {"Foliage", 0, 0, 0, 1}; 
struct Move Pound = {"Pound", 2, 0, 0, 0};  
struct Move Shell = {"Shell", 0, 1, 0, 0};

struct Starter {
    int lvl;
    int xp;
    int HP;
    int maxHP;
    int ATK;
    int DEF;
    int evasion;
    int accuracy;
    int speed;
    struct Move moves[MAX_MOVES];
};

struct Starter Supmander = {1,0,10,10,1, 1, 1, 2, 1,{Scratch,Grawl}};
struct Starter Supasaur = {1,0,9,9,1, 1, 3, 2, 2,{Pound,Foliage}};
struct Starter Supirtle = {1,0,11,11,1, 2, 2, 1, 2,{Pound,Shell}};

struct Supemon{
    int id;
    int lvl;
    int xprap;
    int HP;
    int maxHP;
    int ATK;
    int DEF;
    int evasion;
    int accuracy;
    int speed;
    struct Move moves[MAX_MOVES];
};

struct Supemon Patrat = {4, 1, 100, 8, 8, 1, 1, 2, 1, 2, {Pound, Scratch}};
struct Supemon Eevee = {5, 1, 110, 10, 10, 1, 2, 2, 1, 1, {Scratch, Grawl}};
struct Supemon Grimer = {6, 2, 150, 11, 11, 2, 1, 1, 2, 1, {Pound, Shell}};
struct Supemon Abra = {7, 2, 170, 11, 11, 1, 1, 2, 2, 0, {Foliage, Grawl}};
struct Supemon Turtwig = {8, 3, 190, 12, 12, 3, 2, 1, 2, 2, {Scratch, Foliage}};
struct Supemon Glaceon = {9, 3, 200, 12, 12, 2, 1, 2, 1, 3, {Pound, Shell}};


