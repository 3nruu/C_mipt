#include <iostream>
#include "point.hpp"
#include <cmath>
using std::cout, std::endl;

class Circle
{
private:
	Point center;
	float radius;

public:

    Circle(const Point& center, float radius)
    {
        std::cout << "Constructor" << std::endl;
        this->center = center;
        this->radius = radius;
    }

    Circle()
    {
        std::cout << "Default" << std::endl;
        center = Point(0,0);
        radius = 1;
    }

    Circle(const Circle& other)
    {
        std::cout << "Copy" << std::endl;
        center = other.center;
        radius = other.radius;
    }

    Point getCenter() const {return center;}
    float getRadius() const {return radius;}
    void setCenter(const Point& center) {this->center = center;}
    void setRadius(float radius) 
        {
            if (radius < 0)
            {
                this->radius = 0;
            }
            else
            {
                this->radius = radius;
            }
        }

    float area() const {return M_PI*radius*radius;}

    float distance(const Point& p) const
    {
        float CP = center.distance(p);
        return std::max(CP , CP - radius);
    }

     bool isColliding(const Circle& c)
     {
        float CC = center.distance(c.center);
        return (CC-radius-c.radius <= 0);
     }

    void move(const Point& p)
    {
        center = center + p;
    }
    
};

int main()
{
	Point p = {7, -1};
	Point q = {-4, 2};
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "p + q = " << p + q << endl;


	Circle a({4, 1}, 3);
	Circle b;

	cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl; 
	cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

	cout << "Area of a = " << a.area() << endl;
	cout << "Distance from point p to circle a = " << a.distance(p) << endl;


	cout << "Collisions:" << endl;
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;


	cout << "Moving b by {1, 1}:" << endl;
	b.move({1, 1});
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;

}