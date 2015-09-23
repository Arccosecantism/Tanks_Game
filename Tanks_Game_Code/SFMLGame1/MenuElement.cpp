#include "MenuElement.h"


sf::Vector2f MenuElement::getPosition()
{
	return position;
}

void MenuElement::setPosition(sf::Vector2f fpos)
{
	position = fpos;
}

void MenuElement::move(sf::Vector2f velocity)
{
	position += velocity;
}