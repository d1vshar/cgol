#ifndef CONFIG_H
#define CONFIG_H
#include <raylib.h>
#include "constants.h"
#include "structs.h"

/*
 * Reads a file in the current working directory and initializes the grid 
 * buffer provided as parameter.
 * 
 * @param buf       Buffer provided of type struct Grid, GRID_COLS
 *                  is defined in constants.h
 * @param filename  Filename of config file
 * 
 */
void ReadConfig(struct Grid buf[][GRID_COLS], char *filename);

#endif