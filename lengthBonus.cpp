#include "lengthBonus.h"
#include <iostream>

LengthBonus::LengthBonus(sf::Color color, float x, float y, float radius, float duree, float coeff) 
: Bonus(color, x, y, radius, duree), coeff_(coeff)
{
}

LengthBonus::~LengthBonus()
{

}

void LengthBonus::apply(Ball* b)
{
	getOwner()->setLength(getOwner()->getLength() * coeff_);
}

void LengthBonus::disable(Ball* b)
{
	getOwner()->setLength(getOwner()->getLength() / coeff_);
}