#include "Player.h"



Player::Player(sf::Vector2i position)
{
	texture.loadFromFile("Sprites/sprite_1.jpg");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(position));
}

void Player::AddMovement(sf::Vector2f vector) {
	Player::positions.push(vector+sprite.getPosition());
	sprite.setPosition(sf::Vector2f(vector));
}

void Player::AddMovement(float x, float y) {
	Player::positions.push(sf::Vector2f(x,y) + sprite.getPosition());
	sprite.setPosition(positions.top());
}

void Player::Undo() {
	if (positions.size() > 1) {
		sprite.setPosition(sf::Vector2f(positions.top()));
		positions.pop();
	}
}

void Player::Render(sf::RenderWindow& window) {
	window.draw(sprite);
}

