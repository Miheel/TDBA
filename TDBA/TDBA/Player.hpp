#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML\Graphics.hpp>
#include "Entity.hpp"
#include "Bullet.hpp"
#include <vector>
#include <cmath>
class Player: public Entity
{
public:
	Player();
	~Player();
	void Update(float dt, sf::RenderTarget &target);
	
private:
	float movementSpeed = 180.0f;
	int attackdamage = 5;
	float shotDelay ;
	float shotDuration;
	float totalShots;
	int shotsPerSec;

	int dir = 0;//Up 1 Down 2 Left 3 Right 4
	float posX = 0;
	float posY = 0;

	// Projectile Vector Array
	std::vector<Bullet> bulletarr;
	Bullet bullet;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif