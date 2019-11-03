#include <SFML/Graphics.hpp>

#include <fstream>
#include <iostream>

#include "scene.hpp"
#include "textObject.hpp"
#include "spriteObject.hpp"
#include "character.hpp"
#include "button.hpp"
#include "quitButton.hpp"

#include "sceneHandler.hpp"

#include "StartScreen.h"

void characterAttackItself() {
    // GameObject& character = scene.getGameObjectByName("character");
    //Make the character attack it self
    printf("Hello world!\n");
}

int main() {

	//style::close disables resizing and maximizing
    sf::RenderWindow window(sf::VideoMode(1280,720), "SFML with Scenes!",sf::Style::Close);

   

	Scene testScreen("testScreen");


	SceneHandler handler;
	

	StartScreen characterScreen(handler, "identifier");
	
	handler.addScene(characterScreen);
	handler.addScene(testScreen);

    

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else {
				handler.handleEvent(event, window);
                //characterScreen.handleEvent(event, window);

				
            }
        }

        window.clear(sf::Color::White);
        
		handler.update();
		handler.render(window);
		//characterScreen.update();
        //characterScreen.render(window);
		
        window.display();
		
    }

    return 0;
}





