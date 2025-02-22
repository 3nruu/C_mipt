#include <SFML/Graphics.hpp>

int main() 
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rotating Square");
    window.setFramerateLimit(60);
    
    sf::RectangleShape square(sf::Vector2f(100.f, 100.f));
    square.setFillColor(sf::Color::Green);
    square.setOrigin(50.f, 50.f); 
    square.setPosition(400.f, 300.f); 
    
    float angle = 0.0f; 

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        angle += 8.2f;
        square.setRotation(angle);
        
        window.clear(sf::Color::Black);
        window.draw(square);
        window.display();
    }
    
    return 0;
}
