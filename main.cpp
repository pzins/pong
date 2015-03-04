#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread>
#include "game.h"
#include "player.h"
#include "ball.h"
#include "bonus.h"
#include "speedBonus.h"
#include "lengthBonus.h"
#include "speedBallBonus.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <time.h>
#include <string>
#include <sstream>

#define WIDTH_SCREEN 1000
#define HEIGTH_SCREEN 700

#define RAYON 10
#define LENGTH 75
#define HEIGHT 8
#define SPEED 5
#define SPEED_INI_X_BALL 0
#define SPEED_INI_Y_BALL 3

#define BONUS_TIME_LENGTH 20
#define BONUS_TIME_SPEED 20
#define BONUS_TIME_SPEED_BALL 10
#define BONUS_COEFF_LENGTH 2
#define BONUS_COEFF_SPEED 2
#define BONUS_COEFF_SPEED_BALL 2

void intermediaire(Game* game, Ball* ball){game->moveBall(ball);}
void gestionKeyboard(Game* game);
void drawingScore(Game* game);
std::string to_string(float value);
void drawingTime(Game* game, sf::Clock time);
void gestionBonus(Game* game, sf::Clock time, Ball* ball);
bool collisionBonus(Bonus* bonus, Ball* ball);

int main()
{

    Player* h = new Player(0,LENGTH,HEIGHT,SPEED,sf::Color::Blue,
        0.5*WIDTH_SCREEN-LENGTH*0.5,
        HEIGTH_SCREEN-RAYON*2 - HEIGHT);
    Player* c = new Player(0,LENGTH,HEIGHT,SPEED,sf::Color::Red,
        0.5*WIDTH_SCREEN-LENGTH*0.5,
        RAYON*2);

    Game* game = new Game(WIDTH_SCREEN, HEIGTH_SCREEN, sf::Color::White, h, c);
    Ball* ball = new Ball(game->getWidth() / 2 - RAYON, game->getHeight() / 2 - RAYON,RAYON,
        sf::Color::Green, SPEED_INI_X_BALL, SPEED_INI_Y_BALL);

    srand (time(NULL));
    sf::Clock time;

    sf::Texture texture;
    texture.loadFromFile("fond4.jpg", sf::IntRect(0,0,WIDTH_SCREEN,HEIGTH_SCREEN));
    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (game->app.isOpen())
    {
        sf::Event event;
        while (game->app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game->app.close();
            if (event.type == sf::Event::KeyPressed)
            {
                    
            }
        }
        gestionKeyboard(game);               

        //game->getComputer()->setX(ball->getX());
        std::thread t1(intermediaire,game, ball);
        t1.join();
        game->app.draw(sprite);
       // game->app.draw(game->getField());
        game->app.draw(game->getHuman()->computeBase());
        game->app.draw(game->getComputer()->computeBase());
        game->app.draw(ball->computeBall());
        drawingTime(game, time);
        drawingScore(game);
        gestionBonus(game, time, ball);
        game->moveComputer(ball);


        game->app.display();
        game->app.clear();
    }

    return 0;
}

void gestionKeyboard(Game* game)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        game->moveHuman(1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        game->moveHuman(0);
    }
    /*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
         game->moveComputer(0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
         game->moveComputer(1);
    }*/
}




void drawingScore(Game* game)
{
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text human;
    sf::Text computer;
    human.setFont(font);
    human.setCharacterSize(40);
    human.setStyle(sf::Text::Bold);
    human.setString("Blue : " + std::to_string(game->getHuman()->getPoints()));
    human.setPosition(sf::Vector2f(1025,50));
    computer.setFont(font);
    computer.setCharacterSize(40);
    computer.setString("Red : " + std::to_string(game->getComputer()->getPoints()));
    computer.setPosition(sf::Vector2f(1025,120));
    game->app.draw(human);
    game->app.draw(computer);
}

std::string to_string(float value)
{
    std::ostringstream os;
    os << value;
    return os.str();
}


void drawingTime(Game* game, sf::Clock time)
{
    std::string temp = to_string(time.getElapsedTime().asSeconds());
    sf::Text textTime;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    textTime.setFont(font);
    textTime.setCharacterSize(40);
    textTime.setStyle(sf::Text::Bold);
    textTime.setPosition(sf::Vector2f(1025,400));
    textTime.setString(temp);
    game->app.draw(textTime);
}

void gestionBonus(Game* game, sf::Clock time, Ball* ball)
{
    float t = time.getElapsedTime().asSeconds();
    static int old_t = -1;
    if (!(int(t) % 10) && int(t) != old_t && t >= 1)
    {
        old_t = t;
        float y = 100 + rand() % 400;
        float x = 50 + rand() % 550;    
        float r = 5  +rand() % 25;
        int choix = rand() % 100;
        Bonus* b;
        if (choix < 20) b = new SpeedBonus(sf::Color(250, 0, 0,180), x,y,r,BONUS_TIME_SPEED, BONUS_COEFF_SPEED);
        else if (choix < 50) b = new SpeedBallBonus(sf::Color(250,250,0,180), x, y, r, BONUS_TIME_SPEED_BALL, BONUS_COEFF_SPEED_BALL);
        else b = new LengthBonus(sf::Color(0,0,250, 180),x,y,r, BONUS_TIME_LENGTH, BONUS_COEFF_LENGTH);
        game->addBonus(b);
    }
    for(int i = 0; i < game->getVectBonus().size(); ++i)
    {
        if (game->getVectBonus().at(i)->getState())
        {
            if (collisionBonus(game->getVectBonus().at(i), ball))
            {
                game->getVectBonus()[i]->setOwner(game->getLastTouch());
                game->getVectBonus().at(i)->setStartTime(t);
                game->getVectBonus().at(i)->setState(false);
                game->getVectBonus().at(i)->apply(ball);
            }
            else game->app.draw(game->getVectBonus().at(i)->computeBonus());
        }
    }
    for (int i = 0; i < game->getVectBonus().size(); ++i)
    {
        if (!game->getVectBonus()[i]->getState())
        {
            if (game->getVectBonus()[i]->getStartTime() + game->getVectBonus()[i]->getDuree() <  t)
            {
                game->getVectBonus().at(i)->disable(ball);
                game->hitBonus(i);
            }
        }
    }
}



bool collisionBonus(Bonus* bonus, Ball* ball)
{
    float x_ball = ball->getX() + ball->getRadius();
    float y_ball = ball->getY() + ball->getRadius();
    float x_bonus = bonus->getX() + bonus->getRadius();
    float y_bonus = bonus->getY() + bonus->getRadius();
    if (std::abs(x_ball - x_bonus) < ball->getRadius() + bonus->getRadius()
        && std::abs(y_ball - y_bonus) < ball->getRadius() + bonus->getRadius())
    return true;
    return false;
}