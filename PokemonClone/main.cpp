#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Texture texture;
	texture.loadFromFile("Sprites/sprite_1.jpg");

	sf::Sprite spriteTest;

	spriteTest.setTexture(texture);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			spriteTest.move(0.1, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			spriteTest.setColor(sf::Color::Transparent);
		}
		else {
			spriteTest.setColor(sf::Color::White);
		}
		

		window.clear();
		window.draw(spriteTest);
		window.display();
	}

	return 0;
}