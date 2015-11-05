#include "AARectHitBox.h"


AARectHitBox::AARectHitBox()
{
	active = true;
	identity = "AARHB";
}

AARectHitBox::AARectHitBox(double fwidth, double fheight, sf::Vector2f fpos)
{
	active = true;
	identity = "AARHB";
	setup(fwidth, fheight, fpos);
}

AARectHitBox::AARectHitBox(sf::Vector2f fTLCorner, sf::Vector2f fBRCorner)
{
	active = true;
	identity = "AARHB"; 
	setup(fTLCorner, fBRCorner);
}


void AARectHitBox::setup(double fwidth, double fheight, sf::Vector2f fpos)
{
	width = fwidth;
	height = fheight;
	position = fpos;

	corners[0] = fpos + sf::Vector2f(-fwidth / 2, -fheight / 2);
	corners[1] = fpos + sf::Vector2f(fwidth / 2, -fheight / 2);
	corners[2] = fpos + sf::Vector2f(fwidth / 2, fheight / 2);
	corners[3] = fpos + sf::Vector2f(-fwidth / 2, fheight / 2);
}

void AARectHitBox::setup(sf::Vector2f fTLCorner, sf::Vector2f fBRCorner)
{
	width = fBRCorner.x - fTLCorner.x;
	height = fBRCorner.y - fTLCorner.y;
	position = sf::Vector2f(fTLCorner.x + width / 2, fTLCorner.y + height / 2);

	corners[0] = position + sf::Vector2f(-width / 2, -height / 2);
	corners[1] = position + sf::Vector2f(width / 2, -height / 2);
	corners[2] = position + sf::Vector2f(width / 2, height / 2);
	corners[3] = position + sf::Vector2f(-width / 2, height / 2);
}



AARectHitBox::~AARectHitBox()
{
}


void AARectHitBox::move(sf::Vector2f fdisp)
{
	position += fdisp;

	for (unsigned int i = 0; i < 4; i++)
	{
		corners[i] += fdisp;
	}

}

void AARectHitBox::setPosition(sf::Vector2f fpos)
{
	sf::Vector2f difDist = fpos - position;
	move(difDist);
}

sf::Vector2f AARectHitBox::getCorner(int findex)
{
	return corners[findex];
}

sf::Vector2f AARectHitBox::getPosition()
{
	return position;
}

double AARectHitBox::getWidth()
{
	return width;
}

double AARectHitBox::getHeight()
{
	return height;
}