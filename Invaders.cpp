#include "Invaders.h"


Invaders::Invaders(sf::Texture* texture, const sf::Vector2<unsigned> &imageCount, float switchTime, float speed)
	: animation(texture, imageCount, switchTime), speed(speed) {
	invader.setTexture(*texture);
}

void Invaders::setPosition(sf::Vector2<float> newPos) {
	invader.setPosition(newPos);
}

void Invaders::update() {
	animation.update();
	invader.setTextureRect(animation.uvRect);
}

void Invaders::move(sf::Vector2<float> distance) {
	invader.move(distance);
}

void Invaders::renderTo(sf::RenderWindow& window) {
	window.draw(invader);
}

bool Invaders::isTouchingLeft() {
	if (invader.getPosition().x <= SCREEN_WIDTH * 0) { return true; }
	return false;
}

bool Invaders::isTouchingRight() {
	if (invader.getPosition().x >= SCREEN_WIDTH) { return true; }
	return false;
}
