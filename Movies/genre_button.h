#pragma once
#include <string>
class Genre_Button //The genre buttons 
{
	float pos_x; //button position x
	float pos_y; //button position y
	float pos_xt;//name position x
	float pos_yt;//name position y
	std::string Name; // name of the genre
	bool highlithed = false; // highlight button
	float Size; // size of button
public:
	Genre_Button(float x, float y, std::string name,float x2,float y2,float size); //constructor
	void draw();
	void update();
	bool contains_b(float x, float y); // checks whether mouse is inside the button
	float get_x() { return pos_x; } // returns pos of button x
	float get_y() { return pos_y; } //returns pos of button y
	void set_highlighted(bool h) { highlithed = h; } //sets highlight
	bool get_highlighted() { return highlithed; } // returns highlight status
};