#ifndef ROOM_H
#define ROOM_H
#include "SFML\Graphics.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Random.hpp"
#include <vector>
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
	int lv = 1;
	int dir = 0;
	float posX = 0;
	float posY = 0;
	Player player;
	std::vector<Enemy> enemyarr;
	std::vector<Enemy>::const_iterator iter;
	Enemy enemy;

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif // !ROOM_H