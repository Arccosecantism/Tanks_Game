#pragma once
#include "MenuElement.h"

class TextBox : public MenuElement
{
public:
	TextBox(sf::Vector2f fposition, sf::Font* ffont, std::string fstring, sf::Vector2f fsize, sf::Color fcolor);

	~TextBox();



	void update();

	void update(MouseData& fmouseData);

	void draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition);

	void resetMD();



private:

	sf::Text textBody;
	sf::Vector2f textSize;
};

