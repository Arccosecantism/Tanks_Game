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

	virtual void move(sf::Vector2f fdisp);
	virtual void setPosition(sf::Vector2f fpos);
	virtual void rotate(double frot);
	virtual void setRotation(double frot);

protected:

	void degtorad(double& fdeg);
	
	std::string identity;
	bool active;
	sf::Vector2f position;
};

