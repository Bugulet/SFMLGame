#pragma once

#include <stack>
#include <SFML/Graphics.hpp>

class Player {

public: 
	Player();
	virtual void AddMovement()=0;
	virtual void Undo() = 0;

private:
	std::stack<sf::Vector2i> positions;
};