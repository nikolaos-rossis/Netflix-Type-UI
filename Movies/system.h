#pragma once
#include "graphics.h"
#include "m.h"
#include <list>
#include "Buttons.h"
#include "genre_button.h"


class System
{
	enum system_state {
		S1M, S2M, S3M, S4M, S5M, S6M, SEARCH, ANIMATION, ADVENTURE, ACTION, HORROR, DRAMA, ROMANCE,SCI_FI,COMEDY,MYSTERY
	}; // the S*M state is the original state without filters, while the rest of the states are responsible for the filters
	system_state s_state = S1M; //default state

	bool pic = false; //is responsible for changing the "Press Space..." 
	bool highlighted = false;// to highlight buttons 
	bool move = false; // to ensure that the slider is moving
	std::list<M*>m; //?
	M* mo[10];//List of all movies
	M* An[2]; //List of animation movies
	M* Ad[4]; //List of adventure movies
	M* Ac[3]; //List of action movies
	M* Ho[1]; //List of horror movies
	M* Dr[1]; //List of drama movies
	M* Ro[1]; //List of romance movies
	M* Sc[1]; //List of sci-fi movies
	M* Co[1]; //List of comedy movies
	M* My[1]; //List of mystery movies
	Buttons b; //Buttons Object
	Genre_Button* g[10]; //Table to create and draw the genre_Buttons
	int a; //helps on slider date setter
	int b2; //year on slider
	std::string b3; //helps slider on date setter
	bool drag_highlight = false; //to ensure the highlight during slider movement
	int checker = 0; //indicator for table
	float posx = CANVAS_WIDTH / 1.8;
	float posy= CANVAS_HEIGHT / 2.45;
public:
	void update();
	void draw();
	void init();
	System();
	~System();
};