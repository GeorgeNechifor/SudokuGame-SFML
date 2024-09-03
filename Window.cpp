#include "Window.h"
#define LIGHT_PURPLE sf::Color(87, 8, 120)

void Window::setWindow() {
	Sudoku sudoku;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), Title, sf::Style::Titlebar | sf::Style::Close);
	sf::Text title;
	sf::Font font;
	if (!font.loadFromFile("C:/SudokuGameC/SudokuGame/FontHandjet.ttf")) {
		perror("Font not found");
	}
	title.setPosition(sf::Vector2f(410.f, 5.f));
	title.setFillColor(LIGHT_PURPLE);
	title.setCharacterSize(30);
	title.setFont(font);
	title.setString("Sudoku");

	number.setFont(font);
	number.setFillColor(LIGHT_PURPLE);
	number.setCharacterSize(70);

	menu.setSize(sf::Vector2f(windowWidth , windowHeight));
	menu.setFillColor(sf::Color(246, 241, 227));
	menu.setPosition(sf::Vector2f(0.f, 0.f));

	enterText.setFont(font);
	enterText.setFillColor(LIGHT_PURPLE);
	enterText.setCharacterSize(25);
	enterText.setString("press enter to start...");
	enterText.setPosition(sf::Vector2f(380.f, 550.f));

	if (!texture.loadFromFile("C:/SudokuGameC/SudokuGame/Sudoku.png")) {
		perror("Image not found");
	}
	logo.setTexture(texture);
	logo.setPosition(sf::Vector2f(200.f, 150.f));

	window.setFramerateLimit(60);
	while (window.isOpen()) {
		sf::Event event;
		handleEvents(event, window);
		window.clear(sf::Color(246, 241, 227));
		if (!menuActive) {
			Sudoku::setTable(window);
			window.draw(title);
			setTextTable(window);
		}
		else {
			setGameMenu(window);
		}
	
		
		window.display();
	}
}

void Window::handleEvents(sf::Event& event , sf::RenderWindow& window) {
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		Sudoku::clickEvent(event);
		Sudoku::keyboardEvent(event);
		enterEvent(event);
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
			int content = Sudoku::matrixTable[j][i];
			if (content > 0) {
				number.setString(std::to_string(content));
			}
			else {
				number.setString("");
			}
			number.setPosition(sf::Vector2f(i*100 + 35 , j*100 + 55));
			window.draw(number);
		}
	}
}

void Window::setGameMenu(sf::RenderWindow& window) {
	window.draw(menu);
	window.draw(logo);
	window.draw(enterText);
}

void Window::enterEvent(sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.scancode == sf::Keyboard::Scan::Enter) {
			menuActive = false;
		}
	}
}

void Window::enterTextAnimation() {
	sf::Vector2f TextPos = enterText.getPosition();
	sf::Vector2f FinalPos(TextPos.x + 50, TextPos.y + 50);
	float pos = TextPos.y;
	if (TextPos.y < FinalPos.y) {
		enterText.setPosition(TextPos.x, pos);
		pos++;
	}

}