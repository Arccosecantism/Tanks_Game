#pragma once

#include "IncludeMe.h"

class MenuElement
{
public:

	virtual void update() = 0;
	virtual void update(MouseData& fmouseData) = 0;
	virtual void draw(sf::RenderWindow& frenderWindow) = 0;
	virtual void setTextures(ResourceGroup& rgroup ) = 0;

	bool getRequiresMouseData();

protected:

	bool requiresMouseData;
};

