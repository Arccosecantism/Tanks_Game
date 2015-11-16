#pragma once
#include "HitBoxInclude.h"
class HitBoxVector
{
public:
	HitBoxVector();
	~HitBoxVector();

	void clearVector();

	void addHitBox(GeneralHitBox* fhitbox);


	void move(sf::Vector2f fdisp);
	void setPosition(sf::Vector2f fpos);
	void rotate(double frot);
	void setRotation(double frot);
	unsigned int getVectorSize();

	GeneralHitBox* getHitBox(int findex);

private:

	std::vector<GeneralHitBox*> hitboxvec;
};

