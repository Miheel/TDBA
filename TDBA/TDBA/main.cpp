#include <SFML/Graphics.hpp>
#include "Game.hpp"
int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "TDBA", sf::Style::Close| sf::Style::Titlebar);
	window.setFramerateLimit(60);
	Game game;
	sf::Clock gameTime;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		game.Update(gameTime.restart().asSeconds(), window);
		window.clear();
		window.draw(game);
		window.display();
	}

	return 0;
}