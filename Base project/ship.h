#pragma once
#include "Engine/GameEngine.h"
Class Ship : public GameObject
{
public:
	//Creates our ship
	Ship();

	//Function overriden from GameObject:
	void draw();
private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Ship> ShipPtr;