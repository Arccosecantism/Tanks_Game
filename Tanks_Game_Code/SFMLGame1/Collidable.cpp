#include "Collidable.h"


Collidable::Collidable()
{
}


Collidable::~Collidable()
{
}

bool Collidable::getActivity()
{
	return activity;
}

void Collidable::setActivity(bool b)
{
	activity = b;
}

void Collidable::setInCollision(bool b)
{
	inCollision = b;
}

bool  Collidable::getInCollision()
{
	return inCollision;
}

bool Collidable::getStillness()
{
	return wasStill;
}

GeneralHitBox* Collidable::getHitBox(int findex)
{
	return hitboxvec.getHitBox(findex);
}

AARectHitBox& Collidable::getBoundingBox()
{
	return boundingBox;
}

unsigned int Collidable::getVectorSize()
{
	return hitboxvec.getVectorSize();
}
