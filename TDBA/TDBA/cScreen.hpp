#ifndef SCREENS_H
#define SCREENS_H
#include "SFML\Graphics.hpp"
class cScreen
{
public:
	virtual int Run(sf::RenderWindow &App) = 0;
};
#endif // !CSCREEN_H
