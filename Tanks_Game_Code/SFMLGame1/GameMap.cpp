#include "GameMap.h"


GameMap::GameMap()
{
	inCollision = false;
	activity = true;
}


GameMap::~GameMap()
{
}

sf::Vector2f GameMap::getTankSpawnPoint(int findex)
{
	return tankSpawnPoints[findex];
}

sf::Vector2f GameMap::getUpgradeSpawnPoint(int findex)
{
	return upgradeSpawnPoints[findex];
}