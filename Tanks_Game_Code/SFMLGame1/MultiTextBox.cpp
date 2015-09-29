#include "MultiTextBox.h"


MultiTextBox::MultiTextBox(sf::Vector2f fposition, sf::Font* ffont, std::string fstring, sf::Vector2f fsize, sf::Color fcolor, std::string fname)
{

	

}


MultiTextBox::~MultiTextBox()
{

}


void MultiTextBox::update()
{

}


void MultiTextBox::update(MouseData& fmouseData)
{

}


void MultiTextBox::draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition)
{
	position += drawPosition;

	textBody.move(position);

	frenderwindow.draw(textBody);

	textBody.move(-position);

	position -= drawPosition;
}


void MultiTextBox::resetMD()
{

}


void MultiTextBox::setTextStringByName(std::string fstring, std::string fname)
{

}

void MultiTextBox::setTextSizeByName(std::string fstring, std::string fname)
{

}

void MultiTextBox::resetSizeByName(int findex)
{
	sf::Vector2f tempDimensions = sf::Vector2f(std::get<0>(textBodyVector.first[findex]).getLocalBounds().width, std::get<0>(textBodyVector.first[findex]).getLocalBounds().width);
	std::get<0>(textBodyVector.first[findex]).setScale(std::get<2>(textBodyVector.first[findex]).x / tempDimensions.x, std::get<2>(textBodyVector.first[findex]).y / tempDimensions.y);
}