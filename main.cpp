#include<iostream>
#include<SFML/Graphics.hpp>
#include"Button.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 920), "SFML works!" , sf::Style::Titlebar | sf::Style::Close);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    Button button(sf::Vector2f(100.f, 100.f), "Click");
    button.setButtonColor(sf::Color::Green);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(button.getButton());
        window.draw(button.ButtonText);
        window.display();
    }
    return 0;
}
