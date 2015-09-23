#pragma once
#include "MenuElement.h"
class MenuBackground : MenuElement
{
public:

	MenuBackground(sf::Vector2f fposition, ResourceGroup& fresourceGroup, sf::Vector2f fspriteSize);
	
	void update();

	void update(MouseData& fmouseData);

	void draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition);


private:

	sf::Sprite backgroundSprite;

	sf::Vector2f spriteSize;

	sf::Vector2f halfDimensions;
	


};

