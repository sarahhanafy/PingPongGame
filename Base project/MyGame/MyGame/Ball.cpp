#include "Ball.h"
#include "MeteorSpawner.h"

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
	sf::Vector2u size = GAME.getRenderWindow().getSize();
	if (pos.x > GAME.getRenderWindow().getSize().x - 100)
	{
		//makeDead();
		float meteorX = (float)(size.x - 100);

		// Spawn the meteor somewhere along the height of window, randomly.
		float meteorY = (float)(rand() % size.y);

		// Create a meteor and add it to the scene
		MeteorPtr meteor = std::make_shared<Meteor>(sf::Vector2f(meteorX, meteorY));
		GAME.getCurrentScene().addGameObject(meteor);
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