#include "SingleTextBox.h"

SingleTextBox::SingleTextBox()
{
	requiresMouseData = false;

	isHidden = false;

	resetsOnMD = false;


}

SingleTextBox::SingleTextBox(sf::Vector2f fposition, sf::Font* ffont, std::string fstring, int ffontsize, double fmaxwidth, sf::Color fcolor)
{
	requiresMouseData = false;

	isHidden = false;

	resetsOnMD = false;

	setup(fposition, ffont, fstring, ffontsize, fmaxwidth, fcolor);


}


SingleTextBox::~SingleTextBox()
{
}


void SingleTextBox::setup(sf::Vector2f fposition, sf::Font* ffont, std::string fstring, int ffontsize, double fmaxwidth, sf::Color fcolor)
{

	position = fposition;

	characterSize = ffontsize;

	textColor = fcolor;

	width = fmaxwidth;

	drawString = fstring;



	sf::Vector2f tempDimensions;


	textBody.setFont(*ffont);

	textBody.setString(fstring);

	textBody.setCharacterSize(ffontsize);

	textBody.setString(wrapText());

	textBody.setColor(fcolor);


	tempDimensions = sf::Vector2f(textBody.getLocalBounds().width, textBody.getLocalBounds().height);

	textBody.setOrigin(tempDimensions.x / 2, tempDimensions.y / 2);

	textBody.setPosition(0,0);

	correctPosition();

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
	textBody.setString(wrapText());
}

void SingleTextBox::setTextColor(sf::Color fcolor)
{
	textBody.setColor(fcolor);
}

void SingleTextBox::setFontSize(int fsize)
{
	textBody.setCharacterSize(fsize);
	textBody.setString(wrapText());
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
	std::string searchString;
	for (unsigned int i = 0; i < drawString.size(); i++)
	{
		searchString = drawString[i];
		if (searchString == "\n")
		{
			drawString[i] = ' ';
		}
	}


	

	int spaceIndex;
	char letter;
	std::string word = "";
	std::string line = "";
	std::string transline = "";
	std::string rtstr = "";
	bool notFirstWord = false;
	bool notFirstLine = false;

	for (unsigned int i = 0; i <= drawString.size(); i++)
	{

		if (i == drawString.size())
		{
			letter = ' ';
		}
		else
		{
			letter = drawString[i];
		}
		


		if (letter == ' ')
		{
			if (notFirstWord)
			{
				transline += ' ';
			}

			transline += word;

			if (getDimensionsOfString(transline).x > width)
			{
				if (notFirstLine)
				{
					rtstr += "\n";
				}

				rtstr += line;

				notFirstWord = false;
				notFirstLine = true;

				line = "";
				transline = "";

				i = spaceIndex;
	
			}

			else
			{
				line = transline;
				notFirstWord = true;
				spaceIndex = i;

				if (i == drawString.size())
				{

					if (notFirstLine)
					{
						rtstr += "\n";
					}

					rtstr += line;
				}

			}
			
			word = "";
	
		}

		else
		{
			word += letter;
		}

	}

	return rtstr;
}


sf::Vector2f SingleTextBox::getDimensionsOfString(std::string fstr)
{

	sf::Text tmpText;
	tmpText.setFont(*textBody.getFont());
	tmpText.setCharacterSize(characterSize);
	tmpText.setString(fstr);
	return sf::Vector2f(tmpText.getGlobalBounds().width, tmpText.getGlobalBounds().height);

}

void SingleTextBox::correctPosition()
{
	double maxHeight = 0;
	std::string tmpString;
	for (unsigned int i = 0; i < drawString.size(); i++)
	{
		tmpString = drawString[i];
		if (tmpString == "\n")
		{
			break;
		}
		else if (getDimensionsOfString(tmpString).y > maxHeight)
		{
			maxHeight = getDimensionsOfString(tmpString).y;
		}
	}
	textBody.move(sf::Vector2f(0, - maxHeight / 2));
}