#ifndef GUI_HPP
#define GUI_HPP

#include "raylib.h"

extern Texture2D all_elements;
extern Rectangle elements[1];


extern Vector2 default_rotation;

extern void gui_init();
extern void gui_update();


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