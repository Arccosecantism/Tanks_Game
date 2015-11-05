#include "CircularHitBox.h"


CircularHitBox::CircularHitBox()
{
	identity = "CHB";
	active = true;
}

CircularHitBox::CircularHitBox(sf::Vector2f fpos, double frad)
{
	identity = "CHB";
	active = true;
	setup(fpos, frad);
}

void CircularHitBox::setup(sf::Vector2f fpos, double frad)
{
	position = fpos;
	radius = frad;
	radiusQ = radius * radius;
}

CircularHitBox::~CircularHitBox()
{

}

void CircularHitBox::move(sf::Vector2f fdisp)
{
	position += fdisp;
}

void CircularHitBox::setPosition(sf::Vector2f fpos)
{
	position = fpos;
}

double CircularHitBox::getRadius()
{
	return radius;
}

double CircularHitBox::getRadiusQ()
{
	return radiusQ;
}

sf::Vector2f CircularHitBox::getPosition()
{
	return position;
}