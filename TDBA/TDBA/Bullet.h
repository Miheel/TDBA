#ifndef BULLET_H
#define BULLET_H
#include"SFML\Graphics.hpp"

class Bullet :public sf::Drawable
{
public:
	Bullet();
	~Bullet();
	void update(float dt, sf::RenderTarget &target);

private:
	float bulletSpeed = 10.0f;

	sf::Texture BulletTexture;
	sf::Sprite bulletSpriteSheet;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif // !BULLET_H