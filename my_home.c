#include <stdio.h>
#include <stdlib.h>
//#include "raylib.h"
#include "my_home.h"

Home * setup_H(int h){
    Home * H = (Home *)malloc(h * sizeof(Home));
    Vector2 ballPosition = { X, Y };

    H -> position = ballPosition;
    H -> radius = 20;
    H -> color = MAROON; 

    return H;
}
