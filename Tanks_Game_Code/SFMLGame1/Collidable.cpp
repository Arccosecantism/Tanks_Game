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

GeneralHitBox* Collidable::getHitBox(int findex)
{
	return hitboxvec.getHitBox(findex);
}

AARectHitBox Collidable::getBoundingBox()
{
	return boundingBox;
}