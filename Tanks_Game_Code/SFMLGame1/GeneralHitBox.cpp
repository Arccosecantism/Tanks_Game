#include "GeneralHitBox.h"


GeneralHitBox::GeneralHitBox()
{
}


GeneralHitBox::~GeneralHitBox()
{
}

std::string GeneralHitBox::getID()
{
	return identity;
}

void GeneralHitBox::setActive(bool fb)
{
	active = fb;
}

void GeneralHitBox::switchActive()
{
	active = !active;
}

bool GeneralHitBox::getActive()
{
	return active;
}