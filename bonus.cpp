#include "bonus.h"
#include <iostream>

Bonus::Bonus(sf::Color color, float x, float y, float radius, float duree)
 : color_(color), x_(x), y_(y), radius_(radius), duree_(duree), startTime_(0), state_(true)
{
	owner_ = NULL;
}

Bonus::~Bonus()
{

}

sf::CircleShape Bonus::computeBonus()
{
	sf::CircleShape bonus(getRadius());
	bonus.setFillColor(getColor());
	bonus.setPosition(getX(), getY());
	bonus.setOutlineThickness(getRadius() * 0.1);
	bonus.setOutlineColor(sf::Color(0, 0, 0, 150));

	return bonus;
}


