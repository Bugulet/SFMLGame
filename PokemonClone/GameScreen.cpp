#include "GameScreen.h"
#include "SFML/Window/Mouse.hpp"

#include "sceneHandler.hpp"

GameScreen::GameScreen(std::string identifier, sf::RenderWindow &window)
	:Scene(identifier)
	, loadButton("loadButton", "Sprites/StartButton.png")
	, quitButton("quitButton", "Sprites/QuitButton.png", window)
{



}

void GameScreen::init(SceneHandler &handle) {

	quitButton.setPosition(sf::Vector2f(50.0f, 350.0f));
	loadButton.setPosition(sf::Vector2f(0.0f, 250.0f));

	addGameObject(quitButton);

	font.loadFromFile("Lato-Regular.ttf");


	loadButton.setButtonAction([&handle]() { handle.StartMenu(); });

	addGameObject(loadButton);
}





void GameScreen::update() {

	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++) {
		this->listOfGameObjects[i]->update();
	}

}
