#include "CollidableManager.h"


CollidableManager::CollidableManager()
{
}


CollidableManager::~CollidableManager()
{
}

void CollidableManager::addCollidable(Collidable& fcol)
{
	collidables.push_back(&fcol);
}

void CollidableManager::addCollidable(Collidable* fcol)
{
	collidables.push_back(fcol);
}

void CollidableManager::checkCollision()
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
			if (checkMotion(i, j))
			{
				if (checkAABBCollision(collidables[i]->getBoundingBox(), collidables[j]->getBoundingBox()))
				{
					ksiz = collidables[i]->getVectorSize();
					hsiz = collidables[j]->getVectorSize();

					doneCheckingCollision = false;

					for (int k = 0; (k < ksiz) && !doneCheckingCollision; k++)
					{
						for (int h = 0; (h < hsiz) && !doneCheckingCollision; h++)
						{

							hba = collidables[i]->getHitBox(k);
							hbb = collidables[j]->getHitBox(h);

							if (hba->getID() == "AARHB")
							{
								if (hbb->getID() == "AARHB")
								{
									if (checkAABBCollision(*((AARectHitBox*)(hba)), *((AARectHitBox*)(hbb))))
									{
										collidables[i]->setInCollision(true);
										collidables[j]->setInCollision(true);
										interpretCollisions(i, j);
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

bool CollidableManager::checkAABBCollision(AARectHitBox aabb1, AARectHitBox aabb2)
{
	bool iscolliding = true;

	float aVals[4] = { aabb1.getCorner(0).x, aabb1.getCorner(0).y, aabb1.getCorner(2).x, aabb1.getCorner(2).y };
	float bVals[4] = { aabb2.getCorner(0).x, aabb2.getCorner(0).y, aabb2.getCorner(2).x, aabb2.getCorner(2).y };

	if ((aVals[0] > bVals[2]) || (aVals[1] > bVals[3]) || (aVals[2] < bVals[0]) || (aVals[3] < bVals[1]))
	{
		iscolliding = false;
	}


	return iscolliding;
}

bool CollidableManager::checkMotion(int& i, int& j)
{
	return !(collidables[i]->getStillness() && collidables[j]->getStillness());
}

void CollidableManager::clear()
{
	collidables.clear();
}


void CollidableManager::interpretCollisions(int& i, int& j)
{
	if (collidables[i]->getID() == "Player" && collidables[j]->getID() == "Player")
	{

	}
	else if (collidables[i]->getID() == "Player" && collidables[j]->getID() == "GameMap")
	{
		((Player*)collidables[i])->collideWithWall();
	}
	else if (collidables[i]->getID() == "GameMap" && collidables[j]->getID() == "Player")
	{
		((Player*)collidables[j])->collideWithWall();
	}

}
