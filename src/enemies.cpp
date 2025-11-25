#include "enemies.hpp"

Texture2D enemy_tex;

Vector2 target;

std::vector<enemy> enemy_list;
coordinate possible_spawnpoints[6] = {
    {0, 0},
    {0, 400},
    {0, 750},
    {750, 0},
    {750, 400},
    {750, 750}
};

Rectangle scaled_sprites;

Rectangle lvl1_green = {0, 0, LVL1_SPRITE_WIDTH, LVL1_SPRITE_HEIGHT};
Rectangle lvl1_pink = {16, 0, LVL1_SPRITE_WIDTH, LVL1_SPRITE_HEIGHT};
Rectangle lvl1_yellow = {0, 16, LVL1_SPRITE_WIDTH, LVL1_SPRITE_HEIGHT};
Rectangle lvl1_brown = {16, 16, LVL1_SPRITE_WIDTH, LVL1_SPRITE_HEIGHT};
Rectangle lvl1_red = {0, 32, LVL1_SPRITE_WIDTH, LVL1_SPRITE_HEIGHT};
Rectangle lvl1_blue = {16, 32, LVL1_SPRITE_WIDTH, LVL1_SPRITE_HEIGHT};

Rectangle lvl2_green = {0, 48, LVL2_SPRITE_WIDTH, LVL2_SPRITE_HEIGHT};
Rectangle lvl2_pink = {16, 48, LVL2_SPRITE_WIDTH, LVL2_SPRITE_HEIGHT};
Rectangle lvl2_yellow = {0, 64, LVL2_SPRITE_WIDTH, LVL2_SPRITE_HEIGHT};
Rectangle lvl2_brown = {16, 64, LVL2_SPRITE_WIDTH, LVL2_SPRITE_HEIGHT};
Rectangle lvl2_red = {0, 80, LVL2_SPRITE_WIDTH, LVL2_SPRITE_HEIGHT};
Rectangle lvl2_blue = {16, 80, LVL2_SPRITE_WIDTH, LVL2_SPRITE_HEIGHT};

Rectangle lvl3_green = {0, 96, LVL3_SPRITE_WIDTH, LVL3_SPRITE_HEIGHT};
Rectangle lvl3_pink = {16, 96, LVL3_SPRITE_WIDTH, LVL3_SPRITE_HEIGHT};
Rectangle lvl3_yellow = {0, 112, LVL3_SPRITE_WIDTH, LVL3_SPRITE_HEIGHT};
Rectangle lvl3_brown = {16, 112, LVL3_SPRITE_WIDTH, LVL3_SPRITE_HEIGHT};
Rectangle lvl3_red = {0, 128, LVL3_SPRITE_WIDTH, LVL3_SPRITE_HEIGHT};
Rectangle lvl3_blue = {16, 128, LVL3_SPRITE_WIDTH, LVL3_SPRITE_HEIGHT};

Rectangle lvl4_green = {0, 144, LVL4_SPRITE_WIDTH, LVL4_SPRITE_HEIGHT};
Rectangle lvl4_pink = {16, 144, LVL4_SPRITE_WIDTH, LVL4_SPRITE_HEIGHT};
Rectangle lvl4_yellow = {0, 160, LVL4_SPRITE_WIDTH, LVL4_SPRITE_HEIGHT};
Rectangle lvl4_brown = {16, 160, LVL4_SPRITE_WIDTH, LVL4_SPRITE_HEIGHT};
Rectangle lvl4_red = {0, 176, LVL4_SPRITE_WIDTH, LVL4_SPRITE_HEIGHT};
Rectangle lvl4_blue = {16, 176, LVL4_SPRITE_WIDTH, LVL4_SPRITE_HEIGHT};

void wave_1_init()
{
    //setting target in a vector
    target.x = 400;
    target.y = 400;

    //making base enemy
    enemy lvl1_base;
    lvl1_base.speed = 10;
    lvl1_base.health = 5;
    lvl1_base.pos.x = 100;
    lvl1_base.pos.y = 100;
    // setting it to a base color, random later
    lvl1_base.img_rect = lvl1_green;
    lvl1_base.rect = {lvl1_base.pos.x, lvl1_base.pos.y, 7, 5};
    
    for (int i = 0; i < WAVE_1_AMOUNT; i++)
    {
        int num = rand() % 6;
        
        if(num == 0){
            lvl1_base.img_rect = lvl1_green;
            lvl1_base.pos.x = possible_spawnpoints[num].x;
            lvl1_base.pos.y = possible_spawnpoints[num].y;
        }
        if(num == 1){
            lvl1_base.img_rect = lvl1_pink;
            lvl1_base.pos.x = possible_spawnpoints[num].x;
            lvl1_base.pos.y = possible_spawnpoints[num].y;
        }
        if(num == 2){
            lvl1_base.img_rect = lvl1_yellow;
            lvl1_base.pos.x = possible_spawnpoints[num].x;
            lvl1_base.pos.y = possible_spawnpoints[num].y;
        }
        if(num == 3){
            lvl1_base.img_rect = lvl1_brown;
            lvl1_base.pos.x = possible_spawnpoints[num].x;
            lvl1_base.pos.y = possible_spawnpoints[num].y;
        }
        if(num == 4){
            lvl1_base.img_rect = lvl1_red;
            lvl1_base.pos.x = possible_spawnpoints[num].x;
            lvl1_base.pos.y = possible_spawnpoints[num].y;
        }
        if(num == 5){
            lvl1_base.img_rect = lvl1_blue;
            lvl1_base.pos.x = possible_spawnpoints[num].x;
            lvl1_base.pos.y = possible_spawnpoints[num].y;
        }
        enemy_list.push_back(lvl1_base);
    }
}

void wave_1_update()
{

    for (int i = 0; i < int(enemy_list.size()); i++)
    {
        for (int j = 0; j < int(connector_index.size()); j++)
        {
            //works! like, too well!
            //implement killing the clones here:
            if (CheckCollisionRecs(enemy_list[i].rect, connector_index[j].where_to_draw_stuff_rect))
            {
                
            }
        }

        //implement moving towards the center here:
        Vector2 dir = Vector2Normalize(Vector2Subtract(target, enemy_list[i].pos));
        enemy_list[i].pos = Vector2Add(enemy_list[i].pos, Vector2Scale(dir, enemy_list[i].speed * GetFrameTime()));

        
        Rectangle scaled_sprites = {enemy_list[i].pos.x, enemy_list[i].pos.y, enemy_list[i].rect.width * ENEMY_SCALE, enemy_list[i].rect.height * ENEMY_SCALE};
        DrawTexturePro(enemy_tex, enemy_list[i].img_rect, scaled_sprites, default_rotation, 0, WHITE);
    }
}

void enemies_init()
{
    enemy_tex = LoadTexture("gfx/enemies/enemies.png");
};

void enemies_update() {

};