#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include "raylib.h"
#include "cmath"
#include "config.hpp"



int round_up(int numToRound, int multiple);
void grid(bool show);



class Wall{
    public:
        float x;
        float y;
        int number_of_clones;
        int draw_layer;
        int type;
        bool show_grid = false;
        Texture2D tex;

        // wall sprite rects
        Rectangle empty_base = {0, 0, WALL_SPRITE_WIDTH, WALL_SPRITE_HEIGHT};
        Rectangle basic_connector = {32, 0, WALL_SPRITE_WIDTH, WALL_SPRITE_HEIGHT};
        Rectangle right_connector = {64, 0, WALL_SPRITE_WIDTH, WALL_SPRITE_HEIGHT};
        Rectangle left_connector = {96, 0, WALL_SPRITE_WIDTH, WALL_SPRITE_HEIGHT};
        Rectangle down_right_connector = {0, 32, WALL_SPRITE_WIDTH, WALL_SPRITE_HEIGHT};
        Rectangle down_connector = {32, 32, WALL_SPRITE_WIDTH, WALL_SPRITE_HEIGHT};
        Rectangle left_right_connector = {64, 32, WALL_SPRITE_WIDTH, WALL_SPRITE_HEIGHT};
        Rectangle left_right_wall = {96, 32, WALL_SPRITE_WIDTH, WALL_SPRITE_HEIGHT};
        Rectangle down_left_connector = {0, 64, WALL_SPRITE_WIDTH, WALL_SPRITE_HEIGHT};
        Rectangle down_left_right_connector = {32, 64, WALL_SPRITE_WIDTH, WALL_SPRITE_HEIGHT};
        Rectangle up_down_wall = {64, 64, WALL_SPRITE_WIDTH, WALL_SPRITE_HEIGHT};
    



        void init();
        void update();
        void spawn_clone(int x, int y);
        void snap_to_grid();
        

};

#endif