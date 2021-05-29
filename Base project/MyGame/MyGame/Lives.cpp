#include "Lives.h"
#include "GameScene.h"
#include <sstream>

Lives::Lives(sf::Vector2f pos)
{
	text_.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	text_.setPosition(pos);
	text_.setCharacterSize(24);
	//text_.setColor(sf::Color::White);
	assignTag("lives");
}

void Lives::draw()
{
	GAME.getRenderWindow().draw(text_);
}

void Lives::update(sf::Time& elapsed)
{
	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	std::stringstream stream;
	stream << "Lives: " << scene.getLives();
	text_.setString(stream.str());
}
