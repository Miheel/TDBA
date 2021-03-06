#include "Bullet.hpp"
Bullet::Bullet()
{
	sf::String bulletFile = "../Resources/tear.png";
	texture.loadFromFile(bulletFile);
	spriteSheet1.setTexture(texture);
	spriteSheet1.setTextureRect(sf::IntRect(0, 0, 13, 13));


	this->objX = objX;
	this->objY = objY;
	this->direction = direction;
	this->attackDamage = attackDamage;
	this->bulletSpeed = bulletSpeed;
}

Bullet::~Bullet()
{
}

void Bullet::setDir(int &direction)
{
	this->direction = direction;
}

void Bullet::setPos(float &objX, float &objY)
{
	this->objX = objX;
	this->objY = objY;	
	spriteSheet1.setPosition(this->objX, this->objY);
}

void Bullet::update(float dt, sf::RenderTarget &target)
{
	sf::Vector2f directionV(0.0f, 0.0f);

	if (this->direction == 1)
	{
		directionV.y = -1.0f;
	}
	if (this->direction == 2)
	{
		directionV.y = 1.0f;
	}
	else if (this->direction == 3)
	{
		directionV.x = -1.0f;
	}
	else if (this->direction == 4)
	{
		directionV.x = 1.0f;
	}
	spriteSheet1.move(directionV * dt * bulletSpeed);
}

void Bullet::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(spriteSheet1, states);
}