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
