#include "GameMap.h"
#include <fstream>
#include <sstream>


GameMap::GameMap()
{
	ID = "GameMap";
	setInCollision(false);
	activity = true;
}


GameMap::~GameMap()
{
}

void GameMap::loadFromFile(std::string filename, ResourceGroup* fresourceGroup)
{
	reset();

	std::ifstream ifs(filename);

	std::string line;

	
	bool tagFinder = true;

	bool addingWalls = false;

	bool addingBGs = false;

	bool addingPlayerSpawn = false;

	bool addingUpgradeSpawn = false;

	
	std::vector<std::vector<std::string>> upgradeSpawns;
	
	std::vector<std::vector<std::string>> playerSpawns;
	
	std::vector<std::vector<std::string>> wallVector;
	
	std::vector<std::vector<std::string>> BGVector;
	
	std::vector<std::string> pbvec;

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
				else if (line[0] == '<')
				{
					if (addingBGs)
					{
						BGVector.push_back(pbvec);
						tmpVecPointer = &BGVector[BGVector.size()-1];
					}
					else
					{
						wallVector.push_back(pbvec);
						tmpVecPointer = &wallVector[wallVector.size() - 1];
					}
					
					readSpriteTuple(line, *tmpVecPointer);
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
				else if (line[0] == '(')
				{
					if (addingPlayerSpawn)
					{
						playerSpawns.push_back(pbvec);
						tmpVecPointer = &playerSpawns[playerSpawns.size() - 1];
					}
					else
					{
						upgradeSpawns.push_back(pbvec);
						tmpVecPointer = &upgradeSpawns[upgradeSpawns.size() - 1];
					}
					
					readOrderedPair(line, *tmpVecPointer);
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


	sf::Vector2f minTLcorn(0,0);
	sf::Vector2f maxBRcorn(0,0);




	for (int i = 0; i < wallVector.size(); i++)
	{
		if (wallVector[i][0] == "THREE_ARG")
		{
			wallSprites.push_back(	AppSprite(	fresourceGroup->getTexturePointer(wallVector[i][10]),
												sf::Vector2f(matof(wallVector[i][3]), matof(wallVector[i][4])),
												sf::Vector2f(matof(wallVector[i][1]), matof(wallVector[i][2])),
												0		));
		}
		else if (wallVector[i][0] == "TWO_ARG")
		{
			wallSprites.push_back(	AppSprite(fresourceGroup->getTexturePointer(wallVector[i][10]),
									sf::Vector2f(matof(wallVector[i][1]), matof(wallVector[i][2])),
									sf::Vector2f(matof(wallVector[i][3]), matof(wallVector[i][4]))));
		}
		
		if (wallVector[i][5] == "THREE_ARG")
		{
			hitboxvec.addHitBox(new AARectHitBox(	matof(wallVector[i][6]), matof(wallVector[i][7]),
													sf::Vector2f(matof(wallVector[i][8]), matof(wallVector[i][9]))));


			if (matof(wallVector[i][8]) - matof(wallVector[i][6]) < minTLcorn.x)
			{
				minTLcorn.x = matof(wallVector[i][8]) - matof(wallVector[i][6]);
			}
			if (matof(wallVector[i][9]) - matof(wallVector[i][7]) < minTLcorn.y)
			{
				minTLcorn.y = matof(wallVector[i][9]) - matof(wallVector[i][7]);
			}
			if (matof(wallVector[i][8]) + matof(wallVector[i][6]) > maxBRcorn.x)
			{
				maxBRcorn.x = matof(wallVector[i][8]) + matof(wallVector[i][6]);
			}
			if (matof(wallVector[i][9]) + matof(wallVector[i][7]) > maxBRcorn.y)
			{
				maxBRcorn.y = matof(wallVector[i][9]) + matof(wallVector[i][7]);
			}
		}
		else if (wallVector[i][5] == "TWO_ARG")
		{
			hitboxvec.addHitBox(new AARectHitBox(	sf::Vector2f(matof(wallVector[i][6]), matof(wallVector[i][7])),
													sf::Vector2f(matof(wallVector[i][8]), matof(wallVector[i][9]))));

			if (matof(wallVector[i][6]) < minTLcorn.x)
			{
				minTLcorn.x = matof(wallVector[i][6]);
			}
			if (matof(wallVector[i][7]) < minTLcorn.y)
			{
				minTLcorn.y = matof(wallVector[i][7]);
			}
			if (matof(wallVector[i][8]) > maxBRcorn.x)
			{
				maxBRcorn.x = matof(wallVector[i][8]);
			}
			if (matof(wallVector[i][9]) > maxBRcorn.y)
			{
				maxBRcorn.y = matof(wallVector[i][9]);
			}

		}
	}

	boundingBox = AARectHitBox(minTLcorn, maxBRcorn);


	for (int i = 0; i < playerSpawns.size(); i++)
	{
		tankSpawnPoints.push_back(sf::Vector2f(matof(playerSpawns[i][0]), matof(playerSpawns[i][1])));

	}

	for (int i = 0; i < upgradeSpawns.size(); i++)
	{
		upgradeSpawnPoints.push_back(sf::Vector2f(matof(upgradeSpawns[i][0]), matof(upgradeSpawns[i][1])));

	}


	if (BGVector[0][0] == "THREE_ARG")
	{
		bgSprite = AppSprite(	fresourceGroup->getTexturePointer(BGVector[0][10]),
								sf::Vector2f(matof(BGVector[0][3]), matof(BGVector[0][4])),
								sf::Vector2f(matof(BGVector[0][1]), matof(BGVector[0][2])),
								0);
	}
	else if (BGVector[0][0] == "TWO_ARG")
	{
		bgSprite = AppSprite(	fresourceGroup->getTexturePointer(BGVector[0][10]),
								sf::Vector2f(matof(BGVector[0][1]), matof(BGVector[0][2])),
								sf::Vector2f(matof(BGVector[0][3]), matof(BGVector[0][4])));
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


void GameMap::draw(sf::RenderWindow& frenderWindow, sf::Vector2f drawPosition)
{

	sf::CircleShape testor;
	testor.setRadius(3);
	testor.setOrigin(1.5, 1.5);
	testor.setFillColor(sf::Color::Red);

	bgSprite.draw(frenderWindow, drawPosition);

	for (int i = 0; i < wallSprites.size(); i++)
	{
		wallSprites[i].draw(frenderWindow, drawPosition);
		

		for (int j = 0; j < 4; j++)
		{
			testor.setPosition((((AARectHitBox*)(hitboxvec.getHitBox(i)))->getCorner(j)));
			frenderWindow.draw(testor);
		}
	}

}



void GameMap::reset()
{
	wallSprites.clear();
	tankSpawnPoints.clear();
	upgradeSpawnPoints.clear();
	hitboxvec.clearVector();
}



void GameMap::readSpriteTuple(std::string ftupleLine, std::vector<std::string>& vectbfilled)
{
	if (!vectbfilled.size())
	{
		bool inTuple = false;
		
		bool inSet = false;

		bool inOP = false;
		
		bool wasFirstOP = false;

		bool firstSet = true;

		bool lastWasNum = true;

		bool decidedArg = false;


		std::string character;


		std::string number = "";

		
		for (int i = 0; i < ftupleLine.size(); i++)
		{
			character = ftupleLine[i];
			if (character != " ")
			{
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
										vectbfilled.push_back("TWO_ARG");
										decidedArg = true;
									}

								}
								else
								{
									if (wasFirstOP)
									{
										if (!decidedArg)
										{
											vectbfilled.push_back("THREE_ARG");
											decidedArg = true;
										}
										
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
												decidedArg = false;
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
									else
									{
										lastWasNum = true;
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
}

void GameMap::readOrderedPair(std::string fopLine, std::vector<std::string>& vectbfilled)
{
	if (!vectbfilled.size())
	{
		bool inOP;
		
		std::string character = "";
		
		std::string number = "";
		
		for (int i = 0; i < fopLine.size(); i++)
		{
			character = fopLine[i];
			if (character != " ")
			{
				if (character == "(")
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
}

float GameMap::matof(std::string str)
{
	float returnme = 0.0;
	std::stringstream ss;
	ss << str;
	ss >> returnme;
	return returnme;
}