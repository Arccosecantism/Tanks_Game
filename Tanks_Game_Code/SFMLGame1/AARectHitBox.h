#pragma once
#include "GeneralHitBox.h"

class AARectHitBox : public GeneralHitBox
{
public:
	AARectHitBox();

	AARectHitBox(double fwidth, double fheight, sf::Vector2f fpos);

	AARectHitBox(sf::Vector2f fTLCorner, sf::Vector2f fBRCorner);


	void setup(double fwidth, double fheight, sf::Vector2f fpos);

	void setup(sf::Vector2f fTLCorner, sf::Vector2f fBRCorner);

	~AARectHitBox();




	void move(sf::Vector2f fdisp);

	void setPosition(sf::Vector2f fpos);



	sf::Vector2f getCorner(int findex);

	sf::Vector2f getPosition();

	double getWidth();

	double getHeight();

	

private:

	double width;
	double height;
	sf::Vector2f position;
	sf::Vector2f corners[4];
};

