#include <raylib.h>
#include <stdio.h>
#include "ui.h"
#include "constants.h"

int main(void)
{
    double lastRecordedTime = 0;
    double generation = 1.00;
    char generationStr[12];
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "cgol");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        double currentTime = GetTime();
        if (currentTime - lastRecordedTime > 1.0)
        {
            sprintf(generationStr, "%.0lf", generation);
            lastRecordedTime = currentTime;
            generation += 1.0;
        }
        InitBase();
        DrawGeneration(generationStr);
        DrawMouseTrace();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}