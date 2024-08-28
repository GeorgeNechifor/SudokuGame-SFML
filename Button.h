#pragma once
#include<SFML/Graphics.hpp>


class Button
{
public:
	Button(sf::Vector2f size , std::string text)
	{
		ButtonSize = size;
		ButtonShape.setSize(ButtonSize);
		Text = text;
	}
	void setButtonSize(sf::Vector2f size);
	void setButtonPosition(sf::Vector2f position);
	void setButtonColor(sf::Color color);
	bool buttonClickEvent(sf::Event& event);
	void setButtonText();
	sf::RectangleShape getButton();
	sf::Text ButtonText;

private:
	sf::Vector2f ButtonSize;
	sf::Vector2f ButtonCoordonates;
	sf::RectangleShape ButtonShape;
	std::string Text;
};

