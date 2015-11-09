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

void GeneralHitBox::degtorad(double& fdeg)
{
	double pi = 3.141592653589793238463;
	fdeg *= pi / 180.0f;
}