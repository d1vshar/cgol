#include <raylib.h>
#include <stdio.h>
#include "ui.h"
#include "constants.h"
#include "structs.h"

void InitBase()
{
    ClearBackground(RAYWHITE);

    DrawStatusBar();
    DrawGrids();
    DrawBorders();
    DrawScaleX();
    DrawScaleY();
}

void UpdateGrids(struct Grid buf[][GRID_COLS])
{
    int i, j, x, y;
    Vector2 vTmp;

    for (i = 0; i < GRID_ROWS; i++)
    {
        for (j = 0; j < GRID_COLS; j++)
        {
            if (buf[i][j].filled)
            {
                vTmp = TransformToScreenPoint(j + 1, i + 1);
                DrawRectangle(vTmp.x, vTmp.y, GRID_SIZE, GRID_SIZE, BLACK);
            }
        }
    }
}

void DrawStatusBar()
{
    DrawRectangle(0, 0, WINDOW_WIDTH, STATUS_BAR_SIZE, BLACK);
    DrawLine(0, STATUS_BAR_SIZE, WINDOW_WIDTH, STATUS_BAR_SIZE, RAYWHITE);
}

void DrawGeneration(char *generationStr)
{
    DrawText("Generation:", 2, 2, 21, RAYWHITE);
    int nPixel = 2 + MeasureText("Generation:", 21);

    int m = MeasureText(generationStr, 21);
    int offSet = 120 - m;

    DrawText(generationStr, nPixel + offSet, 2, 21, RAYWHITE);
}

void DrawGrids()
{
    int x1, x2, y1, y2;
    x1 = BORDER_SIZE;
    x2 = WINDOW_WIDTH;
    y1 = y2 = STATUS_BAR_SIZE + BORDER_SIZE + GRID_SIZE;

    for (; y1 < WINDOW_HEIGHT; y1 += GRID_SIZE, y2 += GRID_SIZE)
    {
        DrawLine(x1, y1, x2, y2, BLACK);
    }

    x1 = x2 = BORDER_SIZE + GRID_SIZE;
    y1 = STATUS_BAR_SIZE + BORDER_SIZE;
    y2 = WINDOW_HEIGHT;

    for (; x1 < WINDOW_WIDTH; x1 += GRID_SIZE, x2 += GRID_SIZE)
    {
        DrawLine(x1, y1, x2, y2, BLACK);
    }
}

void DrawBorders()
{
    DrawRectangle(0, STATUS_BAR_SIZE, WINDOW_WIDTH, BORDER_SIZE, BLACK);
    DrawRectangle(0, STATUS_BAR_SIZE, BORDER_SIZE, WINDOW_HEIGHT, BLACK);
}

void DrawScaleX()
{
    int x = BORDER_SIZE, y = STATUS_BAR_SIZE + 5, size = 6, c = 1, xOffSet = 0;
    char s[3];

    while (x < WINDOW_WIDTH)
    {
        sprintf(s, "%d", c);

        xOffSet = (GRID_SIZE - MeasureText(s, size)) / 2;
        DrawText(s, x + xOffSet, y, size, RAYWHITE);
        x += GRID_SIZE;
        c++;
    }
}

void DrawScaleY()
{
    int y = STATUS_BAR_SIZE + BORDER_SIZE, size = 6, c = 1, xOffSet = 0;
    char s[3];

    while (y < WINDOW_HEIGHT)
    {
        sprintf(s, "%d", c);

        xOffSet = (GRID_SIZE - MeasureText(s, size)) / 2;
        DrawText(s, xOffSet, y + 3, size, RAYWHITE);
        y += GRID_SIZE;
        c++;
    }
}

void DrawMouseTrace()
{
    Vector2 v = GetMousePosition();
    int x = v.x <= WINDOW_WIDTH && v.x >= 0;
    int y = v.y <= WINDOW_HEIGHT && v.y >= STATUS_BAR_SIZE;
    if (x && y)
    {
        DrawLine(v.x, STATUS_BAR_SIZE, v.x, WINDOW_HEIGHT, RED);
        DrawLine(0, v.y, WINDOW_WIDTH, v.y, RED);
    }
}

Vector2 TransformToScreenPoint(int x, int y)
{
    int nX, nY;
    nX = BORDER_SIZE;
    nY = BORDER_SIZE + STATUS_BAR_SIZE;

    nX += GRID_SIZE * (x - 1);
    nY += GRID_SIZE * (y - 1);

    Vector2 v = {nX, nY};

    return v;
}

Vector2 TransformToGridPoint(int x, int y)
{
    int nX, nY;

    nX = (x - BORDER_SIZE) / GRID_SIZE + 1;
    nY = (y - STATUS_BAR_SIZE - BORDER_SIZE) / GRID_SIZE + 1;

    Vector2 v = {nX, nY};

    return v;
}