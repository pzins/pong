#ifndef SPEEDBALLBONUS_H_INCLUDED
#define SPEEDBALLBONUS_H_INCLUDED
#include "bonus.h"
#include "ball.h"
#include <iostream>

class SpeedBallBonus : public Bonus
{
private:
	float coeff_;
    SpeedBallBonus(const SpeedBallBonus& b);


public:

	SpeedBallBonus(sf::Color color, float x, float y, float radius, float duree, float coeff);
	~SpeedBallBonus();

	virtual void apply(Ball* b);
	virtual void disable(Ball* b);
	void setCoeff(float c){coeff_ = c;}
	float getCoeff(){return coeff_;}

};


#endif