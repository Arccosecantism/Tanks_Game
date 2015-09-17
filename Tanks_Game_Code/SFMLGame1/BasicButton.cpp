#include "BasicButton.h"


BasicButton::BasicButton()
{
}

void BasicButton::update()
{
	


}


void BasicButton::update(MouseData& fmouseData);
void BasicButton::draw(sf::RenderWindow& frenderWindow);
void BasicButton::setTextures(ResourceGroup& rgroup);
int BasicButton::getButtonState();