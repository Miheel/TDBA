#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML\Graphics.hpp>
#include "Entity.hpp"
#include "Bullet.hpp"
#include <vector>
#include <list>
class Player: public Entity
{
public:
	Player();
	~Player();
	void Update(float dt, sf::RenderTarget &target);
	
private:
	float movementSpeed = 180.0f;
	int attackdamage = 5;
	// Projectile Vector Array
	std::vector<Bullet> bulletarr;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif