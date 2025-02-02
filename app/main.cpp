#include <iostream>
#include <raylib.h>
#include "game/Game.h"
#include "game property/constants.h"
#include "colors/Colors.h"

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

Game game = Game();

int main()
    {
        UpdateMusicStream(game.music);
        InitWindow(rectangleHorizontalSideValue, rectangleVerticalSideValue, "Tetris by C++");
        SetTargetFPS(targetFPSValue);


        Font font = LoadFontEx(
            "../../Tetris/fonts/Press_Start_2P/PressStart2P-Regular.ttf", 64,
            nullptr,
            0);

        while (!WindowShouldClose())
            {
                game.handleInput();

                if (eventTriggered(gameSpeedValue))
                    {
                        game.moveBlockDown();
                    }

                BeginDrawing();

                ClearBackground(darkBlue);

                DrawTextEx(font, "Score", {xUiTextPosition, yUiTextPosition}, fontSizeUiText, 0,
                           WHITE);

                DrawTextEx(font, "Next", {xUiTextPosition + 5, yUiTextPosition + 160},
                           fontSizeUiText, 0,
                           WHITE);

                if (game.gameOver)
                    {
                        DrawTextEx(font, "GAME OVER", {xUiTextPosition - 25, yUiTextPosition + 435},
                                   fontSizeUiText - 2, 0,
                                   WHITE);
                    }

                DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);


                char scoreText[10];

                sprintf(scoreText, "%d", game.gameScore);

                Vector2 scoreTextSize = MeasureTextEx(font, scoreText, 38, 2);


                DrawTextEx(font, scoreText,
                           {xUiTextPosition + (140 - scoreTextSize.x) / 2, 70},
                           fontSizeUiText, 0,
                           WHITE);
                DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

                game.draw();

                EndDrawing();
            }

        CloseWindow();
        return 0;
    }
