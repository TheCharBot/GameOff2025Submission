#ifndef GUI_HPP
#define GUI_HPP

#include "raylib.h"

#include "config.hpp"
#include <vector>

extern std::vector<int> grid_spaces_x;
extern std::vector<int> grid_spaces_y;

extern int place_type;
extern int menu_state;
// Wave state - 0 for the start, 1 for the 1st wave, 1.1 for after fist wave, 2 for 2nd wave, 2.1 for after second wave, etc
extern double wave_state;

extern Texture2D all_elements;

extern Rectangle tower_menu_rects[];
extern Rectangle elements[7];
extern Rectangle grid_select;
extern Rectangle grid_square;
extern Rectangle exit_rect;

extern Vector2 exit_position;
extern Vector2 menu_position;
extern Vector2 default_rotation;

extern void gui_init();
extern void gui_update();

extern void draw_menu();
extern void draw_menu_1_contents();
extern void open_menu_1();

extern void open_menu_3();

extern int get_cell_mouse();

extern void gen_grid_coords();
extern void draw_grid();

class Bottom_button
{
public:
    int x;
    int y;
    int self_index;
    Rectangle rect;
    Vector2 position;
    Rectangle scaled_sprite;
    Rectangle inited_sprite;

    void init(int index);
    void update();
    int is_pressed();
};

extern Bottom_button button_1;
extern Bottom_button button_2;
extern Bottom_button button_3;

#endif