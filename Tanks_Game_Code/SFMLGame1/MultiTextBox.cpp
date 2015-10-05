#include "MultiTextBox.h"


MultiTextBox::MultiTextBox()
{
	setVectorSize(1);

	requiresMouseData = false;

	isHidden = false;

	resetsOnMD = false;
}


MultiTextBox::~MultiTextBox()
{

}


void MultiTextBox::update()
{
	for (unsigned int i = 0; i < textBoxVector.size(); i++)
	{
		textBoxVector[i].update();
	}
}


void MultiTextBox::update(MouseData& fmouseData)
{
	for (unsigned int i = 0; i < textBoxVector.size(); i++)
	{
		textBoxVector[i].update(fmouseData);
	}
}


void MultiTextBox::draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition)
{
	position += drawPosition;

	for (unsigned int i = 0; i < textBoxVector.size(); i++)
	{
		textBoxVector[i].draw(frenderwindow, position);
	}

	position -= drawPosition;
}


void MultiTextBox::resetMD()
{

}


void MultiTextBox::setCurrentTextBoxByName(std::string fname)
{
	for (unsigned int i = 0; i < textBoxVector.size(); i++)
	{
		textBoxVector[i].hide();
	}
	textBoxVector[ntoi(fname)].unhide();
}


void MultiTextBox::addTextBox(SingleTextBox fsingleTextBox, std::string fname)
{
	fsingleTextBox.hide();
	textBoxVector.push_back(fsingleTextBox);
	addName(fname, textBoxVector.size() - 1);
}


SingleTextBox* MultiTextBox::getTextBoxPointerByName(std::string fname)
{
	SingleTextBox* tmpTextBox = &textBoxVector[ntoi(fname)];
	return tmpTextBox;
}
