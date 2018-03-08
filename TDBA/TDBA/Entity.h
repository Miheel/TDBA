#ifndef ENTITY_H
#define ENTITY_H
#include <SFML\Graphics.hpp>
class Entity : public sf::Drawable
{
public:
	sf::Texture texture;
	sf::Sprite spriteSheet;

	sf::Vector2i CurrentKeyFrame;
	sf::Vector2i KeyFrameSize;

	int SpriteSheetWidth;
	float mAnimationSpeed;
	float mKeyFrameDuration;
private:

};
#endif // !ENTITY_H
