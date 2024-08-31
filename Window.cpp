#include "Window.h"

void Window::setWindow() {
	Sudoku sudoku;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), Title, sf::Style::Titlebar | sf::Style::Close);
	sf::Text title;
	sf::Font font;
	if (!font.loadFromFile("C:/SudokuGameC/SudokuGame/FontRoboto.ttf")) {
		perror("Font not found");
	}
	title.setFont(font);
	title.setFillColor(sf::Color::Black);
	title.setCharacterSize(40);
	title.setPosition(sf::Vector2f(380.f, 5.f));
	title.setString("Sudoku");

	window.setFramerateLimit(60);
	while (window.isOpen()) {
		sf::Event event;
		handleEvents(event, window);
		window.clear(sf::Color::White);
		Sudoku::setTable(window);
		window.draw(title);
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
