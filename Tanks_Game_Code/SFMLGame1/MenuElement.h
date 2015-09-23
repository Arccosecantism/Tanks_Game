#pragma once

#include "IncludeMe.h"

class MenuElement
{
public:

	virtual void update() = 0;
	virtual void update(MouseData& fmouseData) = 0;
	virtual void draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition) = 0;
	//virtual void setResources(ResourceGroup& rgroup) = 0;

	sf::Vector2f getPosition();

	void setPosition(sf::Vector2f fpos);

	void move(sf::Vector2f velocity);



	bool getRequiresMouseData();

	void setRequiresMouseData(bool frequiresMouseData);


	void hide();

	void unhide();

	bool getIsHidden();


protected:

		sf::Vector2f position;


		bool requiresMouseData;

		bool isHidden;
};

