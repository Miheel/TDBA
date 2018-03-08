#include "Bullet.h"

Bullet::Bullet()
{
	sf::String bulletFile = "../Resources/tear.png";
	BulletTexture.loadFromFile(bulletFile);
	bulletSpriteSheet.setTexture(BulletTexture);
	bulletSpriteSheet.setTextureRect(sf::IntRect(0, 0, 13, 13));
	bulletSpriteSheet.setPosition(205.0f, 180.0f);
}

Bullet::~Bullet()
{
}

void Bullet::update(float dt, sf::RenderTarget &target)
{
	sf::Vector2f speed(0.0f, 0.0f);
}

void Bullet::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(bulletSpriteSheet, states);
}