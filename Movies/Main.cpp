#include "graphics.h"
#include "system.h"
#include "config.h"




void update(float ms)
{
	System* system = reinterpret_cast<System *>(graphics::getUserData());
	system->update();
}


void draw()
{
	System* system = reinterpret_cast<System*>(graphics::getUserData());
	system->draw();
}


int main()
{


	System mysystem;
	graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "MovieLand");

	graphics::setUserData(&mysystem);
	
	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);
	
	graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	mysystem.init();
	graphics::startMessageLoop();


	return 0;

}