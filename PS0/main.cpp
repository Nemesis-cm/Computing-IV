//Thomas Freeman
// implementation of main.cpp
// 9/13/21


#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

	// Create the window
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	// Load a sprite
	sf::Texture texture;
	if (!texture.loadFromFile("sprite.png"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);

	// Create a circle
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);

	

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			
		}

		window.clear();

		
			

		float offsetX = 0;
		float offsetY = 0;

		// Get current position of the sprite
		sf::Vector2f pos = sprite.getPosition();

		// Moves the sprite around
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && pos.x != 0)
		offsetX = -1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && pos.x != 400 - 198)
			offsetX = 1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pos.y != 0)
			offsetY = -1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pos.y != 400 - 152)
			offsetY = 1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			shape.setFillColor(sf::Color::Magenta);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			shape.setFillColor(sf::Color::Yellow);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			shape.setFillColor(sf::Color::Blue);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			shape.setFillColor(sf::Color::Red);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			sprite.setPosition(0, 0);
			pos.x = pos.y = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		// Assign it to a new position
		sprite.setPosition(pos.x + offsetX, pos.y + offsetY);

		// Draw the images
		window.draw(shape);
		window.draw(sprite);

		window.display();
	}

	return 0;
}