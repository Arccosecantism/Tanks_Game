#pragma once
#include "HitBoxVector.h"

class Collidable
{
public:
	Collidable();
	~Collidable();

	bool getActivity();
	GeneralHitBox* getHitBox(int findex);
	AARectHitBox getBoundingBox();



protected:

	bool inCollision;
	bool activity;
	HitBoxVector hitboxvec;
	AARectHitBox boundingBox;
};

