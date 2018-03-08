#include "Enemy.h"

Enemy::Enemy()
{
	sf::String fileName = "../Resources/Deaths_Head.png";

	texture.loadFromFile(fileName);

	//spriteSheet1.setTexture(fileName);
	spriteSheet1.setTextureRect(sf::IntRect(0, 0, 32, 31));

	currentKeyFrame1 = sf::Vector2i(0, 25);
	keyFrameSize1 = sf::Vector2i(28, 25);
	spriteSheetWidth1 = 4;
}

Enemy::~Enemy()
{
}

void Enemy::Update(float dt, sf::RenderTarget & target)
{
}

void Enemy::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(spriteSheet1, states);
	target.getSize().x;
}
