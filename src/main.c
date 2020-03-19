#include <raylib.h>
#include <stdio.h>
#include "ui.h"

#define SCREEN_WIDTH 1145
#define SCREEN_HEIGHT 795
#define GRID_SIZE 15
#define BORDER_SIZE 20
#define STATUS_BAR_SIZE 25

int main(void)
{
    double lastRecordedTime = 0;
    double generation = 1.00;
    char generationStr[12];
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "cgol");

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