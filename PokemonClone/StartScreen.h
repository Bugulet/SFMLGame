#pragma once

#include "scene.hpp"

#include "scene.hpp"
#include "textObject.hpp"
#include "spriteObject.hpp"
#include "character.hpp"
#include "button.hpp"
#include "quitButton.hpp"


#include "sceneHandler.hpp"

class StartScreen :
	public Scene
{
public:
	StartScreen(SceneHandler &handler, std::string identifier);
	//~StartScreen();
    void update();

private:

	Character character;

	TextObject characterName;

	SpriteObject characterAvatar;

	TextObject hpText;

	TextObject attackText;

	TextObject defenseText;

	//Button attackItselfButton;

	SceneHandler *refe;

	Button loadButton;

	sf::Font font;

	sf::Color darkColor = sf::Color(71, 82, 94, 255);
	sf::Color darkGreyColor = sf::Color(132, 146, 166, 255);
	sf::Color lightGreyColor = sf::Color(129, 144, 165, 255);

	SceneHandler handler;

};

