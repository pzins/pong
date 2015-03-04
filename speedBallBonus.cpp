#include "speedBallBonus.h"
#include <iostream>

SpeedBallBonus::SpeedBallBonus(sf::Color color, float x, float y, float radius, float duree, float coeff) 
: Bonus(color, x, y, radius, duree), coeff_(coeff)
{
}

SpeedBallBonus::~SpeedBallBonus()
{

}

void SpeedBallBonus::apply(Ball* b)
{
	b->setSpeedX(b->getSpeedX() * getCoeff());
	b->setSpeedY(b->getSpeedY() * getCoeff());
}

void SpeedBallBonus::disable(Ball* b)
{
	b->setSpeedX(b->getSpeedX() / getCoeff());
}