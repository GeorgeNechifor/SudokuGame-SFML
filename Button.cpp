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
	sf::Font font;
	font.loadFromFile("Assets/Roboto-Medium.ttf");
	ButtonText.setFont(font);
	ButtonText.setCharacterSize(20);
	ButtonText.setString(Text);
	ButtonText.setFillColor(sf::Color::White);
	sf::FloatRect textRect = ButtonText.getLocalBounds();
	ButtonText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	sf::Vector2f rectangleCenter = ButtonShape.getPosition() + ButtonShape.getSize() / 2.0f;
	ButtonShape.setPosition(rectangleCenter);
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