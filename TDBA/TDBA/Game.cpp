#include "Game.hpp"
#include "SFML\Graphics.hpp"
Game::Game() :room()
{
	
}

void Game::Update(sf::RenderTarget &target)
{
	// Make sure everything in the game is updated (if needed).
	room.Update(Time.restart().asSeconds(), target);
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	// Make sure everything in the game is drawn.
	target.draw(room, states);
}