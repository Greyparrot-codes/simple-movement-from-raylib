#include <iostream>
#include "raylib.h"

int main(void)
{

    const int screenWidth = 1000;
    const int screenHeight = 500;

    int bpos_x = 500;
    int bpos_y = 250;

    int y_vel = 2;
    int j_vel = 3;

    bool Jump = false;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(8000);
    //images-------------------------------------


    Texture2D player = LoadTexture("images/square.png");
    Texture2D BACKROUND = LoadTexture("images/backround.png");


    //----------------------------------------------

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) bpos_x += 2;
        if (IsKeyDown(KEY_LEFT)) bpos_x -= 2;

        if(bpos_x <= 1000-50){
            bpos_x += 2;
        }
        if(bpos_x >= 0){
            bpos_x -= 2;
        }
        if(bpos_y <= 0){
            bpos_y += 8;
        }
        if(bpos_y >= 500-50){
            bpos_y -= 2;
        }

        //terrarian generation
        for(int y = 0; y < 10; y++){
            for(int x = 0; x < 20; x++){
                DrawTextureV(BACKROUND, {x*50,y*50}, WHITE);
            }
        }

        bpos_y += y_vel;

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTextureV(player, {bpos_x, bpos_y}, WHITE);
        EndDrawing();

    }
    UnloadTexture(player);


    CloseWindow();
    return 0;
}
