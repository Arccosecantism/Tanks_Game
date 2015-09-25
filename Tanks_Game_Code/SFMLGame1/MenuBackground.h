#pragma once
#include "MenuElement.h"

class MenuBackground : MenuElement											//Child of MenuEntity. it's a very basic class; simply a texture for the background of a menu										
{
public:

	MenuBackground(	sf::Vector2f fposition, ResourceGroup& fresourceGroup,	
					sf::Vector2f fspriteSize);								//a position, size, and resource group define a menuBackground
	
	//inherited virtual; not super useful---------------------------------------------------------

	void update();															//empty

	void update(MouseData& fmouseData);										//empty

	void draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition);	//draws the background

	//--------------------------------------------------------------------------------------------

private:

	sf::Sprite backgroundSprite;											//the sprite that is the background of the menu

};

