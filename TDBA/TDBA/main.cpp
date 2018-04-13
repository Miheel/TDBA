#include <windows.h>
#include <SFML\Graphics.hpp>
#include "Game.hpp"
const int winx = 1280, winy = 720;

int __stdcall WINAPI WinMain(HINSTANCE hInstance,		// HANDLE TO AN INSTANCE.  This is the "handle" to YOUR PROGRAM ITSELF.
	HINSTANCE hPrevInstance,							// USELESS on modern windows (totally ignore hPrevInstance)
	LPSTR szCmdLine,									// Command line arguments.  similar to argv in standard C programs
	int iCmdShow)										// Start window maximized, minimized, etc.
{
	sf::RenderWindow window(sf::VideoMode(900, 506), "TDBA", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);

	sf::Clock gameTime;
	Game game;
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