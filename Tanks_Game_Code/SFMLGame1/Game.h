#pragma once
#include "CollidableManager.h"
class Game
{
public:
	Game();
	~Game();

	void setup(ResourceManager& fresourceManager);

	void setupLevel(std::string fileName, std::string rgname);

	void update(std::vector<int>& fkeyVec);

	void draw(sf::RenderWindow& frenderWindow);

private:


	void resetCollisionManager();

	Player player1;

	GameMap level;

	CollidableManager gameCollisionManager;

	ResourceManager* gameResources;


};

