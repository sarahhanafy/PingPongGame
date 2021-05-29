#include "Meteor.h"
#include "Explosion.h"
#include "GameScene.h"
#include "Ball.h"
#include "Ship.h"

const float SPEED = 0.25f;
Meteor::Meteor(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/pingpongballfinal.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
	setCollisionCheckEnabled(true);
}

void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Meteor::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();

		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}

sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

void Meteor::handleCollision(GameObject& otherGameObject)
{
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;
	if (otherGameObject.hasTag("ship"))
	{
		//otherGameObject.makeDead();

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float ballX = x + bounds.width;
		float ballY = y + (bounds.height / 2.0f);

		BallPtr ball = std::make_shared<Ball>(sf::Vector2f(ballX, ballY));
		GAME.getCurrentScene().addGameObject(ball);
	}
	sf::FloatRect bounds = sprite_.getGlobalBounds();

	float ExplosionX = x + bounds.width;
	float ExplosionY = y + (bounds.height / 2.0f);

	ExplosionPtr explosion = std::make_shared<Explosion>(sf::Vector2f(ExplosionX, ExplosionY));
	GAME.getCurrentScene().addGameObject(explosion);
	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	//scene.increaseScore();
	makeDead();
}