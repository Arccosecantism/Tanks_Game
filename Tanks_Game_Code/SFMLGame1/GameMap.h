#pragma once
#include "Collidable.h"
#include "IncludeMe.h"
class GameMap : Collidable
{
public:
	GameMap();
	~GameMap();

	void loadFromFile(std::string filename, ResourceGroup& frg);

	sf::Vector2f getTankSpawnPoint(int findex);
	sf::Vector2f getUpgradeSpawnPoint(int findex);

private:

	sf::Sprite bgSprite;
	std::vector<sf::Sprite> wallSprites;

	std::vector<sf::Vector2f> tankSpawnPoints;
	std::vector<sf::Vector2f> upgradeSpawnPoints;

};

