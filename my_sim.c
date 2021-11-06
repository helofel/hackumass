#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "my_draw.h"
#include "my_entity.h"
#include "my_food.h"
#include "my_home.h"
#include "raylib.h"
#include "my_sim.h"

Node * create_grid(){
    Node * head;

    head = malloc((PIXEL_ROWS * PIXEL_COLS) * sizeof(Node));

    for(int y = 0; y < PIXEL_ROWS; ++y){
        for(int x = 0; x < PIXEL_COLS; ++x){


            head[y + PIXEL_COLS * x].next = &head[y + PIXEL_COLS * (x + 1)]; 
            head[y + PIXEL_COLS * x].previous = &head[y + PIXEL_COLS * (x - 1)]; 
            head[y + PIXEL_COLS * x].up = &head[(y - 1) + PIXEL_COLS * x]; 
            head[y + PIXEL_COLS * x].down = &head[(y + 1) + PIXEL_COLS * x];
            head[y + PIXEL_COLS * x].up_right = &head[(y - 1) + PIXEL_COLS * (x + 1)]; 
            head[y + PIXEL_COLS * x].down_right = &head[(y + 1) + PIXEL_COLS * (x + 1)]; 
            head[y + PIXEL_COLS * x].up_left = &head[(y - 1) + PIXEL_COLS * (x - 1)];
            head[y + PIXEL_COLS * x].down_left = &head[(y + 1) + PIXEL_COLS * (x - 1)];


            if(x == 0 && y == 0){
                head[y + PIXEL_COLS * x].previous = NULL;
                head[y + PIXEL_COLS * x].up = NULL;
                head[y + PIXEL_COLS * x].up_left = NULL;
                head[y + PIXEL_COLS * x].up_right = NULL;
                head[y + PIXEL_COLS * x].down_left = NULL;
            }
            if(x == PIXEL_COLS - 1 && y == 0){
                head[y + PIXEL_COLS * x].next = NULL;
                head[y + PIXEL_COLS * x].up = NULL; 
                head[y + PIXEL_COLS * x].up_left = NULL;
                head[y + PIXEL_COLS * x].up_right = NULL;
                head[y + PIXEL_COLS * x].down_right = NULL;
            } 
            if(x == 0 && y == PIXEL_ROWS - 1){
                head[y + PIXEL_COLS * x].previous = NULL;
                head[y + PIXEL_COLS * x].down = NULL;
                head[y + PIXEL_COLS * x].down_left = NULL;
                head[y + PIXEL_COLS * x].down_right = NULL;
                head[y + PIXEL_COLS * x].up_left = NULL;
            }
            if(x == PIXEL_COLS - 1 && y == PIXEL_ROWS - 1){
                head[y + PIXEL_COLS * x].next = NULL;
                head[y + PIXEL_COLS * x].down = NULL;
                head[y + PIXEL_COLS * x].up_right = NULL;
                head[y + PIXEL_COLS * x].down_left = NULL;
                head[y + PIXEL_COLS * x].down_right = NULL;
            }
            if(x == 0 && y > 0 && y < PIXEL_ROWS - 1){
                head[y + PIXEL_COLS * x].previous = NULL;
                head[y + PIXEL_COLS * x].up_left = NULL;
                head[y + PIXEL_COLS * x].down_left = NULL;
            } 
            if(x == PIXEL_COLS - 1 && y > 0 && y < PIXEL_ROWS - 1){

                head[y + PIXEL_COLS * x].next = NULL;
                head[y + PIXEL_COLS * x].up_right = NULL;
                head[y + PIXEL_COLS * x].down_right = NULL;
            }
            if(x > 0 && x < PIXEL_COLS - 1 && y == 0){

                head[y + PIXEL_COLS * x].up = NULL;
                head[y + PIXEL_COLS * x].up_right = NULL;
                head[y + PIXEL_COLS * x].up_left = NULL;

            }
            if(x > 0 && x < PIXEL_COLS - 1 && y == PIXEL_ROWS - 1){

                head[y + PIXEL_COLS * x].down = NULL;
                head[y + PIXEL_COLS * x].down_right = NULL;
                head[y + PIXEL_COLS * x].down_left = NULL;
            }

        }
    }
    return head;
}

int main(int argv, char ** argc, char** env){

    if(argv < 1){
        return -1;
    }

    while(*argc++ != NULL)
        printf("%s\n", *argc);

    while(*env++ != NULL)
        printf("%s\n", *env);

    const int screenWidth = PIXEL_ROWS;
    const int screenHeight = PIXEL_COLS;
    time_t t;

    InitWindow(screenWidth, screenHeight, "HIVe");
    srand((unsigned) time(&t));

    SetTargetFPS(60);                       

    Entity * E; 
    Food * F;
    Home * H;

    E = setup_E(1);
    F = setup_F(1);
    H = setup_H(1);


    while (!WindowShouldClose())      
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        draw(E, F, H);

        DrawFPS(10, 10);
        EndDrawing();
    }


    CloseWindow();

    free(E);
    free(F);
    free(H);


    return 0;

    
}
