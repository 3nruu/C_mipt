#include <iostream>
#include <cmath>

using std::cout, std::endl;

struct Vector2f
{
    float x;
    float y;
};

Vector2f operator+(const Vector2f& a ,const Vector2f& b)
{
    Vector2f result = {a.x + b.x , a.y + b.y};
    return result;
}

Vector2f operator+(const Vector2f& a , float b)
{
    Vector2f result = {a.x + b , a.y + b};
    return result;
}

Vector2f operator-(const Vector2f& a ,const Vector2f& b)
{
    Vector2f result = {a.x - b.x , a.y - b.y};
    return result;
}

Vector2f operator-(const Vector2f& a , float b)
{
    Vector2f result = {a.x - b , a.y - b};
    return result;
}

Vector2f operator*(const Vector2f& a , float b)
{
    Vector2f result = {b*a.x , b*a.y};
    return result;
}

Vector2f operator*(float b, const Vector2f& a)
{
    Vector2f result = {b*a.x , b*a.y};
    return result;
}

Vector2f operator*(const Vector2f& a , const Vector2f& b)
{
    Vector2f result = {b.x*a.x , b.y*a.y};
    return result;
}

Vector2f operator-(const Vector2f& a)
{
    Vector2f result = {-a.x , -a.y};
    return result;
}

Vector2f operator+(const Vector2f& a)
{
    return a;
}

bool operator==(const Vector2f& a, const Vector2f& b) 
{
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Vector2f& a, const Vector2f& b) 
{
    return !(a == b);
}

Vector2f& operator+=(Vector2f& a, const Vector2f& b) 
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vector2f& operator-=(Vector2f& a, const Vector2f& b) 
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

Vector2f& operator*=(Vector2f& a, float scalar) 
{
    a.x *= scalar;
    a.y *= scalar;
    return a;
}

std::ostream& operator<<(std::ostream& out, const Vector2f& a) 
{
    out << "(" << a.x << ", " << a.y << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Vector2f& a) 
{
    in >> a.x >> a.y;
    return in;
}

