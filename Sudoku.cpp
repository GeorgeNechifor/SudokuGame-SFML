#include "Sudoku.h"
#include<iostream>
#include<vector>
#include<random>
#include<set>
#define LIGHT_PURPLE sf::Color(151, 2, 214)
#define DARK_PURPLE sf::Color(87, 4, 122)
#define GREEN sf::Color(10, 240, 94)
#define RED sf::Color(250, 95, 90)

void Sudoku::setSudokuSquare() {
	SudokuTableSquare.setSize(sf::Vector2f(SquareSize, SquareSize));
	SudokuTableSquare.setFillColor(sf::Color::Transparent);
	SudokuTableSquare.setOutlineColor(LIGHT_PURPLE);
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
			if (valid && matrixTable[j][i] == 0) {
				useClickEvent(SudokuTableSquare, sf::Vector2f(x, y), i, j);
			}
			
			window.draw(SudokuTableSquare);
		}
	}
}

void Sudoku::setLine(float x , float y ,sf::RenderWindow& window , float angle) {
	sf::RectangleShape line;
	line.setFillColor(LIGHT_PURPLE);
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
			if(isValidSudoku(matrixTable)) {
				color = GREEN;
				valid = true;
			}
			else {
				color = RED;
				valid = false;
			}
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

void Sudoku::generateSample() {
	for (int i = 0; i < tableSize; ++i) {
		for (int j = 0; j < tableSize; ++j) {
			int randomChoice = getRandomNumber(sf::Vector2i(0, 1));
			if (randomChoice) {
				int randomNumber = getRandomNumber(sf::Vector2i(1,9));
				matrixTable[j][i] = randomNumber;
				if (!isValidSudoku(matrixTable)) {
					matrixTable[j][i] = 0;
				}

			}
		}
	}
}

int Sudoku::getRandomNumber(sf::Vector2i range) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(range.x, range.y);
	return dist6(rng);
}

bool Sudoku::isValidSudoku(int board[9][9]) {

	// Check each row
	for (int i = 0; i < 9; ++i) {
		std::set<int> rowSet;
		for (int j = 0; j < 9; ++j) {
			if (board[i][j] != 0 && !rowSet.insert(board[i][j]).second) {
				return false;
			}
		}
	}

	// Check each column
	for (int j = 0; j < 9; ++j) {
		std::set<int> colSet;
		for (int i = 0; i < 9; ++i) {
			if (board[i][j] != 0 && !colSet.insert(board[i][j]).second) {
				return false; 
			}
		}
	}

	// Check each 3x3 subgrid
	for (int gridRow = 0; gridRow < 3; ++gridRow) {
		for (int gridCol = 0; gridCol < 3; ++gridCol) {
			std::set<int> gridSet;
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					int num = board[gridRow * 3 + i][gridCol * 3 + j];
					if (num != 0 && !gridSet.insert(num).second) {
						return false;
					}
				}
			}
		}
	}

	// If all checks pass, the Sudoku is valid
	return true;
}
