#include "App.h"





//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PUBLIC-----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************







/*------------------------------------------------------------------------------------
-------------------------------Constructor--------------------------------------------
------------------------------------------------------------------------------------*/
App::App(sf::RenderWindow& fwindow)								/*basic counstructor for App. App must be given a reference to a 
																RenderWindow which it will send all over the place*/
{

	window = &fwindow;											//setting a pointer to a renderwindow

	mouseInfo.setButtonData(sf::Vector2i(UNHELD, UNHELD));		//starting the mouse as unheld

	
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-----------------------------------Setup----------------------------------------------
------------------------------------------------------------------------------------*/
void App::setup()												//initialize all objects
{

	setupResourceManager();										//set up the resource manager, adding all files

	startingMenu.setup(generalResourceManager);					//set up the main menu

	//startingMenu.deactivate();
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-------------------------------Checkevents--------------------------------------------
------------------------------------------------------------------------------------*/
void App::checkEvents(sf::Event& fevent)						//checks events like mouse clicking	
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







//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PRIVATE----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************








/*------------------------------------------------------------------------------------
------------------------------------Update--------------------------------------------
------------------------------------------------------------------------------------*/
void App::update()											//update all objects and menus
{

	startingMenu.update(mouseInfo);

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
--------------------------------------Draw--------------------------------------------
------------------------------------------------------------------------------------*/
void App::draw()											//draw all objects
{

	startingMenu.draw(*window);

}



//----------------------------------------------------------------------------------------------------------------------------***************************


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



//----------------------------------------------------------------------------------------------------------------------------***************************


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
			keys.push_back(i);												//add the pressed key index to the keys vector
		}
	}

}



//----------------------------------------------------------------------------------------------------------------------------***************************


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



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-------------------------------setupResourceManager-----------------------------------
------------------------------------------------------------------------------------*/
void App::setupResourceManager()																//adds all the files to the resource manager
{

	generalResourceManager.addFile("Resources\\GreenButtonUnpressed.png", "GreenButtonUnpressed");
	generalResourceManager.addFile("Resources\\GreenButtonHovered.png", "GreenButtonHovered");
	generalResourceManager.addFile("Resources\\GreenButtonHeld.png", "GreenButtonHeld");
	generalResourceManager.addFile("Resources\\GreenButtonPressed.png", "GreenButtonPressed");
	generalResourceManager.addFile("Resources\\GreenButtonHoveredPressed.png", "GreenButtonHoveredPressed");
	generalResourceManager.addFile("Resources\\GreenButtonHeldPressed.png", "GreenButtonHeldPressed");


	generalResourceManager.addFile("Resources\\WalrusBG.png", "WalrusBackground");

	generalResourceManager.addFile("Resources\\GiraffeBG.png", "GiraffeBackground");




	generalResourceManager.addFile("Resources\\AlexandriaFLF.ttf", "DefaultFont");				//adding font

	

	//-------NEW GROUP----------
	ResourceGroup tempGroup;																	//creating a resource group WRONG PLACE

	tempGroup.addFont(generalResourceManager.getFontPointerByName("DefaultFont"));				


	tempGroup.addTexture(generalResourceManager.getTexturePointerByName("GreenButtonUnpressed"));
	tempGroup.addTexture(generalResourceManager.getTexturePointerByName("GreenButtonHovered"));
	tempGroup.addTexture(generalResourceManager.getTexturePointerByName("GreenButtonHeld"));
	tempGroup.addTexture(generalResourceManager.getTexturePointerByName("GreenButtonPressed"));
	tempGroup.addTexture(generalResourceManager.getTexturePointerByName("GreenButtonHoveredPressed"));
	tempGroup.addTexture(generalResourceManager.getTexturePointerByName("GreenButtonHeldPressed"));

	generalResourceManager.addResourceSet(tempGroup, "GreenButtonRG");

}


//----------------------------------------------------------------------------------------------------------------------------***************************

