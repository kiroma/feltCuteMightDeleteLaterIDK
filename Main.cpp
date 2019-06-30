#include "SFML/Graphics.hpp"

#include "Invaders.h"

#include "MoreInfo.h"

int main() {
	sf::Texture texture;

	Invaders* invader;

	texture.loadFromFile("images/SIInvader2.png");
	invader = new Invaders(&texture, sf::Vector2<unsigned>(1, 2), 0.3, 2.0f);
	invader->setPosition(sf::Vector2<float>(100, 100));

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
			}
		}

		sf::Vector2<float> movement(0.f, 0.f);
		unsigned int speed = 5;

		bool isMovingLeft = false;
		bool isMovingRight = false;

		if (invader->isTouchingLeft() == true)  { movement.x += speed; bool isMovingLeft = false; bool isMovingRight = true; }
		if (invader->isTouchingRight() == true) { movement.x -= speed; bool isMovingLeft = true; bool isMovingRight = false; }

		else if (invader->isTouchingLeft() == false && invader->isTouchingRight() == false){
			if (isMovingRight == true) { movement.x += speed; }
			if (isMovingLeft == true)  { movement.x -= speed; }
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { movement.x -= speed; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { movement.x += speed; }

		invader->move(movement);



		window.clear();
		
		//Render items
		invader->renderTo(window);


		window.display();
	}
}