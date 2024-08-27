#include "Button.h"
#include<iostream>
void Button::setButtonSize(sf::Vector2f size) {
	ButtonShape.setSize(size);
}
void Button::setButtonPosition(sf::Vector2f position) {
	ButtonShape.setPosition(position);
}
void Button::setButtonColor(sf::Color color) {
	ButtonShape.setFillColor(color);
}
sf::RectangleShape Button::getButton() {
	return ButtonShape;
}
void Button::setButtonText() {
	
}
bool Button::buttonClickEvent(sf::Event& event) {
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			float mouseX = event.mouseButton.x;
			float mouseY = event.mouseButton.y;
			float XMargin = ButtonCoordonates.x + ButtonSize.x;
			float YMargin = ButtonCoordonates.y + ButtonSize.y;
			if (mouseX >= ButtonCoordonates.x && mouseX <= XMargin) {
				if (mouseY >= ButtonCoordonates.y && mouseY <= YMargin) {
					return true;
				}
			}
			
			return false;
		}
	}
	return false;
	
}