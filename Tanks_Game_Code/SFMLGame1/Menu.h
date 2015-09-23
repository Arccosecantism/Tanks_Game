#pragma once

#include "MenuToolsInclude.h"


class Menu
{

public:

	Menu();

	void addMenuElement(MenuElement& fmenuElement, std::string fname);

	void setRelativePosition(sf::Vector2f fpos);

	void addRelativePosition(sf::Vector2f velocity);



	bool getIsActive();



	void deactivate();

	void activate();

	void switchActive();

	void setIsActive(bool factive);


	MenuElement* getPointerToElementByIndex(int findex);

	MenuElement* getPointerToElementByName(std::string fname);


	template<class C> C* getPointerToChildByName(std::string fname);


	void update(MouseData& fmousedata);

	void draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition);



private:

	void addElementName(std::string fname);


	std::vector<MenuElement*> elementVector;

	std::map<std::string, int> elementNames;
	

	sf::Vector2f position;
	
	bool isActive;


	
};

