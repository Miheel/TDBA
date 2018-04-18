#include "Enemy.hpp"

Enemy::Enemy()
{
	sf::String fileName = "../Resources/Deaths_Head.png";

	texture.loadFromFile(fileName);

	spriteSheet1.setTexture(texture);
	spriteSheet1.setTextureRect(sf::IntRect(0, 0, 32, 31));
	currentKeyFrame1 = sf::Vector2i(0, 25);
	keyFrameSize1 = sf::Vector2i(28, 25);
	spriteSheetWidth1 = 4;
	spriteSheet1.setPosition(100, 100);

	this->objX = objX;
	this->objY = objY;
	this->directionrng = directionrng;
}

Enemy::~Enemy()
{
}

void Enemy::setDir(int &directionrng)
{
	this->directionrng = directionrng;
}

void Enemy::setPos(float & objX, float & objY)
{
	this->objX = objX;
	this->objY = objY;
	spriteSheet1.setPosition(this->objX, this->objY);
}

void Enemy::Update(float dt, sf::RenderTarget &target)
{
	if (movement >= spriteSheet1.getLocalBounds().width)
	{
		direction.x = 0.0f;
		direction.y = 0.0f;
		directionrng = generateRandom(4);
		movement = 0;
	}
	movement++;

	if (spriteSheet1.getPosition().x >= 40)
	{
		if (this->directionrng == 1)//left
		{
			direction.x = -1.0f;
		}
	}
	if (spriteSheet1.getPosition().x + spriteSheet1.getLocalBounds().width <= target.getSize().x - 40)
	{
		if (this->directionrng == 2)//right
		{
			direction.x = 1.0f;
		}
	}
	if (spriteSheet1.getPosition().y >= 40)
	{
		if (this->directionrng == 3)//up
		{
			direction.y = -1.0f;	
		}
	}
	if (spriteSheet1.getPosition().y + spriteSheet1.getLocalBounds().height <= target.getSize().y - 40)
	{
		if (this->directionrng == 4)//down
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
