#pragma once
#include "MenuElement.h"

class SingleTextBox : public MenuElement									//This class is simply text on the screen that has been wrapped a bit																	
{
public:
	SingleTextBox();
	SingleTextBox(sf::Vector2f fposition, sf::Font* ffont, std::string fstring, int ffontsize, double fmaxwidth, sf::Color fcolor);
	~SingleTextBox();
	
	void setup(sf::Vector2f fposition, sf::Font* ffont, std::string fstring, int ffontsize, double fmaxwidth, sf::Color fcolor);



	void update();

	void update(MouseData& fmouseData);

	void draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition);

	void resetMD();



	void setTextString(std::string fstring);

	void setTextColor(sf::Color fcolor);

	void setFontSize(int fsize);

private:

	std::string wrapText();

	void resetSize();

	sf::Vector2f getDimensionsOfString(std::string fstr);

	void correctPosition();


	sf::Text textBody;
	sf::Color textColor;
	std::string drawString;
	int characterSize;
	double width;

};

