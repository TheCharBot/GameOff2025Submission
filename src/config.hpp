#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>
#include <stdlib.h>

// Global-focused macros
#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 800

// GUI-focused macros
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

// Wall-focused macros
#define WALL_SPRITE_HEIGHT 32
#define WALL_SPRITE_WIDTH 16
#define WALL_SCALE 2
#define GRID_SPACE 32

// Player-focused macros
#define TOWER_HEALTH 10
#define RANGER_RANGE 4
#define RANGER_DAMAGE 4
#define RANGE_COOLDOWN_MS 25
#define MELEE_RANGE 1
#define MELEE_DAMAGE 8
#define CORE_HEALTH 100;

// Enemy-focused macros
#define ENEMY_SCALE 2
#define LVL1_SPRITE_WIDTH 7
#define LVL1_SPRITE_HEIGHT 5
#define LVL_1_HEALTH 8

#define LVL2_SPRITE_WIDTH 9
#define LVL2_SPRITE_HEIGHT 7
#define LVL_2_HEALTH 15

#define LVL3_SPRITE_WIDTH 11
#define LVL3_SPRITE_HEIGHT 8
#define LVL_3_HEALTH 30

#define LVL4_SPRITE_WIDTH 16
#define LVL4_SPRITE_HEIGHT 12
#define LVL_4_HEALTH 40

#define KNOCKBACK 25

// Wave-focused macros
#define WAVE_1_AMOUNT 1000

#define WAVE_2_AMOUNT 1200
#define WAVE_2_LVL1_AMOUNT 600
#define WAVE_2_LVL2_AMOUNT 600

#define WAVE_3_AMOUNT 1800
#define WAVE_3_LVL1_AMOUNT 600
#define WAVE_3_LVL2_AMOUNT 600
#define WAVE_3_LVL3_AMOUNT 600

#define WAVE_4_AMOUNT 1200
#define WAVE_4_LVL3_AMOUNT 600
#define WAVE_4_LVL4_AMOUNT 600

#define WAVE_5_AMOUNT 1800
#define WAVE_5_LVL3_AMOUNT 900
#define WAVE_5_LVL4_AMOUNT 900

#define WAVE_6_AMOUNT 2000
#define WAVE_6_LVL3_AMOUNT 1000
#define WAVE_6_LVL4_AMOUNT 1000

#define WAVE_7_AMOUNT 1300
#define WAVE_7_LVL4_AMOUNT 1300

#define WAVE_8_AMOUNT 1500
#define WAVE_8_LVL4_AMOUNT 1500

#define WAVE_9_AMOUNT 1800
#define WAVE_9_LVL4_AMOUNT 1800

#define WAVE_10_AMOUNT 2000
#define WAVE_10_LVL4_AMOUNT 2000

#endif