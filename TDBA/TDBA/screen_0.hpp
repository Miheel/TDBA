#ifndef SCREEN_0_H
#define SCREEN_0_H
#include <iostream>
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

#pragma warning(disable:4996)
class screen_0 : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;
public:
	screen_0(void);
	virtual int Run(sf::RenderWindow &App);
};

#endif // !SCREEN_1_H
