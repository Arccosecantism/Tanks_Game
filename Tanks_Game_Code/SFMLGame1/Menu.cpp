#include "Menu.h"



Menu::Menu()
{
	isActive = true;
	position = sf::Vector2f(0, 0);
}



void Menu::addMenuElement(MenuElement& fmenuElement, std::string fname)
{

	elementVector.push_back(&fmenuElement);
	addElementName(fname);
}



void Menu::setRelativePosition(sf::Vector2f fpos)
{
	sf::Vector2f oldPos = position;
	position = fpos;

	sf::Vector2f distance(oldPos - position);
	
	for (unsigned int i = 0; i < elementVector.size(); i++)
	{
		elementVector[i]->move(distance);
	}
}



void Menu::addRelativePosition(sf::Vector2f velocity)
{
	position += velocity;

	for (unsigned int i = 0; i < elementVector.size(); i++)
	{
		elementVector[i]->move(velocity);
	}
}


bool Menu::getIsActive()
{
	return isActive;
}



void Menu::deactivate()
{
	isActive = false;
}



void Menu::activate()
{
	isActive = true;
}



void Menu::switchActive()
{
	isActive = !isActive;
}




void Menu::setIsActive(bool factive)
{
	isActive = factive;
}




MenuElement* Menu::getPointerToElementByIndex(int findex)
{
	return elementVector[findex];
}



MenuElement* Menu::getPointerToElementByName(std::string fname)
{
	return elementVector[elementNames[fname]];
}





template<class C> C* Menu::getPointerToChildByName(std::string fname)
{
	C* returnChild = (C*) elementVector[elementNames[fname]];
}





void Menu::update(MouseData& fmousedata)
{
	for (unsigned int i = 0; i < elementVector.size(); i++)
	{
		if (elementVector[i]->getRequiresMouseData())
		{
			elementVector[i]->update(fmousedata);
		}
		else
		{
			elementVector[i]->update();
		}
	}
}






void Menu::draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition)
{
	position += drawPosition;
	for (unsigned int i = 0; i < elementVector.size(); i++)
	{
		if (!elementVector[i]->getIsHidden())
		{
			elementVector[i]->draw(frenderwindow, position);
		}
	}
	position -= drawPosition;
}



void Menu::addElementName(std::string fname)
{
	bool sameName = true;
	bool firstDuplicate = true;

	while (sameName == true)
	{

		if (elementNames.count(fname) == 1)
		{
			if (firstDuplicate == true)
			{
				fname += "2";										/*if there exists a "ExitButton" already, and you try to add another one,
																	it will become "ExitButton2"*/
			}
			else
			{
				fname[fname.size() - 1]++;							/*if there exists a "ExitButton2" already, and you try to add another one,
																	it will become "ExitButton3"*/
			}
		}

		else
		{
			sameName = false;										//if there is no same name, exit the while loop
		}

	}

	elementNames[fname] = elementVector.size() - 1;					//then add the altered (or not) name
}