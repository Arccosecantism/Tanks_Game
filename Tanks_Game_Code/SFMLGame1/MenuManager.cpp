#include "MenuManager.h"



//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PUBLIC-----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************



/*------------------------------------------------------------------------------------
-------------------Constructor--------------------------------------------------------
------------------------------------------------------------------------------------*/
MenuManager::MenuManager()															//empty constructor
{

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-------------------addMenu------------------------------------------------------------
------------------------------------------------------------------------------------*/
void MenuManager::addMenu(Menu fmenu, std::string fname)							//adds a menu
{

	menuVector.push_back(fmenu);													//add the menu

	addMenuName(fname);																//add the name of the menu

	drawPositions.push_back(sf::Vector2f(0, 0));									//automatically makes a new drawPosition

}



/*------------------------------------------------------------------------------------
-------------------getMenuPointerByName-----------------------------------------------
------------------------------------------------------------------------------------*/
Menu* MenuManager::getMenuPointerByName(std::string fname)							//returns a pointer to a menu
{

	Menu* tmpMenuPointer = &menuVector[menuNames[fname]];							//makes a temporary pointer that points to a menu

	return tmpMenuPointer;															//return it

}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
-------------------setMenuDrawPositionbyName-----------------------------------------
------------------------------------------------------------------------------------*/
void MenuManager::setMenuDrawPositionByName(std::string fname, sf::Vector2f fpos)	//sets a drawPoisiton of one of the menus by name
{

	drawPositions[menuNames[fname]] = fpos;											//set the drawPosition by name

}



/*------------------------------------------------------------------------------------
-------------------addMenuDrawpositionByName------------------------------------------
------------------------------------------------------------------------------------*/
void MenuManager::addMenuDrawPositionByName(std::string fname, sf::Vector2f fvel)	//add position to a drawPoisiton of a menu by name
{
	drawPositions[menuNames[fname]] += fvel;										//increment the drawPosition by the desired velocity
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
--------------------------update------------------------------------------------------
------------------------------------------------------------------------------------*/
void MenuManager::update(MouseData& fmousedata)										//updates the menus
{
	for (unsigned int i = 0; i < menuVector.size(); i++)							//cycle through all the menus
	{
		menuVector[i].update(fmousedata);											//update them
	}
}



//----------------------------------------------------------------------------------------------------------------------------***************************


/*------------------------------------------------------------------------------------
---------------------------draw-------------------------------------------------------
------------------------------------------------------------------------------------*/
void MenuManager::draw(sf::RenderWindow& frenderwindow)								//draws all the menus
{
	for (unsigned int i = 0; i < menuVector.size(); i++)							//cycle through all of the menus
	{
		menuVector[i].draw(frenderwindow, drawPositions[i]);						//draw them all at their respective drawPositions
	}
}






//----------------------------------------------------------------------------------------------------------------------------***************************
//-----------------------------------------PRIVATE----------------------------------------------------------------------------***************************
//----------------------------------------------------------------------------------------------------------------------------***************************



/*------------------------------------------------------------------------------------
--------------------------addMenuName-------------------------------------------------
------------------------------------------------------------------------------------*/
void MenuManager::addMenuName(std::string fname)									//adds a name to the name map
{
	bool sameName = true;
	bool firstDuplicate = true;

	while (sameName == true)
	{

		if (menuNames.count(fname) == 1)
		{
			if (firstDuplicate == true)
			{
				fname += "2";										/*if there exists a "OptionsMenu" already, and you try to add another one,
																	it will become "OptionsMenu2"*/
				firstDuplicate = false;
			}
			else
			{
				fname[fname.size() - 1]++;							/*if there exists a "OptionsMenu2" already, and you try to add another one,
																	it will become "OptionsMenu3"*/
			}
		}

		else
		{
			sameName = false;										//if there is no same name, exit the while loop
		}

	}

	menuNames[fname] = menuVector.size() - 1;					//then add the altered (or not) name
}

//----------------------------------------------------------------------------------------------------------------------------***************************