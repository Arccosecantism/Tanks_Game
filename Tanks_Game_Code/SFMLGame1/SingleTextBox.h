#pragma once
#include "MenuElement.h"

class SingleTextBox : public MenuElement
{
public:
	SingleTextBox(sf::Vector2f fposition, sf::Font* ffont, std::string fstring, int ffontsize, double fmaxwidth, sf::Color fcolor);
	~SingleTextBox();

	void update();

	void update(MouseData& fmouseData);

	void draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition);

	void resetMD();



	void setTextString(std::string fstring);

	void setTextColor(sf::Color fcolor);

	void setTextSize(sf::Vector2f fsize);

private:

	std::string wrapText();
	void resetSize();
	double getWidthOfString(std::string fstr);

	sf::Text textBody;
	sf::Color textColor;
	std::string drawString;
	int characterSize;
	double width;

};

