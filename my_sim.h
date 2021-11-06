#ifndef MY_SIM_H
#define MY_SIM_H

#include "my_entity.h"

#define PIXEL_ROWS 1280
#define PIXEL_COLS 675

enum dirc {
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3,
    UPLEFT = 4,
    UPRIGHT = 5,
    DOWNLEFT = 6,
    DOWNRIGHT = 7
};

void initialize_board(Node *);
Node * create_grid();
void print_linked_grid(Node *, struct Entity *, int);

int _stat_grid(Node *, Trail *, Entity *, int, int);
int (*_arg_ptr)(Node *, Trail *, Entity *, bool, bool);
int _create_path(int (*arg_ptr)(Node *, Entity *, bool, bool), Node *, Trail *, Entity *, bool, bool, int);
int _move_on_path(int (*arg_ptr)(Node *, Entity *, bool, bool), Node *, Trail *, Entity *, bool, bool, int);

int up(Node *, Trail *, Entity *, bool, bool);
int down(Node *, Trail *, Entity *, bool, bool);
int left(Node *, Trail *, Entity *, bool, bool);
int right(Node *, Trail *, Entity *, bool, bool);
int up_left(Node *, Trail *, Entity *, bool, bool);
int up_right(Node *, Trail *, Entity *, bool, bool);
int down_left(Node *, Trail *, Entity *, bool, bool);
int down_right(Node *, Trail *, Entity *, bool, bool);


#endif
