#ifndef STRUCTS_H
#define STRUCTS_H

#include <raylib.h>
/*
 * Grid struct defined for tracking status of every grid in the board.
 * 
 */
struct Grid
{
    Vector2 pos;
    int filled;
};

#endif