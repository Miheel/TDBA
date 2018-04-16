#include "Player.hpp"

Player::Player()
{
	sf::String fileName = "../Resources/The_lost.png";
	// Load texture, set it to the sprite and set what part of the sprite sheet to draw.
	if (texture.loadFromFile(fileName))
	{
		// Handle error
	}
#pragma region Head Texture
	//Head
	spriteSheet1.setTexture(texture);
	spriteSheet1.setTextureRect(sf::IntRect(0, 25, 28, 25));
	spriteSheet1.setPosition(195.5f, 183.0f);

	// Initialise animation variables head.
	currentKeyFrame1 = sf::Vector2i(0, 25);
	keyFrameSize1 = sf::Vector2i(28, 25);
	spriteSheetWidth1 = 8;
#pragma endregion

#pragma region Boddy Texture
	//Boddy
	spriteSheet2.setTexture(texture);
	spriteSheet2.setTextureRect(sf::IntRect(0, 76, 19, 19));
	spriteSheet2.setPosition(200.0f, 200.0f);

	// Initialise animation variables boddy.
	currentKeyFrame2 = sf::Vector2i(0, 76);
	keyFrameSize2 = sf::Vector2i(19, 19);
	spriteSheetWidth2 = 5;

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
	currentKeyFrame1.y = 1;
	currentKeyFrame2.y = 4;


	// Handle input from arrow keys and update direction and animation
#pragma region key move input
	if (spriteSheet1.getPosition().x >= 40 && spriteSheet2.getPosition().x >= 40)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			direction.x = -1.0f;
			mKeyFrameDuration += dt;
			currentKeyFrame1.x = 6;
			currentKeyFrame2.y = 4;
		}
	}
	if (spriteSheet2.getPosition().x + spriteSheet2.getLocalBounds().width <= target.getSize().x-40 &&
		spriteSheet1.getPosition().x + spriteSheet1.getLocalBounds().width <= target.getSize().x-40)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			direction.x = 1.0f;
			mKeyFrameDuration += dt;
			currentKeyFrame1.x = 2;
			//boddyCurrentKeyFrame.y = 4;
		}
	}

	if (spriteSheet2.getPosition().y >= 40 && spriteSheet1.getPosition().y >= 25)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			direction.y = -1.0f;
			mKeyFrameDuration += dt;
			currentKeyFrame1.x = 4;
			currentKeyFrame2.y = 4;
		}
	}

	if (spriteSheet2.getPosition().y + spriteSheet2.getLocalBounds().height <= target.getSize().y-40 &&
		spriteSheet1.getPosition().y + spriteSheet1.getLocalBounds().height <= target.getSize().y-40)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			direction.y = 1.0f;
			mKeyFrameDuration += dt;
			currentKeyFrame1.x = 0;
			currentKeyFrame2.y = 4;
		}
	}
	if (direction.y == 0.0f && direction.x == 0.0f)
	{
		currentKeyFrame1.x = 0;
	}
	spriteSheet1.move(direction * movementSpeed * dt);
	spriteSheet2.move(direction * movementSpeed * dt);
#pragma endregion

#pragma region key shoot input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//4-5
		//mKeyFrameDuration += dt;
		currentKeyFrame1.x = 5;
		Bullet *temp = new Bullet();
		bulletarr.push_back(*temp);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//6-7
		//mKeyFrameDuration += dt;
		currentKeyFrame1.x = 7;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//1-0
		//mKeyFrameDuration += dt;
		currentKeyFrame1.x = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//2-3
		//mKeyFrameDuration += dt;
		currentKeyFrame1.x = 3;
	}

#pragma endregion

#pragma region Update animation boddy
	if (mKeyFrameDuration >= mAnimationSpeed)
	{
		/*headCurrentKeyFrame.x++;
		if (headCurrentKeyFrame.x >= headSpriteSheetWidth)
		{
			headCurrentKeyFrame.x = 0;
		}*/
		spriteSheet1.setTextureRect(sf::IntRect(currentKeyFrame1.x*keyFrameSize1.x,
			currentKeyFrame1.y*keyFrameSize1.y, keyFrameSize1.x, keyFrameSize1.y));

		currentKeyFrame2.x++;

		if (currentKeyFrame2.x >= spriteSheetWidth2)
			currentKeyFrame2.x = 0;

		spriteSheet2.setTextureRect(sf::IntRect(currentKeyFrame2.x *keyFrameSize2.x,
			currentKeyFrame2.y * keyFrameSize2.y, keyFrameSize2.x, keyFrameSize2.y));
		mKeyFrameDuration = 0.0f;
	}
#pragma endregion
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(spriteSheet2, states);
	target.draw(spriteSheet1, states);
	for (int i = 0; i < bulletarr.size(); i++)
	{
		target.draw(bulletarr[i], states);
	}
	target.getSize().x;
}