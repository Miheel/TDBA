#include "Random.hpp"

int generateRandom(int max)
{

	int random = rand() % max + 1;
	return random;
}