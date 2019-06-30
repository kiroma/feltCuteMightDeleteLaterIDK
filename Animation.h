#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"

#include <chrono>

class Animation {
	public:
		enum Direction
		{
			up = 0,
			left = 1,
			down = 2,
			right = 3
		};
		Animation(sf::Texture* texture, const sf::Vector2u &imageCount, float switchTime);
		
		void update();
		sf::IntRect uvRect;
		bool isMoving = false;
		Direction direction = up;

	private:
		const sf::Vector2u imageCount;
		sf::Vector2u currentImage;

		std::chrono::steady_clock::time_point tp = std::chrono::steady_clock::now();
		float elapsed()
		{
			return std::chrono::duration<float>(std::chrono::steady_clock::now() - tp).count();
		}
		const float switchTime;
};

#endif
