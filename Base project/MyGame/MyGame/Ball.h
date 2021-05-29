#pragma once

#include "Engine/GameEngine.h"
class Ball : public GameObject
{
public:
	// Creates our Ball.
	Ball(sf::Vector2f pos);
	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Ball> BallPtr;