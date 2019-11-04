#pragma once

#include "scene.hpp"

#include "scene.hpp"
#include "textObject.hpp"
#include "spriteObject.hpp"
#include "button.hpp"
#include "quitButton.hpp"

class SceneHandler;



class GameScreen :
	public Scene
{
public:
	GameScreen(std::string identifier, sf::RenderWindow &window);
	void init(SceneHandler &handle);
	//~StartScreen();
	void update();

private:
	sf::RenderWindow window;
	QuitButton quitButton;
	Button loadButton;

	sf::Font font;

	sf::Color darkColor = sf::Color(71, 82, 94, 255);
	sf::Color darkGreyColor = sf::Color(132, 146, 166, 255);
	sf::Color lightGreyColor = sf::Color(129, 144, 165, 255);

	SceneHandler *handler;

};

