#pragma once

#include "IncludeMe.h"

class MenuElement
{
public:

	virtual void update() = 0;
	virtual void update(MouseData& fmouseData) = 0;
	virtual void draw(sf::RenderWindow& frenderWindow) = 0;
	//virtual void setResources(ResourceGroup& rgroup) = 0;

	sf::Vector2f getPosition();


protected:

		sf::Vector2f position;
};

