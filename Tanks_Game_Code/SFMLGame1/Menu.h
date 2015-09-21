#pragma once

#include "MenuToolsInclude.h"

class Menu
{

public:

	Menu();

	void addMenuElement(MenuElement& fmenuElement, std::string fname);

	void setPosition(sf::Vector2f fpos);

	bool getIsActive();

	void deactivate();
	void activate();

	void setIsActive(bool factive);

private:

	std::vector<MenuElement> elementVector;
	std::vector<std::string> elementNames;
	

	sf::Vector2f position;
	
	bool isActive;


	
};

