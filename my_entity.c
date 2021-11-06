#include <stdio.h>
#include <stdlib.h>
#include "my_entity.h"

Entity * setup_E(int e){

    Entity * E = (Entity *)malloc(e * sizeof(Entity));
    E -> pos_x = 700;
    E -> pos_y = 700;
    E -> color = BLACK;
    E -> trail = (Trail *)malloc(1 * sizeof(Trail));

    E -> trail -> to_food = (Node *)malloc(1 * sizeof(Node));
    E -> trail -> to_home = (Node *)malloc(1 * sizeof(Node));

    E -> trail -> to_food -> pos_x = 0;
    E -> trail -> to_food -> pos_y = 0;
    E -> trail -> to_food -> color = LIME;
    E -> trail -> to_food -> next = NULL;

    E -> trail -> to_home -> pos_x = 0;
    E -> trail -> to_home -> pos_y = 0;
    E -> trail -> to_home -> color = LIME;
    E -> trail -> to_home -> next = NULL;

    printf("Done setting up Entities\n");
    return E;
}

/*
Entity * traverse_E(Entity * E){

    return NULL;
}
*/
