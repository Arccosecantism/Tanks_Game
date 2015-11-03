#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::update(std::vector<int> fkeyVec)
{
	for (unsigned int i = 0; i < fkeyVec.size(); i++)
	{
		if (static_cast<sf::Keyboard::Key>(fkeyVec[i]) == sf::Keyboard::Up)
		{
			position += forVelocity;
		}
		else if (static_cast<sf::Keyboard::Key>(fkeyVec[i]) == sf::Keyboard::Down)
		{
			position += bacVelocity;
		}
		else if (static_cast<sf::Keyboard::Key>(fkeyVec[i]) == sf::Keyboard::Right)
		{
			rotation += rotSpeed;
		}
		else if (static_cast<sf::Keyboard::Key>(fkeyVec[i]) == sf::Keyboard::Left)
		{
			rotation -= rotSpeed;
		}
	}
}

void Player::resetVelocities()
{
	forVelocity = forSpeed * +
}