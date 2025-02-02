#include <raylib.h>
#include "game/Game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
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
    Color backgroundColor = {10, 120, 156, 124};
    int rectangleSide = 300;
    InitWindow(rectangleSide, rectangleSide * 2, "Tetris by C++");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        if (EventTriggered(0.3))
            game.MoveBlockDown();
        BeginDrawing();
        ClearBackground(backgroundColor);
        game.DrawBlock();
        EndDrawing();
    }
    CloseWindow();
}
