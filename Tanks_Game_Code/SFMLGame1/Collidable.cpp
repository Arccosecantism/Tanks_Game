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

GeneralHitBox* Collidable::getHitBox(int findex)
{
	return hitboxvec.getHitBox(findex);
}

AARectHitBox Collidable::getBoundingBox()
{
	return boundingBox;
}
