#ifndef LENGTHBONUS_H_INCLUDED
#define LENGTHBONUS_H_INCLUDED
#include "bonus.h"
#include "ball.h"
#include <iostream>

class LengthBonus : public Bonus
{
private:
	float coeff_;
    LengthBonus(const LengthBonus& b);


public:

	LengthBonus(sf::Color color, float x, float y, float radius, float duree, float coeff);
	~LengthBonus();

	virtual void apply(Ball* b);
	virtual void disable(Ball* b);
	void setCoeff(float c){coeff_ = c;}
	float getCoeff(){return coeff_;}

};


#endif