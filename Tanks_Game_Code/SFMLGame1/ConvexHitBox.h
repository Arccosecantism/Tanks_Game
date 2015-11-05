#pragma once
#include "GeneralHitBox.h"
class ConvexHitBox : GeneralHitBox
{
public:

	ConvexHitBox();

	~ConvexHitBox();


	void addVertex(sf::Vector2f fvertex);

	void move(sf::Vector2f fdisp);

	void setPosition(sf::Vector2f fpos);

	unsigned int getVertexVectorSize();
	
	sf::Vector2f getVertex(int findex);



private:
	bool checkConcavity();
	bool checkSimplicity();

	std::vector<sf::Vector2f> vertecies;

	sf::Vector2f position;
};

