#include "Window.h"

void Window::setWindow() {
	Sudoku sudoku;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), Title, sf::Style::Titlebar | sf::Style::Close);
	sf::Text title;
	sf::Font font;
	if (!font.loadFromFile("C:/SudokuGameC/SudokuGame/FontRoboto.ttf")) {
		perror("Font not found");
	}
	title.setPosition(sf::Vector2f(380.f, 5.f));
	title.setFillColor(sf::Color::Black);
	title.setCharacterSize(40);
	title.setFont(font);
	title.setString("Sudoku");

	number.setFont(font);
	number.setFillColor(sf::Color::Black);
	number.setCharacterSize(60);


	window.setFramerateLimit(60);
	while (window.isOpen()) {
		sf::Event event;
		handleEvents(event, window);
		window.clear(sf::Color::White);
		Sudoku::setTable(window);
		window.draw(title);
		setTextTable(window);
		window.display();
	}
}

void Window::handleEvents(sf::Event& event , sf::RenderWindow& window) {
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void Window::setTextStyle(sf::Text text, sf::Color color, sf::Font font, float size, std::string s) {
	text.setFont(font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setString(s);
}

void Window::setTextTable(sf::RenderWindow& window) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			number.setString(std::to_string(Sudoku::matrixTable[i][j]));
			number.setPosition(sf::Vector2f(i*100 + 35 , j*100 + 62));
			window.draw(number);
		}
	}
}

