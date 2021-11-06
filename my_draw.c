#include "raylib.h"
#include "my_draw.h"
//#include "my_entity.h"

int draw(Entity * E, Food * F, Home * H){
    draw_home(H);
    draw_food(F);
    draw_entities(E);
    return 0;

}

void draw_entities(Entity * E){
    DrawPixel(E -> pos_x, E -> pos_y, E -> color);
    DrawPixel(E -> pos_x+1, E -> pos_y, E -> color);
    DrawPixel(E -> pos_x+2, E -> pos_y, E -> color);
    DrawPixel(E -> pos_x+3, E -> pos_y, E -> color);
    DrawPixel(E -> pos_x+4, E -> pos_y, E -> color);
}


void draw_food(Food * F){

    DrawCircle(GetScreenWidth()/5, F -> pos_x, F -> pos_y, F -> color);
}

void draw_home(Home * H){

    DrawCircleV(H -> position, (float)H -> radius, H -> color);
}
