#pragma once
#include "HitBoxVector.h"

class Collidable
{
public:
	Collidable();
	~Collidable();

	bool getActivity();
	void setActivity(bool b);
	GeneralHitBox* getHitBox(int findex);
	AARectHitBox getBoundingBox();



protected:

	bool inCollision;
	bool activity;
	HitBoxVector hitboxvec;
	AARectHitBox boundingBox;
};

