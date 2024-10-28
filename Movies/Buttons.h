#pragma once
#include "widget.h"
#include "helperbutton.h"
class Buttons : public Helperbutton
{
	bool space = false; // 
	bool next = false; //
	bool previous = false; // 
public:
	Buttons();
	void space_checker() override;
	void next_checker() override;
	void previous_checker() override;
	bool contains_s(float x,float y) override;
	bool get_space();
	bool get_next();
	bool get_previous();
	bool contains_ball(float x, float y, float x2, float y2);
};