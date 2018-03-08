#ifndef ENTITY_H
#define ENTITY_H
#include <SFML\Graphics.hpp>
class Entity : public sf::Drawable
{
public:
	sf::Texture texture;
	sf::Sprite spriteSheet1;
	sf::Sprite spriteSheet2;

	sf::Vector2i currentKeyFrame1;
	sf::Vector2i keyFrameSize1;
	sf::Vector2i currentKeyFrame2;
	sf::Vector2i keyFrameSize2;

	int spriteSheetWidth1;
	int spriteSheetWidth2;
	float mAnimationSpeed;
	float mKeyFrameDuration;
private:

};
#endif // !ENTITY_H
