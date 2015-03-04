#include "ball.h"

Ball::Ball(float x, float y, float r, sf::Color c, float speedInitX, float speedInitY) 
: color_(c), x_(x), y_(y), radius_(r), speedX_(speedInitX), speedY_(speedInitY), lastPlayer_(2)
{

}

Ball::~Ball()
{

}

sf::CircleShape Ball::computeBall()
{
	sf::CircleShape ball(radius_);
	ball.setFillColor(color_);
	ball.setPosition(x_, y_);
	return ball;
}
