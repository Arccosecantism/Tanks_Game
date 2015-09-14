#include "MouseData.h"


MouseData::MouseData()
{
}


void MouseData::setMousePosition(sf::Vector2i fposition)
{
	mousePosition = fposition;

}


void MouseData::setLeftButtonData(int fdata)
{
	buttonData.x = fdata;
}

void MouseData::setRightButtonData(int fdata)
{
	buttonData.y = fdata;
}

void MouseData::setButtonData(sf::Vector2i fdata)
{
	buttonData = fdata;
}


sf::Vector2i MouseData::getMousePosition()
{
	return mousePosition;
}


sf::Vector2i MouseData::getButtonData()
{
	return buttonData;
}

int MouseData::getLeftButtonData()
{
	return buttonData.x;
}

int MouseData::getRightButtonData()
{
	return buttonData.y;
}