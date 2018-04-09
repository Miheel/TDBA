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
	// Projectile Vector Array
	std::vector<Bullet>::const_iterator iter;
	std::vector<Bullet> bulletarr;
	// Projectile Object
	Bullet bullet;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif