#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"

int aleaSupemon() {
    int debut = 4;
    int fin = 9;
    return debut + rand() % (fin - debut + 1);
}

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
}