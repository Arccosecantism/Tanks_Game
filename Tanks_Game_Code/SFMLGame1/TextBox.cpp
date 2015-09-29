#include "TextBox.h"


TextBox::TextBox(sf::Vector2f fposition, sf::Font* ffont, std::string fstring, sf::Vector2f fsize, sf::Color fcolor)
{

	requiresMouseData = false;

	isHidden = false;

	resetsOnMD = false;


	
	position = fposition

	textSize = fsize;



	sf::Vector2f tempDimensions;


	textBody.setFont(*ffont);

	textBody.setString(fstring);

	textBody.setColor(fcolor);

	
	tempDimensions = sf::Vector2f(textBody.getLocalBounds().width, textBody.getLocalBounds().height);

	textBody.setOrigin(tempDimensions.x / 2, tempDimensions.y / 2);

	textBody.setScale(textSize.x / tempDimensions.x, textSize.y / tempDimensions.y);

	textBody.setPosition(0,0);


}


TextBox::~TextBox()
{

}


void TextBox::update()
{

}


void TextBox::update(MouseData& fmouseData)
{

}


void TextBox::draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition)
{
	position += drawPosition;
}


void TextBox::resetMD()
{

}