#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400) , "Circle", sf::Style::Default);

    sf::RectangleShape rectangle(sf::Vector2f(200, 100));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setOrigin(100 , 50);
    rectangle.setPosition(200 , 200);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        if (rectangle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) 
        {
            rectangle.setFillColor(sf::Color::Red);
        } 
        else 
        {
            rectangle.setFillColor(sf::Color::Green); 
        }

        window.clear();
        window.draw(rectangle);
        window.display();

    }
}