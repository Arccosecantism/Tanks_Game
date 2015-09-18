#pragma once
#include "SFMLbase.h"


class MouseData
{
public:

	MouseData();

	void setMousePosition(sf::Vector2i fposition);
	void setButtonData(sf::Vector2i fdata);
	void setLeftButtonData(int fdata);
	void setRightButtonData(int fdata);
	

	sf::Vector2i getMousePosition();
	sf::Vector2i getButtonData();
	int getLeftButtonData();
	int getRightButtonData();
	

private:

	sf::Vector2i mousePosition;
	sf::Vector2i buttonData;
	
};

