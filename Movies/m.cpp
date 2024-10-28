#include "m.h"
#include "graphics.h"
#include <string>

void M::update()
{
}

void M::draw() // draws the movie description
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + Pic;
	br.gradient = true;
	br.outline_opacity = 0.0f;
	graphics::drawRect(pos_x, pos_y, CANVAS_WIDTH / 9, CANVAS_HEIGHT / 5, br);


	graphics::Brush br2;
	br2.outline_opacity = 0.0f;
	SETCOLOR(br2.fill_color, 0.0f, 0.0f, 0.0f);
	graphics::setFont("FreeSans.ttf");
	graphics::drawText(CANVAS_WIDTH / 12, CANVAS_HEIGHT / 1.7, 14.0f, "|" + Type1 + "|" + "  " + "|" + Type2 + "|" + "  " + "|" + Type3 + "|", br2);
	graphics::drawText(CANVAS_WIDTH / 12, CANVAS_HEIGHT / 1.5, 25.0f, Title, br2);
    graphics::drawText(CANVAS_WIDTH / 12, CANVAS_HEIGHT / 1.4, 15.0f, "Director: " + Director, br2);
	graphics::drawText(CANVAS_WIDTH / 12, CANVAS_HEIGHT / 1.32, 15.0f, "Cast: " + Cast, br2);
	graphics::drawText(CANVAS_WIDTH / 12, CANVAS_HEIGHT / 1.25, 15.0f, "Year: " + Year , br2);

}

void M::init()
{
}

//M constructor 
M::M(std::string title, std::string director, std::string cast, std::string year, std::string type1, std::string type2, std::string type3, std::string pic)
{
	Title = title;
	Director = director;
	Cast = cast;
	Year = year;
	Type1 = type1;
	Type2 = type2;
	Type3 = type3;
	Pic = pic;
}
