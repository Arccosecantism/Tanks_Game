#pragma once
#include "HitBoxVector.h"

class Collidable
{
public:
	Collidable();
	~Collidable();

	bool getActivity();

	void setActivity(bool b);


	void setInCollision(bool b);
	
	bool getInCollision();

	bool getStillness();

	
	GeneralHitBox* getHitBox(int findex);
	AARectHitBox& getBoundingBox();

	unsigned int getVectorSize();

protected:


	bool wasStill;
	bool activity;
	HitBoxVector hitboxvec;
	AARectHitBox boundingBox;

private:

	bool inCollision;
};

