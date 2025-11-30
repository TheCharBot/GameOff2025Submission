// Wavebreak

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

    // initing stuff
    gui_init();
    player_init();

    enemies_init();
    // generating grid
    gen_grid_coords();

    // Game Loop
    while (WindowShouldClose() == false)
    {
        // Game Logic

        BeginDrawing();
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);

        // updating stuff

        player_update();
        enemies_update();

        // updating gui
        gui_update();

        EndDrawing();
        if(won){
            DrawTexture(win_screen, 336, 376, WHITE);
            std::cout << "\n" <<"You Won!" << "\n";
            system("PAUSE");
            break;
        }
        if(lost){
            DrawTexture(lose_screen, 336, 376, WHITE);
            std::cout << "\n" <<"You Lose!" << "\n";
            system("PAUSE");
            break;
        }
    }

    CloseWindow();

    return 0;
}