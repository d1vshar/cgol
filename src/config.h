#ifndef CONFIG_H
#define CONFIG_H
#include <raylib.h>
#include "constants.h"
#include "structs.h"

void ReadConfig(struct Grid buf[][GRID_COLS], char *filename);

#endif