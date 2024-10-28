#include "Buttons.h"
#include "graphics.h"
#include "config.h"
#include <iostream>


Buttons::Buttons()
{
}

void Buttons::space_checker() // if space is pressed set space = true and the programm starts
{
	if (graphics::getKeyState(graphics::SCANCODE_SPACE))
	{
		space = true;
	}
}

void Buttons::next_checker() //if next is pressed, set next to true and movie changes 
{
	next = false; // due to update running all the time, next must be set to false continously
	if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
	{
		next = true;
	}
}

void Buttons::previous_checker() // if previous is pressed, set previous to true and movie changes 
{
	previous = false; // due to update running all the time, previous must be set to false continously
	if (graphics::getKeyState(graphics::SCANCODE_LEFT))
	{
		previous = true;
	}
}

bool Buttons::contains_s(float x, float y) // checks if mouse is on searcher button
{
	return distance(x, y, CANVAS_WIDTH / 1.05, CANVAS_HEIGHT / 12) < SEARCHER_SIZE * 0.4f;
}

bool Buttons::get_space() // returns space value
{
	return space;
}

bool Buttons::get_next() // returns next value
{
	return next;
}

bool Buttons::get_previous() // returns previous value
{
	return previous;
}

bool Buttons::contains_ball(float x, float y, float x2, float y2) //checks if mouse is on ball slider
{
	return distance(x, y, x2, y2) < 5.0f * 0.9f;
}
