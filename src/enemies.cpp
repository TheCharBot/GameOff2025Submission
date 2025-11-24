#include "enemies.hpp"



Texture2D enemy_tex;

std::vector<enemy> enemy_list;

;



Rectangle lvl1_green = {0, 0, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};
Rectangle lvl1_pink = {16, 0, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};
Rectangle lvl1_yellow = {0, 16, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};
Rectangle lvl1_brown = {16, 16, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};
Rectangle lvl1_red = {0, 32, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};
Rectangle lvl1_blue = {16, 32, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};

Rectangle lvl2_green = {0, 48, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT}; 
Rectangle lvl2_pink = {16, 48, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT}; 
Rectangle lvl2_yellow = {0, 64, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};
Rectangle lvl2_brown = {16, 64, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};
Rectangle lvl2_red = {0, 80, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};
Rectangle lvl2_blue = {16, 80, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};

Rectangle lvl3_green = {0, 96, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT}; 
Rectangle lvl3_pink = {16, 96, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT}; 
Rectangle lvl3_yellow = {0, 112, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};
Rectangle lvl3_brown = {16, 112, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};
Rectangle lvl3_red = {0, 128, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};
Rectangle lvl3_blue = {16, 128, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};

Rectangle lvl4_green = {0, 144, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT}; 
Rectangle lvl4_pink = {16, 144, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT}; 
Rectangle lvl4_yellow = {0, 160, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};
Rectangle lvl4_brown = {16, 160, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};
Rectangle lvl4_red = {0, 176, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};
Rectangle lvl4_blue = {16, 176, ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT};



void wave_1_init(){
    enemy lvl1_base;
    lvl1_base.speed = 10;
    lvl1_base.health = 5;
    lvl1_base.pos.x = 100;
    lvl1_base.pos.y = 100;
    lvl1_base.rect = {lvl1_base.pos.x, lvl1_base.pos.y, 6, 4};
    for(int i = 0; i > WAVE_1_AMOUNT; i++){
        enemy_list.push_back(lvl1_base);    
    }
}

void wave_1_update(){
    for(int i = 0; i > WAVE_1_AMOUNT; i++){
        if(CheckCollisionRecs(enemy_list[i].rect, connector_index[i].where_to_draw_stuff_rect)){
            std::cout << "hello there!";
        }
    }
}

void enemies_init(){
    enemy_tex = LoadTexture("gfx/enemies/enemies.png");
};

void enemies_update(){

};