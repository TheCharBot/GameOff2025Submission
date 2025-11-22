#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include "raylib.h"
#include "cmath"

#include "gui.hpp"
#include "config.hpp"


extern Texture2D player_tex;

extern std::vector<Rectangle> connector_index;
extern std::vector<Rectangle> range_index;
extern std::vector<Rectangle> melee_index;

extern Vector2 wall_place_pos;

extern Rectangle empty_base;
extern Rectangle basic_connector;
extern Rectangle right_connector;
extern Rectangle left_connector;
extern Rectangle down_right_connector;
extern Rectangle down_connector;
extern Rectangle left_right_connector;
extern Rectangle left_right_wall;
extern Rectangle down_left_connector;
extern Rectangle down_left_right_connector;
extern Rectangle up_down_wall;
extern Rectangle range_attacker;
extern Rectangle melee_attacker;


int round_up(int numToRound, int multiple);


extern void player_init();
extern void player_update();



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
        Rectangle range_attacker = {0, 96, WALL_SPRITE_WIDTH, WALL_SPRITE_HEIGHT};
        Rectangle melee_attacker = {16, 96, 48, WALL_SPRITE_HEIGHT};



        void init();
        void update();
        
        

};

#endif