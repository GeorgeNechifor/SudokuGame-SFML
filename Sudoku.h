#pragma once
#include<SFML/Graphics.hpp>

class Sudoku
{
public:
	Sudoku() {
		setSudokuSquare();
		setSquareText();
	}
	sf::RectangleShape getSudokuSquare();

protected:
	void setTable(sf::RenderWindow& window);
	void setTableText(sf::RenderWindow& window , float x , float y);
	int matrixTable[9][9] = {
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}
	};
	sf::Text squareText;

private:
	sf::RectangleShape SudokuTableSquare;
	const float SquareSize = 100.f;
	void setSudokuSquare();
	void setLine(float x , float y , sf::RenderWindow& window , float angle);
	void setSquareText();
	const int tableSize = 9;
};

