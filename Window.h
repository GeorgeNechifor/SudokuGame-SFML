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
	void handleEvents(sf::Event& event , sf::RenderWindow& window);
		
};

