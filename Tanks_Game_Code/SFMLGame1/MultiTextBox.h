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


	void addTextBox(SingleTextBox fsingleTextBox, std::string fname);

	SingleTextBox* getTextBoxPointerByName(std::string fname);



private:

	
	std::vector<SingleTextBox> textBoxVector;
	std::map<std::string, int> nameMap;

};

