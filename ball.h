#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include <SFML/Graphics.hpp>


class Ball
{
private:
	float x_;
	float y_;
	float radius_;
	float speedX_;
	float speedY_;
	sf::Color color_;
	int lastPlayer_; //1 : Human, 2 : Computer


public:
	Ball(float x, float y, float r, sf::Color c, float speedInitX, float speedInitY);
	~Ball();

	sf::CircleShape computeBall();

	void setX(float x){x_ = x;}
	void setY(float y){y_ = y;}
	void setRadius(float r){radius_ = r;}
	void setColor(sf::Color c){color_ = c;}
	void setSpeedX(float x){speedX_ = x;}
	void setSpeedY(float y){speedY_ = y;}
	void setLastPlayer(int l){lastPlayer_ = l;}

	float getX(){return x_;}
	float getY(){return y_;}
	float getRadius(){return radius_;}
	sf::Color getColor(){return color_;}
	float getSpeedX(){return speedX_;}
	float getSpeedY(){return speedY_;}
	int getLastPlayer(){return lastPlayer_;}
};

























#endif 