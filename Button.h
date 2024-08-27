#pragma once
#include<SFML/Graphics.hpp>


class Button
{
public:
	Button(sf::Vector2f size)
	{
		ButtonSize = size;
		ButtonShape.setSize(ButtonSize);
	}
	void setButtonSize(sf::Vector2f size);
	void setButtonPosition(sf::Vector2f position);
	void setButtonColor(sf::Color color);
	void setButtonText(std::string text);
	sf::RectangleShape getButton();
	
private:
	sf::Vector2f ButtonSize;
	sf::Vector2f ButtonCoordonates;
	sf::RectangleShape ButtonShape;
};

