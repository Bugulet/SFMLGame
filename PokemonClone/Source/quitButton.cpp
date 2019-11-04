#include "quitButton.hpp"

QuitButton::QuitButton(std::string identifier, std::string path, sf::RenderWindow& window) : 
        Button(identifier, path), window(window) { }

QuitButton::~QuitButton() { }

void QuitButton::onClick() {
    this->window.close();
}


