#include "speedBonus.h"
#include <iostream>

SpeedBonus::SpeedBonus(sf::Color color, float x, float y, float radius, float duree, float coeff) 
: Bonus(color, x, y, radius, duree), coeff_(coeff)
{
}

SpeedBonus::~SpeedBonus()
{

}

void SpeedBonus::apply(Ball* b)
{
	getOwner()->setSpeed(getOwner()->getSpeed() * coeff_);
}

void SpeedBonus::disable(Ball* b)
{
	getOwner()->setSpeed(getOwner()->getSpeed() / coeff_);
}