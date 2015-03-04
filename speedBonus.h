#ifndef SPEEDBONUS_H_INCLUDED
#define SPEEDBONUS_H_INCLUDED
#include "bonus.h"
#include <iostream>

class SpeedBonus : public Bonus
{
private:
	float coeff_;
    SpeedBonus(const SpeedBonus& b);


public:

	SpeedBonus(sf::Color color, float x, float y, float radius, float duree, float coeff);
	~SpeedBonus();

	virtual void apply(Ball* b);
	virtual void disable(Ball* b);
	void setCoeff(float c){coeff_ = c;}
	float getCoeff(){return coeff_;}

};


#endif