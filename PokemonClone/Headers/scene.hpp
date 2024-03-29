#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

#include "gameObject.hpp"

class Scene {

    protected:
        const std::string identifier;
        std::vector<GameObject*> listOfGameObjects;

    public:
        Scene(std::string identifier);
        ~Scene();

    public:
        void addGameObject(GameObject& object);
        void handleEvent(const sf::Event& event, sf::RenderWindow& window);
        virtual void update();
        void render(sf::RenderWindow& window);

        std::string getIdentifier() const;
};