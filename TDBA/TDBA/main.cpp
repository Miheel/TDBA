#include <windows.h>
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Screens.h"
#pragma warning(disable : 4996)
const int winx = 1280, winy = 720;

int __stdcall WINAPI WinMain(HINSTANCE hInstance,		// HANDLE TO AN INSTANCE.  This is the "handle" to YOUR PROGRAM ITSELF.
	HINSTANCE hPrevInstance,							// USELESS on modern windows (totally ignore hPrevInstance)
	LPSTR szCmdLine,									// Command line arguments.  similar to argv in standard C programs
	int iCmdShow)										// Start window maximized, minimized, etc.
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(unsigned int(time(NULL)));
	std::vector<cScreen*> Screens;
	int screen = 0;
	sf::RenderWindow window(sf::VideoMode(900, 506), "TDBA", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);



	screen_0 s0;
	Screens.push_back(&s0);
	screen_1 s1;
	Screens.push_back(&s1);
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(window);
	}
	return 0;
}