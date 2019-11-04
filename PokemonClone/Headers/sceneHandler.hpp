#pragma once

#include <map>
#include <stack>
#include "scene.hpp"
#include "StartScreen.h"
#include "GameScreen.h"

class SceneHandler {
    private:
        std::map<std::string, Scene*> scenes;
        std::stack<Scene*> scenesStack;

		StartScreen mainMenu;
		GameScreen gameScene;
		Scene endScene;

		sf::RenderWindow *windowReference;

    public:
        SceneHandler(sf::RenderWindow &window); 
        ~SceneHandler();
    public:
        void render(sf::RenderWindow& window) const;
		void StartGame();
		void StartMenu();
        void update();

        void addScene(Scene& scene);
        void stackScene(std::string sceneName);
		void handleEvent(const sf::Event & event, sf::RenderWindow & window);
        void popScene();
};