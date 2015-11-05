#pragma once
#include "SFMLbase.h"
class GeneralHitBox
{
public:
	GeneralHitBox();
	~GeneralHitBox();

	std::string getID();

	void setActive(bool fb);
	void switchActive();
	bool getActive();

	virtual void move(sf::Vector2f fdisp) = 0;
	virtual void setPosition(sf::Vector2f fpos) = 0;

protected:

	
	std::string identity;
	bool active;
};

