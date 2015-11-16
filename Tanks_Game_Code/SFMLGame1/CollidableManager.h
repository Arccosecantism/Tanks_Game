#pragma once
#include "Player.h"
#include "GameMap.h"

class CollidableManager
{
public:
	CollidableManager();
	~CollidableManager();
	void addCollidable(Collidable& fcol);
	void addCollidable(Collidable* fcol);
	void checkCollision();
	void clear();

private:

	void interpretCollisions(int& i, int& j);


	bool checkAABBCollision(AARectHitBox aabb1, AARectHitBox aabb2);
	bool checkMotion(int& i, int& j);
	std::vector<Collidable*> collidables;
};

