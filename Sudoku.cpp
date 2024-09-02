#include "Sudoku.h"
#include<iostream>


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
			float x = i * 100;
			float y = (j * 100) + 50;
			SudokuTableSquare.setPosition(sf::Vector2f(x, y));
			changeColor(SudokuTableSquare, i, j);
			useClickEvent(SudokuTableSquare, sf::Vector2f(x, y), i, j);
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

void Sudoku::hoverEvent(sf::RenderWindow& window , sf::Vector2f pos , sf::RectangleShape& shape) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	float marginX = pos.x + 100;
	float marginY = pos.y + 100;
	if (mousePos.x > pos.x && mousePos.x < marginX) {
		if (mousePos.y > pos.y && mousePos.y < marginY) {
			shape.setFillColor(sf::Color::Green);
		}
		else {
			shape.setFillColor(sf::Color::Transparent);
		}
	}
}

void Sudoku::useClickEvent(sf::RectangleShape& shape , sf::Vector2f pos , int i , int j) {
	if (clicked) {
		sf::Vector2i cpy = matrixPos;

		float marginX = pos.x + 100;
		float marginY = pos.y + 100;
		if (clickPos.x >= pos.x && clickPos.x <= marginX) {
			if (clickPos.y >= pos.y && clickPos.y <= marginY) {
				matrixPos = sf::Vector2i(i, j);
				clearMatrixColor();
			}
		}
	}
}

void Sudoku::keyboardEvent(sf::Event& event) {
	if (event.type == sf::Event::TextEntered) {
		if (event.text.unicode >= 49 && event.text.unicode <= 57) {
			input = (event.text.unicode + 2) % 10;
			Sudoku::matrixTable[Sudoku::matrixPos.y][Sudoku::matrixPos.x] = input;
		}
	}
}

void Sudoku::changeColor(sf::RectangleShape& shape, int i, int j) {
	if (matrixColor[j][i]) {
		shape.setFillColor(color);
	}
	else shape.setFillColor(sf::Color::Transparent);
}

void Sudoku::clearMatrixColor() {
	for (int i = 0; i < tableSize; ++i) {
		for (int j = 0; j < tableSize; ++j) {
			if (i == matrixPos.x && j == matrixPos.y) {
				matrixColor[j][i] = 1;
			}
			else matrixColor[j][i] = 0;
		}
	}
}