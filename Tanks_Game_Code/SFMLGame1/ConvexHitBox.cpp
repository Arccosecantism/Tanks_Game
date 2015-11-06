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
		if (!checkConcavity())
		{
			vertecies.erase(vertecies.begin() + vertecies.size() - 1);
		}
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

		if ((pos && neg) || (vecA.x * vecB.y) - (vecA.y * vecB.x) == 0)
		{ 
			finalVal = false;
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


struct myLine
{
public:
	double slope;
	double xbounds[2];
	double ybounds[2];

	bool checkIntersect(myLine lineB)
	{
		if (!checkConnected(lineB))
		{

		}
	}

private:
	bool checkInBounds(sf::Vector2f point)
	{
		bool inside = false;
		if (point.x < xbounds[1] && point.x > xbounds[0] && point.y < ybounds[1] && point.y > ybounds[0])
		{
			inside = true;
		}
		return inside;
	}

	bool checkConnected(myLine lineB)
	{
		bool connected = false;

		for (int i = 0; i < 2; i++)
		{
			if (lineB.xbounds[i] == this->xbounds[i] && lineB.ybounds[i] == this->ybounds[i])
			{
				connected = true;
			}
			if (lineB.xbounds[i] == this->xbounds[1 - i] && lineB.ybounds[i] == this->ybounds[1 - i])
			{
				connected = true;
			}
			
		}

		return connected;
	}


};


bool ConvexHitBox::checkSimplicity()
{
	myLine lineA;
	myLine lineB;

	int si;
	int sj;
	for (unsigned int i = 0; i < vertecies.size(); i++)
	{
		si = (i + 1) % vertecies.size();
		if (vertecies[i].x == vertecies[si].x)
		{
			for (int j = 0; j < vertecies.size(); j++)
			{

			}
		}
		else
		{
			lineA.slope = (vertecies[si].y - vertecies[i].y) / (vertecies[si].x - vertecies[i].x);

			lineA.xbounds[0] = vertecies[i].x;
			lineA.xbounds[1] = vertecies[si].x;
			lineA.ybounds[0] = vertecies[i].y;
			lineA.ybounds[1] = vertecies[si].y;


			for (int j = 0; j < vertecies.size(); j++)
			{

				sj = (j + 1) % vertecies.size();

				if (vertecies[j].x == vertecies[sj].x)
				{

				}

				else
				{
					lineB.slope = (vertecies[sj].y - vertecies[j].y) / (vertecies[sj].x - vertecies[j].x);

					lineB.xbounds[0] = vertecies[j].x;
					lineB.xbounds[1] = vertecies[sj].x;
					lineB.ybounds[0] = vertecies[j].y;
					lineB.ybounds[1] = vertecies[sj].y;
				}
			}
		}
	}
	return false;
}