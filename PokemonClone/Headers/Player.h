#pragma once

#include <stack>
#include <SFML/Graphics.hpp>

class Player {

public:
	Player(sf::Vector2i position);
	virtual void AddMovement( sf::Vector2f vector) ;
	virtual void AddMovement(float x,float y);
	virtual void Undo() ;
	virtual void Render(sf::RenderWindow& window);

private:
	sf::Sprite sprite;
	sf::Texture texture;
	std::stack<sf::Vector2f> positions;
};

