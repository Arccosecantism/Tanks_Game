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

	
	bool tagFinder = true;



	bool addingWalls = false;

	bool insideTuple = false;

	std::string number = "";

	sf::Vector2f vec2f;

	std::vector<std::string> rectTriples;

	bool addingBGs = false;

	std::string bgCouple;


	bool addingPlayerSpawn = false;

	bool insideOP = false;

	std::vector<std::string> playerSpawns;


	bool addingUpgradeSpawn = false;

	std::vector<std::string> upgradeSpawns;


	
	
	bool inset = false;

	


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
					insideTuple = true;
				}

				else if (insideTuple)
				{
					if (letter == "{")
					{
						inset = true;
					}

					else if (inset)
					{
						if (letter == "(")
						{
							if (typeCheck)
							{
								typeCheck = false;
								curType = TWOARG;
							}
							insideOP = true;
						}
						else if (insideOP)
						{
							if (letter != ",")
							{
								number += letter;
							}
						}
						else
						{
							if (typeCheck)
							{
								typeCheck = false;
								curType = THREEARG;
							}
							
							if (letter == ",")
							{
								
							}
							else
							{
								number += letter;
							}
						}
					}
					if (letter != " ")
					{
						tupleRecord += letter;
					}
					if (letter == ">")
					{
						insideTuple = false;
						rectTriples.push_back(tupleRecord);
						tupleRecord = "";
					}
				}

				if (word == "DONE")
				{
					addingWalls = false;
					tagFinder = true;
				}
			}



			if (addingBGs)
			{
				if (letter == "<")
				{
					insideTuple = true;
				}

				if (insideTuple)
				{
					if (letter != " ")
					{
						tupleRecord += letter;
					}
					if (letter == ">")
					{
						insideTuple = false;
						bgCouple = tupleRecord;
						tupleRecord = "";
					}
				}

				if (word == "DONE")
				{
					addingBGs = false;
					tagFinder = true;
				}
			}


			else if (addingPlayerSpawn)
			{
				if (letter == "(")
				{
					insideOP = true;
				}

				if (insideOP)
				{
					if (letter != " ")
					{
						OPrecord += letter;
					}
					if (letter == ")")
					{
						insideOP = false;
						playerSpawns.push_back(OPrecord);
						OPrecord = "";
					}

				}

				if (word == "DONE")
				{
					addingPlayerSpawn = false;
					tagFinder = true;
				}
				
			}



			else if (addingUpgradeSpawn)
			{
				if (letter == "(")
				{
					insideOP = true;
				}

				if (insideOP)
				{
					if (letter != " ")
					{
						OPrecord += letter;
					}
					if (letter == ")")
					{
						insideOP = false;
						upgradeSpawns.push_back(OPrecord);
						OPrecord = "";
					}

				}

				if (word == "DONE")
				{
					addingUpgradeSpawn = false;
					tagFinder = true;
				}
			}




			if (tagFinder)
			{
				if (word == "ADDING_WALLS")
				{
					addingWalls = true;
					tagFinder = false;
					break;
				}

				else if (word == "ADDING_PLAYER_SPAWN_POINTS")
				{
					addingPlayerSpawn = true;
					tagFinder = false;
				}

				else if (word == "ADDING_UPGRADE_SPAWN_POINTS")
				{
					addingUpgradeSpawn = true;
					tagFinder = false;
				}

				else if (word == "ADDING_BACKGROUND")
				{
					addingBGs = true;
					tagFinder = false;
				}
			}



		}
		word = "";
	}
	


	for (int i = 0; i < rectTriples.size(); i++)
	{
		for (int j = 0; j < rectTriples[i].size(); j++)
		{
			letter = rectTriples[i][j];
			if (letter ==)
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < playerSpawns.size(); i++)
	{
		std::cout << playerSpawns[i] << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < upgradeSpawns.size(); i++)
	{
		std::cout << upgradeSpawns[i] << std::endl;
	}

	std::cout << std::endl;

	std::cout << bgCouple << std::endl;

}

sf::Vector2f GameMap::getTankSpawnPoint(int findex)
{
	return tankSpawnPoints[findex];
}

sf::Vector2f GameMap::getUpgradeSpawnPoint(int findex)
{
	return upgradeSpawnPoints[findex];
}


void GameMap::loadFromFileHelpSprite(std::string ftupleLine)
{

	bool inTuple = false;
	
	bool inSet = false;

	bool inOP = false;
	
	bool wasFirstOP = false;

	bool firstSet = true;


	enum rectType { TWOARG = 0, THREEARG = 1 };

	bool setType[2] = { TWOARG, TWOARG};

	bool typeCheck = true;

	int argCounter = 0;

	std::string character;


	std::string number = "";

	std::vector<std::string> numberVec;

	for (int i = 0; i < ftupleLine.size(); i++)
	{
		character = ftupleLine[i];
		if (character == "<")
		{
			inTuple = true;
		}
		else
		{
			if (inTuple)
			{
				if (character == "{")
				{
					inSet = true;
					wasFirstOP = true;
				}
				else
				{
					if (inSet)
					{
						if (character == "(")
						{
							inOP = true;

							if (!wasFirstOP)
							{
								if (firstSet)
								{
									setType[0] = THREEARG;
								}
								else
								{
									setType[1] = THREEARG;
								}
							}
							
						}
						else
						{
							if (wasFirstOP)
							{
								wasFirstOP = false;
							}
							if (inOP)
							{
								if (character == "," || character == ")")
								{
									numberVec.push_back(number);
									if (character == ")")
									{
										inOP = false;
									}
								}
								else
								{
									number += character;
								}
							}
						}
					}
				}
			}
		}
	}
}

void GameMap::loadFromFileHelpOP(std::string fopLine)
{

}

