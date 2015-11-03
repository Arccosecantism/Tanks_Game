#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::move(sf::Vector2f fdisp)
{
	position += fdisp;
	tankSprite.move(fdisp);
}

void Player::setPosition(sf::Vector2f fpos)
{
	position = fpos;
	tankSprite.setPosition(fpos);
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


void Player::update(std::vector<int> fkeyVec)
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

void Player::resetVelocities()
{

	double pi = 3.1415926525898;

	forVelocity = sf::Vector2f(forSpeed * cos(rotation - pi / 2), forSpeed * sin(rotation - pi / 2));

	bacVelocity = sf::Vector2f(bacSpeed * cos(pi / 2 + rotation), bacSpeed * sin(pi / 2 + rotation));

}