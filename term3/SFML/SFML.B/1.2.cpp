#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800) , "Circle", sf::Style::Default);

    sf::CircleShape circle(100);
    circle.setFillColor(sf::Color::Green);
    circle.setOrigin(-300 , -300);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                circle.setFillColor(sf::Color::Red);
            }
        
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
            {
                circle.setFillColor(sf::Color::Green);
            }
        }
        window.clear();
        window.draw(circle);
        window.display();

    }
}