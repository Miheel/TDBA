#include "Random.hpp"

int generateRandom(int max)
{
	srand(unsigned int (time(NULL)));
	int random = rand() % max + 1;
	return random;
}