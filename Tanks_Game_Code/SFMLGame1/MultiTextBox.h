#pragma once
#include "SingleTextBox.h"


class MultiTextBox : public MenuElement
{
public:
	MultiTextBox();

	~MultiTextBox();



	void update();

	void update(MouseData& fmouseData);

	void draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition);

	void resetMD();


	void setTextStringByName(std::string fstring, std::string name);

	void setTextColorByName(sf::Color fcolor, std::string name);

	void setTextSizeByName(sf::Vector2f )


	void addTextBody(std::string fstring, sf::Color fcolor, sf::Vector2f fsize);



private:

	

	std::pair<std::vector<std::tuple<sf::Text, sf::Color, sf::Vector2f>>, std::map<std::string, int>> textBodyVector;

};

