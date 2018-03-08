#ifndef ENEMY_H
#define ENEMY_H
#include <SFML\Graphics.hpp>

#include "Entity.h"
class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();
	void Update(float dt, sf::RenderTarget &target);

private:

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif // !ENEMY_H
