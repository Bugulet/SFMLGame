#include "spriteObject.hpp"

SpriteObject::SpriteObject(std::string identifier, std::string spriteFile) : 
    GameObject(identifier), spriteFile(spriteFile) 
{
    this->texture.loadFromFile(this->spriteFile);
    this->sprite.setTexture(this->texture,true);
}

SpriteObject::SpriteObject(const SpriteObject& other) : 
    GameObject(other.getIdentifier()), spriteFile(other.getSpriteFile()) 
{
    this->texture.loadFromFile(this->spriteFile);
    this->sprite.setTexture(this->texture);
}

SpriteObject::~SpriteObject() { }

void SpriteObject::update() {

}

void SpriteObject::render(sf::RenderWindow& window) {
    window.draw(this->sprite);
}

void SpriteObject::setPosition(sf::Vector2f position) {
    sprite.setPosition(position);
}

void SpriteObject::setScale(sf::Vector2f scale) {
    sprite.setScale(scale);
}

void SpriteObject::setSpriteFile(std::string path) {
	spriteFile = path;
	texture.loadFromFile(path);


	sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
	//sprite.setTexture(texture,);
	//printf(sprite.gette)
}

std::string SpriteObject::getSpriteFile() const {
    return this->spriteFile;
}