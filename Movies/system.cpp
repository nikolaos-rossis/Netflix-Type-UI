#include "system.h"
#include "config.h"
#include <string>
#include <iostream>

void System::update()
{
	graphics::MouseState ms; //the current state of the mouse
	graphics::getMouseState(ms); 

	float mx = graphics::windowToCanvasX(ms.cur_pos_x); //pos x of mouse
	float my = graphics::windowToCanvasY(ms.cur_pos_y); //pos y of mouse

	b.space_checker();//checks if space is pressed

	if (b.get_space() == true) //if it is switch to main screen
	{
		pic = true;
	}

	if (b.get_space()) // if we are on main screen
	{
		if (s_state == S1M)// 1st movie
		{
			b.next_checker(); // checks if he pressed next button
			if (b.get_next()) // if he did change to the next movie and follow the same steps
			{
				checker = 1;
				s_state = S2M;
			}
		}
		else if (s_state == S2M)// 2nd movie
		{
			b.next_checker();
			if (b.get_next())
			{
				checker = 2;
				s_state = S3M;
			}
			b.previous_checker(); // checks if he pressed previous button
			if (b.get_previous()) // if he did change to the previous movie and follow the same steps
			{
				checker = 0;
				s_state = S1M;
			}
		}
		else if (s_state == S3M) // 3rd movie
		{
			b.next_checker();
			if (b.get_next())
			{
				checker = 3;
				s_state = S4M;
			}
			b.previous_checker();
			if (b.get_previous())
			{
				checker = 1;
				s_state = S2M;
			}
		}
		else if (s_state == S4M) // 4th movie
		{
			b.next_checker();
			if (b.get_next())
			{
				checker = 4;
				s_state = S5M;
			}
			b.previous_checker();
			if (b.get_previous())
			{
				checker = 2;
				s_state = S3M;
			}
		}
		else if (s_state == S5M) // 5th movie
		{
			b.next_checker();
			if (b.get_next())
			{
				checker = 5;
				s_state = S6M;
			}
			b.previous_checker();
			if (b.get_previous())
			{
				checker = 3;
				s_state = S4M;
			}
		}
		else if (s_state == S6M) // 6th movie
		{
			b.previous_checker();
			if (b.get_previous())
			{
				checker = 4;
				s_state = S5M;
			}
		}

		if (b.contains_s(mx, my) && s_state != SEARCH) // if mouse is on searcher show window
		{
			highlighted = true;
		}
		else 
		{
			highlighted = false;
		}

		if (b.contains_s(mx, my) && ms.button_left_pressed) //if mouse is on searcher and press left click, keep window upen
		{
			s_state = SEARCH;
			highlighted = true;
		}
		for (auto genre : g)
		{
			genre->update();
		}
		if (g[0]->get_highlighted() && ms.button_left_pressed)
		{
			checker = 0;
			s_state = ANIMATION;
		}

		if (g[1]->get_highlighted() && ms.button_left_pressed)
		{
			checker = 0;
			s_state = ADVENTURE;
		}

		if (g[2]->get_highlighted() && ms.button_left_pressed)
		{
			checker = 0;
			s_state = S1M;
		}

		if (g[3]->get_highlighted() && ms.button_left_pressed)
		{
			checker = 0;
			s_state = ACTION;
		}
		
		if (g[4]->get_highlighted() && ms.button_left_pressed)
		{
			checker = 0;
			s_state = HORROR;
		}

		if (g[5]->get_highlighted() && ms.button_left_pressed)
		{
			checker = 0;
			s_state = DRAMA;
		}

		if (g[6]->get_highlighted() && ms.button_left_pressed)
		{
			checker = 0;
			s_state = ROMANCE;
		}

		if (g[7]->get_highlighted() && ms.button_left_pressed)
		{
			checker = 0;
			s_state = SCI_FI;
		}

		if (g[8]->get_highlighted() && ms.button_left_pressed)
		{
			checker = 0;
			s_state = COMEDY;
		}

		if (g[9]->get_highlighted() && ms.button_left_pressed)
		{
			checker = 0;
			s_state = MYSTERY;
		}

		if (s_state == ANIMATION)
		{
			b.next_checker();
			if (b.get_next())
			{
				if (checker < 1)
				{
					checker = checker + 1;
				}
			}
			b.previous_checker();
			if (b.get_previous())
			{
				if (checker > 0)
				{
					checker = checker - 1;
				}
				
			}
		}
		else if (s_state == ADVENTURE)
		{
			b.next_checker();
			if (b.get_next())
			{
				if (checker < 3)
				{
					checker = checker + 1;
				}
			}
			b.previous_checker();
			if (b.get_previous())
			{
				if (checker > 0)
				{
					checker = checker - 1;
				}
			}
		}
		else if (s_state == ACTION)
		{
			b.next_checker();
			if (b.get_next())
			{
				if (checker < 2)
				{
					checker = checker + 1;
				}
			}
			b.previous_checker();
			if (b.get_previous())
			{
				if (checker > 0)
				{
					checker = checker - 1;
				}
			}
		}
	}

	if (b.contains_ball(mx, my, posx, posy)) //checks if the mouse is inside the slider ball
	{
		move = true;
		drag_highlight = true;
	}
	else if(!move)
	{
		drag_highlight = false;
	}

	if (move)//if it contains it
	{
		
		if (ms.dragging) // if mouse is in a draggin state
		{
			if (mx > CANVAS_WIDTH / 1.8 && mx <= CANVAS_WIDTH/1.6) //the slides area
			{	
				posx = mx;
				a = 100 * (mx - CANVAS_WIDTH / 1.8) / 70;
				if (a < 7.69230769)
				{
					b2 = 2009;
				}
				else if (a < 15.38)
				{
					b2 = 2010;
				}
				else if (a < 23.07)
				{
					b2 = 2011;
				}
				else if (a < 30.76)
				{
					b2 = 2012;
				}
				else if (a < 38.46)
				{
					b2 = 2013;
				}
				else if (a < 46.15)
				{
					b2 = 2014;
				}
				else if (a < 53.84)
				{
					b2 = 2015;
				}
				else if (a < 61.53)
				{
					b2 = 2016;
				}
				else if (a < 69.23)
				{
					b2 = 2017;
				}
				else if (a < 76.92)
				{
					b2 = 2018;
				}
				else if (a < 84.61)
				{
					b2 = 2019;
				}
				else if (a < 92.307)
				{
					b2 = 2020;
				}
				else if (a < 100)
				{
					b2 = 2022;
				}
			}
		}
		else
		{
			move = false;
		}
	}
	
}
void System::draw()
{
	if (!pic) // draws the welcoming window 
	{
		graphics::Brush br;
		br.texture = std::string(ASSET_PATH) + "cinema.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_WIDTH, br);

		graphics::Brush br2;
		br2.outline_opacity = 0.0f;
		SETCOLOR(br2.fill_color, 255, 255, 255);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH/2.8, CANVAS_HEIGHT/1.5, 25.0f, "Press SPACE to enter...", br2);
	}
	else if(pic) //draws the movie  
	{
		graphics::Brush br;
		br.texture = std::string(ASSET_PATH) + "orange-background.png"; //draws background
		br.outline_opacity = 0.0f;
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_WIDTH, br);

		graphics::Brush br2;
		br2.texture = std::string(ASSET_PATH) + "searcher.png";//draws searcher image
		br2.outline_opacity = 0.0f;
		graphics::drawRect(CANVAS_WIDTH / 1.05, CANVAS_HEIGHT / 12, SEARCHER_SIZE, SEARCHER_SIZE, br2);

		graphics::Brush br20;
		br2.texture = std::string(ASSET_PATH) + "helper.png"; //draws helper image
		br2.outline_opacity = 0.0f;
		graphics::drawRect(CANVAS_WIDTH * 1.05 - 1000, CANVAS_HEIGHT / 12, HELP_SIZE, HELP_SIZE, br20);

		if (s_state == S1M or s_state == S2M or s_state == S3M or s_state == S4M or s_state == S5M or s_state == S6M or s_state == SEARCH) //if state is S*M or SEARCH, draw the movie's interface 
		{
			mo[checker]->draw();//checker value keeps track of the table's pointer and draws its data
		}

		if (s_state == ANIMATION) //if state is X draw the movie's interface from that certain table (example: STATE = ANIMATION, table is An)
		{
			An[checker]->draw();
		}

		if (s_state == ADVENTURE)
		{
			Ad[checker]->draw();
		}

		if (s_state == ACTION)
		{
			Ac[checker]->draw();
		}

		if (s_state == HORROR)
		{
			Ho[checker]->draw();
		}

		if (s_state == DRAMA)
		{
			Dr[checker]->draw();
		}

		if (s_state == ROMANCE)
		{
			Ro[checker]->draw();
		}

		if (s_state == SCI_FI)
		{
			Sc[checker]->draw();
		}

		if (s_state == COMEDY)
		{
			Co[checker]->draw();
		}

		if (s_state == MYSTERY)
		{
			My[checker]->draw();
		}

		if (highlighted) //if you have mouse on the searcher button
		{
			graphics::Brush br3;
			br3.texture = std::string(ASSET_PATH) + "orange_square.png";
			br3.outline_opacity = 0.0f;
			graphics::drawRect(CANVAS_WIDTH / 1.4, CANVAS_HEIGHT / 3, CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, br3); //draws searcher window

			graphics::Brush br8;
			br8.outline_opacity = 0.0f;
			SETCOLOR(br8.fill_color, 0.0f, 0.0f, 0.0f);
			graphics::drawDisk(posx, posy, 5.0f, br8);

			graphics::Brush br4;
			br4.outline_opacity = 0.0f;
			SETCOLOR(br4.fill_color, 255, 255, 255);
			graphics::setFont("FreeSans.ttf");
			graphics::drawText(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 6.5, 25.0f, "Genre: ", br2);	//draws windows texts (lines 413 - 416)
			graphics::drawText(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2.7, 25.0f, "Year: ", br2);	
			graphics::drawText(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2.4, 15.0f, "From: ", br2);	
			graphics::drawText(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2.25, 15.0f, "To: ", br2);		
			

			for (auto genre : g) //draws the genre buttons 
			{
				genre->draw();
			}
		}

		if (s_state == SEARCH) //if you press on searcher button
		{
			graphics::Brush br3;
			br3.texture = std::string(ASSET_PATH) + "orange_square.png";
			br3.outline_opacity = 0.0f;
			graphics::drawRect(CANVAS_WIDTH / 1.4, CANVAS_HEIGHT / 3, CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, br3); //draws the rectangle


			graphics::Brush br8;
			if (drag_highlight) //if
			{
				br8.outline_opacity = 1.0f;
			}
			else
			{
				br8.outline_opacity = 0.0f;
			}
			SETCOLOR(br8.fill_color, 0.0f, 0.0f, 0.0f);
			graphics::drawDisk(posx, posy, 5.0f, br8);

			b3 = std::to_string(b2);

			graphics::Brush br4;
			br4.outline_opacity = 0.0f;
			SETCOLOR(br4.fill_color, 255, 255, 255);
			graphics::setFont("FreeSans.ttf");

			graphics::drawText(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2.7, 25.0f, "Year: ", br2);
			graphics::drawText(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 6.5, 25.0f, "Genre: ", br2);
			graphics::drawText(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2.4, 15.0f, "From: ", br2);
			graphics::drawText(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2.25, 15.0f, "To: ", br2);
			graphics::drawText(CANVAS_WIDTH / 1.4, CANVAS_HEIGHT / 2.4, 15.0f, b3, br2);

			for (auto genre : g) //draws the buttons
			{
				genre->draw();
			}
		}
	}
	
}

void System::init()
{

}

System::System() //System Constructor
{
	//Movie Objects
	M* Avatar = new M("Avatar", "James Cameron", "Sam Worthington, Zoe Saldana, Sigourney Weaver", "2009", "Action", "Adventure", "Fantasy", "Avatar.png");
	M* The_Avengers = new M("The Avengers", "Joss Whedon", "Robert Downey Jr., Chris Evans, Scarlett Johansson", "2012", "Action", "Adventure", "Sci-Fi", "The Avengers.png");
	M* Smile = new M("Smile", "Parker Finn", "Socie Bacon, Jessie T. Usher, Kyle Gallner", "2022", "Horror", "Mystery", "Thriller", "Smile.png");
	M* Minions2 = new M("Minions 2", "Kyle Balda", "Steve Carell, Pierre Coffin, Alan Arkin", "2022", "Animation", "Adventure", "Comedy", "Minions 2.png");
	M* TheFaultInOurStars = new M("The Fault In Our Stars", "Josh Boone", "Shailene Woodley, Ansel Elgort, Nat Wolff", "2014", "Drana", "Romance", "-", "The fault in our stars.png");
	M* DemonSlayer = new M("Kimetsu no Yaiba: Mugen Ressha-Hen", "Haruo Sotozaki", "Natsuki Hanae, Akari Kito, Yoshitsugu Matsuoka", "2020", "Animation", "Action", "Adventure", "DemonSlayer.png");

	//Genre Button objects (for search)
	Genre_Button* Animation = new Genre_Button(CANVAS_WIDTH / 1.92, CANVAS_HEIGHT / 5.5, "Animation", CANVAS_WIDTH / 1.99, CANVAS_HEIGHT, 9.0f);
	Genre_Button* Adventure = new Genre_Button(CANVAS_WIDTH / 1.745, CANVAS_HEIGHT / 5.5, "Adventure", CANVAS_WIDTH / 1.804, CANVAS_HEIGHT, 8.5f);
	Genre_Button* Action = new Genre_Button(CANVAS_WIDTH / 1.6, CANVAS_HEIGHT / 5.5, "Action", CANVAS_WIDTH / 1.64, CANVAS_HEIGHT, 10.0f);
	Genre_Button* Exit = new Genre_Button(CANVAS_WIDTH / 1.95, CANVAS_HEIGHT / 1.9, "Exit", CANVAS_WIDTH / 1.99, CANVAS_HEIGHT / 0.345, 11.0f);
	Genre_Button* Horror = new Genre_Button(CANVAS_WIDTH / 1.48, CANVAS_HEIGHT / 5.5, "Horror", CANVAS_WIDTH / 1.51, CANVAS_HEIGHT, 10.0f);
	Genre_Button* Drama = new Genre_Button(CANVAS_WIDTH / 1.38, CANVAS_HEIGHT / 5.5, "Drama", CANVAS_WIDTH / 1.41, CANVAS_HEIGHT, 10.0f);
	Genre_Button* Romance = new Genre_Button(CANVAS_WIDTH / 1.92, CANVAS_HEIGHT / 4, "Romance", CANVAS_WIDTH / 1.99, CANVAS_HEIGHT / 0.735, 9.0f);
	Genre_Button* Sci_Fi = new Genre_Button(CANVAS_WIDTH / 1.745, CANVAS_HEIGHT / 4, "Sci-Fi", CANVAS_WIDTH / 1.788, CANVAS_HEIGHT / 0.735, 9.0f);
	Genre_Button* Comedy = new Genre_Button(CANVAS_WIDTH / 1.6, CANVAS_HEIGHT / 4, "Comedy", CANVAS_WIDTH / 1.64, CANVAS_HEIGHT / 0.735, 9.0f);
	Genre_Button* Mystery = new Genre_Button(CANVAS_WIDTH / 1.48, CANVAS_HEIGHT / 4, "Mystery", CANVAS_WIDTH / 1.52, CANVAS_HEIGHT / 0.735, 9.0f);

	//Each M* object is inserted in the mo table
	mo[1] = The_Avengers;
	mo[0] = Avatar;
	mo[2] = Smile;
	mo[3] = Minions2;
	mo[4] = TheFaultInOurStars;
	mo[5] = DemonSlayer;

	//Each Genre_Button* Object is inserted in the g[] table
	g[0] = Animation;
	g[1] = Adventure;
	g[2] = Exit;
	g[3] = Action;
	g[4] = Horror;
	g[5] = Drama;
	g[6] = Romance;
	g[7] = Sci_Fi;
	g[8] = Comedy;
	g[9] = Mystery;


	//Each M* object is inserted in the corresponding table based on genre
	An[0] = Minions2;
	An[1] = DemonSlayer;

	Ad[0] = Avatar;
	Ad[1] = The_Avengers;
	Ad[2] = Minions2;
	Ad[3] = DemonSlayer;

	Ac[0] = Avatar;
	Ac[1] = The_Avengers;
	Ac[2] = DemonSlayer;

	Ho[0] = Smile;

	Dr[0] = TheFaultInOurStars;

	Ro[0] = TheFaultInOurStars;

	Sc[0] = The_Avengers;

	Co[0] = Minions2;

	My[0] = Smile;
}

System::~System() //Destructor for m and genre_button
{
	for (auto m : mo)
	{
		delete m;
	}

	for (auto genre : g)
	{
		delete genre;
	}
}
