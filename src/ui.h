#ifndef UI_H
#define UI_H
#include <raylib.h>
#include "constants.h"
#include "structs.h"

/*
 * Base function that other calls Draw* functions. Responsible for value
 * independent painting.
 * 
 */
void InitBase();

/*
 * Paints grids black according to the grid buffer provided.
 * 
 * @param buf  Buffer provided of type struct Grid, GRID_COLS
 *             is defined in constants.h
 * 
 */
void UpdateGrids(struct Grid buf[][GRID_COLS]);

/*
 * Paints status bar based on constants.
 * 
 */
void DrawStatusBar();

/*
 * Paints generation label and generation value.
 * 
 * @param generationStr characters to draw for generation value
 * 
 */
void DrawGeneration(char *generationStr);

/*
 * Paints grids based on constants.
 * 
 */
void DrawGrids();

/*
 * Paints borders based on constants.
 * 
 */
void DrawBorders();

/*
 * Paints x axis scale based on constants.
 * 
 */
void DrawScaleX();

/*
 * Paints y axis scale based on constants.
 * 
 */
void DrawScaleY();

/*
 * Paints mouse trace to help user with coordinate tracking.
 * Limits based on constants.
 * 
 */
void DrawMouseTrace();

/*
 * Transforms grid number to screen coordinates. 
 * Top left screen coordinates are returned.
 * 
 * Formula used is:
 * SCREEN_COORD += GRID_SIZE * (GRID_NUM - 1);
 * 
 */
Vector2 TransformToScreenPoint(int x, int y);

/*
 * Transforms screen coordinates to grid number.
 * Top left screen coordinates are expected.
 * 
 * Formula used is:
 * SCREEN_COORD += GRID_SIZE * (GRID_NUM - 1);
 * 
 */
Vector2 TransformToGridPoint(int x, int y);
#endif