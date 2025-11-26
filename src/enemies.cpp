#include "enemies.hpp"

Texture2D enemy_tex;

Vector2 target;

int num = 0;

std::vector<enemy> enemy_list;
coordinate possible_spawnpoints[6] = {
    {0, 0},
    {0, 400},
    {0, 790},
    {790, 0},
    {790, 400},
    {790, 790}};

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
    // setting target in a vector
    target.x = 400;
    target.y = 400;

    // making base enemy
    enemy lvl1_base;

    lvl1_base.health = LVL_1_HEALTH;
    lvl1_base.pos.x = 100;
    lvl1_base.pos.y = 100;
    // setting it to a base color, random later
    lvl1_base.img_rect = lvl1_green;
    lvl1_base.rect = {lvl1_base.pos.x, lvl1_base.pos.y, 7, 5};

    for (int i = 0; i < WAVE_1_AMOUNT; i++)
    {

        // image randomization
        int num = rand() % 6;
        if (num == 0)
        {
            lvl1_base.img_rect = lvl1_green;
        }
        if (num == 1)
        {
            lvl1_base.img_rect = lvl1_pink;
        }
        if (num == 2)
        {
            lvl1_base.img_rect = lvl1_yellow;
        }
        if (num == 3)
        {
            lvl1_base.img_rect = lvl1_brown;
        }
        if (num == 4)
        {
            lvl1_base.img_rect = lvl1_red;
        }
        if (num == 5)
        {
            lvl1_base.img_rect = lvl1_blue;
        }

        // position randomization
        num = rand() % 6;
        if (num == 0)
        {
            lvl1_base.pos.x = possible_spawnpoints[num].x;
            lvl1_base.pos.y = possible_spawnpoints[num].y;
        }
        if (num == 1)
        {

            lvl1_base.pos.x = possible_spawnpoints[num].x;
            lvl1_base.pos.y = possible_spawnpoints[num].y;
        }
        if (num == 2)
        {

            lvl1_base.pos.x = possible_spawnpoints[num].x;
            lvl1_base.pos.y = possible_spawnpoints[num].y;
        }
        if (num == 3)
        {

            lvl1_base.pos.x = possible_spawnpoints[num].x;
            lvl1_base.pos.y = possible_spawnpoints[num].y;
        }
        if (num == 4)
        {
            lvl1_base.pos.x = possible_spawnpoints[num].x;
            lvl1_base.pos.y = possible_spawnpoints[num].y;
        }
        if (num == 5)
        {

            lvl1_base.pos.x = possible_spawnpoints[num].x;
            lvl1_base.pos.y = possible_spawnpoints[num].y;
        }

        // speed randomization
        num = rand() % 6;
        if (num == 0)
        {

            lvl1_base.speed = 100;
        }
        if (num == 1)
        {

            lvl1_base.speed = 80;
        }
        if (num == 2)
        {

            lvl1_base.speed = 60;
        }
        if (num == 3)
        {

            lvl1_base.speed = 40;
        }
        if (num == 4)
        {

            lvl1_base.speed = 30;
        }
        if (num == 5)
        {

            lvl1_base.speed = 75;
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
            // works! like, too well!

            // implement killing the clones here:
            if (CheckCollisionRecs(enemy_list[i].rect, connector_index[j].rect))
            {
                connector_index[j].health -= 1;
            }
        }

        // implement moving towards the center here:
        Vector2 dir = Vector2Normalize(Vector2Subtract(target, enemy_list[i].pos));
        enemy_list[i].pos = Vector2Add(enemy_list[i].pos, Vector2Scale(dir, enemy_list[i].speed * GetFrameTime()));
        enemy_list[i].rect.x = enemy_list[i].pos.x;
        enemy_list[i].rect.y = enemy_list[i].pos.y;
        for (int j = 0; j < int(enemy_list.size()); j++)
        {
            if (i == j)
                continue;
            if (CheckCollisionRecs(enemy_list[i].rect, enemy_list[j].rect))
            {

                num = rand() % 4;
                if (num == 0)
                {
                    enemy_list[i].pos.x += enemy_list[j].rect.width;
                }
                if (num == 1)
                {
                    enemy_list[i].pos.x -= enemy_list[j].rect.width;
                }
                if (num == 2)
                {
                    enemy_list[i].pos.y += enemy_list[j].rect.height;
                }
                if (num == 3)
                {
                    enemy_list[i].pos.y -= enemy_list[j].rect.height;
                }
            }
        }
        if (enemy_list[i].pos.x > 790)
        {
            enemy_list[i].pos.x = 790;
        }
        if (enemy_list[i].pos.y > 790)
        {
            enemy_list[i].pos.y = 790;
        }
        if (enemy_list[i].pos.x < 0)
        {
            enemy_list[i].pos.x = 0;
        }
        if (enemy_list[i].pos.y < 0)
        {
            enemy_list[i].pos.y = 0;
        }
        Rectangle scaled_sprites = {enemy_list[i].pos.x, enemy_list[i].pos.y, enemy_list[i].rect.width * ENEMY_SCALE, enemy_list[i].rect.height * ENEMY_SCALE};
        DrawTexturePro(enemy_tex, enemy_list[i].img_rect, scaled_sprites, default_rotation, 0, WHITE);
    }
}

void enemies_init()
{
    enemy_tex = LoadTexture("gfx/enemies/enemies.png");
};

void enemies_update() {
    if(wave_state == 0){}
    if(wave_state == 1){
        wave_1_update();
    }
};