#include "button.hpp"

#include <SFML/Window/Event.hpp>


Button::Button(std::string identifier, std::string path) :
	GameObject(identifier),texture(),sprite()
{
	texture.loadFromFile(path);
	sprite.setTexture(texture);
}

Button::~Button() { }

void Button::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    if(event.type == sf::Event::MouseButtonPressed  && 
        event.mouseButton.button == sf::Mouse::Button::Left) {

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2u size = texture.getSize();
        sf::Vector2f position = sprite.getPosition();

        if(mousePosition.x >= position.x && mousePosition.x <= position.x + size.x && 
            mousePosition.y >= position.y && mousePosition.y <= position.y + size.y) {
                this->onClick();
        }
    }
}

void Button::update() { }

void Button::render(sf::RenderWindow& window) { 
    window.draw(sprite);
}

void Button::setCharacterSize(const int size) {
   // this->text.setCharacterSize(size);
}

void Button::setPosition(const sf::Vector2f position) {
    sprite.setPosition(position);
    sf::Vector2u size =texture.getSize();
    sf::Vector2f centerButton(position.x + (size.x / 2.0f), position.y + (size.y / 2.0f));
    sprite.setPosition(centerButton);
}

void Button::onClick() {
    this->action();
}

void Button::setButtonAction(std::function<void()> action) {
    this->action = action;
}