#include "GameMap.h"
#include <fstream>


GameMap::GameMap()
{
	inCollision = false;
	activity = true;
}


GameMap::~GameMap()
{
}

void loadFromFile(std::string filename, ResourceGroup& frg)
{
	std::ifstream ifs(filename);

	std::string line;

	std::string word = "";

	std::string letter;

	bool addingWalls = false;;

	while (std::getline(ifs, line))
	{
		for (unsigned int i = 0; i < line.size(); i++)
		{
			letter = line[i];

			if (letter != " ")
			{
				word += letter;
			}
			else
			{
				word = "";
			}

			if ((!addingWalls) && word == "ADDING_WALLS")
			{
				addingWalls = true; 
				break;
			}

		}
		word = "";
	}
}

sf::Vector2f GameMap::getTankSpawnPoint(int findex)
{
	return tankSpawnPoints[findex];
}

sf::Vector2f GameMap::getUpgradeSpawnPoint(int findex)
{
	return upgradeSpawnPoints[findex];
}
