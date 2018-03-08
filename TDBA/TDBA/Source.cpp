#include <windows.h>
#include <SFML\Graphics.hpp>

const int winx = 1280, winy = 720;

int __stdcall WINAPI WinMain(HINSTANCE hInstance,		// HANDLE TO AN INSTANCE.  This is the "handle" to YOUR PROGRAM ITSELF.
	HINSTANCE hPrevInstance,							// USELESS on modern windows (totally ignore hPrevInstance)
	LPSTR szCmdLine,									// Command line arguments.  similar to argv in standard C programs
	int iCmdShow)										// Start window maximized, minimized, etc.
{
	sf::RenderWindow window(sf::VideoMode(winx, winy), "");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
				window.close();
		}

		window.clear();


		window.display();

	}

	return 0;
}