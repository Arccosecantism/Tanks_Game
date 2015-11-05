#pragma once
#include "GeneralHitBox.h"
class CircularHitBox : GeneralHitBox
{
public:

	CircularHitBox();
	CircularHitBox(sf::Vector2f fpos, double frad);
	void setup(sf::Vector2f fpos, double frad);
	~CircularHitBox();

	void move(sf::Vector2f fdisp);

	void setPosition(sf::Vector2f fpos);


	double getRadius();

	double getRadiusQ();

	sf::Vector2f getPosition();

private:

	double radius;
	double radiusQ;
	sf::Vector2f position;
};

