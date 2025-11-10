#ifndef GUI_HPP
#define GUI_HPP

#include "raylib.h"

extern Texture2D all_elements;
extern Rectangle elements[1];


extern Vector2 default_rotation;

extern void gui_init();
extern void gui_update();

class Button_bottom_trio{
    public:
    Rectangle button_1_rect;
    Rectangle button_2_rect;
    Rectangle button_3_rect;
    Vector2 slot_1_position;
    Vector2 slot_2_position;
    Vector2 slot_3_position;
    Rectangle scaled_sprite_1;
    Rectangle scaled_sprite_2;
    Rectangle scaled_sprite_3;
    
    void init();
    int is_pressed();
    void update();

};

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