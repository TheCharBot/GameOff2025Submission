#include "gui.hpp"

#include "config.hpp"

//0 for null, 1 for basic tower, 2 for ranged, 3 for melee tower
int place_type = 0;
int menu_state = 0;

Bottom_button button_1;
Bottom_button button_2;
Bottom_button button_3;

Texture2D all_elements;

Vector2 exit_position;
Vector2 default_rotation;
Vector2 menu_position;
Vector2 slot_1_position;

Rectangle tower_menu_rects[3] = {
    {MENU_OFFSET_X + 12, MENU_OFFSET_Y + 12, 54, 54},
    {MENU_OFFSET_X + 78, MENU_OFFSET_Y + 12, 54, 54},
    {MENU_OFFSET_X + 144, MENU_OFFSET_Y + 12, 54, 54}
};
Rectangle elements[7] = {
    {0, 0, 18, 18},
    {32, 0, 32, 32},
    {64, 0, 32, 32},
    {0, 32, 112, 96},
    {96, 0, 16, 16},
    {128, 0, 18, 18},
    {160, 0, 18, 18}
};
Rectangle exit_rect = {EXIT_X, EXIT_Y, 48, 48};

std::vector<int> grid_spaces_x = {};
std::vector<int> grid_spaces_y = {};



void gui_init()
{
    exit_position.x = EXIT_X;
    exit_position.y = EXIT_Y;
    menu_position.x = MENU_X;
    menu_position.y = MENU_Y;
    button_1.init(1);
    button_2.init(2);
    button_3.init(3);
    all_elements = LoadTexture("gfx/gui/gui.png");
}

void gui_update()
{

    if (menu_state == 1)
    {
        open_menu_1();
    }
    if (menu_state == 2)
    {
        open_menu_2();
    }
    if (menu_state == 3)
    {
        open_menu_3();
    }

    button_1.update();
    button_2.update();
    button_3.update();
}



void draw_menu(){
    Rectangle scaled_sprite = {menu_position.x, menu_position.y, elements[3].width * GUI_SCALE, elements[3].height * GUI_SCALE};
    DrawTexturePro(all_elements, elements[3], scaled_sprite, default_rotation, 0, WHITE);
    scaled_sprite = {exit_position.x, exit_position.y, elements[4].width * GUI_SCALE, elements[4].height * GUI_SCALE};
    DrawTexturePro(all_elements, elements[4], scaled_sprite, default_rotation, 0, WHITE);
};

void draw_menu_1_contents(){
    Rectangle scaled_sprites = {tower_menu_rects[0].x, tower_menu_rects[0].y, elements[0].width * GUI_SCALE, elements[0].height * GUI_SCALE};
    DrawTexturePro(all_elements, elements[0], scaled_sprites, default_rotation, 0, WHITE);


    scaled_sprites = {tower_menu_rects[1].x, tower_menu_rects[1].y, elements[5].width * GUI_SCALE, elements[5].height * GUI_SCALE};
    DrawTexturePro(all_elements, elements[5], scaled_sprites, default_rotation, 0, WHITE);


    scaled_sprites = {tower_menu_rects[2].x, tower_menu_rects[2].y, elements[6].width * GUI_SCALE, elements[6].height * GUI_SCALE};
    DrawTexturePro(all_elements, elements[6], scaled_sprites, default_rotation, 0, WHITE);
};

void open_menu_1()
{
    draw_menu();
    draw_menu_1_contents();
    if (CheckCollisionPointRec(GetMousePosition(), tower_menu_rects[0]))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            menu_state = 0;
            place_type = 1;
        }
    }
    if (CheckCollisionPointRec(GetMousePosition(), tower_menu_rects[1]))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            menu_state = 0;
            place_type = 2;
        }
    }
    if (CheckCollisionPointRec(GetMousePosition(), tower_menu_rects[2]))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            menu_state = 0;
            place_type = 3;
        }
    }
    if (CheckCollisionPointRec(GetMousePosition(), exit_rect))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            menu_state = 0;
            place_type = 0;
        }
    }
}
void open_menu_2()
{
    draw_menu();
    if (CheckCollisionPointRec(GetMousePosition(), exit_rect))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            menu_state = 0;
        }
    }
}
void open_menu_3()
{
    draw_menu();
    if (CheckCollisionPointRec(GetMousePosition(), exit_rect))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            menu_state = 0;
        }
    }
}

void gen_grid_coords()
{
    for (int y = 16; y < SCREEN_HEIGHT - 16; y += GRID_SPACE)
    {
        for (int x = 16; x < SCREEN_WIDTH - 16; x += GRID_SPACE)
        {
            grid_spaces_x.push_back(x);
            grid_spaces_y.push_back(y);
        }
    }
}

void draw_grid()
{
    for (int x = 16; x < SCREEN_WIDTH - 16; x += GRID_SPACE)
    {
        for (int y = 16; y < SCREEN_HEIGHT - 16; y += GRID_SPACE)
        {
            DrawRectangleLines(x, y, GRID_SPACE, GRID_SPACE, BLACK);
        }
    }
}



int get_cell_mouse()
{
    int gx = (GetMousePosition().x - 16) / GRID_SPACE;
    int gy = (GetMousePosition().y - 16) / GRID_SPACE;

    if (gx < 0 || gy < 0)
        return -1;

    int cells_x = (SCREEN_WIDTH - 32) / GRID_SPACE;

    return gy * cells_x + gx;
}



void Bottom_button::init(int index)
{
    if (index == 1)
    {
        self_index = 1;
        position.x = SLOT_1_X;
        rect = {SLOT_1_X, BOTTOM_BUTTON_Y, 54, 54};
        inited_sprite = elements[0];
    }
    if (index == 2)
    {
        self_index = 2;
        position.x = SLOT_2_X;
        rect = {SLOT_2_X, BOTTOM_BUTTON_Y, 54, 54};
        inited_sprite = elements[1];
    }
    if (index == 3)
    {
        self_index = 3;
        position.x = SLOT_3_X;
        rect = {SLOT_3_X, BOTTOM_BUTTON_Y, 54, 54};
        inited_sprite = elements[2];
    }

    position.y = BOTTOM_BUTTON_Y;
}

void Bottom_button::update()
{
    scaled_sprite = {position.x, position.y, inited_sprite.width * GUI_SCALE, inited_sprite.height * GUI_SCALE};
    DrawTexturePro(all_elements, inited_sprite, scaled_sprite, default_rotation, 0, WHITE);
    if (CheckCollisionPointRec(GetMousePosition(), rect))
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (self_index == 1)
            {
                menu_state = 1;
            }
            if (self_index == 2)
            {
                menu_state = 2;
            }
            if (self_index == 3)
            {
                menu_state = 3;
            }
        };
    };
}

int Bottom_button::is_pressed()
{
    if (CheckCollisionPointRec(GetMousePosition(), rect))
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            return 1;
        };
    }

    return 0;
}