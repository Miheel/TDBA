#ifndef ROOM_H
#define ROOM_H
#include "SFML\Graphics.hpp"
#include "Player.hpp"
#include "Enemy.h"
class Room : public sf::Drawable
{
public:
	Room();
	void Update(float dt, sf::RenderTarget &target);
private:
	sf::Texture roomBackgroundTex;
	sf::Sprite roomBackgroundSprite;
	int roomX;
	int roomY;
	Player player;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif // !ROOM_H