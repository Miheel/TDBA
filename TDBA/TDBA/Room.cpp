#include "Room.hpp"
Room::Room() :player(), enemy()
{
	if (roomBackgroundTex.loadFromFile("../Resources/Room.png"))
	{
		// Handle error
	}
	roomBackgroundSprite.setTexture(roomBackgroundTex);
	
}

void Room::Update(float dt, sf::RenderTarget &target)
{
	this->roomX = target.getSize().x;
	this->roomY = target.getSize().y;

	player.Update(dt, target);

	if (lv == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			posX = 100.0f;
			posY = 100.0f*(i + 1);
			enemy.setPos(posX, posY);
			enemyarr.push_back(enemy);
		}
		lv++;
	}
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