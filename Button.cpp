#include "Button.h"

void Button::setButtonSize(sf::Vector2f size) {
	ButtonShape.setSize(size);
}
void Button::setButtonPosition(sf::Vector2f position) {
	ButtonShape.setPosition(position);
}
void Button::setButtonColor(sf::Color color) {
	ButtonShape.setFillColor(color);
}
