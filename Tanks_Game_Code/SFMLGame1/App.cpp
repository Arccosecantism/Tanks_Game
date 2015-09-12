#include "App.h"



/*------------------------------------------------------------------------------------
-------------------------------Constructor--------------------------------------------
------------------------------------------------------------------------------------*/
App::App(sf::RenderWindow& fwindow)								/*basic counstructor for App. App must be given a reference to a 
																RenderWindow which it will send all over the place*/
{
	window = &fwindow;											//setting a pointer to a renderwindow
	mouseData = sf::Vector2i(UNHELD, UNHELD);					//starting the mouse as unheld
}




/*------------------------------------------------------------------------------------
-----------------------------------Setup----------------------------------------------
------------------------------------------------------------------------------------*/
void App::setup()												//initialize all objects
{


}





/*------------------------------------------------------------------------------------
-------------------------------Checkevents--------------------------------------------
------------------------------------------------------------------------------------*/
void App::checkEvents(sf::Event& fevent)				
{



	switch (fevent.type)										//switch statement for types of event		
	{



		case sf::Event::Closed:									//window is closed
		{
			window->close();
			break;
		}



		case sf::Event::MouseMoved:								//mouse is moved
		{
			mousePosition = sf::Vector2i(fevent.mouseMove.x, fevent.mouseMove.y);	//set mouse position to the new position	
			break;
		}



		case sf::Event::MouseButtonPressed:						//mouse is pressed down
		{
			if (fevent.mouseButton.button == sf::Mouse::Left)	//if left button
			{
				mouseData.x = PRESSED;							//set the left mouse data to pressed
			}
			if (fevent.mouseButton.button == sf::Mouse::Right)	//if right button
			{
				mouseData.y = PRESSED;							//set right mouse data to pressed
			}
			break;
		}



		case sf::Event::MouseButtonReleased:					//mouse is released
		{
			if (fevent.mouseButton.button == sf::Mouse::Left)	//if left mouse is released
			{
				mouseData.x = RELEASED;							//left mouse data turns to released
			}
			if (fevent.mouseButton.button == sf::Mouse::Right)	//if left button is released
			{
				mouseData.y = RELEASED;							//right mouse data turns to released	
			}
			break;
		}
	}
}




/*------------------------------------------------------------------------------------
------------------------------------Update--------------------------------------------
------------------------------------------------------------------------------------*/
void App::update()							//update all objects and menus
{


}




/*------------------------------------------------------------------------------------
--------------------------------------Draw--------------------------------------------
------------------------------------------------------------------------------------*/
void App::draw()							//draw all objects
{


}




/*------------------------------------------------------------------------------------
-------------------------------resetMouseData-------------------------------------------
------------------------------------------------------------------------------------*/
void App::resetMouseData()			//resets mouse data
{


	/*-------------------------------------------------------------------------------------------
	This section resets the mouse data at the end of each cycle; if the left button was just pressed, it becomes held, etc.
	-------------------------------------------------------------------------------------------*/



	//--------------------------------------------------------------
	//for left mouse button:
	if (mouseData.x == PRESSED)				//if left mouse button was just pressed this cycle...
	{
		mouseData.x = HELD;					//the user is now holding the mouse down.
	}



	else if (mouseData.x == RELEASED)		//if left mouse button was just released this cycle...
	{
		mouseData.x = UNHELD;				//the user has let go of the left mouse button.
	}


	//------------------------------------------------------------
	//for right mouse button:
	if (mouseData.y == PRESSED)
	{
		mouseData.y = HELD;
	}



	else if (mouseData.y == RELEASED)
	{
		mouseData.y = UNHELD;
	}


}





/*------------------------------------------------------------------------------------
-------------------------------getKeyboardData-------------------------------------------
------------------------------------------------------------------------------------*/
void App::getKeyboardData()			//retrieve keyboard data
{


}



/*------------------------------------------------------------------------------------
-------------------------------doPerFrame-------------------------------------------
------------------------------------------------------------------------------------*/
void App::doPerFrame()				//do the above five functions every update cycle
{
	getKeyboardData();
	update();
	draw();
	resetMouseData();
}


