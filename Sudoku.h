#pragma once
#include<SFML/Graphics.hpp>

class Sudoku
{
public:
	Sudoku() {
		setSudokuSquare();
		setButton();
	}
	sf::RectangleShape getSudokuSquare();
protected:
	void setTable(sf::RenderWindow& window);

private:
	sf::RectangleShape SudokuTableSquare;
	const float SquareSize = 100.f;
	void setSudokuSquare();
	void setLine(float x , float y , sf::RenderWindow& window , float angle);
	const int tableSize = 9;
};

