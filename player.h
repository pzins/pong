#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <vector>

class Bonus;

class Player
{
private:
	int points_;
	float length_;
	float height_;
	float speed_;
	sf::Color color_;
	float x_;
	float y_;
	float posIni_;




public:

	Player(int points, float length, float height, float speed, sf::Color color, float x, float y);
	~Player();


	sf::RectangleShape computeBase();



	int getPoints(){return points_;}
	float getLength(){return length_;}
	float getSpeed(){return speed_;}
	sf::Color getColor(){return color_;}
	float getX(){return x_;}
	float getY(){return y_;}
	float getHeight(){return height_;}
	float getPosIni(){return posIni_;}

	void setPoints(int a){points_ = a;}
	void setLength(float a){length_ = a;}
	void setSpeed(float a){speed_ = a;}
	void setColor(sf::Color c){color_ = c;}
	void setX(float x){x_ = x;}
	void setY(float y){y_ = y;}
	void setHeight(float h){height_ = h;}



};




















#endif