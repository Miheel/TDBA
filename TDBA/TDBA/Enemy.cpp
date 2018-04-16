#include "Enemy.hpp"

Enemy::Enemy()
{
	sf::String fileName = "../Resources/Deaths_Head.png";

	texture.loadFromFile(fileName);

	spriteSheet1.setTexture(texture);
	spriteSheet1.setTextureRect(sf::IntRect(0, 0, 32, 31));
	spriteSheet1.setPosition(100, 100);
	currentKeyFrame1 = sf::Vector2i(0, 25);
	keyFrameSize1 = sf::Vector2i(28, 25);
	spriteSheetWidth1 = 4;
}

Enemy::~Enemy()
{
}

void Enemy::Update(float dt, sf::RenderTarget & target)
{
	sf::Vector2f direction(0.0f, 0.0f);
	directionrng = generateRandom(4);
	if (spriteSheet1.getPosition().x >= 40)
	{
		if (directionrng == 1)//left
		{
			direction.x = -1.0f;
		}
	}
	if (spriteSheet1.getPosition().x + spriteSheet1.getLocalBounds().width <= target.getSize().x - 40)
	{
		if (directionrng == 2)//right
		{
			direction.x = 1.0f;
		}
	}
	if (spriteSheet1.getPosition().y >= 40)
	{
		if (directionrng == 3)//up
		{
			direction.y = -1.0f;
		}
	}
	if (spriteSheet1.getPosition().y + spriteSheet1.getLocalBounds().height <= target.getSize().y - 40)
	{
		if (directionrng == 4)//down
		{
			direction.y = 1.0f;
		}
	}
	spriteSheet1.move(direction * movementSpeed * dt);
}

void Enemy::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(spriteSheet1, states);
	target.getSize().x;
}
