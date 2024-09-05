#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<cstdlib>
#define GREEN sf::Color(10, 240, 94)

class Sudoku
{
public:
	Sudoku() {
		setSudokuSquare();
		setSquareText();
		generateSample();
		setHeartImage();
		
	}
	sf::RectangleShape getSudokuSquare();
	bool clicked = false;
	

protected:
	void setTable(sf::RenderWindow& window);
	void setHeartImage();
	void useClickEvent(sf::RectangleShape& shape, sf::Vector2f pos , int i , int j);
	void keyboardEvent(sf::Event& event);
	void changeColor(sf::RectangleShape& shape, int i, int j);
	void clearMatrixColor();
	void generateSample();
	void clearMatrix();
	int getRandomNumber(sf::Vector2i range);
	bool isValidSudoku(int board[9][9]);
	void gameOver();
	void win();
	bool checkMatrixComplete();
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
	
	bool valid = true;
	int input = 0;
	int chances = 5;
	int matrixTable[9][9] = {
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
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
	sf::Vector2i matrixPos = sf::Vector2i(-1 , -1);
	sf::Color color = GREEN;
	sf::Texture HeartSpriteTexture;
	sf::Sprite heartImage;	
private:
	sf::RectangleShape SudokuTableSquare;
	const float SquareSize = 100.f;
	void setSudokuSquare();
	void setLine(float x , float y , sf::RenderWindow& window , float angle);
	void setSquareText();
	const int tableSize = 9;
};

