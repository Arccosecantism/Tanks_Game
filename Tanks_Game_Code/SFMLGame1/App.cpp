#include "App.h"

App::App(sf::RenderWindow& fwindow)
{
	window = &fwindow;
}

void App::setup()
{
	tryme.setFillColor(sf::Color::Green);
	tryme.setRadius(50);
	tryme.setPosition(100, 100);

}

void App::update()
{


}

void App::draw()
{

	window->draw(tryme);

}

void App::getMouseData()
{


}

void App::getKeyboardData()
{


}

void App::doPerFrame()
{
	getKeyboardData();
	getMouseData();
	update();
	draw();
}