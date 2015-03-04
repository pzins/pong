#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "player.h"
#include "ball.h"
#include <iostream>

class Bonus
{
private:
	sf::Color color_;
	float x_;
	float y_;
	float radius_;
	float duree_;
	float startTime_;
	Player* owner_;
	bool state_;

public:

	Bonus(sf::Color c, float x, float y, float radius, float duree);
	virtual ~Bonus();

	sf::CircleShape computeBonus();
	virtual void apply(Ball* b)=0;
	virtual void disable(Ball* b)=0;



	sf::Color getColor(){return color_;}
	int getX(){return x_;}
	int getY(){return y_;}
	float getRadius(){return radius_;}
	float getDuree(){return duree_;}
	float getStartTime(){return startTime_;}
	Player* getOwner(){return owner_;}
	bool getState(){return state_;}

	void setColor(sf::Color c){color_ = c;}
	void setX(float x){x_ = x;}
	void setY(float y){y_ = y;}
	void setRadius(float r){radius_ = r;}
	void setDuree(float d){duree_ = d;}
	void setStartTime(float s){startTime_ = s;}
	void setOwner(Player* p){owner_ = p;}
	void setState(bool s){state_ = s;}
};


#endif