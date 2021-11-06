#ifndef MY_ENTITY_H
#define MY_ENTITY_H

#include "raylib.h"

typedef struct Entity Entity;
typedef struct Trail Trail;
typedef struct Node Node;

struct Node {
    int pos_x;
    int pos_y;
    Color color;
    struct Node * next;
    struct Node * previous;
    struct Node * up;
    struct Node * down;
    struct Node * up_right;
    struct Node * down_right;
    struct Node * up_left;
    struct Node * down_left;
};

struct Trail {
    Node * to_food;
    Node * to_home;
};

struct Entity {
    int pos_x;
    int pos_y;
    Color color;
    Trail * trail; 
};


Entity * setup_E(int);
Entity * traverse_E(Entity *);

#endif
