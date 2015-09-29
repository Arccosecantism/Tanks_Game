#pragma once
#include "MenuElement.h"

class SingleTextBox : public MenuElement
{
public:
	SingleTextBox(sf::Vector2f fposition, sf::Font* ffont, std::string fstring, sf::Vector2f fsize, sf::Color fcolor, sf::String fname);
	~SingleTextBox();

	void update();

	void update(MouseData& fmouseData);

	void draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition);

	void resetMD();



	void setTextString(std::string fstring);

	void setTextColor(sf::Color fcolor);

	void setTextSize(sf::Vector2f fsize);

private:

	void resetSizeByName(int findex);

	sf::Text textBody;
	sf::Color textColor;
	sf::Vector2f textSize;

};

