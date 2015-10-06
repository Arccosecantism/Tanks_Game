#include "MenuSprite.h"

MenuSprite::MenuSprite()
{
	requiresMouseData = false;

	isHidden = false;

	resetsOnMD = false;
}

MenuSprite::MenuSprite(sf::Texture* ftexture, sf::Vector2f fposition, sf::Vector2f fsize)
{
	requiresMouseData = false;

	isHidden = false;

	resetsOnMD = false;

	setup(ftexture, position, fsize);
}


MenuSprite::~MenuSprite()
{

}


void MenuSprite::setup(sf::Texture* ftexture, sf::Vector2f fposition, sf::Vector2f fsize)
{
	position = fposition;

	menuImage.setTexture(*ftexture);

	sf::Vector2f tempDimensions(sf::Vector2f(menuImage.getLocalBounds().width, menuImage.getLocalBounds().height));

	menuImage.setOrigin(tempDimensions.x / 2, tempDimensions.y / 2);

	menuImage.setScale(fsize.x / tempDimensions.x, fsize.y / tempDimensions.y);

	menuImage.setPosition(0, 0);
}



void MenuSprite::update()
{

}

void MenuSprite::update(MouseData& fmouseData)
{

}

void MenuSprite::draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition)
{

	position += drawPosition;



	menuImage.move(position);

	frenderWindow.draw(menuImage);

	menuImage.move(-position);



	position -= drawPosition;

}

void MenuSprite::resetMD()
{

}