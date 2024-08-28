#pragma once
#include<SFML/Graphics.hpp>

class Sudoku
{
public:
	Sudoku() {
		setSudokuSquare();
	}
	sf::RectangleShape getSudokuSquare();
protected:
	void setTable(sf::RenderWindow& window);

private:
	sf::RectangleShape SudokuTableSquare;
	const float SquareSize = 100.f;
	void setSudokuSquare();
	void verticalLines(int i);
	const int tableSize = 9;

};

