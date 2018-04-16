#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML\Graphics.hpp>
#include "Entity.hpp"
#include "Bullet.hpp"
#include <vector>
class Player: public Entity
{
public:
	Player();
	~Player();
	void Update(float dt, sf::RenderTarget &target);
	
private:
	float movementSpeed = 180.0f;
	int attackdamage = 5;
	float attackSpeed = 0.3f;
	int dir = 0;//Up 1 Down 2 Left 3 Right 4
	// Projectile Vector Array
	std::vector<Bullet> bulletarr;
	Bullet bullet;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif