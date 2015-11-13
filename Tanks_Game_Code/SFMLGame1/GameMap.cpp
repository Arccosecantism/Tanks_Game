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

	
	bool tagFinder = true;

	bool addingWalls = false;

	bool addingBGs = false;

	bool addingPlayerSpawn = false;

	bool addingUpgradeSpawn = false;

	
	std::vector<std::string> upgradeSpawns;
	
	std::vector<std::string> playerSpawns;
	
	std::vector<std::string> wallVector;
	
	std::vector<std::string> BGVector;
	
	std::vector<std::string>* tmpVecPointer;


	
	
	bool inset = false;

	


	while (std::getline(ifs, line))
	{
		if (line != "")
		{
			
			if (addingWalls || addingBGs)
			{
				if (line == "DONE")
				{
					addingWalls = false;
					addingBGs = false;
					tagFinder = true;
				}
				else if (line[0] == "<")
				{
					if (addingBGs)
					{
						tmpVecPointer = &BGVector;
					}
					else
					{
						tmpVecPointer = &wallVector;
					}
					
					loadFromFileHelpSprite(*tmpVecPointer);
				}
				
			}


			else if (addingPlayerSpawn || addingUpgradeSpawn)
			{
	
				if (line == "DONE")
				{
					addingPlayerSpawn = false;
					addingUpgradeSpawn = false;
					tagFinder = true;
				}
				else if (line[0] == "(")
				{
					if (addingBGs)
					{
						tmpVecPointer = &playerSpawns;
					}
					else
					{
						tmpVecPointer = &upgradeSpawnPoints;
					}
					
					loadFromFileHelpOP(*tmpVecPointer);
				}
				
			}

			if (tagFinder)
			{
				if (line == "ADDING_WALLS")
				{
					addingWalls = true;
					tagFinder = false;
	
				}

				else if (line == "ADDING_PLAYER_SPAWN_POINTS")
				{
					addingPlayerSpawn = true;
					tagFinder = false;
				}

				else if (line == "ADDING_UPGRADE_SPAWN_POINTS")
				{
					addingUpgradeSpawn = true;
					tagFinder = false;
				}

				else if (line == "ADDING_BACKGROUND")
				{
					addingBGs = true;
					tagFinder = false;
				}
				else if (line == "FILE_DONE")
				{
					break;
				}
			}
		}
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


void GameMap::loadFromFileHelpSprite(std::string ftupleLine, std::vector<std::string>& vectbfilled)
{
	if (!vectbfilled.size())
	{
		bool inTuple = false;
		
		bool inSet = false;

		bool inOP = false;
		
		bool wasFirstOP = false;

		bool firstSet = true;

		bool lastWasNum = true;


		enum rectType {TWOARG = 0, THREEARG = 1 };

		bool setType[2] = {TWOARG, TWOARG};

		bool typeCheck = true;

		int argCounter = 0;

		std::string character;


		std::string number = "";

		
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
						lastWasNum = true;
					}
					else
					{
						if (inSet)
						{
							if (character == "(")
							{
								inOP = true;
								lastWasNum = true;

								if (wasFirstOP)
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
										vectbfilled.push_back(number);
										number = "";
										if (character == ")")
										{
											inOP = false;
											lastWasNum = false;
										}
									}
									else
									{
										number += character;
									}
								}
								else
								{
									if (character == "," || character == "}")
									{
										if (lastWasNum)
										{
											vectbfilled.push_back(number);
											number = "";
										}
										if (character == "}")
										{
											inSet = false;
											lastWasNum = false;
										}
									}
									else
									{
										number += character;
									}
								}
							}
						}
						else
						{
							if (character == "," || character == ">")
							{
								elementBegin = true;
								if (lastWasNum)
								{
									if (number == "SET_DUPLICATE")
									{
										int tmpsiz = vectbfilled.size();
										
										for (int i = 0; i < tmpsiz; i++)
										{
											vectbfilled.push_back(vectbfilled[i]);
										}
										
									}
									else
									{
										vectbfilled.push_back(number);
									}
									
									number = "";
								}
								if (character == ">")
								{
									inTuple = false;
									break;
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

void GameMap::loadFromFileHelpOP(std::string fopLine, std::vector<std::string>& vectbfilled)
{
	if (!vectbfilled.size())
	{
		bool inOP;
		
		std::string character = "";
		
		std::string number = "";
		
		for (int i = 0; i < fopLine.size(); i++)
		{
			character = fopLine[i];
			if (character = "(")
			{
				inOP = true;
			}
			else
			{
				if (inOP)
				{
					if (character == "," || character == ")")
					{
						vectbfilled.push_back(number);
						number = "";
						if (character == ")")
						{
							inOP = false;
							break;
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

