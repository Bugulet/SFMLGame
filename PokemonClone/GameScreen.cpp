#include "GameScreen.h"
#include "SFML/Window/Mouse.hpp"

#include "sceneHandler.hpp"

sf::Clock timer;

enum State {
	PlayerTurn,
	EnemyTurn,
	NextFight,
	PlayerDied
} gameState;

GameScreen::GameScreen(std::string identifier, sf::RenderWindow &window)
	:Scene(identifier)
	, attackButton("loadButton", "Sprites/AttackButton.png")
	, quitButton("quitButton", "Sprites/QuitButton.png", window)

	//enemy initialization
	, enemyHP("enemyHP", font, "ENEMY HP")
	, enemySprite("enemySprite", "Sprites/Enemies/enemy1.png")
	, enemy("enemy", "Sprites/Enemies/enemy1.png", 10, 10, 10)

	//player initialization
	, playerHP("playerHP", font, "PLAYER HP")
	, playerSprite("playerSprite", "Sprites/Enemies/enemy1.png")
	, player("player", "Sprites/head.png", 10, 10, 10)
{


	
}



void GameScreen::init(SceneHandler &handle) {

	//set game state
	gameState = State::PlayerTurn;

	//set object parameters
	font.loadFromFile("Lato-Regular.ttf");

	quitButton.setPosition(sf::Vector2f(50.0f, 350.0f));
	attackButton.setPosition(sf::Vector2f(0.0f, 250.0f));

	playerHP.setPosition(sf::Vector2f(50.0f, 200.0f));
	playerHP.setFillColor(darkColor);
	playerHP.setCharacterSize(30);

	enemyHP.setPosition(sf::Vector2f(300.0f, 200.0f));
	enemyHP.setFillColor(darkColor);
	enemyHP.setCharacterSize(30);

	playerSprite.setPosition(sf::Vector2f(50.0f, 100.0f));

	enemySprite.setPosition(sf::Vector2f(300.0f, 100.0f));

	//local scope so i dont clutter everything
	{
		Character *e = &enemy;
		TextObject *enemyHPptr = &enemyHP;
		SpriteObject *spritePtr = &enemySprite;

		attackButton.setButtonAction([e, enemyHPptr, spritePtr]() {
			if (gameState == State::PlayerTurn) {
				e->takeDamage(3);
				enemyHPptr->setText(std::to_string(e->getHP()));
				if (e->getHP() <= 0) {
					int spriteNum = rand() % 3 + 1;
					spritePtr->setSpriteFile("Sprites/Enemies/enemy" + std::to_string(spriteNum) + ".png");
					e->setHP(15);
					enemyHPptr->setText(std::to_string(e->getHP()));
				}
				gameState = State::EnemyTurn;
			}
		});
	}

	addGameObject(playerSprite);
	addGameObject(playerHP);

	addGameObject(enemySprite);
	addGameObject(enemyHP);
	addGameObject(attackButton);
	addGameObject(quitButton);

}





void GameScreen::update() {

	//regen enemy life (small test for the timer)
	/*if (timer.getElapsedTime().asSeconds() > 2) {
		timer.restart();
		enemy.setHP(enemy.getHP() + 1);
		enemyHP.setText(std::to_string(enemy.getHP()));
	}*/

	if (gameState == State::EnemyTurn) {
		if (timer.getElapsedTime().asSeconds() > 2) {
			timer.restart();
			player.takeDamage(2);
			playerHP.setText(std::to_string(player.getHP()));
			gameState = State::PlayerTurn;
		}
	}

	//update all game objects
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++) {
		this->listOfGameObjects[i]->update();
	}



}
