#include <stdio.h>
#include <math.h>

struct point
{
    double x;
    double y;
};

typedef struct point Point;

struct triangle
{
    Point a;
    Point b;
    Point c;
};

typedef struct triangle Triangle;

void print_point(Point a)
{
    printf("(%g, %g)", a.x, a.y);
}

void print_triangle(Triangle* t)
{
    printf("{");
    print_point(t->a);
    printf(", ");
    print_point(t->b);
    printf(", ");
    print_point(t->c);
    printf("}\n");
}

double distance(Point a ,Point b)
{
    return pow((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) , 0.5);
}

double get_triangle_perimeter(const Triangle* t)
{
    return distance(t->a , t->b) + distance(t->a , t->c) + distance(t->b , t->c);
}

Triangle moved_triangle(const Triangle* t , Point p)
{
    Triangle nt;
    nt.a.x = t->a.x + p.x;
    nt.a.y = t->a.y + p.y;
    nt.b.x = t->b.x + p.x;
    nt.b.y = t->b.y + p.y;
    nt.c.x = t->c.x + p.x;
    nt.c.y = t->c.y + p.y;
    return nt;   
}

void move_triangle(Triangle* t, Point p) 
{
    t->a.x += p.x;
    t->a.y += p.y;
    t->b.x += p.x;
    t->b.y += p.y;
    t->c.x += p.x;
    t->c.y += p.y;
}


int main()
{
    Triangle t = {{1.00, 0.00}, {0.50, 2.00}, {0.00, 1.50}};
    printf("Perimeter = %.2f\n", get_triangle_perimeter(&t));
    Point d = {1.0, 1.0};
    print_triangle(&t);
    move_triangle(&t, d);
    print_triangle(&t);
}