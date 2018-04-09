#ifndef ENEMY_H
#define ENEMY_H
#include <SFML\Graphics.hpp>
#include "Entity.hpp"
#include "Random.hpp"
class Enemy :public Entity
{
public:
	Enemy();
	~Enemy();
	void Update(float dt, sf::RenderTarget &target);

private:
	float movementSpeed = 180.0f;
	int attackdamage = 5;
	int directionrng = 0;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif // !ENEMY_H