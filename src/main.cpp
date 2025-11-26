// Wavebreak
// 16x16 sprites at 320x180 is just way too good

// coding, compiling, curating, coproducing, calculating, can-do attitude
// big screen td game, similar to worldbox in scale and sprites
// enemies, large-scale td game
// waves of enemies visible

// base-building, upgrades, simple pixel art

// AAP-64 palette

// Boss fight similar to undertale, but with tower defense as well

// 6 waves,
// the wave of light(green),
// the wave of strength(pink),
// the wave of speed(yellow),
// the wave of time(brown),
// the wave of evasion(red), and
// the wave of defense(blue)

// each wave has own attack

// light: almost undodgable, low damage
// strength: dodgable, but high damage
// speed: undodgable, medium damage
// time: buffs other waves with time powers, so save slotting, similar to with the flowey fight
// evasion: allows boss and enemies to dodge your attacks
// defense: blocks your attacks when active, decently easy to dodge
#include "raylib.h"


#include "gui.hpp"
#include "player.hpp"
#include "enemies.hpp"

#include "config.hpp"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "WAVEBREAK");
    Image icon = LoadImage("gfx/icon/icon.png");
    SetWindowIcon(icon);
    UnloadImage(icon);
    SetTargetFPS(60);

    //initing stuff
    gui_init();
    player_init();
    
    enemies_init();
    //generating grid
    gen_grid_coords();
    
    // Game Loop
    while (WindowShouldClose() == false)
    {
        // Game Logic
        
        BeginDrawing();
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
        
        //updating stuff
        
        player_update();
        
        
        gui_update();
        
        enemies_update();

        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}