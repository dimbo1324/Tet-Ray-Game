#include <raylib.h>
#include "game/Game.h"
#include "game property/constants.h"

bool eventTriggered(double interval)
    {
        double currentTime = GetTime();
        if (currentTime - lastUpdateTimeValue >= interval)
            {
                lastUpdateTimeValue = currentTime;
                return true;
            }
        return false;
    }

int main()
    {
        InitWindow(rectangleHorizontalSideValue, rectangleVerticalSideValue, "Tetris by C++");
        SetTargetFPS(targetFPSValue);

        Game game;

        while (!WindowShouldClose())
            {
                game.handleInput();

                if (eventTriggered(gameSpeedValue))
                    {
                        game.moveBlockDown();
                    }

                BeginDrawing();
                ClearBackground(backgroundColorValue);

                game.draw();

                EndDrawing();
            }

        CloseWindow();
        return 0;
    }
