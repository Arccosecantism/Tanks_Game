#pragma once
#include "SFMLbase.h"
#include "AppSprite.h"
#include "Collidable.h"

class Player : public Collidable
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


	void setInCollision(bool b);


	void update(std::vector<int>& fkeyVec);




	void draw(sf::RenderWindow& frenderwindow);


	void collideWithWall();


private:

	void incMovement();

	void unincMovement();

	void resetVelocities();

	AppSprite tankSprite;



	sf::Vector2f position;

	sf::Vector2f forVelocity;
	sf::Vector2f bacVelocity;

	double forSpeed;
	double bacSpeed;
	double rotSpeed;



	double rotation;

	std::vector<int> lastKeyVec;

};

