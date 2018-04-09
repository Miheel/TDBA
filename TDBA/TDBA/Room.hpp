#ifndef ROOM_H
#define ROOM_H
#include "SFML\Graphics.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
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
	int counter;
	Player player;
	Enemy enemy;
	std::vector<Enemy>::const_iterator enemyiter;
	std::vector<Enemy> enemyArr;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif // !ROOM_H