#pragma once

#include "button.hpp"

class QuitButton : public Button {
    private:
        sf::RenderWindow& window;
    public:
        QuitButton(std::string identifier, std::string path, sf::RenderWindow& window);
        ~QuitButton();

        void onClick() override;
};

