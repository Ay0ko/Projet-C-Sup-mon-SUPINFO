#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"

int aleaSupemon() {
    int debut = 4;
    int fin = 9;
    return debut + rand() % (fin - debut + 1);
};

int aleaArrondi(float val) {
    srand(time(NULL));
    int kifkif = rand() % 2;
    switch(kifkif) {
        case 0:
            return floor(val);
        case 1:
            return ceil(val);
        default:
            break;
    }
};

bool chanceFuite(struct Supemon *jSupemon, struct Supemon *opSupemon) {
    float fuite = 0.0;
    fuite = jSupemon->accuracy / (jSupemon->accuracy + opSupemon->evasion) + 0.1;
    return (rand()/(double)RAND_MAX) < fuite ? 1 : 0;
};

bool captureSupemon(struct Supemon *opSupemon) {
    float capture = 0.0;
    capture = (opSupemon->maxHP - opSupemon->HP) / opSupemon->maxHP - 0.5;
    return (rand()/(double)RAND_MAX) < capture ? 1 : 0;
};