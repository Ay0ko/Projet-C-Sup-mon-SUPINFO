#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#ifndef DOSSIERH_H_INCLUDED
#define DOSSIERH_H_INCLUDED


struct Move {
    char name[20];
    int damage;
    int BoostDEF;
    int BoostATK;
    int BoostEvasion;
};


struct Supemon {
    char nameSupe[50];
    int id;
    int lvl;
    int xp;
    int xprap;
    int HP;
    int maxHP;
    int ATK;
    int DEF;
    int evasion;
    int accuracy;
    int speed;
    struct Move moves[2];
};

struct Item {
    char nameItem[12];
    int idItem;
    int effect;
    int cost;
    int sell;
};

extern struct Item Potion;
extern struct Item SuperPotion;
extern struct Item RareCandy;

struct Player {
    char name[50];
    int Supemons[6];
    int SupemonCount;
    struct Supemon *selectedSupemon;
    int Supcoins;
    struct Item inventory[10];
};

extern struct Move Scratch; 
extern struct Move Grawl; 
extern struct Move Foliage; 
extern struct Move Pound;  
extern struct Move Shell;
extern struct Supemon Supmander;
extern struct Supemon Supasaur;
extern struct Supemon Supirtle;
extern struct Supemon Patrat;
extern struct Supemon Eevee;
extern struct Supemon Grimer;
extern struct Supemon Abra;
extern struct Supemon Turtwig;
extern struct Supemon Glaceon;

int choix();

void initializeSupemons();
void initializeItems();
void initializePlayer(struct Player *player, const char *name);

bool checkMoula(int price, struct Player *joueur);
bool addItem(struct Item *addedItem, struct Player *joueur);
bool checkItem(struct Item *object, struct Player *joueur);
void removeItem(struct Item *object, struct Player *joueur);
void buyOption(struct Player *joueur);
void sellOption(struct Player *joueur);
void shopOption(struct Player *joueur);

int aleaSupemon();
int aleaArrondi(float val);
bool chanceFuite(struct Supemon *jSupemon, struct Supemon *opSupemon);
bool captureSupemon(struct Supemon *opSupemon);
void niveauSup(struct Supemon *jSupemon);

void choisirDirection();


#endif // DOSSIERH_H_INCLUDED