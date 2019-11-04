#include "sceneHandler.hpp"

SceneHandler::SceneHandler(sf::RenderWindow &window)
	:mainMenu("mainMenu",window)
	,gameScene("gameScene",window)
	,endScene("endScene")
	,windowReference(&window)
{
	addScene(mainMenu);
	addScene(gameScene);
	mainMenu.init(*this);
}

SceneHandler::~SceneHandler() { }

void SceneHandler::render(sf::RenderWindow& window) const {
    if(this->scenesStack.size() != 0) {
        this->scenesStack.top()->render(window);
    }
}



void SceneHandler::StartGame() {
	stackScene("gameScene");
	gameScene.init(*this);
}

void SceneHandler::StartMenu() {
	scenesStack.empty();
	stackScene("mainMenu");
	mainMenu.init(*this);
}

void SceneHandler::update() {
    if(this->scenesStack.size() != 0) {
        this->scenesStack.top()->update();
    }
}

void SceneHandler::addScene(Scene& scene) {
	this->scenes.emplace(scene.getIdentifier(), &scene);
    if(this->scenes.size() == 1) {
        this->stackScene(scene.getIdentifier());
    }
}

void SceneHandler::stackScene(std::string sceneName) {
    this->scenesStack.push(scenes[sceneName]);
}

void SceneHandler::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
	if (this->scenesStack.size() != 0) {
		this->scenesStack.top()->handleEvent(event,window);
	}
}

void SceneHandler::popScene(void) {
    this->scenesStack.pop();
}

