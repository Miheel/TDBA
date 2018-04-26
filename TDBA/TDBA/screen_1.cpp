#include "screen_1.hpp"

screen_1::screen_1()
{
}

int screen_1::Run(sf::RenderWindow & App)
{
	bool Running = true;
	int menu = 0;
	sf::Event event;
	while (Running)
	{


	while (App.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			App.close();

		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
		{
			Running = false;
			menu = 0;
		}
	}
	

	game.Update(App);
	App.clear();
	App.draw(game);
	App.display();
	}
	return menu;
}
