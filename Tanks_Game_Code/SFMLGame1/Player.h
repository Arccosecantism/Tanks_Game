#pragma once
#include "SFMLbase.h"

class Player
{
public:
	Player();
	~Player();

	void update(std::vector<int> fkeyVec);

	void draw();


private:

	void resetVelocities();

	sf::Sprite tankSprite;



	sf::Vector2f position;

	sf::Vector2f forVelocity;
	sf::Vector2f bacVelocity;

	double forSpeed;
	double bacSpeed;
	double rotSpeed;



	double rotation;

	

};

