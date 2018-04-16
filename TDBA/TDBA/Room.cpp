#include "Room.hpp"
#include <vector>
Room::Room() :player(), enemy()
{
	if (roomBackgroundTex.loadFromFile("../Resources/Room.png"))
	{
		// Handle error
	}
	roomBackgroundSprite.setTexture(roomBackgroundTex);
}

void Room::Update(float dt, sf::RenderTarget & target)
{
	this->roomX = target.getSize().x;
	this->roomY = target.getSize().y;

	player.Update(dt, target);
	enemy.Update(dt, target);
}

void Room::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(roomBackgroundSprite, states);
	target.draw(player, states);
	target.draw(enemy, states);
}