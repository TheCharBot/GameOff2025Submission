#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include "raylib.h"
#include "config.hpp"
#include "player.hpp"
#include <bits/stdc++.h>

struct enemy{
    int self_index;
    int speed;
    int health;
    Vector2 pos;
    Rectangle rect;
    
};

extern Texture2D enemy_tex;


extern Rectangle lvl1_rect;
extern Rectangle lvl2_rect;
extern Rectangle lvl3_rect;
extern Rectangle lvl4_rect;


extern Rectangle lvl1_green;
extern Rectangle lvl1_pink;
extern Rectangle lvl1_yellow;
extern Rectangle lvl1_brown;
extern Rectangle lvl1_red;
extern Rectangle lvl1_blue;

extern Rectangle lvl2_green; 
extern Rectangle lvl2_pink; 
extern Rectangle lvl2_yellow;
extern Rectangle lvl2_brown;
extern Rectangle lvl2_red;
extern Rectangle lvl2_blue;

extern Rectangle lvl3_green; 
extern Rectangle lvl3_pink; 
extern Rectangle lvl3_yellow;
extern Rectangle lvl3_brown;
extern Rectangle lvl3_red;
extern Rectangle lvl3_blue;

extern Rectangle lvl4_green; 
extern Rectangle lvl4_pink; 
extern Rectangle lvl4_yellow;
extern Rectangle lvl4_brown;
extern Rectangle lvl4_red;
extern Rectangle lvl4_blue;





extern void enemies_init();
extern void enemies_update();

extern void wave_1_init();
extern void wave_1_update();

#endif