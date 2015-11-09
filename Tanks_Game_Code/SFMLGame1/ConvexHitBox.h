#pragma once
#include "GeneralHitBox.h"
//#include "CollisionLineSeg.h"
class ConvexHitBox : GeneralHitBox
{
public:

	ConvexHitBox();

	~ConvexHitBox();


	void addVertex(sf::Vector2f fvertex);
	void addVertex(double fx, double fy);

	void move(sf::Vector2f fdisp);
	void setPosition(sf::Vector2f fpos);
	void rotate(double frot);
	void setRotation(double frot);

	unsigned int getVertexVectorSize();
	
	sf::Vector2f getVertex(int findex);



private:
	bool checkConcavity();
//	bool checkSimplicity();
	bool checkVertexExistance();

	std::vector<sf::Vector2f> vertecies;

	sf::Vector2f position;
	double rotation;
};

