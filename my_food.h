#ifndef MY_FOOD_H
#define MY_FOOD_H

#include "raylib.h"

typedef struct Food Food;

struct Food{
   int pos_x;
   int pos_y;
   int scale;
   Color color;
};

Food * setup_F(int);

Food * traverse_F(Food *);

#endif
