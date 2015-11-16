#pragma once
#include "Collidable.h"
#include "IncludeMe.h"
#include "AppSprite.h"
class GameMap : Collidable
{
public:
	GameMap();
	~GameMap();


	void loadFromFile(std::string filename, ResourceGroup* fresourceGroup);

	sf::Vector2f getTankSpawnPoint(int findex);

	sf::Vector2f getUpgradeSpawnPoint(int findex);

	void draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition);

private:

	void reset();

	void readSpriteTuple(std::string ftupleLine, std::vector<std::string>& vectbfilled);

	void readOrderedPair(std::string fOPLine, std::vector<std::string>& vectbfilled);

	float matof(std::string str);


	AppSprite bgSprite;

	std::vector<AppSprite> wallSprites;


	std::vector<sf::Vector2f> tankSpawnPoints;

	std::vector<sf::Vector2f> upgradeSpawnPoints;

};

