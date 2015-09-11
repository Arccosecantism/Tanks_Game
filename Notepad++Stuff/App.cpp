#include "App.h"

App::App(sf::RenderWindow& fwindow)	//basic counstructor for App. App must be given a reference to a RenderWindow which it will send all over the place
{
	window = &fwindow;				//setting a pointer to a renderwindow
}

void App::setup()					//initialize all objects
{


}

void App::setMousePosition(sf::Vector2i fmousePosition) //sets mouse position from int main
{
	mousePosition = fmousePosition;
	
}

void checkEvents(Event& fevent)
{
	
	switch (fevent.type)
	{
		case sf::Event::Closed:
		{
			window->close();
			break;
		}
		case sf::Event::MouseMoved:
		{
			mousePosition = sf::Vector2i(event.mouseMove.x, event.mouseMove.y);
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if(fevent.mouseButton.button == sf::Mouse::Left)
			{
				mouseData.x = CLICKED;
			}
			if(fevent.mouseButton.button == sf::Mouse::Right)
			{
				mouseData.y = CLICKED;
			}
			break;
		}
		case sf::Event::MouseButtonReleased:
		{
			if(fevent.mouseButton.button == sf::Mouse::Left)
			{
				mouseData.x = RELEASED;
			}
			if(fevent.mouseButton.button == sf::Mouse::Right)
			{
				mouseData.y = RELEASED;
			}
			break;	
		}
	}
	
}


void App::update()					//update all objects and menus
{


}

void App::draw()					//draw all objects
{


}

void App::getMouseData()			//retrieve mouse data
{



		if(mouseData.x == PRESSED)
		{
			mouseData.x = HELD;
		}
		else if(mouseData.x == RELEASED)
		{
			mouseData.x = UNHELD;
		}
		if(mouseData.y == PRESSED)
		{
			mouseData.y = HELD;
		}
		else if(mouseData.y == RELEASED)
		{
			mouseData.y = UNHELD;
		}
		
		
	}
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