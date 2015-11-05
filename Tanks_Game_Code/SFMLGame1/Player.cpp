#include "Player.h"


Player::Player()
{
	position = sf::Vector2f(0,0);
}

Player::Player(AppSprite& fappSprite, sf::Vector2f fpos)
{
	setup(fappSprite, fpos);
}


Player::~Player()
{

}

void Player::setup(AppSprite& fappSprite, sf::Vector2f fpos)
{
	position = fpos;

	tankSprite = fappSprite;
	rotation = 0;
	forSpeed = 3.0;
	bacSpeed = 2.0;
	rotSpeed = 2.5;
	resetVelocities();
}

void Player::move(sf::Vector2f fdisp)
{
	position += fdisp;
	//tankSprite.move(fdisp);
}

void Player::setPosition(sf::Vector2f fpos)
{
	position = fpos;
	//tankSprite.setPosition(fpos);
}


void Player::rotate(double frot)
{
	rotation += frot;
	tankSprite.rotate(frot);
	resetVelocities();
}

void Player::setRotation(double frot)
{
	rotation = frot;
	tankSprite.setRotation(frot);
	resetVelocities();
}


void Player::update(std::vector<int>& fkeyVec)
{
	for (unsigned int i = 0; i < fkeyVec.size(); i++)
	{
		if (static_cast<sf::Keyboard::Key>(fkeyVec[i]) == sf::Keyboard::Up)
		{
			move(forVelocity);
		}
		else if (static_cast<sf::Keyboard::Key>(fkeyVec[i]) == sf::Keyboard::Down)
		{
			move(bacVelocity);
		}
		else if (static_cast<sf::Keyboard::Key>(fkeyVec[i]) == sf::Keyboard::Right)
		{
			rotate(rotSpeed);
		}
		else if (static_cast<sf::Keyboard::Key>(fkeyVec[i]) == sf::Keyboard::Left)
		{
			rotate(-rotSpeed);
		}
	}
}

void Player::draw(sf::RenderWindow& frenderwindow)
{
	tankSprite.draw(frenderwindow, position);
}


void Player::resetVelocities()
{

	double pi = 3.1415926525898;

	forVelocity = sf::Vector2f(forSpeed * cos(pi / 180 * rotation - pi / 2), forSpeed * sin(pi / 180 * rotation - pi / 2));

	bacVelocity = sf::Vector2f(bacSpeed * cos(pi / 2 + pi / 180 * rotation), bacSpeed * sin(pi / 2 + pi / 180 * rotation));

}