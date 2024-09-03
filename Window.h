#pragma once
#include<SFML/Graphics.hpp>
#include"Sudoku.h"

class Window : protected Sudoku
{
public:
	void setWindow();
private:
	const float windowWidth = 900.f;
	const float windowHeight = 950.f;
	const std::string Title = "Sudoku";
	bool menuActive = true;
	sf::Text number;
	sf::RectangleShape menu;
	sf::Texture texture;
	sf::Sprite logo;
	sf::Text enterText;
	void handleEvents(sf::Event& event , sf::RenderWindow& window);
	void setTextStyle(sf::Text text, sf::Color color, sf::Font font, float size, std::string s);
	void setTextTable(sf::RenderWindow& window);
	void setGameMenu(sf::RenderWindow& window);
	void enterEvent(sf::Event& event);
};

