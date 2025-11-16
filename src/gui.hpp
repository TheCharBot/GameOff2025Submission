#ifndef GUI_HPP
#define GUI_HPP

#include "raylib.h"
#include "config.hpp"
#include <vector>


extern std::vector<int> grid_spaces_x;
extern std::vector<int> grid_spaces_y;

extern int menu_state;

extern Texture2D all_elements;

extern Rectangle elements[5];
extern Rectangle grid_select;
extern Rectangle grid_square;
extern Rectangle exit_rect;

extern Vector2 exit_position;
extern Vector2 menu_position;
extern Vector2 default_rotation;


extern void gui_init();
extern void open_menu_1();
extern void update_gui();
extern int get_cell_mouse();
extern void draw_grid();
extern void gen_grid_coords();


class Bottom_button{
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