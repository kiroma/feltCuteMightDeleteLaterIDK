#pragma once

#include "SFML/Graphics.hpp"

#include "Animation.h"
#include "MoreInfo.h"

#include <iostream>

class Invaders {
	public:
		Invaders(sf::Texture* texture, const sf::Vector2<unsigned> &imageCount, float switchTime, float speed);
		
		void setPosition(sf::Vector2<float> newPos);
		void update();
		void move(sf::Vector2<float> distance);
		void renderTo(sf::RenderWindow& window);

		bool isTouchingLeft();
		bool isTouchingRight();

	private:
		sf::Sprite invader;

		Animation animation;
		unsigned int row = 0;
		float speed;
		bool isFacingRight;
};

