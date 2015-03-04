#include "game.h"


Game::Game(int w, int h, sf::Color c, Player* p1, Player* p2) 
: human_(p1), computer_(p2), app(sf::VideoMode(w, h), "PONG", sf::Style::Default), width_(w), height_(h), level_(0), lastTouch_(0)
{
    app.setPosition(sf::Vector2i(0,0));
    app.setMouseCursorVisible(false);
    field_.setSize(sf::Vector2f(w,h));
    field_.setFillColor(c);
}


Game::~Game()
{

}

void Game::addBonus(Bonus* b)
{
	vectBonus_.push_back(b);
}

void Game::hitBonus(int i)
{
	delete vectBonus_[i];
	vectBonus_.erase(vectBonus_.begin()+i);
}

void Game::moveHuman(int c)
{
    float speed = human_->getSpeed();
    float x = human_->getX();
    if (c == 1)
    {
        speed *= -1;
    }
    float new_x = x + speed;
    if (new_x > width_ - human_->getLength())
    {
        new_x = width_ - human_->getLength();
    }
    else if (new_x < 0)
    {
        new_x = 0;
    }
    human_->setX(new_x);

}

void Game::moveComputer(Ball* ball)
{
	/*
    float speed = computer_->getSpeed();
    float x = computer_->getX();
    if (c == 1)
    {
        speed *= -1;
    }
    float new_x = x + speed;
    if (new_x > width_ - computer_->getLength())
    {
        new_x = width_ - computer_->getLength();
    }
    else if (new_x < 0)
    {
        new_x = 0;
    }
    computer_->setX(new_x);
	*/
	if (ball->getSpeedY() < 0)
	{
		float half = computer_->getLength() / 2;
		if (ball->getX() > computer_->getX() + half && ball->getSpeedX() > 0)
		{
			computer_->setX(computer_->getX() + computer_->getSpeed());
		}
		else if (ball->getX() < computer_->getX() + half && ball->getSpeedX() < 0) computer_->setX(computer_->getX() - computer_->getSpeed());
	}
}


void Game::restart(Ball* ball)
{
    ball->setX(width_ / 2 - ball->getRadius());
    ball->setY(height_ / 2 - ball->getRadius());
    ball->setSpeedX(0);
    ball->setSpeedY(3);
    computer_->setX(computer_->getPosIni());
    human_->setX(human_->getPosIni());
    for (int i = 0; i < vectBonus_.size(); ++i)
    {
        if (!vectBonus_[i]->getState())
        {
           vectBonus_.at(i)->disable(ball);
           hitBonus(i);
        }
    }
	resetBonus();
	ball->setLastPlayer(2);
}


void Game::moveBall(Ball* ball)
{
    float new_x = ball->getX() + ball->getSpeedX();
    float new_y = ball->getY() + ball->getSpeedY();
    if (new_x + ball->getRadius()*2 > width_ || new_x < 0)
    {
        ball->setSpeedX(ball->getSpeedX() * -1);
    }
    if (ball->getSpeedY() > 0 && new_y + ball->getRadius()*2 > human_->getY() && ball->getLastPlayer() == 2)
    {
        new_x += ball->getRadius();
        new_y += ball->getRadius();
        float begin = human_->getX();
        float end = human_->getX() + human_->getLength();
        int help = 2;
        if (new_x - ball->getRadius() <= end + help && new_x + ball->getRadius() >= begin - help)
        {
            float pos = std::abs(new_x - begin) / (end - begin);
            pos -= 0.5;
            pos *= 7;
            ball->setSpeedX(ball->getSpeedX() +  pos);
            ball->setSpeedY(ball->getSpeedY() * -1);
          	setLastTouch(human_);
        }
        ball->setLastPlayer(1);
    }
    else if (ball->getSpeedY() < 0 && new_y < computer_->getY() + computer_->getHeight() && ball->getLastPlayer() == 1)
    {
        new_x += ball->getRadius();
        new_y += ball->getRadius();
        float begin = computer_->getX();
        float end = computer_->getX() + computer_->getLength();
        int help = 2;
        if (new_x - ball->getRadius() <= end + help && new_x + ball->getRadius() >= begin - help)
        {
            float pos = std::abs(new_x - begin) / (end - begin);
            pos -= 0.5;
            pos *= 7;
            ball->setSpeedX(ball->getSpeedX() +  pos);
            ball->setSpeedY(ball->getSpeedY() * -1);
           	setLastTouch(computer_);
        }
        ball->setLastPlayer(2);
    }

    new_x = ball->getX() + ball->getSpeedX();
    new_y = ball->getY() + ball->getSpeedY();
    ball->setX(new_x);
    ball->setY(new_y);

    if(ball->getY() + ball->getRadius() * 2 < 0 || ball->getY() > height_)
    {
        if (ball->getY() > height_) computer_->setPoints(computer_->getPoints()+1);
        else human_->setPoints(human_->getPoints()+1);
        restart(ball);
    }
}
