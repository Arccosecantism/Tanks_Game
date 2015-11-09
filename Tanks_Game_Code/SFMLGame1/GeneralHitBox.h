#pragma once
#include "SFMLbase.h"
#include <iostream>
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
	virtual void rotate(double frot) = 0;
	virtual void setRotation(double frot) = 0;

protected:

	void degtorad(double& fdeg);
	
	std::string identity;
	bool active;
};

