#include "Room.hpp"
Room::Room() :player(), enemy()
{
	if (roomBackgroundTex.loadFromFile("../Resources/Room.png"))
	{
		// Handle error
	}
	roomBackgroundSprite.setTexture(roomBackgroundTex);
	for (int i = 0; i < 4; i++)
	{
		enemyarr.push_back(enemy);
	}
}

void Room::Update(float dt, sf::RenderTarget &target)
{
	this->roomX = target.getSize().x;
	this->roomY = target.getSize().y;

	player.Update(dt, target);
		
	for (unsigned int i = 0; i < enemyarr.size(); i++)
	{
		enemyarr[i].Update(dt, target);
	}
}

void Room::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(roomBackgroundSprite, states);
	target.draw(player, states);
	for (unsigned int i = 0; i < enemyarr.size(); i++)
	{
		target.draw(enemyarr[i], states);
	}
}