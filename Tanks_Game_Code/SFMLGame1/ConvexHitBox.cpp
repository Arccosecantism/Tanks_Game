#include "ConvexHitBox.h"





ConvexHitBox::ConvexHitBox()
{
	identity = "CHB";
	active = true;
	rotation = 0;
}


ConvexHitBox::~ConvexHitBox()
{
}

void ConvexHitBox::addVertex(sf::Vector2f fvertex)
{
	vertecies.push_back(fvertex);
	if (checkVertexExistance())
	{
		//std::cout << "didn't work -- already exists" << std::endl;
		vertecies.erase(vertecies.begin() + vertecies.size() - 1);
	}
	else if (vertecies.size() > 3)
	{
		if (!checkConcavity())
		{
			//std::cout << "didn't work -- concave" << std::endl;
			vertecies.erase(vertecies.begin() + vertecies.size() - 1);
		}
		//else if(!checkSimplicity())
		//{
		//	std::cout << "didn't work -- complex" << std::endl;
		//	vertecies.erase(vertecies.begin() + vertecies.size() - 1);
		//}
		//else
		//{
		//	std::cout << "maybe worked" << std::endl;
		//}


	}
	//else
	//{
	//	std::cout << "maybe worked" << std::endl;
	//}
}

void  ConvexHitBox::addVertex(double fx, double fy)
{
	addVertex(sf::Vector2f(fx, fy));
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

void ConvexHitBox::rotate(double frot)
{
	rotation += frot;
	degtorad(frot);
	sf::Vector2f distVec;
	sf::Vector2f rotDistVec;
	for (unsigned int i = 0; i < vertecies.size(); i++)
	{
		distVec = vertecies[i] - position;
		rotDistVec.x = distVec.x * cos(-frot) + distVec.y * sin(-frot);
		rotDistVec.y = -distVec.x * sin(-frot) + distVec.y * cos(-frot);
		vertecies[i] = rotDistVec + position;
	}

}

void ConvexHitBox::setRotation(double frot)
{
	rotate(frot - rotation);
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
	bool convex = true;

	int checkerA;
	int checkerN;
	int checkerB;

	for (unsigned int i = 1; i <= vertecies.size(); i++)
	{
		vecA = vertecies[i - 1] - vertecies[i % vertecies.size()];
		vecB = vertecies[(i + 1) % vertecies.size()] - vertecies[i % vertecies.size()];

		checkerA = i - 1;
		checkerN = i;
		checkerB = (i + 1) % vertecies.size();

		if ((pos && neg) || (vecA.x * vecB.y) - (vecA.y * vecB.x) == 0)
		{ 
			convex = false;
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
		convex = false;
	}

	return  convex;
}





//bool ConvexHitBox::checkSimplicity()
//{
//	bool simple = true;
//	CollisionLineSeg lineA;
//	CollisionLineSeg lineB;
//
//	int curVert = vertecies.size() - 1;
//
//
//	lineA.twoPointsSetup(vertecies[curVert], vertecies[0]);
//
//	for (unsigned int j = 1; j < vertecies.size() - 1; j++)
//	{
//
//		lineB.twoPointsSetup(vertecies[j], vertecies[j - 1]);
//		if (lineA.checkIntersect(lineB))
//		{
//			simple = false;
//			break;
//		}
//	}
//
//	return simple;
//}

bool ConvexHitBox::checkVertexExistance()
{
	bool exists = false;
	if (vertecies.size() > 1)
	{
		for (unsigned int i = 0; i < vertecies.size() - 1; i++)
		{
			if (vertecies[i] == vertecies[vertecies.size() - 1])
			{
				exists = true;
			}
		}
	}
	return exists;

}