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
	void setDir(int &directionrng);
	void setPos(float &objX, float &objY);
	void Update(float dt, sf::RenderTarget &target);
private:
	float movementSpeed = 180.0f;
	int attackdamage = 5;
	int directionrng = 0;
	int movement;

	float objX = 0;
	float objY = 0;
	sf::Vector2f direction;
	int isInsideTarget(sf::RenderTarget &target);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif // !ENEMY_H
