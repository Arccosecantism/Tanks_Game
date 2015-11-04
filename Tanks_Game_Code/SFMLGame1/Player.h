#pragma once
#include "SFMLbase.h"
#include "AppSprite.h"

class Player
{
public:
	Player();
	Player(AppSprite& fappSprite, sf::Vector2f fpos);
	~Player();

	void setup(AppSprite& fappSprite, sf::Vector2f fpos);

	void move(sf::Vector2f fdisp);

	void setPosition(sf::Vector2f fpos);



	void rotate(double frot);

	void setRotation(double frot);



	void update(std::vector<int>& fkeyVec);

	void draw(sf::RenderWindow& frenderwindow);


private:

	void resetVelocities();

	AppSprite tankSprite;



	sf::Vector2f position;

	sf::Vector2f forVelocity;
	sf::Vector2f bacVelocity;

	double forSpeed;
	double bacSpeed;
	double rotSpeed;



	double rotation;

	

};

