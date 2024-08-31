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
		if (i % 3 == 0 && i != 0) {
			setLine(i * 100, 50, window, 90);
			setLine(0, i * 100 + 50, window, 0);
		}
		for (int j = 0; j < tableSize; ++j) {
			SudokuTableSquare.setPosition(sf::Vector2f(i * 100, (j * 100) + 50));
			window.draw(SudokuTableSquare);
		}
	}
}

void Sudoku::setLine(float x , float y ,sf::RenderWindow& window , float angle) {
	sf::RectangleShape line;
	line.setFillColor(sf::Color::Black);
	line.setSize(sf::Vector2f(900.f, 5.f));
	line.setPosition(sf::Vector2f(x, y));
	line.rotate(angle);
	window.draw(line);
}

void Sudoku::setSquareText() {
	sf::Font font;
	if (!font.loadFromFile("C:/SudokuGameC/SudokuGame/FontRoboto.ttf")) {
		perror("Font not found");
	}
	squareText.setFont(font);
	squareText.setCharacterSize(50);
	squareText.setFillColor(sf::Color::Black);
}
