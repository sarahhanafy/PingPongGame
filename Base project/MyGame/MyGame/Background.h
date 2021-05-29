#pragma once

#include "Engine/GameEngine.h"


class Background : public GameObject
{
public:
	// Creates our background.
	Background();
	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);

private:
	int backgroundTimer_ = 0;
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Background> BackgroundPtr;