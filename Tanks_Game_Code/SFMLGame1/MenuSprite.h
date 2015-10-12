#pragma once
#include "MenuElement.h"

class MenuSprite : public MenuElement
{

public:
	MenuSprite();
	MenuSprite(sf::Texture* ftexture, sf::Vector2f fposition, sf::Vector2f fsize);
	~MenuSprite();

	void setup(sf::Texture* ftexture, sf::Vector2f fposition, sf::Vector2f fsize);



	void update();

	void update(MouseData& fmouseData);

	void draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition);

	void resetMD();

	sf::Vector2f getGlobalDimensions();

	sf::Vector2f getLocalDimensions();

private:

	sf::Sprite menuImage;

};

