#ifndef GUI_HPP
#define GUI_HPP

#include "raylib.h"
#include "config.hpp"
#include <vector>


extern std::vector<int> grid_spaces_x;
extern std::vector<int> grid_spaces_y;

extern Texture2D all_elements;
extern Rectangle elements[3];
extern Rectangle grid_select;
extern Rectangle grid_square;


extern Vector2 default_rotation;

extern void gui_init();
extern void gui_update();
extern int get_cell_mouse();
extern void draw_grid();
extern void gen_grid_coords();


class Bottom_button{
    public:
    int x;
    int y;
    Rectangle rect;
    Vector2 position;
    Rectangle scaled_sprite;

    void init(int index);
    void update();
    int is_pressed();
};


#endif