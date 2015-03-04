#include "player.h"



Player::Player(int points, float length, float height, float speed, sf::Color color, float x, float y)
 : points_(points), height_(height), length_(length), speed_(speed), color_(color), x_(x), y_(y), posIni_(x)
{

}

Player::~Player()
{

}

sf::RectangleShape Player::computeBase()
{
	sf::RectangleShape base(sf::Vector2f(length_, height_));
	base.setFillColor(color_);
	base.setPosition(x_,y_);
	return base;
}

