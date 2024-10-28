#include "genre_button.h"
#include "graphics.h"
#include "config.h"
#include <iostream>

Genre_Button::Genre_Button(float x, float y,std::string name,float x2,float y2,float size)
{
	pos_x = x;
	pos_y = y;
	Name = name;
	pos_xt = x2;
	pos_yt = y2;
	Size = size;
}

void Genre_Button::draw()
{
	graphics::Brush br;
	br.outline_opacity = 1.0f;
	if (!highlithed)
	{
		SETCOLOR(br.fill_color, 255.0f, 255.0f, 255.0f);
	}
	else
	{
		SETCOLOR(br.fill_color, 0.0f, 255.0f, 0.0f);
	}
	
	graphics::drawRect(pos_x, pos_y, BUTTONS_SIZE_X, BUTTONS_SIZE_Y, br);

	graphics::Brush br2;
	SETCOLOR(br2.fill_color, 0.0f, 0.0f, 0.0f);
	graphics::setFont("FreeSans.ttf");
	graphics::drawText(pos_xt, pos_yt / 5.4, Size, Name, br2);
}

void Genre_Button::update()
{
	graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);

	if (contains_b(mx, my))
	{
		highlithed = true;
	}
	else
	{
		highlithed = false;
	}


}

bool Genre_Button::contains_b(float x, float y)
{
	return distance(x, y, pos_x, pos_y) < BUTTONS_SIZE_X * 0.4f;
}
