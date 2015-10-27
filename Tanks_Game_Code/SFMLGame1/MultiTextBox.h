#pragma once
#include "SingleTextBox.h"


class MultiTextBox : public MenuElement, public NameSearchable				//a named collection of textboxes -- useful for changing text
{
public:

	MultiTextBox();															//constructor

	~MultiTextBox();														//destructor
		

	//inherited virtual
	void update();

	void update(MouseData& fmouseData);

	void draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition);

	void resetMD();



	void setCurrentTextBoxByName(std::string fname);						//set the textbox being drawn -- can only draw one at a time

	void addTextBox(SingleTextBox fsingleTextBox, std::string fname);		//adds a textbox to the collection
	
	SingleTextBox* getTextBoxPointerByName(std::string fname);				//returns a pointer to a textbox by name



private:

	
	std::vector<SingleTextBox> textBoxVector;								//the collection of textboxes


};

