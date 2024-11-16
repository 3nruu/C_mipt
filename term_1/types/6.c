#include <stdio.h>
#include <math.h>

#define STEP 0.01 
#define EPS pow(10 , -10)

double gamma(double x)
{
    double gamma = 0.0 , t = 0.0 , f1 , f2 , s;


    while (1)
    {
        f1 = pow(t, x - 1.0) * exp(-t);
        t += STEP;
        f2 = pow(t, x - 1.0) * exp(-t);

        s = (f1 + f2) * STEP / 2;
        gamma += s;

        if (s < EPS)
        {
            break;
        }
    } 

    return gamma;
}



int main()
{

    double x;

    scanf("%lf", &x);

    //Как сделать проверку на тип числа?(вар. с sizeof не подходит)

    printf("%lf" , gamma(x));
    return 0;

}
