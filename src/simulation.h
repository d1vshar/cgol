#ifndef SIMULATION_H
#define SIMULATION_H

#include "constants.h"
#include "structs.h"

/*
 * Simulates one generation on the grid buffer provided.
 * 
 * @param buf       Buffer provided of type struct Grid, GRID_COLS
 *                  is defined in constants.h
 * 
 */
void SimulateGeneration(struct Grid buf[][GRID_COLS]);

#endif