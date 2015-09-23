#include "MenuBackground.h"

MenuBackground::MenuBackground(sf::Vector2f fposition, ResourceGroup& fresourceGroup, sf::Vector2f fspriteSize)
{
	position = fposition;

	requiresMouseData = 0;

	isHidden = false;




	spriteSize = fspriteSize;

	halfDimensions = sf::Vector2f(fspriteSize.x / 2, fspriteSize.y / 2);




	sf::Vector2f tempDimensions;

	backgroundSprite.setTexture(*fresourceGroup.getTexturePointer(0));

	tempDimensions = sf::Vector2f(backgroundSprite.getLocalBounds().width, backgroundSprite.getLocalBounds().height);
	
	backgroundSprite.setOrigin(tempDimensions.x / 2, tempDimensions.y / 2);

	backgroundSprite.setScale(spriteSize.x / tempDimensions.x, spriteSize.y / tempDimensions.y);

	backgroundSprite.setPosition(0, 0);
}



void MenuBackground::update()
{

}



void MenuBackground::update(MouseData& fmouseData)
{

}



void MenuBackground::draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition)
{
	position += drawPosition;



	backgroundSprite.move(position);

	frenderWindow.draw(backgroundSprite);

	backgroundSprite.move(-position);



	position -= drawPosition;

}


