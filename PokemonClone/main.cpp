#include <SFML/Graphics.hpp>
#include "Player.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

	Player p1(sf::Vector2i(10, 10));


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			p1.AddMovement(0.6f, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			p1.AddMovement(-0.6f, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			p1.AddMovement(0, -0.6f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			p1.AddMovement(0, 0.6f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			p1.Undo();
		}



		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			spriteTest.setColor(sf::Color::Transparent);
		}
		else {
			spriteTest.setColor(sf::Color::White);
		}*/
		

		window.clear();
		p1.Render(window);
		window.display();
	}

	return 0;
}