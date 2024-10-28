#pragma once
class Widget
{
public:
	virtual void space_checker() = 0; //responsible for the space button usage
	virtual void next_checker() = 0; //responsible for the -> button usage
	virtual void previous_checker() = 0; //responsible for the <- button usage
	virtual bool contains_s(float x,float y) = 0; //checks whether the mouse is inside a certain area
	virtual bool contains_ball(float x, float y,float x2,float y2) = 0; //checks whether the mouse is inside a the ball for the slider

};
