#include <raylib.h>
#include "./game/Game.h"
#include "./game/constants.h"
#include "./colors/Colors.h"

using namespace tetris;

// Функция для контроля интервала между обновлениями (таймер)
bool eventTriggered(double interval)
    {
        static double lastUpdateTime = 0.0;
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
        // Инициализация окна
        InitWindow(kWindowWidth, kWindowHeight, "Tetris by C++");
        SetTargetFPS(kTargetFPS);

        // Загрузка шрифта
        Font font = LoadFontEx(kFontFile, 64, nullptr, 0);

        Game game;

        while (!WindowShouldClose())
            {
                UpdateMusicStream(game.music);
                game.handleInput();

                if (eventTriggered(kGameSpeedSeconds))
                    {
                        game.moveBlockDown();
                    }

                BeginDrawing();
                ClearBackground(kDarkBlue);

                // Отрисовка UI (очки, следующая фигура, сообщение GAME OVER)
                DrawTextEx(font, "Score", {
                               static_cast<float>(kXUiTextPosition),
                               static_cast<float>(kYUiTextPosition)
                           },
                           kFontSizeUiText, 0, WHITE);
                DrawTextEx(font, "Next", {
                               static_cast<float>(kXUiTextPosition + 5),
                               static_cast<float>(kYUiTextPosition + 160)
                           },
                           kFontSizeUiText, 0, WHITE);

                if (game.gameOver)
                    {
                        DrawTextEx(font, "GAME OVER", {
                                       static_cast<float>(kXUiTextPosition - 25),
                                       static_cast<float>(kYUiTextPosition + 435)
                                   },
                                   kFontSizeUiText - 2, 0, WHITE);
                    }

                DrawRectangleRounded({320, 55, 170, 60}, 0.3f, 6, kLightBlue);

                char scoreText[10];
                sprintf(scoreText, "%d", game.gameScore);
                Vector2 scoreTextSize = MeasureTextEx(font, scoreText, 38, 2);
                DrawTextEx(font, scoreText,
                           {kXUiTextPosition + (140 - scoreTextSize.x) / 2, 70},
                           kFontSizeUiText, 0, WHITE);

                DrawRectangleRounded({320, 215, 170, 180}, 0.3f, 6, kLightBlue);

                game.draw();

                EndDrawing();
            }

        UnloadFont(font);
        CloseWindow();
        return 0;
    }
