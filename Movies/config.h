#pragma once
#include <math.h>
#include <iostream>

#define ASSET_PATH "assets\\"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 600
#define CANVAS_WIDTH 1000
#define CANVAS_HEIGHT 500
#define SEARCHER_SIZE 50
#define HELP_SIZE 50
#define BUTTONS_SIZE_X CANVAS_WIDTH / 25
#define BUTTONS_SIZE_Y CANVAS_HEIGHT / 25

#define SETCOLOR(c, r, g, b){c[0] = r; c[1] = g; c[2] = b;}

inline float distance(float x1, float y1, float x2, float y2)
{
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx + dy * dy);
}