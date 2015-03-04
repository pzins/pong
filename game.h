#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
#include "player.h"
#include "ball.h"
#include "bonus.h"

class Game
{
private:
	Player* human_;
	Player* computer_;
	sf::RectangleShape field_;
	int width_;
	int height_;
	sf::Color color_;
	int level_;
	Player* lastTouch_; //1: Human, 2: Computer
	std::vector<Bonus*> vectBonus_;



public:
    sf::RenderWindow app;


	Game(int w, int h, sf::Color c, Player* p1, Player* p2);
	~Game();

	void addBonus(Bonus* b);
	void hitBonus(int i);


	sf::RectangleShape getField(){return field_;}
	Player* getHuman(){return human_;}
	Player* getComputer(){return computer_;}
	int getWidth(){return width_;}
	int getHeight(){return height_;}
	int getLevel(){return level_;}
	Player* getLastTouch(){return lastTouch_;}
	std::vector<Bonus*> getVectBonus(){return vectBonus_;}


	void setLevel(int l){level_ = l;}
	void setLastTouch(Player* l){lastTouch_ = l;}

	void resetBonus(){vectBonus_.clear();}

	void moveHuman(int c);
	void moveComputer(Ball* b);
	void restart(Ball* ball);
	void moveBall(Ball* ball);



};

























#endif 