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

void Bottom_button::init(int index){
    if(index == 1){
        position.x = SLOT_1_X;
        rect = {SLOT_1_X, BOTTOM_BUTTON_Y, 54, 54};
    }
    if(index == 2){
        
        position.x = SLOT_2_X;
        rect = {SLOT_2_X, BOTTOM_BUTTON_Y, 54, 54};
    }
    if(index == 3){
        position.x = SLOT_3_X;
        rect = {SLOT_3_X, BOTTOM_BUTTON_Y, 54, 54};
    
        }
    
    
    position.y = BOTTOM_BUTTON_Y;
    
}

void Bottom_button::update(){
    scaled_sprite = {position.x, position.y, elements[0].width * GUI_SCALE, elements[0].height * GUI_SCALE};
    DrawTexturePro(all_elements, elements[0], scaled_sprite, default_rotation, 0, WHITE);
    if(CheckCollisionPointRec(GetMousePosition(), rect)){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            std::cout << "worked";
        };
    };
}

int Bottom_button::is_pressed(){
    if(CheckCollisionPointRec(GetMousePosition(), rect)){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            return 1;
        };
    }
    else{
        return 0;
    };
}
