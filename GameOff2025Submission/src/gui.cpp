#include "gui.hpp"

#include "config.hpp"

Vector2 default_rotation;
Texture2D all_elements;
Vector2 slot_1_position;
Rectangle elements[3] = {
    {0, 0, 18, 18},
    {32, 0, 48, 48},
    {80, 0, 32, 32}
};

std::vector<int> grid_spaces_x = {

};
std::vector<int> grid_spaces_y = {

};



void gui_init()
{
    all_elements = LoadTexture("gfx/gui/gui.png");
}

void gen_grid_coords(){
    for (int y = 16; y < SCREEN_HEIGHT-16; y += GRID_SPACE) {
        for (int x = 16; x < SCREEN_WIDTH-16; x += GRID_SPACE) {
            grid_spaces_x.push_back(x);
            grid_spaces_y.push_back(y);
        }
    }
}


void draw_grid() {
    for (int x = 16; x < SCREEN_WIDTH-16; x += GRID_SPACE) {
        for (int y = 16; y < SCREEN_HEIGHT-16; y += GRID_SPACE) {
            DrawRectangleLines(x, y, GRID_SPACE, GRID_SPACE, BLACK);
            
            
        }
    }
}

int get_cell_mouse() {
    int gx = (GetMousePosition().x - 16) / GRID_SPACE;
    int gy = (GetMousePosition().y - 16) / GRID_SPACE;

    if (gx < 0 || gy < 0) return -1;

    int cells_x = (SCREEN_WIDTH - 32) / GRID_SPACE;

    return gy * cells_x + gx;
}
void Bottom_button::init(int index)
{
    if (index == 1)
    {
        position.x = SLOT_1_X;
        rect = {SLOT_1_X, BOTTOM_BUTTON_Y, 54, 54};
    }
    if (index == 2)
    {

        position.x = SLOT_2_X;
        rect = {SLOT_2_X, BOTTOM_BUTTON_Y, 54, 54};
    }
    if (index == 3)
    {
        position.x = SLOT_3_X;
        rect = {SLOT_3_X, BOTTOM_BUTTON_Y, 54, 54};
    }

    position.y = BOTTOM_BUTTON_Y;
}

void Bottom_button::update()
{
    scaled_sprite = {position.x, position.y, elements[0].width * GUI_SCALE, elements[0].height * GUI_SCALE};
    DrawTexturePro(all_elements, elements[0], scaled_sprite, default_rotation, 0, WHITE);
    if (CheckCollisionPointRec(GetMousePosition(), rect))
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            std::cout << "worked";
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