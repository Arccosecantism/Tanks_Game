#include "CollideableManager.h"


CollideableManager::CollideableManager()
{
}


CollideableManager::~CollideableManager()
{
}

void CollideableManager::addCollidabe(Collidable& fcol)
{
	collidables.push_back(&fcol);
}

void CollideableManager::addCollidabe(Collidable* fcol)
{
	collidables.push_back(fcol);
}

void CollideableManager::checkCollision()
{
	unsigned int isiz = collidables.size() - 1;
	unsigned int ksiz;
	unsigned int hsiz;
	GeneralHitBox* hba;
	GeneralHitBox* hbb;
	bool doneCheckingCollision = false;

	for (int i = 0; i < isiz; i++)
	{
		for (int j = i + 1; j <= isiz; j++)
		{
			if (!checkMotion(i, j))
			{
				if (!checkAABBCollision(collidables[i]->getBoundingBox(), collidables[j]->getBoundingBox()))
				{
					ksiz = collidables[i]->getVectorSize();
					hsiz = collidables[j]->getVectorSize();

					for (int k = 0; (k < ksiz) && !doneCheckingCollision; k++)
					{
						for (int h = 0; (h < hsiz) && !doneCheckingCollision; h++)
						{

							hba = collidables[i]->getHitBox(k);
							hbb = collidables[j]->getHitBox(h);

							if (hba->getID() == "AABB")
							{
								if (hbb->getID() == "AABB")
								{
									if (checkAABBCollision(*((AARectHitBox*)(hba)), *((AARectHitBox*)(hbb))))
									{
										collidables[i]->setInCollision(true);
										collidables[j]->setInCollision(true);
										bool doneCheckingCollision = true;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

bool CollideableManager::checkAABBCollision(AARectHitBox aabb1, AARectHitBox aabb2)
{
	bool iscolliding = true;

	float aVals[4] = { aabb1.getCorner(0).x, aabb1.getCorner(0).y, aabb1.getCorner(2).x, aabb1.getCorner(2).y };
	float bVals[4] = { aabb2.getCorner(0).x, aabb2.getCorner(0).y, aabb2.getCorner(2).x, aabb2.getCorner(2).y };

	for (int i = 0; i < 4; i++)
	{
		if (aVals[i] > bVals[(i + 2) % 4])
		{
			iscolliding = false;
			break;
		}
	}

	return iscolliding;
}

bool CollideableManager::checkMotion(int& i, int& j)
{
	return (collidables[i]->getStillness() && collidables[j]->getStillness());
}