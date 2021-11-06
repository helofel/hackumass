#ifndef MY_DRAW_H 
#define MY_DRAW_H

#include "my_entity.h"
#include "my_food.h"
#include "my_home.h"

int draw(Entity *, Food *, Home *);
void draw_food(Food *);
void draw_entities(Entity *);
void draw_home(Home *);

#endif
