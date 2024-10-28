#pragma once
#include "config.h"
#include <string>
#include <iostream>
#include <list>
#include "Buttons.h"

class M 
{
	std::string Title;
	std::string Director;
	std::string Cast;
	std::string Year;
	std::string Type1;
	std::string Type2;
	std::string Type3;
	std::string Pic;
	float pos_x = CANVAS_WIDTH / 2;
	float pos_y = CANVAS_HEIGHT / 2;

public:
	void update();
	void draw();
	void init();
	M(std::string title, std::string director, std::string cast,std::string year, std::string type1, std::string type2, std::string type3, std::string pic);
	void setTitle(std::string title)
	{
		Title = title;
	}
	std::string getTitle()
	{
		return Title;
	}

	void setDirector(std::string director)
	{
		Director = director;
	}

	std::string getDirector()
	{
		return Director;
	}

	void setCast(std::string cast)
	{
		Cast = cast;
	}

	std::string getCast()
	{
		return Cast;
	}

	void setYear(std::string year)
	{
		Year = year;
	}

	std::string getYear()
	{
		return Year;
	}

	void setType(std::string type1)
	{
		Type1 = type1;
	}

	std::string getType1()
	{
		return Type1;
	}

	std::string getType2()
	{
		return Type2;
	}

	std::string getType3()
	{
		return Type3;
	}

	void setPic(std::string pic)
	{
		Pic = pic;
	}

	std::string getPic()
	{
		return Pic;
	}
};