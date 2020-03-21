#include "constants.h"
#include "structs.h"
#include "simulation.h"
#include <stdio.h>

/*
 * Returns count of live neighbours around the provided coordinates.
 * Note that the coordinates given are grid's, which are 1 based.
 * 
 * @param buf       Buffer provided of type struct Grid, GRID_COLS
 *                  is defined in constants.h
 * @param gX        grid x coordinate
 * @param gY        grid y coordinate
 * 
 */
int GetLiveNeighbours(struct Grid buf[][GRID_COLS], int gX, int gY);
void GetDirFlags(int *dFlags, int gX, int gY);

void SimulateGeneration(struct Grid buf[][GRID_COLS])
{
    int nextBuf[GRID_ROWS][GRID_COLS], i, j;

    for (i = 0; i < GRID_ROWS; i++)
    {
        for (j = 0; j < GRID_COLS; j++)
        {
            int count = GetLiveNeighbours(buf,buf[i][j].pos.x,buf[i][j].pos.y);

            if (buf[i][j].filled && (count == 2 || count == 3)) 
                nextBuf[i][j] = 1;
            else if (!buf[i][j].filled && count == 3) 
                nextBuf[i][j] = 1;
            else
                nextBuf[i][j] = 0;
        }
    }

    for (i = 0; i < GRID_ROWS; i++)
    {
        for (j = 0; j < GRID_COLS; j++) {
            buf[i][j].filled = nextBuf[i][j];
        }
    }
}

int GetLiveNeighbours(struct Grid buf[][GRID_COLS], int gX, int gY)
{
    int dFlags[8] = {1,1,1,1,1,1,1,1}, i, j, count = 0;
    GetDirFlags(dFlags,gX,gY);
    gX--; gY--;

    for (i = 0; i < 8; i++)
    {
        if (dFlags[i])
        {
            switch (i)
            {
            case 0:
                if (buf[gY - 1][gX].filled)
                    count++;
                break;
            case 1:
                if (buf[gY - 1][gX + 1].filled)
                    count++;
                break;
            case 2:
                if (buf[gY][gX + 1].filled)
                    count++;
                break;
            case 3:
                if (buf[gY + 1][gX + 1].filled)
                    count++;
                break;
            case 4:
                if (buf[gY + 1][gX].filled)
                    count++;
                break;
            case 5:
                if (buf[gY + 1][gX - 1].filled)
                    count++;
                break;
            case 6:
                if (buf[gY][gX - 1].filled)
                    count++;
                break;
            case 7:
                if (buf[gY - 1][gX - 1].filled)
                    count++;
                break;
            }
        }
    }
    return count;
}

void GetDirFlags(int *dFlags, int gX, int gY) {
    if (gY <= 1)
    {
        dFlags[0] = 0;
        dFlags[1] = 0;
        dFlags[7] = 0;
    }
    if (gX >= GRID_COLS)
    {
        dFlags[1] = 0;
        dFlags[2] = 0;
        dFlags[3] = 0;
    }
    if (gY >= GRID_ROWS)
    {
        dFlags[3] = 0;
        dFlags[4] = 0;
        dFlags[5] = 0;
    }
    if (gX <= 1)
    {
        dFlags[5] = 0;
        dFlags[6] = 0;
        dFlags[7] = 0;
    }
}