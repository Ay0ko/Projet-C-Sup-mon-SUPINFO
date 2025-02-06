#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"

struct Player {
    char name[50];
    int Supemons[6];
    int SupemonCount;
    int SelectedSupemon[6];
    int Supcoins;
    char Items[500];
};