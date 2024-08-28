#include "Window.h"

void Window::setWindow() {
	Sudoku sudoku;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), Title, sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		sf::Event event;
		handleEvents(event, window);
		window.clear(sf::Color::White);
		Sudoku::setTable(window);
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

