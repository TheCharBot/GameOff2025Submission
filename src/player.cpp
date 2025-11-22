#include "player.hpp"

Texture2D player_tex;

Vector2 wall_place_pos;

std::vector<sprite_pos_rects> connector_index = {};
std::vector<Rectangle> range_index = {};
std::vector<Rectangle> melee_index = {};

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

void player_init()
{
    player_tex = LoadTexture("gfx/walls/walls.png");
}

void player_update()
{

    if (place_type == 0)
    {
    }

    // connector placement
    if (place_type == 1)
    {
        wall_place_pos.x = grid_spaces_x[get_cell_mouse()];
        wall_place_pos.y = grid_spaces_y[get_cell_mouse()];
        Rectangle scaled_sprites = {wall_place_pos.x, wall_place_pos.y, float(WALL_SPRITE_WIDTH * WALL_SCALE), float(WALL_SPRITE_HEIGHT * WALL_SCALE)};

        DrawTexturePro(player_tex, basic_connector, scaled_sprites, default_rotation, 0, WHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {

            connector_index.push_back({basic_connector, {wall_place_pos.x, wall_place_pos.y, 32, 32}});
            

            place_type = 0;
        }
    }

    // range attacker placement
    if (place_type == 2)
    {
        wall_place_pos.x = grid_spaces_x[get_cell_mouse()];
        wall_place_pos.y = grid_spaces_y[get_cell_mouse()];
        Rectangle scaled_sprites = {wall_place_pos.x, wall_place_pos.y, float(WALL_SPRITE_WIDTH * WALL_SCALE), float(WALL_SPRITE_HEIGHT * WALL_SCALE)};

        DrawTexturePro(player_tex, range_attacker, scaled_sprites, default_rotation, 0, WHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {

            range_index.push_back({wall_place_pos.x, wall_place_pos.y, 32, 32});

            place_type = 0;
        }
    }

    // melee attacker placement
    if (place_type == 3)
    {
        wall_place_pos.x = grid_spaces_x[get_cell_mouse()];
        wall_place_pos.y = grid_spaces_y[get_cell_mouse()];
        Rectangle scaled_sprites = {wall_place_pos.x, wall_place_pos.y, float(48 * WALL_SCALE), float(WALL_SPRITE_HEIGHT * WALL_SCALE)};

        DrawTexturePro(player_tex, melee_attacker, scaled_sprites, default_rotation, 0, WHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {

            melee_index.push_back({wall_place_pos.x, wall_place_pos.y, 48, 32});

            place_type = 0;
        }
    }

    // drawing stored towers
    bool right = false;
    bool left = false;
    bool up = false;
    bool down = false;
    for (int i = 0; i < int(connector_index.size()); i++)
    {

        Rectangle scaled_sprites = {connector_index[i].where_to_draw_stuff_rect.x, connector_index[i].where_to_draw_stuff_rect.y, float(WALL_SPRITE_WIDTH * WALL_SCALE), float(WALL_SPRITE_HEIGHT * WALL_SCALE)};

        DrawTexturePro(player_tex, connector_index[i].stuff_to_draw_rect, scaled_sprites, default_rotation, 0, WHITE);

        right = false;
        left = false;
        up = false;
        down = false;
        for (int j = 0; j < int(connector_index.size()); j++)
        {
            
            if(i == j) continue;
            if (connector_index[j].where_to_draw_stuff_rect.x == connector_index[i].where_to_draw_stuff_rect.x && connector_index[j].where_to_draw_stuff_rect.y == connector_index[i].where_to_draw_stuff_rect.y - 32) up = true;
            if (connector_index[j].where_to_draw_stuff_rect.x == connector_index[i].where_to_draw_stuff_rect.x && connector_index[j].where_to_draw_stuff_rect.y == connector_index[i].where_to_draw_stuff_rect.y + 32) down = true;
            if (connector_index[j].where_to_draw_stuff_rect.x == connector_index[i].where_to_draw_stuff_rect.x - 32 && connector_index[j].where_to_draw_stuff_rect.y == connector_index[i].where_to_draw_stuff_rect.y) left = true;
            if (connector_index[j].where_to_draw_stuff_rect.x == connector_index[i].where_to_draw_stuff_rect.x + 32 && connector_index[j].where_to_draw_stuff_rect.y == connector_index[i].where_to_draw_stuff_rect.y) right = true;
            

            if (up && down && left && right) {
                connector_index[i].stuff_to_draw_rect = down_left_right_connector;   // optional
            }
            else if (left && right && !up && !down) {
                connector_index[i].stuff_to_draw_rect = left_right_wall;
            }
            else if (up && down && !left && !right) {
                connector_index[i].stuff_to_draw_rect = up_down_wall;
            }
            else if (down && right) {
                connector_index[i].stuff_to_draw_rect = down_right_connector;
            }
            else if (down && left) {
                connector_index[i].stuff_to_draw_rect = down_left_connector;
            }
            else if (right) {
                connector_index[i].stuff_to_draw_rect = right_connector;
            }
            else if (left) {
                connector_index[i].stuff_to_draw_rect = left_connector;
            }
            else if (down) {
                connector_index[i].stuff_to_draw_rect = down_connector;
            }
            else {
                connector_index[i].stuff_to_draw_rect = basic_connector;
            }
            
        }
    }

    for (int i = 0; i < int(range_index.size()); i++)
    {
        Rectangle scaled_sprites = {range_index[i].x, range_index[i].y, float(WALL_SPRITE_WIDTH * WALL_SCALE), float(WALL_SPRITE_HEIGHT * WALL_SCALE)};
        DrawTexturePro(player_tex, range_attacker, scaled_sprites, default_rotation, 0, WHITE);
    }

    for (int i = 0; i < int(melee_index.size()); i++)
    {
        Rectangle scaled_sprites = {melee_index[i].x, melee_index[i].y, float(48 * WALL_SCALE), float(WALL_SPRITE_HEIGHT * WALL_SCALE)};
        DrawTexturePro(player_tex, melee_attacker, scaled_sprites, default_rotation, 0, WHITE);
    }
}

void Wall::init()
{
    //
}
