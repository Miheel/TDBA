#include "Player.hpp"

Player::Player()
{
	sf::String fileName = "../Resources/The_lost.png";
	//this->capacity = capacity;
	//this->bullet = new Bullet*[this->capacity];
	// Load texture, set it to the sprite and set what part of the sprite sheet to draw.
	if (texture.loadFromFile(fileName))
	{
		// Handle error
	}
#pragma region Head Texture
	//Head
	spriteSheet.setTexture(texture);
	spriteSheet.setTextureRect(sf::IntRect(0, 25, 28, 25));
	spriteSheet.setPosition(205.0f, 180.0f);

	// Initialise animation variables head.
	CurrentKeyFrame = sf::Vector2i(0, 25);
	KeyFrameSize = sf::Vector2i(28, 25);
	SpriteSheetWidth = 8;
#pragma endregion

#pragma region Boddy Texture
	//Boddy
	spriteSheet.setTexture(texture);
	spriteSheet.setTextureRect(sf::IntRect(0, 76, 34, 19));
	spriteSheet.setPosition(200.0f, 200.0f);

	// Initialise animation variables boddy.
	boddyCurrentKeyFrame = sf::Vector2i(0, 76);
	boddyKeyFrameSize = sf::Vector2i(34, 19);
	boddySpriteSheetWidth = 5;

	////Boddy
	//boddySpriteSheet.setTexture(texture);
	//boddySpriteSheet.setTextureRect(sf::IntRect(0, 76, 34, 19));
	//boddySpriteSheet.setPosition(200.0f, 200.0f);
	//// Initialise animation variables boddy.
	//boddyCurrentKeyFrame = sf::Vector2i(0, 76);
	//boddyKeyFrameSize = sf::Vector2i(34, 19);
	//boddySpriteSheetWidth = 5;
#pragma endregion

	mAnimationSpeed = 0.2f;
	mKeyFrameDuration = 0.0f;
}

Player::~Player()
{
	//this->freeMemory();
}

void Player::Update(float dt, sf::RenderTarget &target)
{
	sf::Vector2f direction(0.0f, 0.0f);

	mKeyFrameDuration += dt;
	CurrentKeyFrame.y = 1;
	//boddyCurrentKeyFrame.y = 4;


	// Handle input from arrow keys and update direction and animation
#pragma region key move input
	if (spriteSheet.getPosition().x >= 0 && spriteSheet.getPosition().x >= 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			direction.x = -1.0f;
			mKeyFrameDuration += dt;
			CurrentKeyFrame.x = 6;
			boddyCurrentKeyFrame.y = 4;
		}
	}
	if (boddySpriteSheet.getPosition().x + boddySpriteSheet.getLocalBounds().width <= target.getSize().x &&
		spriteSheet.getPosition().x + spriteSheet.getLocalBounds().width <= target.getSize().x)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			direction.x = 1.0f;
			mKeyFrameDuration += dt;
			CurrentKeyFrame.x = 2;
			//boddyCurrentKeyFrame.y = 4;
		}
	}

	if (boddySpriteSheet.getPosition().y >= 0 && spriteSheet.getPosition().y >= 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			direction.y = -1.0f;
			mKeyFrameDuration += dt;
			CurrentKeyFrame.x = 4;
			boddyCurrentKeyFrame.y = 4;
		}
	}

	if (boddySpriteSheet.getPosition().y + boddySpriteSheet.getLocalBounds().height <= target.getSize().y &&
		spriteSheet.getPosition().y + spriteSheet.getLocalBounds().height <= target.getSize().y)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			direction.y = 1.0f;
			mKeyFrameDuration += dt;
			CurrentKeyFrame.x = 0;
			boddyCurrentKeyFrame.y = 4;
		}
	}
	if (direction.y == 0.0f && direction.x == 0.0f)
	{
		CurrentKeyFrame.x = 0;
	}
	boddySpriteSheet.move(direction * movementSpeed * dt);
	spriteSheet.move(direction * movementSpeed * dt);
#pragma endregion

//#pragma region key shoot input
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//	{
//		//4-5
//		//mKeyFrameDuration += dt;
//		headCurrentKeyFrame.x = 5;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//	{
//		//6-7
//		//mKeyFrameDuration += dt;
//		headCurrentKeyFrame.x = 7;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//	{
//		//1-0
//		//mKeyFrameDuration += dt;
//		headCurrentKeyFrame.x = 1;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//	{
//		//2-3
//		//mKeyFrameDuration += dt;
//		headCurrentKeyFrame.x = 3;
//	}
//
//#pragma endregion

#pragma region Update animation boddy
	if (mKeyFrameDuration >= mAnimationSpeed)
	{
		/*headCurrentKeyFrame.x++;
		if (headCurrentKeyFrame.x >= headSpriteSheetWidth)
		{
			headCurrentKeyFrame.x = 0;
		}*/
		spriteSheet.setTextureRect(sf::IntRect(CurrentKeyFrame.x*KeyFrameSize.x,
			CurrentKeyFrame.y*KeyFrameSize.y, KeyFrameSize.x, KeyFrameSize.y));

		boddyCurrentKeyFrame.x++;

		if (boddyCurrentKeyFrame.x >= boddySpriteSheetWidth)
			boddyCurrentKeyFrame.x = 0;

		boddySpriteSheet.setTextureRect(sf::IntRect(boddyCurrentKeyFrame.x *boddyKeyFrameSize.x,
			boddyCurrentKeyFrame.y * boddyKeyFrameSize.y, boddyKeyFrameSize.x, boddyKeyFrameSize.y));
		mKeyFrameDuration = 0.0f;
	}
#pragma endregion
}

//void Player::expand()
//{
//	this->capacity += 10;
//	Bullet**tempBullet = new Bullet*[this->capacity];
//	for (int i = 0; i < this->nrOfBullets; i++)
//	{
//		tempBullet[i] = this->bullet[i];
//	}
//	delete[]this->bullet;
//	this->bullet = tempBullet;
//	this->initiate(this->nrOfBullets);
//}
//
//void Player::initiate(int from)
//{
//	for (int i = 0; i < this->capacity; i++)
//	{
//		this->bullet = nullptr;
//	}
//}
//
//void Player::freeMemory()
//{
//	for (int i = 0; i < nrOfBullets; i++)
//	{
//		delete this->bullet[i];
//	}
//	delete[] this->bullet;
//}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(boddySpriteSheet, states);
	target.draw(spriteSheet, states);
	target.getSize().x;
}