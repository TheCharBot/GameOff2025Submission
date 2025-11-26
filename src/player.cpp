#include "player.hpp"

Texture2D player_tex;

Vector2 wall_place_pos;

std::vector<sprite_pos_rects> connector_index = {};
std::vector<Rectangle> range_index = {};
std::vector<Rectangle> melee_index = {};

int cell = get_cell_mouse();
int last_cell = 0;
int can_place = false;

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

bool right = false;
bool left = false;
bool up = false;
bool down = false;

void player_init()
{
    player_tex = LoadTexture("gfx/walls/walls.png");
}

void add_towers()
{
    if (place_type == 1)
    {

        cell = get_cell_mouse();
        wall_place_pos.x = grid_spaces_x[get_cell_mouse()];
        wall_place_pos.y = grid_spaces_y[get_cell_mouse()];
        Rectangle scaled_sprites = {wall_place_pos.x, wall_place_pos.y, float(WALL_SPRITE_WIDTH * WALL_SCALE), float(WALL_SPRITE_HEIGHT * WALL_SCALE)};

        DrawTexturePro(player_tex, basic_connector, scaled_sprites, default_rotation, 0, WHITE);

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            can_place = true;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && can_place)
        {
            // Only place if we moved to a new grid square
            if (cell != last_cell)
            {
                connector_index.push_back({basic_connector, {wall_place_pos.x, wall_place_pos.y, 32, 32}, 10});

                last_cell = cell; // remember last placed cell
            }
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            place_type = 0;
            can_place = false;
            last_cell = -1;
        }
    }

    // range attacker placement
    if (place_type == 2)
    {
        cell = get_cell_mouse();
        wall_place_pos.x = grid_spaces_x[get_cell_mouse()];
        wall_place_pos.y = grid_spaces_y[get_cell_mouse()];
        Rectangle scaled_sprites = {wall_place_pos.x, wall_place_pos.y, float(WALL_SPRITE_WIDTH * WALL_SCALE), float(WALL_SPRITE_HEIGHT * WALL_SCALE)};

        DrawTexturePro(player_tex, range_attacker, scaled_sprites, default_rotation, 0, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            can_place = true;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && can_place)
        {
            // Only place if we moved to a new grid square
            if (cell != last_cell)
            {
                range_index.push_back({wall_place_pos.x, wall_place_pos.y, 32, 32});

                last_cell = cell; // remember last placed cell
            }
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            place_type = 0;
            can_place = false;
            last_cell = -1;
        }
    }

    // melee attacker placement
    if (place_type == 3)
    {
        cell = get_cell_mouse();
        wall_place_pos.x = grid_spaces_x[get_cell_mouse()];
        wall_place_pos.y = grid_spaces_y[get_cell_mouse()];
        Rectangle scaled_sprites = {wall_place_pos.x, wall_place_pos.y, float(48 * WALL_SCALE), float(WALL_SPRITE_HEIGHT * WALL_SCALE)};

        DrawTexturePro(player_tex, melee_attacker, scaled_sprites, default_rotation, 0, WHITE);
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            can_place = true;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && can_place)
        {
            // Only place if we moved to a new grid square
            if (cell != last_cell)
            {
                melee_index.push_back({wall_place_pos.x, wall_place_pos.y, 48, 32});

                last_cell = cell; // remember last placed cell
            }
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            place_type = 0;
            can_place = false;
            last_cell = -1;
        }
    }
};

void player_update()
{

    if (place_type == 0)
    {
        can_place = false;
    }

    if (place_type != 0 && menu_state == 0)
    {

        add_towers();
    }
    // connector placement

    // drawing stored towers

    std::sort(connector_index.begin(), connector_index.end(), [](auto &a, auto &b)
              { return a.rect.y < b.rect.y; });

    for (int i = 0; i < int(connector_index.size()); i++)
    {
        if (connector_index[i].health <= 0)
        {
            connector_index.erase(connector_index.begin() + i);
        };
        right = false;
        left = false;
        up = false;
        down = false;
        for (int j = 0; j < int(connector_index.size()); j++)
        {
            if (i == j)
                continue;
            if (connector_index[j].rect.x == connector_index[i].rect.x && connector_index[j].rect.y == connector_index[i].rect.y - 32)
                up = true;
            if (connector_index[j].rect.x == connector_index[i].rect.x && connector_index[j].rect.y == connector_index[i].rect.y + 32)
                down = true;
            if (connector_index[j].rect.x == connector_index[i].rect.x - 32 && connector_index[j].rect.y == connector_index[i].rect.y)
                left = true;
            if (connector_index[j].rect.x == connector_index[i].rect.x + 32 && connector_index[j].rect.y == connector_index[i].rect.y)
                right = true;
        }
        Rectangle sprite;

        if (up && down && left && right)
            sprite = down_left_right_connector;
        else if (down && left && right)
            sprite = down_left_right_connector;
        else if (up && left && right)
            sprite = left_right_connector;
        else if (up && down && left)
            sprite = down_left_connector;
        else if (up && down && right)
            sprite = down_right_connector;
        else if (left && right)
            sprite = left_right_wall;
        else if (up && down)
            sprite = up_down_wall;
        else if (down && right)
            sprite = down_right_connector;
        else if (down && left)
            sprite = down_left_connector;
        else if (up && right)
            sprite = right_connector;
        else if (up && left)
            sprite = left_connector;
        else if (right)
            sprite = right_connector;
        else if (left)
            sprite = left_connector;
        else if (down)
            sprite = down_connector;
        else if (up)
            sprite = basic_connector;
        else
            sprite = basic_connector;

        connector_index[i].img_rect = sprite;
        Rectangle scaled_sprites = {connector_index[i].rect.x, connector_index[i].rect.y, float(WALL_SPRITE_WIDTH * WALL_SCALE), float(WALL_SPRITE_HEIGHT * WALL_SCALE)};

        DrawTexturePro(player_tex, connector_index[i].img_rect, scaled_sprites, default_rotation, 0, WHITE);
    }
    std::sort(range_index.begin(), range_index.end(), [](auto &a, auto &b)
              { return a.y < b.y; });

    for (int i = 0; i < int(range_index.size()); i++)
    {

        Rectangle scaled_sprites = {range_index[i].x, range_index[i].y, float(WALL_SPRITE_WIDTH * WALL_SCALE), float(WALL_SPRITE_HEIGHT * WALL_SCALE)};
        DrawTexturePro(player_tex, range_attacker, scaled_sprites, default_rotation, 0, WHITE);
    }

    std::sort(melee_index.begin(), melee_index.end(), [](auto &a, auto &b)
              { return a.y < b.y; });
    for (int i = 0; i < int(melee_index.size()); i++)
    {

        Rectangle scaled_sprites = {melee_index[i].x, melee_index[i].y, float(48 * WALL_SCALE), float(WALL_SPRITE_HEIGHT * WALL_SCALE)};
        DrawTexturePro(player_tex, melee_attacker, scaled_sprites, default_rotation, 0, WHITE);
    }
}
