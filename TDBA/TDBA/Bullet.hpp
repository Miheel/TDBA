#ifndef BULLET_H
#define BULLET_H
#include "SFML\Graphics.hpp"
#include "Entity.hpp"
class Bullet :public Entity
{
public:
	Bullet();
	~Bullet();
	void update(float dt, sf::RenderTarget &target);
	void setDir(int direction);
private:
	float bulletSpeed = 10.0f;
	int attackDamage = 5;
	int direction = 0;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif // !BULLET_H