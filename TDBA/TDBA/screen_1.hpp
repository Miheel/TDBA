#ifndef SCREEN_1_H
#define SCREEN_1_H
#include "cScreen.hpp"
#include "SFML\Graphics.hpp"
#include "Game.hpp"
class screen_1 : public cScreen
{
public: 
	screen_1();
	virtual int Run(sf::RenderWindow &App);

private:
	Game game;
};
#endif // !SCREEN_1_H
