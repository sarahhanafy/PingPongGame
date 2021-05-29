#pragma once

#include "Background.h"

const float SPEED = 0.10f;
Background::Background()
{
	sprite_.setTexture(GAME.getTexture("Resources/pingpongtable.PNG"));
	//sprite_.setPosition(pos);
}

void Background::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Background::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	if (pos.x > 0) {
		sprite_.setPosition(sf::Vector2f((pos.x -800) - SPEED * msElapsed, pos.y));
	}
	
	//else if (pos.x < 800) {
		//sprite_.setPosition(sf::Vector2f((pos.x + 800) - SPEED * msElapsed, pos.y));
	//}
	
}