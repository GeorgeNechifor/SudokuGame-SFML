#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Sudoku
{
public:
	Sudoku() {
		setSudokuSquare();
		setSquareText();
	}
	sf::RectangleShape getSudokuSquare();
	bool clicked = false;

protected:
	void setTable(sf::RenderWindow& window);
	void setTableText(sf::RenderWindow& window , float x , float y);
	void hoverEvent(sf::RenderWindow& window , sf::Vector2f pos , sf::RectangleShape& shape);
	void useClickEvent(sf::RectangleShape& shape, sf::Vector2f pos , int i , int j);
	void keyboardEvent(sf::Event& event);
	void changeColor(sf::RectangleShape& shape, int i, int j);
	void clearMatrixColor();
	void clickEvent(sf::Event& event) {
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				float mouseX = event.mouseButton.x;
				float mouseY = event.mouseButton.y;
				clickPos = sf::Vector2f(mouseX, mouseY);
				clicked = true;
			}
		}
		else clicked = false;
	}
	int input = 0;
	int matrixTable[9][9] = {
		{1 , 2 , 3 , 0 , 0 , 0 , 0 , 0 , 0},
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}
	};
	bool matrixColor[9][9] = {
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0}
	};
	sf::Text squareText;
	sf::Vector2f clickPos;
	sf::Vector2i matrixPos;
	sf::Color color = sf::Color::Green;
	
private:
	sf::RectangleShape SudokuTableSquare;
	const float SquareSize = 100.f;
	void setSudokuSquare();
	void setLine(float x , float y , sf::RenderWindow& window , float angle);
	void setSquareText();
	const int tableSize = 9;
};

