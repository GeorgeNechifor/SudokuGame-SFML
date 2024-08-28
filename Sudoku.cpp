#include "Sudoku.h"


void Sudoku::setSudokuSquare() {
	SudokuTableSquare.setSize(sf::Vector2f(SquareSize, SquareSize));
	SudokuTableSquare.setFillColor(sf::Color::Transparent);
	SudokuTableSquare.setOutlineColor(sf::Color::Black);
	SudokuTableSquare.setOutlineThickness(1.f);
}

sf::RectangleShape Sudoku::getSudokuSquare() {
	return SudokuTableSquare;
}

void Sudoku::setTable(sf::RenderWindow& window) {
	for (int i = 0; i < tableSize; ++i) {
		for (int j = 0; j < tableSize; ++j) {
			SudokuTableSquare.setPosition(sf::Vector2f(i * 100, (j * 100) + 50));
			
			window.draw(SudokuTableSquare);
		}
	}
}

void Sudoku::verticalLines(int i) {

}