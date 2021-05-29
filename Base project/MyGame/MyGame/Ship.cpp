#include "Ship.h"
#include "Ball.h"
#include "GameScene.h"
#include "Meteor.h"

const float SPEED = 0.3f;
const int FIRE_DELAY = 200;

Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/pingpongpaddle.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
	setCollisionCheckEnabled(true);
	assignTag("ship");
}

void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}


void Ship::handleCollision(GameObject& otherGameObject)
{
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;
	if (otherGameObject.hasTag("ball"))
	{
		//otherGameObject.makeDead();
		fireTimer_ = FIRE_DELAY;

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float ballX = x + bounds.width;
		float ballY = y + (bounds.height / 2.0f);

		BallPtr ball = std::make_shared<Ball>(sf::Vector2f(ballX, ballY));
		GAME.getCurrentScene().addGameObject(ball);
	}
	sf::FloatRect bounds = sprite_.getGlobalBounds();

	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	scene.increaseScore();
	//makeDead();
}

void Ship::update(sf::Time& elapsed) {
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;

	int msElapsed = elapsed.asMilliseconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) y -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) y += SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) x -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) x += SPEED * msElapsed;

	sprite_.setPosition(sf::Vector2f(x, y));
	/*
	if (fireTimer_ > 0)
	{
		fireTimer_ -= msElapsed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer_ <= 0)
	{
		fireTimer_ = FIRE_DELAY;

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float ballX = x + bounds.width;
		float ballY = y + (bounds.height / 2.0f);

		BallPtr ball = std::make_shared<Ball>(sf::Vector2f(ballX, ballY));
		GAME.getCurrentScene().addGameObject(ball);
	}
	*/
}


sf::FloatRect Ship::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}