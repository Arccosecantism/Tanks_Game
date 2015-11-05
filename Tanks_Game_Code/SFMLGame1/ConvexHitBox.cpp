#include "ConvexHitBox.h"


ConvexHitBox::ConvexHitBox()
{
}


ConvexHitBox::~ConvexHitBox()
{
}

void ConvexHitBox::addVertex(sf::Vector2f fvertex)
{
	vertecies.push_back(fvertex);
	if (vertecies.size() > 3)
	{
		if (checkConcavity())
	}
}

void ConvexHitBox::move(sf::Vector2f fdisp)
{
	position += fdisp;
	for (unsigned int i = 0; i < vertecies.size(); i++)
	{
		vertecies[i] += fdisp;
	}
}

void ConvexHitBox::setPosition(sf::Vector2f fpos)
{
	sf::Vector2f difdist = fpos - position;
	move(difdist);
}

unsigned int ConvexHitBox::getVertexVectorSize()
{
	return vertecies.size();
}

sf::Vector2f ConvexHitBox::getVertex(int findex)
{
	return vertecies[findex];
}

bool ConvexHitBox::checkConcavity()
{
	sf::Vector2f vecA;
	sf::Vector2f vecB;


	bool neg = false;
	bool pos = false;
	bool finalVal = true;

	for (unsigned int i = 1; i <= vertecies.size(); i++)
	{
		vecA = vertecies[i - 1] - vertecies[i];
		vecB = vertecies[(i + 1) % vertecies.size()] - vertecies[i];

		if (pos && neg)
		{
			break;
		}
		else
		{
			if ((vecA.x * vecB.y) - (vecA.y * vecB.x) > 0 && !pos)
			{
				pos = true;
			}

			if ((vecA.x * vecB.y) - (vecA.y * vecB.x) < 0 && !neg)
			{
				neg = true;
			}
		}
		

	}
	if (neg && pos)
	{
		finalVal = false;
	}

	return  finalVal;
}