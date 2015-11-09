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

void GameMap::loadFromFile(std::string filename)
{
	std::ifstream ifs(filename);

	std::string line;

	std::string word = "";

	std::string letter;

	

	bool addingWalls = false;

	bool insideTriple = false;

	bool insideRect = false;

	std::string tripleRecord = "";
	std::vector<std::string> rectTriples;

	while (std::getline(ifs, line))
	{
		for (unsigned int i = 0; i < line.size(); i++)
		{
			letter = line[i];
			word += letter;
			if (letter == " ")
			{
				word = "";
			}

			if (addingWalls)
			{
				if (letter == "<")
				{
					insideTriple = true;
				}

				if (insideTriple)
				{
					tripleRecord += letter;
					if (letter == ">")
					{
						insideTriple = false;
						rectTriples.push_back(tripleRecord);
						tripleRecord = "";
					}
				}

				
			}
			if ((!addingWalls) && (word == "ADDING_WALLS"))
			{
				addingWalls = true; 
				break;
			}



		}
		word = "";
	}

	for (int i = 0; i < rectTriples.size(); i++)
	{
		std::cout << rectTriples[i] << std::endl;
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
