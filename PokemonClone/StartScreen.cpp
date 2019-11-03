#include "StartScreen.h"



StartScreen::StartScreen(SceneHandler &handler, std::string identifier)
	:Scene(identifier)
	, character("Dude", "head.png", 10, 2, 2)
	, characterName("characterNameText", font, character.getName())
	, characterAvatar("soldierSprite", character.getSpriteFile())
	, hpText("hpText", font, "HP: " + std::to_string(character.getHP()))
	, attackText("attackText", font, "ATTACK: " + std::to_string(character.getAttack()))
	, defenseText("defenseText", font, "DEFENSE: " + std::to_string(character.getDefense()))
//	, attackItselfButton("attackItselfButton", font, "ATTACK ITSELF", sf::Vector2f(192.5f, 50.0f), darkColor)
	, loadButton("loadButton", font, "LOAD", sf::Vector2f(192.5f, 50.0f), darkColor)
{
	this->handler = handler;

	

	//QuitButton quitButton("quitButton", font, "QUIT", sf::Vector2f(192.5f, 50.0f), darkColor, window);
	//quitButton.setPosition(sf::Vector2f(108.0f, 540.0f));

	
	//addGameObject(quitButton);

	//characterName("characterNameText", font, character.getName());

	font.loadFromFile("Lato-Regular.ttf");


	characterName.setPosition(sf::Vector2f(109.0f, 34.0f));
	characterName.setCharacterSize(26);
	characterName.setFillColor(darkColor);


	characterAvatar.setPosition(sf::Vector2f(135.0f, 90.0f));
	characterAvatar.setScale(sf::Vector2f(2.5f, 2.5f));

	hpText.setPosition(sf::Vector2f(161.0f, 238.0f));
	hpText.setCharacterSize(26);
	hpText.setFillColor(darkColor);


	attackText.setPosition(sf::Vector2f(148.0f, 290.0f));
	attackText.setCharacterSize(26);
	attackText.setFillColor(darkColor);


	defenseText.setPosition(sf::Vector2f(140.0f, 345.0f));
	defenseText.setCharacterSize(26);
	defenseText.setFillColor(darkColor);


	//attackItselfButton.setPosition(sf::Vector2f(108.0f, 400.0f));

	//attackItselfButton.setButtonAction([]() {
	//	printf("huhu");
	//});

	SceneHandler *refe = &handler;

	loadButton.setPosition(sf::Vector2f(108.0f, 470.0f));

	loadButton.setButtonAction([&handler]() {
		handler.popScene();

	});

	addGameObject(characterName);
	addGameObject(characterAvatar);
	addGameObject(hpText);
	addGameObject(attackText);
	addGameObject(defenseText);
	//addGameObject(attackItselfButton);
	addGameObject(loadButton);

}



void StartScreen::update() {
	

	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++) {
		this->listOfGameObjects[i]->update();
	}

	printf("huuuhhhhhh");

}
