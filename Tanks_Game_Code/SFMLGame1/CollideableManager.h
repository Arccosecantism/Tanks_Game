#pragma once
#include "Collidable.h"
class CollideableManager
{
public:
	CollideableManager();
	~CollideableManager();
	void addCollidabe(Collidable& fcol);
	void addCollidabe(Collidable* fcol);
	void checkCollision();

private:

	bool checkAABBCollision(AARectHitBox aabb1, AARectHitBox aabb2);
	bool checkMotion(int& i, int& j);
	std::vector<Collidable*> collidables;
};

