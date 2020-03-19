#ifndef UI_H
#define UI_H
#include <raylib.h>

void InitBase();
void DrawStatusBar();
void DrawGeneration(char *generationStr);
void DrawGrids();
void DrawBorders();
void DrawScaleX();
void DrawScaleY();
void DrawMouseTrace();
Vector2 TransformToScreenPoint(int x, int y);
Vector2 TransformToGridPoint(int x, int y);
#endif