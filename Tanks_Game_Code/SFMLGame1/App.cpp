#include "App.h"

App::App(sf::RenderWindow& fwindow)	//basic counstructor for App. App must be given a reference to a RenderWindow which it will send all over the place
{
	window = &fwindow;				//setting a pointer to a renderwindow
}

void App::setup()					//initialize all objects
{


}

void App::update()					//update all objects and menus
{


}

void App::draw()					//draw all objects
{


}

void App::getMouseData()			//retrieve mouse data
{


}

void App::getKeyboardData()			//retrieve keyboard data
{


}

void App::doPerFrame()				//do the above four functions every update cycle
{
	getKeyboardData();
	getMouseData();
	update();
	draw();
}