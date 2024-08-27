#pragma once
#include<SFML/Graphics.hpp>


class Button
{
public:
	Button(sf::Vector2f size , sf::Text text)
	{
		ButtonSize = size;
		ButtonShape.setSize(ButtonSize);
		ButtonText = text;
	}
	void setButtonSize(sf::Vector2f size);
	void setButtonPosition(sf::Vector2f position);
	void setButtonColor(sf::Color color);
	bool buttonClickEvent(sf::Event& event);
	sf::RectangleShape getButton();
	
private:
	sf::Vector2f ButtonSize;
	sf::Vector2f ButtonCoordonates;
	sf::RectangleShape ButtonShape;
	sf::Text ButtonText;
	void setButtonText();
};

