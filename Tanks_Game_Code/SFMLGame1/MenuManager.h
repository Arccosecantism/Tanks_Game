#pragma once
#include "Menu.h"


class MenuManager
{
public:

	MenuManager();


	void addMenu(Menu fmenu, std::string fname);

	Menu* getMenuPointerByName(std::string fname);



	void setMenuDrawPositionByName(std::string fname, sf::Vector2f fpos);

	void addMenuDrawPositionByName(std::string fname, sf::Vector2f fvel);



	void update(MouseData& fmousedata);

	void draw(sf::RenderWindow& frenderwindow);


private:

	void addMenuName(std::string fname);


	std::vector<Menu> menuVector;

	std::vector<sf::Vector2f> drawPositions;

	std::map<std::string, int> menuNames;

};

