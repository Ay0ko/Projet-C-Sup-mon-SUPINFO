#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"

struct Player {
    char name;
    char Supemons[500];
    char SelectedSupemon;
    int Supcoins;
    char Items[500];
};