#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML\Graphics.hpp>
#include "Bullet.h"
#include "Entity.h"
class Player: public Entity
{
public:
	Player();
	~Player();
	void Update(float dt, sf::RenderTarget &target);
	
private:
	
	float movementSpeed = 180.0f;
	////Bullet**bullet;
	////int capacity;
	////int nrOfBullets;
	////void expand();
	////void initiate(int from = 0);
	////void freeMemory();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif