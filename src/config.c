#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "constants.h"
#include "config.h"

void ReadConfig(struct Grid buf[][GRID_COLS], char *filename)
{
    char ch;
    int c = 0, x, y, tmp = 0, d;
    Vector2 vTmp;

    FILE *f = fopen(filename, "r");

    if (f != NULL)
    {
        printf("Config file found\n");

        while ((ch = fgetc(f)))
        {

            d = (int)ch - 48;

            if (d < 10 && d >= 0)
            {
                tmp = tmp * 10 + d;
            }

            if (ch == 44)
            {
                x = tmp;
                tmp = 0;
            }

            if (ch == '\n' || ch == EOF)
            {
                y = tmp;
                tmp = 0;

                printf("[%d, %d]\n", x, y);

                vTmp.x = x;
                vTmp.y = y;
                buf[y - 1][x - 1].pos = vTmp;
                buf[y - 1][x - 1].filled = 1;

                x = y = 0;

                if (ch == EOF)
                    break;
            }
        }
        fclose(f);
    }
}