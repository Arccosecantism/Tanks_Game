#pragma once
#include "Player.h"
#include "GameMap.h"

class CollidableManager
{
public:
	CollidableManager();
	~CollidableManager();
	void addCollidabe(Collidable& fcol);
	void addCollidabe(Collidable* fcol);
	void checkCollision();

private:

	void interpretCollisions(int& i, int& j);
	void tankWallCollision(int& i, int& j);
	void tankTankCollision(int& i, int& j);

	bool checkAABBCollision(AARectHitBox aabb1, AARectHitBox aabb2);
	bool checkMotion(int& i, int& j);
	std::vector<Collidable*> collidables;
};

