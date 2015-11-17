#include "Game.h"


Game::Game()
{
	activity = true;
}


Game::~Game()
{

}

void Game::setup(ResourceManager& fresourceManager)
{
	gameResources = &fresourceManager;

	player1.setup(AppSprite(gameResources->getTexturePointerByName("DefaultTank"), sf::Vector2f(0, 0), sf::Vector2f(50, 50), 0), sf::Vector2f(400, 200));
}

void Game::setupLevel(std::string fileName, std::string rgname)
{
	level.loadFromFile(fileName, gameResources->getResourceSetByName(rgname));
	resetCollisionManager();
}

void Game::update(std::vector<int>& fkeyVec)
{
	player1.update(fkeyVec);
	gameCollisionManager.checkCollision();
}

void Game::draw(sf::RenderWindow& frenderWindow)
{
	
	level.draw(frenderWindow, sf::Vector2f(0, 0));
	player1.draw(frenderWindow);
}

void Game::resetCollisionManager()
{
	gameCollisionManager.clear();
	gameCollisionManager.addCollidable(&player1);
	gameCollisionManager.addCollidable(&level);
}