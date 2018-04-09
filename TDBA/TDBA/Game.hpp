#ifndef GAME_HPP
#define GAME_HPP

#include <SFML\Graphics.hpp>
#include "Room.hpp"

class Game : public sf::Drawable
{
public:
	Game();

	void Update(float dt, sf::RenderTarget &target);

private:
	Room room;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif