#pragma once
#include "MenuSprite.h"
#include "MenuElement.h"

class MultiMenuSprite : public MenuElement, public NameSearchable
{
public:
	MultiMenuSprite();
	~MultiMenuSprite();

	void setup();



	void update();

	void update(MouseData& fmouseData);

	void draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition);

	void resetMD();


	void setCurrentMenuSpriteByName(std::string fname);

	void setCurrentMenuSpriteByIndex(int findex);


	void addMenuSprite(MenuSprite fmenuSprite, std::string fname);

	void addMenuSprite(MenuSprite fmenuSprite, int fintname);


	MenuSprite* getMenuSpritePointerByName(std::string fname);

	MenuSprite* getMenuSpritePointerByIndex(int findex);

private:

	std::vector<MenuSprite> spriteVector;
};

