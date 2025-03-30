#include <SFML/Graphics.hpp>
#include <iostream>

class Toggle{
private:
    sf::RectangleShape background;
    sf::CircleShape slider;
    sf::Vector2f position;
    sf::Vector2f size;
    bool isOn;

    void updateBackground() {
        if (isOn) {
            background.setFillColor(sf::Color::Green); 
        } 
        else 
        {
            background.setFillColor(sf::Color(220, 220, 220)); 
        }
    }

    void updateSliderPosition() {
        if (isOn) 
        {
            slider.setPosition(position.x + size.x - slider.getRadius() * 2 - 4,
                                position.y + 3);
        } 
        else 
        {
            slider.setPosition(position.x + 4, position.y + 3);
        }
    }
public:
    Toggle(float x, float y, float width, float height) : position(x, y), size(width, height), isOn(false) 
    {
        background.setSize(size);
        background.setFillColor(sf::Color(220, 220, 220)); 
        background.setPosition(position);

        slider.setRadius(height / 2 - 2); 
        slider.setFillColor(sf::Color::White); 
        updateSliderPosition(); 
    }

    void handleEvent(const sf::Event& event) 
    {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
        {
            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
            if (background.getGlobalBounds().contains(mousePos)) {
                isOn = !isOn; 
                updateBackground();
                updateSliderPosition();
            }
        }
    }

    void draw(sf::RenderWindow& window) const 
    {
        window.draw(background);
        window.draw(slider);
    }

    bool getState() const 
    {
        return isOn;
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600),  "Toggle" ,sf::Style::Default);

    std::vector<Toggle> toggles;
    float toggleWidth = 100, toggleHeight = 40;
    float spacingX = 20, spacingY = 20;

    for (int i = 0; i < 10; ++i) {
        float x = 50 + (toggleWidth + spacingX) * (i % 5); 
        float y = 50 + (toggleHeight + spacingY) * (i / 5); 
        toggles.emplace_back(x, y, toggleWidth, toggleHeight);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }

            for (auto& toggle : toggles) {
                toggle.handleEvent(event);
            }
        }

        window.clear(sf::Color::White);
        for (const auto& toggle : toggles) {
            toggle.draw(window);
        }
        window.display();
    }

    return 0;
}