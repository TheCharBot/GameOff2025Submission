#include "player.hpp"

Texture2D player_tex;

Vector2 wall_place_pos;

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

int round_up(int numToRound, int multiple)
{
    if (multiple == 0)
        return numToRound;

    int remainder = abs(numToRound) % multiple;
    if (remainder == 0)
        return numToRound;

    if (numToRound < 0)
        return -(abs(numToRound) - remainder);
    else
        return numToRound + multiple - remainder;
}

void player_init(){
    player_tex = LoadTexture("gfx/walls/walls.png");
}

void player_update(){
    if(place_type == 0){

    }
    if(place_type == 1){
        wall_place_pos.x = grid_spaces_x[get_cell_mouse()];
        wall_place_pos.y = grid_spaces_y[get_cell_mouse()];
        Rectangle scaled_sprites = {wall_place_pos.x, wall_place_pos.y, float(WALL_SPRITE_WIDTH * WALL_SCALE), float(WALL_SPRITE_HEIGHT * WALL_SCALE)};
        
        DrawTexturePro(player_tex, basic_connector, scaled_sprites, default_rotation, 0, WHITE);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            place_type = 0;
        }
    }
}

void Wall::init(){
    //
}

