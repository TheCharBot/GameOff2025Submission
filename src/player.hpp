#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include "raylib.h"
#include "cmath"

#include "gui.hpp"
#include "config.hpp"

struct sprite_pos_rects{
    Rectangle img_rect;
    Rectangle rect;
    float health;
};

extern Texture2D player_tex;

extern std::vector<sprite_pos_rects> connector_index;
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




extern void player_init();
extern void player_update();
extern void add_towers();




#endif