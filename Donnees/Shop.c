#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "DossierH.h"

struct Shop shop;

void initializeShop() {
    shop = (struct Shop) {{1, 5, 100, 50}, {2, 10, 300, 150}, {3, 1, 700, 350}};
};