#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"

struct Shop {
    int Potion[3];
    int SuperPotion[3];
    int RareCandy[3];
};

struct Shop shop = {
    {5, 100, 50},
    {10, 300, 150},
    {1, 700, 350}
};