#include <stdio.h>
#include <stdlib.h>
//#include "raylib.h"
#include "my_food.h"

Food * setup_F(int f){
    Food * F = (Food *)malloc(f * sizeof(Food));

    F -> pos_x = 120;
    F -> pos_y = 35;
    F -> scale = 5;
    F -> color = DARKBLUE;


    return F;
}

/*
Food * traverse_F(Food * F){

    return NULL;
}

*/
