#include <raylib.h>
#include "game/Game.h"
#include "utils/types/Types.h"


int main()
    {
        Color backgroundColor = {10, 120, 156, 124};
        sint rectangleSide = 300;
        InitWindow(rectangleSide, rectangleSide * 2, "Tetris by C++");
        SetTargetFPS(60);

        Game game = Game();

        while (WindowShouldClose() == false)
            {
                game.HandleInput();
                BeginDrawing();
                ClearBackground(backgroundColor);
                game.DrawBlock();
                EndDrawing();
            }
        CloseWindow();
    }
