#include "SFML/Graphics.hpp"

#include "Invaders.h"

#include "MoreInfo.h"

int main() {
	sf::Texture texture;

	texture.loadFromFile("images/skeletons.png");
	Invaders invader(&texture, sf::Vector2<unsigned>(9, 4), 0.1, 2.0f);
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
		unsigned int speed = 2;

		bool moving = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !invader.isTouchingLeft()) { movement.x -= speed; invader.setDirection(Animation::Direction::left); moving = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !invader.isTouchingRight()) { movement.x += speed; invader.setDirection(Animation::Direction::right); moving = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !invader.isTouchingUp()) { movement.y -= speed; invader.setDirection(Animation::Direction::up); moving = true; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !invader.isTouchingDown()) { movement.y += speed; invader.setDirection(Animation::Direction::down); moving = true; }

		invader.setMoving(moving);
		invader.move(movement);
		invader.update();

		window.clear();
		
		//Render items
		invader.renderTo(window);

		window.display();
	}
}
