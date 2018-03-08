#include "Room.h"

Room::Room() :player()
{
	if (roomBackgroundTex.loadFromFile("../Resources/background.jpg"))
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
}

void Room::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(roomBackgroundSprite, states);
	target.draw(player, states);
}