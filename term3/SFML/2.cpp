#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <random>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float dt = 1.0f / 60.0f;  // Шаг по времени
const float MIN_DISTANCE = 5.0f; // Минимальное расстояние для учета силы
const float COULOMB_CONSTANT = 1000.0f;  // Коэффициент силы Кулона
const float BALL_RADIUS = 5.0f;
const float MAX_CHARGE = 5.0f;
const float MAX_MASS = 5.0f;

struct Ball {
    sf::Vector2f position;
    sf::Vector2f velocity;
    float charge;
    float mass;
    sf::CircleShape shape;

    Ball(float x, float y, float charge, float mass)
        : position(x, y), charge(charge), mass(mass), velocity(0.f, 0.f) 
    {
        shape.setRadius(BALL_RADIUS);
        shape.setOrigin(BALL_RADIUS, BALL_RADIUS);
        shape.setPosition(position);
        if (charge > 0)
        {
            shape.setFillColor(sf::Color::Red);
        }
        else
        {
            shape.setFillColor(sf::Color::Blue);
        }
    }

    void updatePosition() 
    {
        position += velocity * dt;
        shape.setPosition(position);
    }
};

float distance(const sf::Vector2f& a, const sf::Vector2f& b) 
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void applyCoulombForces(std::vector<Ball>& balls) 
{
    for (size_t i = 0; i < balls.size(); ++i) 
    {
        for (size_t j = i + 1; j < balls.size(); ++j) 
        {
            sf::Vector2f diff = balls[j].position - balls[i].position;
            float r = distance(balls[i].position, balls[j].position);

            if (r > MIN_DISTANCE) 
            {
                float force = -COULOMB_CONSTANT * balls[i].charge * balls[j].charge / r;
                sf::Vector2f direction = diff / r;
                sf::Vector2f acceleration_i = (force / balls[i].mass) * direction;
                sf::Vector2f acceleration_j = (-force / balls[j].mass) * direction;

                balls[i].velocity += acceleration_i * dt;
                balls[j].velocity += acceleration_j * dt;
            }
        }
    }
}

void handleWallCollisions(Ball& ball) 
{
    if (ball.position.x - BALL_RADIUS < 0) 
    {
        ball.position.x = BALL_RADIUS;
        ball.velocity.x = -ball.velocity.x;
    } 
    else if (ball.position.x + BALL_RADIUS > WINDOW_WIDTH) 
    {
        ball.position.x = WINDOW_WIDTH - BALL_RADIUS;
        ball.velocity.x = -ball.velocity.x;
    }
    if (ball.position.y - BALL_RADIUS < 0) 
    {
        ball.position.y = BALL_RADIUS;
        ball.velocity.y = -ball.velocity.y;
    } 
    else if (ball.position.y + BALL_RADIUS > WINDOW_HEIGHT) 
    {
        ball.position.y = WINDOW_HEIGHT - BALL_RADIUS;
        ball.velocity.y = -ball.velocity.y;
    }
}

std::vector<Ball> generateBalls(size_t n) 
{
    std::vector<Ball> balls;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> posX(BALL_RADIUS, WINDOW_WIDTH - BALL_RADIUS);
    std::uniform_real_distribution<float> posY(BALL_RADIUS, WINDOW_HEIGHT - BALL_RADIUS);
    std::uniform_real_distribution<float> charge(-MAX_CHARGE, MAX_CHARGE);
    std::uniform_real_distribution<float> mass(1.0f, MAX_MASS);

    for (size_t i = 0; i < n; ++i) {
        balls.emplace_back(posX(gen), posY(gen), charge(gen), mass(gen));
    }
    return balls;
}

int main() 
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Simulation");
    window.setFramerateLimit(60);
    std::vector<Ball> balls = generateBalls(10);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        if (event.type == sf::Event::MouseButtonPressed) 
        {
                if (event.mouseButton.button == sf::Mouse::Left) 
                {
                    balls.emplace_back(event.mouseButton.x, event.mouseButton.y, -1.0f, 1.0f);
                } 
                else if (event.mouseButton.button == sf::Mouse::Right) 
                {
                    balls.emplace_back(event.mouseButton.x, event.mouseButton.y, 5.0f, 5.0f);
                }
            }

        applyCoulombForces(balls);
        for (auto& ball : balls) 
        {
            ball.updatePosition();
            handleWallCollisions(ball);
        }


        window.clear();
        for (const auto& ball : balls)
            window.draw(ball.shape);
        window.display();
    }
    return 0;
}
