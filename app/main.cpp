#include <raylib.h>
#include "game/Game.h"

double lastUpdateTime = 0.0;

bool eventTriggered(double interval)
    {
        double currentTime = GetTime();
        if (currentTime - lastUpdateTime >= interval)
            {
                lastUpdateTime = currentTime;
                return true;
            }
        return false;
    }

int main()
    {
        const Color backgroundColor = {10, 120, 156, 124};
        const int rectangleSide = 300;

        InitWindow(rectangleSide, rectangleSide * 2, "Tetris by C++");
        SetTargetFPS(60);

        Game game;

        while (!WindowShouldClose())
            {
                game.handleInput();

                if (eventTriggered(0.3))
                    {
                        game.moveBlockDown();
                    }

                BeginDrawing();
                ClearBackground(backgroundColor);

                game.draw();

                EndDrawing();
            }

        CloseWindow();
        return 0;
    }
