#include <raylib.h>
#include "game/Game.h"
#include "game property/constants.h"

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
        InitWindow(rectangleSide, rectangleSide * 2, "Tetris by C++");
        SetTargetFPS(60);

        Game game;

        while (!WindowShouldClose())
            {
                game.handleInput();

                if (eventTriggered(0.003))
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

