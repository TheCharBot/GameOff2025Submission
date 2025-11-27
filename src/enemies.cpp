#include "enemies.hpp"

Texture2D enemy_tex;

Vector2 target;

int num = 0;

bool won = false;
bool lost = false;

std::vector<enemy> enemy_list;
std::vector<enemy> empty_list = {};
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

void wave_initer_helper(enemy filler, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        // image randomization
        int num = rand() % 6;
        if (num == 0)
        {
            filler.img_rect = lvl1_green;
        }
        if (num == 1)
        {
            filler.img_rect = lvl1_pink;
        }
        if (num == 2)
        {
            filler.img_rect = lvl1_yellow;
        }
        if (num == 3)
        {
            filler.img_rect = lvl1_brown;
        }
        if (num == 4)
        {
            filler.img_rect = lvl1_red;
        }
        if (num == 5)
        {
            filler.img_rect = lvl1_blue;
        }

        // position randomization
        num = rand() % 6;
        if (num == 0)
        {
            filler.pos.x = possible_spawnpoints[num].x;
            filler.pos.y = possible_spawnpoints[num].y;
        }
        if (num == 1)
        {

            filler.pos.x = possible_spawnpoints[num].x;
            filler.pos.y = possible_spawnpoints[num].y;
        }
        if (num == 2)
        {

            filler.pos.x = possible_spawnpoints[num].x;
            filler.pos.y = possible_spawnpoints[num].y;
        }
        if (num == 3)
        {

            filler.pos.x = possible_spawnpoints[num].x;
            filler.pos.y = possible_spawnpoints[num].y;
        }
        if (num == 4)
        {
            filler.pos.x = possible_spawnpoints[num].x;
            filler.pos.y = possible_spawnpoints[num].y;
        }
        if (num == 5)
        {

            filler.pos.x = possible_spawnpoints[num].x;
            filler.pos.y = possible_spawnpoints[num].y;
        }

        // speed randomization
        num = rand() % 6;
        if (num == 0)
        {

            filler.speed = 100;
        }
        if (num == 1)
        {

            filler.speed = 80;
        }
        if (num == 2)
        {

            filler.speed = 60;
        }
        if (num == 3)
        {

            filler.speed = 40;
        }
        if (num == 4)
        {

            filler.speed = 30;
        }
        if (num == 5)
        {

            filler.speed = 75;
        }
        enemy_list.push_back(filler);
    }
};

void wave_1_init()
{
    enemy_list.clear();
    // setting target in a vector

    // making base enemy
    enemy lvl1_base;

    lvl1_base.health = LVL_1_HEALTH;
    lvl1_base.pos.x = 0;
    lvl1_base.pos.y = 0;
    // setting it to a base color, random later
    lvl1_base.img_rect = lvl1_green;
    lvl1_base.rect = {lvl1_base.pos.x, lvl1_base.pos.y, LVL1_SPRITE_WIDTH, LVL1_SPRITE_HEIGHT};

    wave_initer_helper(lvl1_base, WAVE_1_AMOUNT);
}

void wave_2_init()
{
    enemy_list.clear();
    // setting target in a vector

    // making base enemy
    // setting it to a base color, random later
    enemy lvl1_base;

    lvl1_base.health = LVL_1_HEALTH;
    lvl1_base.pos.x = 0;
    lvl1_base.pos.y = 0;
    lvl1_base.img_rect = lvl1_green;
    lvl1_base.rect = {lvl1_base.pos.x, lvl1_base.pos.y, LVL1_SPRITE_WIDTH, LVL1_SPRITE_HEIGHT};

    enemy lvl2_base;
    lvl2_base.health = LVL_2_HEALTH;
    lvl2_base.pos.x = 0;
    lvl2_base.pos.y = 0;
    lvl2_base.img_rect = lvl2_green;
    lvl2_base.rect = {lvl2_base.pos.x, lvl2_base.pos.y, LVL2_SPRITE_WIDTH, LVL2_SPRITE_HEIGHT};

    wave_initer_helper(lvl1_base, WAVE_2_LVL1_AMOUNT);
    wave_initer_helper(lvl2_base, WAVE_2_LVL2_AMOUNT);
}

void wave_3_init()
{
    enemy_list.clear();
    // setting target in a vector

    // making base enemy
    // setting it to a base color, random later
    enemy lvl1_base;

    lvl1_base.health = LVL_1_HEALTH;
    lvl1_base.pos.x = 0;
    lvl1_base.pos.y = 0;
    lvl1_base.img_rect = lvl1_green;
    lvl1_base.rect = {lvl1_base.pos.x, lvl1_base.pos.y, LVL1_SPRITE_WIDTH, LVL1_SPRITE_HEIGHT};

    enemy lvl2_base;
    lvl2_base.health = LVL_2_HEALTH;
    lvl2_base.pos.x = 0;
    lvl2_base.pos.y = 0;
    lvl2_base.img_rect = lvl2_green;
    lvl2_base.rect = {lvl2_base.pos.x, lvl2_base.pos.y, LVL2_SPRITE_WIDTH, LVL2_SPRITE_HEIGHT};

    enemy lvl3_base;
    lvl3_base.health = LVL_3_HEALTH;
    lvl3_base.pos.x = 0;
    lvl3_base.pos.y = 0;
    lvl3_base.img_rect = lvl2_green;
    lvl3_base.rect = {lvl3_base.pos.x, lvl3_base.pos.y, LVL3_SPRITE_WIDTH, LVL3_SPRITE_HEIGHT};

    wave_initer_helper(lvl1_base, WAVE_3_LVL1_AMOUNT);
    wave_initer_helper(lvl2_base, WAVE_3_LVL2_AMOUNT);
    wave_initer_helper(lvl3_base, WAVE_3_LVL3_AMOUNT);
}

void wave_4_init()
{
    enemy_list.clear();
    // setting target in a vector

    // making base enemy
    // setting it to a base color, random later

    enemy lvl3_base;
    lvl3_base.health = LVL_3_HEALTH;
    lvl3_base.pos.x = 0;
    lvl3_base.pos.y = 0;
    lvl3_base.img_rect = lvl2_green;
    lvl3_base.rect = {lvl3_base.pos.x, lvl3_base.pos.y, LVL3_SPRITE_WIDTH, LVL3_SPRITE_HEIGHT};

    enemy lvl4_base;
    lvl4_base.health = LVL_4_HEALTH;
    lvl4_base.pos.x = 0;
    lvl4_base.pos.y = 0;
    lvl4_base.img_rect = lvl2_green;
    lvl4_base.rect = {lvl4_base.pos.x, lvl4_base.pos.y, LVL4_SPRITE_WIDTH, LVL4_SPRITE_HEIGHT};

    wave_initer_helper(lvl3_base, WAVE_4_LVL3_AMOUNT);
    wave_initer_helper(lvl4_base, WAVE_4_LVL4_AMOUNT);
}

void wave_5_init()
{
    enemy_list.clear();
    // setting target in a vector

    // making base enemy
    // setting it to a base color, random later

    enemy lvl3_base;
    lvl3_base.health = LVL_3_HEALTH;
    lvl3_base.pos.x = 0;
    lvl3_base.pos.y = 0;
    lvl3_base.img_rect = lvl2_green;
    lvl3_base.rect = {lvl3_base.pos.x, lvl3_base.pos.y, LVL3_SPRITE_WIDTH, LVL3_SPRITE_HEIGHT};

    enemy lvl4_base;
    lvl4_base.health = LVL_4_HEALTH;
    lvl4_base.pos.x = 0;
    lvl4_base.pos.y = 0;
    lvl4_base.img_rect = lvl2_green;
    lvl4_base.rect = {lvl4_base.pos.x, lvl4_base.pos.y, LVL4_SPRITE_WIDTH, LVL4_SPRITE_HEIGHT};

    wave_initer_helper(lvl3_base, WAVE_5_LVL3_AMOUNT);
    wave_initer_helper(lvl4_base, WAVE_5_LVL4_AMOUNT);
}

void wave_6_init()
{
    enemy_list.clear();
    // setting target in a vector

    // making base enemy
    // setting it to a base color, random later

    enemy lvl3_base;
    lvl3_base.health = LVL_3_HEALTH;
    lvl3_base.pos.x = 0;
    lvl3_base.pos.y = 0;
    lvl3_base.img_rect = lvl2_green;
    lvl3_base.rect = {lvl3_base.pos.x, lvl3_base.pos.y, LVL3_SPRITE_WIDTH, LVL3_SPRITE_HEIGHT};

    enemy lvl4_base;
    lvl4_base.health = LVL_4_HEALTH;
    lvl4_base.pos.x = 0;
    lvl4_base.pos.y = 0;
    lvl4_base.img_rect = lvl2_green;
    lvl4_base.rect = {lvl4_base.pos.x, lvl4_base.pos.y, LVL4_SPRITE_WIDTH, LVL4_SPRITE_HEIGHT};

    wave_initer_helper(lvl3_base, WAVE_6_LVL3_AMOUNT);
    wave_initer_helper(lvl4_base, WAVE_6_LVL4_AMOUNT);
}

void wave_7_init()
{
    enemy_list.clear();
    // setting target in a vector

    // making base enemy
    // setting it to a base color, random later

    enemy lvl4_base;
    lvl4_base.health = LVL_4_HEALTH;
    lvl4_base.pos.x = 0;
    lvl4_base.pos.y = 0;
    lvl4_base.img_rect = lvl2_green;
    lvl4_base.rect = {lvl4_base.pos.x, lvl4_base.pos.y, LVL4_SPRITE_WIDTH, LVL4_SPRITE_HEIGHT};
    wave_initer_helper(lvl4_base, WAVE_7_LVL4_AMOUNT);
}

void wave_8_init()
{

    enemy lvl4_base;
    lvl4_base.health = LVL_4_HEALTH;
    lvl4_base.pos.x = 0;
    lvl4_base.pos.y = 0;
    lvl4_base.img_rect = lvl2_green;
    lvl4_base.rect = {lvl4_base.pos.x, lvl4_base.pos.y, LVL4_SPRITE_WIDTH, LVL4_SPRITE_HEIGHT};
    wave_initer_helper(lvl4_base, WAVE_8_LVL4_AMOUNT);
}

void wave_9_init()
{
    enemy lvl4_base;
    lvl4_base.health = LVL_4_HEALTH;
    lvl4_base.pos.x = 0;
    lvl4_base.pos.y = 0;
    lvl4_base.img_rect = lvl2_green;
    lvl4_base.rect = {lvl4_base.pos.x, lvl4_base.pos.y, LVL4_SPRITE_WIDTH, LVL4_SPRITE_HEIGHT};
    wave_initer_helper(lvl4_base, WAVE_9_LVL4_AMOUNT);
}

void wave_10_init()
{
    enemy lvl4_base;
    lvl4_base.health = LVL_4_HEALTH;
    lvl4_base.pos.x = 0;
    lvl4_base.pos.y = 0;
    lvl4_base.img_rect = lvl2_green;
    lvl4_base.rect = {lvl4_base.pos.x, lvl4_base.pos.y, LVL4_SPRITE_WIDTH, LVL4_SPRITE_HEIGHT};
    wave_initer_helper(lvl4_base, WAVE_9_LVL4_AMOUNT);
}

void wave_update()
{
    // does the stuff for every enemy instance
    for (int i = 0; i < int(enemy_list.size()); i++)
    {

        // damage-related checkers
        for (int j = 0; j < int(connector_index.size()); j++)
        {
            // works! like, too well!

            // implement killing the clones here:
            if (CheckCollisionRecs(enemy_list[i].rect, connector_index[j].rect))
            {
                connector_index[j].health -= 0.1;
                if (enemy_list[i].pos.x < 400)
                {
                    enemy_list[i].pos.x -= KNOCKBACK;
                }
                else if (enemy_list[i].pos.x > 400)
                {
                    enemy_list[i].pos.x += KNOCKBACK;
                }
                if (enemy_list[i].pos.y < 400)
                {
                    enemy_list[i].pos.y -= KNOCKBACK;
                }
                else if (enemy_list[i].pos.y > 400)
                {
                    enemy_list[i].pos.y += KNOCKBACK;
                }
            }
        }
        for (int j = 0; j < int(melee_index.size()); j++)
        {
            if (CheckCollisionRecs(enemy_list[i].rect, melee_index[j].rect))
            {
                enemy_list[i].health -= 5;
                melee_index[j].health -= 0.05;
                if (enemy_list[i].pos.x < 400)
                {
                    enemy_list[i].pos.x -= KNOCKBACK;
                }
                else if (enemy_list[i].pos.x > 400)
                {
                    enemy_list[i].pos.x += KNOCKBACK;
                }
                if (enemy_list[i].pos.y < 400)
                {
                    enemy_list[i].pos.y -= KNOCKBACK;
                }
                else if (enemy_list[i].pos.y > 400)
                {
                    enemy_list[i].pos.y += KNOCKBACK;
                }
            }
        }
        for (int j = 0; j < int(range_index.size()); j++)
        {
            if (CheckCollisionRecs(enemy_list[i].rect, range_index[j].rect))
            {
                enemy_list[i].health -= 1;
                range_index[j].health -= 1;
                if (enemy_list[i].pos.x < 400)
                {
                    enemy_list[i].pos.x -= KNOCKBACK;
                }
                else if (enemy_list[i].pos.x > 400)
                {
                    enemy_list[i].pos.x += KNOCKBACK;
                }
                if (enemy_list[i].pos.y < 400)
                {
                    enemy_list[i].pos.y -= KNOCKBACK;
                }
                else if (enemy_list[i].pos.y > 400)
                {
                    enemy_list[i].pos.y += KNOCKBACK;
                }
            }
        }

        for (int j = 0; j < int(range_attack_area.size()); j++)
        {
            if (CheckCollisionRecs(enemy_list[i].rect, range_attack_area[j]))
            {
                DrawRectangle(enemy_list[i].rect.x, enemy_list[i].rect.y, 4, 10, RED);
                enemy_list[i].health -= 0.1;
            }
        }
        if (enemy_list[i].health <= 0)
        {
            enemy_list.erase(enemy_list.begin() + i);
        }
        // moving towards the center and other movement calculations
        Vector2 dir = Vector2Normalize(Vector2Subtract(target, enemy_list[i].pos));
        enemy_list[i].pos = Vector2Add(enemy_list[i].pos, Vector2Scale(dir, enemy_list[i].speed * GetFrameTime()));
        enemy_list[i].rect.x = enemy_list[i].pos.x;
        enemy_list[i].rect.y = enemy_list[i].pos.y;

        // enemy-to enemy collision checks to reduce clipping
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

        // keeping the clones inside the screen
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
    target.x = 400;
    target.y = 400;
};

void enemies_update()
{
    if (wave_state == 0)
    {
    }
    if (wave_state == 1)
    {
        wave_update();
        if (enemy_list.size() == 0)
        {
            wave_state = 1.1;
        }
    }
    if (wave_state == 2)
    {
        wave_update();
        if (enemy_list.size() == 0)
        {
            wave_state = 2.1;
        }
    }
    if (wave_state == 3)
    {
        wave_update();
        if (enemy_list.size() == 0)
        {
            wave_state = 3.1;
        }
    }
    if (wave_state == 4)
    {
        wave_update();
        if (enemy_list.size() == 0)
        {
            wave_state = 4.1;
        }
    }
    if (wave_state == 5)
    {
        wave_update();
        if (enemy_list.size() == 0)
        {
            wave_state = 5.1;
        }
    }
    if (wave_state == 6)
    {
        wave_update();
        if (enemy_list.size() == 0)
        {
            wave_state = 6.1;
        }
    }
    if (wave_state == 7)
    {
        wave_update();
        if (enemy_list.size() == 0)
        {
            wave_state = 7.1;
        }
    }
    if (wave_state == 8)
    {
        wave_update();
        if (enemy_list.size() == 0)
        {
            wave_state = 8.1;
        }
    }
    if (wave_state == 9)
    {
        wave_update();
        if (enemy_list.size() == 0)
        {
            wave_state = 9.1;
        }
    }
    if (wave_state == 10)
    {
        wave_update();
        if (enemy_list.size() == 0)
        {
            wave_state = 10.1;
        }
    }
    if(wave_state >= 1 && connector_index.size() == 0 && range_index.size() == 0 && melee_index.size() == 0){
        lost = true;
    }
    if(wave_state >= 10.1 && connector_index.size() >= 1 && range_index.size() >= 1 && melee_index.size() >= 1){
        won = true;
    }
};
