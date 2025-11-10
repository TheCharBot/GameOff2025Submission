#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"



int building_arr[16] = {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0, 
    0, 0, 0, 0
};

struct building{
    int x;
    int y;
    int draw_layer;
};




struct connection_point{
    int x; 
    int y; 
    int offset_x;
    int offset_y; 
    int draw_layer;
};

#endif