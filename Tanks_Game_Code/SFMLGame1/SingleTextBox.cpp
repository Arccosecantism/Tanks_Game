#include "SingleTextBox.h"


SingleTextBox::SingleTextBox(sf::Vector2f fposition, sf::Font* ffont, std::string fstring, int ffontsize, double fmaxwidth, sf::Color fcolor)
{
	requiresMouseData = false;

	isHidden = false;

	resetsOnMD = false;



	position = fposition;

	characterSize = ffontsize;



	sf::Vector2f tempDimensions;


	textBody.setFont(*ffont);

	textBody.setString(fstring);

	textBody.setColor(fcolor);


	tempDimensions = sf::Vector2f(textBody.getLocalBounds().width, textBody.getLocalBounds().height);

	textBody.setOrigin(tempDimensions.x / 2, tempDimensions.y / 2);

	textBody.setScale(textSize.x / tempDimensions.x, textSize.y / tempDimensions.y);

	textBody.setPosition(0, 0);

}


SingleTextBox::~SingleTextBox()
{
}


void SingleTextBox::update()
{ 

}


void SingleTextBox::update(MouseData& fmouseData)
{

}


void SingleTextBox::draw(sf::RenderWindow& frenderwindow, sf::Vector2f drawPosition)
{
	position += drawPosition;

	textBody.move(position);

	frenderwindow.draw(textBody);

	textBody.move(-position);

	position -= drawPosition;
}


void SingleTextBox::resetMD()
{

}


void SingleTextBox::setTextString(std::string fstring)
{
	textBody.setString(fstring);
	resetSize();
}

void SingleTextBox::setTextColor(sf::Color fcolor)
{
	textBody.setColor(fcolor);
}

void SingleTextBox::setTextSize(sf::Vector2f fsize)
{
	textSize = fsize;
	resetSize();
}


//void SingleTextBox::wrapText()
//{
//	sf::Text tmpText;
//	tmpText.setFont(*textBody.getFont());
//
//	std::string tmpString = textBody.getString();
//	tmpText.setString(tmpS)
//
//
//}

//void SingleTextBox::resetSize()
//{
//	sf::Vector2f tempDimensions = sf::Vector2f(textBody.getGlobalBounds().width, textBody.getGlobalBounds().height);
//	textBody.setScale(textSize.x / tempDimensions.x, textSize.y / tempDimensions.y);
//}
std::string SingleTextBox::wrapText()
{
	char letter;
	std::string word = "";
	std::string line = "";
	std::string transline = "";
	std::string rtstr = "";
	bool notFirstWord = false;

	for (unsigned int i = 0; i <= drawString.size(); i++)
	{
		if (i = drawString.size)
		{

		}
		letter = drawString[i];
		if (letter == ' ')
		{



			if (notFirstWord)
			{
				transline += ' ';
			}

			transline += word;
			

			if (getWidthOfString(transline) > width)
			{
				rtstr += line;
				rtstr += "\n";
				notFirstWord = false;
			}
			else
			{
				line = transline;

			}

			notFirstWord = true;
			word = "";

			

			
		}
		else
		{
			word += letter;
		}

	}
}


double SingleTextBox::getWidthOfString(std::string fstr)
{

	sf::Text tmpText;
	tmpText.setFont(*textBody.getFont());
	tmpText.setCharacterSize(characterSize);
	tmpText.setString(fstr);
	return tmpText.getGlobalBounds().width;

}