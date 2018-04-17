#ifndef BULLET_H
#define BULLET_H
#include "SFML\Graphics.hpp"
#include "Entity.hpp"
class Bullet :public Entity
{
public:
	Bullet();
	~Bullet();
	void setDir(int &direction);
	void setPos(float &objX, float &objY);
	void update(float dt, sf::RenderTarget &target);
private:
	float bulletSpeed = 300.0f;
	int attackDamage = 5;
	int direction = 0;
	float objX = 0;
	float objY = 0;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif // !BULLET_H