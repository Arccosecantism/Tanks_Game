#include "MenuManager.h"


MenuManager::MenuManager()
{

}

void MenuManager::addMenu(Menu fmenu, std::string fname)
{
	menuVector.push_back(fmenu);
	addMenuName(fname);
	drawPositions.push_back(sf::Vector2f(0, 0));
}

Menu* MenuManager::getMenuPointerByName(std::string fname)
{
	Menu* tmpMenuPointer = &menuVector[menuNames[fname]];
	return tmpMenuPointer;
}



void MenuManager::setMenuDrawPositionByName(std::string fname, sf::Vector2f fpos)
{
	drawPositions[menuNames[fname]] = fpos;
}

void MenuManager::addMenuDrawPositionByName(std::string fname, sf::Vector2f fvel)
{
	drawPositions[menuNames[fname]] += fvel;
}



void MenuManager::update(MouseData& fmousedata)
{
	for (unsigned int i = 0; i < menuVector.size(); i++)
	{
		menuVector[i].update(fmousedata);
	}
}

void MenuManager::draw(sf::RenderWindow& frenderwindow)
{
	for (unsigned int i = 0; i < menuVector.size(); i++)
	{
		menuVector[i].draw(frenderwindow, drawPositions[i]);
	}
}

void MenuManager::addMenuName(std::string fname)
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