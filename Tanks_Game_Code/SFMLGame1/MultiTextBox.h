#pragma once
#include "SingleTextBox.h"


class MultiTextBox : public MenuElement, public NameSearchable
{
public:
	MultiTextBox();

	~MultiTextBox();



	void update();

	void update(MouseData& fmouseData);

	void draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition);

	void resetMD();



	void setCurrentTextBoxByName(std::string fname);

	void addTextBox(SingleTextBox fsingleTextBox, std::string fname);
	
	SingleTextBox* getTextBoxPointerByName(std::string fname);



private:

	
	std::vector<SingleTextBox> textBoxVector;


};

