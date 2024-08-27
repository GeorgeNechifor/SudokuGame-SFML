#include<iostream>
#include<SFML/Graphics.hpp>
#include"Button.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1264, 800), "SFML works!" , sf::Style::Titlebar | sf::Style::Close);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    Button btn = Button(sf::Vector2f(100.f, 100.f));
    
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw();
        window.display();
    }
    return 0;
}
