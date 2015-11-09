#include "AARectHitBox.h"


AARectHitBox::AARectHitBox()
{
	active = true;
	identity = "AARHB";
	rotation = 0;
}

AARectHitBox::AARectHitBox(double fwidth, double fheight, sf::Vector2f fpos)
{
	active = true;
	identity = "AARHB";
	rotation = 0;
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

	for (unsigned int i = 0; i < 4; i++)
	{
		initCorners[i] = corners[i];
	}
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

	for (unsigned int i = 0; i < 4; i++)
	{
		initCorners[i] = corners[i];
	}
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

void AARectHitBox::rotate(double frot)
{
	setRotation(rotation + frot);
}

void AARectHitBox::setRotation(double frot)
{
	rotation = frot;

	degtorad(frot);
	sf::Vector2f distvec;
	sf::Vector2f rotdistvec;



	for (unsigned int i = 0; i < 4; i++)
	{
		distvec = initCorners[i] - position;
		rotdistvec.x = distvec.x * cos(-frot) + distvec.y * sin(-frot);
		rotdistvec.y = -distvec.x * sin(-frot) + distvec.y * cos(-frot);
		corners[i] = rotdistvec + position;
	}


	double maxX = corners[0].x;
	double minX = corners[0].x;
	double maxY = corners[0].y;
	double minY = corners[0].y;

	for (int i = 0; i < 4; i++)
	{
		if (corners[i].x > maxX)
		{
			maxX = corners[i].x;
		}
		if (corners[i].x < minX)
		{
			minX = corners[i].x;
		}
		if (corners[i].y > maxY)
		{
			maxY = corners[i].y;
		}
		if (corners[i].y < minY)
		{
			maxY = corners[i].y;
		}
	}

	corners[0] = sf::Vector2f(minX, minY);
	corners[1] = sf::Vector2f(maxX, minY);
	corners[2] = sf::Vector2f(maxX, maxY);
	corners[3] = sf::Vector2f(minX, maxY);

	height = maxY - minY;
	width = maxX - minX;
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