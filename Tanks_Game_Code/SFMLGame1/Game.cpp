#include "Game.h"


Game::Game()
{
}


Game::~Game()
{

}

void Game::setup(ResourceManager& fresourceManager)
{
	gameResources = &fresourceManager;

	player1.setup(AppSprite(gameResources->getTexturePointerByName("DefaultTank"), sf::Vector2f(0, 0), sf::Vector2f(50, 50), 0), sf::Vector2f(400, 300));
}

void Game::setupLevel(std::string fileName, std::string rgname)
{
	level.loadFromFile(fileName, gameResources->getResourceSetByName(rgname));
}

void Game::update(std::vector<int>& fkeyVec)
{
	player1.update(fkeyVec);
}

void Game::draw(sf::RenderWindow& frenderWindow)
{

}

void Game::resetCollisionManager()
{
	Collidable* tmp = &level;
	gameCollisionManager.clear();

	gameCollisionManager.addCollidable(&player1);
	gameCollisionManager.addCollidable(&level);
}