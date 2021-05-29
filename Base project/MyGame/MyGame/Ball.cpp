#include "Ball.h"

const float SPEED = 1.2f;

Ball::Ball(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/pingpongballfinal.png"));
	sprite_.setPosition(pos);
	assignTag("ball"); 
}
void Ball::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void Ball::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	if (pos.x > GAME.getRenderWindow().getSize().x)
	{
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x + SPEED * msElapsed, pos.y));
	}
	
}

sf::FloatRect Ball::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}