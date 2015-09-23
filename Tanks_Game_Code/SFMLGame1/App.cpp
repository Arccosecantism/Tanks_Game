#include "App.h"



/*------------------------------------------------------------------------------------
-------------------------------Constructor--------------------------------------------
------------------------------------------------------------------------------------*/
App::App(sf::RenderWindow& fwindow)								/*basic counstructor for App. App must be given a reference to a 
																RenderWindow which it will send all over the place*/
{
	window = &fwindow;											//setting a pointer to a renderwindow
	mouseInfo.setButtonData(sf::Vector2i(UNHELD, UNHELD));					//starting the mouse as unheld
}




/*------------------------------------------------------------------------------------
-----------------------------------Setup----------------------------------------------
------------------------------------------------------------------------------------*/
void App::setup()												//initialize all objects
{
	generalResourceManager.addFile("Resources\\GreenButton.png", "GreenButton");
	generalResourceManager.addFile("Resources\\AlexandriaFLF.ttf", "DefaultFont");
	ResourceGroup tempGroup;
	tempGroup.addFont(generalResourceManager.getFontPointerByName("DefaultFont"));
	for (int i = 0; i < 6; i++)
	{
		tempGroup.addTexture(generalResourceManager.getTexturePointerByName("GreenButton"));
	}

	generalResourceManager.addResourceSet(tempGroup, "GreenButtonRG");

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
			mouseInfo.setMousePosition(sf::Vector2i(fevent.mouseMove.x, fevent.mouseMove.y));	//set mouse position to the new position	
			break;
		}



		case sf::Event::MouseButtonPressed:						//mouse is pressed down
		{
			if (fevent.mouseButton.button == sf::Mouse::Left)	//if left button
			{
				mouseInfo.setLeftButtonData(PRESSED);			//set the left mouse data to pressed
			}
			if (fevent.mouseButton.button == sf::Mouse::Right)	//if right button
			{
				mouseInfo.setRightButtonData(PRESSED);			//set right mouse data to pressed
			}
			break;
		}



		case sf::Event::MouseButtonReleased:					//mouse is released
		{
			if (fevent.mouseButton.button == sf::Mouse::Left)	//if left mouse is released
			{
				mouseInfo.setLeftButtonData(RELEASED);			//left mouse data turns to released
			}
			if (fevent.mouseButton.button == sf::Mouse::Right)	//if left button is released
			{
				mouseInfo.setRightButtonData(RELEASED);			//right mouse data turns to released	
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
	BasicButton tempButton(sf::Vector2f(0,0), generalResourceManager.getResourceSetByName("GreenButtonRG"),
							"Test", sf::Color::White, sf::Vector2f(600,300), sf::Vector2f (300, 150));
	tempButton.setRelativeTextPosition(sf::Vector2f(0, 0));
	tempButton.draw(*window, sf::Vector2f(400, 300));

}




/*------------------------------------------------------------------------------------
-------------------------------resetMouseData-------------------------------------------
------------------------------------------------------------------------------------*/
void App::resetMouseData()									//resets mouse data
{


	/*-------------------------------------------------------------------------------------------
	This section resets the mouse data at the end of each cycle; if the left button was just pressed, it becomes held, etc.
	-------------------------------------------------------------------------------------------*/



	//--------------------------------------------------------------
	//for left mouse button:
	if (mouseInfo.getLeftButtonData() == PRESSED)			//if left mouse button was just pressed this cycle...
	{
		mouseInfo.setLeftButtonData(HELD);					//the user is now holding the mouse down.
	}



	else if (mouseInfo.getLeftButtonData() == RELEASED)		//if left mouse button was just released this cycle...
	{
		mouseInfo.setLeftButtonData(UNHELD);				//the user has let go of the left mouse button.
	}


	//------------------------------------------------------------
	//for right mouse button:
	if (mouseInfo.getRightButtonData() == PRESSED)
	{
		mouseInfo.setRightButtonData(HELD);	
	}



	else if (mouseInfo.getRightButtonData() == RELEASED)
	{
		mouseInfo.setRightButtonData(UNHELD);
	}


}





/*------------------------------------------------------------------------------------
-------------------------------getKeyboardData-------------------------------------------
------------------------------------------------------------------------------------*/
void App::getKeyboardData()													//retrieve keyboard data
{
	keys.clear();															//empty the key vector
	for (int i = 0; i < sf::Keyboard::KeyCount; i++)						//KeyCount is the number of Keys; this is intended to check every key
	{
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i)))	//trying to typecast int i as a Key enum 
		{
			keys.push_back(i);
		}
	}
}



/*------------------------------------------------------------------------------------
-------------------------------doPerFrame-------------------------------------------
------------------------------------------------------------------------------------*/
void App::doPerFrame()							//do the above four functions every update cycle
{
	getKeyboardData();
	update();
	draw();
	resetMouseData();
}


/*------------------------------------------------------------------------------------
-------------------------------setupResourceManager-----------------------------------
------------------------------------------------------------------------------------*/
void App::setupResourceManager()				//adds all the files to the resource manager
{
	//generalResourceManager.addFile("defaultFont.ttf", "defaultFont");

}


