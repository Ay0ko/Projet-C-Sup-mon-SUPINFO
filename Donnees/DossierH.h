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
    char nameSupe[15];
    int id;
    int lvl;
    int xp;
    int xprap;
    int HP;
    int maxHP;
    int ATK;
    int actuATK;
    int DEF;
    int actuDEF;
    int evasion;
    int actuEvasion;
    int accuracy;
    int actuAccuracy;
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
    struct Supemon team[6];
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
extern struct Supemon listSupemons[9];

int choix(int debut, int fin);
void leChoix(struct Player *joueur);

void initializeSupemons();
void initializeItems();
void initializePlayer(struct Player *player, const char *name);

void addSupemon(struct Supemon *sup, struct Player *dresseur);
int countSupemons(struct Player *joueur);

bool checkMoula(int price, struct Player *joueur);
bool addItem(struct Item *addedItem, struct Player *joueur);
bool checkItem(struct Item *object, struct Player *joueur);
void removeItem(struct Item *object, struct Player *joueur);
int getPotion(struct Player *joueur);
int getSuperpotion(struct Player *joueur);
int getRarecandy(struct Player *joueur);
int getNbitems(struct Player *joueur);
void buyOption(struct Player *joueur, struct Player *opJoueur);
bool handleItemPurchase(struct Player *joueur, struct Item *item);
void sellOption(struct Player *joueur, struct Player *opJoueur);
bool handleItemSale(struct Player *joueur, struct Item *item);
void shopOption(struct Player *joueur, struct Player *opJoueur);

int aleaSupemon();
int aleaArrondi(float val);
bool chanceEsquive(struct Supemon *jSupemon, struct Player *opJoueur);
bool chancefuite(struct Supemon *jSupemon, struct Player *opJoueur);
bool captureSupemon(struct Player *opJoueur);
int gainExperience(int enemyLevel);
void niveauSup(struct Supemon *jSupemon);
void doMove(struct Player *opJoueur, struct Player *joueur, int choosed);
int RecompencePiece(struct Player *joueur);
void choixEnemymove(struct Player *opJoueur, struct Player *joueur, int choosed);
void changeSupemon(struct Player *opSupemon, struct Player *joueur);
void capture(struct Player *opJoueur, struct Player *joueur);
void FuiteCombat(struct Player *opJoueur, struct Player *joueur);
void useItem(struct Player *opJoueur, struct Player *joueur);
void enemyMove(struct Player *opJoueur, struct Player *joueur);
void SetBattle(struct Player *opJoueur, struct Player *joueur);
void battleOption(struct Player *opJoueur, struct Player *joueur);

void choisirDirection(struct Player *opJoueur, struct Player *joueuractu);

void restore_hp(struct Player *joueur);

void displayBattle(struct Player *opJoueur, struct Player *joueur);
void displayShop();
void displayBuy(struct Player *joueur);
void displaySell(struct Player *joueur);
void displayPotion();
void displaySuperpotion();
void displayRarecandy();
void displayTeam(struct Player *joueur);


#endif // DOSSIERH_H_INCLUDED