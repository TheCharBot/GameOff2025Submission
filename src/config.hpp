#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "raylib.h"
#include <iostream>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>
#include <stdlib.h> 

// Global-focused macros
#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 800

//GUI-focused macros
#define SLOT_1_X 309
#define SLOT_2_X 373
#define SLOT_3_X 437
#define BOTTOM_BUTTON_Y 680
#define GUI_SCALE 3
#define MENU_X 232
#define MENU_Y 256
#define EXIT_X 0
#define EXIT_Y 0
#define MENU_OFFSET_X 232
#define MENU_OFFSET_Y 256

//Wall-focused macros 
#define WALL_SPRITE_HEIGHT 32
#define WALL_SPRITE_WIDTH 16
#define WALL_SCALE 2
#define GRID_SPACE 32


//Player-focused macros
#define TOWER_HEALTH 10
#define RANGER_RANGE 4
#define RANGER_DAMAGE 4
#define MELEE_RANGE 1
#define MELEE_DAMAGE 8

//Enemy-focused macros
#define ENEMY_SPRITE_WIDTH 16
#define ENEMY_SPRITE_HEIGHT 16
#define LVL1_SPRITE_WIDTH 7
#define LVL1_SPRITE_HEIGHT 5
#define LVL2_SPRITE_WIDTH 9
#define LVL2_SPRITE_HEIGHT 7
#define LVL3_SPRITE_WIDTH 11
#define LVL3_SPRITE_HEIGHT 8
#define LVL4_SPRITE_WIDTH 16
#define LVL4_SPRITE_HEIGHT 12
#define ENEMY_SCALE 2
#define WAVE_1_AMOUNT 1000
#define LVL_1_SPEED 10
#define LVL_1_HEALTH 5

#endif