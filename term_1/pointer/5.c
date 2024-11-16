#include <stdio.h>
#include <math.h>

#define eps 1e-10

int solve_quadratic(double a, double b, double c, double* px1, double* px2)
{
    double D = b*b - 4*a*c;

    if (D < -eps)
    {
        return 0;
    }
    else if (fabs(D) < eps)
    {
        *px1 = -b / (2 * a);
        return 1;
    }
    else
    {
        *px1 = (-b + sqrt(D)) / (2 * a);
        *px2 = (-b - sqrt(D)) / (2 * a);
        return 2;
    }
}


int main()
{
    double a , b , c , x1 , x2;
    scanf("%lf %lf  %lf" , &a , &b , &c);
    int flag = solve_quadratic(a , b , c , &x1 , &x2);

    if (flag == 0) 
    {
        printf("0");
    } 
    else if (flag == 1) 
    {
        printf("x1 = %lf\n", x1);
    } 
    else if (flag == 2) 
    {
        printf("x1 = %lf, x2 = %lf\n", x1, x2);
    }

    return 0;

}