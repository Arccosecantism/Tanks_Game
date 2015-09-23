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