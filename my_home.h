#ifndef MY_HOME_H
#define MY_HOME_H

#include "raylib.h"

#define HOMES 1
#define X 1280/2.0f
#define Y 800/2.0f

typedef struct Home Home;

struct Home{
    Vector2 position;
    int radius;
    Color color;
};

Home * setup_H(int);

#endif

