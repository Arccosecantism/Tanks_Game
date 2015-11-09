#include "HitBoxVector.h"


HitBoxVector::HitBoxVector()
{
}


HitBoxVector::~HitBoxVector()
{
}

void HitBoxVector::addHitBox(GeneralHitBox* fhitbox)
{
	hitboxvec.push_back(fhitbox);
}

void HitBoxVector::addHitBox(GeneralHitBox& fhitbox)
{
	hitboxvec.push_back(&fhitbox);
}

void HitBoxVector::move(sf::Vector2f fdisp)
{
	for (int i = 0; i < hitboxvec.size(); i++)
	{
		hitboxvec[i]->move(fdisp);
	}
}

void HitBoxVector::setPosition(sf::Vector2f fpos)
{
	for (int i = 0; i < hitboxvec.size(); i++)
	{
		hitboxvec[i]->setPosition(fpos);
	}
}

void HitBoxVector::rotate(double frot)
{
	for (int i = 0; i < hitboxvec.size(); i++)
	{
		hitboxvec[i]->rotate(frot);
	}
}

void HitBoxVector::setRotation(double frot)
{
	for (int i = 0; i < hitboxvec.size(); i++)
	{
		hitboxvec[i]->rotate(frot);
	}

}

GeneralHitBox* HitBoxVector::getHitBox(int findex)
{
	return hitboxvec[findex];
}