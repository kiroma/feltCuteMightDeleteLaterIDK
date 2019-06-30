#include "SFML/Graphics.hpp"

#include "Invaders.h"

#include "MoreInfo.h"

int main() {
	sf::Texture texture;

	texture.loadFromFile("images/SIInvader2.png");
	Invaders invader(&texture, sf::Vector2<unsigned>(2, 1), 0.3, 2.0f);
	invader.setPosition(sf::Vector2<float>(100, 100));

	sf::RenderWindow window;
	sf::Event sfEvent;

	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Window");
	window.setFramerateLimit(120);

	while (window.isOpen()) {
		while (window.pollEvent(sfEvent)) {
			switch (sfEvent.type) {
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}

		sf::Vector2<float> movement(0.f, 0.f);
		unsigned int speed = 5;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { movement.x -= speed; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { movement.x += speed; }

		invader.move(movement);
		invader.update();

		window.clear();
		
		//Render items
		invader.renderTo(window);

		window.display();
	}
}
