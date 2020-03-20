#include <raylib.h>
#include <stdio.h>
#include "ui.h"
#include "constants.h"
#include "config.h"
#include "structs.h"

int main(void)
{

    double lastRecordedTime = 0;
    double generation = 1.00;
    char generationStr[12];
    Vector2 vTmp;
    struct Grid grids[GRID_ROWS][GRID_COLS];

    int i, j;
    for (i = 0; i < GRID_ROWS; i++)
    {
        for (j = 0; j < GRID_COLS; j++)
        {
            vTmp.x = j + 1;
            vTmp.y = i + 1;
            struct Grid g = {vTmp, 0};
            grids[i][j].pos = vTmp;
            grids[i][j].filled = 0;
        }
    }

    ReadConfig(grids, "config.txt");

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "cgol");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        double currentTime = GetTime();
        if (currentTime - lastRecordedTime > 0.125)
        {
            sprintf(generationStr, "%.0lf", generation);
            lastRecordedTime = currentTime;
            generation += 1.0;
        }
        InitBase();
        UpdateGrids(grids);
        DrawGeneration(generationStr);
        DrawMouseTrace();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}