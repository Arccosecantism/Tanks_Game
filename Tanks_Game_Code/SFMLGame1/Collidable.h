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

	std::string getID();


	

	
	GeneralHitBox* getHitBox(int findex);
	AARectHitBox& getBoundingBox();

	unsigned int getVectorSize();

protected:

	std::string ID;
	bool wasStill;
	bool activity;
	HitBoxVector hitboxvec;
	AARectHitBox boundingBox;

private:

	bool inCollision;
};

