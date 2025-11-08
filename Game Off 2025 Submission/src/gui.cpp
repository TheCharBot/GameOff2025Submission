#include "gui.hpp"

#include "config.hpp"


Vector2 default_rotation;
Texture2D all_elements;
Vector2 slot_1_position;
Rectangle elements[1] = {
    {0, 0, 18, 18},
};


void gui_init(){
    all_elements = LoadTexture("gfx/gui/gui.png");
    
    
}
void gui_update(){
    
}

void Button_bottom_trio::init(){
    slot_1_position.x = (SLOT_1_X);
    slot_1_position.y = (BUTTON_BOTTOM_TRIO_Y);
    slot_2_position.x = (SLOT_2_X);
    slot_2_position.y = (BUTTON_BOTTOM_TRIO_Y);
    slot_3_position.x = (SLOT_3_X);
    slot_3_position.y = (BUTTON_BOTTOM_TRIO_Y);
    button_1_rect = {SLOT_1_X, BUTTON_BOTTOM_TRIO_Y, 54, 54};
    button_2_rect = {SLOT_2_X, BUTTON_BOTTOM_TRIO_Y, 54, 54};
    button_3_rect = {SLOT_3_X, BUTTON_BOTTOM_TRIO_Y, 54, 54};
}

void Button_bottom_trio::update(){
    scaled_sprite_1 = {slot_1_position.x, slot_1_position.y, elements[0].width * GUI_SCALE, elements[0].height * GUI_SCALE};
    DrawTexturePro(all_elements, elements[0], scaled_sprite_1, default_rotation, 0, WHITE);
    scaled_sprite_2 = {slot_2_position.x, slot_2_position.y, elements[0].width * GUI_SCALE, elements[0].height * GUI_SCALE};
    DrawTexturePro(all_elements, elements[0], scaled_sprite_2, default_rotation, 0, WHITE);
    scaled_sprite_3 = {slot_3_position.x, slot_3_position.y, elements[0].width * GUI_SCALE, elements[0].height * GUI_SCALE};
    DrawTexturePro(all_elements, elements[0], scaled_sprite_3, default_rotation, 0, WHITE);
    if(CheckCollisionPointRec(GetMousePosition(), button_1_rect)){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            std::cout << "worked 1";
        };
    };
    if(CheckCollisionPointRec(GetMousePosition(), button_2_rect)){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            std::cout << "worked 2";
        };
    };
    if(CheckCollisionPointRec(GetMousePosition(), button_3_rect)){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            std::cout << "worked 3";
        };
    };
};


int Button_bottom_trio::is_pressed(){
    return 1;
};

